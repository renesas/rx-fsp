/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"
#include "GUI.h"
#include "GUIConf.h"
#include "rm_emwin_rx_port.h"

#define RM_EMWIN_RX_PORT_GUI_AV_BLOCK_SIZE    (0x80) // NOLINT(readability-magic-numbers,modernize-macro-to-enum)

extern rm_emwin_rx_port_cfg_t g_rm_emwin_rx_port_cfg;

void GUI_X_Config (void)
{
    rm_emwin_rx_port_cfg_t const * p_cfg = &g_rm_emwin_rx_port_cfg;

    if ((NULL != p_cfg->p_gui_heap) && (0U != p_cfg->gui_heap_size))
    {
        GUI_ALLOC_AssignMemory(p_cfg->p_gui_heap, p_cfg->gui_heap_size);
    }

    GUI_ALLOC_SetAvBlockSize(RM_EMWIN_RX_PORT_GUI_AV_BLOCK_SIZE);
}

/* Unused weak definition for AppWizard-required function. */
BSP_WEAK_REFERENCE void APPW_X_FS_Init (void)
{
    /* Function not used. */
}
