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

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p89f (void)
{
    static const uint32_t Param_p89f_func102_001[] =
    {
        BSWAP_32BIG_C(0x2205b0e9U), BSWAP_32BIG_C(0x7030122fU), BSWAP_32BIG_C(0xfb47cb16U), BSWAP_32BIG_C(0xce844ebbU),
    };
    r_rsip_func102(Param_p89f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
