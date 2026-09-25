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

void r_rsip_func043 (void)
{
    static const uint32_t Param_func043_func100_001[] =
    {
        BSWAP_32BIG_C(0xb7a2103bU), BSWAP_32BIG_C(0xb293dc0dU), BSWAP_32BIG_C(0x4601cc5fU), BSWAP_32BIG_C(0xd221202aU),
    };
    r_rsip_func100(Param_func043_func100_001);
    r_rsip_func_sub023(0x0000b540U, 0x000001d0U, 0x8188000aU);

    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_func043_func100_002[] =
    {
        BSWAP_32BIG_C(0xa78edc17U), BSWAP_32BIG_C(0xadfee61fU), BSWAP_32BIG_C(0x19850168U), BSWAP_32BIG_C(0x4f73986cU),
    };
    r_rsip_func100(Param_func043_func100_002);
    WR1_PROG(REG_1A24H, 0x08000095U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_func043_func100_003[] =
    {
        BSWAP_32BIG_C(0xa8176caaU), BSWAP_32BIG_C(0x5d93c023U), BSWAP_32BIG_C(0x28dcf5c5U), BSWAP_32BIG_C(0xf97420a6U),
    };
    r_rsip_func100(Param_func043_func100_003);

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

    r_rsip_func_sub027(0x40000000U, 0x30009045U, 0x81040140U);
    r_rsip_func_sub001(0x00890011U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    static const uint32_t Param_func043_func100_004[] =
    {
        BSWAP_32BIG_C(0x00c61d46U), BSWAP_32BIG_C(0xae8ca048U), BSWAP_32BIG_C(0xe5e30ad1U), BSWAP_32BIG_C(0x7a581f3bU),
    };
    r_rsip_func100(Param_func043_func100_004);
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_func043_func100_005[] =
    {
        BSWAP_32BIG_C(0x6ea1c1dcU), BSWAP_32BIG_C(0x9e75c681U), BSWAP_32BIG_C(0x3433eaddU), BSWAP_32BIG_C(0x414e72b1U),
    };
    r_rsip_func100(Param_func043_func100_005);
    r_rsip_func_sub004(0x0c000094U, 0x00000000U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
