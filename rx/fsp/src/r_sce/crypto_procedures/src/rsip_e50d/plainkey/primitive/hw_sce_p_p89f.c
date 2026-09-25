/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes192EncryptDecryptFinalSub (void)
{
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        HW_SCE_p_func101(0x8734a0e2U, 0x469fa49bU, 0x007c8948U, 0x989d20c1U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        HW_SCE_p_func101(0x07709bc1U, 0x5ccd3bdbU, 0xe2f2aa0fU, 0x060277b0U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        HW_SCE_p_func101(0xf53fbe9aU, 0xb6755779U, 0x40ba706fU, 0xe2321716U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        HW_SCE_p_func101(0x48961a02U, 0xef621427U, 0xee76efb1U, 0x306be095U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        HW_SCE_p_func101(0x8f5f200bU, 0xf320cb2fU, 0x998c3b43U, 0x3524c05cU);
    }

    HW_SCE_p_func102(0x44e467fcU, 0xf20ec304U, 0x57b4fac9U, 0xac8aa9a9U);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
