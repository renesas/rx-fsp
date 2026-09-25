/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_Chacha20Poly1305UpdateAADSub (const uint32_t InData_DataA[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1444H, 0x00020066U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_DataA[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_DataA[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    WAIT_STS(REG_1C30H, 0, 1);

    HW_SCE_p_func101(0xa8161e4cU, 0x5f5eb156U, 0xc991cfa0U, 0x7b91b826U);
}
