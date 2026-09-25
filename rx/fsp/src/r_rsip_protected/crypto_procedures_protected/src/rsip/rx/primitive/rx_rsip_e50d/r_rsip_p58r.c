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

rsip_ret_t r_rsip_p58r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[],
                        uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00580001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2400H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_p58r_func100_001[] =
    {
        BSWAP_32BIG_C(0x607216e6U), BSWAP_32BIG_C(0x998ae40cU), BSWAP_32BIG_C(0xf263c37dU), BSWAP_32BIG_C(0xef45fbd4U),
    };
    r_rsip_func100(Param_p58r_func100_001);
    r_rsip_func_sub021(0x3420a880U, 0x00000004U, 0x2000b480U, 0x00000003U);

    r_rsip_func_sub014(0x00007c04U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002cU);

        WR1_PROG(REG_2404H, 0x00001001U);

        r_rsip_func_sub021(0x0000b460U, 0x00000008U, 0x0000b420U, 0x00000024U);

        static const uint32_t Param_p58r_func101_001[] =
        {
            BSWAP_32BIG_C(0x7b5f4bfdU), BSWAP_32BIG_C(0x44444a93U), BSWAP_32BIG_C(0xa3e0d9d2U), BSWAP_32BIG_C(
                0x06c4f381U),
        };
        r_rsip_func101(Param_p58r_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002dU);

        WR1_PROG(REG_2404H, 0x00001011U);

        r_rsip_func_sub021(0x0000b460U, 0x00000008U, 0x0000b420U, 0x00000022U);

        static const uint32_t Param_p58r_func101_002[] =
        {
            BSWAP_32BIG_C(0xee63d4d9U), BSWAP_32BIG_C(0x9a657c6bU), BSWAP_32BIG_C(0x53d41e43U), BSWAP_32BIG_C(
                0xb9edb786U),
        };
        r_rsip_func101(Param_p58r_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002eU);

        WR1_PROG(REG_2404H, 0x00001021U);

        r_rsip_func_sub021(0x0000b460U, 0x0000000cU, 0x0000b420U, 0x0000001aU);

        static const uint32_t Param_p58r_func101_003[] =
        {
            BSWAP_32BIG_C(0xb9724afcU), BSWAP_32BIG_C(0xd2a06c40U), BSWAP_32BIG_C(0x788c50b2U), BSWAP_32BIG_C(
                0x4077c0ccU),
        };
        r_rsip_func101(Param_p58r_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002fU);

        WR1_PROG(REG_2404H, 0x00001031U);

        r_rsip_func_sub021(0x0000b460U, 0x00000010U, 0x0000b420U, 0x00000012U);

        static const uint32_t Param_p58r_func101_004[] =
        {
            BSWAP_32BIG_C(0x1590fb58U), BSWAP_32BIG_C(0xa79c57b3U), BSWAP_32BIG_C(0x3057b3f4U), BSWAP_32BIG_C(
                0x076b9facU),
        };
        r_rsip_func101(Param_p58r_func101_004);
    }

    WR1_PROG(REG_2408H, 0x00000003U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00005802U);

    static const uint32_t Param_p58r_func101_005[] =
    {
        BSWAP_32BIG_C(0x81b17096U), BSWAP_32BIG_C(0x88537dd5U), BSWAP_32BIG_C(0xbc77cc72U), BSWAP_32BIG_C(0x68dd4889U),
    };
    r_rsip_func101(Param_p58r_func101_005);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub009(0x00005802U);

    static const uint32_t Param_p58r_func101_006[] =
    {
        BSWAP_32BIG_C(0xcc0d4293U), BSWAP_32BIG_C(0xb6aebbf0U), BSWAP_32BIG_C(0x3880c17fU), BSWAP_32BIG_C(0xff34df0bU),
    };
    r_rsip_func101(Param_p58r_func101_006);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008e7U);

    for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; iLoop = iLoop + 4U)
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

        r_rsip_func_sub001(0x01820011U);

        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1600H, 0x00000004U);

        static const uint32_t Param_p58r_func101_007[] =
        {
            BSWAP_32BIG_C(0x31ac3c94U), BSWAP_32BIG_C(0xc08ebf1dU), BSWAP_32BIG_C(0xbf347283U), BSWAP_32BIG_C(
                0x37e4d8e9U),
        };
        r_rsip_func101(Param_p58r_func101_007);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x380008e3U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p58r_func100_002[] =
    {
        BSWAP_32BIG_C(0xdf9bb8cdU), BSWAP_32BIG_C(0x3b6f6b3dU), BSWAP_32BIG_C(0x4be22b70U), BSWAP_32BIG_C(0x73e2aea0U),
    };
    r_rsip_func100(Param_p58r_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p58r_func102_001[] =
        {
            BSWAP_32BIG_C(0x3fb8d754U), BSWAP_32BIG_C(0x9022fa89U), BSWAP_32BIG_C(0x70dcf39fU), BSWAP_32BIG_C(
                0x0b6a7fffU),
        };
        r_rsip_func102(Param_p58r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p58r_func100_003[] =
        {
            BSWAP_32BIG_C(0x400e6806U), BSWAP_32BIG_C(0xb581db49U), BSWAP_32BIG_C(0x3a4a3818U), BSWAP_32BIG_C(
                0xa5c7b57eU),
        };
        r_rsip_func100(Param_p58r_func100_003);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2414H, InData_State[50]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2410H, InData_State[51]);

        for (iLoop = 0U; iLoop < 50; iLoop++)
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2438H, InData_State[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub016(0x81010020U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_p58r_func101_008[] =
        {
            BSWAP_32BIG_C(0x0bcea83cU), BSWAP_32BIG_C(0x0fe8dee1U), BSWAP_32BIG_C(0x10b49f78U), BSWAP_32BIG_C(
                0xcadf19d2U),
        };
        r_rsip_func101(Param_p58r_func101_008);

        return RSIP_RET_PASS;
    }
}
