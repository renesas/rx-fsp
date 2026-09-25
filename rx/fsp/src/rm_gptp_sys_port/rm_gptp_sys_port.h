/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_SYS_PORT_H
#define RM_GPTP_SYS_PORT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "rm_gptp_sys_port_internal.h"
#if (2 != BSP_CFG_RTOS)
 #include "rm_gptp_sys_baremetal.h"
#else
 #include "rm_gptp_sys_freertos.h"
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_port_setup(gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_SYS_PORT_H */
