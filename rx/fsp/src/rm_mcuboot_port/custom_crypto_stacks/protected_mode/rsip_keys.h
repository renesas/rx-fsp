 /*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "mcuboot_config/mcuboot_config.h"
#include "bootutil/sign_key.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
#ifndef RSIP_KEYS_H
#define RSIP_KEYS_H

/* Convert input bit data into byte units. */
#define RM_MCUBOOT_PORT_BITS_TO_BYTES(bits)    (((bits) + 7) / 8)

/* The size of the array designated to program the wrapped keys from RFP should
 * aligned to the flash write size. */
#define MCUBOOT_RSIP_ALIGNED_ECC_KEY_SIZE_BYTES   (128)

#if defined(MCUBOOT_USE_RSIP)
#if defined(MCUBOOT_SIGN_EC256)

/* NUM_ECC_BYTES is the size of the P256 private key.
 * 2 x NUM_ECC_BYTES is the size of the public key and the signature. */
#define NUM_ECC_BYTES (32U)

/* The size of the ECDSA public key index. */
#define MCUBOOT_RSIP_ECC_PUB_KEY_LEN (RSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP256R1_PUBLIC)

#endif

#if defined(MCUBOOT_ENCRYPT_KW)
/* The size of the key wrap key index. */
#define MCUBOOT_RSIP_KEY_WRAP_KEY_LEN (RSIP_BYTE_SIZE_WRAPPED_KEY_AES_256)
#endif

extern const struct bootutil_key g_bootutil_keys_wrapped[];
extern const struct bootutil_key bootutil_enc_key;
#endif /* MCUBOOT_USE_RSIP */

#endif /* RSIP_KEYS_H */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/******************************************************************************
 * End  Of File
 ******************************************************************************/
