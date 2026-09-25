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

void r_rsip_func090 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11200000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003f0U, 0x0808000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003f0U, 0x08080010U);

    r_rsip_func_sub009(0x00f09001U);

    static const uint32_t Param_func090_func101_001[] =
    {
        BSWAP_32BIG_C(0xec0c9299U), BSWAP_32BIG_C(0xc20df715U), BSWAP_32BIG_C(0x043397f1U), BSWAP_32BIG_C(0xee447ea7U),
    };
    r_rsip_func101(Param_func090_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f09002U);

    static const uint32_t Param_func090_func101_002[] =
    {
        BSWAP_32BIG_C(0xcb40fd78U), BSWAP_32BIG_C(0x2734d801U), BSWAP_32BIG_C(0xb3e840b9U), BSWAP_32BIG_C(0xd1a7db69U),
    };
    r_rsip_func101(Param_func090_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f09003U);

    static const uint32_t Param_func090_func101_003[] =
    {
        BSWAP_32BIG_C(0x5a590b60U), BSWAP_32BIG_C(0x021b79f5U), BSWAP_32BIG_C(0x20b47c54U), BSWAP_32BIG_C(0x41327c77U),
    };
    r_rsip_func101(Param_func090_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00f09004U);

    static const uint32_t Param_func090_func101_004[] =
    {
        BSWAP_32BIG_C(0x0705e165U), BSWAP_32BIG_C(0xf3173b1cU), BSWAP_32BIG_C(0x168d5415U), BSWAP_32BIG_C(0xffd8bb19U),
    };
    r_rsip_func101(Param_func090_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub040(0x000003f0U, 0x00000480U, 0x00000020U, 0x08080004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_1404H, 0x13f80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000438U, 0x00000160U, 0x08080009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x08080010U);

    r_rsip_func_sub038(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x08080005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000438U, 0x00000480U, 0x0808000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func090_func100_001[] =
    {
        BSWAP_32BIG_C(0x0d4172a1U), BSWAP_32BIG_C(0xb7ff738bU), BSWAP_32BIG_C(0xf0bc6e69U), BSWAP_32BIG_C(0x33e621aaU),
    };
    r_rsip_func100(Param_func090_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func090_func101_005[] =
        {
            BSWAP_32BIG_C(0xbb443432U), BSWAP_32BIG_C(0x1d61c5daU), BSWAP_32BIG_C(0xb548d9bdU), BSWAP_32BIG_C(
                0x608f552aU),
        };
        r_rsip_func101(Param_func090_func101_005);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_func_sub040(0x00000070U, 0x00000250U, 0x00000018U, 0x08080004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x13b00000U);
        r_rsip_func_sub001(0x00c00041U);

        r_rsip_func_sub002(0x00000890U, 0x000003f0U, 0x000002a8U, 0x08080009U);

        r_rsip_func_sub002(0x00000070U, 0x000003f0U, 0x000002f0U, 0x08080009U);

        static const uint32_t Param_func090_func100_002[] =
        {
            BSWAP_32BIG_C(0x6e6438e7U), BSWAP_32BIG_C(0x854e34cfU), BSWAP_32BIG_C(0x2725458cU), BSWAP_32BIG_C(
                0x058a98e4U),
        };
        r_rsip_func100(Param_func090_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x08080015U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_143CH, 0x00000d00U);

        WR1_PROG(REG_1404H, 0x10d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0003dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x000004e0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func090_func100_003[] =
        {
            BSWAP_32BIG_C(0x687a7555U), BSWAP_32BIG_C(0x18d5d937U), BSWAP_32BIG_C(0x3cc88417U), BSWAP_32BIG_C(
                0xe47a732eU),
        };
        r_rsip_func100(Param_func090_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func090_func101_006[] =
            {
                BSWAP_32BIG_C(0xfd5ee590U), BSWAP_32BIG_C(0x793417deU), BSWAP_32BIG_C(0x44945522U), BSWAP_32BIG_C(
                    0x22bc07d4U),
            };
            r_rsip_func101(Param_func090_func101_006);
        }
        else
        {
            static const uint32_t Param_func090_func100_004[] =
            {
                BSWAP_32BIG_C(0x8d1253b8U), BSWAP_32BIG_C(0xc95e8382U), BSWAP_32BIG_C(0xcb193551U), BSWAP_32BIG_C(
                    0x4a239ab2U),
            };
            r_rsip_func100(Param_func090_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x08080015U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1404H, 0x10d00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0003dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func090_func100_005[] =
            {
                BSWAP_32BIG_C(0xda56a8beU), BSWAP_32BIG_C(0xa9f89c7bU), BSWAP_32BIG_C(0x072d04afU), BSWAP_32BIG_C(
                    0x2ebb6a04U),
            };
            r_rsip_func100(Param_func090_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func090_func101_007[] =
                {
                    BSWAP_32BIG_C(0x29311c3cU), BSWAP_32BIG_C(0xb22718fcU), BSWAP_32BIG_C(0xe0bbefdcU), BSWAP_32BIG_C(
                        0x8755a7f0U),
                };
                r_rsip_func101(Param_func090_func101_007);
            }
            else
            {
                static const uint32_t Param_func090_func100_006[] =
                {
                    BSWAP_32BIG_C(0xf89aa91cU), BSWAP_32BIG_C(0x24a666c6U), BSWAP_32BIG_C(0x69345f6cU), BSWAP_32BIG_C(
                        0xaa446769U),
                };
                r_rsip_func100(Param_func090_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x08080004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11200000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0003dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0808000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub038(0x000004e0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x00000528U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0808000aU);

                r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000528U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x08080002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11200000U);
                r_rsip_func_sub001(0x00c00041U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x000004e0U, 0x08080009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x08080004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x08080013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x12b00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0003dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func090_func100_007[] =
                {
                    BSWAP_32BIG_C(0xd803d678U), BSWAP_32BIG_C(0xb30c41e9U), BSWAP_32BIG_C(0x6f2c225aU), BSWAP_32BIG_C(
                        0x8e315726U),
                };
                r_rsip_func100(Param_func090_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func090_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x150f79e3U), BSWAP_32BIG_C(0xd13777f2U), BSWAP_32BIG_C(0x576bb11eU),
                        BSWAP_32BIG_C(0xe851fba8U),
                    };
                    r_rsip_func101(Param_func090_func101_008);
                }
                else
                {
                    static const uint32_t Param_func090_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x911475d4U), BSWAP_32BIG_C(0x9b455a89U), BSWAP_32BIG_C(0x66f94becU),
                        BSWAP_32BIG_C(0x7136cdd0U),
                    };
                    r_rsip_func100(Param_func090_func100_008);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x08080004U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x11200000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000002U);
                    r_rsip_func_sub001(0x00c0003dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);

                    r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0808000fU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    r_rsip_func_sub038(0x000001c0U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x08080002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000208U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x08080002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xeb8914f1U);

                    static const uint32_t Param_func090_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x22dc9ad0U), BSWAP_32BIG_C(0x86dc692eU), BSWAP_32BIG_C(0xc28f4e0cU),
                        BSWAP_32BIG_C(0xd2749c75U),
                    };
                    r_rsip_func101(Param_func090_func101_009);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0xeb8914f1U, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
