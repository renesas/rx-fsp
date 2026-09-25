;/*
;* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
;*
;* SPDX-License-Identifier: BSD-3-Clause
;*/

.if __ASRX__ == 1

;/***********************************************************************************************************************
; * Includes   <System Includes> , "Project Includes"
; **********************************************************************************************************************/

;/***********************************************************************************************************************
; * Macro definitions
; **********************************************************************************************************************/
;
;/***********************************************************************************************************************
; * Typedef definitions
; **********************************************************************************************************************/

;/***********************************************************************************************************************
; * Public Functions
; **********************************************************************************************************************/
    .glb _pxCurrentTCB
    .glb _vTaskSwitchContext
    .glb _rm_freertos_port_start_first_task
    .glb _vStartFirstTaskISR
    .glb _vSwitchContextISR
    .glb _rm_freertos_port_restore_task_stackless
    .glb _vPortYield
    .glb _vPortSetInterruptPriority

    .if configENABLE_MPU == 1
        .glb _rm_freertos_port_is_privileged
        .glb _rm_freertos_port_reset_privileged
    .endif

    .glb _g_configMAX_SYSCALL_INTERRUPT_PRIORITY
    .glb _g_configKERNEL_INTERRUPT_PRIORITY

;/***********************************************************************************************************************
; * Section definitions
; **********************************************************************************************************************/

    .section .text,CODE

;/***********************************************************************************************************************
; * This interrupt is called to start the first task.
; **********************************************************************************************************************/
_vStartFirstTaskISR:
;    /* When starting the scheduler there is nothing that needs moving to the
;     * interrupt stack because the function is not called from an interrupt.
;     * Just ensure the current stack is the user stack. */
    SETPSW     U

;    /* Obtain the location of the stack associated with which ever task
;     * pxCurrentTCB is currently pointing to. */
    MOV.L      #_pxCurrentTCB, R15
    MOV.L      [R15], R15
    MOV.L      [R15], R0

;    /* Restore the task. This function does not return. */
    MOV.L      #_rm_freertos_port_restore_task_stackless, R5
    JMP        R5

;/***********************************************************************************************************************
; * Resets the FPU lazy stacking, configures the hardware stack monitor, enables interrupts, and requests an SVC
;  * interrupt. The first task is started in the SVC interrupt.
; **********************************************************************************************************************/
_rm_freertos_port_start_first_task:
;    /*Call handler for stack restore. The handler is registered in vector number 1 for unconditional trap only.*/
    INT #1
    RTS

;/***********************************************************************************************************************
; * This interrupt is called to execute a context switch.
; **********************************************************************************************************************/
_vSwitchContextISR:
;    /* Re-enable interrupts. */
    SETPSW     I

;    /* Move the data that was automatically pushed onto the interrupt stack when
;     * the interrupt occurred from the interrupt stack to the user stack.
;     *
;     * R15 is saved before it is clobbered. */
    PUSH.L     R15

;    /* Read the user stack pointer. */
    MVFC       USP, R15

;    /* Move the address down to the data being moved. */
    SUB        #12, R15
    MVTC       R15, USP

;    /* Copy the data across, R15, then PC, then PSW. */
    MOV.L      [ R0 ], [ R15 ]
    MOV.L      4[ R0 ], 4[ R15 ]
    MOV.L      8[ R0 ], 8[ R15 ]

;    /* Move the interrupt stack pointer to its new correct position. */
    ADD        #12, R0

;    /* All the rest of the registers are saved directly to the user stack. */
    SETPSW     U

;    /* Save the rest of the general registers (R15 has been saved already). */
    PUSHM      R1-R14

;    /* Save the FPSW and accumulators. */
    MVFC       FPSW, R15
    PUSH.L     R15
    MVFACGU    #0, A1, R15
    PUSH.L     R15
    MVFACHI    #0, A1, R15
    PUSH.L     R15
    MVFACLO    #0, A1, R15
    PUSH.L     R15
    MVFACGU    #0, A0, R15
    PUSH.L     R15
    MVFACHI    #0, A0, R15
    PUSH.L     R15
    MVFACLO    #0, A0, R15
    PUSH.L     R15

