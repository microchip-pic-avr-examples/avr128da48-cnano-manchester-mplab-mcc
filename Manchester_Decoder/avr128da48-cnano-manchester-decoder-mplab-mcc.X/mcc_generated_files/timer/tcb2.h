/**
 * TCB2 Generated Driver API Header File
 *
 * @file tcb2.h
 *
 * @defgroup tcb2 TCB2
 *
 * @brief  This file contains the API prototypes and other data types for TCB2.
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

#ifndef TCB2_H_INCLUDED
#define TCB2_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "../system/utils/compiler.h"
#include "tcb2_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tcb2
 * @brief Defines the TCB2 maximum count value
 */
#define TCB2_MAX_COUNT (65535U)
/**
 * @ingroup tcb2
 * @brief Defines the TCB2 frequency in hertz.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB2_CLOCK_FREQ (24000000UL)

/**
 * @ingroup tcb2
 * @brief Registers a callback function to be called during a capture event.
 * @param void (* CallbackHandler)(void) - Pointer to the custom callback
 * @return None.
 */
void TCB2_CaptureCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tcb2
 * @brief Registers a callback function to be called during an overflow event.
 * @param void (* CallbackHandler)(void) - Pointer to the custom callback
 * @return None.
 */
 void TCB2_OverflowCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tcb2
 * @brief Initializes the TCB2 module
 * @param None.
 * @return None.
 */
void TCB2_Initialize(void);

/**
 * @ingroup tcb2
 * @brief Deinitializes the TCB2 module.
 * @param None.
 * @return None.
 */
void TCB2_Deinitialize(void);

/**
 * @ingroup tcb2
 * @brief Starts the TCB2 counter.
 * @param None.
 * @return None.
 */
void TCB2_Start(void);

/**
 * @ingroup tcb2
 * @brief Stops the TCB2 counter.
 * @param None.
 * @return None.
 */
void TCB2_Stop(void);

/**
 * @ingroup tcb2
 * @brief Writes the counter value to the CNT register.
 * @pre Initialize TCB2 with TCB2_Initialize() before calling this API.
 * @param counterValue - Counter value to be written to the CNT register
 * @return None.
 */
void TCB2_CounterSet(uint16_t counterValue);

/**
 * @ingroup tcb2
 * @brief Reads the counter value from the CNT register.
 * @pre Initialize TCB2 with TCB2_Initialize() before calling this API.
 * @param None.
 * @return Counter value from the CNT register
 */
uint16_t TCB2_CounterGet(void);

/**
 * @ingroup tcb2
 * @brief Loads the period count value to the CCMP register.
 * @pre Initialize TCB2 with TCB2_Initialize() before calling this API.
 * @param periodVal - Count value written to the CCMP register
 * @return None.
 */
void TCB2_PeriodSet(uint16_t periodVal);

/**
 * @ingroup tcb2
 * @brief Gets the current period value from the CCMP register.
 * @pre Initialize TCB2 with TCB2_Initialize() before calling this API.
 * @param None.
 * @return Period value from the CCMP register
 */
uint16_t TCB2_PeriodGet(void);

/**
 * @ingroup tcb2
 * @brief Gets the maximum timer count value.
 * @param None.
 * @return Maximum count value
 */
uint16_t TCB2_MaxCountGet(void);

/**
 * @ingroup tcb2
 * @brief Enables the capture interrupt for the TCB2.
 * @param None.
 * @return None.
 */
void TCB2_CAPTInterruptEnable(void);

/**
 * @ingroup tcb2
 * @brief Disables the capture interrupt for the TCB2.
 * @param None.
 * @return None.
 */
void TCB2_CAPTInterruptDisable(void);

/**
 * @ingroup tcb2
 * @brief Enables the overflow interrupt for the TCB2.
 * @param None.
 * @return None.
 */
void TCB2_OVFInterruptEnable(void);

/**
 * @ingroup tcb2
 * @brief Disables the overflow interrupt for the TCB2.
 * @param None.
 * @return None.
 */
void TCB2_OVFInterruptDisable(void);


/**
 * @ingroup tcb2
 * @brief Checks if the capture interrupt is enabled.
 * @param None.
 * @return None.
 */
bool TCB2_IsCaptInterruptEnabled(void) __attribute__((deprecated("This function will be deprecated in future")));

/**
 * @ingroup tcb2
 * @brief Checks if the overflow interrupt is enabled.
 * @param None.
 * @return None.
 */
bool TCB2_IsOvfInterruptEnabled(void) __attribute__((deprecated("This function will be deprecated in future")));




#endif /* TCB2_H_INCLUDED */