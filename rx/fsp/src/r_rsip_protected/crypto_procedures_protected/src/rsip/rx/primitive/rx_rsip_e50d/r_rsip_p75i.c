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

rsip_ret_t r_rsip_p75i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgLen[],
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

    static const uint32_t Param_p75i_func100_001[] =
    {
        BSWAP_32BIG_C(0x87b291d4U), BSWAP_32BIG_C(0x55814964U), BSWAP_32BIG_C(0x96bfef1aU), BSWAP_32BIG_C(0x0d2d1edbU),
    };
    r_rsip_func100(Param_p75i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p75i_func102_001[] =
        {
            BSWAP_32BIG_C(0x1103febaU), BSWAP_32BIG_C(0xd4e28a4aU), BSWAP_32BIG_C(0x6365bfa7U), BSWAP_32BIG_C(
                0x26bfa2e1U),
        };
        r_rsip_func102(Param_p75i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p75i_func100_002[] =
        {
            BSWAP_32BIG_C(0x86dbc82dU), BSWAP_32BIG_C(0x03033dd4U), BSWAP_32BIG_C(0x81bd9cb1U), BSWAP_32BIG_C(
                0x3470b022U),
        };
        r_rsip_func100(Param_p75i_func100_002);
        r_rsip_func_sub021(0x3420a880U, 0x00000007U, 0x2000b480U, 0x00000006U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000001aU);

            r_rsip_func_sub032(0x00000040U, 0x0000b460U, 0x00000008U);

            static const uint32_t Param_p75i_func101_001[] =
            {
                BSWAP_32BIG_C(0xc85eba0bU), BSWAP_32BIG_C(0xc871b769U), BSWAP_32BIG_C(0xa648f4b0U), BSWAP_32BIG_C(
                    0x7a203dc6U),
            };
            r_rsip_func101(Param_p75i_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000001bU);

            r_rsip_func_sub032(0x00000050U, 0x0000b460U, 0x00000008U);

            static const uint32_t Param_p75i_func101_002[] =
            {
                BSWAP_32BIG_C(0x82d4283bU), BSWAP_32BIG_C(0xd4ca4e41U), BSWAP_32BIG_C(0xf4dd55e3U), BSWAP_32BIG_C(
                    0x65cfd536U),
            };
            r_rsip_func101(Param_p75i_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000002aU);

            r_rsip_func_sub032(0x00000080U, 0x0000b460U, 0x00000010U);

            static const uint32_t Param_p75i_func101_003[] =
            {
                BSWAP_32BIG_C(0x6cd96ff1U), BSWAP_32BIG_C(0x01edfc4eU), BSWAP_32BIG_C(0x01438eefU), BSWAP_32BIG_C(
                    0xe9a3f085U),
            };
            r_rsip_func101(Param_p75i_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000002bU);

            r_rsip_func_sub032(0x00000090U, 0x0000b460U, 0x00000010U);

            static const uint32_t Param_p75i_func101_004[] =
            {
                BSWAP_32BIG_C(0xfaf4b1ccU), BSWAP_32BIG_C(0x1d4a5647U), BSWAP_32BIG_C(0x1c8c9b81U), BSWAP_32BIG_C(
                    0xa583b59dU),
            };
            r_rsip_func101(Param_p75i_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x00000028U);

            r_rsip_func_sub032(0x000000a0U, 0x0000b460U, 0x0000000cU);

            static const uint32_t Param_p75i_func101_005[] =
            {
                BSWAP_32BIG_C(0x33d95827U), BSWAP_32BIG_C(0x89356081U), BSWAP_32BIG_C(0xf0a82872U), BSWAP_32BIG_C(
                    0x3df3b90cU),
            };
            r_rsip_func101(Param_p75i_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x00000029U);

            r_rsip_func_sub032(0x000000b0U, 0x0000b460U, 0x00000010U);

            static const uint32_t Param_p75i_func101_006[] =
            {
                BSWAP_32BIG_C(0x09e45ef0U), BSWAP_32BIG_C(0x80b9fb09U), BSWAP_32BIG_C(0x6588de4bU), BSWAP_32BIG_C(
                    0xc30aeebaU),
            };
            r_rsip_func101(Param_p75i_func101_006);
        }

        WR1_PROG(REG_2008H, 0x00000003U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x00007501U);

        static const uint32_t Param_p75i_func101_007[] =
        {
            BSWAP_32BIG_C(0x8ed703fdU), BSWAP_32BIG_C(0x7a6883faU), BSWAP_32BIG_C(0x47c6c8beU), BSWAP_32BIG_C(
                0x9c0ccc0bU),
        };
        r_rsip_func101(Param_p75i_func101_007);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e5U);

        r_rsip_func_sub009(0x00007501U);

        static const uint32_t Param_p75i_func101_008[] =
        {
            BSWAP_32BIG_C(0x3349630aU), BSWAP_32BIG_C(0xf749b474U), BSWAP_32BIG_C(0x8f86b113U), BSWAP_32BIG_C(
                0x47cdd0b7U),
        };
        r_rsip_func101(Param_p75i_func101_008);
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

            static const uint32_t Param_p75i_func101_009[] =
            {
                BSWAP_32BIG_C(0x1175dbcbU), BSWAP_32BIG_C(0xc3e168f9U), BSWAP_32BIG_C(0x9f1b6158U), BSWAP_32BIG_C(
                    0x2b071384U),
            };
            r_rsip_func101(Param_p75i_func101_009);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x380008e3U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p75i_func100_003[] =
        {
            BSWAP_32BIG_C(0x8a5cacc1U), BSWAP_32BIG_C(0xe2d2c917U), BSWAP_32BIG_C(0x60ec8769U), BSWAP_32BIG_C(
                0x6a69b5bbU),
        };
        r_rsip_func100(Param_p75i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p75i_func102_002[] =
            {
                BSWAP_32BIG_C(0x02efd2b3U), BSWAP_32BIG_C(0x9bcb9843U), BSWAP_32BIG_C(0x294d5debU), BSWAP_32BIG_C(
                    0x4fcf8fd8U),
            };
            r_rsip_func102(Param_p75i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
            {
                r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000080U);

                WR1_PROG(REG_200CH, 0x00000001U);

                WAIT_STS(REG_2030H, 8, 0);

                r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000000U);

                WR1_PROG(REG_200CH, 0x00000100U);

                static const uint32_t Param_p75i_func101_010[] =
                {
                    BSWAP_32BIG_C(0x6cad70c9U), BSWAP_32BIG_C(0x5d17e3b8U), BSWAP_32BIG_C(0x82bcf3a2U), BSWAP_32BIG_C(
                        0x7ccdced9U),
                };
                r_rsip_func101(Param_p75i_func101_010);
            }
            else
            {
                r_rsip_func_sub033(0x00000040U, InData_MsgLen[0], 0x00000040U, InData_MsgLen[1]);

                WR1_PROG(REG_200CH, 0x00000001U);

                static const uint32_t Param_p75i_func101_011[] =
                {
                    BSWAP_32BIG_C(0x2d31155aU), BSWAP_32BIG_C(0x0c1bdc3eU), BSWAP_32BIG_C(0xb6211e39U), BSWAP_32BIG_C(
                        0x5175c471U),
                };
                r_rsip_func101(Param_p75i_func101_011);
            }

            return RSIP_RET_PASS;
        }
    }
}
