/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_ShaGenerateMessageDigestResumeSub (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

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
        WR1_PROG(REG_2004H, 0x00001000U);

        HW_SCE_p_func101(0x95733d28U, 0x556178a2U, 0xb36f0407U, 0x26d9bb0bU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x00001040U);

        HW_SCE_p_func101(0x3a455415U, 0x00ce3c7fU, 0x4694fc39U, 0x02675bf2U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x00001050U);

        HW_SCE_p_func101(0x9eefc10eU, 0xafe8424dU, 0x7408f675U, 0x0b3b2d97U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_2004H, 0x00001080U);

        HW_SCE_p_func101(0x31f82889U, 0x26a74939U, 0x7cd2ad37U, 0xd3eefb99U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        WR1_PROG(REG_2004H, 0x00001090U);

        HW_SCE_p_func101(0x35257d5cU, 0x8646f0ddU, 0xa6586533U, 0x0ea35354U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        WR1_PROG(REG_2004H, 0x000010a0U);

        HW_SCE_p_func101(0xf1d49c6eU, 0x08e7ceaeU, 0xcb9b0b96U, 0x42dc99dcU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
    {
        WR1_PROG(REG_2004H, 0x000010b0U);

        HW_SCE_p_func101(0xdc157512U, 0x89ea5841U, 0x8741d185U, 0xe61fc720U);
    }

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

    HW_SCE_p_func101(0x04705722U, 0xa8bb1bd4U, 0x10863c5cU, 0x9a1d10aaU);

    return FSP_SUCCESS;
}
