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

rsip_ret_t r_rsip_p15 (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00150001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00001501U);

    static const uint32_t Param_p15_func101_001[] =
    {
        BSWAP_32BIG_C(0xa6e189acU), BSWAP_32BIG_C(0xf437cd57U), BSWAP_32BIG_C(0x6d640395U), BSWAP_32BIG_C(0x5301ef79U),
    };
    r_rsip_func101(Param_p15_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00000015U);

    static const uint32_t Param_p15_func101_002[] =
    {
        BSWAP_32BIG_C(0x9e6646e5U), BSWAP_32BIG_C(0xec690119U), BSWAP_32BIG_C(0x1e927de1U), BSWAP_32BIG_C(0x6fd7602dU),
    };
    r_rsip_func101(Param_p15_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub009(0x00000015U);

    static const uint32_t Param_p15_func101_003[] =
    {
        BSWAP_32BIG_C(0xbb818d7fU), BSWAP_32BIG_C(0x72e98d60U), BSWAP_32BIG_C(0xf76dde59U), BSWAP_32BIG_C(0x1bd0ebfeU),
    };
    r_rsip_func101(Param_p15_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p15_func100_001[] =
    {
        BSWAP_32BIG_C(0xd8a1de98U), BSWAP_32BIG_C(0xe99d785cU), BSWAP_32BIG_C(0x2b085be4U), BSWAP_32BIG_C(0x93ca58c7U),
    };
    r_rsip_func100(Param_p15_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00001502U);

    static const uint32_t Param_p15_func101_004[] =
    {
        BSWAP_32BIG_C(0x5889d84bU), BSWAP_32BIG_C(0x250ea333U), BSWAP_32BIG_C(0x0038f649U), BSWAP_32BIG_C(0xb61d99a5U),
    };
    r_rsip_func101(Param_p15_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub009(0x00001503U);

    static const uint32_t Param_p15_func101_005[] =
    {
        BSWAP_32BIG_C(0x95c58133U), BSWAP_32BIG_C(0x2f1396b9U), BSWAP_32BIG_C(0x8324e4cfU), BSWAP_32BIG_C(0x34b3c7c3U),
    };
    r_rsip_func101(Param_p15_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p15_func100_002[] =
    {
        BSWAP_32BIG_C(0xa4b8ccb7U), BSWAP_32BIG_C(0xab427aeeU), BSWAP_32BIG_C(0x2c4566cdU), BSWAP_32BIG_C(0xa3dc5679U),
    };
    r_rsip_func100(Param_p15_func100_002);
    r_rsip_func_sub027(0x40000100U, 0xe7009d47U, 0x81060000U);
    r_rsip_func_sub001(0x00890019U);
    r_rsip_func_sub001(0x00800009U);

    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000002U));

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    static const uint32_t Param_p15_func102_001[] =
    {
        BSWAP_32BIG_C(0x3194e619U), BSWAP_32BIG_C(0xeff82e50U), BSWAP_32BIG_C(0xea3d17fdU), BSWAP_32BIG_C(0x0a55be30U),
    };
    r_rsip_func102(Param_p15_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
