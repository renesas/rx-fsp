/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_xspi_target.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "SPIT" in ASCII.  Used to determine if the control block is open. */
#define XSPI_TARGET_PRV_OPEN    (0x53504954U)

/**
 * Gets the extended configuration struct for this instance.
 * @param p_ctrl Pointer to the instance control block.
 */
#define XSPI_TARGET_PRV_EXTENDED_CFG(p_ctrl)    ((xspi_target_extended_cfg_t *)                    \
                                                 ((xspi_target_instance_ctrl_t *) (p_ctrl))->p_cfg \
                                                 ->p_extend)

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t r_xspi_target_protocol_specific_settings(xspi_target_instance_ctrl_t * p_instance_ctrl);

/*******************************************************************************************************************//**
 * @addtogroup XSPI_TARGET
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

const spi_flash_api_t g_xspi_target_on_spi_flash =
{
    .open           = R_XSPI_TARGET_Open,
    .directWrite    = R_XSPI_TARGET_DirectWrite,
    .directRead     = R_XSPI_TARGET_DirectRead,
    .directTransfer = R_XSPI_TARGET_DirectTransfer,
    .spiProtocolSet = R_XSPI_TARGET_SpiProtocolSet,
    .write          = R_XSPI_TARGET_Write,
    .erase          = R_XSPI_TARGET_Erase,
    .statusGet      = R_XSPI_TARGET_StatusGet,
    .xipEnter       = R_XSPI_TARGET_XipEnter,
    .xipExit        = R_XSPI_TARGET_XipExit,
    .bankSet        = R_XSPI_TARGET_BankSet,
    .close          = R_XSPI_TARGET_Close,
    .autoCalibrate  = R_XSPI_TARGET_AutoCalibrate,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Open the xSPI device. After the driver is open, the xSPI device can be accessed like internal flash memory.
 *
 * Implements @ref spi_flash_api_t::open.
 *
 * @retval FSP_SUCCESS              Configuration was successful.
 * @retval FSP_ERR_ASSERTION        The parameter p_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_ALREADY_OPEN     Driver has already been opened with the same p_ctrl.
 * @retval FSP_ERR_INVALID_MODE     Invalid configuration for p_cmd_set.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_Open (spi_flash_ctrl_t * const p_ctrl, spi_flash_cfg_t const * const p_cfg)
{
    xspi_target_instance_ctrl_t * p_instance_ctrl = (xspi_target_instance_ctrl_t *) p_ctrl;
    fsp_err_t ret = FSP_SUCCESS;

#if XSPI_TARGET_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(XSPI_TARGET_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    const xspi_target_extended_cfg_t * const p_cfg_extend = (xspi_target_extended_cfg_t *) (p_cfg->p_extend);
    uint32_t unit = p_cfg_extend->unit;

    /* Check that the unit is present*/
    FSP_ERROR_RETURN(unit < BSP_FEATURE_XSPI_TARGET_UNIT_COUNT, FSP_ERR_IP_UNIT_NOT_PRESENT);
#else
    const xspi_target_extended_cfg_t * const p_cfg_extend = (xspi_target_extended_cfg_t *) (p_cfg->p_extend);
