/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_GenerateOemKeyIndexSub (const uint32_t InData_KeyType[],
                                         const uint32_t InData_Cmd[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    uint32_t OFS_ADR = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x006e0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x800103e0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0xcbc4a7c6U, 0x60168d00U, 0x67f5ce13U, 0x1042f8b8U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func049(InData_Cmd);

        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010020U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(InData_SharedKeyIndex[0]));
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x0000094aU);

        WR1_PROG(REG_1600H, 0x000037e4U);

        HW_SCE_p_func083();

        WR1_PROG(REG_1600H, 0x3000a880U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1600H, 0x00010020U);
        WR1_PROG(REG_1600H, 0x3000a880U);
        WR1_PROG(REG_1600H, 0x00000032U);
        WR1_PROG(REG_1600H, 0x00040020U);
        WR1_PROG(REG_1600H, 0x0000b480U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1600H, 0x00000080U);

        WR1_PROG(REG_1600H, 0x3420a880U);
        WR1_PROG(REG_1600H, 0x00000033U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        WR1_PROG(REG_1600H, 0x3420a880U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        WR1_PROG(REG_1600H, 0x3420a820U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        HW_SCE_p_func100(0x1fb8609eU, 0x125b0761U, 0xdae469d2U, 0xe5bb86cbU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x73cf8ddaU, 0xaba77360U, 0x3658ccc7U, 0x038f7202U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000349fU);

            OFS_ADR = InData_SharedKeyIndex[0] << 3;

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x0000006eU));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x8abd685cU, 0x88c546c3U, 0xcd77ce04U, 0x90c0a938U);
            HW_SCE_p_func058(InData_SessionKey, OFS_ADR);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x80010380U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x0000006eU));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xfbc73350U, 0x6cd354e5U, 0xbf603c27U, 0xbcf26abfU);
            HW_SCE_p_func057(InData_IV, InData_InstData, OutData_KeyIndex);

            HW_SCE_p_func100(0xe2fc0047U, 0x1eafeb18U, 0x20f4beb5U, 0x9f3699fcU);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func102(0x6d02eeddU, 0x5a4e0a8fU, 0x014d4eceU, 0x1e4a5ed3U);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_ERR_CRYPTO_SCE_FAIL;
            }
            else
            {
                HW_SCE_p_func100(0xa4a370feU, 0xc40dfa8fU, 0x036aebbdU, 0x89aeae80U);
                WR1_PROG(REG_1608H, 0x81010000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                HW_SCE_p_func102(0x54c1c6bbU, 0x77a1d077U, 0x60ed36dcU, 0x022ca355U);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_SUCCESS;
            }
        }
    }
    else
    {
        HW_SCE_p_func049(InData_Cmd);

        WR1_PROG(REG_1600H, 0x000037e4U);
        HW_SCE_p_func083();

        WR1_PROG(REG_1600H, 0x3000a880U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1600H, 0x00010020U);
        WR1_PROG(REG_1600H, 0x3000a880U);
        WR1_PROG(REG_1600H, 0x00000032U);
        WR1_PROG(REG_1600H, 0x00040020U);
        WR1_PROG(REG_1600H, 0x0000b480U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1600H, 0x00000080U);

        WR1_PROG(REG_1600H, 0x3420a880U);
        WR1_PROG(REG_1600H, 0x00000033U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        WR1_PROG(REG_1600H, 0x3420a880U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        HW_SCE_p_func100(0xcc7eb844U, 0x911888eeU, 0x867bf95aU, 0x9a22cb2dU);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x753331f1U, 0x96d2d114U, 0x0371f2f3U, 0xcdb57a9aU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000349fU);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x80010380U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x0000006eU));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x1dab5a82U, 0xa6c3ddd6U, 0xc5a5dbb2U, 0x2ddcd124U);
            HW_SCE_p_func093(InData_InstData, OutData_KeyIndex);

            HW_SCE_p_func100(0xe3f22e6dU, 0x5b314793U, 0xcbc584bbU, 0x6ca6b375U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

            HW_SCE_p_func102(0x6490a58fU, 0xc29a523dU, 0x103b7d44U, 0x33e336cdU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
