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

rsip_ret_t r_rsip_p2c (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002c0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000002cU);

    static const uint32_t Param_p2c_func101_001[] =
    {
        BSWAP_32BIG_C(0x29606d23U), BSWAP_32BIG_C(0x2ace1715U), BSWAP_32BIG_C(0xcfbcfa29U), BSWAP_32BIG_C(0xb9686021U),
    };
    r_rsip_func101(Param_p2c_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x0000002cU);

    static const uint32_t Param_p2c_func101_002[] =
    {
        BSWAP_32BIG_C(0xee0b8c22U), BSWAP_32BIG_C(0xd930ce2aU), BSWAP_32BIG_C(0xbdc670bfU), BSWAP_32BIG_C(0x0b74931aU),
    };
    r_rsip_func101(Param_p2c_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x80840001U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p2c_func100_001[] =
    {
        BSWAP_32BIG_C(0x20650634U), BSWAP_32BIG_C(0xf2b8964eU), BSWAP_32BIG_C(0x1ad38d66U), BSWAP_32BIG_C(0x5b3f8e06U),
    };
    r_rsip_func100(Param_p2c_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2c_func102_001[] =
        {
            BSWAP_32BIG_C(0x154d3149U), BSWAP_32BIG_C(0x943511e7U), BSWAP_32BIG_C(0xa5b71628U), BSWAP_32BIG_C(
                0xd7f45d20U),
        };
        r_rsip_func102(Param_p2c_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010000U);
        WR1_PROG(REG_1420H, InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000c00U, 0x00260000U);

        static const uint32_t Param_p2c_func100_002[] =
        {
            BSWAP_32BIG_C(0x4dfc4b62U), BSWAP_32BIG_C(0x7af4d603U), BSWAP_32BIG_C(0xef53b874U), BSWAP_32BIG_C(
                0x5a39a560U),
        };
        r_rsip_func100(Param_p2c_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2c_func100_003[] =
            {
                BSWAP_32BIG_C(0xc9483ed2U), BSWAP_32BIG_C(0x19e33f2cU), BSWAP_32BIG_C(0x1f108210U), BSWAP_32BIG_C(
                    0xf21a48bbU),
            };
            r_rsip_func100(Param_p2c_func100_003);
            WR1_PROG(REG_1438H, 0x40000100U);

            r_rsip_func_sub023(0x0000b400U, 0x00000000U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2c_func100_004[] =
            {
                BSWAP_32BIG_C(0xf1f3e27eU), BSWAP_32BIG_C(0x3b445389U), BSWAP_32BIG_C(0x9e2e1d66U), BSWAP_32BIG_C(
                    0x6a23a0b0U),
            };
            r_rsip_func100(Param_p2c_func100_004);
            WR1_PROG(REG_1438H, 0x40000110U);

            r_rsip_func_sub001(0x02000011U);

            static const uint32_t Param_p2c_func100_005[] =
            {
                BSWAP_32BIG_C(0x0c2a785aU), BSWAP_32BIG_C(0x8a93454fU), BSWAP_32BIG_C(0xf225ca44U), BSWAP_32BIG_C(
                    0x4b8ae6feU),
            };
            r_rsip_func100(Param_p2c_func100_005);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x02090011U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2c_func100_006[] =
            {
                BSWAP_32BIG_C(0xc8f39bffU), BSWAP_32BIG_C(0xbe47a86cU), BSWAP_32BIG_C(0xce3c368dU), BSWAP_32BIG_C(
                    0x17fa2e50U),
            };
            r_rsip_func100(Param_p2c_func100_006);
            WR1_PROG(REG_1438H, 0x40000140U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2c_func102_002[] =
            {
                BSWAP_32BIG_C(0xf839bc0eU), BSWAP_32BIG_C(0xb10bcb6eU), BSWAP_32BIG_C(0xd946340fU), BSWAP_32BIG_C(
                    0x1d94a1fdU),
            };
            r_rsip_func102(Param_p2c_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
        else
        {
            static const uint32_t Param_p2c_func100_007[] =
            {
                BSWAP_32BIG_C(0xeaa347b4U), BSWAP_32BIG_C(0xce76dd71U), BSWAP_32BIG_C(0xf2049a8eU), BSWAP_32BIG_C(
                    0x8555d908U),
            };
            r_rsip_func100(Param_p2c_func100_007);
            WR1_PROG(REG_1438H, 0x40000180U);

            r_rsip_func_sub023(0x0000b400U, 0x00000000U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2c_func100_008[] =
            {
                BSWAP_32BIG_C(0x4801a6ffU), BSWAP_32BIG_C(0x6d138fddU), BSWAP_32BIG_C(0x0688dba8U), BSWAP_32BIG_C(
                    0x5073df9bU),
            };
            r_rsip_func100(Param_p2c_func100_008);
            WR1_PROG(REG_1438H, 0x40000190U);

            r_rsip_func_sub001(0x02000011U);

            static const uint32_t Param_p2c_func100_009[] =
            {
                BSWAP_32BIG_C(0xa659ec31U), BSWAP_32BIG_C(0x909364a3U), BSWAP_32BIG_C(0xefb53693U), BSWAP_32BIG_C(
                    0x937da76fU),
            };
            r_rsip_func100(Param_p2c_func100_009);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x02090011U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2c_func100_010[] =
            {
                BSWAP_32BIG_C(0x7e515ac5U), BSWAP_32BIG_C(0x3107b387U), BSWAP_32BIG_C(0xa742653dU), BSWAP_32BIG_C(
                    0xe8d3be52U),
            };
            r_rsip_func100(Param_p2c_func100_010);
            WR1_PROG(REG_1438H, 0x400001C0U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2c_func102_003[] =
            {
                BSWAP_32BIG_C(0xbc51fb76U), BSWAP_32BIG_C(0x1ad854d7U), BSWAP_32BIG_C(0xb1aea890U), BSWAP_32BIG_C(
                    0x0182df81U),
            };
            r_rsip_func102(Param_p2c_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
