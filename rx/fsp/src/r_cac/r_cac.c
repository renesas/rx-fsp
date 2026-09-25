/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_cac.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "CAC" in ASCII, used to determine if channel is open. */
#define CAC_OPEN                        (0x00434143ULL)

/* CAC Control Register 0 Bit Field Definitions */
#define CAC_PRV_CACR0_CFME_OFFSET       (0U)
#define CAC_PRV_CACR0_CFME_MASK         (1U << CAC_PRV_CACR0_CFME_OFFSET)

/* CAC Control Register 1 Bit Field Definitions */
#define CAC_PRV_CACR1_CACREFE_OFFSET    (0U)
#define CAC_PRV_CACR1_CACREFE_MASK      (1U << CAC_PRV_CACR1_CACREFE_OFFSET)
#define CAC_PRV_CACR1_FMCS_OFFSET       (1U)
#define CAC_PRV_CACR1_FMCS_MASK         (0x07U << CAC_PRV_CACR1_FMCS_OFFSET)
#define CAC_PRV_CACR1_TCSS_OFFSET       (4U)
#define CAC_PRV_CACR1_TCSS_MASK         (0x03U << CAC_PRV_CACR1_TCSS_OFFSET)
#define CAC_PRV_CACR1_EDGES_OFFSET      (6U)
#define CAC_PRV_CACR1_EDGES_MASK        (0x03U << CAC_PRV_CACR1_EDGES_OFFSET)

/* CAC Control Register 2 Bit Field Definitions */
#define CAC_PRV_CACR2_RPS_OFFSET        (0U)
#define CAC_PRV_CACR2_RPS_MASK          (1U << CAC_PRV_CACR2_RPS_OFFSET)
#define CAC_PRV_CACR2_RSCS_OFFSET       (1U)
#define CAC_PRV_CACR2_RCSC_MASK         (0x07U << CAC_PRV_CACR2_RSCS_OFFSET)
#define CAC_PRV_CACR2_RCDS_OFFSET       (4U)
#define CAC_PRV_CACR2_RCDS_MASK         (0x03U << CAC_PRV_CACR2_RCDS_OFFSET)
#define CAC_PRV_CACR2_DFS_OFFSET        (6U)
#define CAC_PRV_CACR2_DFS_MASK          (0x03U << CAC_PRV_CACR2_DFS_OFFSET)

/* CAC Interrupt Control Register Bit Field Definitions */
#define CAC_PRV_CAICR_FERRIE_OFFSET     (0U)
#define CAC_PRV_CAICR_FERRIE_MASK       (1U << CAC_PRV_CAICR_FERRIE_OFFSET)
#define CAC_PRV_CAICR_MENDIE_OFFSET     (1U)
#define CAC_PRV_CAICR_MENDIE_MASK       (1U << CAC_PRV_CAICR_MENDIE_OFFSET)
#define CAC_PRV_CAICR_OVFIE_OFFSET      (2U)
#define CAC_PRV_CAICR_OVFIE_MASK        (1U << CAC_PRV_CAICR_OVFIE_OFFSET)
#define CAC_PRV_CAICR_FERRFCL_OFFSET    (4U)
#define CAC_PRV_CAICR_FERRFCL_MASK      (1U << CAC_PRV_CAICR_FERRFCL_OFFSET)
#define CAC_PRV_CAICR_MENDFCL_OFFSET    (5U)
#define CAC_PRV_CAICR_MENDFCL_MASK      (1U << CAC_PRV_CAICR_MENDFCL_OFFSET)
#define CAC_PRV_CAICR_OVFFCL_OFFSET     (6U)
#define CAC_PRV_CAICR_OVFFCL_MASK       (1U << CAC_PRV_CAICR_OVFFCL_OFFSET)

/* CAC Status Register Bit Field Definitions */
#define CAC_PRV_CASTR_FERRF_OFFSET      (0U)
#define CAC_PRV_CASTR_FERRF_MASK        (1U << CAC_PRV_CASTR_FERRF_OFFSET)
#define CAC_PRV_CASTR_MENDF_OFFSET      (1U)
#define CAC_PRV_CASTR_MENDF_MASK        (1U << CAC_PRV_CASTR_MENDF_OFFSET)
#define CAC_PRV_CASTR_OVFF_OFFSET       (2U)
#define CAC_PRV_CASTR_OVFF_MASK         (1U << CAC_PRV_CASTR_OVFF_OFFSET)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
void cac_ferri_isr(void);
void cac_mendi_isr(void);
void cac_ovfi_isr(void);

