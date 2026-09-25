/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes128OutputKeyForDotfSub (const uint32_t InData_KeyMode[],
                                            const uint32_t InData_Cmd[],
                                            const uint32_t InData_KeyIndex[],
                                            const uint32_t InData_Key[],
                                            const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002c0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xc333db79U, 0x0ad461eeU, 0xc2f9ff06U, 0x1e63b35dU);
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
        WR1_PROG(REG_1420H, change_endian_long(0x0000002cU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x8f493ad1U, 0x4697fc83U, 0x70c919ceU, 0x7b263120U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000005U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000002cU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x59243e66U, 0x5710d421U, 0xf78336fdU, 0xb2a3bf89U);
        HW_SCE_p_func044();

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xf7009d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x80840001U);
        WR1_PROG(REG_1400H, 0x03420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0xc38d5d6fU, 0xa9391522U, 0x18a60d8aU, 0x1a04e2c7U);
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80840001U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xd922cb65U, 0x01b4032dU, 0xefcd26b9U, 0xa822a5b3U);
    }

    HW_SCE_p_func100(0x15b7aaa1U, 0xdb3495e7U, 0x970a3ff4U, 0xe086e204U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xb6b40319U, 0x4235c92aU, 0x0abeed3aU, 0x29a4a497U);
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

        WR1_PROG(REG_1600H, 0x38000c00U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x0dac0196U, 0xd297c60eU, 0x1c675b3eU, 0x3bd07abfU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func100(0xda16d61dU, 0xc850c968U, 0x663f7757U, 0x23f33e23U);
            WR1_PROG(REG_1438H, 0x40000100U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000000U);

            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1400H, 0x02090005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0xd0ecedf6U, 0xea4aa3b8U, 0xcaf7410fU, 0x04013c85U);
            WR1_PROG(REG_1438H, 0x40000110U);

            WR1_PROG(REG_1400H, 0x02000011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0x97acf6fcU, 0xb6609b4eU, 0x7e867bbeU, 0x6f53c617U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1400H, 0x02090011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0xd70573ffU, 0x991322e0U, 0x0d610338U, 0x32646f96U);
            WR1_PROG(REG_1438H, 0x40000140U);

            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1400H, 0x02090009U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func102(0x6ee86f9dU, 0xd02aa5a8U, 0xe7507fceU, 0x9caad25bU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
        else
        {
            HW_SCE_p_func100(0x18ca5815U, 0xa33fbf07U, 0xa6634c26U, 0xe036c285U);
            WR1_PROG(REG_1438H, 0x40000180U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000000U);

            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1400H, 0x02090005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0x7efc956dU, 0x7debf423U, 0xae39000cU, 0xa598981eU);
            WR1_PROG(REG_1438H, 0x40000190U);

            WR1_PROG(REG_1400H, 0x02000011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0xf036d8c0U, 0x55355e5fU, 0x3f3a5deeU, 0xcef198f5U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1400H, 0x02090011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x89309a01U, 0x420bc492U, 0x232b6e69U, 0x439d5a08U);
            WR1_PROG(REG_1438H, 0x400001C0U);

            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1400H, 0x02090009U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func102(0x8cc90fdbU, 0xcc9d09c5U, 0xf20e4cecU, 0xc722ab73U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
