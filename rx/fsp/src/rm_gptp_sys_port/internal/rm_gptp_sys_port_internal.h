/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_GPTP_SYS_PORT_INTERNAL_H
#define RM_GPTP_SYS_PORT_INTERNAL_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "bsp_api.h"

#if (2 == BSP_CFG_RTOS)
 #include "FreeRTOS.h"
 #include "task.h"
 #include "timers.h"
 #include "queue.h"
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if (2 != BSP_CFG_RTOS)
 #ifndef pdPASS
  #define pdPASS               (1)
 #endif

 #ifndef pdTRUE
  #define pdTRUE               (1)
 #endif

 #ifndef pdFALSE
  #define pdFALSE              (0)
 #endif

 #ifndef pdFAIL
  #define pdFAIL               (0)
 #endif

 #define portTICK_PERIOD_MS    (1)
 #define portMAX_DELAY         (1)

 #define TimerHandle_t         gptpTimerHandle_t
 #define TaskHandle_t          gptpTimerHandle_t
 #define QueueHandle_t         gptpQueue_t

 #define xTimerCreate(name, period, reload, id, callback)    gptp_timer_create(period, reload, id, callback)
 #define xTimerDelete(handle, block)                         gptp_timer_delete(handle)
 #define xTimerStart(handle, block)                          gptp_timer_start(handle)
 #define xTimerReset(handle, block)                          gptp_timer_start(handle)
 #define xTimerStop(handle, block)                           gptp_timer_stop(handle)
 #define xTimerChangePeriod(handle, period, block)           gptp_timer_change_period(handle, period)
 #define xTimerIsTimerActive(handle)                         gptp_timer_is_active(handle)
 #define pvTimerGetTimerID(handle)                           gptp_timer_get_timer_id(handle)
 #define xTimerGetPeriod(handle)                             gptp_timer_get_period(handle)

 #define xTaskGetTickCount    gptp_get_tick_cnt
 #define vTaskDelay(wait_ms)                                 gptp_delay_ms(wait_ms)

 #define xQueueCreate(queue_length, item_size)               gptp_queue_create(queue_length, item_size)
 #define xQueueSend(handle, item, block)                     gptp_queue_send(handle, item)
 #define xQueueReceive(handle, buffer, block)                gptp_queue_receive(handle, buffer)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct gptpTimerControl * gptpTimerHandle_t;
typedef struct gptpQueueControl * gptpQueue_t;
typedef void                   (* gptpTimerCallbackFunction_t)(gptpTimerHandle_t xTimer);

typedef uint32_t TickType_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/
extern gptpTimerHandle_t gptp_timer_create(const uint32_t              timer_period,
                                           const bool                  auto_reload,
                                           void * const                timer_id,
                                           gptpTimerCallbackFunction_t p_callback_function);
extern uint32_t gptp_timer_is_active(gptpTimerHandle_t timer_handler);
extern uint32_t gptp_timer_start(gptpTimerHandle_t timer_handler);
extern uint32_t gptp_timer_stop(gptpTimerHandle_t timer_handler);
extern uint32_t gptp_timer_change_period(gptpTimerHandle_t timer_handler, uint32_t new_priod);
extern uint32_t gptp_timer_delete(gptpTimerHandle_t timer_handler);
extern void   * gptp_timer_get_timer_id(gptpTimerHandle_t timer_handler);
extern uint32_t gptp_timer_get_period(gptpTimerHandle_t timer_handler);
extern int32_t  gptp_get_tick_count(void);
extern void     gptp_delay_ms(uint32_t wait_ms);
extern uint8_t  gptp_detect_count(void);
extern void     gptp_timer_check(void);

extern gptpQueue_t gptp_queue_create(uint32_t queue_length, uint32_t item_size);
extern uint32_t    gptp_queue_send(gptpQueue_t gptp_queue, const void * item);
extern uint32_t    gptp_queue_receive(gptpQueue_t gptp_queue, void * buffer);

#endif                                 /* 2 != BSP_CFG_RTOS */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* RM_GPTP_SYS_PORT_INTERNAL_H */
