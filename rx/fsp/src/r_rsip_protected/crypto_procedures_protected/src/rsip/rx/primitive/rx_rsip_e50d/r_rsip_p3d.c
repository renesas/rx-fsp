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

rsip_ret_t r_rsip_p3d (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003d0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00003d01U);

    static const uint32_t Param_p3d_func101_001[] =
    {
        BSWAP_32BIG_C(0x74fe1e35U), BSWAP_32BIG_C(0x8780f130U), BSWAP_32BIG_C(0x5d4c297eU), BSWAP_32BIG_C(0x68ec7e3fU),
    };
    r_rsip_func101(Param_p3d_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000003dU);

    static const uint32_t Param_p3d_func101_002[] =
    {
        BSWAP_32BIG_C(0xd649fb95U), BSWAP_32BIG_C(0xa943fef2U), BSWAP_32BIG_C(0xa1b3e5d5U), BSWAP_32BIG_C(0x1b0916beU),
    };
    r_rsip_func101(Param_p3d_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000029U);

    r_rsip_func_sub009(0x0000003dU);

    static const uint32_t Param_p3d_func101_003[] =
    {
        BSWAP_32BIG_C(0x2f28bc02U), BSWAP_32BIG_C(0x90fa8629U), BSWAP_32BIG_C(0xef35d103U), BSWAP_32BIG_C(0x54fd8c78U),
    };
    r_rsip_func101(Param_p3d_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3d_func100_001[] =
    {
        BSWAP_32BIG_C(0x9d555ef1U), BSWAP_32BIG_C(0x9acddd2fU), BSWAP_32BIG_C(0x5a2e99ccU), BSWAP_32BIG_C(0x4e9b1586U),
    };
    r_rsip_func100(Param_p3d_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00003d02U);

    static const uint32_t Param_p3d_func101_004[] =
    {
        BSWAP_32BIG_C(0x3c875270U), BSWAP_32BIG_C(0x170753eaU), BSWAP_32BIG_C(0xd202f34eU), BSWAP_32BIG_C(0xd51ff8bdU),
    };
    r_rsip_func101(Param_p3d_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003d03U);

    static const uint32_t Param_p3d_func101_005[] =
    {
        BSWAP_32BIG_C(0x38b6d888U), BSWAP_32BIG_C(0xbe3f936fU), BSWAP_32BIG_C(0xd8ee0765U), BSWAP_32BIG_C(0x3a082c2fU),
    };
    r_rsip_func101(Param_p3d_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003d04U);

    static const uint32_t Param_p3d_func101_006[] =
    {
        BSWAP_32BIG_C(0xd2ad1046U), BSWAP_32BIG_C(0x2fc48d9eU), BSWAP_32BIG_C(0xd61962e9U), BSWAP_32BIG_C(0x2f66bf30U),
    };
    r_rsip_func101(Param_p3d_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003d05U);

    static const uint32_t Param_p3d_func101_007[] =
    {
        BSWAP_32BIG_C(0x8fdd56c7U), BSWAP_32BIG_C(0x568a1ffaU), BSWAP_32BIG_C(0x0cfdedc0U), BSWAP_32BIG_C(0x75d72fb8U),
    };
    r_rsip_func101(Param_p3d_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040180U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3d_func100_002[] =
    {
        BSWAP_32BIG_C(0x4c6b4ba9U), BSWAP_32BIG_C(0xeee2f72fU), BSWAP_32BIG_C(0x5acce515U), BSWAP_32BIG_C(0xd6954673U),
    };
    r_rsip_func100(Param_p3d_func100_002);

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

    static const uint32_t Param_p3d_func100_003[] =
    {
        BSWAP_32BIG_C(0x9270c6feU), BSWAP_32BIG_C(0x167840d5U), BSWAP_32BIG_C(0x6faf0dc3U), BSWAP_32BIG_C(0x83b839a1U),
    };
    r_rsip_func100(Param_p3d_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000004U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

    static const uint32_t Param_p3d_func102_001[] =
    {
        BSWAP_32BIG_C(0x88baac6cU), BSWAP_32BIG_C(0xe56ecdd4U), BSWAP_32BIG_C(0x4c1aefbbU), BSWAP_32BIG_C(0x2d175604U),
    };
    r_rsip_func102(Param_p3d_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
