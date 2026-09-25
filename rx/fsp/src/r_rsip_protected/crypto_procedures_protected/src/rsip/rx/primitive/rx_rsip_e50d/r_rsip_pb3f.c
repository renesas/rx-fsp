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

rsip_ret_t r_rsip_pb3f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func420();

    static const uint32_t Param_pb3f_func100_001[] =
    {
        BSWAP_32BIG_C(0xa398fc1dU), BSWAP_32BIG_C(0x7cab1d82U), BSWAP_32BIG_C(0x907baeafU), BSWAP_32BIG_C(0xc15184fdU),
    };
    r_rsip_func100(Param_pb3f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb3f_func102_001[] =
        {
            BSWAP_32BIG_C(0xf248f40bU), BSWAP_32BIG_C(0x5f2a895dU), BSWAP_32BIG_C(0x237ec1b8U), BSWAP_32BIG_C(
                0x8c4e31d0U),
        };
        r_rsip_func102(Param_pb3f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pb3f_func100_002[] =
        {
            BSWAP_32BIG_C(0x3d17a9dbU), BSWAP_32BIG_C(0xd05e477bU), BSWAP_32BIG_C(0xca9b54a7U), BSWAP_32BIG_C(
                0xa573b2bcU),
        };
        r_rsip_func100(Param_pb3f_func100_002);
        r_rsip_func_sub016(0x810103c0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_pb3f_func100_003[] =
        {
            BSWAP_32BIG_C(0xa59b5849U), BSWAP_32BIG_C(0x72f4e12aU), BSWAP_32BIG_C(0x4eb4e036U), BSWAP_32BIG_C(
                0x846a2685U),
        };
        r_rsip_func100(Param_pb3f_func100_003);

        r_rsip_func_sub025(0x00020061U, 0x00000020U, 0x0d008906U);
        WR1_PROG(REG_1408H, 0x000c1000U);

        iLoop = 0U;
        if (S_RAM[0] >= 4)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[0]);
            for (iLoop = 4; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
        }

        r_rsip_func214();

        r_rsip_func421();

        static const uint32_t Param_pb3f_func100_004[] =
        {
            BSWAP_32BIG_C(0x1e5b35c9U), BSWAP_32BIG_C(0x0844007eU), BSWAP_32BIG_C(0x46b7807eU), BSWAP_32BIG_C(
                0x101e113fU),
        };
        r_rsip_func100(Param_pb3f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x00000020U, 0x0d008905U);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub009(0x000000b3U);

            static const uint32_t Param_pb3f_func101_001[] =
            {
                BSWAP_32BIG_C(0x185030b7U), BSWAP_32BIG_C(0x3078030aU), BSWAP_32BIG_C(0xd57acba7U), BSWAP_32BIG_C(
                    0x8c7d3f1fU),
            };
            r_rsip_func101(Param_pb3f_func101_001);
            r_rsip_func422(InData_Text, iLoop);

            static const uint32_t Param_pb3f_func100_005[] =
            {
                BSWAP_32BIG_C(0x03168ff3U), BSWAP_32BIG_C(0x90a5e1e4U), BSWAP_32BIG_C(0x08f40eb1U), BSWAP_32BIG_C(
                    0xee0c69a9U),
            };
            r_rsip_func100(Param_pb3f_func100_005);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x00000020U);
            WR1_PROG(REG_1824H, 0x0d008905U);
            WR1_PROG(REG_1608H, 0x81840007U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            r_rsip_func_sub009(0x000000b3U);

            static const uint32_t Param_pb3f_func101_002[] =
            {
                BSWAP_32BIG_C(0xe2f2039eU), BSWAP_32BIG_C(0x4810d5e0U), BSWAP_32BIG_C(0x273bb304U), BSWAP_32BIG_C(
                    0xb38c4881U),
            };
            r_rsip_func101(Param_pb3f_func101_002);
            r_rsip_func423(OutData_Text, iLoop);

            static const uint32_t Param_pb3f_func101_003[] =
            {
                BSWAP_32BIG_C(0x7ffafcaeU), BSWAP_32BIG_C(0xe0de7f08U), BSWAP_32BIG_C(0xff58d436U), BSWAP_32BIG_C(
                    0x1f52ea5fU),
            };
            r_rsip_func101(Param_pb3f_func101_003);
        }

        static const uint32_t Param_pb3f_func102_002[] =
        {
            BSWAP_32BIG_C(0xafea1a85U), BSWAP_32BIG_C(0xfdf3ef57U), BSWAP_32BIG_C(0x3705ef26U), BSWAP_32BIG_C(
                0x704ad16eU),
        };
        r_rsip_func102(Param_pb3f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
