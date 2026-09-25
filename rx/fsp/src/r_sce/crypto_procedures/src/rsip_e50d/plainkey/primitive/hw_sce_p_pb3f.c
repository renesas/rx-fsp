/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes128XtsEncryptFinalSub (const uint32_t InData_TextBitLen[],
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

    HW_SCE_p_func100(0x73e3e629U, 0x2943399dU, 0xb84d865bU, 0x1c6d6b73U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x730d3081U, 0xf0aede55U, 0xe256265dU, 0xc684edc6U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        HW_SCE_p_func100(0xca62302dU, 0x14524553U, 0xf2649c97U, 0x8f29af8dU);
        WR1_PROG(REG_1608H, 0x810103c0U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = change_endian_long(S_RAM[0]);

        HW_SCE_p_func100(0x324c65f8U, 0x7ed8fa27U, 0xf8bc5362U, 0x3d44978aU);

        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_182CH, 0x00000020U);
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

        HW_SCE_p_func100(0xfa00282cU, 0x460b2c1aU, 0x28fcae08U, 0xc4941422U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_182CH, 0x00000020U);
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

            HW_SCE_p_func100(0x5843a77dU, 0x2bc04711U, 0x03481c88U, 0xb9021d49U);
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
                HW_SCE_p_func101(0xe9c803c5U, 0x725e6950U, 0x0d658c93U, 0xbe0d2c4dU);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x38000fdeU);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x0709a6eeU, 0xc1bc404cU, 0x038eda51U, 0x54f29ab5U);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x00000020U);
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
                HW_SCE_p_func101(0x0bd8eea9U, 0x2159ccfbU, 0x86a85b87U, 0x75ccaeb8U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func100(0x233be00aU, 0xd63eee27U, 0xbd1e0889U, 0x54c6a698U);
            WR1_PROG(REG_1600H, 0x38000d29U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

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

            HW_SCE_p_func101(0xfa29e3e6U, 0x01b529caU, 0x107064d0U, 0x1e0ac872U);
        }

        HW_SCE_p_func102(0xfa7130e3U, 0x6c9ae169U, 0xff8d6865U, 0xab979e90U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_SUCCESS;
    }
}
