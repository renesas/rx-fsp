/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <string.h>

#include "GUI.h"
#include "GUIDRV_FlexColor.h"
#include "LCDConf.h"
#include "rm_emwin_rx_port.h"
#include "rm_emwin_rx_port_private.h"

extern rm_emwin_rx_port_cfg_t g_rm_emwin_rx_port_cfg;

typedef void (* rm_emwin_rx_port_flexcolor_func_t)(GUI_DEVICE * p_device);

static rm_emwin_rx_port_instance_ctrl_t * gp_rm_emwin_rx_port_ctrl;

static uint32_t rm_emwin_rx_port_rotation_get(rm_emwin_rx_port_orientation_t orientation);
static uint32_t rm_emwin_rx_port_base_orientation_get(
    rm_emwin_rx_port_lcd_driver_t lcd_driver);
static int                               rm_emwin_rx_port_first_com_get(rm_emwin_rx_port_cfg_t const * p_cfg);
static int                               rm_emwin_rx_port_first_seg_get(rm_emwin_rx_port_cfg_t const * p_cfg);
static uint8_t                           rm_emwin_rx_port_colmod_get(rm_emwin_rx_port_cfg_t const * p_cfg);
static LCD_API_COLOR_CONV const        * rm_emwin_rx_port_color_conversion_get(rm_emwin_rx_port_cfg_t const * p_cfg);
static rm_emwin_rx_port_flexcolor_func_t rm_emwin_rx_port_controller_mode_get(rm_emwin_rx_port_cfg_t const * p_cfg);

static void write8_a0 (U8 data)
{
    uint8_t tx = data;
    (void) RM_EMWIN_RX_PORT_Write(gp_rm_emwin_rx_port_ctrl, &tx, 1U, true);
}

static void write8_a1 (U8 data)
{
    uint8_t tx = data;
    (void) RM_EMWIN_RX_PORT_Write(gp_rm_emwin_rx_port_ctrl, &tx, 1U, false);
}

static void writem8_a0 (U8 * p_data, int num_items)
{
    (void) RM_EMWIN_RX_PORT_Write(gp_rm_emwin_rx_port_ctrl, p_data, (uint32_t) num_items, true);
}

static void writem8_a1 (U8 * p_data, int num_items)
{
    (void) RM_EMWIN_RX_PORT_Write(gp_rm_emwin_rx_port_ctrl, p_data, (uint32_t) num_items, false);
}

static U8 read8_dummy (void)
{
    return 0U;
}

static void readm8_dummy (U8 * p_data, int num_items)
{
    memset(p_data, 0, (size_t) num_items);
}

static fsp_err_t rm_emwin_rx_port_init_controller (void)
{
    rm_emwin_rx_port_cfg_t const           * p_cfg  = &g_rm_emwin_rx_port_cfg;
    rm_emwin_rx_port_instance_ctrl_t * const p_ctrl = p_cfg->p_ctrl;
    uint8_t   command;
    uint8_t   data;
    fsp_err_t err = RM_EMWIN_RX_PORT_Open(p_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    if (p_cfg->use_chip_select_pin)
    {
        err = RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->chip_select_pin, BSP_IO_LEVEL_HIGH);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    if (p_cfg->use_display_pin)
    {
        err = RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->display_pin, BSP_IO_LEVEL_HIGH);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    if (p_cfg->use_backlight_pin)
    {
        err = RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->backlight_pin, BSP_IO_LEVEL_LOW);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    if (p_cfg->use_reset_pin)
    {
        err = RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->reset_pin, BSP_IO_LEVEL_LOW);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        GUI_X_Delay(RM_EMWIN_RX_PORT_RESET_ASSERT_DELAY_MS);
        err = RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->reset_pin, BSP_IO_LEVEL_HIGH);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
        GUI_X_Delay(RM_EMWIN_RX_PORT_RESET_RECOVERY_DELAY_MS);
    }

    command = RM_EMWIN_RX_PORT_SWRESET;
    err     = RM_EMWIN_RX_PORT_Write(p_ctrl, &command, 1U, true);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    GUI_X_Delay(RM_EMWIN_RX_PORT_SWRESET_RECOVERY_DELAY_MS);

    command = RM_EMWIN_RX_PORT_SLPOUT;
    err     = RM_EMWIN_RX_PORT_Write(p_ctrl, &command, 1U, true);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    GUI_X_Delay(RM_EMWIN_RX_PORT_SLPOUT_RECOVERY_DELAY_MS);

    command = RM_EMWIN_RX_PORT_COLMOD;
    data    = rm_emwin_rx_port_colmod_get(p_cfg);
    err     = RM_EMWIN_RX_PORT_Write(p_ctrl, &command, 1U, true);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    err = RM_EMWIN_RX_PORT_Write(p_ctrl, &data, 1U, false);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    GUI_X_Delay(RM_EMWIN_RX_PORT_COLMOD_RECOVERY_DELAY_MS);

    command = RM_EMWIN_RX_PORT_NORON;
    err     = RM_EMWIN_RX_PORT_Write(p_ctrl, &command, 1U, true);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    GUI_X_Delay(RM_EMWIN_RX_PORT_NORON_RECOVERY_DELAY_MS);

    command = RM_EMWIN_RX_PORT_DISPON;
    err     = RM_EMWIN_RX_PORT_Write(p_ctrl, &command, 1U, true);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    GUI_X_Delay(RM_EMWIN_RX_PORT_DISPON_RECOVERY_DELAY_MS);

    return FSP_SUCCESS;
}

