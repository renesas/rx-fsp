/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Rsa2048ModularExponentDecryptSub (const uint32_t InData_KeyMode[],
                                                   const uint32_t InData_KeyIndex[],
                                                   const uint32_t InData_Key[],
                                                   const uint32_t InData_Text[],
                                                   uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00570001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000e50U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    HW_SCE_p_func100(0xfddb8993U, 0x5a3e58c9U, 0x08f29385U, 0xa903844bU);
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
        WR1_PROG(REG_1420H, change_endian_long(0x00000057U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x63a86e49U, 0x52d4cb61U, 0xafa1d738U, 0x231889ddU);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x0000000dU);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000057U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x713cb291U, 0xbd2c5072U, 0x31373304U, 0x0917fd16U);
        HW_SCE_p_func044();

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1444H, 0x00007fc2U);
        WR1_PROG(REG_1A2CH, 0x40000f00U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);

        WR1_PROG(REG_1404H, 0x15300000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
            WR1_PROG(REG_1400H, 0x00c20021U);

            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000f00U);
        WR1_PROG(REG_1A24H, 0xf7008d07U);

        WR1_PROG(REG_1404H, 0x13280000U);
        for (iLoop = 64; iLoop < 128U; iLoop = iLoop + 8U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
            WR1_PROG(REG_1400H, 0x00c20021U);

            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[129]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0x49154e1aU, 0xe487c845U, 0x8a98a202U, 0xa9a0a45bU);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00007fc2U);
        WR1_PROG(REG_1A2CH, 0x40000f00U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        WR1_PROG(REG_1404H, 0x15300000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[iLoop + 4]);
            WR1_PROG(REG_1400H, 0x00c20021U);

            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000f00U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        WR1_PROG(REG_1404H, 0x13280000U);
        for (iLoop = 64; iLoop < 128U; iLoop = iLoop + 8U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[iLoop + 4]);
            WR1_PROG(REG_1400H, 0x00c20021U);

            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xcff52d9cU, 0x565dbc73U, 0x8296ac52U, 0x22a51573U);
    }

    HW_SCE_p_func100(0xde331e14U, 0x8ae36a8cU, 0x4630e56fU, 0x22b18dfeU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xd5a516fcU, 0xb0ea2125U, 0x2bf2622aU, 0xb2367ff6U);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_101CH, 0x00000630U);

        WR1_PROG(REG_1004H, 0x20200010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1444H, 0x00003fc2U);
        WR1_PROG(REG_1A2CH, 0x40000f00U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        WR1_PROG(REG_1404H, 0x11200000U);
        for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
            WR1_PROG(REG_1400H, 0x00c20021U);

            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        WR1_PROG(REG_1400H, 0x00030005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x03430005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x3800dbe0U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

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

        WR1_PROG(REG_1014H, 0x00000a40U);
        WR1_PROG(REG_1018H, 0x00000220U);
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x2020000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x19400000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
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
        WR1_PROG(REG_1020H, 0x00000838U);

        WR1_PROG(REG_1004H, 0x2020000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000838U);
        WR1_PROG(REG_1018H, 0x00000220U);
        WR1_PROG(REG_1020H, 0x00000a40U);

        WR1_PROG(REG_1004H, 0x2020000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x14b30b3bU, 0x478ce546U, 0x7cd9105eU, 0xab79fce6U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0xf1e42b61U, 0x0ed8f354U, 0x6aa082fcU, 0xd80950caU);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            HW_SCE_p_func100(0x4059536cU, 0x83319f1cU, 0x8f07f02eU, 0x9a65c4b7U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000428U);
            WR1_PROG(REG_101CH, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);

            WR1_PROG(REG_1004H, 0x20200000U);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1600H, 0x00000040U);

            WR1_PROG(REG_1404H, 0x17380000U);

            for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 8U)
            {
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1600H, 0x34202be0U);
                WR1_PROG(REG_1600H, 0x2000d3c0U);

                WR1_PROG(REG_1600H, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func100(0xfafab8c1U, 0x354282baU, 0x50c3548aU, 0x3728105fU);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                WR1_PROG(REG_1400H, 0x00830021U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);

                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1600H, 0x00000008U);

                HW_SCE_p_func101(0xa7e29f22U, 0x50d0998fU, 0xace09beaU, 0xa82ba3fbU);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x5de9716dU, 0x5d19c168U, 0xac797943U, 0x783ea32aU);
            WR1_PROG(REG_1408H, 0x00020000U);

            HW_SCE_p_func102(0xad1f703eU, 0xe5f62c2eU, 0x29038d48U, 0x601ce8deU);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
