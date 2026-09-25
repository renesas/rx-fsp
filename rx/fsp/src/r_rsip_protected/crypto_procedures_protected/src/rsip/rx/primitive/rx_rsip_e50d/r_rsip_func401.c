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

void r_rsip_func401 (const uint32_t ARG1[])
{
    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    r_rsip_func_sub028(0x0e0704c4U, 0x6212e267U);

    r_rsip_func_sub008(0x00000fc2U, 0x00000300U, 0xf7049d07U);
    WR4_ADDR(REG_1420H, &ARG1[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[4]);
    WR1_PROG(REG_1404H, 0x14600000U);
    r_rsip_func_sub001(0x00c20021U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[8]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[12]);
    WR1_PROG(REG_1404H, 0x14b00000U);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[16]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);
}
