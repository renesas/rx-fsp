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

rsip_ret_t r_rsip_p19 (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MsgLen[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[],
                       uint64_t       MAX_CNT)
{
    uint64_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00190001U, 0x000008c8U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000019U);

    static const uint32_t Param_p19_func101_001[] =
    {
        BSWAP_32BIG_C(0xe1b3b1b0U), BSWAP_32BIG_C(0x46c05cb0U), BSWAP_32BIG_C(0x377b6c13U), BSWAP_32BIG_C(0xeb9cf677U),
    };
    r_rsip_func101(Param_p19_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000026U);

    r_rsip_func_sub009(0x00000019U);

    static const uint32_t Param_p19_func101_002[] =
    {
        BSWAP_32BIG_C(0x0155206aU), BSWAP_32BIG_C(0x72d6d462U), BSWAP_32BIG_C(0x7ddf39d7U), BSWAP_32BIG_C(0x93ce440fU),
    };
    r_rsip_func101(Param_p19_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000007c2U, 0x40000100U, 0xe8009107U);

    for (iLoop = 0U; iLoop < 8U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x19100000U);
    r_rsip_func_sub001(0x00c20021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p19_func100_001[] =
    {
        BSWAP_32BIG_C(0x83ba1cd9U), BSWAP_32BIG_C(0x28f4f238U), BSWAP_32BIG_C(0x47b87245U), BSWAP_32BIG_C(0x482a2d20U),
    };
    r_rsip_func100(Param_p19_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p19_func102_001[] =
        {
            BSWAP_32BIG_C(0x78662a70U), BSWAP_32BIG_C(0x6f9c7c0fU), BSWAP_32BIG_C(0x1ee696c9U), BSWAP_32BIG_C(
                0xc219986aU),
        };
        r_rsip_func102(Param_p19_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000001c7U, 0x80020000U);
        WR2_ADDR(REG_1420H, &InData_MsgLen[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x00000bffU, 0x30008800U, 0xffffffffU, 0x00030020U);
        r_rsip_func_sub021(0x3000a820U, 0xfffffdffU, 0x00050020U, 0x1000d3e0U);
        r_rsip_func_sub021(0x00000080U, 0x00000080U, 0x38008be0U, 0x00000001U);

        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        static const uint32_t Param_p19_func100_002[] =
        {
            BSWAP_32BIG_C(0xd45d4a9eU), BSWAP_32BIG_C(0xa8c2bb47U), BSWAP_32BIG_C(0xfa6998f6U), BSWAP_32BIG_C(
                0x5a54f942U),
        };
        r_rsip_func100(Param_p19_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p19_func102_002[] =
            {
                BSWAP_32BIG_C(0x3638bc6aU), BSWAP_32BIG_C(0x7b2d354bU), BSWAP_32BIG_C(0xe97acf66U), BSWAP_32BIG_C(
                    0x1e806f0aU),
            };
            r_rsip_func102(Param_p19_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub024(0x000007c2U, 0x00000100U, 0x08008107U);
            WR1_PROG(REG_1404H, 0x1c300000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Signature[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Signature[4]);
            r_rsip_func_sub001(0x00c20021U);

            static const uint32_t Param_p19_func100_003[] =
            {
                BSWAP_32BIG_C(0xa92b841eU), BSWAP_32BIG_C(0x38186509U), BSWAP_32BIG_C(0x795ef6daU), BSWAP_32BIG_C(
                    0xbb832a7cU),
            };
            r_rsip_func100(Param_p19_func100_003);
            r_rsip_func_sub021(0x00000842U, 0x0c00a420U, 0x00000200U, 0x00802402U);

            r_rsip_func_sub016(0x81020000U, 0x0000500aU);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

            WR1_PROG(REG_2000H, 0x00000001U);

            WR1_PROG(REG_2004H, 0x000000b0U);

            r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

            WR1_PROG(REG_1404H, 0x1c300000U);
            r_rsip_func_sub001(0x01430021U);

            WR1_PROG(REG_1404H, 0x19100000U);
            r_rsip_func_sub001(0x01430021U);

            WR1_PROG(REG_1444H, 0x00020064U);

            for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffffffffffff0U); iLoop = iLoop + 16U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = (MAX_CNT & 0xfffffffffffffff0U); iLoop < MAX_CNT; iLoop++)
            {
                WR1_PROG(REG_1420H, InData_Msg[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x00000000U);

            WAIT_STS(REG_2030H, 4, 1);

            r_rsip_func_sub023(0x00000821U, 0x00000842U, 0x80900001U);
            r_rsip_func_sub001(0x03450041U);

            r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x0000003fU);

            for (iLoop = 0U; iLoop < 32U; iLoop++)
            {
                r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                WR1_PROG(REG_1600H, 0x00002c20U);
                WR1_PROG(REG_1600H, 0x00003060U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81900001U);

            WR1_PROG(REG_1404H, 0x1a000000U);
            r_rsip_func_sub001(0x00c90021U);

            WR1_PROG(REG_1404H, 0x1a500000U);
            r_rsip_func_sub001(0x00c90021U);

            WR1_PROG(REG_1004H, 0x00000000U);
            WR1_PROG(REG_1004H, 0x04040000U);

            static const uint32_t Param_p19_func100_004[] =
            {
                BSWAP_32BIG_C(0xd5d9993bU), BSWAP_32BIG_C(0xf6527676U), BSWAP_32BIG_C(0xabf45e20U), BSWAP_32BIG_C(
                    0x70cc1dbfU),
            };
            r_rsip_func100(Param_p19_func100_004);
            r_rsip_func406(InData_DomainParam);

            WR1_PROG(REG_1404H, 0x12300000U);
            r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x0EEC73D2U),
                     bswap_32big(0x17F5BE65U),
                     bswap_32big(0xCB5C63AAU),
                     bswap_32big(0x97A331B5U));
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x0665E1DBU),
                     bswap_32big(0x6EABA043U),
                     bswap_32big(0xF98B4BAAU),
                     bswap_32big(0x9C78F954U));
            r_rsip_func_sub001(0x00c20021U);

            r_rsip_func_sub041(0x00000250U, 0x00000a20U, 0x000000c0U, 0x000002a0U, 0x00000010U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            r_rsip_func_sub007(0x00000a70U, 0x00000200U, 0x000000c0U);
            r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            r_rsip_func_sub005(0x000003e0U, 0x04040004U, 0x00010001U);
            r_rsip_func_sub007(0x000003e0U, 0x000002a0U, 0x000000c0U);
            r_rsip_func_sub005(0x000009d0U, 0x04040005U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x14300000U);
            r_rsip_func_sub001(0x00c000f1U);

            r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x0000001fU);

            WR1_PROG(REG_1404H, 0x19100000U);
            WR1_PROG(REG_1608H, 0x80880001U);
            r_rsip_func_sub001(0x03430021U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                WR1_PROG(REG_1600H, 0x00002c20U);
                WR1_PROG(REG_1600H, 0x00003060U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x02003801U, 0x00003440U);
            r_rsip_func_sub021(0x00076800U, 0x000037e0U, 0x00008c40U, 0x0000007FU);
            r_rsip_func_sub023(0x02003c41U, 0x00000800U, 0x81880000U);

            WR1_PROG(REG_1404H, 0x12300000U);
            r_rsip_func_sub001(0x00c90021U);

            r_rsip_func_sub041(0x00000250U, 0x000001b0U, 0x00000070U, 0x000004d0U, 0x00000008U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x000004d0U, 0x00000b10U, 0x00000ac0U, 0x0404000aU);

            r_rsip_func_sub041(0x000004d0U, 0x00000ac0U, 0x00000070U, 0x00000250U, 0x00000008U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x000001b0U);
            r_rsip_func_sub040(0x00000070U, 0x000002a0U, 0x00000008U, 0x04040004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub041(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x00000008U, 0x04040006U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub041(0x00000250U, 0x00000160U, 0x00000070U, 0x00000390U, 0x00000008U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub041(0x00000390U, 0x000002a0U, 0x00000070U, 0x00000340U, 0x00000008U, 0x04040005U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000340U);
            r_rsip_func_sub040(0x00000070U, 0x00000250U, 0x00000008U, 0x04040004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x12800000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub041(0x00000070U, 0x000002a0U, 0x00000070U, 0x000003e0U, 0x00000008U, 0x04040006U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p19_func100_005[] =
            {
                BSWAP_32BIG_C(0xe9d91f62U), BSWAP_32BIG_C(0xf0e5ff54U), BSWAP_32BIG_C(0x707d5abcU), BSWAP_32BIG_C(
                    0x79756e0cU),
            };
            r_rsip_func100(Param_p19_func100_005);
            r_rsip_func_sub013(0x00000250U, 0x000003e0U, 0x00000070U, 0x000002a0U, 0x0404000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub041(0x000002f0U, 0x000002a0U, 0x00000070U, 0x00000390U, 0x00000008U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x12300000U);
            r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x0FFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU));
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFEU));
            r_rsip_func_sub001(0x00c20021U);

            static const uint32_t Param_p19_func100_006[] =
            {
                BSWAP_32BIG_C(0x1581d1bdU), BSWAP_32BIG_C(0xc7b7b353U), BSWAP_32BIG_C(0xe3d7195eU), BSWAP_32BIG_C(
                    0x0ea8d88eU),
            };
            r_rsip_func100(Param_p19_func100_006);
            r_rsip_func_sub013(0x00000390U, 0x00000250U, 0x00000070U, 0x000003e0U, 0x0404000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub041(0x000003e0U, 0x000001b0U, 0x00000070U, 0x000002f0U, 0x00000008U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x000002f0U, 0x00000b10U, 0x00000ac0U, 0x0404000aU);
            r_rsip_func_sub041(0x000002f0U, 0x00000ac0U, 0x00000070U, 0x00000340U, 0x00000008U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000340U);
            r_rsip_func_sub040(0x00000070U, 0x000002f0U, 0x00000008U, 0x04040004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000070U, 0x00000390U, 0x00000250U, 0x04040006U);

            WR1_PROG(REG_1404H, 0x14100000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000002f0U, 0x00000390U, 0x00000ac0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000390U, 0x000002f0U, 0x00000ac0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p19_func100_007[] =
            {
                BSWAP_32BIG_C(0xca376081U), BSWAP_32BIG_C(0x7361dcf2U), BSWAP_32BIG_C(0x837c54ceU), BSWAP_32BIG_C(
                    0x9b67a86eU),
            };
            r_rsip_func100(Param_p19_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x000002f0U, 0x00000250U, 0x00000ac0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x00000ac0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p19_func100_008[] =
                {
                    BSWAP_32BIG_C(0x81967e7fU), BSWAP_32BIG_C(0x5d3bda5bU), BSWAP_32BIG_C(0x600482c6U), BSWAP_32BIG_C(
                        0x3978414eU),
                };
                r_rsip_func100(Param_p19_func100_008);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xd4cfa273U);

                    static const uint32_t Param_p19_func101_003[] =
                    {
                        BSWAP_32BIG_C(0x21a0f1bcU), BSWAP_32BIG_C(0xd14fe070U), BSWAP_32BIG_C(0x969dfdbcU),
                        BSWAP_32BIG_C(0xee1d3c93U),
                    };
                    r_rsip_func101(Param_p19_func101_003);
                }
                else
                {
                    r_rsip_func_sub041(0x000003e0U, 0x000001b0U, 0x00000070U, 0x00000250U, 0x00000008U, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x12800000U);
                    r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
                    WR4_PROG(REG_1420H,
                             bswap_32big(0x2B832480U),
                             bswap_32big(0x4FC1DF0BU),
                             bswap_32big(0x2B4D0099U),
                             bswap_32big(0x3DFBD7A7U));
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_PROG(REG_1420H,
                             bswap_32big(0x2F431806U),
                             bswap_32big(0xAD2FE478U),
                             bswap_32big(0xC4EE1B27U),
                             bswap_32big(0x4A0EA0B0U));
                    r_rsip_func_sub001(0x00c20021U);

                    r_rsip_func_sub041(0x00000250U, 0x000002a0U, 0x00000070U, 0x000003e0U, 0x00000008U, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    static const uint32_t Param_p19_func101_004[] =
                    {
                        BSWAP_32BIG_C(0x16bd93baU), BSWAP_32BIG_C(0xdce3634cU), BSWAP_32BIG_C(0x750c4079U),
                        BSWAP_32BIG_C(0x54592971U),
                    };
                    r_rsip_func101(Param_p19_func101_004);
                }

                static const uint32_t Param_p19_func101_005[] =
                {
                    BSWAP_32BIG_C(0xdbf75ceaU), BSWAP_32BIG_C(0xd328e2d5U), BSWAP_32BIG_C(0xd9ae7c70U), BSWAP_32BIG_C(
                        0x6f6f8433U),
                };
                r_rsip_func101(Param_p19_func101_005);
            }
            else
            {
                static const uint32_t Param_p19_func101_006[] =
                {
                    BSWAP_32BIG_C(0x2a793f2eU), BSWAP_32BIG_C(0x7c78df88U), BSWAP_32BIG_C(0x6fab2e99U), BSWAP_32BIG_C(
                        0xe2d9ede0U),
                };
                r_rsip_func101(Param_p19_func101_006);
            }

            r_rsip_func_sub006(0x38008800U, 0xd4cfa273U, 0x00260000U);

            static const uint32_t Param_p19_func100_009[] =
            {
                BSWAP_32BIG_C(0x22b8428dU), BSWAP_32BIG_C(0xa0f276e3U), BSWAP_32BIG_C(0x1c87dc0dU), BSWAP_32BIG_C(
                    0xa58f9d91U),
            };
            r_rsip_func100(Param_p19_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p19_func102_003[] =
                {
                    BSWAP_32BIG_C(0x2fad08a9U), BSWAP_32BIG_C(0x7432e9b1U), BSWAP_32BIG_C(0xbe4e27b1U), BSWAP_32BIG_C(
                        0x25191020U),
                };
                r_rsip_func102(Param_p19_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1b100000U);
                r_rsip_func_sub001(0x00c000f1U);

                r_rsip_func_sub030(0x13c00000U, 0x00000821U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x0000b420U, 0x0000001fU, 0x02003841U, 0x00008c40U);
                r_rsip_func_sub006(0x00000001U, 0x3800085fU, 0x00260000U);

                static const uint32_t Param_p19_func100_010[] =
                {
                    BSWAP_32BIG_C(0xce3442dbU), BSWAP_32BIG_C(0xb5bf713fU), BSWAP_32BIG_C(0x4c35d6a9U), BSWAP_32BIG_C(
                        0x6312f299U),
                };
                r_rsip_func100(Param_p19_func100_010);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    r_rsip_func_sub041(0x000003e0U, 0x000001b0U, 0x00000070U, 0x00000480U, 0x00000008U, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    static const uint32_t Param_p19_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x15046da1U), BSWAP_32BIG_C(0xfccd3057U), BSWAP_32BIG_C(0xf5590710U),
                        BSWAP_32BIG_C(0x7dcbad44U),
                    };
                    r_rsip_func101(Param_p19_func101_007);
                }
                else
                {
                    r_rsip_func_sub002(0x00000070U, 0x000003e0U, 0x00000250U, 0x04040006U);

                    r_rsip_func_sub041(0x00000250U, 0x000001b0U, 0x00000070U, 0x00000480U, 0x00000008U, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    static const uint32_t Param_p19_func101_008[] =
                    {
                        BSWAP_32BIG_C(0xc0a42587U), BSWAP_32BIG_C(0xfd25b2bdU), BSWAP_32BIG_C(0x9f7f5673U),
                        BSWAP_32BIG_C(0xeef4e4c5U),
                    };
                    r_rsip_func101(Param_p19_func101_008);
                }

                WR1_PROG(REG_1010H, 0x00000008U);

                WR1_PROG(REG_1404H, 0x15000000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16400000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1404H, 0x16900000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16e00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x1b400000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1404H, 0x1b900000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x1be00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                r_rsip_func_sub030(0x19b00000U, 0x00000bffU, 0x8088001fU);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x00000908U, 0x00000800U, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b660U, 0x00000001U, 0x0000b520U, 0x00000100U);

                r_rsip_func_sub009(0x00000019U);

                for (iLoop = 0U; iLoop < 256U; iLoop++)
                {
                    r_rsip_func405();

                    r_rsip_func403();

                    static const uint32_t Param_p19_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x9e9d8921U), BSWAP_32BIG_C(0x8c8729eeU), BSWAP_32BIG_C(0x933a2443U),
                        BSWAP_32BIG_C(0x589f61afU),
                    };
                    r_rsip_func101(Param_p19_func101_009);
                    r_rsip_func402();

                    r_rsip_func404();

                    WR1_PROG(REG_1600H, 0x00002d00U);

                    static const uint32_t Param_p19_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x9d2ef48eU), BSWAP_32BIG_C(0x2e24fb0dU), BSWAP_32BIG_C(0x258b9269U),
                        BSWAP_32BIG_C(0x93262a66U),
                    };
                    r_rsip_func101(Param_p19_func101_010);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x08000909U);

                r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000ca0U, 0x0404000aU);

                r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x00000cf0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x00000d40U, 0x0404000aU);

                WR1_PROG(REG_1444H, 0x000007c7U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1608H, 0x80880001U);
                for (iLoop = 8; iLoop < 16U; iLoop++)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, InData_Signature[iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
                WR1_PROG(REG_1600H, 0x0000001fU);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub030(0x19600000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_1404H, 0x12300000U);
                r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
                WR4_PROG(REG_1420H,
                         bswap_32big(0x0EEC73D2U),
                         bswap_32big(0x17F5BE65U),
                         bswap_32big(0xCB5C63AAU),
                         bswap_32big(0x97A331B5U));
                WAIT_STS(REG_1444H, 31, 1);
                WR4_PROG(REG_1420H,
                         bswap_32big(0x0665E1DBU),
                         bswap_32big(0x6EABA043U),
                         bswap_32big(0xF98B4BAAU),
                         bswap_32big(0x9C78F954U));
                r_rsip_func_sub001(0x00c20021U);

                WR1_PROG(REG_1404H, 0x12800000U);
                r_rsip_func_sub001(0x00c00021U);

                r_rsip_func_sub041(0x000002a0U, 0x00000250U, 0x000000c0U, 0x000002f0U, 0x00000010U, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                r_rsip_func_sub007(0x00000980U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                r_rsip_func_sub005(0x000003e0U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x000003e0U, 0x000002f0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000980U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1010H, 0x00000008U);

                static const uint32_t Param_p19_func100_011[] =
                {
                    BSWAP_32BIG_C(0xfabbdf1fU), BSWAP_32BIG_C(0xeea3d567U), BSWAP_32BIG_C(0xf9744cf6U), BSWAP_32BIG_C(
                        0x1766c596U),
                };
                r_rsip_func100(Param_p19_func100_011);
                r_rsip_func401(InData_DomainParam);

                WR1_PROG(REG_1404H, 0x15000000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16400000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1404H, 0x16900000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16e00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                r_rsip_func_sub030(0x19600000U, 0x00000bffU, 0x8088001fU);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x00000908U, 0x00000800U, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b660U, 0x00000001U, 0x0000b520U, 0x00000100U);

                r_rsip_func_sub009(0x00000119U);

                for (iLoop = 0U; iLoop < 256U; iLoop++)
                {
                    r_rsip_func405();

                    r_rsip_func403();

                    static const uint32_t Param_p19_func101_011[] =
                    {
                        BSWAP_32BIG_C(0xbb58e607U), BSWAP_32BIG_C(0x981aff62U), BSWAP_32BIG_C(0x3952e567U),
                        BSWAP_32BIG_C(0x90e87471U),
                    };
                    r_rsip_func101(Param_p19_func101_011);
                    r_rsip_func402();

                    r_rsip_func404();

                    WR1_PROG(REG_1600H, 0x00002d00U);

                    static const uint32_t Param_p19_func101_012[] =
                    {
                        BSWAP_32BIG_C(0xda30ba36U), BSWAP_32BIG_C(0xd2dd9e2eU), BSWAP_32BIG_C(0xfb54bcc6U),
                        BSWAP_32BIG_C(0xa26089d7U),
                    };
                    r_rsip_func101(Param_p19_func101_012);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x08000909U);

                r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000750U, 0x0404000aU);

                r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x000007a0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x000007f0U, 0x0404000aU);

                WR1_PROG(REG_1404H, 0x12300000U);
                r_rsip_func_sub001(0x00c00021U);

                r_rsip_func_sub038(0x00000250U, 0x00000ca0U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x04040006U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000b10U, 0x00000ca0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000ca0U, 0x00000b10U, 0x00000570U, 0x0404000aU);

                r_rsip_func_sub002(0x00000cf0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000d40U, 0x00000b10U, 0x00000610U, 0x0404000aU);

                r_rsip_func404();

                r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000570U, 0x0404000aU);

                r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x00000610U, 0x0404000aU);

                WR1_PROG(REG_1014H, 0x00000610U);
                r_rsip_func_sub040(0x00000070U, 0x00000250U, 0x00000008U, 0x04040004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x12d00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x000002f0U, 0x000002a0U, 0x04040006U);

                static const uint32_t Param_p19_func100_012[] =
                {
                    BSWAP_32BIG_C(0x8cc17499U), BSWAP_32BIG_C(0x8797ea31U), BSWAP_32BIG_C(0x7e0cc3ebU), BSWAP_32BIG_C(
                        0x1c082c3eU),
                };
                r_rsip_func100(Param_p19_func100_012);
                r_rsip_func_sub013(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x0404000fU, 0x00010001U);
                r_rsip_func_sub007(0x00000570U, 0x000002f0U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub007(0x000005c0U, 0x000002f0U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub030(0x12800000U, 0x00000821U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                WR1_PROG(REG_1600H, 0x00003801U);
                r_rsip_func_sub031(0x00008c00U, 0x7fffffffU, 0x12300000U);
                r_rsip_func_sub023(0x0000b420U, 0x00000020U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x0000b420U, 0x0000003cU, 0x00003841U, 0x001f6c42U);
                r_rsip_func_sub021(0x00001002U, 0x00000821U, 0x00003c01U, 0x00000800U);
                r_rsip_func_sub021(0x00000821U, 0x00000842U, 0x0000b460U, 0x0000001fU);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub030(0x12300000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_1404H, 0x14100000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x00000c50U, 0x000002a0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000c50U, 0x00000250U, 0x000002a0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p19_func100_013[] =
                {
                    BSWAP_32BIG_C(0xd49016abU), BSWAP_32BIG_C(0x261ddb8aU), BSWAP_32BIG_C(0x21362860U), BSWAP_32BIG_C(
                        0x3fb86223U),
                };
                r_rsip_func100(Param_p19_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p19_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xe3854cd7U), BSWAP_32BIG_C(0xcd502215U), BSWAP_32BIG_C(0xdd1b41c3U),
                        BSWAP_32BIG_C(0x952bd024U),
                    };
                    r_rsip_func102(Param_p19_func102_004);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p19_func102_005[] =
                    {
                        BSWAP_32BIG_C(0xed85bef1U), BSWAP_32BIG_C(0xca7a60ecU), BSWAP_32BIG_C(0x84d5a23eU),
                        BSWAP_32BIG_C(0x1679be45U),
                    };
                    r_rsip_func102(Param_p19_func102_005);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