void LCD_X_Config (void)
{
    rm_emwin_rx_port_cfg_t const * p_cfg = &g_rm_emwin_rx_port_cfg;
    gp_rm_emwin_rx_port_ctrl = p_cfg->p_ctrl;
    GUI_DEVICE     * p_device;
    GUI_PORT_API     port_api            = {0};
    CONFIG_FLEXCOLOR config              = {0};
    uint32_t         rotation            = rm_emwin_rx_port_rotation_get(p_cfg->orientation);
    uint32_t         display_orientation = rm_emwin_rx_port_base_orientation_get(p_cfg->lcd_driver);
    int              first_com           = rm_emwin_rx_port_first_com_get(p_cfg);
    int              first_seg           = rm_emwin_rx_port_first_seg_get(p_cfg);

    display_orientation ^= rotation;

    p_device = GUI_DEVICE_CreateAndLink(GUIDRV_FLEXCOLOR, rm_emwin_rx_port_color_conversion_get(p_cfg), 0, 0);

    if (rotation & RM_EMWIN_RX_PORT_SWAP_XY)
    {
        LCD_SetSizeEx(0, (int) p_cfg->y_size, (int) p_cfg->x_size);
        LCD_SetVSizeEx(0, (int) p_cfg->y_size, (int) p_cfg->x_size);
    }
    else
    {
        LCD_SetSizeEx(0, (int) p_cfg->x_size, (int) p_cfg->y_size);
        LCD_SetVSizeEx(0, (int) p_cfg->x_size, (int) p_cfg->y_size);
    }

    port_api.pfWrite8_A0  = write8_a0;
    port_api.pfWrite8_A1  = write8_a1;
    port_api.pfWriteM8_A0 = writem8_a0;
    port_api.pfWriteM8_A1 = writem8_a1;
    port_api.pfRead8_A0   = read8_dummy;
    port_api.pfRead8_A1   = read8_dummy;
    port_api.pfReadM8_A0  = readm8_dummy;
    port_api.pfReadM8_A1  = readm8_dummy;

    GUIDRV_FlexColor_SetFunc(p_device, &port_api, GUIDRV_FLEXCOLOR_F66709, rm_emwin_rx_port_controller_mode_get(p_cfg));

    if (rotation & RM_EMWIN_RX_PORT_SWAP_XY)
    {
        int temp = first_com;
        first_com = first_seg;
        first_seg = temp;
    }

    config.Orientation   = (int) display_orientation;
    config.FirstCOM      = first_com;
    config.FirstSEG      = first_seg;
    config.NumDummyReads = 0;
    GUIDRV_FlexColor_Config(p_device, &config);
}

int LCD_X_DisplayDriver (unsigned LayerIndex, unsigned Cmd, void * pData)
{
    FSP_PARAMETER_NOT_USED(LayerIndex);
    FSP_PARAMETER_NOT_USED(pData);

    switch (Cmd)
    {
        case LCD_X_INITCONTROLLER:
        {
            fsp_err_t err = rm_emwin_rx_port_init_controller();

            return (FSP_SUCCESS == err) ? 0 : -1;
        }

        case LCD_X_ON:
        {
            rm_emwin_rx_port_cfg_t const           * p_cfg  = &g_rm_emwin_rx_port_cfg;
            rm_emwin_rx_port_instance_ctrl_t * const p_ctrl = p_cfg->p_ctrl;
            if (p_cfg->use_backlight_pin)
            {
                if (FSP_SUCCESS != RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->backlight_pin, BSP_IO_LEVEL_HIGH))
                {
                    return -1;
                }
            }

            break;
        }

        case LCD_X_OFF:
        {
            rm_emwin_rx_port_cfg_t const           * p_cfg  = &g_rm_emwin_rx_port_cfg;
            rm_emwin_rx_port_instance_ctrl_t * const p_ctrl = p_cfg->p_ctrl;
            if (p_cfg->use_backlight_pin)
            {
                if (FSP_SUCCESS != RM_EMWIN_RX_PORT_PinWrite(p_ctrl, p_cfg->backlight_pin, BSP_IO_LEVEL_LOW))
                {
                    return -1;
                }
            }

            break;
        }

        default:
        {
            break;
        }
    }

    return 0;
}

