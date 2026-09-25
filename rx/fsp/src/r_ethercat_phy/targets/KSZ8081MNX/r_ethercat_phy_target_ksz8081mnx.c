/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

/* Access to peripherals and board defines. */
#include "bsp_api.h"
#include "r_ethercat_phy.h"

#if (ETHER_PHY_CFG_TARGET_KSZ8081MNX_ENABLE)

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/* Vendor Specific PHY Registers */
 #define ETHERCAT_PHY_REG_INTERRUPT_CONTROL                (0x1B)
 #define ETHERCAT_PHY_REG_PHY_CONTROL2                     (0x1F)

 #define ETHERCAT_PHY_REG_INTERRUPT_CONTROL_LUIE_OFFSET    (0x8)
 #define ETHERCAT_PHY_REG_INTERRUPT_CONTROL_LDIE_OFFSET    (0xA)
 #define ETHERCAT_PHY_REG_PHY_CONTROL2_RMII_IL_OFFSET      (0x9)
 #define ETHERCAT_PHY_LED_MODE_MASK                        (0x30U)
 #define ETHERCAT_PHY_LED_MODE_LED0_LINK_LED1_ACTIVITY     (0x10U)

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/
void ethercat_phy_target_ksz8081mnx_initialize(ethercat_phy_instance_ctrl_t * p_instance_ctrl);
bool ethercat_phy_target_ksz8081mnx_is_support_link_partner_ability(ethercat_phy_instance_ctrl_t * p_instance_ctrl,
                                                                    uint32_t                       line_speed_duplex);

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Name: ethercat_phy_target_ksz8081mnx_initialize
 * Description  : PHY-LSI specific initialization processing
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 * Return Value : none
 ***********************************************************************************************************************/
void ethercat_phy_target_ksz8081mnx_initialize (ethercat_phy_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t reg;

    /* When KSZ8081MNX of the Micrel, Inc. is used.
     * This processing is a setting to use Link-up and Link-down as a factor of INTRP.
     * b10=1:Enable link-down interrupt
     * b8=1 :Enable link-up interrupt
     */
    R_ETHERCAT_PHY_Write(p_instance_ctrl,
                         ETHERCAT_PHY_REG_INTERRUPT_CONTROL,
                         (0x1 << ETHERCAT_PHY_REG_INTERRUPT_CONTROL_LUIE_OFFSET | 0x1 <<
                          ETHERCAT_PHY_REG_INTERRUPT_CONTROL_LDIE_OFFSET));

    /* b7-b0 are read-only status flags that self-clear when this register is read. This read
     * is issued for that side effect only - to drop any status latched before the enables
     * above were set. The value returned in reg is deliberately unused; it is overwritten by
     * the next read. */
    R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_INTERRUPT_CONTROL, &reg);

    /* b9=0:Interrupt pin active low */
    R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_PHY_CONTROL2, &reg);
    reg &= (uint16_t) ~(0x1 << ETHERCAT_PHY_REG_PHY_CONTROL2_RMII_IL_OFFSET);
    R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_PHY_CONTROL2, reg);

    /* The pin that outputs the state of LINK is used combinedly with ACTIVITY in default.
     * The setting of the pin is changed so that only the state of LINK is output.
     */
    R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_PHY_CONTROL2, &reg);
    reg &= ~ETHERCAT_PHY_LED_MODE_MASK;
    reg |= ETHERCAT_PHY_LED_MODE_LED0_LINK_LED1_ACTIVITY;
    R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_PHY_CONTROL2, reg);
}                                      /* End of function ethercat_phy_target_ksz8081mnx_initialize() */

/***********************************************************************************************************************
 * Function Name: ethercat_phy_target_ksz8081mnx_is_support_link_partner_ability
 * Description  : Check if the PHY-LSI connected Ethernet controller supports link ability
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 *                line_speed_duplex -
 *                    Line speed duplex of link partner PHY-LSI
 * Return Value : bool
 ***********************************************************************************************************************/
bool ethercat_phy_target_ksz8081mnx_is_support_link_partner_ability (ethercat_phy_instance_ctrl_t * p_instance_ctrl,
                                                                     uint32_t                       line_speed_duplex)
{
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(line_speed_duplex);

    /* This PHY-LSI supports half and full duplex mode. */
    return true;
}                                      /* End of function ethercat_phy_target_ksz8081mnx_is_support_link_partner_ability() */

#endif /* ETHER_PHY_CFG_TARGET_KSZ8081MNX_ENABLE */
