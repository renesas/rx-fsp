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

rsip_ret_t r_rsip_p56 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    r_rsip_func_sub029(0x00560001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000056U);

    static const uint32_t Param_p56_func101_001[] =
    {
        BSWAP_32BIG_C(0x08d8d9b7U), BSWAP_32BIG_C(0xec63b582U), BSWAP_32BIG_C(0xacd11dd4U), BSWAP_32BIG_C(0x0c650236U),
    };
    r_rsip_func101(Param_p56_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000cU);

    r_rsip_func_sub009(0x00000056U);

    static const uint32_t Param_p56_func101_002[] =
    {
        BSWAP_32BIG_C(0xd89d8fc5U), BSWAP_32BIG_C(0x6bed27e6U), BSWAP_32BIG_C(0x0e74c5a4U), BSWAP_32BIG_C(0x0cdc8cadU),
    };
    r_rsip_func101(Param_p56_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000043c2U, 0x40000f00U, 0xe8009107U);

    WR1_PROG(REG_1404H, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[65]);

    WR1_PROG(REG_1404H, 0x12200000U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[69]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p56_func100_001[] =
    {
        BSWAP_32BIG_C(0x0157afb8U), BSWAP_32BIG_C(0x2f232e41U), BSWAP_32BIG_C(0x19140bf5U), BSWAP_32BIG_C(0xb3f59345U),
    };
    r_rsip_func100(Param_p56_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p56_func102_001[] =
        {
            BSWAP_32BIG_C(0xe9e1f7c8U), BSWAP_32BIG_C(0x5084d1ecU), BSWAP_32BIG_C(0x51317a24U), BSWAP_32BIG_C(
                0xdf0656a7U),
        };
        r_rsip_func102(Param_p56_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x20200010U);

        r_rsip_func_sub024(0x00003fc2U, 0x40000f00U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x11200000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
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

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p56_func100_002[] =
        {
            BSWAP_32BIG_C(0x311b0b8cU), BSWAP_32BIG_C(0x25f105c5U), BSWAP_32BIG_C(0x49f0e223U), BSWAP_32BIG_C(
                0x9774318fU),
        };
        r_rsip_func100(Param_p56_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p56_func102_002[] =
            {
                BSWAP_32BIG_C(0x6a9386d1U), BSWAP_32BIG_C(0x2a33d4b8U), BSWAP_32BIG_C(0x48d64fddU), BSWAP_32BIG_C(
                    0x36ff0c16U),
            };
            r_rsip_func102(Param_p56_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p56_func100_003[] =
            {
                BSWAP_32BIG_C(0x54657bf5U), BSWAP_32BIG_C(0x62deaedeU), BSWAP_32BIG_C(0x081ae650U), BSWAP_32BIG_C(
                    0x79e023f6U),
            };
            r_rsip_func100(Param_p56_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000228U, 0x00000630U, 0x00000838U, 0x0120000fU, 0x00010001U);
            r_rsip_func_sub045();
            r_rsip_func_sub031(0x0000b400U, 0x00000040U, 0x17380000U);

            for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
            {
                r_rsip_func_sub021(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p56_func100_004[] =
                {
                    BSWAP_32BIG_C(0xfc31b9f4U), BSWAP_32BIG_C(0x0552092dU), BSWAP_32BIG_C(0x5991191fU), BSWAP_32BIG_C(
                        0x4d2da9c5U),
                };
                r_rsip_func100(Param_p56_func100_004);
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

                static const uint32_t Param_p56_func101_003[] =
                {
                    BSWAP_32BIG_C(0x46aec07fU), BSWAP_32BIG_C(0x3a42d026U), BSWAP_32BIG_C(0xb31be112U), BSWAP_32BIG_C(
                        0x989be213U),
                };
                r_rsip_func101(Param_p56_func101_003);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_p56_func100_005[] =
            {
                BSWAP_32BIG_C(0x41e17f00U), BSWAP_32BIG_C(0xc7aa6866U), BSWAP_32BIG_C(0x4e1b88c9U), BSWAP_32BIG_C(
                    0xe91d642bU),
            };
            r_rsip_func100(Param_p56_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p56_func102_003[] =
            {
                BSWAP_32BIG_C(0x1f2a78abU), BSWAP_32BIG_C(0x365711bcU), BSWAP_32BIG_C(0xa7c4ec99U), BSWAP_32BIG_C(
                    0x1561531eU),
            };
            r_rsip_func102(Param_p56_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
