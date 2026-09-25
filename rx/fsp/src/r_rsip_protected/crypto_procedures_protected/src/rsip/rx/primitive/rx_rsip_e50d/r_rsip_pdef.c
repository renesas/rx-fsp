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

rsip_ret_t r_rsip_pdef (const uint32_t InData_SignatureType[],
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

    r_rsip_func_sub009(0x000000deU);

    static const uint32_t Param_pdef_func101_001[] =
    {
        BSWAP_32BIG_C(0x34e7a8ecU), BSWAP_32BIG_C(0x8722d777U), BSWAP_32BIG_C(0xbb0b670bU), BSWAP_32BIG_C(0xc67a7fdbU),
    };
    r_rsip_func101(Param_pdef_func101_001);
    r_rsip_func411(InData_MsgDgst);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_pdef_func100_001[] =
    {
        BSWAP_32BIG_C(0x74c0debeU), BSWAP_32BIG_C(0x498f408eU), BSWAP_32BIG_C(0x753a7946U), BSWAP_32BIG_C(0x3d9f7020U),
    };
    r_rsip_func100(Param_pdef_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1404H, 0x17f80000U);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x03430041U);

        WR1_PROG(REG_1600H, 0x00000842U);

        static const uint32_t Param_pdef_func101_002[] =
        {
            BSWAP_32BIG_C(0x1ff4e52fU), BSWAP_32BIG_C(0x3e829228U), BSWAP_32BIG_C(0xad736c9bU), BSWAP_32BIG_C(
                0xc62e06c5U),
        };
        r_rsip_func101(Param_pdef_func101_002);
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_SaltLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x000000deU);

        static const uint32_t Param_pdef_func101_003[] =
        {
            BSWAP_32BIG_C(0xfd0401faU), BSWAP_32BIG_C(0xd942f996U), BSWAP_32BIG_C(0x0e76610aU), BSWAP_32BIG_C(
                0x116e51faU),
        };
        r_rsip_func101(Param_pdef_func101_003);
        r_rsip_func412(InData_Salt);

        r_rsip_func_sub006(0x38008bc0U, 0xc2f4b027U, 0x00A60000U);
        static const uint32_t Param_pdef_func100_002[] =
        {
            BSWAP_32BIG_C(0xc82b495eU), BSWAP_32BIG_C(0xfd2b7c20U), BSWAP_32BIG_C(0x421674b3U), BSWAP_32BIG_C(
                0x643fac71U),
        };
        r_rsip_func100(Param_pdef_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdef_func102_001[] =
            {
                BSWAP_32BIG_C(0xf9bd8d03U), BSWAP_32BIG_C(0xcc6f4dc4U), BSWAP_32BIG_C(0xc8c25210U), BSWAP_32BIG_C(
                    0xf5c70b24U),
            };
            r_rsip_func102(Param_pdef_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdef_func101_004[] =
            {
                BSWAP_32BIG_C(0x5477c3f0U), BSWAP_32BIG_C(0x9ab384a6U), BSWAP_32BIG_C(0xf4969d19U), BSWAP_32BIG_C(
                    0xebc1dbd7U),
            };
            r_rsip_func101(Param_pdef_func101_004);
        }
    }

    r_rsip_func_sub009(0x000000deU);

    static const uint32_t Param_pdef_func101_005[] =
    {
        BSWAP_32BIG_C(0x247e3b8dU), BSWAP_32BIG_C(0xd8cc22c2U), BSWAP_32BIG_C(0x403d9289U), BSWAP_32BIG_C(0x31ef7be0U),
    };
    r_rsip_func101(Param_pdef_func101_005);
    r_rsip_func413();

    r_rsip_func_sub006(0x38008be0U, 0xd6e85365U, 0x00A60000U);
    static const uint32_t Param_pdef_func100_003[] =
    {
        BSWAP_32BIG_C(0x49721f78U), BSWAP_32BIG_C(0x199ccf6bU), BSWAP_32BIG_C(0x284bd0f8U), BSWAP_32BIG_C(0x8b0401c2U),
    };
    r_rsip_func100(Param_pdef_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdef_func102_002[] =
        {
            BSWAP_32BIG_C(0xc506a338U), BSWAP_32BIG_C(0x983a5d87U), BSWAP_32BIG_C(0x7f7c0f7bU), BSWAP_32BIG_C(
                0xac0dbedeU),
        };
        r_rsip_func102(Param_pdef_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub009(0x000000deU);

        static const uint32_t Param_pdef_func101_006[] =
        {
            BSWAP_32BIG_C(0xce649cd2U), BSWAP_32BIG_C(0xd7a099a8U), BSWAP_32BIG_C(0xb4bcda65U), BSWAP_32BIG_C(
                0x7c03fe78U),
        };
        r_rsip_func101(Param_pdef_func101_006);
        r_rsip_func414(OutData_EncCertificateInfo);

        static const uint32_t Param_pdef_func102_003[] =
        {
            BSWAP_32BIG_C(0x8272fc1fU), BSWAP_32BIG_C(0x7c0d1633U), BSWAP_32BIG_C(0xec412da3U), BSWAP_32BIG_C(
                0x0e72ac0dU),
        };
        r_rsip_func102(Param_pdef_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
