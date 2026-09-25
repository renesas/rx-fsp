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

void r_rsip_func412 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub021(0x00003527U, 0x000035abU, 0x00026dadU, 0x0000252dU);
    r_rsip_func_sub021(0x0000a520U, 0x00000002U, 0x3420a920U, 0x00000101U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);

    static const uint32_t Param_func412_func100_001[] =
    {
        BSWAP_32BIG_C(0xac596391U), BSWAP_32BIG_C(0xa17b58a0U), BSWAP_32BIG_C(0x0195a1b9U), BSWAP_32BIG_C(0x4724defdU),
    };
    r_rsip_func100(Param_func412_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000bdeU);

        static const uint32_t Param_func412_func101_001[] =
        {
            BSWAP_32BIG_C(0xd89cb543U), BSWAP_32BIG_C(0xab6bca0cU), BSWAP_32BIG_C(0x16ccd684U), BSWAP_32BIG_C(
                0x481c62d0U),
        };
        r_rsip_func101(Param_func412_func101_001);
    }
    else
    {
        static const uint32_t Param_func412_func100_002[] =
        {
            BSWAP_32BIG_C(0xfb86e08dU), BSWAP_32BIG_C(0x79269078U), BSWAP_32BIG_C(0x31c85699U), BSWAP_32BIG_C(
                0xe98c626fU),
        };
        r_rsip_func100(Param_func412_func100_002);
        WR1_PROG(REG_1404H, 0x17f00000U);
        r_rsip_func_sub001(0x1003001dU);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x13430101U);
        r_rsip_func_sub001(0x10030005U);

        WR1_PROG(REG_1600H, 0x0000b440U);
        WR1_PROG(REG_1600H, 0x00000040U);

        WR1_PROG(REG_2000H, 0x00000001U);

        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_2004H, 0x00000040U);

            static const uint32_t Param_func412_func101_002[] =
            {
                BSWAP_32BIG_C(0x645b4883U), BSWAP_32BIG_C(0x0d27e6d0U), BSWAP_32BIG_C(0x2990b2f5U), BSWAP_32BIG_C(
                    0x1b6e9353U),
            };
            r_rsip_func101(Param_func412_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_2004H, 0x00000050U);

            static const uint32_t Param_func412_func101_003[] =
            {
                BSWAP_32BIG_C(0xeea1625fU), BSWAP_32BIG_C(0x5d5f9761U), BSWAP_32BIG_C(0xe750a759U), BSWAP_32BIG_C(
                    0xa90851b2U),
            };
            r_rsip_func101(Param_func412_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_2004H, 0x00000080U);

            static const uint32_t Param_func412_func101_004[] =
            {
                BSWAP_32BIG_C(0xa52d5c76U), BSWAP_32BIG_C(0xd38af7adU), BSWAP_32BIG_C(0x752cee4bU), BSWAP_32BIG_C(
                    0x37c67303U),
            };
            r_rsip_func101(Param_func412_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_2004H, 0x00000090U);

            static const uint32_t Param_func412_func101_005[] =
            {
                BSWAP_32BIG_C(0xd9d6bf9fU), BSWAP_32BIG_C(0x10529f9fU), BSWAP_32BIG_C(0x6b3b7247U), BSWAP_32BIG_C(
                    0xf2a71796U),
            };
            r_rsip_func101(Param_func412_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_2004H, 0x000000a0U);

            static const uint32_t Param_func412_func101_006[] =
            {
                BSWAP_32BIG_C(0x1cb63ee2U), BSWAP_32BIG_C(0xd5c96b4eU), BSWAP_32BIG_C(0x8b2b7ce3U), BSWAP_32BIG_C(
                    0x75e27a5dU),
            };
            r_rsip_func101(Param_func412_func101_006);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_2004H, 0x000000b0U);

            static const uint32_t Param_func412_func101_007[] =
            {
                BSWAP_32BIG_C(0x3990fc6eU), BSWAP_32BIG_C(0x9efb539cU), BSWAP_32BIG_C(0xa309267aU), BSWAP_32BIG_C(
                    0xc7d856aeU),
            };
            r_rsip_func101(Param_func412_func101_007);
        }

        static const uint32_t Param_func412_func100_003[] =
        {
            BSWAP_32BIG_C(0x6ae097d8U), BSWAP_32BIG_C(0xd7bab063U), BSWAP_32BIG_C(0xc9591deeU), BSWAP_32BIG_C(
                0x1a813d3dU),
        };
        r_rsip_func100(Param_func412_func100_003);
        r_rsip_func_sub021(0x0000a520U, 0x00000006U, 0x00000908U, 0x01836d09U);
        WR1_PROG(REG_1600H, 0x00036d29U);

        r_rsip_func_sub016(0x81020100U, 0x0000500aU);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
        S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

        static const uint32_t Param_func412_func100_004[] =
        {
            BSWAP_32BIG_C(0x4e2a9140U), BSWAP_32BIG_C(0x60bff8f6U), BSWAP_32BIG_C(0x5b6417f4U), BSWAP_32BIG_C(
                0xd26b1dfaU),
        };
        r_rsip_func100(Param_func412_func100_004);
        r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

        r_rsip_func_sub001(0x01400009U);

        WR1_PROG(REG_1600H, 0x00000800U);

        WR1_PROG(REG_1600H, 0x0000094aU);

        r_rsip_func_sub016(0x81010160U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1608H, 0x81810000U);
            r_rsip_func_sub001(0x01490005U);

            r_rsip_func_sub022(0x0000a400U, 0x00000004U, 0x00002d40U);

            static const uint32_t Param_func412_func101_008[] =
            {
                BSWAP_32BIG_C(0x0802b05dU), BSWAP_32BIG_C(0xb737b858U), BSWAP_32BIG_C(0xb9133c92U), BSWAP_32BIG_C(
                    0x35e834ddU),
            };
            r_rsip_func101(Param_func412_func101_008);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_func412_func100_005[] =
        {
            BSWAP_32BIG_C(0x316aa199U), BSWAP_32BIG_C(0xdf085357U), BSWAP_32BIG_C(0x6b195815U), BSWAP_32BIG_C(
                0x60302d39U),
        };
        r_rsip_func100(Param_func412_func100_005);
        r_rsip_func_sub011(0x3800094bU);

        r_rsip_func_sub021(0x0000a4e0U, 0x00000003U, 0x000268e7U, 0x0000094aU);

        r_rsip_func_sub016(0x810100e0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
        S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

        for (iLoop = 0U; iLoop < S_RAM[0 + 1]; iLoop++)
        {
            WR1_PROG(REG_1444H, 0x000000c4U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, ARG1[iLoop]);

            WR1_PROG(REG_1600H, 0x00002d40U);

            static const uint32_t Param_func412_func101_009[] =
            {
                BSWAP_32BIG_C(0x6155cec4U), BSWAP_32BIG_C(0x63907a61U), BSWAP_32BIG_C(0xb1e8a5b9U), BSWAP_32BIG_C(
                    0x85f66c37U),
            };
            r_rsip_func101(Param_func412_func101_009);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000947U);

        WAIT_STS(REG_2030H, 8, 0);
        WR1_PROG(REG_143CH, 0x00001600U);

        WAIT_STS(REG_2030H, 4, 1);

        WR1_PROG(REG_1600H, 0x0000094aU);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1608H, 0x80810002U);
            r_rsip_func_sub001(0x03450005U);

            r_rsip_func_sub022(0x0000a440U, 0x00000004U, 0x00002d40U);

            static const uint32_t Param_func412_func101_010[] =
            {
                BSWAP_32BIG_C(0xce569d2fU), BSWAP_32BIG_C(0x942d16bdU), BSWAP_32BIG_C(0x8ae0940eU), BSWAP_32BIG_C(
                    0xa896ef2fU),
            };
            r_rsip_func101(Param_func412_func101_010);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x3800094bU);

        r_rsip_func_sub021(0x0000b440U, 0x00000040U, 0x0000b7c0U, 0xc2f4b027U);

        static const uint32_t Param_func412_func101_011[] =
        {
            BSWAP_32BIG_C(0x1fdd338dU), BSWAP_32BIG_C(0x0f050150U), BSWAP_32BIG_C(0x64ffc433U), BSWAP_32BIG_C(
                0x92988889U),
        };
        r_rsip_func101(Param_func412_func101_011);
    }

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
