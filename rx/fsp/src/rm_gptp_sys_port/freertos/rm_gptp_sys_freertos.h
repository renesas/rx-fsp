/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_SYS_FREERTOS_H
#define RM_GPTP_SYS_FREERTOS_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "rm_gptp_sys_port_common.h"
#include "rm_gptp_sys_port_internal.h"
#include "rm_gptp_sys_freertos_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Control handle for tasks. */
typedef struct st_gptp_sys_freertos_task_ctrl
{
    TaskHandle_t ptp_task_handle;             ///< Task handle of ptp task.
    TaskHandle_t ptp_message_gen_task_handle; ///< Task handle of ptp message generation task.
    TaskHandle_t ptp_read_task_handle;        ///< Task handle of read task.
    TaskHandle_t ptp_parent_task_handle;      ///< Parent task handle.
} gptp_sys_freertos_task_ctrl_t;

/** Instance control block. DO NOT INITIALIZE. */
typedef struct st_gptp_sys_freertos_instance_ctrl
{
    const gptp_sys_port_cfg_t   * p_cfg;     ///< Pointer to configuration.
    gptp_sys_freertos_task_ctrl_t task_ctrl; ///< Pointer to task control block.
    void * p_context;                        ///< Placeholder for user data.
} gptp_sys_freertos_instance_ctrl_t;

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t  rm_gptp_sys_freertos_setup(gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg);
BaseType_t rm_gptp_sys_freertos_create_ptp_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
BaseType_t rm_gptp_sys_freertos_create_ptp_message_gen_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
BaseType_t rm_gptp_sys_freertos_create_ptp_read_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_start_ptp_message_gen_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_start_ptp_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_start_ptp_read_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_stop_ptp_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_stop_ptp_message_gen_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_stop_ptp_read_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_delete_ptp_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_delete_ptp_message_gen_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);
void       rm_gptp_sys_freertos_delete_ptp_read_task(gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_SYS_FREERTOS_H */
