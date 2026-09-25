/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tmr.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "TMR" in ASCII.  Used to determine if the control block is open. */
#define TMR_OPEN                                   (('T' << 24U) | ('M' << 16U) | ('R' << 8U))

#define TMR_PRV_UNIT(channel)       (channel / 2)
#define TMR_PRV_CHANNEL(channel)    (channel % 2)
#define TMR_PRV_ODD_CHANNEL                        (0x01)

#define TMR_PRV_USER_INTERNAL_CLOCK_MASK           (0x08U)

#define TMR_IRQ_REQ_DISABLE                        (0x00U)
#define TMR_IRQ_REQ_ENABLE                         (0x0FU)
#define TMR_OUTPUT_COMPARE_RETAIN                  (0x00U)
#define TMR_CLEAR_COUNTER_COMPARE_MATCH            (1UL)

/* TMR TCCR register bit mask */
#define TMR_TCCR_SCK_DIV_1_MASK                    (0x00U)
#define TMR_TCCR_SCK_DIV_2_MASK                    (0x01U)
#define TMR_TCCR_SCK_DIV_8_MASK                    (0x02U)
#define TMR_TCCR_SCK_DIV_32_MASK                   (0x03U)
#define TMR_TCCR_SCK_DIV_64_MASK                   (0x04U)
#define TMR_TCCR_SCK_DIV_1024_MASK                 (0x05U)
#define TMR_TCCR_SCK_DIV_8192_MASK                 (0x06U)
#define TMR_TCCR_SCK_CSS_VALUE_MASK                (0x1FU)
#define TMR_TCCR_CSS_INTERNAL_CLOCK_VALUE_MASK     (0x01U)

/* TMR TCSR register bit mask */
#define TMR_TCSR_OSA_HIGH_OUTPUT_MASK              (0x02U)
#define TMR_TCSR_OSB_LOW_OUTPUT_MASK               (0x01U)
#define TMR_TCSR_OSA_TOGGLE_OUTPUT_MASK            (0x03U)
#define TMR_TCSR_OSB_TOGGLE_OUTPUT_MASK            (0x03U)
#define TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_1_3    (0xF0U)
#define TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_0_2    (0xE0U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void     r_tmr_common_open(tmr_instance_ctrl_t * const p_instance_ctrl, timer_cfg_t const * const p_cfg);
static void     r_tmr_config_set(tmr_instance_ctrl_t * const p_instance_ctrl, timer_cfg_t const * const p_cfg);
static void     r_tmr_period_register_set(tmr_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts);
static void     r_tmr_start_timer(tmr_instance_ctrl_t * const p_instance_ctrl);
static uint32_t r_tmr_clock_frequency_get(tmr_instance_ctrl_t * const p_instance_ctrl);
static void     r_tmr_call_callback(tmr_instance_ctrl_t * p_instance_ctrl, timer_event_t event, uint32_t capture);

/* ISRs. */
void tmr_overflow_isr(void);
void tmr_compare_match_isr(void);

/***********************************************************************************************************************
 * Private global variables.
 **********************************************************************************************************************/

/* TMR base address */
static const uint32_t volatile * p_tmr_base_address[BSP_FEATURE_TMR_MAX_CASCADED_CHANNEL] =
{
#if (BSP_FEATURE_TMR_CHANNELS & (1 << 0))
    [0] = (uint32_t *) R_TMR01,
#endif
#if (BSP_FEATURE_TMR_CHANNELS & (1 << 1))
    [1] = (uint32_t *) R_TMR23,
#endif
};

/* TMR Implementation of General Timer Driver  */
const timer_api_t g_timer_on_tmr =
{
    .open            = R_TMR_Open,
    .stop            = R_TMR_Stop,
    .start           = R_TMR_Start,
    .reset           = R_TMR_Reset,
    .enable          = R_TMR_Enable,
    .disable         = R_TMR_Disable,
    .periodSet       = R_TMR_PeriodSet,
    .dutyCycleSet    = R_TMR_DutyCycleSet,
    .compareMatchSet = R_TMR_CompareMatchSet,
    .infoGet         = R_TMR_InfoGet,
    .statusGet       = R_TMR_StatusGet,
    .callbackSet     = R_TMR_CallbackSet,
    .close           = R_TMR_Close
};

