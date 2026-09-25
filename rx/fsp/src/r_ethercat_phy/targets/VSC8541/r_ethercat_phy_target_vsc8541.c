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

#if (ETHER_PHY_CFG_TARGET_VSC8541_ENABLE)

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/* Vendor Specific PHY Registers */
 #define ETHERCAT_PHY_REG_LED_MODE_SELECT                             (0x1D)
 #define ETHERCAT_PHY_REG_LED_BEHAVIOR                                (0x1E)
 #define ETHERCAT_PHY_REG_INTERRUPT_MASK                              (0x19)
 #define ETHERCAT_PHY_REG_EXT_PHY_CONTROL1                            (0x17)
 #define ETHERCAT_PHY_REG_MODE_CONTROL                                (0x00)
 #define ETHERCAT_PHY_REG_1000BASET_CONTROL                           (0x09)
 #define ETHERCAT_PHY_REG_RGMII_CONTROL                               (0x14)
 #define ETHERCAT_PHY_REG_PAGE_REG_ACCESS                             (0x1F)
 #define ETHERCAT_PHY_REG_GPIO_CONTROL2                               (0x0E)

 #define ETHERCAT_PHY_REG_LEDMODE_ANYSPEED_LINK_ACTIVITY              (0x0)
 #define ETHERCAT_PHY_REG_LED0_MODE_SELECT_OFFSET                     (0x0)
 #define ETHERCAT_PHY_REG_LED1_MODE_SELECT_OFFSET                     (0x4)
 #define ETHERCAT_PHY_REG_LED0_FEATURE_DISABLE_OFFSET                 (0x0)
 #define ETHERCAT_PHY_REG_LED1_FEATURE_DISABLE_OFFSET                 (0x1)
 #define ETHERCAT_PHY_REG_INTERRUPT_MASK_MDINT_OFFSET                 (0xF)
 #define ETHERCAT_PHY_REG_TRISTATE_ENABLE_OFFSET                      (0x9)

 #define ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_OFFSET        (0xB)
 #define ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_VALUE_MASK    (0x3)
 #define ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_MII_GMII      (0x0)
 #define ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_RMII          (0x1)
 #define ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_RGMII         (0x2)

 #define ETHERCAT_PHY_REG_MODE_CONTROL_SOFTWARE_RESET_OFFSET          (0xF)

 #define ETHERCAT_PHY_REG_1000BASET_CONTROL_FDX_CAPABLITY_OFFSET      (0x09)
 #define ETHERCAT_PHY_REG_1000BASET_CONTROL_HDX_CAPABLITY_OFFSET      (0x08)

 #define ETHERCAT_PHY_REG_RGMII_CONTROL_RX_CLK_DELAY_OFFSET           (0x4)
 #define ETHERCAT_PHY_REG_RGMII_CONTROL_TX_CLK_DELAY_OFFSET           (0x0)
 #define ETHERCAT_PHY_REG_RGMII_CONTROL_XX_CLK_DELAY_VALUE_MASK       (0x07)
 #define ETHERCAT_PHY_REG_RGMII_CONTROL_XX_CLK_DELAY_VALUE_2NS        (0x04)

 #define ETHERCAT_PHY_REG_PAGE_REG_ACCESS_MAIN_REG                    (0x00)
 #define ETHERCAT_PHY_REG_PAGE_REG_ACCESS_PAGE2                       (0x02)
 #define ETHERCAT_PHY_REG_PAGE_REG_ACCESS_GPIO                        (0x10)

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global funtion
 ***********************************************************************************************************************/
void ethercat_phy_target_vsc8541_initialize(ethercat_phy_instance_ctrl_t * p_instance_ctrl);
bool ethercat_phy_target_vsc8541_is_support_link_partner_ability(ethercat_phy_instance_ctrl_t * p_instance_ctrl,
                                                                 uint32_t                       line_speed_duplex);

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Name: ethercat_phy_targets_initialize
 * Description  : PHY-LSI specific initialization processing
 * Arguments    : p_api_ctrl -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
