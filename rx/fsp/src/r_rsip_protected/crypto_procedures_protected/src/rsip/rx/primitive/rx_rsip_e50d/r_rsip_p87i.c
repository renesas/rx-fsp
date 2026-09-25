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

rsip_ret_t r_rsip_p87i (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00870001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000087U);

    static const uint32_t Param_p87i_func101_001[] =
    {
        BSWAP_32BIG_C(0xeabc6499U), BSWAP_32BIG_C(0x9182766fU), BSWAP_32BIG_C(0x5ba4e95dU), BSWAP_32BIG_C(0xd8deb5c2U),
    };
    r_rsip_func101(Param_p87i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub009(0x00000087U);

    static const uint32_t Param_p87i_func101_002[] =
    {
        BSWAP_32BIG_C(0xe874d4e0U), BSWAP_32BIG_C(0x52c61361U), BSWAP_32BIG_C(0x1cbc01ffU), BSWAP_32BIG_C(0xd58b357cU),
    };
    r_rsip_func101(Param_p87i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p87i_func100_001[] =
    {
        BSWAP_32BIG_C(0x9b14848aU), BSWAP_32BIG_C(0x7bdc37c0U), BSWAP_32BIG_C(0x3ee656a8U), BSWAP_32BIG_C(0x451fe289U),
    };
    r_rsip_func100(Param_p87i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p87i_func100_002[] =
    {
        BSWAP_32BIG_C(0x857c2394U), BSWAP_32BIG_C(0x8b04cb0eU), BSWAP_32BIG_C(0xf11fc8d4U), BSWAP_32BIG_C(0x754c5ba3U),
    };
    r_rsip_func100(Param_p87i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p87i_func100_003[] =
    {
        BSWAP_32BIG_C(0x96a30b63U), BSWAP_32BIG_C(0x2d57a0efU), BSWAP_32BIG_C(0xd4795c51U), BSWAP_32BIG_C(0xb6654baeU),
    };
    r_rsip_func100(Param_p87i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p87i_func102_001[] =
        {
            BSWAP_32BIG_C(0x11586307U), BSWAP_32BIG_C(0x01df47c2U), BSWAP_32BIG_C(0x570e499bU), BSWAP_32BIG_C(
                0x6fbd7536U),
        };
        r_rsip_func102(Param_p87i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub020(0x000000a1U, 0x08000044U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        return RSIP_RET_PASS;
    }
}
