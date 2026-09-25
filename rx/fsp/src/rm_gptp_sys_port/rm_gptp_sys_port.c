/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include "rm_gptp_sys_port.h"

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Initialize porting layer and start timer.
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_port_setup (gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

    /* Null check for each parameters. */
    FSP_ERROR_RETURN(NULL != p_ctrl, FSP_ERR_ASSERTION);
    FSP_ERROR_RETURN(NULL != p_cfg, FSP_ERR_ASSERTION);

    /* Initialize porting layer. */
#if (2 != BSP_CFG_RTOS)
    err = rm_gptp_sys_baremetal_setup(p_ctrl, p_cfg);
#else
    err = rm_gptp_sys_freertos_setup(p_ctrl, p_cfg);
#endif

    return err;
}
