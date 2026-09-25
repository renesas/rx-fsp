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

void r_rsip_func083 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_func083_func100_001[] =
    {
        BSWAP_32BIG_C(0x9625497cU), BSWAP_32BIG_C(0xd8f71dc2U), BSWAP_32BIG_C(0xee8c2bf1U), BSWAP_32BIG_C(0x969c47eaU),
    };
    r_rsip_func100(Param_func083_func100_001);
    r_rsip_func_sub010(0x000000c7U, 0x800100c0U);
    WR1_PROG(REG_1420H, ARG1[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x00003416U, 0x00008c00U, 0x00000003U, 0x0000b440U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x00002840U);

    r_rsip_func_sub016(0x81010040U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x000008a5U);

    WR1_PROG(REG_1600H, 0x00003466U);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        WR1_PROG(REG_1608H, 0x81010060U);
        r_rsip_func_sub001(0x12490005U);
        r_rsip_func_sub001(0x1009000dU);

        WR1_PROG(REG_1600H, 0x00086c63U);

        WR1_PROG(REG_1600H, 0x00002ca0U);

        static const uint32_t Param_func083_func101_001[] =
        {
            BSWAP_32BIG_C(0x1e3d0990U), BSWAP_32BIG_C(0x1fd04c17U), BSWAP_32BIG_C(0x04088b9fU), BSWAP_32BIG_C(
                0x9d65e5d2U),
        };
        r_rsip_func101(Param_func083_func101_001);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000845U);

    static const uint32_t Param_func083_func100_002[] =
    {
        BSWAP_32BIG_C(0x7cffa8e5U), BSWAP_32BIG_C(0x8f12031dU), BSWAP_32BIG_C(0xa70e58b2U), BSWAP_32BIG_C(0xf4550e27U),
    };
    r_rsip_func100(Param_func083_func100_002);

    r_rsip_func_sub022(0x000034e6U, 0x00036c00U, 0x00004400U);

    r_rsip_func_sub016(0x81010160U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1600H, 0x00000001U);

    for (iLoop = 1; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100c0U);
        WR1_PROG(REG_1420H, ARG1[iLoop]);
        r_rsip_func_sub034(0x00003506U, 0x01807507U);
        WR1_PROG(REG_1608H, 0x81010100U);
        r_rsip_func_sub001(0x02490005U);

        WR1_PROG(REG_1600H, 0x000034e6U);

        WR1_PROG(REG_1600H, 0x00002ca0U);

        static const uint32_t Param_func083_func101_002[] =
        {
            BSWAP_32BIG_C(0x77f6830aU), BSWAP_32BIG_C(0xef2eae1aU), BSWAP_32BIG_C(0x4c00385cU), BSWAP_32BIG_C(
                0xaea890f8U),
        };
        r_rsip_func101(Param_func083_func101_002);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000965U);
    r_rsip_func_sub006(0x38008ec0U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_func083_func100_003[] =
    {
        BSWAP_32BIG_C(0x8137bef6U), BSWAP_32BIG_C(0xb3b7976cU), BSWAP_32BIG_C(0x1b2fc45cU), BSWAP_32BIG_C(0x990b891cU),
    };
    r_rsip_func100(Param_func083_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub023(0x00000908U, 0x01807507U, 0x81010100U);
        r_rsip_func_sub001(0x02490005U);

        static const uint32_t Param_func083_func101_003[] =
        {
            BSWAP_32BIG_C(0x6c2b117cU), BSWAP_32BIG_C(0xcb22753dU), BSWAP_32BIG_C(0xd92f5086U), BSWAP_32BIG_C(
                0x98d6b47aU),
        };
        r_rsip_func101(Param_func083_func101_003);
    }

    static const uint32_t Param_func083_func100_004[] =
    {
        BSWAP_32BIG_C(0xbebbc2c3U), BSWAP_32BIG_C(0x338795d9U), BSWAP_32BIG_C(0x3335fde8U), BSWAP_32BIG_C(0x697a6019U),
    };
    r_rsip_func100(Param_func083_func100_004);
    r_rsip_func_sub021(0x00003416U, 0x0000a400U, 0x00000003U, 0x00026800U);
    r_rsip_func_sub021(0x0000240bU, 0x00008c00U, 0x00000003U, 0x0000b440U);
    r_rsip_func_sub021(0x00000004U, 0x00002840U, 0x00008c40U, 0x00000003U);

    r_rsip_func_sub016(0x81010040U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x000008a5U);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub001(0x00400005U);

        WR1_PROG(REG_1600H, 0x00002ca0U);

        static const uint32_t Param_func083_func101_004[] =
        {
            BSWAP_32BIG_C(0x7b35ddc1U), BSWAP_32BIG_C(0xb7dec69eU), BSWAP_32BIG_C(0x23e29cd0U), BSWAP_32BIG_C(
                0xfb967808U),
        };
        r_rsip_func101(Param_func083_func101_004);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000845U);

    WAIT_STS(REG_2030H, 4, 1);

    WAIT_STS(REG_1828H, 6, 0);
    WR1_PROG(REG_143CH, 0x00000400U);
    WR1_PROG(REG_1824H, 0x00000000U);
    r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1608H, 0x8084001eU);
    r_rsip_func_sub001(0x03410011U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
