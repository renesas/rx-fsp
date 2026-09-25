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

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p96f (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p96f_func100_001[] =
    {
        BSWAP_32BIG_C(0x39378f2aU), BSWAP_32BIG_C(0xcb8cc19bU), BSWAP_32BIG_C(0x44114973U), BSWAP_32BIG_C(0xfa68f340U),
    };
    r_rsip_func100(Param_p96f_func100_001);

    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    static const uint32_t Param_p96f_func102_001[] =
    {
        BSWAP_32BIG_C(0x8abcc63dU), BSWAP_32BIG_C(0x4d5a79a1U), BSWAP_32BIG_C(0x20afd927U), BSWAP_32BIG_C(0xbcc6be8fU),
    };
    r_rsip_func102(Param_p96f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
