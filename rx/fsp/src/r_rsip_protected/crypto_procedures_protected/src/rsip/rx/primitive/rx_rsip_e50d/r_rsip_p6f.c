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

rsip_ret_t r_rsip_p6f (const uint32_t InData_LC[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_InstData[],
                       uint32_t       OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x006f0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    r_rsip_func049(InData_Cmd);

    r_rsip_func_sub006(0x3420a800U, 0x0000000aU, 0x00A60000U);

    r_rsip_func_sub006(0x38008800U, 0x00000002U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000003U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000005U, 0x00260000U);

    r_rsip_func_sub006(0x3420a880U, 0x00000005U, 0x00260000U);

    r_rsip_func_sub021(0x00000bffU, 0x3000a880U, 0x00000033U, 0x00010020U);
    r_rsip_func_sub021(0x38008880U, 0x000000feU, 0x200053e0U, 0x00000080U);

    r_rsip_func_sub017(0x38000fffU, 0x00A60000U);

    static const uint32_t Param_p6f_func100_001[] =
    {
        BSWAP_32BIG_C(0xf5e285c3U), BSWAP_32BIG_C(0x636ea8c2U), BSWAP_32BIG_C(0x2fa46aa2U), BSWAP_32BIG_C(0x9cbb1319U),
    };
    r_rsip_func100(Param_p6f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p6f_func102_001[] =
        {
            BSWAP_32BIG_C(0x5e50c408U), BSWAP_32BIG_C(0x76c23586U), BSWAP_32BIG_C(0xbca7156cU), BSWAP_32BIG_C(
                0x3d253b59U),
        };
        r_rsip_func102(Param_p6f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, S_INST2[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x0000006fU);

        static const uint32_t Param_p6f_func101_001[] =
        {
            BSWAP_32BIG_C(0xcafb7949U), BSWAP_32BIG_C(0x87aa117fU), BSWAP_32BIG_C(0x63270636U), BSWAP_32BIG_C(
                0x3a03b2ccU),
        };
        r_rsip_func101(Param_p6f_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x000000ffU);

        r_rsip_func_sub009(0x0000006fU);

        static const uint32_t Param_p6f_func101_002[] =
        {
            BSWAP_32BIG_C(0x0a7b0773U), BSWAP_32BIG_C(0x147a0477U), BSWAP_32BIG_C(0x9dcb05dfU), BSWAP_32BIG_C(
                0x8b878f28U),
        };
        r_rsip_func101(Param_p6f_func101_002);
        r_rsip_func044();

        static const uint32_t Param_p6f_func100_002[] =
        {
            BSWAP_32BIG_C(0xd48b3d01U), BSWAP_32BIG_C(0x8cb83269U), BSWAP_32BIG_C(0xd1e45b65U), BSWAP_32BIG_C(
                0xe6fcedf4U),
        };
        r_rsip_func100(Param_p6f_func100_002);
        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_1420H, &S_INST2[0 + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &S_INST2[0 + 5]);

        WR1_PROG(REG_1824H, 0x08000085U);
        r_rsip_func_sub001(0x00420011U);

        static const uint32_t Param_p6f_func100_003[] =
        {
            BSWAP_32BIG_C(0xf3d036d3U), BSWAP_32BIG_C(0xd0b1f2caU), BSWAP_32BIG_C(0xe8e1ea11U), BSWAP_32BIG_C(
                0x99ffac70U),
        };
        r_rsip_func100(Param_p6f_func100_003);
        WR1_PROG(REG_1824H, 0x08000095U);
        r_rsip_func_sub001(0x00420011U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &S_INST2[0 + 9]);

        WR1_PROG(REG_1A24H, 0x8c100005U);
        r_rsip_func_sub001(0x00820011U);

        r_rsip_func_sub003(0x80010380U, 0x0000006fU);

        static const uint32_t Param_p6f_func101_003[] =
        {
            BSWAP_32BIG_C(0x87ca4044U), BSWAP_32BIG_C(0xe5c758c7U), BSWAP_32BIG_C(0x3d7a923dU), BSWAP_32BIG_C(
                0x38037aa7U),
        };
        r_rsip_func101(Param_p6f_func101_003);
        r_rsip_func057(InData_IV, InData_InstData, OutData_KeyIndex);

        static const uint32_t Param_p6f_func100_004[] =
        {
            BSWAP_32BIG_C(0x7eef47acU), BSWAP_32BIG_C(0x30fc1189U), BSWAP_32BIG_C(0x4c3f58c8U), BSWAP_32BIG_C(
                0x6b27425aU),
        };
        r_rsip_func100(Param_p6f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p6f_func102_002[] =
            {
                BSWAP_32BIG_C(0x3a39b81fU), BSWAP_32BIG_C(0x16d65cc8U), BSWAP_32BIG_C(0xa95b847dU), BSWAP_32BIG_C(
                    0x16e14163U),
            };
            r_rsip_func102(Param_p6f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p6f_func100_005[] =
            {
                BSWAP_32BIG_C(0x566efd01U), BSWAP_32BIG_C(0xfbd05d82U), BSWAP_32BIG_C(0x38a88ec3U), BSWAP_32BIG_C(
                    0xf1a3f4e9U),
            };
            r_rsip_func100(Param_p6f_func100_005);
            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

            static const uint32_t Param_p6f_func102_003[] =
            {
                BSWAP_32BIG_C(0x396cec47U), BSWAP_32BIG_C(0x740c5117U), BSWAP_32BIG_C(0xb8b5a577U), BSWAP_32BIG_C(
                    0xfc53a98aU),
            };
            r_rsip_func102(Param_p6f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
