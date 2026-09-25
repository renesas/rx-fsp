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

rsip_ret_t r_rsip_p41i (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00410001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000041U);

    static const uint32_t Param_p41i_func101_001[] =
    {
        BSWAP_32BIG_C(0xeb3f2a9bU), BSWAP_32BIG_C(0x0de72998U), BSWAP_32BIG_C(0x7a6d6fe1U), BSWAP_32BIG_C(0x3888bce0U),
    };
    r_rsip_func101(Param_p41i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x00000041U);

    static const uint32_t Param_p41i_func101_002[] =
    {
        BSWAP_32BIG_C(0xd1d65cedU), BSWAP_32BIG_C(0x3072067dU), BSWAP_32BIG_C(0x839436a8U), BSWAP_32BIG_C(0x3e1bf7e0U),
    };
    r_rsip_func101(Param_p41i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p41i_func100_001[] =
    {
        BSWAP_32BIG_C(0xb307a95cU), BSWAP_32BIG_C(0xc62d68d7U), BSWAP_32BIG_C(0x3eb813a5U), BSWAP_32BIG_C(0x3ddedf8cU),
    };
    r_rsip_func100(Param_p41i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p41i_func100_002[] =
    {
        BSWAP_32BIG_C(0x65b3bc87U), BSWAP_32BIG_C(0x3b174a1bU), BSWAP_32BIG_C(0xdf5a6a6eU), BSWAP_32BIG_C(0x05440366U),
    };
    r_rsip_func100(Param_p41i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p41i_func102_001[] =
        {
            BSWAP_32BIG_C(0x4c07d630U), BSWAP_32BIG_C(0x8adea3deU), BSWAP_32BIG_C(0xa429b5abU), BSWAP_32BIG_C(
                0x7993f97cU),
        };
        r_rsip_func102(Param_p41i_func102_001);
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
