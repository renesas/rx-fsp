 /*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include "r_rsip.h"
#include "rsip_sha256.h"
#include "r_rsip_private.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
#ifndef BOOTUTIL_CRYPTO_RSIP_ECDSA_P256_H
#define BOOTUTIL_CRYPTO_RSIP_ECDSA_P256_H

#define BOOTUTIL_CRYPTO_ECDSA_P256_SIGNATURE_SIZE_BYTES         (64U)

/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/
typedef uintptr_t bootutil_ecdsa_context_t;

/*******************************************************************************************************************//**
 * Prepare ECDSA signature verification with key length of 256 bits.
 **********************************************************************************************************************/
static inline void bootutil_ecdsa_init (bootutil_ecdsa_context_t * p_ctx)
{
    /* Do nothing. */
    (void) p_ctx;
}

/*******************************************************************************************************************//**
 * Release resources for ECDSA signature verification with key length 256 bits.
 **********************************************************************************************************************/
static inline void bootutil_ecdsa_drop (bootutil_ecdsa_context_t * p_ctx)
{
    /* Do nothing. */
    (void) p_ctx;
}

#endif /* BOOTUTIL_CRYPTO_RSIP_ECDSA_P256_H */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/******************************************************************************
 * End  Of File
 ******************************************************************************/
