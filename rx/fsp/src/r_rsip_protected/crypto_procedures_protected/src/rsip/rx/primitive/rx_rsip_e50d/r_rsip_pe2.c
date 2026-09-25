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

rsip_ret_t r_rsip_pe2 (const uint32_t InData_CurveType[],
                       const uint32_t InData_PubKeyType[],
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

    WR1_PROG(REG_1B00H, 0x00e20001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    static const uint32_t Param_pe2_func100_001[] =
    {
        BSWAP_32BIG_C(0xa2943f30U), BSWAP_32BIG_C(0xfb17267bU), BSWAP_32BIG_C(0xf5a42d60U), BSWAP_32BIG_C(0x1390e12dU),
    };
    r_rsip_func100(Param_pe2_func100_001);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420ab40U, 0x00000002U, 0x2000b740U, 0x00000001U);

    WR1_PROG(REG_1600H, 0x00000b9cU);

    r_rsip_func070(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000e201U);

    static const uint32_t Param_pe2_func101_001[] =
    {
        BSWAP_32BIG_C(0xff21a6c9U), BSWAP_32BIG_C(0xaec6dbb9U), BSWAP_32BIG_C(0x80ede59aU), BSWAP_32BIG_C(0x02d782d1U),
    };
    r_rsip_func101(Param_pe2_func101_001);
    r_rsip_func043();

    r_rsip_func074();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub009(0x0000e201U);

    static const uint32_t Param_pe2_func101_002[] =
    {
        BSWAP_32BIG_C(0x9a8e7c10U), BSWAP_32BIG_C(0x2815d8baU), BSWAP_32BIG_C(0xda52aab7U), BSWAP_32BIG_C(0x6be89595U),
    };
    r_rsip_func101(Param_pe2_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x000007c2U, 0x40000100U, 0xf7009d07U);

    for (iLoop = 0U; iLoop < 8U; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x13200000U);
    r_rsip_func_sub001(0x00c20021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe2_func100_002[] =
    {
        BSWAP_32BIG_C(0xdcdc9cb5U), BSWAP_32BIG_C(0x56872faeU), BSWAP_32BIG_C(0x05118c0eU), BSWAP_32BIG_C(0xa07de9c9U),
    };
    r_rsip_func100(Param_pe2_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe2_func102_001[] =
        {
            BSWAP_32BIG_C(0x8081ea46U), BSWAP_32BIG_C(0xfdc19133U), BSWAP_32BIG_C(0x8e94f68fU), BSWAP_32BIG_C(
                0x9bd9ea56U),
        };
        r_rsip_func102(Param_pe2_func102_001);
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

        static const uint32_t Param_pe2_func100_003[] =
        {
            BSWAP_32BIG_C(0xbd53993bU), BSWAP_32BIG_C(0x19efee7dU), BSWAP_32BIG_C(0xc0b0af17U), BSWAP_32BIG_C(
                0x1ae139b9U),
        };
        r_rsip_func100(Param_pe2_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x000007d0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 32U; iLoop = iLoop + 4U)
            {
                WR1_ADDR((&(REG_00F0H))[iLoop / 4], &InData_PubKey[0 + (iLoop / 4)]);
            }

            WR1_PROG(REG_1444H, 0x000007d0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 32U; iLoop = iLoop + 4U)
            {
                WR1_ADDR((&(REG_0140H))[iLoop / 4], &InData_PubKey[8 + (iLoop / 4)]);
            }

            static const uint32_t Param_pe2_func101_003[] =
            {
                BSWAP_32BIG_C(0xfed21b55U), BSWAP_32BIG_C(0x84980aa6U), BSWAP_32BIG_C(0x97ee4c2cU), BSWAP_32BIG_C(
                    0xc1b3e795U),
            };
            r_rsip_func101(Param_pe2_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x0000e202U);

            static const uint32_t Param_pe2_func101_004[] =
            {
                BSWAP_32BIG_C(0xd2d0a931U), BSWAP_32BIG_C(0xa1979c04U), BSWAP_32BIG_C(0x2527954bU), BSWAP_32BIG_C(
                    0xd25addcdU),
            };
            r_rsip_func101(Param_pe2_func101_004);
            r_rsip_func043();

            r_rsip_func075();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub009(0x0000e202U);

            static const uint32_t Param_pe2_func101_005[] =
            {
                BSWAP_32BIG_C(0x07595c4aU), BSWAP_32BIG_C(0xb96488d9U), BSWAP_32BIG_C(0xb06050eeU), BSWAP_32BIG_C(
                    0xfd28bbaeU),
            };
            r_rsip_func101(Param_pe2_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x00000fc2U, 0x40000300U, 0xe8009107U);
            WR4_ADDR(REG_1420H, &InData_PubKey[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[5]);

            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_func_sub001(0x00c20021U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[9]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[13]);

            WR1_PROG(REG_1404H, 0x11400000U);
            r_rsip_func_sub001(0x00c20021U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[17]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pe2_func100_004[] =
            {
                BSWAP_32BIG_C(0x756c8ccdU), BSWAP_32BIG_C(0xd66d1457U), BSWAP_32BIG_C(0x2e358867U), BSWAP_32BIG_C(
                    0x19666e9fU),
            };
            r_rsip_func100(Param_pe2_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe2_func102_002[] =
                {
                    BSWAP_32BIG_C(0x95c1edd5U), BSWAP_32BIG_C(0x35c211f3U), BSWAP_32BIG_C(0x3deefd00U), BSWAP_32BIG_C(
                        0xbf923aadU),
                };
                r_rsip_func102(Param_pe2_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_pe2_func101_006[] =
                {
                    BSWAP_32BIG_C(0xff83ef9cU), BSWAP_32BIG_C(0xb3e1fcc3U), BSWAP_32BIG_C(0x7dfb5a4cU), BSWAP_32BIG_C(
                        0x0ffff05cU),
                };
                r_rsip_func101(Param_pe2_func101_006);
            }
        }

        r_rsip_func008();

        static const uint32_t Param_pe2_func100_005[] =
        {
            BSWAP_32BIG_C(0x91995cefU), BSWAP_32BIG_C(0x515051daU), BSWAP_32BIG_C(0x8b174b26U), BSWAP_32BIG_C(
                0x4bfee39aU),
        };
        r_rsip_func100(Param_pe2_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe2_func102_003[] =
            {
                BSWAP_32BIG_C(0xcb4c756cU), BSWAP_32BIG_C(0x2c7a9a98U), BSWAP_32BIG_C(0xaef36338U), BSWAP_32BIG_C(
                    0x25f67194U),
            };
            r_rsip_func102(Param_pe2_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_func_sub001(0x00c00021U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000228U, 0x04040009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000200U, 0x04040009U);

            r_rsip_func_sub009(0x000000e2U);

            static const uint32_t Param_pe2_func101_007[] =
            {
                BSWAP_32BIG_C(0x67eb6ad9U), BSWAP_32BIG_C(0xa7e160f6U), BSWAP_32BIG_C(0x2492edf4U), BSWAP_32BIG_C(
                    0x3bce480eU),
            };
            r_rsip_func101(Param_pe2_func101_007);
            r_rsip_func088();

            static const uint32_t Param_pe2_func100_006[] =
            {
                BSWAP_32BIG_C(0x6e5fc1b1U), BSWAP_32BIG_C(0xc3a0fc7aU), BSWAP_32BIG_C(0xf173ad84U), BSWAP_32BIG_C(
                    0x66a72eeeU),
            };
            r_rsip_func100(Param_pe2_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe2_func102_004[] =
                {
                    BSWAP_32BIG_C(0x66c6b4e3U), BSWAP_32BIG_C(0x297dc300U), BSWAP_32BIG_C(0xac0f0f06U), BSWAP_32BIG_C(
                        0x01fca736U),
                };
                r_rsip_func102(Param_pe2_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub009(0x000000e2U);

                static const uint32_t Param_pe2_func101_008[] =
                {
                    BSWAP_32BIG_C(0x4cb8785dU), BSWAP_32BIG_C(0x6d3245a3U), BSWAP_32BIG_C(0x0f108738U), BSWAP_32BIG_C(
                        0xf61100a9U),
                };
                r_rsip_func101(Param_pe2_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x0000e203U);

                static const uint32_t Param_pe2_func101_009[] =
                {
                    BSWAP_32BIG_C(0x5609ebbcU), BSWAP_32BIG_C(0xca759305U), BSWAP_32BIG_C(0x59397c6fU), BSWAP_32BIG_C(
                        0x290fd473U),
                };
                r_rsip_func101(Param_pe2_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01fdb192U);

                r_rsip_func_sub009(0x0000e203U);

                static const uint32_t Param_pe2_func101_010[] =
                {
                    BSWAP_32BIG_C(0x06044718U), BSWAP_32BIG_C(0x0235ffeeU), BSWAP_32BIG_C(0x52fb1e41U), BSWAP_32BIG_C(
                        0xc5862053U),
                };
                r_rsip_func101(Param_pe2_func101_010);
                r_rsip_func044();

                static const uint32_t Param_pe2_func100_007[] =
                {
                    BSWAP_32BIG_C(0xb2e9da34U), BSWAP_32BIG_C(0x46ccd211U), BSWAP_32BIG_C(0x253ac515U), BSWAP_32BIG_C(
                        0x72f200a5U),
                };
                r_rsip_func100(Param_pe2_func100_007);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12800000U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[5]);

                static const uint32_t Param_pe2_func100_008[] =
                {
                    BSWAP_32BIG_C(0xe4bc5c17U), BSWAP_32BIG_C(0xaf62dcf8U), BSWAP_32BIG_C(0xcc4a3b24U), BSWAP_32BIG_C(
                        0x5c716ec0U),
                };
                r_rsip_func100(Param_pe2_func100_008);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[9]);

                static const uint32_t Param_pe2_func100_009[] =
                {
                    BSWAP_32BIG_C(0x90c98adbU), BSWAP_32BIG_C(0x94e95252U), BSWAP_32BIG_C(0xb9b55db2U), BSWAP_32BIG_C(
                        0x8f737326U),
                };
                r_rsip_func100(Param_pe2_func100_009);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_pe2_func102_005[] =
                {
                    BSWAP_32BIG_C(0xe20959a6U), BSWAP_32BIG_C(0x577a39c3U), BSWAP_32BIG_C(0x7015bb56U), BSWAP_32BIG_C(
                        0xd114429bU),
                };
                r_rsip_func102(Param_pe2_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
