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

void r_rsip_func414 (uint32_t ARG1[])
{
    WR1_PROG(REG_1600H, 0x0000379dU);

    r_rsip_func_sub009(0x0000f414U);

    static const uint32_t Param_func414_func101_001[] =
    {
        BSWAP_32BIG_C(0x3f8363c1U), BSWAP_32BIG_C(0x9b36bd3bU), BSWAP_32BIG_C(0xf8f2dec5U), BSWAP_32BIG_C(0x5404a3efU),
    };
    r_rsip_func101(Param_func414_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000f414U);

    static const uint32_t Param_func414_func101_002[] =
    {
        BSWAP_32BIG_C(0xfe118a2bU), BSWAP_32BIG_C(0x2ae9b229U), BSWAP_32BIG_C(0x371acc35U), BSWAP_32BIG_C(0x6a628b9fU),
    };
    r_rsip_func101(Param_func414_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x01df34faU);

    r_rsip_func_sub009(0x0000f414U);

    static const uint32_t Param_func414_func101_003[] =
    {
        BSWAP_32BIG_C(0x7959e25bU), BSWAP_32BIG_C(0x388af648U), BSWAP_32BIG_C(0x97492b80U), BSWAP_32BIG_C(0x8efab815U),
    };
    r_rsip_func101(Param_func414_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_func414_func100_001[] =
    {
        BSWAP_32BIG_C(0x9aab4effU), BSWAP_32BIG_C(0x89cae8d9U), BSWAP_32BIG_C(0x27e3ae1bU), BSWAP_32BIG_C(0x89e13546U),
    };
    r_rsip_func100(Param_func414_func100_001);
    r_rsip_func_sub027(0x40000100U, 0xe7009d07U, 0x81880004U);
    r_rsip_func_sub001(0x00890021U);
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG1[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG1[5]);

    static const uint32_t Param_func414_func100_002[] =
    {
        BSWAP_32BIG_C(0x3877d544U), BSWAP_32BIG_C(0x0357ad7dU), BSWAP_32BIG_C(0xa8928d63U), BSWAP_32BIG_C(0xac490e63U),
    };
    r_rsip_func100(Param_func414_func100_002);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG1[9]);

    static const uint32_t Param_func414_func100_003[] =
    {
        BSWAP_32BIG_C(0xd615834cU), BSWAP_32BIG_C(0x9aa593f5U), BSWAP_32BIG_C(0x892821a1U), BSWAP_32BIG_C(0xbffd3f0aU),
    };
    r_rsip_func100(Param_func414_func100_003);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &ARG1[0]);

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
