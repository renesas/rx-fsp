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

rsip_ret_t r_rsip_p0c (const uint32_t InData_CurrentVer[], const uint32_t InData_NextVer[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000c0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func048(InData_CurrentVer);

    r_rsip_func049(InData_NextVer);

    r_rsip_func_sub017(0x34202880U, 0x00260000U);

    static const uint32_t Param_p0c_func100_001[] =
    {
        BSWAP_32BIG_C(0xe1e12bbaU), BSWAP_32BIG_C(0xa3be06d5U), BSWAP_32BIG_C(0x9d8a8505U), BSWAP_32BIG_C(0x2c425f9bU),
    };
    r_rsip_func100(Param_p0c_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_14BCH, 0x00000020U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_VERIFICATION_FAIL;
    }
    else
    {
        r_rsip_func_sub017(0x38002880U, 0x00260000U);

        static const uint32_t Param_p0c_func100_002[] =
        {
            BSWAP_32BIG_C(0xe55b8d7fU), BSWAP_32BIG_C(0x09a08d66U), BSWAP_32BIG_C(0xba33822eU), BSWAP_32BIG_C(
                0x6333361cU),
        };
        r_rsip_func100(Param_p0c_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1B08H, 0x00000215U);

            static const uint32_t Param_p0c_func102_001[] =
            {
                BSWAP_32BIG_C(0xb6353d36U), BSWAP_32BIG_C(0xfb8259d8U), BSWAP_32BIG_C(0xebdc52f1U), BSWAP_32BIG_C(
                    0x0251ed79U),
            };
            r_rsip_func102(Param_p0c_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_VERSION_MATCH;
        }
        else
        {
            WR1_PROG(REG_1B08H, 0x00000215U);

            static const uint32_t Param_p0c_func102_002[] =
            {
                BSWAP_32BIG_C(0x743009b0U), BSWAP_32BIG_C(0x4bccd6faU), BSWAP_32BIG_C(0xfd1cb416U), BSWAP_32BIG_C(
                    0xb3efe8d4U),
            };
            r_rsip_func102(Param_p0c_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
