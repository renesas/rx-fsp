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

;/***********************************************************************************************************************
; * Typedef definitions
; **********************************************************************************************************************/

;/***********************************************************************************************************************
; * Public Variables
; **********************************************************************************************************************/
    .glb __tx_thread_current_ptr
    .glb __tx_thread_execute_ptr
    .glb __tx_timer_time_slice
    .glb __tx_thread_system_state
    .glb __tx_thread_preempt_disable

;/***********************************************************************************************************************
; * Public Functions
; **********************************************************************************************************************/
    .glb __tx_get_fpsw
    .glb __tx_thread_interrupt_disable
    .glb __tx_thread_interrupt_restore
    .glb __tx_thread_schedule
    .glb _tx_software_interrupt_handler
    .glb __tx_thread_interrupt_control
    .glb __tx_thread_context_save
    .glb __tx_thread_context_restore

;/***********************************************************************************************************************
; * Section definitions
; **********************************************************************************************************************/

    .section .text,CODE

__tx_get_fpsw:
    MVFC    FPSW, R1 ; R1 = current FPSW.
    RTS              ; Return FPSW.

__tx_thread_interrupt_disable:
    MVFC    PSW, R1          ; R1 = current PSW.
    BTST    #16, R1          ; Check old I bit
	CLRPSW  I                ; Disable interrupts.
    BEQ     .Lint_off        ; If I was 0, already disabled.
    MOV.L   #1, R1           ; Return 1 (interrupts were enabled).
    RTS
.Lint_off:
    MOV.L   #0, R1           ; Return 0 (interrupts were disabled).
    RTS

__tx_thread_interrupt_restore:
    CMP     #0, R1           ; Check saved interrupt state.
    BEQ     .Lrestore_end    ; If 0, keep interrupts disabled.
    SETPSW  I                ; Re-enable interrupts.
.Lrestore_end:
    RTS

__tx_thread_schedule:
    MOV.L    #__tx_thread_execute_ptr, R1 ; R1 = &execute_ptr.

__tx_thread_schedule_loop:
    SETPSW I                              ; Enable interrupts briefly.
    CLRPSW I                              ; Disable interrupts.
    MOV.L    [R1],R2                      ; R2 = execute_ptr.
    CMP      #0,R2                        ; Thread ready?
    BNE      __tx_thread_thread_ready     ; Yes, schedule it.

.IF BSP_CFG_RTOS_IDLE_SLEEP==1
    WAIT                                  ; Enter idle sleep.
.ENDIF

    BRA      __tx_thread_schedule_loop    ; Loop until thread ready.

__tx_thread_thread_ready:
    MOV.L    #__tx_thread_current_ptr, R3 ; R3 = &current_ptr.
    MOV.L    R2,[R3]                      ; current_ptr = execute_ptr

    MOV.L    4[R2],R3                     ; Load run_count.
    ADD      #1,R3                        ; run_count++.
    MOV.L    R3,4[R2]                     ; Store run_count.

    MOV.L    24[R2],R3                    ; Load thread time_slice.
    MOV.L    #__tx_timer_time_slice,R4    ; R4 = &timer_time_slice.
    MOV.L    R3, [R4]                     ; Set global time slice.

    SETPSW U                              ; Switch to user stack.
    MOV.L   8[R2],R0                      ; SP = thread stack pointer.

    POPM    R1-R3                         ; Restore ACC0 registers.
    MVTACLO R3, A0
    MVTACHI R2, A0
    MVTACGU R1, A0
    POPM    R1-R3                         ; Restore ACC1 registers.
    MVTACLO R3, A1
    MVTACHI R2, A1
    MVTACGU R1, A1

    POPM   R6-R13                         ; Restore general registers.
    POPC   FPSW                           ; Restore FPSW.
    POPM   R14-R15                        ; Restore R14-R15.
    POPM   R3-R5                          ; Restore R3-R5.
    POPM   R1-R2                          ; Restore R1-R2.
    RTE


_tx_software_interrupt_handler:
; R1 and R2 are saved here because __tx_thread_context_save uses them internally at entry.
; Pushing them before the call preserves their values so __tx_thread_context_save can
; read them from the ISP as part of the interrupted thread's saved register frame.
    PUSHM R1-R2                           ; Save R1-R2 before __tx_thread_context_save uses them.

    BSR __tx_thread_context_save          ; Call _tx_thread_context_save

    BRA __tx_thread_context_restore       ; Jump to _tx_thread_context_restore (non-returning)


__tx_thread_interrupt_control:
    MVFC    PSW, R2          ; R2 = old PSW
    MOV.L   R2, R3           ; R3 = old PSW copy
    BTST    #16, R1          ; Check new_posture I bit
    BMC     #16, R2          ; Clear I bit
    BEQ     .Lctl_write      ; If new I=0, skip set.
    BSET    #16, R2          ; Set I bit if requested.
.Lctl_write:
    MVTC    R2, PSW          ; Write new PSW.
    MOV.L   R3, R1           ; return old PSW
    RTS


