/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_EMWIN_RX_PORT_H
#define RM_EMWIN_RX_PORT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_ioport_api.h"
#include "r_spi_api.h"
#include "rm_emwin_rx_port_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup RM_EMWIN_RX_PORT
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Serial LCD controller type. */
typedef enum e_rm_emwin_rx_port_lcd_driver
{
    RM_EMWIN_RX_PORT_LCD_DRIVER_ST7715 = 0, ///< ST7715 compatible controller.
    RM_EMWIN_RX_PORT_LCD_DRIVER_ILI9341,    ///< ILI9341 compatible controller.
} rm_emwin_rx_port_lcd_driver_t;

/** Serial LCD orientation. */
typedef enum e_rm_emwin_rx_port_orientation
{
    RM_EMWIN_RX_PORT_ORIENTATION_0 = 0, ///< 0 degrees.
    RM_EMWIN_RX_PORT_ORIENTATION_CW,    ///< 90 degrees clockwise.
    RM_EMWIN_RX_PORT_ORIENTATION_180,   ///< 180 degrees.
    RM_EMWIN_RX_PORT_ORIENTATION_CCW,   ///< 90 degrees counter-clockwise.
} rm_emwin_rx_port_orientation_t;

/** Forward declaration of the configuration structure. */
typedef struct st_rm_emwin_rx_port_cfg rm_emwin_rx_port_cfg_t;

/** RX serial emWin port control block. */
typedef struct st_rm_emwin_rx_port_instance_ctrl
{
    uint32_t open;
    rm_emwin_rx_port_cfg_t const * p_cfg;
    volatile bool        transfer_pending;
    volatile spi_event_t transfer_event;
} rm_emwin_rx_port_instance_ctrl_t;

/** Extended configuration structure. */
struct st_rm_emwin_rx_port_cfg
{
    /** Pointer to the control block for this instance. */
    rm_emwin_rx_port_instance_ctrl_t * p_ctrl;

    /** Add an SPI instance. */
    spi_instance_t const * p_lower_lvl_spi;

    /** Add an I/O port instance. */
    ioport_instance_t const * p_ioport;

    void   * p_gui_heap;                ///< Pointer to the GUI heap memory assigned to emWin.
    uint32_t gui_heap_size;             ///< Size of the GUI heap memory in bytes.

    bsp_io_port_pin_t data_command_pin; ///< GPIO pin used as the serial LCD D/C signal.
    bsp_io_port_pin_t chip_select_pin;  ///< GPIO pin used as the serial LCD CS signal.
    bsp_io_port_pin_t display_pin;      ///< Optional GPIO pin used as the serial LCD DISP signal.
    bsp_io_port_pin_t backlight_pin;    ///< Optional GPIO pin used as the serial LCD backlight signal.
    bsp_io_port_pin_t reset_pin;        ///< Optional GPIO pin used as the serial LCD reset signal.

    uint32_t x_size;                    ///< Physical LCD horizontal pixel count.
    uint32_t y_size;                    ///< Physical LCD vertical pixel count.
    uint32_t bits_per_pixel;            ///< Serial LCD pixel format used by emWin FlexColor.

    rm_emwin_rx_port_lcd_driver_t  lcd_driver;
    rm_emwin_rx_port_orientation_t orientation;

    bool use_data_command_pin;         ///< Enable D/C GPIO control.
    bool use_chip_select_pin;          ///< Enable CS GPIO control.
    bool use_display_pin;              ///< Enable DISP GPIO control.
    bool use_backlight_pin;            ///< Enable backlight GPIO control.
    bool use_reset_pin;                ///< Enable reset GPIO control.
    bool use_write_cache;              ///< Select cached FlexColor mode during GUI initialization for 16 bpp output.
};

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t RM_EMWIN_RX_PORT_PinWrite(rm_emwin_rx_port_instance_ctrl_t * const p_ctrl,
                                    bsp_io_port_pin_t const                  pin,
                                    bsp_io_level_t const                     level);

fsp_err_t RM_EMWIN_RX_PORT_Open(rm_emwin_rx_port_instance_ctrl_t * const p_ctrl,
                                rm_emwin_rx_port_cfg_t const * const     p_cfg);

fsp_err_t RM_EMWIN_RX_PORT_Write(rm_emwin_rx_port_instance_ctrl_t * const p_ctrl,
                                 uint8_t const * const                    p_data,
                                 uint32_t const                           length,
                                 bool const                               command);

fsp_err_t RM_EMWIN_RX_PORT_Close(rm_emwin_rx_port_instance_ctrl_t * const p_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_EMWIN_RX_PORT)
 **********************************************************************************************************************/
