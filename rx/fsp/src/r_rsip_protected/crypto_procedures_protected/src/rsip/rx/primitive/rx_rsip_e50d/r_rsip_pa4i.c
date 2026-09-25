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

rsip_ret_t r_rsip_pa4i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00a40001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000a401U);

    static const uint32_t Param_pa4i_func101_001[] =
    {
        BSWAP_32BIG_C(0x52090be4U), BSWAP_32BIG_C(0x56d57973U), BSWAP_32BIG_C(0xc7d46bb5U), BSWAP_32BIG_C(0x32a49da9U),
    };
    r_rsip_func101(Param_pa4i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x0000a401U);

    static const uint32_t Param_pa4i_func101_002[] =
    {
        BSWAP_32BIG_C(0xa780a63fU), BSWAP_32BIG_C(0xfb724d6aU), BSWAP_32BIG_C(0xc3c734d1U), BSWAP_32BIG_C(0x1b111114U),
    };
    r_rsip_func101(Param_pa4i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_pa4i_func100_001[] =
    {
        BSWAP_32BIG_C(0x6c998881U), BSWAP_32BIG_C(0x19125d9aU), BSWAP_32BIG_C(0xed4df5a3U), BSWAP_32BIG_C(0xd88b9a0eU),
    };
    r_rsip_func100(Param_pa4i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_pa4i_func100_002[] =
    {
        BSWAP_32BIG_C(0xe0b95eb0U), BSWAP_32BIG_C(0xa58d85eeU), BSWAP_32BIG_C(0x217d547eU), BSWAP_32BIG_C(0x745d840aU),
    };
    r_rsip_func100(Param_pa4i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pa4i_func100_003[] =
    {
        BSWAP_32BIG_C(0x640eb5c3U), BSWAP_32BIG_C(0x97bb3223U), BSWAP_32BIG_C(0x24fd6158U), BSWAP_32BIG_C(0xb8db26d6U),
    };
    r_rsip_func100(Param_pa4i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pa4i_func102_001[] =
        {
            BSWAP_32BIG_C(0x519d83c5U), BSWAP_32BIG_C(0xf96349f7U), BSWAP_32BIG_C(0xdea586c9U), BSWAP_32BIG_C(
                0x8fe2f73aU),
        };
        r_rsip_func102(Param_pa4i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010080U);
        WR1_PROG(REG_1420H, InData_IVType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000c84U, 0x00260000U);

        static const uint32_t Param_pa4i_func100_004[] =
        {
            BSWAP_32BIG_C(0xfbcbe87eU), BSWAP_32BIG_C(0x9d3f82f4U), BSWAP_32BIG_C(0x627ab71dU), BSWAP_32BIG_C(
                0x2d70aef9U),
        };
        r_rsip_func100(Param_pa4i_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_pa4i_func101_003[] =
            {
                BSWAP_32BIG_C(0x3f0e5c55U), BSWAP_32BIG_C(0xdbcfd8d9U), BSWAP_32BIG_C(0x770e1b37U), BSWAP_32BIG_C(
                    0x842c29d4U),
            };
            r_rsip_func101(Param_pa4i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x0000a402U);

            static const uint32_t Param_pa4i_func101_004[] =
            {
                BSWAP_32BIG_C(0xf4c3fa28U), BSWAP_32BIG_C(0x8e54b607U), BSWAP_32BIG_C(0xf92b61e6U), BSWAP_32BIG_C(
                    0xd28da3acU),
            };
            r_rsip_func101(Param_pa4i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x0000a402U);

            static const uint32_t Param_pa4i_func101_005[] =
            {
                BSWAP_32BIG_C(0x0528367aU), BSWAP_32BIG_C(0xe98c6879U), BSWAP_32BIG_C(0xee3137b8U), BSWAP_32BIG_C(
                    0xcff4686dU),
            };
            r_rsip_func101(Param_pa4i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1824H, 0x08000045U);
            r_rsip_func_sub001(0x00420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pa4i_func100_005[] =
            {
                BSWAP_32BIG_C(0xf997af7aU), BSWAP_32BIG_C(0x2919d5dbU), BSWAP_32BIG_C(0xc657af6cU), BSWAP_32BIG_C(
                    0xc6bc17fbU),
            };
            r_rsip_func100(Param_pa4i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pa4i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x24ecba7eU), BSWAP_32BIG_C(0x52083231U), BSWAP_32BIG_C(0x6c33328bU), BSWAP_32BIG_C(
                        0x91dbb891U),
                };
                r_rsip_func102(Param_pa4i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pa4i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x2bfc8b95U), BSWAP_32BIG_C(0xf93b845eU), BSWAP_32BIG_C(0x8b7896ecU), BSWAP_32BIG_C(
                        0x63a4beb6U),
                };
                r_rsip_func101(Param_pa4i_func101_006);
            }
        }

        WR1_PROG(REG_182CH, 0x40000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_pa4i_func101_007[] =
        {
            BSWAP_32BIG_C(0xbdc70fadU), BSWAP_32BIG_C(0x26f62093U), BSWAP_32BIG_C(0x04909362U), BSWAP_32BIG_C(
                0x52f1295bU),
        };
        r_rsip_func101(Param_pa4i_func101_007);

        return RSIP_RET_PASS;
    }
}
