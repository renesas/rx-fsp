/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_CONNECTIVITY_INTERFACES
 * @defgroup PCIF_API PCIF Interface
 * @brief Interface for PCIF functions.
 *
 * @section PCIF_API_SUMMARY Summary
 * @brief  Phase Counting Interface(PCIF) interface provides APIs and definitions for motor communication.
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_PCIF_API_H
#define R_PCIF_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
#include "bsp_api.h"
#include "r_timer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** PCIF Error Event */
typedef enum e_pcif_error
{
    PCIF_ERROR_NONE                   = 0U,         ///< No error
    PCIF_ERROR_CARRIER_PERIOD         = (1U << 16), ///< Carrier Period Event error
    PCIF_ERROR_INTERNAL_EDGE_COUNTING = (1U << 17), ///< Internal Edge Count error
    PCIF_ERROR_EDGE_COUNTING_OVERFLOW = (1U << 18), ///< Internal Edge Count Overflow error
    PCIF_ERROR_OLD_EDGE_COUNTING      = (1U << 19), ///< Old Edge Count Usage error
} pcif_error_t;

/** PCIF Status */
typedef enum e_pcif_state
{
    PCIF_STATE_STOPPED  = 0U,          ///< PCIF is idle
    PCIF_STATE_RUNNING  = 1U,          ///< PCIF is busy
} pcif_state_t;

/** PCIF Mode */
typedef enum e_pcif_mode
{
    PCIF_MODE_PHASE_COUNTING = 0U,     ///< Phase counting mode
    PCIF_MODE_INCREMENTAL    = 1U,     ///< Incremental mode
} pcif_mode_t;

#ifndef BSP_OVERRIDE_PCIF_CLOCK_T
/** Selection of source clock */
typedef enum e_pcif_clock_source
{
    PCIF_CLOCK_SOURCE_ASYN_CLK = 0U,       ///< Select asynchronous clock source (GPTCLK)
    PCIF_CLOCK_SOURCE_SYN_CLK  = 1U,       ///< Select synchronous clock source (PCLK) 
} pcif_clock_source_t;

/** Division clock ratio for source clock */
typedef enum e_pcif_clock_div
{
    PCIF_CLOCK_DIV_1  = 0U,            ///< Clock source divided by 1
    PCIF_CLOCK_DIV_2  = 1U,            ///< Clock source divided by 2 with duty ratio 1:1
    PCIF_CLOCK_DIV_3  = 2U,            ///< Clock source divided by 3 with duty ratio 2:1
    PCIF_CLOCK_DIV_4  = 3U,            ///< Clock source divided by 4 with duty ratio 2:2
    PCIF_CLOCK_DIV_5  = 4U,            ///< Clock source divided by 5 with duty ratio 3:2
    PCIF_CLOCK_DIV_6  = 5U,            ///< Clock source divided by 6 with duty ratio 3:3
    PCIF_CLOCK_DIV_7  = 6U,            ///< Clock source divided by 7 with duty ratio 4:3
    PCIF_CLOCK_DIV_8  = 7U,            ///< Clock source divided by 8 with duty ratio 4:4
    PCIF_CLOCK_DIV_9  = 8U,            ///< Clock source divided by 9 with duty ratio 5:4
    PCIF_CLOCK_DIV_10 = 9U,            ///< Clock source divided by 10 with duty ratio 5:5
    PCIF_CLOCK_DIV_11 = 10U,           ///< Clock source divided by 11 with duty ratio 6:5
    PCIF_CLOCK_DIV_12 = 11U,           ///< Clock source divided by 12 with duty ratio 6:6
    PCIF_CLOCK_DIV_13 = 12U,           ///< Clock source divided by 13 with duty ratio 7:6
    PCIF_CLOCK_DIV_14 = 13U,           ///< Clock source divided by 14 with duty ratio 7:7
    PCIF_CLOCK_DIV_15 = 14U,           ///< Clock source divided by 15 with duty ratio 8:7
    PCIF_CLOCK_DIV_16 = 15U,           ///< Clock source divided by 16 with duty ratio 8:8
    PCIF_CLOCK_DIV_17 = 16U,           ///< Clock source divided by 17 with duty ratio 9:8
    PCIF_CLOCK_DIV_18 = 17U,           ///< Clock source divided by 18 with duty ratio 9:9
    PCIF_CLOCK_DIV_19 = 18U,           ///< Clock source divided by 19 with duty ratio 10:9
    PCIF_CLOCK_DIV_20 = 19U,           ///< Clock source divided by 20 with duty ratio 10:10
    PCIF_CLOCK_DIV_21 = 20U,           ///< Clock source divided by 21 with duty ratio 11:10
    PCIF_CLOCK_DIV_22 = 21U,           ///< Clock source divided by 22 with duty ratio 11:11
    PCIF_CLOCK_DIV_23 = 22U,           ///< Clock source divided by 23 with duty ratio 12:11
    PCIF_CLOCK_DIV_24 = 23U,           ///< Clock source divided by 24 with duty ratio 12:12
    PCIF_CLOCK_DIV_25 = 24U,           ///< Clock source divided by 25 with duty ratio 13:12
    PCIF_CLOCK_DIV_26 = 25U,           ///< Clock source divided by 26 with duty ratio 13:13
    PCIF_CLOCK_DIV_27 = 26U,           ///< Clock source divided by 27 with duty ratio 14:13
    PCIF_CLOCK_DIV_28 = 27U,           ///< Clock source divided by 28 with duty ratio 14:14
    PCIF_CLOCK_DIV_29 = 28U,           ///< Clock source divided by 29 with duty ratio 15:14
    PCIF_CLOCK_DIV_30 = 29U,           ///< Clock source divided by 30 with duty ratio 15:15
    PCIF_CLOCK_DIV_31 = 30U,           ///< Clock source divided by 31 with duty ratio 16:15
    PCIF_CLOCK_DIV_32 = 31U,           ///< Clock source divided by 32 with duty ratio 16:16
} pcif_clock_div_t;
#endif

