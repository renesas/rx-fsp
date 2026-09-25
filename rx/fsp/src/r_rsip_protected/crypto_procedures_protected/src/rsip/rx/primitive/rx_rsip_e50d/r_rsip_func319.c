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

void r_rsip_func319 (void)
{
    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1e480000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e40U, 0x3131000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func319_func100_001[] =
    {
        BSWAP_32BIG_C(0xd3b513ffU), BSWAP_32BIG_C(0x2b7a9accU), BSWAP_32BIG_C(0xb6330a0eU), BSWAP_32BIG_C(0x8d8a7688U),
    };
    r_rsip_func100(Param_func319_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func319_func100_002[] =
        {
            BSWAP_32BIG_C(0xd0cf8da8U), BSWAP_32BIG_C(0x8558d410U), BSWAP_32BIG_C(0x4fa258b0U), BSWAP_32BIG_C(
                0x58b5a871U),
        };
        r_rsip_func100(Param_func319_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x31310009U);

            static const uint32_t Param_func319_func101_001[] =
            {
                BSWAP_32BIG_C(0x61be05eaU), BSWAP_32BIG_C(0xdeab698cU), BSWAP_32BIG_C(0xec5d5a12U), BSWAP_32BIG_C(
                    0x85076572U),
            };
            r_rsip_func101(Param_func319_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x3131000aU);

            static const uint32_t Param_func319_func101_002[] =
            {
                BSWAP_32BIG_C(0x105a9695U), BSWAP_32BIG_C(0xdceead6bU), BSWAP_32BIG_C(0xeba0cf43U), BSWAP_32BIG_C(
                    0x11f5c01fU),
            };
            r_rsip_func101(Param_func319_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func319_func100_003[] =
        {
            BSWAP_32BIG_C(0x61a8ee89U), BSWAP_32BIG_C(0x7757c4b3U), BSWAP_32BIG_C(0x6f0e4232U), BSWAP_32BIG_C(
                0xdada34c0U),
        };
        r_rsip_func100(Param_func319_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x31310009U);

            static const uint32_t Param_func319_func101_003[] =
            {
                BSWAP_32BIG_C(0x20385b1bU), BSWAP_32BIG_C(0xe54f2be7U), BSWAP_32BIG_C(0x5a1a6844U), BSWAP_32BIG_C(
                    0x16115f18U),
            };
            r_rsip_func101(Param_func319_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x3131000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func319_func101_004[] =
            {
                BSWAP_32BIG_C(0x2eb0907fU), BSWAP_32BIG_C(0xdcf582d2U), BSWAP_32BIG_C(0xe4c3a017U), BSWAP_32BIG_C(
                    0x15ab248aU),
            };
            r_rsip_func101(Param_func319_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