/*******************************************************************************************************************//**
 * @addtogroup TMR
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the timer module and applies configurations. Implements @ref timer_api_t::open.
 *
 * TMR hardware does not support one-shot functionality natively.  When using one-shot mode, the timer will be stopped
 * in an ISR after the requested period has elapsed.
 *
 * The TMR implementation of the general timer can accept a tmr_extended_cfg_t extension parameter.
 *
 * Example:
 * @snippet r_tmr_example.c R_TMR_Open
 *
 * @retval FSP_SUCCESS                    Initialization was successful.
 * @retval FSP_ERR_ASSERTION              A required input pointer is NULL or the source divider is invalid or
 *                                        channel does not support a 16bit counter size or the period was not in the valid range of
 *                                        1 to 0xFF in 8bit counter or 1 to 0xFFFF in 16bit counter or an input parameter is invalid.
 * @retval FSP_ERR_ALREADY_OPEN           Module is already open.
 * @retval FSP_ERR_IRQ_BSP_DISABLED       timer_cfg_t::mode is ::TIMER_MODE_ONE_SHOT or timer_cfg_t::p_callback is not
 *                                        NULL, but ISR is not enabled.  ISR must be enabled to use one-shot mode or
 *                                        callback. Or a required interrupt has not been enabled in the vector table.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The channel requested in the p_cfg parameter is not available on this device.
 **********************************************************************************************************************/
fsp_err_t R_TMR_Open (timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;
#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(TMR_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    if ((p_cfg->p_callback) || (TIMER_MODE_ONE_SHOT == p_cfg->mode))
    {
        FSP_ERROR_RETURN(p_cfg->cycle_end_irq > 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_cfg->p_extend;

    /* Validate channel number. */
    FSP_ERROR_RETURN(((1U << p_cfg->channel) & BSP_FEATURE_TMR_VALID_CHANNEL_MASK), FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Validate channel number support for count size 16bit. */
        FSP_ERROR_RETURN(((1U << p_cfg->channel) & BSP_FEATURE_TMR_VALID_CHANNEL_16_BIT_MASK),
                         FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    }

    /* Validate period parameter. */
    if (TMR_COUNTER_SIZE_8_BIT == p_extend->counter_size)
    {
        FSP_ASSERT(p_cfg->period_counts <= TMR_MAX_PERIOD_8BIT);
    }
    else
    {
        FSP_ASSERT(p_cfg->period_counts <= TMR_MAX_PERIOD_16BIT);
    }

    /* Allowed dividers for PCLK are 1, 2, 8, 32, 64, 1024 and 8192. */
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_4);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_16);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_128);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_256);
    FSP_ASSERT(p_cfg->source_div != TIMER_SOURCE_DIV_512);

    if (BSP_IRQ_DISABLED != p_extend->output_compare_ipl)
    {
        /* Return error if IRQ is required and not in the vector table. */
        FSP_ERROR_RETURN(p_extend->output_compare_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }
#endif

    /* Initialize control structure based on configurations. */
    r_tmr_common_open(p_instance_ctrl, p_cfg);

    /* Power on the TMR channel. */
    R_BSP_MODULE_START(FSP_IP_TMR, p_cfg->channel);

    uint8_t tcsr = 0;
    if (0 != p_instance_ctrl->index % 2)
    {
        tcsr |= TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_1_3;
    }
    else
    {
        tcsr |= TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_0_2;
    }

    /* Initialize registers to the value reset*/
    p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->index]          = 0U;
    p_instance_ctrl->p_reg->TCR[p_instance_ctrl->index]           = 0U;
    p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index]          = tcsr;
    p_instance_ctrl->p_reg->TCSTR[p_instance_ctrl->control_index] = 0U;

    /* Set the TMR configuration settings provided in ::timer_cfg_t and ::tmr_extended_cfg_t. */
    r_tmr_config_set(p_instance_ctrl, p_cfg);

    /* Set period register and update duty cycle if output mode is used for one-shot or periodic mode. */
    r_tmr_period_register_set(p_instance_ctrl, p_cfg->period_counts);

    p_instance_ctrl->open = TMR_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops timer. Implements @ref timer_api_t::stop.
 *
 * @retval FSP_SUCCESS                 Timer successfully stopped.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/

