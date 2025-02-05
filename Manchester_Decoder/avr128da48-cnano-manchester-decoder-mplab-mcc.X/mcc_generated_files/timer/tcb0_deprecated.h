/**
 * TCB0 Generated Driver API Header File
 *
 * @file tcb0.h
 *
 * @defgroup tcb0 TCB0
 *
 * @brief This file contains the deprecated macros or APIs for the TCB0 driver.
 *
 * @version TCB0 Driver Version 2.0.0
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

#ifndef TCB0_DEPRECATED_H
#define TCB0_DEPRECATED_H

#warning "The tcb0_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_CounterGet API.
 *        The TCB0_Read will be deprecated in the future release. Use TCB0_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_Read TCB0_CounterGet
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_CounterSet API.
 *        The TCB0_Write will be deprecated in the future release. Use TCB0_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_Write TCB0_CounterSet
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_CAPTInterruptEnable API.
 *        The TCB0_EnableCaptInterrupt will be deprecated in the future release. Use TCB0_CAPTInterruptEnable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_EnableCaptInterrupt TCB0_CAPTInterruptEnable
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_CAPTInterruptDisable API.
 *        The TCB0_DisableCaptInterrupt will be deprecated in the future release. Use TCB0_CAPTInterruptDisable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_DisableCaptInterrupt TCB0_CAPTInterruptDisable
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_OVFInterruptEnable API.
 *        The TCB0_EnableOvfInterrupt will be deprecated in the future release. Use TCB0_OVFInterruptEnable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_EnableOvfInterrupt TCB0_OVFInterruptEnable
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_OVFInterruptDisable API.
 *        The TCB0_DisableOvfInterrupt will be deprecated in the future release. Use TCB0_OVFInterruptDisable instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_DisableOvfInterrupt TCB0_OVFInterruptDisable
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_OverflowStatusClear API.
 *        The TCB0_ClearOvfInterruptFlag will be deprecated in the future release. Use TCB0_OverflowStatusClear instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_ClearOvfInterruptFlag TCB0_OverflowStatusClear
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_CaptureStatusClear API.
 *        The TCB0_ClearCaptInterruptFlag will be deprecated in the future release. Use TCB0_CaptureStatusClear instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_ClearCaptInterruptFlag TCB0_CaptureStatusClear
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_OverflowStatusGet API.
 *        The TCB0_IsOvfInterruptFlag will be deprecated in the future release. Use TCB0_OverflowStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_IsOvfInterruptFlag TCB0_OverflowStatusGet
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_CaptureStatusGet API.
 *        The TCB0_IsCaptInterruptFlag will be deprecated in the future release. Use TCB0_CaptureStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_IsCaptInterruptFlag TCB0_CaptureStatusGet
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_Start API.
 *        The TCB0_PWM_Enable will be deprecated in the future release. Use TCB0_Start instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_PWM_Enable TCB0_Start
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_Stop API.
 *        The TCB0_PWM_Disable will be deprecated in the future release. Use TCB0_Stop instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_PWM_Disable TCB0_Stop
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_CounterSet API.
 *        The TCB0_load_counter will be deprecated in the future release. Use TCB0_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_load_counter TCB0_CounterSet
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_PeriodSet API.
 *        The TCB0_load_top will be deprecated in the future release. Use TCB0_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_load_top TCB0_PeriodSet
/**
 * @ingroup tcb0
 * @brief Defines the Custom Name for the \ref TCB0_DutyCycleSet API.
 *        The TCB0_load_duty_cycle will be deprecated in the future release. Use TCB0_DutyCycleSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_load_duty_cycle TCB0_DutyCycleSet
/**
 * @ingroup tcb0
 * @brief Defines a macro to handle deprecated custom data type.
 *        This macro will be deprecated in the future release.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_pwm_register_t uint8_t

/**
 * @ingroup tcb0
 * @brief Defines a macro to handle deprecated custom data type.
 *        This macro will be deprecated in the future release.
 */
/* cppcheck-suppress misra-c2012-2.5 */ 
#define TCB0_pwm_register_t uint8_t

#endif // TCB0_DEPRECATED_H