static uint32_t rm_emwin_rx_port_rotation_get (rm_emwin_rx_port_orientation_t orientation)
{
    uint32_t rotation;

    switch (orientation)
    {
        case RM_EMWIN_RX_PORT_ORIENTATION_CW:
        {
            rotation = RM_EMWIN_RX_PORT_MIRROR_X | RM_EMWIN_RX_PORT_SWAP_XY;
            break;
        }

        case RM_EMWIN_RX_PORT_ORIENTATION_180:
        {
            rotation = RM_EMWIN_RX_PORT_MIRROR_X | RM_EMWIN_RX_PORT_MIRROR_Y;
            break;
        }

        case RM_EMWIN_RX_PORT_ORIENTATION_CCW:
        {
            rotation = RM_EMWIN_RX_PORT_MIRROR_Y | RM_EMWIN_RX_PORT_SWAP_XY;
            break;
        }

        case RM_EMWIN_RX_PORT_ORIENTATION_0:
        default:
        {
            rotation = 0U;
            break;
        }
    }

    return rotation;
}

static uint32_t rm_emwin_rx_port_base_orientation_get (rm_emwin_rx_port_lcd_driver_t lcd_driver)
{
    uint32_t base_orientation = 0U;

    if (RM_EMWIN_RX_PORT_LCD_DRIVER_ILI9341 == lcd_driver)
    {
        base_orientation = RM_EMWIN_RX_PORT_MIRROR_X;
    }

    return base_orientation;
}

static int rm_emwin_rx_port_first_com_get (rm_emwin_rx_port_cfg_t const * p_cfg)
{
    int first_com = RM_EMWIN_RX_PORT_FIRST_COM_DEFAULT;

    if (RM_EMWIN_RX_PORT_LCD_DRIVER_ST7715 == p_cfg->lcd_driver)
    {
        first_com = RM_EMWIN_RX_PORT_FIRST_COM_ST7715;
        if ((RM_EMWIN_RX_PORT_ORIENTATION_180 == p_cfg->orientation) ||
            (RM_EMWIN_RX_PORT_ORIENTATION_CCW == p_cfg->orientation))
        {
            first_com = RM_EMWIN_RX_PORT_FIRST_COM_ST7715_180;
        }
    }

    return first_com;
}

static int rm_emwin_rx_port_first_seg_get (rm_emwin_rx_port_cfg_t const * p_cfg)
{
    int first_seg = RM_EMWIN_RX_PORT_FIRST_SEG_DEFAULT;

    if (RM_EMWIN_RX_PORT_LCD_DRIVER_ST7715 == p_cfg->lcd_driver)
    {
        first_seg = RM_EMWIN_RX_PORT_FIRST_SEG_ST7715;
    }

    return first_seg;
}

static uint8_t rm_emwin_rx_port_colmod_get (rm_emwin_rx_port_cfg_t const * p_cfg)
{
    uint8_t colmod = RM_EMWIN_RX_PORT_COLMOD_RGB565;

    if (RM_EMWIN_RX_PORT_BITS_PER_PIXEL_24 == p_cfg->bits_per_pixel)
    {
        colmod = RM_EMWIN_RX_PORT_COLMOD_RGB888;
    }

    return colmod;
}

static LCD_API_COLOR_CONV const * rm_emwin_rx_port_color_conversion_get (rm_emwin_rx_port_cfg_t const * p_cfg)
{
    LCD_API_COLOR_CONV const * p_color_conversion = GUICC_565;

    if (RM_EMWIN_RX_PORT_BITS_PER_PIXEL_24 == p_cfg->bits_per_pixel)
    {
        p_color_conversion = GUICC_888;
    }

    return p_color_conversion;
}

static rm_emwin_rx_port_flexcolor_func_t rm_emwin_rx_port_controller_mode_get (rm_emwin_rx_port_cfg_t const * p_cfg)
{
    rm_emwin_rx_port_flexcolor_func_t p_controller_mode = GUIDRV_FLEXCOLOR_M16C0B8;

    if (RM_EMWIN_RX_PORT_BITS_PER_PIXEL_24 == p_cfg->bits_per_pixel)
    {
        p_controller_mode = GUIDRV_FLEXCOLOR_M24C0B8;
    }
    else if (p_cfg->use_write_cache)
    {
        p_controller_mode = GUIDRV_FLEXCOLOR_M16C1B8;
    }
    else
    {
        /* Use the default 16 bpp uncached controller mode. */
    }

    return p_controller_mode;
}
