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

void r_rsip_p85u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p85u_func100_001[] =
    {
        BSWAP_32BIG_C(0x1817b8b2U), BSWAP_32BIG_C(0x32a46f7aU), BSWAP_32BIG_C(0x8b7ebfc2U), BSWAP_32BIG_C(0xc9a9d471U),
    };
    r_rsip_func100(Param_p85u_func100_001);

    r_rsip_func_sub025(0x00020061U, 0x40018030U, 0x07008d06U);
    WR1_PROG(REG_1408H, 0x000c1000U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    for (iLoop = 4U; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);

    r_rsip_func202();

    static const uint32_t Param_p85u_func101_001[] =
    {
        BSWAP_32BIG_C(0x2b675d4eU), BSWAP_32BIG_C(0x4e46a428U), BSWAP_32BIG_C(0x2815be81U), BSWAP_32BIG_C(0x04528d2fU),
    };
    r_rsip_func101(Param_p85u_func101_001);
}
