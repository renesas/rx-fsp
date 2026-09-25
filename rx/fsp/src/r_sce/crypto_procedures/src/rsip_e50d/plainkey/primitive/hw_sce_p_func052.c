/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func052 (void)
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

        HW_SCE_p_func100(0x6ac95eb9U, 0x046f569aU, 0x08882be7U, 0xcef26a04U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x1010000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x1010000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            HW_SCE_p_func101(0x4136a55eU, 0x95a73010U, 0xcf0c4d5dU, 0x60242026U);
        }
        else
        {
            HW_SCE_p_func101(0x7b3b68acU, 0xae3b8935U, 0x2f877b93U, 0xfbe7650cU);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    WR1_PROG(REG_1400H, 0x00c00091U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x56d3a4ebU));

    OFS_ADR = 40;

    WR1_PROG(REG_1404H, 0x19b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000024U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000521U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x8742520aU, 0x526bbc23U, 0xa38186b6U, 0x48a5a86eU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x81f404e2U));

    OFS_ADR = 80;

    WR1_PROG(REG_1404H, 0x19b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000024U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000522U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xb66ce2d9U, 0x41e0e538U, 0x67296bb2U, 0x048c4e60U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c0007dU);
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
    WR1_PROG(REG_1420H, change_endian_long(0x58da07c5U));

    OFS_ADR = 0;

    WR1_PROG(REG_1404H, 0x19b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000024U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000523U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x53e4ff0bU, 0xa966a1c1U, 0x89da4341U, 0xd5439012U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x4b091749U));

    OFS_ADR = 120;

    WR1_PROG(REG_1404H, 0x19b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000024U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000524U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x694ec7d2U, 0x453eb77dU, 0x104f78ecU, 0xa8b67adeU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xdb7cb45eU));

    OFS_ADR = 160;

    WR1_PROG(REG_1404H, 0x11a00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000020U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000525U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xb42b540bU, 0x253a85ebU, 0xe17e5e0bU, 0x793251a2U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x15b00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1608H, 0x80a0001bU);
    WR1_PROG(REG_1400H, 0x03430081U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0007dU);
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

        WR1_PROG(REG_1004H, 0x1010000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0xd6aa4808U, 0xfb873eefU, 0x392cc2a1U, 0x666a43d1U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0xfafdaa67U, 0x8027da51U, 0x5aa9aa2aU, 0xdcaa6a59U);

            break;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x58da07c5U));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x13980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000521U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x82d08932U, 0x4e2a334eU, 0xc43f8d78U, 0x0150c35eU);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x56d3a4ebU));

            OFS_ADR = 40;

            WR1_PROG(REG_1404H, 0x19b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000522U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xae1431d8U, 0xa91a2a0cU, 0x7fc9d6a4U, 0x3ff83283U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000521U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x99aa1cffU, 0x42de90f6U, 0xaca522fdU, 0x4145576dU);
            HW_SCE_p_func053();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x58da07c5U));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x13980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000526U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x496d8507U, 0x8d2c7b3cU, 0x8cefaed3U, 0x5dbcc143U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x56d3a4ebU));

            OFS_ADR = 40;

            WR1_PROG(REG_1404H, 0x19b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000527U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x8e8009b7U, 0x1fc06468U, 0x0109b414U, 0x268077a4U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x81f404e2U));

            OFS_ADR = 80;

            WR1_PROG(REG_1404H, 0x13980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000523U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x6052c13dU, 0x297c3a5dU, 0x4a3de020U, 0xe1c77939U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x4b091749U));

            OFS_ADR = 120;

            WR1_PROG(REG_1404H, 0x19b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000524U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x1bb0ec94U, 0xc510097aU, 0x523cde96U, 0x36a8d567U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f580000U);
            WR1_PROG(REG_1400H, 0x00c00081U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x10100009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x10100009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x10100009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000522U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x89478f69U, 0xd82dd8fcU, 0xb8be6c67U, 0xa63f9440U);
            HW_SCE_p_func053();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x81f404e2U));

            OFS_ADR = 80;

            WR1_PROG(REG_1404H, 0x13980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000528U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x585fa7abU, 0x03a82427U, 0x6e90ac81U, 0x5390f9acU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x4b091749U));

            OFS_ADR = 120;

            WR1_PROG(REG_1404H, 0x19b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000024U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000529U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x255ea665U, 0xb639276fU, 0xb1ff0b9bU, 0xe22a035cU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f580000U);
            WR1_PROG(REG_1400H, 0x00c00081U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x10100009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x10100009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x10100009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1010000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00a10000U);

            HW_SCE_p_func100(0x4c6069d8U, 0xd1ba547eU, 0x701f0c4cU, 0x258c0689U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x10100009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x58da07c5U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000525U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x8ea4dac7U, 0xfd655eb4U, 0xe2bc3881U, 0xdaf441e2U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x81f404e2U));

                OFS_ADR = 80;

                WR1_PROG(REG_1404H, 0x1f480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000526U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x86cbcca5U, 0x48bb09feU, 0x9edccb24U, 0xf2a1fc62U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000521U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x978cf00eU, 0xcc71aa51U, 0x1b38ff6eU, 0x158055feU);
                HW_SCE_p_func303();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x58da07c5U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x20e0927dU, 0x95f26cfbU, 0x12285a7cU, 0xdda1caffU);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x56d3a4ebU));

                OFS_ADR = 40;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000527U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x7f42888aU, 0x9f5bb9b4U, 0xb58cdbb8U, 0x21860ebdU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x4b091749U));

                OFS_ADR = 120;

                WR1_PROG(REG_1404H, 0x1f480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000528U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x083bb3f7U, 0x2d08a77eU, 0xb659028aU, 0x2d4f9557U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000522U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xaf502ef5U, 0x6874473eU, 0x01ee0f65U, 0xa866b51aU);
                HW_SCE_p_func303();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x56d3a4ebU));

                OFS_ADR = 40;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x02b5193fU, 0x083f7bf7U, 0x87ec31fdU, 0x60bddf40U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0x9985afa6U, 0x8219facfU, 0x1af1fd22U, 0xb9f4e732U);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1018H, 0x00000220U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x1010000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x81f404e2U));

                OFS_ADR = 80;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x8a9e24b0U, 0xb97a55bdU, 0x92236031U, 0x5c7c0c2aU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x58da07c5U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x1f480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xe033fc0bU, 0x00a9cc5aU, 0xde17d072U, 0xda540882U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000523U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xf9a064c4U, 0xd57e367fU, 0xaa477331U, 0x1a88e27bU);
                HW_SCE_p_func303();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x81f404e2U));

                OFS_ADR = 80;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xbd5f751aU, 0xcd2c51e5U, 0x0f990573U, 0x59faaa55U);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x4b091749U));

                OFS_ADR = 120;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x45a09a30U, 0xd857228dU, 0x6092a484U, 0xd6fefe49U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x56d3a4ebU));

                OFS_ADR = 40;

                WR1_PROG(REG_1404H, 0x1f480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x323649d5U, 0xe6bb6757U, 0x3aa20ab3U, 0x2f82a21bU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000524U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xc975c32aU, 0x15881d1aU, 0x06d396deU, 0xb5087fdeU);
                HW_SCE_p_func303();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x4b091749U));

                OFS_ADR = 120;

                WR1_PROG(REG_1404H, 0x17a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000024U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000052dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xb25a5c8aU, 0xe3b09bc2U, 0x9cc5a399U, 0xc13a4f04U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0x0ddc288fU, 0xe54a7632U, 0x8cfc16d2U, 0x2cf5406bU);
            }
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xdb7cb45eU));

    OFS_ADR = 160;

    WR1_PROG(REG_1404H, 0x11a00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000020U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000052eU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x7287c4f6U, 0x3b36a591U, 0x1a629512U, 0xa6d47d24U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
    WR1_PROG(REG_1400H, 0x00c0007dU);
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

        HW_SCE_p_func100(0xaa1f6d3dU, 0x4cadefcdU, 0x242b380cU, 0xde752273U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x10100008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x10100008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x000033c0U);

            HW_SCE_p_func101(0x794d1aa2U, 0x57ee5e9fU, 0x87d52f07U, 0xdde0f1fdU);
        }
        else
        {
            HW_SCE_p_func101(0x93bbd001U, 0x29f8a8f4U, 0x50f239ccU, 0x637bcb7cU);

            break;
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x4b091749U));

    OFS_ADR = 120;

    WR1_PROG(REG_1404H, 0x17a80000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000024U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000052fU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x4d97e98bU, 0xcf78b8f5U, 0x996e4ffeU, 0xff231214U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17a80000U);
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

        WR1_PROG(REG_1004H, 0x1111000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x012c7c40U, 0xf36c3e24U, 0x3cd0b4ffU, 0x36497eb2U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1111000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0xe5fe7e66U, 0x93758ebbU, 0x0bee3408U, 0x0c133c07U);
        }
        else
        {
            HW_SCE_p_func101(0xf95fd7adU, 0x19326a07U, 0x930a8df1U, 0xcc760616U);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0x387cc8ebU, 0xacb74973U, 0x3a7ad7b1U, 0x3e90595eU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x1111000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        HW_SCE_p_func101(0x313339d1U, 0xdd7a32f9U, 0xa70f78b1U, 0xc2b79590U);
    }
    else
    {
        HW_SCE_p_func101(0xd951b8c0U, 0x0313a321U, 0xd183ed43U, 0x6fe0f83cU);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
