/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_exdmac.h"
#include "r_exdmac_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "EXDM" in ASCII.  Used to determine if the control block is open. */
#define EXDMAC_OPEN                       (('E' << 24U) | ('X' << 16U) | ('D' << 8U) | ('M' << 0U))

/** Length limited to 1024 transfers for repeat and block mode */
#define EXDMAC_REPEAT_BLOCK_MAX_LENGTH    (0x400)

#define EXDMAC_PRV_MASK_ALIGN_2_BYTES     (0x1U)
#define EXDMAC_PRV_MASK_ALIGN_4_BYTES     (0x3U)

/* Calculate the mask bits for byte alignment from the transfer_size_t. */
#define EXDMAC_PRV_MASK_ALIGN_N_BYTES(x)    ((1U << (x)) - 1U)

#define EXDMAC_PRV_REG(ch)                  ((R_EXDMAC0_Type *) (R_EXDMAC0_BASE + (R_EXDMAC1_BASE - R_EXDMAC0_BASE) * \
                                                                 (uint32_t) (ch)))

/* Transfer Count Register A Bit Field Definitions */
#define EXDMAC_PRV_EDMCRA_LOW_OFFSET                (0U)
#define EXDMAC_PRV_EDMCRA_LOW_MASK                  (0x3FFU << EXDMAC_PRV_EDMCRA_LOW_OFFSET)
#define EXDMAC_PRV_EDMCRA_HIGH_OFFSET               (16U)
#define EXDMAC_PRV_EDMCRA_HIGH_MASK                 (0x3FFU << EXDMAC_PRV_EDMCRA_HIGH_OFFSET)

/* Transfer Mode Register Bit Field Definitions */
#define EXDMAC_PRV_EDMTMD_DCTG_OFFSET               (0U)
#define EXDMAC_PRV_EDMTMD_DCTG_MASK                 (3U << EXDMAC_PRV_EDMTMD_DCTG_OFFSET)
#define EXDMAC_PRV_EDMTMD_SZ_OFFSET                 (8U)
#define EXDMAC_PRV_EDMTMD_SZ_MASK                   (3U << EXDMAC_PRV_EDMTMD_SZ_OFFSET)
#define EXDMAC_PRV_EDMTMD_DTS_OFFSET                (12U)
#define EXDMAC_PRV_EDMTMD_DTS_MASK                  (3U << EXDMAC_PRV_EDMTMD_DTS_OFFSET)
#define EXDMAC_PRV_EDMTMD_MD_OFFSET                 (14U)
#define EXDMAC_PRV_EDMTMD_MD_MASK                   (3U << EXDMAC_PRV_EDMTMD_MD_OFFSET)

/* Interrupt Setting Register Bit Field Definitions */
#define EXDMAC_PRV_EDMINT_DARIE_OFFSET              (0U)
#define EXDMAC_PRV_EDMINT_DARIE_MASK                (1U << EXDMAC_PRV_EDMINT_DARIE_OFFSET)
#define EXDMAC_PRV_EDMINT_SARIE_OFFSET              (1U)
#define EXDMAC_PRV_EDMINT_SARIE_MASK                (1U << EXDMAC_PRV_EDMINT_SARIE_OFFSET)
#define EXDMAC_PRV_EDMINT_RPTIE_OFFSET              (2U)
#define EXDMAC_PRV_EDMINT_RPTIE_MASK                (1U << EXDMAC_PRV_EDMINT_RPTIE_OFFSET)
#define EXDMAC_PRV_EDMINT_ESIE_OFFSET               (3U)
#define EXDMAC_PRV_EDMINT_ESIE_MASK                 (1U << EXDMAC_PRV_EDMINT_ESIE_OFFSET)
#define EXDMAC_PRV_EDMINT_DTIE_OFFSET               (4U)
#define EXDMAC_PRV_EDMINT_DTIE_MASK                 (1U << EXDMAC_PRV_EDMINT_DTIE_OFFSET)

