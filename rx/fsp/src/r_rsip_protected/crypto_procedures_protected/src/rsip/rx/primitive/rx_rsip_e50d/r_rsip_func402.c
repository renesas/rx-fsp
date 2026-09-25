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

void r_rsip_func402 (void)
{
    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_func402_func100_001[] =
    {
        BSWAP_32BIG_C(0xcde74e19U), BSWAP_32BIG_C(0xb8dd0d1dU), BSWAP_32BIG_C(0x48fac543U), BSWAP_32BIG_C(0xca77603bU),
    };
    r_rsip_func100(Param_func402_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000b60U, 0x00000b10U, 0x00000750U, 0x0404000aU);

        r_rsip_func_sub002(0x00000bb0U, 0x00000b10U, 0x000007a0U, 0x0404000aU);

        r_rsip_func_sub002(0x00000c00U, 0x00000b10U, 0x000007f0U, 0x0404000aU);

        static const uint32_t Param_func402_func101_001[] =
        {
            BSWAP_32BIG_C(0xc4b09ad6U), BSWAP_32BIG_C(0x62207ffcU), BSWAP_32BIG_C(0xf1bae55dU), BSWAP_32BIG_C(
                0xa3e9ba83U),
        };
        r_rsip_func101(Param_func402_func101_001);
    }
    else
    {
        r_rsip_func_sub002(0x00000480U, 0x00000b10U, 0x00000750U, 0x0404000aU);

        r_rsip_func_sub002(0x000004d0U, 0x00000b10U, 0x000007a0U, 0x0404000aU);

        r_rsip_func_sub002(0x00000520U, 0x00000b10U, 0x000007f0U, 0x0404000aU);

        static const uint32_t Param_func402_func101_002[] =
        {
            BSWAP_32BIG_C(0xcdd28bd4U), BSWAP_32BIG_C(0x310a6073U), BSWAP_32BIG_C(0xa3c7884eU), BSWAP_32BIG_C(
                0x25acc57cU),
        };
        r_rsip_func101(Param_func402_func101_002);
    }

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
