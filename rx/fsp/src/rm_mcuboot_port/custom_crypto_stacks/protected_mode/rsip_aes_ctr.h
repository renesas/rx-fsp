 /*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include "mcuboot_config/mcuboot_config.h"
#if(defined(MCUBOOT_USE_RSIP)) != 1
#error "One crypto backend must be defined: RSIP"
#endif
#if defined(MCUBOOT_USE_RSIP)
#include <string.h>
#include "r_rsip.h"
#include "rsip_keys.h"
#endif
#include <stdint.h>

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
#ifndef BOOTUTIL_CRYPTO_RSIP_AES_CTR_H
#define BOOTUTIL_CRYPTO_RSIP_AES_CTR_H


#if defined (MCUBOOT_USE_RSIP)
/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/
typedef struct
{
    rsip_wrapped_key_t* p_key;
}rsip_aes_context_t;

typedef rsip_aes_context_t bootutil_aes_ctr_context;
extern rsip_instance_ctrl_t g_rsip_ctrl;

/*******************************************************************************************************************//**
 * Prepare for image encryption/decryption processing.
 **********************************************************************************************************************/
static inline void bootutil_aes_ctr_init(bootutil_aes_ctr_context *p_ctx)
{
    /* Do nothing. */
    (void)p_ctx;
}

/*******************************************************************************************************************//**
 * Release resources for image encryption/decryption processing.
 **********************************************************************************************************************/
static inline void bootutil_aes_ctr_drop(bootutil_aes_ctr_context *p_ctx)
{
    /* Do nothing. */
    (void)p_ctx;
}

/*******************************************************************************************************************//**
 * Set the key index of the image encryption key.
 **********************************************************************************************************************/
static inline int32_t bootutil_aes_ctr_set_key(bootutil_aes_ctr_context *p_ctx, const uint8_t *p_k)
{
    p_ctx->p_key = (rsip_wrapped_key_t *)p_k;
    return 0;
}

/*******************************************************************************************************************//**
 * Encrypt the input sentence and output the result.
 * According to the RSIP specifications, the processing is equivalent to bootutil_aes_ctr_decrypt.
 **********************************************************************************************************************/
static inline int32_t bootutil_aes_ctr_encrypt(bootutil_aes_ctr_context *p_ctx, uint8_t *p_counter, const uint8_t *p_m,
                                                uint32_t mlen, size_t blk_off, uint8_t *p_c)
{
    fsp_err_t err = FSP_ERR_ASSERTION;

    /* If blk_off is non-zero, RSIP does nothing. */
    if (blk_off != 0)
    {
        return -1;
    }
    err = R_RSIP_AES_Cipher_Init(&g_rsip_ctrl, RSIP_AES_CIPHER_MODE_CTR, p_ctx->p_key, p_counter);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    err = R_RSIP_AES_Cipher_Update(&g_rsip_ctrl, (uint8_t *)p_m, p_c, mlen);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    err = R_RSIP_AES_Cipher_Finish(&g_rsip_ctrl);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    return 0;
}

/*******************************************************************************************************************//**
 * Decrypt the input sentence and output the result.
 **********************************************************************************************************************/
static inline int32_t bootutil_aes_ctr_decrypt(bootutil_aes_ctr_context *p_ctx, uint8_t *p_counter, const uint8_t *p_c,
                                                uint32_t clen, size_t blk_off, uint8_t *p_m)
{
    fsp_err_t err = FSP_ERR_ASSERTION;

    /* If blk_off is non-zero, RSIP does nothing. */
    if (blk_off != 0)
    {
        return -1;
    }
    err = R_RSIP_AES_Cipher_Init(&g_rsip_ctrl, RSIP_AES_CIPHER_MODE_CTR, p_ctx->p_key, p_counter);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    err = R_RSIP_AES_Cipher_Update(&g_rsip_ctrl, (uint8_t *)p_c, p_m, clen);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    err = R_RSIP_AES_Cipher_Finish(&g_rsip_ctrl);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    return 0;
}

/*******************************************************************************************************************//**
 * End process for decrypto.
 **********************************************************************************************************************/
static inline int32_t bootutil_aes_ctr_finish(bootutil_aes_ctr_context *p_ctx)
{
    /* Do nothing. */
    (void)p_ctx;
    return 0;
}

#endif /* MCUBOOT_USE_RSIP */
#endif /* BOOTUTIL_CRYPTO_RSIP_AES_CTR_H */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/******************************************************************************
 * End  Of File
 ******************************************************************************/
