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

rsip_ret_t r_rsip_pf6 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00f60001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000f6U);

    static const uint32_t Param_pf6_func101_001[] =
    {
        BSWAP_32BIG_C(0xa3de73d3U), BSWAP_32BIG_C(0xa9e4877fU), BSWAP_32BIG_C(0xd2147ae9U), BSWAP_32BIG_C(0x3ec4fa20U),
    };
    r_rsip_func101(Param_pf6_func101_001);
    r_rsip_func043();

    r_rsip_func077();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub009(0x000000f6U);

    static const uint32_t Param_pf6_func101_002[] =
    {
        BSWAP_32BIG_C(0x2eb65089U), BSWAP_32BIG_C(0x2bd50a47U), BSWAP_32BIG_C(0x96789462U), BSWAP_32BIG_C(0x9dda7ec8U),
    };
    r_rsip_func101(Param_pf6_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000017c2U, 0x40000500U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80980001U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
    r_rsip_func_sub001(0x03420031U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[21]);
    r_rsip_func_sub001(0x03420031U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[25]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pf6_func100_001[] =
    {
        BSWAP_32BIG_C(0xba4d9dfcU), BSWAP_32BIG_C(0xb9d7152bU), BSWAP_32BIG_C(0x35ee078bU), BSWAP_32BIG_C(0xfa21a934U),
    };
    r_rsip_func100(Param_pf6_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf6_func102_001[] =
        {
            BSWAP_32BIG_C(0xc5fee6aaU), BSWAP_32BIG_C(0x6b496f0bU), BSWAP_32BIG_C(0x568951c6U), BSWAP_32BIG_C(
                0xe0bb968bU),
        };
        r_rsip_func102(Param_pf6_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000bc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x808c001fU);
        for (iLoop = 0U; iLoop < 12U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x80010360U, 0x000000f6U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_pf6_func100_002[] =
        {
            BSWAP_32BIG_C(0xdd88ee2eU), BSWAP_32BIG_C(0x7716d6f7U), BSWAP_32BIG_C(0x95a1d52bU), BSWAP_32BIG_C(
                0xfd70079bU),
        };
        r_rsip_func100(Param_pf6_func100_002);
        r_rsip_func027(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

        WR1_PROG(REG_1404H, 0x19000000U);
        r_rsip_func_sub008(0x000017c2U, 0x00000500U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x19500000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x11d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0606000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pf6_func100_003[] =
        {
            BSWAP_32BIG_C(0x513cef27U), BSWAP_32BIG_C(0x526137b0U), BSWAP_32BIG_C(0x18925900U), BSWAP_32BIG_C(
                0xcb89a8b2U),
        };
        r_rsip_func100(Param_pf6_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_pf6_func101_003[] =
            {
                BSWAP_32BIG_C(0xc2904074U), BSWAP_32BIG_C(0x733f7bc8U), BSWAP_32BIG_C(0xaf187adbU), BSWAP_32BIG_C(
                    0x518384a9U),
            };
            r_rsip_func101(Param_pf6_func101_003);
        }
        else
        {
            static const uint32_t Param_pf6_func100_004[] =
            {
                BSWAP_32BIG_C(0xe07c3becU), BSWAP_32BIG_C(0x56a10adaU), BSWAP_32BIG_C(0xf7004b1eU), BSWAP_32BIG_C(
                    0x592aa700U),
            };
            r_rsip_func100(Param_pf6_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0606000aU);

            r_rsip_func_sub041(0x00000980U, 0x000001b0U, 0x000000c0U, 0x00000110U, 0x00000020U, 0x0606000fU);
            r_rsip_func_sub035(0x00010001U);

            r_rsip_func_sub038(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub030(0x10e00000U, 0x00000bffU, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub038(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x06060002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub001(0x00c00031U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x06060004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002b8U, 0x06060009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x06060009U);

            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1608H, 0x818c0001U);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a00U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10e00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1608H, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a38U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_pf6_func100_005[] =
            {
                BSWAP_32BIG_C(0x150c3bcbU), BSWAP_32BIG_C(0xad212e18U), BSWAP_32BIG_C(0xb763ea55U), BSWAP_32BIG_C(
                    0xb8cab14dU),
            };
            r_rsip_func100(Param_pf6_func100_005);
            r_rsip_func028(InData_DomainParam);

            r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000af0U, 0x06060009U);

            r_rsip_func_sub002(0x00000218U, 0x00000160U, 0x00000b28U, 0x06060009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x06060009U);

            r_rsip_func_sub002(0x00000af0U, 0x00000a00U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a00U, 0x00000af0U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b28U, 0x00000a38U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a38U, 0x00000b28U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_pf6_func100_006[] =
            {
                BSWAP_32BIG_C(0x53b54c67U), BSWAP_32BIG_C(0xace227deU), BSWAP_32BIG_C(0xf7021a59U), BSWAP_32BIG_C(
                    0x99950b0bU),
            };
            r_rsip_func100(Param_pf6_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub038(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x06060013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_pf6_func101_004[] =
                {
                    BSWAP_32BIG_C(0x06376c5aU), BSWAP_32BIG_C(0x903fd9b0U), BSWAP_32BIG_C(0x6fa70f9eU), BSWAP_32BIG_C(
                        0x6c41b408U),
                };
                r_rsip_func101(Param_pf6_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x06060014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_pf6_func101_005[] =
                {
                    BSWAP_32BIG_C(0x87fa6db5U), BSWAP_32BIG_C(0xc8b35088U), BSWAP_32BIG_C(0xb0825331U), BSWAP_32BIG_C(
                        0x5a256941U),
                };
                r_rsip_func101(Param_pf6_func101_005);
            }

            WR1_PROG(REG_1600H, 0x00000821U);

            WR1_PROG(REG_1404H, 0x14500000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            r_rsip_func_sub031(0x0000a420U, 0x00000050U, 0x13100000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 12U; iLoop++)
            {
                r_rsip_func_sub021(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub022(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11300000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0002dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_pf6_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x435733c9U), BSWAP_32BIG_C(0x45d06110U), BSWAP_32BIG_C(0xc06c9001U),
                        BSWAP_32BIG_C(0xce03acdfU),
                    };
                    r_rsip_func100(Param_pf6_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_pf6_func101_006[] =
                        {
                            BSWAP_32BIG_C(0xd3a3b344U), BSWAP_32BIG_C(0xb41c79d6U), BSWAP_32BIG_C(0x487d45d5U),
                            BSWAP_32BIG_C(0x243f2feaU),
                        };
                        r_rsip_func101(Param_pf6_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_pf6_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x4e653582U), BSWAP_32BIG_C(0xd1e5d713U), BSWAP_32BIG_C(0xfc94cbc8U),
                            BSWAP_32BIG_C(0xb9df6b0aU),
                        };
                        r_rsip_func101(Param_pf6_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_pf6_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x070d31c9U), BSWAP_32BIG_C(0x8aa282f8U), BSWAP_32BIG_C(0x8d154514U),
                        BSWAP_32BIG_C(0xffdb8076U),
                    };
                    r_rsip_func100(Param_pf6_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_pf6_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x040189d4U), BSWAP_32BIG_C(0x001445a0U), BSWAP_32BIG_C(0xd941dd1cU),
                            BSWAP_32BIG_C(0xdde50844U),
                        };
                        r_rsip_func100(Param_pf6_func100_009);

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub001(0x00c00031U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x00000a00U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a38U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x12e61795U), BSWAP_32BIG_C(0xc3814450U), BSWAP_32BIG_C(0x17d6b7e3U),
                                BSWAP_32BIG_C(0xbcddb4cfU),
                            };
                            r_rsip_func101(Param_pf6_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000af0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b28U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_009[] =
                            {
                                BSWAP_32BIG_C(0xe2090901U), BSWAP_32BIG_C(0xaea5d491U), BSWAP_32BIG_C(0x44706fbeU),
                                BSWAP_32BIG_C(0x17749aafU),
                            };
                            r_rsip_func101(Param_pf6_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000be0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c18U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x64ca47fbU), BSWAP_32BIG_C(0xf1208697U), BSWAP_32BIG_C(0x788cdbb6U),
                                BSWAP_32BIG_C(0xc4adc966U),
                            };
                            r_rsip_func101(Param_pf6_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c0002dU);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_pf6_func100_010[] =
                        {
                            BSWAP_32BIG_C(0xefbb7d17U), BSWAP_32BIG_C(0x51f4eb29U), BSWAP_32BIG_C(0x9cc83aa1U),
                            BSWAP_32BIG_C(0x647cfd0bU),
                        };
                        r_rsip_func100(Param_pf6_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_pf6_func100_011[] =
                            {
                                BSWAP_32BIG_C(0xb8f5dd7eU), BSWAP_32BIG_C(0xa96d54fdU), BSWAP_32BIG_C(0x55cdb97cU),
                                BSWAP_32BIG_C(0xdd3e1a03U),
                            };
                            r_rsip_func100(Param_pf6_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001e0U, 0x00000410U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000410U, 0x000001e0U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000218U, 0x00000448U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000448U, 0x00000218U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_pf6_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0x4b6997dbU), BSWAP_32BIG_C(0xcbeec62eU), BSWAP_32BIG_C(0xb9a7c271U),
                                    BSWAP_32BIG_C(0xa9022cf8U),
                                };
                                r_rsip_func100(Param_pf6_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub038(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_pf6_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x8e568209U), BSWAP_32BIG_C(0xaf3f07ccU), BSWAP_32BIG_C(
                                            0xb9c825d7U),           BSWAP_32BIG_C(0x577724b5U),
                                    };
                                    r_rsip_func101(Param_pf6_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_pf6_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x74181af3U), BSWAP_32BIG_C(0xb7e1bf64U), BSWAP_32BIG_C(
                                            0x198e54d5U),           BSWAP_32BIG_C(0x8835c2c9U),
                                    };
                                    r_rsip_func101(Param_pf6_func101_012);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                            }
                            else
                            {
                                static const uint32_t Param_pf6_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x6cab7581U), BSWAP_32BIG_C(0xe8013c8eU), BSWAP_32BIG_C(0xe597e78eU),
                                    BSWAP_32BIG_C(0x0422a0dfU),
                                };
                                r_rsip_func101(Param_pf6_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11300000U);
                            r_rsip_func_sub001(0x00c00031U);

                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x000001e0U, 0x06060009U);

                            r_rsip_func_sub002(0x00000448U, 0x00000160U, 0x00000218U, 0x06060009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_014[] =
                            {
                                BSWAP_32BIG_C(0xda8f2349U), BSWAP_32BIG_C(0xc4e87d12U), BSWAP_32BIG_C(0x14c52c3fU),
                                BSWAP_32BIG_C(0x96a72eceU),
                            };
                            r_rsip_func101(Param_pf6_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_pf6_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x44134fdbU), BSWAP_32BIG_C(0x895d41e3U), BSWAP_32BIG_C(0x31373199U),
                            BSWAP_32BIG_C(0x24417897U),
                        };
                        r_rsip_func101(Param_pf6_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_pf6_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xd7944a4cU), BSWAP_32BIG_C(0xfd1fc8a6U), BSWAP_32BIG_C(0xadc76be7U),
                        BSWAP_32BIG_C(0xea5dfc10U),
                    };
                    r_rsip_func101(Param_pf6_func101_016);
                }

                WR1_PROG(REG_1600H, 0x38008840U);
                r_rsip_func_sub011(0x00000020U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_pf6_func101_017[] =
                {
                    BSWAP_32BIG_C(0xb313332cU), BSWAP_32BIG_C(0x113f682cU), BSWAP_32BIG_C(0x612b5dc8U), BSWAP_32BIG_C(
                        0x485c887eU),
                };
                r_rsip_func101(Param_pf6_func101_017);
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            r_rsip_func_sub011(0x0000000cU);

            WR1_PROG(REG_1404H, 0x12700000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_pf6_func100_013[] =
            {
                BSWAP_32BIG_C(0xd2251688U), BSWAP_32BIG_C(0x054857b1U), BSWAP_32BIG_C(0xffd61484U), BSWAP_32BIG_C(
                    0x086e70f6U),
            };
            r_rsip_func100(Param_pf6_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_pf6_func101_018[] =
                {
                    BSWAP_32BIG_C(0x1bece372U), BSWAP_32BIG_C(0x27c94da4U), BSWAP_32BIG_C(0xb33359d2U), BSWAP_32BIG_C(
                        0x8f37e08bU),
                };
                r_rsip_func101(Param_pf6_func101_018);
            }
            else
            {
                static const uint32_t Param_pf6_func100_014[] =
                {
                    BSWAP_32BIG_C(0x522e41d1U), BSWAP_32BIG_C(0x40d431a7U), BSWAP_32BIG_C(0x3976bb9dU), BSWAP_32BIG_C(
                        0xd3810fd0U),
                };
                r_rsip_func100(Param_pf6_func100_014);

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
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_pf6_func100_015[] =
                {
                    BSWAP_32BIG_C(0x0f7a33ffU), BSWAP_32BIG_C(0xea78e937U), BSWAP_32BIG_C(0xcb51ab52U), BSWAP_32BIG_C(
                        0xfa717853U),
                };
                r_rsip_func100(Param_pf6_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_pf6_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xd2e1b239U), BSWAP_32BIG_C(0xb7d29bf6U), BSWAP_32BIG_C(0x36d194ffU),
                        BSWAP_32BIG_C(0xa8db62ecU),
                    };
                    r_rsip_func101(Param_pf6_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xa69ef2d0U);

                    static const uint32_t Param_pf6_func101_020[] =
                    {
                        BSWAP_32BIG_C(0xcbad9781U), BSWAP_32BIG_C(0xbb5248f1U), BSWAP_32BIG_C(0xe51b9542U),
                        BSWAP_32BIG_C(0xe103cf85U),
                    };
                    r_rsip_func101(Param_pf6_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0xa69ef2d0U, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_pf6_func100_016[] =
        {
            BSWAP_32BIG_C(0x748fe168U), BSWAP_32BIG_C(0xa02586b8U), BSWAP_32BIG_C(0x1da95a83U), BSWAP_32BIG_C(
                0xaad21331U),
        };
        r_rsip_func100(Param_pf6_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf6_func102_002[] =
            {
                BSWAP_32BIG_C(0x946ff484U), BSWAP_32BIG_C(0x0248f1e9U), BSWAP_32BIG_C(0x37ea062fU), BSWAP_32BIG_C(
                    0x9e0c88caU),
            };
            r_rsip_func102(Param_pf6_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf6_func102_003[] =
            {
                BSWAP_32BIG_C(0xf4ca6e63U), BSWAP_32BIG_C(0xb6e2ff46U), BSWAP_32BIG_C(0x3428d3eeU), BSWAP_32BIG_C(
                    0xb913d379U),
            };
            r_rsip_func102(Param_pf6_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
