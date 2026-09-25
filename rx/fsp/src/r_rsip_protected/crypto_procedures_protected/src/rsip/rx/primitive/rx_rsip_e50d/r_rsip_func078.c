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

void r_rsip_func078 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    r_rsip_func_sub028(0x0e0704c4U, 0x018d3a5eU);

    r_rsip_func_sub024(0x00005fc2U, 0x00001700U, 0xf7049d07U);

    WR1_PROG(REG_1404H, 0x10300000U);
    for (iLoop = 36U; iLoop < 52U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x13500000U);
    for (iLoop = 52U; iLoop < 68U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x18500000U);
    for (iLoop = 68U; iLoop < 84U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x18a00000U);
    for (iLoop = 84U; iLoop < 100U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x10800000U);
    for (iLoop = 100U; iLoop < 116U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x18000000U);
    for (iLoop = 116U; iLoop < 132U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[132]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);
}
