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

rsip_ret_t r_rsip_p78f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2440H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020065U);

    for (iLoop = 0U; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop = iLoop + S_RAM[0])
    {
        WAIT_STS(REG_1444H, 31, 1);
        for (jLoop = 0U; jLoop < S_RAM[0]; jLoop = jLoop + 2)
        {
            WR2_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001400U);

    WAIT_STS(REG_2440H, 4, 1);

    static const uint32_t Param_p78f_func100_001[] =
    {
        BSWAP_32BIG_C(0x4c134ef4U), BSWAP_32BIG_C(0xef97e3b2U), BSWAP_32BIG_C(0xf54e7148U), BSWAP_32BIG_C(0x95c54c82U),
    };
    r_rsip_func100(Param_p78f_func100_001);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        static const uint32_t Param_p78f_func100_002[] =
        {
            BSWAP_32BIG_C(0xcc313e36U), BSWAP_32BIG_C(0x16846da3U), BSWAP_32BIG_C(0x9cc71ccfU), BSWAP_32BIG_C(
                0xbef39c21U),
        };
        r_rsip_func100(Param_p78f_func100_002);
        WR1_PROG(REG_1408H, 0x0000601eU);
        WAIT_STS(REG_1408H, 30, 1);
        RD7_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_001[] =
        {
            BSWAP_32BIG_C(0x39997d7eU), BSWAP_32BIG_C(0xf00c199bU), BSWAP_32BIG_C(0xef4e6182U), BSWAP_32BIG_C(
                0x131ad92eU),
        };
        r_rsip_func102(Param_p78f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p78f_func100_003[] =
        {
            BSWAP_32BIG_C(0xc80f6870U), BSWAP_32BIG_C(0xe25868d5U), BSWAP_32BIG_C(0xb66e2730U), BSWAP_32BIG_C(
                0xc73dfe49U),
        };
        r_rsip_func100(Param_p78f_func100_003);
        WR1_PROG(REG_1408H, 0x00006022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD8_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_002[] =
        {
            BSWAP_32BIG_C(0x748084faU), BSWAP_32BIG_C(0xa41d50e5U), BSWAP_32BIG_C(0x23c3cdf7U), BSWAP_32BIG_C(
                0x047fa9cfU),
        };
        r_rsip_func102(Param_p78f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p78f_func100_004[] =
        {
            BSWAP_32BIG_C(0x254d5f8aU), BSWAP_32BIG_C(0xf881a763U), BSWAP_32BIG_C(0x97494e69U), BSWAP_32BIG_C(
                0x5dc8e160U),
        };
        r_rsip_func100(Param_p78f_func100_004);
        WR1_PROG(REG_1408H, 0x00006032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD12_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_003[] =
        {
            BSWAP_32BIG_C(0xf21d6b51U), BSWAP_32BIG_C(0x63f4a832U), BSWAP_32BIG_C(0xc883b1ccU), BSWAP_32BIG_C(
                0x1e48e670U),
        };
        r_rsip_func102(Param_p78f_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        static const uint32_t Param_p78f_func100_005[] =
        {
            BSWAP_32BIG_C(0x12a08302U), BSWAP_32BIG_C(0xfa93f8ebU), BSWAP_32BIG_C(0x6effbd78U), BSWAP_32BIG_C(
                0xf8f14f52U),
        };
        r_rsip_func100(Param_p78f_func100_005);
        WR1_PROG(REG_1408H, 0x00006042U);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_004[] =
        {
            BSWAP_32BIG_C(0xc26bafddU), BSWAP_32BIG_C(0x9c390e3cU), BSWAP_32BIG_C(0xec8dd174U), BSWAP_32BIG_C(
                0x7f0dbff9U),
        };
        r_rsip_func102(Param_p78f_func102_004);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }

    return RSIP_RET_PASS;
}
