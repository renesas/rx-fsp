/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_elc.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "ELC" in ASCII, used to determine if the module is open */
#define ELC_OPEN                  (0x00454C43U)
#define ELC_CLOSED                (0x00000000U)

#define ELC_ELCR_ELCON_DISABLE    (0x00U)
#define ELC_ELCR_ELCON_ENABLE     (0x80U)

/* Steps necessary to unlock and write software event generation bits */
#define ELC_ELSEGRN_STEP1         (0x00U) /* WI = 0, WE = 0, SEG = 0 */
#define ELC_ELSEGRN_STEP2         (0x40U) /* WI = 0, WE = 1, SEG = 0 */
#define ELC_ELSEGRN_STEP3         (0x41U) /* WI = 0, WE = 1, SEG = 1 */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

#if ELC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_elc_common_parameter_checking(elc_instance_ctrl_t * p_instance_ctrl);

#endif

#if BSP_FEATURE_ELC_HAS_ELOP
static fsp_err_t r_bsp_elc_config_operation_select(const elc_cfg_extend_t * p_extend);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
void r_elc_isr(void);

static void r_elc_enable_interrupts(elc_instance_ctrl_t * const p_instance_ctrl);
static void r_elc_disable_interrupts(elc_instance_ctrl_t * const p_instance_ctrl);

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** ELC API structure.  */
const elc_api_t g_elc_on_elc =
{
    .open                  = R_ELC_Open,
    .close                 = R_ELC_Close,
    .softwareEventGenerate = R_ELC_SoftwareEventGenerate,
    .linkSet               = R_ELC_LinkSet,
    .linkBreak             = R_ELC_LinkBreak,
    .enable                = R_ELC_Enable,
    .disable               = R_ELC_Disable,
};

/*******************************************************************************************************************//**
 * @addtogroup ELC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize all the links in the Event Link Controller. Implements @ref elc_api_t::open
 *
 * The configuration structure passed in to this function includes links for every event source included in the ELC
 * and sets them all at once. To set or clear an individual link use R_ELC_LinkSet and R_ELC_LinkBreak respectively.
 *
 * Example:
 * @snippet r_elc_example.c R_ELC_Open
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       p_ctrl or p_cfg was NULL
 * @retval FSP_ERR_ALREADY_OPEN    The module is currently open
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Open (elc_ctrl_t * const p_ctrl, elc_cfg_t const * const p_cfg)
{
    uint32_t i;
    uint64_t i_shift = 1;

    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;

#if ELC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
 #if BSP_FEATURE_ELC_HAS_ELOP
    FSP_ASSERT(NULL != p_cfg->p_extend);
 #endif
    FSP_ERROR_RETURN(ELC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    elc_cfg_extend_t * p_extend = (elc_cfg_extend_t *) p_cfg->p_extend;
    p_instance_ctrl->p_context = p_extend;

#if ELC_CFG_PARAM_CHECKING_ENABLE
    for (uint8_t event_idx = 0; event_idx < ELC_INTERRUPT_NUM; event_idx++)
    {
        if (BSP_IRQ_DISABLED != p_extend->ipl[event_idx])
        {
            FSP_ASSERT(NULL != p_extend->p_callback);
        }
    }
#endif

    /* Power on ELC */
    R_BSP_MODULE_START(FSP_IP_ELC, 0);

    /* Loop through all links and set or clear them in the ELC block */
    for (i = 0; i < ELC_PERIPHERAL_NUM; i++)
    {
        i_shift = ((i % ELC_PERIPHERAL_MASK_SIZE) == 0) ? 1 : (i_shift << 1);

        /* Check to ensure the MCU we are using actually has this event link option */
        if (elc_peripheral_mask[(uint32_t) (i / ELC_PERIPHERAL_MASK_SIZE)] & i_shift)
        {
            R_ELC->ELSR[i].HA = (uint16_t) p_cfg->link[i];
        }
    }

    /* Enable interrupts */
    r_elc_enable_interrupts(p_instance_ctrl);

#if BSP_FEATURE_ELC_HAS_ELOP

    /* Configure event link option operation selections if user provided extension */
    r_bsp_elc_config_operation_select((elc_cfg_extend_t *) p_cfg->p_extend);