static void r_cac_hw_configure(cac_instance_ctrl_t * const p_instance_ctrl);
static void r_cac_isr_handler(cac_event_t event, uint32_t clear_mask);

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* CAC Implementation. */
const cac_api_t g_cac_on_cac =
{
    .open             = R_CAC_Open,
    .startMeasurement = R_CAC_StartMeasurement,
    .stopMeasurement  = R_CAC_StopMeasurement,
    .read             = R_CAC_Read,
    .callbackSet      = R_CAC_CallbackSet,
    .close            = R_CAC_Close,
};

/*******************************************************************************************************************//**
 * @addtogroup CAC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * The Open function configures the CAC based on the provided user configuration settings.
 *
 * @retval     FSP_SUCCESS                  CAC is available and available for measurement(s).
 * @retval     FSP_ERR_ASSERTION            An argument is invalid.
 * @retval     FSP_ERR_ALREADY_OPEN         The CAC has already been opened.
 * @retval     FSP_ERR_IP_UNIT_NOT_PRESENT  Unit does not exist on this MCU.
 *
 * @note       There is only a single CAC peripheral.
 **********************************************************************************************************************/
fsp_err_t R_CAC_Open (cac_ctrl_t * const p_ctrl, cac_cfg_t const * const p_cfg)
{
    cac_instance_ctrl_t * p_instance_ctrl = (cac_instance_ctrl_t *) p_ctrl;
    cac_extended_cfg_t  * p_extend        = (cac_extended_cfg_t *) p_cfg->p_extend;

    fsp_err_t err = FSP_SUCCESS;

#if (CAC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CAC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);

    uint32_t unit = p_extend->unit;

    /* Check that the unit is present*/
    FSP_ERROR_RETURN(unit < BSP_FEATURE_CAC_UNIT_COUNT, FSP_ERR_IP_UNIT_NOT_PRESENT);

    /* Ensure that upper limit is not less than the lower limit. If they are both the same (ie. 0) we will allow
     * measurement to proceed. */
    FSP_ASSERT(p_cfg->cac_upper_limit >= p_cfg->cac_lower_limit);
#endif

#if BSP_FEATURE_CAC_UNIT_COUNT == 1U
    R_CAC_Type * p_reg = R_CAC;
#else
    R_CAC_Type * p_reg =
        (R_CAC_Type *) (R_CAC_BASE + ((p_extend->unit) * (R_CAC1_BASE - R_CAC_BASE)));
#endif

    p_instance_ctrl->p_reg = p_reg;
    p_instance_ctrl->p_cfg = p_cfg;

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Configure the CAC per the configuration. */
    r_cac_hw_configure(p_instance_ctrl);

    /* Mark driver as open by initializing it to "CAC" - its ASCII equivalent. */
    p_instance_ctrl->open = CAC_OPEN;

    return err;
}

/*******************************************************************************************************************//**
 * Start the CAC measurement process.
 *
 * @retval     FSP_SUCCESS        CAC measurement started.
 * @retval     FSP_ERR_ASSERTION  NULL provided for p_instance_ctrl or p_cfg.
 * @retval     FSP_ERR_NOT_OPEN   R_CAC_Open() has not been successfully called.
 **********************************************************************************************************************/
