/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rm_emwin_rx_port_cfg.h"
#include "bsp_api.h"
#include "GUI.h"

/*******************************************************************************************************************//**
 * @addtogroup RM_EMWIN_RX_PORT
 * @{
 **********************************************************************************************************************/

#define RM_EMWIN_RX_PORT_MS_PER_SECOND    (1000U)

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
#if (EMWIN_CFG_RTOS == 0)              /* Bare-metal */
static volatile GUI_TIMER_TIME g_gui_time_ms;
#endif

#if (EMWIN_CFG_RTOS == 2)              /* FreeRTOS */

 #include "FreeRTOS.h"
 #include "semphr.h"
 #include "task.h"

static SemaphoreHandle_t g_gui_mutex;

void GUI_X_InitOS (void)
{
    g_gui_mutex = xSemaphoreCreateRecursiveMutex();
}

void GUI_X_Unlock (void)
{
    xSemaphoreGiveRecursive(g_gui_mutex);
}

void GUI_X_Lock (void)
{
    xSemaphoreTakeRecursive(g_gui_mutex, portMAX_DELAY);
}

U32 GUI_X_GetTaskId (void)
{
    return (U32) xTaskGetCurrentTaskHandle();
}

#elif (EMWIN_CFG_RTOS == 1)            /* ThreadX */

 #include "tx_api.h"

static TX_MUTEX g_gui_mutex;

void GUI_X_InitOS (void)
{
    tx_mutex_create(&g_gui_mutex, "emWin", TX_INHERIT);
}

void GUI_X_Unlock (void)
{
    tx_mutex_put(&g_gui_mutex);
}

void GUI_X_Lock (void)
{
    tx_mutex_get(&g_gui_mutex, TX_WAIT_FOREVER);
}

U32 GUI_X_GetTaskId (void)
{
    return (U32) tx_thread_identify();
}

#else                                  /* Bare-metal, no RTOS */

void GUI_X_InitOS (void)
{
}

void GUI_X_Unlock (void)
{
}

void GUI_X_Lock (void)
{
}

U32 GUI_X_GetTaskId (void)
{
    return 1U;
}

#endif                                 /* EMWIN_CFG_RTOS */

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

GUI_TIMER_TIME GUI_X_GetTime (void)
{
#if (EMWIN_CFG_RTOS == 2)              /* FreeRTOS */
    return (GUI_TIMER_TIME) (xTaskGetTickCount() * portTICK_PERIOD_MS);
#elif (EMWIN_CFG_RTOS == 1)            /* ThreadX */
    return (GUI_TIMER_TIME) ((tx_time_get() * RM_EMWIN_RX_PORT_MS_PER_SECOND) / TX_TIMER_TICKS_PER_SECOND);
#else                                  /* Bare-metal, no RTOS */
    return g_gui_time_ms;
#endif
}

void GUI_X_Delay (int period)
{
    if (period <= 0)
    {
        return;
    }

#if (EMWIN_CFG_RTOS == 2)              /* FreeRTOS */
    vTaskDelay(pdMS_TO_TICKS((uint32_t) period));
#elif (EMWIN_CFG_RTOS == 1)            /* ThreadX */
    tx_thread_sleep((ULONG) ((((uint32_t) period * TX_TIMER_TICKS_PER_SECOND) +
                              (RM_EMWIN_RX_PORT_MS_PER_SECOND - 1U)) / RM_EMWIN_RX_PORT_MS_PER_SECOND));
#else                                  /* Bare-metal, no RTOS */
    R_BSP_SoftwareDelay((uint32_t) period, BSP_DELAY_UNITS_MILLISECONDS);
    g_gui_time_ms += period;
#endif
}

void GUI_X_ExecIdle (void)
{
    GUI_X_Delay(1);
}

void GUI_X_Log (const char * s)
{
    GUI_USE_PARA(s);
}

void GUI_X_Warn (const char * s)
{
    GUI_USE_PARA(s);
}

void GUI_X_ErrorOut (const char * s)
{
    GUI_USE_PARA(s);
}

void GUI_X_Init (void)
{
#if (EMWIN_CFG_RTOS == 0)              /* Bare-metal */
    g_gui_time_ms = 0;
#endif
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_EMWIN_RX_PORT)
 **********************************************************************************************************************/
