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

rsip_ret_t r_rsip_p98i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00980001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00009801U);

    static const uint32_t Param_p98i_func101_001[] =
    {
        BSWAP_32BIG_C(0x6f2af897U), BSWAP_32BIG_C(0xdc8aff2cU), BSWAP_32BIG_C(0xdd350a55U), BSWAP_32BIG_C(0x58f7ce31U),
    };
    r_rsip_func101(Param_p98i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub009(0x00009801U);

    static const uint32_t Param_p98i_func101_002[] =
    {
        BSWAP_32BIG_C(0x9817fabeU), BSWAP_32BIG_C(0x37eebfa1U), BSWAP_32BIG_C(0x868f2d81U), BSWAP_32BIG_C(0xc2d319d3U),
    };
    r_rsip_func101(Param_p98i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p98i_func100_001[] =
    {
        BSWAP_32BIG_C(0x6cc95df6U), BSWAP_32BIG_C(0x18198491U), BSWAP_32BIG_C(0x90b765aaU), BSWAP_32BIG_C(0xbbe31650U),
    };
    r_rsip_func100(Param_p98i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p98i_func100_002[] =
    {
        BSWAP_32BIG_C(0x273c736dU), BSWAP_32BIG_C(0xa9dfd91aU), BSWAP_32BIG_C(0x46c636b9U), BSWAP_32BIG_C(0xe285b48fU),
    };
    r_rsip_func100(Param_p98i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p98i_func102_001[] =
        {
            BSWAP_32BIG_C(0x9ff86c98U), BSWAP_32BIG_C(0x298140c7U), BSWAP_32BIG_C(0x8c597677U), BSWAP_32BIG_C(
                0x4c5d3ebfU),
        };
        r_rsip_func102(Param_p98i_func102_001);
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

        static const uint32_t Param_p98i_func100_003[] =
        {
            BSWAP_32BIG_C(0x1aaca99eU), BSWAP_32BIG_C(0xddd79cafU), BSWAP_32BIG_C(0xce81b742U), BSWAP_32BIG_C(
                0x2d31a211U),
        };
        r_rsip_func100(Param_p98i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p98i_func101_003[] =
            {
                BSWAP_32BIG_C(0x7d714651U), BSWAP_32BIG_C(0xb063ac71U), BSWAP_32BIG_C(0x371a291eU), BSWAP_32BIG_C(
                    0xc3eca257U),
            };
            r_rsip_func101(Param_p98i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x00009802U);

            static const uint32_t Param_p98i_func101_004[] =
            {
                BSWAP_32BIG_C(0xb215da15U), BSWAP_32BIG_C(0x65e9e26dU), BSWAP_32BIG_C(0xa59e18f7U), BSWAP_32BIG_C(
                    0x67be66a7U),
            };
            r_rsip_func101(Param_p98i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x00009802U);

            static const uint32_t Param_p98i_func101_005[] =
            {
                BSWAP_32BIG_C(0xacdb6c57U), BSWAP_32BIG_C(0x87a954caU), BSWAP_32BIG_C(0x2fe75eebU), BSWAP_32BIG_C(
                    0x2411ec7dU),
            };
            r_rsip_func101(Param_p98i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1824H, 0x08000045U);
            r_rsip_func_sub001(0x00420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p98i_func100_004[] =
            {
                BSWAP_32BIG_C(0x3f997e63U), BSWAP_32BIG_C(0x3f05b76cU), BSWAP_32BIG_C(0xf51ac4dbU), BSWAP_32BIG_C(
                    0x9023e697U),
            };
            r_rsip_func100(Param_p98i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p98i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xa3dfd0abU), BSWAP_32BIG_C(0x4dfb32c6U), BSWAP_32BIG_C(0xe1da0373U), BSWAP_32BIG_C(
                        0x70ae69b6U),
                };
                r_rsip_func102(Param_p98i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p98i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x4e670a40U), BSWAP_32BIG_C(0x234b9b74U), BSWAP_32BIG_C(0x2f2fcb46U), BSWAP_32BIG_C(
                        0x0a67ef73U),
                };
                r_rsip_func101(Param_p98i_func101_006);
            }
        }

        WR1_PROG(REG_182CH, 0x00000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_p98i_func101_007[] =
        {
            BSWAP_32BIG_C(0xa1f385d3U), BSWAP_32BIG_C(0x69689757U), BSWAP_32BIG_C(0x0fba3851U), BSWAP_32BIG_C(
                0x639f167fU),
        };
        r_rsip_func101(Param_p98i_func101_007);

        return RSIP_RET_PASS;
    }
}
