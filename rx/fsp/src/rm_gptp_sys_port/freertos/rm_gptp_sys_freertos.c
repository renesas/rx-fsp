/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include "hw_adapt.h"
#include "sync_8021_as.h"

#include "rm_gptp_sys_freertos.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
#define GPTP_SYS_FREERTOS_PASS    (pdPASS)

/**********************************************************************************************************************
 * Private variables and functions
 *********************************************************************************************************************/
static void rm_gptp_sys_freertos_ptp_task(void * pvParameter);
static void rm_gptp_sys_freertos_ptp_message_gen_task(void * pvParameter);
static void rm_gptp_sys_freertos_ptp_read_task(void * pvParameter);

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Initialize freertos tasks.
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_freertos_setup (gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg)
{
    gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl = (gptp_sys_freertos_instance_ctrl_t *) p_ctrl;

    /* Initialize parameters. */
    p_instance_ctrl->task_ctrl.ptp_task_handle             = 0;
    p_instance_ctrl->task_ctrl.ptp_message_gen_task_handle = 0;
    p_instance_ctrl->task_ctrl.ptp_read_task_handle        = 0;
    p_instance_ctrl->task_ctrl.ptp_parent_task_handle      = 0;
    p_instance_ctrl->p_cfg     = p_cfg;
    p_instance_ctrl->p_context = NULL;

    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * Create a ptp task.
 *********************************************************************************************************************/
BaseType_t rm_gptp_sys_freertos_create_ptp_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    BaseType_t rtosError;

    p_instance_ctrl->task_ctrl.ptp_parent_task_handle = xTaskGetCurrentTaskHandle();

    /* Create ptp task. */
    rtosError = xTaskCreate(rm_gptp_sys_freertos_ptp_task,
                            GPTP_SYS_FREERTOS_CFG_PTP_TASK_NAME,
                            GPTP_SYS_FREERTOS_CFG_PTP_TASK_STACK_BYTE_SIZE / sizeof(StackType_t),
                            &p_instance_ctrl->task_ctrl,
                            GPTP_SYS_FREERTOS_CFG_PTP_TASK_PRIORITY,
                            &p_instance_ctrl->task_ctrl.ptp_task_handle);

    /* Wait for notification indicating the created task is initialized. */
    (void) ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    /* Suspend the created task. */
    vTaskSuspend(p_instance_ctrl->task_ctrl.ptp_task_handle);

    /* Resume the created task. */
    vTaskResume(p_instance_ctrl->task_ctrl.ptp_task_handle);

    return rtosError;
}

/**********************************************************************************************************************
 * Start the ptp task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_start_ptp_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskResume(p_instance_ctrl->task_ctrl.ptp_task_handle);
}

/**********************************************************************************************************************
 * Stop the ptp task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_stop_ptp_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskSuspend(p_instance_ctrl->task_ctrl.ptp_task_handle);
}

/**********************************************************************************************************************
 * Delete the ptp task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_delete_ptp_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskDelete(p_instance_ctrl->task_ctrl.ptp_task_handle);
}

/**********************************************************************************************************************
 * Create a ptp message generation task.
 *********************************************************************************************************************/
BaseType_t rm_gptp_sys_freertos_create_ptp_message_gen_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    BaseType_t rtosError;

    /* Create ptp message generation task. */
    rtosError =
        xTaskCreate(rm_gptp_sys_freertos_ptp_message_gen_task,
                    GPTP_SYS_FREERTOS_CFG_PTP_MESSAGE_GEN_TASK_NAME,
                    GPTP_SYS_FREERTOS_CFG_PTP_MESSAGE_GEN_TASK_STACK_BYTE_SIZE / sizeof(StackType_t),
                    &p_instance_ctrl->task_ctrl,
                    GPTP_SYS_FREERTOS_CFG_PTP_MESSAGE_GEN_TASK_PRIORITY,
                    &p_instance_ctrl->task_ctrl.ptp_message_gen_task_handle);

    /* Wait for notification indicating the created task is initialized. */
    (void) ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    /* Suspend the created task. */
    vTaskSuspend(p_instance_ctrl->task_ctrl.ptp_message_gen_task_handle);

    /* Resume the created task. */
    vTaskResume(p_instance_ctrl->task_ctrl.ptp_message_gen_task_handle);

    return rtosError;
}

