/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Sha3GenerateMessageDigestInitSub (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00780001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    HW_SCE_p_func100(0xed7547ceU, 0xfcba6bfaU, 0xcdebdaa0U, 0xb5f9eeb3U);
    WR1_PROG(REG_2400H, 0x00000001U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x2000b400U);
    WR1_PROG(REG_1600H, 0x00000003U);

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2404H, 0x00000001U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000024U);

        HW_SCE_p_func101(0x9fd0c9fbU, 0xb2816acdU, 0x21e78d08U, 0xadaf6812U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2404H, 0x00000011U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000022U);

        HW_SCE_p_func101(0x82daff77U, 0x3684b0e9U, 0xf16f748aU, 0x1d5dc9aaU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2404H, 0x00000021U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x0000001aU);

        HW_SCE_p_func101(0x76dacc82U, 0xf644f3e4U, 0xe31e8242U, 0xff74d8a5U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_2404H, 0x00000031U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000012U);

        HW_SCE_p_func101(0x6a50f971U, 0xf70d45a1U, 0xbbdab474U, 0x366c2050U);
    }

    HW_SCE_p_func100(0x6d99c9efU, 0x564fa8fbU, 0x854f4beaU, 0xc11eb4beU);
    WR1_PROG(REG_1608H, 0x81010020U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = change_endian_long(S_RAM[0]);

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_240CH, 0x00000100U);

        HW_SCE_p_func101(0x2556fb82U, 0xd16feba6U, 0x6806396aU, 0x2531bcf2U);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2414H, InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2410H, InData_MsgLen[1]);

        HW_SCE_p_func101(0x833dd81eU, 0x67d42b0bU, 0x9ef8895dU, 0x3e49f2b4U);
    }

    return FSP_SUCCESS;
}
