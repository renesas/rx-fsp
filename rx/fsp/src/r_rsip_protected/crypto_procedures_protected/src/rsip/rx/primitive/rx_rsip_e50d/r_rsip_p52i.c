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

rsip_ret_t r_rsip_p52i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00520001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00005201U);

    static const uint32_t Param_p52i_func101_001[] =
    {
        BSWAP_32BIG_C(0xd55430d8U), BSWAP_32BIG_C(0x594b16d4U), BSWAP_32BIG_C(0x11d16b23U), BSWAP_32BIG_C(0x7d477beeU),
    };
    r_rsip_func101(Param_p52i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000024U);

    r_rsip_func_sub009(0x00005201U);

    static const uint32_t Param_p52i_func101_002[] =
    {
        BSWAP_32BIG_C(0xaf2c28d8U), BSWAP_32BIG_C(0x50e15207U), BSWAP_32BIG_C(0x26af48ffU), BSWAP_32BIG_C(0xd1bbe0e5U),
    };
    r_rsip_func101(Param_p52i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000027c2U, 0x40000900U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80a80001U);
    for (iLoop = 0U; iLoop < 40U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[41]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p52i_func100_001[] =
    {
        BSWAP_32BIG_C(0x88492ab8U), BSWAP_32BIG_C(0x0e4630faU), BSWAP_32BIG_C(0x13007412U), BSWAP_32BIG_C(0x2750f68bU),
    };
    r_rsip_func100(Param_p52i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p52i_func102_001[] =
        {
            BSWAP_32BIG_C(0x31f9155aU), BSWAP_32BIG_C(0xcac3b040U), BSWAP_32BIG_C(0x91c1ce9aU), BSWAP_32BIG_C(
                0x7fb2c3e0U),
        };
        r_rsip_func102(Param_p52i_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000fc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x8090001fU);
        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
        }

        r_rsip_func_sub034(0x00000bdeU, 0x0000b7e0U);
        WR1_PROG(REG_1600H, 0x00000100U);

        WR1_PROG(REG_1A2CH, 0x00000300U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1608H, 0x8184001eU);
            r_rsip_func_sub001(0x00890011U);
            WR1_PROG(REG_1608H, 0x8084001fU);
            r_rsip_func_sub001(0x03420011U);

            r_rsip_func_sub021(0x0000a7c0U, 0x00000010U, 0x0000a7e0U, 0x00000010U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x80010360U, 0x00000052U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p52i_func100_002[] =
        {
            BSWAP_32BIG_C(0x4fb7decaU), BSWAP_32BIG_C(0x0672fad4U), BSWAP_32BIG_C(0x91234faaU), BSWAP_32BIG_C(
                0x38dab5b2U),
        };
        r_rsip_func100(Param_p52i_func100_002);
        r_rsip_func086(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

        WR1_PROG(REG_1404H, 0x18e00000U);
        r_rsip_func_sub008(0x000027c2U, 0x00000900U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);

        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        r_rsip_func_sub001(0x00c20021U);

        WR1_PROG(REG_1404H, 0x19300000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[24]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[28]);
        r_rsip_func_sub001(0x00c20031U);

        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[32]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[36]);
        r_rsip_func_sub001(0x00c20021U);

        WR1_PROG(REG_1404H, 0x11b80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c00045U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0909000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p52i_func100_003[] =
        {
            BSWAP_32BIG_C(0xb22ac0d1U), BSWAP_32BIG_C(0xfd1aac5dU), BSWAP_32BIG_C(0xc1d0d9daU), BSWAP_32BIG_C(
                0xead15328U),
        };
        r_rsip_func100(Param_p52i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p52i_func101_003[] =
            {
                BSWAP_32BIG_C(0x743a001cU), BSWAP_32BIG_C(0x59d6c18bU), BSWAP_32BIG_C(0xa93c9badU), BSWAP_32BIG_C(
                    0xb2f735ddU),
            };
            r_rsip_func101(Param_p52i_func101_003);
        }
        else
        {
            static const uint32_t Param_p52i_func100_004[] =
            {
                BSWAP_32BIG_C(0xdf226875U), BSWAP_32BIG_C(0x5d470634U), BSWAP_32BIG_C(0x8e7c6cceU), BSWAP_32BIG_C(
                    0xd9ad883aU),
            };
            r_rsip_func100(Param_p52i_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0909000aU);

            r_rsip_func_sub041(0x00000980U, 0x000001b0U, 0x000000c0U, 0x00000110U, 0x00000020U, 0x0909000fU);
            r_rsip_func_sub035(0x00010001U);

            r_rsip_func_sub038(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x10c00000U);
            r_rsip_func_sub001(0x00c00011U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8190001fU);
            r_rsip_func_sub001(0x00c90041U);

            r_rsip_func_sub038(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x09090002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11180000U);
            r_rsip_func_sub001(0x00c00049U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x09090004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002a0U, 0x09090009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x09090009U);

            WR1_PROG(REG_1404H, 0x10c00000U);
            WR1_PROG(REG_1608H, 0x81940001U);
            r_rsip_func_sub001(0x00c90051U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x000009d0U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10c00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1608H, 0x8194001fU);
            r_rsip_func_sub001(0x00c90051U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a20U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p52i_func100_005[] =
            {
                BSWAP_32BIG_C(0xcda31138U), BSWAP_32BIG_C(0xd9be8c7fU), BSWAP_32BIG_C(0x51f93af7U), BSWAP_32BIG_C(
                    0x516733a2U),
            };
            r_rsip_func100(Param_p52i_func100_005);
            r_rsip_func087(InData_DomainParam);

            r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000ac0U, 0x09090009U);

            r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000b10U, 0x09090009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x09090009U);

            r_rsip_func_sub002(0x00000ac0U, 0x000009d0U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x000009d0U, 0x00000ac0U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p52i_func100_006[] =
            {
                BSWAP_32BIG_C(0x4dc83a38U), BSWAP_32BIG_C(0x5d1d2c76U), BSWAP_32BIG_C(0xfee41769U), BSWAP_32BIG_C(
                    0x4536163fU),
            };
            r_rsip_func100(Param_p52i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub038(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x09090013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p52i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xb04cdaa0U), BSWAP_32BIG_C(0x91672858U), BSWAP_32BIG_C(0xda8414fbU), BSWAP_32BIG_C(
                        0x99aab9f7U),
                };
                r_rsip_func101(Param_p52i_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x09090014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p52i_func101_005[] =
                {
                    BSWAP_32BIG_C(0xd3ae3eeeU), BSWAP_32BIG_C(0x826ee070U), BSWAP_32BIG_C(0xc0c90a42U), BSWAP_32BIG_C(
                        0xd12050d8U),
                };
                r_rsip_func101(Param_p52i_func101_005);
            }

            WR1_PROG(REG_1600H, 0x00000821U);

            WR1_PROG(REG_1404H, 0x14380000U);
            WR1_PROG(REG_1608H, 0x80920001U);
            r_rsip_func_sub001(0x03430049U);

            r_rsip_func_sub031(0x0000a420U, 0x00000050U, 0x12f80000U);
            WR1_PROG(REG_1608H, 0x80920001U);
            r_rsip_func_sub001(0x03430049U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 18U; iLoop++)
            {
                r_rsip_func_sub021(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub022(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11180000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c00045U);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_p52i_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x3ee6bc90U), BSWAP_32BIG_C(0xbab4c207U), BSWAP_32BIG_C(0xf533823aU),
                        BSWAP_32BIG_C(0x1d3c6f4eU),
                    };
                    r_rsip_func100(Param_p52i_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p52i_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x4d71c06cU), BSWAP_32BIG_C(0xa6dc40b0U), BSWAP_32BIG_C(0x81c9f922U),
                            BSWAP_32BIG_C(0x8f7607b2U),
                        };
                        r_rsip_func101(Param_p52i_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p52i_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x8ff66e2eU), BSWAP_32BIG_C(0x4b3d28b3U), BSWAP_32BIG_C(0xbdac471bU),
                            BSWAP_32BIG_C(0x05aefec8U),
                        };
                        r_rsip_func101(Param_p52i_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p52i_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x16e1cb80U), BSWAP_32BIG_C(0xe1c60237U), BSWAP_32BIG_C(0x3deda8bfU),
                        BSWAP_32BIG_C(0xd8537a50U),
                    };
                    r_rsip_func100(Param_p52i_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p52i_func100_009[] =
                        {
                            BSWAP_32BIG_C(0xb54e8a23U), BSWAP_32BIG_C(0x310091f0U), BSWAP_32BIG_C(0x99bc5658U),
                            BSWAP_32BIG_C(0x2db67452U),
                        };
                        r_rsip_func100(Param_p52i_func100_009);

                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_func_sub001(0x00c00049U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009d0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a20U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x9c003f14U), BSWAP_32BIG_C(0x0e8c4654U), BSWAP_32BIG_C(0x22a71be6U),
                                BSWAP_32BIG_C(0x988b735aU),
                            };
                            r_rsip_func101(Param_p52i_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ac0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b10U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_009[] =
                            {
                                BSWAP_32BIG_C(0xed68ff1fU), BSWAP_32BIG_C(0xf838d07dU), BSWAP_32BIG_C(0x7fdbfd8bU),
                                BSWAP_32BIG_C(0x890e41f0U),
                            };
                            r_rsip_func101(Param_p52i_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bb0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c00U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x179732efU), BSWAP_32BIG_C(0xb4651d63U), BSWAP_32BIG_C(0x38183ca7U),
                                BSWAP_32BIG_C(0xa760a1b0U),
                            };
                            r_rsip_func101(Param_p52i_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c00045U);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_p52i_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x1686fbebU), BSWAP_32BIG_C(0x97024028U), BSWAP_32BIG_C(0x8d74a1c3U),
                            BSWAP_32BIG_C(0x38a5ba9cU),
                        };
                        r_rsip_func100(Param_p52i_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p52i_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x4cfd78e5U), BSWAP_32BIG_C(0x3fd46670U), BSWAP_32BIG_C(0x682dc518U),
                                BSWAP_32BIG_C(0x8ec53cf8U),
                            };
                            r_rsip_func100(Param_p52i_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001b0U, 0x000003e0U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x000003e0U, 0x000001b0U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000200U, 0x00000430U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000430U, 0x00000200U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_p52i_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0xa1f28405U), BSWAP_32BIG_C(0x7d33f4f8U), BSWAP_32BIG_C(0x23837d5dU),
                                    BSWAP_32BIG_C(0xa200b9f6U),
                                };
                                r_rsip_func100(Param_p52i_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub038(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p52i_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x2ca89db6U), BSWAP_32BIG_C(0x15650014U), BSWAP_32BIG_C(
                                            0xd81050d8U),           BSWAP_32BIG_C(0x4f7fab0fU),
                                    };
                                    r_rsip_func101(Param_p52i_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p52i_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x70f49fc0U), BSWAP_32BIG_C(0xea82da08U), BSWAP_32BIG_C(
                                            0x5e8987f8U),           BSWAP_32BIG_C(0x44c2094bU),
                                    };
                                    r_rsip_func101(Param_p52i_func101_012);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                            }
                            else
                            {
                                static const uint32_t Param_p52i_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x5cf13b0bU), BSWAP_32BIG_C(0x23f1dcbaU), BSWAP_32BIG_C(0xe9bba615U),
                                    BSWAP_32BIG_C(0xb505ed95U),
                                };
                                r_rsip_func101(Param_p52i_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11180000U);
                            r_rsip_func_sub001(0x00c00049U);

                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x4e40ff8bU), BSWAP_32BIG_C(0x5d841441U), BSWAP_32BIG_C(0x26deba09U),
                                BSWAP_32BIG_C(0xcff9cd42U),
                            };
                            r_rsip_func101(Param_p52i_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p52i_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x79de3876U), BSWAP_32BIG_C(0xf9910214U), BSWAP_32BIG_C(0x8164888cU),
                            BSWAP_32BIG_C(0x340c040dU),
                        };
                        r_rsip_func101(Param_p52i_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p52i_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xaef4ea61U), BSWAP_32BIG_C(0x118f4721U), BSWAP_32BIG_C(0x3205b519U),
                        BSWAP_32BIG_C(0xcbf84057U),
                    };
                    r_rsip_func101(Param_p52i_func101_016);
                }

                WR1_PROG(REG_1600H, 0x38008840U);
                r_rsip_func_sub011(0x00000020U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p52i_func101_017[] =
                {
                    BSWAP_32BIG_C(0x0a88314fU), BSWAP_32BIG_C(0x090bb940U), BSWAP_32BIG_C(0x4cd940f1U), BSWAP_32BIG_C(
                        0x1d50ab5aU),
                };
                r_rsip_func101(Param_p52i_func101_017);
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            r_rsip_func_sub011(0x00000012U);

            WR1_PROG(REG_1404H, 0x12580000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c00045U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p52i_func100_013[] =
            {
                BSWAP_32BIG_C(0x0dfa676aU), BSWAP_32BIG_C(0xa97e18a7U), BSWAP_32BIG_C(0xaf0c6a37U), BSWAP_32BIG_C(
                    0x817033ebU),
            };
            r_rsip_func100(Param_p52i_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p52i_func101_018[] =
                {
                    BSWAP_32BIG_C(0xc758b21bU), BSWAP_32BIG_C(0xeac7f26cU), BSWAP_32BIG_C(0x7851638bU), BSWAP_32BIG_C(
                        0x80d9fe9bU),
                };
                r_rsip_func101(Param_p52i_func101_018);
            }
            else
            {
                static const uint32_t Param_p52i_func100_014[] =
                {
                    BSWAP_32BIG_C(0x7e4a561fU), BSWAP_32BIG_C(0x565c3f7bU), BSWAP_32BIG_C(0x89ec0a10U), BSWAP_32BIG_C(
                        0x234c4fa8U),
                };
                r_rsip_func100(Param_p52i_func100_014);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x09090004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);

                r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub038(0x000001b0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p52i_func100_015[] =
                {
                    BSWAP_32BIG_C(0xd2bdb70cU), BSWAP_32BIG_C(0xa2da66e2U), BSWAP_32BIG_C(0xe4a6544bU), BSWAP_32BIG_C(
                        0x64b95abdU),
                };
                r_rsip_func100(Param_p52i_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p52i_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xba263731U), BSWAP_32BIG_C(0xd015db20U), BSWAP_32BIG_C(0x8a170049U),
                        BSWAP_32BIG_C(0xb0349451U),
                    };
                    r_rsip_func101(Param_p52i_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xa69ef2d0U);

                    static const uint32_t Param_p52i_func101_020[] =
                    {
                        BSWAP_32BIG_C(0xcb249a62U), BSWAP_32BIG_C(0xd299666dU), BSWAP_32BIG_C(0x6e87edcdU),
                        BSWAP_32BIG_C(0x8dd58c2fU),
                    };
                    r_rsip_func101(Param_p52i_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0xa69ef2d0U, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p52i_func100_016[] =
        {
            BSWAP_32BIG_C(0xb32b6000U), BSWAP_32BIG_C(0xdd131494U), BSWAP_32BIG_C(0x60806bbfU), BSWAP_32BIG_C(
                0x2431a6fbU),
        };
        r_rsip_func100(Param_p52i_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p52i_func102_002[] =
            {
                BSWAP_32BIG_C(0x9789aa1eU), BSWAP_32BIG_C(0x66951454U), BSWAP_32BIG_C(0xdb8daf0fU), BSWAP_32BIG_C(
                    0xe573b445U),
            };
            r_rsip_func102(Param_p52i_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub022(0x0000b7c0U, 0x00000100U, 0x00000bffU);

            WR1_PROG(REG_1A2CH, 0x00000300U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
            {
                WR1_PROG(REG_1608H, 0x8184001eU);
                r_rsip_func_sub001(0x00890011U);
                WR1_PROG(REG_1608H, 0x8084001fU);
                r_rsip_func_sub001(0x03420011U);

                r_rsip_func_sub021(0x0000a7c0U, 0x00000010U, 0x0000a7e0U, 0x00000010U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p52i_func101_021[] =
            {
                BSWAP_32BIG_C(0xbe65136aU), BSWAP_32BIG_C(0x0026e863U), BSWAP_32BIG_C(0xfb22fdcaU), BSWAP_32BIG_C(
                    0x44230ef1U),
            };
            r_rsip_func101(Param_p52i_func101_021);

            return RSIP_RET_PASS;
        }
    }
}
