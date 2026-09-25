/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes256EncryptDecryptFinalSub (void)
{
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        HW_SCE_p_func101(0x90aa9c52U, 0x9e079951U, 0x850019f7U, 0x7b0c7fa4U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        HW_SCE_p_func101(0x066652deU, 0xd756fd23U, 0x8f2a8c02U, 0xc3285265U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        HW_SCE_p_func101(0x3584aea2U, 0x072fb320U, 0x84a19774U, 0x639573d5U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        HW_SCE_p_func101(0x2a7b78ccU, 0xf9da49afU, 0xf1774e99U, 0x97e9986fU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        HW_SCE_p_func101(0x3dc61e9cU, 0xb7b3be30U, 0x90e54eddU, 0xa3c73cc5U);
    }

    HW_SCE_p_func102(0xef0fc5d4U, 0xd2ddeb3aU, 0xd95979cdU, 0x9dbc1b0fU);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
