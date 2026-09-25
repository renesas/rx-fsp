/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_pvd.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define PVD_OPENED                         (0x505644U)

#define PVD_MONITOR_PVD1                   (1U)
#define PVD_MONITOR_PVD2                   (2U)

#define PVD_PRV_FIRST_MONITOR_NUMBER       (1U)

#define PVD_PRV_NUMBER_OF_NMI              (2U)
#define PVD_PRV_NUMBER_OF_VCC_MONITOR      (5U)

#define PVD_PRV_PVDCR0_BIT3_MASK           (0x8U)

#define PVD_PRV_SECONDS_TO_MICROSECONDS    (1000000U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_pvd_hw_configure(pvd_instance_ctrl_t * p_ctrl);

#if BSP_FEATURE_PVD_HAS_DIGITAL_FILTER == 1
static uint32_t r_pvd_filter_delay(voltage_detection_sample_clock_t sample_clock_divisor);

#endif
#if (PVD_CFG_PARAM_CHECKING_ENABLE == 1)
static fsp_err_t pvd_open_parameter_check(pvd_instance_ctrl_t * p_ctrl, voltage_detection_cfg_t const * const p_cfg);

#endif

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
static void pvd_common_isr_handler(pvd_instance_ctrl_t * p_ctrl);
static void pvd_nmi_handler(bsp_grp_irq_nmi_t irq);
void        pvd_pvd_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Stored context for NMI handler. */
static pvd_instance_ctrl_t * gp_ctrls[PVD_PRV_NUMBER_OF_VCC_MONITOR] = {NULL};

/* Look-up tables for writing to monitor 1, monitor 2, monitor 4, monitor 5, registers. monitor 3 registers are dummy variables. */
static uint8_t volatile * const g_pvdncr0_lut[] =
{
    &(R_SYSTEM->PVD1CR0), &(R_SYSTEM->PVD2CR0), NULL, &(R_SYSTEM->PVD4CR0), &(R_SYSTEM->PVD5CR0)
};
static uint8_t volatile * const g_pvdncr1_lut[] =
{
    &(R_SYSTEM->PVD1CR1), &(R_SYSTEM->PVD2CR1), NULL, NULL, NULL
};
static uint8_t volatile * const g_pvdnsr_lut[] = {&(R_SYSTEM->PVD1SR), &(R_SYSTEM->PVD2SR)};

#if BSP_FEATURE_PVD_SUPPORT_RESET_ON_RISING_EDGE
static uint8_t volatile * const g_pvdnfcr_lut[] =
{
    &(R_SYSTEM->PVD1FCR), &(R_SYSTEM->PVD2FCR), NULL, &(R_SYSTEM->PVD4FCR), &(R_SYSTEM->PVD5FCR)
};

#endif

