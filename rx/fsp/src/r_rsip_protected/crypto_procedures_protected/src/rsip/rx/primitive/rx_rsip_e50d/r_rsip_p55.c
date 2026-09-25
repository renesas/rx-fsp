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

rsip_ret_t r_rsip_p55 (const uint32_t InData_Cmd[], uint32_t OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00550001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func049(InData_Cmd);

    r_rsip_func_sub006(0x3420a880U, 0x0000002cU, 0x00260000U);

    r_rsip_func_sub006(0x3420a880U, 0x00000031U, 0x00A60000U);

    static const uint32_t Param_p55_func100_001[] =
    {
        BSWAP_32BIG_C(0x9126e865U), BSWAP_32BIG_C(0x6ce6b4bbU), BSWAP_32BIG_C(0x4f04be1aU), BSWAP_32BIG_C(0xbf8504c6U),
    };
    r_rsip_func100(Param_p55_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p55_func102_001[] =
        {
            BSWAP_32BIG_C(0xbd8009c3U), BSWAP_32BIG_C(0x31293d58U), BSWAP_32BIG_C(0xcdeb5522U), BSWAP_32BIG_C(
                0x0fa0b23dU),
        };
        r_rsip_func102(Param_p55_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub021(0x00000842U, 0x38008880U, 0x0000002cU, 0x1000b420U);
        r_rsip_func_sub021(0x00000004U, 0x1000d040U, 0x38008880U, 0x0000002dU);
        r_rsip_func_sub021(0x1000b420U, 0x00000008U, 0x38008880U, 0x0000002eU);
        r_rsip_func_sub021(0x1000b420U, 0x0000000cU, 0x38008880U, 0x0000002fU);
        r_rsip_func_sub021(0x1000b420U, 0x00000010U, 0x38008880U, 0x00000030U);
        WR1_PROG(REG_1600H, 0x1000b420U);
        WR1_PROG(REG_1600H, 0x00000008U);

        r_rsip_func_sub009(0x00005501U);

        static const uint32_t Param_p55_func101_001[] =
        {
            BSWAP_32BIG_C(0x8db69909U), BSWAP_32BIG_C(0xc5f60878U), BSWAP_32BIG_C(0x46e8288eU), BSWAP_32BIG_C(
                0xd4e607a6U),
        };
        r_rsip_func101(Param_p55_func101_001);
        r_rsip_func103();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x00000055U);

        static const uint32_t Param_p55_func101_002[] =
        {
            BSWAP_32BIG_C(0xc57aa538U), BSWAP_32BIG_C(0xca1262b5U), BSWAP_32BIG_C(0x024bc1b4U), BSWAP_32BIG_C(
                0x25cd210bU),
        };
        r_rsip_func101(Param_p55_func101_002);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e4U);

        r_rsip_func_sub009(0x00000055U);

        static const uint32_t Param_p55_func101_003[] =
        {
            BSWAP_32BIG_C(0x55dec683U), BSWAP_32BIG_C(0x63bb2a60U), BSWAP_32BIG_C(0xbfed7618U), BSWAP_32BIG_C(
                0x6352ed27U),
        };
        r_rsip_func101(Param_p55_func101_003);
        r_rsip_func044();

        static const uint32_t Param_p55_func100_002[] =
        {
            BSWAP_32BIG_C(0xb34a6b2dU), BSWAP_32BIG_C(0x86ecad69U), BSWAP_32BIG_C(0x60a0fee2U), BSWAP_32BIG_C(
                0x067f140cU),
        };
        r_rsip_func100(Param_p55_func100_002);
        WR1_PROG(REG_1444H, 0x000001a2U);
        r_rsip_func_sub028(0x08000044U, 0x00000000U);

        r_rsip_func_sub028(0x08000054U, 0x00000000U);

        r_rsip_func_sub016(0x81010020U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
        {
            r_rsip_func_sub009(0x00005502U);

            static const uint32_t Param_p55_func101_004[] =
            {
                BSWAP_32BIG_C(0x5cce5c80U), BSWAP_32BIG_C(0x1360aa79U), BSWAP_32BIG_C(0x7235e601U), BSWAP_32BIG_C(
                    0xd26bfc05U),
            };
            r_rsip_func101(Param_p55_func101_004);
            r_rsip_func103();

            static const uint32_t Param_p55_func100_003[] =
            {
                BSWAP_32BIG_C(0xba4da895U), BSWAP_32BIG_C(0x1682aaa0U), BSWAP_32BIG_C(0x4a62522bU), BSWAP_32BIG_C(
                    0x5b81c3ffU),
            };
            r_rsip_func100(Param_p55_func100_003);
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d45U);
            r_rsip_func_sub001(0x00820011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

            WR1_PROG(REG_1600H, 0x0000a820U);
            WR1_PROG(REG_1600H, 0x00000004U);

            static const uint32_t Param_p55_func101_005[] =
            {
                BSWAP_32BIG_C(0xb77c07b7U), BSWAP_32BIG_C(0x8649ca01U), BSWAP_32BIG_C(0xc1b6f484U), BSWAP_32BIG_C(
                    0x0b0a46cdU),
            };
            r_rsip_func101(Param_p55_func101_005);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub014(0x00007c01U, 0x00602000U);

        r_rsip_func_sub006(0x38008840U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p55_func100_004[] =
        {
            BSWAP_32BIG_C(0xe1171c63U), BSWAP_32BIG_C(0x6e77effaU), BSWAP_32BIG_C(0x817428ddU), BSWAP_32BIG_C(
                0x65b235ebU),
        };
        r_rsip_func100(Param_p55_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub009(0x00005503U);

            static const uint32_t Param_p55_func101_006[] =
            {
                BSWAP_32BIG_C(0xe7d210d0U), BSWAP_32BIG_C(0x82445831U), BSWAP_32BIG_C(0x3286dbe9U), BSWAP_32BIG_C(
                    0x25d78a62U),
            };
            r_rsip_func101(Param_p55_func101_006);
            r_rsip_func103();
            static const uint32_t Param_p55_func100_005[] =
            {
                BSWAP_32BIG_C(0x8620fbb9U), BSWAP_32BIG_C(0xd2c67f6cU), BSWAP_32BIG_C(0xd6e2efbbU), BSWAP_32BIG_C(
                    0x9085175dU),
            };
            r_rsip_func100(Param_p55_func100_005);
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d45U);
            r_rsip_func_sub001(0x0082000dU);
            r_rsip_func_sub001(0x00020005U);
            r_rsip_func_sub001(0x00800005U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

            iLoop = iLoop + 4;

            static const uint32_t Param_p55_func101_007[] =
            {
                BSWAP_32BIG_C(0x6f3c11faU), BSWAP_32BIG_C(0x646b44bcU), BSWAP_32BIG_C(0x826e9f64U), BSWAP_32BIG_C(
                    0xf5258fa8U),
            };
            r_rsip_func101(Param_p55_func101_007);
        }

        static const uint32_t Param_p55_func100_006[] =
        {
            BSWAP_32BIG_C(0x3ad8ca81U), BSWAP_32BIG_C(0x0e8ed3bbU), BSWAP_32BIG_C(0x2f79cd87U), BSWAP_32BIG_C(
                0xcd944530U),
        };
        r_rsip_func100(Param_p55_func100_006);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

        static const uint32_t Param_p55_func100_007[] =
        {
            BSWAP_32BIG_C(0xd454edd2U), BSWAP_32BIG_C(0x8b9ff848U), BSWAP_32BIG_C(0x17402349U), BSWAP_32BIG_C(
                0x4d6422b2U),
        };
        r_rsip_func100(Param_p55_func100_007);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

        static const uint32_t Param_p55_func102_002[] =
        {
            BSWAP_32BIG_C(0x72fd8fd8U), BSWAP_32BIG_C(0x91f76eceU), BSWAP_32BIG_C(0x7653c43aU), BSWAP_32BIG_C(
                0xe7b459aaU),
        };
        r_rsip_func102(Param_p55_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