/* Address Mode Register Bit Field Definitions */
#define EXDMAC_PRV_EDMAMD_DARA_OFFSET               (0U)
#define EXDMAC_PRV_EDMAMD_DARA_MASK                 (0x1FU << EXDMAC_PRV_EDMAMD_DARA_OFFSET)
#define EXDMAC_PRV_EDMAMD_DM_OFFSET                 (6U)
#define EXDMAC_PRV_EDMAMD_DM_MASK                   (3U << EXDMAC_PRV_EDMAMD_DM_OFFSET)
#define EXDMAC_PRV_EDMAMD_SARA_OFFSET               (8U)
#define EXDMAC_PRV_EDMAMD_SARA_MASK                 (0x1FU << EXDMAC_PRV_EDMAMD_SARA_OFFSET)
#define EXDMAC_PRV_EDMAMD_SM_OFFSET                 (14U)
#define EXDMAC_PRV_EDMAMD_SM_MASK                   (3U << EXDMAC_PRV_EDMAMD_SM_OFFSET)

/* Software Start Register Bit Field Definitions */
#define EXDMAC_PRV_EDMREQ_SWREQ_OFFSET              (0U)
#define EXDMAC_PRV_EDMREQ_SWREQ_MASK                (1U << EXDMAC_PRV_EDMREQ_SWREQ_OFFSET)
#define EXDMAC_PRV_EDMREQ_CLRS_OFFSET               (4U)
#define EXDMAC_PRV_EDMREQ_CLRS_MASK                 (1U << EXDMAC_PRV_EDMREQ_CLRS_OFFSET)

#ifndef EXDMAC_CFG_PRIORITY_MODE
 #define EXDMAC_CFG_PRIORITY_MODE                   (0)
#endif

/* EXDMAC Trigger Select Register Definitions */
#define EXDMAC_PRV_IRQ0_VECTOR_NUMBER               (64U)
#define EXDMAC_PRV_IRQ15_VECTOR_NUMBER              (79U)
#define EXDMAC_PRV_SOFTWARE_CONFIG_VECTOR_NUMBER    (128U)
#define EXDMAC_PRV_EXTERNAL_PINS_INTERRUPT          (0x3FFU)
#define EXDMAC_PRV_IRQ16_31_SLIRQ                   (112U)
#define EXDMAC_PRV_SELEXDR_SLI_MASK                 (0x03FFU) /* Mask SLI bit, valid range 000h–3FFh, other values are prohibited */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Internal driver storage for p_callback, used by ISRs. */
typedef struct st_exdmac_callback
{
    /** Callback for transfer end interrupt. Set to NULL for no CPU interrupt. */
    void (* p_callback)(exdmac_callback_args_t * cb_data);

    /** Placeholder for user data.  Passed to the user p_callback in ::transfer_callback_args_t. */
    void * p_context;
} exdmac_callback_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void exdmac_int_isr(void);

static fsp_err_t r_exdmac_prv_enable(exdmac_instance_ctrl_t * p_ctrl);
static void      r_exdmac_prv_disable(exdmac_instance_ctrl_t * p_ctrl);
static void      r_exdmac_config_transfer_info(exdmac_instance_ctrl_t * p_ctrl, transfer_info_t * p_info);

#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_exdma_open_parameter_checking(exdmac_instance_ctrl_t * const p_ctrl,
                                                 transfer_cfg_t const * const   p_cfg);
static fsp_err_t r_exdmac_reconfigure_parameter_checking(transfer_info_t const * const p_info);
static fsp_err_t r_exdmac_enable_parameter_checking(exdmac_instance_ctrl_t * const p_ctrl);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** EXDMAC implementation of transfer API. */
const transfer_api_t g_transfer_on_exdmac =
{
    .open          = R_EXDMAC_Open,
    .reconfigure   = R_EXDMAC_Reconfigure,
    .reset         = R_EXDMAC_Reset,
    .infoGet       = R_EXDMAC_InfoGet,
    .softwareStart = R_EXDMAC_SoftwareStart,
    .softwareStop  = R_EXDMAC_SoftwareStop,
    .enable        = R_EXDMAC_Enable,
    .disable       = R_EXDMAC_Disable,
    .reload        = R_EXDMAC_Reload,
    .callbackSet   = R_EXDMAC_CallbackSet,
    .close         = R_EXDMAC_Close,
};

