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

rsip_ret_t r_rsip_p7c (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    r_rsip_func_sub029(0x007c0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000007cU);

    static const uint32_t Param_p7c_func101_001[] =
    {
        BSWAP_32BIG_C(0xb223c637U), BSWAP_32BIG_C(0x2ff6cc34U), BSWAP_32BIG_C(0xfd89beafU), BSWAP_32BIG_C(0x76dbd3b9U),
    };
    r_rsip_func101(Param_p7c_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000011U);

    r_rsip_func_sub009(0x0000007cU);

    static const uint32_t Param_p7c_func101_002[] =
    {
        BSWAP_32BIG_C(0xfee0bfd4U), BSWAP_32BIG_C(0xb5488df8U), BSWAP_32BIG_C(0xffac245bU), BSWAP_32BIG_C(0x636dcfe7U),
    };
    r_rsip_func101(Param_p7c_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x0000ffc2U, 0x40001f00U, 0xf7009d07U);

    WR1_PROG(REG_1404H, 0x14300000U);
    for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40001f00U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);

    WR1_PROG(REG_1404H, 0x12280000U);
    for (iLoop = 128U; iLoop < 256U; iLoop = iLoop + 8U)
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

    static const uint32_t Param_p7c_func100_001[] =
    {
        BSWAP_32BIG_C(0x9a18d495U), BSWAP_32BIG_C(0xc5bcab93U), BSWAP_32BIG_C(0x9ab26619U), BSWAP_32BIG_C(0x0bf5d89bU),
    };
    r_rsip_func100(Param_p7c_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7c_func102_001[] =
        {
            BSWAP_32BIG_C(0x1c089257U), BSWAP_32BIG_C(0x90bc4841U), BSWAP_32BIG_C(0x5d217f73U), BSWAP_32BIG_C(
                0x2ae1105bU),
        };
        r_rsip_func102(Param_p7c_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x40400010U);

        r_rsip_func_sub024(0x00007fc2U, 0x40001f00U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x10200000U);
        for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 8U)
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

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x4040000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p7c_func100_002[] =
        {
            BSWAP_32BIG_C(0x018ca8f7U), BSWAP_32BIG_C(0x82731ce0U), BSWAP_32BIG_C(0xc0ad7452U), BSWAP_32BIG_C(
                0x0e9b2fe0U),
        };
        r_rsip_func100(Param_p7c_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7c_func102_002[] =
            {
                BSWAP_32BIG_C(0x410ec4f1U), BSWAP_32BIG_C(0xaeecee64U), BSWAP_32BIG_C(0x8b7bc7d2U), BSWAP_32BIG_C(
                    0x79db06ceU),
            };
            r_rsip_func102(Param_p7c_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7c_func100_003[] =
            {
                BSWAP_32BIG_C(0x9bb0b297U), BSWAP_32BIG_C(0xc7a449cdU), BSWAP_32BIG_C(0x57cb0011U), BSWAP_32BIG_C(
                    0x4ba84886U),
            };
            r_rsip_func100(Param_p7c_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x40400000U, 0x00010001U);
            r_rsip_func_sub045();
            r_rsip_func_sub031(0x0000b400U, 0x00000080U, 0x16380000U);

            for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 8U)
            {
                r_rsip_func_sub021(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p7c_func100_004[] =
                {
                    BSWAP_32BIG_C(0x1d61de16U), BSWAP_32BIG_C(0xd8f2e129U), BSWAP_32BIG_C(0x62f4b3b3U), BSWAP_32BIG_C(
                        0x85aadc3fU),
                };
                r_rsip_func100(Param_p7c_func100_004);
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

                static const uint32_t Param_p7c_func101_003[] =
                {
                    BSWAP_32BIG_C(0xd1a59372U), BSWAP_32BIG_C(0xd4ad00fcU), BSWAP_32BIG_C(0x9c6ce7feU), BSWAP_32BIG_C(
                        0x1e2c1c32U),
                };
                r_rsip_func101(Param_p7c_func101_003);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_p7c_func100_005[] =
            {
                BSWAP_32BIG_C(0xaee0ec3aU), BSWAP_32BIG_C(0x7e49c358U), BSWAP_32BIG_C(0xa8a65175U), BSWAP_32BIG_C(
                    0xcd919889U),
            };
            r_rsip_func100(Param_p7c_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p7c_func102_003[] =
            {
                BSWAP_32BIG_C(0xd8cfdd42U), BSWAP_32BIG_C(0x13887dfeU), BSWAP_32BIG_C(0xab9f4a37U), BSWAP_32BIG_C(
                    0x3ff83683U),
            };
            r_rsip_func102(Param_p7c_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
