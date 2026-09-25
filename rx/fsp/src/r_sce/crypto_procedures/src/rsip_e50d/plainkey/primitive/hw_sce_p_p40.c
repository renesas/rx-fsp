/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_LoadHukSub (const uint32_t InData_LC[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00400001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    HW_SCE_p_func048(InData_LC);

    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1600H, 0x0000000aU);

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1600H, 0x10003401U);

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1600H, 0x10003401U);

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1600H, 0x00000005U);
    WR1_PROG(REG_1600H, 0x10003401U);

    WR1_PROG(REG_1600H, 0x34202801U);
    WR1_PROG(REG_1600H, 0x20003401U);

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    if (InData_LC[0] == 0x00000000U)
    {
        WR1_PROG(REG_143CH, 0x00b80000U);

        HW_SCE_p_func101(0x70cbe4dbU, 0xe2f8cc53U, 0xbaf5d297U, 0xcdecee68U);
    }
    else if (InData_LC[0] == 0x00000001U)
    {
        WR1_PROG(REG_143CH, 0x00b00000U);

        HW_SCE_p_func101(0xe4590ff0U, 0xb2fa4b4bU, 0x19e4af44U, 0xb957dfe6U);
    }
    else if (InData_LC[0] == 0x00000004U)
    {
        WR1_PROG(REG_143CH, 0x00b30000U);

        HW_SCE_p_func101(0x9e957696U, 0xfefcaa89U, 0x91731aebU, 0x4ac81be7U);
    }
    else if (InData_LC[0] == 0x00000006U)
    {
        WR1_PROG(REG_143CH, 0x00b50000U);

        HW_SCE_p_func101(0xede39517U, 0xbf81d9b0U, 0x531f22d8U, 0x1c0ef68aU);
    }
    else if (InData_LC[0] == 0x00000007U)
    {
        WR1_PROG(REG_143CH, 0x00b60000U);

        HW_SCE_p_func101(0x5d234b37U, 0x37607792U, 0xeec7f9b0U, 0x7b7369e9U);
    }
    else if (InData_LC[0] == 0x00000008U)
    {
        WR1_PROG(REG_143CH, 0x00b70000U);

        HW_SCE_p_func101(0xf860a0baU, 0x5fddd60cU, 0x034e4aa2U, 0x03ea8159U);
    }
    else if (InData_LC[0] == 0x00000009U)
    {
        WR1_PROG(REG_143CH, 0x00b90000U);

        HW_SCE_p_func101(0x4cf12f73U, 0xa0c6c4acU, 0x5b84a9c9U, 0x8f53c80cU);
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38000c00U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        HW_SCE_p_func101(0x078164f4U, 0xe320fe7dU, 0xdcb4d417U, 0x37768c63U);
    }

    HW_SCE_p_func100(0x96a18a05U, 0x5623e05fU, 0xfc97ccfbU, 0x6888ed87U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x7847c0faU, 0x234dff1aU, 0xda0f4558U, 0x8be81f0dU);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x6c9e4cb0U), change_endian_long(0xcf194697U),
                 change_endian_long(0x55a37fefU), change_endian_long(0x24624d48U));

        WR1_PROG(REG_1A24H, 0x30471084U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x01ea725dU));

        WR1_PROG(REG_1A24H, 0x30471094U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x02ea725dU));

        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, change_endian_long(0x37692ff0U), change_endian_long(0x33a702b9U),
                 change_endian_long(0x570bf086U), change_endian_long(0xdeec8ea4U));

        HW_SCE_p_func100(0x9dac8c40U, 0x0db8f3cdU, 0x1a99828eU, 0xb569641bU);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d05U);
        WR1_PROG(REG_1438H, 0x20000000U);
        WR1_PROG(REG_1400H, 0x00880011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xf7008d05U);
        WR1_PROG(REG_1438H, 0x20000010U);
        WR1_PROG(REG_1400H, 0x00880011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1824H, 0x08000085U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0x603faae1U, 0x2145e3deU, 0xcfa34aacU, 0x7dfdddb9U);
        WR1_PROG(REG_1824H, 0x08000095U);
        WR1_PROG(REG_1400H, 0x00420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x000001b0U);
        WR1_PROG(REG_1600H, 0x00003c01U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WR1_PROG(REG_1438H, 0x20000020U);
        WR1_PROG(REG_1400H, 0x00880011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1A24H, 0x8c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000002a1U);
        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x4a008044U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x0e008104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x018beba7U));

        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x0e008104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x028beba7U));

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x000001d0U);
        WR1_PROG(REG_1608H, 0x80880001U);
        WR1_PROG(REG_1400H, 0x03410021U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0xc5ec19f6U, 0xb0b29cd6U, 0xe9f018aeU, 0xd932b8a2U);
        WR1_PROG(REG_1A24H, 0x4a470044U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1A24H, 0x0e4704c4U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0152db38U));

        WR1_PROG(REG_1A24H, 0x4a040044U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1A24H, 0x0e040504U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x01f7370eU));

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x000001c0U);
        WR1_PROG(REG_1608H, 0x80840001U);
        WR1_PROG(REG_1400H, 0x03420011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1B08H, 0x00000202U);

        HW_SCE_p_func102(0x5f0d3de8U, 0x26c66337U, 0xef5f8e7cU, 0xe1894945U);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_SUCCESS;
    }
}
