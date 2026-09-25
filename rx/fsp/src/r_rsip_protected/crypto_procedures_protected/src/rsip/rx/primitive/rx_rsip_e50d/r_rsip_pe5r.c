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

rsip_ret_t r_rsip_pe5r (const uint32_t InData_KeyType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[])
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

    static const uint32_t Param_pe5r_func100_001[] =
    {
        BSWAP_32BIG_C(0x69dcccd7U), BSWAP_32BIG_C(0x6e9d41a8U), BSWAP_32BIG_C(0x2a827502U), BSWAP_32BIG_C(0x039e95d5U),
    };
    r_rsip_func100(Param_pe5r_func100_001);
    r_rsip_func_sub021(0x3420a8c0U, 0x00000003U, 0x2000b4c0U, 0x00000002U);

    r_rsip_func_sub014(0x00007c06U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub032(0x00001050U, 0x0000b5e0U, 0x00000008U);

        static const uint32_t Param_pe5r_func101_001[] =
        {
            BSWAP_32BIG_C(0x856a5804U), BSWAP_32BIG_C(0xbb676e17U), BSWAP_32BIG_C(0x1e75d297U), BSWAP_32BIG_C(
                0xed7b7144U),
        };
        r_rsip_func101(Param_pe5r_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub032(0x000010a0U, 0x0000b5e0U, 0x0000000cU);

        static const uint32_t Param_pe5r_func101_002[] =
        {
            BSWAP_32BIG_C(0xf018fb1eU), BSWAP_32BIG_C(0xaff3a727U), BSWAP_32BIG_C(0x5630f3c1U), BSWAP_32BIG_C(
                0x2742ed01U),
        };
        r_rsip_func101(Param_pe5r_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub032(0x000010b0U, 0x0000b5e0U, 0x00000010U);

        static const uint32_t Param_pe5r_func101_003[] =
        {
            BSWAP_32BIG_C(0x735ac157U), BSWAP_32BIG_C(0x1df3b358U), BSWAP_32BIG_C(0x6ea0e8c1U), BSWAP_32BIG_C(
                0xed26dce7U),
        };
        r_rsip_func101(Param_pe5r_func101_003);
    }

    WR1_PROG(REG_2008H, 0x00000003U);

    r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

    static const uint32_t Param_pe5r_func100_002[] =
    {
        BSWAP_32BIG_C(0xe0f8c36eU), BSWAP_32BIG_C(0xe7e04317U), BSWAP_32BIG_C(0x33db8a73U), BSWAP_32BIG_C(0x353059ceU),
    };
    r_rsip_func100(Param_pe5r_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub021(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x0000001bU);

        r_rsip_func_sub021(0x0000b500U, 0x00000008U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub021(0x00000028U, 0x0000b500U, 0x0000000cU, 0x00050040U);
        r_rsip_func_sub021(0x0000b4a0U, 0x00000029U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5r_func101_004[] =
        {
            BSWAP_32BIG_C(0xfb7cec3aU), BSWAP_32BIG_C(0x4832d5a5U), BSWAP_32BIG_C(0xd9cbeed9U), BSWAP_32BIG_C(
                0x9ed25aa3U),
        };
        r_rsip_func101(Param_pe5r_func101_004);
    }
    else
    {
        r_rsip_func_sub021(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x01a9da78U);

        r_rsip_func_sub021(0x0000b500U, 0x00000010U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub021(0x0102b2eaU, 0x0000b500U, 0x00000010U, 0x00050040U);
        r_rsip_func_sub021(0x0000b4a0U, 0x01e30848U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5r_func101_005[] =
        {
            BSWAP_32BIG_C(0xc7e9a131U), BSWAP_32BIG_C(0x11c2e6f8U), BSWAP_32BIG_C(0x7749010bU), BSWAP_32BIG_C(
                0x03137013U),
        };
        r_rsip_func101(Param_pe5r_func101_005);
    }

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000e502U);

    static const uint32_t Param_pe5r_func101_006[] =
    {
        BSWAP_32BIG_C(0xe2240e32U), BSWAP_32BIG_C(0x97bb078aU), BSWAP_32BIG_C(0x0f967080U), BSWAP_32BIG_C(0x0e9c504aU),
    };
    r_rsip_func101(Param_pe5r_func101_006);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub009(0x0000e502U);

    static const uint32_t Param_pe5r_func101_007[] =
    {
        BSWAP_32BIG_C(0xf3c147a2U), BSWAP_32BIG_C(0x5a180958U), BSWAP_32BIG_C(0x5fc3cf33U), BSWAP_32BIG_C(0xd4e94aadU),
    };
    r_rsip_func101(Param_pe5r_func101_007);
    r_rsip_func044();

    static const uint32_t Param_pe5r_func100_003[] =
    {
        BSWAP_32BIG_C(0xd84d97e1U), BSWAP_32BIG_C(0xfd1383ceU), BSWAP_32BIG_C(0x42d698acU), BSWAP_32BIG_C(0xd347bed9U),
    };
    r_rsip_func100(Param_pe5r_func100_003);
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
        static const uint32_t Param_pe5r_func101_008[] =
        {
            BSWAP_32BIG_C(0x6881754bU), BSWAP_32BIG_C(0x662039c9U), BSWAP_32BIG_C(0x730d72a9U), BSWAP_32BIG_C(
                0xdcbe2a64U),
        };
        r_rsip_func101(Param_pe5r_func101_008);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000909U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe5r_func100_004[] =
    {
        BSWAP_32BIG_C(0xd2e4bc2eU), BSWAP_32BIG_C(0x8e346ac5U), BSWAP_32BIG_C(0x38c9e316U), BSWAP_32BIG_C(0x4cc06fa9U),
    };
    r_rsip_func100(Param_pe5r_func100_004);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe5r_func102_001[] =
        {
            BSWAP_32BIG_C(0xfb604cefU), BSWAP_32BIG_C(0xd0056359U), BSWAP_32BIG_C(0xa5992595U), BSWAP_32BIG_C(
                0x67422792U),
        };
        r_rsip_func102(Param_pe5r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub033(0x00000040U, InData_State[18], 0x00000040U, InData_State[19]);

        for (iLoop = 0U; iLoop < 18U; iLoop++)
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2028H, InData_State[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_pe5r_func101_009[] =
        {
            BSWAP_32BIG_C(0xa75e9c0eU), BSWAP_32BIG_C(0xd049ebffU), BSWAP_32BIG_C(0x69466df3U), BSWAP_32BIG_C(
                0xd891145dU),
        };
        r_rsip_func101(Param_pe5r_func101_009);

        return RSIP_RET_PASS;
    }
}
