/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func093 (const uint32_t ARG1[], uint32_t ARG2[])
{
    uint32_t iLoop = 0U;
    uint32_t oLoop = 0U;

    HW_SCE_p_func100(0x5aade16dU, 0x9b174083U, 0xa59669cbU, 0xbb77c7d8U);
    HW_SCE_p_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1400H, 0x03420005U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1400H, 0x0002000dU);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1600H, 0x000034e0U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000f093U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xd2ae525fU, 0x60534f75U, 0x2029cea2U, 0x969556d4U);
    HW_SCE_p_func043();

    WR1_PROG(REG_1600H, 0x000034e4U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000f093U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xe109aad6U, 0x0a617d7aU, 0x30e62f4cU, 0xd8f08b28U);
    HW_SCE_p_func044();

    HW_SCE_p_func100(0x6ca70d1fU, 0xbb82939eU, 0x6ceeea9cU, 0x3184e0a8U);

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    WR1_PROG(REG_1000H, 0x00010000U);

    HW_SCE_p_func081();

    WR1_PROG(REG_1600H, 0x00007c01U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    oLoop = 0U;
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE); iLoop = iLoop + 4U)
        {
            HW_SCE_p_func100(0x14b2c5dfU, 0x6655bd94U, 0x4f6b1885U, 0x77c63b4cU);
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &ARG1[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            WR1_PROG(REG_1400H, 0x00810011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG2[1 + iLoop]);

            HW_SCE_p_func101(0xedcfced6U, 0xff61a8c7U, 0x7c35639bU, 0xf4150868U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        HW_SCE_p_func101(0xb5170247U, 0xf35bee6cU, 0x977dc94cU, 0x642bb91eU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000aU)
    {
        HW_SCE_p_func100(0x5e82f51dU, 0xfe508bccU, 0x8b333787U, 0x4ada3eccU);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func094(0, ARG1);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func065(0, ARG2);
        HW_SCE_p_func100(0x41c7d6dbU, 0x97c7f626U, 0x78d70871U, 0x7b725380U);
        HW_SCE_p_func065(8, ARG2);
        HW_SCE_p_func100(0x90cb0880U, 0x3ce76b58U, 0xcf74216aU, 0x2b75a2d1U);
        HW_SCE_p_func065(16, ARG2);
        HW_SCE_p_func100(0xeb707c40U, 0x1011c449U, 0xc99da81eU, 0x4ef299c8U);
        HW_SCE_p_func065(24, ARG2);
        oLoop = oLoop + 32;

        HW_SCE_p_func100(0x0c45c364U, 0xa81e0e44U, 0x21953f32U, 0x8fed3986U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000105U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        iLoop = iLoop + 4;

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        WR1_PROG(REG_1400H, 0x00810011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &ARG2[1 + oLoop]);
        oLoop = oLoop + 4;

        WAIT_STS(REG_1A28H, 6, 0);

        HW_SCE_p_func101(0x0073eb6bU, 0x44f80e1cU, 0x7404c3b5U, 0x92b773daU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000bU)
    {
        HW_SCE_p_func100(0x2dcd6025U, 0x848be97eU, 0xe67d39f2U, 0xce1964b2U);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func094(0, ARG1);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func062(0, ARG2);
        HW_SCE_p_func100(0x8393daceU, 0x2e064b9aU, 0x3c8437f8U, 0xa827dc65U);
        HW_SCE_p_func062(8, ARG2);
        HW_SCE_p_func100(0x804f4abcU, 0x04b5f421U, 0xa7312d49U, 0x1734114eU);
        HW_SCE_p_func062(16, ARG2);
        HW_SCE_p_func100(0x971c56deU, 0xc1098763U, 0x1699c57aU, 0xa83e7428U);
        HW_SCE_p_func062(24, ARG2);
        oLoop = oLoop + 32;

        HW_SCE_p_func100(0x83700a65U, 0x36ec2d08U, 0x930db71aU, 0x98ca31c5U);
        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func094(32, ARG1);
        iLoop = 32 + 32;

        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func062(32, ARG2);
        HW_SCE_p_func100(0x30eb2218U, 0x46bf0c6cU, 0xa9cabf59U, 0xef757255U);
        HW_SCE_p_func062(40, ARG2);
        HW_SCE_p_func100(0x7db8409dU, 0x22af166dU, 0x12f44179U, 0xf76589a1U);
        HW_SCE_p_func062(48, ARG2);
        HW_SCE_p_func100(0x64aaa62dU, 0xacf1552dU, 0x810ad403U, 0xdaf0831fU);
        HW_SCE_p_func062(56, ARG2);
        oLoop = oLoop + 32;

        HW_SCE_p_func101(0xb8fa8ecdU, 0xa5b17e1dU, 0xe80b6b81U, 0x0593db1fU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000cU)
    {
        HW_SCE_p_func100(0xc637af63U, 0x1dd5ced4U, 0x1d86428dU, 0xfeac5aa1U);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func095(0, ARG1);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func065(0, ARG2);
        HW_SCE_p_func100(0x34286a62U, 0xa2dea7dfU, 0x1684a3daU, 0xfe980804U);
        HW_SCE_p_func065(8, ARG2);
        HW_SCE_p_func100(0x563bc000U, 0xa82a9d74U, 0x5a5b7b28U, 0x04b2a96aU);
        HW_SCE_p_func065(16, ARG2);
        HW_SCE_p_func100(0x567a3664U, 0x42cc2328U, 0x0401c42eU, 0x17e98c18U);
        HW_SCE_p_func065(24, ARG2);
        HW_SCE_p_func100(0xa9df1ff8U, 0x3c0556f5U, 0x3ff5693bU, 0xe4eb5970U);
        HW_SCE_p_func065(32, ARG2);
        HW_SCE_p_func100(0x90eeb372U, 0x15cff00aU, 0xab6f116aU, 0x2df17c78U);
        HW_SCE_p_func065(40, ARG2);
        HW_SCE_p_func100(0x0f71f9e7U, 0xeebdf84dU, 0xec3f0a4bU, 0xc51b0afbU);
        HW_SCE_p_func065(48, ARG2);
        HW_SCE_p_func100(0xcea7b4f9U, 0x1b1b562cU, 0xa09ee599U, 0xcb556af9U);
        HW_SCE_p_func065(56, ARG2);
        oLoop = oLoop + 64;

        HW_SCE_p_func100(0xf5702d8dU, 0x0568f4daU, 0xa125a1f4U, 0xd9d4dce7U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000105U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG1[iLoop]);
        iLoop = iLoop + 4;

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        WR1_PROG(REG_1400H, 0x00810011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &ARG2[1 + oLoop]);
        oLoop = oLoop + 4;

        WAIT_STS(REG_1A28H, 6, 0);

        HW_SCE_p_func101(0x376c62ddU, 0xffaad39eU, 0x056b2862U, 0x6779c747U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000dU)
    {
        HW_SCE_p_func100(0x94e1e212U, 0xeb692fe4U, 0x266a9b42U, 0xaab2aeccU);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func095(0, ARG1);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func062(0, ARG2);
        HW_SCE_p_func100(0x2407fb44U, 0x847b6774U, 0x95dea4b3U, 0xa6496aa5U);
        HW_SCE_p_func062(8, ARG2);
        HW_SCE_p_func100(0x8f1a89d8U, 0xafff2687U, 0x61d6e6cfU, 0x625e630cU);
        HW_SCE_p_func062(16, ARG2);
        HW_SCE_p_func100(0xe3b34046U, 0x45478396U, 0x17879b0aU, 0x7c2ae788U);
        HW_SCE_p_func062(24, ARG2);
        HW_SCE_p_func100(0xddec52c8U, 0x1a0f14adU, 0x95824b9dU, 0x1d51d4d3U);
        HW_SCE_p_func062(32, ARG2);
        HW_SCE_p_func100(0x4f048561U, 0xa628a566U, 0xca13a2aaU, 0x43e1edebU);
        HW_SCE_p_func062(40, ARG2);
        HW_SCE_p_func100(0x7858e231U, 0x86923872U, 0x21963e84U, 0x7cf62535U);
        HW_SCE_p_func062(48, ARG2);
        HW_SCE_p_func100(0x8cb032a8U, 0x3151bd6dU, 0xd0af2ec4U, 0x07bb8038U);
        HW_SCE_p_func062(56, ARG2);
        oLoop = oLoop + 64;

        HW_SCE_p_func100(0xe6f450dfU, 0x254e5aaaU, 0x8ae23c67U, 0xbc9d8fcaU);
        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func095(64, ARG1);
        iLoop = 64 + 64;

        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func062(64, ARG2);
        HW_SCE_p_func100(0xe37ac492U, 0x9dbe4b10U, 0xf37bcc8bU, 0x1cb57716U);
        HW_SCE_p_func062(72, ARG2);
        HW_SCE_p_func100(0xb1b26050U, 0x904a6eceU, 0x7cc54c3bU, 0xda4187a0U);
        HW_SCE_p_func062(80, ARG2);
        HW_SCE_p_func100(0xe14444b5U, 0x925646c1U, 0x21ba4443U, 0x34b76687U);
        HW_SCE_p_func062(88, ARG2);
        HW_SCE_p_func100(0xe895572eU, 0x2e286ba9U, 0xe91a0399U, 0x6a144bc5U);
        HW_SCE_p_func062(96, ARG2);
        HW_SCE_p_func100(0x76e14c29U, 0x081b4c52U, 0x344981ecU, 0x32a0534bU);
        HW_SCE_p_func062(104, ARG2);
        HW_SCE_p_func100(0x6ffcf9b2U, 0xfcfee2feU, 0xa99f7c32U, 0xf261fccbU);
        HW_SCE_p_func062(112, ARG2);
        HW_SCE_p_func100(0xcf364fccU, 0xffa15f81U, 0x6b637364U, 0xef0dc22dU);
        HW_SCE_p_func062(120, ARG2);
        oLoop = oLoop + 64;

        HW_SCE_p_func101(0x1bfcc2b4U, 0xb5ca5accU, 0xb5eb2888U, 0x6916665dU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000012U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE); iLoop = iLoop + 4U)
        {
            HW_SCE_p_func100(0x741a6a81U, 0xe01dac5cU, 0x75b73e73U, 0x17bcea9eU);
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &ARG1[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WR1_PROG(REG_1400H, 0x00810011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG2[1 + iLoop]);

            HW_SCE_p_func101(0x5bfc31c9U, 0x58092704U, 0xd562a4daU, 0x591dc97aU);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        HW_SCE_p_func101(0x93e31331U, 0x5692c4acU, 0x3f74d939U, 0xe5fe6f09U);
    }

    HW_SCE_p_func100(0x59ba3c67U, 0xb0eacfddU, 0x6851a54fU, 0x5428407dU);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    WR1_PROG(REG_1400H, 0x00820011U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG2[1 + oLoop]);

    WR1_PROG(REG_1600H, 0x00007c1cU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
