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

void r_rsip_func082 (void)
{
    static const uint32_t Param_func082_func100_001[] =
    {
        BSWAP_32BIG_C(0xdcbe78c5U), BSWAP_32BIG_C(0x0d4a9081U), BSWAP_32BIG_C(0x92ebac51U), BSWAP_32BIG_C(0x7f894b8fU),
    };
    r_rsip_func100(Param_func082_func100_001);
    r_rsip_func_sub023(0x0000b540U, 0x000001d0U, 0x8188000aU);

    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_func082_func100_002[] =
    {
        BSWAP_32BIG_C(0xf22b37feU), BSWAP_32BIG_C(0x44c2f930U), BSWAP_32BIG_C(0x00b72b70U), BSWAP_32BIG_C(0xc8b921c3U),
    };
    r_rsip_func100(Param_func082_func100_002);
    WR1_PROG(REG_1A24H, 0x08000095U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_func082_func100_003[] =
    {
        BSWAP_32BIG_C(0x5a02f119U), BSWAP_32BIG_C(0x4c02251aU), BSWAP_32BIG_C(0xfa8df936U), BSWAP_32BIG_C(0x1f2efe80U),
    };
    r_rsip_func100(Param_func082_func100_003);

    r_rsip_func_sub023(0x0000b540U, 0x000001c0U, 0x8184000aU);

    WR1_PROG(REG_1A24H, 0x080000c5U);
    r_rsip_func_sub001(0x00890011U);

    WR1_PROG(REG_1A24H, 0x0b040104U);
    WR1_PROG(REG_1608H, 0x810100e0U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1608H, 0x80040140U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub021(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x01000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009105U, 0x81040140U);
    r_rsip_func_sub001(0x00890011U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    r_rsip_func_sub021(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x02000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009105U, 0x81040140U);
    r_rsip_func_sub001(0x00890011U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    r_rsip_func_sub001(0x01420021U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
