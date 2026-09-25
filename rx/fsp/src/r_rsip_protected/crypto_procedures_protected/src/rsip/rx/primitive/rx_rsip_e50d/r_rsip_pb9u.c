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

void r_rsip_pb9u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    static const uint32_t Param_pb9u_func100_001[] =
    {
        BSWAP_32BIG_C(0x235405caU), BSWAP_32BIG_C(0xddbbb741U), BSWAP_32BIG_C(0xef8b7598U), BSWAP_32BIG_C(0x288f03a2U),
    };
    r_rsip_func100(Param_pb9u_func100_001);

    r_rsip_func_sub025(0x00020061U, 0x40000020U, 0x0d008906U);
    WR1_PROG(REG_1408H, 0x000c1000U);

    r_rsip_func220(InData_Text, MAX_CNT, OutData_Text);

    static const uint32_t Param_pb9u_func101_001[] =
    {
        BSWAP_32BIG_C(0x18beec35U), BSWAP_32BIG_C(0x8e2c5cf0U), BSWAP_32BIG_C(0x052a3a62U), BSWAP_32BIG_C(0xb1df233dU),
    };
    r_rsip_func101(Param_pb9u_func101_001);
}