#endif

    R_XSPI_TARGET0_Type * p_reg = (R_XSPI_TARGET0_Type *) (R_XSPI_TARGET0_BASE +
                                                           p_cfg_extend->unit *
                                                           (R_XSPI_TARGET1_BASE - R_XSPI_TARGET0_BASE));

    /* Enable clock to the xSPI block */
    R_BSP_MODULE_START(FSP_IP_XSPI, p_cfg_extend->unit);

    /* Initialize control block. */
    p_instance_ctrl->p_cfg        = p_cfg;
    p_instance_ctrl->p_reg        = p_reg;
    p_instance_ctrl->spi_protocol = p_cfg->spi_protocol;

    /* Set target mode */
    p_reg->DIPCFG = 1U;

    /* Set xSPI protocol mode. */
    p_reg->L15CFG0 =
        (((uint32_t) p_cfg->spi_protocol << R_XSPI_TARGET0_L15CFG0_PRTMD_Pos) &
         R_XSPI_TARGET0_L15CFG0_PRTMD_Msk) |
        (((uint32_t) p_cfg_extend->p_timing_settings->output_assert_delay << R_XSPI_TARGET0_L15CFG0_OEASTEX_Pos) &
         R_XSPI_TARGET0_L15CFG0_OEASTEX_Msk) |
        (((uint32_t) p_cfg_extend->write_data_mask << R_XSPI_TARGET0_L15CFG0_WRMSKMD_Pos) &
         R_XSPI_TARGET0_L15CFG0_WRMSKMD_Msk);

