/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup ELC
 * @{
 **********************************************************************************************************************/

#ifndef R_ELC_H
#define R_ELC_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_elc_cfg.h"
#include "r_elc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Event link option operation. */
typedef enum e_elc_operation_option
{
    ELC_OPERATION_SELECT_COUNT_START,    ///< Counting is started
    ELC_OPERATION_SELECT_COUNT_RESTART,  ///< Counting is restarted
    ELC_OPERATION_SELECT_COUNTER,        ///< Event counter
    ELC_EVENT_OPERATION_SELECT_DISABLED, ///< Event output is disabled
} elc_operation_option_t;

/** Event link callback arguments definitions  */
typedef struct st_elc_callback_args_t
{
    elc_interrupt_t event;             ///< ELC interrupt event
    void          * p_context;         ///< Placeholder for user data
} elc_callback_args_t;

/** Extended configuration for ELC. */
typedef struct st_elc_cfg_extend
{
    elc_operation_option_t cmt1_md;                    ///< CMT1 Operation Select (placed at ELOPA[3:2])
    elc_operation_option_t cmtw0_md;                   ///< CMTW0 Operation Select (placed at ELOPB[1:0])
    elc_operation_option_t tmr0_md;                    ///< TMR0 Operation Select (placed at ELOPC[1:0])
    elc_operation_option_t tmr1_md;                    ///< TMR1 Operation Select (placed at ELOPC[3:2])
    elc_operation_option_t tmr2_md;                    ///< TMR2 Operation Select (placed at ELOPD[1:0])
    elc_operation_option_t tmr3_md;                    ///< TMR3 Operation Select (placed at ELOPD[3:2])

    uint32_t  ipl[ELC_INTERRUPT_NUM];                  ///< ELC interrupt priority
    IRQn_Type irq[ELC_INTERRUPT_NUM];                  ///< ELC interrupt IRQ number

    /* Configuration for UART Event processing */
    void (* p_callback)(elc_callback_args_t * p_args); ///< Pointer to callback function
    void * p_context;                                  ///< User defined context passed into callback function.
} elc_cfg_extend_t;

/** ELC private control block. DO NOT MODIFY. Initialization occurs when R_ELC_Open() is called. */
typedef struct st_elc_instance_ctrl
{
    uint32_t open;
    void   * p_context;
} elc_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const elc_api_t g_elc_on_elc;

/** @endcond */

/**********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_ELC_Open(elc_ctrl_t * const p_ctrl, elc_cfg_t const * const p_cfg);
fsp_err_t R_ELC_Close(elc_ctrl_t * const p_ctrl);
fsp_err_t R_ELC_SoftwareEventGenerate(elc_ctrl_t * const p_ctrl, elc_software_event_t event_number);
fsp_err_t R_ELC_LinkSet(elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral, elc_event_t signal);
fsp_err_t R_ELC_LinkBreak(elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral);
fsp_err_t R_ELC_Enable(elc_ctrl_t * const p_ctrl);
fsp_err_t R_ELC_Disable(elc_ctrl_t * const p_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_ELC_H

/*******************************************************************************************************************//**
 * @} (end defgroup ELC)
 **********************************************************************************************************************/
