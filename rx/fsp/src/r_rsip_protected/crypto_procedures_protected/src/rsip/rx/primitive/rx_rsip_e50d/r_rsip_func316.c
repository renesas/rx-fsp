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

void r_rsip_func316 (void)
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

        static const uint32_t Param_func316_func100_001[] =
        {
            BSWAP_32BIG_C(0x67d48127U), BSWAP_32BIG_C(0x02371d26U), BSWAP_32BIG_C(0xb10604deU), BSWAP_32BIG_C(
                0x16da8f76U),
        };
        r_rsip_func100(Param_func316_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x3030000cU, 0x00010001U);
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

            static const uint32_t Param_func316_func100_002[] =
            {
                BSWAP_32BIG_C(0x10544b02U), BSWAP_32BIG_C(0x78ce3d36U), BSWAP_32BIG_C(0x0d6cdc97U), BSWAP_32BIG_C(
                    0x75c27db8U),
            };
            r_rsip_func100(Param_func316_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1404H, 0x12980000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x18b00000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x12980000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x18b00000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000428U);
                r_rsip_func_sub005(0x00000428U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000a40U);
                r_rsip_func_sub005(0x00000a40U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x12980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x18b00000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func316_func101_001[] =
                {
                    BSWAP_32BIG_C(0x80b166beU), BSWAP_32BIG_C(0x4a76745dU), BSWAP_32BIG_C(0xbc30126dU), BSWAP_32BIG_C(
                        0x9f37818bU),
                };
                r_rsip_func101(Param_func316_func101_001);
            }
            else
            {
                r_rsip_func_sub030(0x1e480000U, 0x00000b7bU, 0x81e0001bU);
                r_rsip_func_sub001(0x00c00011U);
                r_rsip_func_sub001(0x00c90181U);

                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00191U);
                r_rsip_func_sub002(0x00000428U, 0x00000838U, 0x00000838U, 0x32320009U);

                r_rsip_func_sub009(0x0000f316U);

                static const uint32_t Param_func316_func101_002[] =
                {
                    BSWAP_32BIG_C(0x11ab78f2U), BSWAP_32BIG_C(0xbe03f001U), BSWAP_32BIG_C(0x2a6ff1d6U), BSWAP_32BIG_C(
                        0x1f2893ccU),
                };
                r_rsip_func101(Param_func316_func101_002);
                r_rsip_func319();

                WR1_PROG(REG_1404H, 0x16a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000428U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x12980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x1e480000U);
                r_rsip_func_sub001(0x00c00191U);

                r_rsip_func_sub004(0x0b040184U, 0xe4f152fdU);

                OFS_ADR = 416;

                r_rsip_func_sub012(0x1e580000U, 0x0000b400U, 0x00000060U);

                r_rsip_func_sub009(0x0000f316U);

                static const uint32_t Param_func316_func101_003[] =
                {
                    BSWAP_32BIG_C(0x0b8a3dfcU), BSWAP_32BIG_C(0x0c9fbae0U), BSWAP_32BIG_C(0x3c7326aaU), BSWAP_32BIG_C(
                        0x07dd6d83U),
                };
                r_rsip_func101(Param_func316_func101_003);
                r_rsip_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00191U);
                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000838U, 0x32320009U);

                r_rsip_func_sub009(0x0000f316U);

                static const uint32_t Param_func316_func101_004[] =
                {
                    BSWAP_32BIG_C(0x31a20570U), BSWAP_32BIG_C(0x2d3deddeU), BSWAP_32BIG_C(0xa388a18fU), BSWAP_32BIG_C(
                        0x7881ad4cU),
                };
                r_rsip_func101(Param_func316_func101_004);
                r_rsip_func320();

                WR1_PROG(REG_1404H, 0x16a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x18b00000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func316_func101_005[] =
                {
                    BSWAP_32BIG_C(0x7166354fU), BSWAP_32BIG_C(0xd0822461U), BSWAP_32BIG_C(0xc340951dU), BSWAP_32BIG_C(
                        0x6022e9ccU),
                };
                r_rsip_func101(Param_func316_func101_005);
            }
        }
        else
        {
            static const uint32_t Param_func316_func101_006[] =
            {
                BSWAP_32BIG_C(0x74ddce85U), BSWAP_32BIG_C(0xad285a22U), BSWAP_32BIG_C(0xb2b62d10U), BSWAP_32BIG_C(
                    0x628fca82U),
            };
            r_rsip_func101(Param_func316_func101_006);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
