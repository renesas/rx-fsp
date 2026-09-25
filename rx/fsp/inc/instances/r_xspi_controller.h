/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup XSPI_CONTROLLER
 * @{
 **********************************************************************************************************************/

#ifndef R_XSPI_CONTROLLER_H
#define R_XSPI_CONTROLLER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_xspi_controller_cfg.h"
#include "r_spi_flash_api.h"

#if XSPI_CONTROLLER_CFG_DMAC_SUPPORT_ENABLE
 #include "r_transfer_api.h"
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifndef XSPI_CONTROLLER_MAX_WRITE_ENABLE_POLLING_LOOPS

/** Maximum number of status polling checks after enabling memory writes. */
 #define XSPI_CONTROLLER_MAX_WRITE_ENABLE_POLLING_LOOPS    (5)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** XSPI Flash chip select */
typedef enum e_xspi_controller_chip_select
{
    XSPI_CONTROLLER_DEVICE_NUMBER_0 = 0U, ///< Device connected to Chip-Select 0
    XSPI_CONTROLLER_DEVICE_NUMBER_1,      ///< Device connected to Chip-Select 1
} xspi_controller_device_number_t;

/* OSPI Memory device type select */
typedef enum e_xspi_controller_device_type
{
    XSPI_CONTROLLER_DEVICE_TYPE_FLASH = 0U, ///< Device Memory type OctaFlash
    XSPI_CONTROLLER_DEVICE_TYPE_RAM,        ///< Device Memory type OctaRAM
} xspi_controller_device_type_t;

/** XSPI flash number of command code bytes. */
typedef enum e_xspi_controller_command_bytes
{
    XSPI_CONTROLLER_COMMAND_BYTES_1 = 1U, ///< Command codes are 1 byte long.
    XSPI_CONTROLLER_COMMAND_BYTES_2 = 2U, ///< Command codes are 2 bytes long.
} xspi_controller_command_bytes_t;

/** XSPI frame to frame interval */
typedef enum e_xspi_controller_frame_interval_clocks
{
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_1 = 0U, ///< 1 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_2,      ///< 2 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_3,      ///< 3 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_4,      ///< 4 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_5,      ///< 5 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_6,      ///< 6 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_7,      ///< 7 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_8,      ///< 8 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_9,      ///< 9 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_10,     ///< 10 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_11,     ///< 11 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_12,     ///< 12 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_13,     ///< 13 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_14,     ///< 14 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_15,     ///< 15 interval clocks
    XSPI_CONTROLLER_COMMAND_INTERVAL_CLOCKS_16,     ///< 16 interval clocks
} xspi_controller_command_interval_clocks_t;

/** XSPI chip select de-assertion duration */
typedef enum e_xspi_controller_cs_pullup_clocks
{
    XSPI_CONTROLLER_COMMAND_CS_PULLUP_CLOCKS_NO_EXTENSION = 0U, ///< CS asserting No extension
    XSPI_CONTROLLER_COMMAND_CS_PULLUP_CLOCKS_1,                 ///< CS asserting Extend 1 cycle
} xspi_controller_command_cs_pullup_clocks_t;

/** XSPI chip select assertion duration */
typedef enum e_xspi_controller_cs_pulldown_clocks
{
    XSPI_CONTROLLER_COMMAND_CS_PULLDOWN_CLOCKS_NO_EXTENSION = 0U, ///< CS negating No extension
    XSPI_CONTROLLER_COMMAND_CS_PULLDOWN_CLOCKS_1,                 ///< CS negating Extend 1 cycle
} xspi_controller_command_cs_pulldown_clocks_t;

/** XSPI data strobe delay. */
typedef enum e_xspi_controller_ds_timing_delay
{
    XSPI_CONTROLLER_DS_TIMING_DELAY_NONE = 0U,  ///< Sample without delay.
    XSPI_CONTROLLER_DS_TIMING_DELAY_1    = 1U,  ///< Delay sampling by 1 clock cell.
    XSPI_CONTROLLER_DS_TIMING_DELAY_2    = 2U,  ///< Delay sampling by 2 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_3    = 3U,  ///< Delay sampling by 3 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_4    = 4U,  ///< Delay sampling by 4 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_5    = 5U,  ///< Delay sampling by 5 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_6    = 6U,  ///< Delay sampling by 6 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_7    = 7U,  ///< Delay sampling by 7 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_8    = 8U,  ///< Delay sampling by 8 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_9    = 9U,  ///< Delay sampling by 9 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_10   = 10U, ///< Delay sampling by 10 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_11   = 11U, ///< Delay sampling by 11 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_12   = 12U, ///< Delay sampling by 12 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_13   = 13U, ///< Delay sampling by 13 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_14   = 14U, ///< Delay sampling by 14 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_15   = 15U, ///< Delay sampling by 15 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_16   = 16U, ///< Delay sampling by 16 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_17   = 17U, ///< Delay sampling by 17 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_18   = 18U, ///< Delay sampling by 18 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_19   = 19U, ///< Delay sampling by 19 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_20   = 20U, ///< Delay sampling by 20 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_21   = 21U, ///< Delay sampling by 21 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_22   = 22U, ///< Delay sampling by 22 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_23   = 23U, ///< Delay sampling by 23 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_24   = 24U, ///< Delay sampling by 24 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_25   = 25U, ///< Delay sampling by 25 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_26   = 26U, ///< Delay sampling by 26 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_27   = 27U, ///< Delay sampling by 27 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_28   = 28U, ///< Delay sampling by 28 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_29   = 29U, ///< Delay sampling by 29 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_30   = 30U, ///< Delay sampling by 30 clock cells.
    XSPI_CONTROLLER_DS_TIMING_DELAY_31   = 31U, ///< Delay sampling by 31 clock cells.
} xspi_controller_ds_timing_delay_t;

/** XSPI SDR signal drive timing. */
typedef enum e_xspi_controller_sdr_drive_timing
{
    XSPI_CONTROLLER_SDR_DRIVE_TIMING_BEFORE_CK = 0U, ///< SDR is asserted 1/2 cycle before the rising-edge of CK.
    XSPI_CONTROLLER_SDR_DRIVE_TIMING_AT_CK     = 1U, ///< SDR is asserted at the rising-edge of CK.
} xspi_controller_sdr_drive_timing_t;

/** Clock edge useed to sample data in SDR mode. */
typedef enum e_xspi_controller_ck_edge
{
    XSPI_CONTROLLER_CK_EDGE_FALLING = 0U, ///< Falling-edge of CK signal.
    XSPI_CONTROLLER_CK_EDGE_RISING  = 1U, ///< Rising-edge of CK signal.
} xspi_controller_ck_edge_t;

/** SDR sampling window delay. */
typedef enum e_xspi_controller_sdr_sampling_delay
{
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_NONE = 0U, ///< No sampling delay.
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_1    = 1U, ///< Delay sampling by 1 cycle.
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_2    = 2U, ///< Delay sampling by 2 cycles.
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_3    = 3U, ///< Delay sampling by 3 cycles.
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_4    = 4U, ///< Delay sampling by 4 cycles.
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_5    = 5U, ///< Delay sampling by 5 cycles.
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_6    = 6U, ///< Delay sampling by 6 cycles.
    XSPI_CONTROLLER_SDR_SAMPLING_DELAY_7    = 7U, ///< Delay sampling by 7 cycles.
} xspi_controller_sdr_sampling_delay_t;

/** DDR sampling window extension. */
typedef enum e_xspi_controller_ddr_sampling_extension
{
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_NONE = 0U, ///< No sampling extension.
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_1    = 1U, ///< Sampling extended by 1 cycle.
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_2    = 2U, ///< Sampling extended by 2 cycles.
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_3    = 3U, ///< Sampling extended by 3 cycles.
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_4    = 4U, ///< Sampling extended by 4 cycles.
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_5    = 5U, ///< Sampling extended by 5 cycles.
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_6    = 6U, ///< Sampling extended by 6 cycles.
    XSPI_CONTROLLER_DDR_SAMPLING_EXTENSION_7    = 7U, ///< Sampling extended by 7 cycles.
} xspi_controller_ddr_sampling_extension_t;

/** Output enable delay settings. */
typedef enum e_xspi_controller_output_assert_delay
{
    XSPI_CONTROLLER_ASSERTION_DELAY_DISABLED = 0U, ///< Assertion delay disable
    XSPI_CONTROLLER_ASSERTION_DELAY_ENABLED  = 1U, ///< Assertion delay enable
} xspi_controller_output_assert_delay_t;

/** Format of data frames used for communicating with the target device. */
typedef enum e_xspi_controller_frame_format
{
    XSPI_CONTROLLER_FRAME_FORMAT_STANDARD                = 0x0, ///< Standard frame with command, address, and data phases.
    XSPI_CONTROLLER_FRAME_FORMAT_XSPI_PROFILE_1          = 0x1, ///< JEDEC XSPI 8D-8D-8D Profile 1.0 frame.
    XSPI_CONTROLLER_FRAME_FORMAT_XSPI_PROFILE_2          = 0x2, ///< JEDEC XSPI 8D-8D-8D Profile 2.0 frame.
    XSPI_CONTROLLER_FRAME_FORMAT_XSPI_PROFILE_2_EXTENDED = 0x3, ///< JEDEC XSPI 8D-8D-8D Profile 2.0 extended 6-byte command-address frame, used with HyperRAM.
} xspi_controller_frame_format_t;

/** Mode address setting. */
typedef enum e_xspi_controller_address_mode
{
    XSPI_CONTROLLER_ADDRESS_MODE_NORMAL = 0U, ///< Address is fixed to the number of address bytes for the command.
    XSPI_CONTROLLER_ADDRESS_MODE_ARRAY  = 1U, ///< The flash target signifies additional address bytes by asserting the DQS line during the address phase.
} xspi_controller_address_mode_t;

/** Variable or fixed latency selection for flash devices which can notify the host of requiring additional time. */
typedef enum e_xspi_controller_latency_mode
{
    XSPI_CONTROLLER_LATENCY_MODE_FIXED = 0U, ///< Latency is fixed to the number of dummy cycles for the command.
    XSPI_CONTROLLER_LATENCY_MODE_VARIABLE,   ///< The flash target signifies additional latency (2x dummy cycles) by asserting the DQS line during the address phase.
} xspi_controller_latency_mode_t;

/** Prefetch function settings */
typedef enum e_xspi_controller_prefetch_function
{
    XSPI_CONTROLLER_PREFETCH_FUNCTION_DISABLE = 0x00, ///< Prefetch function disable
    XSPI_CONTROLLER_PREFETCH_FUNCTION_ENABLE  = 0x01, ///< Prefetch function enable
} xspi_controller_prefetch_function_t;

/** Write data mask settings */
typedef enum e_xspi_controller_write_data_mask
{
    XSPI_CONTROLLER_WRITE_DATA_MASK_DISABLE = 0U, ///< Write data mask disable
    XSPI_CONTROLLER_WRITE_DATA_MASK_ENABLE,       ///< Write data mask enable
} xspi_controller_write_data_mask_t;

/** Combination function settings */
typedef enum e_xspi_controller_combination_function
{
    XSPI_CONTROLLER_COMBINATION_FUNCTION_DISABLE = 0x00,  ///< Combination function disable
    XSPI_CONTROLLER_COMBINATION_FUNCTION_4BYTE   = 0x01,  ///< Combine up to 4 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_8BYTE   = 0x03,  ///< Combine up to 8 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_12BYTE  = 0x05,  ///< Combine up to 12 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_16BYTE  = 0x07,  ///< Combine up to 16 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_20BYTE  = 0x09,  ///< Combine up to 20 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_24BYTE  = 0x0B,  ///< Combine up to 24 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_28BYTE  = 0x0D,  ///< Combine up to 28 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_32BYTE  = 0x0F,  ///< Combine up to 32 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_36BYTE  = 0x11,  ///< Combine up to 36 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_40BYTE  = 0x13,  ///< Combine up to 40 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_44BYTE  = 0x15,  ///< Combine up to 44 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_48BYTE  = 0x17,  ///< Combine up to 48 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_52BYTE  = 0x19,  ///< Combine up to 52 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_56BYTE  = 0x1B,  ///< Combine up to 56 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_60BYTE  = 0x1D,  ///< Combine up to 60 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_64BYTE  = 0x1F,  ///< Combine up to 64 bytes
    XSPI_CONTROLLER_COMBINATION_FUNCTION_2BYTE   = 0x1FF, ///< Combine up to 2 bytes
} xspi_controller_combination_function_t;

/** Simple array length table structure. */
typedef struct st_xspi_controller_table
{
    void  * p_table;                   ///< Pointer to the table array.
    uint8_t length;                    ///< Number of entries in the table.
} xspi_controller_table_t;

/** Fixed timing configuration for bus signals. */
typedef struct st_xspi_controller_timing_setting
{
    xspi_controller_command_interval_clocks_t    command_to_command_interval; ///< Interval between 2 consecutive commands
    xspi_controller_command_cs_pullup_clocks_t   cs_pullup_lag;               ///< Duration to de-assert CS line after the last command
    xspi_controller_command_cs_pulldown_clocks_t cs_pulldown_lead;            ///< Duration to assert CS line before the first command
    xspi_controller_sdr_drive_timing_t           sdr_drive_timing;            ///< Data signal timing relative to the rising-edge of the CK signal.
    xspi_controller_ck_edge_t                sdr_sampling_edge;               ///< Selects the clock edge to sample the data signal.
    xspi_controller_sdr_sampling_delay_t     sdr_sampling_delay;              ///< Number of cycles to delay before sampling the data signal.
    xspi_controller_ddr_sampling_extension_t ddr_sampling_extension;          ///< Number of cycles to extending the data sampling window in DDR mode.
    xspi_controller_output_assert_delay_t    output_assert_delay;             ///< Delays the assertion timing of IO[7:0] and DS signals by one cycle.
} xspi_controller_timing_setting_t;

/** Command set used for a protocol mode. */
typedef struct st_xspi_controller_command_set
{
    spi_flash_protocol_t              protocol;        ///< Protocol mode associated with this command set.
    xspi_controller_frame_format_t    frame_format;    ///< Frame format to use for this command set.
    xspi_controller_latency_mode_t    latency_mode;    ///< Configurable or variable latency, only valid for XSPI_CONTROLLER_FRAME_FORMAT_XSPI_PROFILE_2 and XSPI_CONTROLLER_FRAME_FORMAT_XSPI_PROFILE_2_EXTENDED.
    xspi_controller_address_mode_t    address_mode;    ///< Address mode to use for external device.
    xspi_controller_command_bytes_t   command_bytes;   ///< Number of command bytes for each command code.
    spi_flash_address_bytes_t         address_bytes;   ///< Number of bytes used during the address phase.
    xspi_controller_write_data_mask_t write_data_mask; ///< Mask signal for each byte in the write data.

    uint16_t read_command;                             ///< Read command.
    uint16_t program_command;                          ///< Memory program/write command.
    uint16_t write_enable_command;                     ///< Command to enable write or erase, set to 0x00 to ignore.
    uint16_t status_command;                           ///< Command to read the write status, set to 0x00 to ignore.
    uint16_t row_load_command;                         ///< Load a page into the device's internal buffer, set to 0x00 to ignore.
    uint16_t row_store_command;                        ///< Stores the device's internal buffer to the memory page, set to 0x00 to ignore.

    uint8_t read_dummy_cycles;                         ///< Dummy cycles to be inserted for read commands.
    uint8_t program_dummy_cycles;                      ///< Dummy cycles to be inserted for page program commands.
    uint8_t status_dummy_cycles;                       ///< Dummy cycles to be inserted for status read commands.
    uint8_t row_load_dummy_cycles;                     ///< Dummy cycles to be inserted for the page load command.
    uint8_t row_store_dummy_cycles;                    ///< Dummy cycles to be inserted for the page store command.

    uint8_t address_msb_mask;                          ///< Mask of bits to zero when using memory-mapped operations; only applies to the most-significant byte.

    bool     status_needs_address;                     ///< Indicates that reading the status register requires an address stage.
    uint32_t status_address;                           ///< Address to use for reading the status register with "busy" and "write-enable" flags.
    spi_flash_address_bytes_t status_address_bytes;    ///< Number of bytes used for status register addressing.

    xspi_controller_table_t const * p_erase_commands;  ///< List of all erase commands and associated sizes
} xspi_controller_command_set_t;

/** XSPI DOTF AES Key Lengths. */
typedef enum e_xspi_controller_dotf_aes_key_length_words
{
    XSPI_CONTROLLER_DOTF_AES_KEY_LENGTH_WORDS_128 = 16U,
    XSPI_CONTROLLER_DOTF_AES_KEY_LENGTH_WORDS_192 = 24U,
    XSPI_CONTROLLER_DOTF_AES_KEY_LENGTH_WORDS_256 = 32U
} xspi_controller_dotf_aes_key_length_words_t;

/** PSPI DOTF AES Type. */
typedef enum e_xspi_controller_dotf_aes_key_type
{
    XSPI_CONTROLLER_DOTF_AES_KEY_TYPE_128 = 0U,
    XSPI_CONTROLLER_DOTF_AES_KEY_TYPE_192 = 1U,
    XSPI_CONTROLLER_DOTF_AES_KEY_TYPE_256 = 2U
} xspi_controller_dotf_aes_key_type_t;

/** XSPI DOTF key Type. */
typedef enum e_xspi_controller_dotf_key_format
{
    XSPI_CONTROLLER_DOTF_KEY_FORMAT_PLAINTEXT = 0U,
    XSPI_CONTROLLER_DOTF_KEY_FORMAT_WRAPPED   = 1U,
} xspi_controller_dotf_key_format_t;

/** This structure is used to hold all the DOTF related configuration. */
typedef struct st_xspi_controller_dotf_cfg
{
    xspi_controller_dotf_aes_key_type_t key_type;
    xspi_controller_dotf_key_format_t   format;
    uint32_t * p_start_addr;
    uint32_t * p_end_addr;
    uint32_t * p_key;
    uint32_t * p_iv;
} xspi_controller_dotf_cfg_t;

/** XSPI_CONTROLLER Extended configuration. */
typedef struct st_xspi_controller_extended_cfg
{
    uint8_t xspi_controller_unit;                                     ///< The XSPI_CONTROLLER unit corresponding to the selected channel.
    xspi_controller_device_number_t          channel;                 ///< Device number to be used for memory device.
    xspi_controller_device_type_t            memory_type;             ///< Type of memory device.
    xspi_controller_timing_setting_t const * p_timing_settings;       ///< Fixed protocol timing settings.
    xspi_controller_table_t const          * p_xspi_command_set;      ///< Additional protocol command sets; if additional protocol commands set are not used set this to NULL.
    xspi_controller_ds_timing_delay_t        data_latch_delay_clocks; ///< Delay after assertion of the DS signal where data should be latched.
    uint8_t * p_autocalibration_preamble_pattern_addr;                ///< OctaFlash memory address holding the preamble pattern
#if XSPI_CONTROLLER_CFG_DMAC_SUPPORT_ENABLE
    transfer_instance_t const * p_lower_lvl_transfer;                 ///< DMA Transfer instance used for data transmission
#endif
#if XSPI_CONTROLLER_CFG_DOTF_SUPPORT_ENABLE
    xspi_controller_dotf_cfg_t * p_dotf_cfg;                          ///< DOTF Configuration
#endif
#if XSPI_CONTROLLER_CFG_ROW_ADDRESSING_SUPPORT_ENABLE
    spi_flash_address_bytes_t row_index_bytes;                        ///< Number of bytes used to index the memory rows.
#endif
} xspi_controller_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref spi_flash_api_t::open is called */
typedef struct st_xspi_controller_instance_ctrl
{
    spi_flash_cfg_t const         * p_cfg;           ///< Pointer to initial configuration.
    uint32_t                        open;            ///< Whether or not driver is open.
    spi_flash_protocol_t            spi_protocol;    ///< Current XSPI protocol selected.
    xspi_controller_device_number_t channel;         ///< Device number to be used for memory device.
    uint8_t xspi_controller_unit;                    ///< XSPI_CONTROLLER instance number.
    xspi_controller_command_set_t const * p_cmd_set; ///< Command set for the active protocol mode.
    R_XSPI0_Type * p_reg;                            ///< Address for the XSPI peripheral associated with this channel.
} xspi_controller_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const spi_flash_api_t g_xspi_controller_on_spi_flash;

/** @endcond */

fsp_err_t R_XSPI_CONTROLLER_Open(spi_flash_ctrl_t * const p_ctrl, spi_flash_cfg_t const * const p_cfg);
fsp_err_t R_XSPI_CONTROLLER_Close(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_CONTROLLER_DirectWrite(spi_flash_ctrl_t * const p_ctrl,
                                        uint8_t const * const    p_src,
                                        uint32_t const           bytes,
                                        bool const               read_after_write);
fsp_err_t R_XSPI_CONTROLLER_DirectRead(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_XSPI_CONTROLLER_DirectTransfer(spi_flash_ctrl_t * const            p_ctrl,
                                           spi_flash_direct_transfer_t * const p_transfer,
                                           spi_flash_direct_transfer_dir_t     direction);
fsp_err_t R_XSPI_CONTROLLER_SpiProtocolSet(spi_flash_ctrl_t * const p_ctrl, spi_flash_protocol_t spi_protocol);
fsp_err_t R_XSPI_CONTROLLER_XipEnter(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_CONTROLLER_XipExit(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_CONTROLLER_Write(spi_flash_ctrl_t * const p_ctrl,
                                  uint8_t const * const    p_src,
                                  uint8_t * const          p_dest,
                                  uint32_t                 byte_count);
fsp_err_t R_XSPI_CONTROLLER_Erase(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_device_address,
                                  uint32_t byte_count);
fsp_err_t R_XSPI_CONTROLLER_StatusGet(spi_flash_ctrl_t * const p_ctrl, spi_flash_status_t * const p_status);
fsp_err_t R_XSPI_CONTROLLER_BankSet(spi_flash_ctrl_t * const _ctrl, uint32_t bank);
fsp_err_t R_XSPI_CONTROLLER_AutoCalibrate(spi_flash_ctrl_t * const p_ctrl);

fsp_err_t R_XSPI_CONTROLLER_DOTF_Configure(spi_flash_ctrl_t * const           p_ctrl,
                                           xspi_controller_dotf_cfg_t * const p_dotf_cfg);

fsp_err_t R_XSPI_CONTROLLER_RowLoad(spi_flash_ctrl_t * const p_ctrl, uint32_t row_index);
fsp_err_t R_XSPI_CONTROLLER_RowStore(spi_flash_ctrl_t * const p_ctrl, uint32_t row_index);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup XSPI_CONTROLLER)
 **********************************************************************************************************************/
