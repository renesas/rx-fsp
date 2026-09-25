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

void r_rsip_pc2u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    static const uint32_t Param_pc2u_func100_001[] =
    {
        BSWAP_32BIG_C(0xd3145e4fU), BSWAP_32BIG_C(0x108fc8aaU), BSWAP_32BIG_C(0x0a7b160aU), BSWAP_32BIG_C(0xb790c13bU),
    };
    r_rsip_func100(Param_pc2u_func100_001);

    r_rsip_func_sub025(0x00020061U, 0x40000020U, 0x0d00890eU);
    WR1_PROG(REG_1408H, 0x000c1000U);

    r_rsip_func220(InData_Text, MAX_CNT, OutData_Text);

    static const uint32_t Param_pc2u_func101_001[] =
    {
        BSWAP_32BIG_C(0x66cdea5eU), BSWAP_32BIG_C(0xb11597f0U), BSWAP_32BIG_C(0x57609401U), BSWAP_32BIG_C(0x575471feU),
    };
    r_rsip_func101(Param_pc2u_func101_001);
}
