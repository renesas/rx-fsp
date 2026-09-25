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

rsip_ret_t r_rsip_pf0 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00f00001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010380U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    WR1_PROG(REG_1444H, 0x000007c7U);
    WR1_PROG(REG_1608H, 0x8088001eU);
    for (iLoop = 0U; iLoop < 8U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x00000bffU, 0x30003380U, 0x00070020U, 0x0000d3e0U);
    r_rsip_func_sub021(0x00030040U, 0x0000381eU, 0x38000c00U, 0x1000d3e0U);
    r_rsip_func_sub021(0x00050040U, 0x0000381eU, 0x000037beU, 0x0000a7a0U);
    r_rsip_func_sub021(0x00000004U, 0x0000383dU, 0x38001001U, 0x1000d3e0U);
    r_rsip_func_sub021(0x00000080U, 0x30000f5aU, 0x00030020U, 0x0000d3e1U);
    r_rsip_func_sub021(0x00000060U, 0x38000f9cU, 0x1000d3e1U, 0x00000080U);

    r_rsip_func_sub006(0x38008be0U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_pf0_func100_001[] =
    {
        BSWAP_32BIG_C(0xeb9ea453U), BSWAP_32BIG_C(0xc219c5eeU), BSWAP_32BIG_C(0x2e44a142U), BSWAP_32BIG_C(0x204a7f6aU),
    };
    r_rsip_func100(Param_pf0_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf0_func102_001[] =
        {
            BSWAP_32BIG_C(0x8bd10379U), BSWAP_32BIG_C(0x08db0328U), BSWAP_32BIG_C(0x4981eb65U), BSWAP_32BIG_C(
                0xf7ecd94bU),
        };
        r_rsip_func102(Param_pf0_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pf0_func100_002[] =
        {
            BSWAP_32BIG_C(0x6ebb8be8U), BSWAP_32BIG_C(0x149c3bd4U), BSWAP_32BIG_C(0xc3640d57U), BSWAP_32BIG_C(
                0x2863cd98U),
        };
        r_rsip_func100(Param_pf0_func100_002);
        r_rsip_func070(InData_DomainParam);

        WR1_PROG(REG_1404H, 0x11400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000430U, 0x0404000aU);

        r_rsip_func_sub018(0x00000020U, 0x00000430U, 0x04040010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func_sub009(0x0000f001U);

        static const uint32_t Param_pf0_func101_001[] =
        {
            BSWAP_32BIG_C(0x2360f1efU), BSWAP_32BIG_C(0xc5fb1156U), BSWAP_32BIG_C(0x53e8e4d3U), BSWAP_32BIG_C(
                0x2b0bbfc2U),
        };
        r_rsip_func101(Param_pf0_func101_001);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);
        r_rsip_func_sub001(0x00c20011U);

        r_rsip_func_sub009(0x0000f002U);

        static const uint32_t Param_pf0_func101_002[] =
        {
            BSWAP_32BIG_C(0xa21aa656U), BSWAP_32BIG_C(0x46fa6314U), BSWAP_32BIG_C(0x4c6f7394U), BSWAP_32BIG_C(
                0xe94092c1U),
        };
        r_rsip_func101(Param_pf0_func101_002);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);
        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1014H, 0x00000110U);
        r_rsip_func_sub040(0x00000430U, 0x00000160U, 0x00000020U, 0x04040004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x14380000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000160U, 0x00000458U, 0x00000340U, 0x04040009U);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x04040010U);

        static const uint32_t Param_pf0_func100_003[] =
        {
            BSWAP_32BIG_C(0x7c6013edU), BSWAP_32BIG_C(0xae3fd13bU), BSWAP_32BIG_C(0x93ead3edU), BSWAP_32BIG_C(
                0xdc025545U),
        };
        r_rsip_func100(Param_pf0_func100_003);
        r_rsip_func071(InData_DomainParam);

        r_rsip_func_sub009(0x000000f0U);

        static const uint32_t Param_pf0_func101_003[] =
        {
            BSWAP_32BIG_C(0xf3f0f53fU), BSWAP_32BIG_C(0x4b7b936fU), BSWAP_32BIG_C(0xf73c9a85U), BSWAP_32BIG_C(
                0x2531c88aU),
        };
        r_rsip_func101(Param_pf0_func101_003);
        r_rsip_func088();

        static const uint32_t Param_pf0_func100_004[] =
        {
            BSWAP_32BIG_C(0x702dbe6dU), BSWAP_32BIG_C(0xa2fc8568U), BSWAP_32BIG_C(0xbb17042dU), BSWAP_32BIG_C(
                0xe3d8ae08U),
        };
        r_rsip_func100(Param_pf0_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf0_func102_002[] =
            {
                BSWAP_32BIG_C(0x22dffe96U), BSWAP_32BIG_C(0x4ad81af1U), BSWAP_32BIG_C(0x0e1af4fbU), BSWAP_32BIG_C(
                    0xade8cdddU),
            };
            r_rsip_func102(Param_pf0_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub041(0x000002a0U, 0x00000840U, 0x000000c0U, 0x000002f0U, 0x00000020U, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x000002f0U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            r_rsip_func_sub005(0x000002a0U, 0x04040004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_pf0_func100_005[] =
            {
                BSWAP_32BIG_C(0xd35b371dU), BSWAP_32BIG_C(0xff9c3700U), BSWAP_32BIG_C(0xf17d4e76U), BSWAP_32BIG_C(
                    0xb42915b6U),
            };
            r_rsip_func100(Param_pf0_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pf0_func102_003[] =
                {
                    BSWAP_32BIG_C(0xcc73c420U), BSWAP_32BIG_C(0x38b9c8cbU), BSWAP_32BIG_C(0x79f600b8U), BSWAP_32BIG_C(
                        0xf9decc1dU),
                };
                r_rsip_func102(Param_pf0_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pf0_func100_006[] =
                {
                    BSWAP_32BIG_C(0xf85f8142U), BSWAP_32BIG_C(0x2f4badc4U), BSWAP_32BIG_C(0x49cb1e15U), BSWAP_32BIG_C(
                        0xe74e6cb5U),
                };
                r_rsip_func100(Param_pf0_func100_006);
                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0404000aU);

                r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0404000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub038(0x00000160U, 0x00000840U, 0x000000c0U);
                r_rsip_func_sub005(0x00000110U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1608H, 0x8188001eU);
                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub001(0x00c90021U);

                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_KeyIndex[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub009(0x000000f0U);

                static const uint32_t Param_pf0_func101_004[] =
                {
                    BSWAP_32BIG_C(0x48b0024eU), BSWAP_32BIG_C(0xfa548b0eU), BSWAP_32BIG_C(0x649cd99dU), BSWAP_32BIG_C(
                        0x34bdba50U),
                };
                r_rsip_func101(Param_pf0_func101_004);
                r_rsip_func043();

                r_rsip_func074();

                WR1_PROG(REG_1600H, 0x000034feU);

                r_rsip_func_sub009(0x000000f0U);

                static const uint32_t Param_pf0_func101_005[] =
                {
                    BSWAP_32BIG_C(0x7b2adb15U), BSWAP_32BIG_C(0xf95d95bcU), BSWAP_32BIG_C(0x6cc93c8bU), BSWAP_32BIG_C(
                        0xa8b64407U),
                };
                r_rsip_func101(Param_pf0_func101_005);
                r_rsip_func044();

                r_rsip_func_sub024(0x000007c2U, 0x40000100U, 0xf7009d07U);

                for (iLoop = 0U; iLoop < 8U; iLoop = iLoop + 4U)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1404H, 0x11e00000U);
                r_rsip_func_sub001(0x00c20021U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_pf0_func100_007[] =
                {
                    BSWAP_32BIG_C(0xb4475cfdU), BSWAP_32BIG_C(0x510adf3eU), BSWAP_32BIG_C(0x444e16e9U), BSWAP_32BIG_C(
                        0xc187621cU),
                };
                r_rsip_func100(Param_pf0_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pf0_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xc0f97eceU), BSWAP_32BIG_C(0x80abe72fU), BSWAP_32BIG_C(0xa1faaa13U),
                        BSWAP_32BIG_C(0x875325afU),
                    };
                    r_rsip_func102(Param_pf0_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_KEY_FAIL;
                }
                else
                {
                    r_rsip_func_sub038(0x00000200U, 0x00000840U, 0x000000c0U);
                    r_rsip_func_sub005(0x000001b0U, 0x04040002U, 0x00010001U);
                    r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                    r_rsip_func_sub005(0x00000200U, 0x04040002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                    r_rsip_func_sub005(0x000001b0U, 0x04040005U, 0x00010001U);
                    r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                    r_rsip_func_sub005(0x00000200U, 0x04040002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x10f00000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0001dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0404000aU);

                    WR1_PROG(REG_143CH, 0x00210000U);

                    static const uint32_t Param_pf0_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x5cf5a12bU), BSWAP_32BIG_C(0xcccf0c4dU), BSWAP_32BIG_C(0xe31c87e5U),
                        BSWAP_32BIG_C(0x550809e0U),
                    };
                    r_rsip_func100(Param_pf0_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_pf0_func102_005[] =
                        {
                            BSWAP_32BIG_C(0x54791737U), BSWAP_32BIG_C(0x49add93dU), BSWAP_32BIG_C(0x051b08a7U),
                            BSWAP_32BIG_C(0xee7665eeU),
                        };
                        r_rsip_func102(Param_pf0_func102_005);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_FAIL;
                    }
                    else
                    {
                        static const uint32_t Param_pf0_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x009ac05aU), BSWAP_32BIG_C(0x50730cb6U), BSWAP_32BIG_C(0x1c513590U),
                            BSWAP_32BIG_C(0x1d953be0U),
                        };
                        r_rsip_func100(Param_pf0_func100_009);
                        WR1_PROG(REG_1404H, 0x12800000U);
                        WR1_PROG(REG_1A2CH, 0x00000100U);
                        WR1_PROG(REG_1A24H, 0x08008107U);
                        r_rsip_func_sub001(0x00830021U);

                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[0]);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[4]);

                        static const uint32_t Param_pf0_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x3fbcb23fU), BSWAP_32BIG_C(0xb2096fbbU), BSWAP_32BIG_C(0x938a9f75U),
                            BSWAP_32BIG_C(0xde5b5c98U),
                        };
                        r_rsip_func100(Param_pf0_func100_010);
                        WR1_PROG(REG_1404H, 0x11e00000U);
                        WR1_PROG(REG_1A2CH, 0x00000100U);
                        WR1_PROG(REG_1A24H, 0x08008107U);
                        r_rsip_func_sub001(0x00830021U);

                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[8]);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[12]);

                        static const uint32_t Param_pf0_func102_006[] =
                        {
                            BSWAP_32BIG_C(0xe05d9414U), BSWAP_32BIG_C(0xf959acd9U), BSWAP_32BIG_C(0xe65caa37U),
                            BSWAP_32BIG_C(0x9ab671adU),
                        };
                        r_rsip_func102(Param_pf0_func102_006);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
