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

rsip_ret_t r_rsip_p85i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00850001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000085U);

    static const uint32_t Param_p85i_func101_001[] =
    {
        BSWAP_32BIG_C(0x2c5da49dU), BSWAP_32BIG_C(0x9c8eaf62U), BSWAP_32BIG_C(0xc3dd710eU), BSWAP_32BIG_C(0x8a9eb826U),
    };
    r_rsip_func101(Param_p85i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub009(0x00000085U);

    static const uint32_t Param_p85i_func101_002[] =
    {
        BSWAP_32BIG_C(0xefaa893cU), BSWAP_32BIG_C(0x140a355fU), BSWAP_32BIG_C(0x0414958eU), BSWAP_32BIG_C(0x15fc0f24U),
    };
    r_rsip_func101(Param_p85i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1608H, 0x80080000U);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p85i_func100_001[] =
    {
        BSWAP_32BIG_C(0x5f6b1294U), BSWAP_32BIG_C(0x03d1fa8eU), BSWAP_32BIG_C(0xd24853faU), BSWAP_32BIG_C(0xe735d9fcU),
    };
    r_rsip_func100(Param_p85i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p85i_func102_001[] =
        {
            BSWAP_32BIG_C(0x41358286U), BSWAP_32BIG_C(0x350441cdU), BSWAP_32BIG_C(0x361d505fU), BSWAP_32BIG_C(
                0x5be2bbc3U),
        };
        r_rsip_func102(Param_p85i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p85i_func100_002[] =
        {
            BSWAP_32BIG_C(0x61fc8766U), BSWAP_32BIG_C(0x83bd3bb1U), BSWAP_32BIG_C(0x7fc9083cU), BSWAP_32BIG_C(
                0x8d41cb84U),
        };
        r_rsip_func100(Param_p85i_func100_002);
        WR1_PROG(REG_1608H, 0x81080000U);
        WR1_PROG(REG_1824H, 0x08000085U);
        r_rsip_func_sub001(0x00490011U);

        static const uint32_t Param_p85i_func100_003[] =
        {
            BSWAP_32BIG_C(0xe629f1d1U), BSWAP_32BIG_C(0x0c7fbb7eU), BSWAP_32BIG_C(0x5b15ba97U), BSWAP_32BIG_C(
                0x9f0ea5c3U),
        };
        r_rsip_func100(Param_p85i_func100_003);
        WR1_PROG(REG_1824H, 0x08000095U);
        r_rsip_func_sub001(0x00490011U);

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
