/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_SYS_PORT_COMMON_H
#define RM_GPTP_SYS_PORT_COMMON_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#if (2 != BSP_CFG_RTOS)
 #include "r_timer_api.h"
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Configuration parameters. */
typedef struct st_gptp_sys_port_cfg
{
#if (2 != BSP_CFG_RTOS)
    const timer_instance_t * p_timer_instance; ///< Pointer to timer instance.
#endif
    void       * p_context;                    ///< Placeholder for user data.
    void const * p_extend;                     ///< Placeholder for extension data.
} gptp_sys_port_cfg_t;

/** Control block.  Allocate an instance specific control block to pass into the API calls. */
typedef void gptp_sys_port_ctrl_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_gptp_sys_port_instance
{
    gptp_sys_port_ctrl_t * p_ctrl;     ///< pointer to initial configuration.
    gptp_sys_port_cfg_t  * p_cfg;      ///< pointer to initial configuration.
} gptp_sys_port_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_SYS_PORT_COMMON_H */
