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

rsip_ret_t r_rsip_p78s (uint32_t OutData_State[])
{
    uint32_t iLoop = 0U;

    for (iLoop = 0U; iLoop < 50; iLoop++)
    {
        RD1_ADDR(REG_243CH, &OutData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    RD1_ADDR(REG_2414H, &OutData_State[50]);
    RD1_ADDR(REG_2410H, &OutData_State[51]);

    static const uint32_t Param_p78s_func102_001[] =
    {
        BSWAP_32BIG_C(0x9c350774U), BSWAP_32BIG_C(0xb24c2d4aU), BSWAP_32BIG_C(0x67318322U), BSWAP_32BIG_C(0x95105608U),
    };
    r_rsip_func102(Param_p78s_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
