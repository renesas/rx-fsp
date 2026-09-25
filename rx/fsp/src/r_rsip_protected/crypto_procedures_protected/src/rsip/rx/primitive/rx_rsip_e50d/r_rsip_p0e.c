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

rsip_ret_t r_rsip_p0e (void)
{
    if (RD1_MASK(REG_149CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000e0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    static const uint32_t Param_p0e_func100_001[] =
    {
        BSWAP_32BIG_C(0x310bcbf5U), BSWAP_32BIG_C(0xf604abf2U), BSWAP_32BIG_C(0x54d57dc8U), BSWAP_32BIG_C(0x1fe0b29fU),
    };
    r_rsip_func100(Param_p0e_func100_001);
    WR1_PROG(REG_1438H, 0x400000c0U);

    r_rsip_func_sub023(0x0000b7e0U, 0x000000a8U, 0x8181001fU);
    r_rsip_func_sub001(0x02090005U);

    WR1_PROG(REG_1B08H, 0x00000202U);

    static const uint32_t Param_p0e_func102_001[] =
    {
        BSWAP_32BIG_C(0x0aa97e63U), BSWAP_32BIG_C(0xb21db536U), BSWAP_32BIG_C(0xa6b064c3U), BSWAP_32BIG_C(0x9bce3120U),
    };
    r_rsip_func102(Param_p0e_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
