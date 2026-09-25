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

rsip_ret_t r_rsip_p87f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p87f_func100_001[] =
    {
        BSWAP_32BIG_C(0xc4c0c80eU), BSWAP_32BIG_C(0x1a246d5eU), BSWAP_32BIG_C(0x1f4b6bc6U), BSWAP_32BIG_C(0xd2d26782U),
    };
    r_rsip_func100(Param_p87f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p87f_func102_001[] =
        {
            BSWAP_32BIG_C(0xde5556a8U), BSWAP_32BIG_C(0x0314c112U), BSWAP_32BIG_C(0x720b8862U), BSWAP_32BIG_C(
                0x797aba87U),
        };
        r_rsip_func102(Param_p87f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
        {
            r_rsip_func_sub019(0x000000a1U, 0x40000010U, 0x4a008104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            static const uint32_t Param_p87f_func101_001[] =
            {
                BSWAP_32BIG_C(0x5490795eU), BSWAP_32BIG_C(0xbbc1904eU), BSWAP_32BIG_C(0x2eb60175U), BSWAP_32BIG_C(
                    0x188c8202U),
            };
            r_rsip_func101(Param_p87f_func101_001);
        }
        else
        {
            r_rsip_func_sub019(0x000000a1U, 0x40000010U, 0x5a008104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            static const uint32_t Param_p87f_func101_002[] =
            {
                BSWAP_32BIG_C(0xe4e12df7U), BSWAP_32BIG_C(0x029a7769U), BSWAP_32BIG_C(0x1c355de0U), BSWAP_32BIG_C(
                    0xd354aa65U),
            };
            r_rsip_func101(Param_p87f_func101_002);
        }

        WR1_PROG(REG_1824H, 0x0c000045U);
        r_rsip_func_sub001(0x00410011U);

        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
        {
            static const uint32_t Param_p87f_func100_002[] =
            {
                BSWAP_32BIG_C(0x76a786d3U), BSWAP_32BIG_C(0xc243073dU), BSWAP_32BIG_C(0x34c28882U), BSWAP_32BIG_C(
                    0x569b26d0U),
            };
            r_rsip_func100(Param_p87f_func100_002);
            r_rsip_func_sub019(0x000003c1U, 0x40000010U, 0x0e008505U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_DataT[0]);

            static const uint32_t Param_p87f_func102_002[] =
            {
                BSWAP_32BIG_C(0xb3374d7fU), BSWAP_32BIG_C(0xa12372adU), BSWAP_32BIG_C(0xb3599ef9U), BSWAP_32BIG_C(
                    0xac440107U),
            };
            r_rsip_func102(Param_p87f_func102_002);
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

            static const uint32_t Param_p87f_func100_003[] =
            {
                BSWAP_32BIG_C(0x5711bd4eU), BSWAP_32BIG_C(0xe95ecf87U), BSWAP_32BIG_C(0x769a8f4cU), BSWAP_32BIG_C(
                    0x1e5b4c00U),
            };
            r_rsip_func100(Param_p87f_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p87f_func102_003[] =
                {
                    BSWAP_32BIG_C(0xd596e74fU), BSWAP_32BIG_C(0x35735616U), BSWAP_32BIG_C(0xa0f59b44U), BSWAP_32BIG_C(
                        0xb27539bfU),
                };
                r_rsip_func102(Param_p87f_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub019(0x000003c1U, 0x40000010U, 0x0e008505U);
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

                static const uint32_t Param_p87f_func100_004[] =
                {
                    BSWAP_32BIG_C(0xd14e5f11U), BSWAP_32BIG_C(0xf18ad9fbU), BSWAP_32BIG_C(0x9241bae6U), BSWAP_32BIG_C(
                        0x7da91530U),
                };
                r_rsip_func100(Param_p87f_func100_004);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p87f_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xf48b59e5U), BSWAP_32BIG_C(0x9fd622d3U), BSWAP_32BIG_C(0x630a43fdU),
                        BSWAP_32BIG_C(0x2d9b0e59U),
                    };
                    r_rsip_func102(Param_p87f_func102_004);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_AUTH_FAIL;
                }
                else
                {
                    static const uint32_t Param_p87f_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x83192a03U), BSWAP_32BIG_C(0x4618c66fU), BSWAP_32BIG_C(0xea0af438U),
                        BSWAP_32BIG_C(0xb7d47e96U),
                    };
                    r_rsip_func102(Param_p87f_func102_005);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
