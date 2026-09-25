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

rsip_ret_t r_rsip_pb6i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00b60001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000b6U);

    static const uint32_t Param_pb6i_func101_001[] =
    {
        BSWAP_32BIG_C(0x7804a7fcU), BSWAP_32BIG_C(0xbb77f073U), BSWAP_32BIG_C(0x27391769U), BSWAP_32BIG_C(0x76e73e29U),
    };
    r_rsip_func101(Param_pb6i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000008U);

    r_rsip_func_sub009(0x000000b6U);

    static const uint32_t Param_pb6i_func101_002[] =
    {
        BSWAP_32BIG_C(0xe446bfc6U), BSWAP_32BIG_C(0xbfe42aa8U), BSWAP_32BIG_C(0x49c8012cU), BSWAP_32BIG_C(0xfe8534aeU),
    };
    r_rsip_func101(Param_pb6i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1608H, 0x8088001fU);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pb6i_func100_001[] =
    {
        BSWAP_32BIG_C(0x30328403U), BSWAP_32BIG_C(0xf857fff1U), BSWAP_32BIG_C(0x2fb3e2b6U), BSWAP_32BIG_C(0xf57d1ff5U),
    };
    r_rsip_func100(Param_pb6i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb6i_func102_001[] =
        {
            BSWAP_32BIG_C(0x86f0cf29U), BSWAP_32BIG_C(0x121c5cfaU), BSWAP_32BIG_C(0x6b31efdaU), BSWAP_32BIG_C(
                0x32c95361U),
        };
        r_rsip_func102(Param_pb6i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000010U);

        r_rsip_func424();

        r_rsip_func_sub006(0x38008be0U, 0xb2d02d18U, 0x00A60000U);

        static const uint32_t Param_pb6i_func100_002[] =
        {
            BSWAP_32BIG_C(0xb84e6ad3U), BSWAP_32BIG_C(0xa226a13eU), BSWAP_32BIG_C(0xef2f714fU), BSWAP_32BIG_C(
                0xad84b6f4U),
        };
        r_rsip_func100(Param_pb6i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pb6i_func102_002[] =
            {
                BSWAP_32BIG_C(0xa5e3b8b3U), BSWAP_32BIG_C(0x7078291dU), BSWAP_32BIG_C(0xc0bdaf7dU), BSWAP_32BIG_C(
                    0xd57727bfU),
            };
            r_rsip_func102(Param_pb6i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pb6i_func100_003[] =
            {
                BSWAP_32BIG_C(0x830b8528U), BSWAP_32BIG_C(0xc75e3f3aU), BSWAP_32BIG_C(0x26c79ee1U), BSWAP_32BIG_C(
                    0x2c61ae1aU),
            };
            r_rsip_func100(Param_pb6i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8188001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb6i_func100_004[] =
            {
                BSWAP_32BIG_C(0x173256e0U), BSWAP_32BIG_C(0xf188114eU), BSWAP_32BIG_C(0x06a3c084U), BSWAP_32BIG_C(
                    0xe44e34ebU),
            };
            r_rsip_func100(Param_pb6i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub020(0x000003c1U, 0x0a010045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
