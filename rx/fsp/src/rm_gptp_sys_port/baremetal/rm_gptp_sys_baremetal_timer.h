/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_SYS_BAREMETAL_TIMER_H
#define RM_GPTP_SYS_BAREMETAL_TIMER_H

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
#define GPTP_TIMER_MAX_NUMBER    (64)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Timer status. */
typedef enum e_gptp_sys_baremetal_timer_status
{
    GPTP_SYS_BAREMETAL_TIMER_STATUS_DELETE = 0, ///< Timer not created.
    GPTP_SYS_BAREMETAL_TIMER_STATUS_STOP   = 1, ///< Timer created, but not active.
    GPTP_SYS_BAREMETAL_TIMER_STATUS_ACTIVE = 2, ///< Timer created, and active.
} gptp_sys_baremetal_timer_status_t;

/** Timer control block. */
typedef struct st_gptp_sys_baremetal_timer_ctrl
{
    uint8_t auto_reload;                             ///< 1:auto reload, 0:One shot.
    gptp_sys_baremetal_timer_status_t timer_status;  ///< Timer status.
    int64_t timer_period;                            ///< Timer period.
    int64_t timer_count;                             ///< Timer counter.
    void  * p_timer_id;                              ///< Pointer to timer id.
    gptpTimerCallbackFunction_t p_callback_function; ///< Pointer to callback function.
} gptp_sys_baremetal_timer_ctrl_t;

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t rm_gptp_sys_baremetal_timer_setup(gptp_sys_port_ctrl_t * p_ctrl, gptp_sys_port_cfg_t * p_cfg);

gptpTimerHandle_t gptp_timer_create(const uint32_t              timer_period,
                                    const bool                  auto_reload,
                                    void * const                timer_id,
                                    gptpTimerCallbackFunction_t p_callback_function);

uint32_t gptp_timer_is_active(gptpTimerHandle_t timer_handler);

uint32_t gptp_timer_start(gptpTimerHandle_t timer_handler);

uint32_t gptp_timer_stop(gptpTimerHandle_t timer_handler);

uint32_t gptp_timer_change_period(gptpTimerHandle_t timer_handler, uint32_t new_priod);

uint32_t gptp_timer_delete(gptpTimerHandle_t timer_handler);

void * gptp_timer_get_timer_id(gptpTimerHandle_t timer_handler);

uint32_t gptp_timer_get_period(gptpTimerHandle_t timer_handler);

int32_t gptp_get_tick_count(void);

void gptp_delay_ms(uint32_t wait_ms);

uint8_t gptp_detect_count(void);

void gptp_timer_check(void);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_SYS_BAREMETAL_TIMER_H */
