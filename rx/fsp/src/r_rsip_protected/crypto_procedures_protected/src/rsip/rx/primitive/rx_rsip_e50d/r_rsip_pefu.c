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

rsip_ret_t r_rsip_pefu (const uint32_t InData_Msg1[],
                        const uint32_t InData_Msg1Length[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        const uint32_t InData_Msg2[],
                        const uint32_t InData_Msg2Length[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000002c7U, 0x80030060U);
    WR1_PROG(REG_1420H, InData_Msg1Length[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_EncMsgLength[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Msg2Length[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008c60U, 0xfffffffeU, 0x00A60000U);

    r_rsip_func_sub021(0x00000821U, 0x00002423U, 0x00002424U, 0x00002425U);

    static const uint32_t Param_pefu_func100_001[] =
    {
        BSWAP_32BIG_C(0x3c4f6993U), BSWAP_32BIG_C(0x38768088U), BSWAP_32BIG_C(0x880cc7c7U), BSWAP_32BIG_C(0x6d940118U),
    };
    r_rsip_func100(Param_pefu_func100_001);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xfffffff7U, 0x00A60000U);

        r_rsip_func_sub006(0x38008c20U, 0x0000000fU, 0x00A60000U);

        static const uint32_t Param_pefu_func101_001[] =
        {
            BSWAP_32BIG_C(0xd7ab5269U), BSWAP_32BIG_C(0x7fb981f1U), BSWAP_32BIG_C(0x2432c5f1U), BSWAP_32BIG_C(
                0xc90bedf0U),
        };
        r_rsip_func101(Param_pefu_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub021(0x38000c84U, 0x00020020U, 0x38008880U, 0x0000000cU);
        r_rsip_func_sub017(0x00000080U, 0x00A60000U);

        r_rsip_func_sub006(0x38008c20U, 0x0000001fU, 0x00A60000U);

        static const uint32_t Param_pefu_func101_002[] =
        {
            BSWAP_32BIG_C(0xac74653dU), BSWAP_32BIG_C(0xcb5dead8U), BSWAP_32BIG_C(0xf5310c01U), BSWAP_32BIG_C(
                0xc551fd08U),
        };
        r_rsip_func101(Param_pefu_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xffffffefU, 0x00A60000U);

        r_rsip_func_sub006(0x38008c20U, 0x0000001fU, 0x00A60000U);

        static const uint32_t Param_pefu_func101_003[] =
        {
            BSWAP_32BIG_C(0xe68717fcU), BSWAP_32BIG_C(0x6d23da86U), BSWAP_32BIG_C(0xc602b426U), BSWAP_32BIG_C(
                0xc90bc10fU),
        };
        r_rsip_func101(Param_pefu_func101_003);
    }

    static const uint32_t Param_pefu_func100_002[] =
    {
        BSWAP_32BIG_C(0x851c7cafU), BSWAP_32BIG_C(0x5d1121daU), BSWAP_32BIG_C(0xfa7a5b2cU), BSWAP_32BIG_C(0xf397f901U),
    };
    r_rsip_func100(Param_pefu_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pefu_func102_001[] =
        {
            BSWAP_32BIG_C(0xe3433e4fU), BSWAP_32BIG_C(0x0a03eed5U), BSWAP_32BIG_C(0x3cf71749U), BSWAP_32BIG_C(
                0x9d03209aU),
        };
        r_rsip_func102(Param_pefu_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000821U);

        r_rsip_func_sub006(0x00003405U, 0x38000c84U, 0x00A60000U);

        static const uint32_t Param_pefu_func100_003[] =
        {
            BSWAP_32BIG_C(0x8508426aU), BSWAP_32BIG_C(0xf111aa99U), BSWAP_32BIG_C(0x886e1b00U), BSWAP_32BIG_C(
                0x61b2fd18U),
        };
        r_rsip_func100(Param_pefu_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_EncMsg[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub009(0x0000ef01U);

            static const uint32_t Param_pefu_func101_004[] =
            {
                BSWAP_32BIG_C(0x051ca673U), BSWAP_32BIG_C(0xc8e0c2b2U), BSWAP_32BIG_C(0x5d11b484U), BSWAP_32BIG_C(
                    0xedcbd2c4U),
            };
            r_rsip_func101(Param_pefu_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01c80eb2U);

            r_rsip_func_sub009(0x0000ef01U);

            static const uint32_t Param_pefu_func101_005[] =
            {
                BSWAP_32BIG_C(0x72204670U), BSWAP_32BIG_C(0x465dcfbbU), BSWAP_32BIG_C(0xec55083eU), BSWAP_32BIG_C(
                    0xd8547b7bU),
            };
            r_rsip_func101(Param_pefu_func101_005);
            r_rsip_func044();

            r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x000038a7U);

            static const uint32_t Param_pefu_func100_004[] =
            {
                BSWAP_32BIG_C(0xb4ffaeb9U), BSWAP_32BIG_C(0xfdef5dd2U), BSWAP_32BIG_C(0x58737d0aU), BSWAP_32BIG_C(
                    0x877cae4cU),
            };
            r_rsip_func100(Param_pefu_func100_004);

            r_rsip_func_sub014(0x00007c05U, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
            {
                r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[1]);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_EncMsg[5]);

                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_func_sub001(0x00c20021U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[9]);

                static const uint32_t Param_pefu_func101_006[] =
                {
                    BSWAP_32BIG_C(0xd1e7e5e0U), BSWAP_32BIG_C(0xd29693bfU), BSWAP_32BIG_C(0x0c1d1660U), BSWAP_32BIG_C(
                        0xb05459a8U),
                };
                r_rsip_func101(Param_pefu_func101_006);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                r_rsip_func_sub024(0x00000bc2U, 0x40000200U, 0xf7009d07U);

                for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_func_sub001(0x00c20031U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[13]);

                static const uint32_t Param_pefu_func101_007[] =
                {
                    BSWAP_32BIG_C(0xadb781a7U), BSWAP_32BIG_C(0x5757f847U), BSWAP_32BIG_C(0x01d08694U), BSWAP_32BIG_C(
                        0xcf516446U),
                };
                r_rsip_func101(Param_pefu_func101_007);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xf7009d07U);

                WR1_PROG(REG_1404H, 0x10000000U);
                for (iLoop = 0U; iLoop < 16U; iLoop = iLoop + 4U)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);
                    r_rsip_func_sub001(0x00c20011U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[17]);

                static const uint32_t Param_pefu_func101_008[] =
                {
                    BSWAP_32BIG_C(0xd9b7dbfaU), BSWAP_32BIG_C(0x37ef8c55U), BSWAP_32BIG_C(0x8f79849fU), BSWAP_32BIG_C(
                        0x778be677U),
                };
                r_rsip_func101(Param_pefu_func101_008);
            }

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pefu_func100_005[] =
            {
                BSWAP_32BIG_C(0x2ecdb4b3U), BSWAP_32BIG_C(0x935f0f4cU), BSWAP_32BIG_C(0x155e0ea3U), BSWAP_32BIG_C(
                    0x77f2ada2U),
            };
            r_rsip_func100(Param_pefu_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002c20U);
                static const uint32_t Param_pefu_func101_009[] =
                {
                    BSWAP_32BIG_C(0x852e4b9bU), BSWAP_32BIG_C(0xb3d5d93aU), BSWAP_32BIG_C(0x5f484e10U), BSWAP_32BIG_C(
                        0xa574933cU),
                };
                r_rsip_func101(Param_pefu_func101_009);
            }

            static const uint32_t Param_pefu_func101_010[] =
            {
                BSWAP_32BIG_C(0x95cdb0d5U), BSWAP_32BIG_C(0xed2e65c2U), BSWAP_32BIG_C(0x155857eeU), BSWAP_32BIG_C(
                    0x991b5fbaU),
            };
            r_rsip_func101(Param_pefu_func101_010);
        }

        r_rsip_func_sub017(0x38000c21U, 0x00A60000U);

        static const uint32_t Param_pefu_func100_006[] =
        {
            BSWAP_32BIG_C(0x38e47fefU), BSWAP_32BIG_C(0xb8864198U), BSWAP_32BIG_C(0x3b7df373U), BSWAP_32BIG_C(
                0x24e108c9U),
        };
        r_rsip_func100(Param_pefu_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pefu_func102_002[] =
            {
                BSWAP_32BIG_C(0x56ef44e4U), BSWAP_32BIG_C(0x0d83b53cU), BSWAP_32BIG_C(0x3c7cd5cbU), BSWAP_32BIG_C(
                    0x0cd8744cU),
            };
            r_rsip_func102(Param_pefu_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WAIT_STS(REG_2030H, 0, 1);

            r_rsip_func_sub017(0x38000c63U, 0x00A60000U);

            static const uint32_t Param_pefu_func100_007[] =
            {
                BSWAP_32BIG_C(0x755a86b1U), BSWAP_32BIG_C(0x7f99fedeU), BSWAP_32BIG_C(0xb4bafc39U), BSWAP_32BIG_C(
                    0x2297886cU),
            };
            r_rsip_func100(Param_pefu_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1444H, 0x000000c4U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Msg1[0]);

                static const uint32_t Param_pefu_func101_011[] =
                {
                    BSWAP_32BIG_C(0x6e4b8853U), BSWAP_32BIG_C(0x163728c1U), BSWAP_32BIG_C(0xef563adbU), BSWAP_32BIG_C(
                        0x21838a95U),
                };
                r_rsip_func101(Param_pefu_func101_011);
            }

            r_rsip_func_sub017(0x38000c84U, 0x00A60000U);

            static const uint32_t Param_pefu_func100_008[] =
            {
                BSWAP_32BIG_C(0x498bbdf1U), BSWAP_32BIG_C(0x2eecd411U), BSWAP_32BIG_C(0xb903b6d8U), BSWAP_32BIG_C(
                    0xd724a981U),
            };
            r_rsip_func100(Param_pefu_func100_008);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pefu_func100_009[] =
                {
                    BSWAP_32BIG_C(0x7a9da837U), BSWAP_32BIG_C(0x19db87fdU), BSWAP_32BIG_C(0x6c18b7c3U), BSWAP_32BIG_C(
                        0xf6bf02e9U),
                };
                r_rsip_func100(Param_pefu_func100_009);

                r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430021U);

                    static const uint32_t Param_pefu_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x5d09bd19U), BSWAP_32BIG_C(0xa13b694bU), BSWAP_32BIG_C(0xc7f1b01aU),
                        BSWAP_32BIG_C(0x50b1da98U),
                    };
                    r_rsip_func101(Param_pefu_func101_012);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430031U);

                    static const uint32_t Param_pefu_func101_013[] =
                    {
                        BSWAP_32BIG_C(0x8809ee9cU), BSWAP_32BIG_C(0xbe31e8bdU), BSWAP_32BIG_C(0xe8d594c6U),
                        BSWAP_32BIG_C(0x05ec140bU),
                    };
                    r_rsip_func101(Param_pefu_func101_013);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430041U);

                    static const uint32_t Param_pefu_func101_014[] =
                    {
                        BSWAP_32BIG_C(0xf876cae8U), BSWAP_32BIG_C(0xc1659052U), BSWAP_32BIG_C(0x232267fbU),
                        BSWAP_32BIG_C(0x28d93ca0U),
                    };
                    r_rsip_func101(Param_pefu_func101_014);
                }

                static const uint32_t Param_pefu_func101_015[] =
                {
                    BSWAP_32BIG_C(0x29e4c3d4U), BSWAP_32BIG_C(0x1679e43dU), BSWAP_32BIG_C(0x87c3ad3cU), BSWAP_32BIG_C(
                        0x42208aafU),
                };
                r_rsip_func101(Param_pefu_func101_015);
            }

            static const uint32_t Param_pefu_func100_010[] =
            {
                BSWAP_32BIG_C(0xe42742a0U), BSWAP_32BIG_C(0xbeca8566U), BSWAP_32BIG_C(0x1d1ac68cU), BSWAP_32BIG_C(
                    0xd6b51effU),
            };
            r_rsip_func100(Param_pefu_func100_010);

            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1444H, 0x00020064U);

            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0; iLoop < (S_RAM[0] & 0x0000000fU); iLoop++)
            {
                WR1_PROG(REG_1420H, InData_Msg2[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = (S_RAM[0] & 0x0000000fU); iLoop < S_RAM[0]; iLoop = iLoop + 16U)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR16_ADDR(REG_1420H, &InData_Msg2[iLoop]);
            }

            r_rsip_func_sub043();

            r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003801U);

            static const uint32_t Param_pefu_func101_016[] =
            {
                BSWAP_32BIG_C(0xa52fb5c6U), BSWAP_32BIG_C(0x68047727U), BSWAP_32BIG_C(0xb5462f75U), BSWAP_32BIG_C(
                    0x6e159652U),
            };
            r_rsip_func101(Param_pefu_func101_016);

            return RSIP_RET_PASS;
        }
    }
}
