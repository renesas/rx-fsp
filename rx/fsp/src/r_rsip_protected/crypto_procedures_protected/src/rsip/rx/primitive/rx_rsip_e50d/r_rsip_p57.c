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

rsip_ret_t r_rsip_p57 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    r_rsip_func_sub029(0x00570001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000057U);

    static const uint32_t Param_p57_func101_001[] =
    {
        BSWAP_32BIG_C(0x71816d76U), BSWAP_32BIG_C(0x0772b2dcU), BSWAP_32BIG_C(0x28cb397eU), BSWAP_32BIG_C(0x2bf83148U),
    };
    r_rsip_func101(Param_p57_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000dU);

    r_rsip_func_sub009(0x00000057U);

    static const uint32_t Param_p57_func101_002[] =
    {
        BSWAP_32BIG_C(0x872690d0U), BSWAP_32BIG_C(0xce91704cU), BSWAP_32BIG_C(0x1e2cde9aU), BSWAP_32BIG_C(0x18c49ab0U),
    };
    r_rsip_func101(Param_p57_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00007fc2U, 0x40000f00U, 0xf7009d07U);

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

    WR1_PROG(REG_1A2CH, 0x40000f00U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);

    WR1_PROG(REG_1404H, 0x13280000U);
    for (iLoop = 64; iLoop < 128U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[129]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p57_func100_001[] =
    {
        BSWAP_32BIG_C(0x4e8b04f5U), BSWAP_32BIG_C(0xa97cdb80U), BSWAP_32BIG_C(0xfd61ee8aU), BSWAP_32BIG_C(0x681fb421U),
    };
    r_rsip_func100(Param_p57_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p57_func102_001[] =
        {
            BSWAP_32BIG_C(0x3566da44U), BSWAP_32BIG_C(0xf6747712U), BSWAP_32BIG_C(0x1c857583U), BSWAP_32BIG_C(
                0xb278259fU),
        };
        r_rsip_func102(Param_p57_func102_001);
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

        static const uint32_t Param_p57_func100_002[] =
        {
            BSWAP_32BIG_C(0x6b0d8735U), BSWAP_32BIG_C(0x08db191bU), BSWAP_32BIG_C(0x50e95455U), BSWAP_32BIG_C(
                0x44e69d3fU),
        };
        r_rsip_func100(Param_p57_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p57_func102_002[] =
            {
                BSWAP_32BIG_C(0x80f54b19U), BSWAP_32BIG_C(0x8811726dU), BSWAP_32BIG_C(0xf5517926U), BSWAP_32BIG_C(
                    0x5346a01aU),
            };
            r_rsip_func102(Param_p57_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p57_func100_003[] =
            {
                BSWAP_32BIG_C(0x95c1eb07U), BSWAP_32BIG_C(0xa7ee65a0U), BSWAP_32BIG_C(0xb5be4de1U), BSWAP_32BIG_C(
                    0x0fbe171dU),
            };
            r_rsip_func100(Param_p57_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x20200000U, 0x00010001U);
            r_rsip_func_sub045();
            r_rsip_func_sub031(0x0000b400U, 0x00000040U, 0x17380000U);

            for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
            {
                r_rsip_func_sub021(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p57_func100_004[] =
                {
                    BSWAP_32BIG_C(0xabda613fU), BSWAP_32BIG_C(0x70f846d6U), BSWAP_32BIG_C(0xa11dd595U), BSWAP_32BIG_C(
                        0xe288d5a2U),
                };
                r_rsip_func100(Param_p57_func100_004);
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

                static const uint32_t Param_p57_func101_003[] =
                {
                    BSWAP_32BIG_C(0x27705eb4U), BSWAP_32BIG_C(0xf1263978U), BSWAP_32BIG_C(0xcc89a3adU), BSWAP_32BIG_C(
                        0x8ec8b960U),
                };
                r_rsip_func101(Param_p57_func101_003);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_p57_func100_005[] =
            {
                BSWAP_32BIG_C(0xf85dd313U), BSWAP_32BIG_C(0xf1cc1bf1U), BSWAP_32BIG_C(0xa1aead35U), BSWAP_32BIG_C(
                    0x2c1b887bU),
            };
            r_rsip_func100(Param_p57_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p57_func102_003[] =
            {
                BSWAP_32BIG_C(0xd651583aU), BSWAP_32BIG_C(0xbcb9ed35U), BSWAP_32BIG_C(0xfdd58eebU), BSWAP_32BIG_C(
                    0x59498c17U),
            };
            r_rsip_func102(Param_p57_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
