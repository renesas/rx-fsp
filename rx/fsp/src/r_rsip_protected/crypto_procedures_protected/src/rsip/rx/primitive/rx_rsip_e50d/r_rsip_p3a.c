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

rsip_ret_t r_rsip_p3a (const uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;
    uint32_t kLoop   = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x003a0001U, 0x00000e50U);

    WR1_PROG(REG_1600H, 0x00000a31U);
    for (kLoop = 0U; kLoop < MAX_CNT; kLoop++)
    {
        WR1_PROG(REG_1444H, 0x00002fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_0160H, bswap_32big(0x00030005U));
        WR1_PROG(REG_0164H, bswap_32big(0x0007000bU));
        WR1_PROG(REG_0168H, bswap_32big(0x000d0011U));
        WR1_PROG(REG_016CH, bswap_32big(0x00130017U));
        WR1_PROG(REG_0170H, bswap_32big(0x001d001fU));
        WR1_PROG(REG_0174H, bswap_32big(0x00250029U));
        WR1_PROG(REG_0178H, bswap_32big(0x002b002fU));
        WR1_PROG(REG_017CH, bswap_32big(0x003b003dU));
        WR1_PROG(REG_0180H, bswap_32big(0x00430047U));
        WR1_PROG(REG_0184H, bswap_32big(0x0049004fU));
        WR1_PROG(REG_0188H, bswap_32big(0x00530059U));
        WR1_PROG(REG_018CH, bswap_32big(0x00610065U));
        WR1_PROG(REG_0190H, bswap_32big(0x0067006bU));
        WR1_PROG(REG_0194H, bswap_32big(0x006d0071U));
        WR1_PROG(REG_0198H, bswap_32big(0x007f0083U));
        WR1_PROG(REG_019CH, bswap_32big(0x0089008bU));
        WR1_PROG(REG_01A0H, bswap_32big(0x00950097U));
        WR1_PROG(REG_01A4H, bswap_32big(0x009d00a3U));
        WR1_PROG(REG_01A8H, bswap_32big(0x00a700adU));
        WR1_PROG(REG_01ACH, bswap_32big(0x00b300b5U));
        WR1_PROG(REG_01B0H, bswap_32big(0x00bf00c1U));
        WR1_PROG(REG_01B4H, bswap_32big(0x00c500c7U));
        WR1_PROG(REG_01B8H, bswap_32big(0x00d300dfU));
        WR1_PROG(REG_01BCH, bswap_32big(0x00e300e5U));
        WR1_PROG(REG_01C0H, bswap_32big(0x00e900efU));
        WR1_PROG(REG_01C4H, bswap_32big(0x00f100fbU));
        WR1_PROG(REG_01C8H, bswap_32big(0x01010107U));
        WR1_PROG(REG_01CCH, bswap_32big(0x010d010fU));
        WR1_PROG(REG_01D0H, bswap_32big(0x01150119U));
        WR1_PROG(REG_01D4H, bswap_32big(0x011b0125U));
        WR1_PROG(REG_01D8H, bswap_32big(0x01330137U));
        WR1_PROG(REG_01DCH, bswap_32big(0x0139013dU));
        WR1_PROG(REG_01E0H, bswap_32big(0x014b0151U));
        WR1_PROG(REG_01E4H, bswap_32big(0x015b015dU));
        WR1_PROG(REG_01E8H, bswap_32big(0x01610167U));
        WR1_PROG(REG_01ECH, bswap_32big(0x016f0175U));
        WR1_PROG(REG_01F0H, bswap_32big(0x017b017fU));
        WR1_PROG(REG_01F4H, bswap_32big(0x0185018dU));
        WR1_PROG(REG_01F8H, bswap_32big(0x01910199U));
        WR1_PROG(REG_01FCH, bswap_32big(0x01a301a5U));
        WR1_PROG(REG_0200H, bswap_32big(0x01af01b1U));
        WR1_PROG(REG_0204H, bswap_32big(0x01b701bbU));
        WR1_PROG(REG_0208H, bswap_32big(0x01c101c9U));
        WR1_PROG(REG_020CH, bswap_32big(0x01cd01cfU));
        WR1_PROG(REG_0210H, bswap_32big(0x01d301dfU));
        WR1_PROG(REG_0214H, bswap_32big(0x01e701ebU));
        WR1_PROG(REG_0218H, bswap_32big(0x01f301f7U));
        WR1_PROG(REG_021CH, bswap_32big(0x01fd0000U));

        r_rsip_func_sub023(0x0000b4c0U, 0x000000c0U, 0x80b00006U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x034300c1U);

        r_rsip_func_sub009(0x00003a01U);

        static const uint32_t Param_p3a_func101_001[] =
        {
            BSWAP_32BIG_C(0x0c32c5ecU), BSWAP_32BIG_C(0x662fc576U), BSWAP_32BIG_C(0xa8b6be18U), BSWAP_32BIG_C(
                0xd723e76dU),
        };
        r_rsip_func101(Param_p3a_func101_001);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x00c90011U);

        r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000028U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 40U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            r_rsip_func_sub014(0x00007c07U, 0x00602000U);

            r_rsip_func_sub009(0x00003a02U);

            static const uint32_t Param_p3a_func101_002[] =
            {
                BSWAP_32BIG_C(0xc7266edbU), BSWAP_32BIG_C(0x5475e8e2U), BSWAP_32BIG_C(0x7e6f973dU), BSWAP_32BIG_C(
                    0x791e3a71U),
            };
            r_rsip_func101(Param_p3a_func101_002);
            r_rsip_func113();

            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            r_rsip_func_sub001(0x00c20011U);

            WR1_PROG(REG_1600H, 0x00002485U);

            static const uint32_t Param_p3a_func101_003[] =
            {
                BSWAP_32BIG_C(0x6f4f2106U), BSWAP_32BIG_C(0x2dcc7575U), BSWAP_32BIG_C(0xdcb637f2U), BSWAP_32BIG_C(
                    0x8e276a0eU),
            };
            r_rsip_func101(Param_p3a_func101_003);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x38000886U);

        r_rsip_func_sub009(0x00003a03U);

        static const uint32_t Param_p3a_func101_004[] =
        {
            BSWAP_32BIG_C(0x93119bd0U), BSWAP_32BIG_C(0x4febe613U), BSWAP_32BIG_C(0x302662f1U), BSWAP_32BIG_C(
                0x7d16699cU),
        };
        r_rsip_func101(Param_p3a_func101_004);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1608H, 0x81040000U);
        r_rsip_func_sub001(0x00c90011U);

        WR1_PROG(REG_1444H, 0x00002fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_0980H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0984H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0988H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_098CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0990H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0994H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0998H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_099CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09A0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09A4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09A8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09ACH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09B0H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09B4H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09B8H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09BCH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09C0H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09C4H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09C8H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09CCH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09D0H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09D4H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09D8H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09DCH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09E0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09E4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09E8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09ECH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09F0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09F4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09F8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09FCH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A00H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A04H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A08H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A0CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A10H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A14H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A18H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A1CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A20H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A24H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A28H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A2CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A30H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A34H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A38H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A3CH, bswap_32big(0x51EB851EU));

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x1818000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3a_func100_001[] =
        {
            BSWAP_32BIG_C(0xd5e2e809U), BSWAP_32BIG_C(0x7f98ae81U), BSWAP_32BIG_C(0x0ff690e9U), BSWAP_32BIG_C(
                0xd905ad01U),
        };
        r_rsip_func100(Param_p3a_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3a_func101_005[] =
            {
                BSWAP_32BIG_C(0x146439e6U), BSWAP_32BIG_C(0x4e51ea19U), BSWAP_32BIG_C(0x85817a7dU), BSWAP_32BIG_C(
                    0x8d88263eU),
            };
            r_rsip_func101(Param_p3a_func101_005);
            continue;
        }
        else
        {
            static const uint32_t Param_p3a_func101_006[] =
            {
                BSWAP_32BIG_C(0xab04a8e8U), BSWAP_32BIG_C(0xf56b4948U), BSWAP_32BIG_C(0x50a3ffacU), BSWAP_32BIG_C(
                    0x8c4116feU),
            };
            r_rsip_func101(Param_p3a_func101_006);
        }

        r_rsip_func_sub006(0x38008a20U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3a_func100_002[] =
        {
            BSWAP_32BIG_C(0x2ae4cd2dU), BSWAP_32BIG_C(0x7f0c60e1U), BSWAP_32BIG_C(0x5693efabU), BSWAP_32BIG_C(
                0x60e5c308U),
        };
        r_rsip_func100(Param_p3a_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000320U, 0x00000220U, 0x00000630U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_003[] =
            {
                BSWAP_32BIG_C(0xae430d40U), BSWAP_32BIG_C(0x6c718d7bU), BSWAP_32BIG_C(0x377a3a04U), BSWAP_32BIG_C(
                    0x9e3e87e9U),
            };
            r_rsip_func100(Param_p3a_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000220U, 0x00000320U, 0x00000630U, 0x1818000aU);

                static const uint32_t Param_p3a_func101_007[] =
                {
                    BSWAP_32BIG_C(0x6246a085U), BSWAP_32BIG_C(0xf47ba313U), BSWAP_32BIG_C(0x5cfd976eU), BSWAP_32BIG_C(
                        0x7e54e0eeU),
                };
                r_rsip_func101(Param_p3a_func101_007);
            }
            else
            {
                static const uint32_t Param_p3a_func101_008[] =
                {
                    BSWAP_32BIG_C(0x0733cc51U), BSWAP_32BIG_C(0x12f97541U), BSWAP_32BIG_C(0xabfb8e7cU), BSWAP_32BIG_C(
                        0xba5e8d00U),
                };
                r_rsip_func101(Param_p3a_func101_008);
            }

            WR1_PROG(REG_1404H, 0x19800000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x10000000U));
            r_rsip_func_sub001(0x00c20011U);
            r_rsip_func_sub001(0x00c000b1U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_004[] =
            {
                BSWAP_32BIG_C(0x14013bb0U), BSWAP_32BIG_C(0x3021bf0aU), BSWAP_32BIG_C(0xb53aa513U), BSWAP_32BIG_C(
                    0x9be98ee5U),
            };
            r_rsip_func100(Param_p3a_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3a_func101_009[] =
                {
                    BSWAP_32BIG_C(0x75170c57U), BSWAP_32BIG_C(0xca5e7a93U), BSWAP_32BIG_C(0x1f30c5ceU), BSWAP_32BIG_C(
                        0x47a20f9bU),
                };
                r_rsip_func101(Param_p3a_func101_009);
                continue;
            }
            else
            {
                static const uint32_t Param_p3a_func101_010[] =
                {
                    BSWAP_32BIG_C(0xaab7ffb3U), BSWAP_32BIG_C(0xcc185b70U), BSWAP_32BIG_C(0x61690e3aU), BSWAP_32BIG_C(
                        0xdde3ecefU),
                };
                r_rsip_func101(Param_p3a_func101_010);
            }
        }
        else
        {
            static const uint32_t Param_p3a_func101_011[] =
            {
                BSWAP_32BIG_C(0xa27b0c95U), BSWAP_32BIG_C(0xc2b5df0fU), BSWAP_32BIG_C(0x4d8d21c4U), BSWAP_32BIG_C(
                    0xe68bafacU),
            };
            r_rsip_func101(Param_p3a_func101_011);
        }

        r_rsip_func_sub022(0x0000b4c0U, 0x000000c0U, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            r_rsip_func_sub022(0x01003906U, 0x00002cc0U, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x15700000U);
            r_rsip_func_sub001(0x00c000bdU);
            r_rsip_func_sub001(0x00c90005U);

            r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x18180010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x18180004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c000bdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_005[] =
            {
                BSWAP_32BIG_C(0x74252bacU), BSWAP_32BIG_C(0xf928f5dfU), BSWAP_32BIG_C(0xd95911caU), BSWAP_32BIG_C(
                    0x100c2259U),
            };
            r_rsip_func100(Param_p3a_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                static const uint32_t Param_p3a_func101_012[] =
                {
                    BSWAP_32BIG_C(0xad10c169U), BSWAP_32BIG_C(0x45f5497dU), BSWAP_32BIG_C(0xc8244724U), BSWAP_32BIG_C(
                        0xbe04ee6eU),
                };
                r_rsip_func101(Param_p3a_func101_012);
                break;
            }
            else
            {
                static const uint32_t Param_p3a_func101_013[] =
                {
                    BSWAP_32BIG_C(0x041e229dU), BSWAP_32BIG_C(0x570be028U), BSWAP_32BIG_C(0xe6a60946U), BSWAP_32BIG_C(
                        0x4c30f84bU),
                };
                r_rsip_func101(Param_p3a_func101_013);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        r_rsip_func_sub006(0x38008940U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3a_func100_006[] =
        {
            BSWAP_32BIG_C(0x14a44f36U), BSWAP_32BIG_C(0xf66f9331U), BSWAP_32BIG_C(0x72a26375U), BSWAP_32BIG_C(
                0x79c19196U),
        };
        r_rsip_func100(Param_p3a_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3a_func101_014[] =
            {
                BSWAP_32BIG_C(0x658603efU), BSWAP_32BIG_C(0x891867f1U), BSWAP_32BIG_C(0xc3592eb3U), BSWAP_32BIG_C(
                    0x4f6aea02U),
            };
            r_rsip_func101(Param_p3a_func101_014);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18780000U);
        r_rsip_func_sub001(0x00c000c1U);

        r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000428U, 0x18180009U);

        r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1818000aU);

        WR1_PROG(REG_1404H, 0x15700000U);
        r_rsip_func_sub004(0x08000104U, 0x00010001U);
        r_rsip_func_sub001(0x00c000bdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x18180010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        r_rsip_func_sub005(0x00000838U, 0x18180004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000bdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1818000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3a_func100_007[] =
        {
            BSWAP_32BIG_C(0x405baf1dU), BSWAP_32BIG_C(0x1cc36bb2U), BSWAP_32BIG_C(0xf6c9ae76U), BSWAP_32BIG_C(
                0xa3d4be37U),
        };
        r_rsip_func100(Param_p3a_func100_007);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3a_func101_015[] =
            {
                BSWAP_32BIG_C(0x6517c553U), BSWAP_32BIG_C(0xde3f0745U), BSWAP_32BIG_C(0x9963335eU), BSWAP_32BIG_C(
                    0x04f090beU),
            };
            r_rsip_func101(Param_p3a_func101_015);
        }
        else
        {
            static const uint32_t Param_p3a_func100_008[] =
            {
                BSWAP_32BIG_C(0x231c1eaaU), BSWAP_32BIG_C(0x624dda80U), BSWAP_32BIG_C(0xc45b5190U), BSWAP_32BIG_C(
                    0xf0b21db6U),
            };
            r_rsip_func100(Param_p3a_func100_008);
            WR1_PROG(REG_1404H, 0x17780000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c000bdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub018(0x00000018U, 0x00000428U, 0x18180010U);

            r_rsip_func_sub013(0x00000838U, 0x00000220U, 0x00000428U, 0x00000630U, 0x18180000U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000838U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_009[] =
            {
                BSWAP_32BIG_C(0x67eb3337U), BSWAP_32BIG_C(0xfa792850U), BSWAP_32BIG_C(0xa3576fd6U), BSWAP_32BIG_C(
                    0x7423176eU),
            };
            r_rsip_func100(Param_p3a_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3a_func101_016[] =
                {
                    BSWAP_32BIG_C(0x9ac0e4e0U), BSWAP_32BIG_C(0x4cea8666U), BSWAP_32BIG_C(0x71605abdU), BSWAP_32BIG_C(
                        0xaaa79c6eU),
                };
                r_rsip_func101(Param_p3a_func101_016);
                continue;
            }

            static const uint32_t Param_p3a_func100_010[] =
            {
                BSWAP_32BIG_C(0x6edda0f1U), BSWAP_32BIG_C(0x4505d488U), BSWAP_32BIG_C(0xb8ae90a3U), BSWAP_32BIG_C(
                    0x040b24b9U),
            };
            r_rsip_func100(Param_p3a_func100_010);

            r_rsip_func_sub022(0x0000b560U, 0x00000002U, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80b0000aU);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x034300c1U);

            r_rsip_func_sub021(0x00000929U, 0x00000908U, 0x0000b4c0U, 0x000000bcU);

            for (iLoop = 0U; iLoop < 48U; iLoop++)
            {
                r_rsip_func_sub022(0x000038e6U, 0x0000a8c0U, 0x00000004U);
                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x38008900U, 0x00000000U, 0x11816907U, 0x38008900U);
                    r_rsip_func_sub022(0x00000000U, 0x10002d20U, 0x000168e7U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub016(0x81010120U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WR1_PROG(REG_1600H, 0x000037e9U);

            r_rsip_func_sub030(0x15700000U, 0x0000094aU, 0x81b0000aU);
            r_rsip_func_sub001(0x00c900c1U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                r_rsip_func_sub005(0x00000838U, 0x1818000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000838U, 0x00000938U, 0x00000630U, 0x18180009U);

                WR1_PROG(REG_1600H, 0x000033e0U);

                static const uint32_t Param_p3a_func101_017[] =
                {
                    BSWAP_32BIG_C(0x8ced874fU), BSWAP_32BIG_C(0x6d938562U), BSWAP_32BIG_C(0x55f9f06dU), BSWAP_32BIG_C(
                        0x9ff54712U),
                };
                r_rsip_func101(Param_p3a_func101_017);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub014(0x00007c1fU, 0x00602000U);

            static const uint32_t Param_p3a_func100_011[] =
            {
                BSWAP_32BIG_C(0x4a7e989fU), BSWAP_32BIG_C(0x7aaa277aU), BSWAP_32BIG_C(0x2989b0d9U), BSWAP_32BIG_C(
                    0x8487221fU),
            };
            r_rsip_func100(Param_p3a_func100_011);
            WR1_PROG(REG_1600H, 0x00000a52U);

            r_rsip_func_sub016(0x81010160U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
                r_rsip_func_sub031(0x00000030U, 0x000008e7U, 0x11600000U);
                for (jLoop = 0U; jLoop < 48U; jLoop = jLoop + 4U)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    r_rsip_func_sub014(0x00007c07U, 0x00602000U);

                    r_rsip_func_sub009(0x00003a04U);

                    static const uint32_t Param_p3a_func101_018[] =
                    {
                        BSWAP_32BIG_C(0x92b7859eU), BSWAP_32BIG_C(0x6bec6478U), BSWAP_32BIG_C(0xf4d787b7U),
                        BSWAP_32BIG_C(0x0d719e39U),
                    };
                    r_rsip_func101(Param_p3a_func101_018);
                    r_rsip_func113();

                    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                    r_rsip_func_sub001(0x00c20011U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    static const uint32_t Param_p3a_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x76361a77U), BSWAP_32BIG_C(0x1ef2f92aU), BSWAP_32BIG_C(0x066b473fU),
                        BSWAP_32BIG_C(0x9124fb6aU),
                    };
                    r_rsip_func101(Param_p3a_func101_019);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000886U);

                static const uint32_t Param_p3a_func100_012[] =
                {
                    BSWAP_32BIG_C(0x9b8e8384U), BSWAP_32BIG_C(0x7ba2d1d2U), BSWAP_32BIG_C(0xeee6a2e6U), BSWAP_32BIG_C(
                        0x3693e9caU),
                };
                r_rsip_func100(Param_p3a_func100_012);
                WR1_PROG(REG_1404H, 0x19800000U);
                r_rsip_func_sub004(0x08000104U, 0x00000004U);
                r_rsip_func_sub001(0x00c000bdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x1818000aU);

                r_rsip_func_sub018(0x00000018U, 0x00000838U, 0x18180010U);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x18180004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17780000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c000bdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x18180009U);

                r_rsip_func_sub018(0x00000018U, 0x00000428U, 0x18180010U);

                r_rsip_func_sub013(0x00000220U, 0x00000630U, 0x00000428U, 0x00000838U, 0x18180000U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x19800000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c000bdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1818000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1818000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p3a_func100_013[] =
                {
                    BSWAP_32BIG_C(0xa8a3ece5U), BSWAP_32BIG_C(0x2d6309dcU), BSWAP_32BIG_C(0xba2ae8cdU), BSWAP_32BIG_C(
                        0x57700d73U),
                };
                r_rsip_func100(Param_p3a_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    static const uint32_t Param_p3a_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x532118d2U), BSWAP_32BIG_C(0x9fb07a3fU), BSWAP_32BIG_C(0x67e91072U),
                        BSWAP_32BIG_C(0xcd430eebU),
                    };
                    r_rsip_func101(Param_p3a_func101_020);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    static const uint32_t Param_p3a_func100_014[] =
                    {
                        BSWAP_32BIG_C(0x7ce23150U), BSWAP_32BIG_C(0x0737d7d3U), BSWAP_32BIG_C(0x887f6e52U),
                        BSWAP_32BIG_C(0x354122beU),
                    };
                    r_rsip_func100(Param_p3a_func100_014);
                    r_rsip_func_sub016(0x81010120U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19800000U);
                        WR1_PROG(REG_1608H, 0x81b0000aU);
                        r_rsip_func_sub001(0x00c900c1U);

                        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1818000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1818000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        static const uint32_t Param_p3a_func100_015[] =
                        {
                            BSWAP_32BIG_C(0x13b2de9bU), BSWAP_32BIG_C(0xcfe197cfU), BSWAP_32BIG_C(0xcaab345dU),
                            BSWAP_32BIG_C(0xf8867043U),
                        };
                        r_rsip_func100(Param_p3a_func100_015);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            static const uint32_t Param_p3a_func101_021[] =
                            {
                                BSWAP_32BIG_C(0x53dbe530U), BSWAP_32BIG_C(0xdb7d6f19U), BSWAP_32BIG_C(0xf54494beU),
                                BSWAP_32BIG_C(0x274d2d27U),
                            };
                            r_rsip_func101(Param_p3a_func101_021);
                            break;
                        }
                        else
                        {
                            static const uint32_t Param_p3a_func100_016[] =
                            {
                                BSWAP_32BIG_C(0x5c3d9253U), BSWAP_32BIG_C(0x005315adU), BSWAP_32BIG_C(0xec197ad3U),
                                BSWAP_32BIG_C(0xe01c0d80U),
                            };
                            r_rsip_func100(Param_p3a_func100_016);
                            WR1_PROG(REG_1404H, 0x19800000U);
                            r_rsip_func_sub004(0x08000104U, 0x00000002U);
                            r_rsip_func_sub001(0x00c000bdU);
                            r_rsip_func_sub001(0x00c20005U);
                            r_rsip_func_sub001(0x0002000dU);

                            r_rsip_func_sub013(0x00000838U,
                                               0x00000a40U,
                                               0x00000428U,
                                               0x00000220U,
                                               0x18180000U,
                                               0x00010001U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000838U, 0x18180009U);

                            static const uint32_t Param_p3a_func101_022[] =
                            {
                                BSWAP_32BIG_C(0x1ec67400U), BSWAP_32BIG_C(0x0204047bU), BSWAP_32BIG_C(0xd10dd15dU),
                                BSWAP_32BIG_C(0xdfe8390aU),
                            };
                            r_rsip_func101(Param_p3a_func101_022);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub006(0x38008a40U, 0x00000000U, 0x00260000U);

                    static const uint32_t Param_p3a_func100_017[] =
                    {
                        BSWAP_32BIG_C(0xfb858b6eU), BSWAP_32BIG_C(0xfb3a4528U), BSWAP_32BIG_C(0xb14abb98U),
                        BSWAP_32BIG_C(0x375c73b4U),
                    };
                    r_rsip_func100(Param_p3a_func100_017);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p3a_func101_023[] =
                        {
                            BSWAP_32BIG_C(0xbedb2bd3U), BSWAP_32BIG_C(0xe6e50b8dU), BSWAP_32BIG_C(0x9878a656U),
                            BSWAP_32BIG_C(0x2b356f4fU),
                        };
                        r_rsip_func101(Param_p3a_func101_023);
                        break;
                    }
                    else
                    {
                        static const uint32_t Param_p3a_func101_024[] =
                        {
                            BSWAP_32BIG_C(0x0ae80244U), BSWAP_32BIG_C(0xa49fcd08U), BSWAP_32BIG_C(0x536441e5U),
                            BSWAP_32BIG_C(0xf313063eU),
                        };
                        r_rsip_func101(Param_p3a_func101_024);
                    }
                }
            }

            r_rsip_func_sub017(0x38000a4bU, 0x00260000U);

            static const uint32_t Param_p3a_func100_018[] =
            {
                BSWAP_32BIG_C(0x6cfd3939U), BSWAP_32BIG_C(0x325a160fU), BSWAP_32BIG_C(0x7fa0b417U), BSWAP_32BIG_C(
                    0x363a31f2U),
            };
            r_rsip_func100(Param_p3a_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_p3a_func100_019[] =
                {
                    BSWAP_32BIG_C(0x5910ead4U), BSWAP_32BIG_C(0x85a1f289U), BSWAP_32BIG_C(0x44369134U), BSWAP_32BIG_C(
                        0xfa614305U),
                };
                r_rsip_func100(Param_p3a_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p3a_func101_025[] =
                    {
                        BSWAP_32BIG_C(0xb2e5cef2U), BSWAP_32BIG_C(0xabfdecb5U), BSWAP_32BIG_C(0xbb523d15U),
                        BSWAP_32BIG_C(0x81abe8eaU),
                    };
                    r_rsip_func101(Param_p3a_func101_025);
                    break;
                }
                else
                {
                    r_rsip_func_sub002(0x00000428U, 0x00000938U, 0x00000320U, 0x18180009U);

                    static const uint32_t Param_p3a_func101_026[] =
                    {
                        BSWAP_32BIG_C(0xc6b8dab6U), BSWAP_32BIG_C(0xc9fafd05U), BSWAP_32BIG_C(0xdbd95b3dU),
                        BSWAP_32BIG_C(0x7bd33e47U),
                    };
                    r_rsip_func101(Param_p3a_func101_026);
                }
            }
            else
            {
                static const uint32_t Param_p3a_func101_027[] =
                {
                    BSWAP_32BIG_C(0x9fbb9d61U), BSWAP_32BIG_C(0x91d4b60bU), BSWAP_32BIG_C(0xee00e069U), BSWAP_32BIG_C(
                        0x9efec724U),
                };
                r_rsip_func101(Param_p3a_func101_027);
            }
        }
    }

    r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00A60000U);

    static const uint32_t Param_p3a_func100_020[] =
    {
        BSWAP_32BIG_C(0xae09e9aaU), BSWAP_32BIG_C(0xabc71d9eU), BSWAP_32BIG_C(0x3d4ed447U), BSWAP_32BIG_C(0x29a1cd65U),
    };
    r_rsip_func100(Param_p3a_func100_020);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3a_func102_001[] =
        {
            BSWAP_32BIG_C(0x547e9304U), BSWAP_32BIG_C(0xfb93de42U), BSWAP_32BIG_C(0x2b01bef4U), BSWAP_32BIG_C(
                0xe447b32cU),
        };
        r_rsip_func102(Param_p3a_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub001(0x00c000c1U);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x18180009U);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000778U, 0x18180009U);

    r_rsip_func_sub009(0x00003a05U);

    static const uint32_t Param_p3a_func101_028[] =
    {
        BSWAP_32BIG_C(0x6b1418c5U), BSWAP_32BIG_C(0xed607c71U), BSWAP_32BIG_C(0x8bd552c3U), BSWAP_32BIG_C(0x0a1d3edeU),
    };
    r_rsip_func101(Param_p3a_func101_028);
    r_rsip_func113();

    static const uint32_t Param_p3a_func100_021[] =
    {
        BSWAP_32BIG_C(0xa3b7d012U), BSWAP_32BIG_C(0x31e05ba5U), BSWAP_32BIG_C(0x3b5e4aafU), BSWAP_32BIG_C(0x767db665U),
    };
    r_rsip_func100(Param_p3a_func100_021);
    r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x16b80000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub009(0x00003a01U);

    static const uint32_t Param_p3a_func101_029[] =
    {
        BSWAP_32BIG_C(0xca1efd6cU), BSWAP_32BIG_C(0x0192615cU), BSWAP_32BIG_C(0x4f5931c6U), BSWAP_32BIG_C(0x56060272U),
    };
    r_rsip_func101(Param_p3a_func101_029);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000220U, 0x1818000aU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000630U, 0x1818000aU);

    r_rsip_func_sub009(0x0000003aU);

    static const uint32_t Param_p3a_func101_030[] =
    {
        BSWAP_32BIG_C(0x41226624U), BSWAP_32BIG_C(0xe116bca4U), BSWAP_32BIG_C(0x1d64a2edU), BSWAP_32BIG_C(0xea33bab1U),
    };
    r_rsip_func101(Param_p3a_func101_030);
    r_rsip_func313();

    WR1_PROG(REG_1404H, 0x14a00000U);
    r_rsip_func_sub001(0x00c000d1U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x16b80000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub009(0x00003a01U);

    static const uint32_t Param_p3a_func101_031[] =
    {
        BSWAP_32BIG_C(0x55c9cf5fU), BSWAP_32BIG_C(0x8e9fb3e8U), BSWAP_32BIG_C(0xf5957108U), BSWAP_32BIG_C(0xc7686007U),
    };
    r_rsip_func101(Param_p3a_func101_031);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000778U, 0x00000838U, 0x00000220U, 0x18180007U);

    r_rsip_func_sub009(0x00003a01U);

    static const uint32_t Param_p3a_func101_032[] =
    {
        BSWAP_32BIG_C(0x2ea3e4faU), BSWAP_32BIG_C(0x1b91eac7U), BSWAP_32BIG_C(0xed21ed4cU), BSWAP_32BIG_C(0x6e173a83U),
    };
    r_rsip_func101(Param_p3a_func101_032);
    r_rsip_func315();

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3a_func100_022[] =
    {
        BSWAP_32BIG_C(0x1188b57bU), BSWAP_32BIG_C(0x2931fdf7U), BSWAP_32BIG_C(0x9668e415U), BSWAP_32BIG_C(0x2c88f738U),
    };
    r_rsip_func100(Param_p3a_func100_022);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3a_func102_002[] =
        {
            BSWAP_32BIG_C(0xe3a56c0cU), BSWAP_32BIG_C(0x1ba40ecdU), BSWAP_32BIG_C(0xc17f2c29U), BSWAP_32BIG_C(
                0xc4483b43U),
        };
        r_rsip_func102(Param_p3a_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x12a80000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub009(0x00003a02U);

    static const uint32_t Param_p3a_func101_033[] =
    {
        BSWAP_32BIG_C(0x864bc055U), BSWAP_32BIG_C(0xc77c6c21U), BSWAP_32BIG_C(0x3e921177U), BSWAP_32BIG_C(0x9a233204U),
    };
    r_rsip_func101(Param_p3a_func101_033);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000368U, 0x00000428U, 0x00000630U, 0x18180007U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x14b00000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub009(0x00003a02U);

    static const uint32_t Param_p3a_func101_034[] =
    {
        BSWAP_32BIG_C(0x48a5d7a3U), BSWAP_32BIG_C(0xcd3f3006U), BSWAP_32BIG_C(0xb4e9e186U), BSWAP_32BIG_C(0xa46c2f8cU),
    };
    r_rsip_func101(Param_p3a_func101_034);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1818000aU);

    r_rsip_func_sub002(0x00000368U, 0x00000a40U, 0x00000160U, 0x1818000aU);

    r_rsip_func_sub002(0x00000160U, 0x00000220U, 0x00000428U, 0x18180007U);

    r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x30300010U);

    r_rsip_func_sub038(0x00000428U, 0x00000838U, 0x00000630U);
    r_rsip_func_sub005(0x00000428U, 0x30300002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x30300003U, 0x00010001U);
    r_rsip_func_sub007(0x00000428U, 0x00000220U, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x30300002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x14b00000U);
    r_rsip_func_sub004(0x08000104U, 0x00010001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub009(0x00003a02U);

    static const uint32_t Param_p3a_func101_035[] =
    {
        BSWAP_32BIG_C(0xd63c69bbU), BSWAP_32BIG_C(0x92588a9eU), BSWAP_32BIG_C(0x74f7f3e2U), BSWAP_32BIG_C(0xafc9dc3aU),
    };
    r_rsip_func101(Param_p3a_func101_035);
    r_rsip_func315();

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3a_func100_023[] =
    {
        BSWAP_32BIG_C(0x426fa7b7U), BSWAP_32BIG_C(0x91554a24U), BSWAP_32BIG_C(0xa1b504a2U), BSWAP_32BIG_C(0xa87da860U),
    };
    r_rsip_func100(Param_p3a_func100_023);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3a_func102_003[] =
        {
            BSWAP_32BIG_C(0xaaa2f3e4U), BSWAP_32BIG_C(0x0c30ab8fU), BSWAP_32BIG_C(0x30f2d52bU), BSWAP_32BIG_C(
                0x5cd00894U),
        };
        r_rsip_func102(Param_p3a_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub001(0x00c00181U);

    r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000428U, 0x30300009U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x14b00000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub009(0x00003a0fU);

    static const uint32_t Param_p3a_func101_036[] =
    {
        BSWAP_32BIG_C(0xaf598c97U), BSWAP_32BIG_C(0x7b547902U), BSWAP_32BIG_C(0xe4f94bafU), BSWAP_32BIG_C(0xfd89587fU),
    };
    r_rsip_func101(Param_p3a_func101_036);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1600H, 0x00010001U);

    r_rsip_func_sub009(0x00003a06U);

    static const uint32_t Param_p3a_func101_037[] =
    {
        BSWAP_32BIG_C(0x9dcf146cU), BSWAP_32BIG_C(0x9127a179U), BSWAP_32BIG_C(0x3f7588f6U), BSWAP_32BIG_C(0xb13abac7U),
    };
    r_rsip_func101(Param_p3a_func101_037);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00003a01U);

    static const uint32_t Param_p3a_func101_038[] =
    {
        BSWAP_32BIG_C(0x665a5e4aU), BSWAP_32BIG_C(0x771232b5U), BSWAP_32BIG_C(0x151355d5U), BSWAP_32BIG_C(0x7335e0d0U),
    };
    r_rsip_func101(Param_p3a_func101_038);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000fU);

    r_rsip_func_sub009(0x00003a01U);

    static const uint32_t Param_p3a_func101_039[] =
    {
        BSWAP_32BIG_C(0x93024177U), BSWAP_32BIG_C(0x85ff24dbU), BSWAP_32BIG_C(0xc06f36a5U), BSWAP_32BIG_C(0x2eb1963fU),
    };
    r_rsip_func101(Param_p3a_func101_039);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000060U, 0x000008e7U, 0x14b00000U);
    for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3a_func100_024[] =
        {
            BSWAP_32BIG_C(0x66a3b0bdU), BSWAP_32BIG_C(0xc82698c0U), BSWAP_32BIG_C(0xe1203bd9U), BSWAP_32BIG_C(
                0xb5503963U),
        };
        r_rsip_func100(Param_p3a_func100_024);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3a_func101_040[] =
        {
            BSWAP_32BIG_C(0x9d76363cU), BSWAP_32BIG_C(0xcc59616eU), BSWAP_32BIG_C(0xd7dfd935U), BSWAP_32BIG_C(
                0x1de96b90U),
        };
        r_rsip_func101(Param_p3a_func101_040);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000060U, 0x000008e7U, 0x12a80000U);
    for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3a_func100_025[] =
        {
            BSWAP_32BIG_C(0x45090957U), BSWAP_32BIG_C(0xf5b11190U), BSWAP_32BIG_C(0xafe5e110U), BSWAP_32BIG_C(
                0x1917da61U),
        };
        r_rsip_func100(Param_p3a_func100_025);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[97 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3a_func101_041[] =
        {
            BSWAP_32BIG_C(0x5922b2b9U), BSWAP_32BIG_C(0x5a26e210U), BSWAP_32BIG_C(0x0f5ae12bU), BSWAP_32BIG_C(
                0xbdf10d81U),
        };
        r_rsip_func101(Param_p3a_func101_041);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3a_func100_026[] =
    {
        BSWAP_32BIG_C(0xde2c19d4U), BSWAP_32BIG_C(0xf92ef213U), BSWAP_32BIG_C(0xf4dbcd58U), BSWAP_32BIG_C(0xef1eca80U),
    };
    r_rsip_func100(Param_p3a_func100_026);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[193]);

    static const uint32_t Param_p3a_func100_027[] =
    {
        BSWAP_32BIG_C(0x2687e372U), BSWAP_32BIG_C(0x79e6174bU), BSWAP_32BIG_C(0x05a41c2eU), BSWAP_32BIG_C(0x37b20f9cU),
    };
    r_rsip_func100(Param_p3a_func100_027);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub009(0x00003a07U);

    static const uint32_t Param_p3a_func101_042[] =
    {
        BSWAP_32BIG_C(0xb85b1420U), BSWAP_32BIG_C(0x08fe6ef2U), BSWAP_32BIG_C(0xdbd99baeU), BSWAP_32BIG_C(0xd6ed5265U),
    };
    r_rsip_func101(Param_p3a_func101_042);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00003a02U);

    static const uint32_t Param_p3a_func101_043[] =
    {
        BSWAP_32BIG_C(0xa61d3b49U), BSWAP_32BIG_C(0x60874a4dU), BSWAP_32BIG_C(0x14a0e546U), BSWAP_32BIG_C(0x0621aa45U),
    };
    r_rsip_func101(Param_p3a_func101_043);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000eU);

    r_rsip_func_sub009(0x00003a02U);

    static const uint32_t Param_p3a_func101_044[] =
    {
        BSWAP_32BIG_C(0xfe98626fU), BSWAP_32BIG_C(0xf623be35U), BSWAP_32BIG_C(0xb21c8ffeU), BSWAP_32BIG_C(0xf9767266U),
    };
    r_rsip_func101(Param_p3a_func101_044);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000060U, 0x000008e7U, 0x14b00000U);
    for (iLoop = 0U; iLoop < 96U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3a_func100_028[] =
        {
            BSWAP_32BIG_C(0x19d787a7U), BSWAP_32BIG_C(0x33f8f902U), BSWAP_32BIG_C(0x2e6a329bU), BSWAP_32BIG_C(
                0xc4683fdbU),
        };
        r_rsip_func100(Param_p3a_func100_028);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3a_func101_045[] =
        {
            BSWAP_32BIG_C(0xad44873aU), BSWAP_32BIG_C(0x78621cd7U), BSWAP_32BIG_C(0xb535f8bdU), BSWAP_32BIG_C(
                0x72455356U),
        };
        r_rsip_func101(Param_p3a_func101_045);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3a_func100_029[] =
    {
        BSWAP_32BIG_C(0x50aa7ff0U), BSWAP_32BIG_C(0xf28a370cU), BSWAP_32BIG_C(0x0489a857U), BSWAP_32BIG_C(0xfc47e498U),
    };
    r_rsip_func100(Param_p3a_func100_029);
    r_rsip_func_sub027(0x40000000U, 0xe8008104U, 0x81010280U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[97]);

    static const uint32_t Param_p3a_func100_030[] =
    {
        BSWAP_32BIG_C(0x75a4259eU), BSWAP_32BIG_C(0xe86899ceU), BSWAP_32BIG_C(0x456e859aU), BSWAP_32BIG_C(0x29de435aU),
    };
    r_rsip_func100(Param_p3a_func100_030);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[101]);

    static const uint32_t Param_p3a_func100_031[] =
    {
        BSWAP_32BIG_C(0xba2d977cU), BSWAP_32BIG_C(0x6d188a15U), BSWAP_32BIG_C(0xb50f72baU), BSWAP_32BIG_C(0xa7248770U),
    };
    r_rsip_func100(Param_p3a_func100_031);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p3a_func102_004[] =
    {
        BSWAP_32BIG_C(0x67fb2182U), BSWAP_32BIG_C(0x15092f92U), BSWAP_32BIG_C(0x408ee869U), BSWAP_32BIG_C(0x7d683b06U),
    };
    r_rsip_func102(Param_p3a_func102_004);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
