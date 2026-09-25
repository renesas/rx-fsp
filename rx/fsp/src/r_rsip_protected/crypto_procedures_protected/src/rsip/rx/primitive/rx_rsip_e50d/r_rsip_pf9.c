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

rsip_ret_t r_rsip_pf9 (const uint32_t InData_CurveType[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00f90001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_pf9_func100_001[] =
    {
        BSWAP_32BIG_C(0xe6c646dfU), BSWAP_32BIG_C(0xdfdfde80U), BSWAP_32BIG_C(0x5bf42cbbU), BSWAP_32BIG_C(0xcf85ae1dU),
    };
    r_rsip_func100(Param_pf9_func100_001);
    r_rsip_func027(InData_DomainParam);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

    WR1_PROG(REG_1404H, 0x12b80000U);
    r_rsip_func_sub009(0x0000f901U);

    static const uint32_t Param_pf9_func101_001[] =
    {
        BSWAP_32BIG_C(0xeec3eb47U), BSWAP_32BIG_C(0xeafdbe0bU), BSWAP_32BIG_C(0x61baa7ecU), BSWAP_32BIG_C(0x805f6605U),
    };
    r_rsip_func101(Param_pf9_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x0000f902U);

    static const uint32_t Param_pf9_func101_002[] =
    {
        BSWAP_32BIG_C(0x8e3b66a9U), BSWAP_32BIG_C(0xc1e577b5U), BSWAP_32BIG_C(0x7563a722U), BSWAP_32BIG_C(0xdb1f3093U),
    };
    r_rsip_func101(Param_pf9_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x0000f903U);

    static const uint32_t Param_pf9_func101_003[] =
    {
        BSWAP_32BIG_C(0xda80167fU), BSWAP_32BIG_C(0x6f636ea7U), BSWAP_32BIG_C(0x2c3d0689U), BSWAP_32BIG_C(0xc7eeca62U),
    };
    r_rsip_func101(Param_pf9_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x0000f904U);

    static const uint32_t Param_pf9_func101_004[] =
    {
        BSWAP_32BIG_C(0x34d823fbU), BSWAP_32BIG_C(0x5d038984U), BSWAP_32BIG_C(0xaa330045U), BSWAP_32BIG_C(0x8d0c0cdbU),
    };
    r_rsip_func101(Param_pf9_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    r_rsip_func_sub001(0x00c20009U);
    r_rsip_func_sub001(0x00020009U);

    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0606000aU);

    WR1_PROG(REG_1404H, 0x11280000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub001(0x00c00009U);

    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x06060007U);

    static const uint32_t Param_pf9_func100_002[] =
    {
        BSWAP_32BIG_C(0xeae205acU), BSWAP_32BIG_C(0x0d51110cU), BSWAP_32BIG_C(0x4c5e6958U), BSWAP_32BIG_C(0x97382994U),
    };
    r_rsip_func100(Param_pf9_func100_002);
    WR1_PROG(REG_1600H, 0x00000800U);
    r_rsip_func_sub031(0x00000821U, 0x00000863U, 0x12180000U);
    WR1_PROG(REG_1608H, 0x808e0001U);
    r_rsip_func_sub001(0x03430039U);

    for (iLoop = 0U; iLoop < 14U; iLoop++)
    {
        r_rsip_func_sub021(0x38000c63U, 0x20000842U, 0x10003841U, 0x0000b7c0U);
        WR1_PROG(REG_1600H, 0x0000001fU);

        for (jLoop = 0U; jLoop < 32U; jLoop++)
        {
            r_rsip_func_sub021(0x3800585eU, 0x20003460U, 0x20002c60U, 0x10002c00U);
            WR1_PROG(REG_1600H, 0x100033c0U);
        }

        r_rsip_func_sub034(0x0000a420U, 0x00000004U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x14480000U);
    r_rsip_func_sub001(0x00c00039U);

    r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);

    WR1_PROG(REG_1404H, 0x10d80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00035U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x00003403U);

    WR1_PROG(REG_1600H, 0x00003060U);

    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x07070007U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);

        WR1_PROG(REG_1600H, 0x00003060U);

        static const uint32_t Param_pf9_func101_005[] =
        {
            BSWAP_32BIG_C(0x9b51d023U), BSWAP_32BIG_C(0xab199f35U), BSWAP_32BIG_C(0x6e59b1adU), BSWAP_32BIG_C(
                0xa8b985e5U),
        };
        r_rsip_func101(Param_pf9_func101_005);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c03U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10d80000U);
    r_rsip_func_sub001(0x00c00039U);

    static const uint32_t Param_pf9_func100_003[] =
    {
        BSWAP_32BIG_C(0xeaa44cdaU), BSWAP_32BIG_C(0x6db65757U), BSWAP_32BIG_C(0x30ad4833U), BSWAP_32BIG_C(0x39d07e58U),
    };
    r_rsip_func100(Param_pf9_func100_003);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0707000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        static const uint32_t Param_pf9_func100_004[] =
        {
            BSWAP_32BIG_C(0x5968229eU), BSWAP_32BIG_C(0x1be96467U), BSWAP_32BIG_C(0x29fa81fcU), BSWAP_32BIG_C(
                0xa8caba20U),
        };
        r_rsip_func100(Param_pf9_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x07070009U);

            static const uint32_t Param_pf9_func101_006[] =
            {
                BSWAP_32BIG_C(0xfc663e98U), BSWAP_32BIG_C(0xa4f78262U), BSWAP_32BIG_C(0x371c42c4U), BSWAP_32BIG_C(
                    0x4c919f75U),
            };
            r_rsip_func101(Param_pf9_func101_006);
        }

        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_func_sub005(0x00000250U, 0x0707000cU, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x07070009U);
        WR1_PROG(REG_1600H, 0x00003000U);

        static const uint32_t Param_pf9_func101_007[] =
        {
            BSWAP_32BIG_C(0x94fe76a0U), BSWAP_32BIG_C(0xa4585755U), BSWAP_32BIG_C(0xb4cca4b7U), BSWAP_32BIG_C(
                0x9161b516U),
        };
        r_rsip_func101(Param_pf9_func101_007);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x06060009U);

    static const uint32_t Param_pf9_func100_005[] =
    {
        BSWAP_32BIG_C(0xb91784d8U), BSWAP_32BIG_C(0x1b2ff5f6U), BSWAP_32BIG_C(0xbc321b72U), BSWAP_32BIG_C(0xadb3fb9fU),
    };
    r_rsip_func100(Param_pf9_func100_005);
    r_rsip_func028(InData_DomainParam);

    r_rsip_func_sub009(0x000000f9U);

    static const uint32_t Param_pf9_func101_008[] =
    {
        BSWAP_32BIG_C(0xdb72100fU), BSWAP_32BIG_C(0x013365e3U), BSWAP_32BIG_C(0xe00fd49dU), BSWAP_32BIG_C(0xa5ffeb77U),
    };
    r_rsip_func101(Param_pf9_func101_008);
    r_rsip_func089();

    static const uint32_t Param_pf9_func100_006[] =
    {
        BSWAP_32BIG_C(0x1555fa74U), BSWAP_32BIG_C(0x02b18880U), BSWAP_32BIG_C(0x7958b238U), BSWAP_32BIG_C(0x2343a4a1U),
    };
    r_rsip_func100(Param_pf9_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf9_func102_001[] =
        {
            BSWAP_32BIG_C(0xc9d195e1U), BSWAP_32BIG_C(0xb071ade6U), BSWAP_32BIG_C(0x9567b0ddU), BSWAP_32BIG_C(
                0xc1a6e555U),
        };
        r_rsip_func102(Param_pf9_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub009(0x0000f905U);

        static const uint32_t Param_pf9_func101_009[] =
        {
            BSWAP_32BIG_C(0x78f46294U), BSWAP_32BIG_C(0xbea857e2U), BSWAP_32BIG_C(0xb432f638U), BSWAP_32BIG_C(
                0x0a1ba146U),
        };
        r_rsip_func101(Param_pf9_func101_009);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x000000f9U);

        static const uint32_t Param_pf9_func101_010[] =
        {
            BSWAP_32BIG_C(0xdc60abb1U), BSWAP_32BIG_C(0xbc01c3deU), BSWAP_32BIG_C(0xfb0c4482U), BSWAP_32BIG_C(
                0x192b67c4U),
        };
        r_rsip_func101(Param_pf9_func101_010);
        r_rsip_func043();

        r_rsip_func076();

        WR1_PROG(REG_1600H, 0x000034feU);

        r_rsip_func_sub009(0x000000f9U);

        static const uint32_t Param_pf9_func101_011[] =
        {
            BSWAP_32BIG_C(0x5107b4faU), BSWAP_32BIG_C(0xdb17f0faU), BSWAP_32BIG_C(0x201b5db4U), BSWAP_32BIG_C(
                0x223ef32bU),
        };
        r_rsip_func101(Param_pf9_func101_011);
        r_rsip_func044();

        static const uint32_t Param_pf9_func100_007[] =
        {
            BSWAP_32BIG_C(0x743571d8U), BSWAP_32BIG_C(0xcccd0e7cU), BSWAP_32BIG_C(0xb0ce3020U), BSWAP_32BIG_C(
                0x77f87da4U),
        };
        r_rsip_func100(Param_pf9_func100_007);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1404H, 0x13100000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);

        static const uint32_t Param_pf9_func100_008[] =
        {
            BSWAP_32BIG_C(0xe2a31b4cU), BSWAP_32BIG_C(0x73d6ad97U), BSWAP_32BIG_C(0x594d872bU), BSWAP_32BIG_C(
                0x5f3c6a05U),
        };
        r_rsip_func100(Param_pf9_func100_008);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[13]);

        static const uint32_t Param_pf9_func100_009[] =
        {
            BSWAP_32BIG_C(0xdc9349daU), BSWAP_32BIG_C(0x87ba4382U), BSWAP_32BIG_C(0x094ab8feU), BSWAP_32BIG_C(
                0xdc1233caU),
        };
        r_rsip_func100(Param_pf9_func100_009);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        r_rsip_func_sub009(0x0000f906U);

        static const uint32_t Param_pf9_func101_012[] =
        {
            BSWAP_32BIG_C(0x1498ce20U), BSWAP_32BIG_C(0xac14ca47U), BSWAP_32BIG_C(0x825cf34cU), BSWAP_32BIG_C(
                0x8605fcbeU),
        };
        r_rsip_func101(Param_pf9_func101_012);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x00000027U);

        static const uint32_t Param_pf9_func101_013[] =
        {
            BSWAP_32BIG_C(0x53469d7cU), BSWAP_32BIG_C(0x7a3fabdfU), BSWAP_32BIG_C(0x7c0660bdU), BSWAP_32BIG_C(
                0x511d2a5eU),
        };
        r_rsip_func101(Param_pf9_func101_013);
        r_rsip_func043();

        r_rsip_func077();

        WR1_PROG(REG_1600H, 0x000034feU);

        r_rsip_func_sub009(0x00000028U);

        static const uint32_t Param_pf9_func101_014[] =
        {
            BSWAP_32BIG_C(0x05a06fb9U), BSWAP_32BIG_C(0x1ea35965U), BSWAP_32BIG_C(0x793dcc59U), BSWAP_32BIG_C(
                0xaabf14d1U),
        };
        r_rsip_func101(Param_pf9_func101_014);
        r_rsip_func044();

        static const uint32_t Param_pf9_func100_010[] =
        {
            BSWAP_32BIG_C(0x6885f674U), BSWAP_32BIG_C(0x62f8640bU), BSWAP_32BIG_C(0xe444a252U), BSWAP_32BIG_C(
                0xe18803ecU),
        };
        r_rsip_func100(Param_pf9_func100_010);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        WR1_PROG(REG_1404H, 0x12700000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);

        static const uint32_t Param_pf9_func100_011[] =
        {
            BSWAP_32BIG_C(0x821192caU), BSWAP_32BIG_C(0x8a6b227aU), BSWAP_32BIG_C(0x0f763737U), BSWAP_32BIG_C(
                0xd6c23361U),
        };
        r_rsip_func100(Param_pf9_func100_011);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        WR1_PROG(REG_1404H, 0x12c00000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[13]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[21]);

        static const uint32_t Param_pf9_func100_012[] =
        {
            BSWAP_32BIG_C(0x1a6b5049U), BSWAP_32BIG_C(0x1ef077c3U), BSWAP_32BIG_C(0x7ac81e3cU), BSWAP_32BIG_C(
                0x0921be53U),
        };
        r_rsip_func100(Param_pf9_func100_012);
        r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[25]);

        static const uint32_t Param_pf9_func100_013[] =
        {
            BSWAP_32BIG_C(0x465a756dU), BSWAP_32BIG_C(0x2f189884U), BSWAP_32BIG_C(0x4e280a5aU), BSWAP_32BIG_C(
                0xa5201b22U),
        };
        r_rsip_func100(Param_pf9_func100_013);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_pf9_func102_002[] =
        {
            BSWAP_32BIG_C(0xfdea803fU), BSWAP_32BIG_C(0x311b9c31U), BSWAP_32BIG_C(0xa0e66590U), BSWAP_32BIG_C(
                0xd25a6c6cU),
        };
        r_rsip_func102(Param_pf9_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
