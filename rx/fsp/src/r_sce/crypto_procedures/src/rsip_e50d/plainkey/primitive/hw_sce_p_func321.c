/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func321 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1400H, 0x00030005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x03430005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x16580000U);
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

        HW_SCE_p_func100(0x0de8a445U, 0xbbcf3747U, 0xb4ee9903U, 0x6d2f9de0U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000230U);
            WR1_PROG(REG_1020H, 0x00000230U);

            WR1_PROG(REG_1004H, 0x4040000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000660U);
            WR1_PROG(REG_1020H, 0x00000660U);

            WR1_PROG(REG_1004H, 0x4040000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            HW_SCE_p_func101(0x3d3fb043U, 0x02ac0c08U, 0x052a064aU, 0xeeb8e613U);
        }
        else
        {
            HW_SCE_p_func101(0xb2d4fc03U, 0xe59657caU, 0x65584e90U, 0xd6910612U);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    WR1_PROG(REG_1400H, 0x00c00211U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x9bfae8b3U));

    OFS_ADR = 136;

    WR1_PROG(REG_1404H, 0x18800000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000084U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003211U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x039991f3U, 0xf9873a17U, 0x730bc849U, 0x407a8946U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x78929efeU));

    OFS_ADR = 272;

    WR1_PROG(REG_1404H, 0x18800000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000084U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003212U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xd9e5c72cU, 0xff91a78bU, 0xeaf0d097U, 0x11c6285eU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c001fdU);
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
    WR1_PROG(REG_1420H, change_endian_long(0xdd97ff1eU));

    OFS_ADR = 0;

    WR1_PROG(REG_1404H, 0x18800000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000084U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003213U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x297af90eU, 0x8af7f914U, 0x15a5b99bU, 0xa28af1c7U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x71fb591cU));

    OFS_ADR = 408;

    WR1_PROG(REG_1404H, 0x18800000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000084U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003214U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x6d81cf72U, 0x2d036cfbU, 0x5278a640U, 0x1b67089eU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x3d2bbeceU));

    OFS_ADR = 544;

    WR1_PROG(REG_1404H, 0x10300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003215U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xcbc1fba4U, 0x915978bdU, 0xa334f312U, 0x5a9af9bdU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x9ab36a68U));

    OFS_ADR = 676;

    WR1_PROG(REG_1404H, 0x14600000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003216U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xd6c60d10U, 0xdad70cd4U, 0xfdda5c26U, 0x3a42ce17U);
    HW_SCE_p_func016(OFS_ADR);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x18900000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c001fdU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000230U);
        WR1_PROG(REG_1018H, 0x00000a90U);
        WR1_PROG(REG_1020H, 0x00000878U);

        WR1_PROG(REG_1004H, 0x4040000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x08942c68U, 0x09518385U, 0x84209af4U, 0xf52aa1d5U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0x2825b316U, 0x12961ed4U, 0xd6e528ebU, 0xea604ec2U);

            break;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xdd97ff1eU));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x12380000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003211U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xf63b7eb8U, 0xbaa2f1cfU, 0x3b1e05f6U, 0xa013c1c6U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x9bfae8b3U));

            OFS_ADR = 136;

            WR1_PROG(REG_1404H, 0x18800000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003212U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x1e37a06bU, 0xb24b6a5bU, 0x20650d71U, 0x5813be4aU);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003211U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x28054b44U, 0x9e1624e5U, 0xe2b2cf10U, 0x9824a8e9U);
            HW_SCE_p_func322();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xdd97ff1eU));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x12380000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003217U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xe73ce3c9U, 0xfa1159a4U, 0xa7bd0e8eU, 0xaee5a92eU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x9bfae8b3U));

            OFS_ADR = 136;

            WR1_PROG(REG_1404H, 0x18800000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003218U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x788a5b53U, 0x386b1d7cU, 0x8d5594b4U, 0x3823df5dU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x78929efeU));

            OFS_ADR = 272;

            WR1_PROG(REG_1404H, 0x12380000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003213U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x3e058b51U, 0x42a28abdU, 0xc3607238U, 0x28c10741U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x71fb591cU));

            OFS_ADR = 408;

            WR1_PROG(REG_1404H, 0x18800000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003214U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x2faa2ac6U, 0x9561bc7dU, 0x344207a8U, 0x889561a0U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1dd80000U);
            WR1_PROG(REG_1400H, 0x00c00201U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000230U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x40400009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000660U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000230U);

            WR1_PROG(REG_1004H, 0x40400009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000660U);

            WR1_PROG(REG_1004H, 0x40400009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003212U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xa3d627ecU, 0xe22d3913U, 0x9ffe4d25U, 0xedd94b8eU);
            HW_SCE_p_func322();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x78929efeU));

            OFS_ADR = 272;

            WR1_PROG(REG_1404H, 0x12380000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003219U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x001496a5U, 0x82e0f3b8U, 0x5a292af4U, 0x4e2bede0U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x71fb591cU));

            OFS_ADR = 408;

            WR1_PROG(REG_1404H, 0x18800000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000084U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x0000321aU));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xc38227d1U, 0x23645305U, 0x58338de6U, 0x91b04d4eU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1dd80000U);
            WR1_PROG(REG_1400H, 0x00c00201U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000230U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x40400009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000660U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000230U);

            WR1_PROG(REG_1004H, 0x40400009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000660U);

            WR1_PROG(REG_1004H, 0x40400009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000230U);
            WR1_PROG(REG_1018H, 0x00000660U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x4040000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00a10000U);

            HW_SCE_p_func100(0x7ad85d7aU, 0x8e6983dbU, 0x79f5d54fU, 0xb151fc90U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000878U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                WR1_PROG(REG_1020H, 0x00000230U);

                WR1_PROG(REG_1004H, 0x40400009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xdd97ff1eU));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003215U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xf5ed3eebU, 0x117c5755U, 0x76a03c4fU, 0x590aa62bU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x78929efeU));

                OFS_ADR = 272;

                WR1_PROG(REG_1404H, 0x1dc80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003216U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x70617208U, 0xf77c4222U, 0x043d08a0U, 0x7057feb9U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003211U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x6d3d0e82U, 0xae62e4e4U, 0x4c3e8122U, 0x721441c3U);
                HW_SCE_p_func324();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xdd97ff1eU));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x79a06ad8U, 0x70c455b3U, 0x5ffb6dc7U, 0xc5e77ed4U);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x9bfae8b3U));

                OFS_ADR = 136;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003217U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x706e4937U, 0x88e8cd65U, 0xa2aca128U, 0x1c6804b8U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x71fb591cU));

                OFS_ADR = 408;

                WR1_PROG(REG_1404H, 0x1dc80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003218U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xf58a2049U, 0x925d072bU, 0x8e2287faU, 0x119e6457U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003212U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x1b48e285U, 0xe590e0c3U, 0x81dbbffdU, 0xfce57629U);
                HW_SCE_p_func324();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x9bfae8b3U));

                OFS_ADR = 136;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xe3128d43U, 0x2086f881U, 0x7cbafcacU, 0x8f63f542U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0x11417ea5U, 0x50726494U, 0x60d768aeU, 0x3c9f7f30U);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000660U);
                WR1_PROG(REG_1018H, 0x00000230U);
                WR1_PROG(REG_1020H, 0x00000660U);

                WR1_PROG(REG_1004H, 0x4040000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x78929efeU));

                OFS_ADR = 272;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xd12a9c4dU, 0x0f720273U, 0xe516d92eU, 0x6d568f1fU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xdd97ff1eU));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x1dc80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x0b35cec2U, 0x8125da4cU, 0xb32f1bb0U, 0x0323079fU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003213U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xadae04f2U, 0x5aac9787U, 0xeb15ab5bU, 0xa8b986b8U);
                HW_SCE_p_func324();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x78929efeU));

                OFS_ADR = 272;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x8cf606d5U, 0x5ee1eeedU, 0x99a8c8a3U, 0x93f55694U);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x71fb591cU));

                OFS_ADR = 408;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x3658423bU, 0xd15705beU, 0x0e050c25U, 0xf0c62c84U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x9bfae8b3U));

                OFS_ADR = 136;

                WR1_PROG(REG_1404H, 0x1dc80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x05a27255U, 0xbe2a0f1bU, 0xe4d368d8U, 0xb57027a0U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003214U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xb37c330dU, 0x219d2431U, 0xfa5a69caU, 0x32bb4781U);
                HW_SCE_p_func324();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x71fb591cU));

                OFS_ADR = 408;

                WR1_PROG(REG_1404H, 0x16680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000084U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000321eU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x832ea5b3U, 0x8339e9deU, 0xf36e38a2U, 0x8f42a1daU);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0xa6377e79U, 0xaa5dbea0U, 0x7b8b424aU, 0x8d2a67deU);
            }
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x3d2bbeceU));

    OFS_ADR = 544;

    WR1_PROG(REG_1404H, 0x10300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000321eU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x51980698U, 0xafea148bU, 0x24910874U, 0x6f6c9ccfU);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
    WR1_PROG(REG_1400H, 0x00c001fdU);
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

        HW_SCE_p_func100(0x1f751989U, 0xfb71b278U, 0x3e5f642bU, 0x741e3235U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000a90U);
            WR1_PROG(REG_1018H, 0x00000660U);
            WR1_PROG(REG_1020H, 0x00000660U);

            WR1_PROG(REG_1004H, 0x40400008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000a90U);
            WR1_PROG(REG_1018H, 0x00000230U);
            WR1_PROG(REG_1020H, 0x00000230U);

            WR1_PROG(REG_1004H, 0x40400008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x000033c0U);

            HW_SCE_p_func101(0xe6fe9505U, 0xb5f76ad9U, 0xeb65e7d7U, 0x780fee5dU);
        }
        else
        {
            HW_SCE_p_func101(0x80e23a83U, 0xdbdfba13U, 0x2e6cbde4U, 0x41e52478U);

            break;
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x71fb591cU));

    OFS_ADR = 408;

    WR1_PROG(REG_1404H, 0x16680000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000084U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000321fU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xc44ac180U, 0x61bdfdd5U, 0x94191e80U, 0xf83d8799U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1400H, 0x00030005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x03430005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    while (1)
    {
        WR1_PROG(REG_1014H, 0x00000230U);
        WR1_PROG(REG_1018H, 0x00000878U);
        WR1_PROG(REG_1020H, 0x00000a90U);

        WR1_PROG(REG_1004H, 0x4141000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x62609cceU, 0xa7c7bdd3U, 0x68b1d9b9U, 0xdc649600U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000230U);
            WR1_PROG(REG_1020H, 0x00000878U);

            WR1_PROG(REG_1004H, 0x4141000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0x85725375U, 0x41bb4a8cU, 0x512e3cbeU, 0x09f4bdf4U);
        }
        else
        {
            HW_SCE_p_func101(0x2857c7fdU, 0x22c2f9abU, 0x93588049U, 0x06914aadU);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0xc823effaU, 0xbc39f761U, 0xf9233ecaU, 0x4cf51110U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1014H, 0x00000230U);
        WR1_PROG(REG_1018H, 0x00000878U);
        WR1_PROG(REG_1020H, 0x00000878U);

        WR1_PROG(REG_1004H, 0x4141000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        HW_SCE_p_func101(0x2708ff33U, 0xb4b9dff2U, 0x44647c4aU, 0x27a1ab2aU);
    }
    else
    {
        HW_SCE_p_func101(0xdfdc100eU, 0x6b468cecU, 0x07ab8248U, 0x8d7048afU);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
