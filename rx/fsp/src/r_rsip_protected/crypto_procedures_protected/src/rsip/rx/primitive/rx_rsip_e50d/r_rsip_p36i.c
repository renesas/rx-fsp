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

rsip_ret_t r_rsip_p36i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00360001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00003601U);

    static const uint32_t Param_p36i_func101_001[] =
    {
        BSWAP_32BIG_C(0x5145148fU), BSWAP_32BIG_C(0xa548416aU), BSWAP_32BIG_C(0x79e0ead4U), BSWAP_32BIG_C(0x25ee7183U),
    };
    r_rsip_func101(Param_p36i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x00003601U);

    static const uint32_t Param_p36i_func101_002[] =
    {
        BSWAP_32BIG_C(0x7a747546U), BSWAP_32BIG_C(0xbd6d491dU), BSWAP_32BIG_C(0x14794394U), BSWAP_32BIG_C(0xd7a53fd8U),
    };
    r_rsip_func101(Param_p36i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p36i_func100_001[] =
    {
        BSWAP_32BIG_C(0x68111e4eU), BSWAP_32BIG_C(0xbc9e534fU), BSWAP_32BIG_C(0xac0c86c6U), BSWAP_32BIG_C(0x6dd5fcbbU),
    };
    r_rsip_func100(Param_p36i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p36i_func100_002[] =
    {
        BSWAP_32BIG_C(0xb84aaa2aU), BSWAP_32BIG_C(0x8d98ee29U), BSWAP_32BIG_C(0xcdf403c3U), BSWAP_32BIG_C(0x9e482551U),
    };
    r_rsip_func100(Param_p36i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p36i_func100_003[] =
    {
        BSWAP_32BIG_C(0xc87bd6feU), BSWAP_32BIG_C(0x16d028f5U), BSWAP_32BIG_C(0x6e7462e7U), BSWAP_32BIG_C(0x155470ccU),
    };
    r_rsip_func100(Param_p36i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p36i_func102_001[] =
        {
            BSWAP_32BIG_C(0x365a7777U), BSWAP_32BIG_C(0xc522bf18U), BSWAP_32BIG_C(0x5c7843bbU), BSWAP_32BIG_C(
                0x807fbb40U),
        };
        r_rsip_func102(Param_p36i_func102_001);
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

        static const uint32_t Param_p36i_func100_004[] =
        {
            BSWAP_32BIG_C(0x06ec27efU), BSWAP_32BIG_C(0x011d54c9U), BSWAP_32BIG_C(0x19ad37cbU), BSWAP_32BIG_C(
                0xbd34e51cU),
        };
        r_rsip_func100(Param_p36i_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000003c7U, 0x80040080U);
            r_rsip_func_sub042(InData_IV);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p36i_func101_003[] =
            {
                BSWAP_32BIG_C(0x6cc9f3d9U), BSWAP_32BIG_C(0xe9fc9463U), BSWAP_32BIG_C(0xf70fa426U), BSWAP_32BIG_C(
                    0x45b86d75U),
            };
            r_rsip_func101(Param_p36i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00003602U);

            static const uint32_t Param_p36i_func101_004[] =
            {
                BSWAP_32BIG_C(0x74fed583U), BSWAP_32BIG_C(0x8ba5dcb1U), BSWAP_32BIG_C(0x18e71bffU), BSWAP_32BIG_C(
                    0x0b06a6afU),
            };
            r_rsip_func101(Param_p36i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x00003602U);

            static const uint32_t Param_p36i_func101_005[] =
            {
                BSWAP_32BIG_C(0x1d60699dU), BSWAP_32BIG_C(0x353879beU), BSWAP_32BIG_C(0xb1d75021U), BSWAP_32BIG_C(
                    0x002904faU),
            };
            r_rsip_func101(Param_p36i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p36i_func100_005[] =
            {
                BSWAP_32BIG_C(0x6500ecf2U), BSWAP_32BIG_C(0x51fbc474U), BSWAP_32BIG_C(0x5c6da856U), BSWAP_32BIG_C(
                    0xba3cafbaU),
            };
            r_rsip_func100(Param_p36i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p36i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x96f2e260U), BSWAP_32BIG_C(0x947ca4c9U), BSWAP_32BIG_C(0x8d7faaecU), BSWAP_32BIG_C(
                        0x3ab4102dU),
                };
                r_rsip_func102(Param_p36i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p36i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x884b9494U), BSWAP_32BIG_C(0xb2a65163U), BSWAP_32BIG_C(0x378fe801U), BSWAP_32BIG_C(
                        0xa37ae1fbU),
                };
                r_rsip_func101(Param_p36i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x40070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p36i_func101_007[] =
        {
            BSWAP_32BIG_C(0x7958c928U), BSWAP_32BIG_C(0x3b8d3b7eU), BSWAP_32BIG_C(0xbda4ba6bU), BSWAP_32BIG_C(
                0xfc2c4c56U),
        };
        r_rsip_func101(Param_p36i_func101_007);

        return RSIP_RET_PASS;
    }
}
