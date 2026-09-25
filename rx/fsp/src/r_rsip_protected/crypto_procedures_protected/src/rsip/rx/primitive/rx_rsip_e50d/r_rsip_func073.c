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

void r_rsip_func073 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    static const uint32_t Param_func073_func100_001[] =
    {
        BSWAP_32BIG_C(0x4f29c3dcU), BSWAP_32BIG_C(0x8651c0f4U), BSWAP_32BIG_C(0x52518ef1U), BSWAP_32BIG_C(0xc2f87caeU),
    };
    r_rsip_func100(Param_func073_func100_001);
    r_rsip_func070(ARG1);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x04040010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

    WR1_PROG(REG_1404H, 0x11e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0404000aU);

    r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func073_func100_002[] =
    {
        BSWAP_32BIG_C(0x0aa456a2U), BSWAP_32BIG_C(0xe81d3607U), BSWAP_32BIG_C(0x0bcd3138U), BSWAP_32BIG_C(0xdfe48f20U),
    };
    r_rsip_func100(Param_func073_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func073_func101_001[] =
        {
            BSWAP_32BIG_C(0x2f7c6893U), BSWAP_32BIG_C(0x95d349c6U), BSWAP_32BIG_C(0x4f5194f6U), BSWAP_32BIG_C(
                0xe97f46cdU),
        };
        r_rsip_func101(Param_func073_func101_001);
    }
    else
    {
        static const uint32_t Param_func073_func100_003[] =
        {
            BSWAP_32BIG_C(0xe079217dU), BSWAP_32BIG_C(0xd938e8f5U), BSWAP_32BIG_C(0xd003e4faU), BSWAP_32BIG_C(
                0x940d2cd3U),
        };
        r_rsip_func100(Param_func073_func100_003);

        r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0404000aU);

        r_rsip_func_sub041(0x00000980U, 0x000001b0U, 0x000000c0U, 0x00000110U, 0x00000020U, 0x0404000fU);
        r_rsip_func_sub035(0x00010001U);

        r_rsip_func_sub038(0x00000110U, 0x00000840U, 0x000000c0U);
        r_rsip_func_sub005(0x00000160U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub030(0x10f00000U, 0x00000bffU, 0x8188001fU);
        r_rsip_func_sub001(0x00c90021U);

        r_rsip_func_sub038(0x00000110U, 0x00000160U, 0x000000c0U);
        r_rsip_func_sub005(0x00000480U, 0x04040002U, 0x00010001U);
        r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
        r_rsip_func_sub005(0x00000340U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1010H, 0x00000018U);

        WR1_PROG(REG_1404H, 0x11400000U);
        r_rsip_func_sub001(0x00c00021U);

        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_func_sub001(0x00c002d1U);

        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000a70U, 0x04040004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002c8U, 0x04040009U);

        r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x04040009U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1608H, 0x81880001U);
        r_rsip_func_sub001(0x00c90021U);

        r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000a20U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub012(0x10f00000U, 0x000037e1U, 0x0000a7e0U);
        WR1_PROG(REG_1600H, 0x00000020U);
        WR1_PROG(REG_1608H, 0x8188001fU);
        r_rsip_func_sub001(0x00c90021U);

        r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000a48U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        static const uint32_t Param_func073_func100_004[] =
        {
            BSWAP_32BIG_C(0xa94df27bU), BSWAP_32BIG_C(0xad1f4e21U), BSWAP_32BIG_C(0xa0b22633U), BSWAP_32BIG_C(
                0x05ee86eaU),
        };
        r_rsip_func100(Param_func073_func100_004);
        r_rsip_func071(ARG1);

        r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000b10U, 0x04040009U);

        r_rsip_func_sub002(0x00000228U, 0x00000160U, 0x00000b38U, 0x04040009U);

        r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x04040009U);

        r_rsip_func_sub002(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000b38U, 0x00000a48U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000a48U, 0x00000b38U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func073_func100_005[] =
        {
            BSWAP_32BIG_C(0x18ab539eU), BSWAP_32BIG_C(0xc6dc5854U), BSWAP_32BIG_C(0xc31eeec9U), BSWAP_32BIG_C(
                0xed78e5b4U),
        };
        r_rsip_func100(Param_func073_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub038(0x00000b60U, 0x00000a70U, 0x00000070U);
            r_rsip_func_sub005(0x00000c50U, 0x04040013U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            static const uint32_t Param_func073_func101_002[] =
            {
                BSWAP_32BIG_C(0x287b9d19U), BSWAP_32BIG_C(0x217d711cU), BSWAP_32BIG_C(0x641c4929U), BSWAP_32BIG_C(
                    0x56ce3665U),
            };
            r_rsip_func101(Param_func073_func101_002);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            WR1_PROG(REG_101CH, 0x000002f0U);
            r_rsip_func_sub005(0x00000c50U, 0x04040014U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            static const uint32_t Param_func073_func101_003[] =
            {
                BSWAP_32BIG_C(0xf1203b99U), BSWAP_32BIG_C(0x6a1f136aU), BSWAP_32BIG_C(0xe78e46eeU), BSWAP_32BIG_C(
                    0x7b2e0295U),
            };
            r_rsip_func101(Param_func073_func101_003);
        }

        WR1_PROG(REG_1600H, 0x00000821U);

        WR1_PROG(REG_1404H, 0x14600000U);
        WR1_PROG(REG_1608H, 0x80880001U);
        r_rsip_func_sub001(0x03430021U);

        r_rsip_func_sub031(0x0000a420U, 0x00000050U, 0x13200000U);
        WR1_PROG(REG_1608H, 0x80880001U);
        r_rsip_func_sub001(0x03430021U);

        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x00c000f1U);

        WR1_PROG(REG_1600H, 0x00000821U);

        for (iLoop = 0U; iLoop < 8U; iLoop++)
        {
            r_rsip_func_sub021(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
            r_rsip_func_sub022(0x00000050U, 0x00003885U, 0x00000842U);

            for (jLoop = 0U; jLoop < 32U; jLoop++)
            {
                r_rsip_func_sub021(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                WR1_PROG(REG_1600H, 0x00016c84U);

                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000110U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00a10000U);

                r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00a10000U);

                static const uint32_t Param_func073_func100_006[] =
                {
                    BSWAP_32BIG_C(0xe9ef9caaU), BSWAP_32BIG_C(0xd4dcc333U), BSWAP_32BIG_C(0x658e989bU), BSWAP_32BIG_C(
                        0xc69c0039U),
                };
                r_rsip_func100(Param_func073_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x000002f0U);
                    r_rsip_func_sub005(0x00000250U, 0x04040014U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    static const uint32_t Param_func073_func101_004[] =
                    {
                        BSWAP_32BIG_C(0x4d88c111U), BSWAP_32BIG_C(0x2cf71010U), BSWAP_32BIG_C(0x527a289eU),
                        BSWAP_32BIG_C(0x0f552e34U),
                    };
                    r_rsip_func101(Param_func073_func101_004);
                }
                else
                {
                    static const uint32_t Param_func073_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x388e6baaU), BSWAP_32BIG_C(0xfe45aa5eU), BSWAP_32BIG_C(0x4a391181U),
                        BSWAP_32BIG_C(0xda5821e8U),
                    };
                    r_rsip_func101(Param_func073_func101_005);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                static const uint32_t Param_func073_func100_007[] =
                {
                    BSWAP_32BIG_C(0x18c6b17fU), BSWAP_32BIG_C(0xe6157d97U), BSWAP_32BIG_C(0x95cdfd4dU), BSWAP_32BIG_C(
                        0x5aedc72cU),
                };
                r_rsip_func100(Param_func073_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_func073_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x799fdd78U), BSWAP_32BIG_C(0xd2e5e75cU), BSWAP_32BIG_C(0x340597bcU),
                        BSWAP_32BIG_C(0xd0ed3844U),
                    };
                    r_rsip_func100(Param_func073_func100_008);

                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_func_sub001(0x00c00021U);

                    r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                    {
                        r_rsip_func_sub002(0x00000a20U, 0x00000160U, 0x00000430U, 0x04040009U);

                        r_rsip_func_sub002(0x00000a48U, 0x00000160U, 0x00000458U, 0x04040009U);

                        r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x04040009U);

                        static const uint32_t Param_func073_func101_006[] =
                        {
                            BSWAP_32BIG_C(0xd7e1d884U), BSWAP_32BIG_C(0x9daa6a08U), BSWAP_32BIG_C(0x2c00d44cU),
                            BSWAP_32BIG_C(0x4158c6ebU),
                        };
                        r_rsip_func101(Param_func073_func101_006);
                    }
                    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                    {
                        r_rsip_func_sub002(0x00000b10U, 0x00000160U, 0x00000430U, 0x04040009U);

                        r_rsip_func_sub002(0x00000b38U, 0x00000160U, 0x00000458U, 0x04040009U);

                        r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x04040009U);

                        static const uint32_t Param_func073_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x7b01735dU), BSWAP_32BIG_C(0x08387923U), BSWAP_32BIG_C(0x470c78c5U),
                            BSWAP_32BIG_C(0x749e68a4U),
                        };
                        r_rsip_func101(Param_func073_func101_007);
                    }
                    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                    {
                        r_rsip_func_sub002(0x00000c00U, 0x00000160U, 0x00000430U, 0x04040009U);

                        r_rsip_func_sub002(0x00000c28U, 0x00000160U, 0x00000458U, 0x04040009U);

                        r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x04040009U);

                        static const uint32_t Param_func073_func101_008[] =
                        {
                            BSWAP_32BIG_C(0x88df22fdU), BSWAP_32BIG_C(0xbfde7b24U), BSWAP_32BIG_C(0xc2adf51eU),
                            BSWAP_32BIG_C(0xd4e0cfdcU),
                        };
                        r_rsip_func101(Param_func073_func101_008);
                    }

                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0001dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000110U, 0x0404000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_func073_func100_009[] =
                    {
                        BSWAP_32BIG_C(0xb686ca32U), BSWAP_32BIG_C(0x3e7d2ef1U), BSWAP_32BIG_C(0xfd7394ceU),
                        BSWAP_32BIG_C(0xb6ef2bedU),
                    };
                    r_rsip_func100(Param_func073_func100_009);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000110U, 0x0404000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_func073_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x87125f55U), BSWAP_32BIG_C(0xbbafdff5U), BSWAP_32BIG_C(0x08e1bc21U),
                            BSWAP_32BIG_C(0x6d87bb83U),
                        };
                        r_rsip_func100(Param_func073_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x00000200U, 0x00000430U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000430U, 0x00000200U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000228U, 0x00000458U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000458U, 0x00000228U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            static const uint32_t Param_func073_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x985188beU), BSWAP_32BIG_C(0x79f4b07fU), BSWAP_32BIG_C(0x9b8b096fU),
                                BSWAP_32BIG_C(0x786c3b2dU),
                            };
                            r_rsip_func100(Param_func073_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub038(0x00000250U, 0x00000480U, 0x00000070U);
                                r_rsip_func_sub005(0x00000250U, 0x04040013U, 0x00010001U);
                                WAIT_STS(REG_1000H, 0, 0);
                                WR1_PROG(REG_143CH, 0x00000d00U);

                                static const uint32_t Param_func073_func101_009[] =
                                {
                                    BSWAP_32BIG_C(0xe5704129U), BSWAP_32BIG_C(0x16e9929aU), BSWAP_32BIG_C(0x2c65aeafU),
                                    BSWAP_32BIG_C(0x6c8f4889U),
                                };
                                r_rsip_func101(Param_func073_func101_009);
                            }
                            else
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                WR1_PROG(REG_101CH, 0x000002f0U);
                                r_rsip_func_sub005(0x00000250U, 0x04040014U, 0x00010001U);
                                WAIT_STS(REG_1000H, 0, 0);
                                WR1_PROG(REG_143CH, 0x00000d00U);

                                static const uint32_t Param_func073_func101_010[] =
                                {
                                    BSWAP_32BIG_C(0x5e4b052dU), BSWAP_32BIG_C(0x6a749091U), BSWAP_32BIG_C(0xcc863565U),
                                    BSWAP_32BIG_C(0x088a9061U),
                                };
                                r_rsip_func101(Param_func073_func101_010);
                            }

                            WR1_PROG(REG_1458H, 0x00000000U);
                        }
                        else
                        {
                            static const uint32_t Param_func073_func101_011[] =
                            {
                                BSWAP_32BIG_C(0xff3110bfU), BSWAP_32BIG_C(0xae0f970dU), BSWAP_32BIG_C(0x6572de95U),
                                BSWAP_32BIG_C(0x610754efU),
                            };
                            r_rsip_func101(Param_func073_func101_011);
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11400000U);
                        r_rsip_func_sub001(0x00c00021U);

                        r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000200U, 0x04040009U);

                        r_rsip_func_sub002(0x00000458U, 0x00000160U, 0x00000228U, 0x04040009U);

                        r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x04040009U);

                        static const uint32_t Param_func073_func101_012[] =
                        {
                            BSWAP_32BIG_C(0x78fe3e4aU), BSWAP_32BIG_C(0xb0b1965aU), BSWAP_32BIG_C(0xb6b6b719U),
                            BSWAP_32BIG_C(0x3473a051U),
                        };
                        r_rsip_func101(Param_func073_func101_012);
                    }
                }
                else
                {
                    static const uint32_t Param_func073_func101_013[] =
                    {
                        BSWAP_32BIG_C(0xce7d28e7U), BSWAP_32BIG_C(0x84780be9U), BSWAP_32BIG_C(0xb6fc4cf9U),
                        BSWAP_32BIG_C(0xb0dc11c1U),
                    };
                    r_rsip_func101(Param_func073_func101_013);
                }

                WR1_PROG(REG_1600H, 0x00002c40U);
                static const uint32_t Param_func073_func101_014[] =
                {
                    BSWAP_32BIG_C(0x864dd751U), BSWAP_32BIG_C(0x96aa98d4U), BSWAP_32BIG_C(0x0e6eec7eU), BSWAP_32BIG_C(
                        0x3693f27fU),
                };
                r_rsip_func101(Param_func073_func101_014);
            }

            WR1_PROG(REG_1600H, 0x38008840U);
            r_rsip_func_sub011(0x00000020U);

            WR1_PROG(REG_1600H, 0x00002c20U);

            static const uint32_t Param_func073_func101_015[] =
            {
                BSWAP_32BIG_C(0x3aa1bf67U), BSWAP_32BIG_C(0x66219a25U), BSWAP_32BIG_C(0x5326ef3dU), BSWAP_32BIG_C(
                    0x43afb452U),
            };
            r_rsip_func101(Param_func073_func101_015);
        }

        WR1_PROG(REG_1600H, 0x38008820U);
        r_rsip_func_sub011(0x00000008U);

        WR1_PROG(REG_1404H, 0x12800000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func073_func100_012[] =
        {
            BSWAP_32BIG_C(0xd7013a39U), BSWAP_32BIG_C(0x0437dd9bU), BSWAP_32BIG_C(0x11031256U), BSWAP_32BIG_C(
                0x0ca92228U),
        };
        r_rsip_func100(Param_func073_func100_012);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func073_func101_016[] =
            {
                BSWAP_32BIG_C(0xa4954769U), BSWAP_32BIG_C(0x7b21046bU), BSWAP_32BIG_C(0xdcf0d25dU), BSWAP_32BIG_C(
                    0x160b885fU),
            };
            r_rsip_func101(Param_func073_func101_016);
        }
        else
        {
            static const uint32_t Param_func073_func100_013[] =
            {
                BSWAP_32BIG_C(0x6179c739U), BSWAP_32BIG_C(0x054c94d5U), BSWAP_32BIG_C(0x78383f4aU), BSWAP_32BIG_C(
                    0xabc17de8U),
            };
            r_rsip_func100(Param_func073_func100_013);

            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x000002a0U, 0x04040004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x11400000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);

            r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub038(0x00000200U, 0x00000160U, 0x00000070U);
            r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func073_func100_014[] =
            {
                BSWAP_32BIG_C(0xd8d7e186U), BSWAP_32BIG_C(0x9c89b249U), BSWAP_32BIG_C(0x5388683aU), BSWAP_32BIG_C(
                    0x4f92d038U),
            };
            r_rsip_func100(Param_func073_func100_014);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func073_func101_017[] =
                {
                    BSWAP_32BIG_C(0x0cb64054U), BSWAP_32BIG_C(0xecbd17d7U), BSWAP_32BIG_C(0xe1b609c8U), BSWAP_32BIG_C(
                        0x9f4a036cU),
                };
                r_rsip_func101(Param_func073_func101_017);
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0xa69ef2d0U);

                static const uint32_t Param_func073_func101_018[] =
                {
                    BSWAP_32BIG_C(0xed6e3b23U), BSWAP_32BIG_C(0xee5025edU), BSWAP_32BIG_C(0xbe23099cU), BSWAP_32BIG_C(
                        0x0596621eU),
                };
                r_rsip_func101(Param_func073_func101_018);
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0xa69ef2d0U, 0x00A60000U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
