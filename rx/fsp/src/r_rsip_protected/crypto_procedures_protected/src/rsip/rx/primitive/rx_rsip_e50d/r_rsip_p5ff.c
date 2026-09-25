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

rsip_ret_t r_rsip_p5ff (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub009(0x0000005fU);

    static const uint32_t Param_p5ff_func101_001[] =
    {
        BSWAP_32BIG_C(0x6d838923U), BSWAP_32BIG_C(0x3295e0acU), BSWAP_32BIG_C(0xcf693202U), BSWAP_32BIG_C(0x1d488bc8U),
    };
    r_rsip_func101(Param_p5ff_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00005f02U);

    static const uint32_t Param_p5ff_func101_002[] =
    {
        BSWAP_32BIG_C(0x8573a1afU), BSWAP_32BIG_C(0x94cee060U), BSWAP_32BIG_C(0x44f8e4f1U), BSWAP_32BIG_C(0x538bcc59U),
    };
    r_rsip_func101(Param_p5ff_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x019c1ff8U);

    r_rsip_func_sub009(0x00005f02U);

    static const uint32_t Param_p5ff_func101_003[] =
    {
        BSWAP_32BIG_C(0x80fc6ee7U), BSWAP_32BIG_C(0xc5cb4d6fU), BSWAP_32BIG_C(0x75c64b49U), BSWAP_32BIG_C(0xe30d92c4U),
    };
    r_rsip_func101(Param_p5ff_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_p5ff_func100_001[] =
    {
        BSWAP_32BIG_C(0xa4d55942U), BSWAP_32BIG_C(0x5659e481U), BSWAP_32BIG_C(0x6386251bU), BSWAP_32BIG_C(0x087d0362U),
    };
    r_rsip_func100(Param_p5ff_func100_001);
    r_rsip_func_sub027(0x40000200U, 0xe7009d07U, 0x81900004U);
    r_rsip_func_sub001(0x00890031U);
    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_p5ff_func100_002[] =
    {
        BSWAP_32BIG_C(0xd65643c1U), BSWAP_32BIG_C(0x537ab48bU), BSWAP_32BIG_C(0x8294d3c3U), BSWAP_32BIG_C(0x2a1121b9U),
    };
    r_rsip_func100(Param_p5ff_func100_002);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_func_sub001(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);

    static const uint32_t Param_p5ff_func100_003[] =
    {
        BSWAP_32BIG_C(0x35547774U), BSWAP_32BIG_C(0x7ddea972U), BSWAP_32BIG_C(0x745fc5f4U), BSWAP_32BIG_C(0xe11bf48aU),
    };
    r_rsip_func100(Param_p5ff_func100_003);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);

    static const uint32_t Param_p5ff_func100_004[] =
    {
        BSWAP_32BIG_C(0x936b1da9U), BSWAP_32BIG_C(0x7cca3215U), BSWAP_32BIG_C(0xcfeb0221U), BSWAP_32BIG_C(0x04ab5741U),
    };
    r_rsip_func100(Param_p5ff_func100_004);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_p5ff_func102_001[] =
    {
        BSWAP_32BIG_C(0xc640e181U), BSWAP_32BIG_C(0x5db318e5U), BSWAP_32BIG_C(0x9a9c9ab3U), BSWAP_32BIG_C(0x4298215fU),
    };
    r_rsip_func102(Param_p5ff_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
