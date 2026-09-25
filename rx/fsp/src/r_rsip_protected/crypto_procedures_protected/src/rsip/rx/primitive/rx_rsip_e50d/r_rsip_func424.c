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

void r_rsip_func424 (void)
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1600H, 0x00000bffU);

    for (iLoop = 0U; iLoop < 4; iLoop++)
    {
        r_rsip_func_sub021(0x00003840U, 0x00003861U, 0x38000843U, 0x2000b7e0U);
        r_rsip_func_sub021(0xb2d02d18U, 0x0000a400U, 0x00000004U, 0x0000a420U);
        WR1_PROG(REG_1600H, 0x00000004U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
}
