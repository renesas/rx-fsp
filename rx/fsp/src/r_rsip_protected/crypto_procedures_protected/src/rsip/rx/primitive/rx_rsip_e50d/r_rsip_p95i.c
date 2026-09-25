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

rsip_ret_t r_rsip_p95i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00950001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00009501U);

    static const uint32_t Param_p95i_func101_001[] =
    {
        BSWAP_32BIG_C(0xdd9dab43U), BSWAP_32BIG_C(0x740689d5U), BSWAP_32BIG_C(0x947ac09cU), BSWAP_32BIG_C(0x5588e3d8U),
    };
    r_rsip_func101(Param_p95i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x00009501U);

    static const uint32_t Param_p95i_func101_002[] =
    {
        BSWAP_32BIG_C(0x71aa9ad4U), BSWAP_32BIG_C(0xd4a1434bU), BSWAP_32BIG_C(0x5a8a4a23U), BSWAP_32BIG_C(0xf8883303U),
    };
    r_rsip_func101(Param_p95i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p95i_func100_001[] =
    {
        BSWAP_32BIG_C(0xe4bb3412U), BSWAP_32BIG_C(0x66bb8ae7U), BSWAP_32BIG_C(0x2969e943U), BSWAP_32BIG_C(0x7a0fd3c7U),
    };
    r_rsip_func100(Param_p95i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p95i_func100_002[] =
    {
        BSWAP_32BIG_C(0xf5778e56U), BSWAP_32BIG_C(0xb25f360fU), BSWAP_32BIG_C(0x21d477ecU), BSWAP_32BIG_C(0x936d8b4bU),
    };
    r_rsip_func100(Param_p95i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p95i_func102_001[] =
        {
            BSWAP_32BIG_C(0xd2a3854fU), BSWAP_32BIG_C(0x87dfad5bU), BSWAP_32BIG_C(0x4771aff9U), BSWAP_32BIG_C(
                0xa06984dbU),
        };
        r_rsip_func102(Param_p95i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010080U);
        WR1_PROG(REG_1420H, InData_IVType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000c84U, 0x00260000U);

        static const uint32_t Param_p95i_func100_003[] =
        {
            BSWAP_32BIG_C(0x61e48051U), BSWAP_32BIG_C(0x845aea61U), BSWAP_32BIG_C(0xb2aaf2a0U), BSWAP_32BIG_C(
                0x1246194aU),
        };
        r_rsip_func100(Param_p95i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p95i_func101_003[] =
            {
                BSWAP_32BIG_C(0xf9d75982U), BSWAP_32BIG_C(0x1804248eU), BSWAP_32BIG_C(0x2ab7c335U), BSWAP_32BIG_C(
                    0x18124772U),
            };
            r_rsip_func101(Param_p95i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00009502U);

            static const uint32_t Param_p95i_func101_004[] =
            {
                BSWAP_32BIG_C(0x3c5a548fU), BSWAP_32BIG_C(0x23f2e3aaU), BSWAP_32BIG_C(0xb874e572U), BSWAP_32BIG_C(
                    0x29f74f4aU),
            };
            r_rsip_func101(Param_p95i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x00009502U);

            static const uint32_t Param_p95i_func101_005[] =
            {
                BSWAP_32BIG_C(0x27699a56U), BSWAP_32BIG_C(0xcb204ef0U), BSWAP_32BIG_C(0x52dfc9efU), BSWAP_32BIG_C(
                    0xe2f4beaaU),
            };
            r_rsip_func101(Param_p95i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1824H, 0x08000045U);
            r_rsip_func_sub001(0x00420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p95i_func100_004[] =
            {
                BSWAP_32BIG_C(0xc01797c5U), BSWAP_32BIG_C(0xf1f075b4U), BSWAP_32BIG_C(0xea1bfd2eU), BSWAP_32BIG_C(
                    0x57f6f720U),
            };
            r_rsip_func100(Param_p95i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p95i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x365dc81dU), BSWAP_32BIG_C(0xc5f0cf92U), BSWAP_32BIG_C(0xf211a151U), BSWAP_32BIG_C(
                        0xdfadf479U),
                };
                r_rsip_func102(Param_p95i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p95i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x1996466eU), BSWAP_32BIG_C(0x00daecdfU), BSWAP_32BIG_C(0x81019076U), BSWAP_32BIG_C(
                        0x862cb5d9U),
                };
                r_rsip_func101(Param_p95i_func101_006);
            }
        }

        WR1_PROG(REG_182CH, 0x00000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_p95i_func101_007[] =
        {
            BSWAP_32BIG_C(0xdfa2e426U), BSWAP_32BIG_C(0x83fbf7b9U), BSWAP_32BIG_C(0xdd27528aU), BSWAP_32BIG_C(
                0x47986766U),
        };
        r_rsip_func101(Param_p95i_func101_007);

        return RSIP_RET_PASS;
    }
}
