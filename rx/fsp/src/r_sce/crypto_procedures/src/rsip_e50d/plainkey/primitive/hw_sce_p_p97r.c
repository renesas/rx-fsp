/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Chacha20Poly1305ResumeSub (const uint32_t InData_KeyMode[],
                                            const uint32_t InData_KeyIndex[],
                                            const uint32_t InData_Key[],
                                            const uint32_t InData_Cmd[],
                                            const uint32_t InData_Nonce[],
                                            const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00970001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_State[1]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x6f5286f5U, 0x56be3ed6U, 0x0476020fU, 0xde011d00U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x19e60c66U, 0x3f7ccc75U, 0xdb8ab92aU, 0x8ee5872fU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        WAIT_STS(REG_1C30H, 8, 0);
        WR1_PROG(REG_143CH, 0x00001c00U);

        HW_SCE_p_func100(0x4d228f2dU, 0x748dbf21U, 0xa05b27e3U, 0x87fad261U);
        WR1_PROG(REG_1C00H, 0x00000001U);

        WR1_PROG(REG_1C04H, 0x00001001U);

        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010020U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyMode[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x38000c21U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0xceb1d427U, 0x167bf325U, 0xbe77bb0aU, 0xece48b70U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x800100e0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x00003467U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00009702U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xe87d22e2U, 0xc815cb14U, 0x13c224f1U, 0x3240d0c7U);
            HW_SCE_p_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000030U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00009702U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xb0151543U, 0xb37241f9U, 0x6a9d8197U, 0x8e8daa59U);
            HW_SCE_p_func044();

            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xf7009d07U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1400H, 0x01c20021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            WR1_PROG(REG_1400H, 0x00820011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0xed705836U, 0x3b1876a9U, 0xdc77114eU, 0x158ed2c1U);
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x80010060U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_State[10]);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x000007c6U);
            WAIT_STS(REG_1444H, 31, 1);
            WR8_ADDR(REG_1420H, &InData_Key[0]);

            HW_SCE_p_func101(0x6f0739ecU, 0x373b6ae6U, 0xcf24323fU, 0x560bf432U);
        }

        HW_SCE_p_func100(0xeb595fcfU, 0x8cfe5cd8U, 0x632cf2faU, 0x9b78d317U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x41016da6U, 0xc003e0a5U, 0x2162a782U, 0xd743a541U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x80010000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_Cmd[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1C04H, 0x00010011U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C10H, InData_State[1]);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C14H, InData_State[2]);

            WR1_PROG(REG_1C04H, 0x00010010U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C08H, InData_State[0]);

            WR1_PROG(REG_1600H, 0x38000c00U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            HW_SCE_p_func100(0x2b2a6651U, 0x1c143a3cU, 0x27500299U, 0xfb624de7U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1C04H, 0x00010011U);

                HW_SCE_p_func101(0x0bff9697U, 0x8bedb0bfU, 0xf5387feaU, 0x895f1a2fU);
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00010031U);

                HW_SCE_p_func101(0x84b52811U, 0xbd39dfcaU, 0xdde61da1U, 0x70f07a51U);
            }

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[2]);

            for (iLoop = 3; iLoop < 10U; iLoop++)
            {
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_PROG(REG_1C28H, InData_State[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x000034e3U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00009703U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x969efde2U, 0xe9baed83U, 0x1157e3daU, 0xadd2150fU);
            HW_SCE_p_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01d658dfU);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00009703U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xf62737ceU, 0x0f4ef756U, 0xdd158e32U, 0xd1fb2d33U);
            HW_SCE_p_func044();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

            WR1_PROG(REG_1444H, 0x000000c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8009104U);

            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_State[11]);

            WR1_PROG(REG_1608H, 0x80010040U);
            WR1_PROG(REG_1400H, 0x03420005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x0002000dU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_State[12]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            WR1_PROG(REG_1400H, 0x00820011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0xdaa3d606U, 0x14a6c2e1U, 0xc470f75eU, 0xd1c368f7U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func102(0x0adb172eU, 0xc47bba64U, 0x8e7ef884U, 0x588882afU);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_ERR_CRYPTO_SCE_FAIL;
            }
            else
            {
                HW_SCE_p_func100(0xceef5dc1U, 0x895e2b6fU, 0x362e60d4U, 0xfc0dd7d0U);
                WR1_PROG(REG_1608H, 0x81010040U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = change_endian_long(S_RAM[0]);

                WR1_PROG(REG_1600H, 0x38008840U);
                WR1_PROG(REG_1600H, 0x00000001U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);

                HW_SCE_p_func100(0x92bf266cU, 0x317159f1U, 0xfacf2878U, 0xb232aa83U);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    HW_SCE_p_func101(0x84992ed6U, 0x0b0a415cU, 0x3cee9a4dU, 0x44f5849fU);

                    return FSP_ERR_CRYPTO_SCE_PASS_1;
                }
                else
                {
                    HW_SCE_p_func101(0x309ba413U, 0xbced800aU, 0x6739df50U, 0x6f1ee1c5U);

                    return FSP_ERR_CRYPTO_SCE_PASS_2;
                }
            }
        }
    }
}
