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

void r_rsip_p34u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p34u_func100_001[] =
    {
        BSWAP_32BIG_C(0xb8e7b47fU), BSWAP_32BIG_C(0x5c21559eU), BSWAP_32BIG_C(0x79ad47d6U), BSWAP_32BIG_C(0x0bc2830cU),
    };
    r_rsip_func100(Param_p34u_func100_001);

    r_rsip_func_sub019(0x000003c1U, 0x40020020U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[0]);

    static const uint32_t Param_p34u_func100_002[] =
    {
        BSWAP_32BIG_C(0x3760fcabU), BSWAP_32BIG_C(0x3338b286U), BSWAP_32BIG_C(0x9cc3c7f8U), BSWAP_32BIG_C(0x59ddeafdU),
    };
    r_rsip_func100(Param_p34u_func100_002);

    r_rsip_func_sub025(0x00020061U, 0x40028020U, 0x07008d06U);
    WR1_PROG(REG_1408H, 0x000c1000U);

    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func215();

    r_rsip_func_sub019(0x000000a1U, 0x00028000U, 0x08008004U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    static const uint32_t Param_p34u_func101_001[] =
    {
        BSWAP_32BIG_C(0xf0af4a7aU), BSWAP_32BIG_C(0x22a01240U), BSWAP_32BIG_C(0xa88fd042U), BSWAP_32BIG_C(0xd098e264U),
    };
    r_rsip_func101(Param_p34u_func101_001);
}
