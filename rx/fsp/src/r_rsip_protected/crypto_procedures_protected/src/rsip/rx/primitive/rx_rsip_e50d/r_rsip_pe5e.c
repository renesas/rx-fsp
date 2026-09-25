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

rsip_ret_t r_rsip_pe5e (const uint32_t InData_EncMsg[], const uint32_t InData_EncMsgLength[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010100U);
    WR1_PROG(REG_1420H, InData_EncMsgLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000d08U, 0x00A60000U);

    static const uint32_t Param_pe5e_func100_001[] =
    {
        BSWAP_32BIG_C(0x69bc0b6fU), BSWAP_32BIG_C(0x8f8548bdU), BSWAP_32BIG_C(0x2541a304U), BSWAP_32BIG_C(0x69e98137U),
    };
    r_rsip_func100(Param_pe5e_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x0000e503U);

        static const uint32_t Param_pe5e_func101_001[] =
        {
            BSWAP_32BIG_C(0x70c896feU), BSWAP_32BIG_C(0x7dabaddcU), BSWAP_32BIG_C(0xb65d7327U), BSWAP_32BIG_C(
                0x1fa7bb7eU),
        };
        r_rsip_func101(Param_pe5e_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x01c80eb2U);

        r_rsip_func_sub009(0x0000e503U);

        static const uint32_t Param_pe5e_func101_002[] =
        {
            BSWAP_32BIG_C(0xec805f92U), BSWAP_32BIG_C(0x1bbed14aU), BSWAP_32BIG_C(0x49365fe5U), BSWAP_32BIG_C(
                0x41c8314dU),
        };
        r_rsip_func101(Param_pe5e_func101_002);
        r_rsip_func044();

        WAIT_STS(REG_2030H, 0, 1);

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        r_rsip_func_sub020(0x000000a1U, 0x08000044U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub020(0x000000a1U, 0x08000054U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub009(0x0000e501U);

        static const uint32_t Param_pe5e_func101_003[] =
        {
            BSWAP_32BIG_C(0x3625b088U), BSWAP_32BIG_C(0x0fb02648U), BSWAP_32BIG_C(0x08265004U), BSWAP_32BIG_C(
                0xd9b51ca2U),
        };
        r_rsip_func101(Param_pe5e_func101_003);
        r_rsip_func103();

        static const uint32_t Param_pe5e_func100_002[] =
        {
            BSWAP_32BIG_C(0xde8bd3a2U), BSWAP_32BIG_C(0x8b81e4f9U), BSWAP_32BIG_C(0x0361c8b5U), BSWAP_32BIG_C(
                0x52176553U),
        };
        r_rsip_func100(Param_pe5e_func100_002);
        r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

        static const uint32_t Param_pe5e_func100_003[] =
        {
            BSWAP_32BIG_C(0x09f8a96cU), BSWAP_32BIG_C(0xa2eea8d9U), BSWAP_32BIG_C(0xd87ff1e3U), BSWAP_32BIG_C(
                0xcd185993U),
        };
        r_rsip_func100(Param_pe5e_func100_003);
        r_rsip_func_sub016(0x81010100U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        OFS_ADR  = S_RAM[0];

        r_rsip_func_sub021(0x0000a900U, 0x00000002U, 0x00026908U, 0x00000929U);

        for (iLoop = 0U; iLoop < S_RAM[0] - 5; iLoop = iLoop + 4U)
        {
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

            static const uint32_t Param_pe5e_func100_004[] =
            {
                BSWAP_32BIG_C(0xfef3d9a6U), BSWAP_32BIG_C(0x11becb63U), BSWAP_32BIG_C(0xa6c20ebfU), BSWAP_32BIG_C(
                    0x98d5327dU),
            };
            r_rsip_func100(Param_pe5e_func100_004);
            WR1_PROG(REG_1824H, 0xe7040d05U);
            r_rsip_func_sub001(0x00420011U);
            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &S_HEAP[iLoop]);

            WR1_PROG(REG_1600H, 0x00002d20U);

            static const uint32_t Param_pe5e_func101_004[] =
            {
                BSWAP_32BIG_C(0xd1a7049fU), BSWAP_32BIG_C(0xea461d48U), BSWAP_32BIG_C(0xb8963e82U), BSWAP_32BIG_C(
                    0x12eb5a20U),
            };
            r_rsip_func101(Param_pe5e_func101_004);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000909U);

        static const uint32_t Param_pe5e_func100_005[] =
        {
            BSWAP_32BIG_C(0xad1ad449U), BSWAP_32BIG_C(0xbf138769U), BSWAP_32BIG_C(0xd0c13242U), BSWAP_32BIG_C(
                0x9a0a27b4U),
        };
        r_rsip_func100(Param_pe5e_func100_005);
        r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1824H, 0x09140105U);
        r_rsip_func_sub001(0x00410011U);

        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &S_HEAP[iLoop]);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 4]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_pe5e_func100_006[] =
        {
            BSWAP_32BIG_C(0xd4e7a5caU), BSWAP_32BIG_C(0x98630036U), BSWAP_32BIG_C(0x751650b7U), BSWAP_32BIG_C(
                0x83d1d180U),
        };
        r_rsip_func100(Param_pe5e_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe5e_func101_005[] =
            {
                BSWAP_32BIG_C(0x4c2a4475U), BSWAP_32BIG_C(0x5a7dd8abU), BSWAP_32BIG_C(0xe488339bU), BSWAP_32BIG_C(
                    0xc6b4be08U),
            };
            r_rsip_func101(Param_pe5e_func101_005);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub020(0x000000a1U, 0x08000044U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub020(0x000000a1U, 0x08000054U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub006(0x3800a900U, 0x00000005U, 0x00260000U);

            static const uint32_t Param_pe5e_func100_007[] =
            {
                BSWAP_32BIG_C(0xf7213354U), BSWAP_32BIG_C(0x49b0ce76U), BSWAP_32BIG_C(0xeb4db9f2U), BSWAP_32BIG_C(
                    0xe35b17a9U),
            };
            r_rsip_func100(Param_pe5e_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000929U);

                for (iLoop = 0U; iLoop < S_RAM[0] - 9; iLoop = iLoop + 4U)
                {
                    r_rsip_func_sub020(0x000003c1U, 0xf7040d05U);
                    WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);
                    r_rsip_func_sub001(0x01410011U);

                    WR1_PROG(REG_1600H, 0x00002d20U);

                    static const uint32_t Param_pe5e_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x26fb0048U), BSWAP_32BIG_C(0xccdf52b7U), BSWAP_32BIG_C(0x9a55b5e0U),
                        BSWAP_32BIG_C(0x8ab98e65U),
                    };
                    r_rsip_func101(Param_pe5e_func101_006);
                }

                r_rsip_func_sub034(0x000037e8U, 0x000033e0U);
                r_rsip_func_sub011(0x38000be9U);

                r_rsip_func_sub020(0x000003c1U, 0xf7040d05U);
                WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);
                r_rsip_func_sub001(0x01410005U);
                r_rsip_func_sub001(0x0001000dU);

                iLoop = iLoop + 4;

                static const uint32_t Param_pe5e_func101_007[] =
                {
                    BSWAP_32BIG_C(0x1bd35fd2U), BSWAP_32BIG_C(0x2617c058U), BSWAP_32BIG_C(0x0394ed2aU), BSWAP_32BIG_C(
                        0xa1a05ae8U),
                };
                r_rsip_func101(Param_pe5e_func101_007);
            }
            else
            {
                WR1_PROG(REG_1600H, 0x00000929U);

                for (iLoop = 0U; iLoop < S_RAM[0] - 5; iLoop = iLoop + 4U)
                {
                    r_rsip_func_sub020(0x000003c1U, 0xf7040d05U);
                    WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);
                    r_rsip_func_sub001(0x01410011U);

                    WR1_PROG(REG_1600H, 0x00002d20U);

                    static const uint32_t Param_pe5e_func101_008[] =
                    {
                        BSWAP_32BIG_C(0xa60c9a8bU), BSWAP_32BIG_C(0x26e64a32U), BSWAP_32BIG_C(0xdd443ff4U),
                        BSWAP_32BIG_C(0x1223f88cU),
                    };
                    r_rsip_func101(Param_pe5e_func101_008);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x38000909U);

                static const uint32_t Param_pe5e_func101_009[] =
                {
                    BSWAP_32BIG_C(0xba89a21bU), BSWAP_32BIG_C(0x176d4fadU), BSWAP_32BIG_C(0x1d369985U), BSWAP_32BIG_C(
                        0xe79eafc3U),
                };
                r_rsip_func101(Param_pe5e_func101_009);
            }

            r_rsip_func_sub020(0x000003c1U, 0x07040d05U);
            WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);

            WR1_PROG(REG_1824H, 0x8c100005U);
            r_rsip_func_sub001(0x00410011U);

            static const uint32_t Param_pe5e_func100_008[] =
            {
                BSWAP_32BIG_C(0x7ae06704U), BSWAP_32BIG_C(0xa14e9053U), BSWAP_32BIG_C(0x5da89d5bU), BSWAP_32BIG_C(
                    0x4812fce3U),
            };
            r_rsip_func100(Param_pe5e_func100_008);

            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_pe5e_func101_010[] =
            {
                BSWAP_32BIG_C(0xba175866U), BSWAP_32BIG_C(0xb66526bdU), BSWAP_32BIG_C(0x0adeee4eU), BSWAP_32BIG_C(
                    0x1e0faddcU),
            };
            r_rsip_func101(Param_pe5e_func101_010);

            return RSIP_RET_PASS;
        }
    }
    else
    {
        static const uint32_t Param_pe5e_func101_011[] =
        {
            BSWAP_32BIG_C(0x958a83afU), BSWAP_32BIG_C(0xb6cafe38U), BSWAP_32BIG_C(0x0b95147eU), BSWAP_32BIG_C(
                0x4841babaU),
        };
        r_rsip_func101(Param_pe5e_func101_011);

        return RSIP_RET_PASS;
    }
}
