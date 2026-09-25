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

rsip_ret_t r_rsip_p50i (const uint32_t InData_Cmd[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00500001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00005001U);

    static const uint32_t Param_p50i_func101_001[] =
    {
        BSWAP_32BIG_C(0xabfae46dU), BSWAP_32BIG_C(0x9e32deb0U), BSWAP_32BIG_C(0x769aa97aU), BSWAP_32BIG_C(0x16dd1e62U),
    };
    r_rsip_func101(Param_p50i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x00005001U);

    static const uint32_t Param_p50i_func101_002[] =
    {
        BSWAP_32BIG_C(0x950e41c0U), BSWAP_32BIG_C(0xcba404caU), BSWAP_32BIG_C(0xed857470U), BSWAP_32BIG_C(0xb29e0359U),
    };
    r_rsip_func101(Param_p50i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p50i_func100_001[] =
    {
        BSWAP_32BIG_C(0x3c0249aaU), BSWAP_32BIG_C(0x6ef17540U), BSWAP_32BIG_C(0x3e4fa262U), BSWAP_32BIG_C(0xe08df6e5U),
    };
    r_rsip_func100(Param_p50i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p50i_func100_002[] =
    {
        BSWAP_32BIG_C(0x959571beU), BSWAP_32BIG_C(0xe7844558U), BSWAP_32BIG_C(0x331fc1caU), BSWAP_32BIG_C(0x45efdfb3U),
    };
    r_rsip_func100(Param_p50i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p50i_func100_003[] =
    {
        BSWAP_32BIG_C(0xae552e59U), BSWAP_32BIG_C(0xcde775ecU), BSWAP_32BIG_C(0x80c20004U), BSWAP_32BIG_C(0xe381fc97U),
    };
    r_rsip_func100(Param_p50i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p50i_func102_001[] =
        {
            BSWAP_32BIG_C(0x21d237aeU), BSWAP_32BIG_C(0xe1c10c68U), BSWAP_32BIG_C(0x6b287c80U), BSWAP_32BIG_C(
                0xbe81f3dcU),
        };
        r_rsip_func102(Param_p50i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub006(0x3c00a880U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p50i_func100_004[] =
        {
            BSWAP_32BIG_C(0x1d35b450U), BSWAP_32BIG_C(0x5bec56b6U), BSWAP_32BIG_C(0xda859f3cU), BSWAP_32BIG_C(
                0xfa5a591bU),
        };
        r_rsip_func100(Param_p50i_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x000008a5U);

            r_rsip_func_sub006(0x3c00a880U, 0x00000004U, 0x00A60000U);

            static const uint32_t Param_p50i_func100_005[] =
            {
                BSWAP_32BIG_C(0x72636a9fU), BSWAP_32BIG_C(0x2c0ee0ffU), BSWAP_32BIG_C(0x92fba838U), BSWAP_32BIG_C(
                    0x531c44a6U),
            };
            r_rsip_func100(Param_p50i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100a0U);
                WR1_PROG(REG_1420H, InData_IVType[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p50i_func101_003[] =
                {
                    BSWAP_32BIG_C(0x3f059b1eU), BSWAP_32BIG_C(0x050a7cf2U), BSWAP_32BIG_C(0xde037e5dU), BSWAP_32BIG_C(
                        0x08117ff2U),
                };
                r_rsip_func101(Param_p50i_func101_003);
            }

            r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

            static const uint32_t Param_p50i_func100_006[] =
            {
                BSWAP_32BIG_C(0xde20e2c7U), BSWAP_32BIG_C(0xbac4e414U), BSWAP_32BIG_C(0xeb40ee82U), BSWAP_32BIG_C(
                    0xdf3d2d4dU),
            };
            r_rsip_func100(Param_p50i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_1420H, &InData_IV[0]);

                static const uint32_t Param_p50i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xfdbeaf28U), BSWAP_32BIG_C(0x3638d547U), BSWAP_32BIG_C(0x3aae7265U), BSWAP_32BIG_C(
                        0xf856dd10U),
                };
                r_rsip_func101(Param_p50i_func101_004);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_IV[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub009(0x00005002U);

                static const uint32_t Param_p50i_func101_005[] =
                {
                    BSWAP_32BIG_C(0xb18c91faU), BSWAP_32BIG_C(0x96f85758U), BSWAP_32BIG_C(0x99d44f8fU), BSWAP_32BIG_C(
                        0xfe7f99b6U),
                };
                r_rsip_func101(Param_p50i_func101_005);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01b98ba2U);

                r_rsip_func_sub009(0x00005002U);

                static const uint32_t Param_p50i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x30e788a2U), BSWAP_32BIG_C(0xd1fa704fU), BSWAP_32BIG_C(0x53ace3dfU), BSWAP_32BIG_C(
                        0xe7db16a9U),
                };
                r_rsip_func101(Param_p50i_func101_006);
                r_rsip_func044();

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
                WR4_ADDR(REG_1420H, &InData_IV[1]);

                WR1_PROG(REG_1824H, 0x08000045U);
                r_rsip_func_sub001(0x00420011U);
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_IV[5]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_p50i_func100_007[] =
                {
                    BSWAP_32BIG_C(0xab794dbdU), BSWAP_32BIG_C(0x29f27b3bU), BSWAP_32BIG_C(0x2d07e14cU), BSWAP_32BIG_C(
                        0xbfdcd083U),
                };
                r_rsip_func100(Param_p50i_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p50i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0xd76a7f39U), BSWAP_32BIG_C(0xbc7a18ccU), BSWAP_32BIG_C(0xaddaeb42U),
                        BSWAP_32BIG_C(0x42b14ce3U),
                    };
                    r_rsip_func102(Param_p50i_func102_002);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p50i_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x3a4ade7aU), BSWAP_32BIG_C(0x45375f57U), BSWAP_32BIG_C(0x115e500aU),
                        BSWAP_32BIG_C(0x6e3cc198U),
                    };
                    r_rsip_func101(Param_p50i_func101_007);
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
