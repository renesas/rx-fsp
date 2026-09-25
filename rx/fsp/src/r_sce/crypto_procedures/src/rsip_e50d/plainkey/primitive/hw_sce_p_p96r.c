/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Chacha20ResumeSub (const uint32_t InData_KeyMode[],
                                    const uint32_t InData_KeyIndex[],
                                    const uint32_t InData_Key[],
                                    const uint32_t InData_Nonce[],
                                    const uint32_t InData_State[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00960001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    HW_SCE_p_func100(0xeee94d5eU, 0x84e424b9U, 0x895c2ccbU, 0x3fb0b87aU);
    WR1_PROG(REG_1C00H, 0x00000001U);

    WR1_PROG(REG_1C04H, 0x00001001U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x33f014bfU, 0x37570026U, 0x04a20d5eU, 0x3b781d39U);
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
        WR1_PROG(REG_1420H, change_endian_long(0x00009602U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x0dcbd55cU, 0xe20249ecU, 0x8c5005ecU, 0x99d80fa8U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000030U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00009602U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x97a2e3bbU, 0x46586efbU, 0x4ddf0bbdU, 0x5bfae583U);
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

        HW_SCE_p_func101(0xdb5453f8U, 0x79173888U, 0x98bb0a9cU, 0x60dad2f7U);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000007c6U);
        WAIT_STS(REG_1444H, 31, 1);
        WR8_ADDR(REG_1420H, &InData_Key[0]);

        HW_SCE_p_func101(0xfcf1e8bbU, 0x30efeabbU, 0x8321e17bU, 0x256a7801U);
    }

    HW_SCE_p_func100(0xbcec4f24U, 0x6a1f401eU, 0xebae2c5aU, 0xeb9ffc5cU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x42903b27U, 0x8c200b65U, 0xff58ad43U, 0xc8030708U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C10H, InData_State[1]);

        WR1_PROG(REG_1C04H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C08H, InData_State[0]);

        WR1_PROG(REG_1C04H, 0x00000001U);

        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C0CH, InData_Nonce[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C0CH, InData_Nonce[1]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C0CH, InData_Nonce[2]);

        HW_SCE_p_func101(0xa2d51d6fU, 0xaff0a452U, 0x7f5ef03eU, 0x5451cd8cU);

        return FSP_SUCCESS;
    }
}