void ethercat_phy_target_vsc8541_initialize (ethercat_phy_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t reg;
    uint32_t count = 0;
    uint32_t phy_reg_value;
    uint32_t expect_reg_value;

    /* When VSC8541 of the Microsemi Corporation. is used.
     * Enable access to main register.
     */
    do
    {
        R_ETHERCAT_PHY_Write(p_instance_ctrl,
                             ETHERCAT_PHY_REG_PAGE_REG_ACCESS,
                             ETHERCAT_PHY_REG_PAGE_REG_ACCESS_MAIN_REG);
        R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_PAGE_REG_ACCESS, &reg);
        count++;
    } while ((reg != ETHERCAT_PHY_REG_PAGE_REG_ACCESS_MAIN_REG) &&
             (count < p_instance_ctrl->p_ether_phy_cfg->phy_reset_wait_time));

    /* Check MAC interface mode is set as expected. If not, set register */
    R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_EXT_PHY_CONTROL1, &reg);
    phy_reg_value =
        (reg >>
         ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_OFFSET) &
        ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_VALUE_MASK;

    switch (p_instance_ctrl->p_ether_phy_cfg->mii_type)
    {
        case ETHER_PHY_MII_TYPE_MII:
        case ETHER_PHY_MII_TYPE_GMII:
        {
            expect_reg_value = ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_MII_GMII;
            break;
        }

        case ETHER_PHY_MII_TYPE_RMII:
        {
            expect_reg_value = ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_RMII;
            break;
        }

        case ETHER_PHY_MII_TYPE_RGMII:
        {
            expect_reg_value = ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_RGMII;
            break;
        }

        default:
        {
            expect_reg_value = ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_MII_GMII;
            break;
        }
    }

    if (phy_reg_value != expect_reg_value)
    {
        reg =
            (reg &
             ~(uint32_t) (ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_VALUE_MASK <<
                          ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_OFFSET)) |
            (expect_reg_value << ETHERCAT_PHY_REG_EXT_PHY_CONTROL_MAC_INTERFACE_OFFSET);

        R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_EXT_PHY_CONTROL1, reg);

        /* Software reset after MAC interface mode is changed
         * b15=1:Software reset asserted
         * */
        count = 0;                     /* Reset count for new register setting */
        do
        {
            R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_MODE_CONTROL,
                                 (1 << ETHERCAT_PHY_REG_MODE_CONTROL_SOFTWARE_RESET_OFFSET));
            R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_MODE_CONTROL, &reg);
            count++;
        } while ((reg & (1 << ETHERCAT_PHY_REG_MODE_CONTROL_SOFTWARE_RESET_OFFSET)) &&
                 (count < p_instance_ctrl->p_ether_phy_cfg->phy_reset_wait_time));
    }

    /* Disable 1000BASE-T capability in MII or RMII mode
     * b9=0:1000BASE-T FDX capability disabled
     * b8=0:1000BASE-T HDX capability disabled
     * */
    if ((p_instance_ctrl->p_ether_phy_cfg->mii_type == ETHER_PHY_MII_TYPE_MII) ||
        (p_instance_ctrl->p_ether_phy_cfg->mii_type == ETHER_PHY_MII_TYPE_RMII))
    {
        R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_1000BASET_CONTROL, &reg);

        reg = reg &
              ~(uint32_t) ((0x1 << ETHERCAT_PHY_REG_1000BASET_CONTROL_FDX_CAPABLITY_OFFSET) |
                           (0x1 << ETHERCAT_PHY_REG_1000BASET_CONTROL_HDX_CAPABLITY_OFFSET));

        R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_1000BASET_CONTROL, reg);
    }

    /* Enable Extended register Page 2 access
     * 0x0002: Registers 16–30 access extended register space 2
     */
    count = 0;                         /* Reset count for new register setting */
    do
    {
        R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_PAGE_REG_ACCESS, ETHERCAT_PHY_REG_PAGE_REG_ACCESS_PAGE2);
        R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_PAGE_REG_ACCESS, &reg);
        count++;
    } while ((reg != ETHERCAT_PHY_REG_PAGE_REG_ACCESS_PAGE2) &&
             (count < p_instance_ctrl->p_ether_phy_cfg->phy_reset_wait_time));

    /* Set RX_CLK and TX_CLK to 2.0 ns
     * b6:4=0x4:RX_CLK 2.0 ns delay
     * b2:0=0x4:TX_CLK 2.0 ns delay
     */
    R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_RGMII_CONTROL, &reg);
    reg =
        (reg &
         ~(uint32_t) ((ETHERCAT_PHY_REG_RGMII_CONTROL_XX_CLK_DELAY_VALUE_MASK <<
                       ETHERCAT_PHY_REG_RGMII_CONTROL_RX_CLK_DELAY_OFFSET) +
                      (ETHERCAT_PHY_REG_RGMII_CONTROL_XX_CLK_DELAY_VALUE_MASK <<
                       ETHERCAT_PHY_REG_RGMII_CONTROL_TX_CLK_DELAY_OFFSET))) |
        ((ETHERCAT_PHY_REG_RGMII_CONTROL_XX_CLK_DELAY_VALUE_2NS <<
            ETHERCAT_PHY_REG_RGMII_CONTROL_RX_CLK_DELAY_OFFSET) |
         (ETHERCAT_PHY_REG_RGMII_CONTROL_XX_CLK_DELAY_VALUE_2NS << ETHERCAT_PHY_REG_RGMII_CONTROL_RX_CLK_DELAY_OFFSET));
    R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_RGMII_CONTROL, reg);

    /* Enable General purpose register access
     * 0x0010: Registers 0–30 access GPIO register space.
     */
    count = 0;                         /* Reset count for new register setting */
    do
    {
        R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_PAGE_REG_ACCESS, ETHERCAT_PHY_REG_PAGE_REG_ACCESS_GPIO);
        R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_PAGE_REG_ACCESS, &reg);
        count++;
    } while ((reg != ETHERCAT_PHY_REG_PAGE_REG_ACCESS_GPIO) &&
             (count < p_instance_ctrl->p_ether_phy_cfg->phy_reset_wait_time));

    /* Configure LED drive state*/
    R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_GPIO_CONTROL2, &reg);
    reg &= ~(1U << ETHERCAT_PHY_REG_TRISTATE_ENABLE_OFFSET);
    R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_GPIO_CONTROL2, reg);

    /* Enable main register access
     * 0x0000: Register 16–30 accesses main register space
     */
    count = 0;                         /* Reset count for new register setting */
    do
    {
        R_ETHERCAT_PHY_Write(p_instance_ctrl,
                             ETHERCAT_PHY_REG_PAGE_REG_ACCESS,
                             ETHERCAT_PHY_REG_PAGE_REG_ACCESS_MAIN_REG);
        R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_PAGE_REG_ACCESS, &reg);
        count++;
    } while ((reg != ETHERCAT_PHY_REG_PAGE_REG_ACCESS_MAIN_REG) &&
             (count < p_instance_ctrl->p_ether_phy_cfg->phy_reset_wait_time));

    /*
     * When VSC8541-05 of the Microsemi Corporation is used,
     * the pin that outputs the state of LINK is used combinedly with LINK/ACTIVITY in default.
     * The setting of the pin is changed so that only the state of LINK is output.
     * LED Mode Select (0x1D)
     * b7:4 = 0000b : LED1 mode any speed LINK/ACTIVITY
     * b3:0 = 0000b : LED0 mode any speed LINK/ACTIVITY
     * LED Behavior (0x1E)
     * b1 = 1 : LED1 combination feature enable  (link/activity)
     * b0 = 0 : LED0 combination feature disable (link only, duplex only)
     *//* LED Mode Select */
    R_ETHERCAT_PHY_Write(p_instance_ctrl,
                         ETHERCAT_PHY_REG_LED_MODE_SELECT,
                         (ETHERCAT_PHY_REG_LEDMODE_ANYSPEED_LINK_ACTIVITY << ETHERCAT_PHY_REG_LED1_MODE_SELECT_OFFSET) |
                         (ETHERCAT_PHY_REG_LEDMODE_ANYSPEED_LINK_ACTIVITY << ETHERCAT_PHY_REG_LED0_MODE_SELECT_OFFSET));

    /* LED Behavior */
    R_ETHERCAT_PHY_Read(p_instance_ctrl, ETHERCAT_PHY_REG_LED_BEHAVIOR, &reg);
    reg &= ~(1U << ETHERCAT_PHY_REG_LED1_FEATURE_DISABLE_OFFSET);
    reg |= 1U << ETHERCAT_PHY_REG_LED0_FEATURE_DISABLE_OFFSET;
    R_ETHERCAT_PHY_Write(p_instance_ctrl, ETHERCAT_PHY_REG_LED_BEHAVIOR, reg);

    /* Enable interrupt of MDINT
     * b15=1:MDINT interrupt status enable */
    R_ETHERCAT_PHY_Write(p_instance_ctrl,
                         ETHERCAT_PHY_REG_INTERRUPT_MASK,
                         0x1 << ETHERCAT_PHY_REG_INTERRUPT_MASK_MDINT_OFFSET);
}                                      /* End of function ethercat_phy_targets_initialize() */

/***********************************************************************************************************************
 * Function Name: ethercat_phy_targets_is_support_link_partner_ability
 * Description  : Check if the PHY-LSI connected Ethernet controller supports link ability
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 *                line_speed_duplex -
 *                    Line speed duplex of link partner PHY-LSI
 * Return Value : bool
 ***********************************************************************************************************************/
bool ethercat_phy_target_vsc8541_is_support_link_partner_ability (ethercat_phy_instance_ctrl_t * p_instance_ctrl,
                                                                  uint32_t                       line_speed_duplex)
{
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(line_speed_duplex);

    /* This PHY-LSI supports half and full duplex mode. */
    return true;
}                                      /* End of function ethercat_phy_targets_is_support_link_partner_ability() */

#endif /* ETHER_PHY_CFG_TARGET_VSC8541_ENABLE */
