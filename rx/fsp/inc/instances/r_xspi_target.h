/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup XSPI_TARGET
 * @{
 **********************************************************************************************************************/

#ifndef R_XSPI_TARGET_TARGET_H
#define R_XSPI_TARGET_TARGET_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_xspi_target_cfg.h"
#include "r_spi_flash_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Format of data frames used for communicating with the target device. */
typedef enum e_xspi_target_frame_format
{
    XSPI_TARGET_FRAME_FORMAT_STANDARD                = 0x0, ///< Standard frame with command, address, and data phases.
    XSPI_TARGET_FRAME_FORMAT_XSPI_PROFILE_1          = 0x1, ///< JEDEC XSPI 8D-8D-8D Profile 1.0 frame.
    XSPI_TARGET_FRAME_FORMAT_XSPI_PROFILE_2          = 0x2, ///< JEDEC XSPI 8D-8D-8D Profile 2.0 frame.
    XSPI_TARGET_FRAME_FORMAT_XSPI_PROFILE_2_EXTENDED = 0x3, ///< JEDEC XSPI 8D-8D-8D Profile 2.0 extended 6-byte command-address frame, used with HyperRAM.
} xspi_target_frame_format_t;

typedef enum e_xspi_target_maximum_frame_size
{
    XSPI_TARGET_MAX_FRAME_SIZE_8   = 8U,   ///< Maximum supported frame size is 8 bytes.
    XSPI_TARGET_MAX_FRAME_SIZE_16  = 16U,  ///< Maximum supported frame size is 16 bytes.
    XSPI_TARGET_MAX_FRAME_SIZE_32  = 32U,  ///< Maximum supported frame size is 32 bytes.
    XSPI_TARGET_MAX_FRAME_SIZE_64  = 64U,  ///< Maximum supported frame size is 64 bytes.
    XSPI_TARGET_MAX_FRAME_SIZE_128 = 128U, ///< Maximum supported frame size is 128 bytes.
    XSPI_TARGET_MAX_FRAME_SIZE_256 = 256U, ///< Maximum supported frame size is 256 bytes.
    XSPI_TARGET_MAX_FRAME_SIZE_512 = 512U, ///< Maximum supported frame size is 512 bytes.
} xspi_target_maximum_frame_size_t;

/** Memory size of XSPI Target module */
typedef enum e_xspi_target_memory_size
{
    XSPI_TARGET_MEMORY_SIZE_4_KBYTES   = 0x0FFF,  ///< 4 KB memory size (address range 0x0000-0x0FFF).
    XSPI_TARGET_MEMORY_SIZE_8_KBYTES   = 0x1FFF,  ///< 8 KB memory size (address range 0x0000-0x1FFF).
    XSPI_TARGET_MEMORY_SIZE_16_KBYTES  = 0x3FFF,  ///< 16 KB memory size (address range 0x0000-0x3FFF).
    XSPI_TARGET_MEMORY_SIZE_32_KBYTES  = 0x7FFF,  ///< 32 KB memory size (address range 0x0000-0x7FFF).
    XSPI_TARGET_MEMORY_SIZE_64_KBYTES  = 0xFFFF,  ///< 64 KB memory size (address range 0x0000-0xFFFF).
    XSPI_TARGET_MEMORY_SIZE_128_KBYTES = 0x1FFFF, ///< 128 KB memory size (address range 0x0000-0x1FFFF).
    XSPI_TARGET_MEMORY_SIZE_256_KBYTES = 0x3FFFF, ///< 256 KB memory size (address range 0x0000-0x3FFFF).
    XSPI_TARGET_MEMORY_SIZE_512_KBYTES = 0x7FFFF, ///< 512 KB memory size (address range 0x0000-0x7FFFF).
    XSPI_TARGET_MEMORY_SIZE_1_MBYTE    = 0xFFFFF, ///< 1 MB memory size (address range 0x0000-0xFFFFF).
} xspi_target_memory_size_t;

/** Output enable delay settings. */
typedef enum e_xspi_target_output_assert_delay
{
    XSPI_TARGET_ASSERTION_DELAY_DISABLED = 0U, ///< Assertion delay disable
    XSPI_TARGET_ASSERTION_DELAY_ENABLED  = 1U, ///< Assertion delay enable
} xspi_target_output_assert_delay_t;

typedef enum e_xspi_target_write_data_mask_enable
{
    XSPI_TARGET_WRITE_DATA_MASK_DISABLE = 0U, ///< Disable write data mask
    XSPI_TARGET_WRITE_DATA_MASK_ENABLE  = 1U, ///< Enable write data mask
} xspi_target_write_data_mask_enable_t;

/** Fixed timing configuration for bus signals. */
typedef struct st_xspi_target_timing_setting
{
    xspi_target_output_assert_delay_t output_assert_delay; ///< Delays the assertion timing of IO[7:0] and DS signals by one cycle.
} xspi_target_timing_setting_t;

/** Command set used for a protocol mode. */
typedef struct st_xspi_target_command_set
{
    xspi_target_frame_format_t frame_format; ///< Frame format to use for this command set.

    uint8_t read_register_command;           ///< Read register command.
    uint8_t read_memory_command;             ///< Read memory command.
    uint8_t write_register_command;          ///< Write register command.
    uint8_t write_memory_command;            ///< Write memory command.

    uint8_t read_dummy_cycles;               ///< Dummy cycles to be inserted for read commands.
    uint8_t program_dummy_cycles;            ///< Dummy cycles to be inserted for page program commands.
} xspi_target_command_set_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref spi_flash_api_t::open is called */
typedef struct st_xspi_target_instance_ctrl
{
    spi_flash_cfg_t const * p_cfg;        ///< Pointer to initial configuration.
    uint32_t                open;         ///< Whether or not driver is open.
    spi_flash_protocol_t    spi_protocol; ///< Current XSPI protocol selected.
    R_XSPI_TARGET0_Type   * p_reg;        ///< Address for the XSPI peripheral associated with this channel.
} xspi_target_instance_ctrl_t;

/** XSPI_TARGET Extended configuration. */
typedef struct st_xspi_target_extended_cfg
{
    uint8_t unit;                                              ///< XSPI_TARGET instance number.
    xspi_target_timing_setting_t const * p_timing_settings;    ///< Fixed protocol timing settings.
    xspi_target_maximum_frame_size_t     max_read_frame_size;  // < Maximum data size in bytes for the Read frame when accessing memory.
    xspi_target_maximum_frame_size_t     max_write_frame_size; // < Maximum data size in bytes for the Write frame when accessing memory.
    xspi_target_memory_size_t            memory_size;          ///< Determine address space of XSPI Target module
    xspi_target_write_data_mask_enable_t write_data_mask;      ///< Mask signal for each byte in the write data;
    xspi_target_command_set_t const    * p_cmd_set;            ///< Command set for the active protocol mode.
} xspi_target_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const spi_flash_api_t g_xspi_target_on_spi_flash;

/** @endcond */

fsp_err_t R_XSPI_TARGET_Open(spi_flash_ctrl_t * const p_ctrl, spi_flash_cfg_t const * const p_cfg);
fsp_err_t R_XSPI_TARGET_Close(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_TARGET_DirectWrite(spi_flash_ctrl_t * const p_ctrl,
                                    uint8_t const * const    p_src,
                                    uint32_t const           bytes,
                                    bool const               read_after_write);
fsp_err_t R_XSPI_TARGET_DirectRead(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_XSPI_TARGET_DirectTransfer(spi_flash_ctrl_t * const            p_ctrl,
                                       spi_flash_direct_transfer_t * const p_transfer,
                                       spi_flash_direct_transfer_dir_t     direction);
fsp_err_t R_XSPI_TARGET_SpiProtocolSet(spi_flash_ctrl_t * const p_ctrl, spi_flash_protocol_t spi_protocol);
fsp_err_t R_XSPI_TARGET_XipEnter(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_TARGET_XipExit(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_TARGET_Write(spi_flash_ctrl_t * const p_ctrl,
                              uint8_t const * const    p_src,
                              uint8_t * const          p_dest,
                              uint32_t                 byte_count);
fsp_err_t R_XSPI_TARGET_Erase(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_device_address, uint32_t byte_count);
fsp_err_t R_XSPI_TARGET_StatusGet(spi_flash_ctrl_t * const p_ctrl, spi_flash_status_t * const p_status);
fsp_err_t R_XSPI_TARGET_BankSet(spi_flash_ctrl_t * const _ctrl, uint32_t bank);
fsp_err_t R_XSPI_TARGET_AutoCalibrate(spi_flash_ctrl_t * const p_ctrl);

fsp_err_t R_XSPI_TARGET_RowLoad(spi_flash_ctrl_t * const p_ctrl, uint32_t row_index);
fsp_err_t R_XSPI_TARGET_RowStore(spi_flash_ctrl_t * const p_ctrl, uint32_t row_index);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup XSPI_TARGET)
 **********************************************************************************************************************/
