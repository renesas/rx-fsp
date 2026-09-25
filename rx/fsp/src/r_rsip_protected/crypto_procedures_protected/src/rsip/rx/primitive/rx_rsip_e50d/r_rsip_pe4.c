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

rsip_ret_t r_rsip_pe4 (const uint32_t InData_HashType[],
                       const uint32_t InData_CurveType[],
                       const uint32_t InData_EncSecret[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e40001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a880U, 0x00000003U, 0x2000b480U, 0x00000002U);

    WR1_PROG(REG_1600H, 0x000009ceU);

    static const uint32_t Param_pe4_func100_001[] =
    {
        BSWAP_32BIG_C(0x6fd52207U), BSWAP_32BIG_C(0xb7c3d9b5U), BSWAP_32BIG_C(0x8cfa1de9U), BSWAP_32BIG_C(0x09b47a48U),
    };
    r_rsip_func100(Param_pe4_func100_001);
    r_rsip_func_sub014(0x00007c04U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x01fdb192U);

        r_rsip_func_sub003(0x800100c0U, 0x00000008U);

        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1600H, 0x01a9da78U);

        r_rsip_func_sub003(0x80010120U, 0x00000008U);

        static const uint32_t Param_pe4_func101_001[] =
        {
            BSWAP_32BIG_C(0xe83100ceU), BSWAP_32BIG_C(0x18c36bcdU), BSWAP_32BIG_C(0x2fde351eU), BSWAP_32BIG_C(
                0x5be6fcf2U),
        };
        r_rsip_func101(Param_pe4_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x01245edbU);

        r_rsip_func_sub003(0x800100c0U, 0x0000000cU);

        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1600H, 0x0102b2eaU);

        r_rsip_func_sub003(0x80010120U, 0x0000000cU);

        static const uint32_t Param_pe4_func101_002[] =
        {
            BSWAP_32BIG_C(0x7bf414f5U), BSWAP_32BIG_C(0x1874a17cU), BSWAP_32BIG_C(0x64343552U), BSWAP_32BIG_C(
                0x862f796eU),
        };
        r_rsip_func101(Param_pe4_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub010(0x000000c7U, 0x800101c0U);
        WR1_PROG(REG_1420H, InData_CurveType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x30000dceU, 0x00030020U, 0x0000b4a0U, 0x0161bb7bU);

        r_rsip_func_sub021(0x0000b4c0U, 0x00000014U, 0x00000060U, 0x0000b4a0U);
        r_rsip_func_sub021(0x01dcc5c6U, 0x0000b4c0U, 0x00000010U, 0x00000080U);

        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1600H, 0x01e30848U);

        static const uint32_t Param_pe4_func101_003[] =
        {
            BSWAP_32BIG_C(0x923f8934U), BSWAP_32BIG_C(0x92ad4bbeU), BSWAP_32BIG_C(0x6325f7f6U), BSWAP_32BIG_C(
                0xf3bc8626U),
        };
        r_rsip_func101(Param_pe4_func101_003);
    }

    r_rsip_func_sub009(0x000000e4U);

    static const uint32_t Param_pe4_func101_004[] =
    {
        BSWAP_32BIG_C(0xaf90ff93U), BSWAP_32BIG_C(0xac0a686cU), BSWAP_32BIG_C(0x6920d0acU), BSWAP_32BIG_C(0x9c9e8ef7U),
    };
    r_rsip_func101(Param_pe4_func101_004);
    r_rsip_func407(InData_EncSecret);

    static const uint32_t Param_pe4_func100_002[] =
    {
        BSWAP_32BIG_C(0x91d4b0cdU), BSWAP_32BIG_C(0xbf4fbce0U), BSWAP_32BIG_C(0xa8cadd5bU), BSWAP_32BIG_C(0x78058ae3U),
    };
    r_rsip_func100(Param_pe4_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe4_func102_001[] =
        {
            BSWAP_32BIG_C(0xded3857eU), BSWAP_32BIG_C(0x00452241U), BSWAP_32BIG_C(0x9a120d20U), BSWAP_32BIG_C(
                0xc551c83bU),
        };
        r_rsip_func102(Param_pe4_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub006(0x38008880U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_pe4_func100_003[] =
        {
            BSWAP_32BIG_C(0x529cc0e3U), BSWAP_32BIG_C(0xb8dc6bebU), BSWAP_32BIG_C(0x46055777U), BSWAP_32BIG_C(
                0xa6945d38U),
        };
        r_rsip_func100(Param_pe4_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub017(0x38000dceU, 0x00260000U);

            static const uint32_t Param_pe4_func100_004[] =
            {
                BSWAP_32BIG_C(0xf67df486U), BSWAP_32BIG_C(0x96d1d40cU), BSWAP_32BIG_C(0x15647cc9U), BSWAP_32BIG_C(
                    0x3d58b5c2U),
            };
            r_rsip_func100(Param_pe4_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                WR1_PROG(REG_2014H, 0x00000000U);
                WR1_PROG(REG_2010H, 0x00000210U);

                r_rsip_func408();

                WR1_PROG(REG_1600H, 0x000008a5U);

                WR1_PROG(REG_1608H, 0x81910005U);
                r_rsip_func_sub001(0x01490045U);

                WAIT_STS(REG_2030H, 8, 0);
                WR1_PROG(REG_143CH, 0x00001600U);

                WR1_PROG(REG_1608H, 0x80900005U);
                r_rsip_func_sub001(0x03450041U);

                static const uint32_t Param_pe4_func101_005[] =
                {
                    BSWAP_32BIG_C(0x756533a9U), BSWAP_32BIG_C(0x9c532b39U), BSWAP_32BIG_C(0xe5bc3493U), BSWAP_32BIG_C(
                        0x174afabfU),
                };
                r_rsip_func101(Param_pe4_func101_005);
            }
            else
            {
                static const uint32_t Param_pe4_func101_006[] =
                {
                    BSWAP_32BIG_C(0x9c109f9aU), BSWAP_32BIG_C(0xc203243fU), BSWAP_32BIG_C(0xc659283bU), BSWAP_32BIG_C(
                        0xc4804528U),
                };
                r_rsip_func101(Param_pe4_func101_006);
            }
        }
        else
        {
            static const uint32_t Param_pe4_func100_005[] =
            {
                BSWAP_32BIG_C(0x50d32d4aU), BSWAP_32BIG_C(0x0c750b39U), BSWAP_32BIG_C(0xcdc9d0e7U), BSWAP_32BIG_C(
                    0x3724299cU),
            };
            r_rsip_func100(Param_pe4_func100_005);
            r_rsip_func_sub016(0x81010120U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = S_RAM[0]; iLoop < 16U; iLoop = iLoop + 4U)
            {
                WR1_PROG(REG_1608H, 0x80840005U);
                r_rsip_func_sub001(0x03400011U);

                r_rsip_func_sub021(0x0000a4e0U, 0x00000004U, 0x0000a4a0U, 0x00000010U);

                static const uint32_t Param_pe4_func101_007[] =
                {
                    BSWAP_32BIG_C(0xca7f6c5fU), BSWAP_32BIG_C(0x39c0887bU), BSWAP_32BIG_C(0xf2d47a8dU), BSWAP_32BIG_C(
                        0x130345baU),
                };
                r_rsip_func101(Param_pe4_func101_007);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x380088e0U);
            r_rsip_func_sub011(0x00000010U);

            static const uint32_t Param_pe4_func101_008[] =
            {
                BSWAP_32BIG_C(0x8bd16bc7U), BSWAP_32BIG_C(0xe44563b4U), BSWAP_32BIG_C(0xa7af48c0U), BSWAP_32BIG_C(
                    0x1b76a111U),
            };
            r_rsip_func101(Param_pe4_func101_008);
        }

        r_rsip_func_sub009(0x000000e4U);

        static const uint32_t Param_pe4_func101_009[] =
        {
            BSWAP_32BIG_C(0x620e6034U), BSWAP_32BIG_C(0xcdf3d66fU), BSWAP_32BIG_C(0x2e3b67d8U), BSWAP_32BIG_C(
                0x5064eda9U),
        };
        r_rsip_func101(Param_pe4_func101_009);
        r_rsip_func103();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x000000e4U);

        static const uint32_t Param_pe4_func101_010[] =
        {
            BSWAP_32BIG_C(0x9a7280feU), BSWAP_32BIG_C(0xe857384eU), BSWAP_32BIG_C(0xecae6391U), BSWAP_32BIG_C(
                0x2879895bU),
        };
        r_rsip_func101(Param_pe4_func101_010);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e8U);

        r_rsip_func_sub009(0x000000e4U);

        static const uint32_t Param_pe4_func101_011[] =
        {
            BSWAP_32BIG_C(0xfd04afefU), BSWAP_32BIG_C(0x57c4948cU), BSWAP_32BIG_C(0x5a89c6c7U), BSWAP_32BIG_C(
                0x0366e3ffU),
        };
        r_rsip_func101(Param_pe4_func101_011);
        r_rsip_func044();

        static const uint32_t Param_pe4_func100_006[] =
        {
            BSWAP_32BIG_C(0x98253408U), BSWAP_32BIG_C(0xc926c1e6U), BSWAP_32BIG_C(0x63a4e685U), BSWAP_32BIG_C(
                0x3ff6c959U),
        };
        r_rsip_func100(Param_pe4_func100_006);
        WR1_PROG(REG_1600H, 0x000008a5U);
        r_rsip_func_sub027(0x40000100U, 0xe7009d07U, 0x81900005U);
        r_rsip_func_sub001(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

        static const uint32_t Param_pe4_func100_007[] =
        {
            BSWAP_32BIG_C(0x61a55db9U), BSWAP_32BIG_C(0x1114de6cU), BSWAP_32BIG_C(0x94af747eU), BSWAP_32BIG_C(
                0x9e7a06f6U),
        };
        r_rsip_func100(Param_pe4_func100_007);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7008d07U);
        r_rsip_func_sub001(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);

        static const uint32_t Param_pe4_func100_008[] =
        {
            BSWAP_32BIG_C(0x58b42610U), BSWAP_32BIG_C(0xf6aaac16U), BSWAP_32BIG_C(0x28d50316U), BSWAP_32BIG_C(
                0x09816a99U),
        };
        r_rsip_func100(Param_pe4_func100_008);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

        static const uint32_t Param_pe4_func100_009[] =
        {
            BSWAP_32BIG_C(0xd4c390a2U), BSWAP_32BIG_C(0xc0ebdba0U), BSWAP_32BIG_C(0x82a9d60cU), BSWAP_32BIG_C(
                0xe7e2777fU),
        };
        r_rsip_func100(Param_pe4_func100_009);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

        static const uint32_t Param_pe4_func102_002[] =
        {
            BSWAP_32BIG_C(0x3241b4c3U), BSWAP_32BIG_C(0x09fe92fcU), BSWAP_32BIG_C(0xe0e8694bU), BSWAP_32BIG_C(
                0xb704204cU),
        };
        r_rsip_func102(Param_pe4_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
