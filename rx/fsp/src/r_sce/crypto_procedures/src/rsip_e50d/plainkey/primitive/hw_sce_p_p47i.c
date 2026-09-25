/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Aes128EncryptDecryptInitSub (const uint32_t InData_KeyMode[],
                                              const uint32_t InData_Cmd[],
                                              const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_Key[],
                                              const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00470001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80020000U);
    WR1_PROG(REG_1444H, 0x000001c7U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x3000a800U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x00010020U);
    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WR1_PROG(REG_1600H, 0x38000c21U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x9082cc3fU, 0x96284513U, 0xe34c21e2U, 0x718adbedU);
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
        WR1_PROG(REG_1420H, change_endian_long(0x00000047U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0x440424b8U, 0x6efa3b32U, 0x861a06ebU, 0xbefd6491U);
        HW_SCE_p_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000005U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000047U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xaaf0985dU, 0x5857e403U, 0x03b173e1U, 0x1e82ef21U);
        HW_SCE_p_func044();

        HW_SCE_p_func100(0xcb7656bcU, 0x3a1e614fU, 0xaf1a5368U, 0xe20d341eU);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xf7009d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

        WR1_PROG(REG_1824H, 0x08000085U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0xd7cec133U, 0xe5241977U, 0xb86e7e95U, 0xb4bd364bU);
    }
    else
    {
        HW_SCE_p_func100(0x1d9d9e42U, 0xcf1cf0a3U, 0xbaae8f07U, 0x0175c814U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000085U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Key[0]);

        HW_SCE_p_func101(0x55bfc46eU, 0x37680ef7U, 0xb10a6d2fU, 0x55167499U);
    }

    HW_SCE_p_func100(0xe4478b8eU, 0x8174f428U, 0x9815ff11U, 0x8bfcfa0eU);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x57f6ca90U, 0x463689faU, 0x0ec48853U, 0xd13ef16cU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        HW_SCE_p_func100(0x61222fbdU, 0xfbe16c42U, 0xeb501b90U, 0xf3fa7358U);
        WR1_PROG(REG_1600H, 0x00007c00U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            HW_SCE_p_func101(0x20bbaacdU, 0xe43b0977U, 0x699a2710U, 0x8eee9e82U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            HW_SCE_p_func101(0x2da13340U, 0x96814105U, 0x5959ea8fU, 0x5dc8c794U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x08000045U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            HW_SCE_p_func101(0x0cb96b47U, 0xa84879bdU, 0xf74a8823U, 0x15389dd7U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x08000045U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            HW_SCE_p_func101(0xd4fde60cU, 0x0c200c79U, 0x9b07637aU, 0x6d60f633U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x08000045U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            HW_SCE_p_func101(0x725b232dU, 0x03b66c01U, 0xedd845bbU, 0x487d1f4aU);
        }
        else
        {
        }

        return FSP_SUCCESS;
    }
}
