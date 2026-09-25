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

void r_rsip_func017 (uint32_t ARG1)
{
    uint32_t oLoop = 0U;

    static const uint32_t Param_func017_func100_001[] =
    {
        BSWAP_32BIG_C(0xcbbca748U), BSWAP_32BIG_C(0xf596ef55U), BSWAP_32BIG_C(0xae835f4fU), BSWAP_32BIG_C(0x39c351c4U),
    };
    r_rsip_func100(Param_func017_func100_001);
    r_rsip_func_sub021(0x00000821U, 0x0000b440U, 0x00000004U, 0x00000863U);

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0 + 2]);
    S_RAM[0 + 2] = bswap_32big(S_RAM[0 + 2]);

    for (oLoop = 0U; oLoop < S_RAM[0 + 2]; oLoop = oLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202820U);
        WR1_PROG(REG_1600H, 0x2000d060U);
        r_rsip_func_sub014(0x00007c03U, 0x00602000U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0xf70c0d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &S_HEAP[ARG1 + oLoop]);
        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1600H, 0x00002422U);

        static const uint32_t Param_func017_func101_001[] =
        {
            BSWAP_32BIG_C(0xa084044bU), BSWAP_32BIG_C(0xdedc45a0U), BSWAP_32BIG_C(0x4c1665afU), BSWAP_32BIG_C(
                0x5c1620d2U),
        };
        r_rsip_func101(Param_func017_func101_001);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000801U);

    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x070c0d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &S_HEAP[ARG1 + oLoop]);

    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_func_sub001(0x00820011U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
