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

rsip_ret_t r_rsip_peff (const uint32_t InData_Msg1[],
                        const uint32_t InData_Msg1Length[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        const uint32_t InData_Msg2[],
                        const uint32_t InData_Msg2Length[],
                        uint32_t       OutData_KDFInfo[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000002c7U, 0x80030060U);
    WR1_PROG(REG_1420H, InData_Msg1Length[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_EncMsgLength[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Msg2Length[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008c60U, 0xfffffffeU, 0x00A60000U);

    static const uint32_t Param_peff_func100_001[] =
    {
        BSWAP_32BIG_C(0x70bfe630U), BSWAP_32BIG_C(0x5f42623bU), BSWAP_32BIG_C(0x36812c23U), BSWAP_32BIG_C(0xa488c9d2U),
    };
    r_rsip_func100(Param_peff_func100_001);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xfffffff7U, 0x00A60000U);

        static const uint32_t Param_peff_func101_001[] =
        {
            BSWAP_32BIG_C(0xe2c72590U), BSWAP_32BIG_C(0x001cff06U), BSWAP_32BIG_C(0x5444e92bU), BSWAP_32BIG_C(
                0x9e801880U),
        };
        r_rsip_func101(Param_peff_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub021(0x38000c84U, 0x00020020U, 0x38008880U, 0x0000000cU);
        r_rsip_func_sub017(0x00000080U, 0x00A60000U);

        static const uint32_t Param_peff_func101_002[] =
        {
            BSWAP_32BIG_C(0xaf50a67bU), BSWAP_32BIG_C(0x219a7741U), BSWAP_32BIG_C(0xc1735a40U), BSWAP_32BIG_C(
                0xb0d701e4U),
        };
        r_rsip_func101(Param_peff_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xffffffefU, 0x00A60000U);

        static const uint32_t Param_peff_func101_003[] =
        {
            BSWAP_32BIG_C(0x9adb6b4bU), BSWAP_32BIG_C(0xeafac25cU), BSWAP_32BIG_C(0x1e041bfaU), BSWAP_32BIG_C(
                0xf51b88fbU),
        };
        r_rsip_func101(Param_peff_func101_003);
    }

    static const uint32_t Param_peff_func100_002[] =
    {
        BSWAP_32BIG_C(0x91c1c75bU), BSWAP_32BIG_C(0xb8f1fdbcU), BSWAP_32BIG_C(0x0f09f269U), BSWAP_32BIG_C(0xb2a4fd8bU),
    };
    r_rsip_func100(Param_peff_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_peff_func102_001[] =
        {
            BSWAP_32BIG_C(0x6a05aa54U), BSWAP_32BIG_C(0x259c22f7U), BSWAP_32BIG_C(0x2fc07c73U), BSWAP_32BIG_C(
                0x44449225U),
        };
        r_rsip_func102(Param_peff_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000821U);

        r_rsip_func_sub006(0x00003405U, 0x38000c84U, 0x00A60000U);

        static const uint32_t Param_peff_func100_003[] =
        {
            BSWAP_32BIG_C(0x9670f6e3U), BSWAP_32BIG_C(0x46087a28U), BSWAP_32BIG_C(0xb4fd4de0U), BSWAP_32BIG_C(
                0x1f2518c2U),
        };
        r_rsip_func100(Param_peff_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_EncMsg[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x0000ef02U);

            static const uint32_t Param_peff_func101_004[] =
            {
                BSWAP_32BIG_C(0x4b65cd95U), BSWAP_32BIG_C(0x9dd07fa3U), BSWAP_32BIG_C(0xeb5b8a82U), BSWAP_32BIG_C(
                    0x161b9191U),
            };
            r_rsip_func101(Param_peff_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01c80eb2U);

            r_rsip_func_sub009(0x0000ef02U);

            static const uint32_t Param_peff_func101_005[] =
            {
                BSWAP_32BIG_C(0x063cebe6U), BSWAP_32BIG_C(0x3c42dd2bU), BSWAP_32BIG_C(0x65140193U), BSWAP_32BIG_C(
                    0x958fb985U),
            };
            r_rsip_func101(Param_peff_func101_005);
            r_rsip_func044();

            r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x000038a7U);

            static const uint32_t Param_peff_func100_004[] =
            {
                BSWAP_32BIG_C(0x353704cbU), BSWAP_32BIG_C(0xb7644b97U), BSWAP_32BIG_C(0x3cbc7864U), BSWAP_32BIG_C(
                    0x6e7e2632U),
            };
            r_rsip_func100(Param_peff_func100_004);

            r_rsip_func_sub014(0x00007c05U, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
            {
                r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[1]);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_EncMsg[5]);

                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_func_sub001(0x00c20021U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[9]);

                static const uint32_t Param_peff_func101_006[] =
                {
                    BSWAP_32BIG_C(0x14655c0cU), BSWAP_32BIG_C(0x421b942aU), BSWAP_32BIG_C(0xe25406fbU), BSWAP_32BIG_C(
                        0xf2858ceeU),
                };
                r_rsip_func101(Param_peff_func101_006);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                r_rsip_func_sub024(0x00000bc2U, 0x40000200U, 0xf7009d07U);

                for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_func_sub001(0x00c20031U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[13]);

                static const uint32_t Param_peff_func101_007[] =
                {
                    BSWAP_32BIG_C(0x95a13844U), BSWAP_32BIG_C(0xa9674858U), BSWAP_32BIG_C(0x7977e03dU), BSWAP_32BIG_C(
                        0x6fd5d273U),
                };
                r_rsip_func101(Param_peff_func101_007);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xf7009d07U);

                WR1_PROG(REG_1404H, 0x10000000U);
                for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);
                    r_rsip_func_sub001(0x00c20011U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[17]);

                static const uint32_t Param_peff_func101_008[] =
                {
                    BSWAP_32BIG_C(0x4745cccaU), BSWAP_32BIG_C(0x8a7b223eU), BSWAP_32BIG_C(0xdba5cd9bU), BSWAP_32BIG_C(
                        0xb23fdb3cU),
                };
                r_rsip_func101(Param_peff_func101_008);
            }

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_peff_func100_005[] =
            {
                BSWAP_32BIG_C(0x74e5906fU), BSWAP_32BIG_C(0x03a896a4U), BSWAP_32BIG_C(0x7eb41905U), BSWAP_32BIG_C(
                    0x8c5123e2U),
            };
            r_rsip_func100(Param_peff_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002c20U);
                static const uint32_t Param_peff_func101_009[] =
                {
                    BSWAP_32BIG_C(0x6124fa5bU), BSWAP_32BIG_C(0xe2ecc723U), BSWAP_32BIG_C(0x6f693d67U), BSWAP_32BIG_C(
                        0x2f157d8dU),
                };
                r_rsip_func101(Param_peff_func101_009);
            }

            static const uint32_t Param_peff_func101_010[] =
            {
                BSWAP_32BIG_C(0xb3c5975fU), BSWAP_32BIG_C(0xadac437bU), BSWAP_32BIG_C(0x31cf0947U), BSWAP_32BIG_C(
                    0xcea28202U),
            };
            r_rsip_func101(Param_peff_func101_010);
        }

        r_rsip_func_sub017(0x38000c21U, 0x00A60000U);

        static const uint32_t Param_peff_func100_006[] =
        {
            BSWAP_32BIG_C(0x58d292ffU), BSWAP_32BIG_C(0xbbbda4cfU), BSWAP_32BIG_C(0x7d7cea28U), BSWAP_32BIG_C(
                0x826e21c2U),
        };
        r_rsip_func100(Param_peff_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_peff_func102_002[] =
            {
                BSWAP_32BIG_C(0x7ca06defU), BSWAP_32BIG_C(0x3760fffaU), BSWAP_32BIG_C(0xbe023b27U), BSWAP_32BIG_C(
                    0xb7f92248U),
            };
            r_rsip_func102(Param_peff_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WAIT_STS(REG_2030H, 0, 1);

            r_rsip_func_sub017(0x38000c63U, 0x00A60000U);

            static const uint32_t Param_peff_func100_007[] =
            {
                BSWAP_32BIG_C(0x5da17e49U), BSWAP_32BIG_C(0x797cb3a4U), BSWAP_32BIG_C(0xc1693ffbU), BSWAP_32BIG_C(
                    0x4306fa5cU),
            };
            r_rsip_func100(Param_peff_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1444H, 0x000000c4U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Msg1[0]);

                static const uint32_t Param_peff_func101_011[] =
                {
                    BSWAP_32BIG_C(0x36375b38U), BSWAP_32BIG_C(0x4e289f3fU), BSWAP_32BIG_C(0x7aec4775U), BSWAP_32BIG_C(
                        0x1dcd683aU),
                };
                r_rsip_func101(Param_peff_func101_011);
            }

            r_rsip_func_sub017(0x38000c84U, 0x00A60000U);

            static const uint32_t Param_peff_func100_008[] =
            {
                BSWAP_32BIG_C(0x70776e87U), BSWAP_32BIG_C(0x05fb524bU), BSWAP_32BIG_C(0xfbff25d8U), BSWAP_32BIG_C(
                    0x4730ae8dU),
            };
            r_rsip_func100(Param_peff_func100_008);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_peff_func100_009[] =
                {
                    BSWAP_32BIG_C(0xa744c9edU), BSWAP_32BIG_C(0x3d3875c2U), BSWAP_32BIG_C(0xf4c3b918U), BSWAP_32BIG_C(
                        0x9e7cf2c6U),
                };
                r_rsip_func100(Param_peff_func100_009);

                r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430021U);

                    static const uint32_t Param_peff_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x977526bcU), BSWAP_32BIG_C(0x33b68dc7U), BSWAP_32BIG_C(0xf5387d3fU),
                        BSWAP_32BIG_C(0xa62847f0U),
                    };
                    r_rsip_func101(Param_peff_func101_012);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430031U);

                    static const uint32_t Param_peff_func101_013[] =
                    {
                        BSWAP_32BIG_C(0xa55a15e5U), BSWAP_32BIG_C(0x6358087aU), BSWAP_32BIG_C(0xb8d2ad47U),
                        BSWAP_32BIG_C(0x0d130db1U),
                    };
                    r_rsip_func101(Param_peff_func101_013);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430041U);

                    static const uint32_t Param_peff_func101_014[] =
                    {
                        BSWAP_32BIG_C(0x564fabefU), BSWAP_32BIG_C(0xd13632b4U), BSWAP_32BIG_C(0x27e799f8U),
                        BSWAP_32BIG_C(0xd64cf637U),
                    };
                    r_rsip_func101(Param_peff_func101_014);
                }

                static const uint32_t Param_peff_func101_015[] =
                {
                    BSWAP_32BIG_C(0xeaedb38aU), BSWAP_32BIG_C(0x63b7446fU), BSWAP_32BIG_C(0x1c7afc7bU), BSWAP_32BIG_C(
                        0xdc548438U),
                };
                r_rsip_func101(Param_peff_func101_015);
            }

            static const uint32_t Param_peff_func100_010[] =
            {
                BSWAP_32BIG_C(0x50476628U), BSWAP_32BIG_C(0x8c87c410U), BSWAP_32BIG_C(0xcec6157dU), BSWAP_32BIG_C(
                    0xfa05c400U),
            };
            r_rsip_func100(Param_peff_func100_010);

            r_rsip_func_sub010(0x000000c7U, 0x800100a0U);
            WR1_PROG(REG_1420H, InData_Msg2Length[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub016(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1444H, 0x00020064U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Msg2[iLoop]);
            }

            r_rsip_func_sub043();

            WAIT_STS(REG_2030H, 4, 1);

            r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003801U);

            r_rsip_func_sub009(0x000000efU);

            static const uint32_t Param_peff_func101_016[] =
            {
                BSWAP_32BIG_C(0x870b7f7bU), BSWAP_32BIG_C(0x6176063dU), BSWAP_32BIG_C(0x7fe7b664U), BSWAP_32BIG_C(
                    0x56fb6667U),
            };
            r_rsip_func101(Param_peff_func101_016);
            r_rsip_func103();

            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1608H, 0x80010020U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            WR1_PROG(REG_1600H, 0x000034e1U);

            r_rsip_func_sub009(0x0000ef03U);

            static const uint32_t Param_peff_func101_017[] =
            {
                BSWAP_32BIG_C(0x3da101fcU), BSWAP_32BIG_C(0x5e552862U), BSWAP_32BIG_C(0x53305e70U), BSWAP_32BIG_C(
                    0xe39c3780U),
            };
            r_rsip_func101(Param_peff_func101_017);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01c80eb2U);

            r_rsip_func_sub009(0x0000ef03U);

            static const uint32_t Param_peff_func101_018[] =
            {
                BSWAP_32BIG_C(0xb0956f4eU), BSWAP_32BIG_C(0x2dd1e871U), BSWAP_32BIG_C(0xe9c6d695U), BSWAP_32BIG_C(
                    0x863d2a3aU),
            };
            r_rsip_func101(Param_peff_func101_018);
            r_rsip_func044();

            static const uint32_t Param_peff_func100_011[] =
            {
                BSWAP_32BIG_C(0x6ef8c375U), BSWAP_32BIG_C(0x335233bcU), BSWAP_32BIG_C(0xfa59957eU), BSWAP_32BIG_C(
                    0x881cb8f4U),
            };
            r_rsip_func100(Param_peff_func100_011);
            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub004(0x08000054U, 0x00000000U);

            r_rsip_func_sub014(0x00007c00U, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
            {
                static const uint32_t Param_peff_func100_012[] =
                {
                    BSWAP_32BIG_C(0xfcffc9c3U), BSWAP_32BIG_C(0xc4fa70ecU), BSWAP_32BIG_C(0xcc2450b9U), BSWAP_32BIG_C(
                        0xb3a817a8U),
                };
                r_rsip_func100(Param_peff_func100_012);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                r_rsip_func_sub001(0x00850021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[5]);

                static const uint32_t Param_peff_func100_013[] =
                {
                    BSWAP_32BIG_C(0xcbf0a049U), BSWAP_32BIG_C(0x76904a45U), BSWAP_32BIG_C(0xcac086faU), BSWAP_32BIG_C(
                        0xe8d7b01fU),
                };
                r_rsip_func100(Param_peff_func100_013);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func101_019[] =
                {
                    BSWAP_32BIG_C(0xbff0f148U), BSWAP_32BIG_C(0x0bdd351bU), BSWAP_32BIG_C(0xd77f8b83U), BSWAP_32BIG_C(
                        0xa6c17289U),
                };
                r_rsip_func101(Param_peff_func101_019);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                static const uint32_t Param_peff_func100_014[] =
                {
                    BSWAP_32BIG_C(0xb5d617a4U), BSWAP_32BIG_C(0xd1372ae8U), BSWAP_32BIG_C(0x2c5e5eacU), BSWAP_32BIG_C(
                        0xd4680607U),
                };
                r_rsip_func100(Param_peff_func100_014);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                r_rsip_func_sub001(0x00850031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[5]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func100_015[] =
                {
                    BSWAP_32BIG_C(0x9f38d06eU), BSWAP_32BIG_C(0xc599f5b7U), BSWAP_32BIG_C(0x5518a401U), BSWAP_32BIG_C(
                        0xc0931045U),
                };
                r_rsip_func100(Param_peff_func100_015);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[13]);

                static const uint32_t Param_peff_func101_020[] =
                {
                    BSWAP_32BIG_C(0xfca25619U), BSWAP_32BIG_C(0xf71982ffU), BSWAP_32BIG_C(0x008e1e76U), BSWAP_32BIG_C(
                        0x6dab9439U),
                };
                r_rsip_func101(Param_peff_func101_020);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                static const uint32_t Param_peff_func100_016[] =
                {
                    BSWAP_32BIG_C(0xa62bcb4dU), BSWAP_32BIG_C(0xfd3d900eU), BSWAP_32BIG_C(0xb96cc267U), BSWAP_32BIG_C(
                        0x6b6cee8fU),
                };
                r_rsip_func100(Param_peff_func100_016);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                r_rsip_func_sub001(0x00850031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[5]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func100_017[] =
                {
                    BSWAP_32BIG_C(0xa5bd36f9U), BSWAP_32BIG_C(0x7e03b101U), BSWAP_32BIG_C(0x2028c4c1U), BSWAP_32BIG_C(
                        0x1dfb55fdU),
                };
                r_rsip_func100(Param_peff_func100_017);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe7008d05U);
                r_rsip_func_sub001(0x00850011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[13]);

                static const uint32_t Param_peff_func100_018[] =
                {
                    BSWAP_32BIG_C(0x474d30a1U), BSWAP_32BIG_C(0x825f15edU), BSWAP_32BIG_C(0xf4101a44U), BSWAP_32BIG_C(
                        0x840e48ffU),
                };
                r_rsip_func100(Param_peff_func100_018);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[17]);

                static const uint32_t Param_peff_func101_021[] =
                {
                    BSWAP_32BIG_C(0x03926496U), BSWAP_32BIG_C(0x36e12d2aU), BSWAP_32BIG_C(0x13e3b165U), BSWAP_32BIG_C(
                        0x5d7c2d84U),
                };
                r_rsip_func101(Param_peff_func101_021);
            }

            static const uint32_t Param_peff_func100_019[] =
            {
                BSWAP_32BIG_C(0xd2fbe53dU), BSWAP_32BIG_C(0xee39483cU), BSWAP_32BIG_C(0x50681792U), BSWAP_32BIG_C(
                    0x4c7b6724U),
            };
            r_rsip_func100(Param_peff_func100_019);
            r_rsip_func_sub016(0x81010020U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_KDFInfo[0]);

            static const uint32_t Param_peff_func102_003[] =
            {
                BSWAP_32BIG_C(0x139a2530U), BSWAP_32BIG_C(0xf607147bU), BSWAP_32BIG_C(0xfc657adfU), BSWAP_32BIG_C(
                    0x6bbff3b5U),
            };
            r_rsip_func102(Param_peff_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
