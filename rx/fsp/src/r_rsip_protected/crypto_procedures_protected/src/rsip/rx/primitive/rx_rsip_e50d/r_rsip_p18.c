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

rsip_ret_t r_rsip_p18 (const uint32_t InData_PrivKeyIndex[],
                       const uint32_t InData_PubKeyIndex[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MsgLen[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[],
                       uint64_t       MAX_CNT)
{
    uint64_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00180001U, 0x000008c8U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_PrivKeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000018U);

    static const uint32_t Param_p18_func101_001[] =
    {
        BSWAP_32BIG_C(0x437b6abcU), BSWAP_32BIG_C(0x8db0eb11U), BSWAP_32BIG_C(0x08c29bc0U), BSWAP_32BIG_C(0x7933e896U),
    };
    r_rsip_func101(Param_p18_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000027U);

    r_rsip_func_sub009(0x00000018U);

    static const uint32_t Param_p18_func101_002[] =
    {
        BSWAP_32BIG_C(0x8ffea838U), BSWAP_32BIG_C(0x3a405e25U), BSWAP_32BIG_C(0x394ed6e7U), BSWAP_32BIG_C(0x4ef9ec7cU),
    };
    r_rsip_func101(Param_p18_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x000007c2U, 0x40000100U, 0xf7009d07U);

    for (iLoop = 0U; iLoop < 8U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 1]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1608H, 0x80880000U);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p18_func100_001[] =
    {
        BSWAP_32BIG_C(0x262243f7U), BSWAP_32BIG_C(0x5fb77ae9U), BSWAP_32BIG_C(0x08e927e7U), BSWAP_32BIG_C(0x76a631a0U),
    };
    r_rsip_func100(Param_p18_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p18_func102_001[] =
        {
            BSWAP_32BIG_C(0x13901a70U), BSWAP_32BIG_C(0xdf159e5fU), BSWAP_32BIG_C(0x48f72201U), BSWAP_32BIG_C(
                0x966f4fcaU),
        };
        r_rsip_func102(Param_p18_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_PubKeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x00000118U);

        static const uint32_t Param_p18_func101_003[] =
        {
            BSWAP_32BIG_C(0x2a5ce75eU), BSWAP_32BIG_C(0x58530b0bU), BSWAP_32BIG_C(0xb4f4d03bU), BSWAP_32BIG_C(
                0x771715f5U),
        };
        r_rsip_func101(Param_p18_func101_003);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000026U);

        r_rsip_func_sub009(0x00000118U);

        static const uint32_t Param_p18_func101_004[] =
        {
            BSWAP_32BIG_C(0xf12aee4eU), BSWAP_32BIG_C(0x158aae88U), BSWAP_32BIG_C(0x62ef04f8U), BSWAP_32BIG_C(
                0x95033844U),
        };
        r_rsip_func101(Param_p18_func101_004);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub024(0x000007c2U, 0x40000100U, 0xe8009107U);

        for (iLoop = 0U; iLoop < 8U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x19100000U);
        r_rsip_func_sub001(0x00c20021U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_PubKeyIndex[iLoop + 1]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p18_func100_002[] =
        {
            BSWAP_32BIG_C(0x1ab6b3a0U), BSWAP_32BIG_C(0x5086baecU), BSWAP_32BIG_C(0xa2eb2753U), BSWAP_32BIG_C(
                0x0c43d372U),
        };
        r_rsip_func100(Param_p18_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p18_func102_002[] =
            {
                BSWAP_32BIG_C(0x95f2fcd9U), BSWAP_32BIG_C(0xadf7bfd1U), BSWAP_32BIG_C(0xe085b540U), BSWAP_32BIG_C(
                    0xe453cadfU),
            };
            r_rsip_func102(Param_p18_func102_002);
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

            static const uint32_t Param_p18_func100_003[] =
            {
                BSWAP_32BIG_C(0xc66933c0U), BSWAP_32BIG_C(0x68030193U), BSWAP_32BIG_C(0xeb8c823cU), BSWAP_32BIG_C(
                    0xb2d9bcbfU),
            };
            r_rsip_func100(Param_p18_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p18_func102_003[] =
                {
                    BSWAP_32BIG_C(0x49795b0bU), BSWAP_32BIG_C(0x484d4c7cU), BSWAP_32BIG_C(0xcc0bbf5aU), BSWAP_32BIG_C(
                        0x29e4f094U),
                };
                r_rsip_func102(Param_p18_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p18_func100_004[] =
                {
                    BSWAP_32BIG_C(0x5bb378eaU), BSWAP_32BIG_C(0x37e820f1U), BSWAP_32BIG_C(0xcb9ec880U), BSWAP_32BIG_C(
                        0x848e7e3cU),
                };
                r_rsip_func100(Param_p18_func100_004);
                r_rsip_func_sub021(0x00000842U, 0x0c00a420U, 0x00000100U, 0x00802402U);

                r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

                static const uint32_t Param_p18_func100_005[] =
                {
                    BSWAP_32BIG_C(0xdc7460bcU), BSWAP_32BIG_C(0x4ac7ce57U), BSWAP_32BIG_C(0x255198eeU), BSWAP_32BIG_C(
                        0xb9e0fcbdU),
                };
                r_rsip_func100(Param_p18_func100_005);
                r_rsip_func_sub021(0x00000842U, 0x0c00a420U, 0x00000100U, 0x00802402U);

                r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                RD1_ADDR(REG_1420H, &S_RAM[0 + 2]);
                S_RAM[0 + 2] = bswap_32big(S_RAM[0 + 2]);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &S_RAM[0 + 3]);
                S_RAM[0 + 3] = bswap_32big(S_RAM[0 + 3]);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000100U);

                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1608H, 0x8188001eU);
                r_rsip_func_sub001(0x01490021U);

                WAIT_STS(REG_2030H, 4, 1);

                r_rsip_func_sub023(0x00000821U, 0x00000842U, 0x80900001U);
                r_rsip_func_sub001(0x03450041U);

                r_rsip_func_sub021(0x00003841U, 0x00008c40U, 0xf8ffffffU, 0x00003c41U);

                r_rsip_func_sub021(0x0000b420U, 0x0000001cU, 0x00003841U, 0x00008c40U);
                r_rsip_func_sub021(0xffffff3fU, 0x00009040U, 0x00000040U, 0x00003c41U);

                r_rsip_func_sub030(0x19600000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

                r_rsip_func_sub023(0x0000b420U, 0x00000020U, 0x81880001U);
                r_rsip_func_sub001(0x01490021U);

                WR1_PROG(REG_1444H, 0x00020064U);

                for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffffffffffff0U); iLoop = iLoop + 8U)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR8_ADDR(REG_1420H, &InData_Msg[iLoop]);
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

                WR1_PROG(REG_1004H, 0x00000000U);
                WR1_PROG(REG_1004H, 0x04040000U);

                static const uint32_t Param_p18_func100_006[] =
                {
                    BSWAP_32BIG_C(0x97661a43U), BSWAP_32BIG_C(0x9ca21907U), BSWAP_32BIG_C(0x48bcc691U), BSWAP_32BIG_C(
                        0x121f1893U),
                };
                r_rsip_func100(Param_p18_func100_006);
                r_rsip_func401(InData_DomainParam);

                static const uint32_t Param_p18_func100_007[] =
                {
                    BSWAP_32BIG_C(0xb8b264f5U), BSWAP_32BIG_C(0x9c8bd086U), BSWAP_32BIG_C(0x6c8bf4cdU), BSWAP_32BIG_C(
                        0x462f7820U),
                };
                r_rsip_func100(Param_p18_func100_007);
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

                r_rsip_func_sub030(0x12800000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                r_rsip_func_sub041(0x00000250U, 0x000002a0U, 0x000000c0U, 0x000002f0U, 0x00000010U, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub012(0x12300000U, 0x0000b420U, 0x00000020U);
                WR1_PROG(REG_1608H, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                r_rsip_func_sub038(0x00000250U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x000002a0U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                r_rsip_func_sub005(0x00000250U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x00000250U, 0x000002f0U, 0x000000c0U);
                r_rsip_func_sub005(0x000009d0U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

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

                r_rsip_func_sub009(0x00000018U);

                for (iLoop = 0U; iLoop < 256U; iLoop++)
                {
                    r_rsip_func405();

                    r_rsip_func403();

                    static const uint32_t Param_p18_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x8629bfa8U), BSWAP_32BIG_C(0x825704bbU), BSWAP_32BIG_C(0x60f80366U),
                        BSWAP_32BIG_C(0xd6511898U),
                    };
                    r_rsip_func101(Param_p18_func101_005);
                    r_rsip_func402();

                    r_rsip_func404();

                    WR1_PROG(REG_1600H, 0x00002d00U);

                    static const uint32_t Param_p18_func101_006[] =
                    {
                        BSWAP_32BIG_C(0xac4735f8U), BSWAP_32BIG_C(0xb34b408aU), BSWAP_32BIG_C(0x6ce43c3fU),
                        BSWAP_32BIG_C(0x018fc0c4U),
                    };
                    r_rsip_func101(Param_p18_func101_006);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x08000909U);

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

                r_rsip_func_sub002(0x00000070U, 0x000002f0U, 0x000002a0U, 0x0404000aU);

                static const uint32_t Param_p18_func100_008[] =
                {
                    BSWAP_32BIG_C(0x0d47a4b3U), BSWAP_32BIG_C(0xd0903978U), BSWAP_32BIG_C(0x211da647U), BSWAP_32BIG_C(
                        0xe641c531U),
                };
                r_rsip_func100(Param_p18_func100_008);
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

                r_rsip_func_sub030(0x1c300000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub033(0x00000040U, S_RAM[0 + 2], 0x00000040U, S_RAM[0 + 3]);

                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1608H, 0x81880001U);
                r_rsip_func_sub001(0x01490021U);

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

                r_rsip_func_sub030(0x19600000U, 0x00000821U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

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

                r_rsip_func_sub041(0x00000250U, 0x00000a20U, 0x000000c0U, 0x000002a0U, 0x00000010U, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                r_rsip_func_sub007(0x00000a70U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                r_rsip_func_sub005(0x000003e0U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x000003e0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000340U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000980U, 0x00000b10U, 0x00000430U, 0x0404000aU);

                r_rsip_func_sub041(0x00000200U, 0x00000340U, 0x000000c0U, 0x00000390U, 0x00000010U, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                r_rsip_func_sub007(0x00000390U, 0x00000430U, 0x000000c0U);
                r_rsip_func_sub005(0x000003e0U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000009d0U, 0x00000b10U, 0x000002f0U, 0x0404000aU);

                r_rsip_func_sub038(0x000002f0U, 0x000003e0U, 0x000000c0U);
                r_rsip_func_sub005(0x000002a0U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
                WR1_PROG(REG_1600H, 0x0000001fU);

                WR1_PROG(REG_1404H, 0x12800000U);
                WR1_PROG(REG_1608H, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                static const uint32_t Param_p18_func100_009[] =
                {
                    BSWAP_32BIG_C(0x1937604eU), BSWAP_32BIG_C(0xd497401fU), BSWAP_32BIG_C(0x306bc056U), BSWAP_32BIG_C(
                        0xc21fd30bU),
                };
                r_rsip_func100(Param_p18_func100_009);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);

                WR1_PROG(REG_1404H, 0x1c300000U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Signature[0]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Signature[4]);

                static const uint32_t Param_p18_func100_010[] =
                {
                    BSWAP_32BIG_C(0x0d3bdfd6U), BSWAP_32BIG_C(0x39961bdcU), BSWAP_32BIG_C(0xeab7c7feU), BSWAP_32BIG_C(
                        0x8bde7becU),
                };
                r_rsip_func100(Param_p18_func100_010);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1408H, 0x00005022U);
                for (iLoop = 8; iLoop < 16U; iLoop++)
                {
                    WAIT_STS(REG_1408H, 30, 1);
                    RD1_ADDR(REG_1420H, &OutData_Signature[iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p18_func102_004[] =
                {
                    BSWAP_32BIG_C(0x3cc94f4fU), BSWAP_32BIG_C(0x6463cefcU), BSWAP_32BIG_C(0xe4d194cfU), BSWAP_32BIG_C(
                        0x1fd9bc29U),
                };
                r_rsip_func102(Param_p18_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
