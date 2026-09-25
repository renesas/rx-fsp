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

rsip_ret_t r_rsip_pe5i (const uint32_t InData_KeyType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgLen[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e50001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000001c7U, 0x800200a0U);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    static const uint32_t Param_pe5i_func100_001[] =
    {
        BSWAP_32BIG_C(0x69dcccd7U), BSWAP_32BIG_C(0x6e9d41a8U), BSWAP_32BIG_C(0x2a827502U), BSWAP_32BIG_C(0x039e95d5U),
    };
    r_rsip_func100(Param_pe5i_func100_001);
    r_rsip_func_sub021(0x3420a8c0U, 0x00000003U, 0x2000b4c0U, 0x00000002U);

    r_rsip_func_sub014(0x00007c06U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub032(0x00000050U, 0x0000b5e0U, 0x00000008U);

        static const uint32_t Param_pe5i_func101_001[] =
        {
            BSWAP_32BIG_C(0x49864032U), BSWAP_32BIG_C(0x2748870eU), BSWAP_32BIG_C(0xcacc7f77U), BSWAP_32BIG_C(
                0xe6d18c2bU),
        };
        r_rsip_func101(Param_pe5i_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub032(0x000000a0U, 0x0000b5e0U, 0x0000000cU);

        static const uint32_t Param_pe5i_func101_002[] =
        {
            BSWAP_32BIG_C(0x447e9844U), BSWAP_32BIG_C(0xa1a0f124U), BSWAP_32BIG_C(0x63721b75U), BSWAP_32BIG_C(
                0xc0dbb747U),
        };
        r_rsip_func101(Param_pe5i_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub032(0x000000b0U, 0x0000b5e0U, 0x00000010U);

        static const uint32_t Param_pe5i_func101_003[] =
        {
            BSWAP_32BIG_C(0x90c9903cU), BSWAP_32BIG_C(0xefd7cffbU), BSWAP_32BIG_C(0x0fc6d770U), BSWAP_32BIG_C(
                0xdb2cd135U),
        };
        r_rsip_func101(Param_pe5i_func101_003);
    }

    WR1_PROG(REG_2008H, 0x00000003U);

    r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

    static const uint32_t Param_pe5i_func100_002[] =
    {
        BSWAP_32BIG_C(0x751296dfU), BSWAP_32BIG_C(0x84540ce6U), BSWAP_32BIG_C(0xe8993649U), BSWAP_32BIG_C(0x28a20e06U),
    };
    r_rsip_func100(Param_pe5i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub021(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x0000001bU);

        r_rsip_func_sub021(0x0000b500U, 0x00000008U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub021(0x00000028U, 0x0000b500U, 0x0000000cU, 0x00050040U);
        r_rsip_func_sub021(0x0000b4a0U, 0x00000029U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5i_func101_004[] =
        {
            BSWAP_32BIG_C(0xc66bb45bU), BSWAP_32BIG_C(0xf6efa1e2U), BSWAP_32BIG_C(0xd58684cdU), BSWAP_32BIG_C(
                0x0dc02c6aU),
        };
        r_rsip_func101(Param_pe5i_func101_004);
    }
    else
    {
        r_rsip_func_sub021(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x01a9da78U);

        r_rsip_func_sub021(0x0000b500U, 0x00000010U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub021(0x0102b2eaU, 0x0000b500U, 0x00000010U, 0x00050040U);
        r_rsip_func_sub021(0x0000b4a0U, 0x01e30848U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5i_func101_005[] =
        {
            BSWAP_32BIG_C(0xc97a1daaU), BSWAP_32BIG_C(0xacef8bb3U), BSWAP_32BIG_C(0xa43726b8U), BSWAP_32BIG_C(
                0xd44cf2ffU),
        };
        r_rsip_func101(Param_pe5i_func101_005);
    }

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000e501U);

    static const uint32_t Param_pe5i_func101_006[] =
    {
        BSWAP_32BIG_C(0x90791c46U), BSWAP_32BIG_C(0xd81ce91bU), BSWAP_32BIG_C(0x1f3499e4U), BSWAP_32BIG_C(0x7958d9eeU),
    };
    r_rsip_func101(Param_pe5i_func101_006);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub009(0x0000e501U);

    static const uint32_t Param_pe5i_func101_007[] =
    {
        BSWAP_32BIG_C(0x4ebbb4a7U), BSWAP_32BIG_C(0x243f94f9U), BSWAP_32BIG_C(0x53d21620U), BSWAP_32BIG_C(0xc3d1f03eU),
    };
    r_rsip_func101(Param_pe5i_func101_007);
    r_rsip_func044();

    static const uint32_t Param_pe5i_func100_003[] =
    {
        BSWAP_32BIG_C(0x92d04eb5U), BSWAP_32BIG_C(0x8997d90bU), BSWAP_32BIG_C(0x9ff48c36U), BSWAP_32BIG_C(0xe1fd085dU),
    };
    r_rsip_func100(Param_pe5i_func100_003);
    r_rsip_func_sub016(0x81010100U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x00000929U);
    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x01420011U);

        WR1_PROG(REG_1600H, 0x0000a520U);
        WR1_PROG(REG_1600H, 0x00000004U);
        static const uint32_t Param_pe5i_func101_008[] =
        {
            BSWAP_32BIG_C(0x4b4aa8d5U), BSWAP_32BIG_C(0x197b4336U), BSWAP_32BIG_C(0x01320b7eU), BSWAP_32BIG_C(
                0x8bb39ab4U),
        };
        r_rsip_func101(Param_pe5i_func101_008);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000909U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe5i_func100_004[] =
    {
        BSWAP_32BIG_C(0xdd1012b1U), BSWAP_32BIG_C(0x9344c1afU), BSWAP_32BIG_C(0x7ab576c0U), BSWAP_32BIG_C(0x8bf88c20U),
    };
    r_rsip_func100(Param_pe5i_func100_004);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe5i_func102_001[] =
        {
            BSWAP_32BIG_C(0x74261502U), BSWAP_32BIG_C(0x813f1870U), BSWAP_32BIG_C(0x91cf92dbU), BSWAP_32BIG_C(
                0x65fec4b4U),
        };
        r_rsip_func102(Param_pe5i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
        {
            r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000080U);

            WR1_PROG(REG_200CH, 0x00000001U);

            WAIT_STS(REG_2030H, 8, 0);

            r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000000U);

            WR1_PROG(REG_200CH, 0x00000100U);

            static const uint32_t Param_pe5i_func101_009[] =
            {
                BSWAP_32BIG_C(0xf9e6a3ddU), BSWAP_32BIG_C(0x1c627d46U), BSWAP_32BIG_C(0x2a146a0eU), BSWAP_32BIG_C(
                    0x29618a66U),
            };
            r_rsip_func101(Param_pe5i_func101_009);
        }
        else
        {
            r_rsip_func_sub033(0x00000040U, InData_MsgLen[0], 0x00000040U, InData_MsgLen[1]);

            WR1_PROG(REG_200CH, 0x00000001U);

            static const uint32_t Param_pe5i_func101_010[] =
            {
                BSWAP_32BIG_C(0xa650d272U), BSWAP_32BIG_C(0x0ee0f836U), BSWAP_32BIG_C(0x3488bc4eU), BSWAP_32BIG_C(
                    0xd204508bU),
            };
            r_rsip_func101(Param_pe5i_func101_010);
        }

        return RSIP_RET_PASS;
    }
}
