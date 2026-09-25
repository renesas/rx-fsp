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

void r_rsip_p98u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p98u_func100_001[] =
    {
        BSWAP_32BIG_C(0x309b07a3U), BSWAP_32BIG_C(0xd64eb19dU), BSWAP_32BIG_C(0xf90baf01U), BSWAP_32BIG_C(0x593a44b6U),
    };
    r_rsip_func100(Param_p98u_func100_001);
    WR1_PROG(REG_1444H, 0x00020061U);

    WR1_PROG(REG_1824H, 0xf7000d06U);
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
    RD4_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 4]);

    r_rsip_func215();

    static const uint32_t Param_p98u_func101_001[] =
    {
        BSWAP_32BIG_C(0x7abeecdcU), BSWAP_32BIG_C(0xec64d4b5U), BSWAP_32BIG_C(0xf80e8da4U), BSWAP_32BIG_C(0xcf875ba8U),
    };
    r_rsip_func101(Param_p98u_func101_001);
}
