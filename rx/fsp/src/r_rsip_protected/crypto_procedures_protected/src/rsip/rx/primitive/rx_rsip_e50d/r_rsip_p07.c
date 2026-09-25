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

rsip_ret_t r_rsip_p07 (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00070001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00000701U);

    static const uint32_t Param_p07_func101_001[] =
    {
        BSWAP_32BIG_C(0xd8770b2aU), BSWAP_32BIG_C(0x9c2573a8U), BSWAP_32BIG_C(0x34386d31U), BSWAP_32BIG_C(0xde30d529U),
    };
    r_rsip_func101(Param_p07_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00000007U);

    static const uint32_t Param_p07_func101_002[] =
    {
        BSWAP_32BIG_C(0x8e9a8ca9U), BSWAP_32BIG_C(0x13967665U), BSWAP_32BIG_C(0x24692c5fU), BSWAP_32BIG_C(0x3f3b3b26U),
    };
    r_rsip_func101(Param_p07_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x00000007U);

    static const uint32_t Param_p07_func101_003[] =
    {
        BSWAP_32BIG_C(0xf0db6244U), BSWAP_32BIG_C(0xacd7deb9U), BSWAP_32BIG_C(0xd6622365U), BSWAP_32BIG_C(0x26e1f6dcU),
    };
    r_rsip_func101(Param_p07_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p07_func100_001[] =
    {
        BSWAP_32BIG_C(0x6f451ab4U), BSWAP_32BIG_C(0xb25da2bfU), BSWAP_32BIG_C(0xba3e95bbU), BSWAP_32BIG_C(0xb4af1a83U),
    };
    r_rsip_func100(Param_p07_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00000702U);

    static const uint32_t Param_p07_func101_004[] =
    {
        BSWAP_32BIG_C(0xdd06724eU), BSWAP_32BIG_C(0x01d45a54U), BSWAP_32BIG_C(0x7cc164e7U), BSWAP_32BIG_C(0xfa55a634U),
    };
    r_rsip_func101(Param_p07_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub027(0x40000000U, 0xe7009d45U, 0x81040000U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_p07_func100_002[] =
    {
        BSWAP_32BIG_C(0x9f22a1afU), BSWAP_32BIG_C(0xe15e0f81U), BSWAP_32BIG_C(0xe68d0d76U), BSWAP_32BIG_C(0xd3b65452U),
    };
    r_rsip_func100(Param_p07_func100_002);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000001U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

    static const uint32_t Param_p07_func102_001[] =
    {
        BSWAP_32BIG_C(0x938ad3f4U), BSWAP_32BIG_C(0xdd4c7afaU), BSWAP_32BIG_C(0x87b8add1U), BSWAP_32BIG_C(0x5f3ae6feU),
    };
    r_rsip_func102(Param_p07_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
