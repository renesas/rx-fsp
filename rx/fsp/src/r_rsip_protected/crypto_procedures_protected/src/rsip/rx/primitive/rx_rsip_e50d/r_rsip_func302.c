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

void r_rsip_func302 (void)
{
    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1f480000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x1111000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func302_func100_001[] =
    {
        BSWAP_32BIG_C(0xcca96996U), BSWAP_32BIG_C(0x8315daf9U), BSWAP_32BIG_C(0x1eec1ae0U), BSWAP_32BIG_C(0x47c4bae0U),
    };
    r_rsip_func100(Param_func302_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func302_func100_002[] =
        {
            BSWAP_32BIG_C(0x5e64eccdU), BSWAP_32BIG_C(0x46132a7dU), BSWAP_32BIG_C(0xfb40589cU), BSWAP_32BIG_C(
                0xcd86bad0U),
        };
        r_rsip_func100(Param_func302_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func302_func101_001[] =
            {
                BSWAP_32BIG_C(0xbf3537c6U), BSWAP_32BIG_C(0x9b07ef01U), BSWAP_32BIG_C(0xb19efe0aU), BSWAP_32BIG_C(
                    0x78aa1227U),
            };
            r_rsip_func101(Param_func302_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x1111000aU);

            static const uint32_t Param_func302_func101_002[] =
            {
                BSWAP_32BIG_C(0x4edc0b34U), BSWAP_32BIG_C(0xabbfef30U), BSWAP_32BIG_C(0xfe49958dU), BSWAP_32BIG_C(
                    0x1e59dcc1U),
            };
            r_rsip_func101(Param_func302_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func302_func100_003[] =
        {
            BSWAP_32BIG_C(0x2926385cU), BSWAP_32BIG_C(0xb001a38fU), BSWAP_32BIG_C(0x32aa453fU), BSWAP_32BIG_C(
                0x77046e52U),
        };
        r_rsip_func100(Param_func302_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func302_func101_003[] =
            {
                BSWAP_32BIG_C(0xadb97954U), BSWAP_32BIG_C(0xf7c0b6e7U), BSWAP_32BIG_C(0x00c42d96U), BSWAP_32BIG_C(
                    0x9ab6f1b6U),
            };
            r_rsip_func101(Param_func302_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x1111000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func302_func101_004[] =
            {
                BSWAP_32BIG_C(0xa7948bfdU), BSWAP_32BIG_C(0x03d16c26U), BSWAP_32BIG_C(0x81435f24U), BSWAP_32BIG_C(
                    0x97dfd0bfU),
            };
            r_rsip_func101(Param_func302_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
