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

void r_rsip_func323 (void)
{
    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1dc80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000dc0U, 0x4141000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func323_func100_001[] =
    {
        BSWAP_32BIG_C(0x9a851a22U), BSWAP_32BIG_C(0x18201b8cU), BSWAP_32BIG_C(0x226cd4ddU), BSWAP_32BIG_C(0xcab01624U),
    };
    r_rsip_func100(Param_func323_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func323_func100_002[] =
        {
            BSWAP_32BIG_C(0x6b494b4dU), BSWAP_32BIG_C(0x59cfb3adU), BSWAP_32BIG_C(0x9524e282U), BSWAP_32BIG_C(
                0xb607597fU),
        };
        r_rsip_func100(Param_func323_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000878U, 0x41410009U);

            static const uint32_t Param_func323_func101_001[] =
            {
                BSWAP_32BIG_C(0xa8b39c79U), BSWAP_32BIG_C(0xb5abf540U), BSWAP_32BIG_C(0xfaf31005U), BSWAP_32BIG_C(
                    0x2fa09ea9U),
            };
            r_rsip_func101(Param_func323_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000878U, 0x4141000aU);

            static const uint32_t Param_func323_func101_002[] =
            {
                BSWAP_32BIG_C(0x8f0fdb7fU), BSWAP_32BIG_C(0x3f43b482U), BSWAP_32BIG_C(0x48b98e2cU), BSWAP_32BIG_C(
                    0x871c6dacU),
            };
            r_rsip_func101(Param_func323_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func323_func100_003[] =
        {
            BSWAP_32BIG_C(0x165e75edU), BSWAP_32BIG_C(0xa817dd01U), BSWAP_32BIG_C(0x5ea4ce3cU), BSWAP_32BIG_C(
                0x14267ed6U),
        };
        r_rsip_func100(Param_func323_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000878U, 0x00000fd8U, 0x00000878U, 0x41410009U);

            static const uint32_t Param_func323_func101_003[] =
            {
                BSWAP_32BIG_C(0x52a47c2cU), BSWAP_32BIG_C(0xc9035235U), BSWAP_32BIG_C(0x7ab0f141U), BSWAP_32BIG_C(
                    0x3103a46cU),
            };
            r_rsip_func101(Param_func323_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000878U, 0x00000878U, 0x4141000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func323_func101_004[] =
            {
                BSWAP_32BIG_C(0xadafdea4U), BSWAP_32BIG_C(0x97fcad63U), BSWAP_32BIG_C(0x5c3e3db6U), BSWAP_32BIG_C(
                    0x1906e950U),
            };
            r_rsip_func101(Param_func323_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
