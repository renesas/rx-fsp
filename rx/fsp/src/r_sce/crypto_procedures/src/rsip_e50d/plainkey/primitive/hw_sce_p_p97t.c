/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_Chacha20Poly1305UpdateTransitionSub (void)
{
    HW_SCE_p_func100(0x4d7ea5aeU, 0xfa687328U, 0xcc621ee3U, 0xe9e6f3a0U);
    WR1_PROG(REG_1600H, 0x0000b440U);
    WR1_PROG(REG_1600H, 0x00000002U);

    WR1_PROG(REG_1608H, 0x81010040U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = change_endian_long(S_RAM[0]);

    HW_SCE_p_func101(0x6cb3248fU, 0xccd4cffaU, 0x96718c83U, 0xd5cdb5c0U);
}
