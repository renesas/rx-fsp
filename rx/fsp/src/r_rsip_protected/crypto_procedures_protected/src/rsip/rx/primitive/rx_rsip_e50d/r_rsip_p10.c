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

rsip_ret_t r_rsip_p10 (const uint32_t InData_LC[], const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00100001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    r_rsip_func049(InData_Cmd);

    r_rsip_func_sub006(0x38008800U, 0x00000002U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000003U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000005U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000006U, 0x00260000U);

    r_rsip_func_sub006(0x38008880U, 0x000000fdU, 0x00A60000U);

    r_rsip_func_sub021(0x0000b4c0U, 0x000001b0U, 0x000038a6U, 0x38000805U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    static const uint32_t Param_p10_func100_001[] =
    {
        BSWAP_32BIG_C(0x5ef5ae5aU), BSWAP_32BIG_C(0xef18906eU), BSWAP_32BIG_C(0x0aa4dd5aU), BSWAP_32BIG_C(0xd1d40beaU),
    };
    r_rsip_func100(Param_p10_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p10_func102_001[] =
        {
            BSWAP_32BIG_C(0xc9b6e3d2U), BSWAP_32BIG_C(0x56849105U), BSWAP_32BIG_C(0x32f82013U), BSWAP_32BIG_C(
                0x8c0f9dafU),
        };
        r_rsip_func102(Param_p10_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x000000fdU);

        r_rsip_func_sub009(0x00000010U);

        static const uint32_t Param_p10_func101_001[] =
        {
            BSWAP_32BIG_C(0x0a70af23U), BSWAP_32BIG_C(0x717ed7a8U), BSWAP_32BIG_C(0x031df457U), BSWAP_32BIG_C(
                0x55569246U),
        };
        r_rsip_func101(Param_p10_func101_001);
        r_rsip_func043();

        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009c07U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[4]);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[8]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p10_func100_002[] =
        {
            BSWAP_32BIG_C(0xfff7169fU), BSWAP_32BIG_C(0x75788a96U), BSWAP_32BIG_C(0x90349903U), BSWAP_32BIG_C(
                0x00de03f3U),
        };
        r_rsip_func100(Param_p10_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p10_func102_002[] =
            {
                BSWAP_32BIG_C(0x55375b7cU), BSWAP_32BIG_C(0x52464d05U), BSWAP_32BIG_C(0xc0a30512U), BSWAP_32BIG_C(
                    0xb1545d49U),
            };
            r_rsip_func102(Param_p10_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            static const uint32_t Param_p10_func102_003[] =
            {
                BSWAP_32BIG_C(0x11a8e9beU), BSWAP_32BIG_C(0xa3acfce3U), BSWAP_32BIG_C(0x7ae4b400U), BSWAP_32BIG_C(
                    0x8e91f813U),
            };
            r_rsip_func102(Param_p10_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
