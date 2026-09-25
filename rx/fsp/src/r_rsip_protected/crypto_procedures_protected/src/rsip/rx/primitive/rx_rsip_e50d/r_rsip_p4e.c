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

rsip_ret_t r_rsip_p4e (const uint32_t InData_CurveType[],
                       const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x004e0001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_p4e_func100_001[] =
    {
        BSWAP_32BIG_C(0x468a760fU), BSWAP_32BIG_C(0x4e1cd107U), BSWAP_32BIG_C(0x9f81cd30U), BSWAP_32BIG_C(0xd628340bU),
    };
    r_rsip_func100(Param_p4e_func100_001);
    r_rsip_func027(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00004e01U);

    static const uint32_t Param_p4e_func101_001[] =
    {
        BSWAP_32BIG_C(0x02670065U), BSWAP_32BIG_C(0x7ebf6facU), BSWAP_32BIG_C(0x4da2354bU), BSWAP_32BIG_C(0x13f7726bU),
    };
    r_rsip_func101(Param_p4e_func101_001);
    r_rsip_func043();

    r_rsip_func076();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub009(0x00004e01U);

    static const uint32_t Param_p4e_func101_002[] =
    {
        BSWAP_32BIG_C(0x75e1fa9fU), BSWAP_32BIG_C(0x3a1e7fdfU), BSWAP_32BIG_C(0x49b65f11U), BSWAP_32BIG_C(0xa2a70d93U),
    };
    r_rsip_func101(Param_p4e_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x00000bc2U, 0x40000200U, 0xf7009d07U);

    for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x13100000U);
    r_rsip_func_sub001(0x00c20031U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p4e_func100_002[] =
    {
        BSWAP_32BIG_C(0x884da51fU), BSWAP_32BIG_C(0x9ff7b02cU), BSWAP_32BIG_C(0x5e648dd2U), BSWAP_32BIG_C(0x69c2f603U),
    };
    r_rsip_func100(Param_p4e_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p4e_func102_001[] =
        {
            BSWAP_32BIG_C(0x7e8bccbfU), BSWAP_32BIG_C(0x57d9e974U), BSWAP_32BIG_C(0xe96a01c4U), BSWAP_32BIG_C(
                0x0155c4b1U),
        };
        r_rsip_func102(Param_p4e_func102_001);
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

        static const uint32_t Param_p4e_func100_003[] =
        {
            BSWAP_32BIG_C(0x0b3710cfU), BSWAP_32BIG_C(0x136a029eU), BSWAP_32BIG_C(0x6bda616bU), BSWAP_32BIG_C(
                0x4af620a9U),
        };
        r_rsip_func100(Param_p4e_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x00000bd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 48U; iLoop = iLoop + 4U)
            {
                WR1_ADDR((&(REG_00E0H))[iLoop / 4], &InData_PubKey[0 + (iLoop / 4)]);
            }

            WR1_PROG(REG_1444H, 0x00000bd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 48U; iLoop = iLoop + 4U)
            {
                WR1_ADDR((&(REG_0130H))[iLoop / 4], &InData_PubKey[12 + (iLoop / 4)]);
            }

            static const uint32_t Param_p4e_func101_003[] =
            {
                BSWAP_32BIG_C(0x41903c89U), BSWAP_32BIG_C(0x3c062204U), BSWAP_32BIG_C(0x98e25e23U), BSWAP_32BIG_C(
                    0x5cb569dfU),
            };
            r_rsip_func101(Param_p4e_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00004e02U);

            static const uint32_t Param_p4e_func101_004[] =
            {
                BSWAP_32BIG_C(0xbd2de0dbU), BSWAP_32BIG_C(0xee0769cdU), BSWAP_32BIG_C(0x44ed5d05U), BSWAP_32BIG_C(
                    0xf5fba84fU),
            };
            r_rsip_func101(Param_p4e_func101_004);
            r_rsip_func043();

            r_rsip_func077();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub009(0x00004e02U);

            static const uint32_t Param_p4e_func101_005[] =
            {
                BSWAP_32BIG_C(0xed53e727U), BSWAP_32BIG_C(0x4106790dU), BSWAP_32BIG_C(0xfb2a3059U), BSWAP_32BIG_C(
                    0xef5bfdbcU),
            };
            r_rsip_func101(Param_p4e_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000017c2U, 0x40000500U, 0xe8009107U);
            WR4_ADDR(REG_1420H, &InData_PubKey[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[5]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[9]);

            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_func_sub001(0x00c20031U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[13]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[17]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[21]);

            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub001(0x00c20031U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[25]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p4e_func100_004[] =
            {
                BSWAP_32BIG_C(0x92d9c7e6U), BSWAP_32BIG_C(0x15558afeU), BSWAP_32BIG_C(0x054f09bcU), BSWAP_32BIG_C(
                    0x9b2d23d5U),
            };
            r_rsip_func100(Param_p4e_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4e_func102_002[] =
                {
                    BSWAP_32BIG_C(0xdb497e8fU), BSWAP_32BIG_C(0x3a88723cU), BSWAP_32BIG_C(0xa13d5709U), BSWAP_32BIG_C(
                        0xf7b00b55U),
                };
                r_rsip_func102(Param_p4e_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_p4e_func101_006[] =
                {
                    BSWAP_32BIG_C(0xf7b6aeb5U), BSWAP_32BIG_C(0x55b1cb0bU), BSWAP_32BIG_C(0x0c04ca14U), BSWAP_32BIG_C(
                        0x1c881d5aU),
                };
                r_rsip_func101(Param_p4e_func101_006);
            }
        }

        r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x000001b0U, 0x06060002U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x06060001U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x00000890U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x06060005U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x000001b0U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x06060002U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x000008e0U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x06060005U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x06060001U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000250U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000110U, 0x00000250U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p4e_func100_005[] =
        {
            BSWAP_32BIG_C(0x5a3101f2U), BSWAP_32BIG_C(0x46de19e4U), BSWAP_32BIG_C(0x403b3b61U), BSWAP_32BIG_C(
                0x04566ce4U),
        };
        r_rsip_func100(Param_p4e_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p4e_func102_003[] =
            {
                BSWAP_32BIG_C(0x4a289f74U), BSWAP_32BIG_C(0x363d6efaU), BSWAP_32BIG_C(0x7a40f333U), BSWAP_32BIG_C(
                    0x70281982U),
            };
            r_rsip_func102(Param_p4e_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_func_sub001(0x00c00031U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000218U, 0x06060009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x000001e0U, 0x06060009U);

            r_rsip_func_sub009(0x0000004eU);

            static const uint32_t Param_p4e_func101_007[] =
            {
                BSWAP_32BIG_C(0xd25693caU), BSWAP_32BIG_C(0x53c78320U), BSWAP_32BIG_C(0xae2d79d9U), BSWAP_32BIG_C(
                    0xda4fc1e5U),
            };
            r_rsip_func101(Param_p4e_func101_007);
            r_rsip_func089();

            static const uint32_t Param_p4e_func100_006[] =
            {
                BSWAP_32BIG_C(0xbd34d1d0U), BSWAP_32BIG_C(0x2cb93452U), BSWAP_32BIG_C(0xf1e862f0U), BSWAP_32BIG_C(
                    0x5e45fb43U),
            };
            r_rsip_func100(Param_p4e_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4e_func102_004[] =
                {
                    BSWAP_32BIG_C(0x6d1da9c0U), BSWAP_32BIG_C(0x5185abfaU), BSWAP_32BIG_C(0xcd3a7668U), BSWAP_32BIG_C(
                        0x90dbbf9eU),
                };
                r_rsip_func102(Param_p4e_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub009(0x0000004eU);

                static const uint32_t Param_p4e_func101_008[] =
                {
                    BSWAP_32BIG_C(0x2cd16409U), BSWAP_32BIG_C(0xa1cae5abU), BSWAP_32BIG_C(0x5e2a1abbU), BSWAP_32BIG_C(
                        0x42ac194bU),
                };
                r_rsip_func101(Param_p4e_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x00004e03U);

                static const uint32_t Param_p4e_func101_009[] =
                {
                    BSWAP_32BIG_C(0xc5e6edf0U), BSWAP_32BIG_C(0x59fee9d3U), BSWAP_32BIG_C(0xe15157bcU), BSWAP_32BIG_C(
                        0x25835619U),
                };
                r_rsip_func101(Param_p4e_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01245edbU);

                r_rsip_func_sub009(0x00004e03U);

                static const uint32_t Param_p4e_func101_010[] =
                {
                    BSWAP_32BIG_C(0x0401c5dbU), BSWAP_32BIG_C(0xf629cf8eU), BSWAP_32BIG_C(0x7b017331U), BSWAP_32BIG_C(
                        0x90ade34bU),
                };
                r_rsip_func101(Param_p4e_func101_010);
                r_rsip_func044();

                static const uint32_t Param_p4e_func100_007[] =
                {
                    BSWAP_32BIG_C(0x5016e723U), BSWAP_32BIG_C(0xb7997aa9U), BSWAP_32BIG_C(0xd4c25221U), BSWAP_32BIG_C(
                        0xc2ea0da7U),
                };
                r_rsip_func100(Param_p4e_func100_007);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12700000U);
                r_rsip_func_sub001(0x00830031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[5]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[9]);

                static const uint32_t Param_p4e_func100_008[] =
                {
                    BSWAP_32BIG_C(0x7316ad13U), BSWAP_32BIG_C(0x68adb7d6U), BSWAP_32BIG_C(0x3ccd7620U), BSWAP_32BIG_C(
                        0x515ca621U),
                };
                r_rsip_func100(Param_p4e_func100_008);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[13]);

                static const uint32_t Param_p4e_func100_009[] =
                {
                    BSWAP_32BIG_C(0x08060998U), BSWAP_32BIG_C(0x981b4c65U), BSWAP_32BIG_C(0x2cedca53U), BSWAP_32BIG_C(
                        0xa94bc67cU),
                };
                r_rsip_func100(Param_p4e_func100_009);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_p4e_func102_005[] =
                {
                    BSWAP_32BIG_C(0xf168cbf3U), BSWAP_32BIG_C(0x2a2dde62U), BSWAP_32BIG_C(0xed8596c1U), BSWAP_32BIG_C(
                        0xd8383417U),
                };
                r_rsip_func102(Param_p4e_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
