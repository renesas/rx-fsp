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

rsip_ret_t r_rsip_pb9i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00b90001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000b9U);

    static const uint32_t Param_pb9i_func101_001[] =
    {
        BSWAP_32BIG_C(0x71085becU), BSWAP_32BIG_C(0x9365feeeU), BSWAP_32BIG_C(0xc6c88d0aU), BSWAP_32BIG_C(0x337d7cbcU),
    };
    r_rsip_func101(Param_pb9i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000009U);

    r_rsip_func_sub009(0x000000b9U);

    static const uint32_t Param_pb9i_func101_002[] =
    {
        BSWAP_32BIG_C(0xda30088aU), BSWAP_32BIG_C(0xff727cddU), BSWAP_32BIG_C(0xe1814cf5U), BSWAP_32BIG_C(0x0508a7caU),
    };
    r_rsip_func101(Param_pb9i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xf7009d07U);

    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1608H, 0x8090001fU);
    for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pb9i_func100_001[] =
    {
        BSWAP_32BIG_C(0x316c228dU), BSWAP_32BIG_C(0x2f40a43cU), BSWAP_32BIG_C(0x82b47056U), BSWAP_32BIG_C(0x6f3e90b5U),
    };
    r_rsip_func100(Param_pb9i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb9i_func102_001[] =
        {
            BSWAP_32BIG_C(0xf5b3f406U), BSWAP_32BIG_C(0xe79f4342U), BSWAP_32BIG_C(0x903e0c89U), BSWAP_32BIG_C(
                0x4847eb8dU),
        };
        r_rsip_func102(Param_pb9i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000020U);

        r_rsip_func424();

        r_rsip_func_sub021(0x000037dfU, 0x0000b400U, 0x00000010U, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000030U);
        r_rsip_func424();

        WR1_PROG(REG_1600H, 0x000013feU);

        r_rsip_func_sub006(0x38008be0U, 0xb2d02d18U, 0x00A60000U);

        static const uint32_t Param_pb9i_func100_002[] =
        {
            BSWAP_32BIG_C(0x18f0d3a4U), BSWAP_32BIG_C(0x836a6438U), BSWAP_32BIG_C(0x0d5ce534U), BSWAP_32BIG_C(
                0xd30f7bf4U),
        };
        r_rsip_func100(Param_pb9i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pb9i_func102_002[] =
            {
                BSWAP_32BIG_C(0x9a116f44U), BSWAP_32BIG_C(0xf9a5b105U), BSWAP_32BIG_C(0x6e2b765fU), BSWAP_32BIG_C(
                    0xfb4a5e5dU),
            };
            r_rsip_func102(Param_pb9i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pb9i_func100_003[] =
            {
                BSWAP_32BIG_C(0x15a90889U), BSWAP_32BIG_C(0x5ce043d0U), BSWAP_32BIG_C(0xdafc200cU), BSWAP_32BIG_C(
                    0x0e5ae696U),
            };
            r_rsip_func100(Param_pb9i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb9i_func100_004[] =
            {
                BSWAP_32BIG_C(0x94b0b612U), BSWAP_32BIG_C(0x47f41f98U), BSWAP_32BIG_C(0x555f5dd4U), BSWAP_32BIG_C(
                    0xc41bc705U),
            };
            r_rsip_func100(Param_pb9i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb9i_func100_005[] =
            {
                BSWAP_32BIG_C(0xd068b9f1U), BSWAP_32BIG_C(0x5e8917f7U), BSWAP_32BIG_C(0x0d8866e5U), BSWAP_32BIG_C(
                    0x34e57659U),
            };
            r_rsip_func100(Param_pb9i_func100_005);
            WR1_PROG(REG_1824H, 0x080000a5U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb9i_func100_006[] =
            {
                BSWAP_32BIG_C(0xe8dc42f3U), BSWAP_32BIG_C(0x6192a3caU), BSWAP_32BIG_C(0x1f25f301U), BSWAP_32BIG_C(
                    0x4bfa589bU),
            };
            r_rsip_func100(Param_pb9i_func100_006);
            WR1_PROG(REG_1824H, 0x080000b5U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0a028045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
