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

void r_rsip_p85t (void)
{
    WR1_PROG(REG_1824H, 0x08000045U);
    WR1_PROG(REG_1608H, 0x81040080U);
    r_rsip_func_sub001(0x00490011U);

    r_rsip_func_sub019(0x000000a1U, 0x40000030U, 0x07008c04U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
}
