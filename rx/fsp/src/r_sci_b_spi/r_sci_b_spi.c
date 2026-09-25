/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include "r_sci_b_spi.h"
#include "r_sci_b_spi_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE == 1
 #define SCI_B_SPI_PRV_DMA_RX_TRANSFER_SETTINGS    ((uint32_t) (TRANSFER_MODE_NORMAL << TRANSFER_SETTINGS_MODE_BITS) | \
                                                    (uint32_t) (TRANSFER_SIZE_1_BYTE << TRANSFER_SETTINGS_SIZE_BITS) | \
                                                    (uint32_t) (TRANSFER_ADDR_MODE_FIXED <<                            \
                                                                TRANSFER_SETTINGS_SRC_ADDR_BITS) |                     \
                                                    (uint32_t) (TRANSFER_IRQ_END << TRANSFER_SETTINGS_IRQ_BITS) |      \
                                                    (uint32_t) (TRANSFER_ADDR_MODE_INCREMENTED <<                      \
                                                                TRANSFER_SETTINGS_DEST_ADDR_BITS))

 #define SCI_B_SPI_PRV_DMA_TX_TRANSFER_SETTINGS    ((uint32_t) (TRANSFER_MODE_NORMAL << TRANSFER_SETTINGS_MODE_BITS) | \
                                                    (uint32_t) (TRANSFER_SIZE_1_BYTE << TRANSFER_SETTINGS_SIZE_BITS) | \
                                                    (uint32_t) (TRANSFER_ADDR_MODE_INCREMENTED <<                      \
                                                                TRANSFER_SETTINGS_SRC_ADDR_BITS) |                     \
                                                    (uint32_t) (TRANSFER_IRQ_END << TRANSFER_SETTINGS_IRQ_BITS) |      \
                                                    (uint32_t) (TRANSFER_ADDR_MODE_FIXED <<                            \
                                                                TRANSFER_SETTINGS_DEST_ADDR_BITS))
#endif

#define SCI_B_SPI_PRV_CLK_MAX_N                    (0xFFU)
#define SCI_B_SPI_PRV_CLK_MAX_n                    (3U)
#define SCI_B_SPI_PRV_CLK_MIN_DIV                  (4U)
#define SCI_B_SPI_PRV_CLK_MAX_DIV                  ((SCI_B_SPI_PRV_CLK_MAX_N + 1) * 8 * \
                                                    (1 << (2 * SCI_B_SPI_PRV_CLK_MAX_n - 1)))
#define SCI_B_SPI_PRV_CHR_RST_VALUE                (0x0200U)
#define SCI_B_SPI_PRV_DATA_REG_MASK                (0xFFFFFF00)
#define SCI_B_SPI_PRV_RDAT_MASK                    (0xFFU)
#define SCI_B_SPI_PRV_FCR_TRIGGER_MASK             (R_SCI_B0_FCR_RSTRG_Msk)
#define SCI_B_SPI_PRV_FCR_RESET_FIFOS_MASK         (R_SCI_B0_FCR_TFRST_Msk | R_SCI_B0_FCR_RFRST_Msk)
#define SCI_B_SPI_PRV_FCR_RST_VALUE                (R_SCI_B0_FCR_RSTRG_Msk | R_SCI_B0_FCR_RTRG_Msk)

#if BSP_FEATURE_SCI_BASE_ADDRESS_OFFSET_EQUAL == 1

/* SCI channel size */
 #define SCI_B_REG_SIZE                            (R_SCI_B1_BASE - R_SCI_B0_BASE)
#endif

/** "SCIBS" in ASCII, used to determine if channel is open. */
#define SCI_B_SPI_OPEN                             (0x53434953ULL)

/***********************************************************************************************************************
 * Private global variables.
 **********************************************************************************************************************/

const spi_api_t g_spi_on_sci_b =
{
    .open        = R_SCI_B_SPI_Open,
    .read        = R_SCI_B_SPI_Read,
    .write       = R_SCI_B_SPI_Write,
    .writeRead   = R_SCI_B_SPI_WriteRead,
    .close       = R_SCI_B_SPI_Close,
    .callbackSet = R_SCI_B_SPI_CallbackSet
};

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function declarations.
 **********************************************************************************************************************/

static void r_sci_b_spi_hw_config(sci_b_spi_instance_ctrl_t * const p_ctrl);

#if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE == 1
static fsp_err_t r_sci_b_spi_transfer_config(sci_b_spi_instance_ctrl_t * const p_ctrl);
void             sci_b_spi_rx_dmac_callback(sci_b_spi_instance_ctrl_t const * const p_ctrl);
void             sci_b_spi_tx_dmac_callback(sci_b_spi_instance_ctrl_t const * const p_ctrl);

#endif
static fsp_err_t r_sci_b_spi_write_read_common(sci_b_spi_instance_ctrl_t * const p_ctrl,
                                               void const                      * p_src,
                                               void                            * p_dest,
                                               uint32_t const                    length);
static void r_sci_b_spi_start_transfer(sci_b_spi_instance_ctrl_t * const p_ctrl);
static void r_sci_b_spi_transmit(sci_b_spi_instance_ctrl_t * p_ctrl);
static void r_sci_b_spi_call_callback(sci_b_spi_instance_ctrl_t * p_ctrl, spi_event_t event);

void sci_b_spi_txi_isr(void);
void sci_b_spi_rxi_isr(void);
void sci_b_spi_tei_isr(void);
void sci_b_spi_eri_isr(void);

#if BSP_FEATURE_SCI_BASE_ADDRESS_OFFSET_EQUAL == 0

