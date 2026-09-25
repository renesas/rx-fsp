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

void r_rsip_func008 (void)
{
    r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
    r_rsip_func_sub005(0x000001b0U, 0x04040002U, 0x00010001U);
    r_rsip_func_sub007(0x00000160U, 0x00000390U, 0x00000070U);
    r_rsip_func_sub005(0x00000200U, 0x04040002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x000001b0U);
    WR1_PROG(REG_101CH, 0x00000070U);
    r_rsip_func_sub005(0x00000110U, 0x04040001U, 0x00010001U);
    r_rsip_func_sub007(0x00000110U, 0x00000890U, 0x00000070U);
    r_rsip_func_sub005(0x00000160U, 0x04040005U, 0x00010001U);
    r_rsip_func_sub007(0x00000160U, 0x000001b0U, 0x00000070U);
    r_rsip_func_sub005(0x00000110U, 0x04040002U, 0x00010001U);
    r_rsip_func_sub007(0x00000110U, 0x000008e0U, 0x00000070U);
    r_rsip_func_sub005(0x00000160U, 0x04040005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000200U);
    WR1_PROG(REG_101CH, 0x00000070U);
    r_rsip_func_sub005(0x00000110U, 0x04040001U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000250U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000160U, 0x00000110U, 0x00000250U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);
}
