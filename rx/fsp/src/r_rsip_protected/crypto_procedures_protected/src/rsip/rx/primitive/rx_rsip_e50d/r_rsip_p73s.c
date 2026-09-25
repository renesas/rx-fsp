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

rsip_ret_t r_rsip_p73s (uint32_t OutData_State[])
{
    uint32_t iLoop = 0U;

    for (iLoop = 0U; iLoop < 18U; iLoop++)
    {
        RD1_ADDR(REG_202CH, &OutData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    RD1_ADDR(REG_2014H, &OutData_State[18]);
    RD1_ADDR(REG_2010H, &OutData_State[19]);

    static const uint32_t Param_p73s_func102_001[] =
    {
        BSWAP_32BIG_C(0xbbf79645U), BSWAP_32BIG_C(0x6c522492U), BSWAP_32BIG_C(0x5034f8acU), BSWAP_32BIG_C(0x86982578U),
    };
    r_rsip_func102(Param_p73s_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
