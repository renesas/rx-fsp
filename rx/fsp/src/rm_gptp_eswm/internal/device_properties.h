/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef DEVICE_PROPERTIES_H
#define DEVICE_PROPERTIES_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "rm_gptp_middleware_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define NUMBER_OF_ETHERNET_PORTS            (BSP_FEATURE_ETHER_NUM_CHANNELS)
#define ETHPHY_CLOCK_PERIOD                 (GPTP_MIDDLEWARE_CFG_ETHPHY_CLOCK_PERIOD)
#define ETHSW_CLOCK_PERIOD                  (GPTP_MIDDLEWARE_CFG_ESWPHY_CLOCK_PERIOD)

/* (EtherPHY Clock Cycle * 18) + (ETHSW Clock Cycle * 4) */
#define RX_PHY_DELAY                        ((ETHPHY_CLOCK_PERIOD * 18) + (ETHSW_CLOCK_PERIOD * 4))

/* (EtherPHY Clock Cycle * 20) - (ETHSW Clock Cycle * 3) */
#define TX_PHY_DELAY                        ((ETHPHY_CLOCK_PERIOD * 20) - (ETHSW_CLOCK_PERIOD * 3))

#define TIMESTAMP_WAIT_MAX                  (2000)
#define GPTP_OUTPUT_PULSE_PERIOD            (GPTP_PULSE_PERIOD_MSEC)
#define PPS_PULSE_GENERATOR                 (0)

#define MESSAGE_GENERATION_QUEUE_LENGTH     (60)

#define NUMBER_OF_CLOCKS                    (4)
#define NUMBER_OF_HW_CLOCKS                 (2)
#define NUMBER_OF_INSTANCES                 (NUMBER_OF_CLOCKS)
#define NUMBER_OF_DOMAINS                   (NUMBER_OF_INSTANCES)
#define WORKING_CLOCK_INSTANCE              (2)
#define WORKING_CLOCK_REDUNDANT_INSTANCE    (3)
#define GLOBAL_TIME_INSTANCE                (0)
#define GLOBAL_TIME_REDUNDANT_INSTANCE      (1)

/* Free running timer for packet timestamping. */
#define LOCAL_CLOCK_TIMER                   (0)

/* Timer that is synchronized by gPTP. */
#define SYNCRHONIZED_CLOCK_TIMER            (1)

/* Cyclic debug output. If this is set to true, only the information of the instance accessing the hardware clock is shown */
#define SHOW_ONLY_HW_CLOCK_INSTANCE         (false)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* DEVICE_PROPERTIES_H */
