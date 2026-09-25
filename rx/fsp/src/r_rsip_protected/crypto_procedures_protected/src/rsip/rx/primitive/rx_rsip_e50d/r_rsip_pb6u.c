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

void r_rsip_pb6u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    static const uint32_t Param_pb6u_func100_001[] =
    {
        BSWAP_32BIG_C(0x5c9f5457U), BSWAP_32BIG_C(0xd8c9f923U), BSWAP_32BIG_C(0x5ea9a357U), BSWAP_32BIG_C(0x15fac4f3U),
    };
    r_rsip_func100(Param_pb6u_func100_001);

    r_rsip_func_sub025(0x00020061U, 0x00000020U, 0x0d00890eU);
    WR1_PROG(REG_1408H, 0x000c1000U);

    r_rsip_func220(InData_Text, MAX_CNT, OutData_Text);

    static const uint32_t Param_pb6u_func101_001[] =
    {
        BSWAP_32BIG_C(0x1826bc3eU), BSWAP_32BIG_C(0xbd07e6bbU), BSWAP_32BIG_C(0x947a8b59U), BSWAP_32BIG_C(0x81191e3bU),
    };
    r_rsip_func101(Param_pb6u_func101_001);
}
