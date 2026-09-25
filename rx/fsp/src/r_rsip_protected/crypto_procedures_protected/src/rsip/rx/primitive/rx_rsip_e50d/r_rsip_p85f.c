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

rsip_ret_t r_rsip_p85f (const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000001c7U, 0x80020100U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_TextLen[1]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x0000b580U, 0x0000007FU, 0x0000b5a0U, 0xFFFFFF00U);
    r_rsip_func_sub006(0x0c0029a9U, 0x04a02988U, 0x00260000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010140U);
    WR1_PROG(REG_1420H, InData_DataTLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008940U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_1600H, 0x0000b7e0U);
    r_rsip_func_sub006(0x00000010U, 0x34202beaU, 0x00260000U);

    static const uint32_t Param_p85f_func100_001[] =
    {
        BSWAP_32BIG_C(0x2a03bda2U), BSWAP_32BIG_C(0x8829309fU), BSWAP_32BIG_C(0x1fba6167U), BSWAP_32BIG_C(0x9661d416U),
    };
    r_rsip_func100(Param_p85f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p85f_func102_001[] =
        {
            BSWAP_32BIG_C(0x235d7b70U), BSWAP_32BIG_C(0xc6919fcbU), BSWAP_32BIG_C(0x0b6d2358U), BSWAP_32BIG_C(
                0x86da8d34U),
        };
        r_rsip_func102(Param_p85f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub021(0x00003409U, 0x00036800U, 0x08008c00U, 0x0000000fU);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);

        static const uint32_t Param_p85f_func100_002[] =
        {
            BSWAP_32BIG_C(0x414236d9U), BSWAP_32BIG_C(0x61b30f63U), BSWAP_32BIG_C(0x1acf520bU), BSWAP_32BIG_C(
                0xbef1c157U),
        };
        r_rsip_func100(Param_p85f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p85f_func100_003[] =
            {
                BSWAP_32BIG_C(0xf77b541cU), BSWAP_32BIG_C(0x62eb738fU), BSWAP_32BIG_C(0xbeb97431U), BSWAP_32BIG_C(
                    0x997ac343U),
            };
            r_rsip_func100(Param_p85f_func100_003);

            r_rsip_func_sub019(0x000003c1U, 0x40018030U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x80840001U);
            r_rsip_func_sub001(0x03410011U);

            WR1_PROG(REG_1600H, 0x00000bffU);
            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub022(0x3c002be0U, 0x12003c3fU, 0x00002fe0U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x00000821U);
            r_rsip_func_sub016(0x81840001U, 0x00005012U);
            RD1_ADDR(REG_1420H, &OutData_Text[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[2]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[3]);

            static const uint32_t Param_p85f_func101_001[] =
            {
                BSWAP_32BIG_C(0xc045876bU), BSWAP_32BIG_C(0xc3048a1bU), BSWAP_32BIG_C(0xeaba75ddU), BSWAP_32BIG_C(
                    0x3ea8e1baU),
            };
            r_rsip_func101(Param_p85f_func101_001);
        }

        r_rsip_func_sub019(0x000001c1U, 0x00018000U, 0x0a008005U);
        WR2_ADDR(REG_1420H, &InData_DataALen[0]);

        WR1_PROG(REG_1608H, 0x81020100U);
        r_rsip_func_sub001(0x00490009U);

        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1608H, 0x81040080U);
        r_rsip_func_sub001(0x00490011U);

        WR1_PROG(REG_182CH, 0x00400000U);
        r_rsip_func_sub020(0x000000a1U, 0x0c008104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_182CH, 0x40000030U);
        WR1_PROG(REG_1824H, 0x07008d05U);
        r_rsip_func_sub001(0x00410011U);

        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x80840001U);
        r_rsip_func_sub001(0x03410011U);

        WR1_PROG(REG_1600H, 0x00000bffU);
        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub022(0x3c002beaU, 0x12003c3fU, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub020(0x000003c1U, 0x08000055U);
        WR4_ADDR(REG_1420H, &InData_DataT[0]);

        WR1_PROG(REG_1824H, 0x9c100005U);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x81840001U);
        r_rsip_func_sub001(0x00490011U);
        WR1_PROG(REG_1824H, 0x00000000U);

        static const uint32_t Param_p85f_func100_004[] =
        {
            BSWAP_32BIG_C(0x9e85dcacU), BSWAP_32BIG_C(0xef84a172U), BSWAP_32BIG_C(0x0bd768c1U), BSWAP_32BIG_C(
                0x7f684a04U),
        };
        r_rsip_func100(Param_p85f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p85f_func102_002[] =
            {
                BSWAP_32BIG_C(0x0ca182c8U), BSWAP_32BIG_C(0x990276fbU), BSWAP_32BIG_C(0x30e4b49aU), BSWAP_32BIG_C(
                    0x0d4cea2fU),
            };
            r_rsip_func102(Param_p85f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p85f_func102_003[] =
            {
                BSWAP_32BIG_C(0xb9866627U), BSWAP_32BIG_C(0x618aaa02U), BSWAP_32BIG_C(0x7b1f510eU), BSWAP_32BIG_C(
                    0xba6eadadU),
            };
            r_rsip_func102(Param_p85f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
