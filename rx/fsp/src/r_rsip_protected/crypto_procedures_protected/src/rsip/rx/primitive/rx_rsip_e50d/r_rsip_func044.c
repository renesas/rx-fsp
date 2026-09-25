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

void r_rsip_func044 (void)
{
    r_rsip_func_sub021(0x00008ce0U, 0x00ffffffU, 0x000090e0U, 0x01000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009104U, 0x810100e0U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    r_rsip_func_sub021(0x00008ce0U, 0x00ffffffU, 0x000090e0U, 0x02000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009044U, 0x810100e0U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    static const uint32_t Param_func044_func100_001[] =
    {
        BSWAP_32BIG_C(0x6d637c7aU), BSWAP_32BIG_C(0x3567dab1U), BSWAP_32BIG_C(0xb317c94eU), BSWAP_32BIG_C(0x1b027d36U),
    };
    r_rsip_func100(Param_func044_func100_001);
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_func044_func100_002[] =
    {
        BSWAP_32BIG_C(0x6710c55bU), BSWAP_32BIG_C(0x78815fbdU), BSWAP_32BIG_C(0x962465afU), BSWAP_32BIG_C(0x81493da2U),
    };
    r_rsip_func100(Param_func044_func100_002);
    r_rsip_func_sub004(0x0c000094U, 0x00000000U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
