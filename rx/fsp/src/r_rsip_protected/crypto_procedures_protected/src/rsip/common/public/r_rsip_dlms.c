/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_public.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define RSIP_PRV_ROUND_UP_AES_BLOCK(bytes)    ((bytes + 15) & ~15U)

/* Nonce and AAD length
 * - Nonce consists of the following data:
 *   - Sys-T : System Title (8 bytes)
 *   - IC    : Invocation Counter (4 bytes)
 * - AAD consists of the following data:
 *   - SC : Security Control (1 byte)
 *   - AK : Authentication Key
 *     - 16 bytes (for Security Suite 0 or 1)
 *     - 32 bytes (for Security Suite 2) */
#define RSIP_PRV_BYTE_SIZE_NONCE                       (12U) // Nonce
#define RSIP_PRV_BYTE_SIZE_AAD_SECURITY_SUITE_0_1      (17U) // AAD for Suite 0 or Suite 1
#define RSIP_PRV_BYTE_SIZE_AAD_SECURITY_SUITE_2        (33U) // AAD for Suite 2

#define RSIP_PRV_BYTE_SIZE_AAD_BUFFER                  RSIP_PRV_ROUND_UP_AES_BLOCK( \
        RSIP_PRV_BYTE_SIZE_AAD_SECURITY_SUITE_2)

/* Data position and size within the APDU
 * - APDU consists of the following data:
 *   - TAG : APDU Tag                    (1 byte)
 *   - LEN : Data Length of SH || C || T (1 byte)
 *   - SH  : Security Header             (5 bytes)
 *   - C   : Ciphered Message            (Max 49 bytes)
 *   - T   : Authentication Tag          (12 bytes)
 * - SH above consists of the following data:
 *   - SC : Security Control   (1 byte)
 *   - IC : Invocation Counter (4 bytes)
 * - Decrypted C consists of the following data:
 *   - Part 1        (Max 3 bytes, Min 2bytes)
 *   - Dedicated Key
 *     - AES-128     (16 bytes)
 *     - AES-256     (32 bytes)
 *   - Part 2        (Max 14 bytes)
 * - Part 1 above consists of the following data:
 *   - APDU Choice   (1 byte; 0x01 (Fixed value))
 *   - Key Flag      (1 byte; 0x00 : Not exist, Others : Exist)
 *   - Key Length    (1 byte; 0x10 : AES-128, 0x20 : AES-256)
 */
#define RSIP_PRV_BYTE_POS_APDU_LEN                     (1U)  // APDU Data Length
#define RSIP_PRV_BYTE_POS_APDU_SC                      (2U)  // Security Control
#define RSIP_PRV_BYTE_POS_APDU_C                       (7U)  // Ciphered Message
#define RSIP_PRV_BYTE_POS_APDU_PART1_APDU_CHOICE       (0U)  // APDU Choice
#define RSIP_PRV_BYTE_POS_APDU_PART1_KEY_FLAG          (1U)  // Key Flag
#define RSIP_PRV_BYTE_POS_APDU_PART1_KEY_LENGTH        (2U)  // Key Length

#define RSIP_PRV_BYTE_SIZE_APDU_SH                     (5U)  // Security Header
#define RSIP_PRV_BYTE_SIZE_APDU_T                      (12U) // Authentication Tag
#define RSIP_PRV_BYTE_SIZE_APDU_PART1_MAX              (3U)  // Part 1 (Max)
#define RSIP_PRV_BYTE_SIZE_APDU_PART1_MIN              (2U)  // Part 1 (Min)
#define RSIP_PRV_BYTE_SIZE_APDU_PART2_MAX              (14U) // Part 2 (Max)
#define RSIP_PRV_BYTE_SIZE_DEDICATED_KEY_AES_128       (16U) // Dedicated Key (AES-128)
#define RSIP_PRV_BYTE_SIZE_DEDICATED_KEY_AES_256       (32U) // Dedicated Key (AES-256)
#define RSIP_PRV_BYTE_SIZE_APDU_C_MAX                  (RSIP_PRV_BYTE_SIZE_APDU_PART1_MAX +        \
                                                        RSIP_PRV_BYTE_SIZE_DEDICATED_KEY_AES_256 + \
                                                        RSIP_PRV_BYTE_SIZE_APDU_PART2_MAX)
