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

void r_rsip_func054 (void)
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

        static const uint32_t Param_func054_func100_001[] =
        {
            BSWAP_32BIG_C(0x1b97f291U), BSWAP_32BIG_C(0x784452e4U), BSWAP_32BIG_C(0x0eefb714U), BSWAP_32BIG_C(
                0xd8d5531dU),
        };
        r_rsip_func100(Param_func054_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x2020000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x2020000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            static const uint32_t Param_func054_func101_001[] =
            {
                BSWAP_32BIG_C(0x0c01e51bU), BSWAP_32BIG_C(0x2ec979faU), BSWAP_32BIG_C(0xe3a91152U), BSWAP_32BIG_C(
                    0xc7b332d5U),
            };
            r_rsip_func101(Param_func054_func101_001);
        }
        else
        {
            static const uint32_t Param_func054_func101_002[] =
            {
                BSWAP_32BIG_C(0x5b49ab75U), BSWAP_32BIG_C(0x4bb8fdd8U), BSWAP_32BIG_C(0x1f489c07U), BSWAP_32BIG_C(
                    0x7ac70223U),
            };
            r_rsip_func101(Param_func054_func101_002);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_func_sub001(0x00c00111U);

    r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

    OFS_ADR = 72;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub009(0x00000541U);

    static const uint32_t Param_func054_func101_003[] =
    {
        BSWAP_32BIG_C(0xceed8b34U), BSWAP_32BIG_C(0x8e14602eU), BSWAP_32BIG_C(0xd790ce68U), BSWAP_32BIG_C(0xfb49d500U),
    };
    r_rsip_func101(Param_func054_func101_003);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x94174653U);

    OFS_ADR = 144;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub009(0x00000542U);

    static const uint32_t Param_func054_func101_004[] =
    {
        BSWAP_32BIG_C(0x9d98ab69U), BSWAP_32BIG_C(0x6c94adecU), BSWAP_32BIG_C(0xbf2ab3c0U), BSWAP_32BIG_C(0xa7a3b04eU),
    };
    r_rsip_func101(Param_func054_func101_004);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

    OFS_ADR = 0;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub009(0x00000543U);

    static const uint32_t Param_func054_func101_005[] =
    {
        BSWAP_32BIG_C(0xe34a36e6U), BSWAP_32BIG_C(0xdab6776bU), BSWAP_32BIG_C(0xe975378aU), BSWAP_32BIG_C(0xe0fe87b2U),
    };
    r_rsip_func101(Param_func054_func101_005);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

    OFS_ADR = 216;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub009(0x00000544U);

    static const uint32_t Param_func054_func101_006[] =
    {
        BSWAP_32BIG_C(0xf917044aU), BSWAP_32BIG_C(0x05c4ba4aU), BSWAP_32BIG_C(0x28ff4e60U), BSWAP_32BIG_C(0x516dbdbeU),
    };
    r_rsip_func101(Param_func054_func101_006);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x9bee78e8U);

    OFS_ADR = 288;

    r_rsip_func_sub012(0x11200000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub009(0x00000545U);

    static const uint32_t Param_func054_func101_007[] =
    {
        BSWAP_32BIG_C(0x6c938b1eU), BSWAP_32BIG_C(0x0f0ceef0U), BSWAP_32BIG_C(0xfc05f590U), BSWAP_32BIG_C(0x7369c8ffU),
    };
    r_rsip_func101(Param_func054_func101_007);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub030(0x15300000U, 0x00000b7bU, 0x80c0001bU);
    r_rsip_func_sub001(0x03430101U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func054_func100_002[] =
        {
            BSWAP_32BIG_C(0xf86aa2e3U), BSWAP_32BIG_C(0x66a073c9U), BSWAP_32BIG_C(0x515c1ca3U), BSWAP_32BIG_C(
                0x7ea76eafU),
        };
        r_rsip_func100(Param_func054_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_func054_func101_008[] =
            {
                BSWAP_32BIG_C(0x240bc8c4U), BSWAP_32BIG_C(0xd8e7e12aU), BSWAP_32BIG_C(0x68d2985cU), BSWAP_32BIG_C(
                    0xd3c23728U),
            };
            r_rsip_func101(Param_func054_func101_008);

            break;
        }
        else
        {
            r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000541U);

            static const uint32_t Param_func054_func101_009[] =
            {
                BSWAP_32BIG_C(0x71698c32U), BSWAP_32BIG_C(0x5602104dU), BSWAP_32BIG_C(0xbca3474dU), BSWAP_32BIG_C(
                    0xebeaa67dU),
            };
            r_rsip_func101(Param_func054_func101_009);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

            OFS_ADR = 72;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000542U);

            static const uint32_t Param_func054_func101_010[] =
            {
                BSWAP_32BIG_C(0xe3f9f07eU), BSWAP_32BIG_C(0xec50f86eU), BSWAP_32BIG_C(0x92094378U), BSWAP_32BIG_C(
                    0x1ce17bfbU),
            };
            r_rsip_func101(Param_func054_func101_010);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub009(0x00000541U);

            static const uint32_t Param_func054_func101_011[] =
            {
                BSWAP_32BIG_C(0xb0ae10caU), BSWAP_32BIG_C(0x01cef74fU), BSWAP_32BIG_C(0x7fa454efU), BSWAP_32BIG_C(
                    0x2f8fc74fU),
            };
            r_rsip_func101(Param_func054_func101_011);
            r_rsip_func055();

            r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000546U);

            static const uint32_t Param_func054_func101_012[] =
            {
                BSWAP_32BIG_C(0xe161a44eU), BSWAP_32BIG_C(0x7245821bU), BSWAP_32BIG_C(0xa2d8e7d1U), BSWAP_32BIG_C(
                    0x93cb09c9U),
            };
            r_rsip_func101(Param_func054_func101_012);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

            OFS_ADR = 72;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000547U);

            static const uint32_t Param_func054_func101_013[] =
            {
                BSWAP_32BIG_C(0x249fa0cfU), BSWAP_32BIG_C(0xaf4aabafU), BSWAP_32BIG_C(0x6af7184fU), BSWAP_32BIG_C(
                    0x47f15ef3U),
            };
            r_rsip_func101(Param_func054_func101_013);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x94174653U);

            OFS_ADR = 144;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000543U);

            static const uint32_t Param_func054_func101_014[] =
            {
                BSWAP_32BIG_C(0x4cb0e977U), BSWAP_32BIG_C(0xf2316960U), BSWAP_32BIG_C(0xaf818b27U), BSWAP_32BIG_C(
                    0x58cc8e64U),
            };
            r_rsip_func101(Param_func054_func101_014);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

            OFS_ADR = 216;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000544U);

            static const uint32_t Param_func054_func101_015[] =
            {
                BSWAP_32BIG_C(0xa1c91726U), BSWAP_32BIG_C(0x1c32dd44U), BSWAP_32BIG_C(0x88fc4964U), BSWAP_32BIG_C(
                    0xecc7b74eU),
            };
            r_rsip_func101(Param_func054_func101_015);
            r_rsip_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_func_sub001(0x00c00101U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);

            r_rsip_func_sub009(0x00000542U);

            static const uint32_t Param_func054_func101_016[] =
            {
                BSWAP_32BIG_C(0x07aa74c0U), BSWAP_32BIG_C(0x697b07f9U), BSWAP_32BIG_C(0x0ff34d1cU), BSWAP_32BIG_C(
                    0x05fda5a4U),
            };
            r_rsip_func101(Param_func054_func101_016);
            r_rsip_func055();

            r_rsip_func_sub004(0x0b040184U, 0x94174653U);

            OFS_ADR = 144;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000548U);

            static const uint32_t Param_func054_func101_017[] =
            {
                BSWAP_32BIG_C(0x0338b041U), BSWAP_32BIG_C(0x1488bbb0U), BSWAP_32BIG_C(0xbf944316U), BSWAP_32BIG_C(
                    0x96289c9dU),
            };
            r_rsip_func101(Param_func054_func101_017);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

            OFS_ADR = 216;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub009(0x00000549U);

            static const uint32_t Param_func054_func101_018[] =
            {
                BSWAP_32BIG_C(0xfad62499U), BSWAP_32BIG_C(0xc9000509U), BSWAP_32BIG_C(0x33a08eecU), BSWAP_32BIG_C(
                    0x6e191e7bU),
            };
            r_rsip_func101(Param_func054_func101_018);
            r_rsip_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_func_sub001(0x00c00101U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);

            r_rsip_func_sub002(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_func054_func100_003[] =
            {
                BSWAP_32BIG_C(0x3301775cU), BSWAP_32BIG_C(0xbcde6c44U), BSWAP_32BIG_C(0xf447052dU), BSWAP_32BIG_C(
                    0x94b8e4daU),
            };
            r_rsip_func100(Param_func054_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);

                r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x00000545U);

                static const uint32_t Param_func054_func101_019[] =
                {
                    BSWAP_32BIG_C(0xaa81a95fU), BSWAP_32BIG_C(0xd98c89e7U), BSWAP_32BIG_C(0x453547efU), BSWAP_32BIG_C(
                        0xed933704U),
                };
                r_rsip_func101(Param_func054_func101_019);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x94174653U);

                OFS_ADR = 144;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x00000546U);

                static const uint32_t Param_func054_func101_020[] =
                {
                    BSWAP_32BIG_C(0x70e9d946U), BSWAP_32BIG_C(0x39a3a6c0U), BSWAP_32BIG_C(0x474a1027U), BSWAP_32BIG_C(
                        0xc7a69920U),
                };
                r_rsip_func101(Param_func054_func101_020);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000541U);

                static const uint32_t Param_func054_func101_021[] =
                {
                    BSWAP_32BIG_C(0xa8775986U), BSWAP_32BIG_C(0xa2733b36U), BSWAP_32BIG_C(0x88d3a137U), BSWAP_32BIG_C(
                        0x6be5994aU),
                };
                r_rsip_func101(Param_func054_func101_021);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054aU);

                static const uint32_t Param_func054_func101_022[] =
                {
                    BSWAP_32BIG_C(0xef491d6cU), BSWAP_32BIG_C(0x026bf08dU), BSWAP_32BIG_C(0x6ac3c094U), BSWAP_32BIG_C(
                        0x0b49df94U),
                };
                r_rsip_func101(Param_func054_func101_022);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

                OFS_ADR = 72;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x00000547U);

                static const uint32_t Param_func054_func101_023[] =
                {
                    BSWAP_32BIG_C(0x00adedd0U), BSWAP_32BIG_C(0x6390cf1fU), BSWAP_32BIG_C(0x156fd32aU), BSWAP_32BIG_C(
                        0x394cd180U),
                };
                r_rsip_func101(Param_func054_func101_023);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

                OFS_ADR = 216;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x00000548U);

                static const uint32_t Param_func054_func101_024[] =
                {
                    BSWAP_32BIG_C(0x2dca6bc7U), BSWAP_32BIG_C(0xf141d35dU), BSWAP_32BIG_C(0x6fb98b35U), BSWAP_32BIG_C(
                        0xca1efd10U),
                };
                r_rsip_func101(Param_func054_func101_024);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000542U);

                static const uint32_t Param_func054_func101_025[] =
                {
                    BSWAP_32BIG_C(0x099a66c6U), BSWAP_32BIG_C(0x28643d61U), BSWAP_32BIG_C(0x82616ee5U), BSWAP_32BIG_C(
                        0x3a42c33aU),
                };
                r_rsip_func101(Param_func054_func101_025);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

                OFS_ADR = 72;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054bU);

                static const uint32_t Param_func054_func101_026[] =
                {
                    BSWAP_32BIG_C(0x66db5c64U), BSWAP_32BIG_C(0x84b9ed04U), BSWAP_32BIG_C(0x74b86df0U), BSWAP_32BIG_C(
                        0xca657c00U),
                };
                r_rsip_func101(Param_func054_func101_026);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func054_func101_027[] =
                {
                    BSWAP_32BIG_C(0x33ef6d41U), BSWAP_32BIG_C(0x7bc51fbaU), BSWAP_32BIG_C(0x59664b17U), BSWAP_32BIG_C(
                        0x29e8c57cU),
                };
                r_rsip_func101(Param_func054_func101_027);
            }
            else
            {
                r_rsip_func_sub002(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);

                r_rsip_func_sub004(0x0b040184U, 0x94174653U);

                OFS_ADR = 144;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054aU);

                static const uint32_t Param_func054_func101_028[] =
                {
                    BSWAP_32BIG_C(0x6bd347f3U), BSWAP_32BIG_C(0x7b16ff3aU), BSWAP_32BIG_C(0x7f48c1e3U), BSWAP_32BIG_C(
                        0xd0b2e973U),
                };
                r_rsip_func101(Param_func054_func101_028);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054bU);

                static const uint32_t Param_func054_func101_029[] =
                {
                    BSWAP_32BIG_C(0x2b6d827dU), BSWAP_32BIG_C(0xb1468ac5U), BSWAP_32BIG_C(0xd1eb2be4U), BSWAP_32BIG_C(
                        0xa38041ebU),
                };
                r_rsip_func101(Param_func054_func101_029);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000543U);

                static const uint32_t Param_func054_func101_030[] =
                {
                    BSWAP_32BIG_C(0x815b4748U), BSWAP_32BIG_C(0x7bdbed9fU), BSWAP_32BIG_C(0x048cfddfU), BSWAP_32BIG_C(
                        0xacb8bbb4U),
                };
                r_rsip_func101(Param_func054_func101_030);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0x94174653U);

                OFS_ADR = 144;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054cU);

                static const uint32_t Param_func054_func101_031[] =
                {
                    BSWAP_32BIG_C(0x72160266U), BSWAP_32BIG_C(0xa5fd1e03U), BSWAP_32BIG_C(0x89c1ed8cU), BSWAP_32BIG_C(
                        0xee8d3a0fU),
                };
                r_rsip_func101(Param_func054_func101_031);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

                OFS_ADR = 216;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054cU);

                static const uint32_t Param_func054_func101_032[] =
                {
                    BSWAP_32BIG_C(0xaf561e57U), BSWAP_32BIG_C(0x47684b17U), BSWAP_32BIG_C(0x01a4aab3U), BSWAP_32BIG_C(
                        0x5e97a6c0U),
                };
                r_rsip_func101(Param_func054_func101_032);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

                OFS_ADR = 72;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054dU);

                static const uint32_t Param_func054_func101_033[] =
                {
                    BSWAP_32BIG_C(0x2a70e871U), BSWAP_32BIG_C(0xa89b692bU), BSWAP_32BIG_C(0x0afa528eU), BSWAP_32BIG_C(
                        0xcd0a2e73U),
                };
                r_rsip_func101(Param_func054_func101_033);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00000544U);

                static const uint32_t Param_func054_func101_034[] =
                {
                    BSWAP_32BIG_C(0x8be262cbU), BSWAP_32BIG_C(0x50b416eaU), BSWAP_32BIG_C(0x1658b1a0U), BSWAP_32BIG_C(
                        0x087ccfb3U),
                };
                r_rsip_func101(Param_func054_func101_034);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

                OFS_ADR = 216;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub009(0x0000054dU);

                static const uint32_t Param_func054_func101_035[] =
                {
                    BSWAP_32BIG_C(0x00d48297U), BSWAP_32BIG_C(0x44e4506bU), BSWAP_32BIG_C(0x9bc10ec3U), BSWAP_32BIG_C(
                        0x608e15e0U),
                };
                r_rsip_func101(Param_func054_func101_035);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func054_func101_036[] =
                {
                    BSWAP_32BIG_C(0x6ffaae38U), BSWAP_32BIG_C(0x9cd0e837U), BSWAP_32BIG_C(0x33989522U), BSWAP_32BIG_C(
                        0xc0516ea9U),
                };
                r_rsip_func101(Param_func054_func101_036);
            }
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x9bee78e8U);

    OFS_ADR = 288;

    r_rsip_func_sub012(0x11200000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub009(0x0000054eU);

    static const uint32_t Param_func054_func101_037[] =
    {
        BSWAP_32BIG_C(0x833f6705U), BSWAP_32BIG_C(0xceacbd48U), BSWAP_32BIG_C(0x4aab5fa8U), BSWAP_32BIG_C(0xb4d5dbeeU),
    };
    r_rsip_func101(Param_func054_func101_037);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);

        static const uint32_t Param_func054_func100_004[] =
        {
            BSWAP_32BIG_C(0xb4bb7694U), BSWAP_32BIG_C(0xdfd4b639U), BSWAP_32BIG_C(0x566b44f0U), BSWAP_32BIG_C(
                0x2d9834d3U),
        };
        r_rsip_func100(Param_func054_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);

            r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);

            WR1_PROG(REG_1600H, 0x000033c0U);

            static const uint32_t Param_func054_func101_038[] =
            {
                BSWAP_32BIG_C(0x8e4244a6U), BSWAP_32BIG_C(0xe26ee229U), BSWAP_32BIG_C(0x3f4ab674U), BSWAP_32BIG_C(
                    0x5b4914bcU),
            };
            r_rsip_func101(Param_func054_func101_038);
        }
        else
        {
            static const uint32_t Param_func054_func101_039[] =
            {
                BSWAP_32BIG_C(0xbe2dcbccU), BSWAP_32BIG_C(0xafd1aae2U), BSWAP_32BIG_C(0x6882d1a7U), BSWAP_32BIG_C(
                    0x8283ee25U),
            };
            r_rsip_func101(Param_func054_func101_039);

            break;
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

    OFS_ADR = 216;

    r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub009(0x0000054fU);

    static const uint32_t Param_func054_func101_040[] =
    {
        BSWAP_32BIG_C(0xaa0551b3U), BSWAP_32BIG_C(0x11ee0bf3U), BSWAP_32BIG_C(0x9e5ff820U), BSWAP_32BIG_C(0x8df73970U),
    };
    r_rsip_func101(Param_func054_func101_040);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    while (1)
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000a40U, 0x2121000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func054_func100_005[] =
        {
            BSWAP_32BIG_C(0xe0c0cc69U), BSWAP_32BIG_C(0x423596f9U), BSWAP_32BIG_C(0x9700009fU), BSWAP_32BIG_C(
                0xfb3f5d4fU),
        };
        r_rsip_func100(Param_func054_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);

            static const uint32_t Param_func054_func101_041[] =
            {
                BSWAP_32BIG_C(0x3c48c96dU), BSWAP_32BIG_C(0x50f337ddU), BSWAP_32BIG_C(0xbd891565U), BSWAP_32BIG_C(
                    0x6de16a17U),
            };
            r_rsip_func101(Param_func054_func101_041);
        }
        else
        {
            static const uint32_t Param_func054_func101_042[] =
            {
                BSWAP_32BIG_C(0xd5bc504cU), BSWAP_32BIG_C(0xe3ac3ce2U), BSWAP_32BIG_C(0x0bdf5138U), BSWAP_32BIG_C(
                    0xbd4f870bU),
            };
            r_rsip_func101(Param_func054_func101_042);

            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);

    static const uint32_t Param_func054_func100_006[] =
    {
        BSWAP_32BIG_C(0xcd099561U), BSWAP_32BIG_C(0x525a372cU), BSWAP_32BIG_C(0x63d5948eU), BSWAP_32BIG_C(0xeb30c1e9U),
    };
    r_rsip_func100(Param_func054_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);

        static const uint32_t Param_func054_func101_043[] =
        {
            BSWAP_32BIG_C(0x4474cfb7U), BSWAP_32BIG_C(0xde6b99dbU), BSWAP_32BIG_C(0x48884868U), BSWAP_32BIG_C(
                0xe0259e26U),
        };
        r_rsip_func101(Param_func054_func101_043);
    }
    else
    {
        static const uint32_t Param_func054_func101_044[] =
        {
            BSWAP_32BIG_C(0xdd26aed7U), BSWAP_32BIG_C(0x5018ff5cU), BSWAP_32BIG_C(0x3e628351U), BSWAP_32BIG_C(
                0x4a2a38d7U),
        };
        r_rsip_func101(Param_func054_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
