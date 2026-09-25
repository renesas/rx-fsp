/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_RSA2048_KeyPairGenerateSub (const uint32_t InData_KeyMode[],
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

    WR1_PROG(REG_1B00H, 0x002b0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000e50U);

    WR1_PROG(REG_1600H, 0x00000a31U);
    for (kLoop = 0U; kLoop < MAX_CNT; kLoop++)
    {
        WR1_PROG(REG_1404H, 0x11600000U);
        WR1_PROG(REG_1444H, 0x00002fa2U);
        WR1_PROG(REG_1A2CH, 0x00000b00U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x00030005U), change_endian_long(0x0007000bU),
                 change_endian_long(0x000d0011U), change_endian_long(0x00130017U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x001d001fU), change_endian_long(0x00250029U),
                 change_endian_long(0x002b002fU), change_endian_long(0x003b003dU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x00430047U), change_endian_long(0x0049004fU),
                 change_endian_long(0x00530059U), change_endian_long(0x00610065U));
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x0067006bU), change_endian_long(0x006d0071U),
                 change_endian_long(0x007f0083U), change_endian_long(0x0089008bU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x00950097U), change_endian_long(0x009d00a3U),
                 change_endian_long(0x00a700adU), change_endian_long(0x00b300b5U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x00bf00c1U), change_endian_long(0x00c500c7U),
                 change_endian_long(0x00d300dfU), change_endian_long(0x00e300e5U));
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x00e900efU), change_endian_long(0x00f100fbU),
                 change_endian_long(0x01010107U), change_endian_long(0x010d010fU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x01150119U), change_endian_long(0x011b0125U),
                 change_endian_long(0x01330137U), change_endian_long(0x0139013dU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x014b0151U), change_endian_long(0x015b015dU),
                 change_endian_long(0x01610167U), change_endian_long(0x016f0175U));
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x017b017fU), change_endian_long(0x0185018dU),
                 change_endian_long(0x01910199U), change_endian_long(0x01a301a5U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x01af01b1U), change_endian_long(0x01b701bbU),
                 change_endian_long(0x01c101c9U), change_endian_long(0x01cd01cfU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x01d301dfU), change_endian_long(0x01e701ebU),
                 change_endian_long(0x01f301f7U), change_endian_long(0x01fd0000U));
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1608H, 0x80b00006U);
        WR1_PROG(REG_1404H, 0x11600000U);
        WR1_PROG(REG_1400H, 0x034300c1U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x10180000U);
        WR1_PROG(REG_1400H, 0x00c00209U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0x7c226932U, 0xc92c7da4U, 0x53a95f89U, 0x2b7e59deU);
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
        WR1_PROG(REG_1404H, 0x11a00000U);
        WR1_PROG(REG_1400H, 0x00c90011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000018U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 24U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x5342704fU, 0xd96c7825U, 0x8a472a88U, 0x598f204bU);
            HW_SCE_p_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

            WR1_PROG(REG_1400H, 0x00c20011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0x1b0558d2U, 0x4de99e22U, 0xfc3642bbU, 0xaa57b71eU);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0xd3237af3U, 0xc2349435U, 0x052a16bfU, 0xe3d8d64eU);
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

        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x00001fa2U);
        WR1_PROG(REG_1A2CH, 0x00000700U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0xB51EB851U), change_endian_long(0xEB851EB8U),
                 change_endian_long(0x51EB851EU), change_endian_long(0xB851EB85U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x1EB851EBU), change_endian_long(0x851EB851U),
                 change_endian_long(0xEB851EB8U), change_endian_long(0x51EB851EU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0xB851EB85U), change_endian_long(0x1EB851EBU),
                 change_endian_long(0x851EB851U), change_endian_long(0xEB851EB8U));
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x51EB851EU), change_endian_long(0xB851EB85U),
                 change_endian_long(0x1EB851EBU), change_endian_long(0x851EB851U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0xEB851EB8U), change_endian_long(0x51EB851EU),
                 change_endian_long(0xB851EB85U), change_endian_long(0x1EB851EBU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x851EB851U), change_endian_long(0xEB851EB8U),
                 change_endian_long(0x51EB851EU), change_endian_long(0xB851EB85U));
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x1EB851EBU), change_endian_long(0x851EB851U),
                 change_endian_long(0xEB851EB8U), change_endian_long(0x51EB851EU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0xB851EB85U), change_endian_long(0x1EB851EBU),
                 change_endian_long(0x851EB851U), change_endian_long(0xEB851B5CU));
        WR1_PROG(REG_1400H, 0x00c20021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x1010000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x7cf4a2ffU, 0xc8c135f6U, 0x294eadc0U, 0x530ebfc3U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0x9d9de42aU, 0x4b34b244U, 0x64dc8460U, 0xdd2755b5U);
            continue;
        }
        else
        {
            HW_SCE_p_func101(0x1f1cd4c2U, 0xea666571U, 0x2b6d5465U, 0x3d803253U);
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x86494c70U, 0x16bbfaecU, 0x0503ed95U, 0x51cfa157U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000320U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x1010000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0x6dc40b98U, 0xa8f70538U, 0x82a1e90aU, 0x181d8e67U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_1018H, 0x00000320U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x1010000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                HW_SCE_p_func101(0x17cdc175U, 0xc957a6b9U, 0x02430aa5U, 0xe4cd1469U);
            }
            else
            {
                HW_SCE_p_func101(0x02faddceU, 0xdb10d303U, 0x6447a82cU, 0x353d3e6aU);
            }

            WR1_PROG(REG_1404H, 0x19c00000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H, change_endian_long(0x00000000U), change_endian_long(0x00000000U),
                     change_endian_long(0x00000000U), change_endian_long(0x10000000U));
            WR1_PROG(REG_1400H, 0x00c20011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00c00071U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000a40U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1010000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0xb5864b99U, 0x8c900589U, 0x56e364cdU, 0x4955a484U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func101(0x34d89425U, 0xac20d505U, 0x015a1170U, 0x2c568eb9U);
                continue;
            }
            else
            {
                HW_SCE_p_func101(0xf2384b7cU, 0x8c74fb80U, 0x7e38ba4dU, 0xe9698ca5U);
            }
        }
        else
        {
            HW_SCE_p_func101(0x2e3d789cU, 0xa3d19831U, 0xb7c10e39U, 0x724accc4U);
        }

        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1600H, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            WR1_PROG(REG_1600H, 0x01003906U);
            WR1_PROG(REG_1600H, 0x00002cc0U);
            WR1_PROG(REG_1600H, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x14280000U);
            WR1_PROG(REG_1400H, 0x00c00209U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1404H, 0x15b00000U);
            WR1_PROG(REG_1400H, 0x00c0007dU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00c90005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_101CH, 0x00000630U);

            WR1_PROG(REG_1004H, 0x10100010U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x10100004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19c00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
            WR1_PROG(REG_1400H, 0x00c0007dU);
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

            WR1_PROG(REG_1004H, 0x1010000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0x0d6acb81U, 0x708912baU, 0xe7d0d446U, 0x09dc2b37U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                HW_SCE_p_func101(0x73d52177U, 0x564bf594U, 0xe8a45aafU, 0x9c575d6bU);
                break;
            }
            else
            {
                HW_SCE_p_func101(0x31710e27U, 0xc2aa874dU, 0x7c7c7719U, 0x8a6bb4efU);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x90f3f784U, 0x4a26f340U, 0x5b380ff9U, 0x39db433dU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0x77a80bd0U, 0x5be6098bU, 0x5218a482U, 0xe759e424U);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18b80000U);
        WR1_PROG(REG_1400H, 0x00c00081U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000938U);
        WR1_PROG(REG_1020H, 0x00000428U);

        WR1_PROG(REG_1004H, 0x10100009U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000428U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        WR1_PROG(REG_1020H, 0x00000220U);

        WR1_PROG(REG_1004H, 0x1010000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x14280000U);
        WR1_PROG(REG_1400H, 0x00c00209U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x15b00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00010001U));
        WR1_PROG(REG_1400H, 0x00c0007dU);
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

        WR1_PROG(REG_1004H, 0x10100010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x10100004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0007dU);
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

        WR1_PROG(REG_1004H, 0x1010000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x823bb958U, 0x68838352U, 0x4d1b0636U, 0x04698aa0U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func101(0x7aa4185eU, 0xe8cb9430U, 0xc5ad0262U, 0xa1ec5e12U);
        }
        else
        {
            WR1_PROG(REG_1404H, 0x16300000U);
            WR1_PROG(REG_1400H, 0x00c00209U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func100(0x4d9b2e64U, 0x2d8e59caU, 0x5557284fU, 0x09472086U);
            WR1_PROG(REG_1404H, 0x17b80000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
            WR1_PROG(REG_1400H, 0x00c0007dU);
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

            WR1_PROG(REG_1004H, 0x10100010U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000428U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x10100000U);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1014H, 0x00000630U);
            WR1_PROG(REG_1018H, 0x00000a40U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1010000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x1010000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00210000U);

            HW_SCE_p_func100(0x28a496a0U, 0x76f269b1U, 0x45e2ac04U, 0xe84b06d9U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func101(0x130e72c8U, 0x5323ff19U, 0x3fbeac55U, 0x438e402eU);
                continue;
            }

            HW_SCE_p_func100(0x1c519343U, 0xc8cf235cU, 0xa7448911U, 0x66380efaU);

            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1600H, 0x00000003U);

            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80a0000aU);
            WR1_PROG(REG_1404H, 0x11a00000U);
            WR1_PROG(REG_1400H, 0x03430081U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1600H, 0x00000908U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1600H, 0x0000007cU);

            for (iLoop = 0U; iLoop < 32U; iLoop++)
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

            WR1_PROG(REG_1404H, 0x15b00000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x81a0000aU);
            WR1_PROG(REG_1400H, 0x00c90081U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x1010000cU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000938U);
                WR1_PROG(REG_1020H, 0x00000630U);

                WR1_PROG(REG_1004H, 0x10100009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1600H, 0x000033e0U);

                HW_SCE_p_func101(0x8fe9b0e2U, 0x945f08d5U, 0xf549c12aU, 0xc9a69a24U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x6a4eeb71U, 0xcef09fb3U, 0xb82eb9bbU, 0xcdaeb5caU);
            WR1_PROG(REG_1600H, 0x00000a52U);

            WR1_PROG(REG_1608H, 0x81010160U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = change_endian_long(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x10180000U);
                WR1_PROG(REG_1400H, 0x00c00209U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1600H, 0x00000884U);
                WR1_PROG(REG_1600H, 0x0000b4a0U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1600H, 0x0000b4c0U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1600H, 0x000008e7U);

                WR1_PROG(REG_1404H, 0x11a00000U);
                for (jLoop = 0U; jLoop < 32U; jLoop = jLoop + 4U)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    WR1_PROG(REG_1600H, 0x00007c07U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    HW_SCE_p_func100(0x85ad9cafU, 0xa20bdae1U, 0x343056ebU, 0x299624f0U);
                    HW_SCE_p_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

                    WR1_PROG(REG_1400H, 0x00c20011U);
                    WAIT_STS(REG_1404H, 30, 0);
                    WR1_PROG(REG_143CH, 0x00001800U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    HW_SCE_p_func101(0xf5b2fe07U, 0x969f9ce2U, 0x552a2892U, 0xea96ac75U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func100(0x240f37acU, 0xb0d742baU, 0x2e98b316U, 0xeb121236U);
                WR1_PROG(REG_1404H, 0x19c00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000004U));
                WR1_PROG(REG_1400H, 0x00c0007dU);
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

                WR1_PROG(REG_1004H, 0x1010000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1010H, 0x00000018U);
                WR1_PROG(REG_101CH, 0x00000838U);

                WR1_PROG(REG_1004H, 0x10100010U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000a40U);

                WR1_PROG(REG_1004H, 0x10100004U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17b80000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
                WR1_PROG(REG_1400H, 0x00c0007dU);
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

                WR1_PROG(REG_1004H, 0x10100009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1010H, 0x00000018U);
                WR1_PROG(REG_101CH, 0x00000428U);

                WR1_PROG(REG_1004H, 0x10100010U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_1018H, 0x00000630U);
                WR1_PROG(REG_101CH, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x10100000U);
                WR1_PROG(REG_1408H, 0x00020000U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x19c00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
                WR1_PROG(REG_1400H, 0x00c0007dU);
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

                WR1_PROG(REG_1004H, 0x1010000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_143CH, 0x00210000U);

                WR1_PROG(REG_1014H, 0x00000a40U);
                WR1_PROG(REG_1018H, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000220U);

                WR1_PROG(REG_1004H, 0x1010000aU);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_143CH, 0x00210000U);

                HW_SCE_p_func100(0x3be79b2aU, 0x8ab6b67aU, 0x87d10174U, 0xfd2f5203U);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    HW_SCE_p_func101(0xbdc417b9U, 0x82258c37U, 0xd5f47e92U, 0x493cb892U);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    HW_SCE_p_func100(0xa87f60d5U, 0x88114914U, 0xf275d9a5U, 0x9b7bab55U);
                    WR1_PROG(REG_1608H, 0x81010120U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = change_endian_long(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19c00000U);
                        WR1_PROG(REG_1608H, 0x81a0000aU);
                        WR1_PROG(REG_1400H, 0x00c90081U);
                        WAIT_STS(REG_1404H, 30, 0);
                        WR1_PROG(REG_143CH, 0x00001800U);

                        WR1_PROG(REG_1014H, 0x00000838U);
                        WR1_PROG(REG_1018H, 0x00000a40U);
                        WR1_PROG(REG_1020H, 0x00000220U);

                        WR1_PROG(REG_1004H, 0x1010000aU);
                        WR1_PROG(REG_1000H, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        WR1_PROG(REG_1014H, 0x00000a40U);
                        WR1_PROG(REG_1018H, 0x00000838U);
                        WR1_PROG(REG_1020H, 0x00000220U);

                        WR1_PROG(REG_1004H, 0x1010000aU);
                        WR1_PROG(REG_1000H, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        HW_SCE_p_func100(0x6d8e558dU, 0x84a48605U, 0x2ff6bf63U, 0xfc2e5712U);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            HW_SCE_p_func101(0x3c1315c9U, 0x14687ac6U, 0x8ea42219U, 0x3ae14747U);
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18380000U);
                            WR1_PROG(REG_1400H, 0x00c00209U);
                            WAIT_STS(REG_1404H, 30, 0);
                            WR1_PROG(REG_143CH, 0x00001800U);

                            HW_SCE_p_func100(0x1860d8abU, 0x5b139f80U, 0x522a6591U, 0x349c00ffU);
                            WR1_PROG(REG_1404H, 0x19c00000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31, 1);
                            WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
                            WR1_PROG(REG_1400H, 0x00c0007dU);
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

                            WR1_PROG(REG_1004H, 0x10100000U);
                            WR1_PROG(REG_1408H, 0x00020000U);
                            WR1_PROG(REG_1000H, 0x00010201U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            WR1_PROG(REG_1014H, 0x00000220U);
                            WR1_PROG(REG_1018H, 0x00000938U);
                            WR1_PROG(REG_1020H, 0x00000838U);

                            WR1_PROG(REG_1004H, 0x10100009U);
                            WR1_PROG(REG_1000H, 0x00010001U);
                            WAIT_STS(REG_1000H, 0, 0);

                            HW_SCE_p_func101(0xd9432e9eU, 0xee0f477dU, 0xa1d30e5cU, 0x896aa35fU);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);

                    HW_SCE_p_func100(0x9ab65ca9U, 0x40514c93U, 0xc8b34b83U, 0xffe918beU);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        HW_SCE_p_func101(0x382f7f48U, 0xd1c9f3b0U, 0xa2aac8ceU, 0x923d24eeU);
                        break;
                    }
                    else
                    {
                        HW_SCE_p_func101(0xb41ddb46U, 0xc759e198U, 0x514d0c68U, 0x38e5fd50U);
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            HW_SCE_p_func100(0x851e2b38U, 0xa95af6f4U, 0x06381113U, 0x1d0c9851U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                WR1_PROG(REG_1600H, 0x38008a20U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);

                HW_SCE_p_func100(0x7936411dU, 0x5b610074U, 0x95967de0U, 0xc8438974U);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    HW_SCE_p_func101(0x9a71de9dU, 0x605f1a3cU, 0xcc9164e5U, 0x1de1be1aU);
                    break;
                }
                else
                {
                    WR1_PROG(REG_1014H, 0x00000428U);
                    WR1_PROG(REG_1018H, 0x00000938U);
                    WR1_PROG(REG_1020H, 0x00000320U);

                    WR1_PROG(REG_1004H, 0x10100009U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    HW_SCE_p_func101(0x866cc109U, 0x36258928U, 0x8c34b6f0U, 0xeda817ccU);
                }
            }
            else
            {
                HW_SCE_p_func101(0x185769fcU, 0x3653f2f0U, 0xc6b2d269U, 0x4b2580a0U);
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0x9373ffc9U, 0x0ce0599dU, 0x465d1867U, 0x2b29860dU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xf9af3299U, 0x4442da4bU, 0x90b37926U, 0x677f6442U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1400H, 0x00c00081U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000838U);

    WR1_PROG(REG_1004H, 0x10100009U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000320U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x000007b8U);

    WR1_PROG(REG_1004H, 0x10100009U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    HW_SCE_p_func100(0x0701d78bU, 0xa92cf595U, 0xaef5ecf5U, 0xda53df33U);
    HW_SCE_p_func103();
    HW_SCE_p_func100(0x690e38f2U, 0xce5efff9U, 0x9405dd96U, 0x609bbed1U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x9a6430a3U));

    OFS_ADR = 356;

    WR1_PROG(REG_1404H, 0x17380000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00002b01U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xa20459c4U, 0xc5fdc5dbU, 0x38e6d2a5U, 0xc7769259U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c0007dU);
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

    WR1_PROG(REG_1004H, 0x1010000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000630U);

    WR1_PROG(REG_1004H, 0x1010000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000002bU));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x796a73d9U, 0xb02f620fU, 0x1f2975e2U, 0x3d2c21bdU);
    HW_SCE_p_func052();

    WR1_PROG(REG_1404H, 0x15200000U);
    WR1_PROG(REG_1400H, 0x00c00091U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x9a6430a3U));

    OFS_ADR = 356;

    WR1_PROG(REG_1404H, 0x17380000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00002b01U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xf8a8e4c1U, 0xbccf95d2U, 0xc3d9ebbaU, 0x244f7bf2U);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1014H, 0x000007b8U);
    WR1_PROG(REG_1018H, 0x00000838U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x10100007U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00002b01U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x75d3fc68U, 0xcd99fa69U, 0x20e71db4U, 0xdbd7e2d5U);
    HW_SCE_p_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c000fdU);
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

    WR1_PROG(REG_1004H, 0x2020000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    WR1_PROG(REG_1014H, 0x00000a40U);
    WR1_PROG(REG_1018H, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x2020000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    HW_SCE_p_func100(0xe7abe052U, 0x46b9314dU, 0xe420ae5aU, 0x8dac1e89U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x304a5765U, 0xd523ae91U, 0x60cbb342U, 0x15552e42U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x9a6430a3U));

    OFS_ADR = 356;

    WR1_PROG(REG_1404H, 0x13280000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00002b02U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x3b462bd0U, 0xd31d5e31U, 0xaddc7b7bU, 0x8ff0ad5aU);
    HW_SCE_p_func017(OFS_ADR);

    WR1_PROG(REG_1014H, 0x000003a8U);
    WR1_PROG(REG_1018H, 0x00000428U);
    WR1_PROG(REG_1020H, 0x00000630U);

    WR1_PROG(REG_1004H, 0x10100007U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x9a6430a3U));

    OFS_ADR = 356;

    WR1_PROG(REG_1404H, 0x15300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00002b02U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x1566d69dU, 0xbd05d167U, 0xa5e079fcU, 0xe0685264U);
    HW_SCE_p_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1400H, 0x00c00011U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c0007dU);
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

    WR1_PROG(REG_1004H, 0x1010000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x000003a8U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x000001a0U);

    WR1_PROG(REG_1004H, 0x1010000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x000001a0U);
    WR1_PROG(REG_1018H, 0x00000220U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x10100007U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1010H, 0x00000018U);
    WR1_PROG(REG_101CH, 0x00000630U);

    WR1_PROG(REG_1004H, 0x20200010U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000838U);
    WR1_PROG(REG_101CH, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x20200002U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x20200003U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000220U);
    WR1_PROG(REG_101CH, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000220U);

    WR1_PROG(REG_1004H, 0x20200002U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x15300000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00010001U));
    WR1_PROG(REG_1400H, 0x00c000fdU);
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
    WR1_PROG(REG_1420H, change_endian_long(0x00002b02U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x165b4175U, 0xad947b85U, 0x23087797U, 0xa8a765e4U);
    HW_SCE_p_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
    WR1_PROG(REG_1400H, 0x00c000fdU);
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

    WR1_PROG(REG_1004H, 0x2020000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    WR1_PROG(REG_1014H, 0x00000a40U);
    WR1_PROG(REG_1018H, 0x00000630U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x2020000aU);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_143CH, 0x00210000U);

    HW_SCE_p_func100(0xb7699963U, 0xe0e7098aU, 0x85aa60c3U, 0x30732140U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x872c2b2cU, 0xdec3983aU, 0xfe1a8217U, 0x71350bc8U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1400H, 0x00c00101U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1014H, 0x00000838U);
    WR1_PROG(REG_1018H, 0x00000a40U);
    WR1_PROG(REG_1020H, 0x00000428U);

    WR1_PROG(REG_1004H, 0x20200009U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x9a6430a3U));

    OFS_ADR = 356;

    WR1_PROG(REG_1404H, 0x15300000U);

    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00002b03U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0x519b1ae3U, 0x0bd5d87dU, 0x817cd949U, 0x107cf760U);
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

    HW_SCE_p_func100(0x60135455U, 0xdee6c9eeU, 0xf19ea70dU, 0x44646099U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func100(0xd43b7858U, 0xa2a9fe5dU, 0x4a21ac40U, 0xf45df7c1U);
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
        WR1_PROG(REG_1420H, change_endian_long(0x0000012bU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x04b1d795U, 0x0ea1e69fU, 0x98b8b0ceU, 0xfc098d6bU);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x0000000dU);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000012bU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x7d3c4deeU, 0x7dd3e34bU, 0x2ab40c41U, 0x9f209044U);
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
        WR1_PROG(REG_1600H, 0x00000040U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x15300000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x6ed09373U, 0x9849c99cU, 0x4ff48a39U, 0x4c79378fU);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0x4ccbb222U, 0xeb548486U, 0xb15f5498U, 0x7e7ed0e0U);
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
        WR1_PROG(REG_1600H, 0x00000040U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x13280000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x6210df20U, 0xe265fc65U, 0xc280192eU, 0xa7f9fa3cU);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[65 + iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0x8464ac18U, 0xd86f4afeU, 0xd1efd7d5U, 0xc54d5ec6U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0x3c97d453U, 0x0a92e30bU, 0x52e9e569U, 0x25ce53a0U);
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
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[129]);

        HW_SCE_p_func100(0x73e66095U, 0x5894eeb7U, 0xb1fa74c9U, 0xf46b49c5U);
        WR1_PROG(REG_1608H, 0x81010000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        HW_SCE_p_func101(0xae07c9afU, 0xec012caeU, 0x64fa0c03U, 0x6f432602U);
    }
    else
    {
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
        WR1_PROG(REG_1600H, 0x00000040U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x15300000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x836aaa2eU, 0xb998dd8bU, 0x6737fa66U, 0xcac76c62U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKey[iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0x125f382bU, 0xf8b73cfeU, 0x90d53facU, 0xf6f6eae0U);
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
        WR1_PROG(REG_1600H, 0x00000040U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1404H, 0x13280000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x934f12a8U, 0x0bad62ffU, 0x01eae222U, 0x0b326b2bU);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WR1_PROG(REG_1400H, 0x00830011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKey[64 + iLoop]);

            WR1_PROG(REG_1600H, 0x00002485U);

            HW_SCE_p_func101(0xbeac8f95U, 0xfd4a2c49U, 0x98169cfeU, 0x0f357f95U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xccba3638U, 0x0335795fU, 0x3d0bc21fU, 0x33ddd4e7U);
    }

    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1600H, 0x000008e7U);

    WR1_PROG(REG_1404H, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0xfae9380bU, 0x74f02f26U, 0xd5f12a49U, 0xadd39eceU);
        WR1_PROG(REG_1A24H, 0x08000105U);
        WR1_PROG(REG_1400H, 0x00830011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKey[iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        HW_SCE_p_func101(0x8bf17443U, 0xfcdeb6f8U, 0x2ea85cfdU, 0xdfeecb49U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func100(0xdc1ec539U, 0xe644de7aU, 0xfcd7f6e2U, 0x82495192U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WR1_PROG(REG_1608H, 0x81010280U);
    WR1_PROG(REG_1400H, 0x00890005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKey[64]);

    HW_SCE_p_func102(0xf59f8164U, 0x1e6b4ffeU, 0x1b4b978cU, 0xe6221946U);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return FSP_SUCCESS;
}