fsp_err_t R_TMR_Stop (timer_ctrl_t * const p_ctrl)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;
#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint8_t tccr = p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index];

    /* Stop clock timer*/
    tccr &= R_TMR_TCCR_TMRIS_Msk;
    p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index]  = tccr;
    p_instance_ctrl->p_reg->TCSTR[p_instance_ctrl->control_index] = 0U;

    /* Waiting for register TCCR stopped. */
    FSP_HARDWARE_REGISTER_WAIT(tccr, p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index]);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts timer. Implements @ref timer_api_t::start.
 *
 * @retval FSP_SUCCESS                 Timer successfully started.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/

fsp_err_t R_TMR_Start (timer_ctrl_t * const p_ctrl)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;
#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_tmr_start_timer(p_instance_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enables external event triggers that start, event count, or restart the counter. Implements @ref timer_api_t::enable.
 *
 * @retval FSP_ERR_UNSUPPORTED                 API not supported by TMR.
 **********************************************************************************************************************/
fsp_err_t R_TMR_Enable (timer_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Disables external event triggers that start, event count or restart the counter. Implements @ref timer_api_t::disable.
 * @note The timer could be running after R_TMR_Disable(). To ensure it is stopped, call R_TMR_Stop().
 *
 * @retval FSP_ERR_UNSUPPORTED                 API not supported by TMR.
 **********************************************************************************************************************/
fsp_err_t R_TMR_Disable (timer_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Resets the counter value to 0. Implements @ref timer_api_t::reset.
 *
 * @retval FSP_SUCCESS                 Counter reset.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_TMR_Reset (timer_ctrl_t * const p_ctrl)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;

#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Reset Counter 16-bits */
        p_instance_ctrl->p_reg->TCNT = 0U;
    }
    else
    {
        /* Reset Counter 8-bits */
        p_instance_ctrl->p_reg->TCNT_BY[p_instance_ctrl->index].TCNT = 0U;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates period. The new period is updated immediately. Implements
 * @ref timer_api_t::periodSet.
 *
 * @warning Stop the timer before calling this function if one-shot output is used.
 *
 * @retval FSP_SUCCESS                 Period value updated.
 * @retval FSP_ERR_ASSERTION           A required pointer was NULL, or the period was not in the valid range of
 *                                     1 to 0xFF in 8bit counter or 1 to 0xFFFF in 16bit counter.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_TMR_PeriodSet (timer_ctrl_t * const p_ctrl, uint32_t const period_counts)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;

#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Validate period parameter. */
    FSP_ASSERT(0U != period_counts);

    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Validate period parameter. */
    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        FSP_ASSERT(period_counts <= TMR_MAX_PERIOD_16BIT);
    }
    else
    {
        FSP_ASSERT(period_counts <= TMR_MAX_PERIOD_8BIT);
    }
#endif

    /* Set period register and update duty cycle if output mode is used for one-shot or periodic mode. */
    r_tmr_period_register_set(p_instance_ctrl, period_counts);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets duty cycle on requested pin. Implements @ref timer_api_t::dutyCycleSet.
 *
 * Example:
 * @snippet r_tmr_example.c R_TMR_DutyCycleSet
 *
 * @retval FSP_SUCCESS                 Duty cycle updated.
 * @retval FSP_ERR_ASSERTION           A required pointer was NULL, or the pin was invalid.
 * @retval FSP_ERR_INVALID_ARGUMENT    Duty cycle was not in the valid range of 0 to period (counts) - 1
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 * @retval FSP_ERR_UNSUPPORTED         TMR_CFG_OUTPUT_SUPPORT_ENABLE is 0.
 **********************************************************************************************************************/
fsp_err_t R_TMR_DutyCycleSet (timer_ctrl_t * const p_ctrl, uint32_t const duty_cycle_counts, uint32_t const pin)
{
#if TMR_CFG_OUTPUT_SUPPORT_ENABLE
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;
 #if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Get extended config */
    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    uint16_t period_counts = 0;
    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Get period value to register TCORA 16-bit. */
        period_counts = p_instance_ctrl->p_reg->TCORA;
    }
    else
    {
        /* Get period value to register TCORA 8-bit. */
        period_counts = (uint16_t) p_instance_ctrl->p_reg->TCORA_BY[p_instance_ctrl->index].TCORA;
    }

    FSP_ERROR_RETURN(duty_cycle_counts <= (period_counts + 1U), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
 #else

    /* Get extended config */
    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
 #endif
    FSP_PARAMETER_NOT_USED(pin);

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        uint16_t duty_cycle_counts_16 = (uint16_t) duty_cycle_counts;

        /* Set duty cycle for register 16-bits. */
        p_instance_ctrl->p_reg->TCORB = duty_cycle_counts_16;
    }
    else
    {
        /* Set duty cycle for register 8-bits. */
        p_instance_ctrl->p_reg->TCORB_BY[p_instance_ctrl->index].TCORB = (uint8_t) duty_cycle_counts;
    }

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(duty_cycle_counts);
    FSP_PARAMETER_NOT_USED(pin);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Placeholder for unsupported compareMatch function. Implements @ref timer_api_t::compareMatchSet.
 *
 * @retval FSP_ERR_UNSUPPORTED      TMR compare match is not supported.
 **********************************************************************************************************************/
fsp_err_t R_TMR_CompareMatchSet (timer_ctrl_t * const        p_ctrl,
                                 uint32_t const              compare_match_value,
                                 timer_compare_match_t const match_channel)
{
/* This function isn't supported. It is defined only to implement a required function of timer_api_t.
 * Mark the input parameter as unused since this function isn't supported. */
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(compare_match_value);
    FSP_PARAMETER_NOT_USED(match_channel);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Gets timer information and store it in provided pointer p_info. Implements @ref timer_api_t::infoGet.
 *
 * @retval FSP_SUCCESS                 Period, count direction, and frequency stored in p_info.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_TMR_InfoGet (timer_ctrl_t * const p_ctrl, timer_info_t * const p_info)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;

#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_info);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Get and store period. */
    p_info->period_counts = p_instance_ctrl->period;

    /* Get and store clock frequency. */
    p_info->clock_frequency = r_tmr_clock_frequency_get(p_instance_ctrl);

    /* TMR supports only counting up direction. */
    p_info->count_direction = TIMER_DIRECTION_UP;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get current timer status and store it in provided pointer p_status. Implements @ref timer_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 Current timer state and counter value set successfully.
 * @retval FSP_ERR_ASSERTION           p_ctrl or p_status was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_TMR_StatusGet (timer_ctrl_t * const p_ctrl, timer_status_t * const p_status)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;

#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Get counter state. ELC count-start updates TCSTR without changing TCCR. */
    uint8_t tccr = p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index];
    if (((tccr & TMR_TCCR_SCK_CSS_VALUE_MASK) != 0U) ||
        (0U != p_instance_ctrl->p_reg->TCSTR_b[p_instance_ctrl->control_index].TCS))
    {
        p_status->state = TIMER_STATE_COUNTING;
    }
    else
    {
        p_status->state = TIMER_STATE_STOPPED;
    }

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Get counter value 16-bits. */
        p_status->counter = (uint32_t) p_instance_ctrl->p_reg->TCNT;
    }
    else
    {
        /* Get counter value 8-bits. */
        p_status->counter = (uint32_t) p_instance_ctrl->p_reg->TCNT_BY[p_instance_ctrl->index].TCNT;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set A/D converter start request compare match value.
 *
 * @retval FSP_SUCCESS                 Counter value updated.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL or channel unsupport Adc trigger.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The channel requested in the p_cfg parameter is not available on this device 16-bit timer.
 * @retval FSP_ERR_UNSUPPORTED         The feature not available on this device.
 **********************************************************************************************************************/
fsp_err_t R_TMR_AdcTriggerSet (timer_ctrl_t * const p_ctrl, tmr_adc_trigger_t adc_request_enable)
{
#if BSP_FEATURE_TMR_ADC_TRIGGER
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;
 #if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(((1U << p_instance_ctrl->p_cfg->channel) & BSP_FEATURE_TMR_VALID_CHANNEL_16_BIT_MASK),
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
 #endif

    /* Get value from TCRS register. */
    uint32_t tcsr =
        (uint32_t) (p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index] | TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_0_2);

    /* ADC trigger enable. */
    tcsr |= (adc_request_enable << R_TMR_TCSR_ADTE_Pos) & R_TMR_TCSR_ADTE_Msk;
    p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index] = (uint8_t) tcsr;

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(adc_request_enable);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref timer_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 ***********************************************************************************************************************/
fsp_err_t R_TMR_CallbackSet (timer_ctrl_t * const          p_api_ctrl,
                             void (                      * p_callback)(timer_callback_args_t *),
                             void * const                  p_context,
                             timer_callback_args_t * const p_callback_memory)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_api_ctrl;
