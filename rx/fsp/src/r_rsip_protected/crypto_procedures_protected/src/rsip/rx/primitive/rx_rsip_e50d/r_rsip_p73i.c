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

rsip_ret_t r_rsip_p73i (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00730001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p73i_func100_001[] =
    {
        BSWAP_32BIG_C(0xe4b25d67U), BSWAP_32BIG_C(0x03b31761U), BSWAP_32BIG_C(0x9843f039U), BSWAP_32BIG_C(0x0cb69542U),
    };
    r_rsip_func100(Param_p73i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p73i_func102_001[] =
        {
            BSWAP_32BIG_C(0xb5be69fdU), BSWAP_32BIG_C(0x614b5f8dU), BSWAP_32BIG_C(0x442fa9fdU), BSWAP_32BIG_C(
                0xc5c10e1eU),
        };
        r_rsip_func102(Param_p73i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p73i_func100_002[] =
        {
            BSWAP_32BIG_C(0x151a5a59U), BSWAP_32BIG_C(0xe2893a40U), BSWAP_32BIG_C(0xad07bf74U), BSWAP_32BIG_C(
                0x64ff438bU),
        };
        r_rsip_func100(Param_p73i_func100_002);
        r_rsip_func_sub021(0x3420a800U, 0x00000007U, 0x2000b400U, 0x00000006U);

        r_rsip_func_sub014(0x00007c00U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_2004H, 0x00000040U);

            static const uint32_t Param_p73i_func101_001[] =
            {
                BSWAP_32BIG_C(0xdbba6273U), BSWAP_32BIG_C(0x9d91ec23U), BSWAP_32BIG_C(0x234b02c3U), BSWAP_32BIG_C(
                    0xcf4ed3bcU),
            };
            r_rsip_func101(Param_p73i_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_2004H, 0x00000050U);

            static const uint32_t Param_p73i_func101_002[] =
            {
                BSWAP_32BIG_C(0x3990866bU), BSWAP_32BIG_C(0xf8e5f381U), BSWAP_32BIG_C(0xef8cc1c1U), BSWAP_32BIG_C(
                    0x03580372U),
            };
            r_rsip_func101(Param_p73i_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_2004H, 0x00000080U);

            static const uint32_t Param_p73i_func101_003[] =
            {
                BSWAP_32BIG_C(0xf54a5701U), BSWAP_32BIG_C(0x7cdb24c2U), BSWAP_32BIG_C(0x2dc732cdU), BSWAP_32BIG_C(
                    0xc31d28d9U),
            };
            r_rsip_func101(Param_p73i_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_2004H, 0x00000090U);

            static const uint32_t Param_p73i_func101_004[] =
            {
                BSWAP_32BIG_C(0x2c05b725U), BSWAP_32BIG_C(0xa061549fU), BSWAP_32BIG_C(0x8e2cdc29U), BSWAP_32BIG_C(
                    0xdeb490e7U),
            };
            r_rsip_func101(Param_p73i_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_2004H, 0x000000a0U);

            static const uint32_t Param_p73i_func101_005[] =
            {
                BSWAP_32BIG_C(0x1f8d1101U), BSWAP_32BIG_C(0xded70c51U), BSWAP_32BIG_C(0xddc81156U), BSWAP_32BIG_C(
                    0x37b04d06U),
            };
            r_rsip_func101(Param_p73i_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_2004H, 0x000000b0U);

            static const uint32_t Param_p73i_func101_006[] =
            {
                BSWAP_32BIG_C(0xb82cd555U), BSWAP_32BIG_C(0x94885b78U), BSWAP_32BIG_C(0x097c12d5U), BSWAP_32BIG_C(
                    0xbba3e3acU),
            };
            r_rsip_func101(Param_p73i_func101_006);
        }

        if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
        {
            WR1_PROG(REG_200CH, 0x00000100U);

            static const uint32_t Param_p73i_func101_007[] =
            {
                BSWAP_32BIG_C(0x7297c3e4U), BSWAP_32BIG_C(0xaa3be887U), BSWAP_32BIG_C(0xc271e6dfU), BSWAP_32BIG_C(
                    0x8c89f565U),
            };
            r_rsip_func101(Param_p73i_func101_007);
        }
        else
        {
            r_rsip_func_sub033(0x00000040U, InData_MsgLen[0], 0x00000040U, InData_MsgLen[1]);

            static const uint32_t Param_p73i_func101_008[] =
            {
                BSWAP_32BIG_C(0x33a97ef3U), BSWAP_32BIG_C(0x0307f61aU), BSWAP_32BIG_C(0x79d920e2U), BSWAP_32BIG_C(
                    0x3324787eU),
            };
            r_rsip_func101(Param_p73i_func101_008);
        }

        return RSIP_RET_PASS;
    }
}
