/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_Aes192EncryptDecryptUpdateSub (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        HW_SCE_p_func100(0xd6b32c52U, 0x221ca506U, 0x509d2cfcU, 0xfe8e60a7U);

        WR1_PROG(REG_1444H, 0x00020061U);

        WR1_PROG(REG_182CH, 0x40000010U);
        WR1_PROG(REG_1824H, 0x0a008106U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        HW_SCE_p_func100(0x59679866U, 0x19d4f299U, 0x8ccacf25U, 0x7ea130d5U);

        WR1_PROG(REG_1444H, 0x00020061U);

        WR1_PROG(REG_182CH, 0x40000010U);
        WR1_PROG(REG_1824H, 0x0a00810eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        HW_SCE_p_func100(0xb39f9a3eU, 0x219e6569U, 0x4c093786U, 0x633b5b7cU);

        WR1_PROG(REG_1444H, 0x00020061U);

        WR1_PROG(REG_182CH, 0x40000010U);
        WR1_PROG(REG_1824H, 0x0e008506U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        HW_SCE_p_func100(0x06bd0fd7U, 0xc327a08bU, 0x8b09a04fU, 0xe770893eU);

        WR1_PROG(REG_1444H, 0x00020061U);

        WR1_PROG(REG_182CH, 0x40000010U);
        WR1_PROG(REG_1824H, 0x0900890eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        HW_SCE_p_func100(0x484e6264U, 0x0315cd3aU, 0x8409ae29U, 0x6a221d34U);

        WR1_PROG(REG_1444H, 0x00020061U);

        WR1_PROG(REG_182CH, 0x40000010U);
        WR1_PROG(REG_1824H, 0x07008d06U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 4]);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        HW_SCE_p_func214();

        HW_SCE_p_func101(0xeb1b7872U, 0x1904a0a8U, 0x7e10be11U, 0x4cc5d64bU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        HW_SCE_p_func214();

        HW_SCE_p_func101(0xc97275a8U, 0xdac23076U, 0x0ff70c90U, 0xa3aad11dU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        HW_SCE_p_func214();

        HW_SCE_p_func101(0x657f5a7dU, 0x79836c26U, 0xae3c0749U, 0x9b9721a8U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        HW_SCE_p_func214();

        HW_SCE_p_func101(0x463cf308U, 0xeecaada9U, 0x7088683dU, 0x3fee669bU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        HW_SCE_p_func214();

        HW_SCE_p_func101(0xa10cba61U, 0x193eb805U, 0x8f73e2b4U, 0xac0bc333U);
    }
}
