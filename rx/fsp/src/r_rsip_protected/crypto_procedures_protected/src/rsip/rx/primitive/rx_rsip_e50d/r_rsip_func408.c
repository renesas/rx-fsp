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

void r_rsip_func408 (void)
{
    r_rsip_func_sub031(0x0000b4a0U, 0x0000000cU, 0x10000000U);

    WR1_PROG(REG_1608H, 0x81910005U);
    r_rsip_func_sub001(0x00c90045U);

    WR1_PROG(REG_1600H, 0x000008a5U);

    WR1_PROG(REG_1404H, 0x10000000U);

    WR1_PROG(REG_1608H, 0x80940005U);
    r_rsip_func_sub001(0x10030009U);
    r_rsip_func_sub001(0x13430109U);

    r_rsip_func_sub001(0x13400039U);
    r_rsip_func_sub001(0x10000009U);
}
