/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes128GcmDecryptInitSub (const uint32_t InData_KeyMode[],
                                          const uint32_t InData_KeyIndex[],
                                          const uint32_t InData_Key[],
                                          const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00320001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x3a7ede8aU, 0xad4d9079U, 0xcc0cd6edU, 0x673cdf39U);
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
        WR1_PROG(REG_1420H, change_endian_long(0x00000032U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xc3ecd19cU, 0xcc424026U, 0xb3694133U, 0xda27fd45U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000005U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000032U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x45f98b31U, 0xc4ca8fdaU, 0xf2c53197U, 0x4901ca93U);
        HW_SCE_p_func044();

        HW_SCE_p_func100(0x00741b3eU, 0x56310529U, 0x1ff146a4U, 0x22989b4aU);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xf7009d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

        WR1_PROG(REG_1824H, 0x08000085U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0x4a9cd9cbU, 0x85775e0aU, 0xd876d67aU, 0xb52e3aa5U);
    }
    else
    {
        HW_SCE_p_func100(0xb1ba27fdU, 0xcad569d3U, 0x3e6c927eU, 0xc5dbe6fdU);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000085U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[0]);

        HW_SCE_p_func101(0x3d5681b6U, 0x8f0aa271U, 0x3f140f6cU, 0xf16c74bdU);
    }

    HW_SCE_p_func100(0x7e59c642U, 0x60c4d93eU, 0xd9ad933fU, 0x12a87e51U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xffa49127U, 0xb36da4ccU, 0x9c680785U, 0x7f1b8d60U);
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
        WR1_PROG(REG_182CH, 0x00070000U);
        WR1_PROG(REG_1824H, 0x0a008004U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        HW_SCE_p_func101(0x613cccf8U, 0xe8c4a8d1U, 0xf0dabf25U, 0xa44fe788U);

        return FSP_SUCCESS;
    }
}