static uint8_t volatile * const g_pvdncmpcr_lut[] =
{
    &(R_SYSTEM->PVD1CMPCR), &(R_SYSTEM->PVD2CMPCR), NULL, &(R_SYSTEM->PVD4CMPCR),
    &(R_SYSTEM->PVD5CMPCR)
};
static uint32_t const g_pvdnlvl_mask_lut[] =
{
    R_SYSTEM_PVD1CMPCR_PVDLVL_Msk, R_SYSTEM_PVD2CMPCR_PVDLVL_Msk, 0x1fUL,
    R_SYSTEM_PVD4CMPCR_PVDLVL_Msk, R_SYSTEM_PVD5CMPCR_PVDLVL_Msk
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* Instance of low voltage detection peripheral driver interface. */
const voltage_detection_api_t g_voltage_detection_on_pvd =
{
    .open        = R_PVD_Open,
    .statusGet   = R_PVD_StatusGet,
    .statusClear = R_PVD_StatusClear,
    .close       = R_PVD_Close,
    .callbackSet = R_PVD_CallbackSet
};

/*******************************************************************************************************************//**
 * @addtogroup PVD
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes a voltage monitor and detector according to the passed-in configuration structure.
 *
 * @param[in]   p_api_ctrl              Pointer to the control structure for the driver instance
 * @param[in]   p_cfg                   Pointer to the configuration structure for the driver instance
 *
 * @note Digital filter is not to be used with standby modes.
 * @note Startup time can take on the order of milliseconds for some configurations.
 *
 * Example:
 * @snippet r_pvd_example.c R_PVD_Open
 *
 * @retval      FSP_SUCCESS                    Successful
 * @retval      FSP_ERR_ASSERTION              Requested configuration was invalid
 * @retval      FSP_ERR_INVALID_ARGUMENT       An argument is invalid.
 * @retval      FSP_ERR_ALREADY_OPEN           The instance was already opened
 * @retval      FSP_ERR_IN_USE                 Another instance is already using the desired monitor
 * @retval      FSP_ERR_UNSUPPORTED            Digital filter was enabled on a device that does not support it
 **********************************************************************************************************************/
fsp_err_t R_PVD_Open (voltage_detection_ctrl_t * const p_api_ctrl, voltage_detection_cfg_t const * const p_cfg)
{
    pvd_instance_ctrl_t * p_ctrl = (pvd_instance_ctrl_t *) p_api_ctrl;

#if (PVD_CFG_PARAM_CHECKING_ENABLE == 1)
    fsp_err_t err = FSP_SUCCESS;
    err = pvd_open_parameter_check(p_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err)
#endif

    /* Store the user configuration. */
    p_ctrl->p_cfg             = p_cfg;
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    if (p_ctrl->p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_VCC_MONITOR)
    {
        /* Store control structure so it can be accessed from NMI handler. */
        gp_ctrls[p_ctrl->p_cfg->monitor_number - 1] = p_ctrl;

        /* Configure the hardware based on the user settings. */
        r_pvd_hw_configure(p_ctrl);
    }

    /* Mark driver as opened by initializing it to "PVD" in its ASCII equivalent. */
    p_ctrl->open = PVD_OPENED;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the current state of the monitor (threshold crossing detected, voltage currently above or below threshold).
 *
 * @param[in]   p_api_ctrl              Pointer to the control structure for the driver instance
 * @param[out]  p_voltage_detection_status            Pointer to status structure
 *
 * Example:
 * @snippet r_pvd_example.c R_PVD_StatusGet
 *
 * @retval          FSP_SUCCESS         Successful
 * @retval          FSP_ERR_ASSERTION   An argument was NULL
 * @retval          FSP_ERR_NOT_OPEN    Driver is not open
 * @retval          FSP_ERR_UNSUPPORTED This monitor does not support status feature
 *
 **********************************************************************************************************************/
fsp_err_t R_PVD_StatusGet (voltage_detection_ctrl_t * const p_api_ctrl,
                           voltage_detection_status_t     * p_voltage_detection_status)
{
    pvd_instance_ctrl_t * p_ctrl = (pvd_instance_ctrl_t *) p_api_ctrl;

#if (0 != PVD_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_voltage_detection_status);
    FSP_ERROR_RETURN(!((4 == p_ctrl->p_cfg->monitor_number) || (5 == p_ctrl->p_cfg->monitor_number)),
                     FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN((PVD_OPENED == p_ctrl->open), FSP_ERR_NOT_OPEN);
#endif

    uint8_t pvdnsr = 0;

    if (p_ctrl->p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_NMI)
    {
        pvdnsr = *(g_pvdnsr_lut[p_ctrl->p_cfg->monitor_number - 1]);
        p_voltage_detection_status->crossing_detected =
            (voltage_detection_threshold_crossing_t) ((pvdnsr & R_SYSTEM_PVD1SR_DET_Msk) != 0);
        p_voltage_detection_status->current_state =
            (voltage_detection_current_state_t) ((pvdnsr & R_SYSTEM_PVD1SR_MON_Msk) != 0);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Clears the latched status of the monitor.
 *
 * @param[in]   p_api_ctrl          Pointer to the control structure for the driver instance
 *
 * @retval      FSP_SUCCESS         Successful
 * @retval      FSP_ERR_ASSERTION   An argument was NULL
 * @retval      FSP_ERR_NOT_OPEN    Driver is not open
 * @retval      FSP_ERR_UNSUPPORTED This monitor does not support status feature
 *
 **********************************************************************************************************************/
fsp_err_t R_PVD_StatusClear (voltage_detection_ctrl_t * const p_api_ctrl)
{
    pvd_instance_ctrl_t * p_ctrl = (pvd_instance_ctrl_t *) p_api_ctrl;

#if (0 != PVD_CFG_PARAM_CHECKING_ENABLE)
    FSP_ERROR_RETURN((NULL != p_ctrl), FSP_ERR_ASSERTION);
    FSP_ERROR_RETURN(!((4 == p_ctrl->p_cfg->monitor_number) || (5 == p_ctrl->p_cfg->monitor_number)),
                     FSP_ERR_UNSUPPORTED);
    FSP_ERROR_RETURN((PVD_OPENED == p_ctrl->open), FSP_ERR_NOT_OPEN);
#endif

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_PVD);

    /* Clear the status register. */
    if (p_ctrl->p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_NMI)
    {
        *(g_pvdnsr_lut[p_ctrl->p_cfg->monitor_number - 1]) = 0;
    }

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_PVD);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements voltage_detection_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_PVD_CallbackSet (voltage_detection_ctrl_t * const          p_api_ctrl,
                             void (                                  * p_callback)(voltage_detection_callback_args_t *),
                             void * const                              p_context,
                             voltage_detection_callback_args_t * const p_callback_memory)
{
    pvd_instance_ctrl_t * p_ctrl = (pvd_instance_ctrl_t *) p_api_ctrl;

#if (PVD_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(PVD_OPENED == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context. */
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables the PVD peripheral. Closes the driver instance.
 *
 * @param[in]   p_api_ctrl          Pointer to the control block structure for the driver instance
 *
 * @retval      FSP_SUCCESS         Successful
 * @retval      FSP_ERR_ASSERTION   An argument was NULL
 * @retval      FSP_ERR_NOT_OPEN    Driver is not open
 *
 **********************************************************************************************************************/
fsp_err_t R_PVD_Close (voltage_detection_ctrl_t * const p_api_ctrl)
{
    pvd_instance_ctrl_t * p_ctrl = (pvd_instance_ctrl_t *) p_api_ctrl;

#if (0 != PVD_CFG_PARAM_CHECKING_ENABLE)
    FSP_ERROR_RETURN((NULL != p_ctrl), FSP_ERR_ASSERTION);
    FSP_ERROR_RETURN(PVD_OPENED == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    if (FSP_INVALID_VECTOR != p_ctrl->p_cfg->irq)
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->irq);
    }

    if (p_ctrl->p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_VCC_MONITOR)
    {
        uint32_t monitor_index = p_ctrl->p_cfg->monitor_number - 1;

        if (p_ctrl->p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_NMI)
        {
            /* Setting for NMI. */
            R_BSP_GroupIrqWrite((bsp_grp_irq_nmi_t) (BSP_GRP_IRQ_PVD1 + monitor_index), NULL);
        }

        /* See Shutdown procedure from Table "Procedure for setting bits related to the voltage monitor 1
         * interrupt and voltage monitor 1 reset so that voltage monitoring stops" in the "Interrupt and Reset
         * from Voltage Monitor m (m = 1, 2)"" section of the relevant hardware manual. */
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_PVD);

        /* Disable output of comparison results by voltage monitor. Write value to pvdncr0.bit3 should be 1. */
        *(g_pvdncr0_lut[monitor_index]) =
            (uint8_t) ((*(g_pvdncr0_lut[monitor_index]) | (uint8_t) PVD_PRV_PVDCR0_BIT3_MASK) &
                       ((uint8_t) ~(R_SYSTEM_PVD1CR0_CMPE_Msk)));

#if BSP_FEATURE_PVD_HAS_DIGITAL_FILTER == 1
        if (VOLTAGE_DETECTION_SAMPLE_CLOCK_DISABLED != p_ctrl->p_cfg->sample_clock_divisor)
        {
            /* Wait for at least 2n + 3 LOCO cycles, where n = [2,4,8,16]. */
            R_BSP_SoftwareDelay(r_pvd_filter_delay(p_ctrl->p_cfg->sample_clock_divisor), BSP_DELAY_UNITS_MICROSECONDS);
        }
#endif
        uint8_t pvdncr0 = *(g_pvdncr0_lut[monitor_index]);

        /* Disable voltage monitor interrupt or reset. */
        pvdncr0 &= (uint8_t) ~R_SYSTEM_PVD1CR0_RIE_Msk;

#if BSP_FEATURE_PVD_HAS_DIGITAL_FILTER == 1

        /* Disable digital filter. */
        pvdncr0 |= (uint8_t) R_SYSTEM_PVD1CR0_DFDIS_Msk;
#endif

        /* Write value to pvdncr0.bit3 should be 1. */
        *(g_pvdncr0_lut[monitor_index])    = (uint8_t) ((pvdncr0 | (uint8_t) PVD_PRV_PVDCR0_BIT3_MASK));
        *(g_pvdncmpcr_lut[monitor_index]) &= (uint8_t) ~R_SYSTEM_PVD1CMPCR_PVDE_Msk;
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_PVD);
        gp_ctrls[monitor_index] = NULL;
    }

    p_ctrl->open = 0;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup PVD)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures the hardware based on the user defined configuration settings.
 *
 * @param[in]   p_ctrl                  Pointer to the control structure for the driver instance
 *
 **********************************************************************************************************************/
static void r_pvd_hw_configure (pvd_instance_ctrl_t * p_ctrl)
{
    FSP_CRITICAL_SECTION_DEFINE;

    uint32_t pvdncr0 = 0;
    uint32_t pvdncr1 = 0;

    /* Calculate index used to get monitor registers from look-up tables and perform other calculations. */
    uint32_t monitor_index = p_ctrl->p_cfg->monitor_number - 1;

    if (p_ctrl->p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_NMI)
    {
        /* Configure the voltage monitor interrupt condition. */
        pvdncr1 |= (uint32_t) (p_ctrl->p_cfg->voltage_slope << R_SYSTEM_PVD1CR1_IDTSEL_Pos);

        if (VOLTAGE_DETECTION_RESPONSE_NONE != p_ctrl->p_cfg->detection_response)
        {
            if (VOLTAGE_DETECTION_RESPONSE_INTERRUPT == p_ctrl->p_cfg->detection_response)
            {
                /* Configure the voltage monitor interrupt type as maskable. */
                pvdncr1 |= R_SYSTEM_PVD1CR1_IRQSEL_Msk;

                /* Enable interrupt in NVIC. */
                R_BSP_IrqCfgEnable(p_ctrl->p_cfg->irq, (uint32_t) p_ctrl->p_cfg->monitor_ipl, p_ctrl);
            }
            else if (VOLTAGE_DETECTION_RESPONSE_NMI == p_ctrl->p_cfg->detection_response)
            {
                /* Enable the NMI handler. */
                R_BSP_GroupIrqWrite((bsp_grp_irq_nmi_t) (BSP_GRP_IRQ_PVD1 + monitor_index), pvd_nmi_handler);

                /* Enable NMI for this PVD monitor. NMIER bits can only be set. They cannot be cleared. */
                R_ICU->NMIER = (uint16_t) (1U << (2U + monitor_index));
            }
            else
            {
                /* VOLTAGE_DETECTION_RESPONSE_RESET or VOLTAGE_DETECTION_RESPONSE_RESET_ON_RISING. */

                /* Voltage monitor reset enabled. */
                pvdncr0 |= R_SYSTEM_PVD1CR0_RI_Msk;

                /* Configure the voltage monitor reset negation mode. */
                pvdncr0 |= (uint32_t) (p_ctrl->p_cfg->negation_delay << R_SYSTEM_PVD1CR0_RN_Pos);
            }
        }
    }

    /* Amount of time to wait before enabling output of voltage monitor comparison results. */
    uint32_t delay;
    if (PVD_MONITOR_PVD1 == p_ctrl->p_cfg->monitor_number)
    {
        /* PVD monitor is PVD1. */
        delay = BSP_FEATURE_PVD_MONITOR_1_STABILIZATION_TIME_US;
    }
    else
    {
        /* PVD monitor is PVD2. */
        delay = BSP_FEATURE_PVD_MONITOR_2_STABILIZATION_TIME_US;
    }

#if BSP_FEATURE_PVD_HAS_DIGITAL_FILTER == 1
    if (VOLTAGE_DETECTION_SAMPLE_CLOCK_DISABLED != p_ctrl->p_cfg->sample_clock_divisor)
    {
        /* Configure the digital filter clock divider. */
        pvdncr0 |= (uint32_t) (p_ctrl->p_cfg->sample_clock_divisor << R_SYSTEM_PVD1CR0_FSAMP_Pos);

        /* Wait for at least 2n + 3 LOCO cycles, where n = [2,4,8,16]. */
        uint32_t filter_delay = r_pvd_filter_delay(p_ctrl->p_cfg->sample_clock_divisor);

        /* If filter delay is greater than the stabilization delay, wait for filter delay. */
        if (filter_delay > delay)
        {
            delay = filter_delay;
        }
    }
    else
    {
        /* Disable the digital filter. */
        pvdncr0 |= R_SYSTEM_PVD1CR0_DFDIS_Msk;
    }
#endif

    /* See Setup procedure from Table "Procedure for setting bits related to the voltage monitor 1
     * interrupt and voltage monitor 1 reset so that voltage monitoring operates"
     * in the "Interrupt and Reset from Voltage Monitor m (m = 1, 2)" section of the relevant hardware manual. */

    /* Enable access to PVD registers. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_PVD);

    /* Unlock control registers for PVD4 and PVD5.
     * Any additional write to PVDLR will lock it to 1 until the next POR, Reset pin toggle, or PVD0 reset. */
    if (R_SYSTEM->PVDLR != 0)
    {
        R_SYSTEM->PVDLR = 0;
    }

    uint8_t pvdne[PVD_PRV_NUMBER_OF_VCC_MONITOR];
    uint8_t i;

    /* Critical section required because PVDmCMPCR register is shared with other instances. */
    FSP_CRITICAL_SECTION_ENTER;

    /* To change a PVDLVL function both voltage detection circuits must be disabled.
     * Disable the voltage detection circuit for all monitors before writing the PVDmCMPCR register.
     * See "PVD1CMPCR : Voltage Monitoring 1 Comparator Control Register" description in the
     * Register Descriptions section of the relevant hardware manual. */
    for (i = 0; i < PVD_PRV_NUMBER_OF_VCC_MONITOR; i++)
    {
        if (0 != ((1UL << i) & BSP_FEATURE_PVD_MONITOR_MASK))
        {
            /* Preserve enable values for other monitors. */
            pvdne[i] = (uint8_t) (*(g_pvdncmpcr_lut[i]) & R_SYSTEM_PVD1CMPCR_PVDE_Msk);

            /* Disable the monitor. */
            *(g_pvdncmpcr_lut[i]) &= (uint8_t) ~R_SYSTEM_PVD1CMPCR_PVDE_Msk;
        }
    }

    /* Configure the voltage threshold setting. */
    uint8_t pvdncmpcr = *(g_pvdncmpcr_lut[monitor_index]);
    pvdncmpcr &= (uint8_t) ~(g_pvdnlvl_mask_lut[monitor_index]);
    pvdncmpcr |= (uint8_t) (p_ctrl->p_cfg->voltage_threshold);

    /* Write the voltage level setting. */
    *(g_pvdncmpcr_lut[monitor_index]) = pvdncmpcr;

#if BSP_FEATURE_PVD_SUPPORT_RESET_ON_RISING_EDGE
    if (VOLTAGE_DETECTION_RESPONSE_RESET_ON_RISING == p_ctrl->p_cfg->detection_response)
    {
        /* When PVD reset generated by the VCC-rise detection is required, RHSEL must be set to 1. */
        *(g_pvdnfcr_lut[monitor_index]) = 1;
    }
    else
    {
        *(g_pvdnfcr_lut[monitor_index]) = 0;
    }
#endif

    /* Enable the voltage detection circuits. */
    for (i = 0; i < PVD_PRV_NUMBER_OF_VCC_MONITOR; i++)
    {
        if (0 != ((1UL << i) & BSP_FEATURE_PVD_MONITOR_MASK))
        {
            if (monitor_index == i)
            {
                *(g_pvdncmpcr_lut[monitor_index]) |= R_SYSTEM_PVD1CMPCR_PVDE_Msk;
            }
            else
            {
                *(g_pvdncmpcr_lut[i]) |= pvdne[i];
            }
        }
    }

    FSP_CRITICAL_SECTION_EXIT;

    /* Write settings to control registers. Write value to pvdncr0.bit3 should be 1. */
    *(g_pvdncr0_lut[monitor_index]) = (uint8_t) (pvdncr0 | PVD_PRV_PVDCR0_BIT3_MASK);
    *(g_pvdncr1_lut[monitor_index]) = (uint8_t) pvdncr1;

    if (p_ctrl->p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_NMI)
    {
        /* Clear DET before setting RIE. */
        *(g_pvdnsr_lut[monitor_index]) = 0;
    }

    if (VOLTAGE_DETECTION_RESPONSE_NONE != p_ctrl->p_cfg->detection_response)
    {
        /* Reset/Interrupt enable bit set after clearing DET bit. Write value to pvdncr0.bit3 should be 1. */
        *(g_pvdncr0_lut[monitor_index]) |= (R_SYSTEM_PVD1CR0_RIE_Msk | PVD_PRV_PVDCR0_BIT3_MASK);
    }

    /* Wait for PVD and filter stabilization. */
    R_BSP_SoftwareDelay(delay, BSP_DELAY_UNITS_MICROSECONDS);

    /* Enable output of comparison results by voltage monitor. Write value to pvdncr0.bit3 should be 1. */
    *(g_pvdncr0_lut[monitor_index]) |= (R_SYSTEM_PVD1CR0_CMPE_Msk | PVD_PRV_PVDCR0_BIT3_MASK);

    /* Disable access to PVD registers. */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_PVD);
}

#if BSP_FEATURE_PVD_HAS_DIGITAL_FILTER == 1

/*******************************************************************************************************************//**
 * Calculates the microseconds to delay after enabling the digital filter.
 *
 * @param[in]   sample_clock_divisor     The configured sample clock divisor for the digital filter
 *
 * @retval      microseconds             Number of microseconds to delay
 **********************************************************************************************************************/
static uint32_t r_pvd_filter_delay (voltage_detection_sample_clock_t sample_clock_divisor)
{
    uint32_t loco_cycles = (uint32_t) (1 << (sample_clock_divisor + 1)) * 2 + 3;

    return (loco_cycles * PVD_PRV_SECONDS_TO_MICROSECONDS) / BSP_LOCO_HZ + 1U;
}

#endif

#if (PVD_CFG_PARAM_CHECKING_ENABLE == 1)

/*******************************************************************************************************************//**
 * Helper function to do parameter checking for R_PVD_Open.
 *
 * @param[in]   p_ctrl                         Pointer to the control block structure for the driver instance
 * @param[in]   p_cfg                          Pointer to the configuration structure for the driver instance
 *
 * @retval      FSP_SUCCESS                    Successful
 * @retval      FSP_ERR_ASSERTION              Requested configuration was invalid
 * @retval      FSP_ERR_INVALID_ARGUMENT       An argument is invalid.
 * @retval      FSP_ERR_ALREADY_OPEN           The instance was already opened
 * @retval      FSP_ERR_IN_USE                 Another instance is already using the desired monitor
 * @retval      FSP_ERR_UNSUPPORTED            Digital filter was enabled on a device that does not support it
 **********************************************************************************************************************/
static fsp_err_t pvd_open_parameter_check (pvd_instance_ctrl_t * p_ctrl, voltage_detection_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(PVD_OPENED != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(VOLTAGE_DETECTION_THRESHOLD_NOT_AVAILABLE != p_cfg->voltage_threshold, FSP_ERR_INVALID_ARGUMENT);
    FSP_ASSERT(0 != ((1UL << (p_cfg->monitor_number - 1)) & BSP_FEATURE_PVD_MONITOR_MASK));

    if (p_cfg->monitor_number <= PVD_PRV_NUMBER_OF_VCC_MONITOR)
    {
        FSP_ERROR_RETURN(NULL == gp_ctrls[p_cfg->monitor_number - 1], FSP_ERR_IN_USE);
    }

    int32_t threshold = (int32_t) p_cfg->voltage_threshold;

    /* Verify that the threshold is valid for voltage monitor. */
    switch (p_cfg->monitor_number)
    {
        case 1:
        {
            /* High voltage thresholds correspond to low register settings. */
            FSP_ASSERT(threshold >= (int32_t) BSP_FEATURE_PVD_MONITOR_1_HI_THRESHOLD &&
                       threshold <= (int32_t) BSP_FEATURE_PVD_MONITOR_1_LOW_THRESHOLD);
            break;
        }

        case 2:
        case 4:
        case 5:
        {
            /* High voltage thresholds correspond to low register settings. */
            FSP_ASSERT(threshold >= (int32_t) BSP_FEATURE_PVD_MONITOR_2_HI_THRESHOLD &&
                       threshold <= (int32_t) BSP_FEATURE_PVD_MONITOR_2_LOW_THRESHOLD);
            break;
        }

        default:
        {
            break;
        }
    }

    /* If the response is an interrupt then IRQ setting must be a valid interrupt number. */
    if (VOLTAGE_DETECTION_RESPONSE_INTERRUPT == p_cfg->detection_response)
    {
        FSP_ASSERT(p_cfg->irq >= 0);
    }

    /* If the response is a maskable or non-maskable interrupt then a callback must be provided. */
    if ((VOLTAGE_DETECTION_RESPONSE_INTERRUPT == p_cfg->detection_response) ||
        (VOLTAGE_DETECTION_RESPONSE_NMI == p_cfg->detection_response))
    {
        FSP_ASSERT(NULL != p_cfg->p_callback);
    }

    if ((p_cfg->monitor_number == 4) || (p_cfg->monitor_number == 5))
    {
        if (VOLTAGE_DETECTION_RESPONSE_RESET == p_cfg->detection_response)
        {
            /* Negation shall only follow a stabilization time (tPVDm) after VCC > Vdetm is detected on VCC-falling reset and VCC-rising reset. */
            FSP_ASSERT(VOLTAGE_DETECTION_NEGATION_DELAY_FROM_VOLTAGE == p_cfg->negation_delay);
        }
    }

    if (VOLTAGE_DETECTION_RESPONSE_RESET_ON_RISING == p_cfg->detection_response)
    {
        /* Negation shall only follow a stabilization time (tPVDm) after VCC < Vdetm is detected on VCC-rising reset. */
        FSP_ASSERT(VOLTAGE_DETECTION_NEGATION_DELAY_FROM_VOLTAGE == p_cfg->negation_delay);
    }

 #if BSP_FEATURE_PVD_HAS_DIGITAL_FILTER == 0
    FSP_ERROR_RETURN(VOLTAGE_DETECTION_SAMPLE_CLOCK_DISABLED == p_cfg->sample_clock_divisor, FSP_ERR_UNSUPPORTED);
 #endif

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Common code needed for all PVD ISRs.
 *
 * @param[in] p_ctrl            Pointer to the control block structure for the driver instance
 *
 **********************************************************************************************************************/
static void pvd_common_isr_handler (pvd_instance_ctrl_t * p_ctrl)
{
    /* Calculate index used to get monitor registers from look-up tables and perform other calculations. */
    uint32_t monitor_index = p_ctrl->p_cfg->monitor_number - 1;

    voltage_detection_callback_args_t callback_args;

    /* Store callback arguments in memory provided by user if available. */
    voltage_detection_callback_args_t * p_args = p_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack. */
        p_args = &callback_args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        callback_args = *p_args;
    }

    p_args->current_state =
        (voltage_detection_current_state_t) ((*(g_pvdnsr_lut[monitor_index]) & R_SYSTEM_PVD1SR_MON_Msk) > 0);
    p_args->monitor_number = p_ctrl->p_cfg->monitor_number;
    p_args->p_context      = p_ctrl->p_context;

    p_ctrl->p_callback(p_args);

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = callback_args;
    }

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_PVD);

    /* Clear the status register. */
    *(g_pvdnsr_lut[monitor_index]) = 0;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_PVD);
}

/*******************************************************************************************************************//**
 * ISR for maskable PVD interrupts
 *
 **********************************************************************************************************************/
void pvd_pvd_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear the Interrupt Request. */
    R_BSP_IrqStatusClear(irq);

    /* Call common isr handler. */
    pvd_common_isr_handler((pvd_instance_ctrl_t *) R_FSP_IsrContextGet(irq));

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * ISR handler for non-maskable interrupts
 *
 * @param[in] irq         BSP group IRQ identifier
 *
 **********************************************************************************************************************/
static void pvd_nmi_handler (bsp_grp_irq_nmi_t irq)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE
    /* Call common isr handler. */
    pvd_common_isr_handler(gp_ctrls[irq - BSP_GRP_IRQ_PVD1]);

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE
}
