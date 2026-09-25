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

rsip_ret_t r_rsip_pe7 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataType[],
                       const uint32_t InData_OutDataLocation[],
                       const uint32_t InData_SeqNum[],
                       uint32_t       OutData_HMACKeyIndex[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       OutData_EncIV[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e70001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000002c7U, 0x80030080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KDFInfo_Count[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_OutDataType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3000a880U, 0x00000003U, 0x00010020U, 0x0000b480U);
    r_rsip_func_sub021(0x00000002U, 0x00000080U, 0x30003080U, 0x00070020U);
    r_rsip_func_sub021(0x0000b680U, 0x08000000U, 0x00030040U, 0x0000b680U);
    r_rsip_func_sub021(0x05555555U, 0x00050040U, 0x0000b680U, 0x04000000U);
    r_rsip_func_sub021(0x00000080U, 0x3000a8c0U, 0x00000009U, 0x00010020U);
    r_rsip_func_sub021(0x0000b4c0U, 0x00000008U, 0x00000080U, 0x38000ca5U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);

    r_rsip_func_sub017(0x34202a85U, 0x00260000U);

    r_rsip_func_sub006(0x380088c0U, 0x00000005U, 0x00260000U);

    static const uint32_t Param_pe7_func100_001[] =
    {
        BSWAP_32BIG_C(0xc22b9f61U), BSWAP_32BIG_C(0xc7c31c29U), BSWAP_32BIG_C(0x1dff17bbU), BSWAP_32BIG_C(0xd552da59U),
    };
    r_rsip_func100(Param_pe7_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe7_func102_001[] =
        {
            BSWAP_32BIG_C(0xeff01bafU), BSWAP_32BIG_C(0xbab65ea9U), BSWAP_32BIG_C(0xdf0e7005U), BSWAP_32BIG_C(
                0x7e1aea37U),
        };
        r_rsip_func102(Param_pe7_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pe7_func100_002[] =
        {
            BSWAP_32BIG_C(0x4895530bU), BSWAP_32BIG_C(0x4d55cb6eU), BSWAP_32BIG_C(0xa26af4f6U), BSWAP_32BIG_C(
                0x1e93cf76U),
        };
        r_rsip_func100(Param_pe7_func100_002);
        r_rsip_func_sub014(0x00007c06U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000005U);

            r_rsip_func_sub003(0x800101c0U, 0x0000000fU);

            static const uint32_t Param_pe7_func101_001[] =
            {
                BSWAP_32BIG_C(0xac98fbb8U), BSWAP_32BIG_C(0x780cf82dU), BSWAP_32BIG_C(0x699581e3U), BSWAP_32BIG_C(
                    0xe821eaf8U),
            };
            r_rsip_func101(Param_pe7_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000007U);

            r_rsip_func_sub003(0x800101c0U, 0x0000001fU);

            static const uint32_t Param_pe7_func101_002[] =
            {
                BSWAP_32BIG_C(0x823940f2U), BSWAP_32BIG_C(0x7acfa1afU), BSWAP_32BIG_C(0x9b5ccc3fU), BSWAP_32BIG_C(
                    0x780976eeU),
            };
            r_rsip_func101(Param_pe7_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub003(0x800101c0U, 0x0000000fU);

            static const uint32_t Param_pe7_func101_003[] =
            {
                BSWAP_32BIG_C(0xbcb45a9cU), BSWAP_32BIG_C(0xe48762f3U), BSWAP_32BIG_C(0x940da04cU), BSWAP_32BIG_C(
                    0x3661ab4eU),
            };
            r_rsip_func101(Param_pe7_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub003(0x800101c0U, 0x00000003U);

            static const uint32_t Param_pe7_func101_004[] =
            {
                BSWAP_32BIG_C(0x4ba79a4cU), BSWAP_32BIG_C(0x18d6bbb7U), BSWAP_32BIG_C(0xd0e3191dU), BSWAP_32BIG_C(
                    0x92bd4049U),
            };
            r_rsip_func101(Param_pe7_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub003(0x800101c0U, 0x0000000bU);

            static const uint32_t Param_pe7_func101_005[] =
            {
                BSWAP_32BIG_C(0xc088a613U), BSWAP_32BIG_C(0x451c6aceU), BSWAP_32BIG_C(0x73c5c6bfU), BSWAP_32BIG_C(
                    0xf06f3d74U),
            };
            r_rsip_func101(Param_pe7_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x0000001bU);

            r_rsip_func_sub003(0x800101c0U, 0x0000001fU);

            static const uint32_t Param_pe7_func101_006[] =
            {
                BSWAP_32BIG_C(0x3d811797U), BSWAP_32BIG_C(0x13e71389U), BSWAP_32BIG_C(0xb7fc6500U), BSWAP_32BIG_C(
                    0x4715424aU),
            };
            r_rsip_func101(Param_pe7_func101_006);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000007U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000028U);

            r_rsip_func_sub003(0x800101c0U, 0x0000002fU);

            static const uint32_t Param_pe7_func101_007[] =
            {
                BSWAP_32BIG_C(0x35086c59U), BSWAP_32BIG_C(0x28d223a8U), BSWAP_32BIG_C(0xb6bbec4fU), BSWAP_32BIG_C(
                    0x950cd89cU),
            };
            r_rsip_func101(Param_pe7_func101_007);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000008U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000029U);

            r_rsip_func_sub003(0x800101c0U, 0x0000003fU);

            static const uint32_t Param_pe7_func101_008[] =
            {
                BSWAP_32BIG_C(0xd834fb18U), BSWAP_32BIG_C(0x8b991177U), BSWAP_32BIG_C(0x971b2a94U), BSWAP_32BIG_C(
                    0xee4490b0U),
            };
            r_rsip_func101(Param_pe7_func101_008);
        }

        r_rsip_func_sub010(0x000000c7U, 0x80010100U);
        WR1_PROG(REG_1420H, InData_OutDataLocation[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x30003080U, 0x00070020U, 0x0000b600U, 0x0000001fU);

        r_rsip_func_sub021(0x0000b460U, 0x0000000dU, 0x00003685U, 0x00056e94U);
        r_rsip_func_sub021(0x00003280U, 0x00000080U, 0x30003080U, 0x00030020U);

        r_rsip_func_sub021(0x0000b600U, 0x0000002fU, 0x0000b460U, 0x00000011U);

        r_rsip_func_sub021(0x00003685U, 0x00046e94U, 0x000036a5U, 0x00056eb4U);
        r_rsip_func_sub021(0x00002695U, 0x00003280U, 0x00000080U, 0x30003080U);
        r_rsip_func_sub021(0x00050020U, 0x0000b600U, 0x0000003fU, 0x0000b460U);
        r_rsip_func_sub021(0x00000015U, 0x00003685U, 0x00066e94U, 0x00003280U);

        r_rsip_func_sub021(0x00000080U, 0x00003628U, 0x0000262eU, 0x34202a91U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        r_rsip_func_sub017(0x34202911U, 0x00A60000U);

        static const uint32_t Param_pe7_func100_003[] =
        {
            BSWAP_32BIG_C(0xc8706f41U), BSWAP_32BIG_C(0x20c12cccU), BSWAP_32BIG_C(0xb3e04c8aU), BSWAP_32BIG_C(
                0x38f32d62U),
        };
        r_rsip_func100(Param_pe7_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe7_func102_002[] =
            {
                BSWAP_32BIG_C(0xf65a1d9dU), BSWAP_32BIG_C(0x3049d0ceU), BSWAP_32BIG_C(0xb6bb91b9U), BSWAP_32BIG_C(
                    0xc83d67e1U),
            };
            r_rsip_func102(Param_pe7_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe7_func100_004[] =
            {
                BSWAP_32BIG_C(0xd22e21adU), BSWAP_32BIG_C(0x1fe85878U), BSWAP_32BIG_C(0xb79bc666U), BSWAP_32BIG_C(
                    0xd7f30880U),
            };
            r_rsip_func100(Param_pe7_func100_004);

            r_rsip_func_sub021(0x00000a73U, 0x00000ab5U, 0x000009efU, 0x00000a94U);

            WR1_PROG(REG_1600H, 0x00000ad6U);

            WR1_PROG(REG_1600H, 0x00000af7U);

            r_rsip_func_sub016(0x81010060U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            OFS_ADR  = S_RAM[0];

            static const uint32_t Param_pe7_func100_005[] =
            {
                BSWAP_32BIG_C(0x309da0a3U), BSWAP_32BIG_C(0xe8ea48ffU), BSWAP_32BIG_C(0x44495d3cU), BSWAP_32BIG_C(
                    0x02fbc465U),
            };
            r_rsip_func100(Param_pe7_func100_005);
            r_rsip_func_sub016(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x34202a65U);
                WR1_PROG(REG_1600H, 0x2000d2c0U);
                r_rsip_func_sub014(0x00007c16U, 0x00602000U);

                r_rsip_func_sub017(0x34202a35U, 0x00260000U);

                r_rsip_func_sub021(0x000026b0U, 0x34202aa8U, 0x100026f0U, 0x10002ee0U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);

                static const uint32_t Param_pe7_func100_006[] =
                {
                    BSWAP_32BIG_C(0x00e458fdU), BSWAP_32BIG_C(0x8b8aef4aU), BSWAP_32BIG_C(0xfdc9fe26U), BSWAP_32BIG_C(
                        0xf0918249U),
                };
                r_rsip_func100(Param_pe7_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pe7_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x90995288U), BSWAP_32BIG_C(0x2d59bb63U), BSWAP_32BIG_C(0x0e46b8d1U),
                        BSWAP_32BIG_C(0x497828caU),
                    };
                    r_rsip_func101(Param_pe7_func101_009);
                }
                else
                {
                    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                    WR1_PROG(REG_1420H, InData_KDFInfo[iLoop * OFS_ADR]);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub009(0x0000e701U);

                    static const uint32_t Param_pe7_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x19028fe7U), BSWAP_32BIG_C(0x9f19adfbU), BSWAP_32BIG_C(0x9fa120e9U),
                        BSWAP_32BIG_C(0xbfdc8f9dU),
                    };
                    r_rsip_func101(Param_pe7_func101_010);
                    r_rsip_func043();

                    WR1_PROG(REG_1600H, 0x0000b4e0U);
                    WR1_PROG(REG_1600H, 0x01c80eb2U);

                    r_rsip_func_sub009(0x0000e701U);

                    static const uint32_t Param_pe7_func101_011[] =
                    {
                        BSWAP_32BIG_C(0x8a8a8a58U), BSWAP_32BIG_C(0xa6203eecU), BSWAP_32BIG_C(0xcb54edc5U),
                        BSWAP_32BIG_C(0x8270631eU),
                    };
                    r_rsip_func101(Param_pe7_func101_011);
                    r_rsip_func044();

                    r_rsip_func_sub004(0x08000044U, 0x00000000U);

                    r_rsip_func_sub004(0x08000054U, 0x00000000U);

                    WR1_PROG(REG_1600H, 0x00000842U);

                    for (jLoop = 0U; jLoop < OFS_ADR - 5; jLoop = jLoop + 4U)
                    {
                        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                        WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                        WR1_PROG(REG_1608H, 0x8084000fU);
                        r_rsip_func_sub001(0x03420011U);

                        r_rsip_func_sub021(0x0000a5e0U, 0x00000010U, 0x0000a440U, 0x00000004U);

                        static const uint32_t Param_pe7_func101_012[] =
                        {
                            BSWAP_32BIG_C(0x02b0238bU), BSWAP_32BIG_C(0xcbd5ed3bU), BSWAP_32BIG_C(0x17b19425U),
                            BSWAP_32BIG_C(0x189bb72eU),
                        };
                        r_rsip_func101(Param_pe7_func101_012);
                    }

                    r_rsip_func_sub034(0x000037e3U, 0x0000abe0U);
                    WR1_PROG(REG_1600H, 0x00000005U);

                    r_rsip_func_sub011(0x38000be2U);

                    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                    WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                    WR1_PROG(REG_1A24H, 0x9c100005U);
                    r_rsip_func_sub001(0x00820011U);

                    static const uint32_t Param_pe7_func100_007[] =
                    {
                        BSWAP_32BIG_C(0xa8b94ddeU), BSWAP_32BIG_C(0x54c11395U), BSWAP_32BIG_C(0xf80dd61fU),
                        BSWAP_32BIG_C(0x7bfbf744U),
                    };
                    r_rsip_func100(Param_pe7_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1600H, 0x0000d280U);
                        static const uint32_t Param_pe7_func101_013[] =
                        {
                            BSWAP_32BIG_C(0x0f9688c7U), BSWAP_32BIG_C(0x010a8a56U), BSWAP_32BIG_C(0x64a40306U),
                            BSWAP_32BIG_C(0xdfd86203U),
                        };
                        r_rsip_func101(Param_pe7_func101_013);
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func101_014[] =
                        {
                            BSWAP_32BIG_C(0xaf624872U), BSWAP_32BIG_C(0xd939e351U), BSWAP_32BIG_C(0x6b782f6fU),
                            BSWAP_32BIG_C(0xe3635a6fU),
                        };
                        r_rsip_func101(Param_pe7_func101_014);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1600H, 0x00002ea0U);

                WR1_PROG(REG_1600H, 0x00002e60U);

                static const uint32_t Param_pe7_func101_015[] =
                {
                    BSWAP_32BIG_C(0xca42a95fU), BSWAP_32BIG_C(0xb26792f1U), BSWAP_32BIG_C(0xb9d30722U), BSWAP_32BIG_C(
                        0x81a91e64U),
                };
                r_rsip_func101(Param_pe7_func101_015);
            }

            r_rsip_func_sub011(0x38000a65U);

            r_rsip_func_sub017(0x38000e94U, 0x00A60000U);
            static const uint32_t Param_pe7_func100_008[] =
            {
                BSWAP_32BIG_C(0x1ddfd64bU), BSWAP_32BIG_C(0x1b91ddc7U), BSWAP_32BIG_C(0xf59be044U), BSWAP_32BIG_C(
                    0xa5f5c2bfU),
            };
            r_rsip_func100(Param_pe7_func100_008);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe7_func102_003[] =
                {
                    BSWAP_32BIG_C(0x35c6fc30U), BSWAP_32BIG_C(0x5450bb8eU), BSWAP_32BIG_C(0x1268e70dU), BSWAP_32BIG_C(
                        0x59c4e834U),
                };
                r_rsip_func102(Param_pe7_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub009(0x000000e7U);

                static const uint32_t Param_pe7_func101_016[] =
                {
                    BSWAP_32BIG_C(0x61558382U), BSWAP_32BIG_C(0x9473b74fU), BSWAP_32BIG_C(0x50269524U), BSWAP_32BIG_C(
                        0xc9ec2ab3U),
                };
                r_rsip_func101(Param_pe7_func101_016);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x0000e702U);

                static const uint32_t Param_pe7_func101_017[] =
                {
                    BSWAP_32BIG_C(0x759b94efU), BSWAP_32BIG_C(0xe2a4effeU), BSWAP_32BIG_C(0xcd4b7c0dU), BSWAP_32BIG_C(
                        0x96ca329aU),
                };
                r_rsip_func101(Param_pe7_func101_017);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034e9U);

                r_rsip_func_sub009(0x0000e702U);

                static const uint32_t Param_pe7_func101_018[] =
                {
                    BSWAP_32BIG_C(0x00371db9U), BSWAP_32BIG_C(0xaa44ef23U), BSWAP_32BIG_C(0x306e7c65U), BSWAP_32BIG_C(
                        0x5899f3d6U),
                };
                r_rsip_func101(Param_pe7_func101_018);
                r_rsip_func044();

                r_rsip_func_sub021(0x00002917U, 0x0000b5e0U, 0x00000080U, 0x3420a8c0U);
                r_rsip_func_sub017(0x00000002U, 0x00260000U);

                static const uint32_t Param_pe7_func100_009[] =
                {
                    BSWAP_32BIG_C(0x5f05b773U), BSWAP_32BIG_C(0x28feca91U), BSWAP_32BIG_C(0x8ee8d45dU), BSWAP_32BIG_C(
                        0x637bf30fU),
                };
                r_rsip_func100(Param_pe7_func100_009);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    for (iLoop = 0U; iLoop < 32U; iLoop++)
                    {
                        r_rsip_func_sub021(0x00000ab5U, 0x02003aa8U, 0x02003eafU, 0x00002d00U);
                        WR1_PROG(REG_1600H, 0x00002de0U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    WR1_PROG(REG_1600H, 0x0000b5e0U);
                    r_rsip_func_sub006(0x00000080U, 0x38000cc6U, 0x00260000U);

                    static const uint32_t Param_pe7_func100_010[] =
                    {
                        BSWAP_32BIG_C(0xb6c7e9abU), BSWAP_32BIG_C(0x6dd3b9d6U), BSWAP_32BIG_C(0x5da04fe7U),
                        BSWAP_32BIG_C(0x3e8254e4U),
                    };
                    r_rsip_func100(Param_pe7_func100_010);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_pe7_func100_011[] =
                        {
                            BSWAP_32BIG_C(0x3f3c6d4aU), BSWAP_32BIG_C(0x77256ea2U), BSWAP_32BIG_C(0xec96137bU),
                            BSWAP_32BIG_C(0xbfcbdb5cU),
                        };
                        r_rsip_func100(Param_pe7_func100_011);
                        r_rsip_func_sub027(0x40000000U, 0xe7009d05U, 0x8184000fU);
                        r_rsip_func_sub001(0x00890011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);

                        static const uint32_t Param_pe7_func100_012[] =
                        {
                            BSWAP_32BIG_C(0x1776f93eU), BSWAP_32BIG_C(0xc5f7f6ccU), BSWAP_32BIG_C(0x88afdcc7U),
                            BSWAP_32BIG_C(0x7230056eU),
                        };
                        r_rsip_func100(Param_pe7_func100_012);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func101_019[] =
                        {
                            BSWAP_32BIG_C(0x9b51a7b3U), BSWAP_32BIG_C(0x387f3e7eU), BSWAP_32BIG_C(0xd9eae59bU),
                            BSWAP_32BIG_C(0x210a9174U),
                        };
                        r_rsip_func101(Param_pe7_func101_019);
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func100_013[] =
                        {
                            BSWAP_32BIG_C(0x7756313dU), BSWAP_32BIG_C(0x01bb972aU), BSWAP_32BIG_C(0x7e4202afU),
                            BSWAP_32BIG_C(0x49eac8b9U),
                        };
                        r_rsip_func100(Param_pe7_func100_013);
                        r_rsip_func_sub027(0x40000100U, 0xe7009d07U, 0x8188000fU);
                        r_rsip_func_sub001(0x00890021U);
                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func100_014[] =
                        {
                            BSWAP_32BIG_C(0x9320f7d2U), BSWAP_32BIG_C(0xb5a801a4U), BSWAP_32BIG_C(0x8cba72f3U),
                            BSWAP_32BIG_C(0x6cbb9751U),
                        };
                        r_rsip_func100(Param_pe7_func100_014);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

                        static const uint32_t Param_pe7_func101_020[] =
                        {
                            BSWAP_32BIG_C(0x4c9ec5ceU), BSWAP_32BIG_C(0xd76fc85cU), BSWAP_32BIG_C(0xa30843baU),
                            BSWAP_32BIG_C(0xeeff8047U),
                        };
                        r_rsip_func101(Param_pe7_func101_020);
                    }

                    static const uint32_t Param_pe7_func100_015[] =
                    {
                        BSWAP_32BIG_C(0x3eca032cU), BSWAP_32BIG_C(0x3a26e164U), BSWAP_32BIG_C(0xcb63e2bdU),
                        BSWAP_32BIG_C(0x59a060f3U),
                    };
                    r_rsip_func100(Param_pe7_func100_015);
                    r_rsip_func_sub016(0x81010000U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                    static const uint32_t Param_pe7_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x178209eaU), BSWAP_32BIG_C(0x0e11926bU), BSWAP_32BIG_C(0x45aea8f5U),
                        BSWAP_32BIG_C(0x9ddd2127U),
                    };
                    r_rsip_func102(Param_pe7_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
                else
                {
                    r_rsip_func_sub006(0x3420a8c0U, 0x00000005U, 0x00A60000U);

                    static const uint32_t Param_pe7_func100_016[] =
                    {
                        BSWAP_32BIG_C(0xdb372e3eU), BSWAP_32BIG_C(0xd2ad621cU), BSWAP_32BIG_C(0x8dd052fdU),
                        BSWAP_32BIG_C(0x44e32952U),
                    };
                    r_rsip_func100(Param_pe7_func100_016);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        for (iLoop = 0U; iLoop < 64U; iLoop++)
                        {
                            r_rsip_func_sub021(0x00000ab5U, 0x02003aa8U, 0x02003eafU, 0x00002d00U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                        }

                        r_rsip_func_sub034(0x0000b5e0U, 0x00000080U);

                        WR1_PROG(REG_1600H, 0x000008e7U);

                        static const uint32_t Param_pe7_func100_017[] =
                        {
                            BSWAP_32BIG_C(0x87016884U), BSWAP_32BIG_C(0xae9e0ba7U), BSWAP_32BIG_C(0xf9c7aae0U),
                            BSWAP_32BIG_C(0xc4a5e7d6U),
                        };
                        r_rsip_func100(Param_pe7_func100_017);
                        r_rsip_func_sub004(0x08000044U, 0x00000000U);

                        r_rsip_func_sub004(0x08000054U, 0x00000000U);

                        WR1_PROG(REG_1600H, 0x00002dc0U);
                        WR1_PROG(REG_1600H, 0x000269ceU);

                        r_rsip_func_sub016(0x810101c0U, 0x00005006U);
                        RD1_ADDR(REG_1420H, &S_RAM[0]);
                        S_RAM[0] = bswap_32big(S_RAM[0]);

                        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
                        {
                            static const uint32_t Param_pe7_func100_018[] =
                            {
                                BSWAP_32BIG_C(0xe3264bbbU), BSWAP_32BIG_C(0x8106d653U), BSWAP_32BIG_C(0xc2bcc934U),
                                BSWAP_32BIG_C(0x87a48a94U),
                            };
                            r_rsip_func100(Param_pe7_func100_018);
                            r_rsip_func_sub027(0x40000000U, 0xe7008d05U, 0x8184000fU);
                            r_rsip_func_sub001(0x00890011U);

                            WR1_PROG(REG_1408H, 0x00002012U);
                            WAIT_STS(REG_1408H, 30, 1);
                            RD4_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 1]);

                            r_rsip_func_sub021(0x0000a5e0U, 0x00000010U, 0x0000a4e0U, 0x00000004U);

                            static const uint32_t Param_pe7_func101_021[] =
                            {
                                BSWAP_32BIG_C(0x6515b1b2U), BSWAP_32BIG_C(0x6c769bd6U), BSWAP_32BIG_C(0xa7c477ddU),
                                BSWAP_32BIG_C(0x8ceae460U),
                            };
                            r_rsip_func101(Param_pe7_func101_021);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);

                        r_rsip_func_sub011(0x380009c7U);

                        static const uint32_t Param_pe7_func100_019[] =
                        {
                            BSWAP_32BIG_C(0x12d5bc13U), BSWAP_32BIG_C(0x1a31f8b4U), BSWAP_32BIG_C(0xa9036b68U),
                            BSWAP_32BIG_C(0x1268d8e7U),
                        };
                        r_rsip_func100(Param_pe7_func100_019);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 1]);

                        static const uint32_t Param_pe7_func100_020[] =
                        {
                            BSWAP_32BIG_C(0x15151724U), BSWAP_32BIG_C(0xa58344c7U), BSWAP_32BIG_C(0x4e46a6d4U),
                            BSWAP_32BIG_C(0x9e48ee4cU),
                        };
                        r_rsip_func100(Param_pe7_func100_020);
                        r_rsip_func_sub016(0x81010000U, 0x00005006U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[0]);

                        static const uint32_t Param_pe7_func102_005[] =
                        {
                            BSWAP_32BIG_C(0x5a597364U), BSWAP_32BIG_C(0x246f321eU), BSWAP_32BIG_C(0x4938197eU),
                            BSWAP_32BIG_C(0xb3e955cbU),
                        };
                        r_rsip_func102(Param_pe7_func102_005);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_PASS;
                    }
                    else
                    {
                        for (iLoop = 0U; iLoop < 16U; iLoop++)
                        {
                            r_rsip_func_sub021(0x00000ab5U, 0x02003aa8U, 0x02003eafU, 0x00002d00U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);

                        r_rsip_func_sub021(0x0000b5e0U, 0x00000080U, 0x380088c0U, 0x00000002U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);

                        static const uint32_t Param_pe7_func100_021[] =
                        {
                            BSWAP_32BIG_C(0xfb067e20U), BSWAP_32BIG_C(0xc3f075baU), BSWAP_32BIG_C(0x6a681b16U),
                            BSWAP_32BIG_C(0xc1fb605bU),
                        };
                        r_rsip_func100(Param_pe7_func100_021);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            WR1_PROG(REG_1A24H, 0x08000105U);
                            WR1_PROG(REG_1608H, 0x8184000fU);
                            r_rsip_func_sub001(0x00890011U);
                            WR1_PROG(REG_1608H, 0x80040140U);
                            r_rsip_func_sub001(0x03420011U);

                            static const uint32_t Param_pe7_func101_022[] =
                            {
                                BSWAP_32BIG_C(0x4afedcc8U), BSWAP_32BIG_C(0x67013656U), BSWAP_32BIG_C(0xffd7c078U),
                                BSWAP_32BIG_C(0xa23a13ddU),
                            };
                            r_rsip_func101(Param_pe7_func101_022);
                        }
                        else
                        {
                            r_rsip_func_sub010(0x000001c7U, 0x80020080U);
                            WR1_PROG(REG_1420H, InData_SeqNum[0]);
                            WAIT_STS(REG_1444H, 31, 1);
                            WR1_PROG(REG_1420H, InData_SeqNum[1]);
                            WR1_PROG(REG_1458H, 0x00000000U);

                            r_rsip_func_sub006(0x380088c0U, 0x00000003U, 0x00260000U);

                            static const uint32_t Param_pe7_func100_022[] =
                            {
                                BSWAP_32BIG_C(0x191aee2eU), BSWAP_32BIG_C(0x3ff86732U), BSWAP_32BIG_C(0x34536f03U),
                                BSWAP_32BIG_C(0xb98c82c2U),
                            };
                            r_rsip_func100(Param_pe7_func100_022);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub021(0x0000394fU, 0x00003564U, 0x00003585U, 0x0000b5a0U);
                                WR1_PROG(REG_1600H, 0x00000001U);

                                static const uint32_t Param_pe7_func101_023[] =
                                {
                                    BSWAP_32BIG_C(0x00a4864cU), BSWAP_32BIG_C(0x99b30195U), BSWAP_32BIG_C(0x331e6b85U),
                                    BSWAP_32BIG_C(0x28594e40U),
                                };
                                r_rsip_func101(Param_pe7_func101_023);
                            }
                            else
                            {
                                WR1_PROG(REG_1A24H, 0x08000105U);
                                WR1_PROG(REG_1608H, 0x8183000fU);
                                r_rsip_func_sub001(0x0089000dU);
                                r_rsip_func_sub001(0x00800005U);
                                WR1_PROG(REG_1608H, 0x80040140U);
                                r_rsip_func_sub001(0x03420011U);

                                r_rsip_func_sub021(0x00000964U, 0x00000985U, 0x0000b5a0U, 0x00000001U);

                                static const uint32_t Param_pe7_func101_024[] =
                                {
                                    BSWAP_32BIG_C(0x1e8dfa30U), BSWAP_32BIG_C(0x53ad70b0U), BSWAP_32BIG_C(0x53520947U),
                                    BSWAP_32BIG_C(0x3dbebaacU),
                                };
                                r_rsip_func101(Param_pe7_func101_024);
                            }
                        }

                        static const uint32_t Param_pe7_func100_023[] =
                        {
                            BSWAP_32BIG_C(0xca3b4809U), BSWAP_32BIG_C(0x955e1acbU), BSWAP_32BIG_C(0x90d37aeeU),
                            BSWAP_32BIG_C(0xa84e0e53U),
                        };
                        r_rsip_func100(Param_pe7_func100_023);
                        r_rsip_func_sub027(0x40000000U, 0xe7009d05U, 0x81040140U);
                        r_rsip_func_sub001(0x00890011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_EncIV[1]);

                        static const uint32_t Param_pe7_func100_024[] =
                        {
                            BSWAP_32BIG_C(0x032b693cU), BSWAP_32BIG_C(0xd0e44828U), BSWAP_32BIG_C(0x11ebc0dfU),
                            BSWAP_32BIG_C(0x188f181eU),
                        };
                        r_rsip_func100(Param_pe7_func100_024);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_EncIV[5]);

                        static const uint32_t Param_pe7_func100_025[] =
                        {
                            BSWAP_32BIG_C(0x7effccffU), BSWAP_32BIG_C(0x6c846b66U), BSWAP_32BIG_C(0x843cfdf3U),
                            BSWAP_32BIG_C(0xca6d03f7U),
                        };
                        r_rsip_func100(Param_pe7_func100_025);
                        r_rsip_func_sub016(0x81010000U, 0x00005006U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[0]);

                        static const uint32_t Param_pe7_func102_006[] =
                        {
                            BSWAP_32BIG_C(0xd592bcd6U), BSWAP_32BIG_C(0x0ae0971aU), BSWAP_32BIG_C(0x783fc332U),
                            BSWAP_32BIG_C(0x6f0ab3aeU),
                        };
                        r_rsip_func102(Param_pe7_func102_006);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
