/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_ESWM_H
#define RM_GPTP_ESWM_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_gptp.h"
#include "r_rmac.h"
#include "rm_gptp_sys_port.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Configuration parameters. */
typedef struct st_gptp_eswm_cfg
{
    const ether_instance_t         * p_ether_instances[BSP_FEATURE_ETHER_NUM_CHANNELS]; /// List of pointer to Ethernet instance.
    const gptp_sys_port_instance_t * p_gptp_sys_port_instance;                          /// Pointer to gPTP porting layer instance.

    /* Pointer to context to be passed into callback function */
    void       * p_context;                                                             ///< Placeholder for user data.
    void const * p_extend;                                                              ///< Placeholder for user extension.
} gptp_eswm_cfg_t;

/** Control block. */
typedef struct st_gptp_eswm_instance_ctrl
{
    const gptp_eswm_cfg_t * p_cfg;         ///< Pointer to configuration.
    uint8_t               * p_mac_address; ///< Mac address for clock identify.
    void * p_context;                      ///< Placeholder for user data.
} gptp_eswm_instance_ctrl_t;

/** Control block. Allocate an instance specific control block to pass into the API calls. */
typedef void gptp_eswm_ctrl_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_gptp_eswm_instance
{
    gptp_eswm_ctrl_t * p_ctrl;         ///< Pointer to gPTP ESEM control block.
    gptp_eswm_cfg_t  * p_cfg;          ///< Pointer to initial configuration.
} gptp_eswm_instance_t;

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t rm_gptp_eswm_init(gptp_eswm_ctrl_t * p_ctrl, gptp_eswm_cfg_t const * const p_cfg);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_ESWM_H */
