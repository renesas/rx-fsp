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

void r_rsip_func501 (const uint32_t ARG1[], uint32_t ARG2)
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1824H, 0x08000065U);
    r_rsip_func_sub001(0x00410011U);

    r_rsip_func_sub020(0x000000a1U, 0x07000c04U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    r_rsip_func_sub020(0x000000a1U, 0x08000054U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1444H, 0x00020061U);
    WR1_PROG(REG_1824H, 0x0e108406U);

    for (iLoop = 0U; iLoop < ARG2; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func216();
}
