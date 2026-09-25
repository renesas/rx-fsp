/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func314 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000379dU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1400H, 0x00030005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x03430005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x3800db40U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x72935cc4U, 0xab260bbcU, 0x2228da18U, 0xccd7391bU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x1818000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            WR1_PROG(REG_1400H, 0x00030005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x03430005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1404H, 0x1a380000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            WR1_PROG(REG_1400H, 0x00030005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x03430005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x0000135bU);
            WR1_PROG(REG_1600H, 0x3800db40U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            HW_SCE_p_func100(0xa2f7f8dcU, 0xcd0ef62eU, 0x3b6da9d9U, 0x6e4ca67aU);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1400H, 0x00030005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x03430005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                WR1_PROG(REG_1400H, 0x00030005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x03430005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1400H, 0x00c00009U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1400H, 0x00c00009U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1014H, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000428U);

                WR1_PROG(REG_1004H, 0x1919000cU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000a40U);
                WR1_PROG(REG_1020H, 0x00000a40U);

                WR1_PROG(REG_1004H, 0x1919000cU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1400H, 0x00c00005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c90005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                WR1_PROG(REG_1400H, 0x00c00005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c90005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                HW_SCE_p_func101(0xe81025c3U, 0xe94df07cU, 0x91a0ffbfU, 0xf491a3f9U);
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1f080000U);
                WR1_PROG(REG_1600H, 0x00000b7bU);
                WR1_PROG(REG_1608H, 0x81b0001bU);
                WR1_PROG(REG_1400H, 0x00c00011U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c900c1U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1400H, 0x00c000d1U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1014H, 0x00000428U);
                WR1_PROG(REG_1018H, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x1a1a0009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000f314U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x2bd26459U, 0x61979a69U, 0xa6e5d18cU, 0xe8484a62U);
                HW_SCE_p_func317();

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1400H, 0x00030005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x03430005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1400H, 0x00c00009U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000428U);

                WR1_PROG(REG_1004H, 0x1919000cU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1400H, 0x00c00005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c90005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1404H, 0x1f080000U);
                WR1_PROG(REG_1400H, 0x00c000d1U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xf88d9a0dU));

                OFS_ADR = 224;

                WR1_PROG(REG_1404H, 0x1f180000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000030U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000f314U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x5f1bacb0U, 0x4f205716U, 0x71f8f872U, 0x59ebb41cU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1400H, 0x00c000d1U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1014H, 0x00000a40U);
                WR1_PROG(REG_1018H, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x1a1a0009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000f314U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x3a0d5a59U, 0x0e12e7e0U, 0x388da8a7U, 0xa0a41447U);
                HW_SCE_p_func318();

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1400H, 0x00030005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x03430005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1400H, 0x00c00009U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000a40U);

                WR1_PROG(REG_1004H, 0x1919000cU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1400H, 0x00c00005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c90005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                HW_SCE_p_func101(0x3f8f51f3U, 0x1ab9bb34U, 0x6a576a69U, 0xf1202f9aU);
            }
        }
        else
        {
            HW_SCE_p_func101(0x1c26bf0aU, 0x5b7f833dU, 0xe8e08738U, 0xb35077f0U);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);

    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
