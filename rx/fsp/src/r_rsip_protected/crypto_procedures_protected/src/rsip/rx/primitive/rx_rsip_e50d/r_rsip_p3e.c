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

rsip_ret_t r_rsip_p3e (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003e0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00003e01U);

    static const uint32_t Param_p3e_func101_001[] =
    {
        BSWAP_32BIG_C(0x32c8947bU), BSWAP_32BIG_C(0x1e69411aU), BSWAP_32BIG_C(0x51747bf8U), BSWAP_32BIG_C(0xd3e8814fU),
    };
    r_rsip_func101(Param_p3e_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000003eU);

    static const uint32_t Param_p3e_func101_002[] =
    {
        BSWAP_32BIG_C(0x59a7276eU), BSWAP_32BIG_C(0x464a49d3U), BSWAP_32BIG_C(0x1c03a3c7U), BSWAP_32BIG_C(0xc227da99U),
    };
    r_rsip_func101(Param_p3e_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000002aU);

    r_rsip_func_sub009(0x0000003eU);

    static const uint32_t Param_p3e_func101_003[] =
    {
        BSWAP_32BIG_C(0x496ff465U), BSWAP_32BIG_C(0xa4db790eU), BSWAP_32BIG_C(0xd2b27180U), BSWAP_32BIG_C(0x08762510U),
    };
    r_rsip_func101(Param_p3e_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3e_func100_001[] =
    {
        BSWAP_32BIG_C(0x12b07a86U), BSWAP_32BIG_C(0x60b93d5dU), BSWAP_32BIG_C(0x774a6b87U), BSWAP_32BIG_C(0x2cb70698U),
    };
    r_rsip_func100(Param_p3e_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00003e02U);

    static const uint32_t Param_p3e_func101_004[] =
    {
        BSWAP_32BIG_C(0x73920c25U), BSWAP_32BIG_C(0xc5767c4aU), BSWAP_32BIG_C(0xcd0c5c74U), BSWAP_32BIG_C(0x31a16e4bU),
    };
    r_rsip_func101(Param_p3e_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003e03U);

    static const uint32_t Param_p3e_func101_005[] =
    {
        BSWAP_32BIG_C(0x22f1e0b3U), BSWAP_32BIG_C(0xd6585746U), BSWAP_32BIG_C(0x712eb8f8U), BSWAP_32BIG_C(0xe99bdc53U),
    };
    r_rsip_func101(Param_p3e_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003e04U);

    static const uint32_t Param_p3e_func101_006[] =
    {
        BSWAP_32BIG_C(0xef8dc900U), BSWAP_32BIG_C(0x75196429U), BSWAP_32BIG_C(0x01957408U), BSWAP_32BIG_C(0xdbd55dacU),
    };
    r_rsip_func101(Param_p3e_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003e05U);

    static const uint32_t Param_p3e_func101_007[] =
    {
        BSWAP_32BIG_C(0x2d2e1925U), BSWAP_32BIG_C(0x3625eda2U), BSWAP_32BIG_C(0xc91a4641U), BSWAP_32BIG_C(0xb46eda22U),
    };
    r_rsip_func101(Param_p3e_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040180U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3e_func100_002[] =
    {
        BSWAP_32BIG_C(0xbea073d8U), BSWAP_32BIG_C(0xbb1e4902U), BSWAP_32BIG_C(0xa69799e3U), BSWAP_32BIG_C(0xca47a039U),
    };
    r_rsip_func100(Param_p3e_func100_002);

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

    static const uint32_t Param_p3e_func100_003[] =
    {
        BSWAP_32BIG_C(0xbe504a17U), BSWAP_32BIG_C(0x1af8bd73U), BSWAP_32BIG_C(0x6f4a6f03U), BSWAP_32BIG_C(0xc178849eU),
    };
    r_rsip_func100(Param_p3e_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000004U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

    static const uint32_t Param_p3e_func102_001[] =
    {
        BSWAP_32BIG_C(0x0650b350U), BSWAP_32BIG_C(0xfff24829U), BSWAP_32BIG_C(0xd1eb8df5U), BSWAP_32BIG_C(0x8a9dee7eU),
    };
    r_rsip_func102(Param_p3e_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
