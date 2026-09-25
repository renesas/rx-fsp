/**************************************************************************/

/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   Port Specific                                                       */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  PORT SPECIFIC C INFORMATION                            RELEASE        */
/*                                                                        */
/*    tx_port.h                                         RXv3/             */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file contains data type definitions that make the ThreadX      */
/*    real-time kernel function identically on a variety of different     */
/*    processor architectures.  For example, the size or number of bits   */
/*    in an "int" data type vary between microprocessor architectures and */
/*    even C compilers for the same microprocessor.  ThreadX does not     */
/*    directly use native C data types.  Instead, ThreadX creates its     */
/*    own special types that can be mapped to actual data types by this   */
/*    file to guarantee consistency in the interface and functionality.   */
/*                                                                        */
/**************************************************************************/

#ifndef TX_PORT_H
 #define TX_PORT_H

 #include "tx_port_vendor.h"

/* Determine if the optional ThreadX user define file should be used.  */
 #ifdef TX_INCLUDE_USER_DEFINE_FILE

/* Yes, include the user defines in tx_user.h. The defines in this file may
 * alternately be defined on the command line.  */

  #include "tx_user.h"
 #endif

/* Define compiler library include files.  */

 #include <string.h>
 #if defined(__ICCRX__)
  #include <intrinsics.h>
 #endif

 #include "bsp_api.h"

 #ifdef __cplusplus
