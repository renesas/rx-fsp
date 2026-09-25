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

rsip_ret_t r_rsip_p97r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_Nonce[],
                        const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00970001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_State[1]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p97r_func100_001[] =
    {
        BSWAP_32BIG_C(0x5af83a3bU), BSWAP_32BIG_C(0x03a0a7a2U), BSWAP_32BIG_C(0x49924325U), BSWAP_32BIG_C(0x22d5635fU),
    };
    r_rsip_func100(Param_p97r_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p97r_func102_001[] =
        {
            BSWAP_32BIG_C(0x982c64ddU), BSWAP_32BIG_C(0xf5e91b9aU), BSWAP_32BIG_C(0xcf14d4edU), BSWAP_32BIG_C(
                0x3f1b429cU),
        };
        r_rsip_func102(Param_p97r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WAIT_STS(REG_1C30H, 8, 0);
        WR1_PROG(REG_143CH, 0x00001c00U);

        static const uint32_t Param_p97r_func100_002[] =
        {
            BSWAP_32BIG_C(0x4f33ea16U), BSWAP_32BIG_C(0xfbf5cf44U), BSWAP_32BIG_C(0xbdcb2af0U), BSWAP_32BIG_C(
                0x1cb354ceU),
        };
        r_rsip_func100(Param_p97r_func100_002);
        WR1_PROG(REG_1C00H, 0x00000001U);

        WR1_PROG(REG_1C04H, 0x00001001U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00003467U);

        r_rsip_func_sub009(0x00009702U);

        static const uint32_t Param_p97r_func101_001[] =
        {
            BSWAP_32BIG_C(0xf2524471U), BSWAP_32BIG_C(0x362ec8bfU), BSWAP_32BIG_C(0x8001719eU), BSWAP_32BIG_C(
                0x9a34e286U),
        };
        r_rsip_func101(Param_p97r_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000030U);

        r_rsip_func_sub009(0x00009702U);

        static const uint32_t Param_p97r_func101_002[] =
        {
            BSWAP_32BIG_C(0xcff9fbe3U), BSWAP_32BIG_C(0xb7322094U), BSWAP_32BIG_C(0x4a428222U), BSWAP_32BIG_C(
                0xaf51aec5U),
        };
        r_rsip_func101(Param_p97r_func101_002);
        r_rsip_func044();

        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        r_rsip_func_sub001(0x01c20021U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p97r_func100_003[] =
        {
            BSWAP_32BIG_C(0x9910ecb1U), BSWAP_32BIG_C(0xc74e57afU), BSWAP_32BIG_C(0xb0c2c100U), BSWAP_32BIG_C(
                0xdb3cb7ebU),
        };
        r_rsip_func100(Param_p97r_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p97r_func102_002[] =
            {
                BSWAP_32BIG_C(0x3c38e585U), BSWAP_32BIG_C(0x04d140a6U), BSWAP_32BIG_C(0x8b464d00U), BSWAP_32BIG_C(
                    0xc182374bU),
            };
            r_rsip_func102(Param_p97r_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010000U);
            WR1_PROG(REG_1420H, InData_Cmd[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1C04H, 0x00010011U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C10H, InData_State[1]);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C14H, InData_State[2]);

            WR1_PROG(REG_1C04H, 0x00010010U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C08H, InData_State[0]);

            r_rsip_func_sub017(0x38000c00U, 0x00260000U);

            static const uint32_t Param_p97r_func100_004[] =
            {
                BSWAP_32BIG_C(0x6f13acebU), BSWAP_32BIG_C(0x61775104U), BSWAP_32BIG_C(0xa7255d35U), BSWAP_32BIG_C(
                    0x65653b99U),
            };
            r_rsip_func100(Param_p97r_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1C04H, 0x00010011U);

                static const uint32_t Param_p97r_func101_003[] =
                {
                    BSWAP_32BIG_C(0x3e47fac8U), BSWAP_32BIG_C(0x618e1a08U), BSWAP_32BIG_C(0x3a167153U), BSWAP_32BIG_C(
                        0xb10dda7cU),
                };
                r_rsip_func101(Param_p97r_func101_003);
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00010031U);

                static const uint32_t Param_p97r_func101_004[] =
                {
                    BSWAP_32BIG_C(0x220939ceU), BSWAP_32BIG_C(0x7aca85deU), BSWAP_32BIG_C(0xfac34908U), BSWAP_32BIG_C(
                        0x87790514U),
                };
                r_rsip_func101(Param_p97r_func101_004);
            }

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[2]);

            for (iLoop = 3; iLoop < 10U; iLoop++)
            {
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_PROG(REG_1C28H, InData_State[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x000034e3U);

            r_rsip_func_sub009(0x00009703U);

            static const uint32_t Param_p97r_func101_005[] =
            {
                BSWAP_32BIG_C(0xbad83201U), BSWAP_32BIG_C(0x3cfeda69U), BSWAP_32BIG_C(0xed1c2bb2U), BSWAP_32BIG_C(
                    0x375f1f3bU),
            };
            r_rsip_func101(Param_p97r_func101_005);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x019c2adaU);

            r_rsip_func_sub009(0x00009703U);

            static const uint32_t Param_p97r_func101_006[] =
            {
                BSWAP_32BIG_C(0x5b68348aU), BSWAP_32BIG_C(0x8c783168U), BSWAP_32BIG_C(0x97e38444U), BSWAP_32BIG_C(
                    0xcda9af38U),
            };
            r_rsip_func101(Param_p97r_func101_006);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000000c2U, 0x40000000U, 0xe8009104U);
            WR1_PROG(REG_1420H, InData_State[11]);

            WR1_PROG(REG_1608H, 0x80010040U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_State[12]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p97r_func100_005[] =
            {
                BSWAP_32BIG_C(0xc0b5e353U), BSWAP_32BIG_C(0x43a86530U), BSWAP_32BIG_C(0x4d21d5c7U), BSWAP_32BIG_C(
                    0x5dcb7e48U),
            };
            r_rsip_func100(Param_p97r_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p97r_func102_003[] =
                {
                    BSWAP_32BIG_C(0xf600a881U), BSWAP_32BIG_C(0xc9a2c959U), BSWAP_32BIG_C(0x398c8331U), BSWAP_32BIG_C(
                        0x28617484U),
                };
                r_rsip_func102(Param_p97r_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p97r_func100_006[] =
                {
                    BSWAP_32BIG_C(0x07ed4978U), BSWAP_32BIG_C(0xa4239b1dU), BSWAP_32BIG_C(0x43fdfa40U), BSWAP_32BIG_C(
                        0x0d4b31b0U),
                };
                r_rsip_func100(Param_p97r_func100_006);
                r_rsip_func_sub016(0x81010040U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub006(0x38008840U, 0x00000001U, 0x00260000U);

                static const uint32_t Param_p97r_func100_007[] =
                {
                    BSWAP_32BIG_C(0x92a34cf8U), BSWAP_32BIG_C(0xa096f1e9U), BSWAP_32BIG_C(0x2388ed53U), BSWAP_32BIG_C(
                        0x5b01ccccU),
                };
                r_rsip_func100(Param_p97r_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p97r_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xa261363eU), BSWAP_32BIG_C(0xa6a7b70cU), BSWAP_32BIG_C(0x56394b1eU),
                        BSWAP_32BIG_C(0xbd375b06U),
                    };
                    r_rsip_func101(Param_p97r_func101_007);

                    return RSIP_RET_PASS_1;
                }
                else
                {
                    static const uint32_t Param_p97r_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x2ab34d4dU), BSWAP_32BIG_C(0xabdfd769U), BSWAP_32BIG_C(0xc7bd8c44U),
                        BSWAP_32BIG_C(0x2587acfaU),
                    };
                    r_rsip_func101(Param_p97r_func101_008);

                    return RSIP_RET_PASS_2;
                }
            }
        }
    }
}
