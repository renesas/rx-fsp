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

rsip_ret_t r_rsip_pefi (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ef0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3000a800U, 0x00000003U, 0x00010020U, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1600H, 0x00000080U);

    static const uint32_t Param_pefi_func100_001[] =
    {
        BSWAP_32BIG_C(0xa7047c26U), BSWAP_32BIG_C(0xf7a5077bU), BSWAP_32BIG_C(0xa3ce282bU), BSWAP_32BIG_C(0xdd119db0U),
    };
    r_rsip_func100(Param_pefi_func100_001);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2004H, 0x00000050U);

        static const uint32_t Param_pefi_func101_001[] =
        {
            BSWAP_32BIG_C(0xc8f85783U), BSWAP_32BIG_C(0xd69c3420U), BSWAP_32BIG_C(0x9bc9a669U), BSWAP_32BIG_C(
                0xad3c88caU),
        };
        r_rsip_func101(Param_pefi_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x000000a0U);

        static const uint32_t Param_pefi_func101_002[] =
        {
            BSWAP_32BIG_C(0x9f276210U), BSWAP_32BIG_C(0x63e071ceU), BSWAP_32BIG_C(0xc520e784U), BSWAP_32BIG_C(
                0xa870e2b3U),
        };
        r_rsip_func101(Param_pefi_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x000000b0U);

        static const uint32_t Param_pefi_func101_003[] =
        {
            BSWAP_32BIG_C(0x747bf10dU), BSWAP_32BIG_C(0xb6447d00U), BSWAP_32BIG_C(0x3167f1aeU), BSWAP_32BIG_C(
                0x5f8998b0U),
        };
        r_rsip_func101(Param_pefi_func101_003);
    }

    r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003c01U);

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_200CH, 0x00000100U);

        static const uint32_t Param_pefi_func101_004[] =
        {
            BSWAP_32BIG_C(0x55bb1b5fU), BSWAP_32BIG_C(0xb7e3c15eU), BSWAP_32BIG_C(0xe7f03355U), BSWAP_32BIG_C(
                0xe433372fU),
        };
        r_rsip_func101(Param_pefi_func101_004);
    }
    else
    {
        r_rsip_func_sub033(0x00000040U, InData_MsgLen[0], 0x00000040U, InData_MsgLen[1]);

        static const uint32_t Param_pefi_func101_005[] =
        {
            BSWAP_32BIG_C(0x6c59593dU), BSWAP_32BIG_C(0x19c76815U), BSWAP_32BIG_C(0xef696e67U), BSWAP_32BIG_C(
                0x4bdd0b9eU),
        };
        r_rsip_func101(Param_pefi_func101_005);
    }

    return RSIP_RET_PASS;
}
