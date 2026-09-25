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

rsip_ret_t r_rsip_p83i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00830001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000083U);

    static const uint32_t Param_p83i_func101_001[] =
    {
        BSWAP_32BIG_C(0x9df3ea08U), BSWAP_32BIG_C(0x947eb78dU), BSWAP_32BIG_C(0x256bbfbdU), BSWAP_32BIG_C(0xe8395ddfU),
    };
    r_rsip_func101(Param_p83i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub009(0x00000083U);

    static const uint32_t Param_p83i_func101_002[] =
    {
        BSWAP_32BIG_C(0xcab701aeU), BSWAP_32BIG_C(0x64cb1739U), BSWAP_32BIG_C(0xbd8f0b46U), BSWAP_32BIG_C(0xfea57017U),
    };
    r_rsip_func101(Param_p83i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p83i_func100_001[] =
    {
        BSWAP_32BIG_C(0xce7bdbe2U), BSWAP_32BIG_C(0xd6c064e7U), BSWAP_32BIG_C(0x757be6e9U), BSWAP_32BIG_C(0x63a49a2cU),
    };
    r_rsip_func100(Param_p83i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p83i_func100_002[] =
    {
        BSWAP_32BIG_C(0xaa1e2afaU), BSWAP_32BIG_C(0xd33847b2U), BSWAP_32BIG_C(0x6b9ff5d0U), BSWAP_32BIG_C(0xba06f516U),
    };
    r_rsip_func100(Param_p83i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p83i_func100_003[] =
    {
        BSWAP_32BIG_C(0xc13f0315U), BSWAP_32BIG_C(0xb9898151U), BSWAP_32BIG_C(0x73f78b2aU), BSWAP_32BIG_C(0x08471bdfU),
    };
    r_rsip_func100(Param_p83i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p83i_func102_001[] =
        {
            BSWAP_32BIG_C(0xc4214467U), BSWAP_32BIG_C(0xb8558533U), BSWAP_32BIG_C(0x6b555a95U), BSWAP_32BIG_C(
                0x81aeb99fU),
        };
        r_rsip_func102(Param_p83i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000003c7U, 0x80040080U);
        r_rsip_func_sub042(InData_IV);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x40070010U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        return RSIP_RET_PASS;
    }
}
