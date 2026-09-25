/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

void HW_SCE_p_func057 (const uint32_t ARG1[], const uint32_t ARG2[], uint32_t ARG3[])
{
    uint32_t iLoop = 0U;
    uint32_t oLoop = 0U;

    HW_SCE_p_func100(0x95f12127U, 0xa79ca44dU, 0xbe3b33a3U, 0xbcc1ff81U);
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x08000045U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG1[0]);

    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x08000054U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x00000000U));

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
    WR1_PROG(REG_1420H, change_endian_long(0x0000f057U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xb7c75f5eU, 0xac681ca3U, 0x880369a1U, 0x4be90feeU);
    HW_SCE_p_func043();

    WR1_PROG(REG_1600H, 0x000034e4U);

    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, change_endian_long(0x0000f057U));
    WR1_PROG(REG_1458H, 0x00000000U);

    HW_SCE_p_func101(0xd80e3286U, 0x7c27f798U, 0x1c0794cfU, 0x80168749U);
    HW_SCE_p_func044();

    HW_SCE_p_func100(0x7a67b7daU, 0xdfa92f69U, 0x76b85526U, 0xd9015c84U);

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

    oLoop = 0x00000000U;
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); iLoop = iLoop + 4U)
        {
            HW_SCE_p_func100(0x3b7537f0U, 0x9a779e37U, 0x77acaac3U, 0x95b6a789U);
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xd900090dU);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &ARG2[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            WR1_PROG(REG_1400H, 0x00810011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG3[1 + iLoop]);

            HW_SCE_p_func101(0x169f372eU, 0x0503dc3bU, 0xf9a464f8U, 0x28e2c43dU);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        HW_SCE_p_func101(0xb4acdcd1U, 0x15772820U, 0xb786ccadU, 0x6d06230cU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000aU)
    {
        HW_SCE_p_func100(0x7d018923U, 0xaec95570U, 0xd128c8dbU, 0x0803ab5fU);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func061(0, ARG2);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func065(0, ARG3);
        HW_SCE_p_func100(0x5757fc0dU, 0x4a7233cbU, 0xe55577dbU, 0x71975a48U);
        HW_SCE_p_func065(8, ARG3);
        HW_SCE_p_func100(0xabd8ecf5U, 0x17235e5cU, 0x1f5ddc56U, 0x45bdb09dU);
        HW_SCE_p_func065(16, ARG3);
        HW_SCE_p_func100(0x1dcfc9adU, 0xae1d57c8U, 0x54319989U, 0x074b33c3U);
        HW_SCE_p_func065(24, ARG3);
        oLoop = oLoop + 32;

        HW_SCE_p_func100(0x84f69dc4U, 0x497951a6U, 0x6c8ff95aU, 0x52887391U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG2[iLoop]);
        iLoop = iLoop + 4;

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        WR1_PROG(REG_1400H, 0x00810011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &ARG3[1 + oLoop]);
        oLoop = oLoop + 4;

        WAIT_STS(REG_1A28H, 6, 0);

        HW_SCE_p_func101(0xd859386eU, 0x91fc7dc2U, 0x72094428U, 0xe990fe66U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000bU)
    {
        HW_SCE_p_func100(0x4d7bb5faU, 0xf3183e07U, 0xf9ad1a72U, 0xdaac74b4U);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func061(0, ARG2);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func062(0, ARG3);
        HW_SCE_p_func100(0xbec48e07U, 0xeccb304eU, 0x5d17d1aeU, 0xf04001bbU);
        HW_SCE_p_func062(8, ARG3);
        HW_SCE_p_func100(0x19bfb419U, 0xdf1bdcd9U, 0x9d0a86e5U, 0x84983c69U);
        HW_SCE_p_func062(16, ARG3);
        HW_SCE_p_func100(0xbce64b9eU, 0x64038f94U, 0x11df1a1bU, 0x2b38e04dU);
        HW_SCE_p_func062(24, ARG3);
        oLoop = oLoop + 32;

        HW_SCE_p_func100(0xb3175e21U, 0xfa105f19U, 0x7abda2bbU, 0x6eae66fdU);
        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func061(32, ARG2);
        iLoop = 32 + 32;

        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func062(32, ARG3);
        HW_SCE_p_func100(0x907ea1e4U, 0xa24e0192U, 0xc60af8b3U, 0x5905351aU);
        HW_SCE_p_func062(40, ARG3);
        HW_SCE_p_func100(0x13f3f9a1U, 0xe6938b37U, 0x377a066bU, 0xb0b23647U);
        HW_SCE_p_func062(48, ARG3);
        HW_SCE_p_func100(0x5ee08c44U, 0xcf8729bfU, 0x4d55e3ecU, 0x66a798c8U);
        HW_SCE_p_func062(56, ARG3);
        oLoop = oLoop + 32;

        HW_SCE_p_func101(0x75334cdfU, 0xf0c92b40U, 0xf9d8f060U, 0xd4dfacdcU);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000cU)
    {
        HW_SCE_p_func100(0x4976b9bdU, 0x6e68d8daU, 0xee918b58U, 0x9a93e545U);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func063(0, ARG2);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func065(0, ARG3);
        HW_SCE_p_func100(0xb72c696bU, 0x38d44582U, 0x5e6fae9dU, 0xa6eda7fbU);
        HW_SCE_p_func065(8, ARG3);
        HW_SCE_p_func100(0xad4f0a36U, 0x2da1af2fU, 0xaca8d165U, 0xe2864f61U);
        HW_SCE_p_func065(16, ARG3);
        HW_SCE_p_func100(0x89852cdbU, 0x90145e1bU, 0x4ccd5aa3U, 0xa1019407U);
        HW_SCE_p_func065(24, ARG3);
        HW_SCE_p_func100(0xcfc2a07fU, 0xb2283db1U, 0x12cfa527U, 0x4adf8b30U);
        HW_SCE_p_func065(32, ARG3);
        HW_SCE_p_func100(0xab72ddcbU, 0x3cd10ce5U, 0x873f90c4U, 0x3aeff5cfU);
        HW_SCE_p_func065(40, ARG3);
        HW_SCE_p_func100(0x54d321eaU, 0xc5796e19U, 0x2b3bd6c2U, 0x9ed46386U);
        HW_SCE_p_func065(48, ARG3);
        HW_SCE_p_func100(0x7a6a488dU, 0x5d93dbbcU, 0x34c68c36U, 0x3af2839dU);
        HW_SCE_p_func065(56, ARG3);
        oLoop = oLoop + 64;

        HW_SCE_p_func100(0x59f2c163U, 0x20e45f36U, 0xc23f6de9U, 0xe0b4f4ddU);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &ARG2[iLoop]);
        iLoop = iLoop + 4;

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        WR1_PROG(REG_1400H, 0x00810011U);
        WAIT_STS(REG_1404H, 30, 0);
        WR1_PROG(REG_143CH, 0x00001800U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &ARG3[1 + oLoop]);
        oLoop = oLoop + 4;

        WAIT_STS(REG_1A28H, 6, 0);

        HW_SCE_p_func101(0x6d742020U, 0x78765e7fU, 0x5b3b57b2U, 0xa0f487c4U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000dU)
    {
        HW_SCE_p_func100(0x61e1350bU, 0x8a25b6edU, 0x253fc9c3U, 0xc357670cU);
        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func063(0, ARG2);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        HW_SCE_p_func062(0, ARG3);
        HW_SCE_p_func100(0x880f6be6U, 0x540e9e78U, 0xb30214dbU, 0x26e29975U);
        HW_SCE_p_func062(8, ARG3);
        HW_SCE_p_func100(0x2d6e6579U, 0xefdf424fU, 0x9c89dcf6U, 0x0ad54b3eU);
        HW_SCE_p_func062(16, ARG3);
        HW_SCE_p_func100(0xf884cce5U, 0xbee21c51U, 0x40834d0eU, 0x4afbcaefU);
        HW_SCE_p_func062(24, ARG3);
        HW_SCE_p_func100(0x291300dbU, 0xee18d5a8U, 0x5c3622a3U, 0x185814e5U);
        HW_SCE_p_func062(32, ARG3);
        HW_SCE_p_func100(0xc85f8547U, 0x236b2c25U, 0xa8db5b67U, 0x33cefc87U);
        HW_SCE_p_func062(40, ARG3);
        HW_SCE_p_func100(0xddce6673U, 0xbe5fa412U, 0x0291fb96U, 0xc7172555U);
        HW_SCE_p_func062(48, ARG3);
        HW_SCE_p_func100(0x1d3ff5a2U, 0xb78a22f9U, 0x0f185352U, 0x4fc99589U);
        HW_SCE_p_func062(56, ARG3);
        oLoop = oLoop + 64;

        HW_SCE_p_func100(0x8357c615U, 0x4f001300U, 0x082cd798U, 0xd08b878aU);
        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func063(64, ARG2);
        iLoop = 64 + 64;

        WR1_PROG(REG_1404H, 0x11100000U);
        HW_SCE_p_func062(64, ARG3);
        HW_SCE_p_func100(0xa8d33135U, 0x5d4542bbU, 0x018c7a02U, 0x1e92dd8dU);
        HW_SCE_p_func062(72, ARG3);
        HW_SCE_p_func100(0x6de79107U, 0x85dd020aU, 0xf598b19aU, 0xbf572540U);
        HW_SCE_p_func062(80, ARG3);
        HW_SCE_p_func100(0xa437fd63U, 0x6a8bef7fU, 0xca25a26cU, 0xc296790eU);
        HW_SCE_p_func062(88, ARG3);
        HW_SCE_p_func100(0x836f233aU, 0x3854a851U, 0x7d3128a7U, 0x8752ef17U);
        HW_SCE_p_func062(96, ARG3);
        HW_SCE_p_func100(0xe66be75dU, 0x44d35053U, 0xfcd75ad9U, 0x92d44a7aU);
        HW_SCE_p_func062(104, ARG3);
        HW_SCE_p_func100(0x5de745d8U, 0xfede992cU, 0x73025640U, 0x0463e93dU);
        HW_SCE_p_func062(112, ARG3);
        HW_SCE_p_func100(0x918611c4U, 0x3ea5ee97U, 0xb65323deU, 0x3eb89708U);
        HW_SCE_p_func062(120, ARG3);
        oLoop = oLoop + 64;

        HW_SCE_p_func101(0xa8326ba2U, 0xb13fb422U, 0xdf35c8d3U, 0xbbe20d53U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000012U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); iLoop = iLoop + 4U)
        {
            HW_SCE_p_func100(0x08d8cf1dU, 0xdd0cdf3bU, 0x37ab5e9eU, 0x20d80d17U);
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xd900090dU);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &ARG2[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WR1_PROG(REG_1400H, 0x00810011U);
            WAIT_STS(REG_1404H, 30, 0);
            WR1_PROG(REG_143CH, 0x00001800U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG3[1 + iLoop]);

            HW_SCE_p_func101(0x04671718U, 0x1d125e32U, 0xd3be547dU, 0x256350b6U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        HW_SCE_p_func101(0x601d0573U, 0xc9f07c17U, 0x877f0671U, 0x3fd9f3bdU);
    }

    HW_SCE_p_func100(0x249e33b1U, 0x3141ebceU, 0x64e6be0eU, 0xdc5c69caU);
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
    RD4_ADDR(REG_1420H, &ARG3[1 + oLoop]);

    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x0900090dU);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &ARG2[iLoop]);

    WR1_PROG(REG_1824H, 0x9c100005U);
    WR1_PROG(REG_1400H, 0x00410011U);
    WAIT_STS(REG_1404H, 30, 0);
    WR1_PROG(REG_143CH, 0x00001800U);

    WR1_PROG(REG_1600H, 0x00007c1cU);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
