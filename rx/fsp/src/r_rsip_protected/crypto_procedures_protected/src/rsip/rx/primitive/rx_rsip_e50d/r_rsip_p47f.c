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

rsip_ret_t r_rsip_p47f (void)
{
    static const uint32_t Param_p47f_func102_001[] =
    {
        BSWAP_32BIG_C(0xad557dd8U), BSWAP_32BIG_C(0xaa5190c5U), BSWAP_32BIG_C(0x161b7986U), BSWAP_32BIG_C(0x72a16cceU),
    };
    r_rsip_func102(Param_p47f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