#if XSPI_TARGET_CFG_PARAM_CHECKING_ENABLE
    uint32_t bufsize = p_reg->TBI_b.BUFSIZE;
    FSP_ERROR_RETURN(p_cfg_extend->max_read_frame_size <= bufsize, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg_extend->max_write_frame_size <= bufsize, FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Set maximum Read/Write frame size*/
    p_reg->L15CFG2 =
        (((uint32_t) p_cfg_extend->max_read_frame_size << R_XSPI_TARGET0_L15CFG2_MRDFSIZE_Pos) &
         R_XSPI_TARGET0_L15CFG2_MRDFSIZE_Msk) |
        (((uint32_t) p_cfg_extend->max_write_frame_size << R_XSPI_TARGET0_L15CFG2_MWRFSIZE_Pos) &
         R_XSPI_TARGET0_L15CFG2_MWRFSIZE_Msk);

    /* Setting memory size*/
    p_reg->L2CFG0 = p_cfg_extend->memory_size;

    /* Set xSPI memory-mapping operation. */
    ret = r_xspi_target_protocol_specific_settings(p_instance_ctrl);

    if (FSP_SUCCESS == ret)
    {
        p_instance_ctrl->open = XSPI_TARGET_PRV_OPEN;
    }
    else
    {
        /* If the open fails and no other channels are open, stop the module. */
        R_BSP_MODULE_STOP(FSP_IP_XSPI, p_cfg_extend->unit);
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Writes raw data directly to the OctaFlash. API not supported. Use R_XSPI_TARGET_DirectTransfer
 *
 * Implements @ref spi_flash_api_t::directWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_DirectWrite (spi_flash_ctrl_t    * p_ctrl,
                                     uint8_t const * const p_src,
                                     uint32_t const        bytes,
                                     bool const            read_after_write)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(bytes);
    FSP_PARAMETER_NOT_USED(read_after_write);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Reads raw data directly from the OctaFlash. API not supported. Use R_XSPI_TARGET_DirectTransfer.
 *
 * Implements @ref spi_flash_api_t::directRead.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_DirectRead (spi_flash_ctrl_t * p_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(bytes);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Read/Write a transfer to XSPI Target.
 *
 * Implements @ref spi_flash_api_t::directTransfer.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_DirectTransfer (spi_flash_ctrl_t                  * p_ctrl,
                                        spi_flash_direct_transfer_t * const p_transfer,
                                        spi_flash_direct_transfer_dir_t     direction)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_transfer);
    FSP_PARAMETER_NOT_USED(direction);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Enters XIP (execute in place) mode.
 *
 * Implements @ref spi_flash_api_t::xipEnter.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_XipEnter (spi_flash_ctrl_t * p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Exits XIP (execute in place) mode.
 *
 * Implements @ref spi_flash_api_t::xipExit.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_XipExit (spi_flash_ctrl_t * p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Program a page of data to the flash.
 *
 * Implements @ref spi_flash_api_t::write.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_Write (spi_flash_ctrl_t    * p_ctrl,
                               uint8_t const * const p_src,
                               uint8_t * const       p_dest,
                               uint32_t              byte_count)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(byte_count);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Erase a block or sector of flash.  The byte_count must exactly match one of the erase sizes defined in spi_flash_cfg_t.
 * For chip erase, byte_count must be SPI_FLASH_ERASE_SIZE_CHIP_ERASE.
 *
 * Implements @ref spi_flash_api_t::erase.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_Erase (spi_flash_ctrl_t * p_ctrl, uint8_t * const p_device_address, uint32_t byte_count)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_device_address);
    FSP_PARAMETER_NOT_USED(byte_count);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Gets the write or erase status of the flash.
 *
 * Implements @ref spi_flash_api_t::statusGet.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI Target module.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_StatusGet (spi_flash_ctrl_t * p_ctrl, spi_flash_status_t * const p_status)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_status);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Sets the SPI protocol.
 *
 * Implements @ref spi_flash_api_t::spiProtocolSet.
 *
 * @retval FSP_SUCCESS                SPI protocol updated on MPU peripheral.
 * @retval FSP_ERR_ASSERTION          A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN           Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_SpiProtocolSet (spi_flash_ctrl_t * p_ctrl, spi_flash_protocol_t spi_protocol)
{
    xspi_target_instance_ctrl_t * p_instance_ctrl = (xspi_target_instance_ctrl_t *) p_ctrl;

#if XSPI_TARGET_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(XSPI_TARGET_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Save the old protocol in case of an undefined command set. */
    spi_flash_protocol_t old_protocol = p_instance_ctrl->spi_protocol;
    p_instance_ctrl->spi_protocol = spi_protocol;

    /* Update the SPI protocol and its associated registers. */
    fsp_err_t err = r_xspi_target_protocol_specific_settings(p_instance_ctrl);

    if (FSP_ERR_INVALID_MODE == err)
    {
        /* Restore the original spi protocol. Nothing else has been changed in this case. */
        p_instance_ctrl->spi_protocol = old_protocol;
    }

    return err;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup XSPI)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Perform initialization based on SPI/OPI protocol
 *
 * @param[in]   p_instance_ctrl    Pointer to XSPI specific control structure
 *
 * @retval      FSP_SUCCESS                Protocol based settings completed successfully.
 * @retval      FSP_ERR_INVALID_MODE       Invalid configuration for p_cmd_set.
 **********************************************************************************************************************/
static fsp_err_t r_xspi_target_protocol_specific_settings (xspi_target_instance_ctrl_t * p_instance_ctrl)
{
    R_XSPI_TARGET0_Type * const  p_reg        = p_instance_ctrl->p_reg;
    xspi_target_extended_cfg_t * p_cfg_extend = XSPI_TARGET_PRV_EXTENDED_CFG(p_instance_ctrl);

    /* Get the command set for the configured protocol and save it to the control struct. */
    xspi_target_command_set_t const * p_cmd_set = p_cfg_extend->p_cmd_set;
    FSP_ERROR_RETURN(NULL != p_cmd_set, FSP_ERR_INVALID_MODE);

    /* Update the SPI protocol and latency mode. */
    uint32_t l15cfg0 = p_reg->L15CFG0 &
                       ~(R_XSPI_TARGET0_L15CFG0_PRTMD_Msk);
    l15cfg0 |=
        (((uint32_t) p_instance_ctrl->spi_protocol << R_XSPI_TARGET0_L15CFG0_PRTMD_Pos) &
         R_XSPI_TARGET0_L15CFG0_PRTMD_Msk);
    p_reg->L15CFG0 = l15cfg0;

    /* Specifies the read/write commands and Read dummy clocks for Device
     * (see "Flow of Memory-mapping" in the xSPI section of the relevant hardware manual). */
#if XSPI_TARGET_CFG_PARAM_CHECKING_ENABLE
    if ((p_cmd_set->frame_format == XSPI_TARGET_FRAME_FORMAT_XSPI_PROFILE_2) ||
        (p_cmd_set->frame_format == XSPI_TARGET_FRAME_FORMAT_XSPI_PROFILE_2_EXTENDED))
    {
        FSP_ERROR_RETURN(p_instance_ctrl->p_cfg->address_bytes == SPI_FLASH_ADDRESS_BYTES_4, FSP_ERR_INVALID_ARGUMENT);
    }
#endif
    uint32_t l15cfg1 =
        ((uint32_t) (p_cmd_set->frame_format << R_XSPI_TARGET0_L15CFG1_FFMT_Pos) & R_XSPI_TARGET0_L15CFG1_FFMT_Msk) |
        (((uint32_t) p_instance_ctrl->p_cfg->address_bytes << R_XSPI_TARGET0_L15CFG1_ADDSIZE_Pos) &
         R_XSPI_TARGET0_L15CFG1_ADDSIZE_Msk) |
        ((uint32_t) (p_cmd_set->read_dummy_cycles << R_XSPI_TARGET0_L15CFG1_RDLATE_Pos) &
         R_XSPI_TARGET0_L15CFG1_RDLATE_Msk) |
        ((uint32_t) (p_cmd_set->program_dummy_cycles << R_XSPI_TARGET0_L15CFG1_WRLATE_Pos) &
         R_XSPI_TARGET0_L15CFG1_WRLATE_Msk);

    p_reg->L15CFG1 = l15cfg1;

    p_reg->L2CFG1 =
        (((uint32_t) (p_cmd_set->read_register_command) << R_XSPI_TARGET0_L2CFG1_RDRCMD_Pos) &
         R_XSPI_TARGET0_L2CFG1_RDRCMD_Msk) |
        (((uint32_t) (p_cmd_set->read_memory_command) << R_XSPI_TARGET0_L2CFG1_RDMCMD_Pos) &
         R_XSPI_TARGET0_L2CFG1_RDMCMD_Msk) |
        (((uint32_t) (p_cmd_set->write_register_command) << R_XSPI_TARGET0_L2CFG1_WRRCMD_Pos) &
         R_XSPI_TARGET0_L2CFG1_WRRCMD_Msk) |
        (((uint32_t) (p_cmd_set->write_memory_command) << R_XSPI_TARGET0_L2CFG1_WRMCMD_Pos) &
         R_XSPI_TARGET0_L2CFG1_WRMCMD_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Selects the bank to access. Use XSPI_TARGET_bank_select_t as the bank value.
 *
 * Implements @ref spi_flash_api_t::bankSet.
 *
 * @retval FSP_ERR_UNSUPPORTED           This function is unsupported.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_BankSet (spi_flash_ctrl_t * p_ctrl, uint32_t bank)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(bank);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * AutoCalibrate the XSPI_TARGET DS signal.
 *
 * Implements @ref spi_flash_api_t::autoCalibrate.
 *
 * @retval FSP_ERR_UNSUPPORTED           This function is unsupported.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_AutoCalibrate (spi_flash_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Close the XSPI driver module.
 *
 * Implements @ref spi_flash_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_instance_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_TARGET_Close (spi_flash_ctrl_t * p_ctrl)
{
    xspi_target_instance_ctrl_t * p_instance_ctrl = (xspi_target_instance_ctrl_t *) p_ctrl;

#if XSPI_TARGET_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(XSPI_TARGET_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_instance_ctrl->p_cfg);
    FSP_ASSERT(NULL != p_instance_ctrl->p_cfg->p_extend);
#endif

    xspi_target_extended_cfg_t * p_cfg_extend = XSPI_TARGET_PRV_EXTENDED_CFG(p_instance_ctrl);

    p_instance_ctrl->open = 0U;

    /* Disable clock to the XSPI block if all channels are closed. */
    R_BSP_MODULE_STOP(FSP_IP_XSPI, p_cfg_extend->unit);

    return FSP_SUCCESS;
}
