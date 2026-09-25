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

rsip_ret_t r_rsip_p21 (const uint32_t InData_HV[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Text[],
                       uint32_t       OutData_DataT[],
                       uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00210001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub019(0x000003c1U, 0x00070000U, 0x08008005U);
    WR4_ADDR(REG_1420H, &InData_HV[0]);

    r_rsip_func_sub020(0x000003c1U, 0x08000025U);
    WR4_ADDR(REG_1420H, &InData_IV[0]);

    r_rsip_func_sub025(0x00020061U, 0x00018000U, 0x0a058006U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func216();

    static const uint32_t Param_p21_func100_001[] =
    {
        BSWAP_32BIG_C(0xd8c5fad3U), BSWAP_32BIG_C(0x8f89ba3dU), BSWAP_32BIG_C(0x4312840dU), BSWAP_32BIG_C(0x8e88c6d8U),
    };
    r_rsip_func100(Param_p21_func100_001);
    r_rsip_func_sub019(0x000000a1U, 0x00400000U, 0x0c008104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_DataT[0]);

    static const uint32_t Param_p21_func102_001[] =
    {
        BSWAP_32BIG_C(0x86fa54e5U), BSWAP_32BIG_C(0x0836fcdcU), BSWAP_32BIG_C(0x6fbcfa74U), BSWAP_32BIG_C(0x942f2a93U),
    };
    r_rsip_func102(Param_p21_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
