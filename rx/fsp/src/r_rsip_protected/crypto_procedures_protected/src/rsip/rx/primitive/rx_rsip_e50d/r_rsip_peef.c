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

rsip_ret_t r_rsip_peef (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub009(0x00000eefU);

    static const uint32_t Param_peef_func101_001[] =
    {
        BSWAP_32BIG_C(0xd85e21efU), BSWAP_32BIG_C(0xe30ab9b7U), BSWAP_32BIG_C(0x3290636bU), BSWAP_32BIG_C(0xc8c2d84cU),
    };
    r_rsip_func101(Param_peef_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000ee02U);

    static const uint32_t Param_peef_func101_002[] =
    {
        BSWAP_32BIG_C(0x1f8d9d99U), BSWAP_32BIG_C(0x9f3c3eddU), BSWAP_32BIG_C(0xcc5704d5U), BSWAP_32BIG_C(0x49a6e3f2U),
    };
    r_rsip_func101(Param_peef_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x01df34faU);

    r_rsip_func_sub009(0x0000ee02U);

    static const uint32_t Param_peef_func101_003[] =
    {
        BSWAP_32BIG_C(0x33488929U), BSWAP_32BIG_C(0x42a7ecb7U), BSWAP_32BIG_C(0x6b9b5a7eU), BSWAP_32BIG_C(0x97726c14U),
    };
    r_rsip_func101(Param_peef_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_peef_func100_001[] =
    {
        BSWAP_32BIG_C(0x245269f1U), BSWAP_32BIG_C(0x225d46f5U), BSWAP_32BIG_C(0x3003b571U), BSWAP_32BIG_C(0x8537d6edU),
    };
    r_rsip_func100(Param_peef_func100_001);
    r_rsip_func_sub027(0x40000100U, 0xe7009d07U, 0x81880004U);
    r_rsip_func_sub001(0x00890021U);
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);

    static const uint32_t Param_peef_func100_002[] =
    {
        BSWAP_32BIG_C(0xbd2eed38U), BSWAP_32BIG_C(0x66eefce1U), BSWAP_32BIG_C(0xa17cd4e1U), BSWAP_32BIG_C(0x9fb32d5fU),
    };
    r_rsip_func100(Param_peef_func100_002);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_peef_func100_003[] =
    {
        BSWAP_32BIG_C(0xfc5ab4cbU), BSWAP_32BIG_C(0xe3645826U), BSWAP_32BIG_C(0xb2807ac2U), BSWAP_32BIG_C(0xb436f1abU),
    };
    r_rsip_func100(Param_peef_func100_003);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_peef_func102_001[] =
    {
        BSWAP_32BIG_C(0x3e72b1afU), BSWAP_32BIG_C(0x1440157aU), BSWAP_32BIG_C(0xb34b4b43U), BSWAP_32BIG_C(0xa48b3030U),
    };
    r_rsip_func102(Param_peef_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
