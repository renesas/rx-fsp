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

rsip_ret_t r_rsip_p73r (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00730001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p73r_func100_001[] =
    {
        BSWAP_32BIG_C(0xe4b25d67U), BSWAP_32BIG_C(0x03b31761U), BSWAP_32BIG_C(0x9843f039U), BSWAP_32BIG_C(0x0cb69542U),
    };
    r_rsip_func100(Param_p73r_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p73r_func102_001[] =
        {
            BSWAP_32BIG_C(0xb5be69fdU), BSWAP_32BIG_C(0x614b5f8dU), BSWAP_32BIG_C(0x442fa9fdU), BSWAP_32BIG_C(
                0xc5c10e1eU),
        };
        r_rsip_func102(Param_p73r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p73r_func100_002[] =
        {
            BSWAP_32BIG_C(0x151a5a59U), BSWAP_32BIG_C(0xe2893a40U), BSWAP_32BIG_C(0xad07bf74U), BSWAP_32BIG_C(
                0x64ff438bU),
        };
        r_rsip_func100(Param_p73r_func100_002);
        r_rsip_func_sub021(0x3420a800U, 0x00000007U, 0x2000b400U, 0x00000006U);

        r_rsip_func_sub014(0x00007c00U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_2004H, 0x00001040U);

            static const uint32_t Param_p73r_func101_001[] =
            {
                BSWAP_32BIG_C(0x8e201836U), BSWAP_32BIG_C(0x89087ff0U), BSWAP_32BIG_C(0x1d744a68U), BSWAP_32BIG_C(
                    0xcde4a534U),
            };
            r_rsip_func101(Param_p73r_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_2004H, 0x00001050U);

            static const uint32_t Param_p73r_func101_002[] =
            {
                BSWAP_32BIG_C(0x802993d3U), BSWAP_32BIG_C(0x3656c660U), BSWAP_32BIG_C(0x39969291U), BSWAP_32BIG_C(
                    0xfed44acdU),
            };
            r_rsip_func101(Param_p73r_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_2004H, 0x00001080U);

            static const uint32_t Param_p73r_func101_003[] =
            {
                BSWAP_32BIG_C(0x5d6b8046U), BSWAP_32BIG_C(0xc2f8fd23U), BSWAP_32BIG_C(0x5725d229U), BSWAP_32BIG_C(
                    0x7e8b5a56U),
            };
            r_rsip_func101(Param_p73r_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_2004H, 0x00001090U);

            static const uint32_t Param_p73r_func101_004[] =
            {
                BSWAP_32BIG_C(0xf0be6877U), BSWAP_32BIG_C(0x576b76caU), BSWAP_32BIG_C(0x4d6119bfU), BSWAP_32BIG_C(
                    0xa110c3deU),
            };
            r_rsip_func101(Param_p73r_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_2004H, 0x000010a0U);

            static const uint32_t Param_p73r_func101_005[] =
            {
                BSWAP_32BIG_C(0x48683400U), BSWAP_32BIG_C(0xa7c5cf10U), BSWAP_32BIG_C(0x436923f6U), BSWAP_32BIG_C(
                    0x3fb5df51U),
            };
            r_rsip_func101(Param_p73r_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_2004H, 0x000010b0U);

            static const uint32_t Param_p73r_func101_006[] =
            {
                BSWAP_32BIG_C(0xcf7ad620U), BSWAP_32BIG_C(0x7f0e862dU), BSWAP_32BIG_C(0xfa18c2a2U), BSWAP_32BIG_C(
                    0xa45b26f8U),
            };
            r_rsip_func101(Param_p73r_func101_006);
        }

        r_rsip_func_sub033(0x00000040U, InData_State[18], 0x00000040U, InData_State[19]);

        for (iLoop = 0U; iLoop < 18U; iLoop++)
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2028H, InData_State[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p73r_func101_007[] =
        {
            BSWAP_32BIG_C(0x8b68730cU), BSWAP_32BIG_C(0xf7fdb394U), BSWAP_32BIG_C(0xae35b88fU), BSWAP_32BIG_C(
                0x28824952U),
        };
        r_rsip_func101(Param_p73r_func101_007);

        return RSIP_RET_PASS;
    }
}
