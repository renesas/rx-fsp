/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_ShaGenerateMessageDigestFinalSub (const uint32_t InData_Msg[],
                                                   uint32_t       OutData_MsgDigest[],
                                                   uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001600U);

    WAIT_STS(REG_2030H, 4, 1);

    HW_SCE_p_func100(0xca8f0f15U, 0x1029eb63U, 0xbd0a6e1aU, 0xac01ef3aU);
    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1600H, 0x1000b400U);
    WR1_PROG(REG_1600H, 0x00000001U);

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x1000b400U);
    WR1_PROG(REG_1600H, 0x00000002U);

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        HW_SCE_p_func100(0x2e9a3091U, 0x4e6dd125U, 0xf973b82cU, 0x91e0e8c4U);
        WR1_PROG(REG_1408H, 0x00004016U);
        WAIT_STS(REG_1408H, 30, 1);
        RD5_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0xfc1d23ebU, 0x5a7177afU, 0xcbf52fefU, 0x2e106968U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        HW_SCE_p_func100(0x4b5ac4feU, 0x2bad2820U, 0xceb3f754U, 0x608704e9U);
        WR1_PROG(REG_1408H, 0x0000401eU);
        WAIT_STS(REG_1408H, 30, 1);
        RD7_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0xd6875e96U, 0x20602b90U, 0x8567fdb4U, 0x8ace4bd6U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        HW_SCE_p_func100(0x90c66922U, 0x4e00551bU, 0x17089981U, 0x5c7e2061U);
        WR1_PROG(REG_1408H, 0x00004022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD8_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0x672e6ae7U, 0x8b41cbefU, 0xf76e6691U, 0x6f7f7352U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        HW_SCE_p_func100(0xc72de095U, 0xb882c524U, 0xd13ed147U, 0x38d3799aU);
        WR1_PROG(REG_1408H, 0x00004032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD12_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0x494785c4U, 0x79f2aa26U, 0xe73c34a2U, 0xb278251fU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
    {
        HW_SCE_p_func100(0x0d4d95ffU, 0x36318775U, 0xe7546890U, 0xd1e11d1fU);
        WR1_PROG(REG_1408H, 0x00004042U);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        HW_SCE_p_func102(0xe31cb449U, 0x185b1de2U, 0x606d48a5U, 0x02489071U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }

    return FSP_SUCCESS;
}
