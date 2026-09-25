/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes256XtsEncryptFinalSub (const uint32_t InData_TextBitLen[],
                                           const uint32_t InData_Text[],
                                           uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000037c0U);
    WR1_PROG(REG_1600H, 0x00076bdeU);
    WR1_PROG(REG_1600H, 0x00026fdeU);

    WR1_PROG(REG_1600H, 0x00000bffU);

    WR1_PROG(REG_1600H, 0x38008c00U);
    WR1_PROG(REG_1600H, 0x0000007fU);
    WR1_PROG(REG_1600H, 0x00020020U);
    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1600H, 0x2000abc0U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0xfa68956cU, 0x3d4385d9U, 0x000e4c98U, 0x60071378U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x6fbf71acU, 0x3068be85U, 0x44911af6U, 0x561c9265U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        HW_SCE_p_func100(0xc38cc9c5U, 0x21092158U, 0x9c693732U, 0xaad98ed3U);
        WR1_PROG(REG_1608H, 0x810103c0U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = change_endian_long(S_RAM[0]);

        HW_SCE_p_func100(0xe9b6baf5U, 0x9e9a338cU, 0x2e0bbc45U, 0x050016c4U);

        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x40000020U);
        WR1_PROG(REG_1824H, 0x0d008906U);
        WR1_PROG(REG_1408H, 0x000c1000U);

        iLoop = 0U;
        if (S_RAM[0] >= 4)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[0]);
            for (iLoop = 4; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
        }

        HW_SCE_p_func214();

        WR1_PROG(REG_1600H, 0x38008c00U);
        WR1_PROG(REG_1600H, 0x0000007fU);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        HW_SCE_p_func100(0x23f3768eU, 0x8fef2607U, 0xb466622cU, 0xb8f476b7U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_182CH, 0x40000020U);
            WR1_PROG(REG_1824H, 0x0d008905U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            WR1_PROG(REG_1400H, 0x03410011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80840007U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_Text[iLoop + 4]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_Text[iLoop + 5]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_Text[iLoop + 6]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_Text[iLoop + 7]);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x00000004U);

            WR1_PROG(REG_1600H, 0x00003500U);
            WR1_PROG(REG_1600H, 0x00036908U);
            WR1_PROG(REG_1600H, 0x00008d00U);
            WR1_PROG(REG_1600H, 0x0000000cU);

            WR1_PROG(REG_1600H, 0x000024c8U);

            WR1_PROG(REG_1600H, 0x000024e8U);

            WR1_PROG(REG_1600H, 0x00003826U);

            WR1_PROG(REG_1600H, 0x00003847U);

            WR1_PROG(REG_1600H, 0x00003460U);
            WR1_PROG(REG_1600H, 0x00008c60U);
            WR1_PROG(REG_1600H, 0x0000001fU);

            WR1_PROG(REG_1600H, 0x0000b480U);
            WR1_PROG(REG_1600H, 0xffffffffU);
            WR1_PROG(REG_1600H, 0x00004403U);
            WR1_PROG(REG_1600H, 0x00007484U);

            WR1_PROG(REG_1600H, 0x00000c24U);

            WR1_PROG(REG_1600H, 0x00001484U);

            WR1_PROG(REG_1600H, 0x00000c44U);

            WR1_PROG(REG_1600H, 0x00001041U);

            WR1_PROG(REG_1600H, 0x00003c47U);

            WR1_PROG(REG_1600H, 0x000037e0U);
            WR1_PROG(REG_1600H, 0x00008fe0U);
            WR1_PROG(REG_1600H, 0x0000007fU);

            WR1_PROG(REG_1600H, 0x38008fe0U);
            WR1_PROG(REG_1600H, 0x0000001fU);
            WR1_PROG(REG_1600H, 0x1000a7e0U);
            WR1_PROG(REG_1600H, 0x00000020U);

            WR1_PROG(REG_1600H, 0x0000b7c0U);
            WR1_PROG(REG_1600H, 0x00000080U);
            WR1_PROG(REG_1600H, 0x00002bdfU);
            WR1_PROG(REG_1600H, 0x00056bdeU);
            WR1_PROG(REG_1600H, 0x0000353eU);

            HW_SCE_p_func100(0xe599d842U, 0xd444b5d4U, 0xb776a61fU, 0x64a9559dU);
            WR1_PROG(REG_1608H, 0x810103c0U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = change_endian_long(S_RAM[0]);

            for (jLoop = 0U; jLoop < S_RAM[0]; jLoop++)
            {
                WR1_PROG(REG_1600H, 0x000024c5U);
                WR1_PROG(REG_1600H, 0x000024e5U);

                WR1_PROG(REG_1600H, 0x00003ba6U);
                WR1_PROG(REG_1600H, 0x00003fa7U);

                WR1_PROG(REG_1600H, 0x000033c0U);
                HW_SCE_p_func101(0x5425e333U, 0x14af16f9U, 0x0ba6b9a3U, 0x8f61e405U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x38000fdeU);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            HW_SCE_p_func100(0x3f5b34fbU, 0x92b5fa06U, 0x8e04145bU, 0xf932e03aU);
            WR1_PROG(REG_182CH, 0x40000020U);
            WR1_PROG(REG_1824H, 0x0d008905U);
            WR1_PROG(REG_1608H, 0x81840007U);
            WR1_PROG(REG_1400H, 0x00490011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);

            WR1_PROG(REG_1600H, 0x000024c8U);

            WR1_PROG(REG_1600H, 0x00003826U);

            WR1_PROG(REG_1600H, 0x00000c24U);

            WR1_PROG(REG_1600H, 0x00003c26U);

            WR1_PROG(REG_1600H, 0x00000bffU);

            for (jLoop = 0U; jLoop < S_RAM[0]; jLoop++)
            {
                WR1_PROG(REG_1600H, 0x000024c5U);

                WR1_PROG(REG_1600H, 0x00003fe6U);

                WR1_PROG(REG_1600H, 0x00003120U);
                HW_SCE_p_func101(0xf7c806b8U, 0x6bfff30aU, 0xd70a0639U, 0x3cd1d0a3U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x38000d29U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x23eb8ee6U, 0x613af767U, 0xbf1beb4dU, 0x4647cdcbU);
            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x81840006U);
            WR1_PROG(REG_1408H, 0x00005012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 5]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 6]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 7]);

            HW_SCE_p_func101(0x4b6555f9U, 0x3631dcc6U, 0x5ec5c1eaU, 0x2679c52eU);
        }

        HW_SCE_p_func102(0xaf9b14caU, 0x0a1fb782U, 0xd86d6751U, 0x27699a47U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_SUCCESS;
    }
}
