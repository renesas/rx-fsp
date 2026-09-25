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

rsip_ret_t r_rsip_p73u (const uint32_t InData_Msg[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
    }

    r_rsip_func_sub043();

    static const uint32_t Param_p73u_func101_001[] =
    {
        BSWAP_32BIG_C(0xcb2a465eU), BSWAP_32BIG_C(0xb460a654U), BSWAP_32BIG_C(0xf5a95abaU), BSWAP_32BIG_C(0x81dcf43dU),
    };
    r_rsip_func101(Param_p73u_func101_001);

    return RSIP_RET_PASS;
}
