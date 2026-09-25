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

rsip_ret_t r_rsip_p97i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_Nonce[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_DataALen[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00970001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p97i_func100_001[] =
    {
        BSWAP_32BIG_C(0x5af83a3bU), BSWAP_32BIG_C(0x03a0a7a2U), BSWAP_32BIG_C(0x49924325U), BSWAP_32BIG_C(0x22d5635fU),
    };
    r_rsip_func100(Param_p97i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p97i_func102_001[] =
        {
            BSWAP_32BIG_C(0x982c64ddU), BSWAP_32BIG_C(0xf5e91b9aU), BSWAP_32BIG_C(0xcf14d4edU), BSWAP_32BIG_C(
                0x3f1b429cU),
        };
        r_rsip_func102(Param_p97i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p97i_func100_002[] =
        {
            BSWAP_32BIG_C(0x95c368f8U), BSWAP_32BIG_C(0x368f9024U), BSWAP_32BIG_C(0xa5fbc163U), BSWAP_32BIG_C(
                0xf1dacc63U),
        };
        r_rsip_func100(Param_p97i_func100_002);
        WR1_PROG(REG_1C00H, 0x00000001U);

        WR1_PROG(REG_1C04H, 0x00001001U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00003467U);

        r_rsip_func_sub009(0x00009701U);

        static const uint32_t Param_p97i_func101_001[] =
        {
            BSWAP_32BIG_C(0x5d4df5c8U), BSWAP_32BIG_C(0x1bbff8e0U), BSWAP_32BIG_C(0xccdc9a5bU), BSWAP_32BIG_C(
                0xab289b8bU),
        };
        r_rsip_func101(Param_p97i_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000030U);

        r_rsip_func_sub009(0x00009701U);

        static const uint32_t Param_p97i_func101_002[] =
        {
            BSWAP_32BIG_C(0x7455d87dU), BSWAP_32BIG_C(0xbf801f0aU), BSWAP_32BIG_C(0xab9cbe5dU), BSWAP_32BIG_C(
                0xdd3d9022U),
        };
        r_rsip_func101(Param_p97i_func101_002);
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

        static const uint32_t Param_p97i_func100_003[] =
        {
            BSWAP_32BIG_C(0x5c4a331aU), BSWAP_32BIG_C(0xc3cc446dU), BSWAP_32BIG_C(0xce52aea4U), BSWAP_32BIG_C(
                0xd72fd337U),
        };
        r_rsip_func100(Param_p97i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p97i_func102_002[] =
            {
                BSWAP_32BIG_C(0x615b10dfU), BSWAP_32BIG_C(0x80ef9ba3U), BSWAP_32BIG_C(0x45917a85U), BSWAP_32BIG_C(
                    0xdc49e5f9U),
            };
            r_rsip_func102(Param_p97i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010000U);
            WR1_PROG(REG_1420H, InData_Cmd[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub017(0x38000c00U, 0x00260000U);

            static const uint32_t Param_p97i_func100_004[] =
            {
                BSWAP_32BIG_C(0xe9c1f537U), BSWAP_32BIG_C(0xe758e2c4U), BSWAP_32BIG_C(0x4fc1b4bdU), BSWAP_32BIG_C(
                    0x77b91877U),
            };
            r_rsip_func100(Param_p97i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1C04H, 0x00000011U);

                static const uint32_t Param_p97i_func101_003[] =
                {
                    BSWAP_32BIG_C(0x4e5e1f26U), BSWAP_32BIG_C(0x61ded693U), BSWAP_32BIG_C(0xfd9b38b3U), BSWAP_32BIG_C(
                        0xb51abb5dU),
                };
                r_rsip_func101(Param_p97i_func101_003);
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00000031U);

                static const uint32_t Param_p97i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xe91e7df4U), BSWAP_32BIG_C(0xf774547aU), BSWAP_32BIG_C(0x57901445U), BSWAP_32BIG_C(
                        0x4a7a55f6U),
                };
                r_rsip_func101(Param_p97i_func101_004);
            }

            static const uint32_t Param_p97i_func100_005[] =
            {
                BSWAP_32BIG_C(0xe2238d20U), BSWAP_32BIG_C(0xd7aa8bcfU), BSWAP_32BIG_C(0x0539f753U), BSWAP_32BIG_C(
                    0xa1560f66U),
            };
            r_rsip_func100(Param_p97i_func100_005);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C10H, InData_TextLen[0]);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C14H, InData_DataALen[0]);

            WR1_PROG(REG_1C08H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[2]);

            WAIT_STS(REG_1C30H, 0, 1);

            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000001U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            static const uint32_t Param_p97i_func101_005[] =
            {
                BSWAP_32BIG_C(0xa44dbb34U), BSWAP_32BIG_C(0x547f9a74U), BSWAP_32BIG_C(0xd1202b87U), BSWAP_32BIG_C(
                    0x1a041208U),
            };
            r_rsip_func101(Param_p97i_func101_005);

            return RSIP_RET_PASS;
        }
    }
}
