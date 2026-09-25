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

extern TX_THREAD * volatile _tx_thread_current_ptr;
extern volatile ULONG       _tx_thread_system_state;

#if defined(__GNUC__) || defined(__ICCRX__)
TX_PORT_NAKED_FUNCTION
void _tx_thread_context_save (void)
{
    __asm volatile (
        "mov.l  %0, r1                           \n" /* R1 = &_tx_thread_system_state */
        "mov.l  [r1], r2                         \n" /* R2 = system_state. */
        "cmp    #0, r2                           \n" /* Check nesting (0 means first level). */
        "beq.w  __tx_not_nested_save             \n" /* Branch if not nested. */

        "add    #1, r2                          \n"  /* Nested: system_state++. */
        "mov.l  r2, [r1]                        \n"  /* Store updated system_state. */

        "pop    r1                              \n"  /* R1 = return address (from JSR/BSR). */
        "pushm r3-r5                            \n"  /* Save scratch regs R3-R5. */
        "pushm r14-r15                          \n"  /* Save regs R14-R15. */
        "pushc fpsw                             \n"  /* Save FPSW. */
        "jmp    r1                              \n"  /* Return to ISR (nested case). */

        "__tx_not_nested_save:                  \n"  /* Not-nested entry. */
        "add    #1, r2                          \n"  /* system_state++. */
        "mov.l  r2, [r1]                        \n"  /* Store system_state. */

        "mov.l  %1, r2                          \n"  /* R2 = &_tx_thread_current_ptr. */
        "mov.l  [r2], r2                        \n"  /* R2 = current thread ptr. */
        "cmp    #0, r2                          \n"  /* Is a thread running? */
        "beq.w  __tx_idle_save                  \n"  /* If NULL, idle/system context. */

        "mvfc   usp, r1                         \n"  /* R1 = USP (thread stack pointer). */

        "mov.l  16[r0], r2                      \n"  /* Load saved PSW from interrupt stack. */
        "mov.l  r2, [-r1]                       \n"  /* Push PSW to thread stack. */
        "mov.l  12[r0], r2                      \n"  /* Load saved PC from interrupt stack. */
        "mov.l  r2, [-r1]                       \n"  /* Push PC to thread stack. */
        "mov.l   8[r0], r2                      \n"  /* Load saved R2 from interrupt stack. */
        "mov.l  r2, [-r1]                       \n"  /* Push R2 to thread stack. */
        "mov.l   4[r0], r2                      \n"  /* Load saved R1 from interrupt stack. */
        "mov.l  r2, [-r1]                       \n"  /* Push R1 to thread stack. */

        "mov.l  r5, [-r1]                       \n"  /* Push R5 (scratch) to thread stack. */
        "mov.l  r4, [-r1]                       \n"  /* Push R4 (scratch) to thread stack. */
        "mov.l  r3, [-r1]                       \n"  /* Push R3 (scratch) to thread stack. */
        "mov.l  r15,[-r1]                       \n"  /* Push R15 to thread stack. */
        "mov.l  r14,[-r1]                       \n"  /* Push R14 to thread stack. */
        "mvfc   fpsw, r3                        \n"  /* R3 = FPSW. */
        "mov.l  r3, [-r1]                       \n"  /* Push FPSW to thread stack. */

        "pop    r2                              \n"  /* R2 = return address (from interrupt stack). */
        "add    #16, r0                         \n"  /* Fix interrupt SP back to bottom of frame. */
        "mvtc   r1, usp                         \n"  /* USP = updated thread stack pointer. */
        "jmp    r2                              \n"  /* Return to ISR (thread context saved). */

        "__tx_idle_save:                        \n"  /* Idle/system: no thread to save. */
        "pop    r1                              \n"  /* R1 = return address. */
        "add    #16, r0                         \n"  /* Drop interrupt frame (PC/PSW + saved regs). */
        "jmp    r1                              \n"  /* Return to caller/ISR. */
        :
        : "i" (&_tx_thread_system_state),
        "i" (&_tx_thread_current_ptr)
        );
}

#endif
