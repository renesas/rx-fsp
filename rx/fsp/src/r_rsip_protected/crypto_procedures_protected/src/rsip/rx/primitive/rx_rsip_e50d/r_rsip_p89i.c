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

rsip_ret_t r_rsip_p89i (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00890001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000089U);

    static const uint32_t Param_p89i_func101_001[] =
    {
        BSWAP_32BIG_C(0x16ca6384U), BSWAP_32BIG_C(0x71987645U), BSWAP_32BIG_C(0x0eae2656U), BSWAP_32BIG_C(0x87fba0f9U),
    };
    r_rsip_func101(Param_p89i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub009(0x00000089U);

    static const uint32_t Param_p89i_func101_002[] =
    {
        BSWAP_32BIG_C(0x07027dd2U), BSWAP_32BIG_C(0x9441d58bU), BSWAP_32BIG_C(0x21db8436U), BSWAP_32BIG_C(0x66bcdf57U),
    };
    r_rsip_func101(Param_p89i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p89i_func100_001[] =
    {
        BSWAP_32BIG_C(0x2404be57U), BSWAP_32BIG_C(0xa1e85628U), BSWAP_32BIG_C(0x4594c543U), BSWAP_32BIG_C(0x1563f3c5U),
    };
    r_rsip_func100(Param_p89i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p89i_func100_002[] =
    {
        BSWAP_32BIG_C(0x504f8292U), BSWAP_32BIG_C(0x94ab2470U), BSWAP_32BIG_C(0xd0330b8aU), BSWAP_32BIG_C(0x9e372f47U),
    };
    r_rsip_func100(Param_p89i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p89i_func100_003[] =
    {
        BSWAP_32BIG_C(0x3e0914b2U), BSWAP_32BIG_C(0x3e547ddcU), BSWAP_32BIG_C(0x44de9315U), BSWAP_32BIG_C(0xd47ded02U),
    };
    r_rsip_func100(Param_p89i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p89i_func102_001[] =
        {
            BSWAP_32BIG_C(0x063eb495U), BSWAP_32BIG_C(0x69d6bb8cU), BSWAP_32BIG_C(0x484c4922U), BSWAP_32BIG_C(
                0x747b25a1U),
        };
        r_rsip_func102(Param_p89i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub006(0x3c00a880U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p89i_func100_004[] =
        {
            BSWAP_32BIG_C(0x0c6fcf92U), BSWAP_32BIG_C(0x951d5c5dU), BSWAP_32BIG_C(0x17998ae1U), BSWAP_32BIG_C(
                0x373b0dc4U),
        };
        r_rsip_func100(Param_p89i_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p89i_func101_003[] =
            {
                BSWAP_32BIG_C(0x14dc4d51U), BSWAP_32BIG_C(0x4e6aa06eU), BSWAP_32BIG_C(0x9ef64880U), BSWAP_32BIG_C(
                    0xf42dd06fU),
            };
            r_rsip_func101(Param_p89i_func101_003);
        }

        r_rsip_func_sub021(0x0c003080U, 0x2000b4e0U, 0x0a000100U, 0x0c003080U);
        r_rsip_func_sub021(0x2000b4e0U, 0x0a000108U, 0x0c003080U, 0x2000b4e0U);
        r_rsip_func_sub021(0x0e000500U, 0x0c003080U, 0x2000b4e0U, 0x09000908U);

        r_rsip_func_sub021(0x0c00a880U, 0xfffffffcU, 0x2000b4e0U, 0x07000d00U);

        return RSIP_RET_PASS;
    }
}
