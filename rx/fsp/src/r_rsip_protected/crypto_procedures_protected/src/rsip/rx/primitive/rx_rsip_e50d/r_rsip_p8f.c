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

rsip_ret_t r_rsip_p8f (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_WrappedKeyIndex[],
                       uint32_t       OutData_Text[],
                       uint32_t       KEY_INDEX_SIZE,
                       uint32_t       WRAPPED_KEY_SIZE)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B4H, 0x0000001dU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x008f0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000001c7U, 0x80020100U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_WrappedKeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00003409U);

    r_rsip_func_sub006(0x3420a900U, 0x00000002U, 0x00A60000U);

    r_rsip_func_sub006(0x3420a800U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_p8f_func100_001[] =
    {
        BSWAP_32BIG_C(0x70f7b8eaU), BSWAP_32BIG_C(0x07721504U), BSWAP_32BIG_C(0x062ddedeU), BSWAP_32BIG_C(0xffbbc545U),
    };
    r_rsip_func100(Param_p8f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p8f_func102_001[] =
        {
            BSWAP_32BIG_C(0xa15d2dc9U), BSWAP_32BIG_C(0x1839799eU), BSWAP_32BIG_C(0x2c363c1eU), BSWAP_32BIG_C(
                0xf31a2257U),
        };
        r_rsip_func102(Param_p8f_func102_001);
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x00008f01U);

        static const uint32_t Param_p8f_func101_001[] =
        {
            BSWAP_32BIG_C(0x0eda6926U), BSWAP_32BIG_C(0xfc25a8a5U), BSWAP_32BIG_C(0x1c64c30fU), BSWAP_32BIG_C(
                0x805a030bU),
        };
        r_rsip_func101(Param_p8f_func101_001);
        r_rsip_func043();

        r_rsip_func_sub017(0x38000d08U, 0x00260000U);

        static const uint32_t Param_p8f_func100_002[] =
        {
            BSWAP_32BIG_C(0x0f153c48U), BSWAP_32BIG_C(0x606a1ccaU), BSWAP_32BIG_C(0xdf1c718dU), BSWAP_32BIG_C(
                0x06115047U),
        };
        r_rsip_func100(Param_p8f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000005U);

            r_rsip_func_sub009(0x00008f01U);

            static const uint32_t Param_p8f_func101_002[] =
            {
                BSWAP_32BIG_C(0x1da08afdU), BSWAP_32BIG_C(0xc10dd8f0U), BSWAP_32BIG_C(0xf6c8fa75U), BSWAP_32BIG_C(
                    0x7e6bfc71U),
            };
            r_rsip_func101(Param_p8f_func101_002);
            r_rsip_func044();

            static const uint32_t Param_p8f_func100_003[] =
            {
                BSWAP_32BIG_C(0xde01729aU), BSWAP_32BIG_C(0xe07b1e8dU), BSWAP_32BIG_C(0xedb41624U), BSWAP_32BIG_C(
                    0x5089d8d6U),
            };
            r_rsip_func100(Param_p8f_func100_003);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_182CH, 0x00000000U);

            static const uint32_t Param_p8f_func101_003[] =
            {
                BSWAP_32BIG_C(0xcd9b8a7dU), BSWAP_32BIG_C(0xbcf649f0U), BSWAP_32BIG_C(0xb492ee2aU), BSWAP_32BIG_C(
                    0x6d2224dfU),
            };
            r_rsip_func101(Param_p8f_func101_003);
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000007U);

            r_rsip_func_sub009(0x00008f02U);

            static const uint32_t Param_p8f_func101_004[] =
            {
                BSWAP_32BIG_C(0xcbc80fc2U), BSWAP_32BIG_C(0xa5d26044U), BSWAP_32BIG_C(0x39576f05U), BSWAP_32BIG_C(
                    0x84ca0e79U),
            };
            r_rsip_func101(Param_p8f_func101_004);
            r_rsip_func044();

            static const uint32_t Param_p8f_func100_004[] =
            {
                BSWAP_32BIG_C(0xdfe24a68U), BSWAP_32BIG_C(0x2b871c9fU), BSWAP_32BIG_C(0xffeb0084U), BSWAP_32BIG_C(
                    0x5eb20b91U),
            };
            r_rsip_func100(Param_p8f_func100_004);
            r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            static const uint32_t Param_p8f_func100_005[] =
            {
                BSWAP_32BIG_C(0x01b0253aU), BSWAP_32BIG_C(0xe15f7fb5U), BSWAP_32BIG_C(0x18df39e7U), BSWAP_32BIG_C(
                    0x882b5afdU),
            };
            r_rsip_func100(Param_p8f_func100_005);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

            WR1_PROG(REG_182CH, 0x40000000U);

            static const uint32_t Param_p8f_func101_005[] =
            {
                BSWAP_32BIG_C(0xa82bd401U), BSWAP_32BIG_C(0x723c4869U), BSWAP_32BIG_C(0x08719362U), BSWAP_32BIG_C(
                    0xa363bb18U),
            };
            r_rsip_func101(Param_p8f_func101_005);
        }

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p8f_func100_006[] =
        {
            BSWAP_32BIG_C(0x60f77247U), BSWAP_32BIG_C(0x278a4e67U), BSWAP_32BIG_C(0xb63ad4abU), BSWAP_32BIG_C(
                0x606d6130U),
        };
        r_rsip_func100(Param_p8f_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p8f_func102_002[] =
            {
                BSWAP_32BIG_C(0x06349e38U), BSWAP_32BIG_C(0x1f899bb9U), BSWAP_32BIG_C(0xdadc0e3cU), BSWAP_32BIG_C(
                    0x41925696U),
            };
            r_rsip_func102(Param_p8f_func102_002);
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            WR1_PROG(REG_1600H, 0x000035c7U);

            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_WrappedKeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00008f02U);

            static const uint32_t Param_p8f_func101_006[] =
            {
                BSWAP_32BIG_C(0x829817e2U), BSWAP_32BIG_C(0xe1e12b9eU), BSWAP_32BIG_C(0x0a5e8163U), BSWAP_32BIG_C(
                    0xdf0ce012U),
            };
            r_rsip_func101(Param_p8f_func101_006);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x000034e6U);

            r_rsip_func_sub009(0x00008f03U);

            static const uint32_t Param_p8f_func101_007[] =
            {
                BSWAP_32BIG_C(0xc445ab01U), BSWAP_32BIG_C(0xfeb157c7U), BSWAP_32BIG_C(0xedba63a3U), BSWAP_32BIG_C(
                    0xf6277577U),
            };
            r_rsip_func101(Param_p8f_func101_007);
            r_rsip_func044();

            WR1_PROG(REG_1600H, 0x000034eeU);

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub004(0x08000054U, 0x00000000U);

            r_rsip_func_sub021(0x0000b7e0U, 0x00000008U, 0x0000b780U, 0x00000010U);

            r_rsip_func_sub021(0x00000bdeU, 0x0000b760U, 0x00000004U, 0x0000a8e0U);
            WR1_PROG(REG_1600H, 0x00000005U);

            for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; iLoop = iLoop + 4U)
            {
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 1]);

                WR1_PROG(REG_1608H, 0x8084001fU);
                r_rsip_func_sub001(0x03420011U);

                WR1_PROG(REG_1600H, 0x000027fcU);

                WR1_PROG(REG_1600H, 0x000027dbU);

                static const uint32_t Param_p8f_func101_008[] =
                {
                    BSWAP_32BIG_C(0x60f46932U), BSWAP_32BIG_C(0xcd21c7e1U), BSWAP_32BIG_C(0x7fdbb8dcU), BSWAP_32BIG_C(
                        0x9e667ed4U),
                };
                r_rsip_func101(Param_p8f_func101_008);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub011(0x38000bc7U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p8f_func100_007[] =
            {
                BSWAP_32BIG_C(0xd5fdcc65U), BSWAP_32BIG_C(0x59a67e8bU), BSWAP_32BIG_C(0x7f0a7f97U), BSWAP_32BIG_C(
                    0x4859314cU),
            };
            r_rsip_func100(Param_p8f_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p8f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x988d1c8eU), BSWAP_32BIG_C(0x832dc171U), BSWAP_32BIG_C(0xaa2fd1e2U), BSWAP_32BIG_C(
                        0x2712a067U),
                };
                r_rsip_func102(Param_p8f_func102_003);
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub021(0x0000b400U, 0xa6a6a6a6U, 0x00003420U, 0x0000b760U);
                r_rsip_func_sub021(0x00000008U, 0x0000b780U, 0x00000004U, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000001U);

                WR1_PROG(REG_1600H, 0x00000bdeU);

                for (jLoop = 0U; jLoop <= 5; jLoop++)
                {
                    WR1_PROG(REG_1600H, 0x000037fbU);

                    WR1_PROG(REG_1600H, 0x00000bbdU);

                    for (iLoop = 1; iLoop <= (WRAPPED_KEY_SIZE - 2) / 2; iLoop++)
                    {
                        WR1_PROG(REG_1824H, 0x0a008105U);
                        WR1_PROG(REG_1608H, 0x81020000U);
                        r_rsip_func_sub001(0x00490009U);
                        WR1_PROG(REG_1608H, 0x8182001fU);
                        r_rsip_func_sub001(0x00490009U);

                        WR1_PROG(REG_1608H, 0x80040000U);
                        r_rsip_func_sub001(0x03410011U);

                        r_rsip_func_sub021(0x00000824U, 0x00003c5fU, 0x000027fcU, 0x00003c7fU);
                        r_rsip_func_sub022(0x000027fcU, 0x00002c80U, 0x00002fa0U);

                        static const uint32_t Param_p8f_func101_009[] =
                        {
                            BSWAP_32BIG_C(0xfc311990U), BSWAP_32BIG_C(0x091646adU), BSWAP_32BIG_C(0x81c2c971U),
                            BSWAP_32BIG_C(0xb840e916U),
                        };
                        r_rsip_func101(Param_p8f_func101_009);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub011(0x38000ba5U);

                    WR1_PROG(REG_1600H, 0x00002fc0U);

                    static const uint32_t Param_p8f_func101_010[] =
                    {
                        BSWAP_32BIG_C(0xb3989a70U), BSWAP_32BIG_C(0x38638b45U), BSWAP_32BIG_C(0xc3c0888aU),
                        BSWAP_32BIG_C(0x0c9fc02fU),
                    };
                    r_rsip_func101(Param_p8f_func101_010);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38008bc0U);
                r_rsip_func_sub011(0x00000006U);

                r_rsip_func_sub021(0x00000bffU, 0x00003c1fU, 0x000027fcU, 0x00003c3fU);

                r_rsip_func_sub021(0x00000bffU, 0x00000bdeU, 0x000037a5U, 0x00002fa0U);

                WR1_PROG(REG_1600H, 0x0000b780U);
                WR1_PROG(REG_1600H, 0x00000008U);

                for (iLoop = 0U; iLoop < WRAPPED_KEY_SIZE; iLoop = iLoop + 2)
                {
                    r_rsip_func_sub021(0x000008c6U, 0x34202bddU, 0x2000d0c0U, 0x00007c06U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    static const uint32_t Param_p8f_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x1165b558U), BSWAP_32BIG_C(0x2f8c9191U), BSWAP_32BIG_C(0x8ce67cdeU),
                        BSWAP_32BIG_C(0x8e13b0e6U),
                    };
                    r_rsip_func100(Param_p8f_func100_008);
                    r_rsip_func_sub016(0x8182001fU, 0x0000500aU);
                    RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 1]);

                    WR1_PROG(REG_1600H, 0x000027fcU);

                    WR1_PROG(REG_1600H, 0x00002fc0U);

                    static const uint32_t Param_p8f_func101_011[] =
                    {
                        BSWAP_32BIG_C(0x36ae0118U), BSWAP_32BIG_C(0xce22c055U), BSWAP_32BIG_C(0xadfbddecU),
                        BSWAP_32BIG_C(0x1781a545U),
                    };
                    r_rsip_func101(Param_p8f_func101_011);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000bddU);

                static const uint32_t Param_p8f_func102_004[] =
                {
                    BSWAP_32BIG_C(0xe5c897c4U), BSWAP_32BIG_C(0x66e5db56U), BSWAP_32BIG_C(0x1b45a77dU), BSWAP_32BIG_C(
                        0xf26e334dU),
                };
                r_rsip_func102(Param_p8f_func102_004);
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
