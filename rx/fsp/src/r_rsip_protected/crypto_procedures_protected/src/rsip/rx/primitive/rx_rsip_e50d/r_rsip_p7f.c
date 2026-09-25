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

rsip_ret_t r_rsip_p7f (const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x007f0001U, 0x000007f0U);

    static const uint32_t Param_p7f_func100_001[] =
    {
        BSWAP_32BIG_C(0x5a1aa730U), BSWAP_32BIG_C(0x7b7e235bU), BSWAP_32BIG_C(0xbb95dd26U), BSWAP_32BIG_C(0x756b8beaU),
    };
    r_rsip_func100(Param_p7f_func100_001);
    r_rsip_func078(InData_DomainParam);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x08080010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

    WR1_PROG(REG_1404H, 0x12a80000U);
    r_rsip_func_sub009(0x00007f01U);

    static const uint32_t Param_p7f_func101_001[] =
    {
        BSWAP_32BIG_C(0xe39db5dbU), BSWAP_32BIG_C(0x8b06fa1fU), BSWAP_32BIG_C(0x579d4165U), BSWAP_32BIG_C(0xf598959aU),
    };
    r_rsip_func101(Param_p7f_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00007f02U);

    static const uint32_t Param_p7f_func101_002[] =
    {
        BSWAP_32BIG_C(0x40550371U), BSWAP_32BIG_C(0x698c2745U), BSWAP_32BIG_C(0xe77063d7U), BSWAP_32BIG_C(0xa0496e16U),
    };
    r_rsip_func101(Param_p7f_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00007f03U);

    static const uint32_t Param_p7f_func101_003[] =
    {
        BSWAP_32BIG_C(0x89e2483cU), BSWAP_32BIG_C(0x61ab2143U), BSWAP_32BIG_C(0xdd0330a5U), BSWAP_32BIG_C(0x7650c1a9U),
    };
    r_rsip_func101(Param_p7f_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00007f04U);

    static const uint32_t Param_p7f_func101_004[] =
    {
        BSWAP_32BIG_C(0x20aa9357U), BSWAP_32BIG_C(0x276ff974U), BSWAP_32BIG_C(0xd3fb087dU), BSWAP_32BIG_C(0x7787b303U),
    };
    r_rsip_func101(Param_p7f_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub009(0x00007f05U);

    static const uint32_t Param_p7f_func101_005[] =
    {
        BSWAP_32BIG_C(0xec3b0483U), BSWAP_32BIG_C(0xe49d6d9fU), BSWAP_32BIG_C(0x2de43a83U), BSWAP_32BIG_C(0xb3e3cda4U),
    };
    r_rsip_func101(Param_p7f_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    r_rsip_func_sub001(0x00c20009U);
    r_rsip_func_sub001(0x00020009U);

    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0808000aU);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub001(0x00c00009U);

    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x08080007U);

    static const uint32_t Param_p7f_func100_002[] =
    {
        BSWAP_32BIG_C(0x9f073a94U), BSWAP_32BIG_C(0x3a1f28a9U), BSWAP_32BIG_C(0xc12eb97dU), BSWAP_32BIG_C(0x2fd8270bU),
    };
    r_rsip_func100(Param_p7f_func100_002);
    WR1_PROG(REG_1600H, 0x00000800U);
    r_rsip_func_sub031(0x00000821U, 0x00000863U, 0x12080000U);
    WR1_PROG(REG_1608H, 0x80920001U);
    r_rsip_func_sub001(0x03430049U);

    for (iLoop = 0U; iLoop < 18U; iLoop++)
    {
        r_rsip_func_sub021(0x38000c63U, 0x20000842U, 0x10003841U, 0x0000b7c0U);
        WR1_PROG(REG_1600H, 0x0000001fU);

        for (jLoop = 0U; jLoop < 32U; jLoop++)
        {
            r_rsip_func_sub021(0x3800585eU, 0x20003460U, 0x20002c60U, 0x10002c00U);
            WR1_PROG(REG_1600H, 0x100033c0U);
        }

        r_rsip_func_sub034(0x0000a420U, 0x00000004U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x14380000U);
    r_rsip_func_sub001(0x00c00049U);

    r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x09090009U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x00003403U);

    WR1_PROG(REG_1600H, 0x00003060U);

    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x09090007U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x09090009U);

        WR1_PROG(REG_1600H, 0x00003060U);

        static const uint32_t Param_p7f_func101_006[] =
        {
            BSWAP_32BIG_C(0x0205b842U), BSWAP_32BIG_C(0x9fb7bb79U), BSWAP_32BIG_C(0x28a7bde5U), BSWAP_32BIG_C(
                0x599b5a1dU),
        };
        r_rsip_func101(Param_p7f_func101_006);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c03U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub001(0x00c00049U);

    static const uint32_t Param_p7f_func100_003[] =
    {
        BSWAP_32BIG_C(0x6cb2871fU), BSWAP_32BIG_C(0x53dee77bU), BSWAP_32BIG_C(0x0e424b16U), BSWAP_32BIG_C(0xf2dda49fU),
    };
    r_rsip_func100(Param_p7f_func100_003);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        static const uint32_t Param_p7f_func100_004[] =
        {
            BSWAP_32BIG_C(0x66a73d02U), BSWAP_32BIG_C(0x54032faaU), BSWAP_32BIG_C(0x8a5b4be2U), BSWAP_32BIG_C(
                0xf7ca2199U),
        };
        r_rsip_func100(Param_p7f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x09090009U);

            static const uint32_t Param_p7f_func101_007[] =
            {
                BSWAP_32BIG_C(0x2c7f027cU), BSWAP_32BIG_C(0xf374ea32U), BSWAP_32BIG_C(0x00203d56U), BSWAP_32BIG_C(
                    0xd21d68a1U),
            };
            r_rsip_func101(Param_p7f_func101_007);
        }

        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_func_sub005(0x00000250U, 0x0909000cU, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x09090009U);
        WR1_PROG(REG_1600H, 0x00003000U);

        static const uint32_t Param_p7f_func101_008[] =
        {
            BSWAP_32BIG_C(0x062c5537U), BSWAP_32BIG_C(0x193ab735U), BSWAP_32BIG_C(0x74e49be9U), BSWAP_32BIG_C(
                0xedf1b38bU),
        };
        r_rsip_func101(Param_p7f_func101_008);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x08080009U);

    static const uint32_t Param_p7f_func100_005[] =
    {
        BSWAP_32BIG_C(0xe0d4e962U), BSWAP_32BIG_C(0x4cf434faU), BSWAP_32BIG_C(0x74c5a5d7U), BSWAP_32BIG_C(0x0b1050a7U),
    };
    r_rsip_func100(Param_p7f_func100_005);

    r_rsip_func079(InData_DomainParam);

    r_rsip_func_sub009(0x0000007fU);

    static const uint32_t Param_p7f_func101_009[] =
    {
        BSWAP_32BIG_C(0x161b0670U), BSWAP_32BIG_C(0x1fa4b71dU), BSWAP_32BIG_C(0x31bb24efU), BSWAP_32BIG_C(0x27236689U),
    };
    r_rsip_func101(Param_p7f_func101_009);
    r_rsip_func090();

    static const uint32_t Param_p7f_func100_006[] =
    {
        BSWAP_32BIG_C(0xec15f832U), BSWAP_32BIG_C(0x1236f028U), BSWAP_32BIG_C(0x61942db4U), BSWAP_32BIG_C(0xd11855deU),
    };
    r_rsip_func100(Param_p7f_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7f_func102_001[] =
        {
            BSWAP_32BIG_C(0x09496839U), BSWAP_32BIG_C(0xf623bd1fU), BSWAP_32BIG_C(0xcf1ace08U), BSWAP_32BIG_C(
                0xf680c5a3U),
        };
        r_rsip_func102(Param_p7f_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub009(0x00007f06U);

        static const uint32_t Param_p7f_func101_010[] =
        {
            BSWAP_32BIG_C(0xb97a5b6bU), BSWAP_32BIG_C(0x9412f05aU), BSWAP_32BIG_C(0x42259f82U), BSWAP_32BIG_C(
                0xfcafd8b4U),
        };
        r_rsip_func101(Param_p7f_func101_010);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x0000007fU);

        static const uint32_t Param_p7f_func101_011[] =
        {
            BSWAP_32BIG_C(0x4f18fc8aU), BSWAP_32BIG_C(0x90f857a2U), BSWAP_32BIG_C(0x9ffc17c7U), BSWAP_32BIG_C(
                0x351664cdU),
        };
        r_rsip_func101(Param_p7f_func101_011);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000021U);

        r_rsip_func_sub009(0x0000007fU);

        static const uint32_t Param_p7f_func101_012[] =
        {
            BSWAP_32BIG_C(0x1d914906U), BSWAP_32BIG_C(0xc4fa82c5U), BSWAP_32BIG_C(0x7c435f33U), BSWAP_32BIG_C(
                0xc30be2d7U),
        };
        r_rsip_func101(Param_p7f_func101_012);
        r_rsip_func044();

        static const uint32_t Param_p7f_func100_007[] =
        {
            BSWAP_32BIG_C(0x7962e4f6U), BSWAP_32BIG_C(0x9a0355a4U), BSWAP_32BIG_C(0x59d93836U), BSWAP_32BIG_C(
                0xe9a542ffU),
        };
        r_rsip_func100(Param_p7f_func100_007);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1404H, 0x13000000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_008[] =
        {
            BSWAP_32BIG_C(0x79c0e841U), BSWAP_32BIG_C(0xa1eca38bU), BSWAP_32BIG_C(0x7ce149acU), BSWAP_32BIG_C(
                0x1bb068c9U),
        };
        r_rsip_func100(Param_p7f_func100_008);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);

        static const uint32_t Param_p7f_func100_009[] =
        {
            BSWAP_32BIG_C(0x5057413cU), BSWAP_32BIG_C(0xee308b88U), BSWAP_32BIG_C(0x7e0e6766U), BSWAP_32BIG_C(
                0x9c784c8eU),
        };
        r_rsip_func100(Param_p7f_func100_009);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);

        static const uint32_t Param_p7f_func100_010[] =
        {
            BSWAP_32BIG_C(0x13877d6dU), BSWAP_32BIG_C(0x865a7d9eU), BSWAP_32BIG_C(0xb4102a6aU), BSWAP_32BIG_C(
                0x66df9ea6U),
        };
        r_rsip_func100(Param_p7f_func100_010);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        r_rsip_func_sub009(0x00007f07U);

        static const uint32_t Param_p7f_func101_013[] =
        {
            BSWAP_32BIG_C(0xcea683e5U), BSWAP_32BIG_C(0x52a069d0U), BSWAP_32BIG_C(0x6f2812c5U), BSWAP_32BIG_C(
                0x98f2ee98U),
        };
        r_rsip_func101(Param_p7f_func101_013);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub009(0x00000009U);

        static const uint32_t Param_p7f_func101_014[] =
        {
            BSWAP_32BIG_C(0x6247439bU), BSWAP_32BIG_C(0x3529885fU), BSWAP_32BIG_C(0x0985b6a4U), BSWAP_32BIG_C(
                0xd0644798U),
        };
        r_rsip_func101(Param_p7f_func101_014);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000020U);

        r_rsip_func_sub009(0x00000009U);

        static const uint32_t Param_p7f_func101_015[] =
        {
            BSWAP_32BIG_C(0x48c36639U), BSWAP_32BIG_C(0xf260ba45U), BSWAP_32BIG_C(0xa2b2228bU), BSWAP_32BIG_C(
                0xaa168e0fU),
        };
        r_rsip_func101(Param_p7f_func101_015);
        r_rsip_func044();

        static const uint32_t Param_p7f_func100_011[] =
        {
            BSWAP_32BIG_C(0x8b62b21cU), BSWAP_32BIG_C(0x8a0283cbU), BSWAP_32BIG_C(0x800ea010U), BSWAP_32BIG_C(
                0xe23abb9aU),
        };
        r_rsip_func100(Param_p7f_func100_011);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        WR1_PROG(REG_1404H, 0x12600000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_012[] =
        {
            BSWAP_32BIG_C(0x84abf3f2U), BSWAP_32BIG_C(0x15b5d0dcU), BSWAP_32BIG_C(0xe44295dbU), BSWAP_32BIG_C(
                0x0469e71bU),
        };
        r_rsip_func100(Param_p7f_func100_012);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830011U);
        WR1_PROG(REG_1404H, 0x12b00000U);
        r_rsip_func_sub001(0x00830021U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 12; iLoop < 24U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_013[] =
        {
            BSWAP_32BIG_C(0xf2bdd5f4U), BSWAP_32BIG_C(0x3d68b9f9U), BSWAP_32BIG_C(0x9d93090eU), BSWAP_32BIG_C(
                0x26de8013U),
        };
        r_rsip_func100(Param_p7f_func100_013);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830021U);

        WR1_PROG(REG_1408H, 0x00002022U);
        for (iLoop = 24; iLoop < 32U; iLoop = iLoop + 4U)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_014[] =
        {
            BSWAP_32BIG_C(0x07c73233U), BSWAP_32BIG_C(0xd6d81737U), BSWAP_32BIG_C(0x8f864031U), BSWAP_32BIG_C(
                0x80bb2622U),
        };
        r_rsip_func100(Param_p7f_func100_014);
        r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);

        static const uint32_t Param_p7f_func100_015[] =
        {
            BSWAP_32BIG_C(0xd850b5e5U), BSWAP_32BIG_C(0xcf3d7e6aU), BSWAP_32BIG_C(0x5e08c7f6U), BSWAP_32BIG_C(
                0xdc22e3fdU),
        };
        r_rsip_func100(Param_p7f_func100_015);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_p7f_func102_002[] =
        {
            BSWAP_32BIG_C(0x20be4c1aU), BSWAP_32BIG_C(0xccdec0f9U), BSWAP_32BIG_C(0x0524100eU), BSWAP_32BIG_C(
                0x0b353c39U),
        };
        r_rsip_func102(Param_p7f_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
