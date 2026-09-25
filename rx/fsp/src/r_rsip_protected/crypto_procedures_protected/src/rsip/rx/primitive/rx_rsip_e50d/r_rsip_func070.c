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

void r_rsip_func070 (const uint32_t ARG1[])
{
    r_rsip_func_sub021(0x30003340U, 0x00050020U, 0x0000b7c0U, 0x0131ec45U);
    r_rsip_func_sub021(0x00030040U, 0x0000b7c0U, 0x014bb610U, 0x00070040U);
    r_rsip_func_sub021(0x30003380U, 0x00070020U, 0x0000b7c0U, 0x01542614U);
    r_rsip_func_sub021(0x00030040U, 0x0000b7c0U, 0x01ba24feU, 0x00050040U);
    r_rsip_func_sub021(0x0000b7c0U, 0x01bb59d6U, 0x00000080U, 0x00000080U);

    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0e0704c4U);
    WR1_PROG(REG_1608H, 0x810103c0U);
    r_rsip_func_sub001(0x00890005U);
    WAIT_STS(REG_1A28H, 6, 0);
    WR1_PROG(REG_143CH, 0x00000900U);

    WR1_PROG(REG_1404H, 0x10500000U);
    r_rsip_func_sub008(0x00002fc2U, 0x00000b00U, 0xf7049d07U);
    WR4_ADDR(REG_1420H, &ARG1[20]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[24]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x13700000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[28]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[32]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x18700000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[36]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[40]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x18c00000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[44]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[48]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x10a00000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[52]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[56]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x18200000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[60]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[64]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[68]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);
}
