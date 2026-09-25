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

rsip_ret_t r_rsip_p44i (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00440001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000044U);

    static const uint32_t Param_p44i_func101_001[] =
    {
        BSWAP_32BIG_C(0x78cca89cU), BSWAP_32BIG_C(0x25c2e78aU), BSWAP_32BIG_C(0x02616f1bU), BSWAP_32BIG_C(0x6a6ae6b1U),
    };
    r_rsip_func101(Param_p44i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x00000044U);

    static const uint32_t Param_p44i_func101_002[] =
    {
        BSWAP_32BIG_C(0x5a686d91U), BSWAP_32BIG_C(0x63af073dU), BSWAP_32BIG_C(0x5bcd175bU), BSWAP_32BIG_C(0xfd8ff94aU),
    };
    r_rsip_func101(Param_p44i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p44i_func100_001[] =
    {
        BSWAP_32BIG_C(0xf2086e21U), BSWAP_32BIG_C(0xd0ff01ccU), BSWAP_32BIG_C(0x18189b69U), BSWAP_32BIG_C(0xd9db91d1U),
    };
    r_rsip_func100(Param_p44i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p44i_func100_002[] =
    {
        BSWAP_32BIG_C(0xd9bda41cU), BSWAP_32BIG_C(0xda57a399U), BSWAP_32BIG_C(0x5a3fd2e3U), BSWAP_32BIG_C(0xee0045cbU),
    };
    r_rsip_func100(Param_p44i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p44i_func100_003[] =
    {
        BSWAP_32BIG_C(0xca86f3deU), BSWAP_32BIG_C(0xda3cbd8bU), BSWAP_32BIG_C(0xddb7816dU), BSWAP_32BIG_C(0xd283868fU),
    };
    r_rsip_func100(Param_p44i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p44i_func102_001[] =
        {
            BSWAP_32BIG_C(0x37736dc9U), BSWAP_32BIG_C(0xfe7d90ceU), BSWAP_32BIG_C(0xb48085c4U), BSWAP_32BIG_C(
                0xbeb332cfU),
        };
        r_rsip_func102(Param_p44i_func102_001);
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
