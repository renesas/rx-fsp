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

void r_rsip_func103 (void)
{
    static const uint32_t Param_func103_func100_001[] =
    {
        BSWAP_32BIG_C(0x3be22395U), BSWAP_32BIG_C(0xe45b3bc3U), BSWAP_32BIG_C(0x60f37bbeU), BSWAP_32BIG_C(0x29598418U),
    };
    r_rsip_func100(Param_func103_func100_001);
    r_rsip_func_sub008(0x000004a2U, 0x40000000U, 0x07328c04U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub028(0x07328d04U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x08000065U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub028(0x07328d04U, 0x00000000U);

    WR1_PROG(REG_1404H, 0x1fd80000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub028(0x07328d04U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub028(0x06328074U, 0x00000000U);

    WR1_PROG(REG_1404H, 0x1fd80000U);
    WR1_PROG(REG_1A24H, 0x080000a5U);
    r_rsip_func_sub001(0x00830011U);

    static const uint32_t Param_func103_func100_002[] =
    {
        BSWAP_32BIG_C(0xc6514919U), BSWAP_32BIG_C(0xa12aa896U), BSWAP_32BIG_C(0xeaf3f76bU), BSWAP_32BIG_C(0xb36aee37U),
    };
    r_rsip_func100(Param_func103_func100_002);
    WR1_PROG(REG_1A24H, 0x080000b5U);
    r_rsip_func_sub001(0x00820011U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
