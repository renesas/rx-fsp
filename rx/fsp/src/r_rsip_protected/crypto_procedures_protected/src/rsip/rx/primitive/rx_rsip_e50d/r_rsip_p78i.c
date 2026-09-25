/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"
#include "r_rsip_sub_func.h"

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p78i (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00780001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    static const uint32_t Param_p78i_func100_001[] =
    {
        BSWAP_32BIG_C(0xf1236960U), BSWAP_32BIG_C(0x72428804U), BSWAP_32BIG_C(0x641550edU), BSWAP_32BIG_C(0xa693815aU),
    };
    r_rsip_func100(Param_p78i_func100_001);
    WR1_PROG(REG_2400H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a800U, 0x00000004U, 0x2000b400U, 0x00000003U);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2404H, 0x00000001U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000024U);

        static const uint32_t Param_p78i_func101_001[] =
        {
            BSWAP_32BIG_C(0xafaaafb2U), BSWAP_32BIG_C(0x323250d5U), BSWAP_32BIG_C(0xf01ba28dU), BSWAP_32BIG_C(
                0xd8401fd7U),
        };
        r_rsip_func101(Param_p78i_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2404H, 0x00000011U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000022U);

        static const uint32_t Param_p78i_func101_002[] =
        {
            BSWAP_32BIG_C(0xf772d8deU), BSWAP_32BIG_C(0x153c2e54U), BSWAP_32BIG_C(0x35b08704U), BSWAP_32BIG_C(
                0x5e72c33dU),
        };
        r_rsip_func101(Param_p78i_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2404H, 0x00000021U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x0000001aU);

        static const uint32_t Param_p78i_func101_003[] =
        {
            BSWAP_32BIG_C(0x71354b0bU), BSWAP_32BIG_C(0x8442a75fU), BSWAP_32BIG_C(0xe54d0faeU), BSWAP_32BIG_C(
                0x3ad50ae3U),
        };
        r_rsip_func101(Param_p78i_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_2404H, 0x00000031U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000012U);

        static const uint32_t Param_p78i_func101_004[] =
        {
            BSWAP_32BIG_C(0x9f906916U), BSWAP_32BIG_C(0x9b7d4583U), BSWAP_32BIG_C(0xa18918c2U), BSWAP_32BIG_C(
                0x5f663f03U),
        };
        r_rsip_func101(Param_p78i_func101_004);
    }

    static const uint32_t Param_p78i_func100_002[] =
    {
        BSWAP_32BIG_C(0x69f79d13U), BSWAP_32BIG_C(0xe7a1bb8bU), BSWAP_32BIG_C(0xe1fbfa8dU), BSWAP_32BIG_C(0x875d12c6U),
    };
    r_rsip_func100(Param_p78i_func100_002);
    r_rsip_func_sub016(0x81010020U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_240CH, 0x00000100U);

        static const uint32_t Param_p78i_func101_005[] =
        {
            BSWAP_32BIG_C(0xa1de41ecU), BSWAP_32BIG_C(0xd680dfccU), BSWAP_32BIG_C(0xe10220d6U), BSWAP_32BIG_C(
                0xa7669e4fU),
        };
        r_rsip_func101(Param_p78i_func101_005);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2414H, InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2410H, InData_MsgLen[1]);

        static const uint32_t Param_p78i_func101_006[] =
        {
            BSWAP_32BIG_C(0xfc1f9aa9U), BSWAP_32BIG_C(0x98eda8e4U), BSWAP_32BIG_C(0x3bf7cfcdU), BSWAP_32BIG_C(
                0x855d6828U),
        };
        r_rsip_func101(Param_p78i_func101_006);
    }

    return RSIP_RET_PASS;
}
