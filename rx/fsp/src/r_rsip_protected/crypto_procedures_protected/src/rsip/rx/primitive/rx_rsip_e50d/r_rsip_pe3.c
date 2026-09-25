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

rsip_ret_t r_rsip_pe3 (const uint32_t InData_HashType[],
                       const uint32_t InData_CurveType[],
                       const uint32_t InData_EncSecret[],
                       uint32_t       OutData_EncMsg[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e30001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a880U, 0x00000003U, 0x2000b480U, 0x00000002U);

    WR1_PROG(REG_1600H, 0x000009ceU);

    static const uint32_t Param_pe3_func100_001[] =
    {
        BSWAP_32BIG_C(0xedaa33fcU), BSWAP_32BIG_C(0xd53effcaU), BSWAP_32BIG_C(0x77032981U), BSWAP_32BIG_C(0x6caa3948U),
    };
    r_rsip_func100(Param_pe3_func100_001);
    r_rsip_func_sub014(0x00007c04U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x01fdb192U);

        r_rsip_func_sub003(0x800100c0U, 0x00000008U);

        static const uint32_t Param_pe3_func101_001[] =
        {
            BSWAP_32BIG_C(0x73a1fa73U), BSWAP_32BIG_C(0x37e53466U), BSWAP_32BIG_C(0x792f75beU), BSWAP_32BIG_C(
                0x9054f961U),
        };
        r_rsip_func101(Param_pe3_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x01245edbU);

        r_rsip_func_sub003(0x800100c0U, 0x0000000cU);

        static const uint32_t Param_pe3_func101_002[] =
        {
            BSWAP_32BIG_C(0x9514eb0dU), BSWAP_32BIG_C(0x4e5cb1aeU), BSWAP_32BIG_C(0xa0e2451dU), BSWAP_32BIG_C(
                0xa8624b33U),
        };
        r_rsip_func101(Param_pe3_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub010(0x000000c7U, 0x800101c0U);
        WR1_PROG(REG_1420H, InData_CurveType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x30000dceU, 0x00030020U, 0x0000b4a0U, 0x0161bb7bU);

        r_rsip_func_sub021(0x0000b4c0U, 0x00000014U, 0x00000060U, 0x0000b4a0U);
        r_rsip_func_sub021(0x01dcc5c6U, 0x0000b4c0U, 0x00000010U, 0x00000080U);

        static const uint32_t Param_pe3_func101_003[] =
        {
            BSWAP_32BIG_C(0xc99c40a2U), BSWAP_32BIG_C(0x5b83026bU), BSWAP_32BIG_C(0x9061bb98U), BSWAP_32BIG_C(
                0xc2ea5636U),
        };
        r_rsip_func101(Param_pe3_func101_003);
    }

    r_rsip_func_sub009(0x000000e3U);

    static const uint32_t Param_pe3_func101_004[] =
    {
        BSWAP_32BIG_C(0x51dc22ceU), BSWAP_32BIG_C(0xb84586e5U), BSWAP_32BIG_C(0xa9c0c6e3U), BSWAP_32BIG_C(0xb7696e6bU),
    };
    r_rsip_func101(Param_pe3_func101_004);
    r_rsip_func407(InData_EncSecret);

    static const uint32_t Param_pe3_func100_002[] =
    {
        BSWAP_32BIG_C(0x531153faU), BSWAP_32BIG_C(0x801c1f49U), BSWAP_32BIG_C(0xa25fa14eU), BSWAP_32BIG_C(0x06a19fffU),
    };
    r_rsip_func100(Param_pe3_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe3_func102_001[] =
        {
            BSWAP_32BIG_C(0xff2626feU), BSWAP_32BIG_C(0x1bb4a8ecU), BSWAP_32BIG_C(0x26e33ef9U), BSWAP_32BIG_C(
                0x43338e58U),
        };
        r_rsip_func102(Param_pe3_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub021(0x00000800U, 0x30008880U, 0x00000002U, 0x00030020U);
        r_rsip_func_sub021(0x38000dceU, 0x10002c00U, 0x00000080U, 0x38008800U);
        r_rsip_func_sub017(0x00000001U, 0x00260000U);

        static const uint32_t Param_pe3_func100_003[] =
        {
            BSWAP_32BIG_C(0x7c82d21dU), BSWAP_32BIG_C(0xa3b2a229U), BSWAP_32BIG_C(0x67c28792U), BSWAP_32BIG_C(
                0x87b146f1U),
        };
        r_rsip_func100(Param_pe3_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func408();

            static const uint32_t Param_pe3_func101_005[] =
            {
                BSWAP_32BIG_C(0xe6c4e61fU), BSWAP_32BIG_C(0x21602266U), BSWAP_32BIG_C(0x6217f0adU), BSWAP_32BIG_C(
                    0x89d6bb72U),
            };
            r_rsip_func101(Param_pe3_func101_005);
        }

        r_rsip_func_sub009(0x000000e3U);

        static const uint32_t Param_pe3_func101_006[] =
        {
            BSWAP_32BIG_C(0x0a825265U), BSWAP_32BIG_C(0xe36c21c4U), BSWAP_32BIG_C(0x1e514ac9U), BSWAP_32BIG_C(
                0x6a6a0572U),
        };
        r_rsip_func101(Param_pe3_func101_006);
        r_rsip_func103();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x000000e3U);

        static const uint32_t Param_pe3_func101_007[] =
        {
            BSWAP_32BIG_C(0x7bb07dbaU), BSWAP_32BIG_C(0x1305d354U), BSWAP_32BIG_C(0x15f3eaf3U), BSWAP_32BIG_C(
                0x3296133dU),
        };
        r_rsip_func101(Param_pe3_func101_007);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x01c80eb2U);

        r_rsip_func_sub009(0x000000e3U);

        static const uint32_t Param_pe3_func101_008[] =
        {
            BSWAP_32BIG_C(0xcc27a42bU), BSWAP_32BIG_C(0x01c81f6bU), BSWAP_32BIG_C(0x4d73ae35U), BSWAP_32BIG_C(
                0xde1a3278U),
        };
        r_rsip_func101(Param_pe3_func101_008);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1600H, 0x000008a5U);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
        {
            static const uint32_t Param_pe3_func100_004[] =
            {
                BSWAP_32BIG_C(0xe2f11a86U), BSWAP_32BIG_C(0x952ca299U), BSWAP_32BIG_C(0x44e6cffaU), BSWAP_32BIG_C(
                    0x50dbe907U),
            };
            r_rsip_func100(Param_pe3_func100_004);
            r_rsip_func_sub027(0x40000000U, 0xe7008d05U, 0x81840005U);
            r_rsip_func_sub001(0x00890011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_EncMsg[1 + iLoop]);

            r_rsip_func_sub021(0x0000a4a0U, 0x00000010U, 0x0000a4e0U, 0x00000004U);

            static const uint32_t Param_pe3_func101_009[] =
            {
                BSWAP_32BIG_C(0x6da962c3U), BSWAP_32BIG_C(0x4e2e0fc9U), BSWAP_32BIG_C(0x16ea37b7U), BSWAP_32BIG_C(
                    0x76bc41ebU),
            };
            r_rsip_func101(Param_pe3_func101_009);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x380008c7U);

        static const uint32_t Param_pe3_func100_005[] =
        {
            BSWAP_32BIG_C(0xf81657f2U), BSWAP_32BIG_C(0x7ea9ce7bU), BSWAP_32BIG_C(0xcde60287U), BSWAP_32BIG_C(
                0x1354b462U),
        };
        r_rsip_func100(Param_pe3_func100_005);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_EncMsg[1 + iLoop]);

        static const uint32_t Param_pe3_func100_006[] =
        {
            BSWAP_32BIG_C(0x44ce5172U), BSWAP_32BIG_C(0xd8d29065U), BSWAP_32BIG_C(0xc2d43f14U), BSWAP_32BIG_C(
                0x536dd4b2U),
        };
        r_rsip_func100(Param_pe3_func100_006);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_EncMsg[0]);

        static const uint32_t Param_pe3_func102_002[] =
        {
            BSWAP_32BIG_C(0x6a2f324dU), BSWAP_32BIG_C(0xfd4fbb04U), BSWAP_32BIG_C(0x2cea8736U), BSWAP_32BIG_C(
                0x6ccde901U),
        };
        r_rsip_func102(Param_pe3_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
