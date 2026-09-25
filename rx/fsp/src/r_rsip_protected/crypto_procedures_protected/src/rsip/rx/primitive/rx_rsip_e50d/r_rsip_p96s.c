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

rsip_ret_t r_rsip_p96s (uint32_t OutData_State[])
{
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    RD1_ADDR(REG_1C08H, &OutData_State[0]);
    RD1_ADDR(REG_1C10H, &OutData_State[1]);

    static const uint32_t Param_p96s_func102_001[] =
    {
        BSWAP_32BIG_C(0x3b70844cU), BSWAP_32BIG_C(0x5414bc6cU), BSWAP_32BIG_C(0x692056aeU), BSWAP_32BIG_C(0x92400444U),
    };
    r_rsip_func102(Param_p96s_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
