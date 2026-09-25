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

rsip_ret_t r_rsip_p47i (const uint32_t InData_Cmd[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00470001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00004701U);

    static const uint32_t Param_p47i_func101_001[] =
    {
        BSWAP_32BIG_C(0xc8bad4afU), BSWAP_32BIG_C(0x30165175U), BSWAP_32BIG_C(0xb0ef075fU), BSWAP_32BIG_C(0xe42355cbU),
    };
    r_rsip_func101(Param_p47i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x00004701U);

    static const uint32_t Param_p47i_func101_002[] =
    {
        BSWAP_32BIG_C(0xaeaec610U), BSWAP_32BIG_C(0x15857d9fU), BSWAP_32BIG_C(0x92143dd2U), BSWAP_32BIG_C(0x885ec9efU),
    };
    r_rsip_func101(Param_p47i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p47i_func100_001[] =
    {
        BSWAP_32BIG_C(0x4d76962aU), BSWAP_32BIG_C(0x1b03e11bU), BSWAP_32BIG_C(0xcd6db45bU), BSWAP_32BIG_C(0x45df1d5aU),
    };
    r_rsip_func100(Param_p47i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p47i_func100_002[] =
    {
        BSWAP_32BIG_C(0x7821ff83U), BSWAP_32BIG_C(0x5723e963U), BSWAP_32BIG_C(0x2021b4f4U), BSWAP_32BIG_C(0x997bfee7U),
    };
    r_rsip_func100(Param_p47i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p47i_func102_001[] =
        {
            BSWAP_32BIG_C(0x8d7853e4U), BSWAP_32BIG_C(0x821cfdf4U), BSWAP_32BIG_C(0x33116c91U), BSWAP_32BIG_C(
                0xd6e02a7bU),
        };
        r_rsip_func102(Param_p47i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub006(0x3c00a880U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p47i_func100_003[] =
        {
            BSWAP_32BIG_C(0x384b772eU), BSWAP_32BIG_C(0x4949e5cdU), BSWAP_32BIG_C(0xd0cbd809U), BSWAP_32BIG_C(
                0x4192b89aU),
        };
        r_rsip_func100(Param_p47i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x000008a5U);

            r_rsip_func_sub006(0x3c00a880U, 0x00000004U, 0x00A60000U);

            static const uint32_t Param_p47i_func100_004[] =
            {
                BSWAP_32BIG_C(0x68c9bfbbU), BSWAP_32BIG_C(0xc1392fc7U), BSWAP_32BIG_C(0xc64a8746U), BSWAP_32BIG_C(
                    0x212857b2U),
            };
            r_rsip_func100(Param_p47i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100a0U);
                WR1_PROG(REG_1420H, InData_IVType[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p47i_func101_003[] =
                {
                    BSWAP_32BIG_C(0x09a6520aU), BSWAP_32BIG_C(0xdb51c8fbU), BSWAP_32BIG_C(0x62fe1db5U), BSWAP_32BIG_C(
                        0x92cdc608U),
                };
                r_rsip_func101(Param_p47i_func101_003);
            }

            r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

            static const uint32_t Param_p47i_func100_005[] =
            {
                BSWAP_32BIG_C(0x1f72e68aU), BSWAP_32BIG_C(0x93cc169dU), BSWAP_32BIG_C(0xede29298U), BSWAP_32BIG_C(
                    0xc74e7e98U),
            };
            r_rsip_func100(Param_p47i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_1420H, &InData_IV[0]);

                static const uint32_t Param_p47i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x8b6a3a53U), BSWAP_32BIG_C(0x2cc3d38eU), BSWAP_32BIG_C(0xf9542002U), BSWAP_32BIG_C(
                        0x69f47ba9U),
                };
                r_rsip_func101(Param_p47i_func101_004);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_IV[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub009(0x00004702U);

                static const uint32_t Param_p47i_func101_005[] =
                {
                    BSWAP_32BIG_C(0xea81e879U), BSWAP_32BIG_C(0xd201e174U), BSWAP_32BIG_C(0xca7c647bU), BSWAP_32BIG_C(
                        0xe4fa7578U),
                };
                r_rsip_func101(Param_p47i_func101_005);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01b98ba2U);

                r_rsip_func_sub009(0x00004702U);

                static const uint32_t Param_p47i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x9cc153c9U), BSWAP_32BIG_C(0xfb9b3c76U), BSWAP_32BIG_C(0xc100748fU), BSWAP_32BIG_C(
                        0x13335a7eU),
                };
                r_rsip_func101(Param_p47i_func101_006);
                r_rsip_func044();

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
                WR4_ADDR(REG_1420H, &InData_IV[1]);

                WR1_PROG(REG_1824H, 0x08000045U);
                r_rsip_func_sub001(0x00420011U);
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_IV[5]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_p47i_func100_006[] =
                {
                    BSWAP_32BIG_C(0x97fde7f6U), BSWAP_32BIG_C(0xaf140b5cU), BSWAP_32BIG_C(0xcdaa627cU), BSWAP_32BIG_C(
                        0xf1b7066dU),
                };
                r_rsip_func100(Param_p47i_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p47i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0x97eb2adeU), BSWAP_32BIG_C(0x2fc63b72U), BSWAP_32BIG_C(0x854384d2U),
                        BSWAP_32BIG_C(0x62b387acU),
                    };
                    r_rsip_func102(Param_p47i_func102_002);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p47i_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xca34e966U), BSWAP_32BIG_C(0x92f95b74U), BSWAP_32BIG_C(0x20aeb682U),
                        BSWAP_32BIG_C(0xa07b2d5dU),
                    };
                    r_rsip_func101(Param_p47i_func101_007);
                }
            }
        }

        r_rsip_func_sub021(0x0c003080U, 0x2000b4e0U, 0x0a000100U, 0x0c003080U);
        r_rsip_func_sub021(0x2000b4e0U, 0x0a000108U, 0x0c003080U, 0x2000b4e0U);
        r_rsip_func_sub021(0x0e000500U, 0x0c003080U, 0x2000b4e0U, 0x09000908U);

        r_rsip_func_sub021(0x0c00a880U, 0xfffffffcU, 0x2000b4e0U, 0x07000d00U);

        return RSIP_RET_PASS;
    }
}
