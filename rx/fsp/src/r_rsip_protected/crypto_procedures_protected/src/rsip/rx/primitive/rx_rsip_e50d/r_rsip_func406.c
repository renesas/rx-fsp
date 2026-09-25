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

void r_rsip_func406 (const uint32_t ARG1[])
{
    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    r_rsip_func_sub028(0x0e0704c4U, 0x785d648dU);

    WR1_PROG(REG_1404H, 0x10500000U);
    r_rsip_func_sub008(0x000033c2U, 0x00000c00U, 0xf7049d07U);
    WR4_ADDR(REG_1420H, &ARG1[20]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[24]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x10a00000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[28]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[32]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x11e00000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[36]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[40]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x10000000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[44]);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1404H, 0x11900000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[48]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[52]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x10f00000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[56]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[60]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x11400000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[64]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[68]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[72]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1404H, 0x1af00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000000U);
    r_rsip_func_sub001(0x00c00011U);
    r_rsip_func_sub001(0x00c20011U);
}
