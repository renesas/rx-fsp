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

rsip_ret_t r_rsip_p98f (const uint32_t InData_Text[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_MACLength[],
                        uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010140U);
    WR1_PROG(REG_1420H, InData_MACLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008940U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_1600H, 0x0000b7e0U);
    r_rsip_func_sub006(0x00000010U, 0x34202beaU, 0x00260000U);

    static const uint32_t Param_p98f_func100_001[] =
    {
        BSWAP_32BIG_C(0x082de046U), BSWAP_32BIG_C(0xd9766a73U), BSWAP_32BIG_C(0x458a645cU), BSWAP_32BIG_C(0x53591fd1U),
    };
    r_rsip_func100(Param_p98f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p98f_func102_001[] =
        {
            BSWAP_32BIG_C(0x1b51caadU), BSWAP_32BIG_C(0x0bf05558U), BSWAP_32BIG_C(0xc4182a19U), BSWAP_32BIG_C(
                0x0d0e56fbU),
        };
        r_rsip_func102(Param_p98f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010000U);
        WR1_PROG(REG_1420H, InData_TextLen[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x00008c00U, 0x0000000fU, 0x38008800U, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        static const uint32_t Param_p98f_func100_002[] =
        {
            BSWAP_32BIG_C(0x1a4fa9e1U), BSWAP_32BIG_C(0x6a2b4b20U), BSWAP_32BIG_C(0xba6b8fe7U), BSWAP_32BIG_C(
                0x60a0d973U),
        };
        r_rsip_func100(Param_p98f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000003c1U, 0x07000d05U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            r_rsip_func_sub023(0x0000b420U, 0x00000080U, 0x80840001U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub021(0x00000821U, 0x0000a400U, 0x00000080U, 0x0000b7e0U);
            WR1_PROG(REG_1600H, 0x00000080U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub022(0x3c002be0U, 0x12003c3fU, 0x00002fe0U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p98f_func100_003[] =
            {
                BSWAP_32BIG_C(0xad321e18U), BSWAP_32BIG_C(0x3659fd75U), BSWAP_32BIG_C(0xca714a37U), BSWAP_32BIG_C(
                    0x7086bd4bU),
            };
            r_rsip_func100(Param_p98f_func100_003);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1600H, 0x00000080U);
            r_rsip_func_sub016(0x81840001U, 0x00005012U);
            RD1_ADDR(REG_1420H, &OutData_Text[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[2]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[3]);

            WR1_PROG(REG_1824H, 0x0e100405U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_p98f_func101_001[] =
            {
                BSWAP_32BIG_C(0x3320caaaU), BSWAP_32BIG_C(0x6afdaabaU), BSWAP_32BIG_C(0x7e392229U), BSWAP_32BIG_C(
                    0xb551edffU),
            };
            r_rsip_func101(Param_p98f_func101_001);
        }
        else
        {
            static const uint32_t Param_p98f_func101_002[] =
            {
                BSWAP_32BIG_C(0x1438aac3U), BSWAP_32BIG_C(0x888dee49U), BSWAP_32BIG_C(0x21a56173U), BSWAP_32BIG_C(
                    0x1da23248U),
            };
            r_rsip_func101(Param_p98f_func101_002);
        }

        r_rsip_func_sub020(0x000000a1U, 0x0c100104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1824H, 0x07200d05U);
        r_rsip_func_sub001(0x00410011U);

        r_rsip_func_sub023(0x0000b420U, 0x00000080U, 0x80840001U);
        r_rsip_func_sub001(0x03410011U);

        r_rsip_func_sub021(0x0000a540U, 0x00000080U, 0x0000b7e0U, 0x00000080U);

        WR1_PROG(REG_1600H, 0x00000821U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub022(0x3c002beaU, 0x12003c3fU, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub020(0x000003c1U, 0x08000055U);
        WR4_ADDR(REG_1420H, &InData_MAC[0]);

        WR1_PROG(REG_1824H, 0x9c100005U);
        r_rsip_func_sub023(0x0000b420U, 0x00000080U, 0x81840001U);
        r_rsip_func_sub001(0x00490011U);
        WR1_PROG(REG_1824H, 0x00000000U);

        static const uint32_t Param_p98f_func100_004[] =
        {
            BSWAP_32BIG_C(0x3494b474U), BSWAP_32BIG_C(0x1be882b1U), BSWAP_32BIG_C(0x3473e4a5U), BSWAP_32BIG_C(
                0x5191b033U),
        };
        r_rsip_func100(Param_p98f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p98f_func102_002[] =
            {
                BSWAP_32BIG_C(0x30bef0a0U), BSWAP_32BIG_C(0xed4592e7U), BSWAP_32BIG_C(0x56c7b0d8U), BSWAP_32BIG_C(
                    0x3e5c2f29U),
            };
            r_rsip_func102(Param_p98f_func102_002);

            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p98f_func102_003[] =
            {
                BSWAP_32BIG_C(0x8f711d76U), BSWAP_32BIG_C(0x416acaf3U), BSWAP_32BIG_C(0xb19b7fe1U), BSWAP_32BIG_C(
                    0xeab96462U),
            };
            r_rsip_func102(Param_p98f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
