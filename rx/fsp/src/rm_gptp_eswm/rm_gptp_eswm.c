/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include "hw_adapt.h"

#include "rm_gptp_eswm.h"
#include "rm_gptp_sys_port.h"

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/********************************************************************************************************************//**
 * Initialize gPTP and ethernet hardware.
 ***********************************************************************************************************************/
fsp_err_t rm_gptp_eswm_init (gptp_eswm_ctrl_t * p_ctrl, gptp_eswm_cfg_t const * const p_cfg)
{
    fsp_err_t                   err = FSP_SUCCESS;
    const ether_instance_t    * p_ether_instance;
    gptp_eswm_instance_ctrl_t * p_instance_ctrl = (gptp_eswm_instance_ctrl_t *) p_ctrl;

    /* Null check for each parameters. */
    FSP_ERROR_RETURN(NULL != p_instance_ctrl, FSP_ERR_ASSERTION);
    FSP_ERROR_RETURN(NULL != p_cfg, FSP_ERR_ASSERTION);

    p_instance_ctrl->p_cfg     = p_cfg;
    p_instance_ctrl->p_context = NULL;

    /* Open Ethernet driver. */
    for (uint8_t i = 0; i < BSP_FEATURE_ETHER_NUM_CHANNELS; i++)
    {
        p_ether_instance = p_instance_ctrl->p_cfg->p_ether_instances[i];

        if (NULL != p_ether_instance)
        {
            err = R_RMAC_Open(p_ether_instance->p_ctrl, p_ether_instance->p_cfg);

            if (FSP_SUCCESS == err)
            {
                if (NULL == p_instance_ctrl->p_mac_address)
                {
                    /* Set mac address for clock ID. */
                    p_instance_ctrl->p_mac_address = p_ether_instance->p_cfg->p_mac_address;
                }
            }
            else
            {
                break;
            }
        }
    }

    /* Setup porting layer. */
    if (FSP_SUCCESS == err)
    {
        err = rm_gptp_sys_port_setup(p_instance_ctrl->p_cfg->p_gptp_sys_port_instance->p_ctrl,
                                     p_instance_ctrl->p_cfg->p_gptp_sys_port_instance->p_cfg);
    }

    /* Initialize hardware. */
    if (FSP_SUCCESS == err)
    {
        err = gptp_initialize(p_instance_ctrl);
    }

    if (FSP_SUCCESS == err)
    {
        do
        {
            err = gptp_link_process();
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
        } while (FSP_SUCCESS != err);
    }

    return err;
}
