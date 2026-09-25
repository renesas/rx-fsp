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

rsip_ret_t r_rsip_pc2i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00c20001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000c2U);

    static const uint32_t Param_pc2i_func101_001[] =
    {
        BSWAP_32BIG_C(0x557c2066U), BSWAP_32BIG_C(0x99fbebcdU), BSWAP_32BIG_C(0xa28b15daU), BSWAP_32BIG_C(0x25539935U),
    };
    r_rsip_func101(Param_pc2i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000009U);

    r_rsip_func_sub009(0x000000c2U);

    static const uint32_t Param_pc2i_func101_002[] =
    {
        BSWAP_32BIG_C(0x15bb0012U), BSWAP_32BIG_C(0xcebd646cU), BSWAP_32BIG_C(0x7eb5d031U), BSWAP_32BIG_C(0xf402bfb1U),
    };
    r_rsip_func101(Param_pc2i_func101_002);
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

    static const uint32_t Param_pc2i_func100_001[] =
    {
        BSWAP_32BIG_C(0x03b35c23U), BSWAP_32BIG_C(0x9244fbb1U), BSWAP_32BIG_C(0xd60f3fe5U), BSWAP_32BIG_C(0xe96564a1U),
    };
    r_rsip_func100(Param_pc2i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pc2i_func102_001[] =
        {
            BSWAP_32BIG_C(0x1ea7a0bbU), BSWAP_32BIG_C(0x5a7dc2d5U), BSWAP_32BIG_C(0x2221ac7fU), BSWAP_32BIG_C(
                0x04722c18U),
        };
        r_rsip_func102(Param_pc2i_func102_001);
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

        static const uint32_t Param_pc2i_func100_002[] =
        {
            BSWAP_32BIG_C(0x5ca0ebf4U), BSWAP_32BIG_C(0x89cf1c53U), BSWAP_32BIG_C(0xc56c0d14U), BSWAP_32BIG_C(
                0xe9ed2f1bU),
        };
        r_rsip_func100(Param_pc2i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pc2i_func102_002[] =
            {
                BSWAP_32BIG_C(0x03eb6a61U), BSWAP_32BIG_C(0x432eddeaU), BSWAP_32BIG_C(0x1c53c1a2U), BSWAP_32BIG_C(
                    0x0e0b096dU),
            };
            r_rsip_func102(Param_pc2i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pc2i_func100_003[] =
            {
                BSWAP_32BIG_C(0x1d87a219U), BSWAP_32BIG_C(0x91c42213U), BSWAP_32BIG_C(0x895dc94cU), BSWAP_32BIG_C(
                    0x088db13fU),
            };
            r_rsip_func100(Param_pc2i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pc2i_func100_004[] =
            {
                BSWAP_32BIG_C(0x7b50daa3U), BSWAP_32BIG_C(0x942ccb6eU), BSWAP_32BIG_C(0x60dde11dU), BSWAP_32BIG_C(
                    0x347a3b2cU),
            };
            r_rsip_func100(Param_pc2i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pc2i_func100_005[] =
            {
                BSWAP_32BIG_C(0xf1750355U), BSWAP_32BIG_C(0x45513f1cU), BSWAP_32BIG_C(0x0656939dU), BSWAP_32BIG_C(
                    0xf283eab7U),
            };
            r_rsip_func100(Param_pc2i_func100_005);
            WR1_PROG(REG_1824H, 0x080000a5U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pc2i_func100_006[] =
            {
                BSWAP_32BIG_C(0xa88a546aU), BSWAP_32BIG_C(0x2f067f0cU), BSWAP_32BIG_C(0xc877ff45U), BSWAP_32BIG_C(
                    0x6129be5eU),
            };
            r_rsip_func100(Param_pc2i_func100_006);
            WR1_PROG(REG_1824H, 0x080000b5U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0a028045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
