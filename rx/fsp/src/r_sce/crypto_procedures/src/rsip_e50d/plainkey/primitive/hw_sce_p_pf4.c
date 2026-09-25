/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

fsp_err_t HW_SCE_GenerateEccRandomKeyIndexSub (const uint32_t InData_KeyMode[],
                                               const uint32_t InData_CurveType[],
                                               const uint32_t InData_Cmd[],
                                               const uint32_t InData_DomainParam[],
                                               uint32_t       OutData_PubKey[],
                                               uint32_t       OutData_PrivKeyIndex[],
                                               uint32_t       OutData_PrivKey[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00f40001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x3020ab80U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1600H, 0x00060020U);
    WR1_PROG(REG_1600H, 0x0000b780U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WR1_PROG(REG_1600H, 0x00000bffU);

    WR1_PROG(REG_1600H, 0x30000f5aU);
    WR1_PROG(REG_1600H, 0x00030020U);
    WR1_PROG(REG_1600H, 0x0000d3e1U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1600H, 0x38000f9cU);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WR1_PROG(REG_1600H, 0x38008be0U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    HW_SCE_p_func100(0x06d73510U, 0x31d9822aU, 0x88c037aaU, 0x785c4776U);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        HW_SCE_p_func102(0x387e759aU, 0xae8a985eU, 0xbafce6edU, 0xc6e01753U);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return FSP_ERR_CRYPTO_SCE_FAIL;
    }
    else
    {
        HW_SCE_p_func100(0xc7b796f5U, 0x984d9984U, 0x383b5ae7U, 0x0a2fd802U);
        HW_SCE_p_func070(InData_DomainParam);
        HW_SCE_p_func100(0x8b5c32c4U, 0xcf44af32U, 0x4ea3f778U, 0xb3bb9298U);

        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_101CH, 0x000000c0U);

        WR1_PROG(REG_1004H, 0x04040010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_101CH, 0x00000070U);

        WR1_PROG(REG_1004H, 0x04040010U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_1404H, 0x12c80000U);

        WR1_PROG(REG_1600H, 0x00007c1cU);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            HW_SCE_p_func100(0x52759785U, 0xb7d091fdU, 0xe292ecefU, 0x312b28efU);
            WR1_PROG(REG_1400H, 0x00c00009U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            HW_SCE_p_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000000U));
            WR1_PROG(REG_1400H, 0x00c20009U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x00020009U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0x121460fcU, 0x6072b7cbU, 0x5f379f7eU, 0xd4318a7dU);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            HW_SCE_p_func100(0xf2475a40U, 0x9142b5aaU, 0x45e2e3adU, 0xaf0737f3U);
            WR1_PROG(REG_1400H, 0x00c0000dU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, change_endian_long(0x00000000U));
            WR1_PROG(REG_1400H, 0x00c20005U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);
            WR1_PROG(REG_1400H, 0x0002000dU);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0xa86245f5U, 0xa8311d2cU, 0xc477f363U, 0x3fb4b5e0U);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1400H, 0x00c00011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            HW_SCE_p_func101(0x72360511U, 0xbc50c154U, 0xa5de7a13U, 0xb7260185U);
        }

        HW_SCE_p_func100(0x4ef461b6U, 0xfc146df5U, 0x09ac4a5aU, 0x0fa10d59U);
        HW_SCE_p_func103();
        HW_SCE_p_func100(0xadbc84bfU, 0x35a81762U, 0x09bc328dU, 0xb134c16bU);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));
        WR1_PROG(REG_1400H, 0x00c20011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

        WR1_PROG(REG_1400H, 0x00c20011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0001dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x000000c0U);
        WR1_PROG(REG_1018H, 0x00000110U);
        WR1_PROG(REG_1020H, 0x000001b0U);

        WR1_PROG(REG_1004H, 0x0404000aU);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x11380000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0001dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c00009U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_1018H, 0x00000160U);
        WR1_PROG(REG_1020H, 0x00000250U);

        WR1_PROG(REG_1004H, 0x04040007U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        HW_SCE_p_func100(0x119436bdU, 0xc8a3ac9fU, 0xae9f419dU, 0x4a390a09U);
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1600H, 0x00000863U);

        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x808a0001U);
        WR1_PROG(REG_1400H, 0x03430029U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        for (iLoop = 0U; iLoop < 10U; iLoop++)
        {
            WR1_PROG(REG_1600H, 0x38000c63U);
            WR1_PROG(REG_1600H, 0x20000842U);
            WR1_PROG(REG_1600H, 0x10003841U);

            WR1_PROG(REG_1600H, 0x0000b7c0U);
            WR1_PROG(REG_1600H, 0x0000001fU);

            for (jLoop = 0U; jLoop < 32U; jLoop++)
            {
                WR1_PROG(REG_1600H, 0x3800585eU);
                WR1_PROG(REG_1600H, 0x20003460U);
                WR1_PROG(REG_1600H, 0x20002c60U);
                WR1_PROG(REG_1600H, 0x10002c00U);
                WR1_PROG(REG_1600H, 0x100033c0U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a420U);
            WR1_PROG(REG_1600H, 0x00000004U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x14580000U);
        WR1_PROG(REG_1400H, 0x00c00029U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x00000250U);
        WR1_PROG(REG_1018H, 0x00000480U);
        WR1_PROG(REG_1020H, 0x000001b0U);

        WR1_PROG(REG_1004H, 0x05050009U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x10e80000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000002U));
        WR1_PROG(REG_1400H, 0x00c00025U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1600H, 0x00003403U);

        WR1_PROG(REG_1600H, 0x00003060U);

        WR1_PROG(REG_1608H, 0x81010060U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = change_endian_long(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1014H, 0x000001b0U);
            WR1_PROG(REG_1018H, 0x00000110U);
            WR1_PROG(REG_1020H, 0x00000250U);

            WR1_PROG(REG_1004H, 0x05050007U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x00000480U);
            WR1_PROG(REG_1020H, 0x000001b0U);

            WR1_PROG(REG_1004H, 0x05050009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00003060U);

            HW_SCE_p_func101(0x62c8d0c3U, 0x58e23f94U, 0xb2305437U, 0xbec60135U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00007c03U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x10e80000U);
        WR1_PROG(REG_1400H, 0x00c00029U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        HW_SCE_p_func100(0x5881d6efU, 0x29dfbe59U, 0x4b5d1887U, 0x940a6177U);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1600H, 0x00000040U);

        WR1_PROG(REG_1608H, 0x81010000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = change_endian_long(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1014H, 0x000002f0U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_1020H, 0x00000250U);

            WR1_PROG(REG_1004H, 0x0505000aU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_143CH, 0x00a10000U);

            HW_SCE_p_func100(0xfa63dafdU, 0x0de0359dU, 0xc44eaa69U, 0x8623faaaU);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000110U);
                WR1_PROG(REG_1020H, 0x000002f0U);

                WR1_PROG(REG_1004H, 0x05050009U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                HW_SCE_p_func101(0x75758c5eU, 0xb08b12adU, 0xb466dc68U, 0xfbeefa6cU);
            }

            WR1_PROG(REG_1014H, 0x000001b0U);
            WR1_PROG(REG_1020H, 0x00000250U);

            WR1_PROG(REG_1004H, 0x0505000cU);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x00000110U);
            WR1_PROG(REG_1020H, 0x000001b0U);

            WR1_PROG(REG_1004H, 0x05050009U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_1600H, 0x00003000U);

            HW_SCE_p_func101(0x7781ac87U, 0xf9946c5eU, 0x824de91dU, 0xd4c09b9dU);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00007c00U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x00000001U));
        WR1_PROG(REG_1400H, 0x00c0001dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x00c20005U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1400H, 0x0002000dU);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);

        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_1018H, 0x00000110U);
        WR1_PROG(REG_1020H, 0x00000340U);

        WR1_PROG(REG_1004H, 0x04040009U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        HW_SCE_p_func100(0x99b5d080U, 0x9d095068U, 0x2f658818U, 0x51893ca7U);
        HW_SCE_p_func071(InData_DomainParam);

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x800103a0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, change_endian_long(0x000000f4U));
        WR1_PROG(REG_1458H, 0x00000000U);

        HW_SCE_p_func101(0xf9c49cddU, 0x77f9915aU, 0xd049a652U, 0x183a90e7U);
        HW_SCE_p_func088();

        HW_SCE_p_func100(0x1c3a9648U, 0x793be4c0U, 0xb956da6dU, 0x71cbc875U);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            HW_SCE_p_func102(0x2f8cb67eU, 0x48b08c2fU, 0x9d7ce28aU, 0xd779aa88U);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_ERR_CRYPTO_SCE_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x800103e0U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_KeyMode[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x38000fffU);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);

            HW_SCE_p_func100(0xdda45600U, 0x10969487U, 0xc4530738U, 0x5005d9e8U);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                HW_SCE_p_func100(0xd41bb2d0U, 0x3aea83bbU, 0x4a07ebc7U, 0xeb5ef1d4U);
                HW_SCE_p_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

                WR1_PROG(REG_1608H, 0x80010000U);
                WR1_PROG(REG_1400H, 0x03420005U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);
                WR1_PROG(REG_1400H, 0x0002000dU);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1600H, 0x000034e0U);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x000000f4U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0xae7727f9U, 0x8a6638a5U, 0x1fe3ae4cU, 0xbecb0e8aU);
                HW_SCE_p_func043();

                HW_SCE_p_func074();

                WR1_PROG(REG_1600H, 0x000034feU);

                WR1_PROG(REG_1444H, 0x000000a7U);
                WR1_PROG(REG_1608H, 0x800103a0U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x000000f4U));
                WR1_PROG(REG_1458H, 0x00000000U);

                HW_SCE_p_func101(0x4d8f95d6U, 0x0df55f45U, 0x397ec782U, 0x24dbf540U);
                HW_SCE_p_func044();

                HW_SCE_p_func100(0xef425376U, 0x70f0f8bdU, 0x97127ac9U, 0x44a83e69U);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x13200000U);
                WR1_PROG(REG_1400H, 0x00830021U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);

                HW_SCE_p_func100(0x7a2fea3eU, 0xd62ab980U, 0xcb9bba83U, 0x01e1de9eU);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c000104U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                WR1_PROG(REG_1400H, 0x00820011U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);

                HW_SCE_p_func100(0x8d3e25c1U, 0xd54c7a95U, 0x42bb4014U, 0x0ee9678eU);
                WR1_PROG(REG_1608H, 0x81010000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

                HW_SCE_p_func101(0x45ac32b4U, 0x864009c5U, 0x121e54bcU, 0x4e8fd55fU);
            }
            else
            {
                HW_SCE_p_func100(0xf745eacfU, 0xb6bb5d95U, 0x4ff3cf8fU, 0x8ddd4bfaU);
                WR1_PROG(REG_1404H, 0x13200000U);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                WR1_PROG(REG_1400H, 0x00830021U);
                WAIT_STS(REG_1404H, 30, 0);
                WR1_PROG(REG_143CH, 0x00001800U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_PrivKey[0]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_PrivKey[4]);

                HW_SCE_p_func101(0x789530fdU, 0xd22fc10cU, 0xedee0dcaU, 0x6a616e72U);
            }

            HW_SCE_p_func100(0x361bc39fU, 0x9eb09bb0U, 0x59381287U, 0x2268c55eU);
            WR1_PROG(REG_1404H, 0x12800000U);
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WR1_PROG(REG_1400H, 0x00830021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKey[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKey[4]);

            HW_SCE_p_func100(0xaeea5137U, 0x4fadf137U, 0x7405f7c9U, 0x3fe1ead2U);
            WR1_PROG(REG_1404H, 0x12d00000U);
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WR1_PROG(REG_1400H, 0x00830021U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKey[8]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKey[12]);

            HW_SCE_p_func102(0x00cf60c4U, 0x823afc75U, 0xd01a7cf1U, 0xe2775bb1U);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return FSP_SUCCESS;
        }
    }
}
