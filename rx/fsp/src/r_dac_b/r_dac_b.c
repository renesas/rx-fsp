/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include "r_dac_b.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* D/A Control Register Mask */
/** Driver ID (DACB in ASCII), used to identify Digital to Analog Converter (DAC_B) configuration  */
#define DAC_B_OPEN                       (0x44414342)
#define DAC_B_CHANNEL_COUNT              (BSP_FEATURE_DAC_B_CHANNELS_PER_UNIT * BSP_FEATURE_DAC_B_UNIT_COUNT)
#define DAC_B_DADR_OFSSEL_0              (0x00E0U)
#define DAC_B_DADR_OFSSEL_1              (0x01F8U)
#define DAC_B_BUFFER_START_TIME_US       (6U)
#define DAC_B_BUFFER_RECOVERY_TIME_US    (6U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

const dac_api_t g_dac_on_dac_b =
{
    .open  = R_DAC_B_Open,
    .write = R_DAC_B_Write,
    .start = R_DAC_B_Start,
    .stop  = R_DAC_B_Stop,
    .close = R_DAC_B_Close,
};

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup DAC_B
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/******************************************************************************************************************//**
 * Perform required initialization described in hardware manual.  Implements @ref dac_api_t::open.
 * Configures a single DAC channel, starts the channel, and provides a handle for use with the
 * DAC API Write and Close functions.  Must be called once prior to calling any other DAC API
 * functions.  After a channel is opened, Open should not be called again for the same channel
 * without calling Close first.
 *
 * @retval FSP_SUCCESS                     The channel was successfully opened.
 * @retval FSP_ERR_ASSERTION               Parameter check failure due to one or more reasons below:
 *                                         1. One or both of the following parameters may be NULL: p_api_ctrl or p_cfg
 *                                         2. data_format value in p_cfg is out of range.
 *                                         3. Extended configuration structure is set to NULL
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Channel ID requested in p_cfg may not available on the devices.
 * @retval FSP_ERR_ALREADY_OPEN            The control structure is already opened.
 *
 **********************************************************************************************************************/
