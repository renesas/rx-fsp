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

rsip_ret_t r_rsip_p3b (const uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;
    uint32_t kLoop   = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x003b0001U, 0x00000e50U);

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

        r_rsip_func_sub009(0x00003b01U);

        static const uint32_t Param_p3b_func101_001[] =
        {
            BSWAP_32BIG_C(0xc3b30cd7U), BSWAP_32BIG_C(0x5f7d0ce5U), BSWAP_32BIG_C(0x53771bd5U), BSWAP_32BIG_C(
                0xf4b9b0c5U),
        };
        r_rsip_func101(Param_p3b_func101_001);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1404H, 0x11200000U);
        r_rsip_func_sub001(0x00c90011U);

        r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000038U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 56U; iLoop = iLoop + 4U)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            r_rsip_func_sub014(0x00007c07U, 0x00602000U);

            r_rsip_func_sub009(0x00003b02U);

            static const uint32_t Param_p3b_func101_002[] =
            {
                BSWAP_32BIG_C(0xbf2816c9U), BSWAP_32BIG_C(0xc44a43c8U), BSWAP_32BIG_C(0x5b245181U), BSWAP_32BIG_C(
                    0xa57c4eccU),
            };
            r_rsip_func101(Param_p3b_func101_002);
            r_rsip_func113();

            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            r_rsip_func_sub001(0x00c20011U);

            WR1_PROG(REG_1600H, 0x00002485U);

            static const uint32_t Param_p3b_func101_003[] =
            {
                BSWAP_32BIG_C(0x271b7dc6U), BSWAP_32BIG_C(0xd4e2c94cU), BSWAP_32BIG_C(0xd1e1a72fU), BSWAP_32BIG_C(
                    0x286a9cd2U),
            };
            r_rsip_func101(Param_p3b_func101_003);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x38000886U);

        r_rsip_func_sub009(0x00003b03U);

        static const uint32_t Param_p3b_func101_004[] =
        {
            BSWAP_32BIG_C(0x91d6c434U), BSWAP_32BIG_C(0x949de59bU), BSWAP_32BIG_C(0x439ab541U), BSWAP_32BIG_C(
                0x88c49e9dU),
        };
        r_rsip_func101(Param_p3b_func101_004);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1608H, 0x81040000U);
        r_rsip_func_sub001(0x00c90011U);

        WR1_PROG(REG_1444H, 0x00003fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_0940H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0944H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0948H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_094CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0950H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0954H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0958H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_095CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0960H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0964H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0968H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_096CH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0970H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0974H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0978H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_097CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0980H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0984H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0988H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_098CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0990H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0994H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0998H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_099CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09A0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09A4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09A8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09ACH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09B0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09B4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09B8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09BCH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09C0H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09C4H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09C8H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09CCH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09D0H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09D4H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09D8H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09DCH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09E0H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09E4H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09E8H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09ECH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09F0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09F4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09F8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09FCH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A00H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A04H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A08H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A0CH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A10H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A14H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A18H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A1CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A20H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A24H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A28H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A2CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A30H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A34H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A38H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A3CH, bswap_32big(0xB851EB85U));

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3b_func100_001[] =
        {
            BSWAP_32BIG_C(0x55557406U), BSWAP_32BIG_C(0x413a5ecdU), BSWAP_32BIG_C(0x347163d2U), BSWAP_32BIG_C(
                0xa1e79c82U),
        };
        r_rsip_func100(Param_p3b_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3b_func101_005[] =
            {
                BSWAP_32BIG_C(0xea3e31e6U), BSWAP_32BIG_C(0xd5a54af4U), BSWAP_32BIG_C(0x694a9c39U), BSWAP_32BIG_C(
                    0xd11b185eU),
            };
            r_rsip_func101(Param_p3b_func101_005);
            continue;
        }
        else
        {
            static const uint32_t Param_p3b_func101_006[] =
            {
                BSWAP_32BIG_C(0x3ae976b1U), BSWAP_32BIG_C(0xb668b2c9U), BSWAP_32BIG_C(0x48d287feU), BSWAP_32BIG_C(
                    0x8f3dcfb2U),
            };
            r_rsip_func101(Param_p3b_func101_006);
        }

        r_rsip_func_sub006(0x38008a20U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3b_func100_002[] =
        {
            BSWAP_32BIG_C(0xebf6a0aeU), BSWAP_32BIG_C(0xac5a6137U), BSWAP_32BIG_C(0xc4e2ced1U), BSWAP_32BIG_C(
                0xbfbdc323U),
        };
        r_rsip_func100(Param_p3b_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000320U, 0x00000220U, 0x00000630U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_003[] =
            {
                BSWAP_32BIG_C(0xd5f594e4U), BSWAP_32BIG_C(0xd4bceffaU), BSWAP_32BIG_C(0x51966f3eU), BSWAP_32BIG_C(
                    0xc00f6cbfU),
            };
            r_rsip_func100(Param_p3b_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000220U, 0x00000320U, 0x00000630U, 0x2020000aU);

                static const uint32_t Param_p3b_func101_007[] =
                {
                    BSWAP_32BIG_C(0x1db384a0U), BSWAP_32BIG_C(0x69809d6aU), BSWAP_32BIG_C(0xf1579c03U), BSWAP_32BIG_C(
                        0xf627e160U),
                };
                r_rsip_func101(Param_p3b_func101_007);
            }
            else
            {
                static const uint32_t Param_p3b_func101_008[] =
                {
                    BSWAP_32BIG_C(0x171648b2U), BSWAP_32BIG_C(0x852524ffU), BSWAP_32BIG_C(0xf2faa2d2U), BSWAP_32BIG_C(
                        0x9a7475f5U),
                };
                r_rsip_func101(Param_p3b_func101_008);
            }

            WR1_PROG(REG_1404H, 0x19400000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x10000000U));
            r_rsip_func_sub001(0x00c20011U);
            r_rsip_func_sub001(0x00c000f1U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_004[] =
            {
                BSWAP_32BIG_C(0x26b5171aU), BSWAP_32BIG_C(0x9814afdaU), BSWAP_32BIG_C(0x2c6d3decU), BSWAP_32BIG_C(
                    0x9970b2beU),
            };
            r_rsip_func100(Param_p3b_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3b_func101_009[] =
                {
                    BSWAP_32BIG_C(0xeca4aa00U), BSWAP_32BIG_C(0xf189b740U), BSWAP_32BIG_C(0x46fc1f10U), BSWAP_32BIG_C(
                        0x939b13ecU),
                };
                r_rsip_func101(Param_p3b_func101_009);
                continue;
            }
            else
            {
                static const uint32_t Param_p3b_func101_010[] =
                {
                    BSWAP_32BIG_C(0xa48ac594U), BSWAP_32BIG_C(0x06b8cd39U), BSWAP_32BIG_C(0xe5fb98b2U), BSWAP_32BIG_C(
                        0x58a0540dU),
                };
                r_rsip_func101(Param_p3b_func101_010);
            }
        }
        else
        {
            static const uint32_t Param_p3b_func101_011[] =
            {
                BSWAP_32BIG_C(0xa9789462U), BSWAP_32BIG_C(0x76ba9646U), BSWAP_32BIG_C(0x34965382U), BSWAP_32BIG_C(
                    0x0bcb5ee2U),
            };
            r_rsip_func101(Param_p3b_func101_011);
        }

        r_rsip_func_sub022(0x0000b4c0U, 0x000000c0U, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            r_rsip_func_sub022(0x01003906U, 0x00002cc0U, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x15300000U);
            r_rsip_func_sub001(0x00c000fdU);
            r_rsip_func_sub001(0x00c90005U);

            r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x20200010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x20200004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19400000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c000fdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_005[] =
            {
                BSWAP_32BIG_C(0xe7a96086U), BSWAP_32BIG_C(0x347fbf5dU), BSWAP_32BIG_C(0x068b5ed2U), BSWAP_32BIG_C(
                    0x15b9d4a5U),
            };
            r_rsip_func100(Param_p3b_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                static const uint32_t Param_p3b_func101_012[] =
                {
                    BSWAP_32BIG_C(0xefa235d4U), BSWAP_32BIG_C(0x5400a732U), BSWAP_32BIG_C(0x12a9db8fU), BSWAP_32BIG_C(
                        0x79a6a7d1U),
                };
                r_rsip_func101(Param_p3b_func101_012);
                break;
            }
            else
            {
                static const uint32_t Param_p3b_func101_013[] =
                {
                    BSWAP_32BIG_C(0x0057e298U), BSWAP_32BIG_C(0x75d35a4bU), BSWAP_32BIG_C(0x8a741870U), BSWAP_32BIG_C(
                        0x74a114ddU),
                };
                r_rsip_func101(Param_p3b_func101_013);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        r_rsip_func_sub006(0x38008940U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3b_func100_006[] =
        {
            BSWAP_32BIG_C(0x4062096cU), BSWAP_32BIG_C(0x656424bdU), BSWAP_32BIG_C(0x1be630f7U), BSWAP_32BIG_C(
                0x265a5cdaU),
        };
        r_rsip_func100(Param_p3b_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3b_func101_014[] =
            {
                BSWAP_32BIG_C(0xb6790e5cU), BSWAP_32BIG_C(0x88675d0cU), BSWAP_32BIG_C(0x81098526U), BSWAP_32BIG_C(
                    0xd1bef327U),
            };
            r_rsip_func101(Param_p3b_func101_014);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_func_sub001(0x00c00101U);

        r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000428U, 0x20200009U);

        r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x2020000aU);

        WR1_PROG(REG_1404H, 0x15300000U);
        r_rsip_func_sub004(0x08000104U, 0x00010001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x20200010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        r_rsip_func_sub005(0x00000838U, 0x20200004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3b_func100_007[] =
        {
            BSWAP_32BIG_C(0xd5ce691eU), BSWAP_32BIG_C(0xf8f4f4e9U), BSWAP_32BIG_C(0x9f07f8abU), BSWAP_32BIG_C(
                0x9b8e0d59U),
        };
        r_rsip_func100(Param_p3b_func100_007);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3b_func101_015[] =
            {
                BSWAP_32BIG_C(0x8013f6eeU), BSWAP_32BIG_C(0x8d33eebdU), BSWAP_32BIG_C(0x97429219U), BSWAP_32BIG_C(
                    0x1e2fe7d2U),
            };
            r_rsip_func101(Param_p3b_func101_015);
        }
        else
        {
            static const uint32_t Param_p3b_func100_008[] =
            {
                BSWAP_32BIG_C(0xd7d16faeU), BSWAP_32BIG_C(0xf5b72d35U), BSWAP_32BIG_C(0xa12c47e8U), BSWAP_32BIG_C(
                    0x2ec90fe7U),
            };
            r_rsip_func100(Param_p3b_func100_008);
            WR1_PROG(REG_1404H, 0x17380000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c000fdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub018(0x00000018U, 0x00000428U, 0x20200010U);

            r_rsip_func_sub013(0x00000838U, 0x00000220U, 0x00000428U, 0x00000630U, 0x20200000U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_009[] =
            {
                BSWAP_32BIG_C(0x849f822aU), BSWAP_32BIG_C(0x0b90ef40U), BSWAP_32BIG_C(0x960f8917U), BSWAP_32BIG_C(
                    0xd464bf04U),
            };
            r_rsip_func100(Param_p3b_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3b_func101_016[] =
                {
                    BSWAP_32BIG_C(0xe6375340U), BSWAP_32BIG_C(0x5f2647a3U), BSWAP_32BIG_C(0xc4eab046U), BSWAP_32BIG_C(
                        0xd56ba5b4U),
                };
                r_rsip_func101(Param_p3b_func101_016);
                continue;
            }

            static const uint32_t Param_p3b_func100_010[] =
            {
                BSWAP_32BIG_C(0xe63676b5U), BSWAP_32BIG_C(0x04d51861U), BSWAP_32BIG_C(0xc9d7d522U), BSWAP_32BIG_C(
                    0x8ca47075U),
            };
            r_rsip_func100(Param_p3b_func100_010);

            r_rsip_func_sub022(0x0000b560U, 0x00000001U, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80c0000aU);
            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_func_sub001(0x03430101U);

            r_rsip_func_sub021(0x00000929U, 0x00000908U, 0x0000b4c0U, 0x000000fcU);

            for (iLoop = 0U; iLoop < 64U; iLoop++)
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

            r_rsip_func_sub030(0x15300000U, 0x0000094aU, 0x81c0000aU);
            r_rsip_func_sub001(0x00c90101U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                r_rsip_func_sub005(0x00000838U, 0x2020000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000838U, 0x00000938U, 0x00000630U, 0x20200009U);

                WR1_PROG(REG_1600H, 0x000033e0U);

                static const uint32_t Param_p3b_func101_017[] =
                {
                    BSWAP_32BIG_C(0x92f379e6U), BSWAP_32BIG_C(0x11998f9dU), BSWAP_32BIG_C(0x162e83aeU), BSWAP_32BIG_C(
                        0x95c5c650U),
                };
                r_rsip_func101(Param_p3b_func101_017);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub014(0x00007c1fU, 0x00602000U);

            static const uint32_t Param_p3b_func100_011[] =
            {
                BSWAP_32BIG_C(0xc44450faU), BSWAP_32BIG_C(0x6a4243a5U), BSWAP_32BIG_C(0xc81610a0U), BSWAP_32BIG_C(
                    0x3a8a3f67U),
            };
            r_rsip_func100(Param_p3b_func100_011);
            WR1_PROG(REG_1600H, 0x00000a52U);

            r_rsip_func_sub016(0x81010160U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
                r_rsip_func_sub031(0x00000040U, 0x000008e7U, 0x11200000U);
                for (jLoop = 0U; jLoop < 64U; jLoop = jLoop + 4U)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    r_rsip_func_sub014(0x00007c07U, 0x00602000U);

                    r_rsip_func_sub009(0x00003b04U);

                    static const uint32_t Param_p3b_func101_018[] =
                    {
                        BSWAP_32BIG_C(0xc68e04d9U), BSWAP_32BIG_C(0x43b3c552U), BSWAP_32BIG_C(0x40cb86ecU),
                        BSWAP_32BIG_C(0x828125cdU),
                    };
                    r_rsip_func101(Param_p3b_func101_018);
                    r_rsip_func113();

                    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                    r_rsip_func_sub001(0x00c20011U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    static const uint32_t Param_p3b_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xe166ea65U), BSWAP_32BIG_C(0xc58c2567U), BSWAP_32BIG_C(0x67301272U),
                        BSWAP_32BIG_C(0x5d867033U),
                    };
                    r_rsip_func101(Param_p3b_func101_019);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000886U);

                static const uint32_t Param_p3b_func100_012[] =
                {
                    BSWAP_32BIG_C(0x17402032U), BSWAP_32BIG_C(0xa6e3f9a9U), BSWAP_32BIG_C(0xd6887b4dU), BSWAP_32BIG_C(
                        0x122f7441U),
                };
                r_rsip_func100(Param_p3b_func100_012);
                WR1_PROG(REG_1404H, 0x19400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000004U);
                r_rsip_func_sub001(0x00c000fdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x2020000aU);

                r_rsip_func_sub018(0x00000018U, 0x00000838U, 0x20200010U);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x20200004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17380000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c000fdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x20200009U);

                r_rsip_func_sub018(0x00000018U, 0x00000428U, 0x20200010U);

                r_rsip_func_sub013(0x00000220U, 0x00000630U, 0x00000428U, 0x00000838U, 0x20200000U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x19400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c000fdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x2020000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x2020000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p3b_func100_013[] =
                {
                    BSWAP_32BIG_C(0x5bea17e1U), BSWAP_32BIG_C(0xbc79486bU), BSWAP_32BIG_C(0x73c383dfU), BSWAP_32BIG_C(
                        0x904ff317U),
                };
                r_rsip_func100(Param_p3b_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    static const uint32_t Param_p3b_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x66556cd5U), BSWAP_32BIG_C(0x9c81a892U), BSWAP_32BIG_C(0xb2c7eca7U),
                        BSWAP_32BIG_C(0xb436d265U),
                    };
                    r_rsip_func101(Param_p3b_func101_020);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    static const uint32_t Param_p3b_func100_014[] =
                    {
                        BSWAP_32BIG_C(0x010dafc3U), BSWAP_32BIG_C(0x6a575bf4U), BSWAP_32BIG_C(0x7f419b25U),
                        BSWAP_32BIG_C(0x7051ef07U),
                    };
                    r_rsip_func100(Param_p3b_func100_014);
                    r_rsip_func_sub016(0x81010120U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19400000U);
                        WR1_PROG(REG_1608H, 0x81c0000aU);
                        r_rsip_func_sub001(0x00c90101U);

                        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x2020000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x2020000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        static const uint32_t Param_p3b_func100_015[] =
                        {
                            BSWAP_32BIG_C(0xc4202b82U), BSWAP_32BIG_C(0x3da1b160U), BSWAP_32BIG_C(0x0f5259bfU),
                            BSWAP_32BIG_C(0xcc1ca975U),
                        };
                        r_rsip_func100(Param_p3b_func100_015);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            static const uint32_t Param_p3b_func101_021[] =
                            {
                                BSWAP_32BIG_C(0xf48b5eb5U), BSWAP_32BIG_C(0x8d932b2eU), BSWAP_32BIG_C(0x2ff13475U),
                                BSWAP_32BIG_C(0x28722a96U),
                            };
                            r_rsip_func101(Param_p3b_func101_021);
                            break;
                        }
                        else
                        {
                            static const uint32_t Param_p3b_func100_016[] =
                            {
                                BSWAP_32BIG_C(0xa1f05616U), BSWAP_32BIG_C(0x447ee459U), BSWAP_32BIG_C(0x91901ecbU),
                                BSWAP_32BIG_C(0x5ed98c57U),
                            };
                            r_rsip_func100(Param_p3b_func100_016);
                            WR1_PROG(REG_1404H, 0x19400000U);
                            r_rsip_func_sub004(0x08000104U, 0x00000002U);
                            r_rsip_func_sub001(0x00c000fdU);
                            r_rsip_func_sub001(0x00c20005U);
                            r_rsip_func_sub001(0x0002000dU);

                            r_rsip_func_sub013(0x00000838U,
                                               0x00000a40U,
                                               0x00000428U,
                                               0x00000220U,
                                               0x20200000U,
                                               0x00010001U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000838U, 0x20200009U);

                            static const uint32_t Param_p3b_func101_022[] =
                            {
                                BSWAP_32BIG_C(0xd393d317U), BSWAP_32BIG_C(0x4a3f98faU), BSWAP_32BIG_C(0xc574cf09U),
                                BSWAP_32BIG_C(0x595758f2U),
                            };
                            r_rsip_func101(Param_p3b_func101_022);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub006(0x38008a40U, 0x00000000U, 0x00260000U);

                    static const uint32_t Param_p3b_func100_017[] =
                    {
                        BSWAP_32BIG_C(0xafd6166eU), BSWAP_32BIG_C(0x8d656220U), BSWAP_32BIG_C(0xc9cee0b1U),
                        BSWAP_32BIG_C(0x714f77d4U),
                    };
                    r_rsip_func100(Param_p3b_func100_017);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p3b_func101_023[] =
                        {
                            BSWAP_32BIG_C(0x11373b93U), BSWAP_32BIG_C(0x3e359f33U), BSWAP_32BIG_C(0xe13b1e37U),
                            BSWAP_32BIG_C(0x4af2084cU),
                        };
                        r_rsip_func101(Param_p3b_func101_023);
                        break;
                    }
                    else
                    {
                        static const uint32_t Param_p3b_func101_024[] =
                        {
                            BSWAP_32BIG_C(0x4fb9a6d6U), BSWAP_32BIG_C(0xc815dde1U), BSWAP_32BIG_C(0x5e633cfeU),
                            BSWAP_32BIG_C(0x59ca2d35U),
                        };
                        r_rsip_func101(Param_p3b_func101_024);
                    }
                }
            }

            r_rsip_func_sub017(0x38000a4bU, 0x00260000U);

            static const uint32_t Param_p3b_func100_018[] =
            {
                BSWAP_32BIG_C(0xde9ea080U), BSWAP_32BIG_C(0xb12082bfU), BSWAP_32BIG_C(0x1def137aU), BSWAP_32BIG_C(
                    0x6dc79211U),
            };
            r_rsip_func100(Param_p3b_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_p3b_func100_019[] =
                {
                    BSWAP_32BIG_C(0xf4b8e9abU), BSWAP_32BIG_C(0x7859d58fU), BSWAP_32BIG_C(0xfb3b5660U), BSWAP_32BIG_C(
                        0x8679eaa5U),
                };
                r_rsip_func100(Param_p3b_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p3b_func101_025[] =
                    {
                        BSWAP_32BIG_C(0x9925f19eU), BSWAP_32BIG_C(0xe37a673fU), BSWAP_32BIG_C(0x2aebcc05U),
                        BSWAP_32BIG_C(0x2c3421bbU),
                    };
                    r_rsip_func101(Param_p3b_func101_025);
                    break;
                }
                else
                {
                    r_rsip_func_sub002(0x00000428U, 0x00000938U, 0x00000320U, 0x20200009U);

                    static const uint32_t Param_p3b_func101_026[] =
                    {
                        BSWAP_32BIG_C(0xda4a3eecU), BSWAP_32BIG_C(0x6f4688f0U), BSWAP_32BIG_C(0x90451a80U),
                        BSWAP_32BIG_C(0x1221f234U),
                    };
                    r_rsip_func101(Param_p3b_func101_026);
                }
            }
            else
            {
                static const uint32_t Param_p3b_func101_027[] =
                {
                    BSWAP_32BIG_C(0x4546d7abU), BSWAP_32BIG_C(0x55d19302U), BSWAP_32BIG_C(0xd173be39U), BSWAP_32BIG_C(
                        0x31e01679U),
                };
                r_rsip_func101(Param_p3b_func101_027);
            }
        }
    }

    r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00A60000U);

    static const uint32_t Param_p3b_func100_020[] =
    {
        BSWAP_32BIG_C(0xc9b39c81U), BSWAP_32BIG_C(0xc22107c9U), BSWAP_32BIG_C(0x7f0989b5U), BSWAP_32BIG_C(0xdd7a30d1U),
    };
    r_rsip_func100(Param_p3b_func100_020);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3b_func102_001[] =
        {
            BSWAP_32BIG_C(0x34720861U), BSWAP_32BIG_C(0x57c9e1bbU), BSWAP_32BIG_C(0xb0968033U), BSWAP_32BIG_C(
                0x1d2e75f5U),
        };
        r_rsip_func102(Param_p3b_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub001(0x00c00101U);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x20200009U);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000738U, 0x20200009U);

    r_rsip_func_sub009(0x00003b05U);

    static const uint32_t Param_p3b_func101_028[] =
    {
        BSWAP_32BIG_C(0xe12f98e3U), BSWAP_32BIG_C(0x6dca0dfaU), BSWAP_32BIG_C(0x1a6b0c4fU), BSWAP_32BIG_C(0x35a0472fU),
    };
    r_rsip_func101(Param_p3b_func101_028);
    r_rsip_func113();

    static const uint32_t Param_p3b_func100_021[] =
    {
        BSWAP_32BIG_C(0xd332c058U), BSWAP_32BIG_C(0xbbbed384U), BSWAP_32BIG_C(0x0b451b2bU), BSWAP_32BIG_C(0x9d3b61a6U),
    };
    r_rsip_func100(Param_p3b_func100_021);
    r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x16380000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x00003b01U);

    static const uint32_t Param_p3b_func101_029[] =
    {
        BSWAP_32BIG_C(0x8b3f34b9U), BSWAP_32BIG_C(0x59d5d62cU), BSWAP_32BIG_C(0x8a2dd910U), BSWAP_32BIG_C(0x0407ffc6U),
    };
    r_rsip_func101(Param_p3b_func101_029);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000220U, 0x2020000aU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000630U, 0x2020000aU);

    r_rsip_func_sub009(0x0000003bU);

    static const uint32_t Param_p3b_func101_030[] =
    {
        BSWAP_32BIG_C(0x2668f6ccU), BSWAP_32BIG_C(0x78a035dfU), BSWAP_32BIG_C(0x5994f595U), BSWAP_32BIG_C(0x2e838ac4U),
    };
    r_rsip_func101(Param_p3b_func101_030);
    r_rsip_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub001(0x00c00101U);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000660U, 0x20200009U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000dc0U);

    WR1_PROG(REG_1404H, 0x14500000U);
    r_rsip_func_sub001(0x00c00111U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x16780000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x00003b01U);

    static const uint32_t Param_p3b_func101_031[] =
    {
        BSWAP_32BIG_C(0x44d78cccU), BSWAP_32BIG_C(0xbff4e7dfU), BSWAP_32BIG_C(0x7281a007U), BSWAP_32BIG_C(0xeac51dc4U),
    };
    r_rsip_func101(Param_p3b_func101_031);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000778U, 0x00000878U, 0x00000230U, 0x20200007U);

    r_rsip_func_sub009(0x00003b01U);

    static const uint32_t Param_p3b_func101_032[] =
    {
        BSWAP_32BIG_C(0x8be77293U), BSWAP_32BIG_C(0x36c418c4U), BSWAP_32BIG_C(0xddf609a5U), BSWAP_32BIG_C(0x1e2f8de8U),
    };
    r_rsip_func101(Param_p3b_func101_032);
    r_rsip_func321();

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000660U, 0x00000a90U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a90U, 0x00000660U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3b_func100_022[] =
    {
        BSWAP_32BIG_C(0x2e94fb22U), BSWAP_32BIG_C(0x8126b17eU), BSWAP_32BIG_C(0x4f48f059U), BSWAP_32BIG_C(0x1a3e93faU),
    };
    r_rsip_func100(Param_p3b_func100_022);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3b_func102_002[] =
        {
            BSWAP_32BIG_C(0xe1431549U), BSWAP_32BIG_C(0x16db39edU), BSWAP_32BIG_C(0x85e07f92U), BSWAP_32BIG_C(
                0xc7e74a51U),
        };
        r_rsip_func102(Param_p3b_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x12480000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x00003b02U);

    static const uint32_t Param_p3b_func101_033[] =
    {
        BSWAP_32BIG_C(0x677faf3bU), BSWAP_32BIG_C(0xd9dfc848U), BSWAP_32BIG_C(0x859ce312U), BSWAP_32BIG_C(0x9f4fff1bU),
    };
    r_rsip_func101(Param_p3b_func101_033);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000348U, 0x00000448U, 0x00000660U, 0x20200007U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x14600000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x00003b02U);

    static const uint32_t Param_p3b_func101_034[] =
    {
        BSWAP_32BIG_C(0xdf6054cbU), BSWAP_32BIG_C(0x9b7d51b0U), BSWAP_32BIG_C(0x755d3eb9U), BSWAP_32BIG_C(0x43686c79U),
    };
    r_rsip_func101(Param_p3b_func101_034);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000448U, 0x00000a90U, 0x00000230U, 0x2020000aU);

    r_rsip_func_sub002(0x00000348U, 0x00000a90U, 0x00000130U, 0x2020000aU);

    r_rsip_func_sub002(0x00000130U, 0x00000230U, 0x00000448U, 0x20200007U);

    r_rsip_func_sub018(0x00000018U, 0x00000660U, 0x40400010U);

    r_rsip_func_sub038(0x00000448U, 0x00000878U, 0x00000660U);
    r_rsip_func_sub005(0x00000448U, 0x40400002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000660U);
    r_rsip_func_sub005(0x00000230U, 0x40400003U, 0x00010001U);
    r_rsip_func_sub007(0x00000448U, 0x00000230U, 0x00000660U);
    r_rsip_func_sub005(0x00000230U, 0x40400002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x14600000U);
    r_rsip_func_sub004(0x08000104U, 0x00010001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub009(0x00003b02U);

    static const uint32_t Param_p3b_func101_035[] =
    {
        BSWAP_32BIG_C(0x6a1a54ccU), BSWAP_32BIG_C(0xea04675dU), BSWAP_32BIG_C(0x82655d55U), BSWAP_32BIG_C(0x8522583dU),
    };
    r_rsip_func101(Param_p3b_func101_035);
    r_rsip_func321();

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000660U, 0x00000a90U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a90U, 0x00000660U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3b_func100_023[] =
    {
        BSWAP_32BIG_C(0x9edc997fU), BSWAP_32BIG_C(0xf8ea8c2fU), BSWAP_32BIG_C(0x90dec28fU), BSWAP_32BIG_C(0xed31223dU),
    };
    r_rsip_func100(Param_p3b_func100_023);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3b_func102_003[] =
        {
            BSWAP_32BIG_C(0x208e50c2U), BSWAP_32BIG_C(0xf3e18948U), BSWAP_32BIG_C(0x71973ffbU), BSWAP_32BIG_C(
                0xbcccd615U),
        };
        r_rsip_func102(Param_p3b_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub001(0x00c00201U);

    r_rsip_func_sub002(0x00000878U, 0x00000a90U, 0x00000448U, 0x40400009U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x14600000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub009(0x00003b03U);

    static const uint32_t Param_p3b_func101_036[] =
    {
        BSWAP_32BIG_C(0xbe08c57eU), BSWAP_32BIG_C(0xb0800d26U), BSWAP_32BIG_C(0x91e6c55aU), BSWAP_32BIG_C(0x07155e09U),
    };
    r_rsip_func101(Param_p3b_func101_036);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1600H, 0x00010001U);

    r_rsip_func_sub009(0x00003b06U);

    static const uint32_t Param_p3b_func101_037[] =
    {
        BSWAP_32BIG_C(0x4ca392acU), BSWAP_32BIG_C(0x1b6a84d9U), BSWAP_32BIG_C(0xa51679edU), BSWAP_32BIG_C(0x548e2db7U),
    };
    r_rsip_func101(Param_p3b_func101_037);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00003b01U);

    static const uint32_t Param_p3b_func101_038[] =
    {
        BSWAP_32BIG_C(0x3815cfaaU), BSWAP_32BIG_C(0x8e741cbfU), BSWAP_32BIG_C(0x23e86032U), BSWAP_32BIG_C(0x0fd50545U),
    };
    r_rsip_func101(Param_p3b_func101_038);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000011U);

    r_rsip_func_sub009(0x00003b01U);

    static const uint32_t Param_p3b_func101_039[] =
    {
        BSWAP_32BIG_C(0x8852f666U), BSWAP_32BIG_C(0x87e05644U), BSWAP_32BIG_C(0xe8c498e3U), BSWAP_32BIG_C(0x93bd9bcfU),
    };
    r_rsip_func101(Param_p3b_func101_039);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000080U, 0x000008e7U, 0x14600000U);
    for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3b_func100_024[] =
        {
            BSWAP_32BIG_C(0x40704dfdU), BSWAP_32BIG_C(0x2e738635U), BSWAP_32BIG_C(0x7ea590e6U), BSWAP_32BIG_C(
                0x70cb4428U),
        };
        r_rsip_func100(Param_p3b_func100_024);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3b_func101_040[] =
        {
            BSWAP_32BIG_C(0x06ca3a7cU), BSWAP_32BIG_C(0x63c37e43U), BSWAP_32BIG_C(0x3a86d612U), BSWAP_32BIG_C(
                0x835e4927U),
        };
        r_rsip_func101(Param_p3b_func101_040);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000080U, 0x000008e7U, 0x12480000U);
    for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3b_func100_025[] =
        {
            BSWAP_32BIG_C(0x6909e67fU), BSWAP_32BIG_C(0x5bc9d57dU), BSWAP_32BIG_C(0x3fb3aeabU), BSWAP_32BIG_C(
                0xcaa13ff6U),
        };
        r_rsip_func100(Param_p3b_func100_025);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[129 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3b_func101_041[] =
        {
            BSWAP_32BIG_C(0x4409cb18U), BSWAP_32BIG_C(0xc0d222caU), BSWAP_32BIG_C(0xac3a7b84U), BSWAP_32BIG_C(
                0x28f6b929U),
        };
        r_rsip_func101(Param_p3b_func101_041);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3b_func100_026[] =
    {
        BSWAP_32BIG_C(0xeb0ad959U), BSWAP_32BIG_C(0x8ee81554U), BSWAP_32BIG_C(0x96a4af5eU), BSWAP_32BIG_C(0xcc1f93bbU),
    };
    r_rsip_func100(Param_p3b_func100_026);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[257]);

    static const uint32_t Param_p3b_func100_027[] =
    {
        BSWAP_32BIG_C(0x149174f2U), BSWAP_32BIG_C(0xf88274a8U), BSWAP_32BIG_C(0x28a7abefU), BSWAP_32BIG_C(0xb064703aU),
    };
    r_rsip_func100(Param_p3b_func100_027);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub009(0x00003b07U);

    static const uint32_t Param_p3b_func101_042[] =
    {
        BSWAP_32BIG_C(0xf47f667cU), BSWAP_32BIG_C(0xdfbab78dU), BSWAP_32BIG_C(0x79089748U), BSWAP_32BIG_C(0x14607269U),
    };
    r_rsip_func101(Param_p3b_func101_042);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00003b02U);

    static const uint32_t Param_p3b_func101_043[] =
    {
        BSWAP_32BIG_C(0x02af0468U), BSWAP_32BIG_C(0x38c7a1f2U), BSWAP_32BIG_C(0xac4f34c0U), BSWAP_32BIG_C(0xcbe3f8a0U),
    };
    r_rsip_func101(Param_p3b_func101_043);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000010U);

    r_rsip_func_sub009(0x00003b02U);

    static const uint32_t Param_p3b_func101_044[] =
    {
        BSWAP_32BIG_C(0x5144f8ddU), BSWAP_32BIG_C(0xe2b6c0c3U), BSWAP_32BIG_C(0x6b456e12U), BSWAP_32BIG_C(0x9724c8ccU),
    };
    r_rsip_func101(Param_p3b_func101_044);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000080U, 0x000008e7U, 0x14600000U);
    for (iLoop = 0U; iLoop < 128U; iLoop = iLoop + 4U)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3b_func100_028[] =
        {
            BSWAP_32BIG_C(0xd816f788U), BSWAP_32BIG_C(0xf6738596U), BSWAP_32BIG_C(0x71bcee68U), BSWAP_32BIG_C(
                0xdffd5b8eU),
        };
        r_rsip_func100(Param_p3b_func100_028);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3b_func101_045[] =
        {
            BSWAP_32BIG_C(0x6ffab2c6U), BSWAP_32BIG_C(0x1c572623U), BSWAP_32BIG_C(0x5102af98U), BSWAP_32BIG_C(
                0xf0cd1430U),
        };
        r_rsip_func101(Param_p3b_func101_045);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3b_func100_029[] =
    {
        BSWAP_32BIG_C(0x50215d04U), BSWAP_32BIG_C(0xfda6e0f2U), BSWAP_32BIG_C(0x7eaaa978U), BSWAP_32BIG_C(0x9abe8148U),
    };
    r_rsip_func100(Param_p3b_func100_029);
    r_rsip_func_sub027(0x40000000U, 0xe8008104U, 0x81010280U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[129]);

    static const uint32_t Param_p3b_func100_030[] =
    {
        BSWAP_32BIG_C(0xb729e1f7U), BSWAP_32BIG_C(0x79d114b2U), BSWAP_32BIG_C(0x97f90113U), BSWAP_32BIG_C(0x6deb2021U),
    };
    r_rsip_func100(Param_p3b_func100_030);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[133]);

    static const uint32_t Param_p3b_func100_031[] =
    {
        BSWAP_32BIG_C(0x1eea462cU), BSWAP_32BIG_C(0xb26f1685U), BSWAP_32BIG_C(0xebb080cfU), BSWAP_32BIG_C(0x04a8de0eU),
    };
    r_rsip_func100(Param_p3b_func100_031);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p3b_func102_004[] =
    {
        BSWAP_32BIG_C(0xe2b28700U), BSWAP_32BIG_C(0xef56598eU), BSWAP_32BIG_C(0x3775a2f6U), BSWAP_32BIG_C(0x970e6d4aU),
    };
    r_rsip_func102(Param_p3b_func102_004);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
