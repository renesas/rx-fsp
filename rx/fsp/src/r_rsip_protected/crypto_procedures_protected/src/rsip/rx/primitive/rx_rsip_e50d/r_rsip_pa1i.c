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

rsip_ret_t r_rsip_pa1i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00a10001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x0000a101U);

    static const uint32_t Param_pa1i_func101_001[] =
    {
        BSWAP_32BIG_C(0x7451d181U), BSWAP_32BIG_C(0x309fdc2fU), BSWAP_32BIG_C(0xc3d958f9U), BSWAP_32BIG_C(0xcd56af3dU),
    };
    r_rsip_func101(Param_pa1i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub009(0x0000a101U);

    static const uint32_t Param_pa1i_func101_002[] =
    {
        BSWAP_32BIG_C(0x9ed7a288U), BSWAP_32BIG_C(0x350ca472U), BSWAP_32BIG_C(0x2a0cc0adU), BSWAP_32BIG_C(0x0045003fU),
    };
    r_rsip_func101(Param_pa1i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_pa1i_func100_001[] =
    {
        BSWAP_32BIG_C(0x3da18291U), BSWAP_32BIG_C(0x52db1097U), BSWAP_32BIG_C(0x4ad2cb1cU), BSWAP_32BIG_C(0x9310664fU),
    };
    r_rsip_func100(Param_pa1i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_pa1i_func100_002[] =
    {
        BSWAP_32BIG_C(0x3fce856fU), BSWAP_32BIG_C(0x72993987U), BSWAP_32BIG_C(0xc2e6b108U), BSWAP_32BIG_C(0xc6ab7960U),
    };
    r_rsip_func100(Param_pa1i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pa1i_func100_003[] =
    {
        BSWAP_32BIG_C(0x30b23d85U), BSWAP_32BIG_C(0x4cd14145U), BSWAP_32BIG_C(0xabd533acU), BSWAP_32BIG_C(0x26828f43U),
    };
    r_rsip_func100(Param_pa1i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pa1i_func102_001[] =
        {
            BSWAP_32BIG_C(0x1292f132U), BSWAP_32BIG_C(0x9e917ad7U), BSWAP_32BIG_C(0x315c6e43U), BSWAP_32BIG_C(
                0x05a04c34U),
        };
        r_rsip_func102(Param_pa1i_func102_001);
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

        static const uint32_t Param_pa1i_func100_004[] =
        {
            BSWAP_32BIG_C(0x12c5ea22U), BSWAP_32BIG_C(0xa1870241U), BSWAP_32BIG_C(0x2a600a41U), BSWAP_32BIG_C(
                0x78b2404fU),
        };
        r_rsip_func100(Param_pa1i_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_pa1i_func101_003[] =
            {
                BSWAP_32BIG_C(0xc1cf89a1U), BSWAP_32BIG_C(0x6bf1a6d7U), BSWAP_32BIG_C(0x21eb49a5U), BSWAP_32BIG_C(
                    0x66d98d28U),
            };
            r_rsip_func101(Param_pa1i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x0000a102U);

            static const uint32_t Param_pa1i_func101_004[] =
            {
                BSWAP_32BIG_C(0xec5b8897U), BSWAP_32BIG_C(0xd3346b98U), BSWAP_32BIG_C(0x69cab16dU), BSWAP_32BIG_C(
                    0x22208141U),
            };
            r_rsip_func101(Param_pa1i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01b98ba2U);

            r_rsip_func_sub009(0x0000a102U);

            static const uint32_t Param_pa1i_func101_005[] =
            {
                BSWAP_32BIG_C(0x221815c2U), BSWAP_32BIG_C(0x363440a5U), BSWAP_32BIG_C(0x8eb41b4cU), BSWAP_32BIG_C(
                    0xfe99ee4aU),
            };
            r_rsip_func101(Param_pa1i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1824H, 0x08000045U);
            r_rsip_func_sub001(0x00420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pa1i_func100_005[] =
            {
                BSWAP_32BIG_C(0x027c1454U), BSWAP_32BIG_C(0x53472586U), BSWAP_32BIG_C(0x31058454U), BSWAP_32BIG_C(
                    0xa0baf784U),
            };
            r_rsip_func100(Param_pa1i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pa1i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x5b170a2aU), BSWAP_32BIG_C(0xf0d44964U), BSWAP_32BIG_C(0x81c065c5U), BSWAP_32BIG_C(
                        0xb10b3784U),
                };
                r_rsip_func102(Param_pa1i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pa1i_func101_006[] =
                {
                    BSWAP_32BIG_C(0xedb2305eU), BSWAP_32BIG_C(0x28800b34U), BSWAP_32BIG_C(0x5366e8e1U), BSWAP_32BIG_C(
                        0xa5dccc4dU),
                };
                r_rsip_func101(Param_pa1i_func101_006);
            }
        }

        WR1_PROG(REG_182CH, 0x40000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_pa1i_func101_007[] =
        {
            BSWAP_32BIG_C(0x01452f61U), BSWAP_32BIG_C(0xa991ca3aU), BSWAP_32BIG_C(0x82e6068aU), BSWAP_32BIG_C(
                0x2530f993U),
        };
        r_rsip_func101(Param_pa1i_func101_007);

        return RSIP_RET_PASS;
    }
}
