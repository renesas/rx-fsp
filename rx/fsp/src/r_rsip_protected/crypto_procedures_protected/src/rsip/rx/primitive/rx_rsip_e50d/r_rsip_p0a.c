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

rsip_ret_t r_rsip_p0a (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000a0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00000a01U);

    static const uint32_t Param_p0a_func101_001[] =
    {
        BSWAP_32BIG_C(0x56a6b931U), BSWAP_32BIG_C(0x17457d56U), BSWAP_32BIG_C(0xef013d0cU), BSWAP_32BIG_C(0xd51fdafdU),
    };
    r_rsip_func101(Param_p0a_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000000aU);

    static const uint32_t Param_p0a_func101_002[] =
    {
        BSWAP_32BIG_C(0x8a41205cU), BSWAP_32BIG_C(0x06a321b9U), BSWAP_32BIG_C(0x6605aae8U), BSWAP_32BIG_C(0xf076d52eU),
    };
    r_rsip_func101(Param_p0a_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000001aU);

    r_rsip_func_sub009(0x0000000aU);

    static const uint32_t Param_p0a_func101_003[] =
    {
        BSWAP_32BIG_C(0x4288fc65U), BSWAP_32BIG_C(0xf8de43b3U), BSWAP_32BIG_C(0x40b7835fU), BSWAP_32BIG_C(0x1f7d6e2eU),
    };
    r_rsip_func101(Param_p0a_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p0a_func100_001[] =
    {
        BSWAP_32BIG_C(0xa4df87dcU), BSWAP_32BIG_C(0xac446c73U), BSWAP_32BIG_C(0xfd8bbb5aU), BSWAP_32BIG_C(0x8e61d550U),
    };
    r_rsip_func100(Param_p0a_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00000a02U);

    static const uint32_t Param_p0a_func101_004[] =
    {
        BSWAP_32BIG_C(0x4816cf15U), BSWAP_32BIG_C(0x8aa3edd7U), BSWAP_32BIG_C(0x58226666U), BSWAP_32BIG_C(0xd41b19b6U),
    };
    r_rsip_func101(Param_p0a_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub009(0x00000a03U);

    static const uint32_t Param_p0a_func101_005[] =
    {
        BSWAP_32BIG_C(0x581bf94eU), BSWAP_32BIG_C(0x42a6501cU), BSWAP_32BIG_C(0x6046f0f5U), BSWAP_32BIG_C(0x5a5d528aU),
    };
    r_rsip_func101(Param_p0a_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p0a_func100_002[] =
    {
        BSWAP_32BIG_C(0xeff4fb6cU), BSWAP_32BIG_C(0x178841d8U), BSWAP_32BIG_C(0xda1dab79U), BSWAP_32BIG_C(0x429aea58U),
    };
    r_rsip_func100(Param_p0a_func100_002);
    r_rsip_func_sub027(0x40000100U, 0xe7009d47U, 0x81070000U);
    r_rsip_func_sub001(0x0089001dU);
    r_rsip_func_sub001(0x00800005U);

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

    static const uint32_t Param_p0a_func102_001[] =
    {
        BSWAP_32BIG_C(0x7f88ff05U), BSWAP_32BIG_C(0xdad52ec8U), BSWAP_32BIG_C(0x9b57f49eU), BSWAP_32BIG_C(0xc7eb0699U),
    };
    r_rsip_func102(Param_p0a_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
