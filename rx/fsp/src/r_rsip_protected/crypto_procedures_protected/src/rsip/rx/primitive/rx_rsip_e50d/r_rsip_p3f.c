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

rsip_ret_t r_rsip_p3f (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003f0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00003f01U);

    static const uint32_t Param_p3f_func101_001[] =
    {
        BSWAP_32BIG_C(0x17f71a3aU), BSWAP_32BIG_C(0xc4991824U), BSWAP_32BIG_C(0x09b25d15U), BSWAP_32BIG_C(0x9b6c226dU),
    };
    r_rsip_func101(Param_p3f_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000003fU);

    static const uint32_t Param_p3f_func101_002[] =
    {
        BSWAP_32BIG_C(0x3698c218U), BSWAP_32BIG_C(0x8f8a074eU), BSWAP_32BIG_C(0xc12101a0U), BSWAP_32BIG_C(0xa141efe9U),
    };
    r_rsip_func101(Param_p3f_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000002bU);

    r_rsip_func_sub009(0x0000003fU);

    static const uint32_t Param_p3f_func101_003[] =
    {
        BSWAP_32BIG_C(0xcd803e95U), BSWAP_32BIG_C(0x394d94d6U), BSWAP_32BIG_C(0xfd5424fcU), BSWAP_32BIG_C(0x0f9b7a8dU),
    };
    r_rsip_func101(Param_p3f_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3f_func100_001[] =
    {
        BSWAP_32BIG_C(0xc32192afU), BSWAP_32BIG_C(0x8f5b05bcU), BSWAP_32BIG_C(0x2a1e3bc9U), BSWAP_32BIG_C(0x90663c1cU),
    };
    r_rsip_func100(Param_p3f_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00003f02U);

    static const uint32_t Param_p3f_func101_004[] =
    {
        BSWAP_32BIG_C(0x1686732bU), BSWAP_32BIG_C(0x7a027c3dU), BSWAP_32BIG_C(0xd6960124U), BSWAP_32BIG_C(0x86fb46f8U),
    };
    r_rsip_func101(Param_p3f_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003f03U);

    static const uint32_t Param_p3f_func101_005[] =
    {
        BSWAP_32BIG_C(0x36c5cb51U), BSWAP_32BIG_C(0x820d5147U), BSWAP_32BIG_C(0xd21221b1U), BSWAP_32BIG_C(0xa0e109c5U),
    };
    r_rsip_func101(Param_p3f_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003f04U);

    static const uint32_t Param_p3f_func101_006[] =
    {
        BSWAP_32BIG_C(0xeac581ccU), BSWAP_32BIG_C(0x6758f9faU), BSWAP_32BIG_C(0x5f047dc8U), BSWAP_32BIG_C(0xa639a2c3U),
    };
    r_rsip_func101(Param_p3f_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003f05U);

    static const uint32_t Param_p3f_func101_007[] =
    {
        BSWAP_32BIG_C(0x650cfffdU), BSWAP_32BIG_C(0xedd1195aU), BSWAP_32BIG_C(0x1d3138a3U), BSWAP_32BIG_C(0x17ade922U),
    };
    r_rsip_func101(Param_p3f_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040180U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3f_func100_002[] =
    {
        BSWAP_32BIG_C(0xa41768f7U), BSWAP_32BIG_C(0xd208fd3dU), BSWAP_32BIG_C(0x06b0d14bU), BSWAP_32BIG_C(0xf5add755U),
    };
    r_rsip_func100(Param_p3f_func100_002);

    r_rsip_func_sub027(0x40000300U, 0xe7009d47U, 0x81100000U);
    r_rsip_func_sub001(0x00890031U);

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_p3f_func100_003[] =
    {
        BSWAP_32BIG_C(0xa2b92cf9U), BSWAP_32BIG_C(0x0f03da74U), BSWAP_32BIG_C(0x4d25ee9eU), BSWAP_32BIG_C(0x3533c9afU),
    };
    r_rsip_func100(Param_p3f_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000004U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

    static const uint32_t Param_p3f_func102_001[] =
    {
        BSWAP_32BIG_C(0x7d18e184U), BSWAP_32BIG_C(0xfab7e852U), BSWAP_32BIG_C(0x30802162U), BSWAP_32BIG_C(0x4fe387c5U),
    };
    r_rsip_func102(Param_p3f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
