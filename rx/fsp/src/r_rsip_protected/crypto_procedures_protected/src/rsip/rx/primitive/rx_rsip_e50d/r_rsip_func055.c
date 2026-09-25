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

void r_rsip_func055 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000379dU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800db40U, 0x00260000U);

        static const uint32_t Param_func055_func100_001[] =
        {
            BSWAP_32BIG_C(0x84f107b8U), BSWAP_32BIG_C(0x3436e484U), BSWAP_32BIG_C(0x5e2d5fdeU), BSWAP_32BIG_C(
                0x8917ff88U),
        };
        r_rsip_func100(Param_func055_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x2020000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            WR1_PROG(REG_1404H, 0x1a380000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);

            static const uint32_t Param_func055_func100_002[] =
            {
                BSWAP_32BIG_C(0x6075a5cdU), BSWAP_32BIG_C(0xe92fbb66U), BSWAP_32BIG_C(0xa89a40b7U), BSWAP_32BIG_C(
                    0x288f43deU),
            };
            r_rsip_func100(Param_func055_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1404H, 0x13180000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x19300000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x13180000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19300000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000428U);
                r_rsip_func_sub005(0x00000428U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000a40U);
                r_rsip_func_sub005(0x00000a40U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13180000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x19300000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func055_func101_001[] =
                {
                    BSWAP_32BIG_C(0x6fe8eeaeU), BSWAP_32BIG_C(0x4e505575U), BSWAP_32BIG_C(0xb3e14b90U), BSWAP_32BIG_C(
                        0x7587a359U),
                };
                r_rsip_func101(Param_func055_func101_001);
            }
            else
            {
                r_rsip_func_sub030(0x1ec80000U, 0x00000b7bU, 0x81c0001bU);
                r_rsip_func_sub001(0x00c00011U);
                r_rsip_func_sub001(0x00c90101U);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00111U);
                r_rsip_func_sub002(0x00000428U, 0x00000838U, 0x00000838U, 0x22220009U);

                r_rsip_func_sub009(0x00000f55U);

                static const uint32_t Param_func055_func101_002[] =
                {
                    BSWAP_32BIG_C(0x7c189138U), BSWAP_32BIG_C(0x83feee74U), BSWAP_32BIG_C(0x2245adc5U), BSWAP_32BIG_C(
                        0x34514037U),
                };
                r_rsip_func101(Param_func055_func101_002);
                r_rsip_func304();

                WR1_PROG(REG_1404H, 0x17280000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000428U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13180000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x1ec80000U);
                r_rsip_func_sub001(0x00c00111U);

                r_rsip_func_sub004(0x0b040184U, 0x9bee78e8U);

                OFS_ADR = 288;

                r_rsip_func_sub012(0x1ed80000U, 0x0000b400U, 0x00000040U);

                r_rsip_func_sub009(0x00000f55U);

                static const uint32_t Param_func055_func101_003[] =
                {
                    BSWAP_32BIG_C(0xcabe330bU), BSWAP_32BIG_C(0x7e99e56bU), BSWAP_32BIG_C(0x54504d25U), BSWAP_32BIG_C(
                        0xd51ff16eU),
                };
                r_rsip_func101(Param_func055_func101_003);
                r_rsip_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00111U);
                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000838U, 0x22220009U);

                r_rsip_func_sub009(0x00000f55U);

                static const uint32_t Param_func055_func101_004[] =
                {
                    BSWAP_32BIG_C(0xcb124994U), BSWAP_32BIG_C(0x8dc1c592U), BSWAP_32BIG_C(0x83263450U), BSWAP_32BIG_C(
                        0x99edda5eU),
                };
                r_rsip_func101(Param_func055_func101_004);
                r_rsip_func305();

                WR1_PROG(REG_1404H, 0x17280000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x19300000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func055_func101_005[] =
                {
                    BSWAP_32BIG_C(0x395add04U), BSWAP_32BIG_C(0xe931cb5fU), BSWAP_32BIG_C(0x8a1ba4ffU), BSWAP_32BIG_C(
                        0xb4da0aceU),
                };
                r_rsip_func101(Param_func055_func101_005);
            }
        }
        else
        {
            static const uint32_t Param_func055_func101_006[] =
            {
                BSWAP_32BIG_C(0x541b2babU), BSWAP_32BIG_C(0xe315e7aeU), BSWAP_32BIG_C(0x3fdf150dU), BSWAP_32BIG_C(
                    0x23b365ecU),
            };
            r_rsip_func101(Param_func055_func101_006);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