__tx_thread_context_save:
    MOV.L   #__tx_thread_system_state, R1 ; R1 = &system_state.
    MOV.L   [R1], R2                      ; R2 = system_state.
    CMP     #0, R2                        ; Nested interrupt?
    BEQ     __tx_not_nested_save

    ADD     #1, R2                        ; system_state++ (nested).
    MOV.L   R2, [R1]

    POP R1                                ; R1 = return address.
    PUSHM   R3-R5                         ; Save R3-R5.
    PUSHM   R14-R15                       ; Save R14-R15.
    PUSHC   FPSW                          ; Save FPSW
    JMP     R1

__tx_not_nested_save:
    ADD     #1, R2                        ; system_state++.
    MOV.L   R2, [R1]

    MOV.L   #__tx_thread_current_ptr, R2  ; R2 = &current_ptr.
    MOV.L   [R2], R2                      ; R2 = current thread.
    CMP     #0,R2                         ; Thread running?
    BEQ      __tx_idle_save               ; No, idle/system.

    MVFC    USP, R1                       ; R1 = thread stack pointer.
    MOV.L   16[R0], R2                    ; Load PSW.
    MOV.L   R2, [-R1]                     ; Push PSW.
    MOV.L   12[R0], R2                    ; Load PC.
    MOV.L   R2, [-R1]                     ; Push PC.
    MOV.L   8[R0], R2                     ; Load R2.
    MOV.L   R2, [-R1]                     ; Push R2.
    MOV.L   4[R0], R2                     ; Load R1.
    MOV.L   R2, [-R1]                     ; Push R1.

    MOV.L   R5, [-R1]                     ; Push R5.
    MOV.L   R4, [-R1]                     ; Push R4.
    MOV.L   R3, [-R1]                     ; Push R3.
    MOV.L   R15, [-R1]                    ; Push R15.
    MOV.L   R14, [-R1]                    ; Push R14.
    MVFC    FPSW, R3                      ; Save FPSW
    MOV.L   R3, [-R1]

    POP     R2                            ; R2 = return address.
    ADD     #16, R0, R0                   ; Fix interrupt stack.
    MVTC    R1, USP                       ; Update USP.
    JMP     R2                            ; Return to ISR.

__tx_idle_save:
    POP     R1                            ; R1 = return address.
    ADD     #16, R0, R0                   ; Drop interrupt frame.
    JMP     R1                            ; Return.


__tx_thread_context_restore:
     CLRPSW I

     MOV.L    #__tx_thread_system_state, R1 ; R1 = &system_state.
     MOV.L    [R1], R2                      ; R2 = system_state.
     SUB      #1, R2
     MOV.L    R2,[R1]
     BEQ      __tx_not_nested_restore

     POPC    FPSW                           ; Restore FPSW.
     POPM    R14-R15                        ; Restore R14-R15.
     POPM    R3-R5                          ; Restore R3-R5.
     POPM    R1-R2                          ; Restore R1-R2.
     RTE                                    ; Return from interrupt.

__tx_not_nested_restore:
     MOV.L    #__tx_thread_current_ptr, R1  ; R1 = &current_ptr.
     MOV.L    [R1], R2                      ; R2 = current thread.
     CMP      #0, R2
     BEQ      __tx_idle_restore

     MOV.L    #__tx_thread_preempt_disable, R3 ; R3 = &preempt_disable.
     MOV.L    [R3], R3                         ; Load flag.
     CMP      #0, R3
     BNE      __tx_no_preempt_restore

     MOV.L    #__tx_thread_execute_ptr, R3 ; R3 = &execute_ptr.
     CMP      [R3], R2                     ; execute_ptr == current?
     BNE      __tx_do_preempt

__tx_no_preempt_restore:
     SETPSW  U                             ; Use user stack.
     POPC    FPSW                          ; Restore FPSW.
     POPM    R14-R15
     POPM    R3-R5
     POPM    R1-R2
     RTE                                   ; Resume thread.

__tx_do_preempt:
     SETPSW   U                            ; Use user stack.
     PUSHM    R6-R13                       ; Save remaining registers.

     MVFACGU   #0, A1, R4                  ; Save ACC1 GU.
     MVFACHI   #0, A1, R5                  ; Save ACC1 HI.
     MVFACLO   #0, A1, R6                  ; Save ACC1 LO.
     PUSHM     R4-R6                       ; Push ACC1.

     MVFACGU   #0, A0, R4                  ; Save ACC0 GU.
     MVFACHI   #0, A0, R5                  ; Save ACC0 HI.
     MVFACLO   #0, A0, R6                  ; Save ACC0 LO.
     PUSHM     R4-R6                       ; Push ACC0.

     MOV.L   R0,8[R2]                      ; Save SP to thread stack_ptr.
     MOV.L   #0,R2                         ; R2 = NULL.
     MOV.L   R2,[R1]                       ; current_ptr = NULL.
     BRA     __tx_idle_restore

__tx_idle_restore:
     MVTC    #0, PSW                       ; Reset PSW (IPL = 0).
     BRA     __tx_thread_schedule          ; Jump to scheduler.


    .endif

    .end