extern "C" {
 #endif

/* Define ThreadX basic types for this port.  */

 #define VOID    void
typedef char               CHAR;
typedef unsigned char      UCHAR;
typedef int                INT;
typedef unsigned int       UINT;
typedef long               LONG;
typedef unsigned long      ULONG;
typedef unsigned long long ULONG64;
typedef short              SHORT;
typedef unsigned short     USHORT;

/* Define this so that the FileX port doesn't try to define ULONG64 as well. */
 #define ULONG64_DEFINED

 #if defined(TX_PORT_TRUSTZONE_NSC_ENABLE)

/* Function prototypes for this port. */
struct  TX_THREAD_STRUCT;
UINT _txe_thread_secure_stack_allocate(struct TX_THREAD_STRUCT * thread_ptr, ULONG stack_size);
UINT _txe_thread_secure_stack_free(struct TX_THREAD_STRUCT * thread_ptr);
UINT _tx_thread_secure_stack_allocate(struct TX_THREAD_STRUCT * thread_ptr, ULONG stack_size);
UINT _tx_thread_secure_stack_free(struct TX_THREAD_STRUCT * thread_ptr);

/* Define the system API mappings based on the error checking
 * selected by the user.  Note: this section is only applicable to
 * application source code, hence the conditional that turns off this
 * stuff when the include file is processed by the ThreadX source. */

  #ifndef TX_SOURCE_CODE

/* Determine if error checking is desired.  If so, map API functions
 * to the appropriate error checking front-ends.  Otherwise, map API
 * functions to the core functions that actually perform the work.
 * Note: error checking is enabled by default.  */

   #ifdef TX_DISABLE_ERROR_CHECKING

/* Services without error checking.  */

    #define tx_thread_secure_stack_allocate    _tx_thread_secure_stack_allocate
    #define tx_thread_secure_stack_free        _tx_thread_secure_stack_free

   #else

/* Services with error checking.  */

    #define tx_thread_secure_stack_allocate    _txe_thread_secure_stack_allocate
    #define tx_thread_secure_stack_free        _txe_thread_secure_stack_free

   #endif
  #endif

 #endif

/* Define the priority levels for ThreadX.  Legal values range
 * from 32 to 1024 and MUST be evenly divisible by 32.  */

 #ifndef TX_MAX_PRIORITIES
  #define TX_MAX_PRIORITIES    32
 #endif

/* Define the minimum stack for a ThreadX thread on this processor. If the size supplied during
 * thread creation is less than this value, the thread create call will return an error.  */

 #ifndef TX_MINIMUM_STACK
  #define TX_MINIMUM_STACK    200      /* Minimum stack size for this port  */
 #endif

/* Define the system timer thread's default stack size and priority.  These are only applicable
 * if TX_TIMER_PROCESS_IN_ISR is not defined.  */

 #ifndef TX_TIMER_THREAD_STACK_SIZE
  #define TX_TIMER_THREAD_STACK_SIZE    1024 /* Default timer thread stack size  */
 #endif

 #ifndef TX_TIMER_THREAD_PRIORITY
  #define TX_TIMER_THREAD_PRIORITY      0    /* Default timer thread priority    */
 #endif

/* Define various constants for the ThreadX RXv3 port.  */

/* TX_INT_DISABLE / TX_INT_ENABLE are passed to _tx_thread_interrupt_control() as new_posture.
 * The function returns the previous PSW (full 32-bit value), not a boolean.
 * Use the returned value only for save/restore (pass it back to interrupt_control); do not
 * compare it against TX_INT_DISABLE or TX_INT_ENABLE directly. */
 #define TX_INT_DISABLE    0x00000000  /* I-bit = 0 : interrupts disabled */
 #define TX_INT_ENABLE     0x00010000  /* I-bit = 1 : interrupts enabled  */

/* Define the clock source for trace event entry time stamp. The following two item are port specific.
 * For example, if the time source is at the address 0x0a800024 and is 16-bits in size, the clock
 * source constants would be:
 *
 #define TX_TRACE_TIME_SOURCE                    *((ULONG *) 0x0a800024)
 #define TX_TRACE_TIME_MASK                      0x0000FFFFUL
 *
 */

 #ifndef TX_TRACE_TIME_SOURCE
  #ifndef TX_NO_TIMER
extern uint32_t _tx_timer_module_counter_get(void);

   #define TX_TRACE_TIME_SOURCE    ((ULONG) _tx_timer_module_counter_get())
  #else
   #define TX_TRACE_TIME_SOURCE    ++_tx_trace_simulated_time
  #endif
 #endif
 #ifndef TX_TRACE_TIME_MASK

/* TX_TRACE_TIME_MASK is stored in the trace buffer header as metadata for the
 * trace analysis tool (e.g., TraceX) to identify valid timestamp bits.
 * Note that TX_TRACE_TIME_SOURCE is recorded directly without applying this mask,
 * so counter overflow does not corrupt trace data. A fixed value of 0x0000FFFFUL
 * is used here because overflow of the trace timestamp is acceptable. */
  #define TX_TRACE_TIME_MASK               0x0000FFFFUL
 #endif

/* Define the port specific options for the _tx_build_options variable. This variable indicates
 * how the ThreadX library was built.  */

 #define TX_PORT_SPECIFIC_BUILD_OPTIONS    (0)

/* Define the in-line initialization constant so that modules with in-line
 * initialization capabilities can prevent their initialization from being
 * a function call.  */

 #ifdef TX_MISRA_ENABLE
  #define TX_DISABLE_INLINE
 #else
  #define TX_INLINE_INITIALIZATION
 #endif

/* Determine whether or not stack checking is enabled. By default, ThreadX stack checking is
 * disabled. When the following is defined, ThreadX thread stack checking is enabled.  If stack
 * checking is enabled (TX_ENABLE_STACK_CHECKING is defined), the TX_DISABLE_STACK_FILLING
 * define is negated, thereby forcing the stack fill which is necessary for the stack checking
 * logic.  */

 #ifndef TX_MISRA_ENABLE
  #ifdef TX_ENABLE_STACK_CHECKING
   #undef TX_DISABLE_STACK_FILLING
  #endif
 #endif

/* Define the TX_THREAD control block extensions for this port. The main reason
 * for the multiple macros is so that backward compatibility can be maintained with
 * existing ThreadX kernel awareness modules.  */

 #ifndef TX_THREAD_EXTENSION_0
  #define TX_THREAD_EXTENSION_0
 #endif

 #ifndef TX_THREAD_EXTENSION_1
  #define TX_THREAD_EXTENSION_1
 #endif

 #ifndef TX_THREAD_EXTENSION_2

  #ifdef  TX_ENABLE_IAR_LIBRARY_SUPPORT

/* ThreadX in only one zone. */
   #define TX_THREAD_EXTENSION_2    VOID * tx_thread_iar_tls_pointer;
  #else
   #define TX_THREAD_EXTENSION_2
  #endif

 #endif

 #ifndef TX_THREAD_EXTENSION_3
  #ifndef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
   #define TX_THREAD_EXTENSION_3
  #else
   #define TX_THREAD_EXTENSION_3    unsigned long long tx_thread_execution_time_total; \
    unsigned long long tx_thread_execution_time_last_start;
  #endif
 #endif

/* Define the port extensions of the remaining ThreadX objects.  */

 #ifndef TX_BLOCK_POOL_EXTENSION
  #define TX_BLOCK_POOL_EXTENSION
 #endif
 #ifndef TX_BYTE_POOL_EXTENSION
  #define TX_BYTE_POOL_EXTENSION
 #endif
 #ifndef TX_EVENT_FLAGS_GROUP_EXTENSION
  #define TX_EVENT_FLAGS_GROUP_EXTENSION
 #endif
 #ifndef TX_MUTEX_EXTENSION
  #define TX_MUTEX_EXTENSION
 #endif
 #ifndef TX_QUEUE_EXTENSION
  #define TX_QUEUE_EXTENSION
 #endif
 #ifndef TX_SEMAPHORE_EXTENSION
  #define TX_SEMAPHORE_EXTENSION
 #endif
 #ifndef TX_TIMER_EXTENSION
  #define TX_TIMER_EXTENSION
 #endif

/* Define the user extension field of the thread control block.  Nothing
 * additional is needed for this port so it is defined as white space.  */

 #ifndef TX_THREAD_USER_EXTENSION
  #define TX_THREAD_USER_EXTENSION
 #endif

/* Define the macros for processing extensions in tx_thread_create, tx_thread_delete,
 * _tx_thread_shell_entry, and tx_thread_terminate. */
 #ifdef TX_ENABLE_IAR_LIBRARY_SUPPORT

/* IAR Library support functions (Prototype declarations) */
void * _tx_iar_create_per_thread_tls_area(void);
void   _tx_iar_destroy_per_thread_tls_area(void * tls_ptr);
void   __iar_Initlocks(void);

  #define TX_THREAD_CREATE_EXTENSION(thread_ptr) \
    thread_ptr->tx_thread_iar_tls_pointer = _tx_iar_create_per_thread_tls_area();

  #define TX_THREAD_DELETE_EXTENSION(thread_ptr)                                        \
    do {                                                                                \
        if (thread_ptr->tx_thread_iar_tls_pointer) {                                    \
            _tx_iar_destroy_per_thread_tls_area(thread_ptr->tx_thread_iar_tls_pointer); \
            thread_ptr->tx_thread_iar_tls_pointer = TX_NULL;                            \
        }                                                                               \
    } while (0);

  #define TX_PORT_SPECIFIC_PRE_SCHEDULER_INITIALIZATION    do {__iar_Initlocks();} while (0);

 #else

/* No IAR library support. */
  #define TX_THREAD_CREATE_EXTENSION(thread_ptr)
  #define TX_THREAD_DELETE_EXTENSION(thread_ptr)

 #endif

 #ifdef TX_PORT_TRUSTZONE_NSC_ENABLE

/* Define the size of the secure stack for the timer thread and use the extension to allocate the secure stack. */
  #define TX_TIMER_THREAD_SECURE_STACK_SIZE    256
  #define TX_TIMER_INITIALIZE_EXTENSION(status)    _tx_thread_secure_stack_allocate(&_tx_timer_thread, \
                                                                                    TX_TIMER_THREAD_SECURE_STACK_SIZE);
 #endif

 #if __FPU_USED

  #ifdef TX_MISRA_ENABLE

