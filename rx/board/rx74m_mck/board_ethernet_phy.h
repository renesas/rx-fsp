/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup BOARD_RX74M_MCK
 * @defgroup BOARD_RX74M_MCK_ETHERNET_PHY Board Ethernet Phy
 * @brief Ethernet Phy information for this board.
 *
 * This is code specific to the RX74M_MCK board.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BSP_ETHERNET_PHY_H
#define BSP_ETHERNET_PHY_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define ETHER_PHY_CFG_TARGET_KSZ8081MNX_ENABLE    (1)
#define ETHER_PHY_LSI_TYPE_KIT_COMPONENT          ETHER_PHY_LSI_TYPE_KSZ8081MNX

/* The KSZ8081MNX is a 10/100 MII PHY-LSI, so the RGMII transmit/receive timing skew
 * does not apply to this board. */
#define ETHER_PHY_LSI_TX_CLK_DELAY_DEFAULT        ETHER_PHY_LSI_CLK_DELAY_0_0_NS
#define ETHER_PHY_LSI_RX_CLK_DELAY_DEFAULT        ETHER_PHY_LSI_CLK_DELAY_0_0_NS

#define BOARD_PHY_REF_CLK                         (1)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/** @} (end defgroup BOARD_RX74M_MCK_ETHERNET_PHY) */
