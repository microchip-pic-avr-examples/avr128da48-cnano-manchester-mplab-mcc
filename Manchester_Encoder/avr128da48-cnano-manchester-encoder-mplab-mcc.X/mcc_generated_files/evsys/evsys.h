/**
 * 
 * @file evsys.h
 *
 * @defgroup evsys_driver Event System
 *
 * @brief This file contains the API prototypes for the Event System (EVSYS) driver.
 *
 * @version EVSYS Driver Version 1.1.2
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

#ifndef EVSYS_H_INCLUDED
#define EVSYS_H_INCLUDED

#include "../system/utils/compiler.h"

/**
 * @ingroup evsys_driver
 * @brief Initializes the EVSYS driver. 
 * @param None.
 * @retval 0 - Initialization is successful.
 */
int8_t EVSYS_Initialize(void);

/**
 * @ingroup evsys_driver
 * @brief Updates the Software Event A Channel Select (SWENTA) register.
 * @param channel - Event channel that generates a software event.
 * @return None.
 */
void EVSYS_SoftwareEventASet(uint8_t channel);

/**
 * @ingroup evsys_driver
 * @brief Updates the Software Event B Channel Select (SWENTB) register.
 * @param channel - Event channel that generates a software event.
 * @return None.
 */
void EVSYS_SoftwareEventBSet(uint8_t channel);

#endif /* EVSYS_H_INCLUDED */