/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func313 (void)
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

        HW_SCE_p_func100(0x51df7385U, 0x7aaf685aU, 0x605b5a6bU, 0x317ed86bU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x1818000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x1818000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            HW_SCE_p_func101(0xf3450fd1U, 0x79b708bbU, 0xb33d5193U, 0x495fc8a5U);
        }
        else
        {
            HW_SCE_p_func101(0x49dc89ecU, 0x2fbc03d7U, 0x64a8afe8U, 0x7b7ff1e2U);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    WR1_PROG(REG_1400H, 0x00c000d1U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x4c2d38c1U));

    OFS_ADR = 56;

    WR1_PROG(REG_1404H, 0x19700000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000034U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003131U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x9544e6d9U, 0x8b43e371U, 0x23aee84dU, 0xc6c375cbU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x7ed21809U));

    OFS_ADR = 112;

    WR1_PROG(REG_1404H, 0x19700000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000034U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003132U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x08a33d18U, 0x958786c4U, 0x175a60e3U, 0x10693fd7U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c000bdU);
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
    WR1_PROG(REG_1420H, change_endian_long(0x67640c08U));

    OFS_ADR = 0;

    WR1_PROG(REG_1404H, 0x19700000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000034U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003133U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xde320452U, 0xb54190b3U, 0x886cfba1U, 0xc9c46107U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xbba24613U));

    OFS_ADR = 168;

    WR1_PROG(REG_1404H, 0x19700000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000034U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003134U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x7931d4e9U, 0x4b88f97eU, 0x40e9515dU, 0x8feda099U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xf88d9a0dU));

    OFS_ADR = 224;

    WR1_PROG(REG_1404H, 0x11600000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000030U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003135U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xd0c2ed17U, 0xc80ad0edU, 0x224cd56fU, 0x739ce647U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x15700000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1608H, 0x80b0001bU);
    WR1_PROG(REG_1400H, 0x034300c1U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19800000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c000bdU);
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

        WR1_PROG(REG_1004H, 0x1818000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0xd8e59810U, 0x300c937dU, 0xb11669a3U, 0xe7519a9fU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0x769087c3U, 0xe0ecca6cU, 0xa98272bcU, 0xe7fcbbfcU);

            break;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x67640c08U));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x13580000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003131U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x50586e4eU, 0x2accffa8U, 0x81c77deaU, 0x5a06aebcU);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x4c2d38c1U));

            OFS_ADR = 56;

            WR1_PROG(REG_1404H, 0x19700000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003132U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x521f2ec9U, 0x7c7edee7U, 0xa82416fcU, 0xd454c543U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003131U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x5c12c203U, 0x4caecd71U, 0x2e43a2eaU, 0x968f2f6fU);
            HW_SCE_p_func314();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x67640c08U));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x13580000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003136U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x9d6d61f0U, 0xf2317dfbU, 0xbe5fab67U, 0x63887e57U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x4c2d38c1U));

            OFS_ADR = 56;

            WR1_PROG(REG_1404H, 0x19700000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003137U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x28a1034bU, 0x6aef5cecU, 0x27da7182U, 0x83bba56bU);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x7ed21809U));

            OFS_ADR = 112;

            WR1_PROG(REG_1404H, 0x13580000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003133U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x7822869cU, 0x694ec66aU, 0x4fb2e9d7U, 0x4cbc0f4cU);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xbba24613U));

            OFS_ADR = 168;

            WR1_PROG(REG_1404H, 0x19700000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003134U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xec4cefa1U, 0xa29df1f7U, 0x07390850U, 0xa5521d3bU);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f180000U);
            WR1_PROG(REG_1400H, 0x00c000c1U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x18180009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x18180009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x18180009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003132U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xf3c86b80U, 0xb55d7fd0U, 0x77019e22U, 0x73d58465U);
            HW_SCE_p_func314();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x7ed21809U));

            OFS_ADR = 112;

            WR1_PROG(REG_1404H, 0x13580000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003138U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x34fbbc06U, 0xa1f81c38U, 0xbce43a60U, 0xad609274U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xbba24613U));

            OFS_ADR = 168;

            WR1_PROG(REG_1404H, 0x19700000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000034U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003139U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x38516abcU, 0xe18de13fU, 0x921f6f53U, 0x4fe54e76U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f180000U);
            WR1_PROG(REG_1400H, 0x00c000c1U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x18180009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x18180009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x18180009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1818000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00a10000U);

            HW_SCE_p_func100(0x0eb9c7ebU, 0xb5d58060U, 0x6f52cddaU, 0x2039e8e8U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x18180009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x67640c08U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003135U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xcd074488U, 0xafb5ad87U, 0x360a9b22U, 0xbd649362U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x7ed21809U));

                OFS_ADR = 112;

                WR1_PROG(REG_1404H, 0x1f080000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003136U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x6c7f72f3U, 0xdd634c17U, 0x8bde5d09U, 0x5929d419U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003131U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x025f0636U, 0x3ae805eeU, 0xe5c3cf39U, 0x2b5deb36U);
                HW_SCE_p_func318();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x67640c08U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x61170893U, 0x560d8824U, 0xce97fa19U, 0x62a30178U);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x4c2d38c1U));

                OFS_ADR = 56;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003137U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xa5a16959U, 0xb017a42dU, 0xdb595651U, 0x79dc46caU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xbba24613U));

                OFS_ADR = 168;

                WR1_PROG(REG_1404H, 0x1f080000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003138U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x92007836U, 0x24511f80U, 0xd2a9670bU, 0x27754c2bU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003132U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xcc60d6c9U, 0x4702c2f9U, 0x57c2ed06U, 0xac820404U);
                HW_SCE_p_func318();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x4c2d38c1U));

                OFS_ADR = 56;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x61577c04U, 0x1e547cbaU, 0x85045fcbU, 0x7094b0d5U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0xe8a43501U, 0x6ec19c8bU, 0xf88a3032U, 0x314a87e3U);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1018H, 0x00000220U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x1818000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x7ed21809U));

                OFS_ADR = 112;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x4f096af3U, 0xe858bef8U, 0x6df6b111U, 0xff0667f2U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x67640c08U));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x1f080000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x26f1896eU, 0x1936e471U, 0xa4dc1015U, 0x91b4fe91U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003133U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xc88ac353U, 0xc629e153U, 0xaaa625e6U, 0x99678999U);
                HW_SCE_p_func318();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x7ed21809U));

                OFS_ADR = 112;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x75ae57bfU, 0x8ffdee25U, 0xf10720c9U, 0xaafb1e3bU);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xbba24613U));

                OFS_ADR = 168;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xd63422aeU, 0x68defcfdU, 0x68a9598eU, 0x8b40f2c4U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x4c2d38c1U));

                OFS_ADR = 56;

                WR1_PROG(REG_1404H, 0x1f080000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x2dc05ac8U, 0x50a0a5fbU, 0x104b1105U, 0xac8dd263U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003134U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xb2b31741U, 0xc18a281cU, 0x0e9248e9U, 0xb2b3e8f8U);
                HW_SCE_p_func318();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xbba24613U));

                OFS_ADR = 168;

                WR1_PROG(REG_1404H, 0x17680000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000034U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000313dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xe461dfcfU, 0x7b9ff048U, 0x99322106U, 0x8eff7047U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0xee142902U, 0x1b9ea085U, 0xfdbdd9e8U, 0x03d33714U);
            }
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xf88d9a0dU));

    OFS_ADR = 224;

    WR1_PROG(REG_1404H, 0x11600000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000030U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000313eU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x437b6899U, 0xfc6d93fdU, 0xda0474ccU, 0xe1703a12U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
    WR1_PROG(REG_1400H, 0x00c000bdU);
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

        HW_SCE_p_func100(0x8b05a220U, 0x0f3f84efU, 0x1416f385U, 0xea62133eU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x18180008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x18180008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x000033c0U);

            HW_SCE_p_func101(0x11a5b785U, 0x9a1ef63cU, 0xe73b4940U, 0x6fb10651U);
        }
        else
        {
            HW_SCE_p_func101(0xd3401487U, 0x3ae356baU, 0xb0ad32d6U, 0x3dc5e113U);

            break;
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xbba24613U));

    OFS_ADR = 168;

    WR1_PROG(REG_1404H, 0x17680000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000034U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000313fU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x1823bbb2U, 0xe0cd02cbU, 0x0f586cd1U, 0xafa0fa09U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17680000U);
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

        WR1_PROG(REG_1004H, 0x1919000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x3aa73f4eU, 0x7e9afba4U, 0xe45859cbU, 0xe62566b1U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1919000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0x0b73ec7aU, 0xf507ed9fU, 0xc7f004bdU, 0xdcb878ecU);
        }
        else
        {
            HW_SCE_p_func101(0x398124d8U, 0x4c7fa472U, 0x9f2d62e7U, 0x7311c1fbU);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0xa5ace466U, 0xc679e6fdU, 0x8b129849U, 0x16b479c9U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x1919000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        HW_SCE_p_func101(0x60bbf69eU, 0xaed43f57U, 0xdbd412b4U, 0xdd38e5ceU);
    }
    else
    {
        HW_SCE_p_func101(0xf06e637fU, 0xff6106d6U, 0x761181baU, 0x9142c3c3U);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