/* RSCI base address */
static const void volatile * p_sci_b_base_address[BSP_FEATURE_SCI_MAX_CHANNEL] =
{
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 0))
    [0] = (void *) R_SCI_B0_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 1))
    [1] = (void *) R_SCI_B1_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 2))
    [2] = (void *) R_SCI_B2_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 3))
    [3] = (void *) R_SCI_B3_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 4))
    [4] = (void *) R_SCI_B4_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 5))
    [5] = (void *) R_SCI_B5_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 6))
    [6] = (void *) R_SCI_B6_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 7))
    [7] = (void *) R_SCI_B7_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 8))
    [8] = (void *) R_SCI_B8_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 9))
    [9] = (void *) R_SCI_B9_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 10))
    [10] = (void *) R_SCI_B10_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 11))
    [11] = (void *) R_SCI_B11_BASE,
 #endif
 #if (BSP_FEATURE_SCI_CHANNELS & (1 << 12))
    [12] = (void *) R_SCI_B12_BASE,
 #endif
};
#endif

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup SCI_B_SPI
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize a channel for SPI communication mode. Implements @ref spi_api_t::open.
 *
 * This function performs the following tasks:
 *   - Performs parameter checking and processes error conditions.
 *   - Enables the clock for the SCI channel.
 *   - Initializes the associated registers with default value and the user-configurable options.
 *   - Provides the channel handle for use with other API functions.
 *
 * @param      p_api_ctrl                      Pointer to the control structure.
 * @param      p_cfg                           Pointer to a configuration structure.
 *
 * @retval     FSP_SUCCESS                     Channel initialized successfully.
 * @retval     FSP_ERR_ASSERTION               An input parameter is invalid or NULL.
 * @retval     FSP_ERR_ALREADY_OPEN            The instance has already been opened.
 * @retval     FSP_ERR_IP_CHANNEL_NOT_PRESENT  The channel number is invalid.
 * @retval     FSP_ERR_UNSUPPORTED             Fifo mode is requested but a transfer interface is not used
 **********************************************************************************************************************/
fsp_err_t R_SCI_B_SPI_Open (spi_ctrl_t * p_api_ctrl, spi_cfg_t const * const p_cfg)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t err = FSP_SUCCESS;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(SCI_B_SPI_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ASSERT(NULL != p_cfg->p_callback);
    FSP_ERROR_RETURN(BSP_FEATURE_SCI_CHANNELS & (1U << p_cfg->channel), FSP_ERR_IP_CHANNEL_NOT_PRESENT);
 #if SCI_B_SPI_CFG_FIFO_SUPPORT

    /* FIFO mode is only supported when using a transfer interface for both transmission and reception */
    sci_b_spi_extended_cfg_t * p_extend = (sci_b_spi_extended_cfg_t *) p_cfg->p_extend;
    FSP_ERROR_RETURN(((SCI_B_SPI_TX_FIFO_TRIGGER_DISABLED == p_extend->tx_fifo_trigger) ||
                      (p_cfg->p_transfer_tx && p_cfg->p_transfer_rx)),
                     FSP_ERR_UNSUPPORTED);
 #endif

    FSP_ASSERT(p_cfg->rxi_irq >= 0 || p_cfg->p_transfer_rx);
    FSP_ASSERT(p_cfg->txi_irq >= 0 || p_cfg->p_transfer_tx);
    FSP_ASSERT(p_cfg->tei_irq >= 0);
    FSP_ASSERT(p_cfg->eri_irq >= 0);
#endif

#if BSP_FEATURE_SCI_BASE_ADDRESS_OFFSET_EQUAL == 1
    p_ctrl->p_reg = (R_SCI_B0_Type *) (R_SCI_B0_BASE + (SCI_B_REG_SIZE * p_cfg->channel));
#else
    p_ctrl->p_reg = (R_SCI_B0_Type *) p_sci_b_base_address[p_cfg->channel];
#endif

    p_ctrl->p_cfg = p_cfg;

    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

#if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE == 1

    /* Open the SCI_B_SPI transfer interface if available. */
    err = r_sci_b_spi_transfer_config(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Write user configuration to registers. */
    r_sci_b_spi_hw_config(p_ctrl);

    /* Enable optional interrupts. */
    if (0 <= p_cfg->rxi_irq)
    {
        R_BSP_IrqCfgEnable(p_cfg->rxi_irq, (uint32_t) p_cfg->rxi_ipl, p_ctrl);
    }

    if (0 <= p_cfg->txi_irq)
    {
        R_BSP_IrqCfgEnable(p_cfg->txi_irq, (uint32_t) p_cfg->txi_ipl, p_ctrl);
    }

    /* Enable required interrupts */
    R_BSP_IrqCfgEnable(p_cfg->tei_irq, (uint32_t) p_cfg->tei_ipl, p_ctrl);
    R_BSP_IrqCfgEnable(p_cfg->eri_irq, (uint32_t) p_cfg->eri_ipl, p_ctrl);

    p_ctrl->open = SCI_B_SPI_OPEN;

    return err;
}

/*******************************************************************************************************************//**
 * Receive data from an SPI device. Implements @ref spi_api_t::read.
 *
 * The function performs the following tasks:
 *   - Performs parameter checking and processes error conditions.
 *   - Enable transmitter.
 *   - Enable receiver.
 *   - Enable interrupts.
 *   - Start data transmission by writing data to the TXD register.
 *   - Receive data from receive buffer full interrupt occurs and copy data to the buffer of destination.
 *   - Complete data reception via receive buffer full interrupt and transmitting dummy data.
 *   - Disable transmitter.
 *   - Disable receiver.
 *   - Disable interrupts.
 *
 * @param      p_api_ctrl           Pointer to the control structure.
 * @param      p_dest               Pointer to the destination buffer.
 * @param[in]  length               The number of bytes to transfer.
 * @param[in]  bit_width            Invalid for SCI_B_SPI (Set to SPI_BIT_WIDTH_8_BITS).
 *
 * @retval     FSP_SUCCESS          Read operation successfully completed.
 * @retval     FSP_ERR_ASSERTION    One of the following invalid parameters passed:
 *                                  - Pointer p_api_ctrl is NULL
 *                                  - Bit width is not 8 bits
 *                                  - Length is equal to 0
 *                                  - Pointer to destination is NULL
 *                                  - Transfer length is larger than supported by the transfer instances.
 * @retval     FSP_ERR_NOT_OPEN     The channel has not been opened. Open the channel first.
 * @retval     FSP_ERR_UNSUPPORTED  The given bit_width is not supported.
 * @retval     FSP_ERR_IN_USE       A transfer is already in progress.
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 *               - @ref transfer_api_t::reconfigure
 **********************************************************************************************************************/
fsp_err_t R_SCI_B_SPI_Read (spi_ctrl_t * const    p_api_ctrl,
                            void                * p_dest,
                            uint32_t const        length,
                            spi_bit_width_t const bit_width)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE

    /* Check bit_width parameter, in simple SPI, only 8 bits operation is allowed. */
    FSP_ERROR_RETURN(SPI_BIT_WIDTH_8_BITS == bit_width, FSP_ERR_UNSUPPORTED);

    /* Check the destination, should not be NULL. */
    FSP_ASSERT(NULL != p_dest);
#else
    FSP_PARAMETER_NOT_USED(bit_width);
#endif

    return r_sci_b_spi_write_read_common(p_ctrl, NULL, p_dest, length);
}

