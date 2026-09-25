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

void r_rsip_func030 (void)
{
    r_rsip_func_sub021(0x38008800U, 0x00000000U, 0x1000b4a0U, 0x00000002U);
    r_rsip_func_sub021(0x1000b4c0U, 0x00000005U, 0x1000b4e0U, 0x00000009U);

    r_rsip_func_sub021(0x38008800U, 0x00000001U, 0x1000b4a0U, 0x00000003U);
    r_rsip_func_sub021(0x1000b4c0U, 0x00000006U, 0x1000b4e0U, 0x0000000dU);

    r_rsip_func_sub021(0x38008800U, 0x00000002U, 0x1000b4a0U, 0x00000004U);
    r_rsip_func_sub021(0x1000b4c0U, 0x00000007U, 0x1000b4e0U, 0x0000000dU);
}
