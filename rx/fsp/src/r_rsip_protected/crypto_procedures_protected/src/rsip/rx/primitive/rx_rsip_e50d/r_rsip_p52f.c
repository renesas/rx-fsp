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

rsip_ret_t r_rsip_p52f (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub009(0x00000052U);

    static const uint32_t Param_p52f_func101_001[] =
    {
        BSWAP_32BIG_C(0x6863f43dU), BSWAP_32BIG_C(0x291bfd4fU), BSWAP_32BIG_C(0x747e7641U), BSWAP_32BIG_C(0x9b3afd13U),
    };
    r_rsip_func101(Param_p52f_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00005202U);

    static const uint32_t Param_p52f_func101_002[] =
    {
        BSWAP_32BIG_C(0xebcee305U), BSWAP_32BIG_C(0x3694ce47U), BSWAP_32BIG_C(0x754dcf4dU), BSWAP_32BIG_C(0x973bdbabU),
    };
    r_rsip_func101(Param_p52f_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x019c1ff8U);

    r_rsip_func_sub009(0x00005202U);

    static const uint32_t Param_p52f_func101_003[] =
    {
        BSWAP_32BIG_C(0x1c697cfaU), BSWAP_32BIG_C(0x6f541cc6U), BSWAP_32BIG_C(0x6260a78eU), BSWAP_32BIG_C(0x1773b9fcU),
    };
    r_rsip_func101(Param_p52f_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_p52f_func100_001[] =
    {
        BSWAP_32BIG_C(0xaebdb1d6U), BSWAP_32BIG_C(0x517dcbf0U), BSWAP_32BIG_C(0x66a6d84aU), BSWAP_32BIG_C(0x8de40e31U),
    };
    r_rsip_func100(Param_p52f_func100_001);
    r_rsip_func_sub027(0x40000200U, 0xe7009d07U, 0x81900004U);
    r_rsip_func_sub001(0x00890031U);
    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_p52f_func100_002[] =
    {
        BSWAP_32BIG_C(0xd4ada068U), BSWAP_32BIG_C(0x6f7b0792U), BSWAP_32BIG_C(0xe3aa3b41U), BSWAP_32BIG_C(0x11c474aeU),
    };
    r_rsip_func100(Param_p52f_func100_002);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_func_sub001(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);

    static const uint32_t Param_p52f_func100_003[] =
    {
        BSWAP_32BIG_C(0xb001af5fU), BSWAP_32BIG_C(0x575de014U), BSWAP_32BIG_C(0xd45f804eU), BSWAP_32BIG_C(0x3b490cd2U),
    };
    r_rsip_func100(Param_p52f_func100_003);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);

    static const uint32_t Param_p52f_func100_004[] =
    {
        BSWAP_32BIG_C(0x9c909456U), BSWAP_32BIG_C(0xb852b0f1U), BSWAP_32BIG_C(0xf7a103e3U), BSWAP_32BIG_C(0xc4732d90U),
    };
    r_rsip_func100(Param_p52f_func100_004);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_p52f_func102_001[] =
    {
        BSWAP_32BIG_C(0x2d034f82U), BSWAP_32BIG_C(0x92d927f0U), BSWAP_32BIG_C(0x00e84cd6U), BSWAP_32BIG_C(0xaf89c7daU),
    };
    r_rsip_func102(Param_p52f_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
