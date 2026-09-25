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

rsip_ret_t r_rsip_p11 (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00110001U, 0x000007f0U);

    static const uint32_t Param_p11_func100_001[] =
    {
        BSWAP_32BIG_C(0x62dd9a56U), BSWAP_32BIG_C(0xdf78d3feU), BSWAP_32BIG_C(0x54690ccaU), BSWAP_32BIG_C(0xcdd0b2b5U),
    };
    r_rsip_func100(Param_p11_func100_001);
    r_rsip_func086(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003e0U, 0x0909000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003e0U, 0x09090010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub009(0x00001101U);

    static const uint32_t Param_p11_func101_001[] =
    {
        BSWAP_32BIG_C(0x70aa5dc9U), BSWAP_32BIG_C(0xcffc0e93U), BSWAP_32BIG_C(0xbbacbd15U), BSWAP_32BIG_C(0x361f894cU),
    };
    r_rsip_func101(Param_p11_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00001102U);

    static const uint32_t Param_p11_func101_002[] =
    {
        BSWAP_32BIG_C(0x993a25baU), BSWAP_32BIG_C(0x5e03b041U), BSWAP_32BIG_C(0x929da81bU), BSWAP_32BIG_C(0x3a308e78U),
    };
    r_rsip_func101(Param_p11_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00001103U);

    static const uint32_t Param_p11_func101_003[] =
    {
        BSWAP_32BIG_C(0x459c10ecU), BSWAP_32BIG_C(0xbc26b5b1U), BSWAP_32BIG_C(0x9c021383U), BSWAP_32BIG_C(0x77ff2edbU),
    };
    r_rsip_func101(Param_p11_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00001104U);

    static const uint32_t Param_p11_func101_004[] =
    {
        BSWAP_32BIG_C(0x91af9625U), BSWAP_32BIG_C(0xd7bcf608U), BSWAP_32BIG_C(0x6ede2f9aU), BSWAP_32BIG_C(0x3ddd84e5U),
    };
    r_rsip_func101(Param_p11_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00001105U);

    static const uint32_t Param_p11_func101_005[] =
    {
        BSWAP_32BIG_C(0xebe9c898U), BSWAP_32BIG_C(0xc63a81baU), BSWAP_32BIG_C(0x960ed46dU), BSWAP_32BIG_C(0x448c9921U),
    };
    r_rsip_func101(Param_p11_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20009U);
    r_rsip_func_sub001(0x00020009U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub040(0x000003e0U, 0x00000160U, 0x00000020U, 0x09090004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x13e80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000160U, 0x00000430U, 0x00000340U, 0x09090009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

    static const uint32_t Param_p11_func100_002[] =
    {
        BSWAP_32BIG_C(0x3c52f154U), BSWAP_32BIG_C(0x944753fcU), BSWAP_32BIG_C(0x6f3d4dd1U), BSWAP_32BIG_C(0x134ea818U),
    };
    r_rsip_func100(Param_p11_func100_002);
    r_rsip_func087(InData_DomainParam);

    r_rsip_func_sub009(0x00000011U);

    static const uint32_t Param_p11_func101_006[] =
    {
        BSWAP_32BIG_C(0x90f902bcU), BSWAP_32BIG_C(0x94fa6dc7U), BSWAP_32BIG_C(0xbfb0defcU), BSWAP_32BIG_C(0xf581263fU),
    };
    r_rsip_func101(Param_p11_func101_006);
    r_rsip_func091();

    static const uint32_t Param_p11_func100_003[] =
    {
        BSWAP_32BIG_C(0x9b5a0d3aU), BSWAP_32BIG_C(0x071165cbU), BSWAP_32BIG_C(0x27b2644eU), BSWAP_32BIG_C(0x1275d26cU),
    };
    r_rsip_func100(Param_p11_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p11_func102_001[] =
        {
            BSWAP_32BIG_C(0x1c5d78c5U), BSWAP_32BIG_C(0xaa923422U), BSWAP_32BIG_C(0x99dc2b2aU), BSWAP_32BIG_C(
                0x6cdf8b20U),
        };
        r_rsip_func102(Param_p11_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub041(0x000002a0U, 0x00000840U, 0x000000c0U, 0x000002f0U, 0x00000020U, 0x09090002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        r_rsip_func_sub005(0x000002a0U, 0x09090004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x10c80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c00045U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p11_func100_004[] =
        {
            BSWAP_32BIG_C(0x0613f710U), BSWAP_32BIG_C(0xe7b8fc26U), BSWAP_32BIG_C(0x387ae7f5U), BSWAP_32BIG_C(
                0x40cb0da2U),
        };
        r_rsip_func100(Param_p11_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p11_func102_002[] =
            {
                BSWAP_32BIG_C(0x7ba2149cU), BSWAP_32BIG_C(0xb3550678U), BSWAP_32BIG_C(0x90c228b8U), BSWAP_32BIG_C(
                    0x706340c7U),
            };
            r_rsip_func102(Param_p11_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p11_func100_005[] =
            {
                BSWAP_32BIG_C(0x5a0118deU), BSWAP_32BIG_C(0x28a4de5eU), BSWAP_32BIG_C(0x1cc018d9U), BSWAP_32BIG_C(
                    0xe3d99f5fU),
            };
            r_rsip_func100(Param_p11_func100_005);
            WR1_PROG(REG_1404H, 0x11180000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c00045U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0909000aU);

            r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0909000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub038(0x00000160U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000110U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x11100000U);
            r_rsip_func_sub001(0x00c00011U);

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

            r_rsip_func_sub009(0x00000011U);

            static const uint32_t Param_p11_func101_007[] =
            {
                BSWAP_32BIG_C(0x209e09e3U), BSWAP_32BIG_C(0xf3cbb3daU), BSWAP_32BIG_C(0x07a5e2a6U), BSWAP_32BIG_C(
                    0x503dc5f7U),
            };
            r_rsip_func101(Param_p11_func101_007);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000025U);

            r_rsip_func_sub009(0x00000011U);

            static const uint32_t Param_p11_func101_008[] =
            {
                BSWAP_32BIG_C(0xe6bcd351U), BSWAP_32BIG_C(0xfce497d3U), BSWAP_32BIG_C(0xd70e2512U), BSWAP_32BIG_C(
                    0xc71e865bU),
            };
            r_rsip_func101(Param_p11_func101_008);
            r_rsip_func044();

            r_rsip_func_sub024(0x000013c2U, 0x40000400U, 0xf7009d07U);

            WR1_PROG(REG_1404H, 0x11b00000U);

            for (iLoop = 0U; iLoop < 20; iLoop = iLoop + 4U)
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

            static const uint32_t Param_p11_func100_006[] =
            {
                BSWAP_32BIG_C(0xcf12612fU), BSWAP_32BIG_C(0xe8c250aaU), BSWAP_32BIG_C(0x52bdbf64U), BSWAP_32BIG_C(
                    0xfe5149b7U),
            };
            r_rsip_func100(Param_p11_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p11_func102_003[] =
                {
                    BSWAP_32BIG_C(0xc776ce1eU), BSWAP_32BIG_C(0x6ae6a3b1U), BSWAP_32BIG_C(0xc0007e7fU), BSWAP_32BIG_C(
                        0x2e99b433U),
                };
                r_rsip_func102(Param_p11_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub038(0x00000200U, 0x00000840U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x09090005U, 0x00010001U);
                r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x10c80000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p11_func100_007[] =
                {
                    BSWAP_32BIG_C(0xa484b86dU), BSWAP_32BIG_C(0xc1ee4503U), BSWAP_32BIG_C(0x40860033U), BSWAP_32BIG_C(
                        0x69645640U),
                };
                r_rsip_func100(Param_p11_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p11_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xe75b0ee9U), BSWAP_32BIG_C(0xa0574b61U), BSWAP_32BIG_C(0x3d7d56a8U),
                        BSWAP_32BIG_C(0xd7f73f3cU),
                    };
                    r_rsip_func102(Param_p11_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p11_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x1b18a4ebU), BSWAP_32BIG_C(0xa7d17987U), BSWAP_32BIG_C(0xd2272a3bU),
                        BSWAP_32BIG_C(0x9d11dc14U),
                    };
                    r_rsip_func100(Param_p11_func100_008);
                    WR1_PROG(REG_1404H, 0x12500000U);
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

                    static const uint32_t Param_p11_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x9ae2beeeU), BSWAP_32BIG_C(0xa0e1162dU), BSWAP_32BIG_C(0x0019efd2U),
                        BSWAP_32BIG_C(0x397fb3deU),
                    };
                    r_rsip_func100(Param_p11_func100_009);
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830021U);

                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[12]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[16]);

                    static const uint32_t Param_p11_func100_010[] =
                    {
                        BSWAP_32BIG_C(0xb641f556U), BSWAP_32BIG_C(0xe981219eU), BSWAP_32BIG_C(0x0536a587U),
                        BSWAP_32BIG_C(0x82e36a06U),
                    };
                    r_rsip_func100(Param_p11_func100_010);
                    WR1_PROG(REG_1404H, 0x11b00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[20]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[24]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[28]);

                    static const uint32_t Param_p11_func100_011[] =
                    {
                        BSWAP_32BIG_C(0x7b8fea6bU), BSWAP_32BIG_C(0xc78f9c9cU), BSWAP_32BIG_C(0x5c484c4aU),
                        BSWAP_32BIG_C(0x68df44d7U),
                    };
                    r_rsip_func100(Param_p11_func100_011);
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830021U);

                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[32]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[36]);

                    static const uint32_t Param_p11_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x02b30b5eU), BSWAP_32BIG_C(0x4ea6750bU), BSWAP_32BIG_C(0x350be291U),
                        BSWAP_32BIG_C(0x484c3905U),
                    };
                    r_rsip_func102(Param_p11_func102_005);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
