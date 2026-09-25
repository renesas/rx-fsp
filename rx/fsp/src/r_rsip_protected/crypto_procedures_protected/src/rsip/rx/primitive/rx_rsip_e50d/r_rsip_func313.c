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

void r_rsip_func313 (void)
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

        static const uint32_t Param_func313_func100_001[] =
        {
            BSWAP_32BIG_C(0x2ccbeb42U), BSWAP_32BIG_C(0x86637c41U), BSWAP_32BIG_C(0x4d741ecfU), BSWAP_32BIG_C(
                0x7a7b721bU),
        };
        r_rsip_func100(Param_func313_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x1818000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x1818000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            static const uint32_t Param_func313_func101_001[] =
            {
                BSWAP_32BIG_C(0x6e32761dU), BSWAP_32BIG_C(0xef9c5e83U), BSWAP_32BIG_C(0xd7a48156U), BSWAP_32BIG_C(
                    0xd2ca66d6U),
            };
            r_rsip_func101(Param_func313_func101_001);
        }
        else
        {
            static const uint32_t Param_func313_func101_002[] =
            {
                BSWAP_32BIG_C(0x47a783c6U), BSWAP_32BIG_C(0x7a3bccbbU), BSWAP_32BIG_C(0xaf0e328cU), BSWAP_32BIG_C(
                    0x6a613d20U),
            };
            r_rsip_func101(Param_func313_func101_002);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_func_sub001(0x00c000d1U);

    r_rsip_func_sub004(0x0b040184U, 0xa277852fU);

    OFS_ADR = 56;

    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

    r_rsip_func_sub009(0x00003131U);

    static const uint32_t Param_func313_func101_003[] =
    {
        BSWAP_32BIG_C(0xdc7999abU), BSWAP_32BIG_C(0x59c4df27U), BSWAP_32BIG_C(0x4bce10cbU), BSWAP_32BIG_C(0x0e62a98aU),
    };
    r_rsip_func101(Param_func313_func101_003);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x4db9e5b0U);

    OFS_ADR = 112;

    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

    r_rsip_func_sub009(0x00003132U);

    static const uint32_t Param_func313_func101_004[] =
    {
        BSWAP_32BIG_C(0xae247993U), BSWAP_32BIG_C(0x19b6d4a8U), BSWAP_32BIG_C(0xd706cfb0U), BSWAP_32BIG_C(0x440886daU),
    };
    r_rsip_func101(Param_func313_func101_004);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub004(0x0b040184U, 0xab580788U);

    OFS_ADR = 0;

    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

    r_rsip_func_sub009(0x00003133U);

    static const uint32_t Param_func313_func101_005[] =
    {
        BSWAP_32BIG_C(0xbd2d3583U), BSWAP_32BIG_C(0x5de2b3f4U), BSWAP_32BIG_C(0x3b30ab30U), BSWAP_32BIG_C(0xbf90eb94U),
    };
    r_rsip_func101(Param_func313_func101_005);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0xc447d111U);

    OFS_ADR = 168;

    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

    r_rsip_func_sub009(0x00003134U);

    static const uint32_t Param_func313_func101_006[] =
    {
        BSWAP_32BIG_C(0x5362b8b1U), BSWAP_32BIG_C(0xfc321dd5U), BSWAP_32BIG_C(0x2441d5a5U), BSWAP_32BIG_C(0x336807b7U),
    };
    r_rsip_func101(Param_func313_func101_006);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0xf6428095U);

    OFS_ADR = 224;

    r_rsip_func_sub012(0x11600000U, 0x0000b400U, 0x00000030U);

    r_rsip_func_sub009(0x00003135U);

    static const uint32_t Param_func313_func101_007[] =
    {
        BSWAP_32BIG_C(0x98bbc2aeU), BSWAP_32BIG_C(0x3b4f21dbU), BSWAP_32BIG_C(0xf843e546U), BSWAP_32BIG_C(0x1d7f0190U),
    };
    r_rsip_func101(Param_func313_func101_007);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub030(0x15700000U, 0x00000b7bU, 0x80b0001bU);
    r_rsip_func_sub001(0x034300c1U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000bdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x1818000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func313_func100_002[] =
        {
            BSWAP_32BIG_C(0xb35ffbd2U), BSWAP_32BIG_C(0x4d62f8a5U), BSWAP_32BIG_C(0x4062ac12U), BSWAP_32BIG_C(
                0xc050e899U),
        };
        r_rsip_func100(Param_func313_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_func313_func101_008[] =
            {
                BSWAP_32BIG_C(0xc9dcac61U), BSWAP_32BIG_C(0xcb185f60U), BSWAP_32BIG_C(0x15e46471U), BSWAP_32BIG_C(
                    0x4bea7399U),
            };
            r_rsip_func101(Param_func313_func101_008);

            break;
        }
        else
        {
            r_rsip_func_sub004(0x0b040184U, 0xab580788U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003131U);

            static const uint32_t Param_func313_func101_009[] =
            {
                BSWAP_32BIG_C(0xc219a09fU), BSWAP_32BIG_C(0x9394bb92U), BSWAP_32BIG_C(0x3903f55fU), BSWAP_32BIG_C(
                    0x12b7ada1U),
            };
            r_rsip_func101(Param_func313_func101_009);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xa277852fU);

            OFS_ADR = 56;

            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003132U);

            static const uint32_t Param_func313_func101_010[] =
            {
                BSWAP_32BIG_C(0x8abf7ff6U), BSWAP_32BIG_C(0x8732515dU), BSWAP_32BIG_C(0xf8787851U), BSWAP_32BIG_C(
                    0xfd395897U),
            };
            r_rsip_func101(Param_func313_func101_010);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub009(0x00003131U);

            static const uint32_t Param_func313_func101_011[] =
            {
                BSWAP_32BIG_C(0x7c014c9aU), BSWAP_32BIG_C(0x7ce6dfcfU), BSWAP_32BIG_C(0x6ee67f0eU), BSWAP_32BIG_C(
                    0x04570fb3U),
            };
            r_rsip_func101(Param_func313_func101_011);
            r_rsip_func314();

            r_rsip_func_sub004(0x0b040184U, 0xab580788U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003136U);

            static const uint32_t Param_func313_func101_012[] =
            {
                BSWAP_32BIG_C(0x79ec4c8cU), BSWAP_32BIG_C(0xbea3d1d7U), BSWAP_32BIG_C(0x0f93d54cU), BSWAP_32BIG_C(
                    0x8d23f8bdU),
            };
            r_rsip_func101(Param_func313_func101_012);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xa277852fU);

            OFS_ADR = 56;

            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003137U);

            static const uint32_t Param_func313_func101_013[] =
            {
                BSWAP_32BIG_C(0x5a5adb11U), BSWAP_32BIG_C(0x33085578U), BSWAP_32BIG_C(0x0867003eU), BSWAP_32BIG_C(
                    0x71eac273U),
            };
            r_rsip_func101(Param_func313_func101_013);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x4db9e5b0U);

            OFS_ADR = 112;

            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003133U);

            static const uint32_t Param_func313_func101_014[] =
            {
                BSWAP_32BIG_C(0x820c4f4fU), BSWAP_32BIG_C(0xc39c5a7cU), BSWAP_32BIG_C(0x83a241fbU), BSWAP_32BIG_C(
                    0x2afef7f5U),
            };
            r_rsip_func101(Param_func313_func101_014);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xc447d111U);

            OFS_ADR = 168;

            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003134U);

            static const uint32_t Param_func313_func101_015[] =
            {
                BSWAP_32BIG_C(0x3af86b4cU), BSWAP_32BIG_C(0x916c974aU), BSWAP_32BIG_C(0x8f926892U), BSWAP_32BIG_C(
                    0xb09e3b01U),
            };
            r_rsip_func101(Param_func313_func101_015);
            r_rsip_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_func_sub001(0x00c000c1U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);

            r_rsip_func_sub009(0x00003132U);

            static const uint32_t Param_func313_func101_016[] =
            {
                BSWAP_32BIG_C(0xede5637dU), BSWAP_32BIG_C(0x650a3ae2U), BSWAP_32BIG_C(0x115b24e0U), BSWAP_32BIG_C(
                    0x435c548cU),
            };
            r_rsip_func101(Param_func313_func101_016);
            r_rsip_func314();

            r_rsip_func_sub004(0x0b040184U, 0x4db9e5b0U);

            OFS_ADR = 112;

            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003138U);

            static const uint32_t Param_func313_func101_017[] =
            {
                BSWAP_32BIG_C(0x8a4126e5U), BSWAP_32BIG_C(0xdb991bbcU), BSWAP_32BIG_C(0xc8441dd7U), BSWAP_32BIG_C(
                    0xfd3c5654U),
            };
            r_rsip_func101(Param_func313_func101_017);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xc447d111U);

            OFS_ADR = 168;

            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);

            r_rsip_func_sub009(0x00003139U);

            static const uint32_t Param_func313_func101_018[] =
            {
                BSWAP_32BIG_C(0x4c40672cU), BSWAP_32BIG_C(0xd318d4c4U), BSWAP_32BIG_C(0x59bf8c28U), BSWAP_32BIG_C(
                    0x85e19d79U),
            };
            r_rsip_func101(Param_func313_func101_018);
            r_rsip_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_func_sub001(0x00c000c1U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);

            r_rsip_func_sub002(0x00000220U, 0x00000630U, 0x00000838U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_func313_func100_003[] =
            {
                BSWAP_32BIG_C(0xa178c297U), BSWAP_32BIG_C(0xc71d33baU), BSWAP_32BIG_C(0x3ff67210U), BSWAP_32BIG_C(
                    0x6c8f5c8cU),
            };
            r_rsip_func100(Param_func313_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000220U, 0x18180009U);

                r_rsip_func_sub004(0x0b040184U, 0xab580788U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x00003135U);

                static const uint32_t Param_func313_func101_019[] =
                {
                    BSWAP_32BIG_C(0x3e66d072U), BSWAP_32BIG_C(0xdbd2b537U), BSWAP_32BIG_C(0x727ad56eU), BSWAP_32BIG_C(
                        0x53df9125U),
                };
                r_rsip_func101(Param_func313_func101_019);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x4db9e5b0U);

                OFS_ADR = 112;

                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x00003136U);

                static const uint32_t Param_func313_func101_020[] =
                {
                    BSWAP_32BIG_C(0x8c5bb90cU), BSWAP_32BIG_C(0xf9f21a9aU), BSWAP_32BIG_C(0x92c95ad2U), BSWAP_32BIG_C(
                        0x97c38113U),
                };
                r_rsip_func101(Param_func313_func101_020);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003131U);

                static const uint32_t Param_func313_func101_021[] =
                {
                    BSWAP_32BIG_C(0xaeb56d8cU), BSWAP_32BIG_C(0x7ddc9889U), BSWAP_32BIG_C(0x2b63f003U), BSWAP_32BIG_C(
                        0x0d39c209U),
                };
                r_rsip_func101(Param_func313_func101_021);
                r_rsip_func318();

                r_rsip_func_sub004(0x0b040184U, 0xab580788U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313aU);

                static const uint32_t Param_func313_func101_022[] =
                {
                    BSWAP_32BIG_C(0x77d93ca6U), BSWAP_32BIG_C(0x6eeb9ffeU), BSWAP_32BIG_C(0x0c6be846U), BSWAP_32BIG_C(
                        0x29d189ebU),
                };
                r_rsip_func101(Param_func313_func101_022);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xa277852fU);

                OFS_ADR = 56;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x00003137U);

                static const uint32_t Param_func313_func101_023[] =
                {
                    BSWAP_32BIG_C(0x14fa513dU), BSWAP_32BIG_C(0x5707d87dU), BSWAP_32BIG_C(0x7b299f4cU), BSWAP_32BIG_C(
                        0x9c2dcd01U),
                };
                r_rsip_func101(Param_func313_func101_023);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xc447d111U);

                OFS_ADR = 168;

                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x00003138U);

                static const uint32_t Param_func313_func101_024[] =
                {
                    BSWAP_32BIG_C(0x9cedea53U), BSWAP_32BIG_C(0x578173f8U), BSWAP_32BIG_C(0xd460238bU), BSWAP_32BIG_C(
                        0x161872e7U),
                };
                r_rsip_func101(Param_func313_func101_024);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003132U);

                static const uint32_t Param_func313_func101_025[] =
                {
                    BSWAP_32BIG_C(0x8b7c987eU), BSWAP_32BIG_C(0x974d3bd0U), BSWAP_32BIG_C(0x38867861U), BSWAP_32BIG_C(
                        0xabb588f9U),
                };
                r_rsip_func101(Param_func313_func101_025);
                r_rsip_func318();

                r_rsip_func_sub004(0x0b040184U, 0xa277852fU);

                OFS_ADR = 56;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313bU);

                static const uint32_t Param_func313_func101_026[] =
                {
                    BSWAP_32BIG_C(0x8250f70fU), BSWAP_32BIG_C(0x51b77f83U), BSWAP_32BIG_C(0x508f6420U), BSWAP_32BIG_C(
                        0x0b895880U),
                };
                r_rsip_func101(Param_func313_func101_026);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func313_func101_027[] =
                {
                    BSWAP_32BIG_C(0x7bdd5908U), BSWAP_32BIG_C(0x2ff272e9U), BSWAP_32BIG_C(0x2845d011U), BSWAP_32BIG_C(
                        0x0114ae39U),
                };
                r_rsip_func101(Param_func313_func101_027);
            }
            else
            {
                r_rsip_func_sub002(0x00000630U, 0x00000220U, 0x00000630U, 0x1818000aU);

                r_rsip_func_sub004(0x0b040184U, 0x4db9e5b0U);

                OFS_ADR = 112;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313aU);

                static const uint32_t Param_func313_func101_028[] =
                {
                    BSWAP_32BIG_C(0x131db8b6U), BSWAP_32BIG_C(0xbe858bdeU), BSWAP_32BIG_C(0x57b388aaU), BSWAP_32BIG_C(
                        0xdffd8c2eU),
                };
                r_rsip_func101(Param_func313_func101_028);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xab580788U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313bU);

                static const uint32_t Param_func313_func101_029[] =
                {
                    BSWAP_32BIG_C(0xd3859205U), BSWAP_32BIG_C(0x17fbbe25U), BSWAP_32BIG_C(0x3c0b3b02U), BSWAP_32BIG_C(
                        0x997fe394U),
                };
                r_rsip_func101(Param_func313_func101_029);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003133U);

                static const uint32_t Param_func313_func101_030[] =
                {
                    BSWAP_32BIG_C(0x9ab39994U), BSWAP_32BIG_C(0x989826adU), BSWAP_32BIG_C(0x66ff3738U), BSWAP_32BIG_C(
                        0x6aadafafU),
                };
                r_rsip_func101(Param_func313_func101_030);
                r_rsip_func318();

                r_rsip_func_sub004(0x0b040184U, 0x4db9e5b0U);

                OFS_ADR = 112;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313cU);

                static const uint32_t Param_func313_func101_031[] =
                {
                    BSWAP_32BIG_C(0xc6dd877aU), BSWAP_32BIG_C(0xe513aeafU), BSWAP_32BIG_C(0xfbef4bbbU), BSWAP_32BIG_C(
                        0x8a51cba7U),
                };
                r_rsip_func101(Param_func313_func101_031);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xc447d111U);

                OFS_ADR = 168;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313cU);

                static const uint32_t Param_func313_func101_032[] =
                {
                    BSWAP_32BIG_C(0x164c94f1U), BSWAP_32BIG_C(0x7d1f1bbdU), BSWAP_32BIG_C(0xb2c55265U), BSWAP_32BIG_C(
                        0x2ba4253dU),
                };
                r_rsip_func101(Param_func313_func101_032);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xa277852fU);

                OFS_ADR = 56;

                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313dU);

                static const uint32_t Param_func313_func101_033[] =
                {
                    BSWAP_32BIG_C(0x107c60c2U), BSWAP_32BIG_C(0xc4acce27U), BSWAP_32BIG_C(0x5a886d85U), BSWAP_32BIG_C(
                        0xb6583a00U),
                };
                r_rsip_func101(Param_func313_func101_033);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003134U);

                static const uint32_t Param_func313_func101_034[] =
                {
                    BSWAP_32BIG_C(0xab5d173aU), BSWAP_32BIG_C(0xdafab9b2U), BSWAP_32BIG_C(0x530d4edfU), BSWAP_32BIG_C(
                        0x57fa37e1U),
                };
                r_rsip_func101(Param_func313_func101_034);
                r_rsip_func318();

                r_rsip_func_sub004(0x0b040184U, 0xc447d111U);

                OFS_ADR = 168;

                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

                r_rsip_func_sub009(0x0000313dU);

                static const uint32_t Param_func313_func101_035[] =
                {
                    BSWAP_32BIG_C(0x5066d57cU), BSWAP_32BIG_C(0xa071ec30U), BSWAP_32BIG_C(0x8dac659cU), BSWAP_32BIG_C(
                        0x315d9f7fU),
                };
                r_rsip_func101(Param_func313_func101_035);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func313_func101_036[] =
                {
                    BSWAP_32BIG_C(0x30beb9d5U), BSWAP_32BIG_C(0x8e59d600U), BSWAP_32BIG_C(0x0c216053U), BSWAP_32BIG_C(
                        0x3a00911aU),
                };
                r_rsip_func101(Param_func313_func101_036);
            }
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0xf6428095U);

    OFS_ADR = 224;

    r_rsip_func_sub012(0x11600000U, 0x0000b400U, 0x00000030U);

    r_rsip_func_sub009(0x0000313eU);

    static const uint32_t Param_func313_func101_037[] =
    {
        BSWAP_32BIG_C(0xb213e85eU), BSWAP_32BIG_C(0x6eb86cc7U), BSWAP_32BIG_C(0xffcafd78U), BSWAP_32BIG_C(0xe036df12U),
    };
    r_rsip_func101(Param_func313_func101_037);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);

        static const uint32_t Param_func313_func100_004[] =
        {
            BSWAP_32BIG_C(0x5c450e9aU), BSWAP_32BIG_C(0x0c4899a8U), BSWAP_32BIG_C(0x7a033326U), BSWAP_32BIG_C(
                0x362cf683U),
        };
        r_rsip_func100(Param_func313_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000630U, 0x18180008U);

            r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000220U, 0x18180008U);

            WR1_PROG(REG_1600H, 0x000033c0U);

            static const uint32_t Param_func313_func101_038[] =
            {
                BSWAP_32BIG_C(0x2595840aU), BSWAP_32BIG_C(0xf0210bc3U), BSWAP_32BIG_C(0x3f0526b3U), BSWAP_32BIG_C(
                    0x8a9eaba2U),
            };
            r_rsip_func101(Param_func313_func101_038);
        }
        else
        {
            static const uint32_t Param_func313_func101_039[] =
            {
                BSWAP_32BIG_C(0x78fe8ad7U), BSWAP_32BIG_C(0x793c5c00U), BSWAP_32BIG_C(0xd9c6f859U), BSWAP_32BIG_C(
                    0x1a8f1a3cU),
            };
            r_rsip_func101(Param_func313_func101_039);

            break;
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0xc447d111U);

    OFS_ADR = 168;

    r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);

    r_rsip_func_sub009(0x0000313fU);

    static const uint32_t Param_func313_func101_040[] =
    {
        BSWAP_32BIG_C(0x3ffbc9aaU), BSWAP_32BIG_C(0xb7d82990U), BSWAP_32BIG_C(0x25df44d0U), BSWAP_32BIG_C(0x34e4d98eU),
    };
    r_rsip_func101(Param_func313_func101_040);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    while (1)
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000a40U, 0x1919000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func313_func100_005[] =
        {
            BSWAP_32BIG_C(0xc3e23601U), BSWAP_32BIG_C(0x300b09beU), BSWAP_32BIG_C(0xbdfbf12fU), BSWAP_32BIG_C(
                0xe82ef17eU),
        };
        r_rsip_func100(Param_func313_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000838U, 0x1919000aU);

            static const uint32_t Param_func313_func101_041[] =
            {
                BSWAP_32BIG_C(0x3f21f11aU), BSWAP_32BIG_C(0x6e5e160bU), BSWAP_32BIG_C(0x25b58b33U), BSWAP_32BIG_C(
                    0xe8fdceb1U),
            };
            r_rsip_func101(Param_func313_func101_041);
        }
        else
        {
            static const uint32_t Param_func313_func101_042[] =
            {
                BSWAP_32BIG_C(0x9f6c574eU), BSWAP_32BIG_C(0xcf6d8dccU), BSWAP_32BIG_C(0xd15fc45eU), BSWAP_32BIG_C(
                    0xf33946a2U),
            };
            r_rsip_func101(Param_func313_func101_042);

            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);

    static const uint32_t Param_func313_func100_006[] =
    {
        BSWAP_32BIG_C(0xafc82c0eU), BSWAP_32BIG_C(0x4437586aU), BSWAP_32BIG_C(0xc73f9863U), BSWAP_32BIG_C(0xaac898c2U),
    };
    r_rsip_func100(Param_func313_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000838U, 0x1919000aU);

        static const uint32_t Param_func313_func101_043[] =
        {
            BSWAP_32BIG_C(0xa451d549U), BSWAP_32BIG_C(0x1fd728e0U), BSWAP_32BIG_C(0x837e49baU), BSWAP_32BIG_C(
                0x07d139d6U),
        };
        r_rsip_func101(Param_func313_func101_043);
    }
    else
    {
        static const uint32_t Param_func313_func101_044[] =
        {
            BSWAP_32BIG_C(0x43854432U), BSWAP_32BIG_C(0x51e39074U), BSWAP_32BIG_C(0xd8321183U), BSWAP_32BIG_C(
                0x7ee540cfU),
        };
        r_rsip_func101(Param_func313_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