ULONG _tx_misra_control_get(void);
void  _tx_misra_control_set(ULONG value);
ULONG _tx_misra_fpccr_get(void);
void  _tx_misra_vfp_touch(void);

  #endif

/* A completed thread falls into _thread_shell_entry and we can simply deactivate the FPU via CONTROL.FPCA
 * in order to ensure no lazy stacking will occur. */

  #ifndef TX_MISRA_ENABLE

   #define TX_THREAD_COMPLETED_EXTENSION(thread_ptr)    { \
        ULONG _tx_vfp_state;                              \
        _tx_vfp_state = __get_CONTROL();                  \
        _tx_vfp_state = _tx_vfp_state & ~((ULONG) 0x4);   \
        __set_CONTROL(_tx_vfp_state);                     \
}
  #else

   #define TX_THREAD_COMPLETED_EXTENSION(thread_ptr)    { \
        ULONG _tx_vfp_state;                              \
        _tx_vfp_state = _tx_misra_control_get();          \
        _tx_vfp_state = _tx_vfp_state & ~((ULONG) 0x4);   \
        _tx_misra_control_set(_tx_vfp_state);             \
}

  #endif

/* A thread can be terminated by another thread, so we first check if it's self-terminating and not in an ISR.
 * If so, deactivate the FPU via CONTROL.FPCA. Otherwise we are in an interrupt or another thread is terminating
 * this one, so if the FPCCR.LSPACT bit is set, we need to save the CONTROL.FPCA state, touch the FPU to flush
 * the lazy FPU save, then restore the CONTROL.FPCA state. */

  #ifndef TX_MISRA_ENABLE

   #define TX_THREAD_TERMINATED_EXTENSION(thread_ptr)    {                                 \
        ULONG _tx_system_state;                                                            \
        _tx_system_state = TX_THREAD_GET_SYSTEM_STATE();                                   \
        if ((_tx_system_state == ((ULONG) 0)) && ((thread_ptr) == _tx_thread_current_ptr)) \
        {                                                                                  \
            ULONG _tx_vfp_state;                                                           \
            _tx_vfp_state = __get_CONTROL();                                               \
            _tx_vfp_state = _tx_vfp_state & ~((ULONG) 0x4);                                \
            __set_CONTROL(_tx_vfp_state);                                                  \
        }                                                                                  \
        else                                                                               \
        {                                                                                  \
            ULONG _tx_fpccr;                                                               \
            _tx_fpccr = *((ULONG *) 0xE000EF34);                                           \
            _tx_fpccr = _tx_fpccr & ((ULONG) 0x01);                                        \
            if (_tx_fpccr == ((ULONG) 0x01))                                               \
            {                                                                              \
                ULONG _tx_vfp_state;                                                       \
                _tx_vfp_state = __get_CONTROL();                                           \
                _tx_vfp_state = _tx_vfp_state & ((ULONG) 0x4);                             \
                __asm volatile ("vmov.f32 s0, s0");                                        \
                if (_tx_vfp_state == ((ULONG) 0))                                          \
                {                                                                          \
                    _tx_vfp_state = __get_CONTROL();                                       \
                    _tx_vfp_state = _tx_vfp_state & ~((ULONG) 0x4);                        \
                    __set_CONTROL(_tx_vfp_state);                                          \
                }                                                                          \
            }                                                                              \
        }                                                                                  \
}
  #else

   #define TX_THREAD_TERMINATED_EXTENSION(thread_ptr)    {                                 \
        ULONG _tx_system_state;                                                            \
        _tx_system_state = TX_THREAD_GET_SYSTEM_STATE();                                   \
        if ((_tx_system_state == ((ULONG) 0)) && ((thread_ptr) == _tx_thread_current_ptr)) \
        {                                                                                  \
            ULONG _tx_vfp_state;                                                           \
            _tx_vfp_state = _tx_misra_control_get();                                       \
            _tx_vfp_state = _tx_vfp_state & ~((ULONG) 0x4);                                \
            _tx_misra_control_set(_tx_vfp_state);                                          \
        }                                                                                  \
        else                                                                               \
        {                                                                                  \
            ULONG _tx_fpccr;                                                               \
            _tx_fpccr = _tx_misra_fpccr_get();                                             \
            _tx_fpccr = _tx_fpccr & ((ULONG) 0x01);                                        \
            if (_tx_fpccr == ((ULONG) 0x01))                                               \
            {                                                                              \
                ULONG _tx_vfp_state;                                                       \
                _tx_vfp_state = _tx_misra_control_get();                                   \
                _tx_vfp_state = _tx_vfp_state & ((ULONG) 0x4);                             \
                _tx_misra_vfp_touch();                                                     \
                if (_tx_vfp_state == ((ULONG) 0))                                          \
                {                                                                          \
                    _tx_vfp_state = _tx_misra_control_get();                               \
                    _tx_vfp_state = _tx_vfp_state & ~((ULONG) 0x4);                        \
                    _tx_misra_control_set(_tx_vfp_state);                                  \
                }                                                                          \
            }                                                                              \
        }                                                                                  \
}
  #endif

 #else

  #define TX_THREAD_COMPLETED_EXTENSION(thread_ptr)
  #define TX_THREAD_TERMINATED_EXTENSION(thread_ptr)

 #endif

