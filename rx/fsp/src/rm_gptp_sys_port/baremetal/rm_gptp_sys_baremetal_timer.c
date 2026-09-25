/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "rm_gptp_sys_baremetal.h"
#include "rm_gptp_sys_baremetal_timer.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define GPTP_SYS_BAREMETAL_TIMER_PASS    (pdPASS)
#define GPTP_SYS_BAREMETAL_TIMER_FAIL    (pdFAIL)

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/
extern gptp_sys_baremetal_instance_ctrl_t * rm_gptp_sys_baremetal_set_instance_ctrl(void);

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/
static gptp_sys_baremetal_timer_ctrl_t * rm_gptp_sys_baremetal_get_timer_ctrl(
    gptp_sys_baremetal_instance_ctrl_t * p_instance_ctrl,
    gptpTimerHandle_t                    timer_handler);

void rm_gptp_sys_baremetal_timer_callback(timer_callback_args_t * p_args);

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/********************************************************************************************************************//**
 * Callback of timer interrupt subroutine.
 * This function is set to timer driver callback by configurator.
 ***********************************************************************************************************************/
void rm_gptp_sys_baremetal_timer_callback (timer_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    p_gptp_sys_baremetal_instance_ctrl->timer_tick_count++;
    p_gptp_sys_baremetal_instance_ctrl->timer_expired_count++;
}

/***********************************************************************************************************************
 * Initialize and start timer.
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_baremetal_timer_setup (gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;
    gptp_sys_baremetal_instance_ctrl_t * p_instance_ctrl = (gptp_sys_baremetal_instance_ctrl_t *) p_ctrl;

    p_instance_ctrl->p_timer_instance = p_cfg->p_timer_instance;

    /* Initialize timer control block. */
    for (uint8_t i = 0; i < GPTP_TIMER_MAX_NUMBER; i++)
    {
        p_instance_ctrl->timer_ctrl[i].auto_reload  = 0;
        p_instance_ctrl->timer_ctrl[i].timer_count  = 0;
        p_instance_ctrl->timer_ctrl[i].timer_period = 0;
        p_instance_ctrl->timer_ctrl[i].timer_status =
            GPTP_SYS_BAREMETAL_TIMER_STATUS_DELETE;
        p_instance_ctrl->timer_ctrl[i].p_timer_id          = NULL;
        p_instance_ctrl->timer_ctrl[i].p_callback_function = NULL;
    }

    /* Start timer. */
    err = p_instance_ctrl->p_timer_instance->p_api->open(p_instance_ctrl->p_timer_instance->p_ctrl,
                                                         p_instance_ctrl->p_timer_instance->p_cfg);

    if (FSP_SUCCESS == err)
    {
        err = p_instance_ctrl->p_timer_instance->p_api->start(p_instance_ctrl->p_timer_instance->p_ctrl);
    }

    if (FSP_SUCCESS == err)
    {
        err = p_instance_ctrl->p_timer_instance->p_api->enable(p_instance_ctrl->p_timer_instance->p_ctrl);
    }

    return err;
}

/**********************************************************************************************************************
 * Create timer.
 *********************************************************************************************************************/
gptpTimerHandle_t gptp_timer_create (const uint32_t              timer_period,
                                     const bool                  auto_reload,
                                     void * const                p_timer_id,
                                     gptpTimerCallbackFunction_t p_callback_function)
{
    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = NULL;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    for (uint32_t gptp_timer_index = 0; gptp_timer_index < GPTP_TIMER_MAX_NUMBER; gptp_timer_index++)
    {
        if (GPTP_SYS_BAREMETAL_TIMER_STATUS_DELETE ==
            p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[gptp_timer_index].timer_status)
        {
            p_timer_ctrl =
                &p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[gptp_timer_index];
            p_timer_ctrl->auto_reload         = (uint8_t) auto_reload;
            p_timer_ctrl->timer_count         = 0;
            p_timer_ctrl->timer_period        = (int32_t) timer_period;
            p_timer_ctrl->timer_status        = GPTP_SYS_BAREMETAL_TIMER_STATUS_STOP;
            p_timer_ctrl->p_timer_id          = p_timer_id;
            p_timer_ctrl->p_callback_function = p_callback_function;
            break;
        }
    }

    return (gptpTimerHandle_t) p_timer_ctrl;
}

