/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rm_emwin_rx_port_cfg.h"
#include "rm_emwin_rx_port.h"
#include "rm_emwin_rx_port_private.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "REMW" in ASCII. */
#define RM_EMWIN_RX_PORT_OPEN    (0x52454D57U)

/*******************************************************************************************************************//**
 * @addtogroup RM_EMWIN_RX_PORT
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief  Writes one GPIO pin through the configured I/O port instance.
 *
 * @param[in]  p_ctrl  Pointer to the control block for this instance.
 * @param[in]  pin     GPIO pin to update.
 * @param[in]  level   GPIO output level.
 *
 * @retval FSP_SUCCESS          GPIO pin write completed successfully.
 * @retval FSP_ERR_ASSERTION    A required I/O port pointer is NULL.
 * @return                      See @ref RENESAS_ERROR_CODES or the lower I/O port driver for other possible return
 *                              codes. This function calls
 *                                * ioport_api_t:pinWrite
 **********************************************************************************************************************/
fsp_err_t RM_EMWIN_RX_PORT_PinWrite (rm_emwin_rx_port_instance_ctrl_t * const p_ctrl,
                                     bsp_io_port_pin_t const                  pin,
                                     bsp_io_level_t const                     level)
{
    rm_emwin_rx_port_cfg_t const * p_cfg;

#if RM_EMWIN_RX_PORT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_ctrl->p_cfg);
#endif

    p_cfg = p_ctrl->p_cfg;

#if RM_EMWIN_RX_PORT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg->p_ioport);
    FSP_ASSERT(NULL != p_cfg->p_ioport->p_ctrl);
    FSP_ASSERT(NULL != p_cfg->p_ioport->p_api);
    FSP_ASSERT(NULL != p_cfg->p_ioport->p_api->pinWrite);
#endif

    return p_cfg->p_ioport->p_api->pinWrite(p_cfg->p_ioport->p_ctrl, pin, level);
}

/*******************************************************************************************************************//**
 * @brief  Opens the configured lower SPI driver.
 *
 * @param[in]  p_ctrl  Pointer to the control block for this instance.
 * @param[in]  p_cfg   Pointer to the configuration for this instance.
 *
 * @retval FSP_SUCCESS                  Lower SPI driver is open.
 * @retval FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN         Lower SPI driver is already owned by another user.
 * @return                              See @ref RENESAS_ERROR_CODES or lower level drivers for other possible return
 *                                      codes. This function calls
 *                                        * spi_api_t:open
 **********************************************************************************************************************/
