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

rsip_ret_t r_rsip_pa1f (const uint32_t InData_Text[],
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

    static const uint32_t Param_pa1f_func100_001[] =
    {
        BSWAP_32BIG_C(0x77dd6b5cU), BSWAP_32BIG_C(0x40fd65e3U), BSWAP_32BIG_C(0x8cab2754U), BSWAP_32BIG_C(0xf8eaa0d5U),
    };
    r_rsip_func100(Param_pa1f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0xe7008d05U);
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

        static const uint32_t Param_pa1f_func100_002[] =
        {
            BSWAP_32BIG_C(0x538a5b89U), BSWAP_32BIG_C(0x5782f161U), BSWAP_32BIG_C(0x2c60b452U), BSWAP_32BIG_C(
                0x56711cceU),
        };
        r_rsip_func100(Param_pa1f_func100_002);
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

        static const uint32_t Param_pa1f_func101_001[] =
        {
            BSWAP_32BIG_C(0xccc3be3eU), BSWAP_32BIG_C(0xda97707cU), BSWAP_32BIG_C(0x9fbadecdU), BSWAP_32BIG_C(
                0x747ccfe9U),
        };
        r_rsip_func101(Param_pa1f_func101_001);
    }
    else
    {
        static const uint32_t Param_pa1f_func101_002[] =
        {
            BSWAP_32BIG_C(0xc4773aecU), BSWAP_32BIG_C(0xff8e509fU), BSWAP_32BIG_C(0x58bc359dU), BSWAP_32BIG_C(
                0xcb99937bU),
        };
        r_rsip_func101(Param_pa1f_func101_002);
    }

    r_rsip_func_sub020(0x000000a1U, 0x0c200104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    static const uint32_t Param_pa1f_func100_003[] =
    {
        BSWAP_32BIG_C(0xcd522ecfU), BSWAP_32BIG_C(0x71b9a9b2U), BSWAP_32BIG_C(0x9ce85a7bU), BSWAP_32BIG_C(0x511ade95U),
    };
    r_rsip_func100(Param_pa1f_func100_003);
    WR1_PROG(REG_182CH, 0x40000000U);
    WR1_PROG(REG_1824H, 0x09108105U);
    r_rsip_func_sub001(0x00410011U);

    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_MAC[0]);

    static const uint32_t Param_pa1f_func102_001[] =
    {
        BSWAP_32BIG_C(0x6b066a62U), BSWAP_32BIG_C(0x7ed63bb9U), BSWAP_32BIG_C(0x49ec1073U), BSWAP_32BIG_C(0x0bb19886U),
    };
    r_rsip_func102(Param_pa1f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
