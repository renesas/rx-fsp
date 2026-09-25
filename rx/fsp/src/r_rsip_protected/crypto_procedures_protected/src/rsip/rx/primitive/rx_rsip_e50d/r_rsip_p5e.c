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

rsip_ret_t r_rsip_p5e (const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x005e0001U, 0x000007f0U);

    static const uint32_t Param_p5e_func100_001[] =
    {
        BSWAP_32BIG_C(0x98ee66ebU), BSWAP_32BIG_C(0x56b0cf56U), BSWAP_32BIG_C(0x4c9d23e2U), BSWAP_32BIG_C(0xdb2bd7a0U),
    };
    r_rsip_func100(Param_p5e_func100_001);
    r_rsip_func078(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00005e01U);

    static const uint32_t Param_p5e_func101_001[] =
    {
        BSWAP_32BIG_C(0x9614b9d4U), BSWAP_32BIG_C(0xab74141cU), BSWAP_32BIG_C(0x96cfee4eU), BSWAP_32BIG_C(0xcddc25fdU),
    };
    r_rsip_func101(Param_p5e_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000021U);

    r_rsip_func_sub009(0x00005e01U);

    static const uint32_t Param_p5e_func101_002[] =
    {
        BSWAP_32BIG_C(0xcaa5daa6U), BSWAP_32BIG_C(0xf371554eU), BSWAP_32BIG_C(0x0619b1f6U), BSWAP_32BIG_C(0x6e1c9516U),
    };
    r_rsip_func101(Param_p5e_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xf7009d07U);

    WR1_PROG(REG_1404H, 0x13000000U);

    for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x00c20011U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p5e_func100_002[] =
    {
        BSWAP_32BIG_C(0x8bfd6c8cU), BSWAP_32BIG_C(0xbc69df8bU), BSWAP_32BIG_C(0x24678fb5U), BSWAP_32BIG_C(0x74810b30U),
    };
    r_rsip_func100(Param_p5e_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p5e_func102_001[] =
        {
            BSWAP_32BIG_C(0x5d036eb0U), BSWAP_32BIG_C(0xcd82f43bU), BSWAP_32BIG_C(0xee74967bU), BSWAP_32BIG_C(
                0x854c7438U),
        };
        r_rsip_func102(Param_p5e_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010360U);
        WR1_PROG(REG_1420H, InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000f7bU, 0x00260000U);

        static const uint32_t Param_p5e_func100_003[] =
        {
            BSWAP_32BIG_C(0xc2987a7fU), BSWAP_32BIG_C(0x204525f7U), BSWAP_32BIG_C(0x509b2693U), BSWAP_32BIG_C(
                0xaac0f7b5U),
        };
        r_rsip_func100(Param_p5e_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x00000fd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
            {
                WR1_ADDR((&(REG_00D0H))[iLoop / 4], &InData_PubKey[0 + (iLoop / 4)]);
            }

            WR1_PROG(REG_1444H, 0x00000fd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 64U; iLoop = iLoop + 4U)
            {
                WR1_ADDR((&(REG_0120H))[iLoop / 4], &InData_PubKey[16 + (iLoop / 4)]);
            }

            static const uint32_t Param_p5e_func101_003[] =
            {
                BSWAP_32BIG_C(0xdf6eb8beU), BSWAP_32BIG_C(0x15e90e4fU), BSWAP_32BIG_C(0xacb9d103U), BSWAP_32BIG_C(
                    0xb16c7460U),
            };
            r_rsip_func101(Param_p5e_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00005e02U);

            static const uint32_t Param_p5e_func101_004[] =
            {
                BSWAP_32BIG_C(0xea0e7e24U), BSWAP_32BIG_C(0x09eb8da4U), BSWAP_32BIG_C(0xe29571a6U), BSWAP_32BIG_C(
                    0x25b87b75U),
            };
            r_rsip_func101(Param_p5e_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000020U);

            r_rsip_func_sub009(0x00005e02U);

            static const uint32_t Param_p5e_func101_005[] =
            {
                BSWAP_32BIG_C(0x1462a017U), BSWAP_32BIG_C(0x174b2602U), BSWAP_32BIG_C(0x2d3e6e21U), BSWAP_32BIG_C(
                    0xa9a3e4d9U),
            };
            r_rsip_func101(Param_p5e_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub024(0x00001fc2U, 0x40000700U, 0xe8009107U);

            WR1_PROG(REG_1404H, 0x10d00000U);

            for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_PubKey[1 + iLoop]);
                r_rsip_func_sub001(0x00c20011U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x11200000U);

            for (iLoop = 16; iLoop < 32U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_PubKey[1 + iLoop]);
                r_rsip_func_sub001(0x00c20011U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[1 + iLoop]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p5e_func100_004[] =
            {
                BSWAP_32BIG_C(0x44c8878dU), BSWAP_32BIG_C(0x18d237a6U), BSWAP_32BIG_C(0xb7bb7260U), BSWAP_32BIG_C(
                    0x8a2befb4U),
            };
            r_rsip_func100(Param_p5e_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p5e_func102_002[] =
                {
                    BSWAP_32BIG_C(0xf3beb70cU), BSWAP_32BIG_C(0x49b80e75U), BSWAP_32BIG_C(0x54876670U), BSWAP_32BIG_C(
                        0xb35f02d9U),
                };
                r_rsip_func102(Param_p5e_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_p5e_func101_006[] =
                {
                    BSWAP_32BIG_C(0x77711b6fU), BSWAP_32BIG_C(0x4cc171eeU), BSWAP_32BIG_C(0x44467c6cU), BSWAP_32BIG_C(
                        0xb2eea901U),
                };
                r_rsip_func101(Param_p5e_func101_006);
            }
        }

        r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x000001b0U, 0x08080002U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x08080001U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x00000890U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x08080005U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x000001b0U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x08080002U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x000008e0U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x08080005U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x08080001U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000250U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000110U, 0x00000250U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p5e_func100_005[] =
        {
            BSWAP_32BIG_C(0x105e9a75U), BSWAP_32BIG_C(0xec24573dU), BSWAP_32BIG_C(0x9171d2aaU), BSWAP_32BIG_C(
                0xdf57c3a3U),
        };
        r_rsip_func100(Param_p5e_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p5e_func102_003[] =
            {
                BSWAP_32BIG_C(0x9c684e40U), BSWAP_32BIG_C(0xb9c748f0U), BSWAP_32BIG_C(0x3112a129U), BSWAP_32BIG_C(
                    0xfa126782U),
            };
            r_rsip_func102(Param_p5e_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10d00000U);
            r_rsip_func_sub001(0x00c00041U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000208U, 0x08080009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x000001c0U, 0x08080009U);

            r_rsip_func_sub009(0x0000005eU);

            static const uint32_t Param_p5e_func101_007[] =
            {
                BSWAP_32BIG_C(0xacab9785U), BSWAP_32BIG_C(0x3fb81317U), BSWAP_32BIG_C(0x0f6eee7eU), BSWAP_32BIG_C(
                    0xe8df00c9U),
            };
            r_rsip_func101(Param_p5e_func101_007);
            r_rsip_func090();

            static const uint32_t Param_p5e_func100_006[] =
            {
                BSWAP_32BIG_C(0x0220fc65U), BSWAP_32BIG_C(0x7b6648d2U), BSWAP_32BIG_C(0xcd832a65U), BSWAP_32BIG_C(
                    0x1fe03d7dU),
            };
            r_rsip_func100(Param_p5e_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p5e_func102_004[] =
                {
                    BSWAP_32BIG_C(0xbe9de2b9U), BSWAP_32BIG_C(0xb6e1538dU), BSWAP_32BIG_C(0x1dc7de7bU), BSWAP_32BIG_C(
                        0xe6f077c1U),
                };
                r_rsip_func102(Param_p5e_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub009(0x0000005eU);

                static const uint32_t Param_p5e_func101_008[] =
                {
                    BSWAP_32BIG_C(0xea74d7a1U), BSWAP_32BIG_C(0x75a49c39U), BSWAP_32BIG_C(0xb9d862bfU), BSWAP_32BIG_C(
                        0x6e712d4fU),
                };
                r_rsip_func101(Param_p5e_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x00005e03U);

                static const uint32_t Param_p5e_func101_009[] =
                {
                    BSWAP_32BIG_C(0xd56f2301U), BSWAP_32BIG_C(0x76774733U), BSWAP_32BIG_C(0xde4c4e1dU), BSWAP_32BIG_C(
                        0x08b4f181U),
                };
                r_rsip_func101(Param_p5e_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01dcc5c6U);

                r_rsip_func_sub009(0x00005e03U);

                static const uint32_t Param_p5e_func101_010[] =
                {
                    BSWAP_32BIG_C(0x155e714bU), BSWAP_32BIG_C(0xc88698a5U), BSWAP_32BIG_C(0x9f179afcU), BSWAP_32BIG_C(
                        0x04730d90U),
                };
                r_rsip_func101(Param_p5e_func101_010);
                r_rsip_func044();

                static const uint32_t Param_p5e_func100_007[] =
                {
                    BSWAP_32BIG_C(0x14547728U), BSWAP_32BIG_C(0x790b523cU), BSWAP_32BIG_C(0x4cbab48dU), BSWAP_32BIG_C(
                        0x57b90eebU),
                };
                r_rsip_func100(Param_p5e_func100_007);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12600000U);
                r_rsip_func_sub001(0x00830031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
                {
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_EncSecret[1 + iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p5e_func100_008[] =
                {
                    BSWAP_32BIG_C(0xcde3abd0U), BSWAP_32BIG_C(0x0e1b85d9U), BSWAP_32BIG_C(0xbe9c30b7U), BSWAP_32BIG_C(
                        0x157df92fU),
                };
                r_rsip_func100(Param_p5e_func100_008);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe7008d05U);
                r_rsip_func_sub001(0x00830011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[1 + iLoop]);
                static const uint32_t Param_p5e_func100_009[] =
                {
                    BSWAP_32BIG_C(0x8214072eU), BSWAP_32BIG_C(0x1f996088U), BSWAP_32BIG_C(0x0bc71f1aU), BSWAP_32BIG_C(
                        0xfa47dd29U),
                };
                r_rsip_func100(Param_p5e_func100_009);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[5 + iLoop]);

                static const uint32_t Param_p5e_func100_010[] =
                {
                    BSWAP_32BIG_C(0x035f3555U), BSWAP_32BIG_C(0x423a5ba9U), BSWAP_32BIG_C(0x53dac3d3U), BSWAP_32BIG_C(
                        0xf0679c7bU),
                };
                r_rsip_func100(Param_p5e_func100_010);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_p5e_func102_005[] =
                {
                    BSWAP_32BIG_C(0x6f416889U), BSWAP_32BIG_C(0x5ce06fd9U), BSWAP_32BIG_C(0x5cb9d60bU), BSWAP_32BIG_C(
                        0x7d14c335U),
                };
                r_rsip_func102(Param_p5e_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