fsp_err_t RM_EMWIN_RX_PORT_Open (rm_emwin_rx_port_instance_ctrl_t * const p_ctrl,
                                 rm_emwin_rx_port_cfg_t const * const     p_cfg)
{
#if RM_EMWIN_RX_PORT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_lower_lvl_spi);
    FSP_ASSERT(NULL != p_cfg->p_lower_lvl_spi->p_api);
    FSP_ASSERT(NULL != p_cfg->p_lower_lvl_spi->p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_lower_lvl_spi->p_api->open);
    FSP_ASSERT(NULL != p_cfg->p_lower_lvl_spi->p_api->callbackSet);
    FSP_ERROR_RETURN(RM_EMWIN_RX_PORT_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    spi_instance_t const * p_spi = p_cfg->p_lower_lvl_spi;
    fsp_err_t              err   = p_spi->p_api->open(p_spi->p_ctrl, p_spi->p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = p_spi->p_api->callbackSet(p_spi->p_ctrl, rm_emwin_rx_port_spi_callback, p_ctrl, NULL);
    if (FSP_SUCCESS != err)
    {
        (void) p_spi->p_api->close(p_spi->p_ctrl);

        return err;
    }

    p_ctrl->p_cfg            = p_cfg;
    p_ctrl->transfer_pending = false;
    p_ctrl->open             = RM_EMWIN_RX_PORT_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  Writes command or data bytes to the serial LCD controller through the configured lower SPI driver.
 *
 * @param[in]  p_ctrl    Pointer to the control block for this instance.
 * @param[in]  p_data    Data to write.
 * @param[in]  length    Number of bytes to write.
 * @param[in]  command   True for command bytes, false for data bytes.
 *
 * @retval FSP_SUCCESS                  Data write completed successfully.
 * @retval FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval FSP_ERR_IN_USE               Another transfer is in progress.
 * @retval FSP_ERR_INVALID_SIZE         Length is zero.
 * @retval FSP_ERR_NOT_OPEN             The emWin RX port is not open.
 * @retval FSP_ERR_TIMEOUT              The lower SPI callback was not received before the transfer timeout.
 * @retval FSP_ERR_TRANSFER_ABORTED     The lower SPI callback reported an error event.
 * @return                              See @ref RENESAS_ERROR_CODES or lower level drivers for other possible return
 *                                      codes. This function calls
 *                                        * spi_api_t:write
 **********************************************************************************************************************/
fsp_err_t RM_EMWIN_RX_PORT_Write (rm_emwin_rx_port_instance_ctrl_t * const p_ctrl,
                                  uint8_t const * const                    p_data,
                                  uint32_t const                           length,
                                  bool const                               command)
{
#if RM_EMWIN_RX_PORT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(0U != length, FSP_ERR_INVALID_SIZE);
    FSP_ERROR_RETURN(RM_EMWIN_RX_PORT_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_ctrl->p_cfg);
    FSP_ASSERT(NULL != p_ctrl->p_cfg->p_lower_lvl_spi);
    FSP_ASSERT(NULL != p_ctrl->p_cfg->p_lower_lvl_spi->p_api);
    FSP_ASSERT(NULL != p_ctrl->p_cfg->p_lower_lvl_spi->p_api->write);
#endif

    rm_emwin_rx_port_cfg_t const * p_cfg = p_ctrl->p_cfg;
    bool transfer_available              = false;

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;
    if (!p_ctrl->transfer_pending)
    {
        transfer_available       = true;
        p_ctrl->transfer_event   = SPI_EVENT_TRANSFER_ABORTED;
        p_ctrl->transfer_pending = true;
    }

    FSP_CRITICAL_SECTION_EXIT;

    FSP_ERROR_RETURN(transfer_available, FSP_ERR_IN_USE);

    fsp_err_t err = FSP_SUCCESS;

    if (p_cfg->use_data_command_pin)
    {
        err =
            RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->data_command_pin, command ? BSP_IO_LEVEL_LOW : BSP_IO_LEVEL_HIGH);
    }

    if ((FSP_SUCCESS == err) && p_cfg->use_chip_select_pin)
    {
        err = RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->chip_select_pin, BSP_IO_LEVEL_LOW);
    }

    if (FSP_SUCCESS == err)
    {
        /* Keep chip select asserted until the lower driver's callback reports completion. */
        spi_instance_t const * p_spi = p_cfg->p_lower_lvl_spi;
        err = p_spi->p_api->write(p_spi->p_ctrl, p_data, length, SPI_BIT_WIDTH_8_BITS);

        if (FSP_SUCCESS == err)
        {
            err = rm_emwin_rx_port_transfer_wait(p_ctrl, RM_EMWIN_RX_PORT_WRITE_TIMEOUT_MS);
        }
    }

    /* A pin failure or lower-driver submission failure must not reserve the transfer slot. */
    if (FSP_SUCCESS != err)
    {
        p_ctrl->transfer_pending = false;
    }

    if (p_cfg->use_chip_select_pin)
    {
        fsp_err_t const cleanup_err = RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->chip_select_pin, BSP_IO_LEVEL_HIGH);
        if (FSP_SUCCESS == err)
        {
            err = cleanup_err;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * @brief  Closes the configured lower SPI driver.
 *
 * @param[in]  p_ctrl  Pointer to the control block for this instance.
 *
 * @retval FSP_SUCCESS                  Lower SPI driver is closed.
 * @retval FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval FSP_ERR_IN_USE               A transfer is in progress.
 * @retval FSP_ERR_NOT_OPEN             The emWin RX port is not open.
 * @return                              See @ref RENESAS_ERROR_CODES or lower level drivers for other possible return
 *                                      codes. This function calls
 *                                        * spi_api_t:close
 **********************************************************************************************************************/
fsp_err_t RM_EMWIN_RX_PORT_Close (rm_emwin_rx_port_instance_ctrl_t * const p_ctrl)
{
#if RM_EMWIN_RX_PORT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(RM_EMWIN_RX_PORT_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(!p_ctrl->transfer_pending, FSP_ERR_IN_USE);
    FSP_ASSERT(NULL != p_ctrl->p_cfg);
    FSP_ASSERT(NULL != p_ctrl->p_cfg->p_lower_lvl_spi);
    FSP_ASSERT(NULL != p_ctrl->p_cfg->p_lower_lvl_spi->p_api);
    FSP_ASSERT(NULL != p_ctrl->p_cfg->p_lower_lvl_spi->p_api->close);
#endif

    spi_instance_t const * p_spi = p_ctrl->p_cfg->p_lower_lvl_spi;
    fsp_err_t              err   = p_spi->p_api->close(p_spi->p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    p_ctrl->open             = 0U;
    p_ctrl->p_cfg            = NULL;
    p_ctrl->transfer_pending = false;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Records the result of a lower SPI transfer.
 *
 * @param[in] p_args    Lower SPI callback arguments.
 **********************************************************************************************************************/
void rm_emwin_rx_port_spi_callback (spi_callback_args_t * p_args)
{
    if (NULL != p_args)
    {
        rm_emwin_rx_port_instance_ctrl_t * p_ctrl = (rm_emwin_rx_port_instance_ctrl_t *) p_args->p_context;

        if ((NULL != p_ctrl) && p_ctrl->transfer_pending)
        {
            p_ctrl->transfer_event   = p_args->event;
            p_ctrl->transfer_pending = false;
        }
    }
}

/*******************************************************************************************************************//**
 * @brief Waits for the lower SPI callback for a bounded number of milliseconds.
 **********************************************************************************************************************/
fsp_err_t rm_emwin_rx_port_transfer_wait (rm_emwin_rx_port_instance_ctrl_t * p_ctrl, uint32_t timeout_ms)
{
    while (p_ctrl->transfer_pending && (timeout_ms > 0U))
    {
        uint32_t poll_count = RM_EMWIN_RX_PORT_MICROSECONDS_PER_MS / RM_EMWIN_RX_PORT_TRANSFER_POLL_DELAY_US;

        while (p_ctrl->transfer_pending && (poll_count > 0U))
        {
            R_BSP_SoftwareDelay(RM_EMWIN_RX_PORT_TRANSFER_POLL_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);
            poll_count--;
        }

        timeout_ms--;
    }

    if (p_ctrl->transfer_pending)
    {
        p_ctrl->transfer_pending = false;

        return FSP_ERR_TIMEOUT;
    }

    FSP_ERROR_RETURN(SPI_EVENT_TRANSFER_COMPLETE == p_ctrl->transfer_event, FSP_ERR_TRANSFER_ABORTED);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_EMWIN_RX_PORT)
 **********************************************************************************************************************/
