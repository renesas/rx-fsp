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

rsip_ret_t r_rsip_p97f (const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_DataT[],
                        uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p97f_func100_001[] =
    {
        BSWAP_32BIG_C(0x4279a3c0U), BSWAP_32BIG_C(0x3be6e697U), BSWAP_32BIG_C(0x6c6aaad4U), BSWAP_32BIG_C(0xa01e95a3U),
    };
    r_rsip_func100(Param_p97f_func100_001);

    r_rsip_func_sub010(0x000000c7U, 0x80010020U);
    WR1_PROG(REG_1420H, MAX_CNT);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub016(0x81010020U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    static const uint32_t Param_p97f_func100_002[] =
    {
        BSWAP_32BIG_C(0x6748f45dU), BSWAP_32BIG_C(0xe4877090U), BSWAP_32BIG_C(0x99798b94U), BSWAP_32BIG_C(0x41d3e991U),
    };
    r_rsip_func100(Param_p97f_func100_002);

    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);

    for (iLoop = 0U; iLoop < (S_RAM[0] & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop++)
    {
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    static const uint32_t Param_p97f_func100_003[] =
    {
        BSWAP_32BIG_C(0x3c89cdc0U), BSWAP_32BIG_C(0x90c24239U), BSWAP_32BIG_C(0xfdda9572U), BSWAP_32BIG_C(0x6330287bU),
    };
    r_rsip_func100(Param_p97f_func100_003);
    r_rsip_func_sub021(0x00008c20U, 0x0000000fU, 0x38000c21U, 0x1000b420U);
    WR1_PROG(REG_1600H, 0x00000010U);

    r_rsip_func_sub016(0x81010020U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = S_RAM[0]; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub001(0x00070005U);

        WR1_PROG(REG_1600H, 0x00002c20U);

        static const uint32_t Param_p97f_func101_001[] =
        {
            BSWAP_32BIG_C(0x98481b82U), BSWAP_32BIG_C(0x528a5256U), BSWAP_32BIG_C(0x23196dc8U), BSWAP_32BIG_C(
                0x593fd08dU),
        };
        r_rsip_func101(Param_p97f_func101_001);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38008820U);
    r_rsip_func_sub011(0x00000010U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p97f_func100_004[] =
    {
        BSWAP_32BIG_C(0x455452aeU), BSWAP_32BIG_C(0x2fe698d8U), BSWAP_32BIG_C(0x8f14512aU), BSWAP_32BIG_C(0x5ca11b89U),
    };
    r_rsip_func100(Param_p97f_func100_004);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p97f_func100_005[] =
        {
            BSWAP_32BIG_C(0xc2643c67U), BSWAP_32BIG_C(0xcfeae0edU), BSWAP_32BIG_C(0xabdc9d88U), BSWAP_32BIG_C(
                0x17100132U),
        };
        r_rsip_func100(Param_p97f_func100_005);
        WR1_PROG(REG_1408H, 0x00007012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_DataT[0]);

        static const uint32_t Param_p97f_func102_001[] =
        {
            BSWAP_32BIG_C(0x6d3ca51fU), BSWAP_32BIG_C(0xd5ee1168U), BSWAP_32BIG_C(0x96692f81U), BSWAP_32BIG_C(
                0xa4df3a54U),
        };
        r_rsip_func102(Param_p97f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0x08000055U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_DataT[0]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00870011U);

        static const uint32_t Param_p97f_func100_006[] =
        {
            BSWAP_32BIG_C(0x270331feU), BSWAP_32BIG_C(0x2ea6dfffU), BSWAP_32BIG_C(0xcb478fecU), BSWAP_32BIG_C(
                0x4353175dU),
        };
        r_rsip_func100(Param_p97f_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p97f_func102_002[] =
            {
                BSWAP_32BIG_C(0x9cc5fa76U), BSWAP_32BIG_C(0xf9991505U), BSWAP_32BIG_C(0xe0b5864dU), BSWAP_32BIG_C(
                    0x972d5a88U),
            };
            r_rsip_func102(Param_p97f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p97f_func102_003[] =
            {
                BSWAP_32BIG_C(0x2d636ad4U), BSWAP_32BIG_C(0xf2c31bf7U), BSWAP_32BIG_C(0x5abfb216U), BSWAP_32BIG_C(
                    0x96b6c446U),
            };
            r_rsip_func102(Param_p97f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