/** Output phase polarity selection */
typedef enum e_pcif_phase_polarity
{
    PCIF_PHASE_POSITIVE = 0U,          ///< Positive phase
    PCIF_PHASE_NEGATIVE = 1U,          ///< Negative phase
} pcif_phase_polarity_t;

/** Stop mode */
typedef enum e_pcif_stop_mode
{
    PCIF_STOP_MODE_IMMEDIATE   = 0U,      ///< PCIF stops immediately
    PCIF_STOP_MODE_SYNC        = 1U,      ///< PCIF stops after generating the ABZ phase and synchronizing with the carrier cycle
} pcif_stop_mode_t;

/** Rotation direction */
typedef enum e_pcif_rotation_direction
{
    PCIF_ROTATION_DIRECTION_CW  = 0U,            ///< Clockwise rotation
    PCIF_ROTATION_DIRECTION_CCW = 1U,            ///< Counter-clockwise rotation
} pcif_rotation_direction_t;

/** Callback parameter data */
typedef struct st_pcif_callback_args
{
    /** Placeholder for user data.  Set in @ref pcif_api_t::open function in @ref pcif_cfg_t. */
    void const *  p_context;
    pcif_error_t  error;      /// Error information returned by the PCIF module.
} pcif_callback_args_t;

/** Phase Counting counter data configuration structure */
typedef struct st_pcif_phc_counter_info
{
    uint16_t new_position;    ///< New position of counter to be set
    int16_t  edge_count;      ///< Number of edge count 
} pcif_phc_counter_info_t;

/** Current PCIF status. */
typedef struct st_pcif_status
{
    pcif_state_t              state;                  ///< Current PCIF state (stopped or running)
    pcif_rotation_direction_t rotation_direction;     ///< Rotation direction (clockwise or counter-clockwise)
    uint16_t                  current_position_value; ///< Current output counter value (PHCPOSCNTM or INCOCNTM)
    uint16_t                  position_write_value;   ///< Latest PHCPCWDR write value (0 in incremental mode)
    uint8_t                   input_counter_value;    ///< Incremental input counter value (INCICNTM, 0 in phase-counting mode)
} pcif_status_t;

