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

void r_rsip_func405 (void)
{
    r_rsip_func_sub021(0x000037e8U, 0x00056bffU, 0x00026fffU, 0x0000381fU);

    r_rsip_func_sub021(0x000037e8U, 0x000037c1U, 0x00000fe1U, 0x00002bdfU);
    r_rsip_func_sub022(0x0000441eU, 0x00007400U, 0x00000c13U);
}
