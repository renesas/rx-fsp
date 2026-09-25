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

rsip_ret_t r_rsip_p44f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
    {
        r_rsip_func_sub019(0x000000a1U, 0x40000000U, 0x4a008104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_001[] =
        {
            BSWAP_32BIG_C(0x42bc8a46U), BSWAP_32BIG_C(0xf2092032U), BSWAP_32BIG_C(0x06a59f1cU), BSWAP_32BIG_C(
                0xa4a8f618U),
        };
        r_rsip_func101(Param_p44f_func101_001);
    }
    else
    {
        r_rsip_func_sub019(0x000000a1U, 0x40000000U, 0x5a008104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_002[] =
        {
            BSWAP_32BIG_C(0xfb5f1cf6U), BSWAP_32BIG_C(0xb62ee2acU), BSWAP_32BIG_C(0x87375a76U), BSWAP_32BIG_C(
                0x299ad8f4U),
        };
        r_rsip_func101(Param_p44f_func101_002);
    }

    WR1_PROG(REG_1824H, 0x0c000045U);
    r_rsip_func_sub001(0x00410011U);

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
    {
        static const uint32_t Param_p44f_func100_001[] =
        {
            BSWAP_32BIG_C(0x16c0d1e5U), BSWAP_32BIG_C(0xf07893c7U), BSWAP_32BIG_C(0x0b29f529U), BSWAP_32BIG_C(
                0xbd1155e4U),
        };
        r_rsip_func100(Param_p44f_func100_001);
        r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0e008505U);
        WR4_ADDR(REG_1420H, &InData_Text[0]);

        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_DataT[0]);

        static const uint32_t Param_p44f_func102_001[] =
        {
            BSWAP_32BIG_C(0x95c3bac8U), BSWAP_32BIG_C(0x77630e4cU), BSWAP_32BIG_C(0x97aca87fU), BSWAP_32BIG_C(
                0xf3caa013U),
        };
        r_rsip_func102(Param_p44f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010040U);
        WR1_PROG(REG_1420H, InData_DataTLen[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub006(0x3420a840U, 0x00000010U, 0x00260000U);

        WR1_PROG(REG_1600H, 0x0000b460U);
        r_rsip_func_sub006(0x00000080U, 0x34202862U, 0x00260000U);

        static const uint32_t Param_p44f_func100_002[] =
        {
            BSWAP_32BIG_C(0x49ae6194U), BSWAP_32BIG_C(0x3cffa5a2U), BSWAP_32BIG_C(0xa1694672U), BSWAP_32BIG_C(
                0x3694fb34U),
        };
        r_rsip_func100(Param_p44f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p44f_func102_002[] =
            {
                BSWAP_32BIG_C(0xa28156bfU), BSWAP_32BIG_C(0x3e67cc38U), BSWAP_32BIG_C(0x177f7979U), BSWAP_32BIG_C(
                    0x5337eb25U),
            };
            r_rsip_func102(Param_p44f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0e008505U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x80840001U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub021(0x000034e2U, 0x000568e7U, 0x00026ce7U, 0x00003827U);

            r_rsip_func_sub021(0x0000b4c0U, 0x00000020U, 0x00003402U, 0x00008c00U);
            r_rsip_func_sub021(0x0000001fU, 0x000028c0U, 0x00008cc0U, 0x0000001fU);

            r_rsip_func_sub021(0x00004406U, 0x00007421U, 0x00007821U, 0x00003c27U);

            r_rsip_func_sub021(0x000034c2U, 0x0000a4c0U, 0x0000001fU, 0x000568c6U);

            r_rsip_func_sub022(0x000034e6U, 0x00026ce7U, 0x00000821U);

            for (iLoop = 0U; iLoop < 4U; iLoop++)
            {
                r_rsip_func_sub021(0x3420a8e0U, 0x0000000dU, 0x10003c27U, 0x1000a4e0U);
                WR1_PROG(REG_1600H, 0x00000004U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1824H, 0x08000045U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub020(0x000003c1U, 0x9c000005U);
            WR4_ADDR(REG_1420H, &InData_DataT[0]);

            static const uint32_t Param_p44f_func100_003[] =
            {
                BSWAP_32BIG_C(0x3e346926U), BSWAP_32BIG_C(0xd189247eU), BSWAP_32BIG_C(0x8afcc9ddU), BSWAP_32BIG_C(
                    0x4c75aa0cU),
            };
            r_rsip_func100(Param_p44f_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p44f_func102_003[] =
                {
                    BSWAP_32BIG_C(0xb09ece24U), BSWAP_32BIG_C(0x46c6b82eU), BSWAP_32BIG_C(0xe085d41fU), BSWAP_32BIG_C(
                        0xd6f1127fU),
                };
                r_rsip_func102(Param_p44f_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_AUTH_FAIL;
            }
            else
            {
                static const uint32_t Param_p44f_func102_004[] =
                {
                    BSWAP_32BIG_C(0x16c8667aU), BSWAP_32BIG_C(0x465604c1U), BSWAP_32BIG_C(0x5ed2468aU), BSWAP_32BIG_C(
                        0x5c386f83U),
                };
                r_rsip_func102(Param_p44f_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
