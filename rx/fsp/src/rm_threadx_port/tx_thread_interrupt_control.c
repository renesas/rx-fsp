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

/* #define TX_SOURCE_CODE  */

/* Include necessary system files.  */

#include "tx_api.h"
#include "tx_thread.h"

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _tx_thread_interrupt_control                         RXv3           */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function is responsible for changing the interrupt lockout     */
/*    posture of the system.                                              */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    new_posture                           New interrupt lockout posture */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    old_posture                           Old interrupt lockout posture */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/**************************************************************************/
#if defined(__GNUC__) || defined(__ICCRX__)
UINT _tx_thread_interrupt_control (UINT new_posture)
{
    UINT old_psw;
    UINT psw;

    /* old_posture = current PSW (full) */
    __GET_PSW(old_psw);
    psw = old_psw;

    /* Apply new I-bit posture, keep other PSW bits unchanged */
    if (new_posture & (1U << BSP_CPU_PSW_I_OFFSET))
    {
        psw |= (1U << BSP_CPU_PSW_I_OFFSET);  /* set I */
    }
    else
    {
        psw &= ~(1U << BSP_CPU_PSW_I_OFFSET); /* clear I */
    }

    /* Write back modified PSW */
    __SET_PSW(psw);

    /* Return old posture (full PSW) */
    return old_psw;
}

#endif
