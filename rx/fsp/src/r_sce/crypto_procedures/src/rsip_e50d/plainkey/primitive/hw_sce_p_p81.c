/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_SelfCheck1Sub (void)
{
    WR1_PROG(REG_1D04H, 0x0004dfe1U);
    WR1_PROG(REG_1D08H, 0x000acf24U);

    WR1_PROG(REG_1D00H, 0x00000001U);

    WAIT_STS(REG_1D00H, 1, 0);

    if (RD1_MASK(REG_1D00H, 0x00030000U) != 0x00000000U)
    {
        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        WR1_PROG(REG_140CH, 0x38c60eedU);
        WR1_PROG(REG_1448H, 0x00000000U);

        WR1_PROG(REG_1408H, 0x00000001U);
        WR1_PROG(REG_1414H, 0x00001601U);

        if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
        {
            return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
        }

        WR1_PROG(REG_1800H, 0x00000001U);
        WR1_PROG(REG_1700H, 0x00000001U);

        WR1_PROG(REG_1B00H, 0x00818001U);
        WR1_PROG(REG_1B08H, 0x00000d00U);

        WR1_PROG(REG_1804H, 0x00008006U);

        WR1_PROG(REG_1444H, 0x000003a2U);
        HW_SCE_p_func101(change_endian_long(0x3dbe24b0U), change_endian_long(0x8fc0d4d9U),
                         change_endian_long(0xcd588ccbU), change_endian_long(0xfc081225U));
        WR1_PROG(REG_1804H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, 0xe2126efcU, 0x80c7986aU, 0xf7a6a83cU, 0x081e2486U);

        HW_SCE_p_func101(change_endian_long(0x5e0aa655U), change_endian_long(0xa1821e78U),
                         change_endian_long(0x8a7c9507U), change_endian_long(0x147435feU));

        HW_SCE_p_func100(change_endian_long(0x7ff07e6fU), change_endian_long(0xc7b4e201U),
                         change_endian_long(0x16fe6df0U), change_endian_long(0x2839c823U));

        WR1_PROG(REG_1408H, 0x00020000U);

        if (CHCK_STS(REG_142CH, 13, 0))
        {
            WR1_PROG(REG_14BCH, 0x00000020U);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            WR1_PROG(REG_1430H, 0x0000FFFFU);

            WR1_PROG(REG_1B08H, 0x00000220U);

            HW_SCE_p_func102(change_endian_long(0x3d4107ffU), change_endian_long(0xcf55da78U),
                             change_endian_long(0xd459cbc7U), change_endian_long(0x2779a7a8U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