#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_callback);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context. */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops counter, clears internal driver data. Implements @ref timer_api_t::close.
 *
 * @retval FSP_SUCCESS                 Successful close.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_TMR_Close (timer_ctrl_t * const p_ctrl)
{
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) p_ctrl;
#if TMR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TMR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    uint32_t             tcsr     = 0U;

    /* If channel 0 or 2 selected. */
    if (((1U << p_instance_ctrl->p_cfg->channel) & BSP_FEATURE_TMR_VALID_CHANNEL_16_BIT_MASK))
    {
        tcsr |= (uint32_t) TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_0_2;
    }
    else
    {
        tcsr |= (uint32_t) TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_1_3;
    }

    /* Disable Output. */
    p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index] = (uint8_t) tcsr;

    /* Stop timer. */
    p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index]  = 0U;
    p_instance_ctrl->p_reg->TCSTR[p_instance_ctrl->control_index] = 0U;

    /* Disable interrupts. */
    p_instance_ctrl->p_reg->TCR[p_instance_ctrl->index] = 0U;

    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->cycle_end_irq);
    R_FSP_IsrContextSet(p_instance_ctrl->p_cfg->cycle_end_irq, NULL);

    R_BSP_IrqDisable(p_extend->output_compare_irq);
    R_FSP_IsrContextSet(p_extend->output_compare_irq, NULL);

    p_instance_ctrl->open = 0UL;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup TMR)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes control structure based on configuration.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  p_cfg                   Pointer to timer configuration.
 **********************************************************************************************************************/
