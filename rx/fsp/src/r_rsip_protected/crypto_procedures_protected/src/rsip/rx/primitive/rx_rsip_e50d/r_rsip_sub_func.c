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

void r_rsip_func_sub001 (uint32_t arg1)
{
    WR1_PROG(REG_1400H, arg1);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub002 (uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4)
{
    WR1_PROG(REG_1014H, arg1);
    WR1_PROG(REG_1018H, arg2);
    WR1_PROG(REG_1020H, arg3);
    WR1_PROG(REG_1004H, arg4);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub003 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, arg1);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, bswap_32big(arg2));
    WR1_PROG(REG_1458H, 0x00000000U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub004 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, arg1);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, bswap_32big(arg2));
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub005 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1020H, arg1);
    WR1_PROG(REG_1004H, arg2);
    WR1_PROG(REG_1000H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub006 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub007 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_1014H, arg1);
    WR1_PROG(REG_1018H, arg2);
    WR1_PROG(REG_101CH, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub008 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1444H, arg1);
    WR1_PROG(REG_1A2CH, arg2);
    WR1_PROG(REG_1A24H, arg3);
    WAIT_STS(REG_1444H, 31, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub009 (uint32_t arg1)
{
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(arg1));
    WR1_PROG(REG_1458H, 0x00000000U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub010 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1444H, arg1);
    WR1_PROG(REG_1608H, arg2);
    WAIT_STS(REG_1444H, 31, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub011 (uint32_t arg1)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub012 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1404H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1600H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub013 (uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6)
{
    WR1_PROG(REG_1014H, arg1);
    WR1_PROG(REG_1018H, arg2);
    WR1_PROG(REG_101CH, arg3);
    WR1_PROG(REG_1020H, arg4);
    WR1_PROG(REG_1004H, arg5);
    WR1_PROG(REG_1408H, 0x00020000U);
    WR1_PROG(REG_1000H, arg6);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub014 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_143CH, arg2);
    WR1_PROG(REG_1458H, 0x00000000U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub016 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1608H, arg1);
    WR1_PROG(REG_1408H, arg2);
    WAIT_STS(REG_1408H, 30, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub017 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, arg2);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub018 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1010H, arg1);
    WR1_PROG(REG_101CH, arg2);
    WR1_PROG(REG_1004H, arg3);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub019 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1444H, arg1);
    WR1_PROG(REG_182CH, arg2);
    WR1_PROG(REG_1824H, arg3);
    WAIT_STS(REG_1444H, 31, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub020 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1444H, arg1);
    WR1_PROG(REG_1824H, arg2);
    WAIT_STS(REG_1444H, 31, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub021 (uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1600H, arg3);
    WR1_PROG(REG_1600H, arg4);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub022 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1600H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub023 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1608H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub024 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1444H, arg1);
    WR1_PROG(REG_1A2CH, arg2);
    WR1_PROG(REG_1A24H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub025 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1444H, arg1);
    WR1_PROG(REG_182CH, arg2);
    WR1_PROG(REG_1824H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub027 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1A2CH, arg1);
    WR1_PROG(REG_1A24H, arg2);
    WR1_PROG(REG_1608H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub028 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1A24H, arg1);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, bswap_32big(arg2));
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub029 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1B00H, arg1);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, arg2);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub030 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1404H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1608H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub031 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1404H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub032 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_2004H, arg1);
    WR1_PROG(REG_1600H, arg2);
    WR1_PROG(REG_1600H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub033 (uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4)
{
    WR1_PROG(REG_1444H, arg1);
    WR1_PROG(REG_2014H, arg2);
    WR1_PROG(REG_1444H, arg3);
    WR1_PROG(REG_2010H, arg4);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub034 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, arg1);
    WR1_PROG(REG_1600H, arg2);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub035 (uint32_t arg1)
{
    WR1_PROG(REG_1408H, 0x00020000U);
    WR1_PROG(REG_1000H, arg1);
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_143CH, 0x00000d00U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub037 (uint32_t arg1, uint32_t arg2)
{
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, bswap_32big(arg1));
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, bswap_32big(arg2));
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub038 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_1014H, arg1);
    WR1_PROG(REG_1018H, arg2);
    WR1_PROG(REG_101CH, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub039 (uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4)
{
    WR1_PROG(REG_1020H, arg1);
    WR1_PROG(REG_1010H, arg2);
    WR1_PROG(REG_1004H, arg3);
    WR1_PROG(REG_1000H, arg4);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub040 (uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5)
{
    WR1_PROG(REG_101CH, arg1);
    WR1_PROG(REG_1020H, arg2);
    WR1_PROG(REG_1010H, arg3);
    WR1_PROG(REG_1004H, arg4);
    WR1_PROG(REG_1000H, arg5);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub041 (uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6)
{
    WR1_PROG(REG_1014H, arg1);
    WR1_PROG(REG_1018H, arg2);
    WR1_PROG(REG_101CH, arg3);
    WR1_PROG(REG_1020H, arg4);
    WR1_PROG(REG_1010H, arg5);
    WR1_PROG(REG_1004H, arg6);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub042 (const uint32_t * InData_IV)
{
    WR1_PROG(REG_1420H, InData_IV[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_IV[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_IV[2]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_IV[3]);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub043 (void)
{
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001600U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub044 (void)
{
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x16280000U);
    WR1_PROG(REG_1608H, 0x800103e0U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub045 (void)
{
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_143CH, 0x00000d00U);
    WR1_PROG(REG_1600H, 0x00000bffU);
}
