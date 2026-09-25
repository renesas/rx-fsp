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

rsip_ret_t r_rsip_p95f (const uint32_t InData_Text[],
                        const uint32_t InData_TextLen[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x00008c00U, 0x0000000fU, 0x38008800U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    static const uint32_t Param_p95f_func100_001[] =
    {
        BSWAP_32BIG_C(0xc05bdd7fU), BSWAP_32BIG_C(0x11f335b9U), BSWAP_32BIG_C(0x3233e412U), BSWAP_32BIG_C(0x17d6cb04U),
    };
    r_rsip_func100(Param_p95f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub020(0x000003c1U, 0xe7000d05U);
        WR4_ADDR(REG_1420H, &InData_Text[0]);

        r_rsip_func_sub023(0x0000b420U, 0x00000080U, 0x80840001U);
        r_rsip_func_sub001(0x03410011U);

        r_rsip_func_sub021(0x00000821U, 0x0000a400U, 0x00000080U, 0x0000b7e0U);
        WR1_PROG(REG_1600H, 0x00000080U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub022(0x3c002be0U, 0x12003c3fU, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p95f_func100_002[] =
        {
            BSWAP_32BIG_C(0x62c03788U), BSWAP_32BIG_C(0xd205e57fU), BSWAP_32BIG_C(0x0aaae18aU), BSWAP_32BIG_C(
                0xa91c4258U),
        };
        r_rsip_func100(Param_p95f_func100_002);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000080U);
        r_rsip_func_sub016(0x81840001U, 0x00005012U);
        RD1_ADDR(REG_1420H, &OutData_Text[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[2]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[3]);

        static const uint32_t Param_p95f_func101_001[] =
        {
            BSWAP_32BIG_C(0xd18a4d3dU), BSWAP_32BIG_C(0x109a2ee3U), BSWAP_32BIG_C(0x48e5b8a4U), BSWAP_32BIG_C(
                0x4363f41aU),
        };
        r_rsip_func101(Param_p95f_func101_001);
    }
    else
    {
        static const uint32_t Param_p95f_func101_002[] =
        {
            BSWAP_32BIG_C(0x887db1e6U), BSWAP_32BIG_C(0xf8e35fffU), BSWAP_32BIG_C(0x9eb0432fU), BSWAP_32BIG_C(
                0xfa39417eU),
        };
        r_rsip_func101(Param_p95f_func101_002);
    }

    r_rsip_func_sub020(0x000000a1U, 0x0c200104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    static const uint32_t Param_p95f_func100_003[] =
    {
        BSWAP_32BIG_C(0x33c39418U), BSWAP_32BIG_C(0x145566a4U), BSWAP_32BIG_C(0x65ac199eU), BSWAP_32BIG_C(0xa3933e01U),
    };
    r_rsip_func100(Param_p95f_func100_003);
    WR1_PROG(REG_1824H, 0x09100105U);
    r_rsip_func_sub001(0x00410011U);

    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_MAC[0]);

    static const uint32_t Param_p95f_func102_001[] =
    {
        BSWAP_32BIG_C(0x466ef6fdU), BSWAP_32BIG_C(0xcd6ae3fcU), BSWAP_32BIG_C(0xbe497680U), BSWAP_32BIG_C(0xc80977f2U),
    };
    r_rsip_func102(Param_p95f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
