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

rsip_ret_t r_rsip_p08 (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00080001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00000801U);

    static const uint32_t Param_p08_func101_001[] =
    {
        BSWAP_32BIG_C(0x5f68bb63U), BSWAP_32BIG_C(0xa05dad26U), BSWAP_32BIG_C(0xc15b55c6U), BSWAP_32BIG_C(0xefb83af1U),
    };
    r_rsip_func101(Param_p08_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00000008U);

    static const uint32_t Param_p08_func101_002[] =
    {
        BSWAP_32BIG_C(0x9bc775b1U), BSWAP_32BIG_C(0x01d3202bU), BSWAP_32BIG_C(0x719744deU), BSWAP_32BIG_C(0xfd227072U),
    };
    r_rsip_func101(Param_p08_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x00000008U);

    static const uint32_t Param_p08_func101_003[] =
    {
        BSWAP_32BIG_C(0xcfbe12c1U), BSWAP_32BIG_C(0x6d65d77aU), BSWAP_32BIG_C(0xa5275e06U), BSWAP_32BIG_C(0x15648819U),
    };
    r_rsip_func101(Param_p08_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p08_func100_001[] =
    {
        BSWAP_32BIG_C(0xaa78cfcbU), BSWAP_32BIG_C(0xff7705a9U), BSWAP_32BIG_C(0x04b68e8dU), BSWAP_32BIG_C(0x289d6671U),
    };
    r_rsip_func100(Param_p08_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00000802U);

    static const uint32_t Param_p08_func101_004[] =
    {
        BSWAP_32BIG_C(0x321491cdU), BSWAP_32BIG_C(0x8f083a85U), BSWAP_32BIG_C(0x532948e3U), BSWAP_32BIG_C(0x2cd73a83U),
    };
    r_rsip_func101(Param_p08_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub009(0x00000803U);

    static const uint32_t Param_p08_func101_005[] =
    {
        BSWAP_32BIG_C(0x3d56aa5cU), BSWAP_32BIG_C(0x91c92357U), BSWAP_32BIG_C(0xbf26075eU), BSWAP_32BIG_C(0x9a8bb3f4U),
    };
    r_rsip_func101(Param_p08_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);
    static const uint32_t Param_p08_func100_002[] =
    {
        BSWAP_32BIG_C(0x2bd599ecU), BSWAP_32BIG_C(0x651f821cU), BSWAP_32BIG_C(0x2a983a73U), BSWAP_32BIG_C(0x4c918f0fU),
    };
    r_rsip_func100(Param_p08_func100_002);

    r_rsip_func_sub027(0x40000100U, 0xe7009d47U, 0x81080000U);
    r_rsip_func_sub001(0x00890021U);

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

    static const uint32_t Param_p08_func102_001[] =
    {
        BSWAP_32BIG_C(0x9ac1f616U), BSWAP_32BIG_C(0xf4759dadU), BSWAP_32BIG_C(0xd554b872U), BSWAP_32BIG_C(0x48a364d5U),
    };
    r_rsip_func102(Param_p08_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