/*******************************************************************************************************************//**
 * @addtogroup EXDMAC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configure an EXDMAC channel.
 *
 * @retval FSP_SUCCESS                    Successful open.
 * @retval FSP_ERR_ASSERTION              An input parameter is invalid.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The configured channel is invalid.
 * @retval FSP_ERR_IRQ_BSP_DISABLED       The IRQ associated with the activation source is not enabled in the BSP.
 * @retval FSP_ERR_ALREADY_OPEN           The control structure is already opened.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_Open (transfer_ctrl_t * const p_api_ctrl, transfer_cfg_t const * const p_cfg)
{
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = FSP_SUCCESS;
    err = r_exdma_open_parameter_checking(p_api_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    exdmac_instance_ctrl_t * p_ctrl   = (exdmac_instance_ctrl_t *) p_api_ctrl;
    exdmac_extended_cfg_t  * p_extend = (exdmac_extended_cfg_t *) p_cfg->p_extend;

    p_ctrl->p_cfg = p_cfg;
    p_ctrl->p_reg = EXDMAC_PRV_REG(p_extend->channel);

    /* Set callback and context pointers, if configured */
    p_ctrl->p_callback        = p_extend->p_callback;
    p_ctrl->p_context         = p_extend->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Enable EXDMAC Operation. */
    R_BSP_MODULE_START(FSP_IP_EXDMAC, p_extend->channel);

    R_EXDMA->EDMAST = 1;

#if BSP_FEATURE_EXDMAC_HAS_EDMCTL
    R_EXDMA->EDMCTL = EXDMAC_CFG_PRIORITY_MODE << R_EXDMA_EDMCTL_PR_Pos;
