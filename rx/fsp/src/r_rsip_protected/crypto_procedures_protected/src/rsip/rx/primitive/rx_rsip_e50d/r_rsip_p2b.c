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

rsip_ret_t r_rsip_p2b (const uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;
    uint32_t kLoop   = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x002b0001U, 0x00000e50U);

    WR1_PROG(REG_1600H, 0x00000a31U);
    for (kLoop = 0U; kLoop < MAX_CNT; kLoop++)
    {
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub008(0x00002fa2U, 0x00000b00U, 0x08008107U);
        WR4_PROG(REG_1420H, bswap_32big(0x00030005U), bswap_32big(0x0007000bU), bswap_32big(0x000d0011U),
                 bswap_32big(0x00130017U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x001d001fU), bswap_32big(0x00250029U), bswap_32big(0x002b002fU),
                 bswap_32big(0x003b003dU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00430047U), bswap_32big(0x0049004fU), bswap_32big(0x00530059U),
                 bswap_32big(0x00610065U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x0067006bU), bswap_32big(0x006d0071U), bswap_32big(0x007f0083U),
                 bswap_32big(0x0089008bU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00950097U), bswap_32big(0x009d00a3U), bswap_32big(0x00a700adU),
                 bswap_32big(0x00b300b5U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00bf00c1U), bswap_32big(0x00c500c7U), bswap_32big(0x00d300dfU),
                 bswap_32big(0x00e300e5U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00e900efU), bswap_32big(0x00f100fbU), bswap_32big(0x01010107U),
                 bswap_32big(0x010d010fU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x01150119U), bswap_32big(0x011b0125U), bswap_32big(0x01330137U),
                 bswap_32big(0x0139013dU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x014b0151U), bswap_32big(0x015b015dU), bswap_32big(0x01610167U),
                 bswap_32big(0x016f0175U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x017b017fU), bswap_32big(0x0185018dU), bswap_32big(0x01910199U),
                 bswap_32big(0x01a301a5U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x01af01b1U), bswap_32big(0x01b701bbU), bswap_32big(0x01c101c9U),
                 bswap_32big(0x01cd01cfU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x01d301dfU), bswap_32big(0x01e701ebU), bswap_32big(0x01f301f7U),
                 bswap_32big(0x01fd0000U));
        r_rsip_func_sub001(0x00c20031U);

        r_rsip_func_sub023(0x0000b4c0U, 0x00000080U, 0x80b00006U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x034300c1U);

        WR1_PROG(REG_1404H, 0x10180000U);
        r_rsip_func_sub001(0x00c00209U);

        r_rsip_func_sub009(0x00002b01U);

        static const uint32_t Param_p2b_func101_001[] =
        {
            BSWAP_32BIG_C(0x4e0bd028U), BSWAP_32BIG_C(0x29efaaa9U), BSWAP_32BIG_C(0x2837fbdeU), BSWAP_32BIG_C(
                0x990c747cU),
        };
        r_rsip_func101(Param_p2b_func101_001);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1404H, 0x11a00000U);
        r_rsip_func_sub001(0x00c90011U);

        r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000018U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 24U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            r_rsip_func_sub014(0x00007c07U, 0x00602000U);

            r_rsip_func_sub009(0x00002b02U);

            static const uint32_t Param_p2b_func101_002[] =
            {
                BSWAP_32BIG_C(0x55b22ca9U), BSWAP_32BIG_C(0xe1d7d042U), BSWAP_32BIG_C(0xc111f802U), BSWAP_32BIG_C(
                    0xe2d9c931U),
            };
            r_rsip_func101(Param_p2b_func101_002);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            r_rsip_func_sub001(0x00c20011U);

            WR1_PROG(REG_1600H, 0x00002485U);

            static const uint32_t Param_p2b_func101_003[] =
            {
                BSWAP_32BIG_C(0xe9948d5bU), BSWAP_32BIG_C(0xf45c1916U), BSWAP_32BIG_C(0xf5470ad0U), BSWAP_32BIG_C(
                    0x5f6eb6b2U),
            };
            r_rsip_func101(Param_p2b_func101_003);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x38000886U);

        r_rsip_func_sub009(0x00002b03U);

        static const uint32_t Param_p2b_func101_004[] =
        {
            BSWAP_32BIG_C(0x2da0ace1U), BSWAP_32BIG_C(0x11cc930aU), BSWAP_32BIG_C(0x39ab12a6U), BSWAP_32BIG_C(
                0xbaeced52U),
        };
        r_rsip_func101(Param_p2b_func101_004);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1608H, 0x81040000U);
        r_rsip_func_sub001(0x00c90011U);

        WR1_PROG(REG_1404H, 0x19c00000U);
        r_rsip_func_sub008(0x00001fa2U, 0x00000700U, 0x08008107U);
        WR4_PROG(REG_1420H, bswap_32big(0xB51EB851U), bswap_32big(0xEB851EB8U), bswap_32big(0x51EB851EU),
                 bswap_32big(0xB851EB85U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U), bswap_32big(0xEB851EB8U),
                 bswap_32big(0x51EB851EU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0xB851EB85U), bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U),
                 bswap_32big(0xEB851EB8U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x51EB851EU), bswap_32big(0xB851EB85U), bswap_32big(0x1EB851EBU),
                 bswap_32big(0x851EB851U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0xEB851EB8U), bswap_32big(0x51EB851EU), bswap_32big(0xB851EB85U),
                 bswap_32big(0x1EB851EBU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x851EB851U), bswap_32big(0xEB851EB8U), bswap_32big(0x51EB851EU),
                 bswap_32big(0xB851EB85U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U), bswap_32big(0xEB851EB8U),
                 bswap_32big(0x51EB851EU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0xB851EB85U), bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U),
                 bswap_32big(0xEB851B5CU));
        r_rsip_func_sub001(0x00c20021U);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p2b_func100_001[] =
        {
            BSWAP_32BIG_C(0x1af38c19U), BSWAP_32BIG_C(0xa0b928d8U), BSWAP_32BIG_C(0xd1946c1fU), BSWAP_32BIG_C(
                0x46d96e00U),
        };
        r_rsip_func100(Param_p2b_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2b_func101_005[] =
            {
                BSWAP_32BIG_C(0xadb3a7aaU), BSWAP_32BIG_C(0x8411b76dU), BSWAP_32BIG_C(0x57ae8accU), BSWAP_32BIG_C(
                    0x88f00080U),
            };
            r_rsip_func101(Param_p2b_func101_005);
            continue;
        }
        else
        {
            static const uint32_t Param_p2b_func101_006[] =
            {
                BSWAP_32BIG_C(0x054a59deU), BSWAP_32BIG_C(0x6f96b17dU), BSWAP_32BIG_C(0x0c24fc4aU), BSWAP_32BIG_C(
                    0x1536eca8U),
            };
            r_rsip_func101(Param_p2b_func101_006);
        }

        r_rsip_func_sub006(0x38008a20U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p2b_func100_002[] =
        {
            BSWAP_32BIG_C(0x0d87179fU), BSWAP_32BIG_C(0xdf5a5f5bU), BSWAP_32BIG_C(0x489a1387U), BSWAP_32BIG_C(
                0xe0004d18U),
        };
        r_rsip_func100(Param_p2b_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000320U, 0x00000220U, 0x00000630U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_003[] =
            {
                BSWAP_32BIG_C(0xf1e668e8U), BSWAP_32BIG_C(0xbd1f58f6U), BSWAP_32BIG_C(0x7047a930U), BSWAP_32BIG_C(
                    0x505be7f1U),
            };
            r_rsip_func100(Param_p2b_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000220U, 0x00000320U, 0x00000630U, 0x1010000aU);

                static const uint32_t Param_p2b_func101_007[] =
                {
                    BSWAP_32BIG_C(0x34c40396U), BSWAP_32BIG_C(0x329f9001U), BSWAP_32BIG_C(0xc8455a38U), BSWAP_32BIG_C(
                        0xd5078337U),
                };
                r_rsip_func101(Param_p2b_func101_007);
            }
            else
            {
                static const uint32_t Param_p2b_func101_008[] =
                {
                    BSWAP_32BIG_C(0xdca28f32U), BSWAP_32BIG_C(0x92517470U), BSWAP_32BIG_C(0xfd771b5aU), BSWAP_32BIG_C(
                        0xa56f76ebU),
                };
                r_rsip_func101(Param_p2b_func101_008);
            }

            WR1_PROG(REG_1404H, 0x19c00000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x10000000U));
            r_rsip_func_sub001(0x00c20011U);
            r_rsip_func_sub001(0x00c00071U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_004[] =
            {
                BSWAP_32BIG_C(0x859955feU), BSWAP_32BIG_C(0x8fe4dea5U), BSWAP_32BIG_C(0xe249d3a7U), BSWAP_32BIG_C(
                    0x298840e0U),
            };
            r_rsip_func100(Param_p2b_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p2b_func101_009[] =
                {
                    BSWAP_32BIG_C(0xf29ac101U), BSWAP_32BIG_C(0x594529f9U), BSWAP_32BIG_C(0x0c722c0eU), BSWAP_32BIG_C(
                        0xdf0c567dU),
                };
                r_rsip_func101(Param_p2b_func101_009);
                continue;
            }
            else
            {
                static const uint32_t Param_p2b_func101_010[] =
                {
                    BSWAP_32BIG_C(0x291c9340U), BSWAP_32BIG_C(0x06caae71U), BSWAP_32BIG_C(0x87747676U), BSWAP_32BIG_C(
                        0xfa900b2aU),
                };
                r_rsip_func101(Param_p2b_func101_010);
            }
        }
        else
        {
            static const uint32_t Param_p2b_func101_011[] =
            {
                BSWAP_32BIG_C(0x8338c471U), BSWAP_32BIG_C(0xfb9c3b2cU), BSWAP_32BIG_C(0x73e84a59U), BSWAP_32BIG_C(
                    0xfe4b5c7aU),
            };
            r_rsip_func101(Param_p2b_func101_011);
        }

        r_rsip_func_sub022(0x0000b4c0U, 0x00000080U, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            r_rsip_func_sub022(0x01003906U, 0x00002cc0U, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x14280000U);
            r_rsip_func_sub001(0x00c00209U);

            WR1_PROG(REG_1404H, 0x15b00000U);
            r_rsip_func_sub001(0x00c0007dU);
            r_rsip_func_sub001(0x00c90005U);

            r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x10100010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x10100004U, 0x00010201U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19c00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0007dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_005[] =
            {
                BSWAP_32BIG_C(0x481e1470U), BSWAP_32BIG_C(0x90b2585eU), BSWAP_32BIG_C(0x20791d01U), BSWAP_32BIG_C(
                    0xe3acfe7bU),
            };
            r_rsip_func100(Param_p2b_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                static const uint32_t Param_p2b_func101_012[] =
                {
                    BSWAP_32BIG_C(0x0a80c950U), BSWAP_32BIG_C(0x2ed8bfb0U), BSWAP_32BIG_C(0xf5a488f1U), BSWAP_32BIG_C(
                        0x4256c40dU),
                };
                r_rsip_func101(Param_p2b_func101_012);
                break;
            }
            else
            {
                static const uint32_t Param_p2b_func101_013[] =
                {
                    BSWAP_32BIG_C(0x563449eaU), BSWAP_32BIG_C(0xfbba7483U), BSWAP_32BIG_C(0x77f68f02U), BSWAP_32BIG_C(
                        0x7b58b4a4U),
                };
                r_rsip_func101(Param_p2b_func101_013);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        r_rsip_func_sub006(0x38008940U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p2b_func100_006[] =
        {
            BSWAP_32BIG_C(0xbed32b90U), BSWAP_32BIG_C(0xea13fc1dU), BSWAP_32BIG_C(0xdc9e78aaU), BSWAP_32BIG_C(
                0x6d0c6eadU),
        };
        r_rsip_func100(Param_p2b_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2b_func101_014[] =
            {
                BSWAP_32BIG_C(0x4be8f846U), BSWAP_32BIG_C(0x0c6267ddU), BSWAP_32BIG_C(0x79c207a2U), BSWAP_32BIG_C(
                    0x93bf4539U),
            };
            r_rsip_func101(Param_p2b_func101_014);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18b80000U);
        r_rsip_func_sub001(0x00c00081U);

        r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000428U, 0x10100009U);

        r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1010000aU);

        WR1_PROG(REG_1404H, 0x14280000U);
        r_rsip_func_sub001(0x00c00209U);

        WR1_PROG(REG_1404H, 0x15b00000U);
        r_rsip_func_sub004(0x08000104U, 0x00010001U);
        r_rsip_func_sub001(0x00c0007dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x10100010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        r_rsip_func_sub005(0x00000838U, 0x10100004U, 0x00010201U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0007dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1010000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p2b_func100_007[] =
        {
            BSWAP_32BIG_C(0x7d698d0cU), BSWAP_32BIG_C(0x9c4de971U), BSWAP_32BIG_C(0xbd5f6808U), BSWAP_32BIG_C(
                0xc156be8cU),
        };
        r_rsip_func100(Param_p2b_func100_007);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2b_func101_015[] =
            {
                BSWAP_32BIG_C(0x7ef5a8a7U), BSWAP_32BIG_C(0x025b2343U), BSWAP_32BIG_C(0x55eaa747U), BSWAP_32BIG_C(
                    0xe0719eb6U),
            };
            r_rsip_func101(Param_p2b_func101_015);
        }
        else
        {
            WR1_PROG(REG_1404H, 0x16300000U);
            r_rsip_func_sub001(0x00c00209U);

            static const uint32_t Param_p2b_func100_008[] =
            {
                BSWAP_32BIG_C(0x75e8f0a8U), BSWAP_32BIG_C(0x32f6fc0cU), BSWAP_32BIG_C(0xa71d9783U), BSWAP_32BIG_C(
                    0xc570c23dU),
            };
            r_rsip_func100(Param_p2b_func100_008);
            WR1_PROG(REG_1404H, 0x17b80000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0007dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub018(0x00000018U, 0x00000428U, 0x10100010U);

            r_rsip_func_sub013(0x00000838U, 0x00000220U, 0x00000428U, 0x00000630U, 0x10100000U, 0x00010201U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_009[] =
            {
                BSWAP_32BIG_C(0x1b816a5fU), BSWAP_32BIG_C(0x459c5e61U), BSWAP_32BIG_C(0x87d0ba4fU), BSWAP_32BIG_C(
                    0x866cdfc2U),
            };
            r_rsip_func100(Param_p2b_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p2b_func101_016[] =
                {
                    BSWAP_32BIG_C(0x3a1d2f62U), BSWAP_32BIG_C(0xe382a0f4U), BSWAP_32BIG_C(0xc72da8c3U), BSWAP_32BIG_C(
                        0x03544318U),
                };
                r_rsip_func101(Param_p2b_func101_016);
                continue;
            }

            static const uint32_t Param_p2b_func100_010[] =
            {
                BSWAP_32BIG_C(0xc77de223U), BSWAP_32BIG_C(0x2f2edd37U), BSWAP_32BIG_C(0xa230225fU), BSWAP_32BIG_C(
                    0x8a9f23ecU),
            };
            r_rsip_func100(Param_p2b_func100_010);

            r_rsip_func_sub022(0x0000b560U, 0x00000003U, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80a0000aU);
            WR1_PROG(REG_1404H, 0x11a00000U);
            r_rsip_func_sub001(0x03430081U);

            r_rsip_func_sub021(0x00000929U, 0x00000908U, 0x0000b4c0U, 0x0000007cU);

            for (iLoop = 0U; iLoop < 32U; iLoop++)
            {
                r_rsip_func_sub022(0x000038e6U, 0x0000a8c0U, 0x00000004U);
                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x38008900U, 0x00000000U, 0x11816907U, 0x38008900U);
                    r_rsip_func_sub022(0x00000000U, 0x10002d20U, 0x000168e7U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub016(0x81010120U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WR1_PROG(REG_1600H, 0x000037e9U);

            r_rsip_func_sub030(0x15b00000U, 0x0000094aU, 0x81a0000aU);
            r_rsip_func_sub001(0x00c90081U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                r_rsip_func_sub005(0x00000838U, 0x1010000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000838U, 0x00000938U, 0x00000630U, 0x10100009U);

                WR1_PROG(REG_1600H, 0x000033e0U);

                static const uint32_t Param_p2b_func101_017[] =
                {
                    BSWAP_32BIG_C(0x8e2a266fU), BSWAP_32BIG_C(0x958fa596U), BSWAP_32BIG_C(0x22a3cb5bU), BSWAP_32BIG_C(
                        0x4395630bU),
                };
                r_rsip_func101(Param_p2b_func101_017);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub014(0x00007c1fU, 0x00602000U);

            static const uint32_t Param_p2b_func100_011[] =
            {
                BSWAP_32BIG_C(0xc862666aU), BSWAP_32BIG_C(0xd7ef1970U), BSWAP_32BIG_C(0x2b63862fU), BSWAP_32BIG_C(
                    0x149a3087U),
            };
            r_rsip_func100(Param_p2b_func100_011);
            WR1_PROG(REG_1600H, 0x00000a52U);

            r_rsip_func_sub016(0x81010160U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x10180000U);
                r_rsip_func_sub001(0x00c00209U);

                r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
                r_rsip_func_sub031(0x00000020U, 0x000008e7U, 0x11a00000U);
                for (jLoop = 0U; jLoop < 32U; jLoop = jLoop + 4U)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    r_rsip_func_sub014(0x00007c07U, 0x00602000U);

                    r_rsip_func_sub009(0x00002b04U);

                    static const uint32_t Param_p2b_func101_018[] =
                    {
                        BSWAP_32BIG_C(0xda03ea32U), BSWAP_32BIG_C(0xeb6df49eU), BSWAP_32BIG_C(0x7f5002ebU),
                        BSWAP_32BIG_C(0xb952ae6cU),
                    };
                    r_rsip_func101(Param_p2b_func101_018);
                    r_rsip_func113();
                    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                    r_rsip_func_sub001(0x00c20011U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    static const uint32_t Param_p2b_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x4fbe0724U), BSWAP_32BIG_C(0xbe58025cU), BSWAP_32BIG_C(0xb2921f97U),
                        BSWAP_32BIG_C(0xd9b6ea6bU),
                    };
                    r_rsip_func101(Param_p2b_func101_019);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000886U);

                static const uint32_t Param_p2b_func100_012[] =
                {
                    BSWAP_32BIG_C(0x796399fbU), BSWAP_32BIG_C(0xcab36bd3U), BSWAP_32BIG_C(0xa9ca70e8U), BSWAP_32BIG_C(
                        0x33b91acbU),
                };
                r_rsip_func100(Param_p2b_func100_012);
                WR1_PROG(REG_1404H, 0x19c00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000004U);
                r_rsip_func_sub001(0x00c0007dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x1010000aU);

                r_rsip_func_sub018(0x00000018U, 0x00000838U, 0x10100010U);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x10100004U, 0x00010201U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17b80000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0007dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x10100009U);

                r_rsip_func_sub018(0x00000018U, 0x00000428U, 0x10100010U);

                r_rsip_func_sub013(0x00000220U, 0x00000630U, 0x00000428U, 0x00000838U, 0x10100000U, 0x00010201U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x19c00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0007dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1010000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1010000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p2b_func100_013[] =
                {
                    BSWAP_32BIG_C(0xd6f6ab6fU), BSWAP_32BIG_C(0x0bb1264cU), BSWAP_32BIG_C(0xee68221eU), BSWAP_32BIG_C(
                        0x7b0f9172U),
                };
                r_rsip_func100(Param_p2b_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    static const uint32_t Param_p2b_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x104466dfU), BSWAP_32BIG_C(0x69c7992fU), BSWAP_32BIG_C(0x78e36130U),
                        BSWAP_32BIG_C(0xa9b9e783U),
                    };
                    r_rsip_func101(Param_p2b_func101_020);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    static const uint32_t Param_p2b_func100_014[] =
                    {
                        BSWAP_32BIG_C(0xfbdef15aU), BSWAP_32BIG_C(0xbd8e35f3U), BSWAP_32BIG_C(0x5771cce6U),
                        BSWAP_32BIG_C(0x7d6f1fdeU),
                    };
                    r_rsip_func100(Param_p2b_func100_014);
                    r_rsip_func_sub016(0x81010120U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19c00000U);
                        WR1_PROG(REG_1608H, 0x81a0000aU);
                        r_rsip_func_sub001(0x00c90081U);

                        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1010000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1010000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        static const uint32_t Param_p2b_func100_015[] =
                        {
                            BSWAP_32BIG_C(0xbb203c3eU), BSWAP_32BIG_C(0xbfd7368cU), BSWAP_32BIG_C(0xa74753daU),
                            BSWAP_32BIG_C(0xf92075e9U),
                        };
                        r_rsip_func100(Param_p2b_func100_015);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            static const uint32_t Param_p2b_func101_021[] =
                            {
                                BSWAP_32BIG_C(0xa62ecaf3U), BSWAP_32BIG_C(0xc964211eU), BSWAP_32BIG_C(0x6b1807aeU),
                                BSWAP_32BIG_C(0xb7763499U),
                            };
                            r_rsip_func101(Param_p2b_func101_021);
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18380000U);
                            r_rsip_func_sub001(0x00c00209U);

                            static const uint32_t Param_p2b_func100_016[] =
                            {
                                BSWAP_32BIG_C(0xc8fb5f5bU), BSWAP_32BIG_C(0x6d48a575U), BSWAP_32BIG_C(0xcb07376dU),
                                BSWAP_32BIG_C(0xe727f9b0U),
                            };
                            r_rsip_func100(Param_p2b_func100_016);
                            WR1_PROG(REG_1404H, 0x19c00000U);
                            r_rsip_func_sub004(0x08000104U, 0x00000002U);
                            r_rsip_func_sub001(0x00c0007dU);
                            r_rsip_func_sub001(0x00c20005U);
                            r_rsip_func_sub001(0x0002000dU);

                            r_rsip_func_sub013(0x00000838U,
                                               0x00000a40U,
                                               0x00000428U,
                                               0x00000220U,
                                               0x10100000U,
                                               0x00010201U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000838U, 0x10100009U);

                            static const uint32_t Param_p2b_func101_022[] =
                            {
                                BSWAP_32BIG_C(0x50443904U), BSWAP_32BIG_C(0x41d7336cU), BSWAP_32BIG_C(0x7c02608bU),
                                BSWAP_32BIG_C(0x168ef1e0U),
                            };
                            r_rsip_func101(Param_p2b_func101_022);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub006(0x38008a40U, 0x00000000U, 0x00260000U);

                    static const uint32_t Param_p2b_func100_017[] =
                    {
                        BSWAP_32BIG_C(0x0204058dU), BSWAP_32BIG_C(0xa4c6ddc4U), BSWAP_32BIG_C(0x02cb07a5U),
                        BSWAP_32BIG_C(0x43e8fa83U),
                    };
                    r_rsip_func100(Param_p2b_func100_017);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p2b_func101_023[] =
                        {
                            BSWAP_32BIG_C(0xa7f9389fU), BSWAP_32BIG_C(0xe5c24ce1U), BSWAP_32BIG_C(0xdb10a513U),
                            BSWAP_32BIG_C(0x0d242537U),
                        };
                        r_rsip_func101(Param_p2b_func101_023);
                        break;
                    }
                    else
                    {
                        static const uint32_t Param_p2b_func101_024[] =
                        {
                            BSWAP_32BIG_C(0x8ebffc95U), BSWAP_32BIG_C(0x801f9c18U), BSWAP_32BIG_C(0x1ce82f16U),
                            BSWAP_32BIG_C(0x674723aaU),
                        };
                        r_rsip_func101(Param_p2b_func101_024);
                    }
                }
            }

            r_rsip_func_sub017(0x38000a4bU, 0x00260000U);

            static const uint32_t Param_p2b_func100_018[] =
            {
                BSWAP_32BIG_C(0xbf7d38adU), BSWAP_32BIG_C(0xcc397a79U), BSWAP_32BIG_C(0xe3d8ef88U), BSWAP_32BIG_C(
                    0x74e74e9cU),
            };
            r_rsip_func100(Param_p2b_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_p2b_func100_019[] =
                {
                    BSWAP_32BIG_C(0xaf97d6d9U), BSWAP_32BIG_C(0x13431d9aU), BSWAP_32BIG_C(0xf9688d83U), BSWAP_32BIG_C(
                        0xb05a842dU),
                };
                r_rsip_func100(Param_p2b_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p2b_func101_025[] =
                    {
                        BSWAP_32BIG_C(0x804bd015U), BSWAP_32BIG_C(0x03b2b504U), BSWAP_32BIG_C(0xdcce4133U),
                        BSWAP_32BIG_C(0xb38375e7U),
                    };
                    r_rsip_func101(Param_p2b_func101_025);
                    break;
                }
                else
                {
                    r_rsip_func_sub002(0x00000428U, 0x00000938U, 0x00000320U, 0x10100009U);

                    static const uint32_t Param_p2b_func101_026[] =
                    {
                        BSWAP_32BIG_C(0x6b4e0549U), BSWAP_32BIG_C(0x19474ff3U), BSWAP_32BIG_C(0x2266601cU),
                        BSWAP_32BIG_C(0xf6fcf524U),
                    };
                    r_rsip_func101(Param_p2b_func101_026);
                }
            }
            else
            {
                static const uint32_t Param_p2b_func101_027[] =
                {
                    BSWAP_32BIG_C(0x3e22430aU), BSWAP_32BIG_C(0xaa11753dU), BSWAP_32BIG_C(0xfd79f98dU), BSWAP_32BIG_C(
                        0x10264dc7U),
                };
                r_rsip_func101(Param_p2b_func101_027);
            }
        }
    }

    r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00A60000U);

    static const uint32_t Param_p2b_func100_020[] =
    {
        BSWAP_32BIG_C(0x3fe85d93U), BSWAP_32BIG_C(0x625f7defU), BSWAP_32BIG_C(0x1cc7b71fU), BSWAP_32BIG_C(0xee82df37U),
    };
    r_rsip_func100(Param_p2b_func100_020);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2b_func102_001[] =
        {
            BSWAP_32BIG_C(0x573ececaU), BSWAP_32BIG_C(0xcc375a40U), BSWAP_32BIG_C(0x2499f038U), BSWAP_32BIG_C(
                0x5a6ff887U),
        };
        r_rsip_func102(Param_p2b_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub001(0x00c00081U);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x10100009U);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x000007b8U, 0x10100009U);

    r_rsip_func_sub009(0x00002b05U);

    static const uint32_t Param_p2b_func101_028[] =
    {
        BSWAP_32BIG_C(0xcece7fe2U), BSWAP_32BIG_C(0xfbb08b45U), BSWAP_32BIG_C(0x80d4485eU), BSWAP_32BIG_C(0x8b36f5a8U),
    };
    r_rsip_func101(Param_p2b_func101_028);
    r_rsip_func113();
    static const uint32_t Param_p2b_func100_021[] =
    {
        BSWAP_32BIG_C(0x3cbefce5U), BSWAP_32BIG_C(0xc5c77f83U), BSWAP_32BIG_C(0xf72bda54U), BSWAP_32BIG_C(0x277eb925U),
    };
    r_rsip_func100(Param_p2b_func100_021);
    r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x17380000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub009(0x00002b01U);

    static const uint32_t Param_p2b_func101_029[] =
    {
        BSWAP_32BIG_C(0xbb9d6753U), BSWAP_32BIG_C(0x29b10721U), BSWAP_32BIG_C(0x85a79e9cU), BSWAP_32BIG_C(0x6a228891U),
    };
    r_rsip_func101(Param_p2b_func101_029);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000220U, 0x1010000aU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000630U, 0x1010000aU);

    r_rsip_func_sub009(0x0000002bU);

    static const uint32_t Param_p2b_func101_030[] =
    {
        BSWAP_32BIG_C(0x87d72b25U), BSWAP_32BIG_C(0x333dbf8bU), BSWAP_32BIG_C(0x78a30e76U), BSWAP_32BIG_C(0x185c448eU),
    };
    r_rsip_func101(Param_p2b_func101_030);
    r_rsip_func052();

    WR1_PROG(REG_1404H, 0x15200000U);
    r_rsip_func_sub001(0x00c00091U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x17380000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub009(0x00002b01U);

    static const uint32_t Param_p2b_func101_031[] =
    {
        BSWAP_32BIG_C(0x5cd40107U), BSWAP_32BIG_C(0x16b063c1U), BSWAP_32BIG_C(0x95c09750U), BSWAP_32BIG_C(0x330c4857U),
    };
    r_rsip_func101(Param_p2b_func101_031);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x000007b8U, 0x00000838U, 0x00000220U, 0x10100007U);

    r_rsip_func_sub009(0x00002b01U);

    static const uint32_t Param_p2b_func101_032[] =
    {
        BSWAP_32BIG_C(0x779273f4U), BSWAP_32BIG_C(0x04c3c44fU), BSWAP_32BIG_C(0x0af24695U), BSWAP_32BIG_C(0x9d816739U),
    };
    r_rsip_func101(Param_p2b_func101_032);
    r_rsip_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p2b_func100_022[] =
    {
        BSWAP_32BIG_C(0xf16c8b1cU), BSWAP_32BIG_C(0xf549ba10U), BSWAP_32BIG_C(0x454bd47dU), BSWAP_32BIG_C(0x7bbe88c3U),
    };
    r_rsip_func100(Param_p2b_func100_022);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2b_func102_002[] =
        {
            BSWAP_32BIG_C(0x69542322U), BSWAP_32BIG_C(0x3023f640U), BSWAP_32BIG_C(0xe92ed527U), BSWAP_32BIG_C(
                0x7cfb5050U),
        };
        r_rsip_func102(Param_p2b_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x13280000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub009(0x00002b02U);

    static const uint32_t Param_p2b_func101_033[] =
    {
        BSWAP_32BIG_C(0x6f4a79eeU), BSWAP_32BIG_C(0xbafa69d9U), BSWAP_32BIG_C(0x98269a80U), BSWAP_32BIG_C(0xcc31241dU),
    };
    r_rsip_func101(Param_p2b_func101_033);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x000003a8U, 0x00000428U, 0x00000630U, 0x10100007U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x15300000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub009(0x00002b02U);

    static const uint32_t Param_p2b_func101_034[] =
    {
        BSWAP_32BIG_C(0xde25e95dU), BSWAP_32BIG_C(0xc1cc889dU), BSWAP_32BIG_C(0xee794050U), BSWAP_32BIG_C(0x2c7c4bf1U),
    };
    r_rsip_func101(Param_p2b_func101_034);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17280000U);
    r_rsip_func_sub001(0x00c00011U);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1010000aU);

    r_rsip_func_sub002(0x000003a8U, 0x00000a40U, 0x000001a0U, 0x1010000aU);

    r_rsip_func_sub002(0x000001a0U, 0x00000220U, 0x00000428U, 0x10100007U);

    r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x20200010U);

    r_rsip_func_sub038(0x00000428U, 0x00000838U, 0x00000630U);
    r_rsip_func_sub005(0x00000428U, 0x20200002U, 0x00010201U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x20200003U, 0x00010201U);
    r_rsip_func_sub007(0x00000428U, 0x00000220U, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x20200002U, 0x00010201U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x15300000U);
    r_rsip_func_sub004(0x08000104U, 0x00010001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub009(0x00002b02U);

    static const uint32_t Param_p2b_func101_035[] =
    {
        BSWAP_32BIG_C(0x41392d24U), BSWAP_32BIG_C(0x83b3ab33U), BSWAP_32BIG_C(0xc5d1a120U), BSWAP_32BIG_C(0xf3caafc2U),
    };
    r_rsip_func101(Param_p2b_func101_035);
    r_rsip_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p2b_func100_023[] =
    {
        BSWAP_32BIG_C(0xaa72fd23U), BSWAP_32BIG_C(0x7017d5edU), BSWAP_32BIG_C(0x2a391cc1U), BSWAP_32BIG_C(0x0ec6b641U),
    };
    r_rsip_func100(Param_p2b_func100_023);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2b_func102_003[] =
        {
            BSWAP_32BIG_C(0xdc3b710fU), BSWAP_32BIG_C(0xfcc51589U), BSWAP_32BIG_C(0xa791020dU), BSWAP_32BIG_C(
                0xe5ced51aU),
        };
        r_rsip_func102(Param_p2b_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub001(0x00c00101U);

    r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000428U, 0x20200009U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x15300000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub009(0x00002b03U);

    static const uint32_t Param_p2b_func101_036[] =
    {
        BSWAP_32BIG_C(0xdd873e27U), BSWAP_32BIG_C(0xeccd5003U), BSWAP_32BIG_C(0xd4042b38U), BSWAP_32BIG_C(0x52d9d42dU),
    };
    r_rsip_func101(Param_p2b_func101_036);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1600H, 0x00010001U);

    r_rsip_func_sub009(0x00002b06U);

    static const uint32_t Param_p2b_func101_037[] =
    {
        BSWAP_32BIG_C(0x6e24e3a6U), BSWAP_32BIG_C(0x80bc7643U), BSWAP_32BIG_C(0xb382879fU), BSWAP_32BIG_C(0xace95502U),
    };
    r_rsip_func101(Param_p2b_func101_037);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000012bU);

    static const uint32_t Param_p2b_func101_038[] =
    {
        BSWAP_32BIG_C(0x221fda3cU), BSWAP_32BIG_C(0x484e4856U), BSWAP_32BIG_C(0xf90f5424U), BSWAP_32BIG_C(0xc5783890U),
    };
    r_rsip_func101(Param_p2b_func101_038);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000dU);

    r_rsip_func_sub009(0x0000012bU);

    static const uint32_t Param_p2b_func101_039[] =
    {
        BSWAP_32BIG_C(0x450e65c1U), BSWAP_32BIG_C(0x38b94058U), BSWAP_32BIG_C(0xec996735U), BSWAP_32BIG_C(0x472a4557U),
    };
    r_rsip_func101(Param_p2b_func101_039);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000040U, 0x000008e7U, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p2b_func100_024[] =
        {
            BSWAP_32BIG_C(0x77e12753U), BSWAP_32BIG_C(0x5dcfb3e8U), BSWAP_32BIG_C(0xe5271097U), BSWAP_32BIG_C(
                0xbee6f642U),
        };
        r_rsip_func100(Param_p2b_func100_024);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p2b_func101_040[] =
        {
            BSWAP_32BIG_C(0x05a2cbadU), BSWAP_32BIG_C(0xacd2a699U), BSWAP_32BIG_C(0xc4aa9123U), BSWAP_32BIG_C(
                0x2311507dU),
        };
        r_rsip_func101(Param_p2b_func101_040);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000040U, 0x000008e7U, 0x13280000U);
    for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p2b_func100_025[] =
        {
            BSWAP_32BIG_C(0x4ada5606U), BSWAP_32BIG_C(0x61e8fe6bU), BSWAP_32BIG_C(0xea6e3c7aU), BSWAP_32BIG_C(
                0x5940aaf7U),
        };
        r_rsip_func100(Param_p2b_func100_025);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[65 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p2b_func101_041[] =
        {
            BSWAP_32BIG_C(0x93e9cc23U), BSWAP_32BIG_C(0xd9d2d997U), BSWAP_32BIG_C(0x4667e866U), BSWAP_32BIG_C(
                0x6a4ff20eU),
        };
        r_rsip_func101(Param_p2b_func101_041);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p2b_func100_026[] =
    {
        BSWAP_32BIG_C(0x2b3d3e02U), BSWAP_32BIG_C(0xafc54bf6U), BSWAP_32BIG_C(0x5545208fU), BSWAP_32BIG_C(0x524015bbU),
    };
    r_rsip_func100(Param_p2b_func100_026);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[129]);

    static const uint32_t Param_p2b_func100_027[] =
    {
        BSWAP_32BIG_C(0x7b81653dU), BSWAP_32BIG_C(0x7c0bc2fcU), BSWAP_32BIG_C(0x66337d6aU), BSWAP_32BIG_C(0x5f4dc3ddU),
    };
    r_rsip_func100(Param_p2b_func100_027);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub009(0x00002b07U);

    static const uint32_t Param_p2b_func101_042[] =
    {
        BSWAP_32BIG_C(0x689641bbU), BSWAP_32BIG_C(0xf495f926U), BSWAP_32BIG_C(0xac4638f8U), BSWAP_32BIG_C(0x3db48d27U),
    };
    r_rsip_func101(Param_p2b_func101_042);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000022bU);

    static const uint32_t Param_p2b_func101_043[] =
    {
        BSWAP_32BIG_C(0x56661521U), BSWAP_32BIG_C(0x36a027deU), BSWAP_32BIG_C(0xf7d07915U), BSWAP_32BIG_C(0x41ec84c4U),
    };
    r_rsip_func101(Param_p2b_func101_043);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000cU);

    r_rsip_func_sub009(0x0000022bU);

    static const uint32_t Param_p2b_func101_044[] =
    {
        BSWAP_32BIG_C(0xb82581b2U), BSWAP_32BIG_C(0x2d77a3d2U), BSWAP_32BIG_C(0x786e98e8U), BSWAP_32BIG_C(0x8695ac82U),
    };
    r_rsip_func101(Param_p2b_func101_044);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000040U, 0x000008e7U, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p2b_func100_028[] =
        {
            BSWAP_32BIG_C(0xea13a98cU), BSWAP_32BIG_C(0xbbdef03aU), BSWAP_32BIG_C(0x76732ea1U), BSWAP_32BIG_C(
                0xe9aee9a1U),
        };
        r_rsip_func100(Param_p2b_func100_028);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p2b_func101_045[] =
        {
            BSWAP_32BIG_C(0x1d5e6572U), BSWAP_32BIG_C(0x6408c44cU), BSWAP_32BIG_C(0x92851badU), BSWAP_32BIG_C(
                0xd2c59716U),
        };
        r_rsip_func101(Param_p2b_func101_045);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p2b_func100_029[] =
    {
        BSWAP_32BIG_C(0xeb4a585aU), BSWAP_32BIG_C(0x85dbb42eU), BSWAP_32BIG_C(0x8046141cU), BSWAP_32BIG_C(0x124053eeU),
    };
    r_rsip_func100(Param_p2b_func100_029);
    r_rsip_func_sub027(0x40000000U, 0xe8008104U, 0x81010280U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[65]);

    static const uint32_t Param_p2b_func100_030[] =
    {
        BSWAP_32BIG_C(0xcca842f0U), BSWAP_32BIG_C(0xab1e7d42U), BSWAP_32BIG_C(0xe0007c39U), BSWAP_32BIG_C(0x8ae7a977U),
    };
    r_rsip_func100(Param_p2b_func100_030);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[69]);

    static const uint32_t Param_p2b_func100_031[] =
    {
        BSWAP_32BIG_C(0x7d2bd621U), BSWAP_32BIG_C(0x8e8956bbU), BSWAP_32BIG_C(0xa2708035U), BSWAP_32BIG_C(0xea8d22dcU),
    };
    r_rsip_func100(Param_p2b_func100_031);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p2b_func102_004[] =
    {
        BSWAP_32BIG_C(0xcb143cb6U), BSWAP_32BIG_C(0x872e1c26U), BSWAP_32BIG_C(0xccb53884U), BSWAP_32BIG_C(0xd88de107U),
    };
    r_rsip_func102(Param_p2b_func102_004);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
