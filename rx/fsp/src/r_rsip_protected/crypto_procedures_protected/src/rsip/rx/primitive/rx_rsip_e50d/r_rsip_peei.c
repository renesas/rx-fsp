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

rsip_ret_t r_rsip_peei (const uint32_t InData_CurveType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ee0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420ab40U, 0x00000002U, 0x2000b740U, 0x00000001U);

    WR1_PROG(REG_1600H, 0x00000b9cU);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    WR1_PROG(REG_1404H, 0x19100000U);
    r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
    WR4_ADDR(REG_1420H, &InData_Signature[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Signature[4]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x19600000U);
    r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
    WR4_ADDR(REG_1420H, &InData_Signature[8]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Signature[12]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1444H, 0x000007c7U);
    WR1_PROG(REG_1608H, 0x8088001eU);
    for (iLoop = 0U; iLoop < 8U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000ee01U);

    static const uint32_t Param_peei_func101_001[] =
    {
        BSWAP_32BIG_C(0x0e46d79fU), BSWAP_32BIG_C(0x6fb4e728U), BSWAP_32BIG_C(0x9f73ba0aU), BSWAP_32BIG_C(0xfc027bd8U),
    };
    r_rsip_func101(Param_peei_func101_001);
    r_rsip_func043();

    r_rsip_func075();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub009(0x0000ee01U);

    static const uint32_t Param_peei_func101_002[] =
    {
        BSWAP_32BIG_C(0x9948468eU), BSWAP_32BIG_C(0xa30693f2U), BSWAP_32BIG_C(0x7882cdb6U), BSWAP_32BIG_C(0x02110014U),
    };
    r_rsip_func101(Param_peei_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80900001U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
    r_rsip_func_sub001(0x03420021U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_peei_func100_001[] =
    {
        BSWAP_32BIG_C(0x34afb817U), BSWAP_32BIG_C(0x64190944U), BSWAP_32BIG_C(0xc596d52bU), BSWAP_32BIG_C(0x3250d4abU),
    };
    r_rsip_func100(Param_peei_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_peei_func102_001[] =
        {
            BSWAP_32BIG_C(0xaabef97eU), BSWAP_32BIG_C(0xf754ce9fU), BSWAP_32BIG_C(0x270febb7U), BSWAP_32BIG_C(
                0x49addbe4U),
        };
        r_rsip_func102(Param_peei_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x8188001eU);
        r_rsip_func_sub001(0x00890021U);

        r_rsip_func_sub023(0x0000b7c0U, 0x00000100U, 0x8088001eU);
        r_rsip_func_sub001(0x03420021U);

        r_rsip_func_sub009(0x000000eeU);

        static const uint32_t Param_peei_func101_003[] =
        {
            BSWAP_32BIG_C(0xac115c9cU), BSWAP_32BIG_C(0x42cfb7edU), BSWAP_32BIG_C(0xa749bc66U), BSWAP_32BIG_C(
                0x18950c03U),
        };
        r_rsip_func101(Param_peei_func101_003);
        r_rsip_func073(InData_DomainParam);

        static const uint32_t Param_peei_func100_002[] =
        {
            BSWAP_32BIG_C(0x6cdec4aaU), BSWAP_32BIG_C(0xd17e5f99U), BSWAP_32BIG_C(0x203c4dd1U), BSWAP_32BIG_C(
                0x20d5518dU),
        };
        r_rsip_func100(Param_peei_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_peei_func102_002[] =
            {
                BSWAP_32BIG_C(0x343626b7U), BSWAP_32BIG_C(0x13586588U), BSWAP_32BIG_C(0x48b2164dU), BSWAP_32BIG_C(
                    0x6fd2432aU),
            };
            r_rsip_func102(Param_peei_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            r_rsip_func_sub023(0x0000b7c0U, 0x00000100U, 0x8188001eU);
            r_rsip_func_sub001(0x00890021U);

            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1608H, 0x8088001eU);
            r_rsip_func_sub001(0x03420021U);

            static const uint32_t Param_peei_func101_004[] =
            {
                BSWAP_32BIG_C(0x00a2c720U), BSWAP_32BIG_C(0x45ffbde0U), BSWAP_32BIG_C(0x7e0f6f52U), BSWAP_32BIG_C(
                    0x529e1732U),
            };
            r_rsip_func101(Param_peei_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