#endif

    /* Configure the transfer settings. */
    r_exdmac_config_transfer_info(p_ctrl, p_cfg->p_info);

    /* Mark driver as open by initializing "EXDMAC" in its ASCII equivalent.*/
    p_ctrl->open = EXDMAC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reconfigure the transfer with new transfer info.
 *
 * @retval FSP_SUCCESS              Transfer is configured and will start when trigger occurs.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_ENABLED      EXDMAC is not enabled. The current configuration must not be valid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_Reconfigure (transfer_ctrl_t * const p_api_ctrl, transfer_info_t * p_info)
{
    fsp_err_t                err;
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;

#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
    err = r_exdmac_reconfigure_parameter_checking(p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Reconfigure the transfer settings. */
    r_exdmac_config_transfer_info(p_ctrl, p_info);

    /* Enable the transfer configuration. */
    err = r_exdmac_prv_enable(p_api_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_NOT_ENABLED);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reset transfer source, destination, and number of transfers.
 *
 * @retval FSP_SUCCESS              Transfer reset successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_ENABLED      EXDMAC is not enabled. The current configuration must not be valid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_Reset (transfer_ctrl_t * const p_api_ctrl,
                          void const * volatile   p_src,
                          void * volatile         p_dest,
                          uint16_t const          num_transfers)
{
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t                err    = FSP_SUCCESS;
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
#endif

    /* Disable transfers if they are currently enabled. */
    r_exdmac_prv_disable(p_ctrl);

    if (NULL != p_src)
    {
        /* Configure the EXDMAC source pointer if it is provided. */
        p_ctrl->p_reg->EDMSAR = (uint32_t) p_src;
    }

    if (NULL != p_dest)
    {
        /* Configure the EXDMAC destination pointer if it is provided. */
        p_ctrl->p_reg->EDMDAR = (uint32_t) p_dest;
    }

    if ((TRANSFER_MODE_NORMAL != (transfer_mode_t) p_ctrl->p_reg->EDMTMD_b.MD))
    {
        /* Reset the block/repeat count if it is not normal mode. */
        p_ctrl->p_reg->EDMCRB = num_transfers;
    }
    else
    {
        /* Reset the transfer count if it is normal mode. */
        p_ctrl->p_reg->EDMCRA = num_transfers;
    }

    /* Enable the transfer configuration. */
    err = r_exdmac_prv_enable(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_NOT_ENABLED);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * If the mode is TRANSFER_START_MODE_SINGLE initiate a single transfer with software. If the mode is
 * TRANSFER_START_MODE_REPEAT continue triggering transfers until all of the transfers are completed.
 *
 * @retval FSP_SUCCESS              Transfer started written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 * @retval FSP_ERR_UNSUPPORTED      Handle was not configured for software activation.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_SoftwareStart (transfer_ctrl_t * const p_api_ctrl, transfer_start_mode_t mode)
{
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);

    exdmac_extended_cfg_t * p_extend = (exdmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    FSP_ERROR_RETURN(EXDMAC_SOFTWARE_TRIGGER == p_extend->irq_activation_source, FSP_ERR_UNSUPPORTED);
#endif

    /* Set auto clear bit and software start bit. */
    p_ctrl->p_reg->EDMREQ =
        (uint8_t) (((uint32_t) mode << EXDMAC_PRV_EDMREQ_CLRS_OFFSET) | EXDMAC_PRV_EDMREQ_SWREQ_MASK);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop software transfers if they were started with TRANSFER_START_MODE_REPEAT.
 *
 * @retval FSP_SUCCESS              Transfer stopped written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_SoftwareStop (transfer_ctrl_t * const p_api_ctrl)
{
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
#endif

    /* Reset auto clear bit and clear software start bit. */
    p_ctrl->p_reg->EDMREQ = 0;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable transfers for the configured activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_Enable (transfer_ctrl_t * const p_api_ctrl)
{
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
#endif

    return r_exdmac_prv_enable(p_ctrl);
}

/*******************************************************************************************************************//**
 * Disable transfers so that they are no longer triggered by the activation source.
 *
 * @retval FSP_SUCCESS              Counter value written successfully.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_Disable (transfer_ctrl_t * const p_api_ctrl)
{
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
#endif

    r_exdmac_prv_disable(p_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set driver specific information in provided pointer.
 *
 * @retval FSP_SUCCESS              Information has been written to p_info.
 * @retval FSP_ERR_NOT_OPEN         Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 * @retval FSP_ERR_ASSERTION        An input parameter is invalid.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_InfoGet (transfer_ctrl_t * const p_api_ctrl, transfer_properties_t * const p_info)
{
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_info);
#endif

    p_info->transfer_length_max = EXDMAC_MAX_BLOCK_TRANSFER_LENGTH;
    p_info->block_count_max     = EXDMAC_MAX_BLOCK_COUNT;

    transfer_mode_t mode = (transfer_mode_t) p_ctrl->p_reg->EDMTMD_b.MD;

    p_info->block_count_remaining     = p_ctrl->p_reg->EDMCRB;
    p_info->transfer_length_remaining = p_ctrl->p_reg->EDMCRA_b.EDMCRAL;

    if (TRANSFER_MODE_NORMAL == mode)
    {
        p_info->transfer_length_max = EXDMAC_MAX_NORMAL_TRANSFER_LENGTH;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * To update next transfer information without interruption during transfer.
 *
 * @retval FSP_ERR_UNSUPPORTED        This feature is not supported.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_Reload (transfer_ctrl_t * const p_api_ctrl,
                           void const            * p_src,
                           void                  * p_dest,
                           uint32_t const          num_transfers)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(num_transfers);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_CallbackSet (transfer_ctrl_t * const        p_api_ctrl,
                                void (                       * p_callback)(exdmac_callback_args_t *),
                                void * const                   p_context,
                                exdmac_callback_args_t * const p_callback_memory)
{
    FSP_PARAMETER_NOT_USED(p_callback_memory);

    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;

#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
#endif

    p_ctrl->p_callback = p_callback;
    p_ctrl->p_context  = p_context;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfer and clean up internal data. Implements @ref transfer_api_t::close.
 *
 * @retval FSP_SUCCESS           Successful close.
 * @retval FSP_ERR_ASSERTION     An input parameter is invalid.
 * @retval FSP_ERR_NOT_OPEN      Handle is not initialized.  Call R_EXDMAC_Open to initialize the control block.
 **********************************************************************************************************************/
fsp_err_t R_EXDMAC_Close (transfer_ctrl_t * const p_api_ctrl)
{
    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) p_api_ctrl;
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == EXDMAC_OPEN, FSP_ERR_NOT_OPEN);
#endif

    exdmac_extended_cfg_t * p_extend = (exdmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    /* Disable EXDMAC transfers on this channel. */
    R_ICU->SELEXDR[p_extend->channel].SELEXDR = 0U;

    p_ctrl->p_reg->EDMCNT = 0;

    if (NULL != p_extend->p_callback)
    {
        R_BSP_IrqDisable(p_extend->irq);
        R_FSP_IsrContextSet(p_extend->irq, NULL);
    }

    /* Clear ID so control block can be reused. */
    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup EXDMAC)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable transfers for the channel.
 *
 * @param[in]  p_ctrl             Pointer to control structure.
 *
 * @retval     FSP_SUCCESS        Successful close.
 * @retval     FSP_ERR_ASSERTION  An input parameter is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_exdmac_prv_enable (exdmac_instance_ctrl_t * p_ctrl)
{
#if EXDMAC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_exdmac_enable_parameter_checking(p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /** Enable transfer. */
    p_ctrl->p_reg->EDMCNT = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable transfers for the channel.
 *
 * @param      p_ctrl          Pointer to the control structure
 **********************************************************************************************************************/
static void r_exdmac_prv_disable (exdmac_instance_ctrl_t * p_ctrl)
{
    exdmac_extended_cfg_t * p_extend = (exdmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    R_ICU->SELEXDR[p_extend->channel].SELEXDR = 0U;
    p_ctrl->p_reg->EDMCNT = 0;

    /* Configure EXDMAC activation source  */
    if (EXDMAC_SOFTWARE_TRIGGER != p_extend->irq_activation_source)
    {
        /* Convert activation source into raw vector number */
        uint8_t  activation  = (uint8_t) p_extend->irq_activation_source;
        uint16_t sli_value   = 0U;
        uint8_t  slirq_value = 0U;

        /* IRQ0–IRQ15: External pin interrupts (fixed interrupt) */
        if ((activation >= EXDMAC_PRV_IRQ0_VECTOR_NUMBER) && (activation <= EXDMAC_PRV_IRQ15_VECTOR_NUMBER))
        {
            sli_value   = (uint16_t) EXDMAC_PRV_EXTERNAL_PINS_INTERRUPT;
            slirq_value = (uint8_t) (activation - EXDMAC_PRV_IRQ0_VECTOR_NUMBER);
        }
        else
        {
            if ((uint32_t) g_interrupt_event_link_select[activation - EXDMAC_PRV_SOFTWARE_CONFIG_VECTOR_NUMBER] ==
                (uint32_t) EXDMAC_PRV_EXTERNAL_PINS_INTERRUPT)
            {
                /* IRQ16–IRQ31: External pin interrupts (Sharing vectors with software-configurable interrupt) */
                sli_value   = (uint16_t) EXDMAC_PRV_EXTERNAL_PINS_INTERRUPT;
                slirq_value = (uint8_t) (activation - EXDMAC_PRV_IRQ16_31_SLIRQ);
            }
            else
            {
                /* Software-configurable interrupts */
                sli_value =
                    (uint16_t) ((uint32_t) g_interrupt_event_link_select[activation -
                                                                         EXDMAC_PRV_SOFTWARE_CONFIG_VECTOR_NUMBER]);
            }
        }

        /* Configure SLI and SLIRQ bits */
        uint32_t selexdr_value = ((uint32_t) (sli_value & EXDMAC_PRV_SELEXDR_SLI_MASK)) |
                                 (((uint32_t) slirq_value << R_ICU_SELEXDR_SLIRQ_Pos) & R_ICU_SELEXDR_SLIRQ_Msk);

        /* Write EXDMAC trigger select register */
        R_ICU->SELEXDR[p_extend->channel].SELEXDR = selexdr_value;
    }

    /* Disable software start. */
    p_ctrl->p_reg->EDMREQ = 0;
}

/*******************************************************************************************************************//**
 * Write the transfer info to the hardware registers.
 *
 * @param[in]   p_ctrl         Pointer to control structure.
 * @param       p_info         Pointer to transfer info.
 **********************************************************************************************************************/
static void r_exdmac_config_transfer_info (exdmac_instance_ctrl_t * p_ctrl, transfer_info_t * p_info)
{
    exdmac_extended_cfg_t * p_extend = (exdmac_extended_cfg_t *) p_ctrl->p_cfg->p_extend;

    uint32_t edmcra = 0;
    uint32_t edmcrb = 0;
    uint32_t edmtmd = 0;
    uint32_t edmint = 0;
    uint32_t edmamd = 0;

    /* Disable transfers if they are currently enabled. */
    r_exdmac_prv_disable(p_ctrl);

    /* Configure the Transfer Data Size (1,2,4) bytes. */
    edmtmd |= (uint32_t) (p_info->transfer_settings_u.transfer_settings_word_b.size << EXDMAC_PRV_EDMTMD_SZ_OFFSET);

    /* Configure source and destination address mode. */
    edmamd |=
        (uint32_t) (p_info->transfer_settings_u.transfer_settings_word_b.src_addr_mode << EXDMAC_PRV_EDMAMD_SM_OFFSET);
    edmamd |=
        (uint32_t) (p_info->transfer_settings_u.transfer_settings_word_b.dest_addr_mode << EXDMAC_PRV_EDMAMD_DM_OFFSET);

    /* Configure the transfer mode. */
    edmtmd |= (uint32_t) p_info->transfer_settings_u.transfer_settings_word_b.mode << EXDMAC_PRV_EDMTMD_MD_OFFSET;

    /* Configure the transfer count. */
    edmcra = p_info->length;

    if ((TRANSFER_MODE_BLOCK == p_info->transfer_settings_u.transfer_settings_word_b.mode) ||
        (TRANSFER_MODE_REPEAT == p_info->transfer_settings_u.transfer_settings_word_b.mode) ||
        (TRANSFER_MODE_REPEAT_BLOCK == p_info->transfer_settings_u.transfer_settings_word_b.mode))
    {
        /* Configure the reload count. */
        edmcra |= edmcra << EXDMAC_PRV_EDMCRA_HIGH_OFFSET;
        edmcra &= (EXDMAC_PRV_EDMCRA_HIGH_MASK | EXDMAC_PRV_EDMCRA_LOW_MASK);

        /* Configure the block count. */
        edmcrb = p_info->num_blocks;

        if ((TRANSFER_MODE_BLOCK == p_info->transfer_settings_u.transfer_settings_word_b.mode) ||
            (TRANSFER_MODE_REPEAT == p_info->transfer_settings_u.transfer_settings_word_b.mode))
        {
            /* Configure the repeat area */
            edmtmd |=
                (uint32_t) (p_info->transfer_settings_u.transfer_settings_word_b.repeat_area <<
                            EXDMAC_PRV_EDMTMD_DTS_OFFSET);
        }
    }
    else                               /* TRANSFER_MODE_NORMAL */
    {
        /* Configure no repeat area. */
        edmtmd |= 2U << EXDMAC_PRV_EDMTMD_DTS_OFFSET;
    }

    if (EXDMAC_SOFTWARE_TRIGGER != p_extend->irq_activation_source)
    {
        /* EXDMAC will be triggered by interrupts (ELC Events). */
        edmtmd |= 1U << EXDMAC_PRV_EDMTMD_DCTG_OFFSET;
    }

    if (NULL != p_ctrl->p_callback)
    {
        /* Enable transfer end interrupt requests. */
        edmint |= EXDMAC_PRV_EDMINT_DTIE_MASK;

        /* Enable the transfer end escape interrupt requests.
         * Repeat size end and Extended Repeat area overflow requests are not
         * used with Repeat-Block mode. Reference "EDMINT : EXDMA Interrupt Setting Register"
         * of the relevant hardware manual. */
        if ((TRANSFER_IRQ_EACH == p_info->transfer_settings_u.transfer_settings_word_b.irq) &&
            (TRANSFER_MODE_REPEAT_BLOCK != p_info->transfer_settings_u.transfer_settings_word_b.mode))
        {
            /* Enable the transfer end escape interrupt requests
             * (Repeat size end and Extended Repeat area overflow requests). */
            edmint |= (EXDMAC_PRV_EDMINT_RPTIE_MASK | EXDMAC_PRV_EDMINT_ESIE_MASK);
        }

        /* Enable the IRQ according to EXDMAC channels */
        R_BSP_IrqCfgEnable(p_extend->irq, (uint32_t) p_extend->ipl, p_ctrl);
    }

#if BSP_FEATURE_EXDMAC_HAS_REPEAT_BLOCK_MODE
    uint32_t edmsbs = 0;
    uint32_t edmdbs = 0;

    if (TRANSFER_MODE_REPEAT_BLOCK == p_info->transfer_settings_u.transfer_settings_word_b.mode)
    {
        uint16_t num_of_blocks = p_info->num_blocks;
        uint16_t size_of_block;
        size_of_block = p_info->length;
        uint16_t src_buffer_size;
        uint16_t dest_buffer_size;
        if (TRANSFER_ADDR_MODE_OFFSET == p_info->transfer_settings_u.transfer_settings_word_b.src_addr_mode)
        {
            src_buffer_size = num_of_blocks;
            edmamd         |= R_EXDMAC0_EDMAMD_SADR_Msk;
        }
        else
        {
            src_buffer_size = p_extend->src_buffer_size;
        }

        if (TRANSFER_ADDR_MODE_OFFSET == p_info->transfer_settings_u.transfer_settings_word_b.dest_addr_mode)
        {
            dest_buffer_size = num_of_blocks;
            edmamd          |= R_EXDMAC0_EDMAMD_DADR_Msk;
        }
        else
        {
            dest_buffer_size = (uint16_t) (num_of_blocks * size_of_block);
        }

        edmsbs  = src_buffer_size;
        edmsbs |= edmsbs << R_EXDMAC0_EDMSBS_EDMSBSH_Pos;

        edmdbs  = dest_buffer_size;
        edmdbs |= edmdbs << R_EXDMAC0_EDMDBS_EDMDBSH_Pos;

        p_ctrl->p_reg->EDMSRR = (uint32_t) p_info->p_src;
        p_ctrl->p_reg->EDMDRR = (uint32_t) p_info->p_dest;
    }

    p_ctrl->p_reg->EDMSBS = edmsbs;
    p_ctrl->p_reg->EDMDBS = edmdbs;
#endif

    /* Write register settings. */
    p_ctrl->p_reg->EDMAMD = (uint16_t) edmamd;
    p_ctrl->p_reg->EDMTMD = (uint16_t) edmtmd;
    p_ctrl->p_reg->EDMSAR = (uint32_t) p_info->p_src;
    p_ctrl->p_reg->EDMDAR = (uint32_t) p_info->p_dest;
    p_ctrl->p_reg->EDMCRA = edmcra;
    p_ctrl->p_reg->EDMCRB = (uint16_t) edmcrb;
    p_ctrl->p_reg->EDMOFR = (uint32_t) p_extend->offset;
    p_ctrl->p_reg->EDMINT = (uint8_t) edmint;

    if (EXDMAC_SOFTWARE_TRIGGER != p_extend->irq_activation_source)
    {
        p_ctrl->p_reg->EDMPRF = 1;
    }
}

#if EXDMAC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking of R_EXDMAC_Open.
 *
 * @param[in]   p_ctrl                    Pointer to control structure.
 * @param[in]   p_cfg                     Pointer to configuration structure. All elements of the structure must be
 *                                        set by user.
 *
 * @retval FSP_SUCCESS                    Input Parameters are Valid.
 * @retval FSP_ERR_ASSERTION              An input parameter is invalid.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The configured channel is invalid.
 * @retval FSP_ERR_IRQ_BSP_DISABLED       Callback is NULL and the EXDMAC IRQ is not enabled.
 * @retval FSP_ERR_ALREADY_OPEN           The control structure is already opened.
 **********************************************************************************************************************/
static fsp_err_t r_exdma_open_parameter_checking (exdmac_instance_ctrl_t * const p_ctrl,
                                                  transfer_cfg_t const * const   p_cfg)
{
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open != EXDMAC_OPEN, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    exdmac_extended_cfg_t * p_extend = (exdmac_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(p_extend->channel < BSP_FEATURE_EXDMAC_MAX_CHANNEL, FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    if (NULL != p_extend->p_callback)
    {
        FSP_ERROR_RETURN(p_extend->irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    fsp_err_t err = r_exdmac_reconfigure_parameter_checking(p_cfg->p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Checks for errors in the transfer into structure.
 *
 * @param[in]   p_info              Pointer transfer info.
 *
 * @retval FSP_SUCCESS              The transfer info is valid.
 * @retval FSP_ERR_ASSERTION        A transfer info setting is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_exdmac_reconfigure_parameter_checking (transfer_info_t const * const p_info)
{
    FSP_ASSERT(p_info != NULL);

    if (TRANSFER_MODE_NORMAL != p_info->transfer_settings_u.transfer_settings_word_b.mode)
    {
        FSP_ASSERT(p_info->length <= EXDMAC_REPEAT_BLOCK_MAX_LENGTH);
    }

    FSP_ASSERT((TRANSFER_MODE_REPEAT_BLOCK != p_info->transfer_settings_u.transfer_settings_word_b.mode) ||
               (TRANSFER_IRQ_EACH != p_info->transfer_settings_u.transfer_settings_word_b.irq));

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Parameter checking for r_exdmac_prv_enable.
 *
 * @param[in]   p_ctrl                 Pointer to control structure.
 *
 * @retval      FSP_SUCCESS            Alignment on source and destination pointers is valid.
 * @retval      FSP_ERR_ASSERTION      The current configuration is invalid.
 **********************************************************************************************************************/
static fsp_err_t r_exdmac_enable_parameter_checking (exdmac_instance_ctrl_t * const p_ctrl)
{
    void const    * p_src  = (void const *) (uintptr_t) p_ctrl->p_reg->EDMSAR;
    void const    * p_dest = (void const *) (uintptr_t) p_ctrl->p_reg->EDMDAR;
    transfer_size_t size   = (transfer_size_t) p_ctrl->p_reg->EDMTMD_b.SZ;
    transfer_mode_t mode   = (transfer_mode_t) p_ctrl->p_reg->EDMTMD_b.MD;

    /* The source and destination pointers cannot be NULL. */
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);

    /* The source and destination pointers must be aligned to the transfer size. */
    FSP_ASSERT(0U == ((uint32_t) p_dest & EXDMAC_PRV_MASK_ALIGN_N_BYTES(size)));
    FSP_ASSERT(0U == ((uint32_t) p_src & EXDMAC_PRV_MASK_ALIGN_N_BYTES(size)));

    if (TRANSFER_MODE_NORMAL == mode)
    {
        /* Setting transfer count to 0 in normal mode means transfer forever. This feature is not supported. */
        FSP_ASSERT(0 != p_ctrl->p_reg->EDMCRA);
    }

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * EXDMAC ISR
 **********************************************************************************************************************/
void exdmac_int_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    exdmac_instance_ctrl_t * p_ctrl = (exdmac_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Call the callback routine if one is available */
    exdmac_callback_args_t args;
    args.p_context = p_ctrl->p_context;

    /* Call user callback */
    p_ctrl->p_callback(&args);

    /* Transfers are disabled during the interrupt if an interrupt is requested after each block or after each repeat
     * length. If not all transfers are complete, reenable transfer here. See Transfer End by Repeat
     * Size End Interrupt in the relevant hardware manual. */
    if (p_ctrl->p_reg->EDMCRB > 0U)
    {
        p_ctrl->p_reg->EDMCNT = 1;
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
