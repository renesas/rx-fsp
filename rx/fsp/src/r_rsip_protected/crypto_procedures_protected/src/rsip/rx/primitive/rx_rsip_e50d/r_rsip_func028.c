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

void r_rsip_func028 (const uint32_t ARG1[])
{
    r_rsip_func_sub021(0x38000f5aU, 0x00030020U, 0x0000b7c0U, 0x01166403U);
    r_rsip_func_sub021(0x00000060U, 0x0000b7c0U, 0x013659ffU, 0x00000080U);

    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0e0704c4U);
    WR1_PROG(REG_1608H, 0x810103c0U);
    r_rsip_func_sub001(0x00890005U);
    WAIT_STS(REG_1A28H, 6, 0);
    WR1_PROG(REG_143CH, 0x00000900U);

    WR1_PROG(REG_1404H, 0x11b00000U);
    r_rsip_func_sub008(0x000017c2U, 0x00000500U, 0xf7049d07U);
    WR4_ADDR(REG_1420H, &ARG1[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[4]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[8]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1404H, 0x11e80000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[12]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[16]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[20]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[24]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);
}
