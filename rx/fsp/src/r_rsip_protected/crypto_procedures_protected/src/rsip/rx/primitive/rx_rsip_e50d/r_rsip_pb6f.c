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

rsip_ret_t r_rsip_pb6f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func420();

    static const uint32_t Param_pb6f_func100_001[] =
    {
        BSWAP_32BIG_C(0x3dc00585U), BSWAP_32BIG_C(0x6eb20c87U), BSWAP_32BIG_C(0xb8cb2f86U), BSWAP_32BIG_C(0xc28fd712U),
    };
    r_rsip_func100(Param_pb6f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb6f_func102_001[] =
        {
            BSWAP_32BIG_C(0xc4897220U), BSWAP_32BIG_C(0x622b4ce2U), BSWAP_32BIG_C(0x002acdd4U), BSWAP_32BIG_C(
                0x5aaf66c7U),
        };
        r_rsip_func102(Param_pb6f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pb6f_func100_002[] =
        {
            BSWAP_32BIG_C(0x308ef132U), BSWAP_32BIG_C(0x0a42c1d2U), BSWAP_32BIG_C(0x290865bfU), BSWAP_32BIG_C(
                0x10615ce5U),
        };
        r_rsip_func100(Param_pb6f_func100_002);
        r_rsip_func_sub016(0x810103c0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_pb6f_func100_003[] =
        {
            BSWAP_32BIG_C(0x7cadafeeU), BSWAP_32BIG_C(0x54759c1aU), BSWAP_32BIG_C(0x34a4fc38U), BSWAP_32BIG_C(
                0xede17bb5U),
        };
        r_rsip_func100(Param_pb6f_func100_003);

        r_rsip_func_sub025(0x00020061U, 0x00000020U, 0x0d00890eU);
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

        static const uint32_t Param_pb6f_func100_004[] =
        {
            BSWAP_32BIG_C(0xa0290d8aU), BSWAP_32BIG_C(0x4b41b391U), BSWAP_32BIG_C(0x0a2380e9U), BSWAP_32BIG_C(
                0xae407861U),
        };
        r_rsip_func100(Param_pb6f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040140U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub019(0x000000a1U, 0x00000020U, 0x0d00880cU);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub019(0x000003c1U, 0x00000020U, 0x0d00890dU);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub009(0x000000b6U);

            static const uint32_t Param_pb6f_func101_001[] =
            {
                BSWAP_32BIG_C(0x063df304U), BSWAP_32BIG_C(0xbf3e37baU), BSWAP_32BIG_C(0x166efca1U), BSWAP_32BIG_C(
                    0x3df59c5dU),
            };
            r_rsip_func101(Param_pb6f_func101_001);
            r_rsip_func422(InData_Text, iLoop);

            static const uint32_t Param_pb6f_func100_005[] =
            {
                BSWAP_32BIG_C(0x0123ef27U), BSWAP_32BIG_C(0xbe76b2d5U), BSWAP_32BIG_C(0x372066a7U), BSWAP_32BIG_C(
                    0x334d7eabU),
            };
            r_rsip_func100(Param_pb6f_func100_005);
            WR1_PROG(REG_1824H, 0x08000045U);
            WR1_PROG(REG_1608H, 0x81040140U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x00000020U);
            WR1_PROG(REG_1824H, 0x0d00890dU);
            WR1_PROG(REG_1608H, 0x81840007U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            r_rsip_func_sub009(0x000000b6U);

            static const uint32_t Param_pb6f_func101_002[] =
            {
                BSWAP_32BIG_C(0xf7c400ceU), BSWAP_32BIG_C(0xf3aa8949U), BSWAP_32BIG_C(0x56aeed04U), BSWAP_32BIG_C(
                    0xfdc684c6U),
            };
            r_rsip_func101(Param_pb6f_func101_002);
            r_rsip_func423(OutData_Text, iLoop);

            static const uint32_t Param_pb6f_func101_003[] =
            {
                BSWAP_32BIG_C(0xf640f37bU), BSWAP_32BIG_C(0xfa772c8dU), BSWAP_32BIG_C(0x2688dfa7U), BSWAP_32BIG_C(
                    0x5572cfc0U),
            };
            r_rsip_func101(Param_pb6f_func101_003);
        }

        static const uint32_t Param_pb6f_func102_002[] =
        {
            BSWAP_32BIG_C(0xf0fd46e3U), BSWAP_32BIG_C(0x64dc414fU), BSWAP_32BIG_C(0xbf9b8efcU), BSWAP_32BIG_C(
                0x09d15fc6U),
        };
        r_rsip_func102(Param_pb6f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
