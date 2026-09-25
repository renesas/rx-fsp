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

void r_rsip_func317 (void)
{
    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1f080000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e40U, 0x1919000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func317_func100_001[] =
    {
        BSWAP_32BIG_C(0x5078d373U), BSWAP_32BIG_C(0x1dbde61eU), BSWAP_32BIG_C(0xf74379e4U), BSWAP_32BIG_C(0x8e024e84U),
    };
    r_rsip_func100(Param_func317_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func317_func100_002[] =
        {
            BSWAP_32BIG_C(0xed7307feU), BSWAP_32BIG_C(0x898817b9U), BSWAP_32BIG_C(0xda0a4537U), BSWAP_32BIG_C(
                0x9f2c6e30U),
        };
        r_rsip_func100(Param_func317_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x19190009U);

            static const uint32_t Param_func317_func101_001[] =
            {
                BSWAP_32BIG_C(0x9283a0f7U), BSWAP_32BIG_C(0x0d103cb4U), BSWAP_32BIG_C(0x52dc4385U), BSWAP_32BIG_C(
                    0x35b7d29fU),
            };
            r_rsip_func101(Param_func317_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x1919000aU);

            static const uint32_t Param_func317_func101_002[] =
            {
                BSWAP_32BIG_C(0x39f14cb4U), BSWAP_32BIG_C(0x7445bf7aU), BSWAP_32BIG_C(0xd2b359e8U), BSWAP_32BIG_C(
                    0x87886139U),
            };
            r_rsip_func101(Param_func317_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func317_func100_003[] =
        {
            BSWAP_32BIG_C(0x16a20b7cU), BSWAP_32BIG_C(0xaace26d9U), BSWAP_32BIG_C(0x74de1975U), BSWAP_32BIG_C(
                0x59f7f3c3U),
        };
        r_rsip_func100(Param_func317_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x19190009U);

            static const uint32_t Param_func317_func101_003[] =
            {
                BSWAP_32BIG_C(0x51ee61c8U), BSWAP_32BIG_C(0x666beacfU), BSWAP_32BIG_C(0x832b098fU), BSWAP_32BIG_C(
                    0x2c4f7e67U),
            };
            r_rsip_func101(Param_func317_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x1919000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func317_func101_004[] =
            {
                BSWAP_32BIG_C(0x9e1a2479U), BSWAP_32BIG_C(0xbbde5425U), BSWAP_32BIG_C(0x4d0803f5U), BSWAP_32BIG_C(
                    0xe3e6c7e3U),
            };
            r_rsip_func101(Param_func317_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
