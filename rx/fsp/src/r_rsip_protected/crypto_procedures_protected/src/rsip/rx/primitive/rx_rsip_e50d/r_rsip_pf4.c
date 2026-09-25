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

rsip_ret_t r_rsip_pf4 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
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

    r_rsip_func_sub029(0x00f40001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010380U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3020ab80U, 0x00000003U, 0x00060020U, 0x0000b780U);
    r_rsip_func_sub021(0x00000002U, 0x00000080U, 0x00000bffU, 0x30000f5aU);
    r_rsip_func_sub021(0x00030020U, 0x0000d3e1U, 0x00000060U, 0x38000f9cU);
    r_rsip_func_sub021(0x1000d3e1U, 0x00000080U, 0x38008be0U, 0x00000002U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    static const uint32_t Param_pf4_func100_001[] =
    {
        BSWAP_32BIG_C(0x31e5cb2cU), BSWAP_32BIG_C(0xc2913237U), BSWAP_32BIG_C(0x48fd0049U), BSWAP_32BIG_C(0x064de0d8U),
    };
    r_rsip_func100(Param_pf4_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf4_func102_001[] =
        {
            BSWAP_32BIG_C(0x04b7d2adU), BSWAP_32BIG_C(0xf8066c45U), BSWAP_32BIG_C(0x040263b4U), BSWAP_32BIG_C(
                0x141a876fU),
        };
        r_rsip_func102(Param_pf4_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pf4_func100_002[] =
        {
            BSWAP_32BIG_C(0x96a09c21U), BSWAP_32BIG_C(0x72f9a7a3U), BSWAP_32BIG_C(0xbe0dc410U), BSWAP_32BIG_C(
                0x128fc331U),
        };
        r_rsip_func100(Param_pf4_func100_002);
        r_rsip_func070(InData_DomainParam);

        static const uint32_t Param_pf4_func100_003[] =
        {
            BSWAP_32BIG_C(0x72cfad25U), BSWAP_32BIG_C(0xbb2ff180U), BSWAP_32BIG_C(0xe6ff8c10U), BSWAP_32BIG_C(
                0xba2fb576U),
        };
        r_rsip_func100(Param_pf4_func100_003);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x04040010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

        WR1_PROG(REG_1404H, 0x12c80000U);

        r_rsip_func_sub014(0x00007c1cU, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            r_rsip_func_sub001(0x00c00009U);
            r_rsip_func_sub009(0x0000f401U);

            static const uint32_t Param_pf4_func101_001[] =
            {
                BSWAP_32BIG_C(0xe5fdbba5U), BSWAP_32BIG_C(0xfae3c1adU), BSWAP_32BIG_C(0x23c1a819U), BSWAP_32BIG_C(
                    0x23ee0a4aU),
            };
            r_rsip_func101(Param_pf4_func101_001);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);
            r_rsip_func_sub001(0x00c20009U);
            r_rsip_func_sub001(0x00020009U);

            static const uint32_t Param_pf4_func101_002[] =
            {
                BSWAP_32BIG_C(0x8febe981U), BSWAP_32BIG_C(0x77707e2eU), BSWAP_32BIG_C(0x1be6eceaU), BSWAP_32BIG_C(
                    0x4956cd8cU),
            };
            r_rsip_func101(Param_pf4_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub001(0x00c0000dU);

            r_rsip_func_sub009(0x0000f402U);

            static const uint32_t Param_pf4_func101_003[] =
            {
                BSWAP_32BIG_C(0x653f324bU), BSWAP_32BIG_C(0x6302a03dU), BSWAP_32BIG_C(0xa2af2ebbU), BSWAP_32BIG_C(
                    0x2cce83e7U),
            };
            r_rsip_func101(Param_pf4_func101_003);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            static const uint32_t Param_pf4_func101_004[] =
            {
                BSWAP_32BIG_C(0xbc863c4dU), BSWAP_32BIG_C(0x73c96d17U), BSWAP_32BIG_C(0x4ab2279dU), BSWAP_32BIG_C(
                    0xc4ca39adU),
            };
            r_rsip_func101(Param_pf4_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub001(0x00c00011U);

            static const uint32_t Param_pf4_func101_005[] =
            {
                BSWAP_32BIG_C(0xcfd52e69U), BSWAP_32BIG_C(0x3834dcbfU), BSWAP_32BIG_C(0x399c83cbU), BSWAP_32BIG_C(
                    0xe0b17750U),
            };
            r_rsip_func101(Param_pf4_func101_005);
        }

        r_rsip_func_sub009(0x0000f403U);

        static const uint32_t Param_pf4_func101_006[] =
        {
            BSWAP_32BIG_C(0xe16ea8abU), BSWAP_32BIG_C(0x123cf664U), BSWAP_32BIG_C(0xe9400cb6U), BSWAP_32BIG_C(
                0x7e1fa681U),
        };
        r_rsip_func101(Param_pf4_func101_006);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);
        r_rsip_func_sub001(0x00c20011U);

        r_rsip_func_sub009(0x0000f404U);

        static const uint32_t Param_pf4_func101_007[] =
        {
            BSWAP_32BIG_C(0x52210a4aU), BSWAP_32BIG_C(0xcca2270dU), BSWAP_32BIG_C(0x7a3431e2U), BSWAP_32BIG_C(
                0x3e7a975dU),
        };
        r_rsip_func101(Param_pf4_func101_007);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0404000aU);

        WR1_PROG(REG_1404H, 0x11380000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);
        r_rsip_func_sub001(0x00c00009U);

        r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x04040007U);

        static const uint32_t Param_pf4_func100_004[] =
        {
            BSWAP_32BIG_C(0x2accd1b8U), BSWAP_32BIG_C(0xc60c7139U), BSWAP_32BIG_C(0x7d4087feU), BSWAP_32BIG_C(
                0x55cd807dU),
        };
        r_rsip_func100(Param_pf4_func100_004);
        WR1_PROG(REG_1600H, 0x00000800U);
        r_rsip_func_sub031(0x00000821U, 0x00000863U, 0x12280000U);
        WR1_PROG(REG_1608H, 0x808a0001U);
        r_rsip_func_sub001(0x03430029U);

        for (iLoop = 0U; iLoop < 10U; iLoop++)
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

        WR1_PROG(REG_1404H, 0x14580000U);
        r_rsip_func_sub001(0x00c00029U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x05050009U);

        WR1_PROG(REG_1404H, 0x10e80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c00025U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x00003403U);

        WR1_PROG(REG_1600H, 0x00003060U);

        r_rsip_func_sub016(0x81010060U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x05050007U);

            r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x05050009U);

            WR1_PROG(REG_1600H, 0x00003060U);

            static const uint32_t Param_pf4_func101_008[] =
            {
                BSWAP_32BIG_C(0x6cbce070U), BSWAP_32BIG_C(0x175aa1a5U), BSWAP_32BIG_C(0x280065a3U), BSWAP_32BIG_C(
                    0xdb2288a1U),
            };
            r_rsip_func101(Param_pf4_func101_008);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c03U, 0x00602000U);

        WR1_PROG(REG_1404H, 0x10e80000U);
        r_rsip_func_sub001(0x00c00029U);

        static const uint32_t Param_pf4_func100_005[] =
        {
            BSWAP_32BIG_C(0xace9e9e0U), BSWAP_32BIG_C(0xdda881e5U), BSWAP_32BIG_C(0x0a5b745fU), BSWAP_32BIG_C(
                0x549daf82U),
        };
        r_rsip_func100(Param_pf4_func100_005);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1600H, 0x00000040U);

        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0505000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_pf4_func100_006[] =
            {
                BSWAP_32BIG_C(0xa07eb77bU), BSWAP_32BIG_C(0x803a729fU), BSWAP_32BIG_C(0xa905cb09U), BSWAP_32BIG_C(
                    0x9ac309d7U),
            };
            r_rsip_func100(Param_pf4_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x05050009U);

                static const uint32_t Param_pf4_func101_009[] =
                {
                    BSWAP_32BIG_C(0x18e53fb1U), BSWAP_32BIG_C(0xea4de02aU), BSWAP_32BIG_C(0xbae1aeedU), BSWAP_32BIG_C(
                        0xa9efd5d7U),
                };
                r_rsip_func101(Param_pf4_func101_009);
            }

            WR1_PROG(REG_1014H, 0x000001b0U);
            r_rsip_func_sub005(0x00000250U, 0x0505000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x05050009U);
            WR1_PROG(REG_1600H, 0x00003000U);

            static const uint32_t Param_pf4_func101_010[] =
            {
                BSWAP_32BIG_C(0x2f77d63cU), BSWAP_32BIG_C(0x80f87fdfU), BSWAP_32BIG_C(0x0efe78d1U), BSWAP_32BIG_C(
                    0xc29d64caU),
            };
            r_rsip_func101(Param_pf4_func101_010);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c00U, 0x00602000U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x04040009U);

        static const uint32_t Param_pf4_func100_007[] =
        {
            BSWAP_32BIG_C(0x3cd6387bU), BSWAP_32BIG_C(0x153c6689U), BSWAP_32BIG_C(0x0e3703e8U), BSWAP_32BIG_C(
                0x95801fb5U),
        };
        r_rsip_func100(Param_pf4_func100_007);
        r_rsip_func071(InData_DomainParam);

        r_rsip_func_sub009(0x000000f4U);

        static const uint32_t Param_pf4_func101_011[] =
        {
            BSWAP_32BIG_C(0x2fed415dU), BSWAP_32BIG_C(0x9bba4898U), BSWAP_32BIG_C(0x742a36f4U), BSWAP_32BIG_C(
                0xb8e14c64U),
        };
        r_rsip_func101(Param_pf4_func101_011);
        r_rsip_func088();

        static const uint32_t Param_pf4_func100_008[] =
        {
            BSWAP_32BIG_C(0xfe6c4d20U), BSWAP_32BIG_C(0xf5230102U), BSWAP_32BIG_C(0x6262987eU), BSWAP_32BIG_C(
                0x4936d537U),
        };
        r_rsip_func100(Param_pf4_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf4_func102_002[] =
            {
                BSWAP_32BIG_C(0xb8e41431U), BSWAP_32BIG_C(0x058033c7U), BSWAP_32BIG_C(0x36996487U), BSWAP_32BIG_C(
                    0xe2b9ec39U),
            };
            r_rsip_func102(Param_pf4_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub009(0x0000f405U);

            static const uint32_t Param_pf4_func101_012[] =
            {
                BSWAP_32BIG_C(0xfad6dfd9U), BSWAP_32BIG_C(0x90034a24U), BSWAP_32BIG_C(0x8349657dU), BSWAP_32BIG_C(
                    0xb8786767U),
            };
            r_rsip_func101(Param_pf4_func101_012);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1608H, 0x80010000U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            WR1_PROG(REG_1600H, 0x000034e0U);

            r_rsip_func_sub009(0x000000f4U);

            static const uint32_t Param_pf4_func101_013[] =
            {
                BSWAP_32BIG_C(0xf8b9dbc7U), BSWAP_32BIG_C(0xf02bb29cU), BSWAP_32BIG_C(0x378aab70U), BSWAP_32BIG_C(
                    0xa26ff17cU),
            };
            r_rsip_func101(Param_pf4_func101_013);
            r_rsip_func043();

            r_rsip_func074();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub009(0x000000f4U);

            static const uint32_t Param_pf4_func101_014[] =
            {
                BSWAP_32BIG_C(0xb92abb1cU), BSWAP_32BIG_C(0x4790e670U), BSWAP_32BIG_C(0xa4862dc2U), BSWAP_32BIG_C(
                    0x483e89f0U),
            };
            r_rsip_func101(Param_pf4_func101_014);
            r_rsip_func044();

            static const uint32_t Param_pf4_func100_009[] =
            {
                BSWAP_32BIG_C(0x01d2a955U), BSWAP_32BIG_C(0x547c3d58U), BSWAP_32BIG_C(0x89feb4e1U), BSWAP_32BIG_C(
                    0xfab70bc8U),
            };
            r_rsip_func100(Param_pf4_func100_009);
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xe7009d07U);
            WR1_PROG(REG_1404H, 0x13200000U);
            r_rsip_func_sub001(0x00830021U);

            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);

            static const uint32_t Param_pf4_func100_010[] =
            {
                BSWAP_32BIG_C(0x1f810268U), BSWAP_32BIG_C(0x480ebefdU), BSWAP_32BIG_C(0x7f99d00aU), BSWAP_32BIG_C(
                    0x429722b2U),
            };
            r_rsip_func100(Param_pf4_func100_010);
            r_rsip_func_sub004(0x0c000104U, 0x00000000U);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x09108105U);
            r_rsip_func_sub001(0x00820011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);

            static const uint32_t Param_pf4_func100_011[] =
            {
                BSWAP_32BIG_C(0x2a75a274U), BSWAP_32BIG_C(0x0624525bU), BSWAP_32BIG_C(0x678ce1a6U), BSWAP_32BIG_C(
                    0xed592868U),
            };
            r_rsip_func100(Param_pf4_func100_011);
            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

            r_rsip_func_sub009(0x0000f406U);

            static const uint32_t Param_pf4_func101_015[] =
            {
                BSWAP_32BIG_C(0xffb8b3a6U), BSWAP_32BIG_C(0xf711841aU), BSWAP_32BIG_C(0x15158950U), BSWAP_32BIG_C(
                    0x79620c0cU),
            };
            r_rsip_func101(Param_pf4_func101_015);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1608H, 0x80010000U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            WR1_PROG(REG_1600H, 0x000034e0U);

            r_rsip_func_sub009(0x00000001U);

            static const uint32_t Param_pf4_func101_016[] =
            {
                BSWAP_32BIG_C(0xaa9bca8dU), BSWAP_32BIG_C(0x0bfb8140U), BSWAP_32BIG_C(0x7a75cae8U), BSWAP_32BIG_C(
                    0xf1f580c2U),
            };
            r_rsip_func101(Param_pf4_func101_016);
            r_rsip_func043();

            r_rsip_func075();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub009(0x00000002U);

            static const uint32_t Param_pf4_func101_017[] =
            {
                BSWAP_32BIG_C(0x5800fadfU), BSWAP_32BIG_C(0x679a2939U), BSWAP_32BIG_C(0x70ce377eU), BSWAP_32BIG_C(
                    0x15066adeU),
            };
            r_rsip_func101(Param_pf4_func101_017);
            r_rsip_func044();

            static const uint32_t Param_pf4_func100_012[] =
            {
                BSWAP_32BIG_C(0x9e09cfdcU), BSWAP_32BIG_C(0x9ff6e11bU), BSWAP_32BIG_C(0x9fc40f2cU), BSWAP_32BIG_C(
                    0x7fee0f96U),
            };
            r_rsip_func100(Param_pf4_func100_012);
            WR1_PROG(REG_1A2CH, 0x40000200U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            WR1_PROG(REG_1404H, 0x12800000U);
            r_rsip_func_sub001(0x00830021U);
            WR1_PROG(REG_1404H, 0x12d00000U);
            r_rsip_func_sub001(0x00830011U);

            WR1_PROG(REG_1408H, 0x00002032U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);

            static const uint32_t Param_pf4_func100_013[] =
            {
                BSWAP_32BIG_C(0xd770f518U), BSWAP_32BIG_C(0x2c2eab0fU), BSWAP_32BIG_C(0x0a56bc37U), BSWAP_32BIG_C(
                    0xbd6774a3U),
            };
            r_rsip_func100(Param_pf4_func100_013);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_func_sub001(0x00830011U);

            r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[13]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);

            static const uint32_t Param_pf4_func100_014[] =
            {
                BSWAP_32BIG_C(0x51f8f10bU), BSWAP_32BIG_C(0xcd08844aU), BSWAP_32BIG_C(0xfca2f4e4U), BSWAP_32BIG_C(
                    0x4bb88428U),
            };
            r_rsip_func100(Param_pf4_func100_014);
            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

            static const uint32_t Param_pf4_func102_003[] =
            {
                BSWAP_32BIG_C(0x155cab63U), BSWAP_32BIG_C(0x7c8caf6aU), BSWAP_32BIG_C(0x9643f359U), BSWAP_32BIG_C(
                    0x6dab65f0U),
            };
            r_rsip_func102(Param_pf4_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