#endif

    /* Set driver status to open */
    p_instance_ctrl->open = ELC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Globally disable ELC linking. Implements @ref elc_api_t::close
 *
 * @retval FSP_SUCCESS             The ELC was successfully disabled
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Close (elc_ctrl_t * const p_ctrl)
{
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;

#if ELC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Set state to closed */
    p_instance_ctrl->open = ELC_CLOSED;

    /* Disable interrupts */
    r_elc_disable_interrupts(p_instance_ctrl);

    uint8_t volatile * p_elcr = &R_ELC->ELCR;

    /* Globally disable the operation of the Event Link Controller */
    *p_elcr = ELC_ELCR_ELCON_DISABLE;

    /* Power off ELC */
    R_BSP_MODULE_STOP(FSP_IP_ELC, 0);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Generate a software event in the Event Link Controller. Implements @ref elc_api_t::softwareEventGenerate
 *
 * Example:
 * @snippet r_elc_example.c R_ELC_SoftwareEventGenerate
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       Invalid event number or p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 **********************************************************************************************************************/
fsp_err_t R_ELC_SoftwareEventGenerate (elc_ctrl_t * const p_ctrl, elc_software_event_t event_number)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    FSP_PARAMETER_NOT_USED(p_ctrl);

    uint8_t volatile * p_elsegrn = &R_ELC->ELSEGR[event_number].BY;

    /* Set the ELSEGR bits in the correct order (see "Event Link Software Event Generation Register n
     * (ELSEGRn) (n = 0, 1)" description in the ELC section of the relevant hardware manual). */

    /* Step 1. enable the ELSEGR0 register for writing */
    *p_elsegrn = ELC_ELSEGRN_STEP1;

    /* Step 2. Enable the SEG bit for writing */
    *p_elsegrn = ELC_ELSEGRN_STEP2;

    /* Step 3. Set the SEG bit which causes the software event generation */
    *p_elsegrn = ELC_ELSEGRN_STEP3;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Create a single event link. Implements @ref elc_api_t::linkSet
 *
 * Example:
 * @snippet r_elc_example.c R_ELC_LinkSet
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_LinkSet (elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral, elc_event_t signal)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Set the event link register for the corresponding peripheral to the given signal */
    R_ELC->ELSR[(uint32_t) peripheral].HA = (uint16_t) signal;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Break an event link. Implements @ref elc_api_t::linkBreak
 *
 * @retval FSP_SUCCESS             Event link broken
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_LinkBreak (elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Clear the corresponding peripheral event link register to break the link */
    R_ELC->ELSR[(uint32_t) peripheral].HA = ELC_EVENT_NONE;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable the operation of the Event Link Controller. Implements @ref elc_api_t::enable
 *
 * @retval FSP_SUCCESS           ELC enabled.
 * @retval FSP_ERR_ASSERTION     p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN      The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Enable (elc_ctrl_t * const p_ctrl)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    uint8_t volatile * p_elcr = &R_ELC->ELCR;

    /* Globally enable ELC function */
    *p_elcr = ELC_ELCR_ELCON_ENABLE;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable the operation of the Event Link Controller. Implements @ref elc_api_t::disable
 *
 * @retval FSP_SUCCESS           ELC disabled.
 * @retval FSP_ERR_ASSERTION     p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN      The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Disable (elc_ctrl_t * const p_ctrl)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    uint8_t volatile * p_elcr = &R_ELC->ELCR;

    /* Globally disable ELC function */
    *p_elcr = ELC_ELCR_ELCON_DISABLE;

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @} (end addtogroup ELC)
 **********************************************************************************************************************/

#if ELC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Verifies the control structure is not NULL and the module is open. This reduces code size when the error logger is
 * used.
 *
 * @param[in]  p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                  No error detected.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN             Module is not open.
 **********************************************************************************************************************/
static fsp_err_t r_elc_common_parameter_checking (elc_instance_ctrl_t * p_instance_ctrl)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ELC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    return FSP_SUCCESS;
}

#endif

#if BSP_FEATURE_ELC_HAS_ELOP

/*******************************************************************************************************************//**
 * Configure ELC CMT/CMTW/TMR operation selections using provided extension values.
 * This function applies user-provided configuration values using BSP feature macros.
 * Configuration is driven by BSP feature macros, allowing per-device customization.
 *
 * @param[in]  p_extend             Pointer to extension configuration with operation values
 *
 * @retval FSP_SUCCESS             Configuration was successful
 **********************************************************************************************************************/
