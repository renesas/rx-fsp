/*
 * FreeRTOS Kernel
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 */

/*-----------------------------------------------------------
 * Implementation of functions defined in portable.h for RX MCUs
 *----------------------------------------------------------*/

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "r_timer_api.h"

/* configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to 0.
 * See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html */
#if 0U == configMAX_SYSCALL_INTERRUPT_PRIORITY
 #error "configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to 0"
#endif

/* Constants required to set up the initial stack. */
#define portINITIAL_PSW     ((StackType_t) 0x00030000)
#define portINITIAL_FPSW    ((StackType_t) 0x00000100)

/*-----------------------------------------------------------*/

/* This port does not currently support the MPU. */
#ifdef configENABLE_MPU
 #undef configENABLE_MPU
 #define configENABLE_MPU    (0)
#endif

/*-----------------------------------------------------------*/

extern volatile uint32_t * pxCurrentTCB;

/*
 * Setup the timer to generate the tick interrupts.  The implementation in this
 * file is weak to allow application writers to change the timer used to
 * generate the tick interrupt.
 */
void vPortSetupTimerInterrupt(void);
void vPortTeardownTimerInterrupt(void);

/*
 * Exception handlers.
 */
void vStartFirstTaskISR(void) RM_FREERTOS_PORT_NAKED_FUNCTION;
void vSwitchContextISR(void) RM_FREERTOS_PORT_NAKED_FUNCTION;
void rm_freertos_port_systick_callback(timer_callback_args_t * p_args);

/*
 * Start first task is a separate function so it can be tested in isolation.
 */
static void prvPortStartFirstTask(void);

/* Following functions are defined in assembly file. */
#if defined(__CCRX__)
extern void rm_freertos_port_start_first_task(void);
extern void rm_freertos_port_is_privileged(void);
extern void rm_freertos_port_reset_privileged(void);

#endif

/*
 * Subroutines used by the RX port. See comment header above implementation
 * for details. These functions cannot be static because they are called
 * from inline assembly.
 */
void rm_freertos_port_restore_task_stackless(void) RM_FREERTOS_PORT_NAKED_FUNCTION;

/*-----------------------------------------------------------*/

/* Each task maintains its own interrupt status in the critical nesting
 * variable. */
static UBaseType_t uxCriticalNesting = 0U;

/* The mask level is saved before disabling interrupts so it can be restored
 * when the critical section exits. */
static uint32_t g_mask_level_before_disable = 0U;

/*-----------------------------------------------------------*/

#if defined(__CCRX__)

/* Store macro values to variables that referred  from assembly file. */
const uint32_t g_configMAX_SYSCALL_INTERRUPT_PRIORITY = configMAX_SYSCALL_INTERRUPT_PRIORITY;
const uint32_t g_configKERNEL_INTERRUPT_PRIORITY      = configKERNEL_INTERRUPT_PRIORITY;
#endif

/***********************************************************************************************************************
 * This interrupt is called to start the first task.
 **********************************************************************************************************************/

#if defined(__GNUC__) || defined(__ICCRX__)
void vStartFirstTaskISR (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* When starting the scheduler there is nothing that needs moving to the
         * interrupt stack because the function is not called from an interrupt.
         * Just ensure the current stack is the user stack. */
        "SETPSW     U                       \n"

        /* Obtain the location of the stack associated with which ever task
         * pxCurrentTCB is currently pointing to. */
        "MOV.L      #_pxCurrentTCB, R15     \n"
        "MOV.L      [R15], R15              \n"
        "MOV.L      [R15], R0               \n"

        /* Restore the task. This function does not return. */
        "JMP        %0                      \n"

        ::"r" (rm_freertos_port_restore_task_stackless)
        );
}

#endif

/***********************************************************************************************************************
 * Resets the FPU lazy stacking, configures the hardware stack monitor, enables interrupts, and requests an SVC
 * interrupt. The first task is started in the SVC interrupt.
 **********************************************************************************************************************/
static void prvPortStartFirstTask (void)
{
    /*Call handler for stack restore. The handler is registered in vector number 1 for unconditional trap only.*/
#if defined(__GNUC__) || defined(__ICCRX__)
    __asm volatile
    (
        "INT #1     \n"
        ::: "cc"
    );
#elif defined(__CCRX__)
    rm_freertos_port_start_first_task();
#endif
}

