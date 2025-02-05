/**
 * TCB2 Generated Driver API Header File
 *
 * @file tcb2.h
 *
 * @defgroup tcb2 TCB2
 *
 * @brief This file contains the deprecated macros or APIs for the TCB2 driver.
 *
 * @version TCB2 Driver Version 2.0.0
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

#ifndef TCB2_DEPRECATED_H
#define TCB2_DEPRECATED_H

#warning "The tcb2_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_CounterGet API.
 *        The TCB2_Read will be deprecated in the future release. Use TCB2_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_Read TCB2_CounterGet
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_CounterSet API.
 *        The TCB2_Write will be deprecated in the future release. Use TCB2_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_Write TCB2_CounterSet
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_CAPTInterruptEnable API.
 *        The TCB2_EnableCaptInterrupt will be deprecated in the future release. Use TCB2_CAPTInterruptEnable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_EnableCaptInterrupt TCB2_CAPTInterruptEnable
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_CAPTInterruptDisable API.
 *        The TCB2_DisableCaptInterrupt will be deprecated in the future release. Use TCB2_CAPTInterruptDisable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_DisableCaptInterrupt TCB2_CAPTInterruptDisable
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_OVFInterruptEnable API.
 *        The TCB2_EnableOvfInterrupt will be deprecated in the future release. Use TCB2_OVFInterruptEnable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_EnableOvfInterrupt TCB2_OVFInterruptEnable
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_OVFInterruptDisable API.
 *        The TCB2_DisableOvfInterrupt will be deprecated in the future release. Use TCB2_OVFInterruptDisable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_DisableOvfInterrupt TCB2_OVFInterruptDisable
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_OverflowStatusClear API.
 *        The TCB2_ClearOvfInterruptFlag will be deprecated in the future release. Use TCB2_OverflowStatusClear instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_ClearOvfInterruptFlag TCB2_OverflowStatusClear
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_CaptureStatusClear API.
 *        The TCB2_ClearCaptInterruptFlag will be deprecated in the future release. Use TCB2_CaptureStatusClear instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_ClearCaptInterruptFlag TCB2_CaptureStatusClear
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_OverflowStatusGet API.
 *        The TCB2_IsOvfInterruptFlag will be deprecated in the future release. Use TCB2_OverflowStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_IsOvfInterruptFlag TCB2_OverflowStatusGet
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_CaptureStatusGet API.
 *        The TCB2_IsCaptInterruptFlag will be deprecated in the future release. Use TCB2_CaptureStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_IsCaptInterruptFlag TCB2_CaptureStatusGet
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_Start API.
 *        The TCB2_PWM_Enable will be deprecated in the future release. Use TCB2_Start instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_PWM_Enable TCB2_Start
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_Stop API.
 *        The TCB2_PWM_Disable will be deprecated in the future release. Use TCB2_Stop instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_PWM_Disable TCB2_Stop
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_CounterSet API.
 *        The TCB2_load_counter will be deprecated in the future release. Use TCB2_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_load_counter TCB2_CounterSet
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_PeriodSet API.
 *        The TCB2_load_top will be deprecated in the future release. Use TCB2_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_load_top TCB2_PeriodSet
/**
 * @ingroup tcb2
 * @brief Defines the Custom Name for the \ref TCB2_DutyCycleSet API.
 *        The TCB2_load_duty_cycle will be deprecated in the future release. Use TCB2_DutyCycleSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_load_duty_cycle TCB2_DutyCycleSet
/**
 * @ingroup tcb2
 * @brief Defines a macro to handle deprecated custom data type.
 *        This macro will be deprecated in the future release.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_pwm_register_t uint8_t

/**
 * @ingroup tcb2
 * @brief Defines a macro to handle deprecated custom data type.
 *        This macro will be deprecated in the future release.
 */
/* cppcheck-suppress misra-c2012-2.5 */ 
#define TCB2_pwm_register_t uint8_t

#endif // TCB2_DEPRECATED_H