fsp_err_t R_CAC_StartMeasurement (cac_ctrl_t * const p_ctrl)
{
    cac_instance_ctrl_t * p_instance_ctrl = (cac_instance_ctrl_t *) p_ctrl;

#if (CAC_CFG_PARAM_CHECKING_ENABLE == 1)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((CAC_OPEN == p_instance_ctrl->open), FSP_ERR_NOT_OPEN);
#endif

    /* Start CAC measurement. */
    p_instance_ctrl->p_reg->CACR0 = 1U;

    /* Read CFME bit to confirm the bit value has changed. See "CAC Control Register 0 (CACR0)" description of the
     * relevant hardware manual. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CACR0, 1U);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop the CAC measurement process.
 *
 * @retval     FSP_SUCCESS        CAC measuring has been stopped.
 * @retval     FSP_ERR_ASSERTION  NULL provided for p_instance_ctrl or p_cfg.
 * @retval     FSP_ERR_NOT_OPEN   R_CAC_Open() has not been successfully called.
 **********************************************************************************************************************/
fsp_err_t R_CAC_StopMeasurement (cac_ctrl_t * const p_ctrl)
{
    cac_instance_ctrl_t * p_instance_ctrl = (cac_instance_ctrl_t *) p_ctrl;

#if (CAC_CFG_PARAM_CHECKING_ENABLE == 1)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((CAC_OPEN == p_instance_ctrl->open), FSP_ERR_NOT_OPEN);
#endif

    /* Disable measurements. */
    p_instance_ctrl->p_reg->CACR0 = 0U;

    /* Read CFME bit to confirm the bit value has changed. See "CAC Control Register 0 (CACR0)" description of the relevant
     * hardware manual. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CACR0, 0);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read and return the CAC status and counter registers.
 *
 * @retval     FSP_SUCCESS        CAC read successful.
 * @retval     FSP_ERR_ASSERTION  An argument is NULL.
 * @retval     FSP_ERR_NOT_OPEN   R_CAC_Open() has not been successfully called.
 **********************************************************************************************************************/
fsp_err_t R_CAC_Read (cac_ctrl_t * const p_ctrl, uint32_t * const p_counter)
{
    cac_instance_ctrl_t * p_instance_ctrl = (cac_instance_ctrl_t *) p_ctrl;

#if (CAC_CFG_PARAM_CHECKING_ENABLE == 1)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_counter);
    FSP_ERROR_RETURN((CAC_OPEN == p_instance_ctrl->open), FSP_ERR_NOT_OPEN);
#endif

    /* Read the CAC count buffer. */
    *p_counter = p_instance_ctrl->p_reg->CACNTBR;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref cac_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_CAC_CallbackSet (cac_ctrl_t * const          p_ctrl,
                             void (                    * p_callback)(cac_callback_args_t *),
                             void * const                p_context,
                             cac_callback_args_t * const p_callback_memory)
{
    cac_instance_ctrl_t * p_instance_ctrl = (cac_instance_ctrl_t *) p_ctrl;

#if CAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(CAC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Release any resources that were allocated by the Open() or any subsequent CAC operations.
 *
 * @retval     FSP_SUCCESS        Successful close.
 * @retval     FSP_ERR_ASSERTION  NULL provided for p_instance_ctrl or p_cfg.
 * @retval     FSP_ERR_NOT_OPEN   R_CAC_Open() has not been successfully called.
 **********************************************************************************************************************/
fsp_err_t R_CAC_Close (cac_ctrl_t * const p_ctrl)
{
    cac_instance_ctrl_t * p_instance_ctrl = (cac_instance_ctrl_t *) p_ctrl;
#if (CAC_CFG_PARAM_CHECKING_ENABLE == 1)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN((CAC_OPEN == p_instance_ctrl->open), FSP_ERR_NOT_OPEN);
#endif

    /* Disable measurements. */
    p_instance_ctrl->p_reg->CACR0 = 0U;

    /* Disable interrupts. */
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->ferri_irq);
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->mendi_irq);
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->ovfi_irq);

    /* Read CFME bit to confirm the bit value has changed. See "CAC Control Register 0 (CACR0)" description of the relevant hardware manual. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CACR0, 0);

    /* Power down peripheral. */
    R_BSP_MODULE_STOP(FSP_IP_CAC, 0);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup CAC)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Write the configuration to CAC registers.
 * @param[in]  p_instance_ctrl  A pointer to the instance control structure.
 **********************************************************************************************************************/
static void r_cac_hw_configure (cac_instance_ctrl_t * const p_instance_ctrl)
{
    cac_cfg_t const * p_cfg = p_instance_ctrl->p_cfg;

    uint32_t cacr1 = 0;
    uint32_t cacr2 = 0;
    uint32_t caicr = 0;

    /* Apply power to the peripheral */
    R_BSP_MODULE_START(FSP_IP_CAC, 0);

    /* Disable measurements. */
    p_instance_ctrl->p_reg->CACR0 = 0;

    /* Read CFME bit to confirm the bit value has changed. See "CAC Control Register 0 (CACR0)" description
     * of the relevant hardware manual. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CACR0, 0);

    /* Clear interrupt status flags. */
    p_instance_ctrl->p_reg->CAICR = CAC_PRV_CAICR_FERRFCL_MASK | CAC_PRV_CAICR_MENDFCL_MASK | CAC_PRV_CAICR_OVFFCL_MASK;

    /* Configure measurement clock divider. */
    cacr1 |= (uint32_t) (p_instance_ctrl->p_cfg->cac_meas_clock.divider << CAC_PRV_CACR1_TCSS_OFFSET);

    if (p_cfg->cac_ref_clock.clock == CAC_CLOCK_SOURCE_EXTERNAL)
    {
        /* Enable CACREF. */
        cacr1 |= CAC_PRV_CACR1_CACREFE_MASK;
    }
    else
    {
        /* Configure the CAC reference clock. */
        cacr2 |= (uint32_t) (p_cfg->cac_ref_clock.clock << CAC_PRV_CACR2_RSCS_OFFSET) |
                 CAC_PRV_CACR2_RPS_MASK;
    }

    /* Configure edge detection. */
    cacr1 |= (uint32_t) (p_cfg->cac_ref_clock.edge << CAC_PRV_CACR1_EDGES_OFFSET);

    /* Configure the digital filter. */
    cacr2 |= (uint32_t) (p_cfg->cac_ref_clock.digfilter << CAC_PRV_CACR2_DFS_OFFSET);

    /* Configure reference clock divider. */
    cacr2 |= (uint32_t) (p_cfg->cac_ref_clock.divider << CAC_PRV_CACR2_RCDS_OFFSET);

    /* Configure the measurement clock. */
    cacr1 |= (uint32_t) (p_cfg->cac_meas_clock.clock << CAC_PRV_CACR1_FMCS_OFFSET);

    if (p_cfg->mendi_irq >= 0)
    {
        /* Enable the measurement end interrupt. */
        R_BSP_IrqCfgEnable(p_cfg->mendi_irq, (uint32_t) p_cfg->mendi_ipl, p_instance_ctrl);
        caicr |= CAC_PRV_CAICR_MENDIE_MASK;
    }

    if (p_instance_ctrl->p_cfg->ovfi_irq >= 0)
    {
        /* Enable the measurement overflow interrupt. */
        R_BSP_IrqCfgEnable(p_cfg->ovfi_irq, (uint32_t) p_cfg->ovfi_ipl, p_instance_ctrl);
        caicr |= CAC_PRV_CAICR_OVFIE_MASK;
    }

    if (p_cfg->ferri_irq >= 0)
    {
        /* Enable the frequency error interrupt. */
        R_BSP_IrqCfgEnable(p_cfg->ferri_irq, (uint32_t) p_cfg->ferri_ipl, p_instance_ctrl);
        caicr |= CAC_PRV_CAICR_FERRIE_MASK;
    }

    /* Write settings to registers. */
    p_instance_ctrl->p_reg->CACR1  = (uint8_t) cacr1;
    p_instance_ctrl->p_reg->CACR2  = (uint8_t) cacr2;
    p_instance_ctrl->p_reg->CAICR  = (uint8_t) caicr;
    p_instance_ctrl->p_reg->CAULVR = p_cfg->cac_upper_limit;
    p_instance_ctrl->p_reg->CALLVR = p_cfg->cac_lower_limit;
}

/*******************************************************************************************************************//**
 * Generic routine for handling all of the CAC interrupts.
 *
 * @param[in]  event           The event to pass into the callback args.
 * @param[in]  clear_mask      The status bit to clear.
 **********************************************************************************************************************/
static void r_cac_isr_handler (cac_event_t event, uint32_t clear_mask)
{
    IRQn_Type irq = R_FSP_CurrentIrqGet();
    volatile cac_instance_ctrl_t * p_instance_ctrl = (cac_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (NULL != p_instance_ctrl->p_callback)
    {
        /* Store callback arguments in memory provided by user if available. */
        cac_callback_args_t   args;
        cac_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
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
        p_args->p_context = p_instance_ctrl->p_context;

        p_instance_ctrl->p_callback(p_args);

        if (NULL != p_instance_ctrl->p_callback_memory)
        {
            /* Restore callback memory in case this is a nested interrupt. */
            *p_instance_ctrl->p_callback_memory = args;
        }
    }

    /* Clear the status flag. */
    uint32_t caicr = p_instance_ctrl->p_reg->CAICR;
    caicr |= ((uint8_t) clear_mask);
    p_instance_ctrl->p_reg->CAICR = (uint8_t) caicr;

    /* Depending on MPU and cache settings, the register may need to be read back to ensure the write happens before
     * clearing the IRQ in the ICU. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->CAICR);

    R_BSP_IrqStatusClear(irq);
}

/*******************************************************************************************************************//**
 * CAC Frequency error ISR.
 **********************************************************************************************************************/
void cac_ferri_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE
    /* Call isr handler */
    r_cac_isr_handler(CAC_EVENT_FREQUENCY_ERROR, CAC_PRV_CAICR_FERRFCL_MASK);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * CAC Overflow ISR.
 **********************************************************************************************************************/
void cac_ovfi_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE
    /* Call isr handler */
    r_cac_isr_handler(CAC_EVENT_COUNTER_OVERFLOW, CAC_PRV_CAICR_OVFFCL_MASK);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * CAC Measurement Complete ISR.
 **********************************************************************************************************************/
void cac_mendi_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE
    /* Call isr handler */
    r_cac_isr_handler(CAC_EVENT_MEASUREMENT_COMPLETE, CAC_PRV_CAICR_MENDFCL_MASK);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
