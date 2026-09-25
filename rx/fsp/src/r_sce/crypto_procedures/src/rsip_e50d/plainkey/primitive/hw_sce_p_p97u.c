/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_Chacha20Poly1305UpdateSub (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    HW_SCE_p_func100(0x5d99ea03U, 0x3fc7a6feU, 0x69f2db6aU, 0x69be7b68U);

    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    HW_SCE_p_func101(0x0c628a9aU, 0xfaf1ede6U, 0xa7e4712cU, 0xc175eccfU);
}
