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

rsip_ret_t r_rsip_pe5f (const uint32_t InData_Msg[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        uint32_t       OutData_KDFInfo[],
                        uint32_t       MAX_CNT)
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010100U);
    WR1_PROG(REG_1420H, InData_EncMsgLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000d08U, 0x00A60000U);

    static const uint32_t Param_pe5f_func100_001[] =
    {
        BSWAP_32BIG_C(0x69bc0b6fU), BSWAP_32BIG_C(0x8f8548bdU), BSWAP_32BIG_C(0x2541a304U), BSWAP_32BIG_C(0x69e98137U),
    };
    r_rsip_func100(Param_pe5f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x0000e504U);

        static const uint32_t Param_pe5f_func101_001[] =
        {
            BSWAP_32BIG_C(0x82097ab9U), BSWAP_32BIG_C(0xf7bacb56U), BSWAP_32BIG_C(0x3a5c3f56U), BSWAP_32BIG_C(
                0x526df7c5U),
        };
        r_rsip_func101(Param_pe5f_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x01c80eb2U);

        r_rsip_func_sub009(0x0000e504U);

        static const uint32_t Param_pe5f_func101_002[] =
        {
            BSWAP_32BIG_C(0x52e3088cU), BSWAP_32BIG_C(0xad9a11bbU), BSWAP_32BIG_C(0x0b5f6d6eU), BSWAP_32BIG_C(
                0x2303c734U),
        };
        r_rsip_func101(Param_pe5f_func101_002);
        r_rsip_func044();

        WAIT_STS(REG_2030H, 0, 1);

        static const uint32_t Param_pe5f_func100_002[] =
        {
            BSWAP_32BIG_C(0xc9eb4148U), BSWAP_32BIG_C(0x67466a37U), BSWAP_32BIG_C(0xc6c6e83fU), BSWAP_32BIG_C(
                0x370347c9U),
        };
        r_rsip_func100(Param_pe5f_func100_002);
        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        r_rsip_func_sub016(0x81010100U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        OFS_ADR  = S_RAM[0];

        r_rsip_func_sub021(0x0000a900U, 0x00000002U, 0x00026908U, 0x3800a900U);
        r_rsip_func_sub017(0x00000005U, 0x00260000U);

        static const uint32_t Param_pe5f_func100_003[] =
        {
            BSWAP_32BIG_C(0xa4040ae3U), BSWAP_32BIG_C(0xb8b20338U), BSWAP_32BIG_C(0x0e3d2f1dU), BSWAP_32BIG_C(
                0x67174528U),
        };
        r_rsip_func100(Param_pe5f_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000929U);

            for (iLoop = 0U; iLoop < S_RAM[0] - 9; iLoop = iLoop + 4U)
            {
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

                r_rsip_func_sub001(0x01420011U);

                WR1_PROG(REG_1600H, 0x00002d20U);

                static const uint32_t Param_pe5f_func101_003[] =
                {
                    BSWAP_32BIG_C(0x281251a3U), BSWAP_32BIG_C(0x98bc1514U), BSWAP_32BIG_C(0x16ac16b2U), BSWAP_32BIG_C(
                        0x0678cdd7U),
                };
                r_rsip_func101(Param_pe5f_func101_003);
            }

            r_rsip_func_sub034(0x000037e8U, 0x000033e0U);
            r_rsip_func_sub011(0x38000be9U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

            r_rsip_func_sub001(0x01420005U);
            r_rsip_func_sub001(0x0002000dU);

            iLoop = iLoop + 4;

            static const uint32_t Param_pe5f_func101_004[] =
            {
                BSWAP_32BIG_C(0xbb749ad9U), BSWAP_32BIG_C(0x779d4f56U), BSWAP_32BIG_C(0x9f612a7eU), BSWAP_32BIG_C(
                    0x40685146U),
            };
            r_rsip_func101(Param_pe5f_func101_004);
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00000929U);

            for (iLoop = 0U; iLoop < S_RAM[0] - 5; iLoop = iLoop + 4U)
            {
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

                r_rsip_func_sub001(0x01420011U);

                WR1_PROG(REG_1600H, 0x00002d20U);

                static const uint32_t Param_pe5f_func101_005[] =
                {
                    BSWAP_32BIG_C(0x30d91637U), BSWAP_32BIG_C(0xd7b30125U), BSWAP_32BIG_C(0x849e9f1fU), BSWAP_32BIG_C(
                        0x10c4c164U),
                };
                r_rsip_func101(Param_pe5f_func101_005);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000909U);

            static const uint32_t Param_pe5f_func101_006[] =
            {
                BSWAP_32BIG_C(0x96292e7bU), BSWAP_32BIG_C(0xefa2c4f8U), BSWAP_32BIG_C(0xfbcaf3a3U), BSWAP_32BIG_C(
                    0x5563dadeU),
            };
            r_rsip_func101(Param_pe5f_func101_006);
        }

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 4]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_pe5f_func100_004[] =
        {
            BSWAP_32BIG_C(0x0c383d4aU), BSWAP_32BIG_C(0x02dd0b23U), BSWAP_32BIG_C(0x758e0aa6U), BSWAP_32BIG_C(
                0x82d101e1U),
        };
        r_rsip_func100(Param_pe5f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe5f_func102_001[] =
            {
                BSWAP_32BIG_C(0x5275ede8U), BSWAP_32BIG_C(0x2e156770U), BSWAP_32BIG_C(0xb6807d97U), BSWAP_32BIG_C(
                    0x30d87e23U),
            };
            r_rsip_func102(Param_pe5f_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe5f_func101_007[] =
            {
                BSWAP_32BIG_C(0x531b7cd8U), BSWAP_32BIG_C(0x0d87988dU), BSWAP_32BIG_C(0x0cb001f8U), BSWAP_32BIG_C(
                    0x7b4706ddU),
            };
            r_rsip_func101(Param_pe5f_func101_007);
        }
    }
    else
    {
        static const uint32_t Param_pe5f_func101_008[] =
        {
            BSWAP_32BIG_C(0xbd40e03fU), BSWAP_32BIG_C(0xf8c0d5ccU), BSWAP_32BIG_C(0x4a604564U), BSWAP_32BIG_C(
                0x50a74ffdU),
        };
        r_rsip_func101(Param_pe5f_func101_008);
    }

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    r_rsip_func_sub043();

    WAIT_STS(REG_2030H, 4, 1);

    r_rsip_func_sub009(0x0000e502U);

    static const uint32_t Param_pe5f_func101_009[] =
    {
        BSWAP_32BIG_C(0xd2befe6eU), BSWAP_32BIG_C(0x0f9d1750U), BSWAP_32BIG_C(0x6122529bU), BSWAP_32BIG_C(0x4394d123U),
    };
    r_rsip_func101(Param_pe5f_func101_009);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000e505U);

    static const uint32_t Param_pe5f_func101_010[] =
    {
        BSWAP_32BIG_C(0x21cba769U), BSWAP_32BIG_C(0x8adce027U), BSWAP_32BIG_C(0xd3bad985U), BSWAP_32BIG_C(0x4803278eU),
    };
    r_rsip_func101(Param_pe5f_func101_010);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x01c80eb2U);

    r_rsip_func_sub009(0x0000e505U);

    static const uint32_t Param_pe5f_func101_011[] =
    {
        BSWAP_32BIG_C(0xfbbe250aU), BSWAP_32BIG_C(0xecd790dbU), BSWAP_32BIG_C(0xbea3377eU), BSWAP_32BIG_C(0x07e9814bU),
    };
    r_rsip_func101(Param_pe5f_func101_011);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008e7U);

    static const uint32_t Param_pe5f_func100_005[] =
    {
        BSWAP_32BIG_C(0x8ff1c677U), BSWAP_32BIG_C(0xfcd30d2fU), BSWAP_32BIG_C(0xd6d937b7U), BSWAP_32BIG_C(0xb3ebb511U),
    };
    r_rsip_func100(Param_pe5f_func100_005);
    r_rsip_func_sub016(0x810101e0U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
    {
        static const uint32_t Param_pe5f_func100_006[] =
        {
            BSWAP_32BIG_C(0x7dd7014aU), BSWAP_32BIG_C(0xbacd92b5U), BSWAP_32BIG_C(0xab450fa2U), BSWAP_32BIG_C(
                0xe7e70f12U),
        };
        r_rsip_func100(Param_pe5f_func100_006);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00850011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 1]);

        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1600H, 0x00000004U);

        static const uint32_t Param_pe5f_func101_012[] =
        {
            BSWAP_32BIG_C(0x8f764bdfU), BSWAP_32BIG_C(0x8380aa68U), BSWAP_32BIG_C(0x732f923cU), BSWAP_32BIG_C(
                0xb7b2a0feU),
        };
        r_rsip_func101(Param_pe5f_func101_012);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x380008efU);

    static const uint32_t Param_pe5f_func100_007[] =
    {
        BSWAP_32BIG_C(0xf2d2c577U), BSWAP_32BIG_C(0x3812a8c1U), BSWAP_32BIG_C(0xc7f906baU), BSWAP_32BIG_C(0x5eebeccbU),
    };
    r_rsip_func100(Param_pe5f_func100_007);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 1]);

    static const uint32_t Param_pe5f_func100_008[] =
    {
        BSWAP_32BIG_C(0x247b4071U), BSWAP_32BIG_C(0x7618d984U), BSWAP_32BIG_C(0x9b557eedU), BSWAP_32BIG_C(0x3f5ccdf0U),
    };
    r_rsip_func100(Param_pe5f_func100_008);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[0]);

    static const uint32_t Param_pe5f_func102_002[] =
    {
        BSWAP_32BIG_C(0xf7ff9d4cU), BSWAP_32BIG_C(0xd185a8ccU), BSWAP_32BIG_C(0xd3e734e1U), BSWAP_32BIG_C(0xef6c21c3U),
    };
    r_rsip_func102(Param_pe5f_func102_002);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
