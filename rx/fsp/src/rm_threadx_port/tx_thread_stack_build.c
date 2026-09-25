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
#include "tx_thread.h"

#define TX_INITIAL_PSW    (0x00030000UL) /* PM=1, U=1 */
#define TX_FRAME_WORDS    (24)

#if defined(__GNUC__) || defined(__ICCRX__)
ULONG _tx_get_fpsw(void);

ULONG _tx_get_fpsw (void)
{
    ULONG fpsw;
    __asm volatile ("mvfc fpsw, %0" : "=r" (fpsw));

    return fpsw;
}

#elif defined(__CCRX__)
extern ULONG _tx_get_fpsw(void);

#endif

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _tx_thread_stack_build                            RXv3              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function builds a stack frame on the supplied thread's stack.  */
/*    The stack frame results in a fake interrupt return to the supplied  */
/*    function pointer.                                                   */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    thread_ptr                            Pointer to thread control blk */
/*    function_ptr                          Pointer to return function    */
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
/*    _tx_thread_create                     Create thread service         */
/*                                                                        */
/**************************************************************************/
VOID _tx_thread_stack_build (TX_THREAD * thread_ptr, VOID (* function_ptr)(VOID))
{
    ULONG * stack_top;
    ULONG * frame;
    ULONG   fpsw;

    /* tx_thread_stack_end points to the last byte of the stack area.
     * Add sizeof(ULONG) then align down to 4 bytes to obtain the first 4-byte aligned
     * address past the end of the stack, which is used as the initial stack top. */
    uintptr_t top = (uintptr_t) thread_ptr->tx_thread_stack_end + sizeof(ULONG);
    top      &= ~(uintptr_t) 0x3U;
    stack_top = (ULONG *) top;

    frame = stack_top - TX_FRAME_WORDS;

    fpsw = _tx_get_fpsw();

    /* ACC0 (A0) : popped first */
    frame[0] = 0;                      /* GU */
    frame[1] = 0;                      /* HI */
    frame[2] = 0;                      /* LO */

    /* ACC1 (A1) */
    frame[3] = 0;                      /* GU */
    frame[4] = 0;                      /* HI */
    frame[5] = 0;                      /* LO */

    /* R6..R13 */
    frame[6]  = 0;                     /* R6 */
    frame[7]  = 0;                     /* R7 */
    frame[8]  = 0;                     /* R8 */
    frame[9]  = 0;                     /* R9 */
    frame[10] = 0;                     /* R10 */
    frame[11] = 0;                     /* R11 */
    frame[12] = 0;                     /* R12 */
    frame[13] = 0;                     /* R13 */

    /* FPSW */
    frame[14] = fpsw;

    /* R14, R15 */
    frame[15] = 0;
    frame[16] = 0;

    /* R3, R4, R5 */
    frame[17] = 0;
    frame[18] = 0;
    frame[19] = 0;

    /* R1, R2 */
    frame[20] = 0;
    frame[21] = 0;

    /* PC, PSW */
    frame[22] = (ULONG) function_ptr;
    frame[23] = TX_INITIAL_PSW;

    /* stack_ptr : ACC0 */
    thread_ptr->tx_thread_stack_ptr = frame;
}
