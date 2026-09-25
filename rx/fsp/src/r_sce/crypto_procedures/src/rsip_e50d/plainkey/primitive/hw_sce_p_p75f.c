/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Sha2HmacFinalSub (const uint32_t InData_Cmd[],
                                   const uint32_t InData_Msg[],
                                   const uint32_t InData_MAC[],
                                   const uint32_t InData_length[],
                                   uint32_t       OutData_MAC[],
                                   uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001600U);

    WAIT_STS(REG_2030H, 4, 1);

    WR1_PROG(REG_1600H, 0x38008880U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1600H, 0x1000b480U);
    WR1_PROG(REG_1600H, 0x00000001U);

    WR1_PROG(REG_1600H, 0x38008880U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x1000b480U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x035d5193U, 0xbe75d094U, 0x98962316U, 0xc212e6caU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func100(0xa0b6eb9eU, 0xbf7f3717U, 0x2947005eU, 0xbbbb74eaU);

        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            HW_SCE_p_func100(0x77e032e3U, 0x8563267eU, 0xe6ee9ad7U, 0xa6c84077U);
            WR1_PROG(REG_1408H, 0x0000401eU);
            WAIT_STS(REG_1408H, 30, 1);
            RD7_ADDR(REG_1420H, &OutData_MAC[0]);

            HW_SCE_p_func102(0x31d045f5U, 0xdaf12781U, 0x6ee0cd16U, 0x8a17248dU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            HW_SCE_p_func100(0x40f4176bU, 0xbb861f26U, 0x2688a5bcU, 0x49c0d498U);
            WR1_PROG(REG_1408H, 0x00004022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD8_ADDR(REG_1420H, &OutData_MAC[0]);

            HW_SCE_p_func102(0xa7cb30e8U, 0x863274c7U, 0x65a24cebU, 0xc7862a5eU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            HW_SCE_p_func100(0xa8fc2b92U, 0x058623bdU, 0x23010e7dU, 0x53180642U);
            WR1_PROG(REG_1408H, 0x00004032U);
            WAIT_STS(REG_1408H, 30, 1);
            RD12_ADDR(REG_1420H, &OutData_MAC[0]);

            HW_SCE_p_func102(0xea33a1c5U, 0xfa6db606U, 0x4d03394aU, 0xf4a4b6ceU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            HW_SCE_p_func100(0xea3f8137U, 0x82233577U, 0x3d9c6c9eU, 0xd7b1af6fU);
            WR1_PROG(REG_1408H, 0x00004042U);
            WAIT_STS(REG_1408H, 30, 1);
            RD16_ADDR(REG_1420H, &OutData_MAC[0]);

            HW_SCE_p_func102(0x1fb135f1U, 0x2538b74eU, 0x6881122bU, 0x9b77e6c5U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }

        return FSP_SUCCESS;
    }
    else
    {
        HW_SCE_p_func100(0x44aeca68U, 0x9ce20992U, 0x4ac48b32U, 0xb06c0934U);

        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010020U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_length[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x0000001cU);

            HW_SCE_p_func101(0x334f8256U, 0x093fb307U, 0x9f9c815fU, 0x3d7b7ca2U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000020U);

            HW_SCE_p_func101(0x283c01fcU, 0xe9dbb291U, 0x698bf687U, 0x2bbe5f1aU);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000030U);

            HW_SCE_p_func101(0xf8140547U, 0x761b08adU, 0x817fcf77U, 0xfaa96309U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000040U);

            HW_SCE_p_func101(0x9f0f4ebdU, 0x0a2222b6U, 0x3041ec9dU, 0x25c89ec4U);
        }

        WR1_PROG(REG_1600H, 0x3420a820U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        WR1_PROG(REG_1600H, 0x34202841U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x8a337611U, 0xf253f66cU, 0x771bf60bU, 0xf813babbU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0xf35c7565U, 0xe93ee622U, 0xb9280feaU, 0x19a0b208U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            HW_SCE_p_func100(0xbf3e2a92U, 0xf86b7e4cU, 0x39b980b0U, 0x7ecd58edU);

            WR1_PROG(REG_1600H, 0x000008c6U);

            WR1_PROG(REG_1600H, 0x000008a5U);

            WR1_PROG(REG_1600H, 0x0000a440U);
            WR1_PROG(REG_1600H, 0x0000000fU);
            WR1_PROG(REG_1600H, 0x00046842U);
            WR1_PROG(REG_1600H, 0x00026c42U);

            WR1_PROG(REG_1608H, 0x81010040U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = change_endian_long(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
            {
                HW_SCE_p_func100(0x93af9781U, 0xa0f48159U, 0x798d5026U, 0xaf731e69U);

                WR1_PROG(REG_1600H, 0x000008e7U);

                WR1_PROG(REG_1600H, 0x00000863U);

                WR1_PROG(REG_1600H, 0x380088c0U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1600H, 0x2000d060U);

                WR1_PROG(REG_1600H, 0x38008880U);
                WR1_PROG(REG_1600H, 0x00000001U);
                WR1_PROG(REG_1600H, 0x2000d060U);

                WR1_PROG(REG_1600H, 0x00007c03U);
                WR1_PROG(REG_143CH, 0x00600000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    WR1_PROG(REG_1400H, 0x0345000dU);

                    WAIT_STS(REG_1404H, 30, 0);
                    WR1_PROG(REG_143CH, 0x00001800U);

                    WR1_PROG(REG_1444H, 0x000002c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR3_ADDR(REG_1420H, &InData_MAC[iLoop]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

                    HW_SCE_p_func101(0xb4b4d295U, 0x8b593a14U, 0x5d967197U, 0x6bda6e8dU);
                }
                else
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    WR1_PROG(REG_1400H, 0x03450011U);

                    WAIT_STS(REG_1404H, 30, 0);
                    WR1_PROG(REG_143CH, 0x00001800U);

                    WR1_PROG(REG_1444H, 0x000003c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_MAC[iLoop]);

                    HW_SCE_p_func101(0xeb19bd24U, 0x159a06f8U, 0x7a24915aU, 0xf0d04c23U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000800U);
                for (jLoop = 0U; jLoop < 16U; jLoop++)
                {
                    WR1_PROG(REG_1600H, 0x3c0028a1U);
                    WR1_PROG(REG_1600H, 0x12003c07U);
                    WR1_PROG(REG_1600H, 0x00002ce0U);
                    WR1_PROG(REG_1600H, 0x00002ca0U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1824H, 0x9c000005U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1608H, 0x81840007U);
                WR1_PROG(REG_1400H, 0x00490011U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1600H, 0x0000a4c0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                HW_SCE_p_func101(0x5233ec8aU, 0x2446a7a6U, 0x0cd3fdf6U, 0xca71b42bU);
            }

            WR1_PROG(REG_1600H, 0x000008c2U);

            WR1_PROG(REG_1600H, 0x00007c06U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x881f010dU, 0x15c60c71U, 0x236f76a7U, 0x14bdc88fU);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func102(0xaa4b4680U, 0x4e273a52U, 0xc65215dcU, 0xd01f2b16U);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_ERR_CRYPTO_SCE_FAIL;
            }
            else
            {
                HW_SCE_p_func102(0x591fdbc2U, 0x60de9d8eU, 0xb29ffef8U, 0x7d2c58acU);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_SUCCESS;
            }
        }
    }
}
