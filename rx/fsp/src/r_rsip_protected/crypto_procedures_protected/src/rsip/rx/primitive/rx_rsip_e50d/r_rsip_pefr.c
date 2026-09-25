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

rsip_ret_t r_rsip_pefr (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ef0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3000a800U, 0x00000003U, 0x00010020U, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1600H, 0x00000080U);

    static const uint32_t Param_pefr_func100_001[] =
    {
        BSWAP_32BIG_C(0xa7047c26U), BSWAP_32BIG_C(0xf7a5077bU), BSWAP_32BIG_C(0xa3ce282bU), BSWAP_32BIG_C(0xdd119db0U),
    };
    r_rsip_func100(Param_pefr_func100_001);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2004H, 0x00001050U);

        static const uint32_t Param_pefr_func101_001[] =
        {
            BSWAP_32BIG_C(0x4109a89eU), BSWAP_32BIG_C(0x8415ca1dU), BSWAP_32BIG_C(0x85963c47U), BSWAP_32BIG_C(
                0x481dea18U),
        };
        r_rsip_func101(Param_pefr_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x000010a0U);

        static const uint32_t Param_pefr_func101_002[] =
        {
            BSWAP_32BIG_C(0x83cc36afU), BSWAP_32BIG_C(0xaba7abf1U), BSWAP_32BIG_C(0xbc973157U), BSWAP_32BIG_C(
                0xa7420a8bU),
        };
        r_rsip_func101(Param_pefr_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x000010b0U);

        static const uint32_t Param_pefr_func101_003[] =
        {
            BSWAP_32BIG_C(0xe33eacd7U), BSWAP_32BIG_C(0x1b898bbeU), BSWAP_32BIG_C(0x6f4fdd0dU), BSWAP_32BIG_C(
                0xe1cbed10U),
        };
        r_rsip_func101(Param_pefr_func101_003);
    }

    r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003c01U);

    r_rsip_func_sub033(0x00000040U, InData_State[18], 0x00000040U, InData_State[19]);

    for (iLoop = 0U; iLoop < 18U; iLoop++)
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2028H, InData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_pefr_func101_004[] =
    {
        BSWAP_32BIG_C(0xa3708302U), BSWAP_32BIG_C(0xfd237224U), BSWAP_32BIG_C(0xf78676d6U), BSWAP_32BIG_C(0x85ae2c7bU),
    };
    r_rsip_func101(Param_pefr_func101_004);

    return RSIP_RET_PASS;
}
