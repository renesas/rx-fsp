/***********************************************************************************************************************
 * Copyright [2023] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * File Name    : hw_adapt.h
 * Version      : 0.01
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description

 *********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "device_properties.h"
#include "frame_format.h"

#include "rm_gptp_eswm.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

#ifndef HW_API_H_
#define HW_API_H_

//#define ETHPORT_TYPE_PTP            (0xF788U)
#define ETHPORT_TYPE_PTP            (0x88F7U)
#define GPTP_MULTICAST_DEST_ADDR    {0x01,0x80,0xC2,0x00,0x00,0x0E}

#define CLOCK_FREQ      (200000000)
#define MAX_ADJ         (1000000)
#define REGISTER_SIZE   (0x80000000)
#define CLOCK_SPEED_UP  (9)
#define CLOCK_SLOW_DOWN (7)

#define LINK_DOWN       (0)
#define LINK_UP         (1)


/**********************************************************************************************************************
 Global Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 External global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global functions
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Function Name: initialize_ptp_hardware_functionality
 * Description  : initialize the ptp functions from the hardware
 * Arguments    : None
 * Return Value : None
 *********************************************************************************************************************/
void initialize_ptp_hardware_functionality (void);

/**********************************************************************************************************************
 * Function Name: send_frame
 * Description  : send a ptp frame
 * Arguments    : port_number       - The number of the egress ethernet port
 *                frame_length      - The length of the egress ptp frame
 *                frame_buffer      - Pointer to the frame buffer of the egress ptp frame
 *                tx_timestamp      - Return parameter for the tx timestamp if a timestamp is generated
 *                master_timestamp  - Is true if the time of the local clock is needed
 * Return Value : usr_err_t
 *********************************************************************************************************************/
void send_frame(uint16_t port_number, uint16_t frame_length, uint8_t *frame_buffer, st_timestamp_t *tx_timestamp,
                bool master_timestamp);

/**********************************************************************************************************************
 * Function Name: set_clock_value
 * Description  : Set the clock to an new time value
 * Arguments    : clock_id      - The clock id of the clock that should be set
 *                p_time_to_set   - The time that should be set
 * Return Value : None
 *********************************************************************************************************************/
void set_clock_value (uint8_t clock_id, st_timestamp_t * p_time_to_set);

void set_and_adjust(uint8_t clock_id, int64_t offset_from_master);

/**********************************************************************************************************************
 * Function Name: get_clock_value
 * Description  : Get the current time value in a timestamp format
 * Arguments    : clock_id              - The clock id of the clock that should be read
 *                current_clock_Value   - The current clock value
 * Return Value : None
 *********************************************************************************************************************/
void get_clock_value (uint8_t clock_id, st_timestamp_t * current_clock_value);

/**********************************************************************************************************************
 * Function Name: get_clock_value_all
 * Description  : Get the current time value of bpth timers in a timestamp format
 * Arguments    : p_current_clock_value1    - First timer value
 *                p_current_clock_value2    - Second timer value
 * Return Value : None
 *********************************************************************************************************************/
void get_clock_value_all (st_timestamp_t * p_current_clock_value1, st_timestamp_t * p_current_clock_value2);

/**********************************************************************************************************************
 * Function Name: adjust_clock
 * Description  : Adjust the clock
 * Arguments    : clock_id  - The clock id of the clock which should be adjusted
 *                offset    - The offset that should be adjusted
 * Return Value : None
 *********************************************************************************************************************/
void adjust_clock (uint8_t clock_id, int64_t offset);

/**********************************************************************************************************************
 * Function Name: get_link_state
 * Description  : Get the link state for a port number
 * Arguments    : port_number   - The port number of the port where the link state should be checked
 *                state         - The link state
 * Return Value : None
 *********************************************************************************************************************/
void get_link_state (uint16_t port_number, uint8_t * state);

/**********************************************************************************************************************
 * Function Name: get_link_speed
 * Description  : Get the link state for a port number
 * Arguments    : port_number   - The port number of the port where the link speed should be read
 *                p_link_speed  - The link speed
 * Return Value : error_value
 *********************************************************************************************************************/

// int8_t get_link_speed(uint16_t port_number, uint8_t * p_link_speed);

/**********************************************************************************************************************
 * Function Name: get_src_mac_addr
 * Description  : Get the source mac address of a port
 * Arguments    : None
 * Return Value : port_src_mac_addr - Pointer to the associated source mac address
 *********************************************************************************************************************/
uint8_t * get_src_mac_address (void);

fsp_err_t gptp_initialize(gptp_eswm_instance_ctrl_t * const p_ctrl);

fsp_err_t gptp_link_process(void);
void gptp_read(void);
void gptp_send(void);

#endif /*HW_API_H_*/
