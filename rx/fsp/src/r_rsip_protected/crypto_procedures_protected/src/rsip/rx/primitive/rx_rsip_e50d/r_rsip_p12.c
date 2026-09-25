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

rsip_ret_t r_rsip_p12 (const uint32_t InData_KeyIndex[],
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

    r_rsip_func_sub029(0x00120001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00000012U);

    static const uint32_t Param_p12_func101_001[] =
    {
        BSWAP_32BIG_C(0x820f4b06U), BSWAP_32BIG_C(0x6fc23f01U), BSWAP_32BIG_C(0xcb199886U), BSWAP_32BIG_C(0xd7b1d8ceU),
    };
    r_rsip_func101(Param_p12_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000024U);

    r_rsip_func_sub009(0x00000012U);

    static const uint32_t Param_p12_func101_002[] =
    {
        BSWAP_32BIG_C(0xc3117014U), BSWAP_32BIG_C(0x836c8a1eU), BSWAP_32BIG_C(0x6f3a1cd0U), BSWAP_32BIG_C(0xe4b91aabU),
    };
    r_rsip_func101(Param_p12_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000027c2U, 0x40000900U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80a80001U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
    r_rsip_func_sub001(0x03420031U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);
    r_rsip_func_sub001(0x03420021U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[21]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[25]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[29]);
    r_rsip_func_sub001(0x03420031U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[33]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[37]);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[41]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p12_func100_001[] =
    {
        BSWAP_32BIG_C(0xa37da844U), BSWAP_32BIG_C(0x20a54e53U), BSWAP_32BIG_C(0x9d47c723U), BSWAP_32BIG_C(0x70113728U),
    };
    r_rsip_func100(Param_p12_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p12_func102_001[] =
        {
            BSWAP_32BIG_C(0xeb210ff2U), BSWAP_32BIG_C(0x2d55eb54U), BSWAP_32BIG_C(0xcb3770f7U), BSWAP_32BIG_C(
                0x3861dfe0U),
        };
        r_rsip_func102(Param_p12_func102_001);
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

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x80010360U, 0x00000012U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p12_func100_002[] =
        {
            BSWAP_32BIG_C(0xc0667d75U), BSWAP_32BIG_C(0x4d938309U), BSWAP_32BIG_C(0x59be1551U), BSWAP_32BIG_C(
                0x4f00c39fU),
        };
        r_rsip_func100(Param_p12_func100_002);
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

        static const uint32_t Param_p12_func100_003[] =
        {
            BSWAP_32BIG_C(0x2976eeefU), BSWAP_32BIG_C(0x9fc72673U), BSWAP_32BIG_C(0xdc2c26d9U), BSWAP_32BIG_C(
                0x53825ebaU),
        };
        r_rsip_func100(Param_p12_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p12_func101_003[] =
            {
                BSWAP_32BIG_C(0x3bb469a6U), BSWAP_32BIG_C(0xfdd66e19U), BSWAP_32BIG_C(0x26a2e073U), BSWAP_32BIG_C(
                    0x264aa9b4U),
            };
            r_rsip_func101(Param_p12_func101_003);
        }
        else
        {
            static const uint32_t Param_p12_func100_004[] =
            {
                BSWAP_32BIG_C(0x09a46579U), BSWAP_32BIG_C(0x3f444b89U), BSWAP_32BIG_C(0x0ffcfc56U), BSWAP_32BIG_C(
                    0x6030c341U),
            };
            r_rsip_func100(Param_p12_func100_004);

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

            static const uint32_t Param_p12_func100_005[] =
            {
                BSWAP_32BIG_C(0x554ac72dU), BSWAP_32BIG_C(0x8117a88aU), BSWAP_32BIG_C(0xe5e177cdU), BSWAP_32BIG_C(
                    0x91ad67e6U),
            };
            r_rsip_func100(Param_p12_func100_005);
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

            static const uint32_t Param_p12_func100_006[] =
            {
                BSWAP_32BIG_C(0x892e5595U), BSWAP_32BIG_C(0xf02e3115U), BSWAP_32BIG_C(0xc88feffbU), BSWAP_32BIG_C(
                    0xa21ef56bU),
            };
            r_rsip_func100(Param_p12_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub038(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x09090013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p12_func101_004[] =
                {
                    BSWAP_32BIG_C(0x92ac170cU), BSWAP_32BIG_C(0xf886041dU), BSWAP_32BIG_C(0x4abcd66dU), BSWAP_32BIG_C(
                        0xf79ed4f7U),
                };
                r_rsip_func101(Param_p12_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x09090014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p12_func101_005[] =
                {
                    BSWAP_32BIG_C(0xc1e0ad75U), BSWAP_32BIG_C(0xa19bfd04U), BSWAP_32BIG_C(0x09445ccfU), BSWAP_32BIG_C(
                        0x0e3af98eU),
                };
                r_rsip_func101(Param_p12_func101_005);
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

                    static const uint32_t Param_p12_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x91c138d8U), BSWAP_32BIG_C(0x9812f32dU), BSWAP_32BIG_C(0x1cd953f6U),
                        BSWAP_32BIG_C(0x7d5e538dU),
                    };
                    r_rsip_func100(Param_p12_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p12_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x6bd4c97fU), BSWAP_32BIG_C(0x52bbdfddU), BSWAP_32BIG_C(0x31bdd2b3U),
                            BSWAP_32BIG_C(0x83ac9741U),
                        };
                        r_rsip_func101(Param_p12_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p12_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x2e5055f7U), BSWAP_32BIG_C(0x1336a958U), BSWAP_32BIG_C(0x7310f2b1U),
                            BSWAP_32BIG_C(0x6ab5a435U),
                        };
                        r_rsip_func101(Param_p12_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p12_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x9a52ea47U), BSWAP_32BIG_C(0xb92a5515U), BSWAP_32BIG_C(0xd001a37fU),
                        BSWAP_32BIG_C(0x2fd40f05U),
                    };
                    r_rsip_func100(Param_p12_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p12_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x2bc8e0eeU), BSWAP_32BIG_C(0x75c7962cU), BSWAP_32BIG_C(0xe0c6a80dU),
                            BSWAP_32BIG_C(0x2a5ea8b6U),
                        };
                        r_rsip_func100(Param_p12_func100_009);

                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_func_sub001(0x00c00049U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009d0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a20U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p12_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x6c691e54U), BSWAP_32BIG_C(0xfcc13c01U), BSWAP_32BIG_C(0x2f4d6284U),
                                BSWAP_32BIG_C(0xdce3c126U),
                            };
                            r_rsip_func101(Param_p12_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ac0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b10U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p12_func101_009[] =
                            {
                                BSWAP_32BIG_C(0x55cf1fd8U), BSWAP_32BIG_C(0x4067e86aU), BSWAP_32BIG_C(0x4a7459e4U),
                                BSWAP_32BIG_C(0x9ab04d9fU),
                            };
                            r_rsip_func101(Param_p12_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bb0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c00U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p12_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x9acc0c3eU), BSWAP_32BIG_C(0xc015a7b4U), BSWAP_32BIG_C(0xa0f25dbdU),
                                BSWAP_32BIG_C(0x28c4dd92U),
                            };
                            r_rsip_func101(Param_p12_func101_010);
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

                        static const uint32_t Param_p12_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x812ac3b7U), BSWAP_32BIG_C(0x717ae7b1U), BSWAP_32BIG_C(0xf74eb17cU),
                            BSWAP_32BIG_C(0xf866f61cU),
                        };
                        r_rsip_func100(Param_p12_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p12_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x7e046264U), BSWAP_32BIG_C(0xd9a2825fU), BSWAP_32BIG_C(0xec97b177U),
                                BSWAP_32BIG_C(0x19ce7ec7U),
                            };
                            r_rsip_func100(Param_p12_func100_011);
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

                                static const uint32_t Param_p12_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0x29516438U), BSWAP_32BIG_C(0xc8a24333U), BSWAP_32BIG_C(0x7419f579U),
                                    BSWAP_32BIG_C(0x13154665U),
                                };
                                r_rsip_func100(Param_p12_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub038(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p12_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0xdf7a4999U), BSWAP_32BIG_C(0x5815b9c5U), BSWAP_32BIG_C(
                                            0x6c6e2561U),           BSWAP_32BIG_C(0x70e85f9aU),
                                    };
                                    r_rsip_func101(Param_p12_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p12_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x5f580cb6U), BSWAP_32BIG_C(0x909964dfU), BSWAP_32BIG_C(
                                            0x62949959U),           BSWAP_32BIG_C(0x4a63e645U),
                                    };
                                    r_rsip_func101(Param_p12_func101_012);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                            }
                            else
                            {
                                static const uint32_t Param_p12_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x379cb3d4U), BSWAP_32BIG_C(0x2ecf541cU), BSWAP_32BIG_C(0xd2022877U),
                                    BSWAP_32BIG_C(0x6be44f7fU),
                                };
                                r_rsip_func101(Param_p12_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11180000U);
                            r_rsip_func_sub001(0x00c00049U);

                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);

                            static const uint32_t Param_p12_func101_014[] =
                            {
                                BSWAP_32BIG_C(0xfa1561fcU), BSWAP_32BIG_C(0xb6da204dU), BSWAP_32BIG_C(0x82cdc970U),
                                BSWAP_32BIG_C(0x29aef3f3U),
                            };
                            r_rsip_func101(Param_p12_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p12_func101_015[] =
                        {
                            BSWAP_32BIG_C(0xb056db8bU), BSWAP_32BIG_C(0xd87fdf59U), BSWAP_32BIG_C(0x7a25f7beU),
                            BSWAP_32BIG_C(0x68e2d279U),
                        };
                        r_rsip_func101(Param_p12_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p12_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x3e2bb3edU), BSWAP_32BIG_C(0xeaa94314U), BSWAP_32BIG_C(0x6a343176U),
                        BSWAP_32BIG_C(0xd85ec9a2U),
                    };
                    r_rsip_func101(Param_p12_func101_016);
                }

                WR1_PROG(REG_1600H, 0x38008840U);
                r_rsip_func_sub011(0x00000020U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p12_func101_017[] =
                {
                    BSWAP_32BIG_C(0x5f808741U), BSWAP_32BIG_C(0x5093d719U), BSWAP_32BIG_C(0x609eec5aU), BSWAP_32BIG_C(
                        0x10cb5dfcU),
                };
                r_rsip_func101(Param_p12_func101_017);
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

            static const uint32_t Param_p12_func100_013[] =
            {
                BSWAP_32BIG_C(0x5d1469a4U), BSWAP_32BIG_C(0x886f7beeU), BSWAP_32BIG_C(0x348a3832U), BSWAP_32BIG_C(
                    0x082b38d0U),
            };
            r_rsip_func100(Param_p12_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p12_func101_018[] =
                {
                    BSWAP_32BIG_C(0xcd30e901U), BSWAP_32BIG_C(0xf58a0489U), BSWAP_32BIG_C(0x929a4454U), BSWAP_32BIG_C(
                        0x7766d336U),
                };
                r_rsip_func101(Param_p12_func101_018);
            }
            else
            {
                static const uint32_t Param_p12_func100_014[] =
                {
                    BSWAP_32BIG_C(0xfb745d24U), BSWAP_32BIG_C(0x0c1840c0U), BSWAP_32BIG_C(0x05b4cc52U), BSWAP_32BIG_C(
                        0x82641534U),
                };
                r_rsip_func100(Param_p12_func100_014);

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

                static const uint32_t Param_p12_func100_015[] =
                {
                    BSWAP_32BIG_C(0x3f8ae844U), BSWAP_32BIG_C(0xad4a9e44U), BSWAP_32BIG_C(0xcdd9d2a5U), BSWAP_32BIG_C(
                        0xa6e25020U),
                };
                r_rsip_func100(Param_p12_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p12_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xa0e7756cU), BSWAP_32BIG_C(0xbc8e9069U), BSWAP_32BIG_C(0x9ad3c818U),
                        BSWAP_32BIG_C(0x0a46cd68U),
                    };
                    r_rsip_func101(Param_p12_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xa69ef2d0U);

                    static const uint32_t Param_p12_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x150ed997U), BSWAP_32BIG_C(0xfb891ef7U), BSWAP_32BIG_C(0xbd3c0c19U),
                        BSWAP_32BIG_C(0x09e4cc6cU),
                    };
                    r_rsip_func101(Param_p12_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0xa69ef2d0U, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p12_func100_016[] =
        {
            BSWAP_32BIG_C(0xef0f3582U), BSWAP_32BIG_C(0x99a15758U), BSWAP_32BIG_C(0x8fa942fbU), BSWAP_32BIG_C(
                0x31222629U),
        };
        r_rsip_func100(Param_p12_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p12_func102_002[] =
            {
                BSWAP_32BIG_C(0xc67e0b75U), BSWAP_32BIG_C(0xbefaea21U), BSWAP_32BIG_C(0xfbaf7da5U), BSWAP_32BIG_C(
                    0xcef66dedU),
            };
            r_rsip_func102(Param_p12_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p12_func102_003[] =
            {
                BSWAP_32BIG_C(0x06153fefU), BSWAP_32BIG_C(0xbdd435bfU), BSWAP_32BIG_C(0xda0c2077U), BSWAP_32BIG_C(
                    0xee9c13e4U),
            };
            r_rsip_func102(Param_p12_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
