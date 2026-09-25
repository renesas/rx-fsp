/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Sha2HmacResumeSub (const uint32_t InData_KeyMode[],
                                    const uint32_t InData_KeyIndex[],
                                    const uint32_t InData_Key[],
                                    const uint32_t KEY_SIZE,
                                    const uint32_t InData_HashType[],
                                    const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00750001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xae55986fU, 0x44ea0848U, 0x9152e26fU, 0x23a29df6U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x3b126e41U, 0x32c214deU, 0x3b76d875U, 0x26bbce12U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        HW_SCE_p_func100(0xe21222f6U, 0xf53773e4U, 0xa8c43e4cU, 0x206cfb72U);
        WR1_PROG(REG_1600H, 0x3420a880U);
        WR1_PROG(REG_1600H, 0x00000007U);
        WR1_PROG(REG_1600H, 0x2000b480U);
        WR1_PROG(REG_1600H, 0x00000006U);

        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000001aU);

            WR1_PROG(REG_2004H, 0x00001040U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000008U);

            HW_SCE_p_func101(0xecffd232U, 0x33d2e5c0U, 0xd68f86e7U, 0x8fb0e703U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000001bU);

            WR1_PROG(REG_2004H, 0x00001050U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000008U);

            HW_SCE_p_func101(0xa6e8dbf5U, 0x3adf228aU, 0xcb3e0084U, 0x116a7dffU);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000002aU);

            WR1_PROG(REG_2004H, 0x00001080U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            HW_SCE_p_func101(0xebe43dd4U, 0xb618c7ecU, 0x86fb665aU, 0xa81dc53aU);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x0000002bU);

            WR1_PROG(REG_2004H, 0x00001090U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            HW_SCE_p_func101(0xbb482951U, 0x8bfd1da1U, 0xf9c6729bU, 0xc7423deaU);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x00000028U);

            WR1_PROG(REG_2004H, 0x000010a0U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x0000000cU);

            HW_SCE_p_func101(0xff6d4613U, 0x5cd6ebe3U, 0x22a94638U, 0x36771838U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1600H, 0x00000029U);

            WR1_PROG(REG_2004H, 0x000010b0U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            HW_SCE_p_func101(0x4141931fU, 0x2401db9bU, 0xd62da8e3U, 0xfc8cc9d8U);
        }

        WR1_PROG(REG_2008H, 0x00000003U);

        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyMode[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x38000c00U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0xce97d5caU, 0x00f412a7U, 0x37caa2a1U, 0x0e69fbbeU);
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
            WR1_PROG(REG_1420H, change_endian_long(0x00007502U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x9640b738U, 0x5edf94d6U, 0x78d1867bU, 0xd686ac66U);
            HW_SCE_p_func043();

            WR1_PROG(REG_1600H, 0x000034e5U);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00007502U));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x321a126cU, 0x5a5e7c10U, 0xb17e0febU, 0xaf5d8c4aU);
            HW_SCE_p_func044();

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000054U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

            WR1_PROG(REG_1600H, 0x000008e7U);

            for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; iLoop = iLoop + 4U)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xf7008d05U);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

                WR1_PROG(REG_1400H, 0x01420011U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1600H, 0x0000a4e0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                HW_SCE_p_func101(0x00c4ded4U, 0x8488e9f2U, 0xe12a0ffdU, 0x2d847ba4U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x380008e3U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            WR1_PROG(REG_1400H, 0x00820011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0xfac19ec0U, 0x49531b9aU, 0x0a7b0be6U, 0x193e8376U);
        }
        else
        {
            WR1_PROG(REG_1600H, 0x000008e7U);

            for (iLoop = 0U; iLoop < KEY_SIZE; iLoop = iLoop + 4U)
            {
                WR1_PROG(REG_1444H, 0x000003c4U);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_Key[iLoop]);

                WR1_PROG(REG_1600H, 0x0000a4e0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                HW_SCE_p_func101(0xfe6c3915U, 0xefe5fa7eU, 0xa42d021cU, 0x53601de2U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x380008e3U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xfee09788U, 0x959a9249U, 0xaedd2843U, 0xfd3fd61aU);
        }

        HW_SCE_p_func100(0xa5540331U, 0x052440a4U, 0x8e5eacbcU, 0xd2cc688dU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0xb15cd5f0U, 0x829f10fdU, 0x6dadc748U, 0x4a064f4bU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2014H, InData_State[18]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2010H, InData_State[19]);

            for (iLoop = 0U; iLoop < 18U; iLoop++)
            {
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_PROG(REG_2028H, InData_State[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x533c6e28U, 0x7e03a6a5U, 0x35541c6bU, 0xfc6fd539U);

            return FSP_SUCCESS;
        }
    }
}
