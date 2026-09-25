/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_icu.h"
#include "r_icu_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "ICU" in ASCII, used to determine if channel is open. */
#define ICU_OPEN                (0x00494355U)

#if BSP_FEATURE_ICU_VERSION == 2UL
 #define ICU_IRQMD_OFFSET       (0)

 #if BSP_FEATURE_ICU_HAS_FILTER
  #define ICU_FCLKSEL_OFFSET    (4)
  #define ICU_FLTEN_OFFSET      (7)
  #if BSP_FEATURE_ICU_HAS_LOCO_FILTER
   #define LOCO_CLOCK_HZ        (R_BSP_SourceClockHzGet(FSP_PRIV_CLOCK_LOCO))
   #define SYSTEM_CLOCK_HZ      (SystemCoreClock)
  #endif
 #endif

#else

/* IRQ0 to IRQ7 digital filters are set by IRQFLTE0 and IRQFLTC0.
 * IRQ8 to IRQ15 digital filters are set by IRQFLTE1 and IRQFLTC1.
 */
 #define ICU_IRQFLTE_REG_THRESHOLD    (8U)
 #define ICU_IRQFLTC_BIT_MSK          (0x3)

#endif

#define ICU_IRQCR_CH(c)    (c)
#define ICU_IRQCR_REG                 (R_ICU->IRQCR)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void r_icu_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* ICU implementation of External IRQ API. */
const external_irq_api_t g_external_irq_on_icu =
{
    .open        = R_ICU_ExternalIrqOpen,
    .enable      = R_ICU_ExternalIrqEnable,
    .disable     = R_ICU_ExternalIrqDisable,
    .callbackSet = R_ICU_ExternalIrqCallbackSet,
    .close       = R_ICU_ExternalIrqClose,
};

