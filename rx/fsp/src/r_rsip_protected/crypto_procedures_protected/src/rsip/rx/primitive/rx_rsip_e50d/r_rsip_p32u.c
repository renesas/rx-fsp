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

void r_rsip_p32u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p32u_func100_001[] =
    {
        BSWAP_32BIG_C(0xa3c9ad24U), BSWAP_32BIG_C(0x2c1416c8U), BSWAP_32BIG_C(0x4fccf0b4U), BSWAP_32BIG_C(0x7cc1fffeU),
    };
    r_rsip_func100(Param_p32u_func100_001);

    r_rsip_func_sub025(0x00020061U, 0x00018020U, 0x07008d06U);
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
    RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);

    r_rsip_func215();

    static const uint32_t Param_p32u_func101_001[] =
    {
        BSWAP_32BIG_C(0x9f39ee96U), BSWAP_32BIG_C(0x627a918bU), BSWAP_32BIG_C(0xc914e92eU), BSWAP_32BIG_C(0x8be4140dU),
    };
    r_rsip_func101(Param_p32u_func101_001);
}
