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

rsip_ret_t r_rsip_p17 (uint32_t OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00170001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00001701U);

    static const uint32_t Param_p17_func101_001[] =
    {
        BSWAP_32BIG_C(0xe2fdf043U), BSWAP_32BIG_C(0x3d34a5caU), BSWAP_32BIG_C(0x13f20832U), BSWAP_32BIG_C(0x34d74a4dU),
    };
    r_rsip_func101(Param_p17_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e4U);

    r_rsip_func_sub009(0x00000017U);

    static const uint32_t Param_p17_func101_002[] =
    {
        BSWAP_32BIG_C(0x33fdcb07U), BSWAP_32BIG_C(0xa8c23db3U), BSWAP_32BIG_C(0x63405f0eU), BSWAP_32BIG_C(0x730334f7U),
    };
    r_rsip_func101(Param_p17_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000009U);

    r_rsip_func_sub009(0x00000017U);

    static const uint32_t Param_p17_func101_003[] =
    {
        BSWAP_32BIG_C(0xf2707530U), BSWAP_32BIG_C(0xb377a949U), BSWAP_32BIG_C(0x57701552U), BSWAP_32BIG_C(0x009c074cU),
    };
    r_rsip_func101(Param_p17_func101_003);
    r_rsip_func044();

    r_rsip_func_sub009(0x00001702U);

    static const uint32_t Param_p17_func101_004[] =
    {
        BSWAP_32BIG_C(0x4208d90bU), BSWAP_32BIG_C(0x36ffc9c8U), BSWAP_32BIG_C(0xab0f495fU), BSWAP_32BIG_C(0x75706815U),
    };
    r_rsip_func101(Param_p17_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1608H, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00001703U);

    static const uint32_t Param_p17_func101_005[] =
    {
        BSWAP_32BIG_C(0x9c448585U), BSWAP_32BIG_C(0xdce52fc1U), BSWAP_32BIG_C(0xc41d6293U), BSWAP_32BIG_C(0xd47f2790U),
    };
    r_rsip_func101(Param_p17_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b7e0U, 0x00000010U, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00001704U);

    static const uint32_t Param_p17_func101_006[] =
    {
        BSWAP_32BIG_C(0x28abe310U), BSWAP_32BIG_C(0xc7e211d3U), BSWAP_32BIG_C(0x783cb4a7U), BSWAP_32BIG_C(0x4bccdd2bU),
    };
    r_rsip_func101(Param_p17_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b7e0U, 0x00000020U, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00001705U);

    static const uint32_t Param_p17_func101_007[] =
    {
        BSWAP_32BIG_C(0x0597c86eU), BSWAP_32BIG_C(0x73c97f86U), BSWAP_32BIG_C(0xf958750eU), BSWAP_32BIG_C(0xf173e8c5U),
    };
    r_rsip_func101(Param_p17_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b7e0U, 0x00000030U, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p17_func101_008[] =
    {
        BSWAP_32BIG_C(0x2ffbb319U), BSWAP_32BIG_C(0xd2b9e3c6U), BSWAP_32BIG_C(0x265413adU), BSWAP_32BIG_C(0xc739ad10U),
    };
    r_rsip_func101(Param_p17_func101_008);

    r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000020U);

    r_rsip_func424();

    r_rsip_func_sub021(0x000037dfU, 0x0000b400U, 0x00000010U, 0x0000b420U);
    WR1_PROG(REG_1600H, 0x00000030U);
    r_rsip_func424();

    WR1_PROG(REG_1600H, 0x000013feU);

    r_rsip_func_sub006(0x38008be0U, 0xb2d02d18U, 0x00A60000U);

    static const uint32_t Param_p17_func100_001[] =
    {
        BSWAP_32BIG_C(0xe7133a82U), BSWAP_32BIG_C(0x043e104aU), BSWAP_32BIG_C(0x66a59732U), BSWAP_32BIG_C(0x51d8677aU),
    };
    r_rsip_func100(Param_p17_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p17_func102_001[] =
        {
            BSWAP_32BIG_C(0x4169a204U), BSWAP_32BIG_C(0x2bc838f2U), BSWAP_32BIG_C(0xb10d5130U), BSWAP_32BIG_C(
                0xc80505eeU),
        };
        r_rsip_func102(Param_p17_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p17_func100_002[] =
        {
            BSWAP_32BIG_C(0xb767ebbcU), BSWAP_32BIG_C(0xcaaa72c5U), BSWAP_32BIG_C(0x0151cfd7U), BSWAP_32BIG_C(
                0x1f56f52cU),
        };
        r_rsip_func100(Param_p17_func100_002);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d47U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x818c001fU);
        r_rsip_func_sub001(0x00890031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p17_func100_003[] =
        {
            BSWAP_32BIG_C(0x9c74946aU), BSWAP_32BIG_C(0xd9c4549eU), BSWAP_32BIG_C(0x68ae749cU), BSWAP_32BIG_C(
                0xf60bedf0U),
        };
        r_rsip_func100(Param_p17_func100_003);
        r_rsip_func_sub027(0x40000000U, 0xe7008d47U, 0x81040180U);
        r_rsip_func_sub001(0x00890011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);

        static const uint32_t Param_p17_func100_004[] =
        {
            BSWAP_32BIG_C(0x3772d2a4U), BSWAP_32BIG_C(0xf91cc8f9U), BSWAP_32BIG_C(0xd1c5a87bU), BSWAP_32BIG_C(
                0x5ca396b5U),
        };
        r_rsip_func100(Param_p17_func100_004);
        r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
        WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
                 bswap_32big(0x00000004U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);

        static const uint32_t Param_p17_func100_005[] =
        {
            BSWAP_32BIG_C(0xe6105f4bU), BSWAP_32BIG_C(0x902c3d20U), BSWAP_32BIG_C(0x998727a2U), BSWAP_32BIG_C(
                0x46955614U),
        };
        r_rsip_func100(Param_p17_func100_005);
        r_rsip_func_sub016(0x81010080U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

        static const uint32_t Param_p17_func102_002[] =
        {
            BSWAP_32BIG_C(0xe406720dU), BSWAP_32BIG_C(0x02a899a2U), BSWAP_32BIG_C(0xb4bb33fdU), BSWAP_32BIG_C(
                0x72fe5895U),
        };
        r_rsip_func102(Param_p17_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
