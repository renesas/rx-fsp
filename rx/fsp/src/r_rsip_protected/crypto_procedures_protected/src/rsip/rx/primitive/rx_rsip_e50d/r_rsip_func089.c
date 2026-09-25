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

void r_rsip_func089 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11300000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000410U, 0x0606000aU);

    r_rsip_func_sub018(0x00000020U, 0x00000410U, 0x06060010U);

    r_rsip_func_sub009(0x00f08901U);

    static const uint32_t Param_func089_func101_001[] =
    {
        BSWAP_32BIG_C(0x29b1134fU), BSWAP_32BIG_C(0x8058a78bU), BSWAP_32BIG_C(0x2d82dfd0U), BSWAP_32BIG_C(0x1fb8970bU),
    };
    r_rsip_func101(Param_func089_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f08902U);

    static const uint32_t Param_func089_func101_002[] =
    {
        BSWAP_32BIG_C(0x2902b6a9U), BSWAP_32BIG_C(0x7868c076U), BSWAP_32BIG_C(0x050c074fU), BSWAP_32BIG_C(0x7a40f500U),
    };
    r_rsip_func101(Param_func089_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f08903U);

    static const uint32_t Param_func089_func101_003[] =
    {
        BSWAP_32BIG_C(0x2f46e534U), BSWAP_32BIG_C(0x82b55975U), BSWAP_32BIG_C(0xe509a422U), BSWAP_32BIG_C(0x8e789666U),
    };
    r_rsip_func101(Param_func089_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub040(0x00000410U, 0x00000480U, 0x00000020U, 0x06060004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_1404H, 0x14180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000448U, 0x00000160U, 0x06060009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

    r_rsip_func_sub038(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x06060005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000448U, 0x00000480U, 0x0606000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func089_func100_001[] =
    {
        BSWAP_32BIG_C(0xb69d09ddU), BSWAP_32BIG_C(0x074a2d9eU), BSWAP_32BIG_C(0x09390583U), BSWAP_32BIG_C(0x3aae8f75U),
    };
    r_rsip_func100(Param_func089_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func089_func101_004[] =
        {
            BSWAP_32BIG_C(0x34ea8d7dU), BSWAP_32BIG_C(0xebf0c28dU), BSWAP_32BIG_C(0x2d6d3c8dU), BSWAP_32BIG_C(
                0xd0968163U),
        };
        r_rsip_func101(Param_func089_func101_004);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_func_sub040(0x00000070U, 0x00000250U, 0x00000018U, 0x06060004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x13e00000U);
        r_rsip_func_sub001(0x00c00031U);

        r_rsip_func_sub002(0x00000890U, 0x00000410U, 0x000002b8U, 0x06060009U);

        r_rsip_func_sub002(0x00000070U, 0x00000410U, 0x000002f0U, 0x06060009U);

        static const uint32_t Param_func089_func100_002[] =
        {
            BSWAP_32BIG_C(0xa79204efU), BSWAP_32BIG_C(0x2a8066f9U), BSWAP_32BIG_C(0x80e6f86dU), BSWAP_32BIG_C(
                0x3e31c0ccU),
        };
        r_rsip_func100(Param_func089_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x06060015U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_143CH, 0x00000d00U);

        WR1_PROG(REG_1404H, 0x10e00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x00000500U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func089_func100_003[] =
        {
            BSWAP_32BIG_C(0x241fea76U), BSWAP_32BIG_C(0xa7340fe4U), BSWAP_32BIG_C(0x8a08b7d4U), BSWAP_32BIG_C(
                0x8e037233U),
        };
        r_rsip_func100(Param_func089_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func089_func101_005[] =
            {
                BSWAP_32BIG_C(0x43012284U), BSWAP_32BIG_C(0xd5a781daU), BSWAP_32BIG_C(0x11efa526U), BSWAP_32BIG_C(
                    0xebf26f04U),
            };
            r_rsip_func101(Param_func089_func101_005);
        }
        else
        {
            static const uint32_t Param_func089_func100_004[] =
            {
                BSWAP_32BIG_C(0x81094224U), BSWAP_32BIG_C(0x24d47fb4U), BSWAP_32BIG_C(0x322e5660U), BSWAP_32BIG_C(
                    0x5405b992U),
            };
            r_rsip_func100(Param_func089_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x06060015U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func089_func100_005[] =
            {
                BSWAP_32BIG_C(0x4ae18218U), BSWAP_32BIG_C(0x74d1077fU), BSWAP_32BIG_C(0xceeab547U), BSWAP_32BIG_C(
                    0x8fad5295U),
            };
            r_rsip_func100(Param_func089_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func089_func101_006[] =
                {
                    BSWAP_32BIG_C(0x3a3275e8U), BSWAP_32BIG_C(0xa6c094f8U), BSWAP_32BIG_C(0x06195e17U), BSWAP_32BIG_C(
                        0x0cc151b8U),
                };
                r_rsip_func101(Param_func089_func101_006);
            }
            else
            {
                static const uint32_t Param_func089_func100_006[] =
                {
                    BSWAP_32BIG_C(0x98690ee5U), BSWAP_32BIG_C(0xeda89f72U), BSWAP_32BIG_C(0xb8b5b9bcU), BSWAP_32BIG_C(
                        0xddf73793U),
                };
                r_rsip_func100(Param_func089_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x06060004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0606000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub038(0x00000500U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x00000538U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0606000aU);

                r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000538U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_func_sub001(0x00c00031U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000500U, 0x06060009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x06060004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x06060013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x12c00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func089_func100_007[] =
                {
                    BSWAP_32BIG_C(0x6d9b0f4dU), BSWAP_32BIG_C(0xa0ad5d46U), BSWAP_32BIG_C(0x4a71ac4cU), BSWAP_32BIG_C(
                        0xf22d869eU),
                };
                r_rsip_func100(Param_func089_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func089_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x068efabeU), BSWAP_32BIG_C(0x4087e9bbU), BSWAP_32BIG_C(0x4b76c461U),
                        BSWAP_32BIG_C(0x748e9a47U),
                    };
                    r_rsip_func101(Param_func089_func101_007);
                }
                else
                {
                    static const uint32_t Param_func089_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x4903dac0U), BSWAP_32BIG_C(0x97fd2954U), BSWAP_32BIG_C(0xff44fc12U),
                        BSWAP_32BIG_C(0x684a3692U),
                    };
                    r_rsip_func100(Param_func089_func100_008);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x06060004U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x11300000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000002U);
                    r_rsip_func_sub001(0x00c0002dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0606000fU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    r_rsip_func_sub038(0x000001e0U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x06060002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000218U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x06060002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xaed65002U);

                    static const uint32_t Param_func089_func101_008[] =
                    {
                        BSWAP_32BIG_C(0xcdba852dU), BSWAP_32BIG_C(0xdef9e113U), BSWAP_32BIG_C(0x54d1e1efU),
                        BSWAP_32BIG_C(0x6527a054U),
                    };
                    r_rsip_func101(Param_func089_func101_008);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0xaed65002U, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
