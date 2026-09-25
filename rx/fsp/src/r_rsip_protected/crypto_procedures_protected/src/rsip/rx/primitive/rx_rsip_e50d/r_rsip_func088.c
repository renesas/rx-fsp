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

void r_rsip_func088 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000430U, 0x0404000aU);

    r_rsip_func_sub018(0x00000020U, 0x00000430U, 0x04040010U);

    r_rsip_func_sub009(0x00f08801U);

    static const uint32_t Param_func088_func101_001[] =
    {
        BSWAP_32BIG_C(0x9a7fa432U), BSWAP_32BIG_C(0x340ad3c5U), BSWAP_32BIG_C(0x65d0dc9dU), BSWAP_32BIG_C(0x73078f71U),
    };
    r_rsip_func101(Param_func088_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10f00000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f08802U);

    static const uint32_t Param_func088_func101_002[] =
    {
        BSWAP_32BIG_C(0x61efc92eU), BSWAP_32BIG_C(0x76811748U), BSWAP_32BIG_C(0xddfc07caU), BSWAP_32BIG_C(0x662dca06U),
    };
    r_rsip_func101(Param_func088_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub040(0x00000430U, 0x00000480U, 0x00000020U, 0x04040004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_1404H, 0x14380000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000458U, 0x00000160U, 0x04040009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x04040010U);

    r_rsip_func_sub038(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x04040005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000458U, 0x00000480U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func088_func100_001[] =
    {
        BSWAP_32BIG_C(0x7fa85545U), BSWAP_32BIG_C(0x634cc4c6U), BSWAP_32BIG_C(0x6c54f463U), BSWAP_32BIG_C(0xd0e2f0efU),
    };
    r_rsip_func100(Param_func088_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func088_func101_003[] =
        {
            BSWAP_32BIG_C(0xe111b17eU), BSWAP_32BIG_C(0x898ebb45U), BSWAP_32BIG_C(0x2637f73bU), BSWAP_32BIG_C(
                0x6144d983U),
        };
        r_rsip_func101(Param_func088_func101_003);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_func_sub040(0x00000070U, 0x00000250U, 0x00000018U, 0x04040004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x14100000U);
        r_rsip_func_sub001(0x00c00021U);

        r_rsip_func_sub002(0x00000890U, 0x00000430U, 0x000002c8U, 0x04040009U);

        r_rsip_func_sub002(0x00000070U, 0x00000430U, 0x000002f0U, 0x04040009U);

        static const uint32_t Param_func088_func100_002[] =
        {
            BSWAP_32BIG_C(0xdb963a8cU), BSWAP_32BIG_C(0x921d1b8bU), BSWAP_32BIG_C(0xcfcd805dU), BSWAP_32BIG_C(
                0x836c4425U),
        };
        r_rsip_func100(Param_func088_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x04040015U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_143CH, 0x00000d00U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x00000520U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func088_func100_003[] =
        {
            BSWAP_32BIG_C(0x46c85e1aU), BSWAP_32BIG_C(0x4a12bfe2U), BSWAP_32BIG_C(0xfc711b09U), BSWAP_32BIG_C(
                0x4bbac084U),
        };
        r_rsip_func100(Param_func088_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func088_func101_004[] =
            {
                BSWAP_32BIG_C(0xceff57d0U), BSWAP_32BIG_C(0xea729525U), BSWAP_32BIG_C(0x9f8632faU), BSWAP_32BIG_C(
                    0xf6a060b3U),
            };
            r_rsip_func101(Param_func088_func101_004);
        }
        else
        {
            static const uint32_t Param_func088_func100_004[] =
            {
                BSWAP_32BIG_C(0x06f6d221U), BSWAP_32BIG_C(0x224f4354U), BSWAP_32BIG_C(0x417889efU), BSWAP_32BIG_C(
                    0x623b5a42U),
            };
            r_rsip_func100(Param_func088_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x04040015U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func088_func100_005[] =
            {
                BSWAP_32BIG_C(0xff44ea2bU), BSWAP_32BIG_C(0x98cbdbb0U), BSWAP_32BIG_C(0x928f7387U), BSWAP_32BIG_C(
                    0xfea54413U),
            };
            r_rsip_func100(Param_func088_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func088_func101_005[] =
                {
                    BSWAP_32BIG_C(0x567bb31dU), BSWAP_32BIG_C(0xd6f55526U), BSWAP_32BIG_C(0x60e8c7fcU), BSWAP_32BIG_C(
                        0xf72c4775U),
                };
                r_rsip_func101(Param_func088_func101_005);
            }
            else
            {
                static const uint32_t Param_func088_func100_006[] =
                {
                    BSWAP_32BIG_C(0xc5e1f371U), BSWAP_32BIG_C(0xaf358926U), BSWAP_32BIG_C(0xe9643f3fU), BSWAP_32BIG_C(
                        0x2b8b6793U),
                };
                r_rsip_func100(Param_func088_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x04040004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub038(0x00000520U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub007(0x00000548U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0404000aU);

                r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000548U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub001(0x00c00021U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000520U, 0x04040009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x04040013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x12d00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func088_func100_007[] =
                {
                    BSWAP_32BIG_C(0xd448b0ffU), BSWAP_32BIG_C(0x64c009a2U), BSWAP_32BIG_C(0xc90ac8fcU), BSWAP_32BIG_C(
                        0x4f6f7dd7U),
                };
                r_rsip_func100(Param_func088_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func088_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x692413a4U), BSWAP_32BIG_C(0x98a3bd23U), BSWAP_32BIG_C(0x99e0db29U),
                        BSWAP_32BIG_C(0xf789c836U),
                    };
                    r_rsip_func101(Param_func088_func101_006);
                }
                else
                {
                    static const uint32_t Param_func088_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x79d1f225U), BSWAP_32BIG_C(0x6f67c32dU), BSWAP_32BIG_C(0xad839045U),
                        BSWAP_32BIG_C(0xea92c19fU),
                    };
                    r_rsip_func100(Param_func088_func100_008);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x04040004U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000002U);
                    r_rsip_func_sub001(0x00c0001dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);

                    r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    r_rsip_func_sub038(0x00000200U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000228U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x04040002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xd7a9fc1eU);

                    static const uint32_t Param_func088_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xda928458U), BSWAP_32BIG_C(0x499d5af0U), BSWAP_32BIG_C(0x1a1012f0U),
                        BSWAP_32BIG_C(0xa5352644U),
                    };
                    r_rsip_func101(Param_func088_func101_007);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0xd7a9fc1eU, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
