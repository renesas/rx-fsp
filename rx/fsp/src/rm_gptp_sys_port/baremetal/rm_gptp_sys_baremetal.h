/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_SYS_BAREMETAL_H
#define RM_GPTP_SYS_BAREMETAL_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rm_gptp_sys_baremetal_queue.h"
#include "rm_gptp_sys_baremetal_timer.h"
#include "rm_gptp_sys_port_common.h"
#include "rm_gptp_sys_port_internal.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Instance control block for baremetal. */
typedef struct st_gptp_sys_baremetal_instance_ctrl
{
    const gptp_sys_port_cfg_t * p_cfg;                                 ///< Pointer to configuration.
    const timer_instance_t    * p_timer_instance;                      ///< Pointer to timer instance.

    volatile int32_t timer_tick_count;                                          ///< Tick count of timer.
    volatile int64_t timer_expired_count;                                       ///< Count of timer to check active timer expired.

    gptp_sys_baremetal_timer_ctrl_t timer_ctrl[GPTP_TIMER_MAX_NUMBER]; ///< List of timer control block.
    gptp_sys_baremetal_queue_ctrl_t queue_ctrl;                        ///< Queue control block.

    void * p_context;                                                  ///< Placeholder for user data.
} gptp_sys_baremetal_instance_ctrl_t;

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_baremetal_setup(gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_SYS_BAREMETAL_H */
