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

void r_rsip_func314 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000379dU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800db40U, 0x00260000U);

        static const uint32_t Param_func314_func100_001[] =
        {
            BSWAP_32BIG_C(0x8d614a62U), BSWAP_32BIG_C(0x68c37ce4U), BSWAP_32BIG_C(0x2d18d706U), BSWAP_32BIG_C(
                0xef2eb11bU),
        };
        r_rsip_func100(Param_func314_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x1818000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            WR1_PROG(REG_1404H, 0x1a380000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);

            static const uint32_t Param_func314_func100_002[] =
            {
                BSWAP_32BIG_C(0x0376d780U), BSWAP_32BIG_C(0xe04a6f9aU), BSWAP_32BIG_C(0x422c9a35U), BSWAP_32BIG_C(
                    0x7e4a9f44U),
            };
            r_rsip_func100(Param_func314_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x13580000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19700000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000428U);
                r_rsip_func_sub005(0x00000428U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000a40U);
                r_rsip_func_sub005(0x00000a40U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func314_func101_001[] =
                {
                    BSWAP_32BIG_C(0xb0c4be57U), BSWAP_32BIG_C(0x20cf07d0U), BSWAP_32BIG_C(0xda0cf715U), BSWAP_32BIG_C(
                        0xb90d46fdU),
                };
                r_rsip_func101(Param_func314_func101_001);
            }
            else
            {
                r_rsip_func_sub030(0x1f080000U, 0x00000b7bU, 0x81b0001bU);
                r_rsip_func_sub001(0x00c00011U);
                r_rsip_func_sub001(0x00c900c1U);

                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c000d1U);
                r_rsip_func_sub002(0x00000428U, 0x00000838U, 0x00000838U, 0x1a1a0009U);

                r_rsip_func_sub009(0x0000f314U);

                static const uint32_t Param_func314_func101_002[] =
                {
                    BSWAP_32BIG_C(0x99ef021dU), BSWAP_32BIG_C(0x6ad4bcbaU), BSWAP_32BIG_C(0x3b8c7d9aU), BSWAP_32BIG_C(
                        0x9ef24be3U),
                };
                r_rsip_func101(Param_func314_func101_002);
                r_rsip_func317();

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000428U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x1f080000U);
                r_rsip_func_sub001(0x00c000d1U);

                r_rsip_func_sub004(0x0b040184U, 0xf6428095U);

                OFS_ADR = 224;

                r_rsip_func_sub012(0x1f180000U, 0x0000b400U, 0x00000030U);

                r_rsip_func_sub009(0x0000f314U);

                static const uint32_t Param_func314_func101_003[] =
                {
                    BSWAP_32BIG_C(0xf7da927dU), BSWAP_32BIG_C(0x26119004U), BSWAP_32BIG_C(0x83eb9b0dU), BSWAP_32BIG_C(
                        0xa2497f43U),
                };
                r_rsip_func101(Param_func314_func101_003);
                r_rsip_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c000d1U);
                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000838U, 0x1a1a0009U);

                r_rsip_func_sub009(0x0000f314U);

                static const uint32_t Param_func314_func101_004[] =
                {
                    BSWAP_32BIG_C(0x9e8c15b1U), BSWAP_32BIG_C(0x31ccc777U), BSWAP_32BIG_C(0x9ce4fdd3U), BSWAP_32BIG_C(
                        0x73bfb53bU),
                };
                r_rsip_func101(Param_func314_func101_004);
                r_rsip_func318();

                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func314_func101_005[] =
                {
                    BSWAP_32BIG_C(0xbf768421U), BSWAP_32BIG_C(0xe71c32bdU), BSWAP_32BIG_C(0x0b28686dU), BSWAP_32BIG_C(
                        0xed5155dcU),
                };
                r_rsip_func101(Param_func314_func101_005);
            }
        }
        else
        {
            static const uint32_t Param_func314_func101_006[] =
            {
                BSWAP_32BIG_C(0x6e58e476U), BSWAP_32BIG_C(0x94bc215eU), BSWAP_32BIG_C(0x29869d39U), BSWAP_32BIG_C(
                    0xd7666b8eU),
            };
            r_rsip_func101(Param_func314_func101_006);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
