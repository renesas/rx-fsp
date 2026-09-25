/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_doc_api.h"
#include "bsp_api.h"
#include "bsp_cfg.h"
#include "r_doc.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "DOCO" in ASCII, used to identify Data Operation Circuit (DOC) configuration */
#define DOC_OPEN    (0x444F434fU)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void doc_int_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/* DOC implementation of DOC Driver  */

const doc_api_t g_doc_on_doc =
{
    .open        = R_DOC_Open,
    .close       = R_DOC_Close,
    .read        = R_DOC_Read,
    .write       = R_DOC_Write,
    .callbackSet = R_DOC_CallbackSet,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup DOC
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Opens and configures the Data Operation Circuit (DOC) in comparison, addition or subtraction mode and sets
 * initial data for addition or subtraction, or reference data for comparison.
 *
 * Example:
 * @snippet r_doc_example.c R_DOC_Open
 *
 * @retval FSP_SUCCESS                  DOC successfully configured.
 * @retval FSP_ERR_ALREADY_OPEN         Module already open.
 * @retval FSP_ERR_ASSERTION            One or more pointers point to NULL or callback is NULL or the interrupt vector
 *                                      is invalid.
 *
 ***********************************************************************************************************************/
fsp_err_t R_DOC_Open (doc_ctrl_t * const p_api_ctrl, doc_cfg_t const * const p_cfg)
{
    doc_instance_ctrl_t * p_ctrl = (doc_instance_ctrl_t *) p_api_ctrl;

    /* Validate the parameters and check if the module is initialized */
#if DOC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(p_cfg->p_callback != NULL);
    FSP_ASSERT(p_cfg->irq >= (IRQn_Type) 0);
    FSP_ERROR_RETURN(DOC_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* save pointers for later use */
    p_ctrl->p_cfg             = p_cfg;
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Power on the DOC module. */
    R_BSP_MODULE_START(FSP_IP_DOC, 0);

#if BSP_FEATURE_DOC_VERSION == 1

    /* Clear the hardware status flag and Configure the DOC using DOCR register. */
    R_DOC->DOCR = (uint8_t) (R_DOC_DOCR_DOPCFCL_Msk | p_cfg->event);

    /* write initial data for comparison/ addition/subtraction to DODSR register */
    R_DOC->DODSR = (uint16_t) (p_ctrl->p_cfg->doc_data & UINT16_MAX);
#else

    /* Configure the DOC using DOCR register. */
    uint32_t docr = R_DOC_B_DOCR_OMS_Msk & p_cfg->event;
    docr         |= (uint32_t) (p_cfg->event << (R_DOC_B_DOCR_DCSEL_Pos - 2U)) & R_DOC_B_DOCR_DCSEL_Msk;
    docr         |= (uint32_t) (p_cfg->bit_width << R_DOC_B_DOCR_DOPSZ_Pos) & R_DOC_B_DOCR_DOPSZ_Msk;
    docr         |= R_DOC_B_DOCR_DOPCIE_Msk;
    R_DOC_B->DOCR = (uint8_t) (docr & UINT8_MAX);

    /* Clear the hardware status flag. */
    R_DOC_B->DOSCR = 1;

    /* write initial data for comparison/ addition/subtraction to DODSR0/DODSR1 registers. */
    R_DOC_B->DODSR0 = p_ctrl->p_cfg->doc_data;
    R_DOC_B->DODSR1 = p_ctrl->p_cfg->doc_data_extra;
#endif

    /* Set valid interrupt contexts and user provided priority. Enable the interrupt at the NVIC  */
    R_BSP_IrqCfgEnable(p_ctrl->p_cfg->irq, (uint32_t) p_cfg->ipl, p_ctrl);

    /* Mark driver as open by initializing it to "DOCO" in its ASCII equivalent. */
    p_ctrl->open = DOC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Closes the module driver. Enables module stop mode.
 *
 * @retval FSP_SUCCESS          Module successfully closed.
 * @retval FSP_ERR_NOT_OPEN     Driver not open.
 * @retval FSP_ERR_ASSERTION    Pointer pointing to NULL.
 *
 * @note This function will disable the DOC interrupt in the NVIC.
 **********************************************************************************************************************/
fsp_err_t R_DOC_Close (doc_ctrl_t * const p_api_ctrl)
{
    doc_instance_ctrl_t * p_ctrl = (doc_instance_ctrl_t *) p_api_ctrl;

    /* Validate the parameter and check if the module is initialized */
#if DOC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(DOC_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable the IRQ in the NVIC in case it has been left enabled. */
    if (p_ctrl->p_cfg->irq >= 0)
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->irq);
        R_FSP_IsrContextSet(p_ctrl->p_cfg->irq, NULL);
    }

    R_BSP_MODULE_STOP(FSP_IP_DOC, 0);

    /* Mark driver as closed.  */
    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Returns the result of addition/subtraction.
 *
 * Example:
 * @snippet r_doc_example.c R_DOC_Read
 *
 * @retval FSP_SUCCESS          Status successfully read.
 * @retval FSP_ERR_NOT_OPEN     Driver not open.
 * @retval FSP_ERR_ASSERTION    One or more pointers point to NULL.
 *
 **********************************************************************************************************************/
fsp_err_t R_DOC_Read (doc_ctrl_t * const p_api_ctrl, uint32_t * p_result)
{
    doc_instance_ctrl_t * p_ctrl = (doc_instance_ctrl_t *) p_api_ctrl;

    FSP_PARAMETER_NOT_USED(p_ctrl);

    /* Validate the parameters and check if the module is initialized */
#if DOC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_result);
    FSP_ERROR_RETURN(DOC_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Read the result of addition or subtraction operation from the register and store in the user supplied location */
#if BSP_FEATURE_DOC_VERSION == 1
    *p_result = R_DOC->DODSR;
#else
    *p_result = R_DOC_B->DODSR0;
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Writes to the DODIR - DOC Input Register.
 *
 * Example:
 * @snippet r_doc_example.c R_DOC_Write
 *
 * @retval FSP_SUCCESS          Values successfully written to the registers.
 * @retval FSP_ERR_NOT_OPEN     Driver not open.
 * @retval FSP_ERR_ASSERTION    One or more pointers point to NULL.
 *
 **********************************************************************************************************************/
fsp_err_t R_DOC_Write (doc_ctrl_t * const p_api_ctrl, uint32_t data)
{
    doc_instance_ctrl_t * p_ctrl = (doc_instance_ctrl_t *) p_api_ctrl;

    FSP_PARAMETER_NOT_USED(p_ctrl);

    /* Validate the parameters and check if the module is initialized */
#if DOC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(DOC_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Writes the user supplied data to the DODIR register for data operation in Comparison, Addition and subtraction modes */
#if BSP_FEATURE_DOC_VERSION == 1
    R_DOC->DODIR = (uint16_t) (data & UINT16_MAX);
#else
    R_DOC_B->DODIR = data;
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements doc_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DOC_CallbackSet (doc_ctrl_t * const          p_api_ctrl,
                             void (                    * p_callback)(doc_callback_args_t *),
                             void * const                p_context,
                             doc_callback_args_t * const p_callback_memory)
{
    doc_instance_ctrl_t * p_ctrl = (doc_instance_ctrl_t *) p_api_ctrl;

#if (DOC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(DOC_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup DOC)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * DOC ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls callback if one was provided in the open function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void doc_int_isr (void)
{
    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    doc_instance_ctrl_t * p_ctrl = (doc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Call callback */
    doc_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    doc_callback_args_t * p_args = p_ctrl->p_callback_memory;
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

    p_args->p_context = p_ctrl->p_context;

    p_ctrl->p_callback(p_args);

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }

    /* clear DOPCF flag */
#if BSP_FEATURE_DOC_VERSION == 1
    R_DOC->DOCR = (uint8_t) (R_DOC_DOCR_DOPCFCL_Msk | (p_ctrl->p_cfg->event));
#else
    R_DOC_B->DOSCR = 1;
#endif

    /* Clear the IR flag in the ICU */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE
}