/*******************************************************************************************************************//**
 * Transmit data to a SPI  device. Implements @ref spi_api_t::write.
 *
 * The function performs the following tasks:
 *   - Performs parameter checking and processes error conditions.
 *   - Enable transmitter.
 *   - Enable interrupts.
 *   - Start data transmission with data via transmit buffer empty interrupt.
 *   - Copy data from source buffer to the SPI data register for transmission.
 *   - Complete data transmission via transmit buffer empty interrupt.
 *   - Disable transmitter.
 *   - Disable receiver.
 *   - Disable interrupts.
 *
 * @param      p_api_ctrl           Pointer to the control structure.
 * @param      p_src                Pointer to the source buffer.
 * @param[in]  length               The number of bytes to transfer.
 * @param[in]  bit_width            Invalid for SCI_B_SPI (Set to SPI_BIT_WIDTH_8_BITS).
 *
 * @retval     FSP_SUCCESS          Write operation successfully completed.
 * @retval     FSP_ERR_ASSERTION    One of the following invalid parameters passed:
 *                                  - Pointer p_api_ctrl is NULL
 *                                  - Pointer to source is NULL
 *                                  - Length is equal to 0
 *                                  - Bit width is not equal to 8 bits
 *                                  - Transfer length is larger than supported by the transfer instances.
 * @retval     FSP_ERR_NOT_OPEN     The channel has not been opened. Open the channel first.
 * @retval     FSP_ERR_UNSUPPORTED  The given bit_width is not supported.
 * @retval     FSP_ERR_IN_USE       A transfer is already in progress.
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 *               - @ref transfer_api_t::reconfigure
 **********************************************************************************************************************/
fsp_err_t R_SCI_B_SPI_Write (spi_ctrl_t * const    p_api_ctrl,
                             void const          * p_src,
                             uint32_t const        length,
                             spi_bit_width_t const bit_width)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(SPI_BIT_WIDTH_8_BITS == bit_width, FSP_ERR_UNSUPPORTED);
    FSP_ASSERT(NULL != p_src);
#else
    FSP_PARAMETER_NOT_USED(bit_width);
#endif

    return r_sci_b_spi_write_read_common(p_ctrl, p_src, NULL, length);
}

/*******************************************************************************************************************//**
 * Simultaneously transmit data to SPI device while receiving data from SPI device (full duplex).
 * Implements @ref spi_api_t::writeRead.
 *
 * The function performs the following tasks:
 *   - Performs parameter checking and processes error conditions.
 *   - Enable transmitter.
 *   - Enable receiver.
 *   - Enable interrupts.
 *   - Start data transmission using transmit buffer empty interrupt (or by writing to the TDR register).
 *   - Copy data from source buffer to the SPI data register for transmission.
 *   - Receive data from receive buffer full interrupt and copy data to the destination buffer.
 *   - Complete data transmission and reception via transmit end interrupt.
 *   - Disable transmitter.
 *   - Disable receiver.
 *   - Disable interrupts.
 *
 * @param      p_api_ctrl           Pointer to the control structure.
 * @param      p_src                Pointer to the source buffer.
 * @param      p_dest               Pointer to the destination buffer.
 * @param[in]  length               The number of bytes to transfer.
 * @param[in]  bit_width            Invalid for SCI_B_SPI (Set to SPI_BIT_WIDTH_8_BITS).
 *
 * @retval     FSP_SUCCESS          Write operation successfully completed.
 * @retval     FSP_ERR_ASSERTION    One of the following invalid parameters passed:
 *                                  - Pointer p_api_ctrl is NULL
 *                                  - Pointer to source is NULL
 *                                  - Pointer to destination is NULL
 *                                  - Length is equal to 0
 *                                  - Bit width is not equal to 8 bits
 *                                  - Transfer length is larger than supported by the transfer instances.
 * @retval     FSP_ERR_NOT_OPEN     The channel has not been opened. Open the channel first.
 * @retval     FSP_ERR_UNSUPPORTED  The given bit_width is not supported.
 * @retval     FSP_ERR_IN_USE       A transfer is already in progress.
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 *               - @ref transfer_api_t::reconfigure
 **********************************************************************************************************************/
fsp_err_t R_SCI_B_SPI_WriteRead (spi_ctrl_t * const    p_api_ctrl,
                                 void const          * p_src,
                                 void                * p_dest,
                                 uint32_t const        length,
                                 spi_bit_width_t const bit_width)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(SPI_BIT_WIDTH_8_BITS == bit_width, FSP_ERR_UNSUPPORTED);
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);
#else
    FSP_PARAMETER_NOT_USED(bit_width);
