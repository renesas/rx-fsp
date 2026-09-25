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

void r_rsip_func420 (void)
{
    r_rsip_func_sub021(0x000037c0U, 0x00076bdeU, 0x00026fdeU, 0x00000bffU);

    r_rsip_func_sub021(0x38008c00U, 0x0000007fU, 0x00020020U, 0x3420a800U);
    r_rsip_func_sub021(0x00000080U, 0x1000d3e0U, 0x2000abc0U, 0x00000004U);
    r_rsip_func_sub006(0x00000080U, 0x38000fffU, 0x00A60000U);
}
