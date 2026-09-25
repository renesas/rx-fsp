/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_EMWIN_RX_PORT_PRIVATE_H
#define RM_EMWIN_RX_PORT_PRIVATE_H

#include "GUI.h"
#include "GUIDRV_FlexColor.h"
#include "LCDConf.h"
#include "rm_emwin_rx_port.h"

#define RM_EMWIN_RX_PORT_MIRROR_X                     (1U)
#define RM_EMWIN_RX_PORT_MIRROR_Y                     (1U << 1U)
#define RM_EMWIN_RX_PORT_SWAP_XY                      (1U << 2U)
#define RM_EMWIN_RX_PORT_BITS_PER_PIXEL_16            (16U)
#define RM_EMWIN_RX_PORT_BITS_PER_PIXEL_24            (24U)
#define RM_EMWIN_RX_PORT_FIRST_COM_ST7715             (1)
#define RM_EMWIN_RX_PORT_FIRST_COM_ST7715_180         (3)
#define RM_EMWIN_RX_PORT_FIRST_SEG_ST7715             (2)
#define RM_EMWIN_RX_PORT_FIRST_COM_DEFAULT            (0)
#define RM_EMWIN_RX_PORT_FIRST_SEG_DEFAULT            (0)
#define RM_EMWIN_RX_PORT_SWRESET                      (0x01U)
#define RM_EMWIN_RX_PORT_SLPOUT                       (0x11U)
#define RM_EMWIN_RX_PORT_NORON                        (0x13U)
#define RM_EMWIN_RX_PORT_DISPON                       (0x29U)
#define RM_EMWIN_RX_PORT_COLMOD                       (0x3AU)
#define RM_EMWIN_RX_PORT_COLMOD_RGB565                (0x55U)
#define RM_EMWIN_RX_PORT_COLMOD_RGB888                (0x66U)
#define RM_EMWIN_RX_PORT_RESET_ASSERT_DELAY_MS        (20U)
#define RM_EMWIN_RX_PORT_RESET_RECOVERY_DELAY_MS      (120U)
#define RM_EMWIN_RX_PORT_SWRESET_RECOVERY_DELAY_MS    (120U)
#define RM_EMWIN_RX_PORT_SLPOUT_RECOVERY_DELAY_MS     (120U)
#define RM_EMWIN_RX_PORT_COLMOD_RECOVERY_DELAY_MS     (10U)
#define RM_EMWIN_RX_PORT_NORON_RECOVERY_DELAY_MS      (10U)
#define RM_EMWIN_RX_PORT_DISPON_RECOVERY_DELAY_MS     (120U)
#define RM_EMWIN_RX_PORT_WRITE_TIMEOUT_MS             (5000U)
#define RM_EMWIN_RX_PORT_TRANSFER_POLL_DELAY_US       (1U)
#define RM_EMWIN_RX_PORT_MICROSECONDS_PER_MS          (1000U)

void      rm_emwin_rx_port_spi_callback(spi_callback_args_t * p_args);
fsp_err_t rm_emwin_rx_port_transfer_wait(rm_emwin_rx_port_instance_ctrl_t * p_ctrl, uint32_t timeout_ms);

#endif
