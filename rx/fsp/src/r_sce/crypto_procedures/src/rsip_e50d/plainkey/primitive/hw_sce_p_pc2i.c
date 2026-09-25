/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes256XtsDecryptInitSub (const uint32_t InData_KeyMode[],
                                          const uint32_t InData_KeyIndex[],
                                          const uint32_t InData_Key[],
                                          const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00c20001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xdd6340c5U, 0x95e83821U, 0x715e0182U, 0x6c3d3503U);
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
        WR1_PROG(REG_1420H, change_endian_long(0x000000c2U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xba9fad92U, 0xc879a743U, 0xa8f25483U, 0x866c0570U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000009U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x000000c2U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xabcab389U, 0x58f1f52dU, 0x41504afdU, 0x526ea34bU);
        HW_SCE_p_func044();

        HW_SCE_p_func100(0x1f03bd2eU, 0xcc11a658U, 0x63752351U, 0x332ae732U);
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

        HW_SCE_p_func100(0x82492c8aU, 0x0a5a8ff9U, 0x710bb969U, 0xa1e4bfb5U);
        WR1_PROG(REG_1824H, 0x08000095U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0xa3e271e8U, 0x8665c27bU, 0x517982a3U, 0x7dfc9ca9U);
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

        HW_SCE_p_func100(0xa34bbffeU, 0x63d4fde4U, 0x3584acdfU, 0x697b00feU);
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

        HW_SCE_p_func101(0x203d0526U, 0x7d2f4b36U, 0x9ddd87cbU, 0xcf42bddeU);
    }
    else
    {
        HW_SCE_p_func100(0xbc2935f8U, 0x8d0853d4U, 0x3b5279d5U, 0x2da7dc16U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000085U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[0]);

        HW_SCE_p_func100(0x249e2d72U, 0x08c6eba7U, 0xe5696f83U, 0x373d6bcbU);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000095U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[4]);

        HW_SCE_p_func100(0xdd3f004eU, 0x06222465U, 0xdab4309aU, 0xf1f30157U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x080000a5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[8]);

        HW_SCE_p_func100(0x1b0b83bcU, 0x1390bc74U, 0xf31d99b8U, 0x1388ac40U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x080000b5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[12]);

        HW_SCE_p_func101(0xb9727dbbU, 0x8e1c8bc7U, 0x573c880eU, 0x5d15d0daU);
    }

    HW_SCE_p_func100(0x416246ccU, 0xe4577006U, 0x5d6d819dU, 0x7a8b2bf5U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xd65644f8U, 0xacc2f408U, 0xed42a627U, 0x82fb45f2U);
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

        HW_SCE_p_func101(0x38e7060fU, 0x95b18e39U, 0x57f1f37bU, 0x518870d4U);

        return FSP_SUCCESS;
    }
}
