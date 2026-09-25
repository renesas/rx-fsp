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

void r_rsip_func324 (void)
{
    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1dc80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000dc0U, 0x4141000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func324_func100_001[] =
    {
        BSWAP_32BIG_C(0x7849c156U), BSWAP_32BIG_C(0xc0032a69U), BSWAP_32BIG_C(0x6cbc7428U), BSWAP_32BIG_C(0x710fe9e1U),
    };
    r_rsip_func100(Param_func324_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func324_func100_002[] =
        {
            BSWAP_32BIG_C(0x290b14feU), BSWAP_32BIG_C(0xb35a7090U), BSWAP_32BIG_C(0xc24e51c5U), BSWAP_32BIG_C(
                0xca6ede34U),
        };
        r_rsip_func100(Param_func324_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000878U, 0x4141000aU);

            static const uint32_t Param_func324_func101_001[] =
            {
                BSWAP_32BIG_C(0x8f9bec90U), BSWAP_32BIG_C(0x12e5cd42U), BSWAP_32BIG_C(0xee47b7afU), BSWAP_32BIG_C(
                    0xabd26204U),
            };
            r_rsip_func101(Param_func324_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000878U, 0x41410009U);

            static const uint32_t Param_func324_func101_002[] =
            {
                BSWAP_32BIG_C(0x9a3c96ddU), BSWAP_32BIG_C(0xc5d70f85U), BSWAP_32BIG_C(0x1dbdd389U), BSWAP_32BIG_C(
                    0x16b0caafU),
            };
            r_rsip_func101(Param_func324_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func324_func100_003[] =
        {
            BSWAP_32BIG_C(0xeb7e8094U), BSWAP_32BIG_C(0x89da73c6U), BSWAP_32BIG_C(0xd9743ee0U), BSWAP_32BIG_C(
                0x2635b885U),
        };
        r_rsip_func100(Param_func324_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000878U, 0x00000878U, 0x4141000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func324_func101_003[] =
            {
                BSWAP_32BIG_C(0x73ec79c7U), BSWAP_32BIG_C(0x31783eb8U), BSWAP_32BIG_C(0xf2381dd3U), BSWAP_32BIG_C(
                    0x7ace0d31U),
            };
            r_rsip_func101(Param_func324_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000878U, 0x41410009U);

            static const uint32_t Param_func324_func101_004[] =
            {
                BSWAP_32BIG_C(0x6d893ba0U), BSWAP_32BIG_C(0x0139d19dU), BSWAP_32BIG_C(0xf5da07cdU), BSWAP_32BIG_C(
                    0x7bda906dU),
            };
            r_rsip_func101(Param_func324_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