/***********************************************************************************************************************
 * This interrupt is called to execute a context switch.
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__ICCRX__)
void vSwitchContextISR (void)
{
    /* This function is assembly only to meet the requirements for naked/stackless functions. For GCC, only basic
     * assembly is allowed. */
    __asm volatile (

        /* Re-enable interrupts. */
        "SETPSW     I                                               \n"

        /* Move the data that was automatically pushed onto the interrupt stack when
         * the interrupt occurred from the interrupt stack to the user stack.
         *
         * R15 is saved before it is clobbered. */
        "PUSH.L     R15                                             \n"

        /* Read the user stack pointer. */
        "MVFC       USP, R15                                        \n"

        /* Move the address down to the data being moved. */
        "SUB        #12, R15                                        \n"
        "MVTC       R15, USP                                        \n"

        /* Copy the data across, R15, then PC, then PSW. */
        "MOV.L      [ R0 ], [ R15 ]                                 \n"
        "MOV.L      4[ R0 ], 4[ R15 ]                               \n"
        "MOV.L      8[ R0 ], 8[ R15 ]                               \n"

        /* Move the interrupt stack pointer to its new correct position. */
        "ADD        #12, R0                                         \n"

        /* All the rest of the registers are saved directly to the user stack. */
        "SETPSW     U                                               \n"

        /* Save the rest of the general registers (R15 has been saved already). */
        "PUSHM      R1-R14                                          \n"

        /* Save the FPSW and accumulators. */
        "MVFC       FPSW, R15                                       \n"
        "PUSH.L     R15                                             \n"
        "MVFACGU    #0, A1, R15                                     \n"
        "PUSH       R15                                             \n"
        "MVFACHI    #0, A1, R15                                     \n"
        "PUSH.L     R15                                             \n"
        "MVFACLO    #0, A1, R15                                     \n"
        "PUSH.L     R15                                             \n"
        "MVFACGU    #0, A0, R15                                     \n"
        "PUSH.L     R15                                             \n"
        "MVFACHI    #0, A0, R15                                     \n"
        "PUSH.L     R15                                             \n"
        "MVFACLO    #0, A0, R15                                     \n"
        "PUSH.L     R15                                             \n"

        /* Save the stack pointer to the TCB. */
        "MOV.L      #_pxCurrentTCB, R15                             \n"
        "MOV.L      [ R15 ], R15                                    \n"
        "MOV.L      R0, [ R15 ]                                     \n"

        /* Ensure the interrupt mask is set to the syscall priority while the kernel
         * structures are being accessed. */
        "MVTIPL     %0                                              \n"

        /* Select the next task to run. */
        "MOV.L      %1, R1                                          \n"
        "JSR	    R1                                              \n"

        /* Reset the interrupt mask as no more data structure access is required. */
        "MVTIPL     %2                                              \n"

        /* Load the stack pointer of the task that is now selected as the Running
         * state task from its TCB. */
        "MOV.L      #_pxCurrentTCB,R15                              \n"
        "MOV.L      [ R15 ], R15                                    \n"
        "MOV.L      [ R15 ], R0                                     \n"

        /* Restore the task. This function does not return. */
        "MOV.L      #_rm_freertos_port_restore_task_stackless, R5   \n"
        "JMP        R5                                              \n"

        ::"i" (configMAX_SYSCALL_INTERRUPT_PRIORITY), "i" (vTaskSwitchContext), "i" (configKERNEL_INTERRUPT_PRIORITY)
        );
}

#endif

/***********************************************************************************************************************
 * Increments system time.
 **********************************************************************************************************************/
void rm_freertos_port_systick_callback (timer_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);

    /* Re-enabled interrupts. */
    __SETPSW_I();

    /* Increment the RTOS tick. This must be done in a critical section because
     * it accesses the delayed and ready lists, which can also be modified in
     * critical sections in FromISR functions (reference xTaskRemoveFromEventList,
     * for example). */
    uint32_t ulPreviousMask = portSET_INTERRUPT_MASK_FROM_ISR();
    {
        if (xTaskIncrementTick() != pdFALSE)
        {
            taskYIELD();
        }
    }

    portCLEAR_INTERRUPT_MASK_FROM_ISR(ulPreviousMask);
}

/*-----------------------------------------------------------*/

