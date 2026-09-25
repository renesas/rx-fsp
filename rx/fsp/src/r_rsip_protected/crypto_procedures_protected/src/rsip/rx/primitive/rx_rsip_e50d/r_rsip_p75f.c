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

rsip_ret_t r_rsip_p75f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Msg[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_length[],
                        uint32_t       MAX_CNT,
                        uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    r_rsip_func_sub043();

    WAIT_STS(REG_2030H, 4, 1);

    r_rsip_func_sub021(0x38008880U, 0x00000003U, 0x1000b480U, 0x00000001U);

    r_rsip_func_sub021(0x38008880U, 0x00000004U, 0x1000b480U, 0x00000002U);
    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p75f_func100_001[] =
    {
        BSWAP_32BIG_C(0x50f529f9U), BSWAP_32BIG_C(0xb862b966U), BSWAP_32BIG_C(0x3a670ef3U), BSWAP_32BIG_C(0xe4663301U),
    };
    r_rsip_func100(Param_p75f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p75f_func100_002[] =
        {
            BSWAP_32BIG_C(0x606d926fU), BSWAP_32BIG_C(0x6d7404a5U), BSWAP_32BIG_C(0x936812c4U), BSWAP_32BIG_C(
                0x637faa47U),
        };
        r_rsip_func100(Param_p75f_func100_002);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            static const uint32_t Param_p75f_func100_003[] =
            {
                BSWAP_32BIG_C(0x0125ed22U), BSWAP_32BIG_C(0x6773a568U), BSWAP_32BIG_C(0xc7b46385U), BSWAP_32BIG_C(
                    0x481580c2U),
            };
            r_rsip_func100(Param_p75f_func100_003);
            WR1_PROG(REG_1408H, 0x0000401eU);
            WAIT_STS(REG_1408H, 30, 1);
            RD7_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_001[] =
            {
                BSWAP_32BIG_C(0xfada6061U), BSWAP_32BIG_C(0x68d73270U), BSWAP_32BIG_C(0x4e4a86e6U), BSWAP_32BIG_C(
                    0x77d6a9d4U),
            };
            r_rsip_func102(Param_p75f_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            static const uint32_t Param_p75f_func100_004[] =
            {
                BSWAP_32BIG_C(0x5e7f6c61U), BSWAP_32BIG_C(0x9d657937U), BSWAP_32BIG_C(0x2ab6cc71U), BSWAP_32BIG_C(
                    0x95115dccU),
            };
            r_rsip_func100(Param_p75f_func100_004);
            WR1_PROG(REG_1408H, 0x00004022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD8_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_002[] =
            {
                BSWAP_32BIG_C(0x5fc80ffbU), BSWAP_32BIG_C(0x176b0182U), BSWAP_32BIG_C(0xb32cddb1U), BSWAP_32BIG_C(
                    0x49b4d257U),
            };
            r_rsip_func102(Param_p75f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            static const uint32_t Param_p75f_func100_005[] =
            {
                BSWAP_32BIG_C(0x71dc3d7bU), BSWAP_32BIG_C(0x7514225eU), BSWAP_32BIG_C(0x3a510b33U), BSWAP_32BIG_C(
                    0x41609396U),
            };
            r_rsip_func100(Param_p75f_func100_005);
            WR1_PROG(REG_1408H, 0x00004032U);
            WAIT_STS(REG_1408H, 30, 1);
            RD12_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_003[] =
            {
                BSWAP_32BIG_C(0xe527fc02U), BSWAP_32BIG_C(0x63eed7deU), BSWAP_32BIG_C(0xa46cfd52U), BSWAP_32BIG_C(
                    0xf216039eU),
            };
            r_rsip_func102(Param_p75f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            static const uint32_t Param_p75f_func100_006[] =
            {
                BSWAP_32BIG_C(0xa4b2bbf4U), BSWAP_32BIG_C(0x95923ee8U), BSWAP_32BIG_C(0x3edd43faU), BSWAP_32BIG_C(
                    0x71bb92abU),
            };
            r_rsip_func100(Param_p75f_func100_006);
            WR1_PROG(REG_1408H, 0x00004042U);
            WAIT_STS(REG_1408H, 30, 1);
            RD16_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_004[] =
            {
                BSWAP_32BIG_C(0xc6ce90c1U), BSWAP_32BIG_C(0x980be5b1U), BSWAP_32BIG_C(0x2b53fb5fU), BSWAP_32BIG_C(
                    0xc8f1ccf9U),
            };
            r_rsip_func102(Param_p75f_func102_004);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        static const uint32_t Param_p75f_func100_007[] =
        {
            BSWAP_32BIG_C(0xe571afdfU), BSWAP_32BIG_C(0xb596aa8aU), BSWAP_32BIG_C(0x43bf315eU), BSWAP_32BIG_C(
                0xd7d3d771U),
        };
        r_rsip_func100(Param_p75f_func100_007);

        r_rsip_func_sub010(0x000000c7U, 0x80010020U);
        WR1_PROG(REG_1420H, InData_length[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x0000001cU);

            static const uint32_t Param_p75f_func101_001[] =
            {
                BSWAP_32BIG_C(0xafb043e2U), BSWAP_32BIG_C(0x5fef8bc1U), BSWAP_32BIG_C(0x945df781U), BSWAP_32BIG_C(
                    0x81f23bd4U),
            };
            r_rsip_func101(Param_p75f_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000020U);

            static const uint32_t Param_p75f_func101_002[] =
            {
                BSWAP_32BIG_C(0x14096de9U), BSWAP_32BIG_C(0xc633f26dU), BSWAP_32BIG_C(0x6fb16d8dU), BSWAP_32BIG_C(
                    0x11a1026fU),
            };
            r_rsip_func101(Param_p75f_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000030U);

            static const uint32_t Param_p75f_func101_003[] =
            {
                BSWAP_32BIG_C(0xc32d0484U), BSWAP_32BIG_C(0xe518190aU), BSWAP_32BIG_C(0x77b3b3b4U), BSWAP_32BIG_C(
                    0x6eb5975dU),
            };
            r_rsip_func101(Param_p75f_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000040U);

            static const uint32_t Param_p75f_func101_004[] =
            {
                BSWAP_32BIG_C(0xa38cecccU), BSWAP_32BIG_C(0x602621afU), BSWAP_32BIG_C(0x34da1cf5U), BSWAP_32BIG_C(
                    0xf35b9354U),
            };
            r_rsip_func101(Param_p75f_func101_004);
        }

        r_rsip_func_sub006(0x3420a820U, 0x00000004U, 0x00260000U);

        r_rsip_func_sub017(0x34202841U, 0x00260000U);

        static const uint32_t Param_p75f_func100_008[] =
        {
            BSWAP_32BIG_C(0xebc4206bU), BSWAP_32BIG_C(0x22bd3688U), BSWAP_32BIG_C(0x496f2217U), BSWAP_32BIG_C(
                0xad6d8dbfU),
        };
        r_rsip_func100(Param_p75f_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p75f_func102_005[] =
            {
                BSWAP_32BIG_C(0xb5bd2860U), BSWAP_32BIG_C(0xadb535c2U), BSWAP_32BIG_C(0xc3ab7411U), BSWAP_32BIG_C(
                    0xc96ad557U),
            };
            r_rsip_func102(Param_p75f_func102_005);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p75f_func100_009[] =
            {
                BSWAP_32BIG_C(0x489bc256U), BSWAP_32BIG_C(0x9a9f36a2U), BSWAP_32BIG_C(0x5aedc8b8U), BSWAP_32BIG_C(
                    0x45b333c3U),
            };
            r_rsip_func100(Param_p75f_func100_009);

            r_rsip_func_sub021(0x000008c6U, 0x000008a5U, 0x0000a440U, 0x0000000fU);
            WR1_PROG(REG_1600H, 0x00046842U);
            WR1_PROG(REG_1600H, 0x00026c42U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
            {
                static const uint32_t Param_p75f_func100_010[] =
                {
                    BSWAP_32BIG_C(0x1379fc70U), BSWAP_32BIG_C(0x02dd3094U), BSWAP_32BIG_C(0x5171f1c9U), BSWAP_32BIG_C(
                        0x82017019U),
                };
                r_rsip_func100(Param_p75f_func100_010);

                r_rsip_func_sub021(0x000008e7U, 0x00000863U, 0x380088c0U, 0x00000004U);
                r_rsip_func_sub021(0x2000d060U, 0x38008880U, 0x00000001U, 0x2000d060U);

                r_rsip_func_sub014(0x00007c03U, 0x00600000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    r_rsip_func_sub001(0x0345000dU);

                    r_rsip_func_sub020(0x000002c1U, 0x08000045U);
                    WR3_ADDR(REG_1420H, &InData_MAC[iLoop]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                    static const uint32_t Param_p75f_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xca8f4c47U), BSWAP_32BIG_C(0xccf23c83U), BSWAP_32BIG_C(0xffe9d5e9U),
                        BSWAP_32BIG_C(0x62f8d007U),
                    };
                    r_rsip_func101(Param_p75f_func101_005);
                }
                else
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    r_rsip_func_sub001(0x03450011U);

                    r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                    WR4_ADDR(REG_1420H, &InData_MAC[iLoop]);

                    static const uint32_t Param_p75f_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x2ee1d4e8U), BSWAP_32BIG_C(0x8b99a948U), BSWAP_32BIG_C(0x961b07e0U),
                        BSWAP_32BIG_C(0x22bb0192U),
                    };
                    r_rsip_func101(Param_p75f_func101_006);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000800U);
                for (jLoop = 0U; jLoop < 16U; jLoop++)
                {
                    r_rsip_func_sub021(0x3c0028a1U, 0x12003c07U, 0x00002ce0U, 0x00002ca0U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1824H, 0x9c000005U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1608H, 0x81840007U);
                r_rsip_func_sub001(0x00490011U);

                WR1_PROG(REG_1600H, 0x0000a4c0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                static const uint32_t Param_p75f_func101_007[] =
                {
                    BSWAP_32BIG_C(0xf4fec2b6U), BSWAP_32BIG_C(0x56c882fdU), BSWAP_32BIG_C(0x566dec9cU), BSWAP_32BIG_C(
                        0x50de45c3U),
                };
                r_rsip_func101(Param_p75f_func101_007);
            }

            WR1_PROG(REG_1600H, 0x000008c2U);

            r_rsip_func_sub014(0x00007c06U, 0x00602000U);

            static const uint32_t Param_p75f_func100_011[] =
            {
                BSWAP_32BIG_C(0x4161a77dU), BSWAP_32BIG_C(0xc9e208e1U), BSWAP_32BIG_C(0xcd29be57U), BSWAP_32BIG_C(
                    0xe5fe0686U),
            };
            r_rsip_func100(Param_p75f_func100_011);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p75f_func102_006[] =
                {
                    BSWAP_32BIG_C(0x334c14f2U), BSWAP_32BIG_C(0x6c2a0ab2U), BSWAP_32BIG_C(0x412700d9U), BSWAP_32BIG_C(
                        0x7f56bac7U),
                };
                r_rsip_func102(Param_p75f_func102_006);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p75f_func102_007[] =
                {
                    BSWAP_32BIG_C(0x9b1a61e8U), BSWAP_32BIG_C(0x464cc247U), BSWAP_32BIG_C(0x85a71031U), BSWAP_32BIG_C(
                        0x4e2483d1U),
                };
                r_rsip_func102(Param_p75f_func102_007);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
