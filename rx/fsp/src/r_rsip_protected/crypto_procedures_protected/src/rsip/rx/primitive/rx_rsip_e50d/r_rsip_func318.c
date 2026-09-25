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

void r_rsip_func318 (void)
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

    static const uint32_t Param_func318_func100_001[] =
    {
        BSWAP_32BIG_C(0x2e1edc14U), BSWAP_32BIG_C(0x39284232U), BSWAP_32BIG_C(0x5fa23d46U), BSWAP_32BIG_C(0x5c0512b1U),
    };
    r_rsip_func100(Param_func318_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func318_func100_002[] =
        {
            BSWAP_32BIG_C(0x2bc0321aU), BSWAP_32BIG_C(0x5cc1fd02U), BSWAP_32BIG_C(0x9d13be4cU), BSWAP_32BIG_C(
                0x1d3ad8c9U),
        };
        r_rsip_func100(Param_func318_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x1919000aU);

            static const uint32_t Param_func318_func101_001[] =
            {
                BSWAP_32BIG_C(0x806ff243U), BSWAP_32BIG_C(0x8c30d491U), BSWAP_32BIG_C(0x91315fa2U), BSWAP_32BIG_C(
                    0x2ce71e02U),
            };
            r_rsip_func101(Param_func318_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x19190009U);

            static const uint32_t Param_func318_func101_002[] =
            {
                BSWAP_32BIG_C(0x323b42e2U), BSWAP_32BIG_C(0xa44564e7U), BSWAP_32BIG_C(0xcbb26f09U), BSWAP_32BIG_C(
                    0x2ee1dd10U),
            };
            r_rsip_func101(Param_func318_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func318_func100_003[] =
        {
            BSWAP_32BIG_C(0xec20033cU), BSWAP_32BIG_C(0x068da310U), BSWAP_32BIG_C(0xc8d39353U), BSWAP_32BIG_C(
                0x48fb9251U),
        };
        r_rsip_func100(Param_func318_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x1919000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func318_func101_003[] =
            {
                BSWAP_32BIG_C(0xe2cbffe5U), BSWAP_32BIG_C(0xfebf100cU), BSWAP_32BIG_C(0x93d27cf7U), BSWAP_32BIG_C(
                    0x96c358d3U),
            };
            r_rsip_func101(Param_func318_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x19190009U);

            static const uint32_t Param_func318_func101_004[] =
            {
                BSWAP_32BIG_C(0xb39bf8c4U), BSWAP_32BIG_C(0x15430630U), BSWAP_32BIG_C(0xdde67965U), BSWAP_32BIG_C(
                    0xb19ee958U),
            };
            r_rsip_func101(Param_func318_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
