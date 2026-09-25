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

rsip_ret_t r_rsip_pf5 (const uint32_t InData_CurveType[],
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

    r_rsip_func_sub029(0x00f50001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_pf5_func100_001[] =
    {
        BSWAP_32BIG_C(0x690ca2acU), BSWAP_32BIG_C(0x73c774abU), BSWAP_32BIG_C(0xbedc256fU), BSWAP_32BIG_C(0x336a51ccU),
    };
    r_rsip_func100(Param_pf5_func100_001);
    r_rsip_func027(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x11300000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000410U, 0x0606000aU);

    r_rsip_func_sub018(0x00000020U, 0x00000410U, 0x06060010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub009(0x0000f501U);

    static const uint32_t Param_pf5_func101_001[] =
    {
        BSWAP_32BIG_C(0x619d78ddU), BSWAP_32BIG_C(0x81e33828U), BSWAP_32BIG_C(0x58454013U), BSWAP_32BIG_C(0xc5ad2226U),
    };
    r_rsip_func101(Param_pf5_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x0000f502U);

    static const uint32_t Param_pf5_func101_002[] =
    {
        BSWAP_32BIG_C(0x77e05b83U), BSWAP_32BIG_C(0xee5701cfU), BSWAP_32BIG_C(0x610001acU), BSWAP_32BIG_C(0xc7307de8U),
    };
    r_rsip_func101(Param_pf5_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x0000f503U);

    static const uint32_t Param_pf5_func101_003[] =
    {
        BSWAP_32BIG_C(0xc3a1c4fdU), BSWAP_32BIG_C(0x819be491U), BSWAP_32BIG_C(0xe5139c8cU), BSWAP_32BIG_C(0x61d1ff45U),
    };
    r_rsip_func101(Param_pf5_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub040(0x00000410U, 0x00000160U, 0x00000020U, 0x06060004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x14180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000160U, 0x00000448U, 0x00000340U, 0x06060009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

    static const uint32_t Param_pf5_func100_002[] =
    {
        BSWAP_32BIG_C(0x42df1761U), BSWAP_32BIG_C(0x03d4c4ceU), BSWAP_32BIG_C(0x503e1449U), BSWAP_32BIG_C(0xfa503f5bU),
    };
    r_rsip_func100(Param_pf5_func100_002);
    r_rsip_func028(InData_DomainParam);

    r_rsip_func_sub009(0x000000f5U);

    static const uint32_t Param_pf5_func101_004[] =
    {
        BSWAP_32BIG_C(0x3424820dU), BSWAP_32BIG_C(0xa47d9144U), BSWAP_32BIG_C(0xcf2c89f0U), BSWAP_32BIG_C(0xac948e46U),
    };
    r_rsip_func101(Param_pf5_func101_004);
    r_rsip_func089();

    static const uint32_t Param_pf5_func100_003[] =
    {
        BSWAP_32BIG_C(0x1add9832U), BSWAP_32BIG_C(0xe7fe65fcU), BSWAP_32BIG_C(0x7eab8fccU), BSWAP_32BIG_C(0x62ac4ccbU),
    };
    r_rsip_func100(Param_pf5_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf5_func102_001[] =
        {
            BSWAP_32BIG_C(0xa8309f9eU), BSWAP_32BIG_C(0xd0ff3c87U), BSWAP_32BIG_C(0xedc8a581U), BSWAP_32BIG_C(
                0x28e6d776U),
        };
        r_rsip_func102(Param_pf5_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub041(0x000002a0U, 0x00000840U, 0x000000c0U, 0x000002f0U, 0x00000020U, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        r_rsip_func_sub005(0x000002a0U, 0x06060004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x10e00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pf5_func100_004[] =
        {
            BSWAP_32BIG_C(0xaf7a86fcU), BSWAP_32BIG_C(0xb89cd300U), BSWAP_32BIG_C(0x0fd84838U), BSWAP_32BIG_C(
                0xfb09bdf9U),
        };
        r_rsip_func100(Param_pf5_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf5_func102_002[] =
            {
                BSWAP_32BIG_C(0xf5084ac7U), BSWAP_32BIG_C(0x8f57becaU), BSWAP_32BIG_C(0xfe23ff40U), BSWAP_32BIG_C(
                    0xe720510dU),
            };
            r_rsip_func102(Param_pf5_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf5_func100_005[] =
            {
                BSWAP_32BIG_C(0xaeec492dU), BSWAP_32BIG_C(0xf397d284U), BSWAP_32BIG_C(0x576dc14dU), BSWAP_32BIG_C(
                    0x809a895cU),
            };
            r_rsip_func100(Param_pf5_func100_005);
            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0606000aU);

            r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0606000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub038(0x00000160U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000110U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub024(0x00000bc2U, 0x00000200U, 0x08008107U);

            WR1_PROG(REG_1404H, 0x11300000U);
            for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_MsgDgst[iLoop]);
                r_rsip_func_sub001(0x00c20011U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x000000f5U);

            static const uint32_t Param_pf5_func101_005[] =
            {
                BSWAP_32BIG_C(0x79635c60U), BSWAP_32BIG_C(0xe9503b2bU), BSWAP_32BIG_C(0x7cb64f31U), BSWAP_32BIG_C(
                    0x85d6fea8U),
            };
            r_rsip_func101(Param_pf5_func101_005);
            r_rsip_func043();

            r_rsip_func076();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub009(0x000000f5U);

            static const uint32_t Param_pf5_func101_006[] =
            {
                BSWAP_32BIG_C(0x79b857d1U), BSWAP_32BIG_C(0xfd48ce45U), BSWAP_32BIG_C(0x3676e6c2U), BSWAP_32BIG_C(
                    0x8c73dcf5U),
            };
            r_rsip_func101(Param_pf5_func101_006);
            r_rsip_func044();

            r_rsip_func_sub024(0x00000bc2U, 0x40000200U, 0xf7009d07U);

            for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x11d00000U);
            r_rsip_func_sub001(0x00c20031U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pf5_func100_006[] =
            {
                BSWAP_32BIG_C(0xa189b4b9U), BSWAP_32BIG_C(0xe41d02a8U), BSWAP_32BIG_C(0x0dbbfb9fU), BSWAP_32BIG_C(
                    0xf4e66a10U),
            };
            r_rsip_func100(Param_pf5_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pf5_func102_003[] =
                {
                    BSWAP_32BIG_C(0x331d7ce9U), BSWAP_32BIG_C(0xfc99ac30U), BSWAP_32BIG_C(0x1025b4d5U), BSWAP_32BIG_C(
                        0xa5d9a62eU),
                };
                r_rsip_func102(Param_pf5_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub038(0x00000200U, 0x00000840U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x06060005U, 0x00010001U);
                r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x10e00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_pf5_func100_007[] =
                {
                    BSWAP_32BIG_C(0xf58434d6U), BSWAP_32BIG_C(0x4e0b733aU), BSWAP_32BIG_C(0xc2f74b07U), BSWAP_32BIG_C(
                        0xbc051de8U),
                };
                r_rsip_func100(Param_pf5_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pf5_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x6d4d5281U), BSWAP_32BIG_C(0xee99cb50U), BSWAP_32BIG_C(0x1e9c6978U),
                        BSWAP_32BIG_C(0x164bee35U),
                    };
                    r_rsip_func102(Param_pf5_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_pf5_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x1822b527U), BSWAP_32BIG_C(0x0decfa99U), BSWAP_32BIG_C(0xae3d1b97U),
                        BSWAP_32BIG_C(0x49bb2ab4U),
                    };
                    r_rsip_func100(Param_pf5_func100_008);
                    WR1_PROG(REG_1404H, 0x12700000U);
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

                    static const uint32_t Param_pf5_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x6d20c0d0U), BSWAP_32BIG_C(0x5d074f38U), BSWAP_32BIG_C(0x14554782U),
                        BSWAP_32BIG_C(0x61362dc7U),
                    };
                    r_rsip_func100(Param_pf5_func100_009);
                    WR1_PROG(REG_1404H, 0x11d00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[12]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[16]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[20]);

                    static const uint32_t Param_pf5_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x0e26f78eU), BSWAP_32BIG_C(0x0a21ba69U), BSWAP_32BIG_C(0xc3a71200U),
                        BSWAP_32BIG_C(0xd2a202b2U),
                    };
                    r_rsip_func102(Param_pf5_func102_005);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
