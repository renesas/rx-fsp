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

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p81 (void)
{
    WR1_PROG(REG_1D04H, 0x0004dfe1U);
    WR1_PROG(REG_1D08H, 0x000acf24U);

    WR1_PROG(REG_1D00H, 0x00000001U);

    WAIT_STS(REG_1D00H, 1, 0);

    if (RD1_MASK(REG_1D00H, 0x00030000U) != 0x00000000U)
    {
        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_140CH, 0x38c60eedU);
        WR1_PROG(REG_1448H, 0x00000000U);

        WR1_PROG(REG_1408H, 0x00000001U);
        WR1_PROG(REG_1414H, 0x00001401U);

        if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
        {
            return RSIP_RET_RESOURCE_CONFLICT;
        }

        WR1_PROG(REG_1800H, 0x00000001U);
        WR1_PROG(REG_1700H, 0x00000001U);

        WR1_PROG(REG_1B00H, 0x00818001U);
        WR1_PROG(REG_1B08H, 0x00000d00U);

        WR1_PROG(REG_1804H, 0x00008005U);

        WR1_PROG(REG_1444H, 0x000003a2U);
        static const uint32_t Param_p81_func101_001[] =
        {
            0xced4644cU, 0xa21d8095U, 0xbbced3e1U, 0x353f74dbU,
        };
        r_rsip_func101(Param_p81_func101_001);
        WR1_PROG(REG_1804H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, 0x47046b9fU, 0x72327ea6U, 0xbc803675U, 0x9add9396U);

        static const uint32_t Param_p81_func101_002[] =
        {
            0x6aedd44aU, 0xd3cc6a8aU, 0xd1fba745U, 0x0479731aU,
        };
        r_rsip_func101(Param_p81_func101_002);

        static const uint32_t Param_p81_func100_001[] =
        {
            0x0d50b98eU, 0x29e6cb53U, 0x8bf6666aU, 0xaf6d98d4U,
        };
        r_rsip_func100(Param_p81_func100_001);

        WR1_PROG(REG_1408H, 0x00020000U);

        if (CHCK_STS(REG_142CH, 13, 0))
        {
            WR1_PROG(REG_14BCH, 0x00000020U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1430H, 0x0000FFFFU);

            WR1_PROG(REG_1B08H, 0x00000220U);

            static const uint32_t Param_p81_func102_001[] =
            {
                0x1d299e3bU, 0x94ce9278U, 0x46acb8b4U, 0xb3e43442U,
            };
            r_rsip_func102(Param_p81_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
