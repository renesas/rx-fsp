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

void r_rsip_p97a (const uint32_t InData_DataA[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1444H, 0x00020066U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_DataA[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_DataA[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    WAIT_STS(REG_1C30H, 0, 1);

    static const uint32_t Param_p97a_func101_001[] =
    {
        BSWAP_32BIG_C(0x04c8efa5U), BSWAP_32BIG_C(0x210c8b91U), BSWAP_32BIG_C(0x7451177aU), BSWAP_32BIG_C(0xe4b2d720U),
    };
    r_rsip_func101(Param_p97a_func101_001);
}
