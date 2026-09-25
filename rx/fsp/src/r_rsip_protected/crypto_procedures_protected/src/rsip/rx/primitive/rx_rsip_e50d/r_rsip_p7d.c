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

rsip_ret_t r_rsip_p7d (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x007d0001U, 0x000007f0U);

    static const uint32_t Param_p7d_func100_001[] =
    {
        BSWAP_32BIG_C(0x600445dcU), BSWAP_32BIG_C(0x39f22583U), BSWAP_32BIG_C(0x2b4f3878U), BSWAP_32BIG_C(0x08690675U),
    };
    r_rsip_func100(Param_p7d_func100_001);
    r_rsip_func078(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x11200000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003f0U, 0x0808000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003f0U, 0x08080010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub009(0x00007d01U);

    static const uint32_t Param_p7d_func101_001[] =
    {
        BSWAP_32BIG_C(0xe7e661a7U), BSWAP_32BIG_C(0x2d277691U), BSWAP_32BIG_C(0xae9c4dfdU), BSWAP_32BIG_C(0x57422ec4U),
    };
    r_rsip_func101(Param_p7d_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00007d02U);

    static const uint32_t Param_p7d_func101_002[] =
    {
        BSWAP_32BIG_C(0x89665d53U), BSWAP_32BIG_C(0xa7b193e4U), BSWAP_32BIG_C(0x8bfefce8U), BSWAP_32BIG_C(0x5011a50aU),
    };
    r_rsip_func101(Param_p7d_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00007d03U);

    static const uint32_t Param_p7d_func101_003[] =
    {
        BSWAP_32BIG_C(0x8b17c235U), BSWAP_32BIG_C(0xd495e552U), BSWAP_32BIG_C(0xde46cac7U), BSWAP_32BIG_C(0xb24bb5b7U),
    };
    r_rsip_func101(Param_p7d_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00007d04U);

    static const uint32_t Param_p7d_func101_004[] =
    {
        BSWAP_32BIG_C(0xe3d7c9cbU), BSWAP_32BIG_C(0xa01d9a03U), BSWAP_32BIG_C(0xab36ef05U), BSWAP_32BIG_C(0x9aaa7fa7U),
    };
    r_rsip_func101(Param_p7d_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub040(0x000003f0U, 0x00000160U, 0x00000020U, 0x08080004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x13f80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000160U, 0x00000438U, 0x00000340U, 0x08080009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x08080010U);

    static const uint32_t Param_p7d_func100_002[] =
    {
        BSWAP_32BIG_C(0x09adde74U), BSWAP_32BIG_C(0xd54cb8bcU), BSWAP_32BIG_C(0xbd90d42cU), BSWAP_32BIG_C(0xbc0e699eU),
    };
    r_rsip_func100(Param_p7d_func100_002);
    r_rsip_func079(InData_DomainParam);

    r_rsip_func_sub009(0x0000007dU);

    static const uint32_t Param_p7d_func101_005[] =
    {
        BSWAP_32BIG_C(0x1350fcb5U), BSWAP_32BIG_C(0xa5899ea2U), BSWAP_32BIG_C(0x988ea265U), BSWAP_32BIG_C(0x31ebb094U),
    };
    r_rsip_func101(Param_p7d_func101_005);
    r_rsip_func090();

    static const uint32_t Param_p7d_func100_003[] =
    {
        BSWAP_32BIG_C(0xaa2cbd83U), BSWAP_32BIG_C(0x6cb1e341U), BSWAP_32BIG_C(0x3e7b64beU), BSWAP_32BIG_C(0xf1c37ae5U),
    };
    r_rsip_func100(Param_p7d_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7d_func102_001[] =
        {
            BSWAP_32BIG_C(0xa7083782U), BSWAP_32BIG_C(0xfb508235U), BSWAP_32BIG_C(0x5e775033U), BSWAP_32BIG_C(
                0x9e88de10U),
        };
        r_rsip_func102(Param_p7d_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub041(0x000002a0U, 0x00000840U, 0x000000c0U, 0x000002f0U, 0x00000020U, 0x08080002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        r_rsip_func_sub005(0x000002a0U, 0x08080004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x10d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0003dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p7d_func100_004[] =
        {
            BSWAP_32BIG_C(0xf0861a6dU), BSWAP_32BIG_C(0x4d973a09U), BSWAP_32BIG_C(0x4151419fU), BSWAP_32BIG_C(
                0xeeaf151dU),
        };
        r_rsip_func100(Param_p7d_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7d_func102_002[] =
            {
                BSWAP_32BIG_C(0x90093301U), BSWAP_32BIG_C(0x21c8a0f7U), BSWAP_32BIG_C(0x2ee3a0c4U), BSWAP_32BIG_C(
                    0x10c62191U),
            };
            r_rsip_func102(Param_p7d_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7d_func100_005[] =
            {
                BSWAP_32BIG_C(0x7ff8852fU), BSWAP_32BIG_C(0xa89777bfU), BSWAP_32BIG_C(0xe3e852b6U), BSWAP_32BIG_C(
                    0x905c6562U),
            };
            r_rsip_func100(Param_p7d_func100_005);
            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0003dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0808000aU);

            r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0808000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub038(0x00000160U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000110U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub024(0x00000fc2U, 0x00000300U, 0x08008107U);

            WR1_PROG(REG_1404H, 0x11200000U);
            for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_MsgDgst[iLoop]);
                r_rsip_func_sub001(0x00c20011U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x0000007dU);

            static const uint32_t Param_p7d_func101_006[] =
            {
                BSWAP_32BIG_C(0xb68b3614U), BSWAP_32BIG_C(0xbb9043adU), BSWAP_32BIG_C(0x31b9fa37U), BSWAP_32BIG_C(
                    0xf24052e1U),
            };
            r_rsip_func101(Param_p7d_func101_006);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000021U);

            r_rsip_func_sub009(0x0000007dU);

            static const uint32_t Param_p7d_func101_007[] =
            {
                BSWAP_32BIG_C(0xefb2ecffU), BSWAP_32BIG_C(0x6f60066aU), BSWAP_32BIG_C(0x39d1a9dcU), BSWAP_32BIG_C(
                    0x7eec05a2U),
            };
            r_rsip_func101(Param_p7d_func101_007);
            r_rsip_func044();

            r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xf7009d07U);

            WR1_PROG(REG_1404H, 0x11c00000U);

            for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
                r_rsip_func_sub001(0x00c20011U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p7d_func100_006[] =
            {
                BSWAP_32BIG_C(0x075bb538U), BSWAP_32BIG_C(0xba8408e8U), BSWAP_32BIG_C(0xf01dcf70U), BSWAP_32BIG_C(
                    0xb87ffca8U),
            };
            r_rsip_func100(Param_p7d_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p7d_func102_003[] =
                {
                    BSWAP_32BIG_C(0xbcb70ab5U), BSWAP_32BIG_C(0x370d1634U), BSWAP_32BIG_C(0x3c0b6ec1U), BSWAP_32BIG_C(
                        0x17d6e11dU),
                };
                r_rsip_func102(Param_p7d_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub038(0x00000200U, 0x00000840U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x08080005U, 0x00010001U);
                r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x10d00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0003dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p7d_func100_007[] =
                {
                    BSWAP_32BIG_C(0x6930f40aU), BSWAP_32BIG_C(0x1eb56175U), BSWAP_32BIG_C(0x5c3818c1U), BSWAP_32BIG_C(
                        0x36b6b7cfU),
                };
                r_rsip_func100(Param_p7d_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p7d_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xf4392008U), BSWAP_32BIG_C(0xe86be2c6U), BSWAP_32BIG_C(0x446ecdd7U),
                        BSWAP_32BIG_C(0xd5880ec4U),
                    };
                    r_rsip_func102(Param_p7d_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p7d_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xe53cd62bU), BSWAP_32BIG_C(0x215156ffU), BSWAP_32BIG_C(0x3b01308aU),
                        BSWAP_32BIG_C(0xdb9038bbU),
                    };
                    r_rsip_func100(Param_p7d_func100_008);
                    WR1_PROG(REG_1404H, 0x12600000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[0]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[4]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[8]);

                    static const uint32_t Param_p7d_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x67ca9087U), BSWAP_32BIG_C(0x0e54d04dU), BSWAP_32BIG_C(0xa5f9429bU),
                        BSWAP_32BIG_C(0x75300d45U),
                    };
                    r_rsip_func100(Param_p7d_func100_009);
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_func_sub001(0x00830011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[12]);

                    static const uint32_t Param_p7d_func100_010[] =
                    {
                        BSWAP_32BIG_C(0xf92f0af4U), BSWAP_32BIG_C(0xc316c1e3U), BSWAP_32BIG_C(0x0ec29593U),
                        BSWAP_32BIG_C(0xf7ba48ebU),
                    };
                    r_rsip_func100(Param_p7d_func100_010);
                    WR1_PROG(REG_1404H, 0x11c00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[16]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[20]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[24]);

                    static const uint32_t Param_p7d_func100_011[] =
                    {
                        BSWAP_32BIG_C(0xb1887650U), BSWAP_32BIG_C(0x79735e1bU), BSWAP_32BIG_C(0x17556a95U),
                        BSWAP_32BIG_C(0x7a0908ccU),
                    };
                    r_rsip_func100(Param_p7d_func100_011);
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_func_sub001(0x00830011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[28]);

                    static const uint32_t Param_p7d_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x3daadc4dU), BSWAP_32BIG_C(0xe1fad26cU), BSWAP_32BIG_C(0x7f687e52U),
                        BSWAP_32BIG_C(0x50dc4549U),
                    };
                    r_rsip_func102(Param_p7d_func102_005);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
