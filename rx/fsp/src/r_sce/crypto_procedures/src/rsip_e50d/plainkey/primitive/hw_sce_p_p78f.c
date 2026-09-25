/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Sha3GenerateMessageDigestFinalSub (const uint32_t InData_Msg[],
                                                    uint32_t       OutData_MsgDigest[],
                                                    uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2440H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020065U);

    for (iLoop = 0U; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop = iLoop + S_RAM[0])
    {
        WAIT_STS(REG_1444H, 31, 1);
        for (jLoop = 0U; jLoop < S_RAM[0]; jLoop = jLoop + 2)
        {
            WR2_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001400U);

    WAIT_STS(REG_2440H, 4, 1);

    HW_SCE_p_func100(0xe3e82fdcU, 0x4158ddd3U, 0xfce2af25U, 0xe0fc32c6U);
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        HW_SCE_p_func100(0x9798d43bU, 0xd40dd479U, 0x15af3d7cU, 0x248b61caU);
        WR1_PROG(REG_1408H, 0x0000601eU);
        WAIT_STS(REG_1408H, 30, 1);
        RD7_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0x14db7685U, 0x1f1bf9fbU, 0x0f916b5aU, 0x0a42c684U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        HW_SCE_p_func100(0xf856e3f4U, 0x5ba344f6U, 0x1a73fc0fU, 0x858e7fa5U);
        WR1_PROG(REG_1408H, 0x00006022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD8_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0x1b21d23bU, 0x2b933764U, 0xd6b90bddU, 0xece77267U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        HW_SCE_p_func100(0x7b998718U, 0x05098076U, 0xb21da36fU, 0x40c0aa11U);
        WR1_PROG(REG_1408H, 0x00006032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD12_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0xd3a65528U, 0x6b0cf78aU, 0x1595f2e8U, 0xaab91216U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        HW_SCE_p_func100(0x73564dc8U, 0x35637905U, 0xee81145fU, 0x03fa2695U);
        WR1_PROG(REG_1408H, 0x00006042U);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0xda84663bU, 0x2da7ba75U, 0x7eade896U, 0x3223c5b8U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }

    return FSP_SUCCESS;
}
