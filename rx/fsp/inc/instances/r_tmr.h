/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TMR_H
#define R_TMR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_tmr_cfg.h"
#include "r_timer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Maximum period value allowed for TMR 16-bit peripheral. */
#define TMR_MAX_PERIOD_16BIT    (UINT16_MAX + 1)

/** Maximum period value allowed for standard TMR peripheral. */
#define TMR_MAX_PERIOD_8BIT     (UINT8_MAX + 1U)

/*******************************************************************************************************************//**
 * @addtogroup TMR
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Trigger options to start A/D conversion. */
typedef enum e_tmr_adc_trigger
{
    TMR_ADC_TRIGGER_DISABLE = 0U,      ///< A/D conversion start request in response to compare match A is disabled.
    TMR_ADC_TRIGGER_ENABLE  = 1U,      ///< A/D conversion start request in response to compare match A is enable.
} tmr_adc_trigger_t;

/** Trigger options to start A/D conversion. */
typedef enum e_tmr_counter_size
{
    TMR_COUNTER_SIZE_8_BIT  = 0U,      ///< Counter timer 8-bit selected.
    TMR_COUNTER_SIZE_16_BIT = 1U,      ///< Counter timer 16-bit selected.
} tmr_counter_size_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref timer_api_t::open is called. */
typedef struct st_tmr_instance_ctrl
{
    uint32_t            open;                     ///< Whether or not channel is open
    const timer_cfg_t * p_cfg;                    ///< Pointer to initial configurations
    R_TMR_Type        * p_reg;                    ///< Base register for this channel

    uint32_t period;                              ///< Current timer period (counts)
    uint8_t  index;                               ///< register array index for this channel.
    uint8_t  control_index;                       ///< This field indicates the index of the odd-numbered channel that will be used as the lower byte in 16-bit mode.

    void (* p_callback)(timer_callback_args_t *); ///< Pointer to callback that is called when a timer_event_t occurs.
    timer_callback_args_t * p_callback_memory;    ///< Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.
    void * p_context;                             ///< Pointer to context to be passed into callback function
} tmr_instance_ctrl_t;

/** Optional TMR extension data structure.*/
typedef struct st_tmr_extended_cfg
{
    tmr_counter_size_t counter_size;       ///< Selected timer 16-bit or 8-bit
    tmr_adc_trigger_t  adc_request_enable; ///< A/D Converter Start Request

    uint8_t   output_compare_ipl;          ///< Output Compare match interrupt priority
    IRQn_Type output_compare_irq;          ///< Output Compare match interrupt
} tmr_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const timer_api_t g_timer_on_tmr;

/** @endcond */
fsp_err_t R_TMR_Open(timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg);
fsp_err_t R_TMR_Start(timer_ctrl_t * const p_ctrl);
fsp_err_t R_TMR_Stop(timer_ctrl_t * const p_ctrl);
fsp_err_t R_TMR_Enable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_TMR_Disable(timer_ctrl_t * const p_ctrl);
fsp_err_t R_TMR_Reset(timer_ctrl_t * const p_ctrl);
fsp_err_t R_TMR_PeriodSet(timer_ctrl_t * const p_ctrl, uint32_t const period_counts);
fsp_err_t R_TMR_DutyCycleSet(timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin);
fsp_err_t R_TMR_CompareMatchSet(timer_ctrl_t * const        p_ctrl,
                                uint32_t const              compare_match_value,
                                timer_compare_match_t const match_channel);
fsp_err_t R_TMR_InfoGet(timer_ctrl_t * const p_ctrl, timer_info_t * const p_info);
fsp_err_t R_TMR_StatusGet(timer_ctrl_t * const p_ctrl, timer_status_t * const p_status);
fsp_err_t R_TMR_AdcTriggerSet(timer_ctrl_t * const p_ctrl, tmr_adc_trigger_t adc_request_enable);
fsp_err_t R_TMR_CallbackSet(timer_ctrl_t * const          p_api_ctrl,
                            void (                      * p_callback)(timer_callback_args_t *),
                            void * const                  p_context,
                            timer_callback_args_t * const p_callback_memory);
fsp_err_t R_TMR_Close(timer_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup TMR)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER

#endif                                 // R_TMR_H
