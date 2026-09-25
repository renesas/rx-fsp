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

void r_rsip_func303 (void)
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

    static const uint32_t Param_func303_func100_001[] =
    {
        BSWAP_32BIG_C(0x38056005U), BSWAP_32BIG_C(0x79cfc583U), BSWAP_32BIG_C(0xdbb77ad5U), BSWAP_32BIG_C(0x643fc66bU),
    };
    r_rsip_func100(Param_func303_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func303_func100_002[] =
        {
            BSWAP_32BIG_C(0x6a89a848U), BSWAP_32BIG_C(0x3ecaaf5aU), BSWAP_32BIG_C(0xb7369d67U), BSWAP_32BIG_C(
                0xd49a35dcU),
        };
        r_rsip_func100(Param_func303_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x1111000aU);

            static const uint32_t Param_func303_func101_001[] =
            {
                BSWAP_32BIG_C(0x925216e4U), BSWAP_32BIG_C(0x369f4792U), BSWAP_32BIG_C(0x98fc67bfU), BSWAP_32BIG_C(
                    0x180cf027U),
            };
            r_rsip_func101(Param_func303_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func303_func101_002[] =
            {
                BSWAP_32BIG_C(0x168940f4U), BSWAP_32BIG_C(0xd87cd316U), BSWAP_32BIG_C(0x095274afU), BSWAP_32BIG_C(
                    0x73647376U),
            };
            r_rsip_func101(Param_func303_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func303_func100_003[] =
        {
            BSWAP_32BIG_C(0xd7d6cdd4U), BSWAP_32BIG_C(0xa03570e7U), BSWAP_32BIG_C(0xa2989528U), BSWAP_32BIG_C(
                0xf4137a47U),
        };
        r_rsip_func100(Param_func303_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x1111000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func303_func101_003[] =
            {
                BSWAP_32BIG_C(0xf88ca1a4U), BSWAP_32BIG_C(0xfe2f34deU), BSWAP_32BIG_C(0x8a738e46U), BSWAP_32BIG_C(
                    0x6cf019beU),
            };
            r_rsip_func101(Param_func303_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func303_func101_004[] =
            {
                BSWAP_32BIG_C(0xb593b505U), BSWAP_32BIG_C(0x0e670a90U), BSWAP_32BIG_C(0x0689560aU), BSWAP_32BIG_C(
                    0x7fadb6e8U),
            };
            r_rsip_func101(Param_func303_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
