/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hw_sce_rx_private.h"

uint32_t change_endian_long (uint32_t data)
{
#if (defined(__LIT) && (__LIT == 1))
    /* Little endian CPU: convert data to big endian */
    return __REV(data);
#else
    /* Big endian CPU: no need to convert data to big endian */
    return data;
#endif
}
