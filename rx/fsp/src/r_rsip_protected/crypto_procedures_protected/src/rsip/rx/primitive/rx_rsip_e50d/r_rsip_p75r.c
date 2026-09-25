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

rsip_ret_t r_rsip_p75r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[],
                        uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00750001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_p75r_func100_001[] =
    {
        BSWAP_32BIG_C(0x87b291d4U), BSWAP_32BIG_C(0x55814964U), BSWAP_32BIG_C(0x96bfef1aU), BSWAP_32BIG_C(0x0d2d1edbU),
    };
    r_rsip_func100(Param_p75r_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p75r_func102_001[] =
        {
            BSWAP_32BIG_C(0x1103febaU), BSWAP_32BIG_C(0xd4e28a4aU), BSWAP_32BIG_C(0x6365bfa7U), BSWAP_32BIG_C(
                0x26bfa2e1U),
        };
        r_rsip_func102(Param_p75r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p75r_func100_002[] =
        {
            BSWAP_32BIG_C(0x86dbc82dU), BSWAP_32BIG_C(0x03033dd4U), BSWAP_32BIG_C(0x81bd9cb1U), BSWAP_32BIG_C(
                0x3470b022U),
        };
        r_rsip_func100(Param_p75r_func100_002);
        r_rsip_func_sub021(0x3420a880U, 0x00000007U, 0x2000b480U, 0x00000006U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000001aU);

            r_rsip_func_sub032(0x00001040U, 0x0000b460U, 0x00000008U);

            static const uint32_t Param_p75r_func101_001[] =
            {
                BSWAP_32BIG_C(0x6cbf3b70U), BSWAP_32BIG_C(0xaad34da4U), BSWAP_32BIG_C(0x880b180bU), BSWAP_32BIG_C(
                    0x605d4e78U),
            };
            r_rsip_func101(Param_p75r_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000001bU);

            r_rsip_func_sub032(0x00001050U, 0x0000b460U, 0x00000008U);

            static const uint32_t Param_p75r_func101_002[] =
            {
                BSWAP_32BIG_C(0x0b3037b5U), BSWAP_32BIG_C(0x9e860d47U), BSWAP_32BIG_C(0xc409efc0U), BSWAP_32BIG_C(
                    0xb6b992e9U),
            };
            r_rsip_func101(Param_p75r_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000002aU);

            r_rsip_func_sub032(0x00001080U, 0x0000b460U, 0x00000010U);

            static const uint32_t Param_p75r_func101_003[] =
            {
                BSWAP_32BIG_C(0x5869e1fcU), BSWAP_32BIG_C(0x2034a91cU), BSWAP_32BIG_C(0x4be2b1f3U), BSWAP_32BIG_C(
                    0xc72a8230U),
            };
            r_rsip_func101(Param_p75r_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000002bU);

            r_rsip_func_sub032(0x00001090U, 0x0000b460U, 0x00000010U);

            static const uint32_t Param_p75r_func101_004[] =
            {
                BSWAP_32BIG_C(0x9461fb4aU), BSWAP_32BIG_C(0xffd4a2efU), BSWAP_32BIG_C(0x03efaa3cU), BSWAP_32BIG_C(
                    0xc923ca0aU),
            };
            r_rsip_func101(Param_p75r_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x00000028U);

            r_rsip_func_sub032(0x000010a0U, 0x0000b460U, 0x0000000cU);

            static const uint32_t Param_p75r_func101_005[] =
            {
                BSWAP_32BIG_C(0x8296548aU), BSWAP_32BIG_C(0xbea732a5U), BSWAP_32BIG_C(0xb4dc4821U), BSWAP_32BIG_C(
                    0xd81a7f27U),
            };
            r_rsip_func101(Param_p75r_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x00000029U);

            r_rsip_func_sub032(0x000010b0U, 0x0000b460U, 0x00000010U);

            static const uint32_t Param_p75r_func101_006[] =
            {
                BSWAP_32BIG_C(0x2f44cc05U), BSWAP_32BIG_C(0xe20d9c60U), BSWAP_32BIG_C(0xc5295ec5U), BSWAP_32BIG_C(
                    0x53b18d87U),
            };
            r_rsip_func101(Param_p75r_func101_006);
        }

        WR1_PROG(REG_2008H, 0x00000003U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x00007502U);

        static const uint32_t Param_p75r_func101_007[] =
        {
            BSWAP_32BIG_C(0x72bf7126U), BSWAP_32BIG_C(0x9375203dU), BSWAP_32BIG_C(0xdecc38e9U), BSWAP_32BIG_C(
                0xb899d4ceU),
        };
        r_rsip_func101(Param_p75r_func101_007);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e5U);

        r_rsip_func_sub009(0x00007502U);

        static const uint32_t Param_p75r_func101_008[] =
        {
            BSWAP_32BIG_C(0x85a39538U), BSWAP_32BIG_C(0xc37765adU), BSWAP_32BIG_C(0x56c170aeU), BSWAP_32BIG_C(
                0x3a97b781U),
        };
        r_rsip_func101(Param_p75r_func101_008);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; iLoop = iLoop + 4U)
        {
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            r_rsip_func_sub001(0x01420011U);

            WR1_PROG(REG_1600H, 0x0000a4e0U);
            WR1_PROG(REG_1600H, 0x00000004U);

            static const uint32_t Param_p75r_func101_009[] =
            {
                BSWAP_32BIG_C(0x1761d89fU), BSWAP_32BIG_C(0x70098408U), BSWAP_32BIG_C(0xdd045d5fU), BSWAP_32BIG_C(
                    0xc2f49458U),
            };
            r_rsip_func101(Param_p75r_func101_009);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x380008e3U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p75r_func100_003[] =
        {
            BSWAP_32BIG_C(0x98f9673fU), BSWAP_32BIG_C(0x1744602cU), BSWAP_32BIG_C(0x49695f10U), BSWAP_32BIG_C(
                0x2235e5f1U),
        };
        r_rsip_func100(Param_p75r_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p75r_func102_002[] =
            {
                BSWAP_32BIG_C(0x37618b91U), BSWAP_32BIG_C(0xe128e699U), BSWAP_32BIG_C(0xc3231fdcU), BSWAP_32BIG_C(
                    0xb5cae95eU),
            };
            r_rsip_func102(Param_p75r_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub033(0x00000040U, InData_State[18], 0x00000040U, InData_State[19]);

            for (iLoop = 0U; iLoop < 18U; iLoop++)
            {
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_PROG(REG_2028H, InData_State[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p75r_func101_010[] =
            {
                BSWAP_32BIG_C(0xbacd79b0U), BSWAP_32BIG_C(0x3001c7baU), BSWAP_32BIG_C(0x6ee9714cU), BSWAP_32BIG_C(
                    0x4cb19365U),
            };
            r_rsip_func101(Param_p75r_func101_010);

            return RSIP_RET_PASS;
        }
    }
}
