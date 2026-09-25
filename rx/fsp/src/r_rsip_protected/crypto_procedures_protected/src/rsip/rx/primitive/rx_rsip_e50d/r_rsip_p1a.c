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

rsip_ret_t r_rsip_p1a (const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x0001a001U, 0x000008c8U);

    r_rsip_func_sub009(0x00001a01U);

    static const uint32_t Param_p1a_func101_001[] =
    {
        BSWAP_32BIG_C(0x365df2b4U), BSWAP_32BIG_C(0x313f292bU), BSWAP_32BIG_C(0xe2fc3217U), BSWAP_32BIG_C(0x539cfc7bU),
    };
    r_rsip_func101(Param_p1a_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b400U, 0x00000050U, 0x80840000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub009(0x00001a02U);

    static const uint32_t Param_p1a_func101_002[] =
    {
        BSWAP_32BIG_C(0xa4ff7fdfU), BSWAP_32BIG_C(0x7abf9120U), BSWAP_32BIG_C(0xc132f5d6U), BSWAP_32BIG_C(0xc1d5aec7U),
    };
    r_rsip_func101(Param_p1a_func101_002);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b400U, 0x00000040U, 0x80840000U);
    r_rsip_func_sub001(0x03420011U);

    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_2004H, 0x000000b0U);

    r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000100U);

    WR1_PROG(REG_1608H, 0x81880000U);
    r_rsip_func_sub001(0x01490021U);

    WAIT_STS(REG_2030H, 4, 1);

    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1608H, 0x80880000U);
    r_rsip_func_sub001(0x03450021U);
    r_rsip_func_sub001(0x00050021U);

    r_rsip_func_sub021(0x00003820U, 0x00008c20U, 0xf8ffffffU, 0x00003c20U);

    r_rsip_func_sub021(0x0000b400U, 0x0000001cU, 0x00003820U, 0x00008c20U);
    r_rsip_func_sub021(0xffffff3fU, 0x00009020U, 0x00000040U, 0x00003c20U);

    r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
    WR1_PROG(REG_1600H, 0x0000001fU);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

        WR1_PROG(REG_1600H, 0x00002c20U);
        WR1_PROG(REG_1600H, 0x00003060U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1004H, 0x00000000U);
    WR1_PROG(REG_1004H, 0x04040000U);

    static const uint32_t Param_p1a_func100_001[] =
    {
        BSWAP_32BIG_C(0x2112df6fU), BSWAP_32BIG_C(0x41f8aa72U), BSWAP_32BIG_C(0x1ce8d14aU), BSWAP_32BIG_C(0xc945045cU),
    };
    r_rsip_func100(Param_p1a_func100_001);
    r_rsip_func401(InData_DomainParam);

    static const uint32_t Param_p1a_func100_002[] =
    {
        BSWAP_32BIG_C(0xe7289803U), BSWAP_32BIG_C(0x5b866195U), BSWAP_32BIG_C(0x425d6374U), BSWAP_32BIG_C(0x75d28a46U),
    };
    r_rsip_func100(Param_p1a_func100_002);
    r_rsip_func406(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x15000000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x16400000U);
    r_rsip_func_sub001(0x00c00021U);

    WR1_PROG(REG_1404H, 0x16900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x16e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x1b400000U);
    r_rsip_func_sub001(0x00c00021U);

    WR1_PROG(REG_1404H, 0x1b900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x1be00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    r_rsip_func_sub021(0x00000908U, 0x00000800U, 0x0000b420U, 0x0000001fU);

    r_rsip_func_sub021(0x0000b660U, 0x00000001U, 0x0000b520U, 0x00000100U);

    r_rsip_func_sub009(0x0000001aU);

    for (iLoop = 0U; iLoop < 256U; iLoop++)
    {
        r_rsip_func405();

        r_rsip_func403();

        static const uint32_t Param_p1a_func101_003[] =
        {
            BSWAP_32BIG_C(0xb93a96b7U), BSWAP_32BIG_C(0xfa0c4132U), BSWAP_32BIG_C(0xead74ed5U), BSWAP_32BIG_C(
                0xbd6b1969U),
        };
        r_rsip_func101(Param_p1a_func101_003);
        r_rsip_func402();

        r_rsip_func404();

        WR1_PROG(REG_1600H, 0x00002d00U);

        static const uint32_t Param_p1a_func101_004[] =
        {
            BSWAP_32BIG_C(0x43668820U), BSWAP_32BIG_C(0x840e1a2bU), BSWAP_32BIG_C(0x4b8e2335U), BSWAP_32BIG_C(
                0xc85b04a2U),
        };
        r_rsip_func101(Param_p1a_func101_004);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x08000909U);

    r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000570U, 0x0404000aU);

    r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);

    r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x00000610U, 0x0404000aU);

    WR1_PROG(REG_1014H, 0x00000610U);
    r_rsip_func_sub040(0x00000070U, 0x00000250U, 0x00000008U, 0x04040004U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x12d00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000070U, 0x000002f0U, 0x000002a0U, 0x0404000aU);

    static const uint32_t Param_p1a_func100_003[] =
    {
        BSWAP_32BIG_C(0xef5c7796U), BSWAP_32BIG_C(0x23043f02U), BSWAP_32BIG_C(0x63655e31U), BSWAP_32BIG_C(0x2ab66854U),
    };
    r_rsip_func100(Param_p1a_func100_003);
    r_rsip_func_sub013(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x0404000fU, 0x00010001U);
    r_rsip_func_sub007(0x00000570U, 0x000002f0U, 0x00000070U);
    r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
    r_rsip_func_sub007(0x000005c0U, 0x000002f0U, 0x00000070U);
    r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub030(0x12800000U, 0x00000821U, 0x80880001U);
    r_rsip_func_sub001(0x03430021U);

    WR1_PROG(REG_1600H, 0x00003801U);
    r_rsip_func_sub031(0x00008c00U, 0x7fffffffU, 0x12300000U);
    r_rsip_func_sub023(0x0000b420U, 0x00000020U, 0x80880001U);
    r_rsip_func_sub001(0x03430021U);

    r_rsip_func_sub021(0x0000b420U, 0x0000003cU, 0x00003841U, 0x001f6c42U);
    r_rsip_func_sub021(0x00001002U, 0x00000821U, 0x00003c01U, 0x00000800U);
    r_rsip_func_sub021(0x00000821U, 0x00000842U, 0x0000b460U, 0x0000001fU);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

        WR1_PROG(REG_1600H, 0x00002c20U);
        WR1_PROG(REG_1600H, 0x00003060U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00001a03U);

    static const uint32_t Param_p1a_func101_005[] =
    {
        BSWAP_32BIG_C(0x814e0835U), BSWAP_32BIG_C(0x3f8a0bcaU), BSWAP_32BIG_C(0xbfea416fU), BSWAP_32BIG_C(0xfc221041U),
    };
    r_rsip_func101(Param_p1a_func101_005);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00001a01U);

    static const uint32_t Param_p1a_func101_006[] =
    {
        BSWAP_32BIG_C(0x7226b8f8U), BSWAP_32BIG_C(0x487bf512U), BSWAP_32BIG_C(0x4fc69b0bU), BSWAP_32BIG_C(0x210a04e0U),
    };
    r_rsip_func101(Param_p1a_func101_006);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000027U);

    r_rsip_func_sub009(0x00001a01U);

    static const uint32_t Param_p1a_func101_007[] =
    {
        BSWAP_32BIG_C(0xceec4b7bU), BSWAP_32BIG_C(0x7215714aU), BSWAP_32BIG_C(0x68b95dddU), BSWAP_32BIG_C(0x0e40f691U),
    };
    r_rsip_func101(Param_p1a_func101_007);
    r_rsip_func044();

    static const uint32_t Param_p1a_func100_004[] =
    {
        BSWAP_32BIG_C(0xee512612U), BSWAP_32BIG_C(0xfdbf9914U), BSWAP_32BIG_C(0xc3322239U), BSWAP_32BIG_C(0x1f9aeb85U),
    };
    r_rsip_func100(Param_p1a_func100_004);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    r_rsip_func_sub023(0x0000b420U, 0x00000040U, 0x81880001U);
    r_rsip_func_sub001(0x00890021U);

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);

    static const uint32_t Param_p1a_func100_005[] =
    {
        BSWAP_32BIG_C(0x55dd756cU), BSWAP_32BIG_C(0xb2427fcaU), BSWAP_32BIG_C(0x99f05b1bU), BSWAP_32BIG_C(0xd72771deU),
    };
    r_rsip_func100(Param_p1a_func100_005);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);

    static const uint32_t Param_p1a_func100_006[] =
    {
        BSWAP_32BIG_C(0xdb15e661U), BSWAP_32BIG_C(0x441594e1U), BSWAP_32BIG_C(0x2c2f9b9cU), BSWAP_32BIG_C(0x3d4cd113U),
    };
    r_rsip_func100(Param_p1a_func100_006);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub009(0x00001a04U);

    static const uint32_t Param_p1a_func101_008[] =
    {
        BSWAP_32BIG_C(0x11d3b064U), BSWAP_32BIG_C(0x16ccdd49U), BSWAP_32BIG_C(0xba4ecea8U), BSWAP_32BIG_C(0x3de38254U),
    };
    r_rsip_func101(Param_p1a_func101_008);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub009(0x00001a02U);

    static const uint32_t Param_p1a_func101_009[] =
    {
        BSWAP_32BIG_C(0x6300c451U), BSWAP_32BIG_C(0x2845c583U), BSWAP_32BIG_C(0xe8d0d1c2U), BSWAP_32BIG_C(0xab7d820fU),
    };
    r_rsip_func101(Param_p1a_func101_009);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000026U);

    r_rsip_func_sub009(0x00001a02U);

    static const uint32_t Param_p1a_func101_010[] =
    {
        BSWAP_32BIG_C(0xd29fe4e1U), BSWAP_32BIG_C(0xcceb0473U), BSWAP_32BIG_C(0x0e688bc7U), BSWAP_32BIG_C(0xbd501949U),
    };
    r_rsip_func101(Param_p1a_func101_010);
    r_rsip_func044();

    static const uint32_t Param_p1a_func100_007[] =
    {
        BSWAP_32BIG_C(0x358c6806U), BSWAP_32BIG_C(0x633ed59dU), BSWAP_32BIG_C(0x72eae264U), BSWAP_32BIG_C(0xe022c11cU),
    };
    r_rsip_func100(Param_p1a_func100_007);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x81880001U);
    r_rsip_func_sub001(0x00890021U);

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);

    static const uint32_t Param_p1a_func100_008[] =
    {
        BSWAP_32BIG_C(0x6abb1a2bU), BSWAP_32BIG_C(0x6aa586a1U), BSWAP_32BIG_C(0xa9f74773U), BSWAP_32BIG_C(0x0bbd3ea7U),
    };
    r_rsip_func100(Param_p1a_func100_008);
    r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);

    static const uint32_t Param_p1a_func100_009[] =
    {
        BSWAP_32BIG_C(0x99fa8040U), BSWAP_32BIG_C(0x4e209fafU), BSWAP_32BIG_C(0x791faaa8U), BSWAP_32BIG_C(0x4f5af21aU),
    };
    r_rsip_func100(Param_p1a_func100_009);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p1a_func102_001[] =
    {
        BSWAP_32BIG_C(0x242f840dU), BSWAP_32BIG_C(0x09837a21U), BSWAP_32BIG_C(0xd85306daU), BSWAP_32BIG_C(0x14322fceU),
    };
    r_rsip_func102(Param_p1a_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
