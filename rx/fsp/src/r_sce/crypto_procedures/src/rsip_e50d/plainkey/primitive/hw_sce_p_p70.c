/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_OemKeyIndexValidationSub (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00700001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    HW_SCE_p_func049(InData_Cmd);

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
    WR1_PROG(REG_1600H, 0x00000005U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    WR1_PROG(REG_1600H, 0x3420a880U);
    WR1_PROG(REG_1600H, 0x00000033U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0x7427e0a6U, 0xcf9b2428U, 0x40f3b1ecU, 0xbee070bcU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0xb994531fU, 0x39923959U, 0x3d8c437aU, 0xbe8be38dU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x0000349fU);

        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800100e0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000070U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xfd19fb1fU, 0x42caa5e7U, 0x2d4d9d25U, 0x6993a7c6U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x000034e4U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000070U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x904ebd34U, 0x518724e7U, 0x176152e8U, 0x0020ce02U);
        HW_SCE_p_func044();

        HW_SCE_p_func100(0x338e6568U, 0x25bae2d7U, 0x3f80ec8fU, 0x9367a159U);

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        HW_SCE_p_func081();

        WR1_PROG(REG_1600H, 0x00007c01U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_1444H, 0x00020062U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7009c06U);

            for (iLoop = 0U; iLoop < (KEY_INDEX_SIZE - 5); iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func209();

            HW_SCE_p_func101(0xa2f05608U, 0xd1928d06U, 0x133ccb33U, 0xecb00ae0U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000aU)
        {
            WR1_PROG(REG_1444H, 0x000023c2U);
            WR1_PROG(REG_1A2CH, 0x40000800U);
            WR1_PROG(REG_1A24H, 0xe8009007U);

            for (iLoop = 0U; iLoop < 36; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xb31493d7U, 0x6ccffecfU, 0x2dd4a9efU, 0xe979141eU);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000bU)
        {
            WR1_PROG(REG_1444H, 0x00003fc2U);
            WR1_PROG(REG_1A2CH, 0x40000f00U);
            WR1_PROG(REG_1A24H, 0xf7009c07U);

            for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x6d564428U, 0x3b2c453dU, 0x5ccf3256U, 0x706634b6U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000cU)
        {
            WR1_PROG(REG_1444H, 0x000043c2U);
            WR1_PROG(REG_1A2CH, 0x40001000U);
            WR1_PROG(REG_1A24H, 0xe8009007U);

            for (iLoop = 0U; iLoop < 68; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x02f7c07cU, 0xb930c436U, 0x9d7ae67dU, 0xf41055eaU);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000dU)
        {
            WR1_PROG(REG_1444H, 0x00007fc2U);
            WR1_PROG(REG_1A2CH, 0x40001f00U);
            WR1_PROG(REG_1A24H, 0xf7009c07U);

            for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0xd00d2792U, 0xa6f16bb6U, 0x29cc6061U, 0x7c0bfc89U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000012U)
        {
            WR1_PROG(REG_1444H, 0x00020062U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8009006U);

            for (iLoop = 0U; iLoop < (KEY_INDEX_SIZE - 5); iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func209();

            HW_SCE_p_func101(0xd1183f78U, 0x55027e44U, 0x354fb506U, 0xc8638903U);
        }

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0xd4fab672U, 0x817a33d4U, 0x21cead95U, 0x08cc09d3U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x24e19d0cU, 0x372134a7U, 0xfd80dbdaU, 0xfe22498bU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
        }
        else
        {
            HW_SCE_p_func102(0x962ca917U, 0x8af4725dU, 0x1fefc0caU, 0x4acf7d94U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
