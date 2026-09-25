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

rsip_ret_t r_rsip_p20 (uint32_t OutData_Text[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00200002U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00000020U);

    static const uint32_t Param_p20_func101_001[] =
    {
        BSWAP_32BIG_C(0x1ca87279U), BSWAP_32BIG_C(0xafa7754eU), BSWAP_32BIG_C(0xb92a3499U), BSWAP_32BIG_C(0x5aeadcd1U),
    };
    r_rsip_func101(Param_p20_func101_001);
    r_rsip_func103();
    static const uint32_t Param_p20_func100_001[] =
    {
        BSWAP_32BIG_C(0xcea51b31U), BSWAP_32BIG_C(0xefa8ac7fU), BSWAP_32BIG_C(0xab0a43bdU), BSWAP_32BIG_C(0xbb9c763eU),
    };
    r_rsip_func100(Param_p20_func100_001);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[0]);

    static const uint32_t Param_p20_func102_001[] =
    {
        BSWAP_32BIG_C(0xabacb35cU), BSWAP_32BIG_C(0x144ab073U), BSWAP_32BIG_C(0x329832faU), BSWAP_32BIG_C(0xb4faed45U),
    };
    r_rsip_func102(Param_p20_func102_001);

    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
