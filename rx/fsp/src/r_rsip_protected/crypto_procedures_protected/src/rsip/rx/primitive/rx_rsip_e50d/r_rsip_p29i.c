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

rsip_ret_t r_rsip_p29i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00290001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00002901U);

    static const uint32_t Param_p29i_func101_001[] =
    {
        BSWAP_32BIG_C(0x4fe7c93eU), BSWAP_32BIG_C(0x572c69b6U), BSWAP_32BIG_C(0xe9e5c7fcU), BSWAP_32BIG_C(0xc3d6d8f9U),
    };
    r_rsip_func101(Param_p29i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x00002901U);

    static const uint32_t Param_p29i_func101_002[] =
    {
        BSWAP_32BIG_C(0xa4e33b2bU), BSWAP_32BIG_C(0x7ceacea0U), BSWAP_32BIG_C(0x7d545152U), BSWAP_32BIG_C(0x377145a6U),
    };
    r_rsip_func101(Param_p29i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p29i_func100_001[] =
    {
        BSWAP_32BIG_C(0x81c480f8U), BSWAP_32BIG_C(0x99d42fcfU), BSWAP_32BIG_C(0xe4d2c7a0U), BSWAP_32BIG_C(0xbeffc26aU),
    };
    r_rsip_func100(Param_p29i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p29i_func100_002[] =
    {
        BSWAP_32BIG_C(0xe97b01f1U), BSWAP_32BIG_C(0xe27e2cbdU), BSWAP_32BIG_C(0x21390d3eU), BSWAP_32BIG_C(0x5414a4fcU),
    };
    r_rsip_func100(Param_p29i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p29i_func102_001[] =
        {
            BSWAP_32BIG_C(0x32d9cfd5U), BSWAP_32BIG_C(0xed5713dfU), BSWAP_32BIG_C(0x03cf676cU), BSWAP_32BIG_C(
                0xd930aa5bU),
        };
        r_rsip_func102(Param_p29i_func102_001);
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

        static const uint32_t Param_p29i_func100_003[] =
        {
            BSWAP_32BIG_C(0xe2ea35bcU), BSWAP_32BIG_C(0x53efcc72U), BSWAP_32BIG_C(0xbb741730U), BSWAP_32BIG_C(
                0x0a4056b2U),
        };
        r_rsip_func100(Param_p29i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000003c7U, 0x80040080U);
            r_rsip_func_sub042(InData_IV);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p29i_func101_003[] =
            {
                BSWAP_32BIG_C(0x0b3b3db5U), BSWAP_32BIG_C(0x0a01aa5aU), BSWAP_32BIG_C(0xce7e7623U), BSWAP_32BIG_C(
                    0x67ab14bdU),
            };
            r_rsip_func101(Param_p29i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00002902U);

            static const uint32_t Param_p29i_func101_004[] =
            {
                BSWAP_32BIG_C(0x7f079701U), BSWAP_32BIG_C(0x00e86a20U), BSWAP_32BIG_C(0xf0c89c10U), BSWAP_32BIG_C(
                    0x16dda487U),
            };
            r_rsip_func101(Param_p29i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x00002902U);

            static const uint32_t Param_p29i_func101_005[] =
            {
                BSWAP_32BIG_C(0x9bc97833U), BSWAP_32BIG_C(0x278f63c4U), BSWAP_32BIG_C(0x13dea49eU), BSWAP_32BIG_C(
                    0xc32210f6U),
            };
            r_rsip_func101(Param_p29i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p29i_func100_004[] =
            {
                BSWAP_32BIG_C(0x3a28029fU), BSWAP_32BIG_C(0xf71d2d91U), BSWAP_32BIG_C(0xfd40e703U), BSWAP_32BIG_C(
                    0x9f1423f3U),
            };
            r_rsip_func100(Param_p29i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p29i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xd216b9d4U), BSWAP_32BIG_C(0x49a551efU), BSWAP_32BIG_C(0x95b42242U), BSWAP_32BIG_C(
                        0x79f77092U),
                };
                r_rsip_func102(Param_p29i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p29i_func101_006[] =
                {
                    BSWAP_32BIG_C(0xe8632d72U), BSWAP_32BIG_C(0x4d7c8813U), BSWAP_32BIG_C(0xb6d0631fU), BSWAP_32BIG_C(
                        0xfc540fabU),
                };
                r_rsip_func101(Param_p29i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x00070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p29i_func101_007[] =
        {
            BSWAP_32BIG_C(0xf6416e3dU), BSWAP_32BIG_C(0x0d12cabeU), BSWAP_32BIG_C(0xc7d1a3eaU), BSWAP_32BIG_C(
                0x34cf3f54U),
        };
        r_rsip_func101(Param_p29i_func101_007);

        return RSIP_RET_PASS;
    }
}
