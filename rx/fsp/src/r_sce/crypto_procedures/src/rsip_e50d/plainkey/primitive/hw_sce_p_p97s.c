/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Chacha20Poly1305SuspendSub (uint32_t OutData_State[])
{
    uint32_t iLoop = 0U;

    if (S_RAM[0] == 1)
    {
        HW_SCE_p_func101(0xd22d4f37U, 0xcadb82d2U, 0xbcd2cc2eU, 0x7394801cU);
    }
    else
    {
        HW_SCE_p_func101(0x5c7ca6eeU, 0xbd3f5171U, 0xe00a9c80U, 0xcbd8a423U);
    }

    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    RD1_ADDR(REG_1C08H, &OutData_State[0]);
    RD1_ADDR(REG_1C10H, &OutData_State[1]);
    RD1_ADDR(REG_1C14H, &OutData_State[2]);

    for (iLoop = 3; iLoop < 10U; iLoop++)
    {
        RD1_ADDR(REG_1C2CH, &OutData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c21U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xfd11fe4aU, 0x1afea125U, 0x0836ca9cU, 0xb6693bffU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func101(0xffd2d71bU, 0xa612468aU, 0xc591c1a7U, 0x3d858249U);
    }
    else
    {
        HW_SCE_p_func100(0x90806271U, 0x1dba0427U, 0x32406c26U, 0x56a67839U);
        HW_SCE_p_func103();

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1608H, 0x80010060U);
        WR1_PROG(REG_1400H, 0x03420005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0x35fb00e9U, 0xc34aaf63U, 0x372f062bU, 0x83d79304U);
    }

    WR1_PROG(REG_1600H, 0x000034e3U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00009704U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xbc733d2dU, 0xc60befcfU, 0xfe1e1debU, 0xfc200490U);
    HW_SCE_p_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x01d658dfU);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00009704U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x5a49bd1bU, 0xb5880ef2U, 0x740d3fa0U, 0x893af8e3U);
    HW_SCE_p_func044();

    HW_SCE_p_func100(0x807d38bfU, 0xce6b7d21U, 0xf1264e2bU, 0x76619befU);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8009104U);
    WR1_PROG(REG_1608H, 0x81010040U);
    WR1_PROG(REG_1400H, 0x00890005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1408H, 0x00002006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &OutData_State[11]);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    HW_SCE_p_func100(0x1bcc9946U, 0xbfceeb3dU, 0xe22bef58U, 0x15327b59U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_State[12]);

    HW_SCE_p_func100(0x6224d9c8U, 0xa6657125U, 0x551cab5bU, 0x8733e387U);
    WR1_PROG(REG_1608H, 0x81010060U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &OutData_State[10]);

    HW_SCE_p_func102(0x83686ddaU, 0x0b97793bU, 0x171ce499U, 0x1809b14dU);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
