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

rsip_ret_t r_rsip_pf1 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00f10001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010380U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    WR1_PROG(REG_1444H, 0x000017c7U);
    WR1_PROG(REG_1608H, 0x8098001eU);
    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Signature[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0U; iLoop < 8U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 3U; iLoop++)
    {
        r_rsip_func_sub021(0x00000bffU, 0x30003380U, 0x00070020U, 0x0000d3e0U);
        r_rsip_func_sub021(0x00030040U, 0x0000381eU, 0x38000c00U, 0x1000d3e0U);
        r_rsip_func_sub021(0x00050040U, 0x0000381eU, 0x000037beU, 0x0000a7a0U);
        r_rsip_func_sub021(0x00000004U, 0x0000383dU, 0x38001001U, 0x1000d3e0U);
        r_rsip_func_sub006(0x00000080U, 0x38000fffU, 0x00260000U);

        WR1_PROG(REG_1600H, 0x0000a7c0U);
        WR1_PROG(REG_1600H, 0x00000020U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x30000f5aU, 0x00030020U, 0x0000d3e1U, 0x00000060U);
    r_rsip_func_sub021(0x38000f9cU, 0x1000d3e1U, 0x00000080U, 0x38008be0U);
    r_rsip_func_sub017(0x00000003U, 0x00A60000U);

    static const uint32_t Param_pf1_func100_001[] =
    {
        BSWAP_32BIG_C(0xc9e40ea7U), BSWAP_32BIG_C(0x8d878eeeU), BSWAP_32BIG_C(0x9e3728c5U), BSWAP_32BIG_C(0x24051f49U),
    };
    r_rsip_func100(Param_pf1_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf1_func102_001[] =
        {
            BSWAP_32BIG_C(0x5e342aa0U), BSWAP_32BIG_C(0xe18fe80eU), BSWAP_32BIG_C(0x5ad565edU), BSWAP_32BIG_C(
                0x419255b9U),
        };
        r_rsip_func102(Param_pf1_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x8190001eU);

        WR1_PROG(REG_1404H, 0x19100000U);
        r_rsip_func_sub001(0x00c90021U);

        WR1_PROG(REG_1404H, 0x19600000U);
        r_rsip_func_sub001(0x00c90021U);

        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        r_rsip_func_sub023(0x0000b7c0U, 0x00000040U, 0x8188001eU);
        r_rsip_func_sub001(0x00890021U);

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x8088001eU);
        r_rsip_func_sub001(0x03420021U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x000000f1U);

        static const uint32_t Param_pf1_func101_001[] =
        {
            BSWAP_32BIG_C(0xa8a4179bU), BSWAP_32BIG_C(0xc2eed50fU), BSWAP_32BIG_C(0x510d9eb3U), BSWAP_32BIG_C(
                0x3422de15U),
        };
        r_rsip_func101(Param_pf1_func101_001);
        r_rsip_func043();

        r_rsip_func075();

        WR1_PROG(REG_1600H, 0x000034feU);

        r_rsip_func_sub009(0x000000f1U);

        static const uint32_t Param_pf1_func101_002[] =
        {
            BSWAP_32BIG_C(0x3e93b860U), BSWAP_32BIG_C(0x17682ed1U), BSWAP_32BIG_C(0xa93c835fU), BSWAP_32BIG_C(
                0x9d80ee11U),
        };
        r_rsip_func101(Param_pf1_func101_002);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xe8009107U);

        r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80900001U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
        r_rsip_func_sub001(0x03420021U);

        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
        r_rsip_func_sub001(0x03420021U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_pf1_func100_002[] =
        {
            BSWAP_32BIG_C(0x0cf60d89U), BSWAP_32BIG_C(0x3b3c048dU), BSWAP_32BIG_C(0x7ac5589fU), BSWAP_32BIG_C(
                0x8d5d100bU),
        };
        r_rsip_func100(Param_pf1_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf1_func102_002[] =
            {
                BSWAP_32BIG_C(0x5eb454b1U), BSWAP_32BIG_C(0xc634e01dU), BSWAP_32BIG_C(0xcaa7caa5U), BSWAP_32BIG_C(
                    0x00dc1d4eU),
            };
            r_rsip_func102(Param_pf1_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub009(0x000000f1U);

            static const uint32_t Param_pf1_func101_003[] =
            {
                BSWAP_32BIG_C(0x4eca4636U), BSWAP_32BIG_C(0x38d7204cU), BSWAP_32BIG_C(0x30ba72c4U), BSWAP_32BIG_C(
                    0xf0d83717U),
            };
            r_rsip_func101(Param_pf1_func101_003);
            r_rsip_func073(InData_DomainParam);

            static const uint32_t Param_pf1_func100_003[] =
            {
                BSWAP_32BIG_C(0x2e653441U), BSWAP_32BIG_C(0x5941e497U), BSWAP_32BIG_C(0xf1d7947aU), BSWAP_32BIG_C(
                    0x56b1914fU),
            };
            r_rsip_func100(Param_pf1_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pf1_func102_003[] =
                {
                    BSWAP_32BIG_C(0x7ae739f0U), BSWAP_32BIG_C(0x1554abc0U), BSWAP_32BIG_C(0x2e46887cU), BSWAP_32BIG_C(
                        0x1b40e5f8U),
                };
                r_rsip_func102(Param_pf1_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pf1_func102_004[] =
                {
                    BSWAP_32BIG_C(0x2b8d8432U), BSWAP_32BIG_C(0x91cab050U), BSWAP_32BIG_C(0x678fce1eU), BSWAP_32BIG_C(
                        0xb30291eeU),
                };
                r_rsip_func102(Param_pf1_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
