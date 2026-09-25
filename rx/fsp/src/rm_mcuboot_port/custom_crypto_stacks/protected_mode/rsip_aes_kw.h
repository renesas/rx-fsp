 /*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "mcuboot_config/mcuboot_config.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#if defined(MCUBOOT_USE_RSIP)
#include "r_rsip.h"
#include "rsip_aes_ctr.h"
#include "rsip_keys.h"
#endif

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
#ifndef BOOTUTIL_CRYPTO_RSIP_AES_KW_H
#define BOOTUTIL_CRYPTO_RSIP_AES_KW_H

#if(defined(MCUBOOT_USE_RSIP)) != 1
#error "One crypto backend must be defined: either RSIP or TINYCRYPT"
#endif

#if defined(MCUBOOT_USE_RSIP)

/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/
typedef rsip_aes_context_t bootutil_aes_kw_context;

/*******************************************************************************************************************//**
 * Initialize key wrap processing.
 **********************************************************************************************************************/
static inline void bootutil_aes_kw_init(bootutil_aes_kw_context *p_ctx)
{
    /* Do nothing. */
    (void)p_ctx;
}

/*******************************************************************************************************************//**
 * Release resources for key wrap processing.
 **********************************************************************************************************************/
static inline void bootutil_aes_kw_drop(bootutil_aes_kw_context *p_ctx)
{
    /* Do nothing. */
    (void)p_ctx;
}

/*******************************************************************************************************************//**
 * Set the key encryption key.
 **********************************************************************************************************************/
static inline int32_t bootutil_aes_kw_set_unwrap_key(bootutil_aes_kw_context *p_ctx, const uint8_t *p_k, uint32_t klen)
{
    (void)klen;
    /** If the key wrap key address is not set, -1 is returned. */
    if (p_k == NULL)
    {
        return -1;
    }
    p_ctx->p_key = (rsip_wrapped_key_t*)p_k;
    return 0;
}

/*******************************************************************************************************************//**
 * Decrypts the encrypted image encryption key.
 **********************************************************************************************************************/
static inline int32_t bootutil_aes_kw_unwrap(bootutil_aes_kw_context *p_ctx, const uint8_t *p_wrapped_key,
                                            uint32_t wrapped_key_len, uint8_t *p_key, uint32_t key_len)
{
    (void)wrapped_key_len;
    (void)key_len;
    fsp_err_t err = FSP_ERR_ASSERTION;

    err = R_RSIP_RFC3394_KeyUnwrap(&g_rsip_ctrl, p_ctx->p_key, RSIP_KEY_TYPE_AES_256, (uint8_t*)p_wrapped_key, (rsip_wrapped_key_t*)p_key);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }

    return 0;
}

#endif /* MCUBOOT_USE_RSIP */

#endif /* BOOTUTIL_CRYPTO_RSIP_AES_KW_H */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/******************************************************************************
 * End  Of File
 ******************************************************************************/