;    /* Save the stack pointer to the TCB. */
    MOV.L      #_pxCurrentTCB, R15
    MOV.L      [ R15 ], R15
    MOV.L      R0, [ R15 ]

;    /* Ensure the interrupt mask is set to the syscall priority while the kernel
;     * structures are being accessed. */
    MOV.L  #_g_configMAX_SYSCALL_INTERRUPT_PRIORITY, R4
    MVFC   PSW, R5
    SHLL   #24, R4
    AND    #-0F000001H, R5
    OR     R4, R5
    MVTC   R5, PSW

;    /* Select the next task to run. */
    MOV.L      #_vTaskSwitchContext, R1
    JSR	    R1

;    /* Reset the interrupt mask as no more data structure access is required. */
    MOV.L  #_g_configKERNEL_INTERRUPT_PRIORITY, R4
    MVFC   PSW, R5
    SHLL   #24, R4
    AND    #-0F000001H, R5
    OR     R4, R5
    MVTC   R5, PSW

;    /* Load the stack pointer of the task that is now selected as the Running
;     * state task from its TCB. */
    MOV.L      #_pxCurrentTCB,R15
    MOV.L      [ R15 ], R15
    MOV.L      [ R15 ], R0

;    /* Restore the task. This function does not return. */
    MOV.L      #_rm_freertos_port_restore_task_stackless, R5
    JMP        R5

;/***********************************************************************************************************************
; * Subroutine to restore a task.
; *
; * @note This function does not return to the calling function. It returns to the task being restored. Branch to this
; * function without link (B instruction, not BL).
; **********************************************************************************************************************/
_rm_freertos_port_restore_task_stackless:
    POP        R15

;    /* Accumulator low 32 bits. */
    MVTACLO    R15, A0
    POP        R15

;    /* Accumulator high 32 bits. */
    MVTACHI    R15, A0
    POP        R15

;    /* Accumulator guard. */
    MVTACGU    R15, A0
    POP        R15

;    /* Accumulator low 32 bits. */
    MVTACLO    R15, A1
    POP        R15

;    /* Accumulator high 32 bits. */
    MVTACHI    R15, A1
    POP        R15

;    /* Accumulator guard. */
    MVTACGU    R15, A1
    POP        R15

;    /* Floating point status word. */
    MVTC       R15, FPSW

;    /* R1 to R15 - R0 is not included as it is the SP. */
    POPM       R1-R15

;    /* This pops the remaining registers. */
    RTE
    NOP
    NOP

;/***********************************************************************************************************************
; * Yield equivalent to "*portITU_SWINTR = 0x01; ( void ) *portITU_SWINTR;"
; * where portITU_SWINTR is the location of the software interrupt register
; * (0x000872E0).  Don't rely on the assembler to select a register, so instead
; * save and restore clobbered registers manually.
; **********************************************************************************************************************/
_vPortYield:
    PUSH.L R10
    MOV.L  #870062E0H, R10
    MOV.B  #1, [R10]
    CMP    [R10].UB, R10
    POP    R10
    RTS

;/***********************************************************************************************************************
; * Set interrupts priority.
; **********************************************************************************************************************/
_vPortSetInterruptPriority:
    PUSH.L R5
    MVFC   PSW, R5
    SHLL   #24, R1
    AND    #-0F000001H, R5
    OR     R1, R5
    MVTC   R5, PSW
    POP    R5
    RTS

    .if configENABLE_MPU == 1
;/***********************************************************************************************************************
; * Check if the MCU is in privileged mode
; **********************************************************************************************************************/
_rm_freertos_port_is_privileged:
    MVFC   PSW, R1
    SHLR   #20, R1
    NOT    R1, R1
    RTS

;/***********************************************************************************************************************
; * Reset the MCU's privileged mode
; **********************************************************************************************************************/
_rm_freertos_port_reset_privileged:
    MVFC   PSW, R1
    AND    #-FF0FFFFFH, R1
    MVTC   R1, PSW
    POP    R1
    RTS

    .endif

    .endif

    .end