/***********************************************************************************************************************
 * Subroutine to restore a task.
 *
 * @note This function does not return to the calling function. It returns to the task being restored. Branch to this
 * function without link (B instruction, not BL).
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__ICCRX__)
void rm_freertos_port_restore_task_stackless (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */

    __asm volatile (
        "POP        R15                     \n"

        /* Accumulator low 32 bits. */
        "MVTACLO    R15, A0                 \n"
        "POP        R15                     \n"

        /* Accumulator high 32 bits. */
        "MVTACHI    R15, A0                 \n"
        "POP        R15                     \n"

        /* Accumulator guard. */
        "MVTACGU    R15, A0                 \n"
        "POP        R15                     \n"

        /* Accumulator low 32 bits. */
        "MVTACLO    R15, A1                 \n"
        "POP        R15                     \n"

        /* Accumulator high 32 bits. */
        "MVTACHI    R15, A1                 \n"
        "POP        R15                     \n"

        /* Accumulator guard. */
        "MVTACGU    R15, A1                 \n"
        "POP        R15                     \n"

        /* Floating point status word. */
        "MVTC       R15, FPSW               \n"

        /* R1 to R15 - R0 is not included as it is the SP. */
        "POPM       R1-R15                  \n"

        /* This pops the remaining registers. */
        "RTE                                \n"
        "NOP                                \n"
        "NOP                                \n"
        );
}

#endif

/***********************************************************************************************************************
 * Setup the stack of a new task so it is ready to be placed under the scheduler control.  The registers have to be
 * placed on the stack in the order that the port expects to find them.
 *
 * @param[in]  pxTopOfStack  Pointer to top of this task's stack
 * @param[in]  pxCode        Task function, stored as initial PC for the task
 * @param[in]  pvParameters  Parameters for task
 **********************************************************************************************************************/
#if portHAS_STACK_OVERFLOW_CHECKING
StackType_t * pxPortInitialiseStack (StackType_t  * pxTopOfStack,
                                     StackType_t  * pxEndOfStack,
                                     TaskFunction_t pxCode,
                                     void         * pvParameters)
#else
StackType_t * pxPortInitialiseStack (StackType_t * pxTopOfStack, TaskFunction_t pxCode, void * pvParameters)
#endif
{
    /* R0 is not included as it is the stack pointer. */
    *pxTopOfStack = 0x00;
    pxTopOfStack--;
    *pxTopOfStack = portINITIAL_PSW;
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) pxCode;

    pxTopOfStack -= 15;

    *pxTopOfStack = (StackType_t) pvParameters; /* R1 */
    pxTopOfStack--;
    *pxTopOfStack = portINITIAL_FPSW;
    pxTopOfStack--;

    *pxTopOfStack = 0x11111111; /* Accumulator 1. */ // NOLINT(readability-magic-numbers)
    pxTopOfStack--;
    *pxTopOfStack = 0x22222222; /* Accumulator 1. */ // NOLINT(readability-magic-numbers)
    pxTopOfStack--;
    *pxTopOfStack = 0x33333333; /* Accumulator 1. */ // NOLINT(readability-magic-numbers)
    pxTopOfStack--;
    *pxTopOfStack = 0x44444444; /* Accumulator 0. */ // NOLINT(readability-magic-numbers)
    pxTopOfStack--;
    *pxTopOfStack = 0x55555555; /* Accumulator 0. */ // NOLINT(readability-magic-numbers)
    pxTopOfStack--;
    *pxTopOfStack = 0x66666666; /* Accumulator 0. */ // NOLINT(readability-magic-numbers)

    return pxTopOfStack;
}

/***********************************************************************************************************************
 * Setup the hardware for the scheduler to take control. Configures the SysTick frequency and starts the first task.
 **********************************************************************************************************************/
BaseType_t xPortStartScheduler (void)
{
    /* Use pxCurrentTCB just so it does not get optimised away. */

    if (pxCurrentTCB != NULL)
    {
        /* Call an application function to set up the timer that will generate the
         * tick interrupt.  This way the application can decide which peripheral to
         * use.  A demo application is provided to show a suitable example. */
        vPortSetupTimerInterrupt();

        /* Enable the software interrupt (SWINT0) for context switch. */
        R_BSP_IrqStatusClear((IRQn_Type) 27);
        R_BSP_IrqCfg((IRQn_Type) 27, configKERNEL_INTERRUPT_PRIORITY, NULL);
        R_BSP_IrqEnable((IRQn_Type) 27);

        /* Start the first task. */
        prvPortStartFirstTask();
    }

    /* Should not get here. */
    return pdFAIL;
}

