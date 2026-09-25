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

rsip_ret_t r_rsip_pdfi (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00df0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000dfU);

    static const uint32_t Param_pdfi_func101_001[] =
    {
        BSWAP_32BIG_C(0xb6de192fU), BSWAP_32BIG_C(0x78506298U), BSWAP_32BIG_C(0x2db9112fU), BSWAP_32BIG_C(0xcb5b034eU),
    };
    r_rsip_func101(Param_pdfi_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000010U);

    r_rsip_func_sub009(0x000000dfU);

    static const uint32_t Param_pdfi_func101_002[] =
    {
        BSWAP_32BIG_C(0x2d0949b9U), BSWAP_32BIG_C(0x45ac9474U), BSWAP_32BIG_C(0xd37a3565U), BSWAP_32BIG_C(0xd8bd8a8bU),
    };
    r_rsip_func101(Param_pdfi_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00007fc2U, 0x40001f00U, 0xe8009107U);

    WR1_PROG(REG_1404H, 0x14300000U);
    for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 8U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xe8008105U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1404H, 0x12200000U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pdfi_func100_001[] =
    {
        BSWAP_32BIG_C(0x9618de5aU), BSWAP_32BIG_C(0x71a8a5a9U), BSWAP_32BIG_C(0x825a23f7U), BSWAP_32BIG_C(0x89e58f70U),
    };
    r_rsip_func100(Param_pdfi_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdfi_func102_001[] =
        {
            BSWAP_32BIG_C(0x8dcede00U), BSWAP_32BIG_C(0x037ac239U), BSWAP_32BIG_C(0xa5863110U), BSWAP_32BIG_C(
                0x881af5d5U),
        };
        r_rsip_func102(Param_pdfi_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x40400010U);

        r_rsip_func_sub024(0x00007fc2U, 0x40001f00U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x10200000U);
        for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 8U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
            r_rsip_func_sub001(0x00c20021U);
        }

        r_rsip_func_sub044();
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800dbe0U, 0x00260000U);

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x4040000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pdfi_func100_002[] =
        {
            BSWAP_32BIG_C(0x245f8a93U), BSWAP_32BIG_C(0x5526e7f9U), BSWAP_32BIG_C(0x2ef27ca6U), BSWAP_32BIG_C(
                0x4cc677eaU),
        };
        r_rsip_func100(Param_pdfi_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdfi_func102_002[] =
            {
                BSWAP_32BIG_C(0x82db64c2U), BSWAP_32BIG_C(0x8dae7b7cU), BSWAP_32BIG_C(0x3445679cU), BSWAP_32BIG_C(
                    0x2751eaa7U),
            };
            r_rsip_func102(Param_pdfi_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdfi_func100_003[] =
            {
                BSWAP_32BIG_C(0x281db61dU), BSWAP_32BIG_C(0x89523661U), BSWAP_32BIG_C(0x4a848795U), BSWAP_32BIG_C(
                    0x1d731200U),
            };
            r_rsip_func100(Param_pdfi_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000228U, 0x00000630U, 0x00000838U, 0x0140000fU, 0x00010001U);
            r_rsip_func_sub045();
            r_rsip_func_sub031(0x0000b400U, 0x00000080U, 0x16380000U);

            for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 8U)
            {
                r_rsip_func_sub021(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_pdfi_func100_004[] =
                {
                    BSWAP_32BIG_C(0x232ebe60U), BSWAP_32BIG_C(0x241758a8U), BSWAP_32BIG_C(0x16178b61U), BSWAP_32BIG_C(
                        0xa2979d7fU),
                };
                r_rsip_func100(Param_pdfi_func100_004);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);

                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1600H, 0x00000008U);

                static const uint32_t Param_pdfi_func101_003[] =
                {
                    BSWAP_32BIG_C(0xc32dc4a5U), BSWAP_32BIG_C(0xf36406cbU), BSWAP_32BIG_C(0x60b8b03fU), BSWAP_32BIG_C(
                        0x8400b9dfU),
                };
                r_rsip_func101(Param_pdfi_func101_003);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_pdfi_func100_005[] =
            {
                BSWAP_32BIG_C(0x5b6f486fU), BSWAP_32BIG_C(0x6b4a4a38U), BSWAP_32BIG_C(0x13d7fc3eU), BSWAP_32BIG_C(
                    0x5cea8a63U),
            };
            r_rsip_func100(Param_pdfi_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_pdfi_func101_004[] =
            {
                BSWAP_32BIG_C(0x4541e3c4U), BSWAP_32BIG_C(0xccb48846U), BSWAP_32BIG_C(0xf6dcdb78U), BSWAP_32BIG_C(
                    0x4b6c7f1aU),
            };
            r_rsip_func101(Param_pdfi_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