#define RSIP_PRV_BYTE_SIZE_APDU_LEN_MAX                (RSIP_PRV_BYTE_SIZE_APDU_SH + RSIP_PRV_BYTE_SIZE_APDU_C_MAX + \
                                                        RSIP_PRV_BYTE_SIZE_APDU_T)
#define RSIP_PRV_BYTE_SIZE_APDU_LEN_MIN                (RSIP_PRV_BYTE_SIZE_APDU_SH + RSIP_PRV_BYTE_SIZE_APDU_PART1_MIN + \
                                                        RSIP_PRV_BYTE_SIZE_APDU_T)

#define RSIP_PRV_DATA_APDU_PART1_APDU_CHOICE           (0x01U) // APDU Choice
#define RSIP_PRV_DATA_APDU_PART1_KEY_FLAG_NOT_EXIST    (0x00U) // Not exist

#define RSIP_PRV_BYTE_SIZE_APDU_PART1_BUFFER           (4U)
#define RSIP_PRV_BYTE_SIZE_APDU_PART2_BUFFER           (16U)
#define RSIP_PRV_BYTE_SIZE_APDU_C_BUFFER               RSIP_PRV_ROUND_UP_AES_BLOCK(RSIP_PRV_BYTE_SIZE_APDU_C_MAX)

/* Mask and data for SC (Security Control) byte
 * SC consists of the following data:
 * - Operational Mode (Bit[5:4]):
 *   - 00b : No protection
 *   - 01b : Authentication only
 *   - 10b : Encryption only
 *   - 11b : Authenticated Encryption (Only use this mode in this API)
 * - Security Suite (Bit[3:0]):
 *   - 0000b  : Suite 0 (AES-GCM-128)
 *   - 0001b  : Suite 1 (ECDH-ECDSA-AES-GCM-128-SHA-256)
 *   - 0010b  : Suite 2 (ECDH-ECDSA-AES-GCM-256-SHA-384)
 *   - Others : Reserved (Invalid)
 */
#define RSIP_PRV_MASK_SC_OPERATIONAL_MODE              (0x30U) // Operational Mode
#define RSIP_PRV_MASK_SC_SECURITY_SUITE                (0x0FU) // Security Suite

