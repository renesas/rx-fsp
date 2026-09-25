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

void r_rsip_p89u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1444H, 0x000003c2U);
    static const uint32_t Param_p89u_func100_001[] =
    {
        BSWAP_32BIG_C(0xe958f241U), BSWAP_32BIG_C(0x705616fbU), BSWAP_32BIG_C(0xb4e04e98U), BSWAP_32BIG_C(0x21e985b0U),
    };
    r_rsip_func100(Param_p89u_func100_001);

    WR1_PROG(REG_182CH, 0x40000010U);
    WR1_PROG(REG_1608H, 0x00000008U);
    WR1_PROG(REG_1444H, 0x00020061U);
    WR1_PROG(REG_1824H, 0x00008006U);
    WR1_PROG(REG_1408H, 0x000c1000U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 4]);

    r_rsip_func214();

    static const uint32_t Param_p89u_func101_001[] =
    {
        BSWAP_32BIG_C(0x880d2c44U), BSWAP_32BIG_C(0x337daedaU), BSWAP_32BIG_C(0x6d6244d1U), BSWAP_32BIG_C(0xe9c1189fU),
    };
    r_rsip_func101(Param_p89u_func101_001);
}
