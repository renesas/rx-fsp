/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Ecc256ScalarMultiplicationSub (const uint32_t InData_CurveType[],
                                                const uint32_t InData_Cmd[],
                                                const uint32_t InData_KeyMode[],
                                                const uint32_t InData_KeyIndex[],
                                                const uint32_t InData_Key[],
                                                const uint32_t InData_PubKey[],
                                                const uint32_t InData_DomainParam[],
                                                uint32_t       OutData_R[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x009a0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    WR1_PROG(REG_1444H, 0x00000fc7U);
    WR1_PROG(REG_1608H, 0x8090001eU);
    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_PubKey[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 2U; iLoop++)
    {
        WR1_PROG(REG_1600H, 0x00000bffU);

        WR1_PROG(REG_1600H, 0x30003380U);
        WR1_PROG(REG_1600H, 0x00070020U);
        WR1_PROG(REG_1600H, 0x0000d3e0U);
        WR1_PROG(REG_1600H, 0x00030040U);
        WR1_PROG(REG_1600H, 0x0000381eU);
        WR1_PROG(REG_1600H, 0x38000c00U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1600H, 0x00050040U);
        WR1_PROG(REG_1600H, 0x0000381eU);
        WR1_PROG(REG_1600H, 0x000037beU);
        WR1_PROG(REG_1600H, 0x0000a7a0U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x0000383dU);
        WR1_PROG(REG_1600H, 0x38001001U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1600H, 0x00000080U);

        WR1_PROG(REG_1600H, 0x38000fffU);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        WR1_PROG(REG_1600H, 0x0000a7c0U);
        WR1_PROG(REG_1600H, 0x00000020U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x30000f5aU);
    WR1_PROG(REG_1600H, 0x00030020U);
    WR1_PROG(REG_1600H, 0x0000d3e1U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1600H, 0x38000f9cU);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WR1_PROG(REG_1600H, 0x38008be0U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0xbb74ca57U, 0xd008746dU, 0x18554bc4U, 0xf625261fU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x58c590c0U, 0x4191d9a9U, 0x0f964a4aU, 0x1e996d34U);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyMode[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x38000c00U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0x06258abeU, 0xa8f22ac8U, 0xe1425885U, 0x2d055510U);
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
            WR1_PROG(REG_1420H, change_endian_long(0x0000009aU));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xb901f9d0U, 0x7853b8a9U, 0x48349a15U, 0x8a70c47eU);
            HW_SCE_p_func043();

            HW_SCE_p_func074();

            WR1_PROG(REG_1600H, 0x000034feU);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x0000009aU));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xfec1896bU, 0xd2b32d95U, 0x6296b46bU, 0xf2fa39aeU);
            HW_SCE_p_func044();

            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xf7009d07U);

            for (iLoop = 0U; iLoop < 8U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x13200000U);
            WR1_PROG(REG_1400H, 0x00c20021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            WR1_PROG(REG_1400H, 0x00820011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0x3a26f581U, 0xe30a914eU, 0x22242eaaU, 0x71fedd26U);
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[4]);

            WR1_PROG(REG_1404H, 0x13200000U);
            WR1_PROG(REG_1400H, 0x00c20021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0x8012a8b8U, 0x77e239c1U, 0x555faf0fU, 0x78fa1eb1U);
        }

        HW_SCE_p_func100(0xa4f2f894U, 0x6594490cU, 0x765a2a96U, 0x0b723503U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x27e21153U, 0x2394655bU, 0xd4a07215U, 0xabebf336U);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
        }
        else
        {
            HW_SCE_p_func100(0xa0eaa5e3U, 0x9965af9aU, 0x1a098b83U, 0xac7476a7U);
            HW_SCE_p_func070(InData_DomainParam);

            WR1_PROG(REG_1010H, 0x00000020U);
            WR1_PROG(REG_101CH, 0x000000c0U);

            WR1_PROG(REG_1004H, 0x04040010U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_101CH, 0x00000070U);

            WR1_PROG(REG_1004H, 0x04040010U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1608H, 0x8190001eU);

            WR1_PROG(REG_1404H, 0x10f00000U);
            WR1_PROG(REG_1400H, 0x00c90021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1404H, 0x11400000U);
            WR1_PROG(REG_1400H, 0x00c90021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func008();

            HW_SCE_p_func100(0xe1fae198U, 0xeca4052bU, 0x0fdb946cU, 0x20988d58U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func102(0x92a5b41eU, 0x4573fe09U, 0xc0ac349dU, 0x8a497328U);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_ERR_CRYPTO_SCE_FAIL;
            }
            else
            {
                WR1_PROG(REG_1404H, 0x10f00000U);
                WR1_PROG(REG_1400H, 0x00c00021U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1014H, 0x00000200U);
                WR1_PROG(REG_1018H, 0x00000110U);
                WR1_PROG(REG_1020H, 0x00000228U);

                WR1_PROG(REG_1004H, 0x04040009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x00000110U);
                WR1_PROG(REG_1020H, 0x00000200U);

                WR1_PROG(REG_1004H, 0x04040009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x0000009aU));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xabe8e57aU, 0xa40fc60bU, 0xd18ff4c5U, 0x46516528U);
                HW_SCE_p_func088();

                HW_SCE_p_func100(0x841a07d1U, 0x8763159dU, 0x094ac33fU, 0x40e3cbe8U);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    HW_SCE_p_func102(0x6e8f4895U, 0x72d1f902U, 0xb22e5b88U, 0x596ecdeeU);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return FSP_ERR_CRYPTO_SCE_FAIL;
                }
                else
                {
                    HW_SCE_p_func100(0x7ba70534U, 0x3d89e6a6U, 0x95922109U, 0x4d67df03U);
                    WR1_PROG(REG_1404H, 0x12800000U);
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    WR1_PROG(REG_1400H, 0x00830021U);
                    WAIT_STS(REG_1404H, 30, 0);
                    WR1_PROG(REG_143CH, 0x00001800U);

                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_R[0]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_R[4]);

                    HW_SCE_p_func100(0x26d018e6U, 0xf787d1fcU, 0xed1f41a7U, 0x64005925U);
                    WR1_PROG(REG_1404H, 0x12d00000U);
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    WR1_PROG(REG_1400H, 0x00830021U);
                    WAIT_STS(REG_1404H, 30, 0);
                    WR1_PROG(REG_143CH, 0x00001800U);

                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_R[8]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_R[12]);

                    HW_SCE_p_func102(0xd76b54a8U, 0xc29f70e7U, 0xd3e744b7U, 0xf72c0537U);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return FSP_SUCCESS;
                }
            }
        }
    }
}
