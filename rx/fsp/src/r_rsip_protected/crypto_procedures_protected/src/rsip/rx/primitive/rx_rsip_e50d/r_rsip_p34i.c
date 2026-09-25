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

rsip_ret_t r_rsip_p34i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00340001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00003401U);

    static const uint32_t Param_p34i_func101_001[] =
    {
        BSWAP_32BIG_C(0xb460c597U), BSWAP_32BIG_C(0xc00e018dU), BSWAP_32BIG_C(0x67798e71U), BSWAP_32BIG_C(0x8625cdc8U),
    };
    r_rsip_func101(Param_p34i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x00003401U);

    static const uint32_t Param_p34i_func101_002[] =
    {
        BSWAP_32BIG_C(0xb58a10baU), BSWAP_32BIG_C(0x581a4584U), BSWAP_32BIG_C(0xf179b656U), BSWAP_32BIG_C(0x8125e6d8U),
    };
    r_rsip_func101(Param_p34i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p34i_func100_001[] =
    {
        BSWAP_32BIG_C(0x6126929fU), BSWAP_32BIG_C(0xb50353f9U), BSWAP_32BIG_C(0x56881ff3U), BSWAP_32BIG_C(0xcc8c0a21U),
    };
    r_rsip_func100(Param_p34i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p34i_func100_002[] =
    {
        BSWAP_32BIG_C(0xa37d64efU), BSWAP_32BIG_C(0x693849b0U), BSWAP_32BIG_C(0x58415c45U), BSWAP_32BIG_C(0x8283553aU),
    };
    r_rsip_func100(Param_p34i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p34i_func100_003[] =
    {
        BSWAP_32BIG_C(0x87617d42U), BSWAP_32BIG_C(0x93693e1cU), BSWAP_32BIG_C(0xef25cecfU), BSWAP_32BIG_C(0x55d310edU),
    };
    r_rsip_func100(Param_p34i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p34i_func102_001[] =
        {
            BSWAP_32BIG_C(0xf492385cU), BSWAP_32BIG_C(0xd9317f01U), BSWAP_32BIG_C(0x98a411e2U), BSWAP_32BIG_C(
                0xee23ef70U),
        };
        r_rsip_func102(Param_p34i_func102_001);
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

        static const uint32_t Param_p34i_func100_004[] =
        {
            BSWAP_32BIG_C(0x53c93df1U), BSWAP_32BIG_C(0x31d4e020U), BSWAP_32BIG_C(0x0374164aU), BSWAP_32BIG_C(
                0x9fcabfd0U),
        };
        r_rsip_func100(Param_p34i_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000003c7U, 0x80040080U);
            r_rsip_func_sub042(InData_IV);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p34i_func101_003[] =
            {
                BSWAP_32BIG_C(0x3150ca9eU), BSWAP_32BIG_C(0x3535cbe1U), BSWAP_32BIG_C(0x18573ccaU), BSWAP_32BIG_C(
                    0x2553a511U),
            };
            r_rsip_func101(Param_p34i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00003402U);

            static const uint32_t Param_p34i_func101_004[] =
            {
                BSWAP_32BIG_C(0x726fe176U), BSWAP_32BIG_C(0xe48874f9U), BSWAP_32BIG_C(0x09da1d8bU), BSWAP_32BIG_C(
                    0x824301adU),
            };
            r_rsip_func101(Param_p34i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x00003402U);

            static const uint32_t Param_p34i_func101_005[] =
            {
                BSWAP_32BIG_C(0x9618f8cdU), BSWAP_32BIG_C(0x147b3b17U), BSWAP_32BIG_C(0xe047ef75U), BSWAP_32BIG_C(
                    0x35fe0b97U),
            };
            r_rsip_func101(Param_p34i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p34i_func100_005[] =
            {
                BSWAP_32BIG_C(0x3a77409cU), BSWAP_32BIG_C(0x89dc44ffU), BSWAP_32BIG_C(0xa378598fU), BSWAP_32BIG_C(
                    0xdcd72c22U),
            };
            r_rsip_func100(Param_p34i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p34i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xe11473d7U), BSWAP_32BIG_C(0x96d0172dU), BSWAP_32BIG_C(0xda1ffaa7U), BSWAP_32BIG_C(
                        0xa9165385U),
                };
                r_rsip_func102(Param_p34i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p34i_func101_006[] =
                {
                    BSWAP_32BIG_C(0xf293cb85U), BSWAP_32BIG_C(0x073bd7f7U), BSWAP_32BIG_C(0x8c071a83U), BSWAP_32BIG_C(
                        0xc7ede200U),
                };
                r_rsip_func101(Param_p34i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x40070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p34i_func101_007[] =
        {
            BSWAP_32BIG_C(0x014d9e2dU), BSWAP_32BIG_C(0x03e24ef8U), BSWAP_32BIG_C(0x6f06af71U), BSWAP_32BIG_C(
                0x796b760bU),
        };
        r_rsip_func101(Param_p34i_func101_007);

        return RSIP_RET_PASS;
    }
}
