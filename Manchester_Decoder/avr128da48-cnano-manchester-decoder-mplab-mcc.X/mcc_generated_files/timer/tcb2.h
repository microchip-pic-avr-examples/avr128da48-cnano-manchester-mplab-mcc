/**
 * TCB2 Generated Driver API Header File
 *
 * @file tcb2.h
 *
 * @defgroup tcb2 TCB2
 *
 * @brief This file contains the API prototypes and custom data types for the TCB2 driver.
 *
 * @version TCB2 Driver Version 1.1.5
*/
/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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
#include "../system/utils/compiler.h"
#include "./timer_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const struct TMR_INTERFACE TCB2_Interface;

/**
 * @ingroup tcb2
 * @typedef void *TCB2_cb_t
 * @brief Function pointer to callback function called by the TCB. The default value is set to NULL which means that no callback function will be used.
 */
typedef void (*TCB2_cb_t)(void);

/**
 * @ingroup tcb2
 * @brief Registers a callback function to be called at capture event.
 * @param TCB2_cb_t cb - Callback function for capture event.
 * @return None.
 */
void TCB2_CaptureCallbackRegister(TCB2_cb_t cb);

/**
 * @ingroup tcb2
 * @brief Registers a callback function to be called at overflow event.
 * @param TCB2_cb_t cb - Callback function for overflow event.
 * @return None.
 */
void TCB2_OverflowCallbackRegister(TCB2_cb_t cb);

/**
 * @ingroup tcb2
 * @brief Initializes the TCB module
 * @param None.
 * @return None.
 */
void TCB2_Initialize(void);
/**
 * @ingroup tcb2
 * @brief Starts the TCB counter.
 * @param None.
 * @return None.
 */
void TCB2_Start(void);
/**
 * @ingroup tcb2
 * @brief Stops the TCB counter.
 * @param None.
 * @return None.
 */
void TCB2_Stop(void);
/**
 * @ingroup tcb2
 * @brief Enables the capture interrupt for the TCB.
 * @param None.
 * @return None.
 */
void TCB2_EnableCaptInterrupt(void);
/**
 * @ingroup tcb2
 * @brief Disables the capture interrupt for the TCB.
 * @param None.
 * @return None.
 */
void TCB2_DisableCaptInterrupt(void);
/**
 * @ingroup tcb2
 * @brief Enables the overflow interrupt for the TCB.
 * @param None.
 * @return None.
 */
void TCB2_EnableOvfInterrupt(void);
/**
 * @ingroup tcb2
 * @brief Disables the overflow interrupt for the TCB.
 * @param None.
 * @return None.
 */
void TCB2_DisableOvfInterrupt(void);
/**
 * @ingroup tcb2
 * @brief Reads the 16-bit timer value of the TCB.
 * @param None.
 * @return uint16_t
 */
uint16_t TCB2_Read(void);
/**
 * @ingroup tcb2
 * @brief Writes the 16-bit timer value to the TCB. 
 * @param uint16_t timerVal - 16-bit Timer value to write for TCB interface.
 * @return None.
 */
void TCB2_Write(uint16_t timerVal);
/**
 * @ingroup tcb2
 * @brief Checks the Overflow Interrupt flag.
 * @param None.
 * @return bool.
 */
bool TCB2_IsOvfInterruptFlag(void);
/**
 * @ingroup tcb2
 * @brief Checks the Capture Interrupt flag.
 * @param None.
 * @return bool.
 */
bool TCB2_IsCaptInterruptFlag(void);

/**
 * @ingroup tcb2
 * @brief Clears the Capture Interrupt flag.
 * @param None.
 * @return None.
 */
void TCB2_ClearCaptInterruptFlag(void);
/**
 * @ingroup tcb2
 * @brief Checks if the capture interrupt is enabled.
 * @param None.
 * @return None.
 */
bool TCB2_IsCaptInterruptEnabled(void);
/**
 * @ingroup tcb2
 * @brief Clears the Overflow Interrupt flag.
 * @param None.
 * @return None.
 */
void TCB2_ClearOvfInterruptFlag(void);
/**
 * @ingroup tcb2
 * @brief Checks if the overflow interrupt is enabled.
 * @param None.
 * @return None.
 */
bool TCB2_IsOvfInterruptEnabled(void);

/**
 * @ingroup tcb2_normal
 * @brief Performs the tasks to be executed on timer events.
 * @param None.
 * @return None.
 */
void TCB2_Tasks(void);



#ifdef __cplusplus
}
#endif

#endif /* TCB2_H_INCLUDED */