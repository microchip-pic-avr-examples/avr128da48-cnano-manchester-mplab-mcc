/**
 * TCB0 Generated Driver API Header File
 *
 * @file tcb0.h
 *
 * @defgroup tcb0 TCB0
 *
 * @brief  This file contains the API prototypes and other data types for TCB0.
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

#ifndef TCB0_H_INCLUDED
#define TCB0_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "../system/utils/compiler.h"
#include "tcb0_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tcb0
 * @brief Defines the TCB0 maximum count value
 */
#define TCB0_MAX_COUNT (65535U)
/**
 * @ingroup tcb0
 * @brief Defines the TCB0 frequency in hertz.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TCB0_CLOCK_FREQ (24000000UL)

/**
 * @ingroup tcb0
 * @brief Registers a callback function to be called during a capture event.
 * @param void (* CallbackHandler)(void) - Pointer to the custom callback
 * @return None.
 */
void TCB0_CaptureCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tcb0
 * @brief Registers a callback function to be called during an overflow event.
 * @param void (* CallbackHandler)(void) - Pointer to the custom callback
 * @return None.
 */
 void TCB0_OverflowCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tcb0
 * @brief Initializes the TCB0 module
 * @param None.
 * @return None.
 */
void TCB0_Initialize(void);

/**
 * @ingroup tcb0
 * @brief Deinitializes the TCB0 module.
 * @param None.
 * @return None.
 */
void TCB0_Deinitialize(void);

/**
 * @ingroup tcb0
 * @brief Starts the TCB0 counter.
 * @param None.
 * @return None.
 */
void TCB0_Start(void);

/**
 * @ingroup tcb0
 * @brief Stops the TCB0 counter.
 * @param None.
 * @return None.
 */
void TCB0_Stop(void);

/**
 * @ingroup tcb0
 * @brief Writes the counter value to the CNT register.
 * @pre Initialize TCB0 with TCB0_Initialize() before calling this API.
 * @param counterValue - Counter value to be written to the CNT register
 * @return None.
 */
void TCB0_CounterSet(uint16_t counterValue);

/**
 * @ingroup tcb0
 * @brief Reads the counter value from the CNT register.
 * @pre Initialize TCB0 with TCB0_Initialize() before calling this API.
 * @param None.
 * @return Counter value from the CNT register
 */
uint16_t TCB0_CounterGet(void);

/**
 * @ingroup tcb0
 * @brief Loads the period count value to the CCMP register.
 * @pre Initialize TCB0 with TCB0_Initialize() before calling this API.
 * @param periodVal - Count value written to the CCMP register
 * @return None.
 */
void TCB0_PeriodSet(uint16_t periodVal);

/**
 * @ingroup tcb0
 * @brief Gets the current period value from the CCMP register.
 * @pre Initialize TCB0 with TCB0_Initialize() before calling this API.
 * @param None.
 * @return Period value from the CCMP register
 */
uint16_t TCB0_PeriodGet(void);

/**
 * @ingroup tcb0
 * @brief Gets the maximum timer count value.
 * @param None.
 * @return Maximum count value
 */
uint16_t TCB0_MaxCountGet(void);



/**
 * @ingroup tcb0
 * @brief Checks the Capture Interrupt flag.
 * @param None.
 * @return bool
 */
bool TCB0_CaptureStatusGet(void);

/**
 * @ingroup tcb0
 * @brief Checks the Overflow Interrupt flag.
 * @param None.
 * @return bool
 */
bool TCB0_OverflowStatusGet(void);

/**
 * @ingroup tcb0
 * @brief Clears the Capture Interrupt flag.
 * @param None.
 * @return None.
 */
void TCB0_CaptureStatusClear(void);

/**
 * @ingroup tcb0
 * @brief Clears the Overflow Interrupt flag.
 * @param None.
 * @return None.
 */
void TCB0_OverflowStatusClear(void);

/**
 * @ingroup tcb0
 * @brief Checks if the capture interrupt is enabled.
 * @param None.
 * @return None.
 */
bool TCB0_IsCaptInterruptEnabled(void) __attribute__((deprecated("This function will be deprecated in future")));

/**
 * @ingroup tcb0
 * @brief Checks if the overflow interrupt is enabled.
 * @param None.
 * @return None.
 */
bool TCB0_IsOvfInterruptEnabled(void) __attribute__((deprecated("This function will be deprecated in future")));


/**
 * @ingroup tcb0_normal
 * @brief Performs the tasks to be executed on timer events.
 * @param None.
 * @return None.
 */
void TCB0_Tasks(void);


#endif /* TCB0_H_INCLUDED */