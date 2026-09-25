/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_iwdt.h"
#include "bsp_api.h"
#include "bsp_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "IWDT" in ASCII.  Used to determine if the control block is open. */
#define IWDT_OPEN    (0X49574454ULL)

/* Lookup functions for IWDT settings.  Using function like macro for stringification. */
#define IWDT_PRV_OFS0_SETTING_GET(setting)     (((uint32_t) BSP_CFG_OPTION_SETTING_OFS0 >> \
                                                 IWDT_PRV_OFS0_ ## setting ## _BIT) &      \
                                                IWDT_PRV_OFS0_ ## setting ## _MASK);
#define IWDT_PRV_IWDTCR_SETTING_GET(setting,                                                       \
                                    iwdtcr)    (((iwdtcr >> IWDT_PRV_IWDTCR_ ## setting ## _BIT) & \
                                                 IWDT_PRV_IWDTCR_ ## setting ## _MASK));
#define IWDT_PRV_IWDTCR_SETTING_SET(setting,                                                      \
                                    value)     ((value & IWDT_PRV_IWDTCR_ ## setting ## _MASK) << \
                                                IWDT_PRV_IWDTCR_ ## setting ## _BIT);

/* OFS0 register settings. */
#define IWDT_PRV_OFS0_AUTO_START_MASK          (0x00000002U)
#define IWDT_PRV_OFS0_TIMEOUT_BIT              (2U)
#define IWDT_PRV_OFS0_TIMEOUT_MASK             (0x00000003U)
#define IWDT_PRV_OFS0_NMI_REQUEST_MASK         (0x00001000U)
#define IWDT_PRV_OFS0_CLOCK_DIVISION_BIT       (4U)
#define IWDT_PRV_OFS0_CLOCK_DIVISION_MASK      (0x0000000FU)

/* Status register settings. */
#define IWDT_PRV_STATUS_START_BIT              (14U) /*Bit 14 and Bit 15*/

/* Reset Control register settings. */
#define IWDT_PRV_IWDTRCR_RESET_CONTROL_BIT     (7U)

/* Count Stop Count Control register settings. */
#define IWDT_PRV_IWDTCSTPR_STOP_CONTROL_BIT    (7U)

/* Status register settings. */
#define IWDT_PRV_IWDTSR_COUNTER_MASK           (0x3FFFU)

/* Control register settings. */
#define IWDT_PRV_IWDTCR_TIMEOUT_BIT            (0)  // Bits 0-1
#define IWDT_PRV_IWDTCR_TIMEOUT_MASK           (0x3U)
#define IWDT_PRV_IWDTCR_CLOCK_DIVISION_BIT     (4)  // Bits 4-7
#define IWDT_PRV_IWDTCR_CLOCK_DIVISION_MASK    (0xFU)
#define IWDT_PRV_IWDTCR_WINDOW_END_BIT         (8)  // Bits 8-9
#define IWDT_PRV_IWDTCR_WINDOW_END_MASK        (0x3U)
#define IWDT_PRV_IWDTCR_WINDOW_START_BIT       (12) // Bits 12-13
#define IWDT_PRV_IWDTCR_WINDOW_START_MASK      (0x3U)

/* Refresh register values */
#define IWDT_PRV_REFRESH_STEP_1                (0U)
#define IWDT_PRV_REFRESH_STEP_2                (0xFFU)

/* Macros for start mode and NMI/IRQ support. */
#if (BSP_CFG_OPTION_SETTING_OFS0 & IWDT_PRV_OFS0_AUTO_START_MASK)
 #if (BSP_FEATURE_IWDT_SUPPORTS_REGISTER_START_MODE)

/* Register start mode */
  #define IWDT_PRV_REGISTER_START_MODE    (1U)
  #define IWDT_PRV_NMI_SUPPORTED          (IWDT_CFG_NMI_SUPPORTED)
  #define IWDT_PRV_IRQ_SUPPORTED          (IWDT_CFG_IRQ_SUPPORTED)
 #else
  #define IWDT_PRV_REGISTER_START_MODE    (0U)
  #define IWDT_PRV_NMI_SUPPORTED          (0U)
  #define IWDT_PRV_IRQ_SUPPORTED          (0U)
 #endif
 #define IWDT_PRV_AUTO_START_MODE         (0U)
#else

/* Auto start mode */
 #define IWDT_PRV_AUTO_START_MODE         (1)
 #define IWDT_PRV_REGISTER_START_MODE     (0)
 #if (BSP_CFG_OPTION_SETTING_OFS0 & IWDT_PRV_OFS0_NMI_REQUEST_MASK)
  #define IWDT_PRV_NMI_SUPPORTED          (0)
  #define IWDT_PRV_IRQ_SUPPORTED          (0)
 #else
  #define IWDT_PRV_NMI_SUPPORTED          (IWDT_CFG_NMI_SUPPORTED)
  #define IWDT_PRV_IRQ_SUPPORTED          (IWDT_CFG_IRQ_SUPPORTED)
 #endif
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static uint32_t iwdt_clock_divider_get(wdt_clock_division_t division);

#if IWDT_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t iwdt_parameter_checking(iwdt_instance_ctrl_t * const p_instance_ctrl, wdt_cfg_t const * const p_cfg);

#endif

#if IWDT_PRV_NMI_SUPPORTED
static void iwdt_nmi_internal_callback(bsp_grp_irq_nmi_t irq);
static void iwdt_nmi_initialize(iwdt_instance_ctrl_t * const p_instance_ctrl);

#endif

void iwdt_iwuni_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Convert IWDT timeout value to an integer */
static const uint16_t g_iwdt_timeout[] =
{
    128U,
    512U,
    1024U,
    2048U,
};

/* Converts IWDT division enum to log base 2 of the division value, used to shift the PCLKB frequency. */
static const uint8_t g_iwdt_division_lookup[] =
{
    0U,                                // log base 2(1)    = 0
    2U,                                // log base 2(4)    = 2
    4U,                                // log base 2(16)   = 4
    5U,                                // log base 2(32)   = 5
    6U,                                // log base 2(64)   = 6
    8U,                                // log base 2(256)  = 8
    9U,                                // log base 2(512)  = 9
    11U,                               // log base 2(2048) = 11
    13U,                               // log base 2(8192) = 13
};

/* Global pointer to control structure for use by the NMI callback. */
#if IWDT_PRV_NMI_SUPPORTED
static volatile iwdt_instance_ctrl_t * gp_iwdt_ctrl = NULL;
#endif

/* Watchdog implementation of IWDT Driver. */
const wdt_api_t g_wdt_on_iwdt =
{
    .open        = R_IWDT_Open,
    .refresh     = R_IWDT_Refresh,
    .statusGet   = R_IWDT_StatusGet,
    .statusClear = R_IWDT_StatusClear,
    .counterGet  = R_IWDT_CounterGet,
    .timeoutGet  = R_IWDT_TimeoutGet,
    .callbackSet = R_IWDT_CallbackSet,
};

/*******************************************************************************************************************//**
 * @addtogroup IWDT
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Register the IWDT NMI callback.
 *
 * Example:
 * @snippet r_iwdt_example.c R_IWDT_Open
 *
 * @retval FSP_SUCCESS              IWDT successfully configured.
 * @retval FSP_ERR_ASSERTION        Null Pointer.
 * @retval FSP_ERR_NOT_ENABLED      An attempt to open the IWDT when the OFS0 register is not
 *                                  configured for auto-start mode.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.  This module can only be opened once.
 **********************************************************************************************************************/
fsp_err_t R_IWDT_Open (wdt_ctrl_t * const p_api_ctrl, wdt_cfg_t const * const p_cfg)
{
    iwdt_instance_ctrl_t * p_ctrl = (iwdt_instance_ctrl_t *) p_api_ctrl;

#if IWDT_CFG_PARAM_CHECKING_ENABLE

    /* Check validity of the parameters */
    fsp_err_t err = iwdt_parameter_checking(p_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    p_ctrl->p_callback = p_cfg->p_callback;
    p_ctrl->p_context  = p_cfg->p_context;

#if IWDT_PRV_NMI_SUPPORTED
    if (p_cfg->reset_control == WDT_RESET_CONTROL_NMI)
    {
        /* Register callback with BSP NMI ISR. */
        iwdt_nmi_initialize(p_ctrl);
    }

#elif IWDT_PRV_IRQ_SUPPORTED

    /* Enable */
    if (p_cfg->reset_control == WDT_RESET_CONTROL_NMI)
    {
        iwdt_extended_cfg_t * p_extend = (iwdt_extended_cfg_t *) p_cfg->p_extend;
        R_BSP_IrqCfgEnable(p_extend->irq, (uint32_t) (p_extend->ipl), p_ctrl);
    }
#endif

    /* Configuration only valid when IWDT operating in register-start mode. */
#if IWDT_PRV_REGISTER_START_MODE

    /* Register-start mode. */
    /* Set the configuration registers in register start mode. */
    R_IWDT->IWDTRCR_b.RSTIRQS = (uint8_t) (p_cfg->reset_control == WDT_RESET_CONTROL_RESET);

    uint32_t iwdtcr = IWDT_PRV_IWDTCR_SETTING_SET(TIMEOUT, (uint16_t) p_cfg->timeout);
    iwdtcr |= IWDT_PRV_IWDTCR_SETTING_SET(CLOCK_DIVISION, (uint16_t) p_cfg->clock_division);
    iwdtcr |= IWDT_PRV_IWDTCR_SETTING_SET(WINDOW_START, (uint16_t) p_cfg->window_start);
    iwdtcr |= IWDT_PRV_IWDTCR_SETTING_SET(WINDOW_END, (uint16_t) p_cfg->window_end);

    R_IWDT->IWDTCR             = (uint16_t) iwdtcr;
    R_IWDT->IWDTCSTPR_b.SLCSTP = (uint8_t) (p_cfg->stop_control == WDT_STOP_CONTROL_ENABLE);
#endif

    p_ctrl->wdt_open = IWDT_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Refresh the Independent Watchdog Timer.
 * If the refresh fails due to being performed outside of the
 * permitted refresh period the device will either reset or trigger an NMI/IRQ ISR to run.
 *
 * Example:
 * @snippet r_iwdt_example.c R_IWDT_Refresh
 *
 * @retval FSP_SUCCESS              IWDT successfully refreshed.
 * @retval FSP_ERR_ASSERTION        One or more parameters are NULL pointers.
 * @retval FSP_ERR_NOT_OPEN         The driver has not been opened. Perform R_IWDT_Open() first.
 **********************************************************************************************************************/
fsp_err_t R_IWDT_Refresh (wdt_ctrl_t * const p_api_ctrl)
{
#if (1 == IWDT_CFG_PARAM_CHECKING_ENABLE)
    iwdt_instance_ctrl_t * p_ctrl = (iwdt_instance_ctrl_t *) p_api_ctrl;
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ERROR_RETURN((IWDT_OPEN == p_ctrl->wdt_open), FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

    /* Described in hardware manual (see
     * "Refresh Operation" in the IWDT section of the relevant hardware manual). */
    R_IWDT->IWDTRR = IWDT_PRV_REFRESH_STEP_1;
    R_IWDT->IWDTRR = IWDT_PRV_REFRESH_STEP_2;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read the IWDT status flags.
 *
 * Indicates both status and error conditions.
 *
 * @retval FSP_SUCCESS              IWDT status successfully read.
 * @retval FSP_ERR_ASSERTION        Null pointer as a parameter.
 * @retval FSP_ERR_NOT_OPEN         The driver has not been opened. Perform R_IWDT_Open() first.
 * @retval FSP_ERR_UNSUPPORTED      This function is only valid if the IWDT generates an NMI when an error occurs.
 *
 * @note When the IWDT is configured to output a reset on underflow or refresh error reading the status and error flags
 *       serves no purpose as they will always indicate that no underflow has occurred and there is no refresh error.
 *       Reading the status and error flags is only valid when interrupt request output is enabled.
 **********************************************************************************************************************/
fsp_err_t R_IWDT_StatusGet (wdt_ctrl_t * const p_api_ctrl, wdt_status_t * const p_status)
{
#if IWDT_PRV_NMI_SUPPORTED || IWDT_PRV_IRQ_SUPPORTED
 #if (1 == IWDT_CFG_PARAM_CHECKING_ENABLE)
    iwdt_instance_ctrl_t * p_ctrl = (iwdt_instance_ctrl_t *) p_api_ctrl;
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ASSERT(p_status != NULL);
    FSP_ERROR_RETURN((IWDT_OPEN == p_ctrl->wdt_open), FSP_ERR_NOT_OPEN);
 #else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
 #endif

    *p_status = (wdt_status_t) (R_IWDT->IWDTSR >> (uint32_t) IWDT_PRV_STATUS_START_BIT);

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_status);

    /* This function is only supported when the NMI/IRQ is used. */
    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Clear the IWDT status and error flags. Implements @ref wdt_api_t::statusClear.
 *
 * @retval FSP_SUCCESS              IWDT flag(s) successfully cleared.
 * @retval FSP_ERR_ASSERTION        Null pointer as a parameter.
 * @retval FSP_ERR_NOT_OPEN         The driver has not been opened. Perform R_IWDT_Open() first.
 * @retval FSP_ERR_UNSUPPORTED      This function is only valid if the IWDT generates an NMI/IRQ  when an error occurs.
 *
 * @note When the IWDT is configured to output a reset on underflow or refresh error reading the status and error flags
 *       serves no purpose as they will always indicate that no underflow has occurred and there is no refresh error.
 *       Reading the status and error flags is only valid when interrupt request output is enabled.
 **********************************************************************************************************************/
fsp_err_t R_IWDT_StatusClear (wdt_ctrl_t * const p_api_ctrl, const wdt_status_t status)
{
#if IWDT_PRV_NMI_SUPPORTED || IWDT_PRV_IRQ_SUPPORTED
    uint16_t value;
    uint16_t read_value;

 #if (1 == IWDT_CFG_PARAM_CHECKING_ENABLE)
    iwdt_instance_ctrl_t * p_ctrl = (iwdt_instance_ctrl_t *) p_api_ctrl;
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ERROR_RETURN((IWDT_OPEN == p_ctrl->wdt_open), FSP_ERR_NOT_OPEN);
 #else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
 #endif

    /* Casts to uint16_t to ensure value is handled as unsigned. */
    value = (uint16_t) status;

    /* Write zero to clear flags */
    value = (uint16_t) ((uint16_t) (~value) << (uint32_t) IWDT_PRV_STATUS_START_BIT);

    /* Read back status flags until required flag(s) cleared.
     * Flags cannot be cleared until after the clock cycle after they are set.
     * Described in hardware manual (see
     * "IWDT Status Register (IWDTSR)" description in the relevant hardware manual).
     */
    do
    {
        R_IWDT->IWDTSR = value;
        read_value     = R_IWDT->IWDTSR;
        read_value    &= (uint16_t) ((uint16_t) status << (uint32_t) IWDT_PRV_STATUS_START_BIT);
    } while (read_value);

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(status);

    /* This function is only supported when the NMI/IRQ is used. */
    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Read the current count value of the IWDT. Implements @ref wdt_api_t::counterGet.
 *
 * Example:
 * @snippet r_iwdt_example.c R_IWDT_CounterGet
 *
 * @retval FSP_SUCCESS          IWDT current count successfully read.
 * @retval FSP_ERR_ASSERTION    Null pointer passed as a parameter.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened. Perform R_IWDT_Open() first.
 **********************************************************************************************************************/
fsp_err_t R_IWDT_CounterGet (wdt_ctrl_t * const p_api_ctrl, uint32_t * const p_count)
{
#if (1 == IWDT_CFG_PARAM_CHECKING_ENABLE)
    iwdt_instance_ctrl_t * p_ctrl = (iwdt_instance_ctrl_t *) p_api_ctrl;
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ASSERT(p_count != NULL);
    FSP_ERROR_RETURN((IWDT_OPEN == p_ctrl->wdt_open), FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

    (*p_count) = (uint32_t) R_IWDT->IWDTSR & (uint32_t) IWDT_PRV_IWDTSR_COUNTER_MASK;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read timeout information for the watchdog timer. Implements @ref wdt_api_t::timeoutGet.
 *
 * @retval FSP_SUCCESS              IWDT timeout information retrieved successfully.
 * @retval FSP_ERR_ASSERTION        One or more parameters are NULL pointers.
 * @retval FSP_ERR_NOT_OPEN         The driver has not been opened. Perform R_IWDT_Open() first.
 **********************************************************************************************************************/
fsp_err_t R_IWDT_TimeoutGet (wdt_ctrl_t * const p_api_ctrl, wdt_timeout_values_t * const p_timeout)
{
#if (1 == IWDT_CFG_PARAM_CHECKING_ENABLE)
    iwdt_instance_ctrl_t * p_ctrl = (iwdt_instance_ctrl_t *) p_api_ctrl;
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ASSERT(p_timeout != NULL);
    FSP_ERROR_RETURN((IWDT_OPEN == p_ctrl->wdt_open), FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
#endif

    uint32_t             frequency;
    uint32_t             shift;
    uint32_t             timeout = 0;
    wdt_clock_division_t clock_division;

#if IWDT_PRV_REGISTER_START_MODE

    /* Read the configuration of the watchdog */
    uint32_t iwdtcr = R_IWDT->IWDTCR;
    clock_division = (wdt_clock_division_t) IWDT_PRV_IWDTCR_SETTING_GET(CLOCK_DIVISION, iwdtcr);
    timeout        = IWDT_PRV_IWDTCR_SETTING_GET(TIMEOUT, iwdtcr);
#else                                  /* Auto start mode */
    clock_division = (wdt_clock_division_t) IWDT_PRV_OFS0_SETTING_GET(CLOCK_DIVISION);
    timeout        = IWDT_PRV_OFS0_SETTING_GET(TIMEOUT);
#endif

    p_timeout->timeout_clocks = (uint32_t) g_iwdt_timeout[timeout] << BSP_FEATURE_IWDT_TIMEOUT_MULTIPLIER_SHIFT;

    /* Get the frequency of the clock supplying the watchdog */
    frequency = (uint32_t) BSP_FEATURE_IWDT_CLOCK_FREQUENCY;

    shift = iwdt_clock_divider_get(clock_division);

    p_timeout->clock_frequency_hz = frequency >> shift;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements wdt_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_IWDT_CallbackSet (wdt_ctrl_t * const          p_ctrl,
                              void (                    * p_callback)(wdt_callback_args_t *),
                              void * const                p_context,
                              wdt_callback_args_t * const p_callback_memory)
{
    iwdt_instance_ctrl_t * p_instance_ctrl = (iwdt_instance_ctrl_t *) p_ctrl;

#if IWDT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(IWDT_OPEN == p_instance_ctrl->wdt_open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback = p_callback;

    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup IWDT)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Internal NMI ISR callback which calls the user provided callback passing the context provided by the user.
 *
 * @param[in]   irq     IRQ which has triggered the NMI interrupt.
 *
 **********************************************************************************************************************/
#if IWDT_PRV_NMI_SUPPORTED
static void iwdt_nmi_internal_callback (bsp_grp_irq_nmi_t irq)
{
    FSP_PARAMETER_NOT_USED(irq);

    wdt_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    wdt_callback_args_t * p_args = gp_iwdt_ctrl->p_callback_memory;
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

    p_args->p_context = gp_iwdt_ctrl->p_context;

    gp_iwdt_ctrl->p_callback(p_args);

    if (NULL != gp_iwdt_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *gp_iwdt_ctrl->p_callback_memory = args;
    }
}

#endif

/*******************************************************************************************************************//**
 * Internal function to return timeout in terms of watchdog clocks from provided timeout setting.
 *
 * @param[in]   division    Watchdog division setting.
 *
 **********************************************************************************************************************/
static uint32_t iwdt_clock_divider_get (wdt_clock_division_t division)
{
    uint32_t shift;

    if (WDT_CLOCK_DIVISION_128 == division)
    {
        shift = 7U;                    /* log base 2(128) = 7 */
    }
    else
    {
        shift = g_iwdt_division_lookup[division];
    }

    return shift;
}

/*******************************************************************************************************************//**
 * Initialize the NMI.
 *
 * @param[in]    p_instance_ctrl   Pointer to instance control structure
 **********************************************************************************************************************/
#if IWDT_PRV_NMI_SUPPORTED
static void iwdt_nmi_initialize (iwdt_instance_ctrl_t * const p_instance_ctrl)
{
    /* Initialize global pointer to WDT for NMI callback use.  */
    gp_iwdt_ctrl = p_instance_ctrl;

    /* NMI output mode. */
    R_BSP_GroupIrqWrite(BSP_GRP_IRQ_IWDT_ERROR, iwdt_nmi_internal_callback);

    /* Enable the IWDT underflow/refresh error interrupt to generate an NMI. NMIER bits cannot be cleared after reset,
     * so no need to read-modify-write. */
    R_ICU->NMIER = R_ICU_NMIER_IWDTEN_Msk;
}

#endif

/*******************************************************************************************************************//**
 * Parameter checking function for IWDT Open
 *
 * @param[in]    p_instance_ctrl   Pointer to instance control structure
 * @param[in]    p_cfg             Pointer to configuration structure
 *
 * @retval FSP_SUCCESS              IWDT successfully configured.
 * @retval FSP_ERR_NOT_ENABLED      An attempt to open the IWDT when the OFS0 register is not
 *                                  configured for auto-start mode.
 * @retval FSP_ERR_ASSERTION        Null pointer, or one or more configuration options is invalid.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.  This module can only be opened once.
 **********************************************************************************************************************/
#if IWDT_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t iwdt_parameter_checking (iwdt_instance_ctrl_t * const p_instance_ctrl, wdt_cfg_t const * const p_cfg)
{
    /* Check that control and config structure pointers are valid. */
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_instance_ctrl);
 #if IWDT_PRV_IRQ_SUPPORTED
    if (p_cfg->reset_control == WDT_RESET_CONTROL_NMI)
    {
        FSP_ASSERT(NULL != p_cfg->p_extend);
    }
 #endif

    FSP_ERROR_RETURN(IWDT_OPEN != p_instance_ctrl->wdt_open, FSP_ERR_ALREADY_OPEN);

    /* Check timeout parameter is supported by IWDT. */

    /* Enum checking is done here because some enums in wdt_timeout_t are not supported by the IWDT peripheral (they are
     * included for other implementations of the watchdog interface). */
    FSP_ASSERT((p_cfg->timeout & (~IWDT_PRV_IWDTCR_TIMEOUT_MASK)) == 0);

 #if IWDT_PRV_REGISTER_START_MODE

    /* Register-start mode. */

  #if IWDT_PRV_NMI_SUPPORTED || IWDT_PRV_IRQ_SUPPORTED

    /* Register callback with BSP NMI ISR. */
    if (p_cfg->reset_control == WDT_RESET_CONTROL_NMI)
    {
        FSP_ASSERT(NULL != p_cfg->p_callback);
    }
    else
    {
        FSP_ASSERT(NULL == p_cfg->p_callback);
    }

  #else
    FSP_ASSERT(p_cfg->reset_control == WDT_RESET_CONTROL_RESET);
  #endif
 #else

    /* Auto start mode. */

    /* Check the IWDT is enabled in auto start mode. */
    FSP_ERROR_RETURN((0U != (uint32_t) IWDT_PRV_AUTO_START_MODE), FSP_ERR_NOT_ENABLED);

  #if IWDT_PRV_NMI_SUPPORTED || IWDT_PRV_IRQ_SUPPORTED

    /* NMI/IRQ output mode. */
    FSP_ASSERT(NULL != p_cfg->p_callback);
  #else
    FSP_ASSERT(NULL == p_cfg->p_callback);
  #endif
 #endif

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Calls callback if one was provided in the open function.
 **********************************************************************************************************************/
void iwdt_iwuni_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    wdt_callback_args_t args;
    IRQn_Type           irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    iwdt_instance_ctrl_t * p_instance_ctrl = (iwdt_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Store callback arguments in memory provided by user if available. */
    wdt_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
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

    p_args->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }

    /* Clear pending IRQ to make sure it doesn't fire again after exiting.  This is a level interrupt, so it must be
     * cleared at the end of the ISR. */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