#define RSIP_PRV_DATA_SC_OPERATIONAL_MODE_AUTH_ENC     (0x30U) // Authenticated Encryption
#define RSIP_PRV_DATA_SC_SECURITY_SUITE_0              (0x00U) // Suite 0 (AES-GCM-128)
#define RSIP_PRV_DATA_SC_SECURITY_SUITE_1              (0x01U) // Suite 1 (ECDH-ECDSA-AES-GCM-128-SHA-256)
#define RSIP_PRV_DATA_SC_SECURITY_SUITE_2              (0x02U) // Suite 2 (ECDH-ECDSA-AES-GCM-256-SHA-384)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup RSIP_PROTECTED
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Decrypts and Verifies ciphered InitiateRequest message, and wraps a Dedicated Key embedded in the message.
 *
 * Implements @ref rsip_api_t::xdlmsInitiateRequestDecrypt.
 *
 * @par Conditions
 * @parblock
 * Decrypted InitiateRequest message consists of the following: @n
 * Part 1 and Part 2 are obtained as p_apdu_data (rsip_dlms_apdu_data_t structure), and Dedicated Key is obtained as p_dedicated_key (wrapped key).
 *  <table>
 *      <tr>
 *          <th colspan="3">Decrypted InitiateRequest message</th>
 *      </tr>
 *      <tr>
 *          <td>Part 1 @n (The first 3 bytes of the message, consisting of @n APDU Choice, Key Flag, and Key Length)</td>
 *          <td>Dedicated Key @n (AES-128 or AES-256 key)</td>
 *          <td>Part 2 @n (Remaining message; Maximum 14 bytes)</td>
 *      </tr>
 *  </table>
 *
 * Key type of p_wrapped_key must be one of the following and this must match Security Suite specified in SC (Security Control) byte:
 * - @ref RSIP_KEY_TYPE_AES_128
 * - @ref RSIP_KEY_TYPE_AES_256
 *
 * The p_value of the p_dedicated_key must point to a buffer of size RSIP_BYTE_SIZE_WRAPPED_KEY(RSIP_KEY_TYPE_AES_256). @n
 * The type of the p_dedicated_key will be set to either RSIP_KEY_TYPE_AES_128 or RSIP_KEY_TYPE_AES_256 as per InitiateRequest message.
 *
 * If the return value is FSP_SUCCESS, also refer to p_dlms_ret to check which result was returned:
 * - RSIP_DLMS_RET_SUCCESS : The process completed successfully, and both the Dedicated Key and the decrypted APDU data (p_apdu_data) were output.
 * - RSIP_DLMS_RET_NO_DEDICATED_KEY : The process completed successfully, but the Dedicated Key was not present within the InitiateRequest message. Only the decrypted APDU data was output.
 *
 * If the return value is FSP_ERR_CRYPTO_RSIP_DLMS_ERROR, also refer to p_dlms_ret to identify the more specific error.
 *
 * If the return value is neither FSP_SUCCESS nor FSP_ERR_CRYPTO_RSIP_DLMS_ERROR, p_dlms_ret will be indeterminate.
 * @endparblock
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS                           Normal termination. Refer also to the argument p_dlms_ret.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL      Input key value is illegal.
 * @retval FSP_ERR_CRYPTO_RSIP_AUTHENTICATION    Authentication is failed.
 * @retval FSP_ERR_CRYPTO_RSIP_DLMS_ERROR        An error occurred during DLMS processing. Refer to the argument p_dlms_ret for more details.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_xDLMS_InitiateRequest_Decrypt (rsip_ctrl_t * const              p_ctrl,
                                                rsip_wrapped_key_t const * const p_wrapped_key,
                                                uint8_t const * const            p_apdu,
                                                uint8_t const * const            p_nonce,
                                                uint8_t const * const            p_aad,
                                                uint32_t const                   aad_length,
                                                rsip_wrapped_key_t * const       p_dedicated_key,
                                                rsip_dlms_apdu_data_t * const    p_apdu_data,
                                                rsip_dlms_ret_t * const          p_dlms_ret)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_key);
    FSP_ASSERT(p_wrapped_key->p_value);
    FSP_ASSERT(p_apdu);
    FSP_ASSERT(p_nonce);
    FSP_ASSERT(p_aad);
    FSP_ASSERT(p_dedicated_key);
    FSP_ASSERT(p_dedicated_key->p_value);
    FSP_ASSERT(p_apdu_data);
    FSP_ASSERT(p_dlms_ret);
#endif

    rsip_key_type_extend_t                key_type_ext = r_rsip_key_type_parse(p_wrapped_key->type);              // Parse key type
    rsip_func_dlms_initiate_request_dec_t p_func       = gp_func_dlms_initiate_request_dec[key_type_ext.subtype]; // Set function

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                                // Check configuration
    FSP_ERROR_RETURN(RSIP_PRV_ALG_AES == key_type_ext.alg, FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL);                     // Check key type
