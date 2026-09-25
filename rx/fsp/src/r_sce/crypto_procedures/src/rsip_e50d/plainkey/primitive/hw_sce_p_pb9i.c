/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes256XtsEncryptInitSub (const uint32_t InData_KeyMode[],
                                          const uint32_t InData_KeyIndex[],
                                          const uint32_t InData_Key[],
                                          const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00b90001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xdd35954aU, 0xebedb61dU, 0xfe53ecc5U, 0x70102ea6U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800100e0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x000000b9U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x1ba2745fU, 0xada335dfU, 0x0458eb42U, 0x88adc983U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000009U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x000000b9U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xede16147U, 0xddd1b5e1U, 0x7027f07fU, 0xb063f474U);
        HW_SCE_p_func044();

        HW_SCE_p_func100(0x68758d61U, 0xef69375aU, 0xa8c2ace5U, 0x86eb0495U);
        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        WR1_PROG(REG_1824H, 0x08000085U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0xb8d03d59U, 0x2bc6b89eU, 0x44f5e606U, 0x03ba5c48U);
        WR1_PROG(REG_1824H, 0x08000095U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0x75f36036U, 0xc98dcc5aU, 0x11d55424U, 0x891046fcU);
        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7008d07U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);

        WR1_PROG(REG_1824H, 0x080000a5U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0x11b84addU, 0x889e763bU, 0xd54e0cdbU, 0x1805c40aU);
        WR1_PROG(REG_1824H, 0x080000b5U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0xdf7e86e3U, 0x74160bf5U, 0x94dc3d85U, 0x4106bd01U);
    }
    else
    {
        HW_SCE_p_func100(0x4204b9c5U, 0x00e60c4dU, 0x04b0da1cU, 0xd36ca915U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000085U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[0]);

        HW_SCE_p_func100(0x182b78f5U, 0xad06b6f6U, 0x16dd2019U, 0x905f94ebU);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000095U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[4]);

        HW_SCE_p_func100(0x552c4c17U, 0x9822f87eU, 0xb4a625acU, 0xe6e568fbU);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x080000a5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[8]);

        HW_SCE_p_func100(0xbecd6603U, 0x1b72df5cU, 0x03f92964U, 0x7700ef95U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x080000b5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[12]);

        HW_SCE_p_func101(0xa8ce7e8aU, 0x0f57b8baU, 0xde59883eU, 0xec764c11U);
    }

    HW_SCE_p_func100(0x32540039U, 0x977c8e35U, 0x9a114c01U, 0xe7ff0edfU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x04cbb1c6U, 0xbe1aad59U, 0x7bb07be4U, 0x7c0f36e5U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x0a028045U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_IV[0]);

        HW_SCE_p_func101(0x12510748U, 0xf2033290U, 0x1c1752f4U, 0xbd4436f0U);

        return FSP_SUCCESS;
    }
}
