/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Sha3GenerateMessageDigestSuspendSub (uint32_t OutData_State[])
{
    uint32_t iLoop = 0U;

    for (iLoop = 0U; iLoop < 50; iLoop++)
    {
        RD1_ADDR(REG_243CH, &OutData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    RD1_ADDR(REG_2414H, &OutData_State[50]);
    RD1_ADDR(REG_2410H, &OutData_State[51]);

    HW_SCE_p_func102(0x2c78abcfU, 0x6d8c7d8cU, 0x34a863b2U, 0x83db89aeU);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
