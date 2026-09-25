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

rsip_ret_t r_rsip_p79 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    r_rsip_func_sub029(0x00790001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000079U);

    static const uint32_t Param_p79_func101_001[] =
    {
        BSWAP_32BIG_C(0x2b060aedU), BSWAP_32BIG_C(0x02cc3e07U), BSWAP_32BIG_C(0x999cc8a6U), BSWAP_32BIG_C(0x457b2a1dU),
    };
    r_rsip_func101(Param_p79_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000eU);

    r_rsip_func_sub009(0x00000079U);

    static const uint32_t Param_p79_func101_002[] =
    {
        BSWAP_32BIG_C(0x0d344f47U), BSWAP_32BIG_C(0x88f78348U), BSWAP_32BIG_C(0x83fdc87cU), BSWAP_32BIG_C(0xe17112deU),
    };
    r_rsip_func101(Param_p79_func101_002);
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

    static const uint32_t Param_p79_func100_001[] =
    {
        BSWAP_32BIG_C(0x121a58afU), BSWAP_32BIG_C(0x31b89e95U), BSWAP_32BIG_C(0x7c50a75bU), BSWAP_32BIG_C(0x7f6a101dU),
    };
    r_rsip_func100(Param_p79_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p79_func102_001[] =
        {
            BSWAP_32BIG_C(0x44e839e4U), BSWAP_32BIG_C(0x76b796ddU), BSWAP_32BIG_C(0x5e7df71aU), BSWAP_32BIG_C(
                0x7b30b69aU),
        };
        r_rsip_func102(Param_p79_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
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

        static const uint32_t Param_p79_func100_002[] =
        {
            BSWAP_32BIG_C(0x876cbc4aU), BSWAP_32BIG_C(0xa0d44789U), BSWAP_32BIG_C(0xd6f218caU), BSWAP_32BIG_C(
                0x94f221aaU),
        };
        r_rsip_func100(Param_p79_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p79_func102_002[] =
            {
                BSWAP_32BIG_C(0x08fcd48cU), BSWAP_32BIG_C(0x6512856eU), BSWAP_32BIG_C(0x7d8bd011U), BSWAP_32BIG_C(
                    0xef2614a5U),
            };
            r_rsip_func102(Param_p79_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p79_func100_003[] =
            {
                BSWAP_32BIG_C(0x390aa612U), BSWAP_32BIG_C(0x5b8e6153U), BSWAP_32BIG_C(0xa2554bdcU), BSWAP_32BIG_C(
                    0x1abd9399U),
            };
            r_rsip_func100(Param_p79_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000228U, 0x00000630U, 0x00000838U, 0x0130000fU, 0x00010001U);
            r_rsip_func_sub045();
            r_rsip_func_sub031(0x0000b400U, 0x00000060U, 0x16b80000U);

            for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 8U)
            {
                r_rsip_func_sub021(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p79_func100_004[] =
                {
                    BSWAP_32BIG_C(0x3d987821U), BSWAP_32BIG_C(0x0fd8a373U), BSWAP_32BIG_C(0xdaa13740U), BSWAP_32BIG_C(
                        0xee2bc1f9U),
                };
                r_rsip_func100(Param_p79_func100_004);
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

                static const uint32_t Param_p79_func101_003[] =
                {
                    BSWAP_32BIG_C(0xd38aee52U), BSWAP_32BIG_C(0x31885469U), BSWAP_32BIG_C(0x6b2888d1U), BSWAP_32BIG_C(
                        0x58d6c5c8U),
                };
                r_rsip_func101(Param_p79_func101_003);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_p79_func100_005[] =
            {
                BSWAP_32BIG_C(0x9d6ad6d3U), BSWAP_32BIG_C(0x77f048edU), BSWAP_32BIG_C(0xb71d10c2U), BSWAP_32BIG_C(
                    0xd556ed37U),
            };
            r_rsip_func100(Param_p79_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p79_func102_003[] =
            {
                BSWAP_32BIG_C(0x84661e22U), BSWAP_32BIG_C(0x574042daU), BSWAP_32BIG_C(0x46ff9e64U), BSWAP_32BIG_C(
                    0x46e316dbU),
            };
            r_rsip_func102(Param_p79_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
