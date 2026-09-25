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

#include "tx_api.h"
#include "tx_timer.h"
#include "tx_initialize.h"

#if defined(__GNUC__) && !defined(__clang_analyzer__)
 #define TX_PORT_NAKED_FUNCTION    __attribute__((naked, no_instrument_function, \
                                                  no_profile_instrument_function))
#else
 #define TX_PORT_NAKED_FUNCTION    BSP_ATTRIBUTE_STACKLESS
#endif

extern TX_THREAD * volatile _tx_thread_execute_ptr;
extern TX_THREAD * volatile _tx_thread_current_ptr;
extern volatile ULONG       _tx_thread_system_state;
extern volatile UINT        _tx_thread_preempt_disable;

extern VOID _tx_thread_schedule(VOID);

#if defined(__GNUC__) || defined(__ICCRX__)
TX_PORT_NAKED_FUNCTION

void _tx_thread_context_restore (void)
{
    __asm volatile (
        "clrpsw i                              \n" /* Disable interrupts */

        "mov.l  %0, r1                         \n" /* R1 = &_tx_thread_system_state. */
        "mov.l  [r1], r2                       \n" /* R2 = system_state. */
        "sub    #1, r2                         \n" /* system_state-- */
        "mov.l  r2, [r1]                       \n" /* Store updated system_state. */
        "beq.w  __tx_not_nested_restore        \n" /* Branch if not nested. */

        "popc   fpsw                           \n" /* Restore FPSW (nested). */
        "popm   r14-r15                        \n" /* Restore R14-R15 (nested). */
        "popm   r3-r5                          \n" /* Restore R3-R5 (nested). */
        "popm   r1-r2                          \n" /* Restore R1-R2 (nested). */
        "rte                                   \n" /* Return from interrupt (nested case). */

        "__tx_not_nested_restore:              \n" /* Not-nested restore path. */

        "mov.l  %1, r1                         \n" /* R1 = &_tx_thread_current_ptr. */
        "mov.l  [r1], r2                       \n" /* R2 = current thread ptr. */
        "cmp    #0, r2                         \n" /* Check if a thread was running. */
        "beq.w  __tx_idle_restore              \n" /* If NULL, go to idle restore. */

        "mov.l  %2, r3                         \n" /* R3 = &_tx_thread_preempt_disable. */
        "mov.l  [r3], r3                       \n" /* R3 = preempt_disable flag. */
        "cmp    #0, r3                         \n" /* Preemption disabled? */
        "bne.w  __tx_no_preempt_restore        \n" /* Yes, no preemption. */

        "mov.l  %3, r3                         \n" /* R3 = &_tx_thread_execute_ptr. */
        "cmp    [r3], r2                       \n" /* execute_ptr == current? */
        "bne.w  __tx_do_preempt                \n" /* If different, do preemption. */

        "__tx_no_preempt_restore:              \n" /* Resume current thread. */
        "setpsw u                              \n" /* Switch to user stack. */

        "popc   fpsw                           \n" /* Restore FPSW. */
        "popm   r14-r15                        \n" /* Restore R14-R15. */
        "popm   r3-r5                          \n" /* Restore R3-R5. */
        "popm   r1-r2                          \n" /* Restore R1-R2. */
        "rte                                   \n" /* Return to interrupted thread. */

        "__tx_do_preempt:                      \n" /* Preemption required. */
        "setpsw u                              \n" /* Switch to user stack. */

        "pushm r6-r13                          \n" /* Save remaining registers. */

        "mvfacgu #0, a1, r4                    \n" /* Save ACC1 GU. */
        "mvfachi #0, a1, r5                    \n" /* Save ACC1 HI. */
        "mvfaclo #0, a1, r6                    \n" /* Save ACC1 LO. */
        "pushm r4-r6                           \n" /* Push ACC1 registers. */

        "mvfacgu #0, a0, r4                    \n" /* Save ACC0 GU. */
        "mvfachi #0, a0, r5                    \n" /* Save ACC0 HI. */
        "mvfaclo #0, a0, r6                    \n" /* Save ACC0 LO. */
        "pushm r4-r6                           \n" /* Push ACC0 registers. */

        "mov.l  r0, 8[r2]                      \n" /* Save SP to thread stack_ptr. */

        "mov.l  #0, r2                         \n" /* R2 = NULL. */
        "mov.l  r2, [r1]                       \n" /* current_ptr = NULL. */

        "bra.a  __tx_idle_restore              \n" /* Go to scheduler path. */

        "__tx_idle_restore:                    \n" /* Idle/system restore. */
        "mvtc   #0, psw                        \n" /* Reset PSW (IPL = 0). */
        "mov.l  %4, r1                         \n" /* R1 = &_tx_thread_schedule. */
        "jmp    r1                             \n" /* Jump to scheduler. */
        :
        : "i" (&_tx_thread_system_state),
        "i" (&_tx_thread_current_ptr),
        "i" (&_tx_thread_preempt_disable),
        "i" (&_tx_thread_execute_ptr),
        "i" (_tx_thread_schedule)
        );
}

#endif
