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

rsip_ret_t r_rsip_p40 (const uint32_t InData_LC[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00400001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    r_rsip_func_sub021(0x0000b420U, 0x0000000aU, 0x38008800U, 0x00000002U);
    r_rsip_func_sub021(0x10003401U, 0x38008800U, 0x00000003U, 0x10003401U);

    r_rsip_func_sub021(0x38008800U, 0x00000005U, 0x10003401U, 0x34202801U);
    WR1_PROG(REG_1600H, 0x20003401U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    if (InData_LC[0] == 0x00000000U)
    {
        WR1_PROG(REG_143CH, 0x00b80000U);

        static const uint32_t Param_p40_func101_001[] =
        {
            BSWAP_32BIG_C(0x1245470bU), BSWAP_32BIG_C(0x7416ceccU), BSWAP_32BIG_C(0xcebc6d28U), BSWAP_32BIG_C(
                0x19d583bbU),
        };
        r_rsip_func101(Param_p40_func101_001);
    }
    else if (InData_LC[0] == 0x00000001U)
    {
        WR1_PROG(REG_143CH, 0x00b00000U);

        static const uint32_t Param_p40_func101_002[] =
        {
            BSWAP_32BIG_C(0x18108154U), BSWAP_32BIG_C(0xd30543a4U), BSWAP_32BIG_C(0x948e2178U), BSWAP_32BIG_C(
                0x26490282U),
        };
        r_rsip_func101(Param_p40_func101_002);
    }
    else if (InData_LC[0] == 0x00000004U)
    {
        WR1_PROG(REG_143CH, 0x00b30000U);

        static const uint32_t Param_p40_func101_003[] =
        {
            BSWAP_32BIG_C(0x83f0f51bU), BSWAP_32BIG_C(0x9fbb9badU), BSWAP_32BIG_C(0x44944e9dU), BSWAP_32BIG_C(
                0x75e13af0U),
        };
        r_rsip_func101(Param_p40_func101_003);
    }
    else if (InData_LC[0] == 0x00000006U)
    {
        WR1_PROG(REG_143CH, 0x00b50000U);

        static const uint32_t Param_p40_func101_004[] =
        {
            BSWAP_32BIG_C(0xd13a5f1aU), BSWAP_32BIG_C(0x75c49659U), BSWAP_32BIG_C(0xe3296201U), BSWAP_32BIG_C(
                0xaa30f651U),
        };
        r_rsip_func101(Param_p40_func101_004);
    }
    else if (InData_LC[0] == 0x00000007U)
    {
        WR1_PROG(REG_143CH, 0x00b60000U);

        static const uint32_t Param_p40_func101_005[] =
        {
            BSWAP_32BIG_C(0x8619db57U), BSWAP_32BIG_C(0xe130f883U), BSWAP_32BIG_C(0xac74c298U), BSWAP_32BIG_C(
                0x14c9b9cdU),
        };
        r_rsip_func101(Param_p40_func101_005);
    }
    else if (InData_LC[0] == 0x00000008U)
    {
        WR1_PROG(REG_143CH, 0x00b70000U);

        static const uint32_t Param_p40_func101_006[] =
        {
            BSWAP_32BIG_C(0x4841d020U), BSWAP_32BIG_C(0xc7c7b1caU), BSWAP_32BIG_C(0x8790b263U), BSWAP_32BIG_C(
                0xf6118a8cU),
        };
        r_rsip_func101(Param_p40_func101_006);
    }
    else if (InData_LC[0] == 0x00000009U)
    {
        WR1_PROG(REG_143CH, 0x00b90000U);

        static const uint32_t Param_p40_func101_007[] =
        {
            BSWAP_32BIG_C(0x03d94fafU), BSWAP_32BIG_C(0xaba20f08U), BSWAP_32BIG_C(0x58f7b2bdU), BSWAP_32BIG_C(
                0x76b591ffU),
        };
        r_rsip_func101(Param_p40_func101_007);
    }
    else
    {
        r_rsip_func_sub017(0x38000c00U, 0x00A60000U);

        static const uint32_t Param_p40_func101_008[] =
        {
            BSWAP_32BIG_C(0xd07c9d1cU), BSWAP_32BIG_C(0xfbae3e0dU), BSWAP_32BIG_C(0xdd3f1d5fU), BSWAP_32BIG_C(
                0x8f966a81U),
        };
        r_rsip_func101(Param_p40_func101_008);
    }

    static const uint32_t Param_p40_func100_001[] =
    {
        BSWAP_32BIG_C(0x6733c49aU), BSWAP_32BIG_C(0x58ea7e6fU), BSWAP_32BIG_C(0x82586e31U), BSWAP_32BIG_C(0xc43a99b8U),
    };
    r_rsip_func100(Param_p40_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p40_func102_001[] =
        {
            BSWAP_32BIG_C(0xe4662ac6U), BSWAP_32BIG_C(0xa38c49aaU), BSWAP_32BIG_C(0xab4975c3U), BSWAP_32BIG_C(
                0x9baaaf18U),
        };
        r_rsip_func102(Param_p40_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func040();

        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d05U);
        WR1_PROG(REG_1438H, 0x20000000U);
        r_rsip_func_sub001(0x00880011U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xf7008d05U);
        WR1_PROG(REG_1438H, 0x20000010U);
        r_rsip_func_sub001(0x00880011U);

        r_rsip_func_sub023(0x0000b420U, 0x000001d0U, 0x80880001U);
        r_rsip_func_sub001(0x03420021U);

        r_rsip_func_sub022(0x0000b420U, 0x000001b0U, 0x00003c01U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WR1_PROG(REG_1438H, 0x20000020U);
        r_rsip_func_sub001(0x00880011U);
        WR1_PROG(REG_1A24H, 0x8c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p40_func100_002[] =
        {
            BSWAP_32BIG_C(0x76a45e22U), BSWAP_32BIG_C(0x6cf20978U), BSWAP_32BIG_C(0x88c4c95dU), BSWAP_32BIG_C(
                0x0b418fd5U),
        };
        r_rsip_func100(Param_p40_func100_002);
        r_rsip_func_sub028(0x4a470044U, 0x00000000U);

        r_rsip_func_sub028(0x0e4704c4U, 0x0152db38U);

        r_rsip_func_sub028(0x4a040044U, 0x00000000U);

        r_rsip_func_sub028(0x0e040504U, 0x01f7370eU);

        r_rsip_func_sub023(0x0000b420U, 0x000001c0U, 0x80840001U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1B08H, 0x00000202U);

        static const uint32_t Param_p40_func102_002[] =
        {
            BSWAP_32BIG_C(0x9217ce9fU), BSWAP_32BIG_C(0xce3cc4e1U), BSWAP_32BIG_C(0x81b90025U), BSWAP_32BIG_C(
                0x03455513U),
        };
        r_rsip_func102(Param_p40_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
