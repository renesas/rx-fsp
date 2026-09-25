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

void r_rsip_func052 (void)
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

        static const uint32_t Param_func052_func100_001[] =
        {
            BSWAP_32BIG_C(0xe3e0a20aU), BSWAP_32BIG_C(0x4e301318U), BSWAP_32BIG_C(0x9e9b04d3U), BSWAP_32BIG_C(
                0xe6d373f1U),
        };
        r_rsip_func100(Param_func052_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x1010000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x1010000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            static const uint32_t Param_func052_func101_001[] =
            {
                BSWAP_32BIG_C(0x1df8a87eU), BSWAP_32BIG_C(0x2eb62af5U), BSWAP_32BIG_C(0x628fe639U), BSWAP_32BIG_C(
                    0x70862efcU),
            };
            r_rsip_func101(Param_func052_func101_001);
        }
        else
        {
            static const uint32_t Param_func052_func101_002[] =
            {
                BSWAP_32BIG_C(0x1871b4ccU), BSWAP_32BIG_C(0x02552972U), BSWAP_32BIG_C(0x1f3a7aafU), BSWAP_32BIG_C(
                    0x3a508489U),
            };
            r_rsip_func101(Param_func052_func101_002);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_func_sub001(0x00c00091U);

    r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

    OFS_ADR = 40;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub009(0x00000521U);

    static const uint32_t Param_func052_func101_003[] =
    {
        BSWAP_32BIG_C(0x685c0247U), BSWAP_32BIG_C(0xc6fdb94aU), BSWAP_32BIG_C(0xa9f7f0cdU), BSWAP_32BIG_C(0x9f96cc4cU),
    };
    r_rsip_func101(Param_func052_func101_003);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

    OFS_ADR = 80;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub009(0x00000522U);

    static const uint32_t Param_func052_func101_004[] =
    {
        BSWAP_32BIG_C(0x27ca5ce1U), BSWAP_32BIG_C(0x7fe45b48U), BSWAP_32BIG_C(0x85e04006U), BSWAP_32BIG_C(0xa1bee3c0U),
    };
    r_rsip_func101(Param_func052_func101_004);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

    OFS_ADR = 0;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub009(0x00000523U);

    static const uint32_t Param_func052_func101_005[] =
    {
        BSWAP_32BIG_C(0xa8ee172fU), BSWAP_32BIG_C(0x8a7bf57eU), BSWAP_32BIG_C(0x983618bbU), BSWAP_32BIG_C(0xcbfabfb9U),
    };
    r_rsip_func101(Param_func052_func101_005);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

    OFS_ADR = 120;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub009(0x00000524U);

    static const uint32_t Param_func052_func101_006[] =
    {
        BSWAP_32BIG_C(0xfc0cecd8U), BSWAP_32BIG_C(0x35668d9eU), BSWAP_32BIG_C(0xc3fd4abdU), BSWAP_32BIG_C(0x73194f94U),
    };
    r_rsip_func101(Param_func052_func101_006);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x093b7d04U);

    OFS_ADR = 160;

    r_rsip_func_sub012(0x11a00000U, 0x0000b400U, 0x00000020U);

    r_rsip_func_sub009(0x00000525U);

    static const uint32_t Param_func052_func101_007[] =
    {
        BSWAP_32BIG_C(0xaf0c73c7U), BSWAP_32BIG_C(0xa7a632d6U), BSWAP_32BIG_C(0x613df2dbU), BSWAP_32BIG_C(0x88b011e6U),
    };
    r_rsip_func101(Param_func052_func101_007);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub030(0x15b00000U, 0x00000b7bU, 0x80a0001bU);
    r_rsip_func_sub001(0x03430081U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0007dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func052_func100_002[] =
        {
            BSWAP_32BIG_C(0x87b374a3U), BSWAP_32BIG_C(0x8dde2bceU), BSWAP_32BIG_C(0x59a24760U), BSWAP_32BIG_C(
                0x86733dc1U),
        };
        r_rsip_func100(Param_func052_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_func052_func101_008[] =
            {
                BSWAP_32BIG_C(0xcf363040U), BSWAP_32BIG_C(0x80d00eedU), BSWAP_32BIG_C(0x0305b032U), BSWAP_32BIG_C(
                    0x88ed261eU),
            };
            r_rsip_func101(Param_func052_func101_008);

            break;
        }
        else
        {
            r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000521U);

            static const uint32_t Param_func052_func101_009[] =
            {
                BSWAP_32BIG_C(0xf5400148U), BSWAP_32BIG_C(0xd50bbeebU), BSWAP_32BIG_C(0xb0ecb934U), BSWAP_32BIG_C(
                    0xc673abdaU),
            };
            r_rsip_func101(Param_func052_func101_009);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

            OFS_ADR = 40;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000522U);

            static const uint32_t Param_func052_func101_010[] =
            {
                BSWAP_32BIG_C(0xe08a79c5U), BSWAP_32BIG_C(0xa8284ae3U), BSWAP_32BIG_C(0x0961e3dbU), BSWAP_32BIG_C(
                    0x12abbc63U),
            };
            r_rsip_func101(Param_func052_func101_010);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub009(0x00000521U);

            static const uint32_t Param_func052_func101_011[] =
            {
                BSWAP_32BIG_C(0x75bdc65bU), BSWAP_32BIG_C(0xf82bb938U), BSWAP_32BIG_C(0x6a13e420U), BSWAP_32BIG_C(
                    0x1f2296b6U),
            };
            r_rsip_func101(Param_func052_func101_011);
            r_rsip_func053();

            r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000526U);

            static const uint32_t Param_func052_func101_012[] =
            {
                BSWAP_32BIG_C(0x13c7258eU), BSWAP_32BIG_C(0x5c17574eU), BSWAP_32BIG_C(0x78fb6903U), BSWAP_32BIG_C(
                    0x23243121U),
            };
            r_rsip_func101(Param_func052_func101_012);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

            OFS_ADR = 40;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000527U);

            static const uint32_t Param_func052_func101_013[] =
            {
                BSWAP_32BIG_C(0xb315599eU), BSWAP_32BIG_C(0x4294ca29U), BSWAP_32BIG_C(0x70bd64b5U), BSWAP_32BIG_C(
                    0x20a119abU),
            };
            r_rsip_func101(Param_func052_func101_013);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

            OFS_ADR = 80;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000523U);

            static const uint32_t Param_func052_func101_014[] =
            {
                BSWAP_32BIG_C(0x70e053b4U), BSWAP_32BIG_C(0xf1f9867bU), BSWAP_32BIG_C(0x8844074bU), BSWAP_32BIG_C(
                    0xc386eff1U),
            };
            r_rsip_func101(Param_func052_func101_014);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

            OFS_ADR = 120;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000524U);

            static const uint32_t Param_func052_func101_015[] =
            {
                BSWAP_32BIG_C(0xf3153c8eU), BSWAP_32BIG_C(0x4e45912dU), BSWAP_32BIG_C(0x7e73341aU), BSWAP_32BIG_C(
                    0xe4d27defU),
            };
            r_rsip_func101(Param_func052_func101_015);
            r_rsip_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_func_sub001(0x00c00081U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);

            r_rsip_func_sub009(0x00000522U);

            static const uint32_t Param_func052_func101_016[] =
            {
                BSWAP_32BIG_C(0x6a78080dU), BSWAP_32BIG_C(0xfd8cf430U), BSWAP_32BIG_C(0xaa202c13U), BSWAP_32BIG_C(
                    0x086ca423U),
            };
            r_rsip_func101(Param_func052_func101_016);
            r_rsip_func053();

            r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

            OFS_ADR = 80;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000528U);

            static const uint32_t Param_func052_func101_017[] =
            {
                BSWAP_32BIG_C(0x1ac9ac5eU), BSWAP_32BIG_C(0xbf84fdfcU), BSWAP_32BIG_C(0x91a90a83U), BSWAP_32BIG_C(
                    0xa8ba6845U),
            };
            r_rsip_func101(Param_func052_func101_017);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

            OFS_ADR = 120;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub009(0x00000529U);

            static const uint32_t Param_func052_func101_018[] =
            {
                BSWAP_32BIG_C(0x4804fa61U), BSWAP_32BIG_C(0xf98673ceU), BSWAP_32BIG_C(0xf94beb37U), BSWAP_32BIG_C(
                    0x8b84ea9fU),
            };
            r_rsip_func101(Param_func052_func101_018);
            r_rsip_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_func_sub001(0x00c00081U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);

            r_rsip_func_sub002(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_func052_func100_003[] =
            {
                BSWAP_32BIG_C(0x134b66b8U), BSWAP_32BIG_C(0xe1f2560fU), BSWAP_32BIG_C(0x810727ffU), BSWAP_32BIG_C(
                    0x3ce1dcc0U),
            };
            r_rsip_func100(Param_func052_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);

                r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x00000525U);

                static const uint32_t Param_func052_func101_019[] =
                {
                    BSWAP_32BIG_C(0x605c6001U), BSWAP_32BIG_C(0x2afc6514U), BSWAP_32BIG_C(0xc65efcf0U), BSWAP_32BIG_C(
                        0xac704a2aU),
                };
                r_rsip_func101(Param_func052_func101_019);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

                OFS_ADR = 80;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x00000526U);

                static const uint32_t Param_func052_func101_020[] =
                {
                    BSWAP_32BIG_C(0x26a45a86U), BSWAP_32BIG_C(0x95e195f7U), BSWAP_32BIG_C(0x2f476f73U), BSWAP_32BIG_C(
                        0x9ac7a043U),
                };
                r_rsip_func101(Param_func052_func101_020);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000521U);

                static const uint32_t Param_func052_func101_021[] =
                {
                    BSWAP_32BIG_C(0x05fbced9U), BSWAP_32BIG_C(0xbaef8465U), BSWAP_32BIG_C(0x01983c13U), BSWAP_32BIG_C(
                        0x3beef9e6U),
                };
                r_rsip_func101(Param_func052_func101_021);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052aU);

                static const uint32_t Param_func052_func101_022[] =
                {
                    BSWAP_32BIG_C(0x86dbc9e9U), BSWAP_32BIG_C(0x7670ccf2U), BSWAP_32BIG_C(0x7aff8677U), BSWAP_32BIG_C(
                        0x9caaf700U),
                };
                r_rsip_func101(Param_func052_func101_022);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

                OFS_ADR = 40;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x00000527U);

                static const uint32_t Param_func052_func101_023[] =
                {
                    BSWAP_32BIG_C(0xf4ddc2ebU), BSWAP_32BIG_C(0x6a047e88U), BSWAP_32BIG_C(0x4b1dcdf4U), BSWAP_32BIG_C(
                        0x7c704652U),
                };
                r_rsip_func101(Param_func052_func101_023);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

                OFS_ADR = 120;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x00000528U);

                static const uint32_t Param_func052_func101_024[] =
                {
                    BSWAP_32BIG_C(0xcca562f9U), BSWAP_32BIG_C(0x84d63f89U), BSWAP_32BIG_C(0x42c2bcfeU), BSWAP_32BIG_C(
                        0x689aacd3U),
                };
                r_rsip_func101(Param_func052_func101_024);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000522U);

                static const uint32_t Param_func052_func101_025[] =
                {
                    BSWAP_32BIG_C(0x50f2f63fU), BSWAP_32BIG_C(0xdbe8dcc0U), BSWAP_32BIG_C(0x6d59c2b2U), BSWAP_32BIG_C(
                        0xa6f2ebadU),
                };
                r_rsip_func101(Param_func052_func101_025);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

                OFS_ADR = 40;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052bU);

                static const uint32_t Param_func052_func101_026[] =
                {
                    BSWAP_32BIG_C(0x9f1cba28U), BSWAP_32BIG_C(0x2cf0ce6aU), BSWAP_32BIG_C(0xc7d2d64aU), BSWAP_32BIG_C(
                        0x1aa560d5U),
                };
                r_rsip_func101(Param_func052_func101_026);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func052_func101_027[] =
                {
                    BSWAP_32BIG_C(0xf3275b32U), BSWAP_32BIG_C(0xa89d1e4dU), BSWAP_32BIG_C(0xf3f675c9U), BSWAP_32BIG_C(
                        0xe22662c6U),
                };
                r_rsip_func101(Param_func052_func101_027);
            }
            else
            {
                r_rsip_func_sub002(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);

                r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

                OFS_ADR = 80;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052aU);

                static const uint32_t Param_func052_func101_028[] =
                {
                    BSWAP_32BIG_C(0xa1d5119cU), BSWAP_32BIG_C(0xa9b15578U), BSWAP_32BIG_C(0x8392621dU), BSWAP_32BIG_C(
                        0x3b549844U),
                };
                r_rsip_func101(Param_func052_func101_028);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052bU);

                static const uint32_t Param_func052_func101_029[] =
                {
                    BSWAP_32BIG_C(0x7dee9527U), BSWAP_32BIG_C(0xb386690aU), BSWAP_32BIG_C(0x1af132cfU), BSWAP_32BIG_C(
                        0x44de5fa0U),
                };
                r_rsip_func101(Param_func052_func101_029);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000523U);

                static const uint32_t Param_func052_func101_030[] =
                {
                    BSWAP_32BIG_C(0xef970723U), BSWAP_32BIG_C(0xbe0663a0U), BSWAP_32BIG_C(0x24be3835U), BSWAP_32BIG_C(
                        0x0e09fb41U),
                };
                r_rsip_func101(Param_func052_func101_030);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

                OFS_ADR = 80;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052cU);

                static const uint32_t Param_func052_func101_031[] =
                {
                    BSWAP_32BIG_C(0x1c045f9fU), BSWAP_32BIG_C(0x4156d9a5U), BSWAP_32BIG_C(0xabef731dU), BSWAP_32BIG_C(
                        0xd15314e2U),
                };
                r_rsip_func101(Param_func052_func101_031);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

                OFS_ADR = 120;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052cU);

                static const uint32_t Param_func052_func101_032[] =
                {
                    BSWAP_32BIG_C(0xaf7e1bcdU), BSWAP_32BIG_C(0x872eaf89U), BSWAP_32BIG_C(0x4b68ff03U), BSWAP_32BIG_C(
                        0xe29e4546U),
                };
                r_rsip_func101(Param_func052_func101_032);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

                OFS_ADR = 40;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052dU);

                static const uint32_t Param_func052_func101_033[] =
                {
                    BSWAP_32BIG_C(0x8fa5800dU), BSWAP_32BIG_C(0xaa1c9d71U), BSWAP_32BIG_C(0x6ebeadaeU), BSWAP_32BIG_C(
                        0x49ab3997U),
                };
                r_rsip_func101(Param_func052_func101_033);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000524U);

                static const uint32_t Param_func052_func101_034[] =
                {
                    BSWAP_32BIG_C(0x15eb895eU), BSWAP_32BIG_C(0xb5f5cde9U), BSWAP_32BIG_C(0x74be2bf2U), BSWAP_32BIG_C(
                        0x80ab700dU),
                };
                r_rsip_func101(Param_func052_func101_034);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

                OFS_ADR = 120;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub009(0x0000052dU);

                static const uint32_t Param_func052_func101_035[] =
                {
                    BSWAP_32BIG_C(0x370c00f1U), BSWAP_32BIG_C(0x0c867057U), BSWAP_32BIG_C(0x1872d11bU), BSWAP_32BIG_C(
                        0x994801daU),
                };
                r_rsip_func101(Param_func052_func101_035);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func052_func101_036[] =
                {
                    BSWAP_32BIG_C(0xc0799c92U), BSWAP_32BIG_C(0x8165ebfbU), BSWAP_32BIG_C(0xe59e35cfU), BSWAP_32BIG_C(
                        0xe0fe90b3U),
                };
                r_rsip_func101(Param_func052_func101_036);
            }
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x093b7d04U);

    OFS_ADR = 160;

    r_rsip_func_sub012(0x11a00000U, 0x0000b400U, 0x00000020U);

    r_rsip_func_sub009(0x0000052eU);

    static const uint32_t Param_func052_func101_037[] =
    {
        BSWAP_32BIG_C(0xa5e474e3U), BSWAP_32BIG_C(0x8aa209a2U), BSWAP_32BIG_C(0x9f127798U), BSWAP_32BIG_C(0x51cd9ae9U),
    };
    r_rsip_func101(Param_func052_func101_037);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);

        static const uint32_t Param_func052_func100_004[] =
        {
            BSWAP_32BIG_C(0x2df4aa7fU), BSWAP_32BIG_C(0x1fc3f0ebU), BSWAP_32BIG_C(0x0e0cb1aeU), BSWAP_32BIG_C(
                0x984660dfU),
        };
        r_rsip_func100(Param_func052_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);

            r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);

            WR1_PROG(REG_1600H, 0x000033c0U);

            static const uint32_t Param_func052_func101_038[] =
            {
                BSWAP_32BIG_C(0x2094e6c1U), BSWAP_32BIG_C(0x8c1f4b2bU), BSWAP_32BIG_C(0xbd94413bU), BSWAP_32BIG_C(
                    0x59886761U),
            };
            r_rsip_func101(Param_func052_func101_038);
        }
        else
        {
            static const uint32_t Param_func052_func101_039[] =
            {
                BSWAP_32BIG_C(0x396c93b8U), BSWAP_32BIG_C(0x03636fb5U), BSWAP_32BIG_C(0x1346c9b1U), BSWAP_32BIG_C(
                    0x5f513d06U),
            };
            r_rsip_func101(Param_func052_func101_039);

            break;
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

    OFS_ADR = 120;

    r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub009(0x0000052fU);

    static const uint32_t Param_func052_func101_040[] =
    {
        BSWAP_32BIG_C(0x422efbb6U), BSWAP_32BIG_C(0x4442058aU), BSWAP_32BIG_C(0x74bf08d3U), BSWAP_32BIG_C(0x959fccc3U),
    };
    r_rsip_func101(Param_func052_func101_040);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    while (1)
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000a40U, 0x1111000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func052_func100_005[] =
        {
            BSWAP_32BIG_C(0xf211484bU), BSWAP_32BIG_C(0x81f2894eU), BSWAP_32BIG_C(0x1691cf03U), BSWAP_32BIG_C(
                0x0aad6381U),
        };
        r_rsip_func100(Param_func052_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);

            static const uint32_t Param_func052_func101_041[] =
            {
                BSWAP_32BIG_C(0x6dd2a116U), BSWAP_32BIG_C(0x98a5eedcU), BSWAP_32BIG_C(0x68fdf919U), BSWAP_32BIG_C(
                    0x4281d9d3U),
            };
            r_rsip_func101(Param_func052_func101_041);
        }
        else
        {
            static const uint32_t Param_func052_func101_042[] =
            {
                BSWAP_32BIG_C(0x148a4159U), BSWAP_32BIG_C(0xabbb3890U), BSWAP_32BIG_C(0x9d379326U), BSWAP_32BIG_C(
                    0xc2d4a9efU),
            };
            r_rsip_func101(Param_func052_func101_042);

            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);

    static const uint32_t Param_func052_func100_006[] =
    {
        BSWAP_32BIG_C(0xbd56431bU), BSWAP_32BIG_C(0x3aca836aU), BSWAP_32BIG_C(0xdb56b190U), BSWAP_32BIG_C(0xb49066b9U),
    };
    r_rsip_func100(Param_func052_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);

        static const uint32_t Param_func052_func101_043[] =
        {
            BSWAP_32BIG_C(0xeeb445eaU), BSWAP_32BIG_C(0xf726f4baU), BSWAP_32BIG_C(0x65ab4f43U), BSWAP_32BIG_C(
                0x49601f23U),
        };
        r_rsip_func101(Param_func052_func101_043);
    }
    else
    {
        static const uint32_t Param_func052_func101_044[] =
        {
            BSWAP_32BIG_C(0xa08eed8dU), BSWAP_32BIG_C(0xcf42c0ddU), BSWAP_32BIG_C(0x4c7fc058U), BSWAP_32BIG_C(
                0x890ba92dU),
        };
        r_rsip_func101(Param_func052_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
