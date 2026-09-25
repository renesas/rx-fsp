/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include "r_pcif_cfg.h"
#include "r_pcif.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Driver ID (PCIF in ASCII), used to identify PCIF configuration  */
#define PCIF_PRV_OPEN                         (0x50434946)

/** Max cycle for CCLK for software reset (More than 2 cycle)*/
#define PCIF_PRV_CCLK_RESET_CYCLES            (0x5U)

/** Minimum value allowed in POSMAXR (4 * N - 1, where N >= 4) */
#define PCIF_PRV_MIN_OF_MAX_COUNT_POSITION    (15U)

/** Phase counting error mask */
#define PCIF_PRV_PHCSR_ERROR_MASK             (R_PCIF0_PHCSR_PHCCEES_Msk | R_PCIF0_PHCSR_PHCIECES_Msk | \
                                               R_PCIF0_PHCSR_PHCIECOES_Msk | R_PCIF0_PHCSR_PHCOECUES_Msk)

/** Phase counting error clear mask */
#define PCIF_PRV_PHCSR_ERROR_CLEAR_MASK       (R_PCIF0_PHCSCR_PHCCEESC_Msk | R_PCIF0_PHCSCR_PHCIECESC_Msk | \
                                               R_PCIF0_PHCSCR_PHCIECOESC_Msk | R_PCIF0_PHCSCR_PHCOECUESC_Msk)

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void r_pcif_phc_main_process(timer_callback_args_t * args);

static void r_pcif_hw_initialize(pcif_instance_ctrl_t * const p_instance_ctrl, pcif_cfg_t const * const p_cfg);

static void r_pcif_software_reset(pcif_instance_ctrl_t * const p_instance_ctrl);
static void r_pcif_call_callback(pcif_instance_ctrl_t * p_instance_ctrl, pcif_error_t error);
static void r_pcif_stop_process(pcif_instance_ctrl_t * p_instance_ctrl, pcif_stop_mode_t stop_mode);

#if PCIF_CFG_TIMER_ENABLE
static fsp_err_t r_pcif_timer_open(pcif_instance_ctrl_t * const p_instance_ctrl);
static void      r_pcif_timer_close(pcif_instance_ctrl_t * const p_instance_ctrl);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/** PCIF implementation of PCIF interface. */
const pcif_api_t g_pcif_on_pcif =
{
    .open                  = R_PCIF_Open,
    .start                 = R_PCIF_Start,
    .stop                  = R_PCIF_Stop,
    .setCounter            = R_PCIF_SetCounter,
    .statusGet             = R_PCIF_StatusGet,
    .softwareEventGenerate = R_PCIF_SoftwareEventGenerate,
    .close                 = R_PCIF_Close,
};

/*******************************************************************************************************************//**
 * @addtogroup PCIF
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the pcif module and applies configurations. Implements @ref pcif_api_t::open.
 *
 * This function sets this clock divisor and the configurations specified in pcif_cfg_t.
 *
 * Example:
 * @snippet r_pcif_example.c R_PCIF_Open
 *
 * @retval FSP_SUCCESS                      Successful open.
 * @retval FSP_ERR_ALREADY_OPEN             The control structure is already opened.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT   The channel requested in the p_cfg parameter is not available on this device.
 * @retval FSP_ERR_ASSERTION                Parameter check failure due to one or more reasons below:
 *                                          1. Pointer p_api_ctrl or p_cfg is NULL.
 *                                          2. Extended parameter is NULL.
 *                                          3. Timer instance in p_cfg is NULL when timer support enabled
 *                                          4. Callback parameter is NULL when ELC support enabled.
 * @retval FSP_ERR_INVALID_DATA             Parameter check failure due to one or more reasons below:
 *                                          1. Max count position does not meet “4 * N – 1" requirement.
 *                                          2. Value diff threshold is greater than or equal to value carrier period.
 *                                          3. Initial position is greater than max count position.
 *                                          4. Initial edge count is outside the carrier period range.
 *                                          5. Incremental resolution ratio is outside the hardware bit-field range.
 *                                          6. Prohibited incremental Z generation sources are enabled together.
 *                                          7. Prohibited incremental position clear source is enabled.
 **********************************************************************************************************************/
