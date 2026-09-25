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

rsip_ret_t r_rsip_p58f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Msg[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_length[],
                        uint32_t       MAX_CNT,
                        uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2440H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020065U);

    for (iLoop = 0U; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop = iLoop + S_RAM[0])
    {
        WAIT_STS(REG_1444H, 31, 1);
        for (jLoop = 0U; jLoop < S_RAM[0]; jLoop = jLoop + 2)
        {
            WR2_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop]);
        }
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001400U);

    WAIT_STS(REG_2440H, 4, 1);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p58f_func100_001[] =
    {
        BSWAP_32BIG_C(0x14e9ee65U), BSWAP_32BIG_C(0x7a78e38cU), BSWAP_32BIG_C(0xfc282da7U), BSWAP_32BIG_C(0xf741828bU),
    };
    r_rsip_func100(Param_p58f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p58f_func100_002[] =
        {
            BSWAP_32BIG_C(0xf375f00aU), BSWAP_32BIG_C(0x6d4245eaU), BSWAP_32BIG_C(0x7d4d7a2bU), BSWAP_32BIG_C(
                0x079dcc8aU),
        };
        r_rsip_func100(Param_p58f_func100_002);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            static const uint32_t Param_p58f_func100_003[] =
            {
                BSWAP_32BIG_C(0xf3b29552U), BSWAP_32BIG_C(0xc21e5307U), BSWAP_32BIG_C(0x736692a4U), BSWAP_32BIG_C(
                    0xfcfa00a9U),
            };
            r_rsip_func100(Param_p58f_func100_003);
            WR1_PROG(REG_1408H, 0x0000601eU);
            WAIT_STS(REG_1408H, 30, 1);
            RD7_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_001[] =
            {
                BSWAP_32BIG_C(0x0cf39f3aU), BSWAP_32BIG_C(0xb9dd808fU), BSWAP_32BIG_C(0xe2ccb7d1U), BSWAP_32BIG_C(
                    0xfbfc57bbU),
            };
            r_rsip_func102(Param_p58f_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            static const uint32_t Param_p58f_func100_004[] =
            {
                BSWAP_32BIG_C(0x43c6d415U), BSWAP_32BIG_C(0xe11afe21U), BSWAP_32BIG_C(0xf824223bU), BSWAP_32BIG_C(
                    0x45df1593U),
            };
            r_rsip_func100(Param_p58f_func100_004);
            WR1_PROG(REG_1408H, 0x00006022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD8_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_002[] =
            {
                BSWAP_32BIG_C(0x1da89082U), BSWAP_32BIG_C(0xfc4d85e0U), BSWAP_32BIG_C(0xae7a0ef0U), BSWAP_32BIG_C(
                    0x969b9b1bU),
            };
            r_rsip_func102(Param_p58f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            static const uint32_t Param_p58f_func100_005[] =
            {
                BSWAP_32BIG_C(0xf338aa16U), BSWAP_32BIG_C(0x3cb731daU), BSWAP_32BIG_C(0x2f349c09U), BSWAP_32BIG_C(
                    0x691b0d7aU),
            };
            r_rsip_func100(Param_p58f_func100_005);
            WR1_PROG(REG_1408H, 0x00006032U);
            WAIT_STS(REG_1408H, 30, 1);
            RD12_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_003[] =
            {
                BSWAP_32BIG_C(0x9111aac7U), BSWAP_32BIG_C(0x5621dcdeU), BSWAP_32BIG_C(0x7c88b1c4U), BSWAP_32BIG_C(
                    0x63b4de7bU),
            };
            r_rsip_func102(Param_p58f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            static const uint32_t Param_p58f_func100_006[] =
            {
                BSWAP_32BIG_C(0x00ca5849U), BSWAP_32BIG_C(0x281d8c1aU), BSWAP_32BIG_C(0xf8d18329U), BSWAP_32BIG_C(
                    0xf15895b2U),
            };
            r_rsip_func100(Param_p58f_func100_006);
            WR1_PROG(REG_1408H, 0x00006042U);
            WAIT_STS(REG_1408H, 30, 1);
            RD16_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_004[] =
            {
                BSWAP_32BIG_C(0xf01398f5U), BSWAP_32BIG_C(0x6a61b2a8U), BSWAP_32BIG_C(0x85931f6aU), BSWAP_32BIG_C(
                    0x37d9093aU),
            };
            r_rsip_func102(Param_p58f_func102_004);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        static const uint32_t Param_p58f_func100_007[] =
        {
            BSWAP_32BIG_C(0x047d9718U), BSWAP_32BIG_C(0x2010e2faU), BSWAP_32BIG_C(0xff6efb06U), BSWAP_32BIG_C(
                0x41eb46b4U),
        };
        r_rsip_func100(Param_p58f_func100_007);

        r_rsip_func_sub010(0x000000c7U, 0x80010020U);
        WR1_PROG(REG_1420H, InData_length[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x0000001cU);

            static const uint32_t Param_p58f_func101_001[] =
            {
                BSWAP_32BIG_C(0x51cfb305U), BSWAP_32BIG_C(0x0c4ff407U), BSWAP_32BIG_C(0x9f9ba746U), BSWAP_32BIG_C(
                    0xa7eee99cU),
            };
            r_rsip_func101(Param_p58f_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000020U);

            static const uint32_t Param_p58f_func101_002[] =
            {
                BSWAP_32BIG_C(0xe5d5284bU), BSWAP_32BIG_C(0xcd99868fU), BSWAP_32BIG_C(0x825cc1e5U), BSWAP_32BIG_C(
                    0xb8c47215U),
            };
            r_rsip_func101(Param_p58f_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000030U);

            static const uint32_t Param_p58f_func101_003[] =
            {
                BSWAP_32BIG_C(0x1ddfde1dU), BSWAP_32BIG_C(0x86eb46a7U), BSWAP_32BIG_C(0xeaa57b0cU), BSWAP_32BIG_C(
                    0xf9b8d143U),
            };
            r_rsip_func101(Param_p58f_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000040U);

            static const uint32_t Param_p58f_func101_004[] =
            {
                BSWAP_32BIG_C(0xca76c8d2U), BSWAP_32BIG_C(0x588af282U), BSWAP_32BIG_C(0x6e18ad53U), BSWAP_32BIG_C(
                    0xd5179f73U),
            };
            r_rsip_func101(Param_p58f_func101_004);
        }

        r_rsip_func_sub006(0x3420a820U, 0x00000004U, 0x00260000U);

        r_rsip_func_sub017(0x34202841U, 0x00260000U);

        static const uint32_t Param_p58f_func100_008[] =
        {
            BSWAP_32BIG_C(0x08c10b43U), BSWAP_32BIG_C(0xd055f5dfU), BSWAP_32BIG_C(0x55ee93eeU), BSWAP_32BIG_C(
                0x6c5270d1U),
        };
        r_rsip_func100(Param_p58f_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p58f_func102_005[] =
            {
                BSWAP_32BIG_C(0xbf5270f0U), BSWAP_32BIG_C(0x39cc1687U), BSWAP_32BIG_C(0x144612a4U), BSWAP_32BIG_C(
                    0x940e478fU),
            };
            r_rsip_func102(Param_p58f_func102_005);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p58f_func100_009[] =
            {
                BSWAP_32BIG_C(0xc249eafdU), BSWAP_32BIG_C(0x74c0b419U), BSWAP_32BIG_C(0xd993b716U), BSWAP_32BIG_C(
                    0x4acdcb32U),
            };
            r_rsip_func100(Param_p58f_func100_009);

            r_rsip_func_sub021(0x000008c6U, 0x000008a5U, 0x0000a440U, 0x0000000fU);
            WR1_PROG(REG_1600H, 0x00046842U);
            WR1_PROG(REG_1600H, 0x00026c42U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop = iLoop + 4U)
            {
                static const uint32_t Param_p58f_func100_010[] =
                {
                    BSWAP_32BIG_C(0x503f69f0U), BSWAP_32BIG_C(0x1ab65c29U), BSWAP_32BIG_C(0x75a21d95U), BSWAP_32BIG_C(
                        0x5fd7db42U),
                };
                r_rsip_func100(Param_p58f_func100_010);

                r_rsip_func_sub021(0x000008e7U, 0x00000863U, 0x380088c0U, 0x00000004U);
                r_rsip_func_sub021(0x2000d060U, 0x38000c84U, 0x2000d060U, 0x00007c03U);
                WR1_PROG(REG_143CH, 0x00600000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    r_rsip_func_sub001(0x0346000dU);

                    r_rsip_func_sub020(0x000002c1U, 0x08000045U);
                    WR3_ADDR(REG_1420H, &InData_MAC[iLoop]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                    static const uint32_t Param_p58f_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xa3940748U), BSWAP_32BIG_C(0x0ee8e5e0U), BSWAP_32BIG_C(0xe85734afU),
                        BSWAP_32BIG_C(0xf24c6971U),
                    };
                    r_rsip_func101(Param_p58f_func101_005);
                }
                else
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    r_rsip_func_sub001(0x03460011U);

                    r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                    WR4_ADDR(REG_1420H, &InData_MAC[iLoop]);

                    static const uint32_t Param_p58f_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x63319a39U), BSWAP_32BIG_C(0xa841c228U), BSWAP_32BIG_C(0xc0228d90U),
                        BSWAP_32BIG_C(0xf70bf465U),
                    };
                    r_rsip_func101(Param_p58f_func101_006);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000800U);
                for (jLoop = 0U; jLoop < 16U; jLoop++)
                {
                    r_rsip_func_sub021(0x3c0028a1U, 0x12003c07U, 0x00002ce0U, 0x00002ca0U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1824H, 0x9c000005U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1608H, 0x81840007U);
                r_rsip_func_sub001(0x00490011U);

                WR1_PROG(REG_1600H, 0x0000a4c0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                static const uint32_t Param_p58f_func101_007[] =
                {
                    BSWAP_32BIG_C(0x775836a1U), BSWAP_32BIG_C(0xbe43fd51U), BSWAP_32BIG_C(0xa502fd4fU), BSWAP_32BIG_C(
                        0x5f651374U),
                };
                r_rsip_func101(Param_p58f_func101_007);
            }

            WR1_PROG(REG_1600H, 0x000008c2U);

            r_rsip_func_sub014(0x00007c06U, 0x00602000U);

            static const uint32_t Param_p58f_func100_011[] =
            {
                BSWAP_32BIG_C(0x7531048cU), BSWAP_32BIG_C(0x48b4d0fbU), BSWAP_32BIG_C(0x508ea40aU), BSWAP_32BIG_C(
                    0xd0a70e2eU),
            };
            r_rsip_func100(Param_p58f_func100_011);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p58f_func102_006[] =
                {
                    BSWAP_32BIG_C(0x211811a7U), BSWAP_32BIG_C(0x758dc508U), BSWAP_32BIG_C(0xd3fc3566U), BSWAP_32BIG_C(
                        0xfcdf3846U),
                };
                r_rsip_func102(Param_p58f_func102_006);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p58f_func102_007[] =
                {
                    BSWAP_32BIG_C(0x2dc5ce3fU), BSWAP_32BIG_C(0xc0fd5724U), BSWAP_32BIG_C(0x9ec6cea1U), BSWAP_32BIG_C(
                        0xa68bcd4aU),
                };
                r_rsip_func102(Param_p58f_func102_007);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
