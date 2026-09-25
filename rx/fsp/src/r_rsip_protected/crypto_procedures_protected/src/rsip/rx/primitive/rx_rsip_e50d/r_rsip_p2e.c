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

rsip_ret_t r_rsip_p2e (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002e0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000002eU);

    static const uint32_t Param_p2e_func101_001[] =
    {
        BSWAP_32BIG_C(0x6e526c35U), BSWAP_32BIG_C(0x501dfedaU), BSWAP_32BIG_C(0xeded373dU), BSWAP_32BIG_C(0x9ab12c1cU),
    };
    r_rsip_func101(Param_p2e_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x0000002eU);

    static const uint32_t Param_p2e_func101_002[] =
    {
        BSWAP_32BIG_C(0xc56ce179U), BSWAP_32BIG_C(0x8920b0b4U), BSWAP_32BIG_C(0x5a720ed4U), BSWAP_32BIG_C(0x4c33d1bcU),
    };
    r_rsip_func101(Param_p2e_func101_002);
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

    static const uint32_t Param_p2e_func100_001[] =
    {
        BSWAP_32BIG_C(0xa89fce5bU), BSWAP_32BIG_C(0xb21f7a26U), BSWAP_32BIG_C(0x840bcbf0U), BSWAP_32BIG_C(0x2106f880U),
    };
    r_rsip_func100(Param_p2e_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2e_func102_001[] =
        {
            BSWAP_32BIG_C(0x2a214d3eU), BSWAP_32BIG_C(0xc9ea79f9U), BSWAP_32BIG_C(0x049ca0d6U), BSWAP_32BIG_C(
                0x2bf082ffU),
        };
        r_rsip_func102(Param_p2e_func102_001);
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

        static const uint32_t Param_p2e_func100_002[] =
        {
            BSWAP_32BIG_C(0xb542305dU), BSWAP_32BIG_C(0x1d1cb543U), BSWAP_32BIG_C(0xc030acb3U), BSWAP_32BIG_C(
                0x069f1093U),
        };
        r_rsip_func100(Param_p2e_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2e_func100_003[] =
            {
                BSWAP_32BIG_C(0x71e70532U), BSWAP_32BIG_C(0xf6059707U), BSWAP_32BIG_C(0x565c792eU), BSWAP_32BIG_C(
                    0x802129b2U),
            };
            r_rsip_func100(Param_p2e_func100_003);
            WR1_PROG(REG_1438H, 0x40000100U);

            r_rsip_func_sub023(0x0000b400U, 0x00000002U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2e_func100_004[] =
            {
                BSWAP_32BIG_C(0x23f95541U), BSWAP_32BIG_C(0x08e0e408U), BSWAP_32BIG_C(0x1f3f122fU), BSWAP_32BIG_C(
                    0xc8a3611aU),
            };
            r_rsip_func100(Param_p2e_func100_004);
            WR1_PROG(REG_1438H, 0x40000110U);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81880001U);
            r_rsip_func_sub001(0x02090021U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2e_func100_005[] =
            {
                BSWAP_32BIG_C(0x2f8f7068U), BSWAP_32BIG_C(0x2bebbf99U), BSWAP_32BIG_C(0x00cf2b88U), BSWAP_32BIG_C(
                    0x69162feeU),
            };
            r_rsip_func100(Param_p2e_func100_005);
            WR1_PROG(REG_1438H, 0x40000140U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2e_func102_002[] =
            {
                BSWAP_32BIG_C(0x730535a5U), BSWAP_32BIG_C(0x38e10851U), BSWAP_32BIG_C(0x364756b3U), BSWAP_32BIG_C(
                    0x0516d2d3U),
            };
            r_rsip_func102(Param_p2e_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
        else
        {
            static const uint32_t Param_p2e_func100_006[] =
            {
                BSWAP_32BIG_C(0xb38b9192U), BSWAP_32BIG_C(0xcdd81869U), BSWAP_32BIG_C(0x2c32c87eU), BSWAP_32BIG_C(
                    0xb07ebe33U),
            };
            r_rsip_func100(Param_p2e_func100_006);
            WR1_PROG(REG_1438H, 0x40000180U);

            r_rsip_func_sub023(0x0000b400U, 0x00000002U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2e_func100_007[] =
            {
                BSWAP_32BIG_C(0xfa947676U), BSWAP_32BIG_C(0x44be72c5U), BSWAP_32BIG_C(0x6f35f3b6U), BSWAP_32BIG_C(
                    0xb2c26c71U),
            };
            r_rsip_func100(Param_p2e_func100_007);
            WR1_PROG(REG_1438H, 0x40000190U);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81880001U);
            r_rsip_func_sub001(0x02090021U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2e_func100_008[] =
            {
                BSWAP_32BIG_C(0x0803580eU), BSWAP_32BIG_C(0x2f032b61U), BSWAP_32BIG_C(0xf26032adU), BSWAP_32BIG_C(
                    0x1de62c9aU),
            };
            r_rsip_func100(Param_p2e_func100_008);
            WR1_PROG(REG_1438H, 0x400001C0U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2e_func102_003[] =
            {
                BSWAP_32BIG_C(0xc437d293U), BSWAP_32BIG_C(0xb9df9b4cU), BSWAP_32BIG_C(0x07964bceU), BSWAP_32BIG_C(
                    0xaed5ceb6U),
            };
            r_rsip_func102(Param_p2e_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
