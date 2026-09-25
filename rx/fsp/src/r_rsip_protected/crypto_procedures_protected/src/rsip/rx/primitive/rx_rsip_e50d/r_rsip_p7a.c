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

rsip_ret_t r_rsip_p7a (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    r_rsip_func_sub029(0x007a0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000007aU);

    static const uint32_t Param_p7a_func101_001[] =
    {
        BSWAP_32BIG_C(0xf073d6b0U), BSWAP_32BIG_C(0x0114f3a7U), BSWAP_32BIG_C(0x6d19c585U), BSWAP_32BIG_C(0xe7530322U),
    };
    r_rsip_func101(Param_p7a_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000fU);

    r_rsip_func_sub009(0x0000007aU);

    static const uint32_t Param_p7a_func101_002[] =
    {
        BSWAP_32BIG_C(0xf2aea650U), BSWAP_32BIG_C(0xe57f24a2U), BSWAP_32BIG_C(0xad11ce9eU), BSWAP_32BIG_C(0x74663044U),
    };
    r_rsip_func101(Param_p7a_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x0000bfc2U, 0x40001700U, 0xf7009d07U);

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

    WR1_PROG(REG_1A2CH, 0x40001700U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);

    WR1_PROG(REG_1404H, 0x12a80000U);
    for (iLoop = 96; iLoop < 192; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p7a_func100_001[] =
    {
        BSWAP_32BIG_C(0x5e04c84eU), BSWAP_32BIG_C(0x246e05e4U), BSWAP_32BIG_C(0xb5926a35U), BSWAP_32BIG_C(0x3d558a81U),
    };
    r_rsip_func100(Param_p7a_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7a_func102_001[] =
        {
            BSWAP_32BIG_C(0xfe3036afU), BSWAP_32BIG_C(0x732d72d1U), BSWAP_32BIG_C(0x37fa0b1eU), BSWAP_32BIG_C(
                0xb0e30baaU),
        };
        r_rsip_func102(Param_p7a_func102_001);
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

        static const uint32_t Param_p7a_func100_002[] =
        {
            BSWAP_32BIG_C(0x0d9b9f7dU), BSWAP_32BIG_C(0xf79c6418U), BSWAP_32BIG_C(0xc4d90298U), BSWAP_32BIG_C(
                0x018ee331U),
        };
        r_rsip_func100(Param_p7a_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7a_func102_002[] =
            {
                BSWAP_32BIG_C(0xd601f82fU), BSWAP_32BIG_C(0x424d1404U), BSWAP_32BIG_C(0x3784bf29U), BSWAP_32BIG_C(
                    0xdbf55555U),
            };
            r_rsip_func102(Param_p7a_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7a_func100_003[] =
            {
                BSWAP_32BIG_C(0x431cd4baU), BSWAP_32BIG_C(0x96762388U), BSWAP_32BIG_C(0x9fb62435U), BSWAP_32BIG_C(
                    0xc14ab6e2U),
            };
            r_rsip_func100(Param_p7a_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x30300000U, 0x00010001U);
            r_rsip_func_sub045();
            r_rsip_func_sub031(0x0000b400U, 0x00000060U, 0x16b80000U);

            for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 8U)
            {
                r_rsip_func_sub021(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p7a_func100_004[] =
                {
                    BSWAP_32BIG_C(0xdc513213U), BSWAP_32BIG_C(0x5e4981b0U), BSWAP_32BIG_C(0x374b74deU), BSWAP_32BIG_C(
                        0x105a808cU),
                };
                r_rsip_func100(Param_p7a_func100_004);
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

                static const uint32_t Param_p7a_func101_003[] =
                {
                    BSWAP_32BIG_C(0x6ccbcc53U), BSWAP_32BIG_C(0xd48bea00U), BSWAP_32BIG_C(0xa8c0e52bU), BSWAP_32BIG_C(
                        0xdc91c23eU),
                };
                r_rsip_func101(Param_p7a_func101_003);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_p7a_func100_005[] =
            {
                BSWAP_32BIG_C(0xc6d2d227U), BSWAP_32BIG_C(0x5104ceabU), BSWAP_32BIG_C(0xc24ba223U), BSWAP_32BIG_C(
                    0xa0f480aeU),
            };
            r_rsip_func100(Param_p7a_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p7a_func102_003[] =
            {
                BSWAP_32BIG_C(0x5deac40cU), BSWAP_32BIG_C(0xec32e019U), BSWAP_32BIG_C(0x1bfe2289U), BSWAP_32BIG_C(
                    0xacb3a574U),
            };
            r_rsip_func102(Param_p7a_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