static void r_tmr_common_open (tmr_instance_ctrl_t * const p_instance_ctrl, timer_cfg_t const * const p_cfg)
{
    /* Initialize control structure. */
    p_instance_ctrl->p_cfg = p_cfg;

    uint8_t unit = (uint8_t) TMR_PRV_UNIT(p_instance_ctrl->p_cfg->channel);

    /* Get register array index for this channel.*/
    p_instance_ctrl->index = (uint8_t) TMR_PRV_CHANNEL(p_cfg->channel);

    /* Get the index of the odd-numbered channel*/
    if (TMR_COUNTER_SIZE_16_BIT == ((tmr_extended_cfg_t *) p_cfg->p_extend)->counter_size)
    {
        p_instance_ctrl->control_index = TMR_PRV_ODD_CHANNEL;
    }
    else
    {
        p_instance_ctrl->control_index = p_instance_ctrl->index;
    }

    /* Get base address of TMR channel. */
    p_instance_ctrl->p_reg = (R_TMR_Type *) p_tmr_base_address[unit];

    /* Set callback and context pointers.*/
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;
}

/*******************************************************************************************************************//**
 * Configures TMR related registers based on user configurations.
 *
 * @param[in]     p_instance_ctrl   Pointer to TMR control structure
 * @param[in]     p_cfg             Pointer to TMR specific configuration structure
 **********************************************************************************************************************/
static void r_tmr_config_set (tmr_instance_ctrl_t * const p_instance_ctrl, timer_cfg_t const * const p_cfg)
{
    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_cfg->p_extend;

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* The even channel is configured to use the overflow signal of the odd channel as its clock input. */
        p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->index] = R_TMR_TCCR_CSS_Msk;
    }

    /* Setting for register TCR. */
    uint32_t tcr = 0UL;

    /* set countet clear. */
    tcr |= (TMR_CLEAR_COUNTER_COMPARE_MATCH << R_TMR_TCR_CCLR_Pos) & R_TMR_TCR_CCLR_Msk;

    uint32_t irq_req = 0UL;

    if (p_instance_ctrl->p_cfg->cycle_end_irq > 0)
    {
        /* Compare Match A Interrupt Enable. */
        irq_req = ((p_instance_ctrl->p_cfg->cycle_end_ipl) != BSP_IRQ_DISABLED) ? 1UL : 0UL;
        tcr    |= (irq_req << R_TMR_TCR_CMIEA_Pos) & R_TMR_TCR_CMIEA_Msk;
    }

    if (p_extend->output_compare_irq > 0)
    {
        /* Compare Match B Interrupt Enable. */
        irq_req = ((p_extend->output_compare_ipl) != BSP_IRQ_DISABLED) ? 1UL : 0UL;
        tcr    |= ((irq_req & TMR_IRQ_REQ_ENABLE) << R_TMR_TCR_CMIEB_Pos) & R_TMR_TCR_CMIEB_Msk;
    }

    /* Set value to Timer Control Register. */
    p_instance_ctrl->p_reg->TCR[p_instance_ctrl->index] = (uint8_t) tcr;

    /* Setting for register TCSR. */
    uint32_t tcsr = (uint32_t) p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index];

