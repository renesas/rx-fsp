/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes256GcmDecryptInitSub (const uint32_t InData_KeyMode[],
                                          const uint32_t InData_KeyIndex[],
                                          const uint32_t InData_Key[],
                                          const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00360001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x11e65ff9U, 0x7c4ce9e6U, 0xfb30ecf7U, 0xbeb0761cU);
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
        WR1_PROG(REG_1420H, change_endian_long(0x00000036U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x0874f353U, 0x88cc0d49U, 0x0024a455U, 0xef8337adU);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000007U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000036U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x4e3ca8ceU, 0x1f0ee7f4U, 0xbbeea774U, 0x85b4fd85U);
        HW_SCE_p_func044();

        HW_SCE_p_func100(0xff6917b7U, 0xb4deba07U, 0xb2dd54d8U, 0xb734c1c1U);
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

        HW_SCE_p_func100(0x0127f879U, 0x9aa6adcbU, 0x9ab2b113U, 0x7181dde7U);
        WR1_PROG(REG_1824H, 0x08000095U);
        WR1_PROG(REG_1400H, 0x00420011U);
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

        HW_SCE_p_func101(0x04980865U, 0x593e3e15U, 0xfa418c05U, 0x76a3c0f8U);
    }
    else
    {
        HW_SCE_p_func100(0x8e84351dU, 0x62809252U, 0x26725699U, 0xe6ddace0U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000085U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[0]);

        HW_SCE_p_func100(0x9711fbcdU, 0x55dde621U, 0x6c911bfaU, 0x2440e04fU);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000095U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[4]);

        HW_SCE_p_func101(0x6485c91eU, 0xbb3586e8U, 0x887b8ca2U, 0x53a3e240U);
    }

    HW_SCE_p_func100(0x008e2ab6U, 0x65c6fea0U, 0xb8eb64d7U, 0x4ecef1a0U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x55062f35U, 0xf7ba3422U, 0xf02b9c8eU, 0xdcd1e7ffU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040080U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_IV[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_IV[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_IV[2]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_IV[3]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x08000024U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_182CH, 0x40070000U);
        WR1_PROG(REG_1824H, 0x0a008004U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        HW_SCE_p_func101(0x7d74fecaU, 0xe89376b9U, 0x6119dd5cU, 0xcfbfd780U);

        return FSP_SUCCESS;
    }
}
