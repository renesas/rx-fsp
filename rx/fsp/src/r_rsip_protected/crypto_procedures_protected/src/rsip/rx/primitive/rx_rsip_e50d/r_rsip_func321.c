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

void r_rsip_func321 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        WR1_PROG(REG_1404H, 0x16580000U);
        WR1_PROG(REG_1608H, 0x80010360U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);

        static const uint32_t Param_func321_func100_001[] =
        {
            BSWAP_32BIG_C(0x39dc875fU), BSWAP_32BIG_C(0x1b2c4b56U), BSWAP_32BIG_C(0x17499a2bU), BSWAP_32BIG_C(
                0xf29296f9U),
        };
        r_rsip_func100(Param_func321_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000230U);
            r_rsip_func_sub005(0x00000230U, 0x4040000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000660U);
            r_rsip_func_sub005(0x00000660U, 0x4040000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            static const uint32_t Param_func321_func101_001[] =
            {
                BSWAP_32BIG_C(0x289014b3U), BSWAP_32BIG_C(0x92771d47U), BSWAP_32BIG_C(0xa1bec7b7U), BSWAP_32BIG_C(
                    0x91157641U),
            };
            r_rsip_func101(Param_func321_func101_001);
        }
        else
        {
            static const uint32_t Param_func321_func101_002[] =
            {
                BSWAP_32BIG_C(0xa0525ca1U), BSWAP_32BIG_C(0x8c3009a0U), BSWAP_32BIG_C(0x01aafeb2U), BSWAP_32BIG_C(
                    0xa16159bdU),
            };
            r_rsip_func101(Param_func321_func101_002);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_func_sub001(0x00c00211U);

    r_rsip_func_sub004(0x0b040184U, 0xf9bf3112U);

    OFS_ADR = 136;

    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

    r_rsip_func_sub009(0x00003211U);

    static const uint32_t Param_func321_func101_003[] =
    {
        BSWAP_32BIG_C(0xa43b5d4fU), BSWAP_32BIG_C(0x303eb309U), BSWAP_32BIG_C(0x5e1dec12U), BSWAP_32BIG_C(0x942bd588U),
    };
    r_rsip_func101(Param_func321_func101_003);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x5bfa91b0U);

    OFS_ADR = 272;

    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

    r_rsip_func_sub009(0x00003212U);

    static const uint32_t Param_func321_func101_004[] =
    {
        BSWAP_32BIG_C(0x8c693ba3U), BSWAP_32BIG_C(0xfed2e907U), BSWAP_32BIG_C(0x93ca3575U), BSWAP_32BIG_C(0xae741087U),
    };
    r_rsip_func101(Param_func321_func101_004);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub004(0x0b040184U, 0x9fd531f0U);

    OFS_ADR = 0;

    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

    r_rsip_func_sub009(0x00003213U);

    static const uint32_t Param_func321_func101_005[] =
    {
        BSWAP_32BIG_C(0xe6e8197cU), BSWAP_32BIG_C(0xca05d255U), BSWAP_32BIG_C(0xb4dd92aeU), BSWAP_32BIG_C(0x15429a3eU),
    };
    r_rsip_func101(Param_func321_func101_005);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x0c0ab7c4U);

    OFS_ADR = 408;

    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

    r_rsip_func_sub009(0x00003214U);

    static const uint32_t Param_func321_func101_006[] =
    {
        BSWAP_32BIG_C(0x79266a42U), BSWAP_32BIG_C(0x164bb3cfU), BSWAP_32BIG_C(0xd916d031U), BSWAP_32BIG_C(0x7ed10434U),
    };
    r_rsip_func101(Param_func321_func101_006);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x7edfb1abU);

    OFS_ADR = 544;

    r_rsip_func_sub012(0x10300000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x00003215U);

    static const uint32_t Param_func321_func101_007[] =
    {
        BSWAP_32BIG_C(0x88bb6033U), BSWAP_32BIG_C(0x8f35abfeU), BSWAP_32BIG_C(0x6d9b5fe9U), BSWAP_32BIG_C(0xba6fc176U),
    };
    r_rsip_func101(Param_func321_func101_007);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x8162b38bU);

    OFS_ADR = 676;

    r_rsip_func_sub012(0x14600000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x00003216U);

    static const uint32_t Param_func321_func101_008[] =
    {
        BSWAP_32BIG_C(0x9f0bdc7bU), BSWAP_32BIG_C(0x50812ea6U), BSWAP_32BIG_C(0xbc5c0e35U), BSWAP_32BIG_C(0x8a81ffd9U),
    };
    r_rsip_func101(Param_func321_func101_008);
    r_rsip_func016(OFS_ADR);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x18900000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000230U, 0x00000a90U, 0x00000878U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func321_func100_002[] =
        {
            BSWAP_32BIG_C(0x5dcb9888U), BSWAP_32BIG_C(0xe7eb97dfU), BSWAP_32BIG_C(0xbe3dca65U), BSWAP_32BIG_C(
                0xb71e583cU),
        };
        r_rsip_func100(Param_func321_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_func321_func101_009[] =
            {
                BSWAP_32BIG_C(0x2d063ebeU), BSWAP_32BIG_C(0x8678fc01U), BSWAP_32BIG_C(0x9ca6520dU), BSWAP_32BIG_C(
                    0xfd75a30cU),
            };
            r_rsip_func101(Param_func321_func101_009);

            break;
        }
        else
        {
            r_rsip_func_sub004(0x0b040184U, 0x9fd531f0U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x00003211U);

            static const uint32_t Param_func321_func101_010[] =
            {
                BSWAP_32BIG_C(0xcfd3971dU), BSWAP_32BIG_C(0xa3a9341cU), BSWAP_32BIG_C(0xd89d6f23U), BSWAP_32BIG_C(
                    0xdb563293U),
            };
            r_rsip_func101(Param_func321_func101_010);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xf9bf3112U);

            OFS_ADR = 136;

            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x00003212U);

            static const uint32_t Param_func321_func101_011[] =
            {
                BSWAP_32BIG_C(0x6cad2ddbU), BSWAP_32BIG_C(0x61889180U), BSWAP_32BIG_C(0x49506233U), BSWAP_32BIG_C(
                    0xa9972e8aU),
            };
            r_rsip_func101(Param_func321_func101_011);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub009(0x00003211U);

            static const uint32_t Param_func321_func101_012[] =
            {
                BSWAP_32BIG_C(0x07918db6U), BSWAP_32BIG_C(0xd5baffd0U), BSWAP_32BIG_C(0xf1179464U), BSWAP_32BIG_C(
                    0xd7e07c0bU),
            };
            r_rsip_func101(Param_func321_func101_012);
            r_rsip_func322();

            r_rsip_func_sub004(0x0b040184U, 0x9fd531f0U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x00003217U);

            static const uint32_t Param_func321_func101_013[] =
            {
                BSWAP_32BIG_C(0x346d7f5fU), BSWAP_32BIG_C(0x851f9640U), BSWAP_32BIG_C(0x8de532d4U), BSWAP_32BIG_C(
                    0xe7475d4fU),
            };
            r_rsip_func101(Param_func321_func101_013);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xf9bf3112U);

            OFS_ADR = 136;

            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x00003218U);

            static const uint32_t Param_func321_func101_014[] =
            {
                BSWAP_32BIG_C(0x28d350e5U), BSWAP_32BIG_C(0x807f9051U), BSWAP_32BIG_C(0xe08f5acfU), BSWAP_32BIG_C(
                    0xbbe69346U),
            };
            r_rsip_func101(Param_func321_func101_014);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x5bfa91b0U);

            OFS_ADR = 272;

            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x00003213U);

            static const uint32_t Param_func321_func101_015[] =
            {
                BSWAP_32BIG_C(0x8dbf25b5U), BSWAP_32BIG_C(0x65cfc49cU), BSWAP_32BIG_C(0xcc44d23eU), BSWAP_32BIG_C(
                    0x33553cf1U),
            };
            r_rsip_func101(Param_func321_func101_015);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x0c0ab7c4U);

            OFS_ADR = 408;

            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x00003214U);

            static const uint32_t Param_func321_func101_016[] =
            {
                BSWAP_32BIG_C(0xa3e21a02U), BSWAP_32BIG_C(0x3fe56e11U), BSWAP_32BIG_C(0x59027c5fU), BSWAP_32BIG_C(
                    0x17cce522U),
            };
            r_rsip_func101(Param_func321_func101_016);
            r_rsip_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_func_sub001(0x00c00201U);

            r_rsip_func_sub002(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);

            r_rsip_func_sub002(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);

            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);

            r_rsip_func_sub009(0x00003212U);

            static const uint32_t Param_func321_func101_017[] =
            {
                BSWAP_32BIG_C(0x42e84d1eU), BSWAP_32BIG_C(0x4195939cU), BSWAP_32BIG_C(0x41b3b5b4U), BSWAP_32BIG_C(
                    0x27eede7dU),
            };
            r_rsip_func101(Param_func321_func101_017);
            r_rsip_func322();

            r_rsip_func_sub004(0x0b040184U, 0x5bfa91b0U);

            OFS_ADR = 272;

            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x00003219U);

            static const uint32_t Param_func321_func101_018[] =
            {
                BSWAP_32BIG_C(0xc0fbf40aU), BSWAP_32BIG_C(0x15a04cfbU), BSWAP_32BIG_C(0x03ac5e93U), BSWAP_32BIG_C(
                    0x88fa204fU),
            };
            r_rsip_func101(Param_func321_func101_018);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x0c0ab7c4U);

            OFS_ADR = 408;

            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);

            r_rsip_func_sub009(0x0000321aU);

            static const uint32_t Param_func321_func101_019[] =
            {
                BSWAP_32BIG_C(0x9817f8c1U), BSWAP_32BIG_C(0x16a72d7dU), BSWAP_32BIG_C(0x91c3a5c8U), BSWAP_32BIG_C(
                    0xed793886U),
            };
            r_rsip_func101(Param_func321_func101_019);
            r_rsip_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_func_sub001(0x00c00201U);

            r_rsip_func_sub002(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);

            r_rsip_func_sub002(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);

            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);

            r_rsip_func_sub002(0x00000230U, 0x00000660U, 0x00000878U, 0x4040000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_func321_func100_003[] =
            {
                BSWAP_32BIG_C(0x7e842dfeU), BSWAP_32BIG_C(0xfb89edb9U), BSWAP_32BIG_C(0xaa958267U), BSWAP_32BIG_C(
                    0x0a990fb1U),
            };
            r_rsip_func100(Param_func321_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000230U, 0x40400009U);

                r_rsip_func_sub004(0x0b040184U, 0x9fd531f0U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x00003215U);

                static const uint32_t Param_func321_func101_020[] =
                {
                    BSWAP_32BIG_C(0xf69fbeffU), BSWAP_32BIG_C(0xd0aa10fdU), BSWAP_32BIG_C(0xeae79e83U), BSWAP_32BIG_C(
                        0x671e0f46U),
                };
                r_rsip_func101(Param_func321_func101_020);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x5bfa91b0U);

                OFS_ADR = 272;

                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x00003216U);

                static const uint32_t Param_func321_func101_021[] =
                {
                    BSWAP_32BIG_C(0x1033b142U), BSWAP_32BIG_C(0x07879630U), BSWAP_32BIG_C(0x23cc1b25U), BSWAP_32BIG_C(
                        0xc66a8406U),
                };
                r_rsip_func101(Param_func321_func101_021);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003211U);

                static const uint32_t Param_func321_func101_022[] =
                {
                    BSWAP_32BIG_C(0x6fb4c4f8U), BSWAP_32BIG_C(0x655c1703U), BSWAP_32BIG_C(0x67b03a5bU), BSWAP_32BIG_C(
                        0xb5700930U),
                };
                r_rsip_func101(Param_func321_func101_022);
                r_rsip_func324();

                r_rsip_func_sub004(0x0b040184U, 0x9fd531f0U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321bU);

                static const uint32_t Param_func321_func101_023[] =
                {
                    BSWAP_32BIG_C(0x3f57c819U), BSWAP_32BIG_C(0x89d99438U), BSWAP_32BIG_C(0x1dee4d03U), BSWAP_32BIG_C(
                        0xe517e7c8U),
                };
                r_rsip_func101(Param_func321_func101_023);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xf9bf3112U);

                OFS_ADR = 136;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x00003217U);

                static const uint32_t Param_func321_func101_024[] =
                {
                    BSWAP_32BIG_C(0x0104dc8eU), BSWAP_32BIG_C(0x4db17ea5U), BSWAP_32BIG_C(0xe40289f8U), BSWAP_32BIG_C(
                        0x15308af2U),
                };
                r_rsip_func101(Param_func321_func101_024);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x0c0ab7c4U);

                OFS_ADR = 408;

                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x00003218U);

                static const uint32_t Param_func321_func101_025[] =
                {
                    BSWAP_32BIG_C(0x03207dd8U), BSWAP_32BIG_C(0xdb8725d0U), BSWAP_32BIG_C(0x280bac01U), BSWAP_32BIG_C(
                        0x17d8a8c9U),
                };
                r_rsip_func101(Param_func321_func101_025);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003212U);

                static const uint32_t Param_func321_func101_026[] =
                {
                    BSWAP_32BIG_C(0xa2b3f236U), BSWAP_32BIG_C(0x5f42570cU), BSWAP_32BIG_C(0x30292dacU), BSWAP_32BIG_C(
                        0x810c810bU),
                };
                r_rsip_func101(Param_func321_func101_026);
                r_rsip_func324();

                r_rsip_func_sub004(0x0b040184U, 0xf9bf3112U);

                OFS_ADR = 136;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321cU);

                static const uint32_t Param_func321_func101_027[] =
                {
                    BSWAP_32BIG_C(0xce93d87eU), BSWAP_32BIG_C(0x960d9276U), BSWAP_32BIG_C(0x1fc8c232U), BSWAP_32BIG_C(
                        0x7a5a5678U),
                };
                r_rsip_func101(Param_func321_func101_027);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func321_func101_028[] =
                {
                    BSWAP_32BIG_C(0xcc54c261U), BSWAP_32BIG_C(0x47b4d01bU), BSWAP_32BIG_C(0x51128296U), BSWAP_32BIG_C(
                        0x4af5c0afU),
                };
                r_rsip_func101(Param_func321_func101_028);
            }
            else
            {
                r_rsip_func_sub002(0x00000660U, 0x00000230U, 0x00000660U, 0x4040000aU);

                r_rsip_func_sub004(0x0b040184U, 0x5bfa91b0U);

                OFS_ADR = 272;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321aU);

                static const uint32_t Param_func321_func101_029[] =
                {
                    BSWAP_32BIG_C(0xd2f79b6bU), BSWAP_32BIG_C(0xdfa93d98U), BSWAP_32BIG_C(0xe708d223U), BSWAP_32BIG_C(
                        0xf37ac91fU),
                };
                r_rsip_func101(Param_func321_func101_029);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x9fd531f0U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321bU);

                static const uint32_t Param_func321_func101_030[] =
                {
                    BSWAP_32BIG_C(0x128b296bU), BSWAP_32BIG_C(0x7408cf5eU), BSWAP_32BIG_C(0x0ade2ff0U), BSWAP_32BIG_C(
                        0x4c2dbcc6U),
                };
                r_rsip_func101(Param_func321_func101_030);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003213U);

                static const uint32_t Param_func321_func101_031[] =
                {
                    BSWAP_32BIG_C(0x781ca97aU), BSWAP_32BIG_C(0x45616fbcU), BSWAP_32BIG_C(0x57139269U), BSWAP_32BIG_C(
                        0x5e94b440U),
                };
                r_rsip_func101(Param_func321_func101_031);
                r_rsip_func324();

                r_rsip_func_sub004(0x0b040184U, 0x5bfa91b0U);

                OFS_ADR = 272;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321dU);

                static const uint32_t Param_func321_func101_032[] =
                {
                    BSWAP_32BIG_C(0x0a0a172bU), BSWAP_32BIG_C(0xdea600a1U), BSWAP_32BIG_C(0xbb12bfe8U), BSWAP_32BIG_C(
                        0xbd9e137dU),
                };
                r_rsip_func101(Param_func321_func101_032);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x0c0ab7c4U);

                OFS_ADR = 408;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321cU);

                static const uint32_t Param_func321_func101_033[] =
                {
                    BSWAP_32BIG_C(0xfe181b67U), BSWAP_32BIG_C(0x9c2eff6fU), BSWAP_32BIG_C(0x438bdc9cU), BSWAP_32BIG_C(
                        0xf69d016cU),
                };
                r_rsip_func101(Param_func321_func101_033);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xf9bf3112U);

                OFS_ADR = 136;

                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321dU);

                static const uint32_t Param_func321_func101_034[] =
                {
                    BSWAP_32BIG_C(0x8b90a77cU), BSWAP_32BIG_C(0xec3af91cU), BSWAP_32BIG_C(0x4f089e4aU), BSWAP_32BIG_C(
                        0x1c7acb84U),
                };
                r_rsip_func101(Param_func321_func101_034);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub009(0x00003214U);

                static const uint32_t Param_func321_func101_035[] =
                {
                    BSWAP_32BIG_C(0xa0d1405cU), BSWAP_32BIG_C(0x796a4a5aU), BSWAP_32BIG_C(0x677f3074U), BSWAP_32BIG_C(
                        0x73d3867bU),
                };
                r_rsip_func101(Param_func321_func101_035);
                r_rsip_func324();

                r_rsip_func_sub004(0x0b040184U, 0x0c0ab7c4U);

                OFS_ADR = 408;

                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

                r_rsip_func_sub009(0x0000321eU);

                static const uint32_t Param_func321_func101_036[] =
                {
                    BSWAP_32BIG_C(0xe2cf6c9dU), BSWAP_32BIG_C(0xb6639c67U), BSWAP_32BIG_C(0x9fe63110U), BSWAP_32BIG_C(
                        0xfdda5b16U),
                };
                r_rsip_func101(Param_func321_func101_036);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func321_func101_037[] =
                {
                    BSWAP_32BIG_C(0xf18c364bU), BSWAP_32BIG_C(0x4d13ef6aU), BSWAP_32BIG_C(0xb67b089dU), BSWAP_32BIG_C(
                        0xbd566d4dU),
                };
                r_rsip_func101(Param_func321_func101_037);
            }
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x7edfb1abU);

    OFS_ADR = 544;

    r_rsip_func_sub012(0x10300000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x0000321eU);

    static const uint32_t Param_func321_func101_038[] =
    {
        BSWAP_32BIG_C(0xc2affc14U), BSWAP_32BIG_C(0xe2d82be4U), BSWAP_32BIG_C(0xc88a93b7U), BSWAP_32BIG_C(0xeb5114d2U),
    };
    r_rsip_func101(Param_func321_func101_038);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);

        static const uint32_t Param_func321_func100_004[] =
        {
            BSWAP_32BIG_C(0x6179af39U), BSWAP_32BIG_C(0x6c5b9ed7U), BSWAP_32BIG_C(0x8931c1f8U), BSWAP_32BIG_C(
                0x898e79e9U),
        };
        r_rsip_func100(Param_func321_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000a90U, 0x00000660U, 0x00000660U, 0x40400008U);

            r_rsip_func_sub002(0x00000a90U, 0x00000230U, 0x00000230U, 0x40400008U);

            WR1_PROG(REG_1600H, 0x000033c0U);

            static const uint32_t Param_func321_func101_039[] =
            {
                BSWAP_32BIG_C(0xfc3c64f9U), BSWAP_32BIG_C(0x00a21367U), BSWAP_32BIG_C(0x0f606ef4U), BSWAP_32BIG_C(
                    0xa618a690U),
            };
            r_rsip_func101(Param_func321_func101_039);
        }
        else
        {
            static const uint32_t Param_func321_func101_040[] =
            {
                BSWAP_32BIG_C(0x5cd82679U), BSWAP_32BIG_C(0x6f45028eU), BSWAP_32BIG_C(0x885a6933U), BSWAP_32BIG_C(
                    0x5d165eb8U),
            };
            r_rsip_func101(Param_func321_func101_040);

            break;
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x0c0ab7c4U);

    OFS_ADR = 408;

    r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);

    r_rsip_func_sub009(0x0000321fU);

    static const uint32_t Param_func321_func101_041[] =
    {
        BSWAP_32BIG_C(0x532105aaU), BSWAP_32BIG_C(0x6beb8c5dU), BSWAP_32BIG_C(0xf327663fU), BSWAP_32BIG_C(0xddfbed83U),
    };
    r_rsip_func101(Param_func321_func101_041);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    while (1)
    {
        r_rsip_func_sub002(0x00000230U, 0x00000878U, 0x00000a90U, 0x4141000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func321_func100_005[] =
        {
            BSWAP_32BIG_C(0x65483f50U), BSWAP_32BIG_C(0xbbfde1ecU), BSWAP_32BIG_C(0xff97f5cbU), BSWAP_32BIG_C(
                0x69d97d5aU),
        };
        r_rsip_func100(Param_func321_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000878U, 0x00000230U, 0x00000878U, 0x4141000aU);

            static const uint32_t Param_func321_func101_042[] =
            {
                BSWAP_32BIG_C(0x90648917U), BSWAP_32BIG_C(0xf0199f2cU), BSWAP_32BIG_C(0x75a5d348U), BSWAP_32BIG_C(
                    0x02f06f01U),
            };
            r_rsip_func101(Param_func321_func101_042);
        }
        else
        {
            static const uint32_t Param_func321_func101_043[] =
            {
                BSWAP_32BIG_C(0x63989a00U), BSWAP_32BIG_C(0xb2c51e73U), BSWAP_32BIG_C(0xbf0754adU), BSWAP_32BIG_C(
                    0x1fe0a984U),
            };
            r_rsip_func101(Param_func321_func101_043);

            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);

    static const uint32_t Param_func321_func100_006[] =
    {
        BSWAP_32BIG_C(0x1f9aeabfU), BSWAP_32BIG_C(0x4aed4bceU), BSWAP_32BIG_C(0x631fbac1U), BSWAP_32BIG_C(0xdf9c443eU),
    };
    r_rsip_func100(Param_func321_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000230U, 0x00000878U, 0x00000878U, 0x4141000aU);

        static const uint32_t Param_func321_func101_044[] =
        {
            BSWAP_32BIG_C(0x020a746fU), BSWAP_32BIG_C(0x59274c85U), BSWAP_32BIG_C(0xa24099b2U), BSWAP_32BIG_C(
                0xa5144328U),
        };
        r_rsip_func101(Param_func321_func101_044);
    }
    else
    {
        static const uint32_t Param_func321_func101_045[] =
        {
            BSWAP_32BIG_C(0x811a1628U), BSWAP_32BIG_C(0xf74cf798U), BSWAP_32BIG_C(0xedf5c38fU), BSWAP_32BIG_C(
                0xe4e4304bU),
        };
        r_rsip_func101(Param_func321_func101_045);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
