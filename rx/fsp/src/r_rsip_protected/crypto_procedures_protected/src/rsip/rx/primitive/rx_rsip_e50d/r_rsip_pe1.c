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

rsip_ret_t r_rsip_pe1 (const uint32_t InData_Sel_KeyType[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_Certificate[],
                       const uint32_t InData_CertificateLength[],
                       const uint32_t InData_CertificatePubKey[],
                       const uint32_t InData_EncCertificateInfo[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;
    uint32_t iTemp = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e10001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800101e0U);
    WR1_PROG(REG_1420H, InData_Sel_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a9e0U, 0x00000009U, 0x2000b5e0U, 0x00000008U);

    r_rsip_func_sub021(0x3000a9e0U, 0x00000006U, 0x00070020U, 0x3000a9e0U);
    r_rsip_func_sub021(0x00000004U, 0x00070020U, 0x0000b5c0U, 0x01df34faU);

    r_rsip_func_sub021(0x0000b600U, 0x00000008U, 0x00030040U, 0x0000b5c0U);
    r_rsip_func_sub021(0x01d972d8U, 0x0000b600U, 0x0000000cU, 0x00050040U);
    r_rsip_func_sub021(0x0000b5c0U, 0x019c1ff8U, 0x0000b600U, 0x00000010U);
    r_rsip_func_sub021(0x00000080U, 0x00000060U, 0x3000a9e0U, 0x00000007U);
    r_rsip_func_sub021(0x00070020U, 0x0000b5c0U, 0x01df34faU, 0x0000b600U);
    r_rsip_func_sub021(0x00000008U, 0x00030040U, 0x0000b5c0U, 0x01d972d8U);

    r_rsip_func_sub021(0x0000b600U, 0x0000000cU, 0x00050040U, 0x0000b5c0U);
    r_rsip_func_sub021(0x019c1ff8U, 0x0000b600U, 0x00000010U, 0x00000080U);
    WR1_PROG(REG_1600H, 0x00000080U);

    static const uint32_t Param_pe1_func100_001[] =
    {
        BSWAP_32BIG_C(0x21e4572cU), BSWAP_32BIG_C(0x3e79f8ccU), BSWAP_32BIG_C(0xdec3be41U), BSWAP_32BIG_C(0x0e0636d5U),
    };
    r_rsip_func100(Param_pe1_func100_001);
    r_rsip_func_sub016(0x81010200U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_EncCertificateInfo[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000e101U);

    static const uint32_t Param_pe1_func101_001[] =
    {
        BSWAP_32BIG_C(0x29bbfe1fU), BSWAP_32BIG_C(0xe672e94cU), BSWAP_32BIG_C(0x581cdcecU), BSWAP_32BIG_C(0x1eeb60d2U),
    };
    r_rsip_func101(Param_pe1_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034eeU);

    r_rsip_func_sub009(0x0000e101U);

    static const uint32_t Param_pe1_func101_002[] =
    {
        BSWAP_32BIG_C(0xb462e9ffU), BSWAP_32BIG_C(0xd616526aU), BSWAP_32BIG_C(0xbc5b2d9eU), BSWAP_32BIG_C(0x2bedbfd6U),
    };
    r_rsip_func101(Param_pe1_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008a5U);

    WR1_PROG(REG_1600H, 0x00000800U);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &InData_EncCertificateInfo[1 + iLoop]);

        WR1_PROG(REG_1608H, 0x80840000U);
        r_rsip_func_sub001(0x03420011U);

        r_rsip_func_sub021(0x0000a400U, 0x00000010U, 0x0000a4a0U, 0x00000004U);

        static const uint32_t Param_pe1_func101_003[] =
        {
            BSWAP_32BIG_C(0x646206c1U), BSWAP_32BIG_C(0xb3a9614fU), BSWAP_32BIG_C(0xaa7d1572U), BSWAP_32BIG_C(
                0xc757f6b6U),
        };
        r_rsip_func101(Param_pe1_func101_003);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000a05U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_EncCertificateInfo[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe1_func100_002[] =
    {
        BSWAP_32BIG_C(0x4758b7a3U), BSWAP_32BIG_C(0xcfe52dafU), BSWAP_32BIG_C(0xdf2fe2f9U), BSWAP_32BIG_C(0x42c562ccU),
    };
    r_rsip_func100(Param_pe1_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe1_func102_001[] =
        {
            BSWAP_32BIG_C(0xb1e66125U), BSWAP_32BIG_C(0xfbd0a7e2U), BSWAP_32BIG_C(0xaf1700daU), BSWAP_32BIG_C(
                0x78e31600U),
        };
        r_rsip_func102(Param_pe1_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800102c0U);
        WR1_PROG(REG_1420H, InData_CertificateLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub010(0x000003c7U, 0x800402e0U);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[2]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[3]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_2000H, 0x00000001U);

        r_rsip_func_sub021(0x0000b7e0U, 0xc45bfa0bU, 0x3420a9e0U, 0x00000003U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);

        static const uint32_t Param_pe1_func100_003[] =
        {
            BSWAP_32BIG_C(0xe15fc758U), BSWAP_32BIG_C(0x019864baU), BSWAP_32BIG_C(0x08e9f8d6U), BSWAP_32BIG_C(
                0x7091e9c4U),
        };
        r_rsip_func100(Param_pe1_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe1_func100_004[] =
            {
                BSWAP_32BIG_C(0x828ff628U), BSWAP_32BIG_C(0xbe82eb44U), BSWAP_32BIG_C(0x4e97ad88U), BSWAP_32BIG_C(
                    0x5fa2d6a4U),
            };
            r_rsip_func100(Param_pe1_func100_004);

            r_rsip_func_sub010(0x000000c7U, 0x80010080U);
            WR1_PROG(REG_1420H, InData_HashType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub021(0x3420a880U, 0x00000006U, 0x2000b480U, 0x00000005U);

            r_rsip_func_sub014(0x00007c04U, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
            {
                WR1_PROG(REG_2004H, 0x00000040U);

                static const uint32_t Param_pe1_func101_004[] =
                {
                    BSWAP_32BIG_C(0x903a415eU), BSWAP_32BIG_C(0x966b235eU), BSWAP_32BIG_C(0x7bcf0be4U), BSWAP_32BIG_C(
                        0x5a757453U),
                };
                r_rsip_func101(Param_pe1_func101_004);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                WR1_PROG(REG_2004H, 0x00000050U);

                static const uint32_t Param_pe1_func101_005[] =
                {
                    BSWAP_32BIG_C(0x4e093fbcU), BSWAP_32BIG_C(0x2584d9afU), BSWAP_32BIG_C(0x96d969d8U), BSWAP_32BIG_C(
                        0xba0f72b0U),
                };
                r_rsip_func101(Param_pe1_func101_005);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                WR1_PROG(REG_2004H, 0x00000080U);

                static const uint32_t Param_pe1_func101_006[] =
                {
                    BSWAP_32BIG_C(0x41acd0f4U), BSWAP_32BIG_C(0x6994a6acU), BSWAP_32BIG_C(0x767349a1U), BSWAP_32BIG_C(
                        0xa31fcd44U),
                };
                r_rsip_func101(Param_pe1_func101_006);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
            {
                WR1_PROG(REG_2004H, 0x00000090U);

                static const uint32_t Param_pe1_func101_007[] =
                {
                    BSWAP_32BIG_C(0xa1914aa8U), BSWAP_32BIG_C(0x970e7c85U), BSWAP_32BIG_C(0x09966cffU), BSWAP_32BIG_C(
                        0xd9971fbdU),
                };
                r_rsip_func101(Param_pe1_func101_007);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
            {
                WR1_PROG(REG_2004H, 0x000000a0U);

                static const uint32_t Param_pe1_func101_008[] =
                {
                    BSWAP_32BIG_C(0x3669f42cU), BSWAP_32BIG_C(0x9c649cc4U), BSWAP_32BIG_C(0x92c7d4ecU), BSWAP_32BIG_C(
                        0x17994dd1U),
                };
                r_rsip_func101(Param_pe1_func101_008);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
            {
                WR1_PROG(REG_2004H, 0x000000b0U);

                static const uint32_t Param_pe1_func101_009[] =
                {
                    BSWAP_32BIG_C(0x20cbc785U), BSWAP_32BIG_C(0xfac2ce7bU), BSWAP_32BIG_C(0xa9c537b4U), BSWAP_32BIG_C(
                        0x7ca21681U),
                };
                r_rsip_func101(Param_pe1_func101_009);
            }

            r_rsip_func_sub021(0x300031e0U, 0x00070020U, 0x0000b400U, 0x000000ffU);

            r_rsip_func_sub021(0x0000b760U, 0x00000040U, 0x0000b5c0U, 0x0000000cU);
            r_rsip_func_sub021(0x00030040U, 0x0000b400U, 0x0000017fU, 0x0000b760U);
            r_rsip_func_sub021(0x00000060U, 0x0000b5c0U, 0x0000000eU, 0x00050040U);
            r_rsip_func_sub021(0x0000b400U, 0x000001ffU, 0x0000b760U, 0x00000080U);

            r_rsip_func_sub021(0x0000b5c0U, 0x00000010U, 0x00000080U, 0x0000b420U);
            r_rsip_func_sub021(0x00000003U, 0x3c002b59U, 0x20000bffU, 0x00002439U);
            WR1_PROG(REG_1600H, 0x3c00283aU);
            WR1_PROG(REG_1600H, 0x20000bffU);

            static const uint32_t Param_pe1_func101_010[] =
            {
                BSWAP_32BIG_C(0x2fa3ec89U), BSWAP_32BIG_C(0x6eb7ca02U), BSWAP_32BIG_C(0x318eca7dU), BSWAP_32BIG_C(
                    0xba0c3ad2U),
            };
            r_rsip_func101(Param_pe1_func101_010);
        }
        else
        {
            static const uint32_t Param_pe1_func100_005[] =
            {
                BSWAP_32BIG_C(0x42053996U), BSWAP_32BIG_C(0x6620965dU), BSWAP_32BIG_C(0x26ced35fU), BSWAP_32BIG_C(
                    0x712b6923U),
            };
            r_rsip_func100(Param_pe1_func100_005);
            r_rsip_func_sub014(0x00007c0fU, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x00000050U);

                r_rsip_func_sub021(0x0000b400U, 0x0000001fU, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000010U, 0x0000b5c0U, 0x00000016U);

                static const uint32_t Param_pe1_func101_011[] =
                {
                    BSWAP_32BIG_C(0x91409efaU), BSWAP_32BIG_C(0x381e0247U), BSWAP_32BIG_C(0xc8da898bU), BSWAP_32BIG_C(
                        0x413a0f80U),
                };
                r_rsip_func101(Param_pe1_func101_011);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000004U);

                WR1_PROG(REG_2004H, 0x000000a0U);

                r_rsip_func_sub021(0x0000b400U, 0x0000002fU, 0x0000b420U, 0x0000002fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000018U, 0x0000b5c0U, 0x00000018U);

                static const uint32_t Param_pe1_func101_012[] =
                {
                    BSWAP_32BIG_C(0xee92f1b7U), BSWAP_32BIG_C(0xbfe9a04eU), BSWAP_32BIG_C(0xb69b5b15U), BSWAP_32BIG_C(
                        0x12b1f857U),
                };
                r_rsip_func101(Param_pe1_func101_012);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000005U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub021(0x0000b400U, 0x00000041U, 0x0000b420U, 0x00000041U);

                r_rsip_func_sub021(0x0000b760U, 0x00000028U, 0x0000b5c0U, 0x00000024U);

                static const uint32_t Param_pe1_func101_013[] =
                {
                    BSWAP_32BIG_C(0x48c54528U), BSWAP_32BIG_C(0x79ad9caaU), BSWAP_32BIG_C(0x62bc221aU), BSWAP_32BIG_C(
                        0xe60a3827U),
                };
                r_rsip_func101(Param_pe1_func101_013);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x00000050U);

                r_rsip_func_sub021(0x0000b400U, 0x0000001fU, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000010U, 0x0000b5c0U, 0x0000001cU);

                static const uint32_t Param_pe1_func101_014[] =
                {
                    BSWAP_32BIG_C(0xc066cc55U), BSWAP_32BIG_C(0x60be867cU), BSWAP_32BIG_C(0x04713fc9U), BSWAP_32BIG_C(
                        0x24742267U),
                };
                r_rsip_func101(Param_pe1_func101_014);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000007U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000004U);

                WR1_PROG(REG_2004H, 0x000000a0U);

                r_rsip_func_sub021(0x0000b400U, 0x0000002fU, 0x0000b420U, 0x0000002fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000018U, 0x0000b5c0U, 0x0000001eU);

                static const uint32_t Param_pe1_func101_015[] =
                {
                    BSWAP_32BIG_C(0xa748a403U), BSWAP_32BIG_C(0x58e06bd9U), BSWAP_32BIG_C(0xaab4e4f7U), BSWAP_32BIG_C(
                        0x04bf7456U),
                };
                r_rsip_func101(Param_pe1_func101_015);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000008U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000005U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub021(0x0000b400U, 0x0000003fU, 0x0000b420U, 0x0000003fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000020U, 0x0000b5c0U, 0x00000020U);

                static const uint32_t Param_pe1_func101_016[] =
                {
                    BSWAP_32BIG_C(0xf714b522U), BSWAP_32BIG_C(0x228c22ecU), BSWAP_32BIG_C(0x52ed2f75U), BSWAP_32BIG_C(
                        0x79c5fc27U),
                };
                r_rsip_func101(Param_pe1_func101_016);
            }

            r_rsip_func_sub021(0x3c002b3aU, 0x10000bffU, 0x00002439U, 0x0800283aU);
            WR1_PROG(REG_1600H, 0x20000bffU);

            static const uint32_t Param_pe1_func101_017[] =
            {
                BSWAP_32BIG_C(0x375f6eebU), BSWAP_32BIG_C(0xb35f6badU), BSWAP_32BIG_C(0x26f2e68cU), BSWAP_32BIG_C(
                    0x7e3978b3U),
            };
            r_rsip_func101(Param_pe1_func101_017);
        }

        r_rsip_func_sub021(0x3c002af8U, 0x10000bffU, 0x3c002b19U, 0x10000bffU);

        r_rsip_func_sub021(0x00002417U, 0x08002818U, 0x20000bffU, 0x3c002b56U);
        WR1_PROG(REG_1600H, 0x10000bffU);

        r_rsip_func_sub006(0x38008be0U, 0xc45bfa0bU, 0x00A60000U);

        static const uint32_t Param_pe1_func100_006[] =
        {
            BSWAP_32BIG_C(0xc61770c2U), BSWAP_32BIG_C(0x61080873U), BSWAP_32BIG_C(0xf4063216U), BSWAP_32BIG_C(
                0x39d09a15U),
        };
        r_rsip_func100(Param_pe1_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe1_func102_002[] =
            {
                BSWAP_32BIG_C(0x36fa6b40U), BSWAP_32BIG_C(0xf19508c1U), BSWAP_32BIG_C(0x315a0bf2U), BSWAP_32BIG_C(
                    0x9284fc67U),
            };
            r_rsip_func102(Param_pe1_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe1_func100_007[] =
            {
                BSWAP_32BIG_C(0x4ded368eU), BSWAP_32BIG_C(0x739a402cU), BSWAP_32BIG_C(0xcf25201aU), BSWAP_32BIG_C(
                    0x40866b40U),
            };
            r_rsip_func100(Param_pe1_func100_007);
            r_rsip_func_sub021(0x00000800U, 0x00003436U, 0x01836c01U, 0x00036c21U);

            r_rsip_func_sub016(0x81020000U, 0x0000500aU);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

            static const uint32_t Param_pe1_func100_008[] =
            {
                BSWAP_32BIG_C(0x9f236dcbU), BSWAP_32BIG_C(0x4a05216eU), BSWAP_32BIG_C(0xeaeef1c8U), BSWAP_32BIG_C(
                    0xe5b1fbd0U),
            };
            r_rsip_func100(Param_pe1_func100_008);
            r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

            r_rsip_func_sub022(0x00003417U, 0x00046800U, 0x00026c00U);

            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1600H, 0x000008a5U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
            {
                WR1_PROG(REG_1444H, 0x000003c4U);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_Certificate[iLoop]);

                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                static const uint32_t Param_pe1_func101_018[] =
                {
                    BSWAP_32BIG_C(0xd80dc115U), BSWAP_32BIG_C(0x03f1a667U), BSWAP_32BIG_C(0x7382e88aU), BSWAP_32BIG_C(
                        0x91fa1b92U),
                };
                r_rsip_func101(Param_pe1_func101_018);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_pe1_func100_009[] =
            {
                BSWAP_32BIG_C(0x943673ccU), BSWAP_32BIG_C(0x31b533f1U), BSWAP_32BIG_C(0x864eb4b1U), BSWAP_32BIG_C(
                    0xc1af8ebbU),
            };
            r_rsip_func100(Param_pe1_func100_009);

            r_rsip_func_sub011(0x38000805U);

            WR1_PROG(REG_1000H, 0x00010000U);
            WR1_PROG(REG_1404H, 0x10000000U);

            r_rsip_func_sub021(0x00003416U, 0x0000a400U, 0x00000003U, 0x00026800U);

            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub021(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

            iTemp = iLoop;
            for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
            {
                r_rsip_func_sub010(0x000000c7U, 0x80010120U);
                WR1_PROG(REG_1420H, InData_Certificate[iLoop]);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000821U);

                for (jLoop = 0U; jLoop < 4; jLoop++)
                {
                    r_rsip_func_sub021(0x00002c20U, 0x01886d09U, 0x00086d29U, 0x00000863U);
                    r_rsip_func_sub021(0x3c002859U, 0x20002c60U, 0x3c002b42U, 0x20002c60U);
                    r_rsip_func_sub017(0x38000c63U, 0x00260000U);

                    static const uint32_t Param_pe1_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x52fa4e42U), BSWAP_32BIG_C(0xde3a8342U), BSWAP_32BIG_C(0xed4f789aU),
                        BSWAP_32BIG_C(0x9cf2e4fcU),
                    };
                    r_rsip_func100(Param_pe1_func100_010);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        r_rsip_func_sub006(0x3420a9e0U, 0x00000003U, 0x00260000U);

                        static const uint32_t Param_pe1_func100_011[] =
                        {
                            BSWAP_32BIG_C(0x9c92371bU), BSWAP_32BIG_C(0x61e9d86dU), BSWAP_32BIG_C(0x2c8f9fdeU),
                            BSWAP_32BIG_C(0x2f3dcf23U),
                        };
                        r_rsip_func100(Param_pe1_func100_011);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub022(0x00186d08U, 0x01886e88U, 0x00186908U);

                            static const uint32_t Param_pe1_func101_019[] =
                            {
                                BSWAP_32BIG_C(0xa294132dU), BSWAP_32BIG_C(0x565a2dc4U), BSWAP_32BIG_C(0x3c7f2c11U),
                                BSWAP_32BIG_C(0x4134bf52U),
                            };
                            r_rsip_func101(Param_pe1_func101_019);
                        }
                        else
                        {
                            WR1_PROG(REG_1608H, 0x81010100U);
                            r_rsip_func_sub001(0x1009000dU);
                            r_rsip_func_sub001(0x10c90005U);

                            static const uint32_t Param_pe1_func101_020[] =
                            {
                                BSWAP_32BIG_C(0xd81bf4abU), BSWAP_32BIG_C(0xb4efe6d1U), BSWAP_32BIG_C(0xe830c148U),
                                BSWAP_32BIG_C(0x9abdb394U),
                            };
                            r_rsip_func101(Param_pe1_func101_020);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub021(0x00000863U, 0x3c002857U, 0x20002c60U, 0x3c002b02U);
                    r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                    static const uint32_t Param_pe1_func100_012[] =
                    {
                        BSWAP_32BIG_C(0x3e7aebe3U), BSWAP_32BIG_C(0xa378e9bbU), BSWAP_32BIG_C(0xddc9a3e1U),
                        BSWAP_32BIG_C(0x49b40652U),
                    };
                    r_rsip_func100(Param_pe1_func100_012);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1608H, 0x81010100U);
                        r_rsip_func_sub001(0x1009000dU);
                        r_rsip_func_sub001(0x10c90005U);

                        static const uint32_t Param_pe1_func101_021[] =
                        {
                            BSWAP_32BIG_C(0x44327153U), BSWAP_32BIG_C(0xb62c61e1U), BSWAP_32BIG_C(0x5b348069U),
                            BSWAP_32BIG_C(0x17e1c246U),
                        };
                        r_rsip_func101(Param_pe1_func101_021);
                    }

                    r_rsip_func_sub021(0x00000863U, 0x3c0028c2U, 0x20002c60U, 0x38000c63U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);

                    static const uint32_t Param_pe1_func100_013[] =
                    {
                        BSWAP_32BIG_C(0x95b3ee35U), BSWAP_32BIG_C(0xfbab6178U), BSWAP_32BIG_C(0xd863299eU),
                        BSWAP_32BIG_C(0x49f14dc2U),
                    };
                    r_rsip_func100(Param_pe1_func100_013);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1608H, 0x81010100U);
                        r_rsip_func_sub001(0x1009000dU);
                        r_rsip_func_sub001(0x11490005U);

                        static const uint32_t Param_pe1_func101_022[] =
                        {
                            BSWAP_32BIG_C(0x8c9e70afU), BSWAP_32BIG_C(0x91efe26dU), BSWAP_32BIG_C(0x61fd4e26U),
                            BSWAP_32BIG_C(0x2e2b9b66U),
                        };
                        r_rsip_func101(Param_pe1_func101_022);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);

                    static const uint32_t Param_pe1_func101_023[] =
                    {
                        BSWAP_32BIG_C(0xebc65b89U), BSWAP_32BIG_C(0x8c5f3d76U), BSWAP_32BIG_C(0x4f223e38U),
                        BSWAP_32BIG_C(0x6191d722U),
                    };
                    r_rsip_func101(Param_pe1_func101_023);
                }

                WR1_PROG(REG_1600H, 0x38008820U);
                r_rsip_func_sub011(0x00000004U);

                WR1_PROG(REG_1600H, 0x00002ca0U);

                static const uint32_t Param_pe1_func101_024[] =
                {
                    BSWAP_32BIG_C(0x6d5c8539U), BSWAP_32BIG_C(0xb6195b86U), BSWAP_32BIG_C(0x9b534b14U), BSWAP_32BIG_C(
                        0xfa876225U),
                };
                r_rsip_func101(Param_pe1_func101_024);
            }

            r_rsip_func_sub011(0x38000805U);

            static const uint32_t Param_pe1_func100_014[] =
            {
                BSWAP_32BIG_C(0x1dc7327cU), BSWAP_32BIG_C(0x977dbae2U), BSWAP_32BIG_C(0x946d399aU), BSWAP_32BIG_C(
                    0xff3da863U),
            };
            r_rsip_func100(Param_pe1_func100_014);
            r_rsip_func_sub021(0x00003416U, 0x00008c00U, 0x00000003U, 0x0000b440U);
            r_rsip_func_sub021(0x00000004U, 0x00002840U, 0x00008c40U, 0x00000003U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1600H, 0x000008a5U);

            WR1_PROG(REG_1600H, 0x00000863U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1608H, 0x81010060U);
                r_rsip_func_sub001(0x11490005U);
                r_rsip_func_sub001(0x1009000dU);

                WR1_PROG(REG_1600H, 0x00086c63U);

                WR1_PROG(REG_1600H, 0x00002ca0U);

                static const uint32_t Param_pe1_func101_025[] =
                {
                    BSWAP_32BIG_C(0x134094ebU), BSWAP_32BIG_C(0xd34b894cU), BSWAP_32BIG_C(0xdbb7c5edU), BSWAP_32BIG_C(
                        0xc0f38ef2U),
                };
                r_rsip_func101(Param_pe1_func101_025);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000845U);

            WAIT_STS(REG_2030H, 4, 1);

            r_rsip_func_sub006(0x00000800U, 0x38000c84U, 0x00260000U);

            r_rsip_func_sub006(0x38008880U, 0x00000002U, 0x00260000U);

            static const uint32_t Param_pe1_func100_015[] =
            {
                BSWAP_32BIG_C(0xb2261df8U), BSWAP_32BIG_C(0x7149d534U), BSWAP_32BIG_C(0xf4e0af61U), BSWAP_32BIG_C(
                    0xd3f98973U),
            };
            r_rsip_func100(Param_pe1_func100_015);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00003200U);

                static const uint32_t Param_pe1_func101_026[] =
                {
                    BSWAP_32BIG_C(0x860570eeU), BSWAP_32BIG_C(0x3d58cf8dU), BSWAP_32BIG_C(0xe922a304U), BSWAP_32BIG_C(
                        0x59bc4d4bU),
                };
                r_rsip_func101(Param_pe1_func101_026);
            }

            static const uint32_t Param_pe1_func100_016[] =
            {
                BSWAP_32BIG_C(0xe17ae44aU), BSWAP_32BIG_C(0xce3c83b0U), BSWAP_32BIG_C(0x075309b4U), BSWAP_32BIG_C(
                    0x7a48ccbeU),
            };
            r_rsip_func100(Param_pe1_func100_016);
            r_rsip_func_sub016(0x81010200U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub022(0x000008a5U, 0x0000b7e0U, 0xc45bfa0bU);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1608H, 0x80010020U);
                r_rsip_func_sub001(0x03450005U);

                r_rsip_func_sub021(0x00003840U, 0x08002822U, 0x20000bffU, 0x0000a400U);
                WR1_PROG(REG_1600H, 0x00000004U);

                WR1_PROG(REG_1600H, 0x00002ca0U);

                static const uint32_t Param_pe1_func101_027[] =
                {
                    BSWAP_32BIG_C(0xaaac435aU), BSWAP_32BIG_C(0x3c109c49U), BSWAP_32BIG_C(0x0f38b4bdU), BSWAP_32BIG_C(
                        0xda8ad238U),
                };
                r_rsip_func101(Param_pe1_func101_027);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000a05U);

            r_rsip_func_sub017(0x38000c84U, 0x00260000U);

            r_rsip_func_sub006(0x38008880U, 0x00000002U, 0x00260000U);

            static const uint32_t Param_pe1_func100_017[] =
            {
                BSWAP_32BIG_C(0xe362c73dU), BSWAP_32BIG_C(0x3b9df317U), BSWAP_32BIG_C(0x7163f3feU), BSWAP_32BIG_C(
                    0xf3a3f5bbU),
            };
            r_rsip_func100(Param_pe1_func100_017);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub022(0x00003840U, 0x38000c42U, 0x20000bffU);

                static const uint32_t Param_pe1_func101_028[] =
                {
                    BSWAP_32BIG_C(0xe9d95f73U), BSWAP_32BIG_C(0x5ec0177fU), BSWAP_32BIG_C(0x7240ecf1U), BSWAP_32BIG_C(
                        0xaa9fa2d5U),
                };
                r_rsip_func101(Param_pe1_func101_028);
            }

            r_rsip_func_sub006(0x38008be0U, 0xc45bfa0bU, 0x00A60000U);

            static const uint32_t Param_pe1_func100_018[] =
            {
                BSWAP_32BIG_C(0x51a2b00dU), BSWAP_32BIG_C(0xd2041e26U), BSWAP_32BIG_C(0xc7f7cbfcU), BSWAP_32BIG_C(
                    0x9be3fb96U),
            };
            r_rsip_func100(Param_pe1_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe1_func102_003[] =
                {
                    BSWAP_32BIG_C(0x260110aeU), BSWAP_32BIG_C(0xfc151371U), BSWAP_32BIG_C(0x88c3ac82U), BSWAP_32BIG_C(
                        0xf3d244f9U),
                };
                r_rsip_func102(Param_pe1_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub006(0x380089e0U, 0x00000005U, 0x00260000U);

                static const uint32_t Param_pe1_func100_019[] =
                {
                    BSWAP_32BIG_C(0x756c96eaU), BSWAP_32BIG_C(0xad77977cU), BSWAP_32BIG_C(0x98075bceU), BSWAP_32BIG_C(
                        0x6e881799U),
                };
                r_rsip_func100(Param_pe1_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    WR1_PROG(REG_1608H, 0x80a80000U);

                    r_rsip_func_sub001(0x13400039U);

                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x13430109U);

                    r_rsip_func_sub001(0x13400039U);

                    r_rsip_func_sub001(0x13430109U);

                    WR1_PROG(REG_1404H, 0x10000000U);
                    WR1_PROG(REG_1608H, 0x81a80000U);
                    r_rsip_func_sub001(0x00c900a1U);

                    static const uint32_t Param_pe1_func101_029[] =
                    {
                        BSWAP_32BIG_C(0xa506eaefU), BSWAP_32BIG_C(0x4d32c898U), BSWAP_32BIG_C(0xc97a3821U),
                        BSWAP_32BIG_C(0x8553e52aU),
                    };
                    r_rsip_func101(Param_pe1_func101_029);
                }

                r_rsip_func_sub009(0x000000e1U);

                static const uint32_t Param_pe1_func101_030[] =
                {
                    BSWAP_32BIG_C(0xcd41e486U), BSWAP_32BIG_C(0x0a6fdbb4U), BSWAP_32BIG_C(0xfc39300fU), BSWAP_32BIG_C(
                        0x692a8b48U),
                };
                r_rsip_func101(Param_pe1_func101_030);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub009(0x0000e102U);

                static const uint32_t Param_pe1_func101_031[] =
                {
                    BSWAP_32BIG_C(0x6f2949bcU), BSWAP_32BIG_C(0xa6a6b534U), BSWAP_32BIG_C(0x0121d25dU), BSWAP_32BIG_C(
                        0x5eb2ae70U),
                };
                r_rsip_func101(Param_pe1_func101_031);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034eeU);

                r_rsip_func_sub009(0x0000e102U);

                static const uint32_t Param_pe1_func101_032[] =
                {
                    BSWAP_32BIG_C(0xbf4c82e9U), BSWAP_32BIG_C(0xaf587da9U), BSWAP_32BIG_C(0x78008879U), BSWAP_32BIG_C(
                        0x864304e7U),
                };
                r_rsip_func101(Param_pe1_func101_032);
                r_rsip_func044();

                static const uint32_t Param_pe1_func100_020[] =
                {
                    BSWAP_32BIG_C(0x202d610eU), BSWAP_32BIG_C(0xcc86ec09U), BSWAP_32BIG_C(0x81a3ff56U), BSWAP_32BIG_C(
                        0x5cf31d9aU),
                };
                r_rsip_func100(Param_pe1_func100_020);
                r_rsip_func_sub004(0x08000044U, 0x00000000U);

                r_rsip_func_sub004(0x08000054U, 0x00000000U);

                r_rsip_func_sub016(0x81010360U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub031(0x00000884U, 0x000008a5U, 0x10000000U);
                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
                {
                    WR1_PROG(REG_1600H, 0x342028bbU);
                    WR1_PROG(REG_1600H, 0x2000d080U);
                    r_rsip_func_sub014(0x00007c04U, 0x00602000U);

                    static const uint32_t Param_pe1_func100_021[] =
                    {
                        BSWAP_32BIG_C(0x6576d756U), BSWAP_32BIG_C(0x01e77778U), BSWAP_32BIG_C(0xae73726bU),
                        BSWAP_32BIG_C(0x749d5529U),
                    };
                    r_rsip_func100(Param_pe1_func100_021);
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0xe8008105U);
                    r_rsip_func_sub001(0x00830011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

                    WR1_PROG(REG_1600H, 0x0000a4a0U);
                    WR1_PROG(REG_1600H, 0x00000004U);

                    static const uint32_t Param_pe1_func101_033[] =
                    {
                        BSWAP_32BIG_C(0x8d765fdbU), BSWAP_32BIG_C(0x732d00fcU), BSWAP_32BIG_C(0x634d272bU),
                        BSWAP_32BIG_C(0x45127e77U),
                    };
                    r_rsip_func101(Param_pe1_func101_033);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x380008bbU);

                r_rsip_func_sub006(0x3420a9e0U, 0x00000003U, 0x00260000U);

                static const uint32_t Param_pe1_func100_022[] =
                {
                    BSWAP_32BIG_C(0xebc0bf7cU), BSWAP_32BIG_C(0x5c1c87bfU), BSWAP_32BIG_C(0xaa286a00U), BSWAP_32BIG_C(
                        0x04e4fa4cU),
                };
                r_rsip_func100(Param_pe1_func100_022);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pe1_func100_023[] =
                    {
                        BSWAP_32BIG_C(0x80ce39d6U), BSWAP_32BIG_C(0xfd36fc95U), BSWAP_32BIG_C(0xf24910cdU),
                        BSWAP_32BIG_C(0xefc2ff05U),
                    };
                    r_rsip_func100(Param_pe1_func100_023);
                    r_rsip_func_sub027(0x40000000U, 0xe8008104U, 0x81010280U);
                    r_rsip_func_sub001(0x00890005U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);
                    iLoop = iLoop + 4;

                    static const uint32_t Param_pe1_func101_034[] =
                    {
                        BSWAP_32BIG_C(0xadca102fU), BSWAP_32BIG_C(0x69e9817aU), BSWAP_32BIG_C(0x1b9d333fU),
                        BSWAP_32BIG_C(0xf948a461U),
                    };
                    r_rsip_func101(Param_pe1_func101_034);
                }

                static const uint32_t Param_pe1_func100_024[] =
                {
                    BSWAP_32BIG_C(0x75254fd8U), BSWAP_32BIG_C(0x7ec618ceU), BSWAP_32BIG_C(0xb4195e59U), BSWAP_32BIG_C(
                        0x044069a5U),
                };
                r_rsip_func100(Param_pe1_func100_024);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

                static const uint32_t Param_pe1_func100_025[] =
                {
                    BSWAP_32BIG_C(0xd25147b2U), BSWAP_32BIG_C(0xc94b474eU), BSWAP_32BIG_C(0x4fb0ce45U), BSWAP_32BIG_C(
                        0x516f831dU),
                };
                r_rsip_func100(Param_pe1_func100_025);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                static const uint32_t Param_pe1_func102_004[] =
                {
                    BSWAP_32BIG_C(0xcc0a6039U), BSWAP_32BIG_C(0xac686a39U), BSWAP_32BIG_C(0x7fa27013U), BSWAP_32BIG_C(
                        0x98bf87f4U),
                };
                r_rsip_func102(Param_pe1_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
