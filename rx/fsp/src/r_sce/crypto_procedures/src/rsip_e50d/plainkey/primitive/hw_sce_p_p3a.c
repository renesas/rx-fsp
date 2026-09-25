/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_RSA3072_KeyPairGenerateSub (const uint32_t InData_KeyMode[],
                                             uint32_t       OutData_PubKey[],
                                             uint32_t       OutData_PrivKeyIndex[],
                                             uint32_t       OutData_PrivKey[],
                                             uint32_t       MAX_CNT)
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;
    uint32_t kLoop   = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003a0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000e50U);

    WR1_PROG(REG_1600H, 0x00000a31U);
    for (kLoop = 0U; kLoop < MAX_CNT; kLoop++)
    {
        WR1_PROG(REG_1444H, 0x00002fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_160H, 0x00030005U);
        WR1_PROG(REG_164H, 0x0007000bU);
        WR1_PROG(REG_168H, 0x000d0011U);
        WR1_PROG(REG_16CH, 0x00130017U);
        WR1_PROG(REG_170H, 0x001d001fU);
        WR1_PROG(REG_174H, 0x00250029U);
        WR1_PROG(REG_178H, 0x002b002fU);
        WR1_PROG(REG_17CH, 0x003b003dU);
        WR1_PROG(REG_180H, 0x00430047U);
        WR1_PROG(REG_184H, 0x0049004fU);
        WR1_PROG(REG_188H, 0x00530059U);
        WR1_PROG(REG_18CH, 0x00610065U);
        WR1_PROG(REG_190H, 0x0067006bU);
        WR1_PROG(REG_194H, 0x006d0071U);
        WR1_PROG(REG_198H, 0x007f0083U);
        WR1_PROG(REG_19CH, 0x0089008bU);
        WR1_PROG(REG_1A0H, 0x00950097U);
        WR1_PROG(REG_1A4H, 0x009d00a3U);
        WR1_PROG(REG_1A8H, 0x00a700adU);
        WR1_PROG(REG_1ACH, 0x00b300b5U);
        WR1_PROG(REG_1B0H, 0x00bf00c1U);
        WR1_PROG(REG_1B4H, 0x00c500c7U);
        WR1_PROG(REG_1B8H, 0x00d300dfU);
        WR1_PROG(REG_1BCH, 0x00e300e5U);
        WR1_PROG(REG_1C0H, 0x00e900efU);
        WR1_PROG(REG_1C4H, 0x00f100fbU);
        WR1_PROG(REG_1C8H, 0x01010107U);
        WR1_PROG(REG_1CCH, 0x010d010fU);
        WR1_PROG(REG_1D0H, 0x01150119U);
        WR1_PROG(REG_1D4H, 0x011b0125U);
        WR1_PROG(REG_1D8H, 0x01330137U);
        WR1_PROG(REG_1DCH, 0x0139013dU);
        WR1_PROG(REG_1E0H, 0x014b0151U);
        WR1_PROG(REG_1E4H, 0x015b015dU);
        WR1_PROG(REG_1E8H, 0x01610167U);
        WR1_PROG(REG_1ECH, 0x016f0175U);
        WR1_PROG(REG_1F0H, 0x017b017fU);
        WR1_PROG(REG_1F4H, 0x0185018dU);
        WR1_PROG(REG_1F8H, 0x01910199U);
        WR1_PROG(REG_1FCH, 0x01a301a5U);
        WR1_PROG(REG_200H, 0x01af01b1U);
        WR1_PROG(REG_204H, 0x01b701bbU);
        WR1_PROG(REG_208H, 0x01c101c9U);
        WR1_PROG(REG_20CH, 0x01cd01cfU);
        WR1_PROG(REG_210H, 0x01d301dfU);
        WR1_PROG(REG_214H, 0x01e701ebU);
        WR1_PROG(REG_218H, 0x01f301f7U);
        WR1_PROG(REG_21CH, 0x01fd0000U);

        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x000000c0U);
        WR1_PROG(REG_1608H, 0x80b00006U);
        WR1_PROG(REG_1404H, 0x11600000U);
        WR1_PROG(REG_1400H, 0x034300c1U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0x52dbf671U, 0xdd1cd0a7U, 0x32280981U, 0xfc0a823bU);
        HW_SCE_p_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1400H, 0x03420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1404H, 0x11600000U);
        WR1_PROG(REG_1400H, 0x00c90011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000028U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 40U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0xa1613597U, 0xf2b84778U, 0x3daae153U, 0xa4b15f27U);
            HW_SCE_p_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

            WR1_PROG(REG_1400H, 0x00c20011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0x03d0f2a5U, 0x9c92d9c1U, 0xa8067164U, 0xdfb23bd3U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0x511a250aU, 0x7d560160U, 0xd3dd9cb9U, 0xe419e0beU);
        HW_SCE_p_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1400H, 0x03420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1400H, 0x00c90011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x00002fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_980H, 0xB51EB851U);
        WR1_PROG(REG_984H, 0xEB851EB8U);
        WR1_PROG(REG_988H, 0x51EB851EU);
        WR1_PROG(REG_98CH, 0xB851EB85U);
        WR1_PROG(REG_990H, 0x1EB851EBU);
        WR1_PROG(REG_994H, 0x851EB851U);
        WR1_PROG(REG_998H, 0xEB851EB8U);
        WR1_PROG(REG_99CH, 0x51EB851EU);
        WR1_PROG(REG_9A0H, 0xB851EB85U);
        WR1_PROG(REG_9A4H, 0x1EB851EBU);
        WR1_PROG(REG_9A8H, 0x851EB851U);
        WR1_PROG(REG_9ACH, 0xEB851EB8U);
        WR1_PROG(REG_9B0H, 0x51EB851EU);
        WR1_PROG(REG_9B4H, 0xB851EB85U);
        WR1_PROG(REG_9B8H, 0x1EB851EBU);
        WR1_PROG(REG_9BCH, 0x851EB851U);
        WR1_PROG(REG_9C0H, 0xEB851EB8U);
        WR1_PROG(REG_9C4H, 0x51EB851EU);
        WR1_PROG(REG_9C8H, 0xB851EB85U);
        WR1_PROG(REG_9CCH, 0x1EB851EBU);
        WR1_PROG(REG_9D0H, 0x851EB851U);
        WR1_PROG(REG_9D4H, 0xEB851EB8U);
        WR1_PROG(REG_9D8H, 0x51EB851EU);
        WR1_PROG(REG_9DCH, 0xB851EB85U);
        WR1_PROG(REG_9E0H, 0x1EB851EBU);
        WR1_PROG(REG_9E4H, 0x851EB851U);
        WR1_PROG(REG_9E8H, 0xEB851EB8U);
        WR1_PROG(REG_9ECH, 0x51EB851EU);
        WR1_PROG(REG_9F0H, 0xB851EB85U);
        WR1_PROG(REG_9F4H, 0x1EB851EBU);
        WR1_PROG(REG_9F8H, 0x851EB851U);
        WR1_PROG(REG_9FCH, 0xEB851EB8U);
        WR1_PROG(REG_A00H, 0x51EB851EU);
        WR1_PROG(REG_A04H, 0xB851EB85U);
        WR1_PROG(REG_A08H, 0x1EB851EBU);
        WR1_PROG(REG_A0CH, 0x851EB851U);
        WR1_PROG(REG_A10H, 0xEB851EB8U);
        WR1_PROG(REG_A14H, 0x51EB851EU);
        WR1_PROG(REG_A18H, 0xB851EB85U);
        WR1_PROG(REG_A1CH, 0x1EB851EBU);
        WR1_PROG(REG_A20H, 0x851EB851U);
        WR1_PROG(REG_A24H, 0xEB851EB8U);
        WR1_PROG(REG_A28H, 0x51EB851EU);
        WR1_PROG(REG_A2CH, 0xB851EB85U);
        WR1_PROG(REG_A30H, 0x1EB851EBU);
        WR1_PROG(REG_A34H, 0x851EB851U);
        WR1_PROG(REG_A38H, 0xEB851EB8U);
        WR1_PROG(REG_A3CH, 0x51EB851EU);

        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x1818000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0xe8517e13U, 0x9534283fU, 0x2f0f1b9fU, 0x451dc76eU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0xaafaf519U, 0x0d01ba0bU, 0xc1fd5bcaU, 0x86fdb5aeU);
            continue;
        }
        else
        {
            HW_SCE_p_func101(0x6ad71624U, 0x9f7824ccU, 0x4fe17decU, 0xf5f9120dU);
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x486fd7e1U, 0x07affe5bU, 0x81006f58U, 0xee25f0e1U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000320U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x1818000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0xe3bf2b62U, 0x76312d3fU, 0x280ddd91U, 0x203775caU);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_1018H, 0x00000320U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x1818000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                HW_SCE_p_func101(0x402c4f54U, 0x2a55d44bU, 0x2d1697d3U, 0xe4ec77ecU);
            }
            else
            {
                HW_SCE_p_func101(0xee8d62a6U, 0x38d41b1cU, 0x4e1f55a9U, 0xe060e726U);
            }

            WR1_PROG(REG_1404H, 0x19800000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H, change_endian_long(0x00000000U), change_endian_long(0x00000000U),
                     change_endian_long(0x00000000U), change_endian_long(0x10000000U));
            WR1_PROG(REG_1400H, 0x00c20011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00c000b1U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000a40U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1818000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0xaf5f8842U, 0x67887dd1U, 0x9bae64d2U, 0x993e6588U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func101(0x14a05dafU, 0x040a21bdU, 0x26097895U, 0x693df18cU);
                continue;
            }
            else
            {
                HW_SCE_p_func101(0x00a01951U, 0x68d75baaU, 0x8010ead5U, 0xef1bdc38U);
            }
        }
        else
        {
            HW_SCE_p_func101(0x13782c9eU, 0x1a5ff703U, 0x2d596ff1U, 0x41af557dU);
        }

        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x000000c0U);
        WR1_PROG(REG_1600H, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            WR1_PROG(REG_1600H, 0x01003906U);
            WR1_PROG(REG_1600H, 0x00002cc0U);
            WR1_PROG(REG_1600H, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x15700000U);
            WR1_PROG(REG_1400H, 0x00c000bdU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00c90005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_101CH, 0x00000630U);

            WR1_PROG(REG_1004H, 0x18180010U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x18180004U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19800000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
            WR1_PROG(REG_1400H, 0x00c000bdU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00c20005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x0002000dU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000a40U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x1818000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0x19f54cdfU, 0xd4124086U, 0xa23ba4a4U, 0x4eca3156U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                HW_SCE_p_func101(0x3b56324cU, 0xc5598383U, 0xbce6d142U, 0x2b36a8c7U);
                break;
            }
            else
            {
                HW_SCE_p_func101(0x0f7f64b1U, 0xd9598548U, 0x4bb54400U, 0xf08bebeeU);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0xaf1dee1bU, 0xb00f9fe5U, 0xe25f7c7fU, 0x023a9b46U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0xb408aa43U, 0x88bb1654U, 0xd869f05fU, 0x26c34d84U);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18780000U);
        WR1_PROG(REG_1400H, 0x00c000c1U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000938U);
        WR1_PROG(REG_1020H, 0x00000428U);

        WR1_PROG(REG_1004H, 0x18180009U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000428U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        WR1_PROG(REG_1020H, 0x00000220U);

        WR1_PROG(REG_1004H, 0x1818000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x15700000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00010001U));
        WR1_PROG(REG_1400H, 0x00c000bdU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_101CH, 0x00000630U);

        WR1_PROG(REG_1004H, 0x18180010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x18180004U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19800000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c000bdU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000838U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        WR1_PROG(REG_1020H, 0x00000630U);

        WR1_PROG(REG_1004H, 0x1818000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x846890cdU, 0xc7928b5cU, 0x4b759279U, 0x509b77e0U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0x4744f3e6U, 0xa361ecacU, 0xdddede76U, 0xb01bcaa6U);
        }
        else
        {
            HW_SCE_p_func100(0x32b8498eU, 0xb1ac4b91U, 0xcece8048U, 0x9d4266cbU);
            WR1_PROG(REG_1404H, 0x17780000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
            WR1_PROG(REG_1400H, 0x00c000bdU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00c20005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x0002000dU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_101CH, 0x00000428U);

            WR1_PROG(REG_1004H, 0x18180010U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000428U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x18180000U);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000a40U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1818000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1818000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0x47c2ae78U, 0xbd04d155U, 0x8a0813a5U, 0xc5a321daU);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func101(0xfe142a09U, 0x76723251U, 0xe1145625U, 0x1ade2cf6U);
                continue;
            }

            HW_SCE_p_func100(0x11c4b7bfU, 0x894a87e8U, 0x69fef591U, 0xd129b8e6U);

            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1600H, 0x00000002U);

            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80b0000aU);
            WR1_PROG(REG_1404H, 0x11600000U);
            WR1_PROG(REG_1400H, 0x034300c1U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1600H, 0x00000908U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1600H, 0x000000bcU);

            for (iLoop = 0U; iLoop < 48U; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x000038e6U);
                WR1_PROG(REG_1600H, 0x0000a8c0U);
                WR1_PROG(REG_1600H, 0x00000004U);
                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    WR1_PROG(REG_1600H, 0x38008900U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x11816907U);

                    WR1_PROG(REG_1600H, 0x38008900U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x10002d20U);

                    WR1_PROG(REG_1600H, 0x000168e7U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1608H, 0x81010120U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = change_endian_long(S_RAM[0]);
            WR1_PROG(REG_1600H, 0x000037e9U);

            WR1_PROG(REG_1404H, 0x15700000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x81b0000aU);
            WR1_PROG(REG_1400H, 0x00c900c1U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x1818000cU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000938U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x18180009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1600H, 0x000033e0U);

                HW_SCE_p_func101(0xe4fc63f2U, 0x69d46eaeU, 0xfdb853e0U, 0x89cbc1f1U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x85935357U, 0x2f66843dU, 0x4caba342U, 0xdde68132U);
            WR1_PROG(REG_1600H, 0x00000a52U);

            WR1_PROG(REG_1608H, 0x81010160U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = change_endian_long(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x00000884U);
                WR1_PROG(REG_1600H, 0x0000b4a0U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1600H, 0x0000b4c0U);
                WR1_PROG(REG_1600H, 0x00000030U);
                WR1_PROG(REG_1600H, 0x000008e7U);

                WR1_PROG(REG_1404H, 0x11600000U);
                for (jLoop = 0U; jLoop < 48U; jLoop = jLoop + 4U)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    WR1_PROG(REG_1600H, 0x00007c07U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    HW_SCE_p_func100(0xc1ae6a4bU, 0x056554abU, 0xee79c83dU, 0x4ff26f9aU);
                    HW_SCE_p_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

                    WR1_PROG(REG_1400H, 0x00c20011U);
                    WAIT_STS(REG_1404H, 30, 0);
                    WR1_PROG(REG_143CH, 0x00001800U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    HW_SCE_p_func101(0x00901461U, 0xb9e276e3U, 0xa51e3676U, 0xd5ed612eU);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func100(0x7e48b313U, 0xd357a08eU, 0x7f781016U, 0x7537b5dbU);
                WR1_PROG(REG_1404H, 0x19800000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000004U));
                WR1_PROG(REG_1400H, 0x00c000bdU);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c20005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x0002000dU);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1014H, 0x00000428U);
                WR1_PROG(REG_1018H, 0x00000a40U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x1818000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1010H, 0x00000018U);
                WR1_PROG(REG_101CH, 0x00000838U);

                WR1_PROG(REG_1004H, 0x18180010U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000a40U);

                WR1_PROG(REG_1004H, 0x18180004U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17780000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
                WR1_PROG(REG_1400H, 0x00c000bdU);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c20005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x0002000dU);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1014H, 0x00000a40U);
                WR1_PROG(REG_1018H, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x18180009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1010H, 0x00000018U);
                WR1_PROG(REG_101CH, 0x00000428U);

                WR1_PROG(REG_1004H, 0x18180010U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_1018H, 0x00000630U);
                WR1_PROG(REG_101CH, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x18180000U);
                WR1_PROG(REG_1408H, 0x00020000U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x19800000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
                WR1_PROG(REG_1400H, 0x00c000bdU);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x00c20005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x0002000dU);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000a40U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x1818000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_143CH, 0x00210000U);

                WR1_PROG(REG_1014H, 0x00000a40U);
                WR1_PROG(REG_1018H, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x1818000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_143CH, 0x00210000U);

                HW_SCE_p_func100(0xf78c21a0U, 0x129ef560U, 0xadf6e92aU, 0xaafbaa8cU);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    HW_SCE_p_func101(0xeb25cc8fU, 0xe31716e0U, 0xdda3818bU, 0x394fba46U);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    HW_SCE_p_func100(0x43e7e15cU, 0xa89fd22bU, 0xa85680bcU, 0xcbce9ef8U);
                    WR1_PROG(REG_1608H, 0x81010120U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = change_endian_long(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19800000U);
                        WR1_PROG(REG_1608H, 0x81b0000aU);
                        WR1_PROG(REG_1400H, 0x00c900c1U);
                        WAIT_STS(REG_1404H, 30, 0);
                        WR1_PROG(REG_143CH, 0x00001800U);

                        WR1_PROG(REG_1014H, 0x00000838U);
                        WR1_PROG(REG_1018H, 0x00000a40U);
                        WR1_PROG(REG_1020H, 0x00000220U);

                        WR1_PROG(REG_1004H, 0x1818000aU);
                        WR1_PROG(REG_1000H, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        WR1_PROG(REG_1014H, 0x00000a40U);
                        WR1_PROG(REG_1018H, 0x00000838U);
                        WR1_PROG(REG_1020H, 0x00000220U);

                        WR1_PROG(REG_1004H, 0x1818000aU);
                        WR1_PROG(REG_1000H, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        HW_SCE_p_func100(0x05cd99b0U, 0x196f82efU, 0xe465ad8bU, 0x797bc6faU);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            HW_SCE_p_func101(0x459041bbU, 0x98cb6768U, 0x7f222b62U, 0x47af6640U);
                            break;
                        }
                        else
                        {
                            HW_SCE_p_func100(0x30aa9ac4U, 0x64c9bd2aU, 0xfd06e960U, 0x2a6c25aaU);
                            WR1_PROG(REG_1404H, 0x19800000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31, 1);
                            WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
                            WR1_PROG(REG_1400H, 0x00c000bdU);
                            WAIT_STS(REG_1404H, 30, 0);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            WR1_PROG(REG_1400H, 0x00c20005U);
                            WAIT_STS(REG_1404H, 30, 0);
                            WR1_PROG(REG_143CH, 0x00001800U);
                            WR1_PROG(REG_1400H, 0x0002000dU);
                            WAIT_STS(REG_1404H, 30, 0);
                            WR1_PROG(REG_143CH, 0x00001800U);

                            WR1_PROG(REG_1014H, 0x00000838U);
                            WR1_PROG(REG_1018H, 0x00000a40U);
                            WR1_PROG(REG_101CH, 0x00000428U);
                            WR1_PROG(REG_1020H, 0x00000220U);

                            WR1_PROG(REG_1004H, 0x18180000U);
                            WR1_PROG(REG_1408H, 0x00020000U);
                            WR1_PROG(REG_1000H, 0x00010001U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            WR1_PROG(REG_1014H, 0x00000220U);
                            WR1_PROG(REG_1018H, 0x00000938U);
                            WR1_PROG(REG_1020H, 0x00000838U);

                            WR1_PROG(REG_1004H, 0x18180009U);
                            WR1_PROG(REG_1000H, 0x00010001U);
                            WAIT_STS(REG_1000H, 0, 0);

                            HW_SCE_p_func101(0x3a83f686U, 0x9aaaacabU, 0x16b52607U, 0x19e14dabU);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);

                    HW_SCE_p_func100(0x254c0a89U, 0x6d28a3f8U, 0x1a88bcbbU, 0xbc53501eU);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        HW_SCE_p_func101(0x0f44fe55U, 0xd1863629U, 0x3fa49ee5U, 0x1a949f32U);
                        break;
                    }
                    else
                    {
                        HW_SCE_p_func101(0xb5214813U, 0x6cd15972U, 0xf6e382fbU, 0x4020381fU);
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            HW_SCE_p_func100(0x2aec472eU, 0x1089c37cU, 0x4fa7b8faU, 0xe3893d02U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                WR1_PROG(REG_1600H, 0x38008a20U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);

                HW_SCE_p_func100(0xfba9438fU, 0xa07eb983U, 0x3750df39U, 0x4a60a50dU);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    HW_SCE_p_func101(0x70a142aaU, 0x5d81dc1aU, 0x9cf2b79dU, 0xc5a55a86U);
                    break;
                }
                else
                {
                    WR1_PROG(REG_1014H, 0x00000428U);
                    WR1_PROG(REG_1018H, 0x00000938U);
                    WR1_PROG(REG_1020H, 0x00000320U);

                    WR1_PROG(REG_1004H, 0x18180009U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    HW_SCE_p_func101(0xafb2683dU, 0x5c39a391U, 0xb4f1bac7U, 0xdd3fa9f5U);
                }
            }
            else
            {
                HW_SCE_p_func101(0x2cda7a74U, 0x77461fbbU, 0x06741171U, 0xc549f6c9U);
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0xdbb9511aU, 0x6c95ecf5U, 0x59e791eaU, 0x1289139aU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x999efaddU, 0xbde3c407U, 0x0df50607U, 0x060d820cU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1400H, 0x00c000c1U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000838U);

    WR1_PROG(REG_1004H, 0x18180009U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000320U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000778U);

    WR1_PROG(REG_1004H, 0x18180009U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    HW_SCE_p_func100(0xc9a18a6bU, 0xe628841bU, 0x5806bb70U, 0xb3f3df51U);
    HW_SCE_p_func103();
    HW_SCE_p_func100(0x5f1e22b7U, 0x423fd333U, 0x3307d5bfU, 0xf284a562U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x51daaa41U));

    OFS_ADR = 516;

    WR1_PROG(REG_1404H, 0x16b80000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000060U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003a01U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x5091beeaU, 0x600161e1U, 0xbb197c26U, 0x9027058fU);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c000bdU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c20005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000320U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x1818000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000630U);

    WR1_PROG(REG_1004H, 0x1818000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000003aU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x9975d349U, 0x50d20993U, 0x633b2d84U, 0x821c09bbU);
    HW_SCE_p_func313();

    WR1_PROG(REG_1404H, 0x14a00000U);
    WR1_PROG(REG_1400H, 0x00c000d1U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x51daaa41U));

    OFS_ADR = 516;

    WR1_PROG(REG_1404H, 0x16b80000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000060U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003a01U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xa5835b0cU, 0x063609e2U, 0xaf8a8677U, 0xf78c82b2U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1014H, 0x00000778U);
    WR1_PROG(REG_1018H, 0x00000838U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x18180007U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003a01U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xa394aad2U, 0x92629865U, 0xf164bbd9U, 0x6e31c77aU);
    HW_SCE_p_func315();

    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c0017dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c20005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000630U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x3030000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    WR1_PROG(REG_1014H, 0x00000a40U);
    WR1_PROG(REG_1018H, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x3030000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    HW_SCE_p_func100(0x482dfe35U, 0xe24f71d0U, 0xfcd1ded0U, 0xf384c69bU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x03c3912aU, 0xc38c433fU, 0x1c93bbdfU, 0x8d93afedU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x51daaa41U));

    OFS_ADR = 516;

    WR1_PROG(REG_1404H, 0x12a80000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000060U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003a02U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xd64c6f93U, 0x12e81d2bU, 0x0b3548c6U, 0xba8477c4U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1014H, 0x00000368U);
    WR1_PROG(REG_1018H, 0x00000428U);
    WR1_PROG(REG_1020H, 0x00000630U);

    WR1_PROG(REG_1004H, 0x18180007U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x51daaa41U));

    OFS_ADR = 516;

    WR1_PROG(REG_1404H, 0x14b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000060U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003a02U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xb9373eaeU, 0x2dd1deeeU, 0x3143a1c6U, 0x3411bac1U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c000bdU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c20005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x1818000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000368U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000160U);

    WR1_PROG(REG_1004H, 0x1818000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000160U);
    WR1_PROG(REG_1018H, 0x00000220U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x18180007U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1010H, 0x00000018U);
    WR1_PROG(REG_101CH, 0x00000630U);

    WR1_PROG(REG_1004H, 0x30300010U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000838U);
    WR1_PROG(REG_101CH, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x30300002U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x30300003U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000220U);
    WR1_PROG(REG_101CH, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x30300002U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x14b00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00010001U));
    WR1_PROG(REG_1400H, 0x00c0017dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c20005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003a02U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xba7f3ab5U, 0x6d2f8ae3U, 0xc677a1f3U, 0x945710dbU);
    HW_SCE_p_func315();

    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c0017dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x00c20005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000630U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x3030000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    WR1_PROG(REG_1014H, 0x00000a40U);
    WR1_PROG(REG_1018H, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x3030000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    HW_SCE_p_func100(0xba1f902bU, 0x1cf12aeeU, 0x1dcf523bU, 0xb150e794U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xfb26959bU, 0x5b907fd3U, 0x84cab7ebU, 0x1eca0912U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1400H, 0x00c00181U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000838U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x30300009U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x51daaa41U));

    OFS_ADR = 516;

    WR1_PROG(REG_1404H, 0x14b00000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000060U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00003a0fU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x1306fc3fU, 0x684c1666U, 0x10f5dbb8U, 0xd440e5fdU);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1600H, 0x00010001U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x800103e0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x63e857eeU, 0x84f7e0c3U, 0xe58d0cf5U, 0x147224d6U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func100(0x31bddc75U, 0x90d55c59U, 0x36f4094bU, 0x2195f398U);
        HW_SCE_p_func103();

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1608H, 0x80010000U);
        WR1_PROG(REG_1400H, 0x03420005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x000034e0U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00003a01U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x5d49b98aU, 0xe4990714U, 0x7e5a89d4U, 0x1cda2eb5U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x0000000fU);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00003a01U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xcd2d2f4bU, 0xcc27d1b0U, 0x0f6cd627U, 0xb512babdU);
        HW_SCE_p_func044();

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000060U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x14b00000U);
        for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0xf4dfc676U, 0xd6836d38U, 0xd7229a93U, 0x8e79e18eU);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0xf876b6faU, 0xb8ead6dcU, 0xb48f4e87U, 0x9c933122U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000060U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x12a80000U);
        for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x25150681U, 0x9a4c351cU, 0xddcd52d3U, 0xe8d1e7f3U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[97 + iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0xc4b59355U, 0xcd8b1cc4U, 0x4bcc4177U, 0x82be4529U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0x074b12c9U, 0x443135c1U, 0xc7a68e67U, 0xa2664598U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[193]);

        HW_SCE_p_func100(0xadf15b04U, 0xccabb041U, 0xef48896bU, 0x985333c6U);
        WR1_PROG(REG_1608H, 0x81010000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        HW_SCE_p_func101(0x8f261350U, 0x953095beU, 0x7f310a3dU, 0xa8294f3eU);
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000060U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x14b00000U);
        for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x83e6abfbU, 0xf85c0230U, 0x75e8eb97U, 0x7b6c663aU);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKey[iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0xa6b37254U, 0x775f4252U, 0x8986bc00U, 0x5e1ee2f0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000060U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x12a80000U);
        for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x1d16248cU, 0x963e3090U, 0x9c25708aU, 0x38d3c693U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKey[96 + iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0x839d05edU, 0x2ed8d6cfU, 0x5634bd12U, 0x13450a1cU);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x92ca2045U, 0x32ed35dbU, 0xbef04d53U, 0x5e9c3b55U);
    }

    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1600H, 0x000008e7U);

    WR1_PROG(REG_1404H, 0x14b00000U);
    for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0xffe55792U, 0x094dd14cU, 0x3e0bc3b9U, 0x0e24dc74U);
        WR1_PROG(REG_1A24H, 0x08000105U);
        WR1_PROG(REG_1400H, 0x00830011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKey[iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        HW_SCE_p_func101(0xa53a4a8bU, 0x823303b1U, 0xdd26aee8U, 0x42002d9aU);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func100(0x244fa22cU, 0x93e50d49U, 0x3cdad7f7U, 0x0b85e608U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WR1_PROG(REG_1608H, 0x81010280U);
    WR1_PROG(REG_1400H, 0x00890005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKey[96]);

    HW_SCE_p_func102(0x2d3a1b62U, 0xab92d436U, 0xe9d75682U, 0xe3803d9aU);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
