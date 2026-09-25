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

rsip_ret_t r_rsip_p7e (const uint32_t InData_KeyIndex[],
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

    r_rsip_func_sub029(0x007e0001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000007eU);

    static const uint32_t Param_p7e_func101_001[] =
    {
        BSWAP_32BIG_C(0xd9b7d4c3U), BSWAP_32BIG_C(0x6e086731U), BSWAP_32BIG_C(0xf29bccd2U), BSWAP_32BIG_C(0x61f6a488U),
    };
    r_rsip_func101(Param_p7e_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000020U);

    r_rsip_func_sub009(0x0000007eU);

    static const uint32_t Param_p7e_func101_002[] =
    {
        BSWAP_32BIG_C(0x67294b51U), BSWAP_32BIG_C(0x35b9ee07U), BSWAP_32BIG_C(0x5f26503eU), BSWAP_32BIG_C(0x5065d118U),
    };
    r_rsip_func101(Param_p7e_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00001fc2U, 0x40000700U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80a00001U);
    for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        r_rsip_func_sub001(0x03420011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 17]);
        r_rsip_func_sub001(0x03420011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[33]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p7e_func100_001[] =
    {
        BSWAP_32BIG_C(0x63646770U), BSWAP_32BIG_C(0x85edfdb0U), BSWAP_32BIG_C(0x306f6fb5U), BSWAP_32BIG_C(0x2830094eU),
    };
    r_rsip_func100(Param_p7e_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7e_func102_001[] =
        {
            BSWAP_32BIG_C(0x6e594c3dU), BSWAP_32BIG_C(0x43008ce2U), BSWAP_32BIG_C(0x56b20e13U), BSWAP_32BIG_C(
                0x59488683U),
        };
        r_rsip_func102(Param_p7e_func102_001);
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

        r_rsip_func_sub003(0x80010360U, 0x0000007eU);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p7e_func100_002[] =
        {
            BSWAP_32BIG_C(0x20519d20U), BSWAP_32BIG_C(0x475acb67U), BSWAP_32BIG_C(0xda3e8ab2U), BSWAP_32BIG_C(
                0x50ca5ea7U),
        };
        r_rsip_func100(Param_p7e_func100_002);
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

        static const uint32_t Param_p7e_func100_003[] =
        {
            BSWAP_32BIG_C(0x301d2df8U), BSWAP_32BIG_C(0x096f55d8U), BSWAP_32BIG_C(0xae297481U), BSWAP_32BIG_C(
                0xb8842fddU),
        };
        r_rsip_func100(Param_p7e_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p7e_func101_003[] =
            {
                BSWAP_32BIG_C(0x628e9b6fU), BSWAP_32BIG_C(0x2e7a8613U), BSWAP_32BIG_C(0xd7df9f78U), BSWAP_32BIG_C(
                    0xef427de4U),
            };
            r_rsip_func101(Param_p7e_func101_003);
        }
        else
        {
            static const uint32_t Param_p7e_func100_004[] =
            {
                BSWAP_32BIG_C(0xded703baU), BSWAP_32BIG_C(0xd6fd24cbU), BSWAP_32BIG_C(0xb7c61ef2U), BSWAP_32BIG_C(
                    0xc0149959U),
            };
            r_rsip_func100(Param_p7e_func100_004);

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

            static const uint32_t Param_p7e_func100_005[] =
            {
                BSWAP_32BIG_C(0x9a68c9f0U), BSWAP_32BIG_C(0xc95eb029U), BSWAP_32BIG_C(0xa79be65bU), BSWAP_32BIG_C(
                    0x50dee970U),
            };
            r_rsip_func100(Param_p7e_func100_005);
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

            static const uint32_t Param_p7e_func100_006[] =
            {
                BSWAP_32BIG_C(0xa146d8dbU), BSWAP_32BIG_C(0x0c943fbcU), BSWAP_32BIG_C(0xd2c61835U), BSWAP_32BIG_C(
                    0x368ba5aaU),
            };
            r_rsip_func100(Param_p7e_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub038(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x08080013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p7e_func101_004[] =
                {
                    BSWAP_32BIG_C(0x80ab8fdfU), BSWAP_32BIG_C(0xa1add18dU), BSWAP_32BIG_C(0x817c4b3aU), BSWAP_32BIG_C(
                        0x5c4a3030U),
                };
                r_rsip_func101(Param_p7e_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x08080014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p7e_func101_005[] =
                {
                    BSWAP_32BIG_C(0xd166d077U), BSWAP_32BIG_C(0xfda9c5c4U), BSWAP_32BIG_C(0xd0f11f8bU), BSWAP_32BIG_C(
                        0x13422637U),
                };
                r_rsip_func101(Param_p7e_func101_005);
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

                    static const uint32_t Param_p7e_func100_007[] =
                    {
                        BSWAP_32BIG_C(0xe2a37e65U), BSWAP_32BIG_C(0xca2c57bcU), BSWAP_32BIG_C(0x73eb7a1eU),
                        BSWAP_32BIG_C(0x0923a6f3U),
                    };
                    r_rsip_func100(Param_p7e_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p7e_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x5f7095efU), BSWAP_32BIG_C(0x75f14561U), BSWAP_32BIG_C(0x54d3aad5U),
                            BSWAP_32BIG_C(0x71f04158U),
                        };
                        r_rsip_func101(Param_p7e_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p7e_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xd5a71797U), BSWAP_32BIG_C(0x17edd29aU), BSWAP_32BIG_C(0xfe4824f1U),
                            BSWAP_32BIG_C(0x741d0128U),
                        };
                        r_rsip_func101(Param_p7e_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p7e_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xc99a0b14U), BSWAP_32BIG_C(0x87e5ec33U), BSWAP_32BIG_C(0xe1db3db3U),
                        BSWAP_32BIG_C(0x8e1910faU),
                    };
                    r_rsip_func100(Param_p7e_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p7e_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x5966ac2eU), BSWAP_32BIG_C(0x94ec7cb7U), BSWAP_32BIG_C(0xe5525f9dU),
                            BSWAP_32BIG_C(0xdc8ae35aU),
                        };
                        r_rsip_func100(Param_p7e_func100_009);

                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_func_sub001(0x00c00041U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009e0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a28U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_008[] =
                            {
                                BSWAP_32BIG_C(0xdb6e1a75U), BSWAP_32BIG_C(0x949f1e08U), BSWAP_32BIG_C(0x44ff1f49U),
                                BSWAP_32BIG_C(0x6fb2971bU),
                            };
                            r_rsip_func101(Param_p7e_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ad0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b18U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_009[] =
                            {
                                BSWAP_32BIG_C(0x63969391U), BSWAP_32BIG_C(0x0705af83U), BSWAP_32BIG_C(0x65539e1bU),
                                BSWAP_32BIG_C(0xa79b5fdbU),
                            };
                            r_rsip_func101(Param_p7e_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bc0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c08U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_010[] =
                            {
                                BSWAP_32BIG_C(0xf389bc01U), BSWAP_32BIG_C(0x9dc23f5fU), BSWAP_32BIG_C(0x727f53feU),
                                BSWAP_32BIG_C(0x65324906U),
                            };
                            r_rsip_func101(Param_p7e_func101_010);
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

                        static const uint32_t Param_p7e_func100_010[] =
                        {
                            BSWAP_32BIG_C(0xd8ba82d9U), BSWAP_32BIG_C(0x6921c118U), BSWAP_32BIG_C(0xe4f286dfU),
                            BSWAP_32BIG_C(0xbca6a2eeU),
                        };
                        r_rsip_func100(Param_p7e_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p7e_func100_011[] =
                            {
                                BSWAP_32BIG_C(0xa6d5d5d8U), BSWAP_32BIG_C(0x35ef2946U), BSWAP_32BIG_C(0x37e82fa9U),
                                BSWAP_32BIG_C(0xf646fa98U),
                            };
                            r_rsip_func100(Param_p7e_func100_011);
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

                                static const uint32_t Param_p7e_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0xa2b7546dU), BSWAP_32BIG_C(0x36fe2192U), BSWAP_32BIG_C(0x733538bcU),
                                    BSWAP_32BIG_C(0x750f5b59U),
                                };
                                r_rsip_func100(Param_p7e_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub038(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p7e_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x460de3b6U), BSWAP_32BIG_C(0x19d543eeU), BSWAP_32BIG_C(
                                            0x596496acU),           BSWAP_32BIG_C(0x38385dd4U),
                                    };
                                    r_rsip_func101(Param_p7e_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p7e_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x4ce91551U), BSWAP_32BIG_C(0xfd99b6ebU), BSWAP_32BIG_C(
                                            0x9dc1ef30U),           BSWAP_32BIG_C(0x3a7169faU),
                                    };
                                    r_rsip_func101(Param_p7e_func101_012);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                            }
                            else
                            {
                                static const uint32_t Param_p7e_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x99c83d3cU), BSWAP_32BIG_C(0x6d3dbdaaU), BSWAP_32BIG_C(0xaca1cf15U),
                                    BSWAP_32BIG_C(0x15f51f63U),
                                };
                                r_rsip_func101(Param_p7e_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11200000U);
                            r_rsip_func_sub001(0x00c00041U);

                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x000001c0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000438U, 0x00000160U, 0x00000208U, 0x08080009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_014[] =
                            {
                                BSWAP_32BIG_C(0xf2851a1aU), BSWAP_32BIG_C(0x568071d1U), BSWAP_32BIG_C(0xa9f8cb48U),
                                BSWAP_32BIG_C(0x8f19963dU),
                            };
                            r_rsip_func101(Param_p7e_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p7e_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x1789d6c8U), BSWAP_32BIG_C(0x4fc1557eU), BSWAP_32BIG_C(0x46dde191U),
                            BSWAP_32BIG_C(0x01cc98e1U),
                        };
                        r_rsip_func101(Param_p7e_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p7e_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xa4443a56U), BSWAP_32BIG_C(0x1eed6e07U), BSWAP_32BIG_C(0x2780c20aU),
                        BSWAP_32BIG_C(0x3e71d67dU),
                    };
                    r_rsip_func101(Param_p7e_func101_016);
                }

                WR1_PROG(REG_1600H, 0x38008840U);
                r_rsip_func_sub011(0x00000020U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p7e_func101_017[] =
                {
                    BSWAP_32BIG_C(0x0d9f0803U), BSWAP_32BIG_C(0xd1c5d396U), BSWAP_32BIG_C(0xa2b0118bU), BSWAP_32BIG_C(
                        0xf0d8fe02U),
                };
                r_rsip_func101(Param_p7e_func101_017);
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

            static const uint32_t Param_p7e_func100_013[] =
            {
                BSWAP_32BIG_C(0x7da60076U), BSWAP_32BIG_C(0x09fe90e9U), BSWAP_32BIG_C(0x4e8a8a9bU), BSWAP_32BIG_C(
                    0x81659eb9U),
            };
            r_rsip_func100(Param_p7e_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p7e_func101_018[] =
                {
                    BSWAP_32BIG_C(0x85dc7965U), BSWAP_32BIG_C(0x8fb6fdcaU), BSWAP_32BIG_C(0xa0f947e9U), BSWAP_32BIG_C(
                        0xcf1ab8dbU),
                };
                r_rsip_func101(Param_p7e_func101_018);
            }
            else
            {
                static const uint32_t Param_p7e_func100_014[] =
                {
                    BSWAP_32BIG_C(0x4212b3c8U), BSWAP_32BIG_C(0xe6a33640U), BSWAP_32BIG_C(0x8cbbfd17U), BSWAP_32BIG_C(
                        0xb3a84710U),
                };
                r_rsip_func100(Param_p7e_func100_014);

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

                static const uint32_t Param_p7e_func100_015[] =
                {
                    BSWAP_32BIG_C(0x3d0c010dU), BSWAP_32BIG_C(0x67708da8U), BSWAP_32BIG_C(0x56e983fbU), BSWAP_32BIG_C(
                        0xaf48dee4U),
                };
                r_rsip_func100(Param_p7e_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p7e_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x23fd2f12U), BSWAP_32BIG_C(0x727fbbeaU), BSWAP_32BIG_C(0xbb1e9a08U),
                        BSWAP_32BIG_C(0x329c113eU),
                    };
                    r_rsip_func101(Param_p7e_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xa69ef2d0U);

                    static const uint32_t Param_p7e_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x53b69888U), BSWAP_32BIG_C(0x9dab032eU), BSWAP_32BIG_C(0xff0a8a9bU),
                        BSWAP_32BIG_C(0x1786a19cU),
                    };
                    r_rsip_func101(Param_p7e_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0xa69ef2d0U, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p7e_func100_016[] =
        {
            BSWAP_32BIG_C(0xed209f9dU), BSWAP_32BIG_C(0x2f0c2cdbU), BSWAP_32BIG_C(0x6397b481U), BSWAP_32BIG_C(
                0x6cc9db7dU),
        };
        r_rsip_func100(Param_p7e_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7e_func102_002[] =
            {
                BSWAP_32BIG_C(0x28bdc59dU), BSWAP_32BIG_C(0x8e4b615bU), BSWAP_32BIG_C(0x91ec29f6U), BSWAP_32BIG_C(
                    0x76b14fd2U),
            };
            r_rsip_func102(Param_p7e_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7e_func102_003[] =
            {
                BSWAP_32BIG_C(0x838438cfU), BSWAP_32BIG_C(0x6a2a3c38U), BSWAP_32BIG_C(0xf80e9513U), BSWAP_32BIG_C(
                    0x90b88a5cU),
            };
            r_rsip_func102(Param_p7e_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
