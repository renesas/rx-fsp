/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

/* Access to peripherals and board defines. */
#include "bsp_api.h"
#include "r_rmac_phy.h"

#if (ETHER_PHY_CFG_TARGET_GPY111_ENABLE)

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
 #define RMAC_PHY_REG_MIICTRL                  (0x17U)
 #define RMAC_PHY_REG_MIICTRL_RXSKEW_MASK      (0x7000U)
 #define RMAC_PHY_REG_MIICTRL_RXSKEW_OFFSET    (0x12U)

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/* Vendor Specific PHY Registers */

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/
void rmac_phy_target_gpy111_initialize(rmac_phy_instance_ctrl_t * p_instance_ctrl);
bool rmac_phy_target_gpy111_is_support_link_partner_ability(rmac_phy_instance_ctrl_t * p_instance_ctrl,
                                                            uint32_t                   line_speed_duplex);

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/
static uint8_t rmac_phy_target_gpy111_convert_clk_delay_to_register_value(ether_phy_lsi_clk_delay_t delay_time);

/***********************************************************************************************************************
 * Function Name: rmac_phy_target_gpy111_initialize
 * Description  : PHY-LSI specific initialization processing
 * Arguments    : p_api_ctrl -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
void rmac_phy_target_gpy111_initialize (rmac_phy_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t reg;
    uint8_t  rx_clk_delay_value;
    rmac_phy_extended_cfg_t * p_extend = (rmac_phy_extended_cfg_t *) p_instance_ctrl->p_ether_phy_cfg->p_extend;

    /* Set RGMII receive timing skew to 1.0 ns. */
    rx_clk_delay_value =
        rmac_phy_target_gpy111_convert_clk_delay_to_register_value(p_extend->p_phy_lsi_cfg_list[p_instance_ctrl->
                                                                                                phy_lsi_cfg_index]->rx_clk_delay);
    R_RMAC_PHY_Read(p_instance_ctrl, RMAC_PHY_REG_MIICTRL, &reg);
    reg = (reg & ~RMAC_PHY_REG_MIICTRL_RXSKEW_MASK) |
          (rx_clk_delay_value << RMAC_PHY_REG_MIICTRL_RXSKEW_OFFSET);
    R_RMAC_PHY_Write(p_instance_ctrl, RMAC_PHY_REG_MIICTRL, reg);
}                                      /* End of function rmac_phy_targets_initialize() */

/***********************************************************************************************************************
 * Function Name: rmac_phy_targets_is_support_link_partner_ability
 * Description  : Check if the PHY-LSI connected Ethernet controller supports link ability
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 *                line_speed_duplex -
 *                    Line speed duplex of link partner PHY-LSI
 * Return Value : bool
 ***********************************************************************************************************************/
bool rmac_phy_target_gpy111_is_support_link_partner_ability (rmac_phy_instance_ctrl_t * p_instance_ctrl,
                                                             uint32_t                   line_speed_duplex)
{
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(line_speed_duplex);

    /* This PHY-LSI supports half and full duplex mode. */
    return true;
}                                      /* End of function rmac_phy_targets_is_support_link_partner_ability() */

/***********************************************************************************************************************
 * Function Name: rmac_phy_target_gpy111_convert_clk_delay_to_register_value
 * Description  : Convert input delay time to register value of PHY LSI
 * Arguments    :  delay_time - RX_CLK/TX_CLK delay time
 * Return Value : uint8_t
 ***********************************************************************************************************************/
static uint8_t rmac_phy_target_gpy111_convert_clk_delay_to_register_value (ether_phy_lsi_clk_delay_t delay_time)
{
    uint8_t phy_reg_value = 0;

    switch (delay_time)
    {
        /* 0.0 ns */
        case ETHER_PHY_LSI_CLK_DELAY_0_0_NS:
        {
            phy_reg_value = 0;
            break;
        }

        /* 0.5 ns */
        case ETHER_PHY_LSI_CLK_DELAY_0_5_NS:
        {
            phy_reg_value = 1;
            break;
        }

        /* 1.0 ns */
        case ETHER_PHY_LSI_CLK_DELAY_1_0_NS:
        {
            phy_reg_value = 2;
            break;
        }

        /* 1.5 ns */
        case ETHER_PHY_LSI_CLK_DELAY_1_5_NS:
        {
            phy_reg_value = 3;
            break;
        }

        /* 2.0 ns */
        case ETHER_PHY_LSI_CLK_DELAY_2_0_NS:
        {
            phy_reg_value = 4;
            break;
        }

        /* 2.5 ns */
        case ETHER_PHY_LSI_CLK_DELAY_2_5_NS:
        {
            phy_reg_value = 5;
            break;
        }

        /* 3.0 ns */
        case ETHER_PHY_LSI_CLK_DELAY_3_0_NS:
        {
            phy_reg_value = 6;
            break;
        }

        /* 3.5 ns */
        case ETHER_PHY_LSI_CLK_DELAY_3_5_NS:
        {
            phy_reg_value = 7;
            break;
        }

        /* Invalid value */
        default:
        {
            phy_reg_value = 0;
            break;
        }
    }

    return phy_reg_value;
}                                      /* End of function rmac_phy_target_vsc8541_convert_clk_delay_to_register_value() */

#endif /* ETHER_PHY_CFG_TARGET_GPY111_ENABLE */
