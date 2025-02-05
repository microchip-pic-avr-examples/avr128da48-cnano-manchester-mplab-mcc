/**
 * TCB1 Generated Driver API Header File
 *
 * @file tcb1.h
 *
 * @defgroup tcb1 TCB1
 *
 * @brief This file contains the deprecated macros or APIs for the TCB1 driver.
 *
 * @version TCB1 Driver Version 2.0.0
 * 
 * @version Package Version 6.0.0
 */
/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef TCB1_DEPRECATED_H
#define TCB1_DEPRECATED_H

#warning "The tcb1_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_CounterGet API.
 *        The TCB1_Read will be deprecated in the future release. Use TCB1_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_Read TCB1_CounterGet
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_CounterSet API.
 *        The TCB1_Write will be deprecated in the future release. Use TCB1_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_Write TCB1_CounterSet
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_CAPTInterruptEnable API.
 *        The TCB1_EnableCaptInterrupt will be deprecated in the future release. Use TCB1_CAPTInterruptEnable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_EnableCaptInterrupt TCB1_CAPTInterruptEnable
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_CAPTInterruptDisable API.
 *        The TCB1_DisableCaptInterrupt will be deprecated in the future release. Use TCB1_CAPTInterruptDisable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_DisableCaptInterrupt TCB1_CAPTInterruptDisable
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_OVFInterruptEnable API.
 *        The TCB1_EnableOvfInterrupt will be deprecated in the future release. Use TCB1_OVFInterruptEnable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_EnableOvfInterrupt TCB1_OVFInterruptEnable
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_OVFInterruptDisable API.
 *        The TCB1_DisableOvfInterrupt will be deprecated in the future release. Use TCB1_OVFInterruptDisable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_DisableOvfInterrupt TCB1_OVFInterruptDisable
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_OverflowStatusClear API.
 *        The TCB1_ClearOvfInterruptFlag will be deprecated in the future release. Use TCB1_OverflowStatusClear instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_ClearOvfInterruptFlag TCB1_OverflowStatusClear
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_CaptureStatusClear API.
 *        The TCB1_ClearCaptInterruptFlag will be deprecated in the future release. Use TCB1_CaptureStatusClear instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_ClearCaptInterruptFlag TCB1_CaptureStatusClear
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_OverflowStatusGet API.
 *        The TCB1_IsOvfInterruptFlag will be deprecated in the future release. Use TCB1_OverflowStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_IsOvfInterruptFlag TCB1_OverflowStatusGet
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_CaptureStatusGet API.
 *        The TCB1_IsCaptInterruptFlag will be deprecated in the future release. Use TCB1_CaptureStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_IsCaptInterruptFlag TCB1_CaptureStatusGet
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_Start API.
 *        The TCB1_PWM_Enable will be deprecated in the future release. Use TCB1_Start instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_PWM_Enable TCB1_Start
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_Stop API.
 *        The TCB1_PWM_Disable will be deprecated in the future release. Use TCB1_Stop instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_PWM_Disable TCB1_Stop
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_CounterSet API.
 *        The TCB1_load_counter will be deprecated in the future release. Use TCB1_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_load_counter TCB1_CounterSet
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_PeriodSet API.
 *        The TCB1_load_top will be deprecated in the future release. Use TCB1_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_load_top TCB1_PeriodSet
/**
 * @ingroup tcb1
 * @brief Defines the Custom Name for the \ref TCB1_DutyCycleSet API.
 *        The TCB1_load_duty_cycle will be deprecated in the future release. Use TCB1_DutyCycleSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_load_duty_cycle TCB1_DutyCycleSet
/**
 * @ingroup tcb1
 * @brief Defines a macro to handle deprecated custom data type.
 *        This macro will be deprecated in the future release.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB1_pwm_register_t uint8_t

/**
 * @ingroup tcb1
 * @brief Defines a macro to handle deprecated custom data type.
 *        This macro will be deprecated in the future release.
 */
/* cppcheck-suppress misra-c2012-2.5 */ 
#define TCB1_pwm_register_t uint8_t

#endif // TCB1_DEPRECATED_H