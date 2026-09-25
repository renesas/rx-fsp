/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_Aes128GcmEncryptUpdateAADSub (const uint32_t InData_DataA[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1444H, 0x00020061U);
    WR1_PROG(REG_182CH, 0x00018000U);
    WR1_PROG(REG_1824H, 0x0a008006U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_DataA[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func216();

    HW_SCE_p_func101(0xf20e4762U, 0x06d88b12U, 0xdd1356daU, 0x7f0dcdd8U);
}