#if BSP_FEATURE_TMR_ADC_TRIGGER

    /* If channel 0 or 2 selected. */
    if (((1U << p_instance_ctrl->p_cfg->channel) & BSP_FEATURE_TMR_VALID_CHANNEL_16_BIT_MASK))
    {
        /* ADC trigger enable. */
        tcsr |= (p_extend->adc_request_enable << R_TMR_TCSR_ADTE_Pos) & R_TMR_TCSR_ADTE_Msk;
    }
#endif

#if TMR_CFG_OUTPUT_SUPPORT_ENABLE
    uint16_t duty_cycle_counts = 0UL;

    /* Set initial duty cycle for PWM mode in open.  Duty cycle is set for other modes in r_tmr_period_register_set. */
    if (TIMER_MODE_PWM == p_cfg->mode)
    {
        duty_cycle_counts = (uint16_t) (p_cfg->duty_cycle_counts - 1U);

        /* Set level HIGH output for TMOn pin output when compare match A of TCORA and TCNT occurs. */
        tcsr |= (TMR_TCSR_OSA_HIGH_OUTPUT_MASK << R_TMR_TCSR_OSA_Pos) & R_TMR_TCSR_OSA_Msk;

        /* Set level LOW output for TMOn pin output when compare match B of TCORB and TCNT occurs. */
        tcsr |= (((TMR_TCSR_OSB_LOW_OUTPUT_MASK << R_TMR_TCSR_OSB_Pos) & R_TMR_TCSR_OSB_Msk));
    }
    else
    {
        /* Set level Toggle output for TMOn pin output when compare match A of TCORA and TCNT occurs. */
        tcsr |= (TMR_TCSR_OSA_TOGGLE_OUTPUT_MASK << R_TMR_TCSR_OSA_Pos) & R_TMR_TCSR_OSA_Msk;

        /* Set level Toggle output for TMOn pin output when compare match B of TCORB and TCNT occurs. */
        tcsr |= (((TMR_TCSR_OSB_TOGGLE_OUTPUT_MASK << R_TMR_TCSR_OSB_Pos) & R_TMR_TCSR_OSB_Msk));
    }

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Set period value to register TCORA 16-bit. */
        p_instance_ctrl->p_reg->TCORA = (uint16_t) (p_cfg->period_counts - 1);

        /* Set period value to register TCORB 16-bit. */
        p_instance_ctrl->p_reg->TCORB = duty_cycle_counts;
    }
    else
    {
        /* Set period value to register TCORA 8-bit. */
        p_instance_ctrl->p_reg->TCORA_BY[p_instance_ctrl->index].TCORA = (uint8_t) (p_cfg->period_counts - 1);

        /* Set period value to register TCORB 8-bit. */
        p_instance_ctrl->p_reg->TCORB_BY[p_instance_ctrl->index].TCORB = (uint8_t) duty_cycle_counts;
    }
#endif

    /* Set value to Timer Control/Status Register. */
    p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index] = (uint8_t) tcsr;

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Reset Counter 16-bits */
        p_instance_ctrl->p_reg->TCNT = 0U;
    }
    else
    {
        /* Reset Counter 8-bits */
        p_instance_ctrl->p_reg->TCNT_BY[p_instance_ctrl->index].TCNT = 0U;
    }

    /* Enable required interrupts to bsp. */
    if (p_instance_ctrl->p_cfg->cycle_end_irq > 0)
    {
        R_BSP_IrqCfgEnable(p_instance_ctrl->p_cfg->cycle_end_irq,
                           (uint32_t) p_instance_ctrl->p_cfg->cycle_end_ipl,
                           p_instance_ctrl);
    }

    if (p_extend->output_compare_irq > 0)
    {
        R_BSP_IrqCfgEnable(p_extend->output_compare_irq, (uint32_t) p_extend->output_compare_ipl, p_instance_ctrl);
    }
}

/*******************************************************************************************************************//**
 * Sets period register and updates compare match registers in one-shot and periodic mode.
 *
 * @param[in]  p_instance_ctrl    Control block for this instance
 * @param[in]  period_counts      TMR period in counts
 **********************************************************************************************************************/
