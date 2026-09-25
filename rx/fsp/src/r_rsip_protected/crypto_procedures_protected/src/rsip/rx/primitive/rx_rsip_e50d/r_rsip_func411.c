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

void r_rsip_func411 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_func411_func100_001[] =
    {
        BSWAP_32BIG_C(0x859ab97cU), BSWAP_32BIG_C(0x70da3b61U), BSWAP_32BIG_C(0x98646e1fU), BSWAP_32BIG_C(0x8d3bcfe6U),
    };
    r_rsip_func100(Param_func411_func100_001);

    r_rsip_func_sub021(0x3420a8a0U, 0x00000006U, 0x2000b4a0U, 0x00000005U);

    r_rsip_func_sub021(0x000034c5U, 0x380088c0U, 0x00000002U, 0x100008c6U);

    r_rsip_func_sub021(0x380088c0U, 0x00000003U, 0x1000b4c0U, 0x00000001U);

    r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000080U);

    WR1_PROG(REG_1608H, 0x80b10000U);
    r_rsip_func_sub001(0x034000c5U);

    r_rsip_func_sub014(0x00007c06U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub021(0x0000b560U, 0x00000007U, 0x0000b580U, 0x000000a4U);

        static const uint32_t Param_func411_func101_001[] =
        {
            BSWAP_32BIG_C(0x1fdc18cdU), BSWAP_32BIG_C(0x0bab55a9U), BSWAP_32BIG_C(0xf5c8b118U), BSWAP_32BIG_C(
                0x5839aa4bU),
        };
        r_rsip_func101(Param_func411_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub021(0x0000b560U, 0x00000008U, 0x0000b580U, 0x000000a0U);

        static const uint32_t Param_func411_func101_002[] =
        {
            BSWAP_32BIG_C(0x9b26e780U), BSWAP_32BIG_C(0x949241d1U), BSWAP_32BIG_C(0x69939ec9U), BSWAP_32BIG_C(
                0x620cb816U),
        };
        r_rsip_func101(Param_func411_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        r_rsip_func_sub021(0x0000b560U, 0x0000000cU, 0x0000b580U, 0x00000090U);

        static const uint32_t Param_func411_func101_003[] =
        {
            BSWAP_32BIG_C(0x83fcbc77U), BSWAP_32BIG_C(0x8b685409U), BSWAP_32BIG_C(0x6d438e44U), BSWAP_32BIG_C(
                0x92a375d4U),
        };
        r_rsip_func101(Param_func411_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        r_rsip_func_sub021(0x0000b560U, 0x00000010U, 0x0000b580U, 0x00000080U);

        static const uint32_t Param_func411_func101_004[] =
        {
            BSWAP_32BIG_C(0xf01178fcU), BSWAP_32BIG_C(0x45224f41U), BSWAP_32BIG_C(0x3dbe3642U), BSWAP_32BIG_C(
                0x3611ba30U),
        };
        r_rsip_func101(Param_func411_func101_004);
    }

    WR1_PROG(REG_1600H, 0x0000094aU);

    static const uint32_t Param_func411_func100_002[] =
    {
        BSWAP_32BIG_C(0xe8d6c39bU), BSWAP_32BIG_C(0x3e99d931U), BSWAP_32BIG_C(0xd3478b78U), BSWAP_32BIG_C(0xed41e455U),
    };
    r_rsip_func100(Param_func411_func100_002);
    r_rsip_func_sub016(0x81010160U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub010(0x000000c7U, 0x80810000U);
        WR1_PROG(REG_1420H, ARG1[iLoop]);
        r_rsip_func_sub034(0x0000a400U, 0x00000004U);

        WR1_PROG(REG_1600H, 0x00002d40U);
        static const uint32_t Param_func411_func101_005[] =
        {
            BSWAP_32BIG_C(0x705fceadU), BSWAP_32BIG_C(0xbd6b077eU), BSWAP_32BIG_C(0x282cb934U), BSWAP_32BIG_C(
                0xb3590a40U),
        };
        r_rsip_func101(Param_func411_func101_005);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x3800094bU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