/*******************************************************************************************************************//**
 * @addtogroup ICU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configure an IRQ input pin for use with the external interrupt interface.  Implements @ref external_irq_api_t::open.
 *
 * The Open function is responsible for preparing an external IRQ pin for operation.
 *
 * @retval FSP_SUCCESS                    Open successful.
 * @retval FSP_ERR_ASSERTION              One of the following is invalid:
 *                                          - p_ctrl or p_cfg is NULL
 * @retval FSP_ERR_ALREADY_OPEN           The channel specified has already been opened. No configurations were changed.
 *                                        Call the associated Close function to reconfigure the channel.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The channel requested in p_cfg is not available on the device selected in
 *                                        r_bsp_cfg.h.
 * @retval FSP_ERR_INVALID_ARGUMENT       p_cfg->p_callback is not NULL, but ISR is not enabled. ISR must be enabled to
 *                                        use callback function.
 * @retval FSP_ERR_UNSUPPORTED            An input argument is not supported by selected mode.
 *
 * @note This function is reentrant for different channels.  It is not reentrant for the same channel.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqOpen (external_irq_ctrl_t * const p_api_ctrl, external_irq_cfg_t const * const p_cfg)
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);

    FSP_ASSERT(NULL != p_cfg);

 #if BSP_FEATURE_ICU_HAS_LOCO_FILTER || BSP_FEATURE_ICU_HAS_FILTER_MODE
    FSP_ASSERT(NULL != p_cfg->p_extend);
 #endif

 #if !BSP_FEATURE_ICU_HAS_FILTER

    /* Verify the configuration trigger source is correct */
    FSP_ERROR_RETURN((EXTERNAL_IRQ_TRIG_FALLING == p_cfg->trigger) ||
                     (EXTERNAL_IRQ_TRIG_RISING == p_cfg->trigger) ||
                     (EXTERNAL_IRQ_TRIG_BOTH_EDGE == p_cfg->trigger) ||
                     (EXTERNAL_IRQ_TRIG_LEVEL_LOW == p_cfg->trigger),
                     FSP_ERR_UNSUPPORTED);
 #endif

    FSP_ERROR_RETURN(0 != ((1ULL << p_cfg->channel) & BSP_FEATURE_ICU_IRQ_CHANNELS_MASK),
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    /* Callback must be used with a valid interrupt priority otherwise it will never be called. */
    if (p_cfg->p_callback)
    {
        FSP_ERROR_RETURN(BSP_IRQ_DISABLED != p_cfg->ipl, FSP_ERR_INVALID_ARGUMENT);
    }
#endif

    p_ctrl->irq = p_cfg->irq;

    /* Disable the interrupt. */
    R_BSP_IrqDisable(p_ctrl->irq);

    /* Initialize control block. */
    p_ctrl->p_callback = p_cfg->p_callback;
    p_ctrl->p_context  = p_cfg->p_context;
    p_ctrl->channel    = p_cfg->channel;

#if BSP_FEATURE_ICU_VERSION == 2UL
    uint8_t channel = ICU_IRQCR_CH(p_ctrl->channel);
    uint8_t irqcr   = 0;

 #if BSP_FEATURE_ICU_HAS_FILTER

    /* Disable digital filter */
    ICU_IRQCR_REG[channel].IRQCR = 0U;

  #if BSP_FEATURE_ICU_HAS_LOCO_FILTER || BSP_FEATURE_ICU_HAS_FILTER_MODE
    icu_extended_cfg_t * p_extend = (icu_extended_cfg_t *) p_cfg->p_extend;

   #if BSP_FEATURE_ICU_HAS_LOCO_FILTER

    /* Set the digital filter divider. */
    irqcr = (uint8_t) (p_extend->filter_src << R_ICU_IRQCR_LOCOSEL_Pos);
   #endif

   #if BSP_FEATURE_ICU_HAS_FILTER_MODE

    /* Set the digital filter mode. */
    irqcr |= (uint8_t) (p_extend->filter_mode << R_ICU_IRQCR_FLTMD_Pos);
   #endif
  #endif

    /* Set the digital filter divider. */
    irqcr |= (uint8_t) (p_cfg->clock_source_div << ICU_FCLKSEL_OFFSET);

    /* Enable/Disable digital filter. */
    irqcr |= (uint8_t) (p_cfg->filter_enable << ICU_FLTEN_OFFSET);

    /* Set the IRQ trigger. */
    irqcr |= (uint8_t) (p_cfg->trigger << ICU_IRQMD_OFFSET);
 #else
    irqcr = (uint8_t) (p_cfg->trigger << ICU_IRQMD_OFFSET);
 #endif

    if (EXTERNAL_IRQ_TRIG_LEVEL_LOW != p_cfg->trigger)
    {
        /* Clear IR flag. */
        R_BSP_IrqStatusClear(p_ctrl->irq);
    }

    /* Write IRQCR */
    ICU_IRQCR_REG[channel].IRQCR = irqcr;
 #if BSP_FEATURE_ICU_HAS_LOCO_FILTER

    /* If LOCO is used as Digital Filtering Sample Clock, delay 4 LOCO clock cycles before restore IELSR */
    if (EXTERNAL_IRQ_DIGITAL_FILTER_LOCO == p_extend->filter_src)
    {
        /* If LOCO is used as Digital Filtering Sample Clock, delay 4 LOCO clock cycles before restore IELSR.
         * Total_cycles = (4 * system_clock_hz) / (loco_clock_hz).
         */
        uint32_t total_cycles = (uint32_t) ((4 * SYSTEM_CLOCK_HZ) / LOCO_CLOCK_HZ);

        bsp_prv_software_delay_loop(BSP_DELAY_LOOPS_CALCULATE(total_cycles));
    }
 #endif
#else
    uint8_t digital_filter_reg;
    uint8_t digital_filter_channel_bit;

    /* Get the register number of IRQFLTE. */
    digital_filter_reg = (uint8_t) (p_ctrl->channel / ICU_IRQFLTE_REG_THRESHOLD);

    /* Get the bit number of FLTEN. */
    digital_filter_channel_bit = (uint8_t) (p_ctrl->channel % ICU_IRQFLTE_REG_THRESHOLD);

    /* Disable digital filter */
    R_ICU->IRQFLTE[digital_filter_reg].IRQFLTE &= (uint8_t) ~(1U << digital_filter_channel_bit);

    /* Clear the digital filter sampling clock. */
    R_ICU->IRQFLTC[digital_filter_reg].IRQFLTC &=
        (uint16_t) ~(ICU_IRQFLTC_BIT_MSK << (digital_filter_channel_bit * 2));

    /* Set the digital filter sampling clock. */
    R_ICU->IRQFLTC[digital_filter_reg].IRQFLTC |=
        (uint16_t) (p_cfg->clock_source_div << (digital_filter_channel_bit * 2));

    /* Set the IRQ trigger. */
    R_ICU->IRQCR[p_ctrl->channel].IRQCR =
        (uint8_t) ((p_cfg->trigger << R_ICU_IRQCR_IRQCR_IRQMD_Pos) & R_ICU_IRQCR_IRQCR_IRQMD_Msk);

    if (EXTERNAL_IRQ_TRIG_LEVEL_LOW != p_cfg->trigger)
    {
        /* Clear IR flag. */
        R_BSP_IrqStatusClear(p_ctrl->irq);
    }

    /* Enable/Disable digital filter. */
    R_ICU->IRQFLTE[digital_filter_reg].IRQFLTE |= (uint8_t) (p_cfg->filter_enable << digital_filter_channel_bit);
#endif

    /* NOTE: User can have the driver opened when the IRQ is not in the vector table. This is for use cases
     * where the external IRQ driver is used to generate ELC events only (without CPU interrupts).
     * In such cases we will not set the IRQ priority but will continue with the processing.
     */
    if (p_ctrl->irq >= 0)
    {
        R_BSP_IrqCfg(p_ctrl->irq, (uint32_t) p_cfg->ipl, p_ctrl);
    }

    /* Mark the control block as open */
    p_ctrl->open = ICU_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable external interrupt for specified channel at ICU. Implements @ref external_irq_api_t::enable.
 *
 * @retval FSP_SUCCESS                 Interrupt Enabled successfully.
 * @retval FSP_ERR_ASSERTION           The p_ctrl parameter was null.
 * @retval FSP_ERR_NOT_OPEN            The channel is not opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    Requested IRQ is not defined in this system
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqEnable (external_irq_ctrl_t * const p_api_ctrl)
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(p_ctrl->irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
#endif

    /* Clear the interrupt status and Pending bits, before the interrupt is enabled. */
    R_BSP_IrqEnable(p_ctrl->irq);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable external interrupt for specified channel at ICU. Implements @ref external_irq_api_t::disable.
 *
 * @retval FSP_SUCCESS                 Interrupt disabled successfully.
 * @retval FSP_ERR_ASSERTION           The p_ctrl parameter was null.
 * @retval FSP_ERR_NOT_OPEN            The channel is not opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED    Requested IRQ is not defined in this system
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqDisable (external_irq_ctrl_t * const p_api_ctrl)
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(p_ctrl->irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
#endif

    /* Disable the interrupt, and then clear the interrupt pending bits and interrupt status. */
    R_BSP_IrqDisable(p_ctrl->irq);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements external_irq_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqCallbackSet (external_irq_ctrl_t * const p_api_ctrl,
                                        void (                    * p_callback)(
                                            external_irq_callback_args_t *),
                                        void * const                         p_context,
                                        external_irq_callback_args_t * const p_callback_memory)
{
    icu_instance_ctrl_t * p_ctrl = p_api_ctrl;

    FSP_PARAMETER_NOT_USED(p_callback_memory);

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_callback);
#endif

    p_ctrl->p_callback = p_callback;
    p_ctrl->p_context  = p_context;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the external interrupt channel. Implements @ref external_irq_api_t::close.
 *
 * @retval     FSP_SUCCESS          Successfully closed.
 * @retval     FSP_ERR_ASSERTION    The parameter p_ctrl is NULL.
 * @retval     FSP_ERR_NOT_OPEN     The channel is not opened.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ExternalIrqClose (external_irq_ctrl_t * const p_api_ctrl)
{
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) p_api_ctrl;

#if ICU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(ICU_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Cleanup. Disable interrupt */
    if (p_ctrl->irq >= 0)
    {
        /* Disable the interrupt, and then clear the interrupt pending bits and interrupt status. */
        R_BSP_IrqDisable(p_ctrl->irq);
        R_FSP_IsrContextSet(p_ctrl->irq, NULL);
    }

    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup ICU)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * ICU External Interrupt ISR.
 **********************************************************************************************************************/
void r_icu_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type             irq    = R_FSP_CurrentIrqGet();
    icu_instance_ctrl_t * p_ctrl = (icu_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if ((NULL != p_ctrl) && (NULL != p_ctrl->p_callback))
    {
        /* Set data to identify callback to user, then call user callback. */
        external_irq_callback_args_t args;
        args.channel   = p_ctrl->channel;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
