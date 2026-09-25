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

rsip_ret_t r_rsip_pb9f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func420();

    static const uint32_t Param_pb9f_func100_001[] =
    {
        BSWAP_32BIG_C(0x1cfac8dcU), BSWAP_32BIG_C(0x1860f561U), BSWAP_32BIG_C(0x3496b6dcU), BSWAP_32BIG_C(0x9fe7e3dcU),
    };
    r_rsip_func100(Param_pb9f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb9f_func102_001[] =
        {
            BSWAP_32BIG_C(0x3d6c8463U), BSWAP_32BIG_C(0x0204605bU), BSWAP_32BIG_C(0x3376f114U), BSWAP_32BIG_C(
                0x41539d62U),
        };
        r_rsip_func102(Param_pb9f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pb9f_func100_002[] =
        {
            BSWAP_32BIG_C(0xbe90a218U), BSWAP_32BIG_C(0x3a46772fU), BSWAP_32BIG_C(0x029d8fa9U), BSWAP_32BIG_C(
                0x2b068666U),
        };
        r_rsip_func100(Param_pb9f_func100_002);
        r_rsip_func_sub016(0x810103c0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_pb9f_func100_003[] =
        {
            BSWAP_32BIG_C(0xb365b897U), BSWAP_32BIG_C(0x04b0c5c0U), BSWAP_32BIG_C(0x33f6770aU), BSWAP_32BIG_C(
                0xf2dc11cdU),
        };
        r_rsip_func100(Param_pb9f_func100_003);

        r_rsip_func_sub025(0x00020061U, 0x40000020U, 0x0d008906U);
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

        static const uint32_t Param_pb9f_func100_004[] =
        {
            BSWAP_32BIG_C(0x52c76cfcU), BSWAP_32BIG_C(0xf199f7b1U), BSWAP_32BIG_C(0x270a41d0U), BSWAP_32BIG_C(
                0x64b096a4U),
        };
        r_rsip_func100(Param_pb9f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x40000020U, 0x0d008905U);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub009(0x000000b9U);

            static const uint32_t Param_pb9f_func101_001[] =
            {
                BSWAP_32BIG_C(0xcee4ffb6U), BSWAP_32BIG_C(0x1bca1caeU), BSWAP_32BIG_C(0x5bbbc936U), BSWAP_32BIG_C(
                    0x97f7627aU),
            };
            r_rsip_func101(Param_pb9f_func101_001);
            r_rsip_func422(InData_Text, iLoop);

            static const uint32_t Param_pb9f_func100_005[] =
            {
                BSWAP_32BIG_C(0xfff36509U), BSWAP_32BIG_C(0x02f4bc31U), BSWAP_32BIG_C(0x13d3fbafU), BSWAP_32BIG_C(
                    0xb9c24afeU),
            };
            r_rsip_func100(Param_pb9f_func100_005);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x40000020U);
            WR1_PROG(REG_1824H, 0x0d008905U);
            WR1_PROG(REG_1608H, 0x81840007U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            r_rsip_func_sub009(0x000000b9U);

            static const uint32_t Param_pb9f_func101_002[] =
            {
                BSWAP_32BIG_C(0x04877e15U), BSWAP_32BIG_C(0xdaa08a30U), BSWAP_32BIG_C(0x91153d2aU), BSWAP_32BIG_C(
                    0xf8b3f993U),
            };
            r_rsip_func101(Param_pb9f_func101_002);
            r_rsip_func423(OutData_Text, iLoop);

            static const uint32_t Param_pb9f_func101_003[] =
            {
                BSWAP_32BIG_C(0xcff4281fU), BSWAP_32BIG_C(0x68307f7dU), BSWAP_32BIG_C(0x6de78278U), BSWAP_32BIG_C(
                    0xd2cca4a6U),
            };
            r_rsip_func101(Param_pb9f_func101_003);
        }

        static const uint32_t Param_pb9f_func102_002[] =
        {
            BSWAP_32BIG_C(0x3cbbd1cbU), BSWAP_32BIG_C(0xf7f53e8fU), BSWAP_32BIG_C(0x8a55b7c0U), BSWAP_32BIG_C(
                0x27ceaf3bU),
        };
        r_rsip_func102(Param_pb9f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
