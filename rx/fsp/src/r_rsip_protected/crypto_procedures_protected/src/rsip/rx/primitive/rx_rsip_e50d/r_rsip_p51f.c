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

rsip_ret_t r_rsip_p51f (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub009(0x00000051U);

    static const uint32_t Param_p51f_func101_001[] =
    {
        BSWAP_32BIG_C(0xaf350067U), BSWAP_32BIG_C(0xaa0cf6aeU), BSWAP_32BIG_C(0xe5795625U), BSWAP_32BIG_C(0xcbaa448fU),
    };
    r_rsip_func101(Param_p51f_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00005102U);

    static const uint32_t Param_p51f_func101_002[] =
    {
        BSWAP_32BIG_C(0x28db1d49U), BSWAP_32BIG_C(0x9d5dcee7U), BSWAP_32BIG_C(0xa2e87817U), BSWAP_32BIG_C(0x44b3e1dcU),
    };
    r_rsip_func101(Param_p51f_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x01d972d8U);

    r_rsip_func_sub009(0x00005102U);

    static const uint32_t Param_p51f_func101_003[] =
    {
        BSWAP_32BIG_C(0xd4a19b80U), BSWAP_32BIG_C(0xc357b705U), BSWAP_32BIG_C(0xd0f790a9U), BSWAP_32BIG_C(0x20910ad1U),
    };
    r_rsip_func101(Param_p51f_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_p51f_func100_001[] =
    {
        BSWAP_32BIG_C(0x39e13c7cU), BSWAP_32BIG_C(0x2a8fdce7U), BSWAP_32BIG_C(0xabb89d81U), BSWAP_32BIG_C(0x15d2a2e0U),
    };
    r_rsip_func100(Param_p51f_func100_001);
    r_rsip_func_sub027(0x40000200U, 0xe7009d07U, 0x818c0004U);
    r_rsip_func_sub001(0x00890031U);
    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_p51f_func100_002[] =
    {
        BSWAP_32BIG_C(0x20f0e8e8U), BSWAP_32BIG_C(0xd12f4b55U), BSWAP_32BIG_C(0x486ba766U), BSWAP_32BIG_C(0x632dd240U),
    };
    r_rsip_func100(Param_p51f_func100_002);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);

    static const uint32_t Param_p51f_func100_003[] =
    {
        BSWAP_32BIG_C(0xe594830fU), BSWAP_32BIG_C(0x2df0d36bU), BSWAP_32BIG_C(0x5dc1173fU), BSWAP_32BIG_C(0x4ac034c5U),
    };
    r_rsip_func100(Param_p51f_func100_003);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_p51f_func102_001[] =
    {
        BSWAP_32BIG_C(0xbe53be26U), BSWAP_32BIG_C(0xd652d1b7U), BSWAP_32BIG_C(0x7301a7afU), BSWAP_32BIG_C(0x4f7bfb8eU),
    };
    r_rsip_func102(Param_p51f_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
