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

void r_rsip_func091 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003e0U, 0x0909000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003e0U, 0x09090010U);

    r_rsip_func_sub009(0x00f09101U);

    static const uint32_t Param_func091_func101_001[] =
    {
        BSWAP_32BIG_C(0xc91e9661U), BSWAP_32BIG_C(0x14fe3b98U), BSWAP_32BIG_C(0x64f52e55U), BSWAP_32BIG_C(0x782c6b8fU),
    };
    r_rsip_func101(Param_func091_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f09102U);

    static const uint32_t Param_func091_func101_002[] =
    {
        BSWAP_32BIG_C(0x662176f4U), BSWAP_32BIG_C(0x780135cbU), BSWAP_32BIG_C(0xbd988db0U), BSWAP_32BIG_C(0x9d0c4c4bU),
    };
    r_rsip_func101(Param_func091_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f09103U);

    static const uint32_t Param_func091_func101_003[] =
    {
        BSWAP_32BIG_C(0x4d6a680aU), BSWAP_32BIG_C(0x012c8ef5U), BSWAP_32BIG_C(0xf256ee2eU), BSWAP_32BIG_C(0x08d80623U),
    };
    r_rsip_func101(Param_func091_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f09104U);

    static const uint32_t Param_func091_func101_004[] =
    {
        BSWAP_32BIG_C(0x99c1d47aU), BSWAP_32BIG_C(0xc9728b9dU), BSWAP_32BIG_C(0xc326ba75U), BSWAP_32BIG_C(0x9c401f38U),
    };
    r_rsip_func101(Param_func091_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f09105U);

    static const uint32_t Param_func091_func101_005[] =
    {
        BSWAP_32BIG_C(0xe45a8089U), BSWAP_32BIG_C(0x11941640U), BSWAP_32BIG_C(0xf75feeeeU), BSWAP_32BIG_C(0xa776dddaU),
    };
    r_rsip_func101(Param_func091_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub040(0x000003e0U, 0x00000480U, 0x00000020U, 0x09090004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_1404H, 0x13e80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000430U, 0x00000160U, 0x09090009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

    r_rsip_func_sub038(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x09090005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000430U, 0x00000480U, 0x0909000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func091_func100_001[] =
    {
        BSWAP_32BIG_C(0x8ddd6a08U), BSWAP_32BIG_C(0xa1a5a7c2U), BSWAP_32BIG_C(0xde6fa804U), BSWAP_32BIG_C(0x4bafe7faU),
    };
    r_rsip_func100(Param_func091_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func091_func101_006[] =
        {
            BSWAP_32BIG_C(0x2c3fd006U), BSWAP_32BIG_C(0x16c30a6fU), BSWAP_32BIG_C(0x879f8bb3U), BSWAP_32BIG_C(
                0x1a6fe970U),
        };
        r_rsip_func101(Param_func091_func101_006);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_func_sub040(0x00000070U, 0x00000250U, 0x00000018U, 0x09090004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x13980000U);
        r_rsip_func_sub001(0x00c00049U);

        r_rsip_func_sub002(0x00000890U, 0x000003e0U, 0x000002a0U, 0x09090009U);

        r_rsip_func_sub002(0x00000070U, 0x000003e0U, 0x000002f0U, 0x09090009U);

        static const uint32_t Param_func091_func100_002[] =
        {
            BSWAP_32BIG_C(0x0824d66bU), BSWAP_32BIG_C(0xb593085cU), BSWAP_32BIG_C(0xa41b3438U), BSWAP_32BIG_C(
                0xfa7464f5U),
        };
        r_rsip_func100(Param_func091_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x09090015U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_143CH, 0x00000d00U);

        WR1_PROG(REG_1404H, 0x10c80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c00045U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x000004d0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func091_func100_003[] =
        {
            BSWAP_32BIG_C(0x86525abeU), BSWAP_32BIG_C(0xa47a12ffU), BSWAP_32BIG_C(0x7f83a51dU), BSWAP_32BIG_C(
                0x1f0326f0U),
        };
        r_rsip_func100(Param_func091_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func091_func101_007[] =
            {
                BSWAP_32BIG_C(0xa736afe3U), BSWAP_32BIG_C(0xcbbb7f42U), BSWAP_32BIG_C(0xdf5527bfU), BSWAP_32BIG_C(
                    0xb4db91fbU),
            };
            r_rsip_func101(Param_func091_func101_007);
        }
        else
        {
            static const uint32_t Param_func091_func100_004[] =
            {
                BSWAP_32BIG_C(0x3d3e2433U), BSWAP_32BIG_C(0xf5805f4eU), BSWAP_32BIG_C(0x9bb61d38U), BSWAP_32BIG_C(
                    0xfa2fe18cU),
            };
            r_rsip_func100(Param_func091_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x09090015U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1404H, 0x10c80000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c00045U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func091_func100_005[] =
            {
                BSWAP_32BIG_C(0x163e2eddU), BSWAP_32BIG_C(0xce3ddef0U), BSWAP_32BIG_C(0x28443c90U), BSWAP_32BIG_C(
                    0x34f70b05U),
            };
            r_rsip_func100(Param_func091_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func091_func101_008[] =
                {
                    BSWAP_32BIG_C(0x2e75811dU), BSWAP_32BIG_C(0xb51b6423U), BSWAP_32BIG_C(0x608a513cU), BSWAP_32BIG_C(
                        0xd685f381U),
                };
                r_rsip_func101(Param_func091_func101_008);
            }
            else
            {
                static const uint32_t Param_func091_func100_006[] =
                {
                    BSWAP_32BIG_C(0x7d9ff87cU), BSWAP_32BIG_C(0x0e0c7c47U), BSWAP_32BIG_C(0x3ba190f1U), BSWAP_32BIG_C(
                        0x8b7be05bU),
                };
                r_rsip_func100(Param_func091_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x09090004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub038(0x000004d0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x00000520U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0909000aU);

                r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000520U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_func_sub001(0x00c00049U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x000004d0U, 0x09090009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x09090004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x09090013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x12a80000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func091_func100_007[] =
                {
                    BSWAP_32BIG_C(0xfd298c94U), BSWAP_32BIG_C(0xdd1b5c56U), BSWAP_32BIG_C(0x6c593872U), BSWAP_32BIG_C(
                        0x0a235ae9U),
                };
                r_rsip_func100(Param_func091_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func091_func101_009[] =
                    {
                        BSWAP_32BIG_C(0xf00caf31U), BSWAP_32BIG_C(0x60f679a8U), BSWAP_32BIG_C(0xa78c7f8bU),
                        BSWAP_32BIG_C(0xd6462a84U),
                    };
                    r_rsip_func101(Param_func091_func101_009);
                }
                else
                {
                    static const uint32_t Param_func091_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x0f9769bbU), BSWAP_32BIG_C(0x10b9ad31U), BSWAP_32BIG_C(0x90472096U),
                        BSWAP_32BIG_C(0x973e841fU),
                    };
                    r_rsip_func100(Param_func091_func100_008);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x09090004U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x11180000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000002U);
                    r_rsip_func_sub001(0x00c00045U);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    r_rsip_func_sub038(0x000001b0U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x09090002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000200U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x09090002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x40f57c1eU);

                    static const uint32_t Param_func091_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x285e7468U), BSWAP_32BIG_C(0xc3e53314U), BSWAP_32BIG_C(0xa955d5ffU),
                        BSWAP_32BIG_C(0x70d42773U),
                    };
                    r_rsip_func101(Param_func091_func101_010);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0x40f57c1eU, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
