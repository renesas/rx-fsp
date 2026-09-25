/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2016-2019 JUUL Labs
 * Copyright (c) 2017 Linaro LTD
 *
 * Original license:
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/**********************************************************************************************************************
 Includes
 *********************************************************************************************************************/
#include <string.h>

#include "mcuboot_config/mcuboot_config.h"
#include "rsip_keys.h"

#if defined (MCUBOOT_SIGN_EC256)
#if defined (MCUBOOT_USE_RSIP)
#include "mbedtls/build_info.h"
#include "bootutil/sign_key.h"

#include "mbedtls/oid.h"
#include "mbedtls/asn1.h"
#include "bootutil/crypto/ecdsa.h"
#include "bootutil_priv.h"
#include "rsip_ecdsa_p256.h"

/**
 * Declaring these like this adds NULL termination.
 */
/* Read public key information from ASN1 format. */
static const uint8_t ec_pubkey_oid[] = MBEDTLS_OID_EC_ALG_UNRESTRICTED;
/* Read the elliptic curve information from ASN1 format. */
static const uint8_t ec_secp256r1_oid[] = MBEDTLS_OID_EC_GRP_SECP256R1;

/*******************************************************************************************************************//**
 * Executes ECDSA signature verification with a key length of 256 bits.
 **********************************************************************************************************************/
static inline int32_t bootutil_ecdsa_verify (bootutil_ecdsa_context_t * p_ctx, const uint8_t * p_pk,
                                                const uint8_t * p_hash, const uint8_t * p_sig)
{
    (void) p_ctx;
    fsp_err_t err = FSP_ERR_ASSERTION;

    err = R_RSIP_ECDSA_Verify(&g_rsip_ctrl, (rsip_wrapped_key_t *)p_pk, p_hash, p_sig);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }

    return 0;
}

/*******************************************************************************************************************//**
 * Parse the public key used for signing.
 **********************************************************************************************************************/
static int32_t bootutil_import_key(uint8_t **pp_cp, uint8_t *p_end)
{
    size_t len;
    mbedtls_asn1_buf alg;
    mbedtls_asn1_buf param;

    if (mbedtls_asn1_get_tag(pp_cp, p_end, &len,
        MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE))
    {
        return -1;
    }
    p_end = (*pp_cp) + len;

    /* ECParameters (RFC5480) */
    if (mbedtls_asn1_get_alg(pp_cp, p_end, &alg, &param))
    {
        return -1;
    }
    /* id-ecPublicKey (RFC5480) */
    if ((alg.len != ((sizeof(ec_pubkey_oid)) - 1)) ||
        memcmp(alg.p, ec_pubkey_oid, (sizeof(ec_pubkey_oid)) - 1))
    {
        return -1;
    }
    /* namedCurve (RFC5480) */
    if ((param.len != ((sizeof(ec_secp256r1_oid)) - 1)) ||
        memcmp(param.p, ec_secp256r1_oid, (sizeof(ec_secp256r1_oid)) - 1))
    {
        return -1;
    }
    /* ECPoint (RFC5480) */
    if (mbedtls_asn1_get_bitstring_null(pp_cp, p_end, &len))
    {
        return -1;
    }
    if (((*pp_cp) + len) != p_end)
    {
        return -1;
    }

    if (len != ((2 * NUM_ECC_BYTES) + (1)))
    {
        return -1;
    }
    /* Is uncompressed? */
    if ((*pp_cp[0]) != 0x04)
    {
        return -1;
    }

    (*pp_cp)++;

    return 0;
}

/*******************************************************************************************************************//**
 * cp points to ASN1 string containing an integer.
 * Verify the tag, and that the length is 32 bytes.
 **********************************************************************************************************************/
