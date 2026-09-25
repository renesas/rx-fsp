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

rsip_ret_t r_rsip_p51i (const uint32_t InData_CurveType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00510001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub009(0x00005101U);

    static const uint32_t Param_p51i_func101_001[] =
    {
        BSWAP_32BIG_C(0x05d8c540U), BSWAP_32BIG_C(0xb38d2edeU), BSWAP_32BIG_C(0x8d91aac0U), BSWAP_32BIG_C(0x018959eaU),
    };
    r_rsip_func101(Param_p51i_func101_001);
    r_rsip_func043();

    r_rsip_func077();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub009(0x00005101U);

    static const uint32_t Param_p51i_func101_002[] =
    {
        BSWAP_32BIG_C(0x880048d6U), BSWAP_32BIG_C(0xcdc39f49U), BSWAP_32BIG_C(0xd0b74ed8U), BSWAP_32BIG_C(0xb3c44648U),
    };
    r_rsip_func101(Param_p51i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000017c2U, 0x40000500U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80980001U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
    r_rsip_func_sub001(0x03420031U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[21]);
    r_rsip_func_sub001(0x03420031U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[25]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p51i_func100_001[] =
    {
        BSWAP_32BIG_C(0x8f18665fU), BSWAP_32BIG_C(0xcce0a012U), BSWAP_32BIG_C(0x5167774bU), BSWAP_32BIG_C(0x2781bc22U),
    };
    r_rsip_func100(Param_p51i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p51i_func102_001[] =
        {
            BSWAP_32BIG_C(0x44dd8a64U), BSWAP_32BIG_C(0x3a9c2e03U), BSWAP_32BIG_C(0xdc8ef5d6U), BSWAP_32BIG_C(
                0x7a768f81U),
        };
        r_rsip_func102(Param_p51i_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000bc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x808c001fU);
        for (iLoop = 0U; iLoop < 12U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x00000200U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x818c001eU);
        r_rsip_func_sub001(0x00890031U);

        r_rsip_func_sub023(0x0000b7c0U, 0x00000100U, 0x808c001eU);
        r_rsip_func_sub001(0x03420031U);

        r_rsip_func_sub003(0x80010360U, 0x00000051U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p51i_func100_002[] =
        {
            BSWAP_32BIG_C(0xcb3d8db5U), BSWAP_32BIG_C(0x0398be7cU), BSWAP_32BIG_C(0xc75fa3f5U), BSWAP_32BIG_C(
                0xaf1ea9bcU),
        };
        r_rsip_func100(Param_p51i_func100_002);
        r_rsip_func027(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

        WR1_PROG(REG_1404H, 0x19000000U);
        r_rsip_func_sub008(0x000017c2U, 0x00000500U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x19500000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x11d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0606000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p51i_func100_003[] =
        {
            BSWAP_32BIG_C(0x4f99ea94U), BSWAP_32BIG_C(0x8a4d4a6cU), BSWAP_32BIG_C(0x7cbf6971U), BSWAP_32BIG_C(
                0x3d63c9f4U),
        };
        r_rsip_func100(Param_p51i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p51i_func101_003[] =
            {
                BSWAP_32BIG_C(0xfcf7f374U), BSWAP_32BIG_C(0xaaa31bb4U), BSWAP_32BIG_C(0xa9dff3e6U), BSWAP_32BIG_C(
                    0x30f0f18eU),
            };
            r_rsip_func101(Param_p51i_func101_003);
        }
        else
        {
            static const uint32_t Param_p51i_func100_004[] =
            {
                BSWAP_32BIG_C(0xf76d323cU), BSWAP_32BIG_C(0x98c2cf8fU), BSWAP_32BIG_C(0x993d4cc3U), BSWAP_32BIG_C(
                    0xbffc36aeU),
            };
            r_rsip_func100(Param_p51i_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0606000aU);

            r_rsip_func_sub041(0x00000980U, 0x000001b0U, 0x000000c0U, 0x00000110U, 0x00000020U, 0x0606000fU);
            r_rsip_func_sub035(0x00010001U);

            r_rsip_func_sub038(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub030(0x10e00000U, 0x00000bffU, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub038(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x06060002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub001(0x00c00031U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x06060004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002b8U, 0x06060009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x06060009U);

            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1608H, 0x818c0001U);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a00U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10e00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1608H, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub038(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a38U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p51i_func100_005[] =
            {
                BSWAP_32BIG_C(0x360bff5fU), BSWAP_32BIG_C(0x3dc6df6cU), BSWAP_32BIG_C(0xb834fd1aU), BSWAP_32BIG_C(
                    0x84b405d2U),
            };
            r_rsip_func100(Param_p51i_func100_005);
            r_rsip_func028(InData_DomainParam);

            r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000af0U, 0x06060009U);

            r_rsip_func_sub002(0x00000218U, 0x00000160U, 0x00000b28U, 0x06060009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x06060009U);

            r_rsip_func_sub002(0x00000af0U, 0x00000a00U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a00U, 0x00000af0U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b28U, 0x00000a38U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a38U, 0x00000b28U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p51i_func100_006[] =
            {
                BSWAP_32BIG_C(0x86cef022U), BSWAP_32BIG_C(0x084144ffU), BSWAP_32BIG_C(0x8f000707U), BSWAP_32BIG_C(
                    0xedd1342bU),
            };
            r_rsip_func100(Param_p51i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub038(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x06060013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p51i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x9cc79bdaU), BSWAP_32BIG_C(0x7d6a56bdU), BSWAP_32BIG_C(0xab1d7894U), BSWAP_32BIG_C(
                        0x41904952U),
                };
                r_rsip_func101(Param_p51i_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x06060014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p51i_func101_005[] =
                {
                    BSWAP_32BIG_C(0x85ba6847U), BSWAP_32BIG_C(0x60e7e5b8U), BSWAP_32BIG_C(0xb1b76571U), BSWAP_32BIG_C(
                        0x36e1ebbbU),
                };
                r_rsip_func101(Param_p51i_func101_005);
            }

            WR1_PROG(REG_1600H, 0x00000821U);

            WR1_PROG(REG_1404H, 0x14500000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            r_rsip_func_sub031(0x0000a420U, 0x00000050U, 0x13100000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 12U; iLoop++)
            {
                r_rsip_func_sub021(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub022(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11300000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0002dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_p51i_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x28d7fab6U), BSWAP_32BIG_C(0x58783147U), BSWAP_32BIG_C(0x68d18072U),
                        BSWAP_32BIG_C(0x47a8d1c6U),
                    };
                    r_rsip_func100(Param_p51i_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p51i_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x5b87390fU), BSWAP_32BIG_C(0xa0ffd07fU), BSWAP_32BIG_C(0x9704b75fU),
                            BSWAP_32BIG_C(0xebc7a859U),
                        };
                        r_rsip_func101(Param_p51i_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p51i_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xacc0758aU), BSWAP_32BIG_C(0x536f933cU), BSWAP_32BIG_C(0x21e910d4U),
                            BSWAP_32BIG_C(0xf573464cU),
                        };
                        r_rsip_func101(Param_p51i_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p51i_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x82b099f6U), BSWAP_32BIG_C(0x6a6237faU), BSWAP_32BIG_C(0xf0d22b42U),
                        BSWAP_32BIG_C(0x077c1266U),
                    };
                    r_rsip_func100(Param_p51i_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p51i_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x86824d2dU), BSWAP_32BIG_C(0xec81c76bU), BSWAP_32BIG_C(0xa82dbdb2U),
                            BSWAP_32BIG_C(0xcbe69747U),
                        };
                        r_rsip_func100(Param_p51i_func100_009);

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub001(0x00c00031U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x00000a00U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a38U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_008[] =
                            {
                                BSWAP_32BIG_C(0xf84b4e2bU), BSWAP_32BIG_C(0x8fe60922U), BSWAP_32BIG_C(0xc0bead29U),
                                BSWAP_32BIG_C(0x6bac5d2eU),
                            };
                            r_rsip_func101(Param_p51i_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000af0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b28U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_009[] =
                            {
                                BSWAP_32BIG_C(0x8887f691U), BSWAP_32BIG_C(0x165d8d73U), BSWAP_32BIG_C(0x764dc948U),
                                BSWAP_32BIG_C(0x5922721eU),
                            };
                            r_rsip_func101(Param_p51i_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000be0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c18U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x56288e3fU), BSWAP_32BIG_C(0x6276611fU), BSWAP_32BIG_C(0x901a96e0U),
                                BSWAP_32BIG_C(0x84e96d8eU),
                            };
                            r_rsip_func101(Param_p51i_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c0002dU);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_p51i_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x136bf6acU), BSWAP_32BIG_C(0x3eaec471U), BSWAP_32BIG_C(0xaa21fa16U),
                            BSWAP_32BIG_C(0xa5d9e756U),
                        };
                        r_rsip_func100(Param_p51i_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p51i_func100_011[] =
                            {
                                BSWAP_32BIG_C(0xb1ea3687U), BSWAP_32BIG_C(0x1c741d20U), BSWAP_32BIG_C(0xc8ea09f8U),
                                BSWAP_32BIG_C(0x9e542be3U),
                            };
                            r_rsip_func100(Param_p51i_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001e0U, 0x00000410U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000410U, 0x000001e0U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000218U, 0x00000448U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000448U, 0x00000218U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_p51i_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0x4648a680U), BSWAP_32BIG_C(0xd2f70ffeU), BSWAP_32BIG_C(0x0e206f1fU),
                                    BSWAP_32BIG_C(0x81d71fa8U),
                                };
                                r_rsip_func100(Param_p51i_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub038(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p51i_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x7ae06e78U), BSWAP_32BIG_C(0x621ba3afU), BSWAP_32BIG_C(
                                            0x408df7c9U),           BSWAP_32BIG_C(0x8c7f61cdU),
                                    };
                                    r_rsip_func101(Param_p51i_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p51i_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x33572497U), BSWAP_32BIG_C(0x66de7dc4U), BSWAP_32BIG_C(
                                            0xdeec290dU),           BSWAP_32BIG_C(0x70a3e97fU),
                                    };
                                    r_rsip_func101(Param_p51i_func101_012);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                            }
                            else
                            {
                                static const uint32_t Param_p51i_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x0f99a593U), BSWAP_32BIG_C(0x8fe82c16U), BSWAP_32BIG_C(0xf76a2cd0U),
                                    BSWAP_32BIG_C(0xff88041dU),
                                };
                                r_rsip_func101(Param_p51i_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11300000U);
                            r_rsip_func_sub001(0x00c00031U);

                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x000001e0U, 0x06060009U);

                            r_rsip_func_sub002(0x00000448U, 0x00000160U, 0x00000218U, 0x06060009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x26de81b0U), BSWAP_32BIG_C(0xcef845f4U), BSWAP_32BIG_C(0x9d18bf30U),
                                BSWAP_32BIG_C(0x911e1959U),
                            };
                            r_rsip_func101(Param_p51i_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p51i_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x54382ee9U), BSWAP_32BIG_C(0xa9f40809U), BSWAP_32BIG_C(0x8af39aceU),
                            BSWAP_32BIG_C(0x50fad532U),
                        };
                        r_rsip_func101(Param_p51i_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p51i_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xe733a647U), BSWAP_32BIG_C(0x25099f9aU), BSWAP_32BIG_C(0xe18c2d08U),
                        BSWAP_32BIG_C(0xf2c22153U),
                    };
                    r_rsip_func101(Param_p51i_func101_016);
                }

                WR1_PROG(REG_1600H, 0x38008840U);
                r_rsip_func_sub011(0x00000020U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p51i_func101_017[] =
                {
                    BSWAP_32BIG_C(0x094ceba8U), BSWAP_32BIG_C(0xee8d01feU), BSWAP_32BIG_C(0x38bf6f62U), BSWAP_32BIG_C(
                        0xa502bbf0U),
                };
                r_rsip_func101(Param_p51i_func101_017);
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            r_rsip_func_sub011(0x0000000cU);

            WR1_PROG(REG_1404H, 0x12700000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p51i_func100_013[] =
            {
                BSWAP_32BIG_C(0x1ff1bc8eU), BSWAP_32BIG_C(0x24569db1U), BSWAP_32BIG_C(0x0f179d3dU), BSWAP_32BIG_C(
                    0x32bb944cU),
            };
            r_rsip_func100(Param_p51i_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p51i_func101_018[] =
                {
                    BSWAP_32BIG_C(0xb2ead785U), BSWAP_32BIG_C(0x5a7416e7U), BSWAP_32BIG_C(0x7e474f40U), BSWAP_32BIG_C(
                        0xcf5ff8c1U),
                };
                r_rsip_func101(Param_p51i_func101_018);
            }
            else
            {
                static const uint32_t Param_p51i_func100_014[] =
                {
                    BSWAP_32BIG_C(0xae827190U), BSWAP_32BIG_C(0xe07a2d8bU), BSWAP_32BIG_C(0xdea8eb3fU), BSWAP_32BIG_C(
                        0x89452878U),
                };
                r_rsip_func100(Param_p51i_func100_014);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x06060004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);

                r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0606000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub038(0x000001e0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p51i_func100_015[] =
                {
                    BSWAP_32BIG_C(0xc27c011bU), BSWAP_32BIG_C(0xdb2875c9U), BSWAP_32BIG_C(0xb22c0d1aU), BSWAP_32BIG_C(
                        0x2a4016c8U),
                };
                r_rsip_func100(Param_p51i_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p51i_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xe30c8db9U), BSWAP_32BIG_C(0x51259803U), BSWAP_32BIG_C(0xca780c5eU),
                        BSWAP_32BIG_C(0xd92a2024U),
                    };
                    r_rsip_func101(Param_p51i_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xa69ef2d0U);

                    static const uint32_t Param_p51i_func101_020[] =
                    {
                        BSWAP_32BIG_C(0xc96421f7U), BSWAP_32BIG_C(0x61a56a07U), BSWAP_32BIG_C(0x653d88c1U),
                        BSWAP_32BIG_C(0xe086a67bU),
                    };
                    r_rsip_func101(Param_p51i_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0xa69ef2d0U, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p51i_func100_016[] =
        {
            BSWAP_32BIG_C(0xe8436a8bU), BSWAP_32BIG_C(0x40e2dc2eU), BSWAP_32BIG_C(0x0a09c79aU), BSWAP_32BIG_C(
                0xd033a1f0U),
        };
        r_rsip_func100(Param_p51i_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p51i_func102_002[] =
            {
                BSWAP_32BIG_C(0x35c69925U), BSWAP_32BIG_C(0x7cfb59c9U), BSWAP_32BIG_C(0xf2778a8dU), BSWAP_32BIG_C(
                    0x928b0c14U),
            };
            r_rsip_func102(Param_p51i_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1A2CH, 0x00000200U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            r_rsip_func_sub023(0x0000b7c0U, 0x00000100U, 0x818c001eU);
            r_rsip_func_sub001(0x00890031U);

            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1608H, 0x808c001eU);
            r_rsip_func_sub001(0x03420031U);

            static const uint32_t Param_p51i_func101_021[] =
            {
                BSWAP_32BIG_C(0x189dc3edU), BSWAP_32BIG_C(0x6e682729U), BSWAP_32BIG_C(0xea0d5436U), BSWAP_32BIG_C(
                    0x7f5293d3U),
            };
            r_rsip_func101(Param_p51i_func101_021);

            return RSIP_RET_PASS;
        }
    }
}
