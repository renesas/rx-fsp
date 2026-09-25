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

void r_rsip_p96u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p96u_func100_001[] =
    {
        BSWAP_32BIG_C(0x39378f2aU), BSWAP_32BIG_C(0xcb8cc19bU), BSWAP_32BIG_C(0x44114973U), BSWAP_32BIG_C(0xfa68f340U),
    };
    r_rsip_func100(Param_p96u_func100_001);

    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    static const uint32_t Param_p96u_func101_001[] =
    {
        BSWAP_32BIG_C(0xecca7506U), BSWAP_32BIG_C(0xb25523d0U), BSWAP_32BIG_C(0xf3517f51U), BSWAP_32BIG_C(0xf59c7714U),
    };
    r_rsip_func101(Param_p96u_func101_001);
}
