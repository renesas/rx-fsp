/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_ShaGenerateMessageDigestInitSub (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00730001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    HW_SCE_p_func100(0xbcc43577U, 0x385e24a1U, 0x22646cd0U, 0xd188cd99U);
    WR1_PROG(REG_2000H, 0x00000001U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1600H, 0x00000007U);
    WR1_PROG(REG_1600H, 0x2000b400U);
    WR1_PROG(REG_1600H, 0x00000006U);

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2004H, 0x00000000U);

        HW_SCE_p_func101(0xd7e518ebU, 0xe2aaa3c2U, 0x5307ebd9U, 0xad4b8a3cU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x00000040U);

        HW_SCE_p_func101(0xcf7b96d4U, 0xc4db6739U, 0x58c4ad2dU, 0x90498090U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x00000050U);

        HW_SCE_p_func101(0x1b19490fU, 0x4f036fe1U, 0xfa91151bU, 0x0ce86eaaU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_2004H, 0x00000080U);

        HW_SCE_p_func101(0x062c6de7U, 0x47aa2a28U, 0x51ce9c69U, 0xccd41cccU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        WR1_PROG(REG_2004H, 0x00000090U);

        HW_SCE_p_func101(0x8ec2db4aU, 0x3720ce77U, 0x2d7be330U, 0x09dabd63U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        WR1_PROG(REG_2004H, 0x000000a0U);

        HW_SCE_p_func101(0x97eb473fU, 0xf9d9fcddU, 0xb6902189U, 0xffe56dd2U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
    {
        WR1_PROG(REG_2004H, 0x000000b0U);

        HW_SCE_p_func101(0x55e210ecU, 0xc78e7cd4U, 0xc70703c0U, 0xcb382162U);
    }

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_200CH, 0x00000100U);

        HW_SCE_p_func101(0x7d89cd0bU, 0x0a38c435U, 0x194c4776U, 0x3afb46a0U);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2014H, InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2010H, InData_MsgLen[1]);

        HW_SCE_p_func101(0xd4ce9929U, 0x5057eeb7U, 0xc3195f13U, 0xc86c52b8U);
    }

    return FSP_SUCCESS;
}
