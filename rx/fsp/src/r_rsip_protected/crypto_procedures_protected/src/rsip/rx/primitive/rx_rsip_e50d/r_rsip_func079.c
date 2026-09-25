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

void r_rsip_func079 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    r_rsip_func_sub028(0x0e0704c4U, 0x01a9d8a8U);

    r_rsip_func_sub024(0x00001fc2U, 0x00000700U, 0xf7049d07U);

    WR1_PROG(REG_1404H, 0x11800000U);
    for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        r_rsip_func_sub001(0x00c20011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x11c80000U);
    for (iLoop = 16U; iLoop < 32U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        r_rsip_func_sub001(0x00c20011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[32]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);
}
