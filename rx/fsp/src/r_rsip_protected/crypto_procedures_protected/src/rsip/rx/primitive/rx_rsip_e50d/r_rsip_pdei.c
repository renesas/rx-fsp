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

rsip_ret_t r_rsip_pdei (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00de0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000deU);

    static const uint32_t Param_pdei_func101_001[] =
    {
        BSWAP_32BIG_C(0x14ea9347U), BSWAP_32BIG_C(0x3f843457U), BSWAP_32BIG_C(0x9a4aed25U), BSWAP_32BIG_C(0xe4c8a93aU),
    };
    r_rsip_func101(Param_pdei_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000eU);

    r_rsip_func_sub009(0x000000deU);

    static const uint32_t Param_pdei_func101_002[] =
    {
        BSWAP_32BIG_C(0x881285e8U), BSWAP_32BIG_C(0x1b20d557U), BSWAP_32BIG_C(0xdbfcf20dU), BSWAP_32BIG_C(0x4a2e4726U),
    };
    r_rsip_func101(Param_pdei_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000063c2U, 0x40001800U, 0xe8009107U);

    WR1_PROG(REG_1404H, 0x14b00000U);
    for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1404H, 0x12200000U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pdei_func100_001[] =
    {
        BSWAP_32BIG_C(0x5b2d08a2U), BSWAP_32BIG_C(0xd54c42d5U), BSWAP_32BIG_C(0xad140349U), BSWAP_32BIG_C(0x727ac08bU),
    };
    r_rsip_func100(Param_pdei_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdei_func102_001[] =
        {
            BSWAP_32BIG_C(0xc831a1a3U), BSWAP_32BIG_C(0xbf2b65d6U), BSWAP_32BIG_C(0x48bb7583U), BSWAP_32BIG_C(
                0xfa5f2305U),
        };
        r_rsip_func102(Param_pdei_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x30300010U);

        r_rsip_func_sub024(0x00005fc2U, 0x40001700U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x10a00000U);
        for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 8U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
            r_rsip_func_sub001(0x00c20021U);
        }

        r_rsip_func_sub044();
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800dbe0U, 0x00260000U);

        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0017dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x3030000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c0017dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x3030000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x3030000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pdei_func100_002[] =
        {
            BSWAP_32BIG_C(0x4aab5316U), BSWAP_32BIG_C(0x5d25324aU), BSWAP_32BIG_C(0x871d9672U), BSWAP_32BIG_C(
                0xa4fb0f4cU),
        };
        r_rsip_func100(Param_pdei_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdei_func102_002[] =
            {
                BSWAP_32BIG_C(0x6b406dc9U), BSWAP_32BIG_C(0x525c98d3U), BSWAP_32BIG_C(0x0b19f2edU), BSWAP_32BIG_C(
                    0x3a5530a6U),
            };
            r_rsip_func102(Param_pdei_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdei_func100_003[] =
            {
                BSWAP_32BIG_C(0x912fe109U), BSWAP_32BIG_C(0xfcdcc02eU), BSWAP_32BIG_C(0x25d0b848U), BSWAP_32BIG_C(
                    0x555f7c8bU),
            };
            r_rsip_func100(Param_pdei_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000228U, 0x00000630U, 0x00000838U, 0x0130000fU, 0x00010001U);
            r_rsip_func_sub045();
            r_rsip_func_sub031(0x0000b400U, 0x00000060U, 0x16b80000U);

            for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 8U)
            {
                r_rsip_func_sub021(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_pdei_func100_004[] =
                {
                    BSWAP_32BIG_C(0x8f7855c7U), BSWAP_32BIG_C(0x4e57b661U), BSWAP_32BIG_C(0xa744fd0aU), BSWAP_32BIG_C(
                        0xa67c335dU),
                };
                r_rsip_func100(Param_pdei_func100_004);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);

                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1600H, 0x00000008U);

                static const uint32_t Param_pdei_func101_003[] =
                {
                    BSWAP_32BIG_C(0x0439a42dU), BSWAP_32BIG_C(0x37a2e98dU), BSWAP_32BIG_C(0x7ff81007U), BSWAP_32BIG_C(
                        0x7d13440cU),
                };
                r_rsip_func101(Param_pdei_func101_003);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_pdei_func100_005[] =
            {
                BSWAP_32BIG_C(0x43359fc5U), BSWAP_32BIG_C(0x62fabc59U), BSWAP_32BIG_C(0x2ef33344U), BSWAP_32BIG_C(
                    0xbefab3afU),
            };
            r_rsip_func100(Param_pdei_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_pdei_func101_004[] =
            {
                BSWAP_32BIG_C(0x184d7b98U), BSWAP_32BIG_C(0x7645c7e5U), BSWAP_32BIG_C(0xe39298e8U), BSWAP_32BIG_C(
                    0x21d1422dU),
            };
            r_rsip_func101(Param_pdei_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
