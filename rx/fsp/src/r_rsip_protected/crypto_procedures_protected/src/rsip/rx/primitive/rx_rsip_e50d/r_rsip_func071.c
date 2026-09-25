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

void r_rsip_func071 (const uint32_t ARG1[])
{
    r_rsip_func_sub021(0x30003340U, 0x00050020U, 0x0000b7c0U, 0x017d423aU);
    r_rsip_func_sub021(0x00030040U, 0x0000b7c0U, 0x0163c737U, 0x00070040U);
    r_rsip_func_sub021(0x30003380U, 0x00070020U, 0x0000b7c0U, 0x017c67d8U);
    r_rsip_func_sub021(0x00030040U, 0x0000b7c0U, 0x0126ddb5U, 0x00050040U);
    r_rsip_func_sub021(0x0000b7c0U, 0x01bcfa36U, 0x00000080U, 0x00000080U);

    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0e0704c4U);
    WR1_PROG(REG_1608H, 0x810103c0U);
    r_rsip_func_sub001(0x00890005U);
    WAIT_STS(REG_1A28H, 6, 0);
    WR1_PROG(REG_143CH, 0x00000900U);

    r_rsip_func_sub008(0x00000fc2U, 0x00000300U, 0xf7049d07U);
    WR4_ADDR(REG_1420H, &ARG1[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[4]);
    WR1_PROG(REG_1404H, 0x11e00000U);
    r_rsip_func_sub001(0x00c20021U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[8]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[12]);
    WR1_PROG(REG_1404H, 0x12080000U);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[16]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);
}
