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

rsip_ret_t r_rsip_pb3i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00b30001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000b3U);

    static const uint32_t Param_pb3i_func101_001[] =
    {
        BSWAP_32BIG_C(0x0bf54709U), BSWAP_32BIG_C(0x74337edfU), BSWAP_32BIG_C(0x9c3d7e38U), BSWAP_32BIG_C(0x560bc873U),
    };
    r_rsip_func101(Param_pb3i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000008U);

    r_rsip_func_sub009(0x000000b3U);

    static const uint32_t Param_pb3i_func101_002[] =
    {
        BSWAP_32BIG_C(0xf6a9ef91U), BSWAP_32BIG_C(0xfa75e1e8U), BSWAP_32BIG_C(0x68b8e3e7U), BSWAP_32BIG_C(0xe3b835ceU),
    };
    r_rsip_func101(Param_pb3i_func101_002);
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

    static const uint32_t Param_pb3i_func100_001[] =
    {
        BSWAP_32BIG_C(0x5af54802U), BSWAP_32BIG_C(0x8a817e84U), BSWAP_32BIG_C(0x62f23c6eU), BSWAP_32BIG_C(0xf2d4fd6dU),
    };
    r_rsip_func100(Param_pb3i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb3i_func102_001[] =
        {
            BSWAP_32BIG_C(0x16aaf9aaU), BSWAP_32BIG_C(0x6a8ef64dU), BSWAP_32BIG_C(0x732efedcU), BSWAP_32BIG_C(
                0xf4cc90bdU),
        };
        r_rsip_func102(Param_pb3i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000010U);

        r_rsip_func424();

        r_rsip_func_sub006(0x38008be0U, 0xb2d02d18U, 0x00A60000U);

        static const uint32_t Param_pb3i_func100_002[] =
        {
            BSWAP_32BIG_C(0x854bc48bU), BSWAP_32BIG_C(0xaa8779baU), BSWAP_32BIG_C(0x9424d247U), BSWAP_32BIG_C(
                0x224d918cU),
        };
        r_rsip_func100(Param_pb3i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pb3i_func102_002[] =
            {
                BSWAP_32BIG_C(0xc48b1666U), BSWAP_32BIG_C(0xebd7f186U), BSWAP_32BIG_C(0x5c328768U), BSWAP_32BIG_C(
                    0x26e4a484U),
            };
            r_rsip_func102(Param_pb3i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pb3i_func100_003[] =
            {
                BSWAP_32BIG_C(0x0da536f0U), BSWAP_32BIG_C(0x8732cd29U), BSWAP_32BIG_C(0x1876ca73U), BSWAP_32BIG_C(
                    0xc8a1c3e9U),
            };
            r_rsip_func100(Param_pb3i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8188001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb3i_func100_004[] =
            {
                BSWAP_32BIG_C(0xd208a606U), BSWAP_32BIG_C(0x03f21a22U), BSWAP_32BIG_C(0xea89f42bU), BSWAP_32BIG_C(
                    0x350fc85cU),
            };
            r_rsip_func100(Param_pb3i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub020(0x000003c1U, 0x0a010045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
