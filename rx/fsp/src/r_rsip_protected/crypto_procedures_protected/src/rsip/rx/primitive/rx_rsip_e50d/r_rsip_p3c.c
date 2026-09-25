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

rsip_ret_t r_rsip_p3c (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003c0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub009(0x00003c01U);

    static const uint32_t Param_p3c_func101_001[] =
    {
        BSWAP_32BIG_C(0x31e76ee3U), BSWAP_32BIG_C(0x9f71e067U), BSWAP_32BIG_C(0x755769e5U), BSWAP_32BIG_C(0xa0a1de89U),
    };
    r_rsip_func101(Param_p3c_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x0000003cU);

    static const uint32_t Param_p3c_func101_002[] =
    {
        BSWAP_32BIG_C(0xda3ed45cU), BSWAP_32BIG_C(0x5e78f303U), BSWAP_32BIG_C(0xcc13fd5cU), BSWAP_32BIG_C(0x9d7895b0U),
    };
    r_rsip_func101(Param_p3c_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000028U);

    r_rsip_func_sub009(0x0000003cU);

    static const uint32_t Param_p3c_func101_003[] =
    {
        BSWAP_32BIG_C(0xbc06b69aU), BSWAP_32BIG_C(0x7440addaU), BSWAP_32BIG_C(0xa74069b6U), BSWAP_32BIG_C(0x04ffe162U),
    };
    r_rsip_func101(Param_p3c_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3c_func100_001[] =
    {
        BSWAP_32BIG_C(0x73ffb7a4U), BSWAP_32BIG_C(0xc82a2c9fU), BSWAP_32BIG_C(0x1f0ae847U), BSWAP_32BIG_C(0xbeee1e33U),
    };
    r_rsip_func100(Param_p3c_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub009(0x00003c02U);

    static const uint32_t Param_p3c_func101_004[] =
    {
        BSWAP_32BIG_C(0xa7e4d265U), BSWAP_32BIG_C(0x9c3f3477U), BSWAP_32BIG_C(0x279b746fU), BSWAP_32BIG_C(0xde414278U),
    };
    r_rsip_func101(Param_p3c_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003c03U);

    static const uint32_t Param_p3c_func101_005[] =
    {
        BSWAP_32BIG_C(0x01de41b7U), BSWAP_32BIG_C(0xe62c0e94U), BSWAP_32BIG_C(0x28f1cdbfU), BSWAP_32BIG_C(0x9791703fU),
    };
    r_rsip_func101(Param_p3c_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00003c04U);

    static const uint32_t Param_p3c_func101_006[] =
    {
        BSWAP_32BIG_C(0x96963defU), BSWAP_32BIG_C(0x084ab7f1U), BSWAP_32BIG_C(0x887c65e8U), BSWAP_32BIG_C(0x76b3f3aaU),
    };
    r_rsip_func101(Param_p3c_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3c_func100_002[] =
    {
        BSWAP_32BIG_C(0x2c47c11dU), BSWAP_32BIG_C(0x610e0be3U), BSWAP_32BIG_C(0xc29ce8b8U), BSWAP_32BIG_C(0x3a143a63U),
    };
    r_rsip_func100(Param_p3c_func100_002);

    r_rsip_func_sub027(0x40000200U, 0xe7009d47U, 0x810c0000U);
    r_rsip_func_sub001(0x00890031U);

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    static const uint32_t Param_p3c_func100_003[] =
    {
        BSWAP_32BIG_C(0x02203d35U), BSWAP_32BIG_C(0xaee60c90U), BSWAP_32BIG_C(0x8c9d6f6dU), BSWAP_32BIG_C(0x07912b76U),
    };
    r_rsip_func100(Param_p3c_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000003U));

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);

    static const uint32_t Param_p3c_func102_001[] =
    {
        BSWAP_32BIG_C(0x2601e83bU), BSWAP_32BIG_C(0xa8190eb4U), BSWAP_32BIG_C(0x451b915dU), BSWAP_32BIG_C(0x0fd51b6cU),
    };
    r_rsip_func102(Param_p3c_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
