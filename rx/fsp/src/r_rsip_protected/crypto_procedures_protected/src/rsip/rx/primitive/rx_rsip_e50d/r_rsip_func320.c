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

void r_rsip_func320 (void)
{
    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1e480000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e40U, 0x3131000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func320_func100_001[] =
    {
        BSWAP_32BIG_C(0x9555dfffU), BSWAP_32BIG_C(0x6dfe3540U), BSWAP_32BIG_C(0x9bf05bf8U), BSWAP_32BIG_C(0x015c791eU),
    };
    r_rsip_func100(Param_func320_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func320_func100_002[] =
        {
            BSWAP_32BIG_C(0xb539c847U), BSWAP_32BIG_C(0x2b8ebad5U), BSWAP_32BIG_C(0xbab07d49U), BSWAP_32BIG_C(
                0x1ae6260cU),
        };
        r_rsip_func100(Param_func320_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x3131000aU);

            static const uint32_t Param_func320_func101_001[] =
            {
                BSWAP_32BIG_C(0x4c48e892U), BSWAP_32BIG_C(0x35088b9fU), BSWAP_32BIG_C(0x4281a66bU), BSWAP_32BIG_C(
                    0xbff73574U),
            };
            r_rsip_func101(Param_func320_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x31310009U);

            static const uint32_t Param_func320_func101_002[] =
            {
                BSWAP_32BIG_C(0x315adbafU), BSWAP_32BIG_C(0xc8c652f2U), BSWAP_32BIG_C(0xe24f96fcU), BSWAP_32BIG_C(
                    0xcfb25231U),
            };
            r_rsip_func101(Param_func320_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func320_func100_003[] =
        {
            BSWAP_32BIG_C(0xcd5eb414U), BSWAP_32BIG_C(0xd36d0d47U), BSWAP_32BIG_C(0xa55876f3U), BSWAP_32BIG_C(
                0x80de9149U),
        };
        r_rsip_func100(Param_func320_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x3131000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func320_func101_003[] =
            {
                BSWAP_32BIG_C(0x5f0aff3bU), BSWAP_32BIG_C(0x4db097c6U), BSWAP_32BIG_C(0xa30d63ddU), BSWAP_32BIG_C(
                    0x308acd00U),
            };
            r_rsip_func101(Param_func320_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x31310009U);

            static const uint32_t Param_func320_func101_004[] =
            {
                BSWAP_32BIG_C(0x26d25e31U), BSWAP_32BIG_C(0x835dca44U), BSWAP_32BIG_C(0xbc13265aU), BSWAP_32BIG_C(
                    0x7950ab92U),
            };
            r_rsip_func101(Param_func320_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
