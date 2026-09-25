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

rsip_ret_t r_rsip_p4f (const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x004f0001U, 0x000007f0U);

    static const uint32_t Param_p4f_func100_001[] =
    {
        BSWAP_32BIG_C(0xeb799b4dU), BSWAP_32BIG_C(0x8f92856cU), BSWAP_32BIG_C(0xb2954b6fU), BSWAP_32BIG_C(0xe8d68effU),
    };
    r_rsip_func100(Param_p4f_func100_001);
    r_rsip_func086(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00004f01U);

    static const uint32_t Param_p4f_func101_001[] =
    {
        BSWAP_32BIG_C(0x61ac9a4cU), BSWAP_32BIG_C(0x0c6058e4U), BSWAP_32BIG_C(0x8f877b18U), BSWAP_32BIG_C(0x7222ac17U),
    };
    r_rsip_func101(Param_p4f_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000025U);

    r_rsip_func_sub009(0x00004f01U);

    static const uint32_t Param_p4f_func101_002[] =
    {
        BSWAP_32BIG_C(0xdd3e9d92U), BSWAP_32BIG_C(0x0308dca3U), BSWAP_32BIG_C(0xe5b1880eU), BSWAP_32BIG_C(0x10eb8445U),
    };
    r_rsip_func101(Param_p4f_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x000013c2U, 0x40000400U, 0xf7009d07U);

    WR1_PROG(REG_1404H, 0x12f00000U);

    for (iLoop = 0U; iLoop < 20; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        r_rsip_func_sub001(0x00c20011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p4f_func100_002[] =
    {
        BSWAP_32BIG_C(0xe63a4c4cU), BSWAP_32BIG_C(0x165e99ccU), BSWAP_32BIG_C(0x977b2732U), BSWAP_32BIG_C(0x182669d6U),
    };
    r_rsip_func100(Param_p4f_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p4f_func102_001[] =
        {
            BSWAP_32BIG_C(0x47b19ce0U), BSWAP_32BIG_C(0x36ebee4bU), BSWAP_32BIG_C(0x478ce112U), BSWAP_32BIG_C(
                0x8db7dd08U),
        };
        r_rsip_func102(Param_p4f_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010360U);
        WR1_PROG(REG_1420H, InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000f7bU, 0x00260000U);

        static const uint32_t Param_p4f_func100_003[] =
        {
            BSWAP_32BIG_C(0x7e11b205U), BSWAP_32BIG_C(0x1676d7e3U), BSWAP_32BIG_C(0xa54af12cU), BSWAP_32BIG_C(
                0xe70452efU),
        };
        r_rsip_func100(Param_p4f_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000bdeU);

            WR1_PROG(REG_1444H, 0x000027c7U);
            WR1_PROG(REG_1608H, 0x80a8001eU);
            for (iLoop = 0U; iLoop < 40U; iLoop++)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_PubKey[iLoop]);
            }

            r_rsip_func_sub034(0x00000bffU, 0x00000bbdU);

            for (iLoop = 0U; iLoop < 2U; iLoop++)
            {
                for (jLoop = 0U; jLoop < 3U; jLoop++)
                {
                    r_rsip_func_sub021(0x0000381eU, 0x38000c00U, 0x100053fdU, 0x00002fa0U);
                    WR1_PROG(REG_1600H, 0x0000a7c0U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub021(0x0000381eU, 0x38008c00U, 0xfffffe00U, 0x100053fdU);

                r_rsip_func_sub022(0x00002fa0U, 0x0000b7c0U, 0x00000050U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub006(0x38008be0U, 0x000000ffU, 0x00A60000U);

            static const uint32_t Param_p4f_func100_004[] =
            {
                BSWAP_32BIG_C(0xb77bee59U), BSWAP_32BIG_C(0x54741c37U), BSWAP_32BIG_C(0x58da0e06U), BSWAP_32BIG_C(
                    0xb37ed25eU),
            };
            r_rsip_func100(Param_p4f_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4f_func102_002[] =
                {
                    BSWAP_32BIG_C(0x76117c7eU), BSWAP_32BIG_C(0xd571f3d1U), BSWAP_32BIG_C(0x5d41a9acU), BSWAP_32BIG_C(
                        0xc98701d5U),
                };
                r_rsip_func102(Param_p4f_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p4f_func101_003[] =
                {
                    BSWAP_32BIG_C(0x2fb852bdU), BSWAP_32BIG_C(0x7e0d30ceU), BSWAP_32BIG_C(0xf3813fc9U), BSWAP_32BIG_C(
                        0x4258d2bcU),
                };
                r_rsip_func101(Param_p4f_func101_003);
            }
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00004f02U);

            static const uint32_t Param_p4f_func101_004[] =
            {
                BSWAP_32BIG_C(0xe0a56641U), BSWAP_32BIG_C(0x7f6e5710U), BSWAP_32BIG_C(0x04fd9f4aU), BSWAP_32BIG_C(
                    0x2625cceaU),
            };
            r_rsip_func101(Param_p4f_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000024U);

            r_rsip_func_sub009(0x00004f02U);

            static const uint32_t Param_p4f_func101_005[] =
            {
                BSWAP_32BIG_C(0x435b5153U), BSWAP_32BIG_C(0x36bcac3aU), BSWAP_32BIG_C(0xecf410c7U), BSWAP_32BIG_C(
                    0xb7e68acdU),
            };
            r_rsip_func101(Param_p4f_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub024(0x000027c2U, 0x40000900U, 0xe8009107U);

            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1608H, 0x80a8001eU);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[5]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[9]);
            r_rsip_func_sub001(0x03420031U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[13]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[17]);
            r_rsip_func_sub001(0x03420021U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[21]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[25]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[29]);
            r_rsip_func_sub001(0x03420031U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[33]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[37]);
            r_rsip_func_sub001(0x03420021U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[41]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p4f_func100_005[] =
            {
                BSWAP_32BIG_C(0x8b13b055U), BSWAP_32BIG_C(0x267d1caeU), BSWAP_32BIG_C(0xfe6e73c0U), BSWAP_32BIG_C(
                    0x68e13b89U),
            };
            r_rsip_func100(Param_p4f_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x8c0688c3U), BSWAP_32BIG_C(0x468f8d84U), BSWAP_32BIG_C(0x0332788dU), BSWAP_32BIG_C(
                        0xb0bdbfc7U),
                };
                r_rsip_func102(Param_p4f_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_p4f_func101_006[] =
                {
                    BSWAP_32BIG_C(0x93cc866aU), BSWAP_32BIG_C(0x83609f8fU), BSWAP_32BIG_C(0xbe6baf03U), BSWAP_32BIG_C(
                        0xb270e00bU),
                };
                r_rsip_func101(Param_p4f_func101_006);
            }
        }

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x81a8001eU);
        WR1_PROG(REG_1404H, 0x10c00000U);
        r_rsip_func_sub001(0x00c90051U);

        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func_sub001(0x00c90051U);

        r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x000001b0U, 0x09090002U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x09090001U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x00000890U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x09090005U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x000001b0U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x09090002U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x000008e0U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x09090005U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x09090001U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000250U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000110U, 0x00000250U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p4f_func100_006[] =
        {
            BSWAP_32BIG_C(0x3f196374U), BSWAP_32BIG_C(0x73254bd2U), BSWAP_32BIG_C(0xf337fd87U), BSWAP_32BIG_C(
                0xa7c1e169U),
        };
        r_rsip_func100(Param_p4f_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p4f_func102_004[] =
            {
                BSWAP_32BIG_C(0x46457ecdU), BSWAP_32BIG_C(0xc38e34b7U), BSWAP_32BIG_C(0xd17ca57bU), BSWAP_32BIG_C(
                    0xba9185f9U),
            };
            r_rsip_func102(Param_p4f_func102_004);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10c80000U);
            r_rsip_func_sub001(0x00c00049U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000200U, 0x09090009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x000001b0U, 0x09090009U);

            r_rsip_func_sub009(0x0000004fU);

            static const uint32_t Param_p4f_func101_007[] =
            {
                BSWAP_32BIG_C(0x3afd5a09U), BSWAP_32BIG_C(0x0e6c041eU), BSWAP_32BIG_C(0x23483e31U), BSWAP_32BIG_C(
                    0xe25a9e50U),
            };
            r_rsip_func101(Param_p4f_func101_007);
            r_rsip_func091();

            static const uint32_t Param_p4f_func100_007[] =
            {
                BSWAP_32BIG_C(0x482e8036U), BSWAP_32BIG_C(0x9bc9b53eU), BSWAP_32BIG_C(0x06c79274U), BSWAP_32BIG_C(
                    0x55e01d5eU),
            };
            r_rsip_func100(Param_p4f_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4f_func102_005[] =
                {
                    BSWAP_32BIG_C(0x490fd554U), BSWAP_32BIG_C(0xd4453499U), BSWAP_32BIG_C(0x78871daaU), BSWAP_32BIG_C(
                        0x244776a6U),
                };
                r_rsip_func102(Param_p4f_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub009(0x0000004fU);

                static const uint32_t Param_p4f_func101_008[] =
                {
                    BSWAP_32BIG_C(0x437826c4U), BSWAP_32BIG_C(0x9ecf6405U), BSWAP_32BIG_C(0x6ac0e3c0U), BSWAP_32BIG_C(
                        0x9b12ed6bU),
                };
                r_rsip_func101(Param_p4f_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x00004f03U);

                static const uint32_t Param_p4f_func101_009[] =
                {
                    BSWAP_32BIG_C(0xa655a032U), BSWAP_32BIG_C(0x59d06541U), BSWAP_32BIG_C(0xb4f27919U), BSWAP_32BIG_C(
                        0x39c74bd3U),
                };
                r_rsip_func101(Param_p4f_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x0161bb7bU);

                r_rsip_func_sub009(0x00004f03U);

                static const uint32_t Param_p4f_func101_010[] =
                {
                    BSWAP_32BIG_C(0xa3de2e40U), BSWAP_32BIG_C(0x73d3a17fU), BSWAP_32BIG_C(0x8ba58c02U), BSWAP_32BIG_C(
                        0xd19e54f1U),
                };
                r_rsip_func101(Param_p4f_func101_010);
                r_rsip_func044();

                static const uint32_t Param_p4f_func100_008[] =
                {
                    BSWAP_32BIG_C(0xb15a2f3eU), BSWAP_32BIG_C(0xcfe7f648U), BSWAP_32BIG_C(0x9ca6e13aU), BSWAP_32BIG_C(
                        0xf109b677U),
                };
                r_rsip_func100(Param_p4f_func100_008);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12580000U);
                r_rsip_func_sub001(0x00800009U);
                r_rsip_func_sub001(0x00830029U);

                WR1_PROG(REG_1408H, 0x00002032U);
                for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
                {
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 1]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p4f_func100_009[] =
                {
                    BSWAP_32BIG_C(0x0d58920cU), BSWAP_32BIG_C(0x4cd36deaU), BSWAP_32BIG_C(0x296600adU), BSWAP_32BIG_C(
                        0xcb54ccadU),
                };
                r_rsip_func100(Param_p4f_func100_009);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7008d07U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 5]);
                static const uint32_t Param_p4f_func100_010[] =
                {
                    BSWAP_32BIG_C(0xebecd227U), BSWAP_32BIG_C(0x7ccd31d7U), BSWAP_32BIG_C(0xbab52e93U), BSWAP_32BIG_C(
                        0x881b4a76U),
                };
                r_rsip_func100(Param_p4f_func100_010);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 9]);

                static const uint32_t Param_p4f_func100_011[] =
                {
                    BSWAP_32BIG_C(0x1c0d1f63U), BSWAP_32BIG_C(0x26a7859eU), BSWAP_32BIG_C(0xc12885bfU), BSWAP_32BIG_C(
                        0x6e1f8112U),
                };
                r_rsip_func100(Param_p4f_func100_011);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_p4f_func102_006[] =
                {
                    BSWAP_32BIG_C(0xd28271dfU), BSWAP_32BIG_C(0x8b3d8c4eU), BSWAP_32BIG_C(0x2acbf76eU), BSWAP_32BIG_C(
                        0xc02bf75aU),
                };
                r_rsip_func102(Param_p4f_func102_006);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
