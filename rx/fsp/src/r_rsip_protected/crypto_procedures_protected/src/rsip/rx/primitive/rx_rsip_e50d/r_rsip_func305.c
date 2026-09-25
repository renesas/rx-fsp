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

void r_rsip_func305 (void)
{
    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1ec80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x2121000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func305_func100_001[] =
    {
        BSWAP_32BIG_C(0x25405124U), BSWAP_32BIG_C(0x552c539eU), BSWAP_32BIG_C(0x3441c407U), BSWAP_32BIG_C(0xc76c7203U),
    };
    r_rsip_func100(Param_func305_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func305_func100_002[] =
        {
            BSWAP_32BIG_C(0x158f8471U), BSWAP_32BIG_C(0x53aa88f3U), BSWAP_32BIG_C(0xf7d83c45U), BSWAP_32BIG_C(
                0x347a2c99U),
        };
        r_rsip_func100(Param_func305_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x2121000aU);

            static const uint32_t Param_func305_func101_001[] =
            {
                BSWAP_32BIG_C(0x1414db55U), BSWAP_32BIG_C(0xb8bd0378U), BSWAP_32BIG_C(0xd848da11U), BSWAP_32BIG_C(
                    0x20b063fdU),
            };
            r_rsip_func101(Param_func305_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func305_func101_002[] =
            {
                BSWAP_32BIG_C(0xf97fad2dU), BSWAP_32BIG_C(0x7e856ec4U), BSWAP_32BIG_C(0x34ed511aU), BSWAP_32BIG_C(
                    0x72ee4071U),
            };
            r_rsip_func101(Param_func305_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func305_func100_003[] =
        {
            BSWAP_32BIG_C(0x3859111dU), BSWAP_32BIG_C(0x0b2a9d10U), BSWAP_32BIG_C(0x2e69bcbcU), BSWAP_32BIG_C(
                0xf06aafcaU),
        };
        r_rsip_func100(Param_func305_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x2121000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func305_func101_003[] =
            {
                BSWAP_32BIG_C(0xe289d239U), BSWAP_32BIG_C(0x84538c70U), BSWAP_32BIG_C(0x67a9f2c9U), BSWAP_32BIG_C(
                    0x73cf4cd6U),
            };
            r_rsip_func101(Param_func305_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func305_func101_004[] =
            {
                BSWAP_32BIG_C(0xca5177afU), BSWAP_32BIG_C(0xbef484d4U), BSWAP_32BIG_C(0x67707556U), BSWAP_32BIG_C(
                    0xad668720U),
            };
            r_rsip_func101(Param_func305_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