/* Define the ThreadX object creation extensions for the remaining objects.  */

 #ifndef TX_BLOCK_POOL_CREATE_EXTENSION
  #define TX_BLOCK_POOL_CREATE_EXTENSION(pool_ptr)
 #endif
 #ifndef TX_BYTE_POOL_CREATE_EXTENSION
  #define TX_BYTE_POOL_CREATE_EXTENSION(pool_ptr)
 #endif
 #ifndef TX_EVENT_FLAGS_GROUP_CREATE_EXTENSION
  #define TX_EVENT_FLAGS_GROUP_CREATE_EXTENSION(group_ptr)
 #endif
 #ifndef TX_MUTEX_CREATE_EXTENSION
  #define TX_MUTEX_CREATE_EXTENSION(mutex_ptr)
 #endif
 #ifndef TX_QUEUE_CREATE_EXTENSION
  #define TX_QUEUE_CREATE_EXTENSION(queue_ptr)
 #endif
 #ifndef TX_SEMAPHORE_CREATE_EXTENSION
  #define TX_SEMAPHORE_CREATE_EXTENSION(semaphore_ptr)
 #endif
 #ifndef TX_TIMER_CREATE_EXTENSION
  #define TX_TIMER_CREATE_EXTENSION(timer_ptr)
 #endif

