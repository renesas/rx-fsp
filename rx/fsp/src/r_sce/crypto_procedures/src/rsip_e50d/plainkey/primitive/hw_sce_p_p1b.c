/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Ed25519ScalarMultiplicationSub (const uint32_t InData_KeyMode[],
                                                 const uint32_t InData_KeyIndex[],
                                                 const uint32_t InData_Key[],
                                                 const uint32_t InData_XYZ[],
                                                 const uint32_t InData_DomainParam[],
                                                 uint32_t       OutData_XYZ[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x001b0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000008c8U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x10680a9eU, 0x1a698a4eU, 0x4f16f31dU, 0x883e1522U);
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
        WR1_PROG(REG_1420H, change_endian_long(0x0000001bU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x95ca8c0bU, 0x9e9ca740U, 0x950849e7U, 0xd11cc7e8U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000027U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000001bU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x620ebec7U, 0x79057a5eU, 0x7e906a1bU, 0x8bf675edU);
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

        WR1_PROG(REG_1404H, 0x19b00000U);
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

        HW_SCE_p_func101(0xf5bd55a7U, 0x51af5c0cU, 0x4870893eU, 0x75d64a50U);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        for (iLoop = 0U; iLoop < 8U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x19b00000U);
        WR1_PROG(REG_1400H, 0x00c20021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0xc8a3a08eU, 0x8bc77a02U, 0x79b41a35U, 0x217ddb92U);
    }

    HW_SCE_p_func100(0x8689fef4U, 0x33478be8U, 0x71ce7974U, 0xa08ad6a8U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xc7c4d036U, 0x166575b3U, 0x30d48eccU, 0xae99aef3U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1004H, 0x00000000U);
        WR1_PROG(REG_1004H, 0x04040000U);

        HW_SCE_p_func100(0x136b9797U, 0x506f8f6dU, 0x6b8f7b54U, 0x92b80fa7U);
        HW_SCE_p_func406(InData_DomainParam);

        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WR1_PROG(REG_1404H, 0x14600000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_XYZ[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_XYZ[4]);
        WR1_PROG(REG_1400H, 0x00c20021U);

        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WR1_PROG(REG_1404H, 0x14b00000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_XYZ[8]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_XYZ[12]);
        WR1_PROG(REG_1400H, 0x00c20021U);

        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WR1_PROG(REG_1404H, 0x15000000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_XYZ[16]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_XYZ[20]);
        WR1_PROG(REG_1400H, 0x00c20021U);

        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1010H, 0x00000008U);

        WR1_PROG(REG_1404H, 0x16400000U);
        WR1_PROG(REG_1400H, 0x00c00021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x16900000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000026U));
        WR1_PROG(REG_1400H, 0x00c00015U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c2000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00020005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x16e00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000026U));
        WR1_PROG(REG_1400H, 0x00c00015U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c2000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00020005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x1b400000U);
        WR1_PROG(REG_1400H, 0x00c00021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x1b900000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000026U));
        WR1_PROG(REG_1400H, 0x00c00015U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c2000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00020005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x1be00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000026U));
        WR1_PROG(REG_1400H, 0x00c00015U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c2000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00020005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x19b00000U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x8088001fU);
        WR1_PROG(REG_1400H, 0x03430021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00000908U);
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x0000001fU);

        WR1_PROG(REG_1600H, 0x0000b660U);
        WR1_PROG(REG_1600H, 0x00000001U);

        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1600H, 0x00000100U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000001bU));
        WR1_PROG(REG_1458H, 0x00000000U);

        for (iLoop = 0U; iLoop < 256U; iLoop++)
        {
            HW_SCE_p_func405();

            HW_SCE_p_func403();

            HW_SCE_p_func101(0x23ba1f8eU, 0x25aa8481U, 0x6c47b712U, 0x3e3b05e8U);
            HW_SCE_p_func402();

            HW_SCE_p_func404();

            WR1_PROG(REG_1600H, 0x00002d00U);

            HW_SCE_p_func101(0xac35b185U, 0x0cc7e2b7U, 0xe6023563U, 0xfd13f628U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x08000909U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0x4e719c59U, 0xf8f397ccU, 0xe1efec9dU, 0x9e005035U);
        WR1_PROG(REG_1404H, 0x16400000U);
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WR1_PROG(REG_1400H, 0x00830021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_XYZ[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_XYZ[4]);

        HW_SCE_p_func100(0x5e100886U, 0x3d5ba622U, 0xa2316c17U, 0x8b39470aU);
        WR1_PROG(REG_1404H, 0x16900000U);
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WR1_PROG(REG_1400H, 0x00830021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_XYZ[8]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_XYZ[12]);

        HW_SCE_p_func100(0xac019e67U, 0x86071491U, 0x620fcd08U, 0x071ddac7U);
        WR1_PROG(REG_1404H, 0x16e00000U);
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WR1_PROG(REG_1400H, 0x00830021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_XYZ[16]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_XYZ[20]);

        HW_SCE_p_func102(0xa655f7f7U, 0xbf1d5193U, 0x81aa7ee6U, 0xaf3f46ebU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_SUCCESS;
    }
}
