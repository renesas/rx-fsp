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

rsip_ret_t r_rsip_p32i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00320001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00003201U);

    static const uint32_t Param_p32i_func101_001[] =
    {
        BSWAP_32BIG_C(0x1824103eU), BSWAP_32BIG_C(0x4208d3acU), BSWAP_32BIG_C(0xfd369de7U), BSWAP_32BIG_C(0x53946c8aU),
    };
    r_rsip_func101(Param_p32i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x00003201U);

    static const uint32_t Param_p32i_func101_002[] =
    {
        BSWAP_32BIG_C(0x22837617U), BSWAP_32BIG_C(0x3ac38b62U), BSWAP_32BIG_C(0x720579f2U), BSWAP_32BIG_C(0xb91390baU),
    };
    r_rsip_func101(Param_p32i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p32i_func100_001[] =
    {
        BSWAP_32BIG_C(0xbd193564U), BSWAP_32BIG_C(0x2ed0d6dfU), BSWAP_32BIG_C(0xdf4a9e95U), BSWAP_32BIG_C(0xc383ad6dU),
    };
    r_rsip_func100(Param_p32i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p32i_func100_002[] =
    {
        BSWAP_32BIG_C(0xa8743ca0U), BSWAP_32BIG_C(0xdccb3b02U), BSWAP_32BIG_C(0xf92d2700U), BSWAP_32BIG_C(0x9dfce8c0U),
    };
    r_rsip_func100(Param_p32i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p32i_func102_001[] =
        {
            BSWAP_32BIG_C(0xfa047ba0U), BSWAP_32BIG_C(0x3e0582abU), BSWAP_32BIG_C(0xc2fa01daU), BSWAP_32BIG_C(
                0xc6365271U),
        };
        r_rsip_func102(Param_p32i_func102_001);
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

        static const uint32_t Param_p32i_func100_003[] =
        {
            BSWAP_32BIG_C(0x3b974430U), BSWAP_32BIG_C(0x52b62ac9U), BSWAP_32BIG_C(0xb5eb8b96U), BSWAP_32BIG_C(
                0x2221883fU),
        };
        r_rsip_func100(Param_p32i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000003c7U, 0x80040080U);
            r_rsip_func_sub042(InData_IV);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p32i_func101_003[] =
            {
                BSWAP_32BIG_C(0x7d6774e1U), BSWAP_32BIG_C(0xa6bde49bU), BSWAP_32BIG_C(0x008f516eU), BSWAP_32BIG_C(
                    0x64a106a2U),
            };
            r_rsip_func101(Param_p32i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00003202U);

            static const uint32_t Param_p32i_func101_004[] =
            {
                BSWAP_32BIG_C(0xaeed2c8eU), BSWAP_32BIG_C(0xd9674bebU), BSWAP_32BIG_C(0xa07d2907U), BSWAP_32BIG_C(
                    0x4856a5e1U),
            };
            r_rsip_func101(Param_p32i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x00003202U);

            static const uint32_t Param_p32i_func101_005[] =
            {
                BSWAP_32BIG_C(0xf5096492U), BSWAP_32BIG_C(0x39e600f6U), BSWAP_32BIG_C(0xc36e2973U), BSWAP_32BIG_C(
                    0xc90f5991U),
            };
            r_rsip_func101(Param_p32i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p32i_func100_004[] =
            {
                BSWAP_32BIG_C(0xb52707feU), BSWAP_32BIG_C(0xb975f3daU), BSWAP_32BIG_C(0xa8f291b8U), BSWAP_32BIG_C(
                    0x91e8c6ceU),
            };
            r_rsip_func100(Param_p32i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p32i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xe17f9b36U), BSWAP_32BIG_C(0x74ac4ed2U), BSWAP_32BIG_C(0x4898a674U), BSWAP_32BIG_C(
                        0xfaef4352U),
                };
                r_rsip_func102(Param_p32i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p32i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x917a957cU), BSWAP_32BIG_C(0x1d3a6e9eU), BSWAP_32BIG_C(0x1ccafb1dU), BSWAP_32BIG_C(
                        0xc4497d4cU),
                };
                r_rsip_func101(Param_p32i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x00070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p32i_func101_007[] =
        {
            BSWAP_32BIG_C(0x7286efc8U), BSWAP_32BIG_C(0x6aa63d89U), BSWAP_32BIG_C(0xb0a154e8U), BSWAP_32BIG_C(
                0x4aa0e5eaU),
        };
        r_rsip_func101(Param_p32i_func101_007);

        return RSIP_RET_PASS;
    }
}
