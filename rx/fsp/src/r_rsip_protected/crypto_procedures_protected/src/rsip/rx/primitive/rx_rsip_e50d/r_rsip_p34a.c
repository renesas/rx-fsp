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

void r_rsip_p34a (const uint32_t InData_DataA[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub025(0x00020061U, 0x00018000U, 0x0a008006U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_DataA[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func216();

    static const uint32_t Param_p34a_func101_001[] =
    {
        BSWAP_32BIG_C(0xe98dd09aU), BSWAP_32BIG_C(0x41b8b4efU), BSWAP_32BIG_C(0x765a911eU), BSWAP_32BIG_C(0x40d8b885U),
    };
    r_rsip_func101(Param_p34a_func101_001);
}