fsp_err_t R_DAC_B_Open (dac_ctrl_t * p_api_ctrl, dac_cfg_t const * const p_cfg)
{
    dac_b_instance_ctrl_t * p_ctrl = (dac_b_instance_ctrl_t *) p_api_ctrl;

    /* Validate the input parameter. */
#if DAC_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(p_cfg->channel < (uint8_t) DAC_B_CHANNEL_COUNT, FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(false == p_ctrl->channel_opened, FSP_ERR_ALREADY_OPEN);
#endif

    uint8_t dac_unit = (uint8_t) (p_cfg->channel / BSP_FEATURE_DAC_B_CHANNELS_PER_UNIT);
    p_ctrl->p_reg = (R_DAC_B0_Type *) (R_DAC_B0_BASE + (dac_unit * ((uint32_t) R_DAC_B1 - (uint32_t) R_DAC_B0)));

    /* Power on the DAC device. */
    R_BSP_MODULE_START(FSP_IP_DAC, dac_unit);

    dac_b_extended_cfg_t * p_extend = (dac_b_extended_cfg_t *) p_cfg->p_extend;

    /* Stop the channel. */
    uint32_t dacr0 = p_ctrl->p_reg->DACR0;
    uint32_t dacr2 = p_ctrl->p_reg->DACR2;
    uint16_t dadr  = 0U;
    dacr0 &=
        ~(R_DAC_B0_DACR0_DACEN_Msk | R_DAC_B0_DACR0_DAOUTDIS_Msk | R_DAC_B0_DACR0_DAOUTEN_Msk | R_DAC_B0_DACR0_DAE_Msk);
#if BSP_FEATURE_DAC_B_OUTPUT_ENABLE
    dacr0 &= ~R_DAC_B0_DACR0_DAOE_Msk;                                                     // Clear DAOE bit if the feature is supported
#endif
    p_ctrl->p_reg->DACR0         = dacr0;
    p_ctrl->p_reg->DACR1_b.DPSEL = p_extend->data_format;
    dacr0 |= ((uint32_t) p_extend->internal_output_enabled << R_DAC_B0_DACR0_DAOUTEN_Pos); // Set internal/external routing

#if BSP_FEATURE_DAC_B_HAS_VOLTAGE_MODE_SELECTION
    dacr2 &= ~R_DAC_B0_DACR2_OFSSEL_Msk;                                                   // Clear OFSSEL bit if the feature is supported

    dacr2 |= (p_extend->vrefh << R_DAC_B0_DACR2_OFSSEL_Pos);
#endif

#if BSP_FEATURE_DAC_B_HAS_OUTPUT_AMPLIFIER
    dacr2 &= ~R_DAC_B0_DACR2_DAAMP_Msk; // Clear DAAMP bit if the feature is supported

    /* Ensure DAOUTDIS is not set to 1 before enabling DAAMP */
    if (p_extend->internal_output_enabled == DAC_B_OUTPUT_EXTERNAL)
    {
        dacr2 |= ((uint32_t) p_extend->output_amplifier_enabled << R_DAC_B0_DACR2_DAAMP_Pos);

        if (p_extend->output_amplifier_enabled)
        {
            dadr = (uint16_t) ((dacr2 & R_DAC_B0_DACR2_OFSSEL_Msk) ?
                               DAC_B_DADR_OFSSEL_1 : DAC_B_DADR_OFSSEL_0);
            dadr = (uint16_t) ((p_extend->data_format == DAC_DATA_FORMAT_FLUSH_LEFT) ?
                               (uint16_t) (dadr << 4U) : dadr);
        }
    }
#endif
#if BSP_FEATURE_DAC_B_OUTPUT_ENABLE
 #if BSP_FEATURE_DAC_B_HAS_OUTPUT_AMPLIFIER
    if ((!p_extend->output_amplifier_enabled) ||
        (p_extend->internal_output_enabled != DAC_B_OUTPUT_EXTERNAL))
    {
 #endif
    dacr0 |= (1U << R_DAC_B0_DACR0_DAOE_Pos); // Output Enable
 #if BSP_FEATURE_DAC_B_HAS_OUTPUT_AMPLIFIER
}
 #endif
#endif
    p_ctrl->p_reg->DACR2 = dacr2;
    p_ctrl->p_reg->DADR  = dadr;
    p_ctrl->p_reg->DACR0 = dacr0;

    /* Initialize the channel state information. */
    p_ctrl->channel        = p_cfg->channel;
    p_ctrl->channel_opened = DAC_B_OPEN;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Write data to the D/A converter and enable the output if it has not been enabled.
 *
 * @retval   FSP_SUCCESS           Data is successfully written to the D/A Converter.
 * @retval   FSP_ERR_ASSERTION     p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN      Channel associated with p_ctrl has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DAC_B_Write (dac_ctrl_t * p_api_ctrl, uint16_t value)
{
    dac_b_instance_ctrl_t * p_ctrl = (dac_b_instance_ctrl_t *) p_api_ctrl;

#if DAC_B_CFG_PARAM_CHECKING_ENABLE

    /* Validate the handle parameter */
    FSP_ASSERT(NULL != p_ctrl);

    /* Validate that the channel is opened. */
    FSP_ERROR_RETURN(p_ctrl->channel_opened, FSP_ERR_NOT_OPEN);
#endif

    /* Write the value to D/A converter. */
    p_ctrl->p_reg->DADR = value;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Start the D/A conversion output if it has not been started.
 *
 * @retval   FSP_SUCCESS           The channel is started successfully.
 * @retval   FSP_ERR_ASSERTION     p_api_ctrl is NULL.
 * @retval   FSP_ERR_IN_USE        Attempt to re-start a channel.
 * @retval   FSP_ERR_NOT_OPEN      Channel associated with p_ctrl has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DAC_B_Start (dac_ctrl_t * p_api_ctrl)
{
    dac_b_instance_ctrl_t * p_ctrl = (dac_b_instance_ctrl_t *) p_api_ctrl;

#if BSP_FEATURE_DAC_B_HAS_OUTPUT_AMPLIFIER && BSP_FEATURE_DAC_B_OUTPUT_ENABLE
    bool output_buffer_amplifier_enabled;
#endif

#if DAC_B_CFG_PARAM_CHECKING_ENABLE

    /* Validate the handle parameter */
    FSP_ASSERT(NULL != p_ctrl);

    /* Validate that the channel is opened. */
    FSP_ERROR_RETURN(p_ctrl->channel_opened, FSP_ERR_NOT_OPEN);

    /* Check if the channel is not already started */
    FSP_ERROR_RETURN(!p_ctrl->p_reg->DACR0_b.DACEN, FSP_ERR_IN_USE);
#endif

    {
        FSP_CRITICAL_SECTION_DEFINE;
        FSP_CRITICAL_SECTION_ENTER;

        p_ctrl->p_reg->DACR0_b.DACEN = 1; // Enable channel conversion
#if BSP_FEATURE_DAC_B_HAS_OUTPUT_AMPLIFIER && BSP_FEATURE_DAC_B_OUTPUT_ENABLE
        output_buffer_amplifier_enabled = (bool) (p_ctrl->p_reg->DACR2_b.DAAMP);
#endif

        FSP_CRITICAL_SECTION_EXIT;
    }

#if BSP_FEATURE_DAC_B_HAS_OUTPUT_AMPLIFIER && BSP_FEATURE_DAC_B_OUTPUT_ENABLE
    if (output_buffer_amplifier_enabled)
    {
        R_BSP_SoftwareDelay(DAC_B_BUFFER_START_TIME_US, BSP_DELAY_UNITS_MICROSECONDS);

        p_ctrl->p_reg->DACR0_b.DAOE = 1;

        R_BSP_SoftwareDelay(DAC_B_BUFFER_RECOVERY_TIME_US, BSP_DELAY_UNITS_MICROSECONDS);
    }
#endif

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Stop the D/A conversion and disable the output signal.
 *
 * @retval  FSP_SUCCESS           The control is successfully stopped.
 * @retval  FSP_ERR_ASSERTION     p_api_ctrl is NULL.
 * @retval  FSP_ERR_NOT_OPEN      Channel associated with p_ctrl has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DAC_B_Stop (dac_ctrl_t * p_api_ctrl)
{
    dac_b_instance_ctrl_t * p_ctrl = (dac_b_instance_ctrl_t *) p_api_ctrl;

#if DAC_B_CFG_PARAM_CHECKING_ENABLE

    /* Validate the handle parameter */
    FSP_ASSERT(NULL != p_ctrl);

    /* Validate that the channel is opened. */
    FSP_ERROR_RETURN(p_ctrl->channel_opened, FSP_ERR_NOT_OPEN);
#endif

    {
        FSP_CRITICAL_SECTION_DEFINE;
        FSP_CRITICAL_SECTION_ENTER;

        /* Stop the channel */
        p_ctrl->p_reg->DACR0_b.DACEN = 0U;
        FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->DACR0_b.DACEN, 0);

        FSP_CRITICAL_SECTION_EXIT;
    }

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Stop the D/A conversion, stop output, and close the DAC channel.
 *
 * @retval   FSP_SUCCESS           The channel is successfully closed.
 * @retval   FSP_ERR_ASSERTION     p_api_ctrl is NULL.
 * @retval   FSP_ERR_NOT_OPEN      Channel associated with p_ctrl has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DAC_B_Close (dac_ctrl_t * p_api_ctrl)
{
    dac_b_instance_ctrl_t * p_ctrl = (dac_b_instance_ctrl_t *) p_api_ctrl;

#if DAC_B_CFG_PARAM_CHECKING_ENABLE

    /* Validate the handle parameter */
    FSP_ASSERT(NULL != p_ctrl);

    /* Validate that the channel is opened. */
    FSP_ERROR_RETURN(p_ctrl->channel_opened, FSP_ERR_NOT_OPEN);
#endif
    p_ctrl->p_reg->DACR0 = R_DAC_B0_DACR0_DAOUTDIS_Msk; // Disable output, operation, and coupled operation.

    /* Update the channel state information. */
    p_ctrl->channel_opened = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup DAC_B)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
