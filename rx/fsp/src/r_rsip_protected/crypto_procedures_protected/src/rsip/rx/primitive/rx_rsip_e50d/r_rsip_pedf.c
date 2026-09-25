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

rsip_ret_t r_rsip_pedf (const uint32_t InData_SignatureType[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Salt[],
                        const uint32_t InData_SaltLength[],
                        uint32_t       OutData_EncCertificateInfo[])
{
    r_rsip_func_sub010(0x000001c7U, 0x80020080U);
    WR1_PROG(REG_1420H, InData_SignatureType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x000000edU);

    static const uint32_t Param_pedf_func101_001[] =
    {
        BSWAP_32BIG_C(0xb4398334U), BSWAP_32BIG_C(0xb5480a12U), BSWAP_32BIG_C(0x408a6880U), BSWAP_32BIG_C(0x983ff6a5U),
    };
    r_rsip_func101(Param_pedf_func101_001);
    r_rsip_func411(InData_MsgDgst);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_pedf_func100_001[] =
    {
        BSWAP_32BIG_C(0xb2677dcdU), BSWAP_32BIG_C(0x5a0fdd62U), BSWAP_32BIG_C(0x9574173fU), BSWAP_32BIG_C(0x9a7f6c1eU),
    };
    r_rsip_func100(Param_pedf_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1404H, 0x17f80000U);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x03430041U);

        WR1_PROG(REG_1600H, 0x00000842U);

        static const uint32_t Param_pedf_func101_002[] =
        {
            BSWAP_32BIG_C(0x3ab3aa83U), BSWAP_32BIG_C(0x983a64d0U), BSWAP_32BIG_C(0xb3cc9f72U), BSWAP_32BIG_C(
                0xbbee3a36U),
        };
        r_rsip_func101(Param_pedf_func101_002);
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_SaltLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x000000edU);

        static const uint32_t Param_pedf_func101_003[] =
        {
            BSWAP_32BIG_C(0x4d45f439U), BSWAP_32BIG_C(0x786bc9e3U), BSWAP_32BIG_C(0xf17e2f9eU), BSWAP_32BIG_C(
                0x666a1a8cU),
        };
        r_rsip_func101(Param_pedf_func101_003);
        r_rsip_func412(InData_Salt);

        r_rsip_func_sub006(0x38008bc0U, 0xc2f4b027U, 0x00A60000U);
        static const uint32_t Param_pedf_func100_002[] =
        {
            BSWAP_32BIG_C(0x6b6b3db4U), BSWAP_32BIG_C(0x2e8c35d9U), BSWAP_32BIG_C(0x006e0773U), BSWAP_32BIG_C(
                0x5e2b971aU),
        };
        r_rsip_func100(Param_pedf_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pedf_func102_001[] =
            {
                BSWAP_32BIG_C(0xc7168e84U), BSWAP_32BIG_C(0x7661f0ceU), BSWAP_32BIG_C(0x1059e742U), BSWAP_32BIG_C(
                    0x028716b9U),
            };
            r_rsip_func102(Param_pedf_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pedf_func101_004[] =
            {
                BSWAP_32BIG_C(0x9eac8f5dU), BSWAP_32BIG_C(0x9d739052U), BSWAP_32BIG_C(0x750f84caU), BSWAP_32BIG_C(
                    0x3a84328aU),
            };
            r_rsip_func101(Param_pedf_func101_004);
        }
    }

    r_rsip_func_sub009(0x000000edU);

    static const uint32_t Param_pedf_func101_005[] =
    {
        BSWAP_32BIG_C(0x2061177eU), BSWAP_32BIG_C(0xef38e0e7U), BSWAP_32BIG_C(0x0792a3e3U), BSWAP_32BIG_C(0x299efe83U),
    };
    r_rsip_func101(Param_pedf_func101_005);
    r_rsip_func413();

    r_rsip_func_sub006(0x38008be0U, 0xd6e85365U, 0x00A60000U);
    static const uint32_t Param_pedf_func100_003[] =
    {
        BSWAP_32BIG_C(0x2d452016U), BSWAP_32BIG_C(0xc2897899U), BSWAP_32BIG_C(0x255e0311U), BSWAP_32BIG_C(0x0ad0d276U),
    };
    r_rsip_func100(Param_pedf_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pedf_func102_002[] =
        {
            BSWAP_32BIG_C(0x364a1d44U), BSWAP_32BIG_C(0x1ae02285U), BSWAP_32BIG_C(0x034ba762U), BSWAP_32BIG_C(
                0x7cf8ee9eU),
        };
        r_rsip_func102(Param_pedf_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub009(0x000000edU);

        static const uint32_t Param_pedf_func101_006[] =
        {
            BSWAP_32BIG_C(0x047cf3cdU), BSWAP_32BIG_C(0xb074ec72U), BSWAP_32BIG_C(0x365f72e5U), BSWAP_32BIG_C(
                0x2741000dU),
        };
        r_rsip_func101(Param_pedf_func101_006);
        r_rsip_func414(OutData_EncCertificateInfo);

        static const uint32_t Param_pedf_func102_003[] =
        {
            BSWAP_32BIG_C(0x8f10bbe9U), BSWAP_32BIG_C(0xb56b8717U), BSWAP_32BIG_C(0x6d48e7deU), BSWAP_32BIG_C(
                0x7337a73cU),
        };
        r_rsip_func102(Param_pedf_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
