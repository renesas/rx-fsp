/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_Ecc384ScalarMultiplicationSub (const uint32_t InData_CurveType[],
                                                const uint32_t InData_KeyMode[],
                                                const uint32_t InData_KeyIndex[],
                                                const uint32_t InData_Key[],
                                                const uint32_t InData_PubKey[],
                                                const uint32_t InData_DomainParam[],
                                                uint32_t       OutData_R[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x009b0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyMode[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    HW_SCE_p_func100(0x3f5c719eU, 0xa354c689U, 0x0eea8056U, 0x8a5e8325U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800100e0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000009bU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xa0a2bf53U, 0xddbb579aU, 0xfb41b137U, 0x44db3ddaU);
        HW_SCE_p_func043();

        HW_SCE_p_func076();

        WR1_PROG(REG_1600H, 0x000034feU);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x0000009bU));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xb801ddfeU, 0x8bcaa6e1U, 0x0a455226U, 0x361190e6U);
        HW_SCE_p_func044();

        WR1_PROG(REG_1444H, 0x00000bc2U);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);

        for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x13100000U);
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        WR1_PROG(REG_1400H, 0x00820011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0xf817e13aU, 0x94c78403U, 0xe25d2740U, 0x45804ac1U);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000bc2U);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Key[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x13100000U);
        WR1_PROG(REG_1400H, 0x00c20031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func101(0x68e53a9cU, 0x03361374U, 0x203a651bU, 0x8f4d9e7bU);
    }

    HW_SCE_p_func100(0x20816f36U, 0x13896526U, 0xa054557eU, 0x9c7e93a8U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x3a888b95U, 0x599125d3U, 0xbd49e686U, 0x9073d1beU);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_KEY_SET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000bdeU);

        WR1_PROG(REG_1444H, 0x000017c7U);
        WR1_PROG(REG_1608H, 0x8098001eU);
        for (iLoop = 0U; iLoop < 24U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_PubKey[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func100(0x79dd247dU, 0xc2c6542dU, 0x9aee89a4U, 0x4a22f1e5U);
        HW_SCE_p_func027(InData_DomainParam);

        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_101CH, 0x000000c0U);

        WR1_PROG(REG_1004H, 0x06060010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_101CH, 0x00000070U);

        WR1_PROG(REG_1004H, 0x06060010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x8198001eU);

        WR1_PROG(REG_1404H, 0x10e00000U);
        WR1_PROG(REG_1400H, 0x00c90031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x11300000U);
        WR1_PROG(REG_1400H, 0x00c90031U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x000001b0U);

        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000200U);

        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);

        WR1_PROG(REG_1004H, 0x06060001U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000890U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000160U);

        WR1_PROG(REG_1004H, 0x06060005U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);

        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x000008e0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000160U);

        WR1_PROG(REG_1004H, 0x06060005U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);

        WR1_PROG(REG_1004H, 0x06060001U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000160U);
        WR1_PROG(REG_1020H, 0x00000250U);

        WR1_PROG(REG_1004H, 0x0606000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000110U);
        WR1_PROG(REG_1020H, 0x00000250U);

        WR1_PROG(REG_1004H, 0x0606000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_143CH, 0x00210000U);

        HW_SCE_p_func100(0x40bc63afU, 0x1fcbe54aU, 0x99a050b3U, 0xc862a5f2U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x63c7fe77U, 0x44e29c55U, 0x14ad3824U, 0xce568cb0U);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1400H, 0x00c00031U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1014H, 0x00000200U);
            WR1_PROG(REG_1018H, 0x00000110U);
            WR1_PROG(REG_1020H, 0x00000218U);

            WR1_PROG(REG_1004H, 0x06060009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x000001b0U);
            WR1_PROG(REG_1018H, 0x00000110U);
            WR1_PROG(REG_1020H, 0x000001e0U);

            WR1_PROG(REG_1004H, 0x06060009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800103a0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x0000009bU));
            WR1_PROG(REG_1458H, 0x00000000U);

            HW_SCE_p_func101(0x8b1d3a79U, 0xb2a3ee36U, 0xed5c8596U, 0x1503ad7aU);
            HW_SCE_p_func089();

            HW_SCE_p_func100(0x79039317U, 0x0dbfc0c3U, 0x4ce2f1bbU, 0x28ee5096U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func102(0x41c7aeb6U, 0xd0a088d9U, 0x34047583U, 0x13cae188U);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_ERR_CRYPTO_SCE_FAIL;
            }
            else
            {
                HW_SCE_p_func100(0xca4c866aU, 0x54567673U, 0x85c156dbU, 0xfd401a80U);
                WR1_PROG(REG_1404H, 0x12700000U);
                WR1_PROG(REG_1A2CH, 0x00000200U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                WR1_PROG(REG_1400H, 0x00830031U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_R[0]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_R[4]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_R[8]);

                HW_SCE_p_func100(0xd598a6b7U, 0x9c69a501U, 0x8ef095aeU, 0x56f78103U);
                WR1_PROG(REG_1404H, 0x12c00000U);
                WR1_PROG(REG_1A2CH, 0x00000200U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                WR1_PROG(REG_1400H, 0x00830031U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_R[12]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_R[16]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_R[20]);

                HW_SCE_p_func102(0x984f0f84U, 0xc86804b1U, 0x12ae2993U, 0x962f1751U);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return FSP_SUCCESS;
            }
        }
    }
}
