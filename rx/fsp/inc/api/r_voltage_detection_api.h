/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_MONITORING_INTERFACES
 * @defgroup VOLTAGE_DETECTION_API Voltage Detection Interface
 * @brief Interface for Voltage Detection
 *
 * @section VOLTAGE_DETECTION_API_SUMMARY Summary
 * The VOLTAGE DETECTION driver provides functions for configuring the VOLTAGE DETECTION voltage monitors and detectors.
 *
 *
 * @{
 **********************************************************************************************************************/
#ifndef R_VOLTAGE_DETECTION_API_H
#define R_VOLTAGE_DETECTION_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/** Register definitions, common services, and error codes. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#ifndef BSP_OVERRIDE_VOLTAGE_DETECTION_PERIPHERAL_T

/** Voltage detection level */

/** The thresholds supported by each MCU are in the MCU User's Manual as well as
 *  in the r_voltage_detection module description on the stack tab of the RA project. */
typedef enum
{
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_4_29V = 0x00UL, ///< 4.29V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_4_16V = 0x01UL, ///< 4.16V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_4_14V = 0x01UL, ///< 4.14V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_4_03V = 0x02UL, ///< 4.03V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_4_02V = 0x02UL, ///< 4.02V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_3_86V = 0x03UL, ///< 3.86V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_3_84V = 0x03UL, ///< 3.84V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_3_10V = 0x04UL, ///< 3.10V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_3_00V = 0x05UL, ///< 3.00V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_90V = 0x06UL, ///< 2.90V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_79V = 0x07UL, ///< 2.79V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_68V = 0x08UL, ///< 2.68V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_58V = 0x09UL, ///< 2.58V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_48V = 0x0AUL, ///< 2.48V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_20V = 0x0BUL, ///< 2.20V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_1_96V = 0x0CUL, ///< 1.96V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_1_86V = 0x0DUL, ///< 1.86V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_1_75V = 0x0EUL, ///< 1.75V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_1_65V = 0x0FUL, ///< 1.65V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_99V = 0x11UL, ///< 2.99V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_92V = 0x12UL, ///< 2.92V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_1_LEVEL_2_85V = 0x13UL, ///< 2.85V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_4_31V = 0x00UL, ///< 4.31V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_4_29V = 0x00UL, ///< 4.29V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_4_17V = 0x01UL, ///< 4.17V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_4_14V = 0x01UL, ///< 4.14V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_4_03V = 0x02UL, ///< 4.03V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_4_02V = 0x02UL, ///< 4.02V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_3_84V = 0x03UL, ///< 3.84V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_2_99V = 0x05UL, ///< 2.99V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_2_92V = 0x06UL, ///< 2.92V
    VOLTAGE_DETECTION_THRESHOLD_MONITOR_2_LEVEL_2_85V = 0x07UL, ///< 2.85V

    VOLTAGE_DETECTION_THRESHOLD_EXPVDVBAT_LEVEL_3_1V = 0x06UL,  ///< 3.1V
    VOLTAGE_DETECTION_THRESHOLD_EXPVDVBAT_LEVEL_2_9V = 0x05UL,  ///< 2.9V
    VOLTAGE_DETECTION_THRESHOLD_EXPVDVBAT_LEVEL_2_8V = 0x04UL,  ///< 2.8V
    VOLTAGE_DETECTION_THRESHOLD_EXPVDVBAT_LEVEL_2_7V = 0x03UL,  ///< 2.7V
    VOLTAGE_DETECTION_THRESHOLD_EXPVDVBAT_LEVEL_2_6V = 0x02UL,  ///< 2.6V
    VOLTAGE_DETECTION_THRESHOLD_EXPVDVBAT_LEVEL_2_4V = 0x01UL,  ///< 2.4V
    VOLTAGE_DETECTION_THRESHOLD_EXPVDVBAT_LEVEL_2_2V = 0x00UL,  ///< 2.2V

    VOLTAGE_DETECTION_THRESHOLD_PVDVRTC_LEVEL_2_8V = 0x03UL,    ///< 2.8V
    VOLTAGE_DETECTION_THRESHOLD_PVDVRTC_LEVEL_2_6V = 0x02UL,    ///< 2.6V
    VOLTAGE_DETECTION_THRESHOLD_PVDVRTC_LEVEL_2_4V = 0x01UL,    ///< 2.4V
    VOLTAGE_DETECTION_THRESHOLD_PVDVRTC_LEVEL_2_2V = 0x00UL,    ///< 2.2V
    VOLTAGE_DETECTION_THRESHOLD_NOT_AVAILABLE      = 0xFFUL,    ///< Not Used
} voltage_detection_threshold_t;
#endif

/** Response types for handling threshold crossing event. */
typedef enum e_voltage_detection_response
{
    VOLTAGE_DETECTION_RESPONSE_NMI,             ///< Non-maskable interrupt
    VOLTAGE_DETECTION_RESPONSE_INTERRUPT,       ///< Maskable interrupt
    VOLTAGE_DETECTION_RESPONSE_RESET,           ///< Reset on VCC-fall
    VOLTAGE_DETECTION_RESPONSE_RESET_ON_RISING, ///< Reset on VCC-rise
    VOLTAGE_DETECTION_RESPONSE_NONE,            ///< No response, status must be requested via statusGet function
} voltage_detection_response_t;

/** The direction from which VCC must cross the threshold to trigger a detection (rising, falling, or both). */
typedef enum e_voltage_detection_voltage_slope
{
    VOLTAGE_DETECTION_VOLTAGE_SLOPE_RISING  = 0, ///< When VCC >= Vdet2 (rise) is detected
    VOLTAGE_DETECTION_VOLTAGE_SLOPE_FALLING = 1, ///< When VCC < Vdet2 (drop) is detected
    VOLTAGE_DETECTION_VOLTAGE_SLOPE_BOTH    = 2, ///< When drop and rise are detected
} voltage_detection_voltage_slope_t;

/** Sample clock divider, use VOLTAGE_DETECTION_SAMPLE_CLOCK_DISABLED to disable digital filtering */
typedef enum e_voltage_detection_sample_clock
{
    VOLTAGE_DETECTION_SAMPLE_CLOCK_LOCO_DIV_2  = 0,  ///< Digital filter sample clock is LOCO divided by 2
    VOLTAGE_DETECTION_SAMPLE_CLOCK_LOCO_DIV_4  = 1,  ///< Digital filter sample clock is LOCO divided by 4
    VOLTAGE_DETECTION_SAMPLE_CLOCK_LOCO_DIV_8  = 2,  ///< Digital filter sample clock is LOCO divided by 8
    VOLTAGE_DETECTION_SAMPLE_CLOCK_LOCO_DIV_16 = 3,  ///< Digital filter sample clock is LOCO divided by 16
    VOLTAGE_DETECTION_SAMPLE_CLOCK_DISABLED    = -1, ///< Digital filter is disabled
} voltage_detection_sample_clock_t;

/** Negation delay of VOLTAGE DETECTION reset signal follows reset or voltage in range */
typedef enum e_voltage_detection_negation_delay
{
    /**
     *  Negation follows a stabilization time (tVDn)
     *  after VCC > Vdet1 is detected.
     *  If a transition to software standby or deep software
     *  standby is to be made, the only possible value for
     *  the RN bit is VOLTAGE_DETECTION_NEGATION_DELAY_FROM_VOLTAGE
     */
    VOLTAGE_DETECTION_NEGATION_DELAY_FROM_VOLTAGE = 0,

    /**
     *  Negation follows a stabilization time (tVDn) after
     *  assertion of the VDn reset.
     *  If a transition to software standby or deep software
     *  standby is to be made, the only possible value for
     *  the RN bit is VOLTAGE_DETECTION_NEGATION_DELAY_FROM_VOLTAGE
     */
    VOLTAGE_DETECTION_NEGATION_DELAY_FROM_RESET = 1,
} voltage_detection_negation_delay_t;

/** Threshold crossing detection (latched) */
typedef enum e_voltage_detection_threshold_crossing
{
    VOLTAGE_DETECTION_THRESHOLD_CROSSING_NOT_DETECTED = 0, ///< Threshold crossing has not been detected.
    VOLTAGE_DETECTION_THRESHOLD_CROSSING_DETECTED     = 1, ///< Threshold crossing has been detected.
} voltage_detection_threshold_crossing_t;

/** Instantaneous status of VCC (above or below threshold) */
typedef enum e_voltage_detection_current_state
{
    VOLTAGE_DETECTION_CURRENT_STATE_BELOW_THRESHOLD = 0, ///< VCC <  threshold
    VOLTAGE_DETECTION_CURRENT_STATE_ABOVE_THRESHOLD = 1, ///< VCC >= threshold or monitor is disabled
} voltage_detection_current_state_t;

/**
 * Current state of a voltage monitor.
 */
typedef struct st_voltage_detection_status
{
    /** Threshold crossing detection (latched) */
    voltage_detection_threshold_crossing_t crossing_detected;

    /** Instantaneous status of monitored voltage (above or below threshold) */
    voltage_detection_current_state_t current_state;
} voltage_detection_status_t;

/** VOLTAGE DETECTION callback parameter definition */
typedef struct st_voltage_detection_callback_args
{
    uint32_t monitor_number;                         ///< Monitor number
    voltage_detection_current_state_t current_state; ///< Current state of the voltage monitor
    void * p_context;                                ///< Placeholder for user data
} voltage_detection_callback_args_t;

/** VOLTAGE DETECTION configuration structure */
typedef struct st_voltage_detection_cfg
{
    /** Monitor number, 1, 2, ... */
    uint32_t monitor_number;

    /** Threshold for out of range voltage detection */
    voltage_detection_threshold_t voltage_threshold;

    /** Response on detecting a threshold crossing */
    voltage_detection_response_t detection_response;

    /** Direction of voltage crossing that will trigger a detection (Rising Edge, Falling Edge, Both). */
    voltage_detection_voltage_slope_t voltage_slope;

    /** Negation of VOLTAGE DETECTION signal follows reset or voltage in range */
    voltage_detection_negation_delay_t negation_delay;

    /** Sample clock divider, use VOLTAGE DETECTION_SAMPLE_CLOCK_DISABLED to disable digital filtering */
    voltage_detection_sample_clock_t sample_clock_divisor;

    /** Interrupt number. */
    IRQn_Type irq;

    /** Interrupt priority level. */
    uint8_t monitor_ipl;

    /** User function to be called from interrupt */
    void (* p_callback)(voltage_detection_callback_args_t * p_args);

    /** Placeholder for user data. Passed to the user callback in  */
    void * p_context;

    /** Extension parameter for hardware specific settings */
    void const * p_extend;
} voltage_detection_cfg_t;

/** VOLTAGE DETECTION control block.  Allocate an instance specific control block to pass into the VOLTAGE_DETECTION API calls.
 */
typedef void voltage_detection_ctrl_t;

/** VOLTAGE_DETECTION driver API structure.
 *  VOLTAGE_DETECTION driver functions implemented at the HAL layer will adhere to this API.
 */
typedef struct st_voltage_detection_api
{
    /** Initializes a programmable voltage detection driver according to the passed-in configuration structure.
     * @param[in]       p_ctrl      Pointer to control structure for the driver instance
     * @param[in]       p_cfg       Pointer to the configuration structure for the driver instance
     **/
    fsp_err_t (* open)(voltage_detection_ctrl_t * const p_ctrl, voltage_detection_cfg_t const * const p_cfg);

    /** Get the current state of the monitor, (threshold crossing detected, voltage currently above or below threshold).
     * Must be used if the peripheral was initialized with voltage_detection_response_t set to VOLTAGE_DETECTION_RESPONSE_NONE.
     * @param[in]       p_ctrl          Pointer to the control structure for the driver instance
     * @param[in,out]   p_voltage_detection_status    Pointer to a voltage_detection_status_t structure
     **/
    fsp_err_t (* statusGet)(voltage_detection_ctrl_t * const p_ctrl,
                            voltage_detection_status_t     * p_voltage_detection_status);

    /** Clears the latched status of the monitor.
     * Must be used if the peripheral was initialized with voltage_detection_response_t set to VOLTAGE_DETECTION_RESPONSE_NONE.
     * @param[in]       p_ctrl      Pointer to the control structure for the driver instance
     **/
    fsp_err_t (* statusClear)(voltage_detection_ctrl_t * const p_ctrl);

    /**
     * Specify callback function and optional context pointer and working memory pointer.
     *
     * @param[in]   p_ctrl                   Pointer to the VOLTAGE_DETECTION control block.
     * @param[in]   p_callback               Callback function
     * @param[in]   p_context                Pointer to send to callback function
     * @param[in]   p_working_memory         Pointer to volatile memory where callback structure can be allocated.
     *                                       Callback arguments allocated here are only valid during the callback.
     */
    fsp_err_t (* callbackSet)(voltage_detection_ctrl_t * const p_ctrl,
                              void (* p_callback)(voltage_detection_callback_args_t *), void * const p_context,
                              voltage_detection_callback_args_t * const p_callback_memory);

    /** Disables the VOLTAGE_DETECTION peripheral.
     * Closes the driver instance.
     * @param[in]   p_ctrl      Pointer to the control structure for the driver instance
     **/
    fsp_err_t (* close)(voltage_detection_ctrl_t * const p_ctrl);
} voltage_detection_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_voltage_detection_instance
{
    voltage_detection_ctrl_t      * p_ctrl; ///< Pointer to the control structure for this instance
    voltage_detection_cfg_t const * p_cfg;  ///< Pointer to the configuration structure for this interface instance
    voltage_detection_api_t const * p_api;  ///< Pointer to the API structure for this interface instance
} voltage_detection_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup VOLTAGE_DETECTION_API)
 **********************************************************************************************************************/
