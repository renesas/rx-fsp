/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup PVD
 * @{
 **********************************************************************************************************************/

#ifndef R_PVD_H
#define R_PVD_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_pvd_cfg.h"
#include "r_voltage_detection_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** PVD instance control structure */
typedef struct st_pvd_instance_ctrl
{
    uint32_t open;
    voltage_detection_cfg_t const * p_cfg;

    void (* p_callback)(voltage_detection_callback_args_t *); // Pointer to callback that is called when voltage_detection_current_state_t changes.
    voltage_detection_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function */
    void * p_context;
} pvd_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const voltage_detection_api_t g_voltage_detection_on_pvd;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_PVD_Open(voltage_detection_ctrl_t * const p_api_ctrl, voltage_detection_cfg_t const * const p_cfg);
fsp_err_t R_PVD_Close(voltage_detection_ctrl_t * const p_api_ctrl);
fsp_err_t R_PVD_StatusGet(voltage_detection_ctrl_t * const p_api_ctrl,
                          voltage_detection_status_t     * p_voltage_detection_status);
fsp_err_t R_PVD_StatusClear(voltage_detection_ctrl_t * const p_api_ctrl);
fsp_err_t R_PVD_CallbackSet(voltage_detection_ctrl_t * const          p_api_ctrl,
                            void (                                  * p_callback)(voltage_detection_callback_args_t *),
                            void * const                              p_context,
                            voltage_detection_callback_args_t * const p_callback_memory);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup PVD)
 **********************************************************************************************************************/
