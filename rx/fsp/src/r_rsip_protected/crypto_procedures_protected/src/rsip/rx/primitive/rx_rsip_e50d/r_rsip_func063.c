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

void r_rsip_func063 (const uint32_t ARG1, const uint32_t ARG2[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub025(0x00003fc1U, 0x00000f00U, 0xd900890fU);

    for (iLoop = ARG1; iLoop < ARG1 + 64; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG2[iLoop]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG2[iLoop + 4]);
        r_rsip_func_sub001(0x00c10021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
}
