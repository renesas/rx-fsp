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

rsip_ret_t r_rsip_p58u (const uint32_t InData_Msg[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2440H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020065U);

    for (iLoop = 0U; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop = iLoop + S_RAM[0])
    {
        WAIT_STS(REG_1444H, 31, 1);
        for (jLoop = 0U; jLoop < S_RAM[0]; jLoop = jLoop + 2)
        {
            WR2_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop]);
        }
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001400U);

    static const uint32_t Param_p58u_func101_001[] =
    {
        BSWAP_32BIG_C(0xa1c2d2fdU), BSWAP_32BIG_C(0xb847102aU), BSWAP_32BIG_C(0x802d0991U), BSWAP_32BIG_C(0xc3641923U),
    };
    r_rsip_func101(Param_p58u_func101_001);

    return RSIP_RET_PASS;
}
