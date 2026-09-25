/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#if defined(__GNUC__)
 #include \
    "../../../../rx/aws/FreeRTOS/FreeRTOS-Plus/Source/FreeRTOS-Plus-TCP/source/portable/Compiler/GCC/pack_struct_start.h"
#elif defined(__ICCRX__)

/* Ignore Pe1644 error  (definition at end of file not followed by a semicolon or a declarator). */
 #pragma diag_suppress=Pe1644
 #include \
    "../../../../rx/aws/FreeRTOS/FreeRTOS-Plus/Source/FreeRTOS-Plus-TCP/source/portable/Compiler/IAR/pack_struct_start.h"
#elif defined(__CCRX__)
 #pragma diag_suppress=1644
 #include \
    "../../../../rx/aws/FreeRTOS/FreeRTOS-Plus/Source/FreeRTOS-Plus-TCP/source/portable/Compiler/Renesas/pack_struct_start.h"
#else
 #error Unknown compiler.
#endif