#endif

    /* Check module open */
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;

    /* Check LEN field within the APDU */
    if ((p_apdu[RSIP_PRV_BYTE_POS_APDU_LEN] > RSIP_PRV_BYTE_SIZE_APDU_LEN_MAX) ||
        (p_apdu[RSIP_PRV_BYTE_POS_APDU_LEN] < RSIP_PRV_BYTE_SIZE_APDU_LEN_MIN))
    {
        err         = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
        *p_dlms_ret = RSIP_DLMS_RET_INVALID_SIZE_LEN;
    }
    /* Check Operational Mode within the SC (Security Control) byte */
    else if ((p_apdu[RSIP_PRV_BYTE_POS_APDU_SC] & RSIP_PRV_MASK_SC_OPERATIONAL_MODE) !=
             RSIP_PRV_DATA_SC_OPERATIONAL_MODE_AUTH_ENC)
    {
        err         = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
        *p_dlms_ret = RSIP_DLMS_RET_INVALID_OPERATIONAL_MODE;
    }
    /* Check Security Suite within the SC (Security Control) byte */
    else
    {
        uint8_t security_suite = (uint8_t) (p_apdu[RSIP_PRV_BYTE_POS_APDU_SC] & RSIP_PRV_MASK_SC_SECURITY_SUITE);

        switch (security_suite)
        {
            /* Security Suite 0, 1 : AES-128 */
            case RSIP_PRV_DATA_SC_SECURITY_SUITE_0:
            case RSIP_PRV_DATA_SC_SECURITY_SUITE_1:
            {
                /* Check if the key type of p_wrapped_key matches the Security Suite */
                if (key_type_ext.subtype != RSIP_PRV_KEY_SUBTYPE_AES_128)
                {
                    err         = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
                    *p_dlms_ret = RSIP_DLMS_RET_SECURITY_SUITE_MISMATCH;
                }
                /* Check if the AAD length is valid for Security Suite */
                else if (aad_length != RSIP_PRV_BYTE_SIZE_AAD_SECURITY_SUITE_0_1)
                {
                    err         = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
                    *p_dlms_ret = RSIP_DLMS_RET_INVALID_SIZE_AAD;
                }
                else
                {
                    /* No errors */
                }

                break;
            }

            /* Security Suite 2 : AES-256 */
            case RSIP_PRV_DATA_SC_SECURITY_SUITE_2:
            {
                /* Check if the key type of p_wrapped_key matches the Security Suite */
                if (key_type_ext.subtype != RSIP_PRV_KEY_SUBTYPE_AES_256)
                {
                    err         = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
                    *p_dlms_ret = RSIP_DLMS_RET_SECURITY_SUITE_MISMATCH;
                }
                /* Check if the AAD length is valid for Security Suite */
                else if (aad_length != RSIP_PRV_BYTE_SIZE_AAD_SECURITY_SUITE_2)
                {
                    err         = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
                    *p_dlms_ret = RSIP_DLMS_RET_INVALID_SIZE_AAD;
                }
                else
                {
                    /* No errors */
                }

                break;
            }

            /* Others (Invalid) */
            default:
            {
                err         = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
                *p_dlms_ret = RSIP_DLMS_RET_INVALID_SECURITY_SUITE;
            }
        }
    }

    /* Normal operation */
    if (err != FSP_ERR_CRYPTO_RSIP_DLMS_ERROR)
    {
        uint32_t hashed_ivec[4] =
        {
            0
        };
        uint32_t aad_tmp[RSIP_PRV_BYTE_SIZE_AAD_BUFFER / sizeof(uint32_t)] =
        {
            0
        };
        uint32_t msg_tmp[RSIP_PRV_BYTE_SIZE_APDU_C_BUFFER / sizeof(uint32_t)] =
        {
            0
        };
        uint32_t tag_tmp[RSIP_PRV_BYTE_SIZE_AES_BLOCK / sizeof(uint32_t)] =
        {
            0
        };
        uint8_t part1_tmp[RSIP_PRV_BYTE_SIZE_APDU_PART1_BUFFER] =
        {
            0
        };
        uint8_t part2_tmp[RSIP_PRV_BYTE_SIZE_APDU_PART2_BUFFER] =
        {
            0
        };

        uint8_t msg_length =
            (uint8_t) (p_apdu[RSIP_PRV_BYTE_POS_APDU_LEN] - RSIP_PRV_BYTE_SIZE_APDU_SH - RSIP_PRV_BYTE_SIZE_APDU_T);

        /* Copy nonce, aad, message and tag */
        memcpy(hashed_ivec, p_nonce, RSIP_PRV_BYTE_SIZE_NONCE);
        hashed_ivec[3] = bswap_32big(0x00000001U);
        memcpy(aad_tmp, p_aad, aad_length);
        memcpy(msg_tmp, p_apdu + RSIP_PRV_BYTE_POS_APDU_C, (size_t) msg_length);
        memcpy(tag_tmp, p_apdu + RSIP_PRV_BYTE_POS_APDU_C + msg_length, RSIP_PRV_BYTE_SIZE_APDU_T);

        /* Set parameters */
        uint32_t aad_bit_size[2] =
        {
            bswap_32big(r_rsip_byte_to_bit_convert_upper((uint64_t) aad_length)),
            bswap_32big(r_rsip_byte_to_bit_convert_lower((uint64_t) aad_length))
        };
        uint32_t msg_length_tmp[1] = {bswap_32big((uint32_t) msg_length)};
        uint32_t tag_length_tmp[1] = {bswap_32big(RSIP_PRV_BYTE_SIZE_APDU_T)};

        /* Call function (cast to match the argument type with the primitive function) */
        rsip_ret_t rsip_ret = p_func((const uint32_t *) p_wrapped_key->p_value,
                                     hashed_ivec,
                                     aad_tmp,
                                     aad_bit_size,
                                     msg_tmp,
                                     msg_length_tmp,
                                     tag_tmp,
                                     tag_length_tmp,
                                     (uint32_t *) part1_tmp,
                                     (uint32_t *) p_dedicated_key->p_value,
                                     (uint32_t *) part2_tmp,
                                     r_rsip_byte_to_word_convert(RSIP_PRV_ROUND_UP_AES_BLOCK(aad_length)));

        /* Check error */
        switch (rsip_ret)
        {
            case RSIP_RET_PASS:
            {
                /* If the Dedicated Key exists */
                if (part1_tmp[RSIP_PRV_BYTE_POS_APDU_PART1_KEY_FLAG] !=
                    RSIP_PRV_DATA_APDU_PART1_KEY_FLAG_NOT_EXIST)
                {
                    /* Set key type */
                    p_dedicated_key->type =
                        (part1_tmp[RSIP_PRV_BYTE_POS_APDU_PART1_KEY_LENGTH] ==
                         RSIP_PRV_BYTE_SIZE_DEDICATED_KEY_AES_128) ? RSIP_KEY_TYPE_AES_128 : RSIP_KEY_TYPE_AES_256;
                    *p_dlms_ret = RSIP_DLMS_RET_SUCCESS;
                }
                /* If the Dedicated Key does not exist */
                else
                {
                    *p_dlms_ret = RSIP_DLMS_RET_NO_DEDICATED_KEY;
                }

                memcpy(p_apdu_data->part_1, part1_tmp, RSIP_PRV_BYTE_SIZE_APDU_PART1_MAX);
                memcpy(p_apdu_data->part_2, part2_tmp, RSIP_PRV_BYTE_SIZE_APDU_PART2_MAX);

                err = FSP_SUCCESS;
                break;
            }

            case RSIP_RET_VERIFICATION_FAIL:
            {
                /* If the APDU Choice is invalid */
                if (part1_tmp[RSIP_PRV_BYTE_POS_APDU_PART1_APDU_CHOICE] !=
                    RSIP_PRV_DATA_APDU_PART1_APDU_CHOICE)
                {
                    *p_dlms_ret = RSIP_DLMS_RET_INVALID_APDU_CHOICE;
                }
                /* If the Key Length is invalid */
                else
                {
                    *p_dlms_ret = RSIP_DLMS_RET_INVALID_KEY_LENGTH;
                }

                memcpy(p_apdu_data->part_1, part1_tmp, RSIP_PRV_BYTE_SIZE_APDU_PART1_MAX);

                err = FSP_ERR_CRYPTO_RSIP_DLMS_ERROR;
                break;
            }

            case RSIP_RET_KEY_FAIL:
            {
                err = FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL;
                break;
            }

            case RSIP_RET_AUTH_FAIL:
            {
                err = FSP_ERR_CRYPTO_RSIP_AUTHENTICATION;
                break;
            }

            case RSIP_RET_RESOURCE_CONFLICT:
            {
                err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
                break;
            }

            default:
            {
                err = FSP_ERR_CRYPTO_RSIP_FATAL;
            }
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RSIP_PROTECTED)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
