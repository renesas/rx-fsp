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

void r_rsip_func413 (void)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_func413_func100_001[] =
    {
        BSWAP_32BIG_C(0x1b4b85adU), BSWAP_32BIG_C(0xc7121183U), BSWAP_32BIG_C(0x8419fffbU), BSWAP_32BIG_C(0xbb6b264cU),
    };
    r_rsip_func100(Param_func413_func100_001);
    r_rsip_func_sub021(0x00002d60U, 0x0002696bU, 0x0000094aU, 0x0000b7e0U);
    WR1_PROG(REG_1600H, 0xd6e85365U);

    r_rsip_func_sub016(0x81010160U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1608H, 0x81840002U);
        r_rsip_func_sub001(0x00490011U);

        WR1_PROG(REG_1608H, 0x8184000cU);
        WR1_PROG(REG_1824H, 0x9c000005U);
        r_rsip_func_sub001(0x00490011U);

        static const uint32_t Param_func413_func100_002[] =
        {
            BSWAP_32BIG_C(0x671cb7a3U), BSWAP_32BIG_C(0x1bc87760U), BSWAP_32BIG_C(0xc0b0446eU), BSWAP_32BIG_C(
                0x5fcaa444U),
        };
        r_rsip_func100(Param_func413_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000bffU);

            static const uint32_t Param_func413_func101_001[] =
            {
                BSWAP_32BIG_C(0x5adc316eU), BSWAP_32BIG_C(0xf13d0d45U), BSWAP_32BIG_C(0xa830c809U), BSWAP_32BIG_C(
                    0x71b9cab4U),
            };
            r_rsip_func101(Param_func413_func101_001);
        }
        else
        {
            static const uint32_t Param_func413_func101_002[] =
            {
                BSWAP_32BIG_C(0xa1e472c6U), BSWAP_32BIG_C(0xf99e909fU), BSWAP_32BIG_C(0x5ce638aaU), BSWAP_32BIG_C(
                    0x83637098U),
            };
            r_rsip_func101(Param_func413_func101_002);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x0000a440U, 0x00000010U, 0x0000a580U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00002d40U);

        static const uint32_t Param_func413_func101_003[] =
        {
            BSWAP_32BIG_C(0xb5f8d112U), BSWAP_32BIG_C(0xd488b433U), BSWAP_32BIG_C(0xb7334b4dU), BSWAP_32BIG_C(
                0x2a26b3d1U),
        };
        r_rsip_func101(Param_func413_func101_003);
    }

    r_rsip_func_sub011(0x3800094bU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
