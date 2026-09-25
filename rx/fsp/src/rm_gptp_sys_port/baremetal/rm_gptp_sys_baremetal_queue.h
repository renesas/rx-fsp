/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_SYS_BAREMETAL_QUEUE_H
#define RM_GPTP_SYS_BAREMETAL_QUEUE_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rm_gptp_sys_port_common.h"
#include "rm_gptp_sys_port_internal.h"
#include "sync_8021_as.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define GPTP_SYS_BAREMETAL_QUEUE_LENGTH    (64 + 1)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Queue control block. */
typedef struct st_gptp_sys_baremetal_queue_ctrl
{
    int8_t               queue_head;                                     ///< Queue head.
    int8_t               queue_tail;                                     ///< Queue tail.
    uint8_t              queue_length;                                   ///< Queue length.
    st_message_trigger_t message_queue[GPTP_SYS_BAREMETAL_QUEUE_LENGTH]; ///< List of message trigger.
} gptp_sys_baremetal_queue_ctrl_t;

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_baremetal_queue_setup(gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg);

gptpQueue_t gptp_queue_create(uint32_t queue_length, uint32_t item_size);

uint32_t gptp_queue_send(gptpQueue_t gptp_queue, const void * item);

uint32_t gptp_queue_receive(gptpQueue_t gptp_queue, void * buffer);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_SYS_BAREMETAL_QUEUE_H */
