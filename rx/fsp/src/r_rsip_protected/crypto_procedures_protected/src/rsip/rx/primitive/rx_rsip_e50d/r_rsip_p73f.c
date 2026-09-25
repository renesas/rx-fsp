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

rsip_ret_t r_rsip_p73f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
{
    uint32_t iLoop = 0U;

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    r_rsip_func_sub043();

    WAIT_STS(REG_2030H, 4, 1);

    static const uint32_t Param_p73f_func100_001[] =
    {
        BSWAP_32BIG_C(0x81873db6U), BSWAP_32BIG_C(0x404f6bbfU), BSWAP_32BIG_C(0x9cf9850aU), BSWAP_32BIG_C(0x1880e8dbU),
    };
    r_rsip_func100(Param_p73f_func100_001);
    r_rsip_func_sub021(0x38008800U, 0x00000003U, 0x1000b400U, 0x00000001U);

    r_rsip_func_sub021(0x38008800U, 0x00000004U, 0x1000b400U, 0x00000002U);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p73f_func100_002[] =
        {
            BSWAP_32BIG_C(0x0bf7fdaeU), BSWAP_32BIG_C(0x050521fcU), BSWAP_32BIG_C(0xd221a9dbU), BSWAP_32BIG_C(
                0x29a89a3dU),
        };
        r_rsip_func100(Param_p73f_func100_002);
        WR1_PROG(REG_1408H, 0x0000401eU);
        WAIT_STS(REG_1408H, 30, 1);
        RD7_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_001[] =
        {
            BSWAP_32BIG_C(0x7770d4a6U), BSWAP_32BIG_C(0x975f69d4U), BSWAP_32BIG_C(0xb800eec5U), BSWAP_32BIG_C(
                0x3c0cde3fU),
        };
        r_rsip_func102(Param_p73f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p73f_func100_003[] =
        {
            BSWAP_32BIG_C(0xfabe356fU), BSWAP_32BIG_C(0x204a11d3U), BSWAP_32BIG_C(0x89d27702U), BSWAP_32BIG_C(
                0x08209f8bU),
        };
        r_rsip_func100(Param_p73f_func100_003);
        WR1_PROG(REG_1408H, 0x00004022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD8_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_002[] =
        {
            BSWAP_32BIG_C(0xac50157bU), BSWAP_32BIG_C(0xbbcc92e8U), BSWAP_32BIG_C(0x440b6c77U), BSWAP_32BIG_C(
                0xfa9632fcU),
        };
        r_rsip_func102(Param_p73f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        static const uint32_t Param_p73f_func100_004[] =
        {
            BSWAP_32BIG_C(0xe86807b5U), BSWAP_32BIG_C(0xd72aee2eU), BSWAP_32BIG_C(0x9dc1fed4U), BSWAP_32BIG_C(
                0x7adc6806U),
        };
        r_rsip_func100(Param_p73f_func100_004);
        WR1_PROG(REG_1408H, 0x00004032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD12_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_003[] =
        {
            BSWAP_32BIG_C(0xf74b06e5U), BSWAP_32BIG_C(0x06504c40U), BSWAP_32BIG_C(0xb6bcd6c0U), BSWAP_32BIG_C(
                0x618b2aaeU),
        };
        r_rsip_func102(Param_p73f_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
    {
        static const uint32_t Param_p73f_func100_005[] =
        {
            BSWAP_32BIG_C(0xa33857f6U), BSWAP_32BIG_C(0xdb46f446U), BSWAP_32BIG_C(0x0584d667U), BSWAP_32BIG_C(
                0x38f617f0U),
        };
        r_rsip_func100(Param_p73f_func100_005);
        WR1_PROG(REG_1408H, 0x00004042U);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_004[] =
        {
            BSWAP_32BIG_C(0x6ad2dba8U), BSWAP_32BIG_C(0x6efb770eU), BSWAP_32BIG_C(0x730c2807U), BSWAP_32BIG_C(
                0x4afd5ca6U),
        };
        r_rsip_func102(Param_p73f_func102_004);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }

    return RSIP_RET_PASS;
}