/** User configuration structure, used in open function */
typedef struct st_pcif_cfg
{
    pcif_mode_t mode;                          ///< Select enumerated value from @ref pcif_mode_t

    /** Select a channel corresponding to the channel number of the hardware. */
    uint8_t             channel;
    pcif_clock_source_t clock_src;             ///< Source clock selection
    pcif_clock_div_t    clock_div;             ///< Source clock divider

    /** Common setting */
    pcif_phase_polarity_t a_phase_polarity;   ///< A phase polarity output
    pcif_phase_polarity_t b_phase_polarity;   ///< B phase polarity output
    pcif_phase_polarity_t z_phase_polarity;   ///< Z phase polarity output
    uint16_t              max_count_position; ///< Maximum position value

    timer_instance_t const * p_lower_lvl_timer; ///< Pointer to the timer instance structs

    /** Callback provided when an PCIF carrier period occurs. Set to NULL if not use. */
    void (* p_callback)(pcif_callback_args_t * p_args);

    /** Placeholder for user data.  Passed to the user callback in @ref pcif_callback_args_t. */
    void       * p_context;
    void const * p_extend;  ///< Extension parameter for hardware specific settings
} pcif_cfg_t;

/** PCIF_API control block.  Allocate an instance specific control block to pass into the PCIF_API API calls.
 */
typedef void pcif_ctrl_t;

/** PCIF_API functions implemented at the HAL layer will follow this API. */
typedef struct st_pcif_api
{
    /** Initial configuration.
     * @par Implemented as
     * - R_PCIF_Open()
     * 
     * @pre Peripheral clocks and any required output pins should be configured prior to calling this function.
     * @note To reconfigure after calling this function, call @ref pcif_api_t::close first.
     * @param[in]  p_ctrl       Pointer to control structure. Must be declared by user. Elements set here.
     * @param[in]  p_cfg        Pointer to pin configuration structure. All elements of this structure must be set by user.
     */
    fsp_err_t (* open)(pcif_ctrl_t * const p_ctrl, pcif_cfg_t const * const p_cfg);

    /** Start the output waveform.
     * @par Implemented as
     * - R_PCIF_Start()
     * 
     * @param[in]   p_ctrl     Control block set in @ref pcif_api_t::open call for this module.
     */
    fsp_err_t (* start)(pcif_ctrl_t * const p_ctrl);

    /** Stop the output waveform.
     * @par Implemented as
     * - R_PCIF_Stop()
     * 
     * @param[in]   p_ctrl     Control block set in @ref pcif_api_t::open call for this module.
     * @param[in]   stop_mode  Stop mode
     */
    fsp_err_t (* stop)(pcif_ctrl_t * const p_ctrl, pcif_stop_mode_t stop_mode);

    /** Set the counter and the initial value.
     * @par Implemented as
     * - R_PCIF_SetCounter()
     * 
     * @note This function is only available in phase counting mode.
     *
     * @param[in]   p_ctrl          Control block set in @ref pcif_api_t::open call for this module.
     * @param[in]   p_counter_info  Pointer to counter info structure. All elements of this structure must be set by user.
     * @param[in]   pos_reset       Reset counter position.
     */
    fsp_err_t (* setCounter)(pcif_ctrl_t * const p_ctrl, pcif_phc_counter_info_t const * const p_counter_info, bool pos_reset);

    /** Stores current status in p_status.
     * @par Implemented as
     * - R_PCIF_StatusGet()
     *
     * @param[in]   p_ctrl     Control block set in @ref pcif_api_t::open call for this module.
     * @param[out]  p_status   Current status for this module.
     */
    fsp_err_t (* statusGet)(pcif_ctrl_t * const p_ctrl, pcif_status_t * const p_status);

    /** Generates a software event to trigger the PCIF.
     * @par Implemented as
     * - R_PCIF_SoftwareEventGenerate() 
     * 
     * @note This function is only available in incremental mode.
     * @note This function is used to generate a Z phase signal.
     *
     * @param[in]  p_ctrl      Control block set in @ref pcif_api_t::open call for this module.
     */
    fsp_err_t (* softwareEventGenerate)(pcif_ctrl_t * const p_ctrl);

    /** Closes the driver and allows reconfiguration. May reduce power consumption.
     * @par Implemented as
     * - R_PCIF_Close()  
     * 
     * @param[in]  p_ctrl      Control block set in @ref pcif_api_t::open call for this module.
     */
    fsp_err_t (* close)(pcif_ctrl_t * const p_ctrl);
} pcif_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_pcif_instance
{
    pcif_ctrl_t      * p_ctrl;         ///< Pointer to the control structure for this instance
    pcif_cfg_t const * p_cfg;          ///< Pointer to the configuration structure for this instance
    pcif_api_t const * p_api;          ///< Pointer to the API structure for this instance
} pcif_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end addtogroup PCIF_API_API)
 **********************************************************************************************************************/
