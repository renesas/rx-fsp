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
/**   Initialize                                                          */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define TX_SOURCE_CODE

/* Include necessary system files.  */

#include "bsp_api.h"
#include "tx_api.h"
#include "tx_initialize.h"
#include "tx_thread.h"
#include "tx_timer.h"

/* SysTick must not be higher priority (lower numerical value) than maximum
 * ThreadX interrupt priority. */

extern void _tx_timer_module_setup(void);

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _tx_initialize_low_level                             RXv3           */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function is responsible for any low-level processor            */
/*    initialization, including setting up interrupt vectors, setting     */
/*    up a periodic timer interrupt source, saving the system stack       */
/*    pointer for use in ISR processing later, and finding the first      */
/*    available RAM memory address for tx_application_define.             */
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
/*    _tx_initialize_kernel_enter           ThreadX entry function        */
/*                                                                        */
/**************************************************************************/

VOID _tx_initialize_low_level (VOID)
{
    /* Ensure that all interrupts are disabled.  */
    R_BSP_SetIFlagState(BSP_CPU_INTERRUPT_DISABLE);

    /* Set base of available memory to end of non-initialized RAM area.  */
    _tx_initialize_unused_memory = TX_NULL;

    /* Note: _tx_thread_system_stack_ptr is intentionally not set for RXv3.
     * On Cortex-M it holds the MSP to support MSP/PSP switching, but RXv3 uses
     * ISP/USP switching via PSW.U bit and does not require this pointer. */
    _tx_thread_system_stack_ptr = TX_NULL;
#ifndef TX_NO_TIMER

    /* Enable a hardware timer module */
    _tx_timer_module_setup();
#endif

    /* Enable the software interrupt (SWINT, IRQ 27) for context switch. */
    R_BSP_IrqStatusClear(TX_PORT_SWINT_NUMBER);
    R_BSP_IrqCfg(TX_PORT_SWINT_NUMBER, TX_PORT_SWINT_PRIORITY, NULL); // 1 is the lowest priority level (0 means interrupt disabled)
    R_BSP_IrqEnable(TX_PORT_SWINT_NUMBER);
}
