/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"
#include "r_rsip_sub_func.h"

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func315 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x80010360U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);

        static const uint32_t Param_func315_func100_001[] =
        {
            BSWAP_32BIG_C(0x0bb3421fU), BSWAP_32BIG_C(0x0e1c5048U), BSWAP_32BIG_C(0x2c392d01U), BSWAP_32BIG_C(
                0x27539d9fU),
        };
        r_rsip_func100(Param_func315_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x3030000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x3030000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            static const uint32_t Param_func315_func101_001[] =
            {
                BSWAP_32BIG_C(0xff910039U), BSWAP_32BIG_C(0x49ea5013U), BSWAP_32BIG_C(0xa369e9dfU), BSWAP_32BIG_C(
                    0x6edc65c2U),
            };
            r_rsip_func101(Param_func315_func101_001);
        }
        else
        {
            static const uint32_t Param_func315_func101_002[] =
            {
                BSWAP_32BIG_C(0x7545ff59U), BSWAP_32BIG_C(0x5b1c218fU), BSWAP_32BIG_C(0x7610915bU), BSWAP_32BIG_C(
                    0x1b08dbbaU),
            };
            r_rsip_func101(Param_func315_func101_002);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_func_sub001(0x00c00191U);

    r_rsip_func_sub004(0x0b040184U, 0x2517e7b7U);

    OFS_ADR = 104;

    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

    r_rsip_func_sub009(0x00003151U);

    static const uint32_t Param_func315_func101_003[] =
    {
        BSWAP_32BIG_C(0x5bcd5d21U), BSWAP_32BIG_C(0x96f93cccU), BSWAP_32BIG_C(0x1d84212dU), BSWAP_32BIG_C(0x3b1b639bU),
    };
    r_rsip_func101(Param_func315_func101_003);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x3cc10901U);

    OFS_ADR = 208;

    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

    r_rsip_func_sub009(0x00003152U);

    static const uint32_t Param_func315_func101_004[] =
    {
        BSWAP_32BIG_C(0xf918214aU), BSWAP_32BIG_C(0x43e8cc7bU), BSWAP_32BIG_C(0x99e07e0bU), BSWAP_32BIG_C(0x3ec08cedU),
    };
    r_rsip_func101(Param_func315_func101_004);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub004(0x0b040184U, 0xabf7a97eU);

    OFS_ADR = 0;

    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

    r_rsip_func_sub009(0x00003153U);

    static const uint32_t Param_func315_func101_005[] =
    {
        BSWAP_32BIG_C(0x86b549e0U), BSWAP_32BIG_C(0xbc86635fU), BSWAP_32BIG_C(0x2f748bfaU), BSWAP_32BIG_C(0x49063219U),
    };
    r_rsip_func101(Param_func315_func101_005);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x0b097e1fU);

    OFS_ADR = 312;

    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

    r_rsip_func_sub009(0x00003154U);

    static const uint32_t Param_func315_func101_006[] =
    {
        BSWAP_32BIG_C(0xcbbb5e5cU), BSWAP_32BIG_C(0xc6846974U), BSWAP_32BIG_C(0xe13c3a89U), BSWAP_32BIG_C(0x9aa53ac9U),
    };
    r_rsip_func101(Param_func315_func101_006);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0xe4f152fdU);

    OFS_ADR = 416;

    r_rsip_func_sub012(0x10a00000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub009(0x00003155U);

    static const uint32_t Param_func315_func101_007[] =
    {
        BSWAP_32BIG_C(0x0e6752d5U), BSWAP_32BIG_C(0x3af00b4cU), BSWAP_32BIG_C(0x9412b371U), BSWAP_32BIG_C(0x98d488afU),
    };
    r_rsip_func101(Param_func315_func101_007);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub030(0x14b00000U, 0x00000b7bU, 0x80e0001bU);
    r_rsip_func_sub001(0x03430181U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0017dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x3030000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func315_func100_002[] =
        {
            BSWAP_32BIG_C(0x95f80756U), BSWAP_32BIG_C(0xe7ea8af7U), BSWAP_32BIG_C(0xb98a5b53U), BSWAP_32BIG_C(
                0x009d86bbU),
        };
        r_rsip_func100(Param_func315_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_func315_func101_008[] =
            {
                BSWAP_32BIG_C(0x74af7d02U), BSWAP_32BIG_C(0x57a4d94fU), BSWAP_32BIG_C(0x5fc13c7fU), BSWAP_32BIG_C(
                    0xf023ec9eU),
            };
            r_rsip_func101(Param_func315_func101_008);

            break;
        }
        else
        {
            r_rsip_func_sub004(0x0b040184U, 0xabf7a97eU);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003151U);

            static const uint32_t Param_func315_func101_009[] =
            {
                BSWAP_32BIG_C(0x7babbb19U), BSWAP_32BIG_C(0xfa7c6ee7U), BSWAP_32BIG_C(0x5f58b388U), BSWAP_32BIG_C(
                    0x2f72e4cdU),
            };
            r_rsip_func101(Param_func315_func101_009);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x2517e7b7U);

            OFS_ADR = 104;

            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003152U);

            static const uint32_t Param_func315_func101_010[] =
            {
                BSWAP_32BIG_C(0x9d483698U), BSWAP_32BIG_C(0x6995dfc5U), BSWAP_32BIG_C(0xfe90cf50U), BSWAP_32BIG_C(
                    0xa294cda9U),
            };
            r_rsip_func101(Param_func315_func101_010);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub009(0x00003151U);

            static const uint32_t Param_func315_func101_011[] =
            {
                BSWAP_32BIG_C(0x11840851U), BSWAP_32BIG_C(0x474d096dU), BSWAP_32BIG_C(0x4a8c23e3U), BSWAP_32BIG_C(
                    0x11a359a0U),
            };
            r_rsip_func101(Param_func315_func101_011);
            r_rsip_func316();

            r_rsip_func_sub004(0x0b040184U, 0xabf7a97eU);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003156U);

            static const uint32_t Param_func315_func101_012[] =
            {
                BSWAP_32BIG_C(0x10f1557aU), BSWAP_32BIG_C(0x903a9f7bU), BSWAP_32BIG_C(0xf666d6c9U), BSWAP_32BIG_C(
                    0x0cf829a1U),
            };
            r_rsip_func101(Param_func315_func101_012);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x2517e7b7U);

            OFS_ADR = 104;

            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003157U);

            static const uint32_t Param_func315_func101_013[] =
            {
                BSWAP_32BIG_C(0xc06e683dU), BSWAP_32BIG_C(0x1b0037aeU), BSWAP_32BIG_C(0x8aaa51b7U), BSWAP_32BIG_C(
                    0xba698a98U),
            };
            r_rsip_func101(Param_func315_func101_013);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x3cc10901U);

            OFS_ADR = 208;

            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003153U);

            static const uint32_t Param_func315_func101_014[] =
            {
                BSWAP_32BIG_C(0x2ca42435U), BSWAP_32BIG_C(0x33116234U), BSWAP_32BIG_C(0x72c474f0U), BSWAP_32BIG_C(
                    0x26d24d51U),
            };
            r_rsip_func101(Param_func315_func101_014);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x0b097e1fU);

            OFS_ADR = 312;

            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003154U);

            static const uint32_t Param_func315_func101_015[] =
            {
                BSWAP_32BIG_C(0xd4802ef9U), BSWAP_32BIG_C(0x70defe49U), BSWAP_32BIG_C(0xde7dd3f6U), BSWAP_32BIG_C(
                    0x8c2631d1U),
            };
            r_rsip_func101(Param_func315_func101_015);
            r_rsip_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_func_sub001(0x00c00181U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);

            r_rsip_func_sub009(0x00003152U);

            static const uint32_t Param_func315_func101_016[] =
            {
                BSWAP_32BIG_C(0x52af7848U), BSWAP_32BIG_C(0x3dcca172U), BSWAP_32BIG_C(0xf0bff0c0U), BSWAP_32BIG_C(
                    0x821c7d0aU),
            };
            r_rsip_func101(Param_func315_func101_016);
            r_rsip_func316();

            r_rsip_func_sub004(0x0b040184U, 0x3cc10901U);

            OFS_ADR = 208;

            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003158U);

            static const uint32_t Param_func315_func101_017[] =
            {
                BSWAP_32BIG_C(0x34bd0c26U), BSWAP_32BIG_C(0x06311150U), BSWAP_32BIG_C(0xd311abceU), BSWAP_32BIG_C(
                    0x7cd100d7U),
            };
            r_rsip_func101(Param_func315_func101_017);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x0b097e1fU);

            OFS_ADR = 312;

            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);

            r_rsip_func_sub009(0x00003159U);

            static const uint32_t Param_func315_func101_018[] =
            {
                BSWAP_32BIG_C(0xcf946030U), BSWAP_32BIG_C(0x1dd2fa48U), BSWAP_32BIG_C(0xbd809c54U), BSWAP_32BIG_C(
                    0xfc374df6U),
            };
            r_rsip_func101(Param_func315_func101_018);
            r_rsip_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_func_sub001(0x00c00181U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);

            r_rsip_func_sub002(0x00000220U, 0x00000630U, 0x00000838U, 0x3030000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_func315_func100_003[] =
            {
                BSWAP_32BIG_C(0x44546b31U), BSWAP_32BIG_C(0xa46c9498U), BSWAP_32BIG_C(0x3270111eU), BSWAP_32BIG_C(
                    0xfbcc41deU),
            };
            r_rsip_func100(Param_func315_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000220U, 0x30300009U);

                r_rsip_func_sub004(0x0b040184U, 0xabf7a97eU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x00003155U);

                static const uint32_t Param_func315_func101_019[] =
                {
                    BSWAP_32BIG_C(0x3a8d485aU), BSWAP_32BIG_C(0x88b1b797U), BSWAP_32BIG_C(0xed8a6a93U), BSWAP_32BIG_C(
                        0x06e511d4U),
                };
                r_rsip_func101(Param_func315_func101_019);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x3cc10901U);

                OFS_ADR = 208;

                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x00003156U);

                static const uint32_t Param_func315_func101_020[] =
                {
                    BSWAP_32BIG_C(0x2beeb7b9U), BSWAP_32BIG_C(0xa8277d91U), BSWAP_32BIG_C(0xe15a70e1U), BSWAP_32BIG_C(
                        0x94d23ed3U),
                };
                r_rsip_func101(Param_func315_func101_020);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003151U);

                static const uint32_t Param_func315_func101_021[] =
                {
                    BSWAP_32BIG_C(0x2c6d0bbeU), BSWAP_32BIG_C(0xef1a5843U), BSWAP_32BIG_C(0x1a7b2e89U), BSWAP_32BIG_C(
                        0xfbe3a3baU),
                };
                r_rsip_func101(Param_func315_func101_021);
                r_rsip_func320();

                r_rsip_func_sub004(0x0b040184U, 0xabf7a97eU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315aU);

                static const uint32_t Param_func315_func101_022[] =
                {
                    BSWAP_32BIG_C(0xa2613314U), BSWAP_32BIG_C(0x8a1b01aeU), BSWAP_32BIG_C(0xa37b5328U), BSWAP_32BIG_C(
                        0x1aa3e3fdU),
                };
                r_rsip_func101(Param_func315_func101_022);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x2517e7b7U);

                OFS_ADR = 104;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x00003157U);

                static const uint32_t Param_func315_func101_023[] =
                {
                    BSWAP_32BIG_C(0xb4548a49U), BSWAP_32BIG_C(0x5907da65U), BSWAP_32BIG_C(0xb6380405U), BSWAP_32BIG_C(
                        0x4155e4acU),
                };
                r_rsip_func101(Param_func315_func101_023);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x0b097e1fU);

                OFS_ADR = 312;

                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x00003158U);

                static const uint32_t Param_func315_func101_024[] =
                {
                    BSWAP_32BIG_C(0x9d696929U), BSWAP_32BIG_C(0x148bb513U), BSWAP_32BIG_C(0x5a020a50U), BSWAP_32BIG_C(
                        0xd9cc5ce3U),
                };
                r_rsip_func101(Param_func315_func101_024);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003152U);

                static const uint32_t Param_func315_func101_025[] =
                {
                    BSWAP_32BIG_C(0x17fdf6baU), BSWAP_32BIG_C(0xb397d9bcU), BSWAP_32BIG_C(0x2d90e47fU), BSWAP_32BIG_C(
                        0x5c63e575U),
                };
                r_rsip_func101(Param_func315_func101_025);
                r_rsip_func320();

                r_rsip_func_sub004(0x0b040184U, 0x2517e7b7U);

                OFS_ADR = 104;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315bU);

                static const uint32_t Param_func315_func101_026[] =
                {
                    BSWAP_32BIG_C(0xf6771bc5U), BSWAP_32BIG_C(0xcbf89209U), BSWAP_32BIG_C(0x9b8dcae3U), BSWAP_32BIG_C(
                        0x8173d9a5U),
                };
                r_rsip_func101(Param_func315_func101_026);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func315_func101_027[] =
                {
                    BSWAP_32BIG_C(0x53935c43U), BSWAP_32BIG_C(0x179aff63U), BSWAP_32BIG_C(0x00963206U), BSWAP_32BIG_C(
                        0x6acd2c95U),
                };
                r_rsip_func101(Param_func315_func101_027);
            }
            else
            {
                r_rsip_func_sub002(0x00000630U, 0x00000220U, 0x00000630U, 0x3030000aU);

                r_rsip_func_sub004(0x0b040184U, 0x3cc10901U);

                OFS_ADR = 208;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315aU);

                static const uint32_t Param_func315_func101_028[] =
                {
                    BSWAP_32BIG_C(0xa4e7899fU), BSWAP_32BIG_C(0xdb6bb317U), BSWAP_32BIG_C(0x4a25a2aaU), BSWAP_32BIG_C(
                        0xaf9c9ac7U),
                };
                r_rsip_func101(Param_func315_func101_028);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xabf7a97eU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315bU);

                static const uint32_t Param_func315_func101_029[] =
                {
                    BSWAP_32BIG_C(0xe8ae3050U), BSWAP_32BIG_C(0xe6755106U), BSWAP_32BIG_C(0xfda086dbU), BSWAP_32BIG_C(
                        0x990436afU),
                };
                r_rsip_func101(Param_func315_func101_029);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003153U);

                static const uint32_t Param_func315_func101_030[] =
                {
                    BSWAP_32BIG_C(0x905aef26U), BSWAP_32BIG_C(0x7a87bae5U), BSWAP_32BIG_C(0xfd388cdcU), BSWAP_32BIG_C(
                        0x857edc25U),
                };
                r_rsip_func101(Param_func315_func101_030);
                r_rsip_func320();

                r_rsip_func_sub004(0x0b040184U, 0x3cc10901U);

                OFS_ADR = 208;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315cU);

                static const uint32_t Param_func315_func101_031[] =
                {
                    BSWAP_32BIG_C(0xca87d19eU), BSWAP_32BIG_C(0xe41a545aU), BSWAP_32BIG_C(0x22a1247fU), BSWAP_32BIG_C(
                        0xd5f6d474U),
                };
                r_rsip_func101(Param_func315_func101_031);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x0b097e1fU);

                OFS_ADR = 312;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315cU);

                static const uint32_t Param_func315_func101_032[] =
                {
                    BSWAP_32BIG_C(0xff2223ccU), BSWAP_32BIG_C(0xcd3e2be2U), BSWAP_32BIG_C(0xa4f4a591U), BSWAP_32BIG_C(
                        0x07ed2f41U),
                };
                r_rsip_func101(Param_func315_func101_032);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x2517e7b7U);

                OFS_ADR = 104;

                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315dU);

                static const uint32_t Param_func315_func101_033[] =
                {
                    BSWAP_32BIG_C(0x046767d1U), BSWAP_32BIG_C(0x0d8ee34fU), BSWAP_32BIG_C(0x79586739U), BSWAP_32BIG_C(
                        0x4e39e343U),
                };
                r_rsip_func101(Param_func315_func101_033);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003154U);

                static const uint32_t Param_func315_func101_034[] =
                {
                    BSWAP_32BIG_C(0x5d2eebc1U), BSWAP_32BIG_C(0xbd0e6b3aU), BSWAP_32BIG_C(0x98dbf124U), BSWAP_32BIG_C(
                        0xbc558b40U),
                };
                r_rsip_func101(Param_func315_func101_034);
                r_rsip_func320();

                r_rsip_func_sub004(0x0b040184U, 0x0b097e1fU);

                OFS_ADR = 312;

                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

                r_rsip_func_sub009(0x0000315dU);

                static const uint32_t Param_func315_func101_035[] =
                {
                    BSWAP_32BIG_C(0xcb533de4U), BSWAP_32BIG_C(0x97b3d497U), BSWAP_32BIG_C(0xaf8e7938U), BSWAP_32BIG_C(
                        0x3cfbf653U),
                };
                r_rsip_func101(Param_func315_func101_035);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func315_func101_036[] =
                {
                    BSWAP_32BIG_C(0x43b48e87U), BSWAP_32BIG_C(0x03d87c5dU), BSWAP_32BIG_C(0xfe7e80d9U), BSWAP_32BIG_C(
                        0xee79d9a9U),
                };
                r_rsip_func101(Param_func315_func101_036);
            }
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0xe4f152fdU);

    OFS_ADR = 416;

    r_rsip_func_sub012(0x10a00000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub009(0x0000315eU);

    static const uint32_t Param_func315_func101_037[] =
    {
        BSWAP_32BIG_C(0x1c8fbc35U), BSWAP_32BIG_C(0x38e7a44fU), BSWAP_32BIG_C(0xb31d0b48U), BSWAP_32BIG_C(0x2da76aa9U),
    };
    r_rsip_func101(Param_func315_func101_037);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);

        static const uint32_t Param_func315_func100_004[] =
        {
            BSWAP_32BIG_C(0xa3a6252eU), BSWAP_32BIG_C(0x1449b93cU), BSWAP_32BIG_C(0xdbbcca48U), BSWAP_32BIG_C(
                0xa7dba18aU),
        };
        r_rsip_func100(Param_func315_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000630U, 0x30300008U);

            r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000220U, 0x30300008U);

            WR1_PROG(REG_1600H, 0x000033c0U);

            static const uint32_t Param_func315_func101_038[] =
            {
                BSWAP_32BIG_C(0xccf74c36U), BSWAP_32BIG_C(0x848cc9d0U), BSWAP_32BIG_C(0xb0eec5ecU), BSWAP_32BIG_C(
                    0x78878d17U),
            };
            r_rsip_func101(Param_func315_func101_038);
        }
        else
        {
            static const uint32_t Param_func315_func101_039[] =
            {
                BSWAP_32BIG_C(0x83216bc6U), BSWAP_32BIG_C(0xb33de9faU), BSWAP_32BIG_C(0x63ec904bU), BSWAP_32BIG_C(
                    0xe1142364U),
            };
            r_rsip_func101(Param_func315_func101_039);

            break;
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x0b097e1fU);

    OFS_ADR = 312;

    r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);

    r_rsip_func_sub009(0x0000315fU);

    static const uint32_t Param_func315_func101_040[] =
    {
        BSWAP_32BIG_C(0xe1b595f1U), BSWAP_32BIG_C(0xef2b74c7U), BSWAP_32BIG_C(0xca63a48fU), BSWAP_32BIG_C(0x7e044a67U),
    };
    r_rsip_func101(Param_func315_func101_040);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    while (1)
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000a40U, 0x3131000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func315_func100_005[] =
        {
            BSWAP_32BIG_C(0x22d93406U), BSWAP_32BIG_C(0xc10751f6U), BSWAP_32BIG_C(0x38a43eafU), BSWAP_32BIG_C(
                0xd92bd7a9U),
        };
        r_rsip_func100(Param_func315_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000838U, 0x3131000aU);

            static const uint32_t Param_func315_func101_041[] =
            {
                BSWAP_32BIG_C(0x31bef2bcU), BSWAP_32BIG_C(0xc952b864U), BSWAP_32BIG_C(0x246fc691U), BSWAP_32BIG_C(
                    0x4970df9aU),
            };
            r_rsip_func101(Param_func315_func101_041);
        }
        else
        {
            static const uint32_t Param_func315_func101_042[] =
            {
                BSWAP_32BIG_C(0x98f0fec1U), BSWAP_32BIG_C(0xbbe512beU), BSWAP_32BIG_C(0xebcd27abU), BSWAP_32BIG_C(
                    0x349c3b0bU),
            };
            r_rsip_func101(Param_func315_func101_042);

            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);

    static const uint32_t Param_func315_func100_006[] =
    {
        BSWAP_32BIG_C(0xd7f3ac7bU), BSWAP_32BIG_C(0xa0296770U), BSWAP_32BIG_C(0xf4b9fb24U), BSWAP_32BIG_C(0xb5e75c5bU),
    };
    r_rsip_func100(Param_func315_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000838U, 0x3131000aU);

        static const uint32_t Param_func315_func101_043[] =
        {
            BSWAP_32BIG_C(0x27f0831eU), BSWAP_32BIG_C(0xfd81d665U), BSWAP_32BIG_C(0x625e1d4dU), BSWAP_32BIG_C(
                0x20721045U),
        };
        r_rsip_func101(Param_func315_func101_043);
    }
    else
    {
        static const uint32_t Param_func315_func101_044[] =
        {
            BSWAP_32BIG_C(0x49975d70U), BSWAP_32BIG_C(0xed284096U), BSWAP_32BIG_C(0xc3aed3caU), BSWAP_32BIG_C(
                0x5ca8867eU),
        };
        r_rsip_func101(Param_func315_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
