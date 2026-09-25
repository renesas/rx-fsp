/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func054 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1600H, 0x00000bdeU);

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

        WR1_PROG(REG_1404H, 0x16280000U);
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

        HW_SCE_p_func100(0x5dcd21f5U, 0x182e68a1U, 0xe61bae90U, 0xb3fbb1dcU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x2020000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x2020000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            HW_SCE_p_func101(0xb374fe1bU, 0x7955ed61U, 0x75a52c81U, 0x4365d4f3U);
        }
        else
        {
            HW_SCE_p_func101(0x3f1dd18dU, 0x3e576a41U, 0xc0e1e755U, 0x9292cfc4U);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    WR1_PROG(REG_1400H, 0x00c00111U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xd5a2b742U));

    OFS_ADR = 72;

    WR1_PROG(REG_1404H, 0x19300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000044U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000541U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x4c372b3aU, 0x9c28b1c1U, 0x2cbd0d0bU, 0x30569931U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x242d7f2bU));

    OFS_ADR = 144;

    WR1_PROG(REG_1404H, 0x19300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000044U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000542U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x0ee1af9aU, 0xb537bb9bU, 0x1ad6972bU, 0xa043cb11U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c000fdU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c20005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x40e99bf2U));

    OFS_ADR = 0;

    WR1_PROG(REG_1404H, 0x19300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000044U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000543U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xfe950fe8U, 0x42a95668U, 0x901a11d8U, 0x4ffd6489U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xf5a7be36U));

    OFS_ADR = 216;

    WR1_PROG(REG_1404H, 0x19300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000044U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000544U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x4f894180U, 0x97f6a31eU, 0x34d3dd05U, 0xdb2733ddU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x412b76f0U));

    OFS_ADR = 288;

    WR1_PROG(REG_1404H, 0x11200000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000545U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x67851133U, 0x7e3f7256U, 0xd1395c1fU, 0x590af8bbU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x15300000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1608H, 0x80c0001bU);
    WR1_PROG(REG_1400H, 0x03430101U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19400000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c000fdU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x2020000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x6e4ccc43U, 0x9d4d94beU, 0x385b0aa5U, 0x73b24241U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0x68d67ad1U, 0xc4d314f9U, 0xac9c29bdU, 0x41fa7accU);

            break;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x40e99bf2U));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x13180000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000541U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xfcbadd42U, 0xbad9e467U, 0xfaca047aU, 0x5c29cc1aU);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xd5a2b742U));

            OFS_ADR = 72;

            WR1_PROG(REG_1404H, 0x19300000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000542U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x419a8383U, 0x15b4b9c7U, 0xb4f89d85U, 0x2866b588U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000541U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x46455530U, 0xb9da8339U, 0x178f8361U, 0xda89528eU);
            HW_SCE_p_func055();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x40e99bf2U));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x13180000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000546U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x3d97de28U, 0xf2857cc8U, 0xff8a7fc6U, 0xaf75846dU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xd5a2b742U));

            OFS_ADR = 72;

            WR1_PROG(REG_1404H, 0x19300000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000547U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xbaf015c3U, 0x88da87ebU, 0x2b02e0e5U, 0x6e56f24aU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x242d7f2bU));

            OFS_ADR = 144;

            WR1_PROG(REG_1404H, 0x13180000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000543U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x8cfce2f4U, 0x8e07a169U, 0x192841f2U, 0xb1c8c0d2U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xf5a7be36U));

            OFS_ADR = 216;

            WR1_PROG(REG_1404H, 0x19300000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000544U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x67ec4b9dU, 0x415704dcU, 0xcec2e5f4U, 0xeb9c20f8U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1ed80000U);
            WR1_PROG(REG_1400H, 0x00c00101U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x20200009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x20200009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x20200009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000542U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x7a2bd4d6U, 0xd4e6591cU, 0x919ed0b2U, 0xc510f6a7U);
            HW_SCE_p_func055();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x242d7f2bU));

            OFS_ADR = 144;

            WR1_PROG(REG_1404H, 0x13180000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000548U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x50be129eU, 0xf4e390beU, 0xf5c6e6bfU, 0x70e3421dU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xf5a7be36U));

            OFS_ADR = 216;

            WR1_PROG(REG_1404H, 0x19300000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000044U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000549U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x9b025c55U, 0xa4ed0950U, 0x057804bbU, 0x4eaaebfdU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1ed80000U);
            WR1_PROG(REG_1400H, 0x00c00101U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x20200009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x20200009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x20200009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x2020000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00a10000U);

            HW_SCE_p_func100(0xef09e004U, 0x818bc9efU, 0x71dbcfebU, 0xee5e8763U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x20200009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x40e99bf2U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000545U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x38677adbU, 0x1d74527fU, 0x3f079d56U, 0x2e626b18U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x242d7f2bU));

                OFS_ADR = 144;

                WR1_PROG(REG_1404H, 0x1ec80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000546U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x76c8f1c4U, 0x5033555cU, 0xac807ce4U, 0x11b06d18U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000541U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xfa4a95fcU, 0x94700286U, 0x06ed7b24U, 0x40953fc0U);
                HW_SCE_p_func305();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x40e99bf2U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x572dee22U, 0x3e763a46U, 0xb5a43fb2U, 0x0ba28f6bU);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xd5a2b742U));

                OFS_ADR = 72;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000547U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x7c360f91U, 0x42bf36b9U, 0xa54959c2U, 0x62444229U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xf5a7be36U));

                OFS_ADR = 216;

                WR1_PROG(REG_1404H, 0x1ec80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000548U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xe346e1acU, 0x03fd9a51U, 0x8944c62aU, 0x3b7f51d1U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000542U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x915e503bU, 0x7205d421U, 0x760c2d95U, 0x73911bebU);
                HW_SCE_p_func305();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xd5a2b742U));

                OFS_ADR = 72;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x1d162a2cU, 0xf3db2a8aU, 0x325d71f0U, 0xbe3a9ad7U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0x38881de4U, 0xa8bc3632U, 0x0ed447d0U, 0xea5e2b19U);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1018H, 0x00000220U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x2020000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x242d7f2bU));

                OFS_ADR = 144;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xabe1a383U, 0xfe67d5d5U, 0xbd6ee389U, 0xad271740U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x40e99bf2U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x1ec80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x7f7ec308U, 0x4c941ef5U, 0x4c9786c1U, 0x7b2e905bU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000543U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x712e9020U, 0x0ede769cU, 0x8bd524a3U, 0x3c4a98edU);
                HW_SCE_p_func305();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x242d7f2bU));

                OFS_ADR = 144;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xbb739887U, 0x71de2d1aU, 0xd9815678U, 0x81327772U);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xf5a7be36U));

                OFS_ADR = 216;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x1a1f93d0U, 0x4d7c722aU, 0x4bfed0ccU, 0xc5a2ec9cU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xd5a2b742U));

                OFS_ADR = 72;

                WR1_PROG(REG_1404H, 0x1ec80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xcf0d7e0eU, 0x5a9268c6U, 0xb915d625U, 0x2428e3b2U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000544U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x937fc7c6U, 0xe606b7d3U, 0x62aa69ecU, 0x03b2a17dU);
                HW_SCE_p_func305();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xf5a7be36U));

                OFS_ADR = 216;

                WR1_PROG(REG_1404H, 0x17280000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000044U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000054dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x9a45f218U, 0x12c939edU, 0xd13ded20U, 0x84b62510U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0x12198633U, 0x753ce127U, 0x517b12bfU, 0x21b27902U);
            }
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x412b76f0U));

    OFS_ADR = 288;

    WR1_PROG(REG_1404H, 0x11200000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000054eU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x89bebc52U, 0xd88be394U, 0x661d6c89U, 0x336c075bU);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
    WR1_PROG(REG_1400H, 0x00c000fdU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c20005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        HW_SCE_p_func100(0x65c4ba8aU, 0x8513d7aeU, 0xa821d3d5U, 0xd6e1b066U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x20200008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x20200008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x000033c0U);

            HW_SCE_p_func101(0x839e84cbU, 0xf32a2018U, 0x9b41af23U, 0x085f7da0U);
        }
        else
        {
            HW_SCE_p_func101(0x5e16f0aaU, 0xdb0c79f7U, 0x486a3c76U, 0xf69e22faU);

            break;
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xf5a7be36U));

    OFS_ADR = 216;

    WR1_PROG(REG_1404H, 0x17280000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000044U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000054fU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x5c7d8e04U, 0x7d5da10aU, 0xff177d5dU, 0x9136e5f6U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1400H, 0x00030005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x03430005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    while (1)
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        WR1_PROG(REG_1020H, 0x00000a40U);

        WR1_PROG(REG_1004H, 0x2121000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0xbb67fcf4U, 0xd20ce2b3U, 0x5a948710U, 0xd9f4f280U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x2121000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0x26ef3f1dU, 0xe43ee139U, 0x44294ed0U, 0xaa225051U);
        }
        else
        {
            HW_SCE_p_func101(0x16461491U, 0x0e1b7584U, 0xb1b6504cU, 0x9697eae0U);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0x1d420a7dU, 0x71997e41U, 0x132f2fd5U, 0x76080fb3U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x2121000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        HW_SCE_p_func101(0x2acde254U, 0xb333189aU, 0xc3e18661U, 0x92c18517U);
    }
    else
    {
        HW_SCE_p_func101(0x96446e89U, 0xbe57e74dU, 0xc713d272U, 0x416e4a07U);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
