/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Chacha20Poly1305FinalSub (const uint32_t InData_Text[],
                                           const uint32_t InData_DataT[],
                                           uint32_t       OutData_Text[],
                                           uint32_t       OutData_DataT[],
                                           uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    HW_SCE_p_func100(0xbd900b65U, 0x58f296b8U, 0x2e4189c0U, 0x89852281U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010020U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, MAX_CNT);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1608H, 0x81010020U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = change_endian_long(S_RAM[0]);

    HW_SCE_p_func100(0x89843a2aU, 0x0c0b281cU, 0x0b6ecd26U, 0xd1699392U);

    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);

    for (iLoop = 0U; iLoop < (S_RAM[0] & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop++)
    {
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    HW_SCE_p_func100(0x332da939U, 0x253075c5U, 0x53dca32aU, 0x54b38d4eU);
    WR1_PROG(REG_1600H, 0x00008c20U);
    WR1_PROG(REG_1600H, 0x0000000fU);

    WR1_PROG(REG_1600H, 0x38000c21U);
    WR1_PROG(REG_1600H, 0x1000b420U);
    WR1_PROG(REG_1600H, 0x00000010U);

    WR1_PROG(REG_1608H, 0x81010020U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = change_endian_long(S_RAM[0]);

    for (iLoop = S_RAM[0]; iLoop < 16U; iLoop++)
    {
        WR1_PROG(REG_1400H, 0x00070005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00002c20U);

        HW_SCE_p_func101(0x4c6ad4e1U, 0x237ee291U, 0x8e1ba41dU, 0xeabd7b62U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38008820U);
    WR1_PROG(REG_1600H, 0x00000010U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xf871c53cU, 0x5521e559U, 0x10fc61e5U, 0xe8864532U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func100(0x54724520U, 0xdde303abU, 0x98b19190U, 0x925ef943U);
        WR1_PROG(REG_1408H, 0x00007012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_DataT[0]);

        HW_SCE_p_func102(0x209f2dadU, 0x2a9a0e74U, 0xbaa31cdcU, 0x598ff996U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_SUCCESS;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0x08000055U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_DataT[0]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00870011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0xb1820e6aU, 0x9f5ad021U, 0x36473baeU, 0x1fe3644bU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0xcdcd6bfdU, 0x54124c7aU, 0xdfa9c762U, 0xd7d74104U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_AUTHENTICATION;
        }
        else
        {
            HW_SCE_p_func102(0xd0121fa6U, 0xc7e6a742U, 0xe92b1dceU, 0x6e2b5ee5U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
