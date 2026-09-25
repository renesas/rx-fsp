/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func315 (void)
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

        HW_SCE_p_func100(0x704a779fU, 0x0c93596bU, 0x3a0211afU, 0x24b878c8U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x3030000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x3030000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            HW_SCE_p_func101(0xa13c1e2dU, 0xfbe660e2U, 0x5de345faU, 0xbc15ba00U);
        }
        else
        {
            HW_SCE_p_func101(0xafb0bc72U, 0x6ec2912cU, 0xc1941462U, 0x6191f00aU);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    WR1_PROG(REG_1400H, 0x00c00191U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x325e6813U));

    OFS_ADR = 104;

    WR1_PROG(REG_1404H, 0x18b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000064U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003151U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x31128de2U, 0x8b80f27aU, 0xc768a6faU, 0x41f35f0dU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xcf0876b7U));

    OFS_ADR = 208;

    WR1_PROG(REG_1404H, 0x18b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000064U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003152U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x6fdcdb9cU, 0x38aa5982U, 0x85bced5fU, 0x574f7fc9U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c0017dU);
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
    WR1_PROG(REG_1420H, change_endian_long(0x7217669bU));

    OFS_ADR = 0;

    WR1_PROG(REG_1404H, 0x18b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000064U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003153U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x15b92411U, 0xa62a7c91U, 0xf108463cU, 0xf98993adU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x044ee95dU));

    OFS_ADR = 312;

    WR1_PROG(REG_1404H, 0x18b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000064U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003154U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xa64b3888U, 0x62e3cdffU, 0x5fdf984cU, 0x2fb74ab1U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xda87840aU));

    OFS_ADR = 416;

    WR1_PROG(REG_1404H, 0x10a00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000060U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003155U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xdd9db378U, 0x15325f9dU, 0x1bbf513dU, 0xb49f247cU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x14b00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1608H, 0x80e0001bU);
    WR1_PROG(REG_1400H, 0x03430181U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x18c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0017dU);
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

        WR1_PROG(REG_1004H, 0x3030000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x5fc5631bU, 0xf0412445U, 0x48eb8421U, 0x129d1c15U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0xa4bd7082U, 0xe8043bb6U, 0xb45c90aaU, 0x512c2383U);

            break;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x7217669bU));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x12980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003151U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x188cd3b1U, 0x04ccba12U, 0xd93a51d5U, 0xa07971b5U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x325e6813U));

            OFS_ADR = 104;

            WR1_PROG(REG_1404H, 0x18b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003152U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xe516c9d8U, 0x7b92b8cbU, 0xa00179e7U, 0xaf18842dU);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003151U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xd1190ec2U, 0xa86b1863U, 0xeddeb85dU, 0x97dbe3faU);
            HW_SCE_p_func316();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x7217669bU));

            OFS_ADR = 0;

            WR1_PROG(REG_1404H, 0x12980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003156U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x45798541U, 0xbdce4392U, 0x8526d775U, 0xd44c1e14U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x325e6813U));

            OFS_ADR = 104;

            WR1_PROG(REG_1404H, 0x18b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003157U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x79b4b3faU, 0x17059f32U, 0xac90ef04U, 0x7154d872U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xcf0876b7U));

            OFS_ADR = 208;

            WR1_PROG(REG_1404H, 0x12980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003153U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xa9253e73U, 0xfeb3331eU, 0x45aed499U, 0x19b701a2U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x044ee95dU));

            OFS_ADR = 312;

            WR1_PROG(REG_1404H, 0x18b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003154U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xcae095b5U, 0xbcf20a6cU, 0xcbb9db96U, 0x88e9e117U);
            HW_SCE_p_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1e580000U);
            WR1_PROG(REG_1400H, 0x00c00181U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x30300009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x30300009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x30300009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003152U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x1fd70e1bU, 0x417787f6U, 0x551a7cd3U, 0xfa3bba1bU);
            HW_SCE_p_func316();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0xcf0876b7U));

            OFS_ADR = 208;

            WR1_PROG(REG_1404H, 0x12980000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003158U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xf7dcbbb0U, 0xc7e9fb25U, 0x99de10dcU, 0xbb7e9fd2U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0b040184U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x044ee95dU));

            OFS_ADR = 312;

            WR1_PROG(REG_1404H, 0x18b00000U);

            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000064U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00003159U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x81b31e77U, 0x1e886b2cU, 0x8c81b1fbU, 0xe1d615c4U);
            HW_SCE_p_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1e580000U);
            WR1_PROG(REG_1400H, 0x00c00181U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x30300009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x30300009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x30300009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x3030000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00a10000U);

            HW_SCE_p_func100(0x298fd05bU, 0x581f6bffU, 0x1f0e6400U, 0x415c2400U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x30300009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x7217669bU));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003155U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xbf767c1aU, 0x5a889d17U, 0xf7b36a15U, 0x04727f19U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xcf0876b7U));

                OFS_ADR = 208;

                WR1_PROG(REG_1404H, 0x1e480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003156U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xb6d04afbU, 0xf5b0534aU, 0x44e2e388U, 0x418742b0U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003151U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x9d928569U, 0xfacce7f5U, 0xae7ed410U, 0xd8370ee9U);
                HW_SCE_p_func320();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x7217669bU));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xe1ebbdadU, 0x5d5fe0a7U, 0x2780ba24U, 0x968f3a5cU);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x325e6813U));

                OFS_ADR = 104;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003157U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xf69e7954U, 0xfddcd514U, 0x621865b5U, 0x87a9ed0fU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x044ee95dU));

                OFS_ADR = 312;

                WR1_PROG(REG_1404H, 0x1e480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003158U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xa237727aU, 0x7f7d3e6fU, 0x0d0c1355U, 0x9fecc579U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003152U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x8d714b6eU, 0x5330d6a9U, 0x48d468b4U, 0x08b4bc62U);
                HW_SCE_p_func320();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x325e6813U));

                OFS_ADR = 104;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xfeb30f3cU, 0x6579c055U, 0xc26d5a50U, 0xccdf3446U);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0xd67a23daU, 0xc986a396U, 0x24896bedU, 0x8bdfdd61U);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1018H, 0x00000220U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x3030000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xcf0876b7U));

                OFS_ADR = 208;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x39959e92U, 0xca2642c6U, 0x5ff8f46cU, 0xfc0bb682U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x7217669bU));

                OFS_ADR = 0;

                WR1_PROG(REG_1404H, 0x1e480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315bU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x8b2589e0U, 0xc4bc0242U, 0x3c5b09f9U, 0x772c27c5U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003153U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x542ec6a7U, 0xcea6e50dU, 0x679834f1U, 0xbf4bcb6cU);
                HW_SCE_p_func320();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0xcf0876b7U));

                OFS_ADR = 208;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xa67fdfbaU, 0xa5b30630U, 0xf7c8c069U, 0x98c1f709U);
                HW_SCE_p_func016(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x044ee95dU));

                OFS_ADR = 312;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315cU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x6081ca34U, 0xce8277aaU, 0x0b2ef41fU, 0x6aa1927aU);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x325e6813U));

                OFS_ADR = 104;

                WR1_PROG(REG_1404H, 0x1e480000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xbaac1b82U, 0x50986339U, 0xa4da7b01U, 0x58b09e05U);
                HW_SCE_p_func017(OFS_ADR);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00003154U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x4f97905dU, 0x6b42a8deU, 0x9fe28a60U, 0x0e6e20b4U);
                HW_SCE_p_func320();

                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0b040184U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x044ee95dU));

                OFS_ADR = 312;

                WR1_PROG(REG_1404H, 0x16a80000U);

                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x00000064U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000315dU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xd18b7fccU, 0x49be274cU, 0xdbb924a7U, 0x1549988aU);
                HW_SCE_p_func016(OFS_ADR);

                HW_SCE_p_func101(0x4e61008aU, 0xc3d71639U, 0xcbc756d0U, 0x1bbbca12U);
            }
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0xda87840aU));

    OFS_ADR = 416;

    WR1_PROG(REG_1404H, 0x10a00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000060U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000315eU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x5d7788b3U, 0x7ffb56f4U, 0xfb8515dcU, 0xa175dc73U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
    WR1_PROG(REG_1400H, 0x00c0017dU);
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

        HW_SCE_p_func100(0xe7418c82U, 0x9ae2a8cdU, 0xc73a539aU, 0x104fed22U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x30300008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000220U);

            WR1_PROG(REG_1004H, 0x30300008U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x000033c0U);

            HW_SCE_p_func101(0x6fdf693eU, 0x54dcfce8U, 0xd654f33dU, 0x74643716U);
        }
        else
        {
            HW_SCE_p_func101(0x1c667048U, 0x3435b721U, 0xa9281e90U, 0x80012007U);

            break;
        }
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x044ee95dU));

    OFS_ADR = 312;

    WR1_PROG(REG_1404H, 0x16a80000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000064U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000315fU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x26c7526aU, 0x81e847b6U, 0x0f8c185cU, 0xd5853febU);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x16a80000U);
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

        WR1_PROG(REG_1004H, 0x3131000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x00c2f8bfU, 0x794e977dU, 0x9e968d34U, 0x0e3e3ac2U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x3131000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            HW_SCE_p_func101(0x2595f810U, 0x3454c8f2U, 0xa0bd025eU, 0x461650caU);
        }
        else
        {
            HW_SCE_p_func101(0xf036efbeU, 0xcbfa5a62U, 0x11f8f409U, 0xfe93fd17U);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0x11f41b9aU, 0x6e2fe71bU, 0x8bb2b4edU, 0xd342fd21U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x3131000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        HW_SCE_p_func101(0x91cecbd5U, 0x50b9765dU, 0x440ed147U, 0x4b858512U);
    }
    else
    {
        HW_SCE_p_func101(0xd33113c7U, 0x09e26435U, 0xb82979b8U, 0xc9706c9aU);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
