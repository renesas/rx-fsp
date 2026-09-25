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

rsip_ret_t r_rsip_p5fi (const uint32_t InData_KeyIndex[],
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

    r_rsip_func_sub029(0x005f0001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00005f01U);

    static const uint32_t Param_p5fi_func101_001[] =
    {
        BSWAP_32BIG_C(0xe05e96e8U), BSWAP_32BIG_C(0x1c8f90adU), BSWAP_32BIG_C(0xc4fe6acdU), BSWAP_32BIG_C(0xf288f1deU),
    };
    r_rsip_func101(Param_p5fi_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000020U);

    r_rsip_func_sub009(0x00005f01U);

    static const uint32_t Param_p5fi_func101_002[] =
    {
        BSWAP_32BIG_C(0x10c4ce6dU), BSWAP_32BIG_C(0xe559d78aU), BSWAP_32BIG_C(0x0f1f4ab1U), BSWAP_32BIG_C(0x565bddb0U),
    };
    r_rsip_func101(Param_p5fi_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00001fc2U, 0x40000700U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80a00001U);
    for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[17 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[33]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p5fi_func100_001[] =
    {
        BSWAP_32BIG_C(0xc67a4380U), BSWAP_32BIG_C(0x994a0082U), BSWAP_32BIG_C(0xc384d34cU), BSWAP_32BIG_C(0x56f5905eU),
    };
    r_rsip_func100(Param_p5fi_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p5fi_func102_001[] =
        {
            BSWAP_32BIG_C(0xaff1cf93U), BSWAP_32BIG_C(0x6618fb4cU), BSWAP_32BIG_C(0x833a71afU), BSWAP_32BIG_C(
                0xe698d731U),
        };
        r_rsip_func102(Param_p5fi_func102_001);
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

        r_rsip_func_sub003(0x80010360U, 0x0000005fU);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p5fi_func100_002[] =
        {
            BSWAP_32BIG_C(0xfcf725faU), BSWAP_32BIG_C(0x5e67628cU), BSWAP_32BIG_C(0xef9afb8dU), BSWAP_32BIG_C(
                0x354f16e0U),
        };
        r_rsip_func100(Param_p5fi_func100_002);
        r_rsip_func078(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x08080010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

        WR1_PROG(REG_1404H, 0x18f00000U);
        r_rsip_func_sub008(0x00001fc2U, 0x00000700U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1404H, 0x19400000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[24]);
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[28]);
        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1404H, 0x11c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0003dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0808000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p5fi_func100_003[] =
        {
            BSWAP_32BIG_C(0x09c6a43bU), BSWAP_32BIG_C(0x9f072441U), BSWAP_32BIG_C(0x91e68392U), BSWAP_32BIG_C(
                0x29d2545fU),
        };
        r_rsip_func100(Param_p5fi_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p5fi_func101_003[] =
            {
                BSWAP_32BIG_C(0xe2c2a9d5U), BSWAP_32BIG_C(0x3f5b51caU), BSWAP_32BIG_C(0x825ec83bU), BSWAP_32BIG_C(
                    0x8841d370U),
            };
            r_rsip_func101(Param_p5fi_func101_003);
        }
        else
        {
            static const uint32_t Param_p5fi_func100_004[] =
            {
                BSWAP_32BIG_C(0x3a781cd3U), BSWAP_32BIG_C(0x4af097c6U), BSWAP_32BIG_C(0xd61b9033U), BSWAP_32BIG_C(
                    0x6e155eeeU),
            };
            r_rsip_func100(Param_p5fi_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0808000aU);

            r_rsip_func_sub041(0x00000980U, 0x000001b0U, 0x000000c0U, 0x00000110U, 0x00000020U, 0x0808000fU);
            r_rsip_func_sub035(0x00010001U);

            r_rsip_func_sub038(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub030(0x10d00000U, 0x00000bffU, 0x8190001fU);
            r_rsip_func_sub001(0x00c90041U);

            r_rsip_func_sub038(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x08080002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_func_sub001(0x00c00041U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x08080004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002a8U, 0x08080009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x08080009U);

            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1608H, 0x81900001U);
            r_rsip_func_sub001(0x00c90041U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x000009e0U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10d00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1608H, 0x8190001fU);
            r_rsip_func_sub001(0x00c90041U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a28U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p5fi_func100_005[] =
            {
                BSWAP_32BIG_C(0x7d5fde60U), BSWAP_32BIG_C(0x11b9b0e6U), BSWAP_32BIG_C(0xb088e6ecU), BSWAP_32BIG_C(
                    0x5c85a7b9U),
            };
            r_rsip_func100(Param_p5fi_func100_005);
            r_rsip_func079(InData_DomainParam);

            r_rsip_func_sub002(0x000001c0U, 0x00000160U, 0x00000ad0U, 0x08080009U);

            r_rsip_func_sub002(0x00000208U, 0x00000160U, 0x00000b18U, 0x08080009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x08080009U);

            r_rsip_func_sub002(0x00000ad0U, 0x000009e0U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x000009e0U, 0x00000ad0U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b18U, 0x00000a28U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a28U, 0x00000b18U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p5fi_func100_006[] =
            {
                BSWAP_32BIG_C(0xb752ad06U), BSWAP_32BIG_C(0x3f24f56cU), BSWAP_32BIG_C(0xf1a650a3U), BSWAP_32BIG_C(
                    0x0ee87918U),
            };
            r_rsip_func100(Param_p5fi_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub038(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x08080013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p5fi_func101_004[] =
                {
                    BSWAP_32BIG_C(0xc5dcc235U), BSWAP_32BIG_C(0xfa2c5cecU), BSWAP_32BIG_C(0xce6b46ebU), BSWAP_32BIG_C(
                        0x858b76bdU),
                };
                r_rsip_func101(Param_p5fi_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x08080014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p5fi_func101_005[] =
                {
                    BSWAP_32BIG_C(0x378f15b8U), BSWAP_32BIG_C(0x014da466U), BSWAP_32BIG_C(0x1ae712c5U), BSWAP_32BIG_C(
                        0xceabd336U),
                };
                r_rsip_func101(Param_p5fi_func101_005);
            }

            WR1_PROG(REG_1600H, 0x00000821U);

            WR1_PROG(REG_1404H, 0x14400000U);
            WR1_PROG(REG_1608H, 0x80900001U);
            r_rsip_func_sub001(0x03430041U);

            r_rsip_func_sub031(0x0000a420U, 0x00000050U, 0x13000000U);
            WR1_PROG(REG_1608H, 0x80900001U);
            r_rsip_func_sub001(0x03430041U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub021(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub022(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11200000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0003dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001c0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_p5fi_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x4975cf07U), BSWAP_32BIG_C(0x26f111afU), BSWAP_32BIG_C(0xa38abfe7U),
                        BSWAP_32BIG_C(0x5c8b0683U),
                    };
                    r_rsip_func100(Param_p5fi_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p5fi_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x8685a52aU), BSWAP_32BIG_C(0xd37793ecU), BSWAP_32BIG_C(0xc3796e40U),
                            BSWAP_32BIG_C(0xca62ad3aU),
                        };
                        r_rsip_func101(Param_p5fi_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p5fi_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x312eeabfU), BSWAP_32BIG_C(0x7d040a01U), BSWAP_32BIG_C(0x935133c6U),
                            BSWAP_32BIG_C(0xc99c9526U),
                        };
                        r_rsip_func101(Param_p5fi_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p5fi_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xb2568cc8U), BSWAP_32BIG_C(0xcf366808U), BSWAP_32BIG_C(0x114eb1bbU),
                        BSWAP_32BIG_C(0x77f5e120U),
                    };
                    r_rsip_func100(Param_p5fi_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p5fi_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x0f727fd7U), BSWAP_32BIG_C(0x127a922cU), BSWAP_32BIG_C(0x81f13fa9U),
                            BSWAP_32BIG_C(0xcb3d9c7eU),
                        };
                        r_rsip_func100(Param_p5fi_func100_009);

                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_func_sub001(0x00c00041U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009e0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a28U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_008[] =
                            {
                                BSWAP_32BIG_C(0xbd0fb11aU), BSWAP_32BIG_C(0xa92f51b2U), BSWAP_32BIG_C(0xdca43a30U),
                                BSWAP_32BIG_C(0xdc8b5512U),
                            };
                            r_rsip_func101(Param_p5fi_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ad0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b18U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_009[] =
                            {
                                BSWAP_32BIG_C(0xe265f924U), BSWAP_32BIG_C(0x38eb0619U), BSWAP_32BIG_C(0x8efa5206U),
                                BSWAP_32BIG_C(0x1243dfaeU),
                            };
                            r_rsip_func101(Param_p5fi_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bc0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c08U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x128e6becU), BSWAP_32BIG_C(0x8fc8d2ddU), BSWAP_32BIG_C(0xc1c7cf28U),
                                BSWAP_32BIG_C(0x8caf06cfU),
                            };
                            r_rsip_func101(Param_p5fi_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c0003dU);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001c0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_p5fi_func100_010[] =
                        {
                            BSWAP_32BIG_C(0xf454b3e1U), BSWAP_32BIG_C(0x2d72b85cU), BSWAP_32BIG_C(0x073979e7U),
                            BSWAP_32BIG_C(0x32810515U),
                        };
                        r_rsip_func100(Param_p5fi_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p5fi_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x6c3b9486U), BSWAP_32BIG_C(0xc0a6a764U), BSWAP_32BIG_C(0x7995e9a8U),
                                BSWAP_32BIG_C(0x63be72bbU),
                            };
                            r_rsip_func100(Param_p5fi_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001c0U, 0x000003f0U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x000003f0U, 0x000001c0U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000208U, 0x00000438U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000438U, 0x00000208U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_p5fi_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0x62bba9cbU), BSWAP_32BIG_C(0x164b1021U), BSWAP_32BIG_C(0x394c8b60U),
                                    BSWAP_32BIG_C(0x264fd066U),
                                };
                                r_rsip_func100(Param_p5fi_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub038(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p5fi_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x854bd3c1U), BSWAP_32BIG_C(0xd21afc77U), BSWAP_32BIG_C(
                                            0x9cf3840dU),           BSWAP_32BIG_C(0xd882482fU),
                                    };
                                    r_rsip_func101(Param_p5fi_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p5fi_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x72860713U), BSWAP_32BIG_C(0x9fc3a07eU), BSWAP_32BIG_C(
                                            0x21119091U),           BSWAP_32BIG_C(0xb890152eU),
                                    };
                                    r_rsip_func101(Param_p5fi_func101_012);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                            }
                            else
                            {
                                static const uint32_t Param_p5fi_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0xd404d64fU), BSWAP_32BIG_C(0x1d8fa221U), BSWAP_32BIG_C(0x30702718U),
                                    BSWAP_32BIG_C(0x5e2785a7U),
                                };
                                r_rsip_func101(Param_p5fi_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11200000U);
                            r_rsip_func_sub001(0x00c00041U);

                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x000001c0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000438U, 0x00000160U, 0x00000208U, 0x08080009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x00783571U), BSWAP_32BIG_C(0xd18f75d2U), BSWAP_32BIG_C(0xcbfb6f49U),
                                BSWAP_32BIG_C(0x41a6cae0U),
                            };
                            r_rsip_func101(Param_p5fi_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p5fi_func101_015[] =
                        {
                            BSWAP_32BIG_C(0xc86d5846U), BSWAP_32BIG_C(0x189813d3U), BSWAP_32BIG_C(0x9cd9b5f5U),
                            BSWAP_32BIG_C(0x6c7c4b79U),
                        };
                        r_rsip_func101(Param_p5fi_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p5fi_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xd348a1feU), BSWAP_32BIG_C(0x70cf60e2U), BSWAP_32BIG_C(0x80668560U),
                        BSWAP_32BIG_C(0xa760b1beU),
                    };
                    r_rsip_func101(Param_p5fi_func101_016);
                }

                WR1_PROG(REG_1600H, 0x38008840U);
                r_rsip_func_sub011(0x00000020U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p5fi_func101_017[] =
                {
                    BSWAP_32BIG_C(0x9f923000U), BSWAP_32BIG_C(0xd01dc5e7U), BSWAP_32BIG_C(0x58fe4a10U), BSWAP_32BIG_C(
                        0x5ad56352U),
                };
                r_rsip_func101(Param_p5fi_func101_017);
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            r_rsip_func_sub011(0x00000010U);

            WR1_PROG(REG_1404H, 0x12600000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0003dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p5fi_func100_013[] =
            {
                BSWAP_32BIG_C(0x01e6f675U), BSWAP_32BIG_C(0x89713371U), BSWAP_32BIG_C(0x5df586d6U), BSWAP_32BIG_C(
                    0xbf98130aU),
            };
            r_rsip_func100(Param_p5fi_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p5fi_func101_018[] =
                {
                    BSWAP_32BIG_C(0xaa06f823U), BSWAP_32BIG_C(0x9189c438U), BSWAP_32BIG_C(0x8b946279U), BSWAP_32BIG_C(
                        0xdb3af60dU),
                };
                r_rsip_func101(Param_p5fi_func101_018);
            }
            else
            {
                static const uint32_t Param_p5fi_func100_014[] =
                {
                    BSWAP_32BIG_C(0xe914a3adU), BSWAP_32BIG_C(0x17989edbU), BSWAP_32BIG_C(0xe901f849U), BSWAP_32BIG_C(
                        0x4fc6c413U),
                };
                r_rsip_func100(Param_p5fi_func100_014);

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
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p5fi_func100_015[] =
                {
                    BSWAP_32BIG_C(0x117d2f93U), BSWAP_32BIG_C(0x3ee6f04bU), BSWAP_32BIG_C(0xebbf9ccfU), BSWAP_32BIG_C(
                        0x0cf755cfU),
                };
                r_rsip_func100(Param_p5fi_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p5fi_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xdc473674U), BSWAP_32BIG_C(0x8a210432U), BSWAP_32BIG_C(0x7ad0b00bU),
                        BSWAP_32BIG_C(0x0104de0fU),
                    };
                    r_rsip_func101(Param_p5fi_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xa69ef2d0U);

                    static const uint32_t Param_p5fi_func101_020[] =
                    {
                        BSWAP_32BIG_C(0xadd326ddU), BSWAP_32BIG_C(0x8803a7b7U), BSWAP_32BIG_C(0xf9b554f8U),
                        BSWAP_32BIG_C(0x8b906837U),
                    };
                    r_rsip_func101(Param_p5fi_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0xa69ef2d0U, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p5fi_func100_016[] =
        {
            BSWAP_32BIG_C(0x1792edb3U), BSWAP_32BIG_C(0xb26cef9bU), BSWAP_32BIG_C(0xc57c6a66U), BSWAP_32BIG_C(
                0xa1ce84f6U),
        };
        r_rsip_func100(Param_p5fi_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p5fi_func102_002[] =
            {
                BSWAP_32BIG_C(0x4146afe0U), BSWAP_32BIG_C(0xcaa4a09aU), BSWAP_32BIG_C(0x7edcabbcU), BSWAP_32BIG_C(
                    0x25f6a053U),
            };
            r_rsip_func102(Param_p5fi_func102_002);
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

            return RSIP_RET_PASS;
        }
    }
}
