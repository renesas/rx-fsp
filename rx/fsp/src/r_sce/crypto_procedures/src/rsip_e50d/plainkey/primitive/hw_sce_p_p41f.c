/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes128CmacFinalSub (const uint32_t InData_Cmd[],
                                     const uint32_t InData_Text[],
                                     const uint32_t InData_DataT[],
                                     const uint32_t InData_DataTLen[],
                                     uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
    {
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x4a000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        HW_SCE_p_func101(0x71b33381U, 0x71580fd4U, 0x04a1b88aU, 0x8bf090d6U);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x5a000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        HW_SCE_p_func101(0x00319c67U, 0xc42dffc9U, 0x31f25064U, 0x65e673a9U);
    }

    WR1_PROG(REG_1824H, 0x0c000045U);
    WR1_PROG(REG_1400H, 0x00410011U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
    {
        HW_SCE_p_func100(0x277439f4U, 0x7323edacU, 0x11449e11U, 0x59487c69U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x0e000505U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[0]);

        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_DataT[0]);

        HW_SCE_p_func102(0x65534bd4U, 0xb0977bf5U, 0x34c2dfd0U, 0x2751a4d2U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_SUCCESS;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010040U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_DataTLen[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x3420a840U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        WR1_PROG(REG_1600H, 0x0000b460U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1600H, 0x34202862U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x8d6f636bU, 0x8c219ed4U, 0x95ace362U, 0x59d996c2U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x82341f56U, 0x3687b07bU, 0x2b2681c1U, 0x51334a97U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x0e000505U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x80840001U);
            WR1_PROG(REG_1400H, 0x03410011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x000034e2U);
            WR1_PROG(REG_1600H, 0x000568e7U);
            WR1_PROG(REG_1600H, 0x00026ce7U);

            WR1_PROG(REG_1600H, 0x00003827U);

            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1600H, 0x00003402U);
            WR1_PROG(REG_1600H, 0x00008c00U);
            WR1_PROG(REG_1600H, 0x0000001fU);
            WR1_PROG(REG_1600H, 0x000028c0U);
            WR1_PROG(REG_1600H, 0x00008cc0U);
            WR1_PROG(REG_1600H, 0x0000001fU);

            WR1_PROG(REG_1600H, 0x00004406U);

            WR1_PROG(REG_1600H, 0x00007421U);
            WR1_PROG(REG_1600H, 0x00007821U);

            WR1_PROG(REG_1600H, 0x00003c27U);

            WR1_PROG(REG_1600H, 0x000034c2U);
            WR1_PROG(REG_1600H, 0x0000a4c0U);
            WR1_PROG(REG_1600H, 0x0000001fU);
            WR1_PROG(REG_1600H, 0x000568c6U);

            WR1_PROG(REG_1600H, 0x000034e6U);
            WR1_PROG(REG_1600H, 0x00026ce7U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 4; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x3420a8e0U);
                WR1_PROG(REG_1600H, 0x0000000dU);
                WR1_PROG(REG_1600H, 0x10003c27U);

                WR1_PROG(REG_1600H, 0x1000a4e0U);
                WR1_PROG(REG_1600H, 0x00000004U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1824H, 0x08000045U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1400H, 0x00490011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x9c000005U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_DataT[0]);

            HW_SCE_p_func100(0x6b342206U, 0x4ab5c209U, 0xb773bcbdU, 0x3a7b6236U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func102(0x003306fdU, 0x022b3965U, 0xf34edc6bU, 0x2b236701U);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_ERR_CRYPTO_SCE_AUTHENTICATION;
            }
            else
            {
                HW_SCE_p_func102(0x47ae19abU, 0x8db466bbU, 0x649912f0U, 0x5bbba5dbU);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_SUCCESS;
            }
        }
    }
}
