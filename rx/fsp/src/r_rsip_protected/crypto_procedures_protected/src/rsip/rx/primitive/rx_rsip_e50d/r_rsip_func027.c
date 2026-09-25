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

void r_rsip_func027 (const uint32_t ARG1[])
{
    r_rsip_func_sub021(0x38000f5aU, 0x00030020U, 0x0000b7c0U, 0x01305c44U);
    r_rsip_func_sub021(0x00000060U, 0x0000b7c0U, 0x0142859dU, 0x00000080U);

    r_rsip_func_sub028(0x4a070044U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0e0704c4U);
    WR1_PROG(REG_1608H, 0x810103c0U);
    r_rsip_func_sub001(0x00890005U);
    WAIT_STS(REG_1A28H, 6, 0);
    WR1_PROG(REG_143CH, 0x00000900U);

    WR1_PROG(REG_1404H, 0x10400000U);
    r_rsip_func_sub008(0x000047c2U, 0x00001100U, 0xf7049d07U);
    WR4_ADDR(REG_1420H, &ARG1[28]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[32]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[36]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1404H, 0x13600000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[40]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[44]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[48]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1404H, 0x18600000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[52]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[56]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[60]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1404H, 0x18b00000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[64]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[68]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[72]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1404H, 0x10900000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[76]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[80]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[84]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1404H, 0x18100000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[88]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[92]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[96]);
    r_rsip_func_sub001(0x00c20031U);

    WR1_PROG(REG_1A24H, 0x07040d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[100]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);
}