static void r_tmr_period_register_set (tmr_instance_ctrl_t * p_instance_ctrl, uint32_t period_counts)
{
    /* Store the period value so it can be retrieved later. */
    p_instance_ctrl->period = period_counts;

    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

#if TMR_CFG_OUTPUT_SUPPORT_ENABLE
    uint16_t duty_cycle_counts = 0U;
    if (TIMER_MODE_PERIODIC == p_instance_ctrl->p_cfg->mode)
    {
        duty_cycle_counts = (uint16_t) ((period_counts - 1U) >> 1);
    }
    else if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        duty_cycle_counts = (uint16_t) 0U;
    }
    else
    {
        /* Do nothing duty cycle should not be updated in R_TMR_PeriodSet. */
    }

    if (TIMER_MODE_PWM != p_instance_ctrl->p_cfg->mode)
    {
        if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
        {
            /* Set period value to register TCORB 16-bit. */
            p_instance_ctrl->p_reg->TCORB = duty_cycle_counts;
        }
        else
        {
            /* Set period value to register TCORB 8-bit. */
            p_instance_ctrl->p_reg->TCORB_BY[p_instance_ctrl->index].TCORB = (uint8_t) duty_cycle_counts;
        }
    }
#endif

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Set period value to register TCORA 16-bit. */
        p_instance_ctrl->p_reg->TCORA = (uint16_t) (period_counts - 1);
    }
    else
    {
        /* Set period value to register TCORA 8-bit. */
        p_instance_ctrl->p_reg->TCORA_BY[p_instance_ctrl->index].TCORA = (uint8_t) (period_counts - 1);
    }
}

/*******************************************************************************************************************//**
 * Configures TCCR registers based on user configurations to start timer.
 *
 * @param[in]     p_instance_ctrl  Pointer to TMR control structure
 **********************************************************************************************************************/
static void r_tmr_start_timer (tmr_instance_ctrl_t * const p_instance_ctrl)
{
    tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    uint32_t             tccr     = 0;

    /* Use internal clock source. */
    tccr |= (TMR_TCCR_CSS_INTERNAL_CLOCK_VALUE_MASK << R_TMR_TCCR_CSS_Pos) & R_TMR_TCCR_CSS_Msk;

    /* For setting TCCR.CKS. */
    switch (p_instance_ctrl->p_cfg->source_div)
    {
        case TIMER_SOURCE_DIV_1:
        {
            tccr |= (TMR_TCCR_SCK_DIV_1_MASK & R_TMR_TCCR_CKS_Msk);
            break;
        }

        case TIMER_SOURCE_DIV_2:
        {
            tccr |= (TMR_TCCR_SCK_DIV_2_MASK & R_TMR_TCCR_CKS_Msk);
            break;
        }

        case TIMER_SOURCE_DIV_8:
        {
            tccr |= (TMR_TCCR_SCK_DIV_8_MASK & R_TMR_TCCR_CKS_Msk);
            break;
        }

        case TIMER_SOURCE_DIV_32:
        {
            tccr |= (TMR_TCCR_SCK_DIV_32_MASK & R_TMR_TCCR_CKS_Msk);
            break;
        }

        case TIMER_SOURCE_DIV_64:
        {
            tccr |= (TMR_TCCR_SCK_DIV_64_MASK & R_TMR_TCCR_CKS_Msk);
            break;
        }

        case TIMER_SOURCE_DIV_1024:
        {
            tccr |= (TMR_TCCR_SCK_DIV_1024_MASK & R_TMR_TCCR_CKS_Msk);
            break;
        }

        case TIMER_SOURCE_DIV_8192:
        default:
        {
            tccr |= (TMR_TCCR_SCK_DIV_8192_MASK & R_TMR_TCCR_CKS_Msk);
            break;
        }
    }

    if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
    {
        /* Reset Counter 16-bits */
        p_instance_ctrl->p_reg->TCNT = 0U;
    }
    else
    {
        /* Reset Counter 8-bits */
        p_instance_ctrl->p_reg->TCNT_BY[p_instance_ctrl->index].TCNT = 0U;
    }

    /* Set value to TCCR register to start timer. */
    p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index] |= (uint8_t) tccr;
    FSP_HARDWARE_REGISTER_WAIT((uint8_t) tccr, p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index]);
}

/*******************************************************************************************************************//**
 * Calculates clock frequency of TMR counter.  Divides TMR clock by TMR clock divisor.
 *
 * @param[in]  p_instance_ctrl         Instance control block
 *
 * @return Clock frequency of the TMR counter.
 **********************************************************************************************************************/
