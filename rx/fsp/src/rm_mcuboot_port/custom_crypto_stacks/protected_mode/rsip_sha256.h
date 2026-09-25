 /*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "r_rsip.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

#ifndef BOOTUTIL_CRYPTO_RSIP_SHA256_H
#define BOOTUTIL_CRYPTO_RSIP_SHA256_H

#define BOOTUTIL_CRYPTO_SHA256_DIGEST_SIZE_BYTES  (32)

typedef struct
{
    rsip_sha_handle_t sha_handle;
}rsip_sha_context_t;

/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/
typedef rsip_sha_context_t bootutil_sha_context;
extern rsip_instance_ctrl_t g_rsip_ctrl;

/*******************************************************************************************************************//**
 * Prepare for hash value calculation.
 **********************************************************************************************************************/
static inline void bootutil_sha_init (bootutil_sha_context * p_ctx)
{
    R_RSIP_SHA_Init(&g_rsip_ctrl, RSIP_HASH_TYPE_SHA256);
    R_RSIP_SHA_Suspend(&g_rsip_ctrl, &p_ctx->sha_handle);
}

/*******************************************************************************************************************//**
 * Release resources for hash value calculation.
 **********************************************************************************************************************/
static inline void bootutil_sha_drop (bootutil_sha_context * p_ctx)
{
    /* Do nothing. */
    (void) p_ctx;
}

/*******************************************************************************************************************//**
 * Perform hash value calculation.
 **********************************************************************************************************************/
static inline int32_t bootutil_sha_update (bootutil_sha_context * p_ctx, const void * p_data, uint32_t data_len)
{
    fsp_err_t err = FSP_ERR_ASSERTION;

    err = R_RSIP_SHA_Resume(&g_rsip_ctrl, &p_ctx->sha_handle);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    err = R_RSIP_SHA_Update(&g_rsip_ctrl, (uint8_t *) p_data, data_len);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    err = R_RSIP_SHA_Suspend(&g_rsip_ctrl, &p_ctx->sha_handle);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    return 0;
}

/*******************************************************************************************************************//**
 * Write out the result of hash value operation.
 **********************************************************************************************************************/
static inline int32_t bootutil_sha_finish (bootutil_sha_context * p_ctx, uint8_t * p_output)
{
    fsp_err_t err = FSP_ERR_ASSERTION;

    err = R_RSIP_SHA_Resume(&g_rsip_ctrl, &p_ctx->sha_handle);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    err = R_RSIP_SHA_Finish(&g_rsip_ctrl, p_output);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }
    return 0;
}

#endif /* BOOTUTIL_CRYPTO_RSIP_SHA256_H */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/******************************************************************************
 * End  Of File
 ******************************************************************************/

