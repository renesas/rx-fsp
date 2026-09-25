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

void r_rsip_func057 (const uint32_t ARG1[], const uint32_t ARG2[], uint32_t ARG3[])
{
    uint32_t iLoop = 0U;
    uint32_t oLoop = 0U;

    r_rsip_func_sub020(0x000003c1U, 0x08000045U);
    WR4_ADDR(REG_1420H, &ARG1[0]);

    r_rsip_func_sub020(0x000000a1U, 0x08000054U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    r_rsip_func_sub009(0x0000f057U);

    static const uint32_t Param_func057_func101_001[] =
    {
        BSWAP_32BIG_C(0xfbb46926U), BSWAP_32BIG_C(0x34e84c49U), BSWAP_32BIG_C(0xcad49285U), BSWAP_32BIG_C(0x7967a604U),
    };
    r_rsip_func101(Param_func057_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x000000ffU);

    static const uint32_t Param_func057_func101_002[] =
    {
        BSWAP_32BIG_C(0x5e326c97U), BSWAP_32BIG_C(0xb51f27fcU), BSWAP_32BIG_C(0xe532fd6dU), BSWAP_32BIG_C(0x4dc798f9U),
    };
    r_rsip_func101(Param_func057_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e4U);

    r_rsip_func_sub009(0x000000feU);

    static const uint32_t Param_func057_func101_003[] =
    {
        BSWAP_32BIG_C(0xeeab5fedU), BSWAP_32BIG_C(0xc4e6908cU), BSWAP_32BIG_C(0x7bc48b9fU), BSWAP_32BIG_C(0x4981c349U),
    };
    r_rsip_func101(Param_func057_func101_003);
    r_rsip_func044();

    static const uint32_t Param_func057_func100_001[] =
    {
        BSWAP_32BIG_C(0x4e706d9dU), BSWAP_32BIG_C(0xf0ff39aaU), BSWAP_32BIG_C(0xfe0a74b5U), BSWAP_32BIG_C(0x93e8bd73U),
    };
    r_rsip_func100(Param_func057_func100_001);

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);

    r_rsip_func081();

    r_rsip_func_sub014(0x00007c01U, 0x00600000U);

    oLoop = 0U;
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); iLoop = iLoop + 4U)
        {
            static const uint32_t Param_func057_func100_002[] =
            {
                BSWAP_32BIG_C(0xbce290deU), BSWAP_32BIG_C(0xbfb8f3a6U), BSWAP_32BIG_C(0x72096da3U), BSWAP_32BIG_C(
                    0x4cd8a193U),
            };
            r_rsip_func100(Param_func057_func100_002);
            r_rsip_func_sub020(0x000003c1U, 0xd900090dU);
            WR4_ADDR(REG_1420H, &ARG2[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            r_rsip_func_sub001(0x00810011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG3[1 + iLoop]);

            static const uint32_t Param_func057_func101_004[] =
            {
                BSWAP_32BIG_C(0x4b43f982U), BSWAP_32BIG_C(0x4a5f8607U), BSWAP_32BIG_C(0xffbbf759U), BSWAP_32BIG_C(
                    0x2218168fU),
            };
            r_rsip_func101(Param_func057_func101_004);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        static const uint32_t Param_func057_func101_005[] =
        {
            BSWAP_32BIG_C(0xfa25dbcdU), BSWAP_32BIG_C(0x03870f2bU), BSWAP_32BIG_C(0xf8e6fd30U), BSWAP_32BIG_C(
                0xcb144d1cU),
        };
        r_rsip_func101(Param_func057_func101_005);
    }
    else
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); iLoop = iLoop + 4U)
        {
            static const uint32_t Param_func057_func100_003[] =
            {
                BSWAP_32BIG_C(0x428895d9U), BSWAP_32BIG_C(0x6c66b15fU), BSWAP_32BIG_C(0xc60c6650U), BSWAP_32BIG_C(
                    0x6a55c92cU),
            };
            r_rsip_func100(Param_func057_func100_003);
            r_rsip_func_sub020(0x000003c1U, 0xd900090dU);
            WR4_ADDR(REG_1420H, &ARG2[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_func_sub001(0x00810011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG3[1 + iLoop]);

            static const uint32_t Param_func057_func101_006[] =
            {
                BSWAP_32BIG_C(0x83f92b6bU), BSWAP_32BIG_C(0x19af22c6U), BSWAP_32BIG_C(0x3595a599U), BSWAP_32BIG_C(
                    0x8af82ee7U),
            };
            r_rsip_func101(Param_func057_func101_006);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        static const uint32_t Param_func057_func101_007[] =
        {
            BSWAP_32BIG_C(0x614e9f24U), BSWAP_32BIG_C(0xa782d33eU), BSWAP_32BIG_C(0x994f8bf4U), BSWAP_32BIG_C(
                0xee2f0534U),
        };
        r_rsip_func101(Param_func057_func101_007);
    }

    static const uint32_t Param_func057_func100_004[] =
    {
        BSWAP_32BIG_C(0xe8d880b6U), BSWAP_32BIG_C(0xd2166b1aU), BSWAP_32BIG_C(0x3a3b5779U), BSWAP_32BIG_C(0xc116ad24U),
    };
    r_rsip_func100(Param_func057_func100_004);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG3[1 + oLoop]);

    r_rsip_func_sub020(0x000003c1U, 0x0900090dU);
    WR4_ADDR(REG_1420H, &ARG2[iLoop]);

    WR1_PROG(REG_1824H, 0x9c100005U);
    r_rsip_func_sub001(0x00410011U);

    r_rsip_func_sub014(0x00007c1cU, 0x00602000U);
}
