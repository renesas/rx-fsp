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

rsip_ret_t r_rsip_pdff (const uint32_t InData_SignatureType[],
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

    r_rsip_func_sub009(0x000000dfU);

    static const uint32_t Param_pdff_func101_001[] =
    {
        BSWAP_32BIG_C(0xcff07076U), BSWAP_32BIG_C(0x0a3e867dU), BSWAP_32BIG_C(0x97a35b4dU), BSWAP_32BIG_C(0xd4a9c554U),
    };
    r_rsip_func101(Param_pdff_func101_001);
    r_rsip_func411(InData_MsgDgst);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_pdff_func100_001[] =
    {
        BSWAP_32BIG_C(0x604f9ae9U), BSWAP_32BIG_C(0x8f6be5fbU), BSWAP_32BIG_C(0xb720313cU), BSWAP_32BIG_C(0x68b48d29U),
    };
    r_rsip_func100(Param_pdff_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1404H, 0x17f80000U);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x03430041U);

        WR1_PROG(REG_1600H, 0x00000842U);

        static const uint32_t Param_pdff_func101_002[] =
        {
            BSWAP_32BIG_C(0x4786273cU), BSWAP_32BIG_C(0xe2c90e85U), BSWAP_32BIG_C(0x2775c801U), BSWAP_32BIG_C(
                0x8b211fabU),
        };
        r_rsip_func101(Param_pdff_func101_002);
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_SaltLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x000000dfU);

        static const uint32_t Param_pdff_func101_003[] =
        {
            BSWAP_32BIG_C(0x1aed4d84U), BSWAP_32BIG_C(0x0b4b35fcU), BSWAP_32BIG_C(0xfeea6680U), BSWAP_32BIG_C(
                0x2b28d161U),
        };
        r_rsip_func101(Param_pdff_func101_003);
        r_rsip_func412(InData_Salt);

        r_rsip_func_sub006(0x38008bc0U, 0xc2f4b027U, 0x00A60000U);
        static const uint32_t Param_pdff_func100_002[] =
        {
            BSWAP_32BIG_C(0xbfe43cb8U), BSWAP_32BIG_C(0x9ede288eU), BSWAP_32BIG_C(0xac8aebd9U), BSWAP_32BIG_C(
                0xaacec756U),
        };
        r_rsip_func100(Param_pdff_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdff_func102_001[] =
            {
                BSWAP_32BIG_C(0x7331b47bU), BSWAP_32BIG_C(0x72204169U), BSWAP_32BIG_C(0x91dabedeU), BSWAP_32BIG_C(
                    0x49b04b24U),
            };
            r_rsip_func102(Param_pdff_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdff_func101_004[] =
            {
                BSWAP_32BIG_C(0x3b3ca93dU), BSWAP_32BIG_C(0x06315734U), BSWAP_32BIG_C(0x5548bec8U), BSWAP_32BIG_C(
                    0x0a1f80e6U),
            };
            r_rsip_func101(Param_pdff_func101_004);
        }
    }

    r_rsip_func_sub009(0x000000dfU);

    static const uint32_t Param_pdff_func101_005[] =
    {
        BSWAP_32BIG_C(0xb165f8eeU), BSWAP_32BIG_C(0xc1c9ec79U), BSWAP_32BIG_C(0x72b333f7U), BSWAP_32BIG_C(0xa969b8c9U),
    };
    r_rsip_func101(Param_pdff_func101_005);
    r_rsip_func413();

    r_rsip_func_sub006(0x38008be0U, 0xd6e85365U, 0x00A60000U);
    static const uint32_t Param_pdff_func100_003[] =
    {
        BSWAP_32BIG_C(0x5b68497dU), BSWAP_32BIG_C(0x4f69d4bfU), BSWAP_32BIG_C(0xd8b546bfU), BSWAP_32BIG_C(0x173efba6U),
    };
    r_rsip_func100(Param_pdff_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdff_func102_002[] =
        {
            BSWAP_32BIG_C(0xc27b1e0bU), BSWAP_32BIG_C(0x12809522U), BSWAP_32BIG_C(0x5cbf6389U), BSWAP_32BIG_C(
                0xa79c785bU),
        };
        r_rsip_func102(Param_pdff_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub009(0x000000dfU);

        static const uint32_t Param_pdff_func101_006[] =
        {
            BSWAP_32BIG_C(0xbe659671U), BSWAP_32BIG_C(0x3ac9fe4bU), BSWAP_32BIG_C(0xb2f62b4fU), BSWAP_32BIG_C(
                0xbe160606U),
        };
        r_rsip_func101(Param_pdff_func101_006);
        r_rsip_func414(OutData_EncCertificateInfo);

        static const uint32_t Param_pdff_func102_003[] =
        {
            BSWAP_32BIG_C(0x2a4e66e0U), BSWAP_32BIG_C(0xd886c627U), BSWAP_32BIG_C(0x3d880ae4U), BSWAP_32BIG_C(
                0x92edb810U),
        };
        r_rsip_func102(Param_pdff_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
