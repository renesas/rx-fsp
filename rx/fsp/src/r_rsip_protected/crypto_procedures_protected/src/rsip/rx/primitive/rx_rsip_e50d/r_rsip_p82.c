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

rsip_ret_t r_rsip_p82 (void)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00820001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub004(0x0b070194U, 0x01c7ba56U);

    r_rsip_func_sub004(0x0b070184U, 0x0199829aU);

    r_rsip_func_sub004(0x08000074U, 0x00000000U);

    r_rsip_func_sub021(0x3000a820U, 0x00000003U, 0x00010020U, 0x00000821U);
    WR1_PROG(REG_1600H, 0x00000080U);

    WAIT_STS(REG_1708H, 0, 0);
    WR1_PROG(REG_143CH, 0x00001200U);
    WAIT_STS(REG_1708H, 0, 0);
    WR1_PROG(REG_1704H, 0x00000080U);

    r_rsip_func_sub022(0x00000863U, 0x0000b540U, 0x00000028U);

    for (jLoop = 0U; jLoop < 3U; jLoop++)
    {
        static const uint32_t Param_p82_func100_001[] =
        {
            BSWAP_32BIG_C(0x0d3a7ae4U), BSWAP_32BIG_C(0xebdebb2bU), BSWAP_32BIG_C(0xbe85e46cU), BSWAP_32BIG_C(
                0x0b5c0cd8U),
        };
        r_rsip_func100(Param_p82_func100_001);
        r_rsip_func_sub021(0x00000884U, 0x000008a5U, 0x0000b4c0U, 0x00000013U);

        r_rsip_func_sub021(0x0000b4e0U, 0x00000355U, 0x0000b500U, 0x000000aaU);

        r_rsip_func_sub014(0x00007c01U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WAIT_STS(REG_1708H, 0, 0);
            WAIT_STS(REG_1708H, 0, 0);
            WR1_PROG(REG_1704H, 0x00200007U);

            static const uint32_t Param_p82_func101_001[] =
            {
                BSWAP_32BIG_C(0xa3fb6899U), BSWAP_32BIG_C(0xa9992ab8U), BSWAP_32BIG_C(0x16faf2baU), BSWAP_32BIG_C(
                    0x1048a741U),
            };
            r_rsip_func101(Param_p82_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WAIT_STS(REG_1708H, 0, 0);
            WAIT_STS(REG_1708H, 0, 0);
            WR1_PROG(REG_1704H, 0x00200005U);

            static const uint32_t Param_p82_func101_002[] =
            {
                BSWAP_32BIG_C(0x186d68ccU), BSWAP_32BIG_C(0xf41107f9U), BSWAP_32BIG_C(0xdf6dfbe0U), BSWAP_32BIG_C(
                    0x7cb3edacU),
            };
            r_rsip_func101(Param_p82_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WAIT_STS(REG_1708H, 0, 0);
            WAIT_STS(REG_1708H, 0, 0);
            WR1_PROG(REG_1704H, 0x00200006U);

            static const uint32_t Param_p82_func101_003[] =
            {
                BSWAP_32BIG_C(0x98c1ac3dU), BSWAP_32BIG_C(0xe76e17bfU), BSWAP_32BIG_C(0xf13770f2U), BSWAP_32BIG_C(
                    0x2eb34a75U),
            };
            r_rsip_func101(Param_p82_func101_003);
        }

        WR1_PROG(REG_1A2CH, 0x40000700U);
        WR1_PROG(REG_1A24H, 0x0e3c8407U);
        r_rsip_func_sub001(0x00840081U);
        WAIT_STS(REG_1708H, 2, 1);
        WR1_PROG(REG_143CH, 0x00001200U);

        WAIT_STS(REG_1A28H, 6, 0);
        WR1_PROG(REG_143CH, 0x00000a00U);
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1608H, 0x808a0000U);
        r_rsip_func_sub001(0x03440029U);

        r_rsip_func_sub021(0x000038a0U, 0x00003405U, 0x00002804U, 0x342028e0U);
        r_rsip_func_sub021(0x10005066U, 0x34202808U, 0x10005066U, 0x00003485U);

        r_rsip_func_sub021(0x0000b4e0U, 0x0000005AU, 0x00000842U, 0x000008c6U);

        r_rsip_func_sub021(0x0000b480U, 0x00000004U, 0x0000b4a0U, 0x00000002U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub021(0x01003804U, 0x342028e0U, 0x10005066U, 0x00002440U);

            WR1_PROG(REG_1600H, 0x00002cc0U);

            WR1_PROG(REG_1600H, 0x00002485U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x38008840U);
        r_rsip_func_sub011(0x00000100U);

        r_rsip_func_sub021(0x0000b4e0U, 0x00000037U, 0x0000b480U, 0x00000024U);

        r_rsip_func_sub021(0x01003804U, 0x342028e0U, 0x10005066U, 0x00002cc0U);

        r_rsip_func_sub021(0x0000b480U, 0x00000026U, 0x01003804U, 0x342028e0U);
        WR1_PROG(REG_1600H, 0x10005066U);

        r_rsip_func_sub004(0x0c300104U, 0x00000000U);
        WR1_PROG(REG_1608H, 0x8084000aU);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1600H, 0x0000a540U);
        WR1_PROG(REG_1600H, 0x00000010U);

        WAIT_STS(REG_1708H, 0, 0);
        WR1_PROG(REG_143CH, 0x00001200U);
        WAIT_STS(REG_1708H, 0, 0);
        WR1_PROG(REG_1704H, 0x00000080U);

        static const uint32_t Param_p82_func101_004[] =
        {
            BSWAP_32BIG_C(0xbd08755bU), BSWAP_32BIG_C(0x9ee6b263U), BSWAP_32BIG_C(0x32b6a573U), BSWAP_32BIG_C(
                0x97c94183U),
        };
        r_rsip_func101(Param_p82_func101_004);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x38008940U);
    r_rsip_func_sub011(0x00000058U);

    WR1_PROG(REG_1600H, 0x00002c20U);

    r_rsip_func_sub006(0x38008860U, 0x00000000U, 0x00A60000U);

    static const uint32_t Param_p82_func100_002[] =
    {
        BSWAP_32BIG_C(0xdb701d61U), BSWAP_32BIG_C(0x38b5a4d1U), BSWAP_32BIG_C(0xb113d544U), BSWAP_32BIG_C(0xb430e3eeU),
    };
    r_rsip_func100(Param_p82_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p82_func102_001[] =
        {
            BSWAP_32BIG_C(0x6a7eda76U), BSWAP_32BIG_C(0x8bcf51f4U), BSWAP_32BIG_C(0xa588276cU), BSWAP_32BIG_C(
                0xe4747c68U),
        };
        r_rsip_func102(Param_p82_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_RETRY;
    }
    else
    {
        static const uint32_t Param_p82_func100_003[] =
        {
            BSWAP_32BIG_C(0xebd8332aU), BSWAP_32BIG_C(0xa11152a1U), BSWAP_32BIG_C(0xa8a9a311U), BSWAP_32BIG_C(
                0x72915c72U),
        };
        r_rsip_func100(Param_p82_func100_003);

        r_rsip_func_sub004(0x080000a4U, 0x00000000U);

        static const uint32_t Param_p82_func100_004[] =
        {
            BSWAP_32BIG_C(0x970452c4U), BSWAP_32BIG_C(0x50d84847U), BSWAP_32BIG_C(0x667309f4U), BSWAP_32BIG_C(
                0xd9c48659U),
        };
        r_rsip_func100(Param_p82_func100_004);
        r_rsip_func_sub004(0x080000b4U, 0x00000000U);

        static const uint32_t Param_p82_func100_005[] =
        {
            BSWAP_32BIG_C(0x8a3fc8ffU), BSWAP_32BIG_C(0x221924f9U), BSWAP_32BIG_C(0x6aa62e12U), BSWAP_32BIG_C(
                0x7bc8783aU),
        };
        r_rsip_func100(Param_p82_func100_005);
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x08000075U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
                 bswap_32big(0x00000001U));

        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0x07328d07U);
        r_rsip_func_sub023(0x0000b540U, 0x00000028U, 0x818c000aU);
        r_rsip_func_sub001(0x00890031U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1A24H, 0x080000b5U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p82_func100_006[] =
        {
            BSWAP_32BIG_C(0xba209b1eU), BSWAP_32BIG_C(0x61127374U), BSWAP_32BIG_C(0x5fbdf58cU), BSWAP_32BIG_C(
                0x50b4abc5U),
        };
        r_rsip_func100(Param_p82_func100_006);
        WR1_PROG(REG_1A24H, 0x08000075U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1A24H, 0x080000a5U);
        WR1_PROG(REG_1608H, 0x81040000U);
        r_rsip_func_sub001(0x00890011U);

        r_rsip_func_sub009(0x00008201U);

        static const uint32_t Param_p82_func101_005[] =
        {
            BSWAP_32BIG_C(0xd82b2a16U), BSWAP_32BIG_C(0xfcc88786U), BSWAP_32BIG_C(0x6eecd540U), BSWAP_32BIG_C(
                0x7d89adf2U),
        };
        r_rsip_func101(Param_p82_func101_005);
        r_rsip_func103();
        static const uint32_t Param_p82_func100_007[] =
        {
            BSWAP_32BIG_C(0x41c2c75cU), BSWAP_32BIG_C(0xbfcfcd28U), BSWAP_32BIG_C(0x9d6524a3U), BSWAP_32BIG_C(
                0x68d0305bU),
        };
        r_rsip_func100(Param_p82_func100_007);
        r_rsip_func_sub004(0x0c2000d4U, 0x00000000U);

        r_rsip_func_sub009(0x00008202U);

        static const uint32_t Param_p82_func101_006[] =
        {
            BSWAP_32BIG_C(0xbe5fd982U), BSWAP_32BIG_C(0x97c928f5U), BSWAP_32BIG_C(0x4eb409f6U), BSWAP_32BIG_C(
                0x0c7ac79eU),
        };
        r_rsip_func101(Param_p82_func101_006);
        r_rsip_func103();
        static const uint32_t Param_p82_func100_008[] =
        {
            BSWAP_32BIG_C(0x9fb6b4a3U), BSWAP_32BIG_C(0x25197cc0U), BSWAP_32BIG_C(0xc1fd41f6U), BSWAP_32BIG_C(
                0xa550ca8dU),
        };
        r_rsip_func100(Param_p82_func100_008);
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &S_RAM[16]);
        S_RAM[16] = bswap_32big(S_RAM[16]);
        S_RAM[17] = bswap_32big(S_RAM[17]);
        S_RAM[18] = bswap_32big(S_RAM[18]);
        S_RAM[19] = bswap_32big(S_RAM[19]);

        r_rsip_func_sub009(0x00008203U);

        static const uint32_t Param_p82_func101_007[] =
        {
            BSWAP_32BIG_C(0x40ff4780U), BSWAP_32BIG_C(0x15df29e4U), BSWAP_32BIG_C(0x9a27b14fU), BSWAP_32BIG_C(
                0x77e7ec3cU),
        };
        r_rsip_func101(Param_p82_func101_007);
        r_rsip_func103();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1404H, 0x20000000U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func_sub001(0x00c01001U);

        WR1_PROG(REG_1B00H, 0x00008002U);
        WR1_PROG(REG_1B08H, 0x00000d01U);

        WR1_PROG(REG_1B00H, 0x00008001U);

        WR1_PROG(REG_1B08H, 0x00000214U);

        static const uint32_t Param_p82_func102_002[] =
        {
            BSWAP_32BIG_C(0x765d7076U), BSWAP_32BIG_C(0x1ce4982fU), BSWAP_32BIG_C(0xcd9d3432U), BSWAP_32BIG_C(
                0xf1a1ec6dU),
        };
        r_rsip_func102(Param_p82_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
