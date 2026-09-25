/*
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifndef TX_INCLUDE_USER_DEFINE_FILE
 #define TX_INCLUDE_USER_DEFINE_FILE
#endif

/* SWINT (IRQ 27) is fixed for ThreadX context switching and must not be changed.
 * Note: The RX provides two software interrupts: SWINT (IRQ 27) and SWINT2 (IRQ 26).
 * There is no SWINT1. */
#define TX_PORT_SWINT_NUMBER      ((IRQn_Type) 27)

/* IPL 1 is the lowest usable priority (IPL 0 disables the interrupt). SWINT must remain at the
 * lowest priority so that hardware ISRs always complete before a context switch is triggered.
 * Note: On RX74M/RX74N the IPR field is 5-bit (0-31); on other RX MCUs it is 4-bit (0-15).
 * IPL 1 is valid and the lowest usable value on all supported RX MCUs. */
#define TX_PORT_SWINT_PRIORITY    (1)

/***********************************************************************************************************************
 * Function Prototypes
 **********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
