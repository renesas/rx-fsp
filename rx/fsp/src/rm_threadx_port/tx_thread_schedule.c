/**************************************************************************/

/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   Thread                                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define TX_SOURCE_CODE

/* Include necessary system files.  */

#include "tx_api.h"
#include "tx_timer.h"
#include "r_timer_api.h"

#if defined(__GNUC__) && !defined(__clang_analyzer__)
 #define TX_PORT_NAKED_FUNCTION    __attribute__((naked, no_instrument_function, \
                                                  no_profile_instrument_function))
#else
 #define TX_PORT_NAKED_FUNCTION    BSP_ATTRIBUTE_STACKLESS
#endif

extern TX_THREAD * volatile _tx_thread_execute_ptr;
extern TX_THREAD * volatile _tx_thread_current_ptr;

void                        rm_threadx_port_systick_callback(timer_callback_args_t * p_args);
TX_PORT_NAKED_FUNCTION VOID _tx_thread_schedule(VOID);

TX_PORT_NAKED_FUNCTION void tx_software_interrupt_handler(void);

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _tx_thread_schedule                               RXV3              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function waits for a thread control block pointer to appear in */
/*    the _tx_thread_execute_ptr variable.  Once a thread pointer appears */
/*    in the variable, the corresponding thread is resumed.               */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _tx_initialize_kernel_enter          ThreadX entry function         */
/*    _tx_thread_system_return             Return to system from thread   */
/*                                                                        */
/**************************************************************************/
#if defined(__GNUC__) || defined(__ICCRX__)
TX_PORT_NAKED_FUNCTION

void _tx_thread_schedule (void)
{
    __asm volatile (
        "mov.l  %0, r1                          \n" /* R1 = &_tx_thread_execute_ptr. */

        "_tx_sched_loop:                        \n" /* Scheduler wait loop. */
        "setpsw i                               \n" /* Temporarily enable interrupts. */
        "clrpsw i                               \n" /* Disable interrupts again. */
        "mov.l  [r1], r2                        \n" /* R2 = execute_ptr. */
        "cmp    #0, r2                          \n" /* Is a thread ready? */
        "bne.w  _tx_sched_thread_ready          \n" /* Yes, schedule it. */
 #if defined(BSP_CFG_RTOS_IDLE_SLEEP) && (1 == BSP_CFG_RTOS_IDLE_SLEEP)
        "wait                                   \n" /* Enter idle wait state. */
 #endif
        "bra.a  _tx_sched_loop                  \n" /* Loop until a thread is ready. */

        "_tx_sched_thread_ready:                \n" /* Thread ready to run. */

        "mov.l  %1, r3                          \n" /* R3 = &_tx_thread_current_ptr. */
        "mov.l  r2, [r3]                        \n" /* current_ptr = execute_ptr. */

        "mov.l  4[r2], r3                       \n" /* Load run_count. */
        "add    #1, r3                          \n" /* run_count++. */
        "mov.l  r3, 4[r2]                       \n" /* Store run_count. */

        "mov.l  24[r2], r3                      \n" /* Load thread time-slice. */
        "mov.l  %2, r4                          \n" /* R4 = &_tx_timer_time_slice. */
        "mov.l  r3, [r4]                        \n" /* Set global time-slice. */

        "setpsw u                               \n" /* Switch to user stack mode. */
        "mov.l  8[r2], r0                       \n" /* SP = thread stack pointer. */

        "popm   r1-r3                           \n" /* Pop ACC0 (GU to R1, HI to R2, LO to R3). */
        "mvtaclo r3, a0                         \n" /* Restore ACC0 LO. */
        "mvtachi r2, a0                         \n" /* Restore ACC0 HI. */
        "mvtacgu r1, a0                         \n" /* Restore ACC0 GU. */

        "popm   r1-r3                           \n" /* Pop ACC1 (GU to R1, HI to R2, LO to R3). */
        "mvtaclo r3, a1                         \n" /* Restore ACC1 LO. */
        "mvtachi r2, a1                         \n" /* Restore ACC1 HI. */
        "mvtacgu r1, a1                         \n" /* Restore ACC1 GU. */

        "popm   r6-r13                          \n" /* Restore general registers */
        "popc   fpsw                            \n" /* Restore FPSW. */
        "popm   r14-r15                         \n" /* Restore R14-R15. */
        "popm   r3-r5                           \n" /* Restore R3-R5. */
        "popm   r1-r2                           \n" /* Restore R1-R2. */

        "rte                                    \n" /* Return to thread context. */
        :
        : "i" (&_tx_thread_execute_ptr),
        "i" (&_tx_thread_current_ptr),
        "i" (&_tx_timer_time_slice)
        );
}

#endif

#if defined(__GNUC__) || defined(__ICCRX__)
TX_PORT_NAKED_FUNCTION
void tx_software_interrupt_handler (void)
{
    __asm volatile (
        "pushm r1-r2        \n"        /* Save volatile registers R1-R2 to match the stack frame expected by ThreadX context_save. SWINT entry builds a consistent interrupt frame. */
        "mov.l  %0, r1      \n"        /* Load address of _tx_thread_context_save into R1 (using immediate/constant operand). */
        "jsr    r1          \n"        /* Call _tx_thread_context_save; JSR pushes return address so the callee can POP it if needed. */
        "mov.l  %1, r1      \n"        /* Load address of _tx_thread_context_restore into R1. */
        "jmp    r1          \n"        /* Jump to _tx_thread_context_restore; no return here (restore ends with RTE or branches to scheduler). */
        :
        : "i" (_tx_thread_context_save),
        "i" (_tx_thread_context_restore)
        );
}

#endif

#ifndef TX_NO_TIMER
extern VOID _tx_timer_interrupt(VOID);

/* System tick timer. */

void rm_threadx_port_systick_callback (timer_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);

    _tx_timer_interrupt();
}

#endif
