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

rsip_ret_t r_rsip_pe6 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataLength[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e60001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3000a880U, 0x00000003U, 0x00010020U, 0x0000b480U);
    r_rsip_func_sub021(0x00000002U, 0x00000080U, 0x30003080U, 0x00070020U);
    r_rsip_func_sub021(0x0000b4c0U, 0x00000002U, 0x0000b4e0U, 0x00000020U);

    r_rsip_func_sub021(0x0000b460U, 0x0000000dU, 0x0000b680U, 0x01a9da78U);
    r_rsip_func_sub021(0x00030040U, 0x0000b4c0U, 0x00000002U, 0x0000b4e0U);
    r_rsip_func_sub021(0x00000030U, 0x0000b460U, 0x00000011U, 0x0000b680U);
    r_rsip_func_sub021(0x0102b2eaU, 0x00050040U, 0x0000b4c0U, 0x00000001U);

    r_rsip_func_sub021(0x0000b4e0U, 0x00000040U, 0x0000b460U, 0x00000015U);

    r_rsip_func_sub022(0x0000b680U, 0x01e30848U, 0x00000080U);

    r_rsip_func_sub010(0x000000c7U, 0x800100a0U);
    WR1_PROG(REG_1420H, InData_KDFInfo_Count[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

    r_rsip_func_sub017(0x342028c5U, 0x00260000U);

    static const uint32_t Param_pe6_func100_001[] =
    {
        BSWAP_32BIG_C(0x8136836dU), BSWAP_32BIG_C(0xc84d1b0bU), BSWAP_32BIG_C(0xb8f08505U), BSWAP_32BIG_C(0x26e8f200U),
    };
    r_rsip_func100(Param_pe6_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe6_func102_001[] =
        {
            BSWAP_32BIG_C(0x58701ad3U), BSWAP_32BIG_C(0x99dfd07eU), BSWAP_32BIG_C(0x0e0b692dU), BSWAP_32BIG_C(
                0xb8ed1227U),
        };
        r_rsip_func102(Param_pe6_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100c0U);
        WR1_PROG(REG_1420H, InData_OutDataLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x300030a0U, 0x00030020U, 0x00003547U, 0x00000060U);
        r_rsip_func_sub021(0x0000b540U, 0x00000040U, 0x00000080U, 0x342028c7U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        r_rsip_func_sub017(0x34202946U, 0x00260000U);

        static const uint32_t Param_pe6_func100_002[] =
        {
            BSWAP_32BIG_C(0x1c148c2fU), BSWAP_32BIG_C(0x23985c6cU), BSWAP_32BIG_C(0x4476bca5U), BSWAP_32BIG_C(
                0xa685d6d7U),
        };
        r_rsip_func100(Param_pe6_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe6_func102_002[] =
            {
                BSWAP_32BIG_C(0xaa6c73e7U), BSWAP_32BIG_C(0x36ce0002U), BSWAP_32BIG_C(0x655a0c7bU), BSWAP_32BIG_C(
                    0xac65cc27U),
            };
            r_rsip_func102(Param_pe6_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe6_func100_003[] =
            {
                BSWAP_32BIG_C(0x7a48727eU), BSWAP_32BIG_C(0x147aea6eU), BSWAP_32BIG_C(0x6c85027aU), BSWAP_32BIG_C(
                    0x56a49683U),
            };
            r_rsip_func100(Param_pe6_func100_003);
            r_rsip_func_sub016(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            static const uint32_t Param_pe6_func100_004[] =
            {
                BSWAP_32BIG_C(0x8d3eee90U), BSWAP_32BIG_C(0x76743393U), BSWAP_32BIG_C(0xb0b83fdeU), BSWAP_32BIG_C(
                    0x8c01c8bdU),
            };
            r_rsip_func100(Param_pe6_func100_004);
            r_rsip_func_sub016(0x81010060U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
            OFS_ADR      = S_RAM[0 + 1];

            r_rsip_func_sub021(0x00000908U, 0x00000929U, 0x000009ceU, 0x000009efU);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x34202905U);
                WR1_PROG(REG_1600H, 0x2000d1e0U);
                r_rsip_func_sub014(0x00007c0fU, 0x00602000U);
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_KDFInfo[iLoop * OFS_ADR]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub009(0x0000e601U);

                static const uint32_t Param_pe6_func101_001[] =
                {
                    BSWAP_32BIG_C(0xb8d1ca48U), BSWAP_32BIG_C(0xd949ccc4U), BSWAP_32BIG_C(0x5a68076bU), BSWAP_32BIG_C(
                        0xa1d50a5aU),
                };
                r_rsip_func101(Param_pe6_func101_001);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01c80eb2U);
                r_rsip_func_sub009(0x0000e601U);

                static const uint32_t Param_pe6_func101_002[] =
                {
                    BSWAP_32BIG_C(0xb6450575U), BSWAP_32BIG_C(0xda1cf83fU), BSWAP_32BIG_C(0x84248991U), BSWAP_32BIG_C(
                        0x2380c954U),
                };
                r_rsip_func101(Param_pe6_func101_002);
                r_rsip_func044();

                r_rsip_func_sub004(0x08000044U, 0x00000000U);

                r_rsip_func_sub004(0x08000054U, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000842U);

                for (jLoop = 0U; jLoop < OFS_ADR - 5; jLoop = jLoop + 4U)
                {
                    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                    WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                    WR1_PROG(REG_1608H, 0x80840009U);
                    r_rsip_func_sub001(0x03420011U);

                    r_rsip_func_sub021(0x0000a520U, 0x00000010U, 0x0000a440U, 0x00000004U);

                    static const uint32_t Param_pe6_func101_003[] =
                    {
                        BSWAP_32BIG_C(0xc0b1d928U), BSWAP_32BIG_C(0x186debe2U), BSWAP_32BIG_C(0x88932feaU),
                        BSWAP_32BIG_C(0x7b1b50b7U),
                    };
                    r_rsip_func101(Param_pe6_func101_003);
                }

                r_rsip_func_sub034(0x000037e3U, 0x0000abe0U);
                WR1_PROG(REG_1600H, 0x00000005U);

                r_rsip_func_sub011(0x38000be2U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1600H, 0x00002d00U);

                static const uint32_t Param_pe6_func100_005[] =
                {
                    BSWAP_32BIG_C(0xf959a78eU), BSWAP_32BIG_C(0xb2d136e5U), BSWAP_32BIG_C(0x48ab18d1U), BSWAP_32BIG_C(
                        0x113e9f11U),
                };
                r_rsip_func100(Param_pe6_func100_005);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x0000d1c0U);
                    static const uint32_t Param_pe6_func101_004[] =
                    {
                        BSWAP_32BIG_C(0xdcb1b996U), BSWAP_32BIG_C(0x287cde26U), BSWAP_32BIG_C(0x49c4ea57U),
                        BSWAP_32BIG_C(0x6cbb271fU),
                    };
                    r_rsip_func101(Param_pe6_func101_004);
                }
                else
                {
                    static const uint32_t Param_pe6_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x73b6619eU), BSWAP_32BIG_C(0x7da98d09U), BSWAP_32BIG_C(0x27c755c8U),
                        BSWAP_32BIG_C(0xf7ef5be6U),
                    };
                    r_rsip_func101(Param_pe6_func101_005);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
            }

            r_rsip_func_sub011(0x38000905U);

            r_rsip_func_sub017(0x38000dceU, 0x00A60000U);
            static const uint32_t Param_pe6_func100_006[] =
            {
                BSWAP_32BIG_C(0xc77d72f9U), BSWAP_32BIG_C(0xea29c2ddU), BSWAP_32BIG_C(0x67d99b5bU), BSWAP_32BIG_C(
                    0x99ad0021U),
            };
            r_rsip_func100(Param_pe6_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe6_func102_003[] =
                {
                    BSWAP_32BIG_C(0x659acd40U), BSWAP_32BIG_C(0xd994154fU), BSWAP_32BIG_C(0xcce7e3f3U), BSWAP_32BIG_C(
                        0x2ca9bc0aU),
                };
                r_rsip_func102(Param_pe6_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe6_func100_007[] =
                {
                    BSWAP_32BIG_C(0x6cef7eefU), BSWAP_32BIG_C(0xa52b4802U), BSWAP_32BIG_C(0x63762cf2U), BSWAP_32BIG_C(
                        0x15677a7bU),
                };
                r_rsip_func100(Param_pe6_func100_007);
                r_rsip_func_sub016(0x810100c0U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub021(0x0000094aU, 0x0000b560U, 0x00000040U, 0x00002966U);

                WR1_PROG(REG_1600H, 0x00000908U);
                WR1_PROG(REG_1600H, 0x00003526U);

                for (iLoop = S_RAM[0]; iLoop < 64U; iLoop++)
                {
                    r_rsip_func_sub022(0x02003d49U, 0x00002d00U, 0x00002d20U);
                    static const uint32_t Param_pe6_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x57a336cfU), BSWAP_32BIG_C(0xe6b7f07cU), BSWAP_32BIG_C(0xf0fbc902U),
                        BSWAP_32BIG_C(0x1347ab37U),
                    };
                    r_rsip_func101(Param_pe6_func101_006);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x3800090bU);

                r_rsip_func_sub009(0x000000e6U);

                static const uint32_t Param_pe6_func101_007[] =
                {
                    BSWAP_32BIG_C(0x392009ffU), BSWAP_32BIG_C(0x54f9f46bU), BSWAP_32BIG_C(0x2a843ab9U), BSWAP_32BIG_C(
                        0x685f767fU),
                };
                r_rsip_func101(Param_pe6_func101_007);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x0000e602U);

                static const uint32_t Param_pe6_func101_008[] =
                {
                    BSWAP_32BIG_C(0x1cfd1814U), BSWAP_32BIG_C(0x724b0249U), BSWAP_32BIG_C(0x655d0914U), BSWAP_32BIG_C(
                        0xbe88069cU),
                };
                r_rsip_func101(Param_pe6_func101_008);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034f4U);

                r_rsip_func_sub009(0x0000e602U);

                static const uint32_t Param_pe6_func101_009[] =
                {
                    BSWAP_32BIG_C(0x8bf5c0c7U), BSWAP_32BIG_C(0x9768b592U), BSWAP_32BIG_C(0x67c5bbacU), BSWAP_32BIG_C(
                        0xd87959aaU),
                };
                r_rsip_func101(Param_pe6_func101_009);
                r_rsip_func044();

                static const uint32_t Param_pe6_func100_008[] =
                {
                    BSWAP_32BIG_C(0xf3c4eb25U), BSWAP_32BIG_C(0xb3feac8cU), BSWAP_32BIG_C(0x25144248U), BSWAP_32BIG_C(
                        0x41f1e0e2U),
                };
                r_rsip_func100(Param_pe6_func100_008);
                WR1_PROG(REG_1600H, 0x00000929U);
                r_rsip_func_sub027(0x40000100U, 0xe7009d07U, 0x81900009U);
                r_rsip_func_sub001(0x00890021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

                static const uint32_t Param_pe6_func100_009[] =
                {
                    BSWAP_32BIG_C(0x1bada07cU), BSWAP_32BIG_C(0x7be9169cU), BSWAP_32BIG_C(0xdeb4baffU), BSWAP_32BIG_C(
                        0x5baeb033U),
                };
                r_rsip_func100(Param_pe6_func100_009);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7008d07U);
                r_rsip_func_sub001(0x00890021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);

                static const uint32_t Param_pe6_func100_010[] =
                {
                    BSWAP_32BIG_C(0x9e4d9315U), BSWAP_32BIG_C(0x0689b81fU), BSWAP_32BIG_C(0x2741d486U), BSWAP_32BIG_C(
                        0x52cb9841U),
                };
                r_rsip_func100(Param_pe6_func100_010);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

                static const uint32_t Param_pe6_func100_011[] =
                {
                    BSWAP_32BIG_C(0x502157fcU), BSWAP_32BIG_C(0x4a64778aU), BSWAP_32BIG_C(0xe2f31a7cU), BSWAP_32BIG_C(
                        0x6e652925U),
                };
                r_rsip_func100(Param_pe6_func100_011);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                static const uint32_t Param_pe6_func102_004[] =
                {
                    BSWAP_32BIG_C(0x313819feU), BSWAP_32BIG_C(0x33796b1aU), BSWAP_32BIG_C(0x13e68a81U), BSWAP_32BIG_C(
                        0x8ace9cc6U),
                };
                r_rsip_func102(Param_pe6_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
