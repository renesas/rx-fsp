/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes256OutputKeyForDotfSub (const uint32_t InData_KeyMode[],
                                            const uint32_t InData_Cmd[],
                                            const uint32_t InData_KeyIndex[],
                                            const uint32_t InData_Key[],
                                            const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002e0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xca876020U, 0xd4f650e1U, 0x39c82014U, 0x5cdfeec2U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800100e0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000002eU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xc76190a6U, 0x68d8ff00U, 0x5f77f98cU, 0x528e2688U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000007U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000002eU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x405d8ba7U, 0xf8318de3U, 0x3485257dU, 0x02be1a74U);
        HW_SCE_p_func044();

        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x80880001U);
        WR1_PROG(REG_1400H, 0x03420021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0xab0cc2b6U, 0xc79f8177U, 0xf1ca4f2eU, 0x700bee21U);
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1444H, 0x000007c7U);
        WR1_PROG(REG_1608H, 0x80880001U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[4]);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x903400d4U, 0x64de18bfU, 0x277c0b80U, 0xf02e3e6fU);
    }

    HW_SCE_p_func100(0x804fc6dbU, 0x126eb96dU, 0x8774b5ccU, 0x9718c83aU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xa3cfc63cU, 0x10a39a73U, 0xfc3f9b6eU, 0xc1699287U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x08000c00U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0xadbc5901U, 0xabc1f4e9U, 0x9f0c56a9U, 0xc16d8f88U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func100(0xcba3e49bU, 0x0fd63910U, 0x24b57ddaU, 0x6bc97b52U);
            WR1_PROG(REG_1438H, 0x40000100U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000002U);

            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1400H, 0x02090005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0xd9c0b0d8U, 0x9ae49921U, 0x588189e8U, 0x5fa7e6c2U);
            WR1_PROG(REG_1438H, 0x40000110U);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81880001U);
            WR1_PROG(REG_1400H, 0x02090021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0xe3bd76f6U, 0x59cdf7a6U, 0x1e9a1d5cU, 0x5a320e91U);
            WR1_PROG(REG_1438H, 0x40000140U);

            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1400H, 0x02090009U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func102(0x876ccc7eU, 0x831b6340U, 0x147abe99U, 0x61c7fc47U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
        else
        {
            HW_SCE_p_func100(0xb50256a8U, 0xbf82248cU, 0xb90d0f1aU, 0x4dffc279U);
            WR1_PROG(REG_1438H, 0x40000180U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000002U);

            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1400H, 0x02090005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0xb6a7a626U, 0xd081ca1aU, 0x98a0363bU, 0xe2008cffU);
            WR1_PROG(REG_1438H, 0x40000190U);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81880001U);
            WR1_PROG(REG_1400H, 0x02090021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x90080a58U, 0x575146f0U, 0xfb17829fU, 0x5202e317U);
            WR1_PROG(REG_1438H, 0x400001C0U);

            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1400H, 0x02090009U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func102(0xe6b00539U, 0x9f4fe862U, 0x85103060U, 0x59898033U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
