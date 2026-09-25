/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef GUICONF_H
#define GUICONF_H

#include "rm_emwin_rx_port_cfg.h"

#define GUI_NUM_LAYERS        (1)
#define GUI_SUPPORT_TOUCH     (0)
#define GUI_SUPPORT_MOUSE     (0)
#define GUI_SUPPORT_MEMDEV    (1)
#define GUI_WINSUPPORT        (1)
#define GUI_SUPPORT_BIDI      (1)
#define GUI_DEBUG_LEVEL       (2)

void APPW_X_FS_Init(void);

#endif
