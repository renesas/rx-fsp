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

void r_rsip_func081 (void)
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub021(0x00000821U, 0x0000b4e0U, 0x00000012U, 0x0000b7a0U);
    WR1_PROG(REG_1600H, 0x00000004U);

    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1444H, 0x00000fa7U);
    WR1_PROG(REG_1608H, 0x8090001fU);
    r_rsip_func_sub037(0x0000000aU, 0x0000000cU);
    r_rsip_func_sub037(0x0000000eU, 0x00000010U);
    r_rsip_func_sub037(0x00000012U, 0x00000014U);
    r_rsip_func_sub037(0x00000016U, 0x00000018U);
    r_rsip_func_sub037(0x0000001cU, 0x0000001eU);
    r_rsip_func_sub037(0x00000020U, 0x00000022U);
    r_rsip_func_sub037(0x00000024U, 0x00000026U);
    r_rsip_func_sub037(0x00000031U, 0x000000feU);
    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub021(0x00003bdfU, 0x3800089eU, 0x10003427U, 0x000027fdU);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
}
