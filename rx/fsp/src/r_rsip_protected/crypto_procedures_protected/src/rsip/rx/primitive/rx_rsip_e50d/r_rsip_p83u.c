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

void r_rsip_p83u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p83u_func100_001[] =
    {
        BSWAP_32BIG_C(0xbb10f51bU), BSWAP_32BIG_C(0x2d0df856U), BSWAP_32BIG_C(0x4f6a381aU), BSWAP_32BIG_C(0x39e15590U),
    };
    r_rsip_func100(Param_p83u_func100_001);
    r_rsip_func_sub019(0x000003c1U, 0x40020030U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[0]);

    static const uint32_t Param_p83u_func100_002[] =
    {
        BSWAP_32BIG_C(0x2c90c57cU), BSWAP_32BIG_C(0x3c33c616U), BSWAP_32BIG_C(0xe6911a9dU), BSWAP_32BIG_C(0x6fa094cfU),
    };
    r_rsip_func100(Param_p83u_func100_002);

    r_rsip_func_sub025(0x00020061U, 0x40028030U, 0x07008d06U);
    WR1_PROG(REG_1408H, 0x000c1000U);

    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func202();

    r_rsip_func_sub019(0x000000a1U, 0x00028000U, 0x08008004U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    static const uint32_t Param_p83u_func101_001[] =
    {
        BSWAP_32BIG_C(0x3d3beb69U), BSWAP_32BIG_C(0x1df9e5d4U), BSWAP_32BIG_C(0xbbb50e1cU), BSWAP_32BIG_C(0x604ee12bU),
    };
    r_rsip_func101(Param_p83u_func101_001);
}
