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

rsip_ret_t r_rsip_p13 (const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00130001U, 0x000007f0U);

    static const uint32_t Param_p13_func100_001[] =
    {
        BSWAP_32BIG_C(0xf6549238U), BSWAP_32BIG_C(0x252b6f68U), BSWAP_32BIG_C(0x21072c06U), BSWAP_32BIG_C(0xf600878cU),
    };
    r_rsip_func100(Param_p13_func100_001);
    r_rsip_func086(InData_DomainParam);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

    WR1_PROG(REG_1404H, 0x12a00000U);
    r_rsip_func_sub009(0x00001301U);

    static const uint32_t Param_p13_func101_001[] =
    {
        BSWAP_32BIG_C(0x4da812a1U), BSWAP_32BIG_C(0xd76ca33eU), BSWAP_32BIG_C(0xae13f4b0U), BSWAP_32BIG_C(0xbc893ee2U),
    };
    r_rsip_func101(Param_p13_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80020000U);
    r_rsip_func_sub001(0x03420009U);
    r_rsip_func_sub022(0x00000800U, 0x00008c20U, 0x000001ffU);
    WR1_PROG(REG_1608H, 0x81020000U);
    r_rsip_func_sub001(0x00c90009U);
    r_rsip_func_sub001(0x00c20009U);

    r_rsip_func_sub009(0x00001302U);

    static const uint32_t Param_p13_func101_002[] =
    {
        BSWAP_32BIG_C(0x7fbad214U), BSWAP_32BIG_C(0x6fafb77bU), BSWAP_32BIG_C(0x74dfdde3U), BSWAP_32BIG_C(0xa11fdf1dU),
    };
    r_rsip_func101(Param_p13_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00001303U);

    static const uint32_t Param_p13_func101_003[] =
    {
        BSWAP_32BIG_C(0x946fe8b3U), BSWAP_32BIG_C(0xfd7cb732U), BSWAP_32BIG_C(0x52ab412aU), BSWAP_32BIG_C(0x07778c49U),
    };
    r_rsip_func101(Param_p13_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00001304U);

    static const uint32_t Param_p13_func101_004[] =
    {
        BSWAP_32BIG_C(0x0e594ab7U), BSWAP_32BIG_C(0xaeae8e2eU), BSWAP_32BIG_C(0x390235bcU), BSWAP_32BIG_C(0x4392f7ffU),
    };
    r_rsip_func101(Param_p13_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00001305U);

    static const uint32_t Param_p13_func101_005[] =
    {
        BSWAP_32BIG_C(0x77c2aa8bU), BSWAP_32BIG_C(0xf3676213U), BSWAP_32BIG_C(0x729c3884U), BSWAP_32BIG_C(0x4879e841U),
    };
    r_rsip_func101(Param_p13_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0909000aU);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub001(0x00c00009U);

    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x09090007U);

    static const uint32_t Param_p13_func100_002[] =
    {
        BSWAP_32BIG_C(0xc074ffafU), BSWAP_32BIG_C(0xf3aa39beU), BSWAP_32BIG_C(0x2e0fd942U), BSWAP_32BIG_C(0xe7eb7b7bU),
    };
    r_rsip_func100(Param_p13_func100_002);
    WR1_PROG(REG_1600H, 0x00000800U);
    r_rsip_func_sub031(0x00000821U, 0x00000863U, 0x12000000U);
    WR1_PROG(REG_1608H, 0x80940001U);
    r_rsip_func_sub001(0x03430051U);

    for (iLoop = 0U; iLoop < 20; iLoop++)
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

    WR1_PROG(REG_1404H, 0x14300000U);
    r_rsip_func_sub001(0x00c00051U);

    r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x0a0a0009U);

    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0004dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x00003403U);

    WR1_PROG(REG_1600H, 0x00003060U);

    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x0a0a0007U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x0a0a0009U);

        WR1_PROG(REG_1600H, 0x00003060U);

        static const uint32_t Param_p13_func101_006[] =
        {
            BSWAP_32BIG_C(0xcaff0b48U), BSWAP_32BIG_C(0x945e1f9cU), BSWAP_32BIG_C(0xfec2e444U), BSWAP_32BIG_C(
                0x89aa88edU),
        };
        r_rsip_func101(Param_p13_func101_006);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c03U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_func_sub001(0x00c00051U);

    static const uint32_t Param_p13_func100_003[] =
    {
        BSWAP_32BIG_C(0x9ab7bff1U), BSWAP_32BIG_C(0xaa64686cU), BSWAP_32BIG_C(0x1a614b25U), BSWAP_32BIG_C(0x2c7f5a30U),
    };
    r_rsip_func100(Param_p13_func100_003);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0a0a000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        static const uint32_t Param_p13_func100_004[] =
        {
            BSWAP_32BIG_C(0x2e434929U), BSWAP_32BIG_C(0x54d7676cU), BSWAP_32BIG_C(0x9cabe465U), BSWAP_32BIG_C(
                0xae40785aU),
        };
        r_rsip_func100(Param_p13_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x0a0a0009U);

            static const uint32_t Param_p13_func101_007[] =
            {
                BSWAP_32BIG_C(0xed99555bU), BSWAP_32BIG_C(0x94435b92U), BSWAP_32BIG_C(0x56009fc4U), BSWAP_32BIG_C(
                    0x539b10e5U),
            };
            r_rsip_func101(Param_p13_func101_007);
        }

        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_func_sub005(0x00000250U, 0x0a0a000cU, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x0a0a0009U);
        WR1_PROG(REG_1600H, 0x00003000U);

        static const uint32_t Param_p13_func101_008[] =
        {
            BSWAP_32BIG_C(0x9f18ffddU), BSWAP_32BIG_C(0x047e17c4U), BSWAP_32BIG_C(0x7fce3b32U), BSWAP_32BIG_C(
                0x569a1c99U),
        };
        r_rsip_func101(Param_p13_func101_008);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x09090009U);

    static const uint32_t Param_p13_func100_005[] =
    {
        BSWAP_32BIG_C(0x825e04e1U), BSWAP_32BIG_C(0x5d5d3547U), BSWAP_32BIG_C(0x39fc27ccU), BSWAP_32BIG_C(0x44e100bbU),
    };
    r_rsip_func100(Param_p13_func100_005);

    r_rsip_func087(InData_DomainParam);

    r_rsip_func_sub009(0x00000013U);

    static const uint32_t Param_p13_func101_009[] =
    {
        BSWAP_32BIG_C(0xd3d30f96U), BSWAP_32BIG_C(0x47de6a3dU), BSWAP_32BIG_C(0xcee6988bU), BSWAP_32BIG_C(0x805926b7U),
    };
    r_rsip_func101(Param_p13_func101_009);
    r_rsip_func091();

    static const uint32_t Param_p13_func100_006[] =
    {
        BSWAP_32BIG_C(0xf036ea02U), BSWAP_32BIG_C(0xacacf015U), BSWAP_32BIG_C(0x4d9e9dbcU), BSWAP_32BIG_C(0xbd4572a1U),
    };
    r_rsip_func100(Param_p13_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p13_func102_001[] =
        {
            BSWAP_32BIG_C(0x21957ff3U), BSWAP_32BIG_C(0xa831c700U), BSWAP_32BIG_C(0xa1d0cbedU), BSWAP_32BIG_C(
                0xf0cefee9U),
        };
        r_rsip_func102(Param_p13_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub009(0x00001306U);

        static const uint32_t Param_p13_func101_010[] =
        {
            BSWAP_32BIG_C(0xf9fd89c7U), BSWAP_32BIG_C(0x3f45632fU), BSWAP_32BIG_C(0x91a93ab7U), BSWAP_32BIG_C(
                0x18f9bf29U),
        };
        r_rsip_func101(Param_p13_func101_010);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x00000013U);

        static const uint32_t Param_p13_func101_011[] =
        {
            BSWAP_32BIG_C(0x78a77276U), BSWAP_32BIG_C(0x49256e4eU), BSWAP_32BIG_C(0x7e7bda9aU), BSWAP_32BIG_C(
                0x7d8fce33U),
        };
        r_rsip_func101(Param_p13_func101_011);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000025U);

        r_rsip_func_sub009(0x00000013U);

        static const uint32_t Param_p13_func101_012[] =
        {
            BSWAP_32BIG_C(0x9dc081acU), BSWAP_32BIG_C(0x7632cadbU), BSWAP_32BIG_C(0x911cdc31U), BSWAP_32BIG_C(
                0x91cbc794U),
        };
        r_rsip_func101(Param_p13_func101_012);
        r_rsip_func044();

        static const uint32_t Param_p13_func100_007[] =
        {
            BSWAP_32BIG_C(0x84b8a8c4U), BSWAP_32BIG_C(0x0e80b6a6U), BSWAP_32BIG_C(0xd1afa4cfU), BSWAP_32BIG_C(
                0x9bb4c339U),
        };
        r_rsip_func100(Param_p13_func100_007);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1404H, 0x12f80000U);
        r_rsip_func_sub001(0x00800009U);
        r_rsip_func_sub001(0x00830029U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_008[] =
        {
            BSWAP_32BIG_C(0x4c76db48U), BSWAP_32BIG_C(0x4e99450dU), BSWAP_32BIG_C(0x5ff570a2U), BSWAP_32BIG_C(
                0xda305fa3U),
        };
        r_rsip_func100(Param_p13_func100_008);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7008d07U);
        r_rsip_func_sub001(0x00830021U);

        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);

        static const uint32_t Param_p13_func100_009[] =
        {
            BSWAP_32BIG_C(0x9ca3cd86U), BSWAP_32BIG_C(0xba2ab1e1U), BSWAP_32BIG_C(0x693b5f08U), BSWAP_32BIG_C(
                0x8038a8d7U),
        };
        r_rsip_func100(Param_p13_func100_009);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 9]);

        static const uint32_t Param_p13_func100_010[] =
        {
            BSWAP_32BIG_C(0xa55c6052U), BSWAP_32BIG_C(0xf66ef960U), BSWAP_32BIG_C(0x69fcc632U), BSWAP_32BIG_C(
                0x40821a13U),
        };
        r_rsip_func100(Param_p13_func100_010);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        r_rsip_func_sub009(0x00001307U);

        static const uint32_t Param_p13_func101_013[] =
        {
            BSWAP_32BIG_C(0x02ebf1ebU), BSWAP_32BIG_C(0xd106327fU), BSWAP_32BIG_C(0xf5039c3bU), BSWAP_32BIG_C(
                0x3eb78e1dU),
        };
        r_rsip_func101(Param_p13_func101_013);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x00000113U);

        static const uint32_t Param_p13_func101_014[] =
        {
            BSWAP_32BIG_C(0xf8cf1b15U), BSWAP_32BIG_C(0x3a0e162bU), BSWAP_32BIG_C(0x4d8b54a8U), BSWAP_32BIG_C(
                0xe20473cbU),
        };
        r_rsip_func101(Param_p13_func101_014);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000024U);

        r_rsip_func_sub009(0x00000113U);

        static const uint32_t Param_p13_func101_015[] =
        {
            BSWAP_32BIG_C(0xe2d533e1U), BSWAP_32BIG_C(0x13a40594U), BSWAP_32BIG_C(0x9b3f607bU), BSWAP_32BIG_C(
                0xe4914970U),
        };
        r_rsip_func101(Param_p13_func101_015);
        r_rsip_func044();

        static const uint32_t Param_p13_func100_011[] =
        {
            BSWAP_32BIG_C(0x96f638c9U), BSWAP_32BIG_C(0x4106acb9U), BSWAP_32BIG_C(0x590466c9U), BSWAP_32BIG_C(
                0x08aaddfbU),
        };
        r_rsip_func100(Param_p13_func100_011);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        WR1_PROG(REG_1404H, 0x12580000U);
        r_rsip_func_sub001(0x00800009U);
        r_rsip_func_sub001(0x00830029U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_012[] =
        {
            BSWAP_32BIG_C(0xbe24f265U), BSWAP_32BIG_C(0x5b5c8c57U), BSWAP_32BIG_C(0x29ed8a16U), BSWAP_32BIG_C(
                0x2bdada7eU),
        };
        r_rsip_func100(Param_p13_func100_012);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830021U);
        WR1_PROG(REG_1404H, 0x12a80000U);
        r_rsip_func_sub001(0x00800009U);
        r_rsip_func_sub001(0x00830009U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 12; iLoop < 24U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_013[] =
        {
            BSWAP_32BIG_C(0x7c1776ebU), BSWAP_32BIG_C(0x5fb921a1U), BSWAP_32BIG_C(0x550b23fdU), BSWAP_32BIG_C(
                0x28df46fcU),
        };
        r_rsip_func100(Param_p13_func100_013);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 24; iLoop < 36; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_014[] =
        {
            BSWAP_32BIG_C(0x34096162U), BSWAP_32BIG_C(0xa09ba365U), BSWAP_32BIG_C(0x32d3a602U), BSWAP_32BIG_C(
                0x777b0c41U),
        };
        r_rsip_func100(Param_p13_func100_014);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);

        static const uint32_t Param_p13_func100_015[] =
        {
            BSWAP_32BIG_C(0x15230e4eU), BSWAP_32BIG_C(0x1e581ac5U), BSWAP_32BIG_C(0x5f16475fU), BSWAP_32BIG_C(
                0x507f016dU),
        };
        r_rsip_func100(Param_p13_func100_015);
        r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);

        static const uint32_t Param_p13_func100_016[] =
        {
            BSWAP_32BIG_C(0x7d489315U), BSWAP_32BIG_C(0x01507291U), BSWAP_32BIG_C(0xf01c013aU), BSWAP_32BIG_C(
                0x632f95d7U),
        };
        r_rsip_func100(Param_p13_func100_016);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_p13_func102_002[] =
        {
            BSWAP_32BIG_C(0x05a86ab7U), BSWAP_32BIG_C(0x2c3d547aU), BSWAP_32BIG_C(0x3a30f010U), BSWAP_32BIG_C(
                0xfb057b72U),
        };
        r_rsip_func102(Param_p13_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