#endif

    return r_sci_b_spi_write_read_common(p_ctrl, p_src, p_dest, length);
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements spi_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_B_SPI_CallbackSet (spi_ctrl_t * const          p_api_ctrl,
                                   void (                    * p_callback)(spi_callback_args_t *),
                                   void * const                p_context,
                                   spi_callback_args_t * const p_callback_memory)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if (SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(SCI_B_SPI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable the SCI channel and set the instance as not open. Implements @ref spi_api_t::close.
 *
 * @param      p_api_ctrl         Pointer to an opened instance.
 *
 * @retval     FSP_SUCCESS        Channel successfully closed.
 * @retval     FSP_ERR_ASSERTION  The parameter p_api_ctrl is NULL.
 * @retval     FSP_ERR_NOT_OPEN   The channel has not been opened. Open the channel first.
 **********************************************************************************************************************/
fsp_err_t R_SCI_B_SPI_Close (spi_ctrl_t * const p_api_ctrl)
{
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) p_api_ctrl;

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(SCI_B_SPI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if SCI_B_SPI_CFG_FIFO_SUPPORT

    /* Set all bits in SCR0 to 0, except TE */
    p_ctrl->p_reg->SCR0 &= R_SCI_B0_SCR0_TE_Msk;

    /* Reset the transmit fifo */
    p_ctrl->p_reg->FCR_b.TFRST = 1U;

    /* Clear the SCR3_b.FM bit. This is necessary to set the TEND bit before setting the TE bit. If TEND is 0
     * when TE is set to 0, the SCI peripheral works abnormally next time the TE made to 1.*/
    p_ctrl->p_reg->SCR3 = 0U;
#endif

    /* Disable transmission */
    p_ctrl->p_reg->SCR0 = 0;

    if (0 <= p_ctrl->p_cfg->txi_irq)
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->txi_irq);
    }

    if (0 <= p_ctrl->p_cfg->rxi_irq)
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);
    }

    R_BSP_IrqDisable(p_ctrl->p_cfg->eri_irq);
    R_BSP_IrqDisable(p_ctrl->p_cfg->tei_irq);

    /* Disable the clock to the SCI channel. */
    R_BSP_MODULE_STOP(FSP_IP_SCI, p_ctrl->p_cfg->channel);

    if (NULL != p_ctrl->p_cfg->p_transfer_rx)
    {
        p_ctrl->p_cfg->p_transfer_rx->p_api->close(p_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }

    if (NULL != p_ctrl->p_cfg->p_transfer_tx)
    {
        p_ctrl->p_cfg->p_transfer_tx->p_api->close(p_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }

    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Calculate the register settings required to achieve the desired bitrate.
 *
 * @param[in]  bitrate            bitrate [bps]. For example, 250,000; 500,00; 2,500,000 (max), etc.
 * @param      clock_source       clock source (PCLKA or SCISPICLK) used for bit rate calculation.
 * @param      sclk_div           Pointer to sci_b_spi_div_setting_t used to configure baudrate settings.
 * @retval     FSP_SUCCESS        Baud rate is set successfully.
 * @retval     FSP_ERR_ASSERTION  Baud rate is not achievable.
 * @retval     FSP_ERR_INVALID_ARGUMENT bitrate invalid.
 * @note       The application must pause for 1 bit time after the BRR register is loaded before transmitting/receiving
 *             to allow time for the clock to settle.
 **********************************************************************************************************************/
fsp_err_t R_SCI_B_SPI_CalculateBitrate (uint32_t                  bitrate,
                                        sci_b_spi_clock_source_t  clock_source,
                                        sci_b_spi_div_setting_t * sclk_div)
{
    uint32_t peripheral_clock;
    if (SCI_B_SPI_SOURCE_CLOCK_PCLK == clock_source)
    {
        peripheral_clock = R_FSP_SystemClockHzGet(BSP_FEATURE_SCI_CLOCK);
    }
    else
    {
#if BSP_FEATURE_BSP_HAS_SCISPI_CLOCK
        peripheral_clock = R_FSP_SciSpiClockHzGet();
#elif BSP_FEATURE_BSP_HAS_SCI_CLOCK
        peripheral_clock = R_FSP_SciClockHzGet();
#endif
    }

#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != sclk_div);
    FSP_ASSERT(bitrate);
    FSP_ASSERT(bitrate >= (peripheral_clock + SCI_B_SPI_PRV_CLK_MAX_DIV - 1U) / SCI_B_SPI_PRV_CLK_MAX_DIV);
#endif

    uint32_t divisor = 0;
    uint32_t brr     = 0;

    for (uint8_t cks = 0; cks <= 3; cks++)
    {
        for (int8_t bgdm = 1; bgdm >= 0; bgdm--)
        {
            divisor = ((uint32_t) (1 << (2 * (cks + 1) - bgdm))) * bitrate;

            /* Calculate BRR so that the bit rate is the largest possible value less than or equal to the desired
             * bitrate. */
            brr = (peripheral_clock + divisor - 1) / divisor - 1;

            if (brr <= UINT8_MAX)
            {
                sclk_div->brr  = (uint8_t) brr;
                sclk_div->cks  = (uint8_t) (cks & 3);
                sclk_div->bgdm = (uint8_t) (bgdm & 1);

                return FSP_SUCCESS;
            }
        }
    }

    return FSP_ERR_INVALID_ARGUMENT;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup SCI_B_SPI)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures SCI registers based on the user configuration.
 * @param      p_ctrl          Pointer to control structure.
 **********************************************************************************************************************/
static void r_sci_b_spi_hw_config (sci_b_spi_instance_ctrl_t * const p_ctrl)
{
    spi_cfg_t const          * p_cfg    = p_ctrl->p_cfg;
    sci_b_spi_extended_cfg_t * p_extend = (sci_b_spi_extended_cfg_t *) p_cfg->p_extend;

    /* Initialize registers to their reset values. */
    uint32_t scr0 = 0U;
    uint32_t scr1 = R_SCI_B0_SCR1_SPB2DT_Msk;
    uint32_t scr2 = 0U;
    uint32_t scr3 = R_SCI_B0_SCR3_CPHA_Msk | R_SCI_B0_SCR3_CPOL_Msk | R_SCI_B0_SCR3_DDIR_Msk |
                    SCI_B_SPI_PRV_CHR_RST_VALUE;

    /* SCR4.SCKSEL selects the master receive clock used in simple spi mode on supported MCUs. */
    uint32_t scr4  = 0U;
    uint32_t sscr  = 0U;
    uint32_t rfscr = 0U;
    uint32_t fcr   = SCI_B_SPI_PRV_FCR_RST_VALUE;

    /* SCI Initialization in Simple SPI Mode (See Section RSCI Initialization (Simple SPI Mode) and RSCI Initialization (Clock Synchronous Mode) of the relevant hardware manual). */

    /* Write settings to SCR3:
     * - Set Bypass Synchronizer circuit between bus clock and operation clock.
     * - Set Character Length to 8-Bit.
     * - Set MSB first.
     * - set CPHA and CPOL.
     * - Set Simple SPI Mode.
     */
    if (SPI_BIT_ORDER_MSB_FIRST == p_cfg->bit_order)
    {
        /* Configure MSB first (Default is LSB). */
        scr3 &= ~R_SCI_B0_SCR3_DDIR_Msk;
    }

    if (SPI_MODE_SLAVE == p_cfg->operating_mode)
    {
        /* Select slave mode. */
        scr3 |= 2U << R_SCI_B0_SCR3_CKE_Pos;

        /* Select to use SSLn input pin */
        scr0 |= R_SCI_B0_SCR0_SSE_Msk;
    }

    /* Apply CPOL and CPHA settings as required. By default SCR2.CPHA=1, SCR2.CPOL=1. */
    if (SPI_CLK_PHASE_EDGE_ODD == p_cfg->clk_phase)
    {
        /* In order to get sampling on the ODD edge set SCR3.CPHA = 0. */
        scr3 &= ~R_SCI_B0_SCR3_CPHA_Msk;
    }

    /* In order to get sampling on the even clock edge set SCR3.CPHA = 1. */
    if (SPI_CLK_POLARITY_LOW == p_cfg->clk_polarity)
    {
        /* set SCR3.CPOL = 0 for clock polarity as low during idle. (See section Relationship between Clock and Transmit/Receive Data of the relevant hardware manual). */
        scr3 &= ~R_SCI_B0_SCR3_CPOL_Msk;
    }

    /* Apply the synchronization bypass settings. */
    scr3 |= (uint32_t) ((p_extend->clock_source) << R_SCI_B0_SCR3_SYNDIS_Pos);

    /* Set Simple SPI mode. */
    scr3 |= 3U << R_SCI_B0_SCR3_MOD_Pos;

#if SCI_B_SPI_CFG_FIFO_SUPPORT

    /* Select FIFO mode enabled/disabled */
    uint8_t fifo_mode = (uint8_t) (p_extend->tx_fifo_trigger > SCI_B_SPI_TX_FIFO_TRIGGER_DISABLED);
    scr3 |= (uint32_t) (fifo_mode << R_SCI_B0_SCR3_FM_Pos);
#endif

    if (SPI_MODE_MASTER == p_cfg->operating_mode)
    {
        /* Write settings to SCR2:
         * - Write the BRR setting.
         * - Write the clock divider setting.
         * - Write the Baud Rate Generator Double-Speed Mode setting.
         */
        scr2 |= (uint32_t) (p_extend->clk_div.cks << R_SCI_B0_SCR2_CKS_Pos);
        scr2 |= (uint32_t) ((p_extend->clk_div.brr) << R_SCI_B0_SCR2_BRR_Pos);
        scr2 |= (uint32_t) ((p_extend->clk_div.bgdm) << R_SCI_B0_SCR2_BGDM_Pos);

#if BSP_FEATURE_SCI_B_SPI_HAS_RX_SAMPLING_DELAY

        /* Write the receive sampling adjustment setting. This setting adjusts
         * the master receive sampling timing to account for the propagation delay
         * of SCK and MISO. Refer to the diagram "Reception Sampling Timing
         * Adjustment Operation in Clock Synchronous Mode (Master)" in the
         * SCI section of the relevant hardware manual.
         *
         * Note the enum value is 1 greater than the RTMG register value.
         */
        if (p_extend->rx_sampling_delay > SCI_B_SPI_RX_SAMPLING_DELAY_CYCLES_0)
        {
            scr4 |= R_SCI_B0_SCR4_RTADJ_Msk | ((p_extend->rx_sampling_delay) << R_SCI_B0_SCR4_RTMG_Pos);
        }
#endif
    }

    /* Enable Clock for the SCI Channel. */
    R_BSP_MODULE_START(FSP_IP_SCI, p_cfg->channel);

    /* Set TEIE, TIE, RIE, TE, and RE to 0. */
    p_ctrl->p_reg->SCR0 = 0;

    /* If TCLK is slower than the bus clock, then wait for the internal state to be updated (See Section Notes regarding register access when operation clock (TCLK) is slower than bus
     * clock (PCLK) of the relevant hardware manual). */
    FSP_HARDWARE_REGISTER_WAIT(p_ctrl->p_reg->SISSR, 0U);

    /* Clear status flags. */
    sscr = R_SCI_B0_SSCR_RDRFC_Msk | R_SCI_B0_SSCR_AFERC_Msk | R_SCI_B0_SSCR_APERC_Msk | R_SCI_B0_SSCR_MFFC_Msk |
           R_SCI_B0_SSCR_ORERC_Msk | R_SCI_B0_SSCR_DFERC_Msk | R_SCI_B0_SSCR_DPERC_Msk | R_SCI_B0_SSCR_DCMFC_Msk |
           R_SCI_B0_SSCR_ERSC_Msk;
    rfscr = R_SCI_B0_RFSCR_DRC_Msk;

#if SCI_B_SPI_CFG_FIFO_SUPPORT
    if (fifo_mode)
    {
        /* Keep receive trigger at default level of 0 (1 byte RX trigger level) so that the
         * transfer IP pulls out data as soon as it is available. */
        fcr = SCI_B_SPI_PRV_FCR_TRIGGER_MASK | (uint32_t) (p_extend->tx_fifo_trigger << R_SCI_B0_FCR_TTRG_Pos);
    }
#endif

    /* Set FCR. Reset FIFO/data registers. */
    p_ctrl->p_reg->FCR = fcr | SCI_B_SPI_PRV_FCR_RESET_FIFOS_MASK;

    /* Write all settings except MOD[2:0] to CCR3 (See Table "Example flow of SCI initialization in clock synchronous mode with
     * non-FIFO selected" in the SCI section of the relevant hardware manual). */
    p_ctrl->p_reg->SCR3 = scr3 & ~(R_SCI_B0_SCR3_MOD_Msk);

    /* Write settings to registers. */
    p_ctrl->p_reg->SCR3 = scr3;

#if SCI_B_SPI_CFG_FIFO_SUPPORT
    if (fifo_mode)
    {
        /* In FIFO mode, the FIFOs need to be reset after CCF3.FM has been enabled */
        p_ctrl->p_reg->FCR = fcr | SCI_B_SPI_PRV_FCR_RESET_FIFOS_MASK;
    }
#endif

    /* Write settings to registers. */
    p_ctrl->p_reg->SCR2  = scr2;
    p_ctrl->p_reg->SCR1  = scr1;
    p_ctrl->p_reg->SCR4  = scr4;
    p_ctrl->p_reg->SSCR  = sscr;
    p_ctrl->p_reg->RFSCR = rfscr;
    p_ctrl->p_reg->SCR0  = scr0;
}

#if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE == 1

/*******************************************************************************************************************//**
 * Configures SCI SPI related transfer drivers (if enabled).
 *
 * @param[in]     p_cfg                     Pointer to SCI SPI specific configuration structure.
 * @param[in]     p_fsp_feature             FSP feature.
 *
 * @retval        FSP_SUCCESS               Operation successfully completed.
 * @retval        FSP_ERR_ASSERTION         One of the following invalid parameters passed:
 *                                          - Pointer p_cfg is NULL
 *                                          - Interrupt is not enabled
 **********************************************************************************************************************/
static fsp_err_t r_sci_b_spi_transfer_config (sci_b_spi_instance_ctrl_t * const p_ctrl)
{
    fsp_err_t               err   = FSP_SUCCESS;
    spi_cfg_t const * const p_cfg = p_ctrl->p_cfg;

    if (NULL != p_cfg->p_transfer_rx)
    {
        /* Set the initial configuration for the rx transfer instance. */
        transfer_instance_t const * p_transfer = p_cfg->p_transfer_rx;
        p_transfer->p_cfg->p_info->transfer_settings_u.transfer_settings_word = SCI_B_SPI_PRV_DMA_RX_TRANSFER_SETTINGS;
        p_transfer->p_cfg->p_info->p_src = (void *) &p_ctrl->p_reg->RDR;

        /* Open the transfer instance. */
        err = p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    if (NULL != p_cfg->p_transfer_tx)
    {
        /* Set the initial configuration for the tx transfer instance. */
        transfer_instance_t const * p_transfer = p_cfg->p_transfer_tx;
        p_transfer->p_cfg->p_info->transfer_settings_u.transfer_settings_word = SCI_B_SPI_PRV_DMA_TX_TRANSFER_SETTINGS;
        p_transfer->p_cfg->p_info->p_dest = (void *) &p_ctrl->p_reg->TDR;

        /* Open the transfer instance. */
        err = p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
        if (FSP_SUCCESS != err)
        {
            if (NULL != p_cfg->p_transfer_rx)
            {
                /* If the tx transfer instance could not be opened, close the rx transfer instance. */
                p_cfg->p_transfer_rx->p_api->close(p_cfg->p_transfer_rx->p_ctrl);
            }

            return err;
        }
    }

    return err;
}

#endif

/*******************************************************************************************************************//**
 * Initiates write or read process. Common routine used by SPI API write or read functions.
 *
 * @param[in]  p_ctrl             Pointer to the control block.
 * @param[in]  p_src              Pointer to data buffer which need to be sent.
 * @param[out] p_dest             Pointer to buffer where received data will be stored.
 * @param[in]  length             Number of data transactions to be performed.
 *
 * @retval     FSP_SUCCESS        Operation successfully completed.
 * @retval     FSP_ERR_NOT_OPEN   The channel has not been opened. Open the channel first.
 * @retval     FSP_ERR_ASSERTION  One of the following invalid parameters passed:
 *                                  - Pointer p_ctrl is NULL
 *                                  - length == 0
 *                                  - Transfer length is larger than supported by the transfer instances.
 * @retval     FSP_ERR_IN_USE     A transfer is already in progress.
 *
 * @return     See @ref RENESAS_ERROR_CODES or functions called by this function for other possible return codes. This
 *             function calls:
 *               - @ref transfer_api_t::reconfigure
 *               - @ref transfer_api_t::infoGet
 **********************************************************************************************************************/
static fsp_err_t r_sci_b_spi_write_read_common (sci_b_spi_instance_ctrl_t * const p_ctrl,
                                                void const                      * p_src,
                                                void                            * p_dest,
                                                uint32_t const                    length)
{
#if SCI_B_SPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(SCI_B_SPI_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(0 != length);
 #if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE
    transfer_instance_t const * p_transfer_rx = p_ctrl->p_cfg->p_transfer_rx;
    if (NULL != p_transfer_rx)
    {
        transfer_properties_t transfer_info;
        fsp_err_t             err = p_transfer_rx->p_api->infoGet(p_transfer_rx->p_ctrl, &transfer_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        FSP_ASSERT(length <= transfer_info.transfer_length_max);
    }

    transfer_instance_t const * p_transfer_tx = p_ctrl->p_cfg->p_transfer_tx;
    if (NULL != p_transfer_tx)
    {
        transfer_properties_t transfer_info;
        fsp_err_t             err = p_transfer_tx->p_api->infoGet(p_transfer_tx->p_ctrl, &transfer_info);

        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        FSP_ASSERT(length <= transfer_info.transfer_length_max);
    }
 #endif
#endif

    /* TE and RE must be zero in order to write one to TE or RE (TE and RE will only be set if there is a transfer in
     * progress. Reference section Serial Control Register (SCR0) of the relevant hardware manual. */
    FSP_ERROR_RETURN(0 == (p_ctrl->p_reg->SCR0 & (R_SCI_B0_SCR0_RE_Msk | R_SCI_B0_SCR0_TE_Msk)), FSP_ERR_IN_USE);

    /* Setup the control block. */
    p_ctrl->count    = length;
    p_ctrl->tx_count = 0U;
    p_ctrl->rx_count = 0U;
    p_ctrl->p_src    = (uint8_t *) p_src;
    p_ctrl->p_dest   = (uint8_t *) p_dest;

#if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE == 1
    if (p_ctrl->p_cfg->p_transfer_tx)
    {
        /* Configure the tx transfer instance. */
        p_ctrl->tx_count = length;
        transfer_instance_t const * p_transfer = p_ctrl->p_cfg->p_transfer_tx;
        p_transfer->p_cfg->p_info->length = (uint16_t) length;

        if (NULL == p_src)
        {
            /* If the source is NULL transmit using a dummy value using FIXED mode. */
            static uint8_t tx_dummy = 0;
            p_transfer->p_cfg->p_info->transfer_settings_u.transfer_settings_word_b.src_addr_mode =
                TRANSFER_ADDR_MODE_FIXED;
            p_transfer->p_cfg->p_info->p_src = &tx_dummy;
        }
        else
        {
            p_transfer->p_cfg->p_info->transfer_settings_u.transfer_settings_word_b.src_addr_mode =
                TRANSFER_ADDR_MODE_INCREMENTED;
            p_transfer->p_cfg->p_info->p_src = p_src;
        }

        /* Enable the transfer instance. */
        fsp_err_t err = p_transfer->p_api->reconfigure(p_transfer->p_ctrl, p_transfer->p_cfg->p_info);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    /* The rx transfer instance is not used if p_dest is NULL. */
    if ((NULL != p_ctrl->p_cfg->p_transfer_rx) && (NULL != p_dest))
    {
        /* Configure the rx transfer instance. */
        p_ctrl->rx_count = length;
        transfer_instance_t const * p_transfer = p_ctrl->p_cfg->p_transfer_rx;

        /* Enable the transfer instance. */
        fsp_err_t err = p_transfer->p_api->reset(p_transfer->p_ctrl, NULL, p_dest, (uint16_t) length);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
#endif

    /* Enable transmit and receive interrupts. */
    r_sci_b_spi_start_transfer(p_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enables and disables Receive and Transmit mode based on the current configuration.
 *
 * @param      p_ctrl          Pointer to control structure.
 **********************************************************************************************************************/
static void r_sci_b_spi_start_transfer (sci_b_spi_instance_ctrl_t * const p_ctrl)
{
    /* TE must always be enabled even when receiving data. When RE is enabled without also enabling TE, the SCI will
     * continue transferring data until the RE bit is cleared. At high bitrates, it is not possible to clear the RE bit
     * fast enough and there will be additional clock pulses at the end of the transfer. */
    uint32_t interrupt_settings = R_SCI_B0_SCR0_TE_Msk;

    if ((NULL == p_ctrl->p_dest)
#if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE == 1
        || (NULL != p_ctrl->p_cfg->p_transfer_tx) || (NULL != p_ctrl->p_cfg->p_transfer_rx)
#endif
        )
    {
        /* Enable the transmit IRQ. */
        interrupt_settings |= R_SCI_B0_SCR0_TIE_Msk;
    }

    if (NULL != p_ctrl->p_dest)
    {
        /* Enable Receive mode and the Receive buffer full IRQ. */
        interrupt_settings |= (R_SCI_B0_SCR0_RE_Msk | R_SCI_B0_SCR0_RIE_Msk);
    }

    /* Write the transfer settings. */
    p_ctrl->p_reg->SCR0 |= interrupt_settings;

    /* Transmit from RXI interrupt. */
    if ((NULL == p_ctrl->p_cfg->p_transfer_tx) && (NULL == p_ctrl->p_cfg->p_transfer_rx) && (NULL != p_ctrl->p_dest))
    {
        /* The rxi interrupt must be disabled so that r_sci_b_spi_transmit is not interrupted before it updates the
         * tx_count. */
        R_BSP_IrqDisable(p_ctrl->p_cfg->rxi_irq);

        /* When transmitting from the RXI interrupt, the first byte must be written here because the transmit buffer
         * empty IRQ is disabled. */
        r_sci_b_spi_transmit(p_ctrl);

        if ((SPI_MODE_SLAVE == p_ctrl->p_cfg->operating_mode) && (1 < p_ctrl->count))
        {
            /* First call writes directly to the TSR register. The second call writes to the TDR register. */
            r_sci_b_spi_transmit(p_ctrl);
        }

        /* In master mode the rxi interrupt will fire as soon as it is enabled. */
        R_BSP_IrqEnableNoClear(p_ctrl->p_cfg->rxi_irq);
    }
}

/*******************************************************************************************************************//**
 * Transmit a single byte of data.
 * @param      p_ctrl          Pointer to the control structure.
 **********************************************************************************************************************/
static void r_sci_b_spi_transmit (sci_b_spi_instance_ctrl_t * p_ctrl)
{
    if (p_ctrl->tx_count < p_ctrl->count)
    {
        if (p_ctrl->p_src)
        {
            p_ctrl->p_reg->TDR = (SCI_B_SPI_PRV_DATA_REG_MASK | (p_ctrl->p_src[p_ctrl->tx_count]));
        }
        else
        {
            /* Do a dummy write if there is no tx buffer. */
            p_ctrl->p_reg->TDR = (SCI_B_SPI_PRV_DATA_REG_MASK | 0U);
        }

        p_ctrl->tx_count++;
    }
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to SPI instance control block
 * @param[in]     event      Event code
 **********************************************************************************************************************/
static void r_sci_b_spi_call_callback (sci_b_spi_instance_ctrl_t * p_ctrl, spi_event_t event)
{
    spi_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    spi_callback_args_t * p_args = p_ctrl->p_callback_memory;
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

    p_args->channel   = p_ctrl->p_cfg->channel;
    p_args->event     = event;
    p_args->p_context = p_ctrl->p_context;

    p_ctrl->p_callback(p_args);

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

#if SCI_B_SPI_CFG_DMA_SUPPORT_ENABLE == 1

/*******************************************************************************************************************//**
 * Callback that must be called after a RX DMAC transfer completes.
 *
 * @param[in]     p_ctrl     Pointer to SPI instance control block
 **********************************************************************************************************************/
void sci_b_spi_rx_dmac_callback (sci_b_spi_instance_ctrl_t const * const p_ctrl)
{
    /* Enable the transmit end interrupt once all data has been received
     * and disable the transmit and reception interrupts. */
    uint32_t scr0_temp = p_ctrl->p_reg->SCR0;
    scr0_temp          |= R_SCI_B0_SCR0_TEIE_Msk;
    scr0_temp          &= (uint32_t) ~(R_SCI_B0_SCR0_TIE_Msk | R_SCI_B0_SCR0_RIE_Msk);
    p_ctrl->p_reg->SCR0 = scr0_temp;
}

/*******************************************************************************************************************//**
 * Callback that must be called after a TX DMAC transfer completes.
 *
 * @param[in]     p_ctrl     Pointer to SPI instance control block
 **********************************************************************************************************************/
void sci_b_spi_tx_dmac_callback (sci_b_spi_instance_ctrl_t const * const p_ctrl)
{
    if (NULL == p_ctrl->p_dest)
    {
        /* Clear Pending txi flag */
        R_BSP_IrqClearPending(p_ctrl->p_cfg->txi_irq);

        /* If the last byte is transmitted and there is no data to receive
         * then enable the transmit end interrupt and disable the transmit interrupt. */
        uint32_t scr0_temp = p_ctrl->p_reg->SCR0;
        scr0_temp          |= R_SCI_B0_SCR0_TEIE_Msk;
        scr0_temp          &= (uint32_t) ~(R_SCI_B0_SCR0_TIE_Msk);
        p_ctrl->p_reg->SCR0 = scr0_temp;
    }
}

#endif

/*******************************************************************************************************************//**
 * This function is the ISR handler for R_SCI_B_SPI Transmit Buffer Empty IRQ.
 *
 * The Transmit Buffer Empty IRQ is enabled in the following conditions:
 *   - The transfer is started using R_SCI_B_SPI_Write API (There is no data to receive).
 *   - The rxi IRQ is serviced using a DMA instance.
 *   - The txi IRQ is serviced using a DMA instance (The interrupt will fire on the last byte transferred).
 *
 **********************************************************************************************************************/
void sci_b_spi_txi_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE
    IRQn_Type irq = R_FSP_CurrentIrqGet();
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Write the next byte to the TDR register. */
    r_sci_b_spi_transmit(p_ctrl);

    if ((p_ctrl->tx_count == p_ctrl->count) && (NULL == p_ctrl->p_dest))
    {
        /* If the last byte is transmitted and there is no data to receive then enable the transmit end IRQ and disable
         * the transmit IRQ. */

        /* After all data has been transmitted, disable transmit interrupts and enable the transmit end interrupt. */
        uint32_t scr0_temp = p_ctrl->p_reg->SCR0;
        scr0_temp          |= R_SCI_B0_SCR0_TEIE_Msk;
        scr0_temp          &= (uint32_t) ~(R_SCI_B0_SCR0_TIE_Msk);
        p_ctrl->p_reg->SCR0 = scr0_temp;
    }

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * This function is the ISR handler for R_SCI_B_SPI Receive Buffer Full IRQ.
 * This handler also handles Transmit Buffer Empty IRQs.
 *
 * The Receive Buffer Full IRQ is enabled in the following conditions:
 *   - The transfer is started using either the R_SCI_B_SPI_Read or R_SCI_B_SPI_WriteRead API.
 *
 **********************************************************************************************************************/
void sci_b_spi_rxi_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Write the next byte to the TDR register
     * (Whenever the rxi isr is enabled, the transmit isr is disabled and transmit is handled here). */
    r_sci_b_spi_transmit(p_ctrl);

    /* Read the next byte from the RDR register. */
    if (p_ctrl->rx_count < p_ctrl->count)
    {
        p_ctrl->p_dest[p_ctrl->rx_count++] = (uint8_t) (p_ctrl->p_reg->RDR & SCI_B_SPI_PRV_RDAT_MASK);
    }

    if (p_ctrl->rx_count == p_ctrl->count)
    {
        /* If the last byte is received then enable the transmit end IRQ and disable the receive and transmit IRQs. */

        uint32_t scr0_temp = p_ctrl->p_reg->SCR0;
        scr0_temp          |= R_SCI_B0_SCR0_TEIE_Msk;
        scr0_temp          &= (uint32_t) ~(R_SCI_B0_SCR0_TIE_Msk | R_SCI_B0_SCR0_RIE_Msk);
        p_ctrl->p_reg->SCR0 = scr0_temp;
    }

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * This function is the ISR handler for R_SCI_SPI Transmit End IRQ.
 *
 * The Transmit End IRQ is enabled after the last byte of data has been transferred.
 *
 **********************************************************************************************************************/
void sci_b_spi_tei_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Disables receiver, transmitter and transmit end IRQ. */

    uint32_t scr0_temp = p_ctrl->p_reg->SCR0;
    scr0_temp &=
        (uint32_t) ~(R_SCI_B0_SCR0_TIE_Msk | R_SCI_B0_SCR0_TE_Msk | R_SCI_B0_SCR0_RE_Msk | R_SCI_B0_SCR0_TEIE_Msk);
    p_ctrl->p_reg->SCR0 = scr0_temp;

    /* Notify the user that the transfer has completed. */
    r_sci_b_spi_call_callback(p_ctrl, SPI_EVENT_TRANSFER_COMPLETE);

    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * This function is the ISR handler for  R_SCI_B_SPI Error IRQs.
 *
 * This handler is only enabled if the user passes in a valid IRQ number in Pointer to a configuration structure.
 * structure.
 **********************************************************************************************************************/
void sci_b_spi_eri_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    sci_b_spi_instance_ctrl_t * p_ctrl = (sci_b_spi_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Disables receiver, transmitter and transmit end IRQ. */
    p_ctrl->p_reg->SCR0 &= (uint32_t) ~(R_SCI_B0_SCR0_TIE_Msk | R_SCI_B0_SCR0_RIE_Msk | R_SCI_B0_SCR0_TEIE_Msk);

    /* Clear the error status flags (The only possible error is an RX overflow). */

    p_ctrl->p_reg->SSCR = R_SCI_B0_SSCR_ORERC_Msk;

    /* Notify the user that an error occurred. */
    r_sci_b_spi_call_callback(p_ctrl, SPI_EVENT_ERR_READ_OVERFLOW);

    /* Clear pending IRQ to make sure it doesn't fire again after exiting. */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE
}
