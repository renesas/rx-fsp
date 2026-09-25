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

rsip_ret_t r_rsip_p97s (uint32_t OutData_State[])
{
    uint32_t iLoop = 0U;

    if (S_RAM[0] == 1)
    {
        static const uint32_t Param_p97s_func101_001[] =
        {
            BSWAP_32BIG_C(0xac33ed51U), BSWAP_32BIG_C(0x67ba7eaeU), BSWAP_32BIG_C(0x00ac0a3cU), BSWAP_32BIG_C(
                0x4a8c67e8U),
        };
        r_rsip_func101(Param_p97s_func101_001);
    }
    else
    {
        static const uint32_t Param_p97s_func101_002[] =
        {
            BSWAP_32BIG_C(0xa1c8d49bU), BSWAP_32BIG_C(0x4224c607U), BSWAP_32BIG_C(0x02e4e4a2U), BSWAP_32BIG_C(
                0x2a7dd5daU),
        };
        r_rsip_func101(Param_p97s_func101_002);
    }

    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    RD1_ADDR(REG_1C08H, &OutData_State[0]);
    RD1_ADDR(REG_1C10H, &OutData_State[1]);
    RD1_ADDR(REG_1C14H, &OutData_State[2]);

    for (iLoop = 3; iLoop < 10U; iLoop++)
    {
        RD1_ADDR(REG_1C2CH, &OutData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000034e3U);

    r_rsip_func_sub009(0x00009704U);

    static const uint32_t Param_p97s_func101_003[] =
    {
        BSWAP_32BIG_C(0xa2bf342bU), BSWAP_32BIG_C(0xc977f3e7U), BSWAP_32BIG_C(0xbaf13d0cU), BSWAP_32BIG_C(0xfbdb8012U),
    };
    r_rsip_func101(Param_p97s_func101_003);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x019c2adaU);

    r_rsip_func_sub009(0x00009704U);

    static const uint32_t Param_p97s_func101_004[] =
    {
        BSWAP_32BIG_C(0x7be505e6U), BSWAP_32BIG_C(0x9041a259U), BSWAP_32BIG_C(0x6aeebe89U), BSWAP_32BIG_C(0x7a6eb7eaU),
    };
    r_rsip_func101(Param_p97s_func101_004);
    r_rsip_func044();

    static const uint32_t Param_p97s_func100_001[] =
    {
        BSWAP_32BIG_C(0x0b8d1b37U), BSWAP_32BIG_C(0xd5b9c855U), BSWAP_32BIG_C(0x89e0d0b4U), BSWAP_32BIG_C(0x87720c1bU),
    };
    r_rsip_func100(Param_p97s_func100_001);
    r_rsip_func_sub027(0x40000000U, 0xe8009104U, 0x81010040U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &OutData_State[11]);
    r_rsip_func_sub001(0x0002000dU);

    static const uint32_t Param_p97s_func100_002[] =
    {
        BSWAP_32BIG_C(0xf10482b9U), BSWAP_32BIG_C(0x9da28634U), BSWAP_32BIG_C(0xecad28c8U), BSWAP_32BIG_C(0x9cfebba2U),
    };
    r_rsip_func100(Param_p97s_func100_002);
    r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_State[12]);

    static const uint32_t Param_p97s_func100_003[] =
    {
        BSWAP_32BIG_C(0x17b31d38U), BSWAP_32BIG_C(0x1feb273bU), BSWAP_32BIG_C(0xc69e8f81U), BSWAP_32BIG_C(0x584b1755U),
    };
    r_rsip_func100(Param_p97s_func100_003);
    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_State[10]);

    static const uint32_t Param_p97s_func102_001[] =
    {
        BSWAP_32BIG_C(0x96c6909aU), BSWAP_32BIG_C(0xbd1ab125U), BSWAP_32BIG_C(0x0701a49aU), BSWAP_32BIG_C(0x625028fdU),
    };
    r_rsip_func102(Param_p97s_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
