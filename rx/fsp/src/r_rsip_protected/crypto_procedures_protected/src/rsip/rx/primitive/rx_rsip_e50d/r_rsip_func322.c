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

void r_rsip_func322 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000379dU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800db40U, 0x00260000U);

        static const uint32_t Param_func322_func100_001[] =
        {
            BSWAP_32BIG_C(0xdb50d613U), BSWAP_32BIG_C(0x7e56f348U), BSWAP_32BIG_C(0x9e193977U), BSWAP_32BIG_C(
                0x1e94367aU),
        };
        r_rsip_func100(Param_func322_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000230U);
            r_rsip_func_sub005(0x00000230U, 0x4040000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x14400000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            WR1_PROG(REG_1404H, 0x1a880000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);

            static const uint32_t Param_func322_func100_002[] =
            {
                BSWAP_32BIG_C(0x735dd1e1U), BSWAP_32BIG_C(0x25233b3fU), BSWAP_32BIG_C(0x7ddb2a02U), BSWAP_32BIG_C(
                    0x0667f191U),
            };
            r_rsip_func100(Param_func322_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x12380000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x18800000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000448U);
                r_rsip_func_sub005(0x00000448U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000a90U);
                r_rsip_func_sub005(0x00000a90U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func322_func101_001[] =
                {
                    BSWAP_32BIG_C(0x0cdd4d18U), BSWAP_32BIG_C(0x4967867fU), BSWAP_32BIG_C(0x5e991cf6U), BSWAP_32BIG_C(
                        0x7282d39aU),
                };
                r_rsip_func101(Param_func322_func101_001);
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_func_sub001(0x00c00211U);

                r_rsip_func_sub004(0x0b040184U, 0x8162b38bU);

                OFS_ADR = 676;

                r_rsip_func_sub012(0x1dd80000U, 0x0000b400U, 0x00000080U);

                r_rsip_func_sub009(0x00003221U);

                static const uint32_t Param_func322_func101_002[] =
                {
                    BSWAP_32BIG_C(0x609e9223U), BSWAP_32BIG_C(0x4599dfd6U), BSWAP_32BIG_C(0xa155233aU), BSWAP_32BIG_C(
                        0x26f6327eU),
                };
                r_rsip_func101(Param_func322_func101_002);
                r_rsip_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00211U);
                r_rsip_func_sub002(0x00000448U, 0x00000878U, 0x00000878U, 0x42420009U);

                r_rsip_func_sub009(0x0000f322U);

                static const uint32_t Param_func322_func101_003[] =
                {
                    BSWAP_32BIG_C(0xa1bd3c57U), BSWAP_32BIG_C(0x520257e4U), BSWAP_32BIG_C(0x5f20687eU), BSWAP_32BIG_C(
                        0x4e1dc692U),
                };
                r_rsip_func101(Param_func322_func101_003);
                r_rsip_func323();

                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000878U);
                r_rsip_func_sub005(0x00000448U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_func_sub001(0x00c00211U);

                r_rsip_func_sub004(0x0b040184U, 0x7edfb1abU);

                OFS_ADR = 544;

                r_rsip_func_sub012(0x1dd80000U, 0x0000b400U, 0x00000080U);

                r_rsip_func_sub009(0x00003222U);

                static const uint32_t Param_func322_func101_004[] =
                {
                    BSWAP_32BIG_C(0xe0d7af98U), BSWAP_32BIG_C(0xa0ad1c4fU), BSWAP_32BIG_C(0x827c4c63U), BSWAP_32BIG_C(
                        0xc5e8d48eU),
                };
                r_rsip_func101(Param_func322_func101_004);
                r_rsip_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00211U);
                r_rsip_func_sub002(0x00000a90U, 0x00000878U, 0x00000878U, 0x42420009U);

                r_rsip_func_sub009(0x0000f322U);

                static const uint32_t Param_func322_func101_005[] =
                {
                    BSWAP_32BIG_C(0xab147cacU), BSWAP_32BIG_C(0x428395a8U), BSWAP_32BIG_C(0x85ad4d9dU), BSWAP_32BIG_C(
                        0x3b279c5eU),
                };
                r_rsip_func101(Param_func322_func101_005);
                r_rsip_func324();

                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000878U);
                r_rsip_func_sub005(0x00000a90U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func322_func101_006[] =
                {
                    BSWAP_32BIG_C(0x71fb69beU), BSWAP_32BIG_C(0x6b3a4f64U), BSWAP_32BIG_C(0xc0d81691U), BSWAP_32BIG_C(
                        0x796efa90U),
                };
                r_rsip_func101(Param_func322_func101_006);
            }
        }
        else
        {
            static const uint32_t Param_func322_func101_007[] =
            {
                BSWAP_32BIG_C(0x669bfc98U), BSWAP_32BIG_C(0x3987b340U), BSWAP_32BIG_C(0x6da8173dU), BSWAP_32BIG_C(
                    0x48d3afe8U),
            };
            r_rsip_func101(Param_func322_func101_007);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
