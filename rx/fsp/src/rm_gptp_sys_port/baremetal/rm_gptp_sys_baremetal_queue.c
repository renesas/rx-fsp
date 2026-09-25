/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include "rm_gptp_sys_baremetal.h"
#include "rm_gptp_sys_baremetal_queue.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define GPTP_SYS_BAREMETAL_QUEUE_PASS    (pdPASS)
#define GPTP_SYS_BAREMETAL_QUEUE_FAIL    (pdFAIL)

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/
extern gptp_sys_baremetal_instance_ctrl_t * rm_gptp_sys_baremetal_set_instance_ctrl(void);

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Initialize queue.
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_baremetal_queue_setup (gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg)
{
    FSP_PARAMETER_NOT_USED(p_cfg);
    gptp_sys_baremetal_instance_ctrl_t * p_instance_ctrl = (gptp_sys_baremetal_instance_ctrl_t *) p_ctrl;

    /* Initialize queue control block. */
    p_instance_ctrl->queue_ctrl.queue_head   = 0;
    p_instance_ctrl->queue_ctrl.queue_length = 0;
    p_instance_ctrl->queue_ctrl.queue_tail   = 0;

    for (uint8_t i = 0; i < GPTP_SYS_BAREMETAL_QUEUE_LENGTH; i++)
    {
        p_instance_ctrl->queue_ctrl.message_queue[i].instance     = 0;
        p_instance_ctrl->queue_ctrl.message_queue[i].message_type = 0;
        p_instance_ctrl->queue_ctrl.message_queue[i].port_number  = 0;
    }

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Create queue.
 **********************************************************************************************************************/
gptpQueue_t gptp_queue_create (uint32_t queue_length, uint32_t item_size)
{
    gptp_sys_baremetal_queue_ctrl_t * p_queue_ctrl;

    /* Get instance of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    if (((GPTP_SYS_BAREMETAL_QUEUE_LENGTH - 1) < queue_length) ||
        (0 == queue_length))
    {
        p_queue_ctrl = NULL;
    }

    if (sizeof(st_message_trigger_t) != item_size)
    {
        p_queue_ctrl = NULL;
    }

    /* If already queue is created, return null. */
    if (0 != p_gptp_sys_baremetal_instance_ctrl->queue_ctrl.queue_length)
    {
        p_queue_ctrl = NULL;
    }
    else
    {
        p_gptp_sys_baremetal_instance_ctrl->queue_ctrl.queue_head   = 0;
        p_gptp_sys_baremetal_instance_ctrl->queue_ctrl.queue_tail   = -1;
        p_gptp_sys_baremetal_instance_ctrl->queue_ctrl.queue_length =
            (uint8_t) (queue_length + 1);
        p_queue_ctrl = &p_gptp_sys_baremetal_instance_ctrl->queue_ctrl;
    }

    return (gptpQueue_t) p_queue_ctrl;
}

/***********************************************************************************************************************
 * Send queue.
 **********************************************************************************************************************/
uint32_t gptp_queue_send (gptpQueue_t gptp_queue, const void * item)
{
    uint8_t                           queue_result = GPTP_SYS_BAREMETAL_QUEUE_PASS;
    st_message_trigger_t            * p_item;
    gptp_sys_baremetal_queue_ctrl_t * p_queue_ctrl;

    /* Get instance of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    if ((NULL == gptp_queue) || (NULL == item))
    {
        queue_result = GPTP_SYS_BAREMETAL_QUEUE_FAIL;
    }
    else
    {
        p_queue_ctrl = (gptp_sys_baremetal_queue_ctrl_t *) gptp_queue;
        if (&p_gptp_sys_baremetal_instance_ctrl->queue_ctrl != p_queue_ctrl)
        {
            queue_result = GPTP_SYS_BAREMETAL_QUEUE_FAIL;
        }

        /* Check queue is full. */
        if (p_queue_ctrl->queue_head == ((p_queue_ctrl->queue_tail + 2) % p_queue_ctrl->queue_length))
        {
            queue_result = GPTP_SYS_BAREMETAL_QUEUE_FAIL;
        }
        else
        {
            /* Store message. */
            p_item = (st_message_trigger_t *) item;

            p_queue_ctrl->message_queue[(p_queue_ctrl->queue_tail + 1)] = *p_item;
            p_queue_ctrl->queue_tail =
                (int8_t) (((int16_t) p_queue_ctrl->queue_tail + 1) % (int16_t) p_queue_ctrl->queue_length);
        }
    }

    return (uint32_t) queue_result;
}

/***********************************************************************************************************************
 * Receive queue.
 **********************************************************************************************************************/
uint32_t gptp_queue_receive (gptpQueue_t gptp_queue, void * buffer)
{
    uint8_t queue_result = GPTP_SYS_BAREMETAL_QUEUE_PASS;
    gptp_sys_baremetal_queue_ctrl_t * p_queue_ctrl;

    /* Get instance of baremetal porting layer. */
    gptp_sys_baremetal_instance_ctrl_t * p_gptp_sys_baremetal_instance_ctrl = rm_gptp_sys_baremetal_set_instance_ctrl();

    if ((NULL == gptp_queue) || (NULL == buffer))
    {
        queue_result = GPTP_SYS_BAREMETAL_QUEUE_FAIL;
    }
    else
    {
        p_queue_ctrl = (gptp_sys_baremetal_queue_ctrl_t *) gptp_queue;
        if (&p_gptp_sys_baremetal_instance_ctrl->queue_ctrl != p_queue_ctrl)
        {
            queue_result = GPTP_SYS_BAREMETAL_QUEUE_FAIL;
        }
        else
        {
            /* Check queue is empty. */
            if (p_queue_ctrl->queue_head ==
                ((p_queue_ctrl->queue_tail + 1) % p_queue_ctrl->queue_length))
            {
                queue_result = GPTP_SYS_BAREMETAL_QUEUE_FAIL;
            }
            else
            {
                memcpy(buffer, &p_queue_ctrl->message_queue[p_queue_ctrl->queue_head], sizeof(st_message_trigger_t));
                p_queue_ctrl->queue_head =
                    (int8_t) (((int16_t) p_queue_ctrl->queue_head + 1) % (int16_t) p_queue_ctrl->queue_length);
            }
        }
    }

    return (uint32_t) queue_result;
}