static int32_t bootutil_read_bigint(uint8_t i[NUM_ECC_BYTES], uint8_t **pp_cp, uint8_t *p_end)
{
    size_t len;

    if (mbedtls_asn1_get_tag(pp_cp, p_end, &len, MBEDTLS_ASN1_INTEGER))
    {
        return -1;
    }

    if (len >= NUM_ECC_BYTES)
    {
        memcpy(i, ((*pp_cp) + len) - NUM_ECC_BYTES, NUM_ECC_BYTES);
    }
    else
    {
        memset(i, 0, NUM_ECC_BYTES - len);
        memcpy((i + (NUM_ECC_BYTES - len)), *pp_cp, len);
    }
    (*pp_cp) += len;
    return 0;
}

/*******************************************************************************************************************//**
 * Read in signature. Signature has r and s encoded as integers.
 **********************************************************************************************************************/
static int32_t bootutil_decode_sig(uint8_t signature[NUM_ECC_BYTES * 2], uint8_t *p_cp, uint8_t *p_end)
{
    int32_t rc;
    size_t len;

    rc = mbedtls_asn1_get_tag(&p_cp, p_end, &len,
        MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE);
    if (rc)
    {
        return -1;
    }
    if ((p_cp + len) > p_end)
    {
        return -1;
    }

    rc = bootutil_read_bigint(signature, &p_cp, p_end);
    if (rc)
    {
        return -1;
    }
    rc = bootutil_read_bigint(signature + NUM_ECC_BYTES, &p_cp, p_end);
    if (rc)
    {
        return -1;
    }
    return 0;
}

/*******************************************************************************************************************//**
 * Perform signature verification.
 **********************************************************************************************************************/
fih_ret bootutil_verify_sig(uint8_t *p_hash, uint32_t hlen, uint8_t *p_sig, size_t slen, uint8_t key_id)
{
    int32_t rc;
    bootutil_ecdsa_context_t ctx;
    uint8_t *p_pubkey;
    uint8_t *p_end;

    uint8_t signature[2 * NUM_ECC_BYTES];
    uint8_t public_key_installed[RSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP256R1_PUBLIC];

    uint8_t *p_plaintext = public_key_installed + (0x8U);

    /* If the DER format public key address is not set in the configuration, -1 is returned. */
    if ((bootutil_keys[key_id].key == NULL) || (bootutil_keys[key_id].len == NULL))
    {
        return -1;
    }
    p_pubkey = (uint8_t *)bootutil_keys[key_id].key;
    p_end = p_pubkey + (*bootutil_keys[key_id].len);

    rc = bootutil_import_key(&p_pubkey, p_end);
    if (rc)
    {
        return -1;
    }

    rc = bootutil_decode_sig(signature, p_sig, p_sig + slen);
    if (rc)
    {
        return -1;
    }

    /* The key_id passed to this function is for a key from bootutil_keys[] and
     * its hash has already been validated. Since the imgtool.py does not handle
     * the hash for the wrapped public key, we compare the public key portion of
     * the wrappedkey from bootutil_keys_wrapped[] with the key from
     * bootutil_keys[] and if both are the same, then we use the key from
     * bootutil_keys_wrapped[] to perform the verification using the protected
     * mode procedures. */
    /** Returns -1 if the wrapped public key address is not set in the configuration. */
    if(g_bootutil_keys_wrapped[key_id].key == NULL)
    {
        return -1;
    }
    memcpy(public_key_installed, (uint8_t *) g_bootutil_keys_wrapped[key_id].key, MCUBOOT_RSIP_ECC_PUB_KEY_LEN);
    if (memcmp (p_plaintext, p_pubkey, 2 * NUM_ECC_BYTES))
    {
        return -1;
    }

    /* This is simplified, as the hash length is also 32 bytes. */
    if (hlen != NUM_ECC_BYTES)
    {
        return -1;
    }

    bootutil_ecdsa_init(&ctx);

    rc = bootutil_ecdsa_verify(&ctx, public_key_installed, p_hash, signature);
    bootutil_ecdsa_drop(&ctx);

    return rc;
}

#endif /* MCUBOOT_USE_RSIP */

#endif /* MCUBOOT_SIGN_EC256 */
