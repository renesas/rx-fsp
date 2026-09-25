/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_ShaGenerateMessageDigestUpdateSub (const uint32_t InData_Msg[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001600U);

    HW_SCE_p_func101(0x97237f89U, 0x43c59af2U, 0x096a7231U, 0x27992a5aU);

    return FSP_SUCCESS;
}