/**********************************************************************************************************************
 * Whether the timer is active or not.
 *********************************************************************************************************************/
uint32_t gptp_timer_is_active (gptpTimerHandle_t timer_handler)
{
    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = rm_gptp_sys_baremetal_get_timer_ctrl(
        p_gptp_sys_baremetal_instance_ctrl,
        timer_handler);

    if (NULL == p_timer_ctrl)
    {
        return (uint32_t) GPTP_SYS_BAREMETAL_TIMER_FAIL;
    }

    if (GPTP_SYS_BAREMETAL_TIMER_STATUS_ACTIVE != p_timer_ctrl->timer_status)
    {
        return (uint32_t) GPTP_SYS_BAREMETAL_TIMER_FAIL;
    }

    return (uint32_t) GPTP_SYS_BAREMETAL_TIMER_PASS;
}

/**********************************************************************************************************************
 * Start timer.
 *********************************************************************************************************************/
uint32_t gptp_timer_start (gptpTimerHandle_t timer_handler)
{
    uint8_t timer_result = GPTP_SYS_BAREMETAL_TIMER_PASS;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = rm_gptp_sys_baremetal_get_timer_ctrl(
        p_gptp_sys_baremetal_instance_ctrl,
        timer_handler);

    if (NULL == p_timer_ctrl)
    {
        timer_result = GPTP_SYS_BAREMETAL_TIMER_FAIL;
    }
    else
    {
        p_timer_ctrl->timer_count  = (int32_t) (p_gptp_sys_baremetal_instance_ctrl->timer_expired_count * -1);
        p_timer_ctrl->timer_status = GPTP_SYS_BAREMETAL_TIMER_STATUS_ACTIVE;
    }

    return (uint32_t) timer_result;
}

/**********************************************************************************************************************
 * Stop timer.
 *********************************************************************************************************************/
uint32_t gptp_timer_stop (gptpTimerHandle_t timer_handler)
{
    uint8_t timer_result = GPTP_SYS_BAREMETAL_TIMER_PASS;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = rm_gptp_sys_baremetal_get_timer_ctrl(
        p_gptp_sys_baremetal_instance_ctrl,
        timer_handler);

    if (NULL == p_timer_ctrl)
    {
        timer_result = GPTP_SYS_BAREMETAL_TIMER_FAIL;
    }
    else
    {
        p_timer_ctrl->timer_count  = 0;
        p_timer_ctrl->timer_status = GPTP_SYS_BAREMETAL_TIMER_STATUS_STOP;
    }

    return (uint32_t) timer_result;
}

/**********************************************************************************************************************
 * Change period.
 *********************************************************************************************************************/
uint32_t gptp_timer_change_period (gptpTimerHandle_t timer_handler, uint32_t new_priod)
{
    uint8_t timer_result = GPTP_SYS_BAREMETAL_TIMER_PASS;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = rm_gptp_sys_baremetal_get_timer_ctrl(
        p_gptp_sys_baremetal_instance_ctrl,
        timer_handler);

    if (NULL == p_timer_ctrl)
    {
        timer_result = GPTP_SYS_BAREMETAL_TIMER_FAIL;
    }
    else
    {
        p_timer_ctrl->timer_period = (int32_t) new_priod;
        p_timer_ctrl->timer_count  = (int32_t) (p_gptp_sys_baremetal_instance_ctrl->timer_expired_count * -1);
        p_timer_ctrl->timer_status = GPTP_SYS_BAREMETAL_TIMER_STATUS_ACTIVE;
    }

    return (uint32_t) timer_result;
}

/**********************************************************************************************************************
 * Delete timer.
 *********************************************************************************************************************/
uint32_t gptp_timer_delete (gptpTimerHandle_t timer_handler)
{
    uint8_t timer_result = GPTP_SYS_BAREMETAL_TIMER_PASS;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = rm_gptp_sys_baremetal_get_timer_ctrl(
        p_gptp_sys_baremetal_instance_ctrl,
        timer_handler);

    if (NULL == p_timer_ctrl)
    {
        timer_result = GPTP_SYS_BAREMETAL_TIMER_FAIL;
    }
    else
    {
        p_timer_ctrl->timer_status = GPTP_SYS_BAREMETAL_TIMER_STATUS_DELETE;
        p_timer_ctrl->timer_count  = 0;
    }

    return (uint32_t) timer_result;
}

