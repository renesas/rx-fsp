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

rsip_ret_t r_rsip_p2d (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002d0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000002dU);

    static const uint32_t Param_p2d_func101_001[] =
    {
        BSWAP_32BIG_C(0xd9b9e7f7U), BSWAP_32BIG_C(0x35dce723U), BSWAP_32BIG_C(0x03d3c0b3U), BSWAP_32BIG_C(0x821a402cU),
    };
    r_rsip_func101(Param_p2d_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub009(0x0000002dU);

    static const uint32_t Param_p2d_func101_002[] =
    {
        BSWAP_32BIG_C(0x6583e002U), BSWAP_32BIG_C(0xfac8ab27U), BSWAP_32BIG_C(0x545224e6U), BSWAP_32BIG_C(0x46f2f5e2U),
    };
    r_rsip_func101(Param_p2d_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x80880001U);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p2d_func100_001[] =
    {
        BSWAP_32BIG_C(0xc95fe973U), BSWAP_32BIG_C(0x8ad91b75U), BSWAP_32BIG_C(0xe4216c41U), BSWAP_32BIG_C(0xe338e62dU),
    };
    r_rsip_func100(Param_p2d_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2d_func102_001[] =
        {
            BSWAP_32BIG_C(0x88c39a45U), BSWAP_32BIG_C(0xd3f30e8eU), BSWAP_32BIG_C(0x5ade582eU), BSWAP_32BIG_C(
                0x74c6b9d1U),
        };
        r_rsip_func102(Param_p2d_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010000U);
        WR1_PROG(REG_1420H, InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x08000c00U, 0x00260000U);

        static const uint32_t Param_p2d_func100_002[] =
        {
            BSWAP_32BIG_C(0xcd1966c1U), BSWAP_32BIG_C(0x6520f9bcU), BSWAP_32BIG_C(0x8d440516U), BSWAP_32BIG_C(
                0xa19b718cU),
        };
        r_rsip_func100(Param_p2d_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2d_func100_003[] =
            {
                BSWAP_32BIG_C(0xe40c5655U), BSWAP_32BIG_C(0x00747d84U), BSWAP_32BIG_C(0xfcbf511fU), BSWAP_32BIG_C(
                    0x7e204528U),
            };
            r_rsip_func100(Param_p2d_func100_003);
            WR1_PROG(REG_1438H, 0x40000100U);

            r_rsip_func_sub023(0x0000b400U, 0x00000001U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2d_func100_004[] =
            {
                BSWAP_32BIG_C(0x57e645b2U), BSWAP_32BIG_C(0x53138c97U), BSWAP_32BIG_C(0x6098168eU), BSWAP_32BIG_C(
                    0x54701731U),
            };
            r_rsip_func100(Param_p2d_func100_004);
            WR1_PROG(REG_1438H, 0x40000110U);

            r_rsip_func_sub001(0x02000009U);

            static const uint32_t Param_p2d_func100_005[] =
            {
                BSWAP_32BIG_C(0x8472ad10U), BSWAP_32BIG_C(0x50079a83U), BSWAP_32BIG_C(0xf4325179U), BSWAP_32BIG_C(
                    0xecc2609dU),
            };
            r_rsip_func100(Param_p2d_func100_005);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81860001U);
            r_rsip_func_sub001(0x02090019U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2d_func100_006[] =
            {
                BSWAP_32BIG_C(0xe2ee563dU), BSWAP_32BIG_C(0x0fbbe8f6U), BSWAP_32BIG_C(0xe0e00b87U), BSWAP_32BIG_C(
                    0xee358335U),
            };
            r_rsip_func100(Param_p2d_func100_006);
            WR1_PROG(REG_1438H, 0x40000140U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2d_func102_002[] =
            {
                BSWAP_32BIG_C(0x95bf4316U), BSWAP_32BIG_C(0x71d6cc61U), BSWAP_32BIG_C(0x10070badU), BSWAP_32BIG_C(
                    0xb1622225U),
            };
            r_rsip_func102(Param_p2d_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
        else
        {
            static const uint32_t Param_p2d_func100_007[] =
            {
                BSWAP_32BIG_C(0xbc120bb3U), BSWAP_32BIG_C(0x56bc20a4U), BSWAP_32BIG_C(0x953ea7ceU), BSWAP_32BIG_C(
                    0x92d4c9eeU),
            };
            r_rsip_func100(Param_p2d_func100_007);
            WR1_PROG(REG_1438H, 0x40000180U);

            r_rsip_func_sub023(0x0000b400U, 0x00000001U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2d_func100_008[] =
            {
                BSWAP_32BIG_C(0x4d917f54U), BSWAP_32BIG_C(0x2443b786U), BSWAP_32BIG_C(0xa3071369U), BSWAP_32BIG_C(
                    0x0ad4df8aU),
            };
            r_rsip_func100(Param_p2d_func100_008);
            WR1_PROG(REG_1438H, 0x40000190U);

            r_rsip_func_sub001(0x02000009U);

            static const uint32_t Param_p2d_func100_009[] =
            {
                BSWAP_32BIG_C(0x37bad3a5U), BSWAP_32BIG_C(0x76825663U), BSWAP_32BIG_C(0x45fdfd12U), BSWAP_32BIG_C(
                    0x57f4dd46U),
            };
            r_rsip_func100(Param_p2d_func100_009);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81860001U);
            r_rsip_func_sub001(0x02090019U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2d_func100_010[] =
            {
                BSWAP_32BIG_C(0x5ba21205U), BSWAP_32BIG_C(0x94fa7e57U), BSWAP_32BIG_C(0x88e84c11U), BSWAP_32BIG_C(
                    0xd3438e22U),
            };
            r_rsip_func100(Param_p2d_func100_010);
            WR1_PROG(REG_1438H, 0x400001C0U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2d_func102_003[] =
            {
                BSWAP_32BIG_C(0xd52f8a62U), BSWAP_32BIG_C(0x27cd53f5U), BSWAP_32BIG_C(0x7de10930U), BSWAP_32BIG_C(
                    0x9ed33d47U),
            };
            r_rsip_func102(Param_p2d_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
