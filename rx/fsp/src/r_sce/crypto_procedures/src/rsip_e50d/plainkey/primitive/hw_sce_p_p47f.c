/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes128EncryptDecryptFinalSub (void)
{
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        HW_SCE_p_func101(0x4d71c916U, 0xa6629fdcU, 0x45307e10U, 0xbf24a6e6U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        HW_SCE_p_func101(0xcc90369cU, 0x724bd5e3U, 0x6dcfbe23U, 0x9f3f48bdU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        HW_SCE_p_func101(0x3630825eU, 0x3fe6e1e0U, 0xae642bb5U, 0x1dd9e331U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        HW_SCE_p_func101(0x0861dcf0U, 0x4072fe92U, 0xcfcfeeeeU, 0x3767a108U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        HW_SCE_p_func101(0x106e0258U, 0x82b7b8faU, 0x8ff12e62U, 0xd63aa870U);
    }

    HW_SCE_p_func102(0xd8399374U, 0x4ff8de4cU, 0x0e3bd382U, 0x7823aa87U);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