static uint32_t r_tmr_clock_frequency_get (tmr_instance_ctrl_t * const p_instance_ctrl)
{
    uint32_t clock_freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_PCLKB);

    uint8_t div = (uint8_t) (p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index] & R_TMR_TCCR_CKS_Msk);
    switch (div)
    {
        case TMR_TCCR_SCK_DIV_1_MASK:
        {
            clock_freq_hz >>= TIMER_SOURCE_DIV_1;
            break;
        }

        case TMR_TCCR_SCK_DIV_2_MASK:
        {
            clock_freq_hz >>= TIMER_SOURCE_DIV_2;
            break;
        }

        case TMR_TCCR_SCK_DIV_8_MASK:
        {
            clock_freq_hz >>= TIMER_SOURCE_DIV_8;
            break;
        }

        case TMR_TCCR_SCK_DIV_32_MASK:
        {
            clock_freq_hz >>= TIMER_SOURCE_DIV_32;
            break;
        }

        case TMR_TCCR_SCK_DIV_64_MASK:
        {
            clock_freq_hz >>= TIMER_SOURCE_DIV_64;
            break;
        }

        case TMR_TCCR_SCK_DIV_1024_MASK:
        {
            clock_freq_hz >>= TIMER_SOURCE_DIV_1024;
            break;
        }

        case TMR_TCCR_SCK_DIV_8192_MASK:
        default:
        {
            clock_freq_hz >>= TIMER_SOURCE_DIV_8192;
            break;
        }
    }

    return clock_freq_hz;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl       Pointer to TMR instance control block
 * @param[in]     event                 Event code
 * @param[in]     capture               Event capture counts (if applicable)
 **********************************************************************************************************************/
static void r_tmr_call_callback (tmr_instance_ctrl_t * p_instance_ctrl, timer_event_t event, uint32_t capture)
{
    timer_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    timer_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->event     = event;
    p_args->capture   = capture;
    p_args->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Stops the timer if one-shot mode, clears interrupts, and calls callback if one was provided in the open function.
 **********************************************************************************************************************/
void tmr_overflow_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        tmr_extended_cfg_t * p_extend = (tmr_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
        uint32_t             tccr     = 0;

        /* Reconfigure the settings changed in the Start API. */
        volatile uint8_t tcsr = p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index];

        /* Stop timer*/
        p_instance_ctrl->p_reg->TCCR[p_instance_ctrl->control_index] = (uint8_t) (tccr & R_TMR_TCCR_TMRIS_Msk);

        if (TMR_COUNTER_SIZE_16_BIT == p_extend->counter_size)
        {
            /* Reset Counter 16-bits */
            p_instance_ctrl->p_reg->TCNT = 0U;
        }
        else
        {
            /* Reset Counter 8-bits */
            p_instance_ctrl->p_reg->TCNT_BY[p_instance_ctrl->index].TCNT = 0U;
        }

        if (0 != p_instance_ctrl->index % 2)
        {
            tcsr |= TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_1_3;
        }
        else
        {
            tcsr |= TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_0_2;
        }

        /* Restore TCSR. */
        p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index] = tcsr;

        /* Clear pending interrupt to make sure it doesn't fire again if another overflow has already occurred. */
        R_BSP_IrqClearPending(irq);
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_tmr_call_callback(p_instance_ctrl, TIMER_EVENT_CYCLE_END, 0);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

void tmr_compare_match_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    tmr_instance_ctrl_t * p_instance_ctrl = (tmr_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (TIMER_MODE_ONE_SHOT == p_instance_ctrl->p_cfg->mode)
    {
        /* Reconfigure the settings changed in the Start API. */
        volatile uint8_t tcsr = p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index];

        if (0 != p_instance_ctrl->index % 2)
        {
            tcsr |= TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_1_3;
        }
        else
        {
            tcsr |= TMR_TCSR_REG_UNDEFINE_VALUE_CHANNEL_0_2;
        }

        /* Restore TCSR. */
        p_instance_ctrl->p_reg->TCSR[p_instance_ctrl->index] = tcsr;

        /* Clear pending interrupt to make sure it doesn't fire again if another overflow has already occurred. */
        R_BSP_IrqClearPending(irq);
    }

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_tmr_call_callback(p_instance_ctrl, TIMER_EVENT_COMPARE_B, 0);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
