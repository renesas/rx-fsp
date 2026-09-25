/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes256CcmDecryptFinalSub (const uint32_t InData_Text[],
                                           const uint32_t InData_TextLen[],
                                           const uint32_t InData_MAC[],
                                           const uint32_t InData_MACLength[],
                                           uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010140U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_MACLength[0]);
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

    HW_SCE_p_func100(0x45e65475U, 0xbab589b9U, 0xe47dccfdU, 0x0b8edde9U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x0bac4322U, 0x4416f5a2U, 0x3651c6d7U, 0x87ca76ceU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
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

        HW_SCE_p_func100(0x0b37a0e0U, 0x8708e9aaU, 0x2c4185c5U, 0xfc40d34dU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_182CH, 0x40000000U);
            WR1_PROG(REG_1824H, 0x07008d05U);
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

            HW_SCE_p_func100(0x632b69f4U, 0xf091d61aU, 0x3dea17eaU, 0xf1b32721U);
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

            WR1_PROG(REG_182CH, 0x40000000U);
            WR1_PROG(REG_1824H, 0x0e108405U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1400H, 0x00490011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0x157c6ae0U, 0x61bbe385U, 0x9f9d5f6dU, 0xb8994360U);
        }
        else
        {
            HW_SCE_p_func101(0x7994a73cU, 0x4c95782aU, 0x14e617adU, 0xcb8bef07U);
        }

        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x07208d05U);
        WR1_PROG(REG_1400H, 0x00410011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1608H, 0x80840001U);
        WR1_PROG(REG_1400H, 0x03410011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x0000a540U);
        WR1_PROG(REG_1600H, 0x00000080U);

        WR1_PROG(REG_1600H, 0x0000b7e0U);
        WR1_PROG(REG_1600H, 0x00000080U);

        WR1_PROG(REG_1600H, 0x00000821U);

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
        WR4_ADDR(REG_1420H, &InData_MAC[0]);

        WR1_PROG(REG_1824H, 0x9c100005U);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1608H, 0x81840001U);
        WR1_PROG(REG_1400H, 0x00490011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1824H, 0x00000000U);

        HW_SCE_p_func100(0x2d265095U, 0x45078e07U, 0xf14eb0ddU, 0x95dce5e1U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0xf1af66f1U, 0x8211c473U, 0x39e9336eU, 0x38fbe288U);

            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            HW_SCE_p_func102(0x1a475ea9U, 0x1d2b1557U, 0x44b42252U, 0x7872e572U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
