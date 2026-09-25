/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_Aes192GcmEncryptUpdateSub (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    HW_SCE_p_func100(0xdf3e1b97U, 0x88fe439aU, 0x0a5e075fU, 0x283794c6U);
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_182CH, 0x40020030U);
    WR1_PROG(REG_1824H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[0]);

    HW_SCE_p_func100(0xc7ab453eU, 0x9f993b05U, 0x2b2e58aeU, 0xac625403U);

    WR1_PROG(REG_1444H, 0x00020061U);
    WR1_PROG(REG_182CH, 0x40028030U);
    WR1_PROG(REG_1824H, 0x07008d06U);
    WR1_PROG(REG_1408H, 0x000c1000U);

    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func215();

    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_182CH, 0x00028000U);
    WR1_PROG(REG_1824H, 0x08008004U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    HW_SCE_p_func101(0x98f04525U, 0x2517ef5eU, 0x8bf3b869U, 0xf3d9e013U);
}