fsp_err_t R_PCIF_Open (pcif_ctrl_t * const p_ctrl, pcif_cfg_t const * const p_cfg)
{
    pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) p_ctrl;
#if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the control block is not null. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);

    /* Verify extend config*/
    pcif_extended_cfg_t * p_extend = (pcif_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(NULL != p_extend);

    /* Verify that the channel is valid. */
    FSP_ERROR_RETURN(BSP_PERIPHERAL_PCIF_CHANNEL_MASK & (1U << p_cfg->channel), FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    /* Verify that the control block is not already opened. */
    FSP_ERROR_RETURN(PCIF_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Validate max count position must meet “4 * N – 1" */
    FSP_ERROR_RETURN((PCIF_PRV_MIN_OF_MAX_COUNT_POSITION <= p_cfg->max_count_position) &&
                     (0U == ((p_cfg->max_count_position + 1U) % 4U)),
                     FSP_ERR_INVALID_DATA);

    if (PCIF_MODE_PHASE_COUNTING == p_cfg->mode)
    {
        /* Verify init counter config pointer */
        FSP_ASSERT(NULL != p_extend->p_init_counter_data);

        /* Carrier period difference threshold must be smaller than the carrier period. */
        FSP_ERROR_RETURN((p_extend->carrier_period_diff_threshold < p_extend->carrier_period_counts),
                         FSP_ERR_INVALID_DATA);

        /* Initial position must be smaller than max count position */
        FSP_ERROR_RETURN((p_cfg->max_count_position >= p_extend->p_init_counter_data->new_position),
                         FSP_ERR_INVALID_DATA);

        /* Edge count must be in the range -PHCPERIOD to +PHCPERIOD. */
        FSP_ERROR_RETURN(((int32_t) p_extend->p_init_counter_data->edge_count <=
                          (int32_t) p_extend->carrier_period_counts) &&
                         ((int32_t) p_extend->p_init_counter_data->edge_count >=
                          -((int32_t) p_extend->carrier_period_counts)),
                         FSP_ERR_INVALID_DATA);
    }
    else
    {
        /* Incremental resolution ratio must fit in INCRSL[5:0]. */
        FSP_ERROR_RETURN((PCIF_INC_RESOLUTION_RATIO_SETTING_MAX >= p_extend->resolution_ratio_setting),
                         FSP_ERR_INVALID_DATA);

        /* Counter-based Z generation and Z-input generation are mutually exclusive. */
        FSP_ERROR_RETURN(PCIF_INC_Z_PHASE_GEN_COUNTER_INPUT_PROHIBITED_MASK !=
                         (p_extend->z_generate_source & PCIF_INC_Z_PHASE_GEN_COUNTER_INPUT_PROHIBITED_MASK),
                         FSP_ERR_INVALID_DATA);

        /* Clearing the position counter by Z input is prohibited with counter-based Z generation. */
        FSP_ERROR_RETURN((0U == (p_extend->z_generate_source & PCIF_INC_Z_PHASE_GEN_COUNTER)) ||
                         (0U == (p_extend->position_clear_source & PCIF_INC_COUNTER_CLEAR_Z_GEN_PROHIBITED_MASK)),
                         FSP_ERR_INVALID_DATA);
    }
#endif

    /* Initialize the control structure. */
    p_instance_ctrl->p_cfg = p_cfg;

    /* Calculate base address for registers on this channel. */
    R_PCIF0_Type * p_reg = (R_PCIF0_Type *) (R_PCIF0_BASE + (p_cfg->channel * (R_PCIF1_BASE - R_PCIF0_BASE)));

    /* Set the initial value of the control structure. */
    p_instance_ctrl->p_reg             = p_reg;
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Initialize hardware specific settings */
    r_pcif_hw_initialize(p_instance_ctrl, p_cfg);

    /* Set status channel */
    p_instance_ctrl->state = PCIF_STATE_STOPPED;

    /* Initialization complete. */
    p_instance_ctrl->open = PCIF_PRV_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts PCIF. Implements @ref pcif_api_t::start.
 *
 * Example:
 * @snippet r_pcif_example.c R_PCIF_Start
 *
 * @retval FSP_SUCCESS                 Timer successfully started.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 * @retval FSP_ERR_IN_USE              Channel is running.
 * @return                             See @ref RENESAS_ERROR_CODES or lower level drivers for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t R_PCIF_Start (pcif_ctrl_t * const p_ctrl)
{
    pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) p_ctrl;
#if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the control block is not null. */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify that the control block is opened. */
    FSP_ERROR_RETURN(PCIF_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Verify that is channel available */
    FSP_ERROR_RETURN(PCIF_STATE_STOPPED == p_instance_ctrl->state, FSP_ERR_IN_USE);
#endif

#if PCIF_CFG_TIMER_ENABLE

    /* Configure timer dependency module if needed */
    if (NULL != p_instance_ctrl->p_cfg->p_lower_lvl_timer)
    {
        fsp_err_t err = r_pcif_timer_open(p_instance_ctrl);
        FSP_ERROR_RETURN((FSP_SUCCESS == err), err);
    }
#endif

    /* Start PCIF */
    p_instance_ctrl->p_reg->TRGR_b.PCIFSTRT = 1U;

    /* Waiting for PCIFPS = 1 */
    FSP_HARDWARE_REGISTER_WAIT(1U, p_instance_ctrl->p_reg->SR_b.PCIFPS);

    /* Set status channel */
    p_instance_ctrl->state = PCIF_STATE_RUNNING;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop PCIF. Implements @ref pcif_api_t::stop.
 *
 * Example:
 * @snippet r_pcif_example.c R_PCIF_Stop
 *
 * @retval FSP_SUCCESS                 Module successfully stops.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIF_Stop (pcif_ctrl_t * const p_ctrl, pcif_stop_mode_t stop_mode)
{
    pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) p_ctrl;
#if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the control block is not null. */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify that the control block is opened. */
    FSP_ERROR_RETURN(PCIF_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /** Stop PCIF */
    r_pcif_stop_process(p_instance_ctrl, stop_mode);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close PCIF. Implements @ref pcif_api_t::close.
 *
 * This function powers down the PCIF and closes the lower level timer drivers if they are used.
 *
 * Example:
 * @snippet r_pcif_example.c R_PCIF_Close
 *
 * @retval FSP_SUCCESS                 Timer successfully started.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIF_Close (pcif_ctrl_t * const p_ctrl)
{
    pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) p_ctrl;
#if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the control block is not null. */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify that the control block is opened. */
    FSP_ERROR_RETURN(PCIF_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Stop PCIF according to Figure "PCIF Stop Processing Flow" in
     * section "Operational Flow" from the relevant hardware manual. */

    /* Reset software */
    r_pcif_software_reset(p_instance_ctrl);

    /* Disable clock */
    p_instance_ctrl->p_reg->CLKER_b.CLKEN = 0U;

    /* Waiting for clock disable */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_instance_ctrl->p_reg->CLKSR_b.CLKS);

    /* Disable PCIF module */
    R_BSP_MODULE_STOP(FSP_IP_PCIF, p_instance_ctrl->p_cfg->channel);

#if PCIF_CFG_TIMER_ENABLE

    /* Close the handles for the timer interfaces */
    r_pcif_timer_close(p_instance_ctrl);
#endif

    /* Mark instance as closed. */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set counter data in phase counting mode. Implements @ref pcif_api_t::setCounter.
 * Only used in phase counting mode.
 * This function returns the PCIF information.
 *
 * Example:
 * @snippet r_pcif_example.c R_PCIF_SetCounter
 *
 * @retval FSP_SUCCESS                 Information successfully retrieved.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 * @retval FSP_ERR_INVALID_MODE        The mode is not phase counting.
 * @retval FSP_ERR_INVALID_DATA        The new position or edge count is invalid.
 **********************************************************************************************************************/
fsp_err_t R_PCIF_SetCounter (pcif_ctrl_t * const                   p_ctrl,
                             pcif_phc_counter_info_t const * const p_counter_data,
                             bool                                  reset_counter)
{
    pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) p_ctrl;
#if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the control block is not null. */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify that the counter data is not null. */
    FSP_ASSERT(NULL != p_counter_data);

    /* Verify that the control block is opened. */
    FSP_ERROR_RETURN(PCIF_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Verify that the mode is phase counting */
    FSP_ERROR_RETURN(PCIF_MODE_PHASE_COUNTING == p_instance_ctrl->p_cfg->mode, FSP_ERR_INVALID_MODE);

    /* Validate new position and edge count. */
    FSP_ERROR_RETURN((p_instance_ctrl->p_cfg->max_count_position >= p_counter_data->new_position),
                     FSP_ERR_INVALID_DATA);

    pcif_extended_cfg_t * p_extend = (pcif_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    FSP_ERROR_RETURN(((int32_t) p_counter_data->edge_count <= (int32_t) p_extend->carrier_period_counts) &&
                     ((int32_t) p_counter_data->edge_count >= -((int32_t) p_extend->carrier_period_counts)),
                     FSP_ERR_INVALID_DATA);
#endif

    /* Set the position counter */
    if (reset_counter)
    {
        p_instance_ctrl->p_reg->PHCPCWDR =
            (uint32_t) ((p_counter_data->new_position & R_PCIF0_PHCPCWDR_PHCPOSCNTWD_Msk) <<
                        R_PCIF0_PHCPCWDR_PHCPOSCNTWD_Pos);

        /* Waiting for PHCPCUS flag to 0, make sure counter position updated*/
        FSP_HARDWARE_REGISTER_WAIT(0U, p_instance_ctrl->p_reg->PHCSR_b.PHCPCUS);
    }

    /* Waiting for PHCECUS flag to 0 */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_instance_ctrl->p_reg->PHCSR_b.PHCECUS);

    /* Cast to uint16t to keep signed patten then cast to uint32t */
    p_instance_ctrl->p_reg->PHCECR =
        (((uint32_t) (uint16_t) (p_counter_data->edge_count)) & R_PCIF0_PHCECR_PHCEDGCNT_Msk) <<
            R_PCIF0_PHCECR_PHCEDGCNT_Pos;

    /* PHCECR can be cleared automatically, so retain the configured direction for StatusGet. */
    p_instance_ctrl->rotation_direction =
        (0 > p_counter_data->edge_count) ? PCIF_ROTATION_DIRECTION_CCW : PCIF_ROTATION_DIRECTION_CW;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get PCIF status. Implements @ref pcif_api_t::statusGet.
 *
 * This function returns the PCIF status.
 *
 * Example:
 * @snippet r_pcif_example.c R_PCIF_StatusGet
 *
 * @retval FSP_SUCCESS                 Status successfully retrieved.
 * @retval FSP_ERR_ASSERTION           p_ctrl or p_status was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIF_StatusGet (pcif_ctrl_t * const p_ctrl, pcif_status_t * const p_status)
{
    pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) p_ctrl;
#if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the control block is not null. */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify that the status pointer is not null. */
    FSP_ASSERT(NULL != p_status);

    /* Verify that the control block is opened. */
    FSP_ERROR_RETURN(PCIF_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Fill the status structure. */
    p_status->state = (p_instance_ctrl->p_reg->SR & R_PCIF0_SR_PCIFPS_Msk) ?
                      PCIF_STATE_RUNNING : PCIF_STATE_STOPPED;
    p_status->position_write_value = 0U;
    p_status->input_counter_value  = 0U;

    if (PCIF_MODE_PHASE_COUNTING == p_instance_ctrl->p_cfg->mode)
    {
        p_status->rotation_direction = p_instance_ctrl->rotation_direction;

        uint32_t phcpcmr = p_instance_ctrl->p_reg->PHCPCMR;
        p_status->current_position_value = (uint16_t) ((phcpcmr & R_PCIF0_PHCPCMR_PHCPOSCNTM_Msk) >>
                                                       R_PCIF0_PHCPCMR_PHCPOSCNTM_Pos);
        uint32_t phcpcwdr = p_instance_ctrl->p_reg->PHCPCWDR;
        p_status->position_write_value = (uint16_t) ((phcpcwdr & R_PCIF0_PHCPCWDR_PHCPOSCNTWD_Msk) >>
                                                     R_PCIF0_PHCPCWDR_PHCPOSCNTWD_Pos);
    }
    else
    {
        uint32_t incpcmr = p_instance_ctrl->p_reg->INCPCMR;
        p_status->rotation_direction = (pcif_rotation_direction_t) ((incpcmr & R_PCIF0_INCPCMR_INCROTM_Msk) >>
                                                                    R_PCIF0_INCPCMR_INCROTM_Pos);
        p_status->current_position_value = (uint16_t) ((incpcmr & R_PCIF0_INCPCMR_INCOCNTM_Msk) >>
                                                       R_PCIF0_INCPCMR_INCOCNTM_Pos);
        p_status->input_counter_value = (uint8_t) ((incpcmr & R_PCIF0_INCPCMR_INCICNTM_Msk) >>
                                                   R_PCIF0_INCPCMR_INCICNTM_Pos);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Software reset PCIF. Implements @ref pcif_api_t::softwareEventGenerate.
 *
 * This function generates a software event to reset the PCIF.
 *
 * Example:
 * @snippet r_pcif_example.c R_PCIF_SoftwareEventGenerate
 *
 * @retval FSP_SUCCESS                 Software event successfully generated.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 * @retval FSP_ERR_INVALID_MODE        The mode is not incremental.
 **********************************************************************************************************************/
fsp_err_t R_PCIF_SoftwareEventGenerate (pcif_ctrl_t * const p_ctrl)
{
    pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) p_ctrl;
#if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the control block is not null. */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify that the control block is opened. */
    FSP_ERROR_RETURN(PCIF_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Verify that the mode is incremental mode */
    FSP_ERROR_RETURN(PCIF_MODE_INCREMENTAL == p_instance_ctrl->p_cfg->mode, FSP_ERR_INVALID_MODE);
#endif

    /* Generate software event */
    p_instance_ctrl->p_reg->INCSWTRGR_b.INCSWT = 1U;

    /* INCSWTRGR will auto clear to 0 after write 1 */

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup R_PCIF)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Main Process of PCIF phase counting mode, perfoms PCIF operation flow as describe in HUM
 * Should be call by callback of timer dependency module
 *
 * @param[in] args      Pointer to the timer callback args structure.
 *
 **********************************************************************************************************************/
void r_pcif_phc_main_process (timer_callback_args_t * args)
{
    /* Main process according to Figure "Phase Counting Main Processing Flow" in
     * section "Operational Flow" from the relevant hardware manual. */
    if (NULL != args)
    {
        pcif_instance_ctrl_t * p_instance_ctrl = (pcif_instance_ctrl_t *) args->p_context;

        if (NULL != p_instance_ctrl)
        {
            /* Get status, mask out non-error statuses */
            uint32_t phcsr = p_instance_ctrl->p_reg->PHCSR & PCIF_PRV_PHCSR_ERROR_MASK;

            /* Set errors */
            pcif_error_t event = (pcif_error_t) (phcsr);

            /* Check if there is an error */
            if (PCIF_ERROR_NONE != event)
            {
                /* Clear error flags */
                p_instance_ctrl->p_reg->PHCSCR = PCIF_PRV_PHCSR_ERROR_CLEAR_MASK;

                /* Stop process since error occur */
                r_pcif_stop_process(p_instance_ctrl, PCIF_STOP_MODE_IMMEDIATE);
            }

            /* Call callback if provided */
            if (p_instance_ctrl->p_callback)
            {
                /* Notify user error or allow user to update edge data*/
                r_pcif_call_callback(p_instance_ctrl, event);
            }
        }
    }
}

/*******************************************************************************************************************//**
 * Performs hardware initialization of the pcif with selected mode.
 *
 * @param[in]  p_instance_ctrl        Instance control block.
 * @param[in]  p_cfg                  Pointer to pcif configuration.
 **********************************************************************************************************************/
static void r_pcif_hw_initialize (pcif_instance_ctrl_t * const p_instance_ctrl, pcif_cfg_t const * const p_cfg)
{
    R_PCIF0_Type * p_reg = p_instance_ctrl->p_reg;

    /* Enable PCIF module */
    R_BSP_MODULE_START(FSP_IP_PCIF, p_cfg->channel);

    /* Initialize PCIF IP according to Figure "PCIF Start Flow" in
     * section "Operational Flow" from the relevant hardware manual. */

    /* Disable clock */
    p_reg->CLKER_b.CLKEN = 0U;

    /* Waiting for clock enable CLKS = 0. */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_reg->CLKSR);

    /* Clock scr and clock div setting */
    p_reg->CLKCR = (uint32_t) (p_cfg->clock_src << R_PCIF0_CLKCR_CLKSEL_Pos) |
                   (uint32_t) (p_cfg->clock_div << R_PCIF0_CLKCR_DIVR_Pos);

#if BSP_FEATURE_BSP_HAS_GPT_CLOCK

    /* If using the asynchronous clock, enable GPT to supply GPTCLK. */
    if (PCIF_CLOCK_SOURCE_ASYN_CLK == p_cfg->clock_src)
    {
        /* Enable GPT to use GPTCLK */
        R_BSP_MODULE_START(FSP_IP_GPT, 0);
    }
#endif

    /* Set the mode */
    uint32_t ctlr = (uint32_t) (p_cfg->mode << R_PCIF0_CTLR_PCIFMD_Pos);

    /* Set signal polarity */
    ctlr       |= (uint32_t) (p_cfg->a_phase_polarity << R_PCIF0_CTLR_APOL_Pos);
    ctlr       |= (uint32_t) (p_cfg->b_phase_polarity << R_PCIF0_CTLR_BPOL_Pos);
    ctlr       |= (uint32_t) (p_cfg->z_phase_polarity << R_PCIF0_CTLR_ZPOL_Pos);
    p_reg->CTLR = ctlr;

    /* Enable clock */
    p_reg->CLKER_b.CLKEN = 1U;

    /* Waiting for clock enable CLKS = 1. */
    FSP_HARDWARE_REGISTER_WAIT(1U, p_reg->CLKSR);

    /* Set the position max for counter */
    p_reg->POSMAXR = p_cfg->max_count_position;

    pcif_extended_cfg_t * p_extend = (pcif_extended_cfg_t *) p_cfg->p_extend;
    if (PCIF_MODE_PHASE_COUNTING == p_cfg->mode)
    {
        /* Initialize The Phase Counting mode PCIF according to Figure "Phase Counting Mode Startup" in
         * section "Operational Flow" from the relevant hardware manual. */

        /* Z phase and Carrier Period settings */
        p_reg->PHCCTLR = (uint32_t) (p_extend->z_width << R_PCIF0_PHCCTLR_PHCZW_Pos) |
                         (uint32_t) (p_extend->z_sync << R_PCIF0_PHCCTLR_PHCZOS_Pos) |
                         (uint32_t) (p_extend->carrier_period_mode << R_PCIF0_PHCCTLR_PHCCEDAMD_Pos) |
                         (uint32_t) (p_extend->counter_clear_mode << R_PCIF0_PHCCTLR_PHCECACMD_Pos);

        /* Set the carrier period diff threshold */
        p_reg->PHCCEDTHR = (uint32_t) (p_extend->carrier_period_diff_threshold << R_PCIF0_PHCCEDTHR_PHCCEDTH_Pos);

        /* Set the carrier period. */
        p_reg->PHCPERIODR = (uint32_t) (p_extend->carrier_period_counts << R_PCIF0_PHCPERIODR_PHCPERIOD_Pos);

        /* Set error enable */
        p_reg->PHCSER = (uint32_t) (p_extend->error_carrier_period_enable << R_PCIF0_PHCSCR_PHCCEESC_Pos) |
                        (uint32_t) (p_extend->error_edge_count_enable << R_PCIF0_PHCSCR_PHCIECESC_Pos) |
                        (uint32_t) (p_extend->error_edge_count_overflow_enable << R_PCIF0_PHCSCR_PHCIECOESC_Pos) |
                        (uint32_t) (p_extend->error_old_edge_count_enable << R_PCIF0_PHCSCR_PHCOECUESC_Pos);

        /* Set position */
        pcif_phc_counter_info_t * p_init_counter_data = p_extend->p_init_counter_data;
        p_reg->PHCPCWDR = (uint32_t) ((p_init_counter_data->new_position) << R_PCIF0_PHCPCWDR_PHCPOSCNTWD_Pos);

        /* Cast to uint16t to keep signed partten then cast to uint32t */
        p_reg->PHCECR = (((uint32_t) (uint16_t) (p_init_counter_data->edge_count)) & R_PCIF0_PHCECR_PHCEDGCNT_Msk) <<
                        R_PCIF0_PHCECR_PHCEDGCNT_Pos;
        p_instance_ctrl->rotation_direction =
            (0 > p_init_counter_data->edge_count) ? PCIF_ROTATION_DIRECTION_CCW : PCIF_ROTATION_DIRECTION_CW;
    }
    else                               /** PCIF_MODE_INCREMENTAL */
    {
        /* Initialize The Incremental mode PCIF according to Figure "Incremental Mode Startup" in
         * section "Operational Flow" from the relevant hardware manual. */

        /* Phase ABZ input and output settings */
        uint32_t incctl = (uint32_t) (p_extend->ab_input_mode << R_PCIF0_INCCTLR_INCIMD_Pos) |
                          (uint32_t) (p_extend->ab_output_mode << R_PCIF0_INCCTLR_INCOMD_Pos) |
                          (uint32_t) (p_extend->z_output_mode << R_PCIF0_INCCTLR_INCZOS_Pos);

        /* Set resolution */
        incctl |= (uint32_t) (p_extend->resolution_ratio_setting << R_PCIF0_INCCTLR_INCRSL_Pos);

        /* Set Z phase output minimum cycle */
        incctl        |= (uint32_t) (p_extend->z_output_min_cycles << R_PCIF0_INCCTLR_INCZOMIN_Pos);
        p_reg->INCCTLR = incctl;

        /* Set the Z phase generate source */
        p_reg->INCZGCTLR = (uint32_t) (p_extend->z_generate_source);

        /* Set the position clear source */
        p_reg->INCPCCER = (uint32_t) (p_extend->position_clear_source);
    }
}

#if PCIF_CFG_TIMER_ENABLE

/***********************************************************************************************************************
 * Configures the timer dependency module (if enabled).
 *
 * @param[in] p_cfg                  Pointer to pcif configuration.
 *
 * @retval FSP_SUCCESS               Timer configured successfully
 * @retval FSP_ERR_ASSERTION         Timer configured input parameter is invalid.
 * @return                           See @ref RENESAS_ERROR_CODES or functions called by this function for other
 *                                   possible return codes. This function calls:
 *                                       *@ref pcif_api_t::start.
 **********************************************************************************************************************/
static fsp_err_t r_pcif_timer_open (pcif_instance_ctrl_t * const p_instance_ctrl)
{
    fsp_err_t          err;
    timer_instance_t * p_timer = (timer_instance_t *) p_instance_ctrl->p_cfg->p_lower_lvl_timer;
 #if PCIF_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the timer instance is not null. */
    FSP_ASSERT(NULL != p_timer->p_api);
    FSP_ASSERT(NULL != p_timer->p_cfg);
    FSP_ASSERT(NULL != p_timer->p_ctrl);
 #endif

    /* Open timer */
    err = p_timer->p_api->open(p_timer->p_ctrl, p_timer->p_cfg);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);

    /* Start timer */
    err = p_timer->p_api->start(p_timer->p_ctrl);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Closes the timer dependency module (if enabled).
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 **********************************************************************************************************************/
static void r_pcif_timer_close (pcif_instance_ctrl_t * const p_instance_ctrl)
{
    /* Close the handles for the timer interfaces */
    if (NULL != p_instance_ctrl->p_cfg->p_lower_lvl_timer)
    {
        timer_instance_t * p_timer = (timer_instance_t *) p_instance_ctrl->p_cfg->p_lower_lvl_timer;
        p_timer->p_api->close(p_timer->p_ctrl);
    }
}

#endif

/***********************************************************************************************************************
 * Stop process PCIF.
 *
 * @param[in] p_instance_ctrl          Pointer to the p_instance_ctrl structure.
 * @param[in] stop_mode                Stop mode.
 **********************************************************************************************************************/
static void r_pcif_stop_process (pcif_instance_ctrl_t * const p_instance_ctrl, pcif_stop_mode_t stop_mode)
{
    if ((PCIF_MODE_PHASE_COUNTING == p_instance_ctrl->p_cfg->mode) && (PCIF_STOP_MODE_SYNC == stop_mode))
    {
        /* Trigger synchronous stop */
        p_instance_ctrl->p_reg->TRGR_b.PHCSTPT = 1U;
    }
    else
    {
        /* Trigger immediate stop */
        p_instance_ctrl->p_reg->TRGR_b.PCIFSTPT = 1U;
    }

    /* Waiting for PCIF Stop */
    FSP_HARDWARE_REGISTER_WAIT(0U, p_instance_ctrl->p_reg->SR_b.PCIFPS);

    /* Wait for software reset if phase-counting stop immediately */
    if ((PCIF_MODE_PHASE_COUNTING == p_instance_ctrl->p_cfg->mode) && (PCIF_STOP_MODE_IMMEDIATE == stop_mode))
    {
        r_pcif_software_reset(p_instance_ctrl);
    }

#if PCIF_CFG_TIMER_ENABLE

    /* Close the handles for the timer interfaces */
    r_pcif_timer_close(p_instance_ctrl);
#endif

    /* Reset status channel */
    p_instance_ctrl->state = PCIF_STATE_STOPPED;
}

/***********************************************************************************************************************
 * Call user callback with the provided event.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 * @param[in] error                    The error event to pass to the callback.
 **********************************************************************************************************************/
static void r_pcif_call_callback (pcif_instance_ctrl_t * const p_instance_ctrl, pcif_error_t error)
{
    pcif_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    pcif_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->error     = error;
    p_args->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/***********************************************************************************************************************
 * Reset software PCIF operation.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 **********************************************************************************************************************/
static void r_pcif_software_reset (pcif_instance_ctrl_t * const p_instance_ctrl)
{
    uint32_t delay_microseconds;
    uint32_t cclk_freq;

    /* Calculate delay for software reset */
    if (PCIF_CLOCK_SOURCE_SYN_CLK == p_instance_ctrl->p_cfg->clock_src)
    {
        cclk_freq = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_PCLKB);
    }
    else                               /* PCIF_CLOCK_SOURCE_ASYN_CLK (GPTCLK) */
    {
        uint32_t gptckdivcr = R_SYSTEM->GPTCKDIVCR;
        uint32_t divider    = R_FSP_ClockDividerGet(gptckdivcr & R_SYSTEM_GPTCKDIVCR_GPTCKDIV_Msk);
        cclk_freq = R_BSP_SourceClockHzGet((fsp_priv_source_clock_t) R_SYSTEM->GPTCKCR_b.GPTCKSEL) / divider;
    }

    /* Round up to guarantee the reset remains asserted for the required number of CCLK_DIV cycles. */
    uint32_t const reset_cycles = PCIF_PRV_CCLK_RESET_CYCLES * ((uint32_t) p_instance_ctrl->p_cfg->clock_div + 1U);
    delay_microseconds = ((reset_cycles * BSP_DELAY_UNITS_SECONDS) + cclk_freq - 1U) / cclk_freq;

    /* Reset PCIF */
    p_instance_ctrl->p_reg->SWRSTR_b.SWRST = 1U;

    /* Wait more than 2 cycles of CCLK to reset PCIF peripheral */
    R_BSP_SoftwareDelay(delay_microseconds, BSP_DELAY_UNITS_MICROSECONDS);

    p_instance_ctrl->p_reg->SWRSTR_b.SWRST = 0U;
}