/* Define the ThreadX object deletion extensions for the remaining objects.  */

 #ifndef TX_BLOCK_POOL_DELETE_EXTENSION
  #define TX_BLOCK_POOL_DELETE_EXTENSION(pool_ptr)
 #endif
 #ifndef TX_BYTE_POOL_DELETE_EXTENSION
  #define TX_BYTE_POOL_DELETE_EXTENSION(pool_ptr)
 #endif
 #ifndef TX_EVENT_FLAGS_GROUP_DELETE_EXTENSION
  #define TX_EVENT_FLAGS_GROUP_DELETE_EXTENSION(group_ptr)
 #endif
 #ifndef TX_MUTEX_DELETE_EXTENSION
  #define TX_MUTEX_DELETE_EXTENSION(mutex_ptr)
 #endif
 #ifndef TX_QUEUE_DELETE_EXTENSION
  #define TX_QUEUE_DELETE_EXTENSION(queue_ptr)
 #endif
 #ifndef TX_SEMAPHORE_DELETE_EXTENSION
  #define TX_SEMAPHORE_DELETE_EXTENSION(semaphore_ptr)
 #endif
 #ifndef TX_TIMER_DELETE_EXTENSION
  #define TX_TIMER_DELETE_EXTENSION(timer_ptr)
 #endif

/* Define the get system state macro.
 * Hardware ISRs do not modify _tx_thread_system_state.
 * Only the SWINT context-save/restore path increments this variable.
 * Hardware ISRs are always at priority > SWINT, so context switches are deferred to SWINT
 * and _tx_thread_system_state correctly reflects whether a SWINT-driven context switch
 * is in progress. */

 #ifndef TX_THREAD_GET_SYSTEM_STATE
  #define TX_THREAD_GET_SYSTEM_STATE()    (_tx_thread_system_state)
 #endif

/* Define the macro to ensure _tx_thread_preempt_disable is set early in initialization in order to
 * prevent early scheduling on Cortex-M parts.  */

 #define TX_PORT_SPECIFIC_POST_INITIALIZATION

/* Determine if the ARM architecture has the CLZ instruction. This is available on
 * architectures v5 and above. If available, redefine the macro for calculating the
 * lowest bit set.  */

 #ifndef TX_DISABLE_INLINE
  #if defined(__GNUC__)
   #define TX_LOWEST_SET_BIT_CALCULATE(m, b)    (b) = (UINT) (__builtin_ctz((m)));
  #elif defined(__CCRX__) || defined(__ICCRX__)
