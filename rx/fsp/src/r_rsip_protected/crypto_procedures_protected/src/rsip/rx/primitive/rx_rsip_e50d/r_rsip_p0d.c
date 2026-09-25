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

rsip_ret_t r_rsip_p0d (const uint32_t InData_KeyCertificate[],
                       const uint32_t InData_KeyCertificateLength[],
                       const uint32_t InData_KeyCertificateSignature[],
                       const uint32_t InData_KeyCertificatePubKey[],
                       const uint32_t InData_ImgPkHash[],
                       const uint32_t InData_OemRootPkHashIndex[],
                       const uint32_t InData_CodeCertificate[],
                       const uint32_t InData_CodeCertificateLength[],
                       const uint32_t InData_CodeCertificateSignature[],
                       const uint32_t InData_CodeCertificatePubKey[],
                       const uint32_t InData_Image[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       MAX_CNT,
                       uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;
    uint32_t iTemp = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000d0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000004c7U, 0x800501e0U);
    WR1_PROG(REG_1420H, InData_CodeCertificateLength[0]);
    for (iLoop = 0U; iLoop < 4; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CodeCertificatePubKey[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000006c7U, 0x800702c0U);
    WR1_PROG(REG_1420H, InData_KeyCertificateLength[0]);
    for (iLoop = 0U; iLoop < 4; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyCertificatePubKey[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0U; iLoop < 2U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_ImgPkHash[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x00000bffU, 0x34202af8U, 0x2000d3e0U, 0x34202b19U);
    r_rsip_func_sub021(0x2000d3e0U, 0x34202b3aU, 0x2000d3e0U, 0x34202b5bU);
    r_rsip_func_sub021(0x2000d3e0U, 0x34202b7cU, 0x2000d3e0U, 0x34202b96U);
    r_rsip_func_sub021(0x2000d3e0U, 0x00003417U, 0x0000a400U, 0x0000001fU);
    r_rsip_func_sub021(0x08000818U, 0x2000d3e0U, 0x00003419U, 0x0000a400U);
    r_rsip_func_sub021(0x0000001fU, 0x0800081aU, 0x2000d3e0U, 0x0000341bU);
    r_rsip_func_sub021(0x0000a400U, 0x0000001fU, 0x0800081cU, 0x2000d3e0U);

    r_rsip_func_sub021(0x0000b7c0U, 0x0000001fU, 0x34202bd0U, 0x2000d3e0U);

    r_rsip_func_sub021(0x34202a11U, 0x2000d3e0U, 0x34202a32U, 0x2000d3e0U);

    r_rsip_func_sub021(0x34202a53U, 0x2000d3e0U, 0x34202a6fU, 0x2000d3e0U);

    r_rsip_func_sub021(0x00003410U, 0x0000a400U, 0x0000001fU, 0x08000811U);
    r_rsip_func_sub021(0x2000d3e0U, 0x00003412U, 0x0000a400U, 0x0000001fU);
    WR1_PROG(REG_1600H, 0x08000813U);
    r_rsip_func_sub006(0x2000d3e0U, 0x38000fffU, 0x00A60000U);

    static const uint32_t Param_p0d_func100_001[] =
    {
        BSWAP_32BIG_C(0x831b6bb1U), BSWAP_32BIG_C(0x3f246904U), BSWAP_32BIG_C(0x4b73cb1fU), BSWAP_32BIG_C(0x65cf3e27U),
    };
    r_rsip_func100(Param_p0d_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_14BCH, 0x00000020U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PARAM_FAIL;
    }
    else
    {
        static const uint32_t Param_p0d_func100_002[] =
        {
            BSWAP_32BIG_C(0x5ca1e392U), BSWAP_32BIG_C(0x99db81f1U), BSWAP_32BIG_C(0xb0bd47a4U), BSWAP_32BIG_C(
                0x82f1179aU),
        };
        r_rsip_func100(Param_p0d_func100_002);

        WR1_PROG(REG_2000H, 0x00000001U);

        WR1_PROG(REG_2004H, 0x00000050U);

        r_rsip_func_sub021(0x00000800U, 0x00003436U, 0x01836c01U, 0x00036c21U);

        r_rsip_func_sub016(0x81020000U, 0x0000500aU);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
        S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

        static const uint32_t Param_p0d_func100_003[] =
        {
            BSWAP_32BIG_C(0x1ffeba66U), BSWAP_32BIG_C(0xe03aa614U), BSWAP_32BIG_C(0x5f785cdcU), BSWAP_32BIG_C(
                0xbc43b43bU),
        };
        r_rsip_func100(Param_p0d_func100_003);
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
            WR4_ADDR(REG_1420H, &InData_KeyCertificate[iLoop]);
            r_rsip_func_sub034(0x0000a4a0U, 0x00000004U);

            static const uint32_t Param_p0d_func101_001[] =
            {
                BSWAP_32BIG_C(0x15debcdfU), BSWAP_32BIG_C(0x09241556U), BSWAP_32BIG_C(0x649280c5U), BSWAP_32BIG_C(
                    0x0018b36aU),
            };
            r_rsip_func101(Param_p0d_func101_001);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p0d_func100_004[] =
        {
            BSWAP_32BIG_C(0x55fa5828U), BSWAP_32BIG_C(0x5bb42cd4U), BSWAP_32BIG_C(0xde7185bcU), BSWAP_32BIG_C(
                0x273c3970U),
        };
        r_rsip_func100(Param_p0d_func100_004);

        r_rsip_func_sub011(0x38000805U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1404H, 0x10000000U);

        r_rsip_func_sub021(0x00003416U, 0x00026800U, 0x38008ec0U, 0x00000003U);
        WR1_PROG(REG_1600H, 0x20002c00U);

        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        r_rsip_func_sub021(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1600H, 0x00000180U);

        iTemp = iLoop;
        for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010100U);
            WR1_PROG(REG_1420H, InData_KeyCertificate[iLoop]);
            r_rsip_func_sub034(0x0000b420U, 0x00000004U);

            for (jLoop = 0U; jLoop < 4; jLoop++)
            {
                r_rsip_func_sub021(0x00003020U, 0x01886ce8U, 0x00086d08U, 0x00000863U);
                r_rsip_func_sub021(0x3c002859U, 0x20002c60U, 0x3c002b42U, 0x20002c60U);
                r_rsip_func_sub017(0x38000c63U, 0x00260000U);

                static const uint32_t Param_p0d_func100_005[] =
                {
                    BSWAP_32BIG_C(0xff6751fdU), BSWAP_32BIG_C(0x1c3cf315U), BSWAP_32BIG_C(0x14139929U), BSWAP_32BIG_C(
                        0x26a4890cU),
                };
                r_rsip_func100(Param_p0d_func100_005);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    r_rsip_func_sub001(0x1009000dU);
                    r_rsip_func_sub001(0x10c90005U);

                    static const uint32_t Param_p0d_func101_002[] =
                    {
                        BSWAP_32BIG_C(0x6e28dd83U), BSWAP_32BIG_C(0x1deccb3fU), BSWAP_32BIG_C(0x3521cec4U),
                        BSWAP_32BIG_C(0x2cf3efb3U),
                    };
                    r_rsip_func101(Param_p0d_func101_002);
                }

                r_rsip_func_sub021(0x00000863U, 0x3c002857U, 0x20002c60U, 0x3c002b02U);
                r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                static const uint32_t Param_p0d_func100_006[] =
                {
                    BSWAP_32BIG_C(0x085e6bc6U), BSWAP_32BIG_C(0x2849a151U), BSWAP_32BIG_C(0x9cf59110U), BSWAP_32BIG_C(
                        0x89448764U),
                };
                r_rsip_func100(Param_p0d_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    r_rsip_func_sub001(0x1009000dU);
                    r_rsip_func_sub001(0x10c90005U);

                    static const uint32_t Param_p0d_func101_003[] =
                    {
                        BSWAP_32BIG_C(0x7c1aa105U), BSWAP_32BIG_C(0xd473fa44U), BSWAP_32BIG_C(0x3290bfceU),
                        BSWAP_32BIG_C(0x0e51b99aU),
                    };
                    r_rsip_func101(Param_p0d_func101_003);
                }

                r_rsip_func_sub021(0x00000863U, 0x3c00285bU, 0x20002c60U, 0x3c002b82U);
                r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                static const uint32_t Param_p0d_func100_007[] =
                {
                    BSWAP_32BIG_C(0xfc3c8fc1U), BSWAP_32BIG_C(0xf38b9e12U), BSWAP_32BIG_C(0xb1add27dU), BSWAP_32BIG_C(
                        0xff897ce9U),
                };
                r_rsip_func100(Param_p0d_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x02003ce9U);
                    WR1_PROG(REG_1600H, 0x00002d20U);
                    static const uint32_t Param_p0d_func101_004[] =
                    {
                        BSWAP_32BIG_C(0xf27884d7U), BSWAP_32BIG_C(0x9476dcafU), BSWAP_32BIG_C(0xd89c407aU),
                        BSWAP_32BIG_C(0x35f2fde5U),
                    };
                    r_rsip_func101(Param_p0d_func101_004);
                }

                r_rsip_func_sub021(0x00000863U, 0x3c0028c2U, 0x20002c60U, 0x38000c63U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);

                static const uint32_t Param_p0d_func100_008[] =
                {
                    BSWAP_32BIG_C(0xd4ab7ac6U), BSWAP_32BIG_C(0x2cbe6014U), BSWAP_32BIG_C(0xf5e5c0c8U), BSWAP_32BIG_C(
                        0x63e2077cU),
                };
                r_rsip_func100(Param_p0d_func100_008);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    r_rsip_func_sub001(0x1009000dU);
                    r_rsip_func_sub001(0x11490005U);

                    static const uint32_t Param_p0d_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x4fe5ce9fU), BSWAP_32BIG_C(0x930ae0b5U), BSWAP_32BIG_C(0xaaf6a25dU),
                        BSWAP_32BIG_C(0xf617e0c7U),
                    };
                    r_rsip_func101(Param_p0d_func101_005);
                }

                WR1_PROG(REG_1600H, 0x00002c40U);

                static const uint32_t Param_p0d_func101_006[] =
                {
                    BSWAP_32BIG_C(0x4e33c849U), BSWAP_32BIG_C(0x97c695a3U), BSWAP_32BIG_C(0xe2c4d6a0U), BSWAP_32BIG_C(
                        0x70466b75U),
                };
                r_rsip_func101(Param_p0d_func101_006);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x08000c21U);

            WR1_PROG(REG_1600H, 0x00002ca0U);

            static const uint32_t Param_p0d_func101_007[] =
            {
                BSWAP_32BIG_C(0xa902c7a9U), BSWAP_32BIG_C(0xdce19b91U), BSWAP_32BIG_C(0x4e1926bfU), BSWAP_32BIG_C(
                    0x4dee2dcdU),
            };
            r_rsip_func101(Param_p0d_func101_007);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000805U);

        static const uint32_t Param_p0d_func100_009[] =
        {
            BSWAP_32BIG_C(0xc71bc8edU), BSWAP_32BIG_C(0xad2aaca5U), BSWAP_32BIG_C(0x273c2b2aU), BSWAP_32BIG_C(
                0x0f1d4a2aU),
        };
        r_rsip_func100(Param_p0d_func100_009);
        r_rsip_func_sub021(0x00003416U, 0x00008c00U, 0x00000003U, 0x0000b440U);
        r_rsip_func_sub021(0x00000004U, 0x00002840U, 0x00008c40U, 0x00000003U);

        r_rsip_func_sub016(0x81010040U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        r_rsip_func_sub022(0x000008a5U, 0x0000b460U, 0x00000000U);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1608H, 0x81010060U);
            r_rsip_func_sub001(0x11490005U);
            r_rsip_func_sub001(0x1009000dU);

            WR1_PROG(REG_1600H, 0x00086c63U);

            WR1_PROG(REG_1600H, 0x00002ca0U);

            static const uint32_t Param_p0d_func101_008[] =
            {
                BSWAP_32BIG_C(0xd7c6e88dU), BSWAP_32BIG_C(0xed895421U), BSWAP_32BIG_C(0x7794f213U), BSWAP_32BIG_C(
                    0x4267998bU),
            };
            r_rsip_func101(Param_p0d_func101_008);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000845U);

        WAIT_STS(REG_2030H, 4, 1);

        WR1_PROG(REG_1600H, 0x00000929U);
        WR1_PROG(REG_1608H, 0x80880009U);
        r_rsip_func_sub001(0x03450021U);

        WR1_PROG(REG_2000H, 0x00000001U);

        WR1_PROG(REG_2004H, 0x00000050U);

        WR1_PROG(REG_2014H, 0x00000000U);
        WR1_PROG(REG_2010H, 0x00000200U);

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func_sub001(0x01430041U);

        WAIT_STS(REG_2030H, 4, 1);

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x000000fdU);

        r_rsip_func_sub009(0x0000000dU);

        static const uint32_t Param_p0d_func101_009[] =
        {
            BSWAP_32BIG_C(0xe2b71912U), BSWAP_32BIG_C(0xc41b9246U), BSWAP_32BIG_C(0x752a7471U), BSWAP_32BIG_C(
                0x0387e2bdU),
        };
        r_rsip_func101(Param_p0d_func101_009);
        r_rsip_func043();

        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_1420H, &InData_OemRootPkHashIndex[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_OemRootPkHashIndex[4]);

        r_rsip_func_sub023(0x0000b520U, 0x00000020U, 0x80880009U);
        r_rsip_func_sub001(0x03420021U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_OemRootPkHashIndex[8]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p0d_func100_010[] =
        {
            BSWAP_32BIG_C(0x06a8f9c0U), BSWAP_32BIG_C(0x3bb3ed37U), BSWAP_32BIG_C(0x11876ae6U), BSWAP_32BIG_C(
                0x773822b5U),
        };
        r_rsip_func100(Param_p0d_func100_010);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_14BCH, 0x00000020U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000020U);

            WR1_PROG(REG_1A24H, 0x08000055U);
            WR1_PROG(REG_1608H, 0x81840009U);
            r_rsip_func_sub001(0x00890011U);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00850011U);

            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000030U);

            WR1_PROG(REG_1A24H, 0x08000055U);
            WR1_PROG(REG_1608H, 0x81840009U);
            r_rsip_func_sub001(0x00890011U);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00850011U);

            static const uint32_t Param_p0d_func100_011[] =
            {
                BSWAP_32BIG_C(0x6746deb4U), BSWAP_32BIG_C(0x6509b11cU), BSWAP_32BIG_C(0x81501bfaU), BSWAP_32BIG_C(
                    0x3660fbcaU),
            };
            r_rsip_func100(Param_p0d_func100_011);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_14BCH, 0x00000020U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_VERIFICATION_FAIL;
            }
            else
            {
                r_rsip_func_sub012(0x10000000U, 0x0000b420U, 0x00000060U);
                WR1_PROG(REG_1608H, 0x80900001U);
                r_rsip_func_sub001(0x03430041U);

                WR1_PROG(REG_1404H, 0x19100000U);
                r_rsip_func_sub019(0x00000fc1U, 0x00000300U, 0x08008107U);
                WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[0]);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[4]);
                r_rsip_func_sub001(0x00c10021U);

                WR1_PROG(REG_1404H, 0x19600000U);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[8]);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[12]);
                r_rsip_func_sub001(0x00c10021U);

                WR1_PROG(REG_1600H, 0x00000b5aU);
                WR1_PROG(REG_1600H, 0x00000b9cU);

                r_rsip_func_sub009(0x00000d01U);

                static const uint32_t Param_p0d_func101_010[] =
                {
                    BSWAP_32BIG_C(0x096d68a4U), BSWAP_32BIG_C(0xc2b3e89bU), BSWAP_32BIG_C(0x66882315U), BSWAP_32BIG_C(
                        0xf70ca3e7U),
                };
                r_rsip_func101(Param_p0d_func101_010);
                r_rsip_func073(InData_DomainParam);

                static const uint32_t Param_p0d_func100_012[] =
                {
                    BSWAP_32BIG_C(0xee0c2400U), BSWAP_32BIG_C(0xa455b9e1U), BSWAP_32BIG_C(0x5373985dU), BSWAP_32BIG_C(
                        0x7b80e787U),
                };
                r_rsip_func100(Param_p0d_func100_012);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_14BCH, 0x00000020U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_VERIFICATION_FAIL;
                }
                else
                {
                    static const uint32_t Param_p0d_func100_013[] =
                    {
                        BSWAP_32BIG_C(0x106cfe87U), BSWAP_32BIG_C(0xc142b3f1U), BSWAP_32BIG_C(0xde06adaaU),
                        BSWAP_32BIG_C(0x5101c2d8U),
                    };
                    r_rsip_func100(Param_p0d_func100_013);

                    r_rsip_func_sub021(0x000036cfU, 0x000036f0U, 0x00003711U, 0x00003732U);
                    WR1_PROG(REG_1600H, 0x00003753U);

                    WR1_PROG(REG_2000H, 0x00000001U);

                    WR1_PROG(REG_2004H, 0x00000050U);

                    r_rsip_func_sub010(0x000000c7U, 0x80010160U);
                    WR1_PROG(REG_1420H, MAX_CNT);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub021(0x00000800U, 0x0000342bU, 0x01826c01U, 0x00026c21U);

                    r_rsip_func_sub021(0x000008c6U, 0x0c002436U, 0x00802406U, 0x01836c01U);
                    WR1_PROG(REG_1600H, 0x00036c21U);

                    r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                    RD1_ADDR(REG_1420H, &S_RAM[0]);
                    S_RAM[0] = bswap_32big(S_RAM[0]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

                    static const uint32_t Param_p0d_func100_014[] =
                    {
                        BSWAP_32BIG_C(0x52ca3ff9U), BSWAP_32BIG_C(0x24f7ed63U), BSWAP_32BIG_C(0xa1540279U),
                        BSWAP_32BIG_C(0x895e2e7dU),
                    };
                    r_rsip_func100(Param_p0d_func100_014);
                    r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

                    r_rsip_func_sub022(0x00003417U, 0x00046800U, 0x00026c00U);

                    r_rsip_func_sub016(0x81010000U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0]);
                    S_RAM[0] = bswap_32big(S_RAM[0]);

                    r_rsip_func_sub009(0x0000000dU);

                    static const uint32_t Param_p0d_func101_011[] =
                    {
                        BSWAP_32BIG_C(0x49d6f958U), BSWAP_32BIG_C(0x62a66ccaU), BSWAP_32BIG_C(0xa3a5184bU),
                        BSWAP_32BIG_C(0x071f9050U),
                    };
                    r_rsip_func101(Param_p0d_func101_011);
                    r_rsip_func103();

                    static const uint32_t Param_p0d_func100_015[] =
                    {
                        BSWAP_32BIG_C(0x1575734dU), BSWAP_32BIG_C(0xdb978e67U), BSWAP_32BIG_C(0x3324f9a6U),
                        BSWAP_32BIG_C(0x0780b36eU),
                    };
                    r_rsip_func100(Param_p0d_func100_015);
                    r_rsip_func_sub004(0x0c200184U, 0x00000000U);

                    r_rsip_func_sub020(0x000003a1U, 0x08000045U);
                    WR4_PROG(REG_1420H,
                             bswap_32big(0x8ab22685U),
                             bswap_32big(0xbfab115bU),
                             bswap_32big(0x841c0f17U),
                             bswap_32big(0xa1af8aa1U));

                    WR1_PROG(REG_1824H, 0x0e0c0446U);

                    WR1_PROG(REG_1600H, 0x0000b7e0U);
                    WR1_PROG(REG_1600H, 0x00000090U);

                    WR1_PROG(REG_1444H, 0x000007c7U);
                    WR1_PROG(REG_1608H, 0x8088001fU);
                    for (iLoop = 0U; iLoop < 8U; iLoop++)
                    {
                        WAIT_STS(REG_1444H, 31, 1);
                        WR1_PROG(REG_1420H, InData_CodeCertificate[iLoop]);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    WR1_PROG(REG_1608H, 0x8188001fU);
                    r_rsip_func_sub001(0x02490021U);

                    WR1_PROG(REG_1600H, 0x0000b4a0U);
                    WR1_PROG(REG_1600H, 0x00000008U);

                    for (iLoop = 8; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
                    {
                        WR1_PROG(REG_1444H, 0x000003caU);
                        WAIT_STS(REG_1444H, 31, 1);
                        WR4_ADDR(REG_1420H, &InData_CodeCertificate[iLoop]);

                        WR1_PROG(REG_1600H, 0x0000a4a0U);
                        WR1_PROG(REG_1600H, 0x00000004U);

                        static const uint32_t Param_p0d_func101_012[] =
                        {
                            BSWAP_32BIG_C(0x8e2dd378U), BSWAP_32BIG_C(0x9b1e1130U), BSWAP_32BIG_C(0x6622f038U),
                            BSWAP_32BIG_C(0x9f2fbc6fU),
                        };
                        r_rsip_func101(Param_p0d_func101_012);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    static const uint32_t Param_p0d_func100_016[] =
                    {
                        BSWAP_32BIG_C(0xd2ac06c1U), BSWAP_32BIG_C(0x4c24206aU), BSWAP_32BIG_C(0x6374077bU),
                        BSWAP_32BIG_C(0x874c5275U),
                    };
                    r_rsip_func100(Param_p0d_func100_016);

                    r_rsip_func_sub011(0x38000805U);

                    WR1_PROG(REG_1404H, 0x10000000U);

                    r_rsip_func_sub021(0x00003416U, 0x00026800U, 0x38008ec0U, 0x00000003U);
                    WR1_PROG(REG_1600H, 0x20002c00U);

                    r_rsip_func_sub016(0x81010000U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0]);
                    S_RAM[0] = bswap_32big(S_RAM[0]);

                    r_rsip_func_sub021(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

                    iTemp = iLoop;
                    for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
                    {
                        r_rsip_func_sub010(0x000000c7U, 0x80010100U);
                        WR1_PROG(REG_1420H, InData_CodeCertificate[iLoop]);
                        r_rsip_func_sub034(0x0000b420U, 0x00000004U);

                        for (jLoop = 0U; jLoop < 4; jLoop++)
                        {
                            r_rsip_func_sub021(0x00003020U, 0x01886ce8U, 0x00086d08U, 0x00000863U);
                            r_rsip_func_sub021(0x3c002859U, 0x20002c60U, 0x3c002b42U, 0x20002c60U);
                            r_rsip_func_sub017(0x38000c63U, 0x00260000U);

                            static const uint32_t Param_p0d_func100_017[] =
                            {
                                BSWAP_32BIG_C(0x4a1c63b4U), BSWAP_32BIG_C(0x0beaef70U), BSWAP_32BIG_C(0x69ad39f5U),
                                BSWAP_32BIG_C(0x5e224c40U),
                            };
                            r_rsip_func100(Param_p0d_func100_017);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                WR1_PROG(REG_1608H, 0x810100e0U);
                                r_rsip_func_sub001(0x1009000dU);
                                r_rsip_func_sub001(0x10c90005U);

                                static const uint32_t Param_p0d_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x60d50f52U), BSWAP_32BIG_C(0x78acbbfeU), BSWAP_32BIG_C(0x96a755cbU),
                                    BSWAP_32BIG_C(0x6affc675U),
                                };
                                r_rsip_func101(Param_p0d_func101_013);
                            }

                            r_rsip_func_sub021(0x00000863U, 0x3c002857U, 0x20002c60U, 0x3c002b02U);
                            r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                            static const uint32_t Param_p0d_func100_018[] =
                            {
                                BSWAP_32BIG_C(0x785c8fb8U), BSWAP_32BIG_C(0x38df0190U), BSWAP_32BIG_C(0x73b6248cU),
                                BSWAP_32BIG_C(0xd4e9a41eU),
                            };
                            r_rsip_func100(Param_p0d_func100_018);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                WR1_PROG(REG_1608H, 0x810100e0U);
                                r_rsip_func_sub001(0x1009000dU);
                                r_rsip_func_sub001(0x10c90005U);

                                static const uint32_t Param_p0d_func101_014[] =
                                {
                                    BSWAP_32BIG_C(0xe5ae313bU), BSWAP_32BIG_C(0xa76bda87U), BSWAP_32BIG_C(0xdd02ac49U),
                                    BSWAP_32BIG_C(0xe89c0f57U),
                                };
                                r_rsip_func101(Param_p0d_func101_014);
                            }

                            r_rsip_func_sub021(0x00000863U, 0x3c0028c2U, 0x20002c60U, 0x38000c63U);
                            WR1_PROG(REG_1608H, 0x00000080U);
                            WR1_PROG(REG_143CH, 0x00260000U);

                            static const uint32_t Param_p0d_func100_019[] =
                            {
                                BSWAP_32BIG_C(0x4ee9999cU), BSWAP_32BIG_C(0x67aafa85U), BSWAP_32BIG_C(0x77abe04cU),
                                BSWAP_32BIG_C(0x61215433U),
                            };
                            r_rsip_func100(Param_p0d_func100_019);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                WR1_PROG(REG_1608H, 0x810100e0U);
                                r_rsip_func_sub001(0x1009000dU);
                                r_rsip_func_sub001(0x12490005U);

                                static const uint32_t Param_p0d_func101_015[] =
                                {
                                    BSWAP_32BIG_C(0x48b95348U), BSWAP_32BIG_C(0x99501eceU), BSWAP_32BIG_C(0x5cf5704dU),
                                    BSWAP_32BIG_C(0x9183dad5U),
                                };
                                r_rsip_func101(Param_p0d_func101_015);
                            }

                            WR1_PROG(REG_1600H, 0x00002c40U);

                            static const uint32_t Param_p0d_func101_016[] =
                            {
                                BSWAP_32BIG_C(0x905a3193U), BSWAP_32BIG_C(0x9f559880U), BSWAP_32BIG_C(0x26b3af7dU),
                                BSWAP_32BIG_C(0x73fdc492U),
                            };
                            r_rsip_func101(Param_p0d_func101_016);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);

                        r_rsip_func_sub011(0x08000c21U);

                        WR1_PROG(REG_1600H, 0x00002ca0U);

                        static const uint32_t Param_p0d_func101_017[] =
                        {
                            BSWAP_32BIG_C(0x14057d6fU), BSWAP_32BIG_C(0x652721b8U), BSWAP_32BIG_C(0xa85c76a3U),
                            BSWAP_32BIG_C(0x24f68da2U),
                        };
                        r_rsip_func101(Param_p0d_func101_017);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub011(0x38000805U);

                    WR1_PROG(REG_1600H, 0x0000b7c0U);
                    WR1_PROG(REG_1600H, 0x00000030U);

                    r_rsip_func_sub009(0x00000d01U);

                    static const uint32_t Param_p0d_func101_018[] =
                    {
                        BSWAP_32BIG_C(0xa75c9087U), BSWAP_32BIG_C(0x7305ad89U), BSWAP_32BIG_C(0x3594223bU),
                        BSWAP_32BIG_C(0x9fd577a7U),
                    };
                    r_rsip_func101(Param_p0d_func101_018);
                    r_rsip_func083(InData_Image);

                    WR1_PROG(REG_1600H, 0x00000929U);
                    WR1_PROG(REG_1608H, 0x80880009U);
                    r_rsip_func_sub001(0x03450021U);

                    WR1_PROG(REG_2000H, 0x00000001U);

                    WR1_PROG(REG_2004H, 0x00000050U);

                    WR1_PROG(REG_2014H, 0x00000000U);
                    WR1_PROG(REG_2010H, 0x00000200U);

                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430041U);

                    WAIT_STS(REG_2030H, 4, 1);

                    WR1_PROG(REG_1600H, 0x0000b520U);
                    WR1_PROG(REG_1600H, 0x00000180U);
                    WR1_PROG(REG_1A24H, 0x08000045U);
                    WR1_PROG(REG_1608H, 0x81840009U);
                    r_rsip_func_sub001(0x00890011U);

                    WR1_PROG(REG_1A24H, 0x9c000005U);
                    r_rsip_func_sub001(0x00850011U);

                    WR1_PROG(REG_1600H, 0x0000a520U);
                    WR1_PROG(REG_1600H, 0x00000010U);
                    WR1_PROG(REG_1A24H, 0x08000045U);
                    WR1_PROG(REG_1608H, 0x81840009U);
                    r_rsip_func_sub001(0x00890011U);

                    WR1_PROG(REG_1A24H, 0x9c000005U);
                    r_rsip_func_sub001(0x00850011U);

                    static const uint32_t Param_p0d_func100_020[] =
                    {
                        BSWAP_32BIG_C(0xa8f5aaa9U), BSWAP_32BIG_C(0xf449a73bU), BSWAP_32BIG_C(0xfc6f94a8U),
                        BSWAP_32BIG_C(0x4a257a01U),
                    };
                    r_rsip_func100(Param_p0d_func100_020);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_14BCH, 0x00000020U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_VERIFICATION_FAIL;
                    }
                    else
                    {
                        r_rsip_func_sub012(0x10000000U, 0x0000b420U, 0x00000060U);
                        WR1_PROG(REG_1608H, 0x80900001U);
                        r_rsip_func_sub001(0x03430041U);

                        WR1_PROG(REG_1404H, 0x19100000U);
                        r_rsip_func_sub019(0x00000fc1U, 0x00000300U, 0x08008107U);
                        WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[0]);
                        WAIT_STS(REG_1444H, 31, 1);
                        WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[4]);
                        r_rsip_func_sub001(0x00c10021U);

                        WR1_PROG(REG_1404H, 0x19600000U);
                        WAIT_STS(REG_1444H, 31, 1);
                        WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[8]);
                        WAIT_STS(REG_1444H, 31, 1);
                        WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[12]);
                        r_rsip_func_sub001(0x00c10021U);

                        WR1_PROG(REG_1600H, 0x00000b5aU);
                        WR1_PROG(REG_1600H, 0x00000b9cU);

                        r_rsip_func_sub009(0x00000d02U);

                        static const uint32_t Param_p0d_func101_019[] =
                        {
                            BSWAP_32BIG_C(0x849a8dd6U), BSWAP_32BIG_C(0x57cfa95fU), BSWAP_32BIG_C(0xf704fa52U),
                            BSWAP_32BIG_C(0x730f42c7U),
                        };
                        r_rsip_func101(Param_p0d_func101_019);
                        r_rsip_func073(InData_DomainParam);

                        static const uint32_t Param_p0d_func100_021[] =
                        {
                            BSWAP_32BIG_C(0xd8ceef32U), BSWAP_32BIG_C(0xae87cd69U), BSWAP_32BIG_C(0x71238ff9U),
                            BSWAP_32BIG_C(0x50dab2feU),
                        };
                        r_rsip_func100(Param_p0d_func100_021);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            WR1_PROG(REG_14BCH, 0x00000020U);
                            WAIT_STS(REG_142CH, 12, 0);

                            return RSIP_RET_VERIFICATION_FAIL;
                        }
                        else
                        {
                            WR1_PROG(REG_2000H, 0x00000001U);

                            WR1_PROG(REG_2004H, 0x00000050U);

                            WR1_PROG(REG_2008H, 0x00000013U);

                            r_rsip_func_sub022(0x000037ebU, 0x0000b4e0U, 0x01522594U);

                            r_rsip_func_sub009(0x0000000dU);

                            static const uint32_t Param_p0d_func101_020[] =
                            {
                                BSWAP_32BIG_C(0x31ccd2b5U), BSWAP_32BIG_C(0x9a0c3ccaU), BSWAP_32BIG_C(0x92159829U),
                                BSWAP_32BIG_C(0x4b0628e1U),
                            };
                            r_rsip_func101(Param_p0d_func101_020);
                            r_rsip_func082();

                            r_rsip_func_sub021(0x0000357fU, 0x00000800U, 0x00003436U, 0x01836c01U);
                            r_rsip_func_sub021(0x00036c21U, 0x00000842U, 0x0000346bU, 0x01856c43U);
                            r_rsip_func_sub021(0x00056c63U, 0x0c002423U, 0x00802402U, 0x00000842U);
                            r_rsip_func_sub021(0x0c00a420U, 0x00000200U, 0x00802402U, 0x38001001U);
                            WR1_PROG(REG_1608H, 0x00000080U);
                            WR1_PROG(REG_143CH, 0x00260000U);

                            static const uint32_t Param_p0d_func100_022[] =
                            {
                                BSWAP_32BIG_C(0xcad7a6c9U), BSWAP_32BIG_C(0xaa0db3beU), BSWAP_32BIG_C(0x4324da42U),
                                BSWAP_32BIG_C(0xf18f59f8U),
                            };
                            r_rsip_func100(Param_p0d_func100_022);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000080U);

                                WR1_PROG(REG_200CH, 0x00000001U);

                                WAIT_STS(REG_2030H, 8, 0);

                                r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000000U);

                                WR1_PROG(REG_200CH, 0x00000100U);

                                WAIT_STS(REG_2030H, 4, 1);

                                static const uint32_t Param_p0d_func100_023[] =
                                {
                                    BSWAP_32BIG_C(0x603139b5U), BSWAP_32BIG_C(0xa89417f1U), BSWAP_32BIG_C(0x790476d8U),
                                    BSWAP_32BIG_C(0x0f0bdb6bU),
                                };
                                r_rsip_func100(Param_p0d_func100_023);
                                WR1_PROG(REG_1408H, 0x00004022U);
                                for (iLoop = 0U; iLoop < 8U; iLoop++)
                                {
                                    WAIT_STS(REG_1408H, 30, 1);
                                    RD1_ADDR(REG_1420H, &OutData_MAC[iLoop]);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);

                                WR1_PROG(REG_1B08H, 0x00000216U);

                                static const uint32_t Param_p0d_func102_001[] =
                                {
                                    BSWAP_32BIG_C(0xafe3512fU), BSWAP_32BIG_C(0x46c530bbU), BSWAP_32BIG_C(0xb36bf68aU),
                                    BSWAP_32BIG_C(0x3a36303bU),
                                };
                                r_rsip_func102(Param_p0d_func102_001);
                                WR1_PROG(REG_149CH, 0x00000040U);
                                WAIT_STS(REG_142CH, 12, 0);

                                return RSIP_RET_PASS;
                            }
                            else
                            {
                                static const uint32_t Param_p0d_func100_024[] =
                                {
                                    BSWAP_32BIG_C(0x49a4a29cU), BSWAP_32BIG_C(0x7f7a0b2fU), BSWAP_32BIG_C(0x01d5ff63U),
                                    BSWAP_32BIG_C(0xeed4e6b6U),
                                };
                                r_rsip_func100(Param_p0d_func100_024);
                                r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                                RD1_ADDR(REG_1420H, &S_RAM[0]);
                                S_RAM[0] = bswap_32big(S_RAM[0]);
                                WAIT_STS(REG_1408H, 30, 1);
                                RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                                S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

                                r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

                                WR1_PROG(REG_200CH, 0x00000001U);

                                static const uint32_t Param_p0d_func100_025[] =
                                {
                                    BSWAP_32BIG_C(0x1694a48bU), BSWAP_32BIG_C(0x7b0c62b6U), BSWAP_32BIG_C(0xb4a4e883U),
                                    BSWAP_32BIG_C(0xf18f2bc8U),
                                };
                                r_rsip_func100(Param_p0d_func100_025);
                                r_rsip_func_sub020(0x000003a1U, 0x08000045U);
                                WR4_PROG(REG_1420H, bswap_32big(0x8ab22685U), bswap_32big(0xbfab115bU),
                                         bswap_32big(0x841c0f17U), bswap_32big(0xa1af8aa1U));

                                r_rsip_func_sub021(0x00003416U, 0x00026800U, 0x00008c00U, 0xfffffffcU);

                                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                                RD1_ADDR(REG_1420H, &S_RAM[0]);
                                S_RAM[0] = bswap_32big(S_RAM[0]);

                                WR1_PROG(REG_1600H, 0x000008a5U);

                                WR1_PROG(REG_1824H, 0x0e0c0446U);

                                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
                                {
                                    WR1_PROG(REG_1444H, 0x000003caU);
                                    WAIT_STS(REG_1444H, 31, 1);
                                    WR4_ADDR(REG_1420H, &InData_CodeCertificate[iLoop]);

                                    WR1_PROG(REG_1600H, 0x0000a4a0U);
                                    WR1_PROG(REG_1600H, 0x00000004U);

                                    static const uint32_t Param_p0d_func101_021[] =
                                    {
                                        BSWAP_32BIG_C(0x857a8b19U), BSWAP_32BIG_C(0x708e5f33U), BSWAP_32BIG_C(
                                            0x8c891bc9U),           BSWAP_32BIG_C(0xeb160c55U),
                                    };
                                    r_rsip_func101(Param_p0d_func101_021);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                                static const uint32_t Param_p0d_func100_026[] =
                                {
                                    BSWAP_32BIG_C(0x38d2522eU), BSWAP_32BIG_C(0xf48a15bdU), BSWAP_32BIG_C(0x34aa710aU),
                                    BSWAP_32BIG_C(0x0779654bU),
                                };
                                r_rsip_func100(Param_p0d_func100_026);

                                r_rsip_func_sub011(0x38000805U);

                                r_rsip_func_sub021(0x00003416U, 0x0000a400U, 0x00000003U, 0x00026800U);

                                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                                RD1_ADDR(REG_1420H, &S_RAM[0]);
                                S_RAM[0] = bswap_32big(S_RAM[0]);

                                r_rsip_func_sub021(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

                                iTemp = iLoop;
                                for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
                                {
                                    r_rsip_func_sub010(0x000000c7U, 0x80010100U);
                                    WR1_PROG(REG_1420H, InData_CodeCertificate[iLoop]);
                                    r_rsip_func_sub034(0x0000b420U, 0x00000004U);

                                    for (jLoop = 0U; jLoop < 4; jLoop++)
                                    {
                                        r_rsip_func_sub021(0x00003020U, 0x01886ce8U, 0x00086d08U, 0x00000863U);
                                        WR1_PROG(REG_1600H, 0x3c0028c2U);
                                        r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                                        static const uint32_t Param_p0d_func100_027[] =
                                        {
                                            BSWAP_32BIG_C(0xe60b14bdU), BSWAP_32BIG_C(0x6f13d939U), BSWAP_32BIG_C(
                                                0xcd7aabaeU),           BSWAP_32BIG_C(0xdbec2381U),
                                        };
                                        r_rsip_func100(Param_p0d_func100_027);
                                        WR1_PROG(REG_143CH, 0x00400000U);

                                        if (CHCK_STS(REG_143CH, 22, 1))
                                        {
                                            WR1_PROG(REG_1608H, 0x810100e0U);
                                            r_rsip_func_sub001(0x1009000dU);
                                            r_rsip_func_sub001(0x12490005U);

                                            static const uint32_t Param_p0d_func101_022[] =
                                            {
                                                BSWAP_32BIG_C(0x7833d329U), BSWAP_32BIG_C(0xa26dd896U), BSWAP_32BIG_C(
                                                    0x64c72c74U),           BSWAP_32BIG_C(0xe5661fffU),
                                            };
                                            r_rsip_func101(Param_p0d_func101_022);
                                        }

                                        WR1_PROG(REG_1600H, 0x00002c40U);

                                        static const uint32_t Param_p0d_func101_023[] =
                                        {
                                            BSWAP_32BIG_C(0xc3da5fe8U), BSWAP_32BIG_C(0x791825d1U), BSWAP_32BIG_C(
                                                0xee894746U),           BSWAP_32BIG_C(0xe2f6c15cU),
                                        };
                                        r_rsip_func101(Param_p0d_func101_023);
                                    }

                                    WR1_PROG(REG_1458H, 0x00000000U);
                                    r_rsip_func_sub011(0x08000c21U);

                                    WR1_PROG(REG_1600H, 0x00002ca0U);

                                    static const uint32_t Param_p0d_func101_024[] =
                                    {
                                        BSWAP_32BIG_C(0x19acaf8fU), BSWAP_32BIG_C(0xf3eca56cU), BSWAP_32BIG_C(
                                            0x9e6220daU),           BSWAP_32BIG_C(0x19e9d4d5U),
                                    };
                                    r_rsip_func101(Param_p0d_func101_024);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);

                                r_rsip_func_sub011(0x38000805U);

                                WR1_PROG(REG_1404H, 0x19100000U);
                                r_rsip_func_sub001(0x11430081U);
                                WR1_PROG(REG_1404H, 0x19600000U);
                                r_rsip_func_sub001(0x11430081U);

                                WR1_PROG(REG_1600H, 0x0000b7c0U);
                                WR1_PROG(REG_1600H, 0x00000080U);

                                r_rsip_func_sub009(0x00000d02U);

                                static const uint32_t Param_p0d_func101_025[] =
                                {
                                    BSWAP_32BIG_C(0x113c5809U), BSWAP_32BIG_C(0xdc62926aU), BSWAP_32BIG_C(0x29fce78dU),
                                    BSWAP_32BIG_C(0x7463f18eU),
                                };
                                r_rsip_func101(Param_p0d_func101_025);
                                r_rsip_func083(InData_Image);

                                WR1_PROG(REG_1824H, 0x9c000005U);
                                r_rsip_func_sub023(0x0000b7e0U, 0x00000030U, 0x8184001fU);
                                r_rsip_func_sub001(0x00490011U);

                                static const uint32_t Param_p0d_func100_028[] =
                                {
                                    BSWAP_32BIG_C(0x0e89d969U), BSWAP_32BIG_C(0xe6e7310fU), BSWAP_32BIG_C(0x3b16dacfU),
                                    BSWAP_32BIG_C(0xe3213313U),
                                };
                                r_rsip_func100(Param_p0d_func100_028);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    static const uint32_t Param_p0d_func102_002[] =
                                    {
                                        BSWAP_32BIG_C(0xacefcc17U), BSWAP_32BIG_C(0x30402abfU), BSWAP_32BIG_C(
                                            0xf1f55a87U),           BSWAP_32BIG_C(0xeeb616b3U),
                                    };
                                    r_rsip_func102(Param_p0d_func102_002);
                                    WR1_PROG(REG_14BCH, 0x00000020U);
                                    WAIT_STS(REG_142CH, 12, 0);

                                    return RSIP_RET_FAIL;
                                }
                                else
                                {
                                    static const uint32_t Param_p0d_func100_029[] =
                                    {
                                        BSWAP_32BIG_C(0x79002394U), BSWAP_32BIG_C(0x009eaa27U), BSWAP_32BIG_C(
                                            0xe12a62a5U),           BSWAP_32BIG_C(0xa62435f6U),
                                    };
                                    r_rsip_func100(Param_p0d_func100_029);

                                    WR1_PROG(REG_1408H, 0x00004022U);
                                    for (iLoop = 0U; iLoop < 8U; iLoop++)
                                    {
                                        WAIT_STS(REG_1408H, 30, 1);
                                        RD1_ADDR(REG_1420H, &OutData_MAC[iLoop]);
                                    }

                                    WR1_PROG(REG_1458H, 0x00000000U);

                                    WR1_PROG(REG_1B08H, 0x00000216U);

                                    static const uint32_t Param_p0d_func102_003[] =
                                    {
                                        BSWAP_32BIG_C(0xbb26b75eU), BSWAP_32BIG_C(0xc03d559dU), BSWAP_32BIG_C(
                                            0xaecf3e41U),           BSWAP_32BIG_C(0xd57ff831U),
                                    };
                                    r_rsip_func102(Param_p0d_func102_003);
                                    WR1_PROG(REG_149CH, 0x00000040U);
                                    WAIT_STS(REG_142CH, 12, 0);

                                    return RSIP_RET_PASS;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