/***********************************************************************************************************************
 * Execution should never get here.
 **********************************************************************************************************************/
void vPortEndScheduler (void)
{
    /* Enable the software interrupt (SWINT0) for context switch. */
    R_BSP_IrqDisable((IRQn_Type) 27);
    R_BSP_IrqStatusClear((IRQn_Type) 27);
    R_BSP_IrqCfg((IRQn_Type) 27, 0, NULL);

    /* Disable the timer interrupt for system. */
    vPortTeardownTimerInterrupt();

    /* Not implemented in ports where there is nothing to return to.
     * Artificially force an assert. */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/***********************************************************************************************************************
 * Enter a critical section.
 **********************************************************************************************************************/
void vPortEnterCritical (void)
{
    uint32_t old_mask_level = portSET_INTERRUPT_MASK();
    uxCriticalNesting++;

    /* This is not the interrupt safe version of the enter critical function so
     * assert() if it is being called from an interrupt context.  Only API
     * functions that end in "FromISR" can be used in an interrupt.  Only assert if
     * the critical nesting count is 1 to protect against recursive calls if the
     * assert function also uses a critical section. */
    if (uxCriticalNesting == 1)
    {
        g_mask_level_before_disable = old_mask_level;
        portASSERT_IF_IN_ISR();
    }
}

/***********************************************************************************************************************
 * Exit a critical section.
 **********************************************************************************************************************/
void vPortExitCritical (void)
{
    configASSERT(uxCriticalNesting);
    uxCriticalNesting--;
    if (uxCriticalNesting == 0)
    {
        portCLEAR_INTERRUPT_MASK(g_mask_level_before_disable);
    }
}

/*-----------------------------------------------------------*/

/***********************************************************************************************************************
 * Setup the system timer to generate the tick interrupts at the required frequency.
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__ICCRX__)
BSP_WEAK_REFERENCE __attribute__((noinline)) void vPortSetupTimerInterrupt (void)
{
    /* NOTE: This function is placeholder.
     * Use generated function by FSP configurator or implemented user own code. */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

#endif

/***********************************************************************************************************************
 * Teardown the system timer to terminate scheduler.
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__ICCRX__)
BSP_WEAK_REFERENCE void vPortTeardownTimerInterrupt (void)
{
    /* NOTE: This function is placeholder.
     * Use generated function by FSP configurator or implemented user own code. */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

#endif

#if (configASSERT_DEFINED == 1)

void vPortValidateInterruptPriority (void)
{
    configASSERT(ulPortGetInterruptPriority() <= configMAX_SYSCALL_INTERRUPT_PRIORITY);
}

/*-----------------------------------------------------------*/

 #if (configENABLE_MPU == 1)
BaseType_t xIsPrivileged (void)        /* __attribute__ (( naked )) */
{
  #if defined(__GNUC__) || defined(__ICCRX__)
    __asm volatile
    (
        "MVFC   PSW, R1         \n"
        "SHLR   #20, R1         \n"
        "NOT    R1, R1          \n"
        "RTS                      "
    );
  #elif defined(__CCRX__)
    rm_freertos_port_is_privileged();
  #endif
}

/*-----------------------------------------------------------*/

void vResetPrivilege (void)            /* __attribute__ (( naked )) */
{
  #if defined(__GNUC__) || defined(__ICCRX__)
    __asm volatile
    (
        "MVFC   PSW, R1             \n"
        "AND    #-FF0FFFFFH, R1     \n"
        "MVTC   R1, PSW             \n"
        "POP    R1                  \n"
        "RTS                          "
    );
  #elif defined(__CCRX__)
    rm_freertos_port_reset_privileged();
  #endif
}

/*-----------------------------------------------------------*/

 #endif

#endif

uint32_t ulPortGetInterruptPriority (void)
{
    return R_BSP_GetCurrentIpl();
}

#if defined(__GNUC__) || defined(__ICCRX__)
void vPortSetInterruptPriority (uint32_t ulNewIPL __attribute__((unused)))
{
    __asm volatile
    (
        "PUSH   R5                  \n"
        "MVFC   PSW, R5             \n"
        "SHLL   #24, R1             \n"
        "AND    #-0F000001H, R5     \n"
        "OR     R1, R5              \n"
        "MVTC   R5, PSW             \n"
        "POP    R5                  \n"
        "RTS                          "
    );
}

#endif
