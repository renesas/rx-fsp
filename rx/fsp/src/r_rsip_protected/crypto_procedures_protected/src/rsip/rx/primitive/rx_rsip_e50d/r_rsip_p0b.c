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

rsip_ret_t r_rsip_p0b (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000b0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00000b01U);

    static const uint32_t Param_p0b_func101_001[] =
    {
        BSWAP_32BIG_C(0xf656ed3bU), BSWAP_32BIG_C(0x7a3af40bU), BSWAP_32BIG_C(0xe845e143U), BSWAP_32BIG_C(0xed589ea5U),
    };
    r_rsip_func101(Param_p0b_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000000bU);

    static const uint32_t Param_p0b_func101_002[] =
    {
        BSWAP_32BIG_C(0xe081714cU), BSWAP_32BIG_C(0x5d8b01f3U), BSWAP_32BIG_C(0xb60ff143U), BSWAP_32BIG_C(0xc2a7d218U),
    };
    r_rsip_func101(Param_p0b_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000001bU);

    r_rsip_func_sub009(0x0000000bU);

    static const uint32_t Param_p0b_func101_003[] =
    {
        BSWAP_32BIG_C(0x3479c998U), BSWAP_32BIG_C(0xfb4dbd18U), BSWAP_32BIG_C(0xf770f363U), BSWAP_32BIG_C(0xf8d3560cU),
    };
    r_rsip_func101(Param_p0b_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p0b_func100_001[] =
    {
        BSWAP_32BIG_C(0x81c49553U), BSWAP_32BIG_C(0x686c1ae0U), BSWAP_32BIG_C(0x6d1973a0U), BSWAP_32BIG_C(0xea19b93cU),
    };
    r_rsip_func100(Param_p0b_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00000b02U);

    static const uint32_t Param_p0b_func101_004[] =
    {
        BSWAP_32BIG_C(0x79e7c35aU), BSWAP_32BIG_C(0xafc6d9f4U), BSWAP_32BIG_C(0x532928f6U), BSWAP_32BIG_C(0x0ad77318U),
    };
    r_rsip_func101(Param_p0b_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub009(0x00000b03U);

    static const uint32_t Param_p0b_func101_005[] =
    {
        BSWAP_32BIG_C(0xf0a2d7e7U), BSWAP_32BIG_C(0xd13a486bU), BSWAP_32BIG_C(0x7744110cU), BSWAP_32BIG_C(0x19964657U),
    };
    r_rsip_func101(Param_p0b_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);
    static const uint32_t Param_p0b_func100_002[] =
    {
        BSWAP_32BIG_C(0xf6eda73fU), BSWAP_32BIG_C(0x109b2d8aU), BSWAP_32BIG_C(0x7beec34cU), BSWAP_32BIG_C(0xced82daeU),
    };
    r_rsip_func100(Param_p0b_func100_002);

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

    static const uint32_t Param_p0b_func102_001[] =
    {
        BSWAP_32BIG_C(0x64b745d8U), BSWAP_32BIG_C(0xa6063668U), BSWAP_32BIG_C(0x49824062U), BSWAP_32BIG_C(0x5a952daeU),
    };
    r_rsip_func102(Param_p0b_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