static inline int ctz (uint32_t val)
{
    int i;
    for (i = 0; i < 32; i++)
    {
        if (val & (1u << i))
        {
            break;
        }
    }

    return i;
}

   #define TX_LOWEST_SET_BIT_CALCULATE(m, b)    (b) = (UINT) (ctz((m)));
  #endif
 #endif

 #ifndef TX_PORT_MAX_IPL
  #define TX_PORT_MAX_IPL    ((UINT) 15)
 #endif

/* Define ThreadX interrupt lockout and restore macros for protection on
 * access of critical kernel information.  The restore interrupt macro must
 * restore the interrupt posture of the running thread prior to the value
 * present prior to the disable macro.  In most cases, the save area macro
 * is used to define a local function save area for the disable and restore
 * macros.  */

 #ifndef TX_PORT_SWINTR_ADDR
  #define TX_PORT_SWINTR_ADDR    (0x870062E0u)
 #endif

/* TX_PORT_SWINT_NUMBER and TX_PORT_SWINT_PRIORITY are defined in tx_port_vendor.h. */
static inline void _tx_port_trigger_swintr (void)
{
    *((volatile unsigned char *) TX_PORT_SWINTR_ADDR) = 1u; /* SWINT start (SWINTR register) */
}

/* UINT   _tx_thread_interrupt_control(UINT new_posture); */

 #if defined(__CCRX__)
extern UINT _tx_thread_interrupt_disable(VOID);
extern VOID _tx_thread_interrupt_restore(UINT new_posture);

  #define TX_INTERRUPT_SAVE_AREA    unsigned int interrupt_save;

  #define TX_DISABLE                interrupt_save = _tx_thread_interrupt_disable();

  #define TX_RESTORE                _tx_thread_interrupt_restore(interrupt_save);

 #elif defined(__GNUC__) || defined(__ICCRX__)
  #ifdef TX_DISABLE_INLINE

UINT _tx_thread_interrupt_disable(VOID);
VOID _tx_thread_interrupt_restore(UINT previous_posture);

   #define TX_INTERRUPT_SAVE_AREA    register UINT interrupt_save;

   #define TX_DISABLE                interrupt_save = _tx_thread_interrupt_disable();

   #define TX_RESTORE                _tx_thread_interrupt_restore(interrupt_save);

  #else

   #define TX_INTERRUPT_SAVE_AREA    UCHAR interrupt_save;
   #define TX_DISABLE                {                             \
        UINT _psw_val;                                             \
        __GET_PSW(_psw_val);                                       \
        interrupt_save = (UCHAR) ((_psw_val & (1U << 16U)) != 0U); \
        __CLRPSW_I();                                              \
};
   #define TX_RESTORE                { \
        if (interrupt_save != 0U)      \
        {                              \
            __SETPSW_I();              \
        }                              \
};

  #endif
 #endif

 #ifndef TX_DISABLE_INLINE
  #define _tx_thread_system_return    _tx_thread_system_return_inline

static inline void _tx_thread_system_return_inline (void)
{
    TX_INTERRUPT_SAVE_AREA;

    TX_DISABLE;
    _tx_port_trigger_swintr();         /* raise SWINT (#27) */
    TX_RESTORE;
}

 #endif

/* Define the interrupt lockout macros for each ThreadX object.  */

 #define TX_BLOCK_POOL_DISABLE           TX_DISABLE
 #define TX_BYTE_POOL_DISABLE            TX_DISABLE
 #define TX_EVENT_FLAGS_GROUP_DISABLE    TX_DISABLE
 #define TX_MUTEX_DISABLE                TX_DISABLE
 #define TX_QUEUE_DISABLE                TX_DISABLE
 #define TX_SEMAPHORE_DISABLE            TX_DISABLE

/* Define prototypes specific to the ThreadX RXv3 implementation.  */

VOID tx_isr_start(ULONG isr_id);
VOID tx_isr_end(ULONG isr_id);

/* Define the version ID of ThreadX.  This may be utilized by the application.  */

 #ifdef TX_THREAD_INIT
CHAR _tx_version_id[] =
    "Copyright (c) Microsoft Corporation. All rights reserved.  *  ThreadX RXv3 Version 6.4.0 *";
 #else
extern CHAR _tx_version_id[];
 #endif

 #ifdef __cplusplus
}
 #endif

#endif