/**********************************************************************************************************************
 * Start the ptp message generation task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_start_ptp_message_gen_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskResume(p_instance_ctrl->task_ctrl.ptp_message_gen_task_handle);
}

/**********************************************************************************************************************
 * Stop the ptp message generation task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_stop_ptp_message_gen_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskSuspend(p_instance_ctrl->task_ctrl.ptp_message_gen_task_handle);
}

/**********************************************************************************************************************
 * Delete the ptp message generation task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_delete_ptp_message_gen_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskDelete(p_instance_ctrl->task_ctrl.ptp_message_gen_task_handle);
}

/**********************************************************************************************************************
 * Read ptp packet task.
 *********************************************************************************************************************/
BaseType_t rm_gptp_sys_freertos_create_ptp_read_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    BaseType_t rtosError;

    /* Create read ptp packet task. */
    rtosError =
        xTaskCreate(rm_gptp_sys_freertos_ptp_read_task,
                    GPTP_SYS_FREERTOS_CFG_PTP_READ_TASK_NAME,
                    GPTP_SYS_FREERTOS_CFG_PTP_READ_TASK_STACK_BYTE_SIZE / sizeof(StackType_t),
                    &p_instance_ctrl->task_ctrl,
                    GPTP_SYS_FREERTOS_CFG_PTP_READ_TASK_PRIORITY,
                    &p_instance_ctrl->task_ctrl.ptp_read_task_handle);

    /* Wait for notification indicating the created task is initialized. */
    (void) ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    /* Suspend the created task. */
    vTaskSuspend(p_instance_ctrl->task_ctrl.ptp_read_task_handle);

    /* Resume the created task. */
    vTaskResume(p_instance_ctrl->task_ctrl.ptp_read_task_handle);

    return rtosError;
}

/**********************************************************************************************************************
 * Start the read ptp packet task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_start_ptp_read_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskResume(p_instance_ctrl->task_ctrl.ptp_read_task_handle);
}

/**********************************************************************************************************************
 * Stop the read ptp packet task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_stop_ptp_read_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskSuspend(p_instance_ctrl->task_ctrl.ptp_read_task_handle);
}

/**********************************************************************************************************************
 * Delete the read ptp packet task.
 *********************************************************************************************************************/
void rm_gptp_sys_freertos_delete_ptp_read_task (gptp_sys_freertos_instance_ctrl_t * p_instance_ctrl)
{
    vTaskDelete(p_instance_ctrl->task_ctrl.ptp_read_task_handle);
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Ptp Task.
 *********************************************************************************************************************/
static void rm_gptp_sys_freertos_ptp_task (void * pvParameter)
{
    gptp_sys_freertos_task_ctrl_t * p_ctrl = (gptp_sys_freertos_task_ctrl_t *) pvParameter;

    /* Notify the parenet task launch of this task. */
    xTaskNotifyGive(p_ctrl->ptp_parent_task_handle);

    while (1)
    {
        asTask();
        vTaskDelay(1);
    }
}

/**********************************************************************************************************************
 * Message generation task.
 *********************************************************************************************************************/
static void rm_gptp_sys_freertos_ptp_message_gen_task (void * pvParameter)
{
    gptp_sys_freertos_task_ctrl_t * p_ctrl = (gptp_sys_freertos_task_ctrl_t *) pvParameter;

    /* Notify the parent task launch of this task. */
    xTaskNotifyGive(p_ctrl->ptp_parent_task_handle);

    while (1)
    {
        message_generation(NULL);
        vTaskDelay(1);
    }
}

/**********************************************************************************************************************
 * Read ptp packet task.
 *********************************************************************************************************************/
static void rm_gptp_sys_freertos_ptp_read_task (void * pvParameter)
{
    gptp_sys_freertos_task_ctrl_t * p_ctrl = (gptp_sys_freertos_task_ctrl_t *) pvParameter;

    /* Notify the parent task launch of this task. */
    xTaskNotifyGive(p_ctrl->ptp_parent_task_handle);

    while (1)
    {
        gptp_read();
        vTaskDelay(1);
    }
}
