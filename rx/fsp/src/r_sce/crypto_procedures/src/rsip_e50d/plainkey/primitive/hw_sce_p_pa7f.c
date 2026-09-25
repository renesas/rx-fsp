/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes192CcmEncryptFinalSub (const uint32_t InData_Text[],
                                           const uint32_t InData_TextLen[],
                                           uint32_t       OutData_Text[],
                                           uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00008c00U);
    WR1_PROG(REG_1600H, 0x0000000fU);

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1600H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0xc055f344U, 0x87532190U, 0x7dfb6607U, 0x877a9088U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_182CH, 0x40000010U);
        WR1_PROG(REG_1824H, 0xe7008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[0]);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1608H, 0x80840001U);
        WR1_PROG(REG_1400H, 0x03410011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00000821U);

        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1600H, 0x00000080U);

        WR1_PROG(REG_1600H, 0x0000b7e0U);
        WR1_PROG(REG_1600H, 0x00000080U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            WR1_PROG(REG_1600H, 0x3c002be0U);
            WR1_PROG(REG_1600H, 0x12003c3fU);
            WR1_PROG(REG_1600H, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0x76f44aedU, 0x167fb02bU, 0x79e8f855U, 0xffab93d0U);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1608H, 0x81840001U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[2]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[3]);

        HW_SCE_p_func101(0x6d156883U, 0x9bcb750eU, 0xdff26203U, 0x7f6983ffU);
    }
    else
    {
        HW_SCE_p_func101(0xee5ab717U, 0x5f50e7ddU, 0x42a2b28bU, 0xd9682c48U);
    }

    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    HW_SCE_p_func100(0x7fa0de56U, 0x87ca327aU, 0xd651b5e2U, 0xb4259b6fU);
    WR1_PROG(REG_182CH, 0x40000010U);
    WR1_PROG(REG_1824H, 0x09108105U);
    WR1_PROG(REG_1400H, 0x00410011U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_MAC[0]);

    HW_SCE_p_func102(0x8ac73450U, 0x35c505c4U, 0xb1e8596cU, 0x6520e589U);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
