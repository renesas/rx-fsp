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

rsip_ret_t r_rsip_p90 (const uint32_t InData_KeyType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_Text[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       WRAPPED_KEY_SIZE,
                       uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;
    int32_t  jLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00900001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000002c7U, 0x80030100U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_WrappedKeyType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x00000bffU, 0x00003409U, 0x3420a900U, 0x00000002U);
    r_rsip_func_sub021(0x1000d3e0U, 0x38008940U, 0x00000000U, 0x00030020U);
    r_rsip_func_sub021(0x3420a800U, 0x00000003U, 0x1000d3e1U, 0x00000080U);

    r_rsip_func_sub006(0x38008be0U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_p90_func100_001[] =
    {
        BSWAP_32BIG_C(0x17fa4878U), BSWAP_32BIG_C(0xda76ee47U), BSWAP_32BIG_C(0x14caa3d3U), BSWAP_32BIG_C(0x92688934U),
    };
    r_rsip_func100(Param_p90_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p90_func102_001[] =
        {
            BSWAP_32BIG_C(0x00e4f6b8U), BSWAP_32BIG_C(0x36d07e08U), BSWAP_32BIG_C(0x86894685U), BSWAP_32BIG_C(
                0xcd7da9d8U),
        };
        r_rsip_func102(Param_p90_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub009(0x00009001U);

        static const uint32_t Param_p90_func101_001[] =
        {
            BSWAP_32BIG_C(0x8f1b8556U), BSWAP_32BIG_C(0x4ae15c18U), BSWAP_32BIG_C(0x932ea702U), BSWAP_32BIG_C(
                0x245d3a8aU),
        };
        r_rsip_func101(Param_p90_func101_001);
        r_rsip_func043();

        r_rsip_func_sub017(0x38000d08U, 0x00260000U);

        static const uint32_t Param_p90_func100_002[] =
        {
            BSWAP_32BIG_C(0xc885520fU), BSWAP_32BIG_C(0xec02e12bU), BSWAP_32BIG_C(0xa5ba454fU), BSWAP_32BIG_C(
                0x5bfef8e7U),
        };
        r_rsip_func100(Param_p90_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000005U);

            r_rsip_func_sub009(0x00009001U);

            static const uint32_t Param_p90_func101_002[] =
            {
                BSWAP_32BIG_C(0x342b4befU), BSWAP_32BIG_C(0xffe1cfa6U), BSWAP_32BIG_C(0x7a1a30ecU), BSWAP_32BIG_C(
                    0xa90dcb72U),
            };
            r_rsip_func101(Param_p90_func101_002);
            r_rsip_func044();

            static const uint32_t Param_p90_func100_003[] =
            {
                BSWAP_32BIG_C(0x8a66cd91U), BSWAP_32BIG_C(0x7712babeU), BSWAP_32BIG_C(0x37862d55U), BSWAP_32BIG_C(
                    0xace04321U),
            };
            r_rsip_func100(Param_p90_func100_003);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_182CH, 0x00000000U);

            static const uint32_t Param_p90_func101_003[] =
            {
                BSWAP_32BIG_C(0xc4d77826U), BSWAP_32BIG_C(0xb7b234f0U), BSWAP_32BIG_C(0x8ac02708U), BSWAP_32BIG_C(
                    0x38903015U),
            };
            r_rsip_func101(Param_p90_func101_003);
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000007U);

            r_rsip_func_sub009(0x00009002U);

            static const uint32_t Param_p90_func101_004[] =
            {
                BSWAP_32BIG_C(0x78304f9bU), BSWAP_32BIG_C(0x942f9a02U), BSWAP_32BIG_C(0xf5df980bU), BSWAP_32BIG_C(
                    0xec74d27fU),
            };
            r_rsip_func101(Param_p90_func101_004);
            r_rsip_func044();

            static const uint32_t Param_p90_func100_004[] =
            {
                BSWAP_32BIG_C(0xf159664aU), BSWAP_32BIG_C(0xfd9769cdU), BSWAP_32BIG_C(0x12ea59f8U), BSWAP_32BIG_C(
                    0x4df0365cU),
            };
            r_rsip_func100(Param_p90_func100_004);
            r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            static const uint32_t Param_p90_func100_005[] =
            {
                BSWAP_32BIG_C(0x824277a6U), BSWAP_32BIG_C(0x3c35bb2aU), BSWAP_32BIG_C(0xa1a23e13U), BSWAP_32BIG_C(
                    0x1d110616U),
            };
            r_rsip_func100(Param_p90_func100_005);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

            WR1_PROG(REG_182CH, 0x40000000U);

            static const uint32_t Param_p90_func101_005[] =
            {
                BSWAP_32BIG_C(0x8fd3daf8U), BSWAP_32BIG_C(0xea957668U), BSWAP_32BIG_C(0xc8a347d9U), BSWAP_32BIG_C(
                    0x386d031aU),
            };
            r_rsip_func101(Param_p90_func101_005);
        }

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p90_func100_006[] =
        {
            BSWAP_32BIG_C(0xbd7ace4dU), BSWAP_32BIG_C(0x45be8660U), BSWAP_32BIG_C(0xea19c063U), BSWAP_32BIG_C(
                0xbb9dbcfcU),
        };
        r_rsip_func100(Param_p90_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p90_func102_002[] =
            {
                BSWAP_32BIG_C(0x94cbe1d6U), BSWAP_32BIG_C(0x0ae4c3a2U), BSWAP_32BIG_C(0x3233162bU), BSWAP_32BIG_C(
                    0x86749ad4U),
            };
            r_rsip_func102(Param_p90_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            WR1_PROG(REG_1600H, 0x00002ca0U);

            WR1_PROG(REG_1600H, 0x000035c7U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_Text[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_Text[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub021(0x0000b7e0U, 0x00000008U, 0x00000bdeU, 0x00002fc0U);

            WR1_PROG(REG_1600H, 0x0000b780U);
            WR1_PROG(REG_1600H, 0x00000008U);

            for (iLoop = 2; iLoop < WRAPPED_KEY_SIZE; iLoop = iLoop + 2)
            {
                r_rsip_func_sub010(0x000001c7U, 0x8082001fU);
                WR1_PROG(REG_1420H, InData_Text[iLoop]);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Text[iLoop + 1]);
                r_rsip_func_sub034(0x000027fcU, 0x00002fc0U);

                static const uint32_t Param_p90_func101_006[] =
                {
                    BSWAP_32BIG_C(0x584e5076U), BSWAP_32BIG_C(0x82a797b1U), BSWAP_32BIG_C(0x0d917dc5U), BSWAP_32BIG_C(
                        0x1137e7deU),
                };
                r_rsip_func101(Param_p90_func101_006);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000bc5U);

            r_rsip_func_sub021(0x0000377fU, 0x0000ab60U, 0x00000008U, 0x00003785U);
            r_rsip_func_sub021(0x00003380U, 0x0000349cU, 0x00026c84U, 0x00016f9cU);
            r_rsip_func_sub021(0x0000249cU, 0x00000bdeU, 0x0000b720U, 0x00000004U);

            r_rsip_func_sub021(0x0000b740U, 0x0000000cU, 0x00003785U, 0x00003380U);

            for (jLoop = 5; jLoop >= 0; jLoop = jLoop - 1)
            {
                WR1_PROG(REG_1600H, 0x000037fbU);

                WR1_PROG(REG_1600H, 0x00000bbdU);

                for (iLoop = (WRAPPED_KEY_SIZE / 2) - 1; iLoop >= 1; iLoop = iLoop - 1)
                {
                    WR1_PROG(REG_1600H, 0x00000824U);

                    WR1_PROG(REG_1824H, 0x0a00810dU);
                    WR1_PROG(REG_1608H, 0x81020000U);
                    r_rsip_func_sub001(0x00490009U);
                    WR1_PROG(REG_1608H, 0x8182001fU);
                    r_rsip_func_sub001(0x00490009U);

                    WR1_PROG(REG_1608H, 0x80040000U);
                    r_rsip_func_sub001(0x03410011U);

                    r_rsip_func_sub021(0x00003c5fU, 0x000027f9U, 0x00003c7fU, 0x00002bfaU);

                    WR1_PROG(REG_1600H, 0x00003080U);

                    WR1_PROG(REG_1600H, 0x00002fa0U);

                    static const uint32_t Param_p90_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x2691d8f8U), BSWAP_32BIG_C(0xecdcc551U), BSWAP_32BIG_C(0xf411345fU),
                        BSWAP_32BIG_C(0x1482f993U),
                    };
                    r_rsip_func101(Param_p90_func101_007);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x38000bbcU);

                WR1_PROG(REG_1600H, 0x00002fc0U);

                static const uint32_t Param_p90_func101_008[] =
                {
                    BSWAP_32BIG_C(0xe6457dc8U), BSWAP_32BIG_C(0xfe6987a7U), BSWAP_32BIG_C(0x420f0cd0U), BSWAP_32BIG_C(
                        0x4f9078d9U),
                };
                r_rsip_func101(Param_p90_func101_008);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38008bc0U);
            r_rsip_func_sub011(0x00000006U);

            r_rsip_func_sub006(0x38008800U, 0xa6a6a6a6U, 0x00A60000U);

            r_rsip_func_sub006(0x38008820U, 0xa6a6a6a6U, 0x00A60000U);

            static const uint32_t Param_p90_func100_007[] =
            {
                BSWAP_32BIG_C(0x2b9d0aecU), BSWAP_32BIG_C(0x78bae800U), BSWAP_32BIG_C(0x967e4fbaU), BSWAP_32BIG_C(
                    0xd21592e3U),
            };
            r_rsip_func100(Param_p90_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p90_func102_003[] =
                {
                    BSWAP_32BIG_C(0x64739980U), BSWAP_32BIG_C(0x3c911084U), BSWAP_32BIG_C(0xa5ac3ba5U), BSWAP_32BIG_C(
                        0x44cc7b6eU),
                };
                r_rsip_func102(Param_p90_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub009(0x00000090U);

                static const uint32_t Param_p90_func101_009[] =
                {
                    BSWAP_32BIG_C(0x3a37912bU), BSWAP_32BIG_C(0x5d2532ccU), BSWAP_32BIG_C(0x9cd2c455U), BSWAP_32BIG_C(
                        0x71e1d47dU),
                };
                r_rsip_func101(Param_p90_func101_009);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x00009002U);

                static const uint32_t Param_p90_func101_010[] =
                {
                    BSWAP_32BIG_C(0x157b2c88U), BSWAP_32BIG_C(0x6acbe7e2U), BSWAP_32BIG_C(0x111a0846U), BSWAP_32BIG_C(
                        0x6b83c29fU),
                };
                r_rsip_func101(Param_p90_func101_010);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034e6U);

                r_rsip_func_sub009(0x00009003U);

                static const uint32_t Param_p90_func101_011[] =
                {
                    BSWAP_32BIG_C(0x19d77d87U), BSWAP_32BIG_C(0xd26c8003U), BSWAP_32BIG_C(0x4c7e4da3U), BSWAP_32BIG_C(
                        0xf2656c83U),
                };
                r_rsip_func101(Param_p90_func101_011);
                r_rsip_func044();

                r_rsip_func_sub022(0x000034eeU, 0x0000b7e0U, 0x00000008U);

                r_rsip_func_sub004(0x08000044U, 0x00000000U);

                r_rsip_func_sub004(0x08000054U, 0x00000000U);

                r_rsip_func_sub021(0x00000bdeU, 0x0000b760U, 0x00000004U, 0x0000b780U);
                r_rsip_func_sub022(0x00000010U, 0x0000a8e0U, 0x00000005U);

                for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; iLoop = iLoop + 4U)
                {
                    r_rsip_func_sub021(0x000008c6U, 0x34202bc7U, 0x2000d0c0U, 0x00007c06U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    static const uint32_t Param_p90_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x78aa49baU), BSWAP_32BIG_C(0xcd27daccU), BSWAP_32BIG_C(0xfdb2a6eeU),
                        BSWAP_32BIG_C(0x0abae93aU),
                    };
                    r_rsip_func100(Param_p90_func100_008);
                    r_rsip_func_sub024(0x000003c2U, 0x40000000U, 0xe7008d05U);

                    WR1_PROG(REG_1608H, 0x8184001fU);
                    r_rsip_func_sub001(0x00890011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);

                    WR1_PROG(REG_1600H, 0x000027fcU);

                    WR1_PROG(REG_1600H, 0x000027dbU);

                    static const uint32_t Param_p90_func101_012[] =
                    {
                        BSWAP_32BIG_C(0xc0420dc0U), BSWAP_32BIG_C(0xf27d9f9aU), BSWAP_32BIG_C(0x6ed68f34U),
                        BSWAP_32BIG_C(0x47c0a33aU),
                    };
                    r_rsip_func101(Param_p90_func101_012);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000bc7U);

                static const uint32_t Param_p90_func100_009[] =
                {
                    BSWAP_32BIG_C(0x9be3efb6U), BSWAP_32BIG_C(0x5ebf5febU), BSWAP_32BIG_C(0x813a1f17U), BSWAP_32BIG_C(
                        0xe68b4d3fU),
                };
                r_rsip_func100(Param_p90_func100_009);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);

                static const uint32_t Param_p90_func100_010[] =
                {
                    BSWAP_32BIG_C(0x45067815U), BSWAP_32BIG_C(0xe8fe06beU), BSWAP_32BIG_C(0xd8b291e3U), BSWAP_32BIG_C(
                        0xe72a58c8U),
                };
                r_rsip_func100(Param_p90_func100_010);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                static const uint32_t Param_p90_func102_004[] =
                {
                    BSWAP_32BIG_C(0x2416535fU), BSWAP_32BIG_C(0x516ede37U), BSWAP_32BIG_C(0x7534dbd7U), BSWAP_32BIG_C(
                        0x4c364583U),
                };
                r_rsip_func102(Param_p90_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
