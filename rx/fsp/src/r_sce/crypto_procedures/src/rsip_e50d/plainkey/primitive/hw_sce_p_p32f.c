/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes128GcmDecryptFinalSub (const uint32_t InData_Text[],
                                           const uint32_t InData_TextLen[],
                                           const uint32_t InData_DataALen[],
                                           const uint32_t InData_DataT[],
                                           const uint32_t InData_DataTLen[],
                                           uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1600H, 0x000035c8U);

    WR1_PROG(REG_1444H, 0x000001c7U);
    WR1_PROG(REG_1608H, 0x80020100U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_TextLen[1]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x3420a9c0U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x9a729ef2U, 0x2782793cU, 0x4b78b140U, 0x2a96a269U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x0000b580U);
        WR1_PROG(REG_1600H, 0x0000007FU);
        WR1_PROG(REG_1600H, 0x0000b5a0U);
        WR1_PROG(REG_1600H, 0xFFFFFF00U);
        WR1_PROG(REG_1600H, 0x0c0029a9U);
        WR1_PROG(REG_1600H, 0x04a02988U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func101(0x5200494dU, 0xd362fc34U, 0x608e5fb5U, 0x8218d2bfU);
    }
    else
    {
        WR1_PROG(REG_1600H, 0x0000b580U);
        WR1_PROG(REG_1600H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b5a0U);
        WR1_PROG(REG_1600H, 0x00020800U);
        WR1_PROG(REG_1600H, 0x0c0029a9U);
        WR1_PROG(REG_1600H, 0x04a02988U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func101(0x8ab8eba2U, 0xf84cdfa2U, 0xea634c82U, 0x7539a3d2U);
    }

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010140U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_DataTLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38008940U);
    WR1_PROG(REG_1600H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    WR1_PROG(REG_1600H, 0x0000b7e0U);
    WR1_PROG(REG_1600H, 0x00000010U);
    WR1_PROG(REG_1600H, 0x34202beaU);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x2d884062U, 0xcb119df5U, 0x0350c5edU, 0xd62dd29fU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x746af783U, 0xfb6fdc7fU, 0x99c8bc20U, 0xbd49b8aaU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00003409U);
        WR1_PROG(REG_1600H, 0x00036800U);

        WR1_PROG(REG_1600H, 0x08008c00U);
        WR1_PROG(REG_1600H, 0x0000000fU);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        HW_SCE_p_func100(0xe9f1f0c8U, 0xf3f6c180U, 0x9438dd26U, 0xcc07bc1fU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func100(0x668be6e5U, 0x23f196c6U, 0x2da750a9U, 0xdb10b7e6U);

            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_182CH, 0x00018020U);
            WR1_PROG(REG_1824H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x80840001U);
            WR1_PROG(REG_1400H, 0x03410011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x00000bffU);
            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x3c002be0U);
                WR1_PROG(REG_1600H, 0x12003c3fU);
                WR1_PROG(REG_1600H, 0x00002fe0U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x00000821U);
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

            HW_SCE_p_func101(0xb8fc0126U, 0xc15832b7U, 0xb51a66c2U, 0xaa29848eU);
        }

        WR1_PROG(REG_1444H, 0x000001c1U);
        WR1_PROG(REG_182CH, 0x00018000U);
        WR1_PROG(REG_1824H, 0x0a008005U);
        WAIT_STS(REG_1444H, 31, 1);
        WR2_ADDR(REG_1420H, &InData_DataALen[0]);

        WR1_PROG(REG_1608H, 0x81020100U);
        WR1_PROG(REG_1400H, 0x00490009U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1608H, 0x81040080U);
        WR1_PROG(REG_1400H, 0x00490011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_182CH, 0x00400000U);
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x0c008104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_182CH, 0x00000020U);
        WR1_PROG(REG_1824H, 0x07008d05U);
        WR1_PROG(REG_1400H, 0x00410011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x80840001U);
        WR1_PROG(REG_1400H, 0x03410011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00000bffU);
        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            WR1_PROG(REG_1600H, 0x3c002beaU);
            WR1_PROG(REG_1600H, 0x12003c3fU);
            WR1_PROG(REG_1600H, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000055U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_DataT[0]);

        WR1_PROG(REG_1824H, 0x9c100005U);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x81840001U);
        WR1_PROG(REG_1400H, 0x00490011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1824H, 0x00000000U);

        HW_SCE_p_func100(0x85623473U, 0x93ed5666U, 0x044311a4U, 0x04eb387aU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x3eb42fe8U, 0x39755efeU, 0xadbbf527U, 0x9c3ec713U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_AUTHENTICATION;
        }
        else
        {
            HW_SCE_p_func102(0xbc6ed00cU, 0xba42f0dcU, 0xb3d4e614U, 0xda74ad15U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