/**********************************************************************************************************************
 * Get timer id.
 *********************************************************************************************************************/
void * gptp_timer_get_timer_id (gptpTimerHandle_t timer_handler)
{
    void * p_timer_id;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = rm_gptp_sys_baremetal_get_timer_ctrl(
        p_gptp_sys_baremetal_instance_ctrl,
        timer_handler);

    if (NULL == p_timer_ctrl)
    {
        p_timer_id = NULL;
    }
    else
    {
        p_timer_id = p_timer_ctrl->p_timer_id;
    }

    return p_timer_id;
}

/**********************************************************************************************************************
 * Get timer period.
 *********************************************************************************************************************/
uint32_t gptp_timer_get_period (gptpTimerHandle_t timer_handler)
{
    uint32_t timer_period;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    gptp_sys_baremetal_timer_ctrl_t * p_timer_ctrl = rm_gptp_sys_baremetal_get_timer_ctrl(
        p_gptp_sys_baremetal_instance_ctrl,
        timer_handler);

    if (NULL == p_timer_ctrl)
    {
        timer_period = 0;
    }
    else
    {
        timer_period = (uint32_t) p_timer_ctrl->timer_period;
    }

    return timer_period;
}

/**********************************************************************************************************************
 * Get count from start gptp timer to current.
 *********************************************************************************************************************/
int32_t gptp_get_tick_count (void)
{
    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    return p_gptp_sys_baremetal_instance_ctrl->timer_tick_count;
}

/**********************************************************************************************************************
 * Delay software function.
 *********************************************************************************************************************/
void gptp_delay_ms (uint32_t wait_ms)
{
    R_BSP_SoftwareDelay(wait_ms, BSP_DELAY_UNITS_MILLISECONDS);
}

/**********************************************************************************************************************
 * Detect tiemr count.
 *********************************************************************************************************************/
uint8_t gptp_detect_count (void)
{
    uint8_t detected = (uint8_t) 0;

    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    if (p_gptp_sys_baremetal_instance_ctrl->timer_expired_count > 0)
    {
        detected = 1U;
    }

    return detected;
}

/**********************************************************************************************************************
 * Check active gptp timer expired.
 *********************************************************************************************************************/
void gptp_timer_check (void)
{
    /* Get instance control of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    int64_t timer_hw_count = p_gptp_sys_baremetal_instance_ctrl->timer_expired_count;

    if (timer_hw_count != 0)
    {
        p_gptp_sys_baremetal_instance_ctrl->timer_expired_count = 0;

        for (int32_t timer_count = GPTP_TIMER_MAX_NUMBER - 1; 0 <= timer_count; timer_count--)
        {
            if (GPTP_SYS_BAREMETAL_TIMER_STATUS_ACTIVE !=
                p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].timer_status)
            {
                continue;
            }

            p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].timer_count +=
                timer_hw_count;
            if (p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].timer_period <=
                p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].timer_count)
            {
                p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].p_callback_function((
                                                                                                    gptpTimerHandle_t) &p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[
                                                                                                    timer_count]);

                if (false == p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].auto_reload)
                {
                    p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].timer_status =
                        GPTP_SYS_BAREMETAL_TIMER_STATUS_STOP;
                }

                p_gptp_sys_baremetal_instance_ctrl->timer_ctrl[timer_count].timer_count = 0;
            }
        }
    }
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Get created timer instance associated with the timer handle.
 *********************************************************************************************************************/
static gptp_sys_baremetal_timer_ctrl_t * rm_gptp_sys_baremetal_get_timer_ctrl (
    gptp_sys_baremetal_instance_ctrl_t * p_instance_ctrl,
    gptpTimerHandle_t                    timer_handler)
{
    gptp_sys_baremetal_timer_ctrl_t * p_timer;

    if ((0 == timer_handler) ||
        (0 !=
         (((uint32_t) timer_handler - (uint32_t) p_instance_ctrl->timer_ctrl) %
          sizeof(gptp_sys_baremetal_timer_ctrl_t))))
    {
        p_timer = NULL;
    }
    else
    {
        p_timer = (gptp_sys_baremetal_timer_ctrl_t *) timer_handler;
        if (GPTP_SYS_BAREMETAL_TIMER_STATUS_DELETE == p_timer->timer_status)
        {
            p_timer = NULL;
        }
    }

    return p_timer;
}