fsp_err_t r_bsp_elc_config_operation_select (const elc_cfg_extend_t * p_extend)
{
 #if BSP_FEATURE_ELC_CMT1_ELOP_AVAILABLE

    /* Configure CMT1 Operation Select using feature-driven register/mask/position */
    BSP_FEATURE_ELC_CMT1_ELOP_REG = (uint8_t) ((BSP_FEATURE_ELC_CMT1_ELOP_REG & ~BSP_FEATURE_ELC_CMT1_ELOP_MASK) |
                                               (p_extend->cmt1_md << BSP_FEATURE_ELC_CMT1_ELOP_POS));
 #endif

 #if BSP_FEATURE_ELC_CMTW0_ELOP_AVAILABLE

    /* Configure CMTW0 Operation Select using feature-driven register/mask/position */
    BSP_FEATURE_ELC_CMTW0_ELOP_REG = (uint8_t) ((BSP_FEATURE_ELC_CMTW0_ELOP_REG & ~BSP_FEATURE_ELC_CMTW0_ELOP_MASK) |
                                                (p_extend->cmtw0_md << BSP_FEATURE_ELC_CMTW0_ELOP_POS));
 #endif

 #if BSP_FEATURE_ELC_TMR0_ELOP_AVAILABLE

    /* Configure TMR0 Operation Select using feature-driven register/mask/position */
    BSP_FEATURE_ELC_TMR0_ELOP_REG = (uint8_t) ((BSP_FEATURE_ELC_TMR0_ELOP_REG & ~BSP_FEATURE_ELC_TMR0_ELOP_MASK) |
                                               (p_extend->tmr0_md << BSP_FEATURE_ELC_TMR0_ELOP_POS));
 #endif

 #if BSP_FEATURE_ELC_TMR1_ELOP_AVAILABLE

    /* Configure TMR1 Operation Select using feature-driven register/mask/position */
    BSP_FEATURE_ELC_TMR1_ELOP_REG = (uint8_t) ((BSP_FEATURE_ELC_TMR1_ELOP_REG & ~BSP_FEATURE_ELC_TMR1_ELOP_MASK) |
                                               (p_extend->tmr1_md << BSP_FEATURE_ELC_TMR1_ELOP_POS));
 #endif

 #if BSP_FEATURE_ELC_TMR2_ELOP_AVAILABLE

    /* Configure TMR2 Operation Select using feature-driven register/mask/position */
    BSP_FEATURE_ELC_TMR2_ELOP_REG = (uint8_t) ((BSP_FEATURE_ELC_TMR2_ELOP_REG & ~BSP_FEATURE_ELC_TMR2_ELOP_MASK) |
                                               (p_extend->tmr2_md << BSP_FEATURE_ELC_TMR2_ELOP_POS));
 #endif

 #if BSP_FEATURE_ELC_TMR3_ELOP_AVAILABLE

    /* Configure TMR3 Operation Select using feature-driven register/mask/position */
    BSP_FEATURE_ELC_TMR3_ELOP_REG = (uint8_t) ((BSP_FEATURE_ELC_TMR3_ELOP_REG & ~BSP_FEATURE_ELC_TMR3_ELOP_MASK) |
                                               (p_extend->tmr3_md << BSP_FEATURE_ELC_TMR3_ELOP_POS));
 #endif

    return FSP_SUCCESS;
}

#endif

/***********************************************************************************************************************
 * @brief Enable all elc interrupts
 * @param p_instance_ctrl - pointer to elc instance control structure
 * @return None
 **********************************************************************************************************************/
static void r_elc_enable_interrupts (elc_instance_ctrl_t * const p_instance_ctrl)
{
    elc_cfg_extend_t * p_extend = (elc_cfg_extend_t *) p_instance_ctrl->p_context;

    for (uint32_t i = 0; i < ELC_INTERRUPT_NUM; i++)
    {
        if (0 <= p_extend->irq[i])
        {
            R_BSP_IrqCfgEnable(p_extend->irq[i], p_extend->ipl[i], p_instance_ctrl);
        }
    }
}

/***********************************************************************************************************************
 * @brief Disable all elc interrupts
 * @param p_instance_ctrl - pointer to elc instance control structure
 * @return None
 **********************************************************************************************************************/
static void r_elc_disable_interrupts (elc_instance_ctrl_t * const p_instance_ctrl)
{
    elc_cfg_extend_t * p_extend = (elc_cfg_extend_t *) p_instance_ctrl->p_context;

    for (uint32_t i = 0; i < ELC_INTERRUPT_NUM; i++)
    {
        if (0 <= p_extend->irq[i])
        {
            R_BSP_IrqDisable(p_extend->irq[i]);
            R_FSP_IsrContextSet(p_extend->irq[i], NULL);
        }
    }
}

/*******************************************************************************************************************//**
 * ELC Interrupt ISR.
 **********************************************************************************************************************/
void r_elc_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type             irq             = R_FSP_CurrentIrqGet();
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    elc_cfg_extend_t    * p_extend        = (elc_cfg_extend_t *) p_instance_ctrl->p_context;

    if ((NULL != p_extend) && (NULL != p_extend->p_callback))
    {
        /* Set data to identify callback to user, then call user callback. */
        elc_callback_args_t args;
        args.event     = bsp_elc_interrutp_factor((uint8_t) (irq & 0xff)); // NOLINT(readability-magic-numbers)
        args.p_context = p_extend->p_context;
        p_extend->p_callback(&args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
