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

void r_rsip_func304 (void)
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

    static const uint32_t Param_func304_func100_001[] =
    {
        BSWAP_32BIG_C(0x0df18e82U), BSWAP_32BIG_C(0x18ee0398U), BSWAP_32BIG_C(0xade08ffdU), BSWAP_32BIG_C(0xb7d61555U),
    };
    r_rsip_func100(Param_func304_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func304_func100_002[] =
        {
            BSWAP_32BIG_C(0x3437472cU), BSWAP_32BIG_C(0xc9008188U), BSWAP_32BIG_C(0xd1e0958cU), BSWAP_32BIG_C(
                0x31053dcdU),
        };
        r_rsip_func100(Param_func304_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func304_func101_001[] =
            {
                BSWAP_32BIG_C(0x04e0341aU), BSWAP_32BIG_C(0x13b69d7cU), BSWAP_32BIG_C(0xc32d8310U), BSWAP_32BIG_C(
                    0xbf04c02fU),
            };
            r_rsip_func101(Param_func304_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x2121000aU);

            static const uint32_t Param_func304_func101_002[] =
            {
                BSWAP_32BIG_C(0x5051ff84U), BSWAP_32BIG_C(0x47a2b03bU), BSWAP_32BIG_C(0xfb7c23b7U), BSWAP_32BIG_C(
                    0x2a4118ddU),
            };
            r_rsip_func101(Param_func304_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func304_func100_003[] =
        {
            BSWAP_32BIG_C(0xfbc29990U), BSWAP_32BIG_C(0x655cdceaU), BSWAP_32BIG_C(0x17cd8716U), BSWAP_32BIG_C(
                0xfcfca606U),
        };
        r_rsip_func100(Param_func304_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func304_func101_003[] =
            {
                BSWAP_32BIG_C(0x4bc1c6fcU), BSWAP_32BIG_C(0xdb382693U), BSWAP_32BIG_C(0x75afc462U), BSWAP_32BIG_C(
                    0x66b17e13U),
            };
            r_rsip_func101(Param_func304_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x2121000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func304_func101_004[] =
            {
                BSWAP_32BIG_C(0xec2ff851U), BSWAP_32BIG_C(0x1dd6ddb0U), BSWAP_32BIG_C(0xa9cc9788U), BSWAP_32BIG_C(
                    0xfc0edc5bU),
            };
            r_rsip_func101(Param_func304_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
