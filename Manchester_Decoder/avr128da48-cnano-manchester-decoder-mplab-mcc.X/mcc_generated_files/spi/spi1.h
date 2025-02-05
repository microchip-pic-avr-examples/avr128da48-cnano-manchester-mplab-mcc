/**
 * SPI1 Generated Driver API Header File
 *
 * @file spi1.h
 *
 * @defgroup spi1 SPI1
 *
 * @brief This header file provides API prototypes for the SPI1 driver.
 *
 * @version SPI1 Driver Version 3.1.0
 *  
 * @version SPI1 Package Version 5.1.0
*/
/*
� [2025] Microchip Technology Inc. and its subsidiaries.

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

#ifndef SPI1_H
#define SPI1_H

#include <stdbool.h>
#include "../system/utils/compiler.h"
#include "spi_interface.h"

/**
 * @ingroup spi1
 * @struct SPI_INTERFACE SPI1
 * @brief SPI driver interface object.
 */               
extern const struct SPI_INTERFACE SPI1_Client;

/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_Initialize API
 */
#define SPI1_Client_Initialize SPI1_Initialize
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_Deinitialize API
 */
#define SPI1_Client_Deinitialize SPI1_Deinitialize
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_Close API
 */
#define SPI1_Client_Close SPI1_Close
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_Open API
 */
#define SPI1_Client_Open SPI1_Open
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_ByteExchange API
 */
#define SPI1_Client_ByteExchange SPI1_ByteExchange
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_Transfer API
 */
#define SPI1_Client_Transfer SPI1_Transfer
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_BufferExchange API
 */
#define SPI1_Client_BufferExchange SPI1_BufferExchange
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_BufferWrite API
 */
#define SPI1_Client_BufferWrite SPI1_BufferWrite
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_BufferRead API
 */
#define SPI1_Client_BufferRead SPI1_BufferRead
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_ByteWrite API
 */
#define SPI1_Client_ByteWrite SPI1_ByteWrite
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_ByteRead API
 */
#define SPI1_Client_ByteRead SPI1_ByteRead
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_IsRxReady API
 */
#define SPI1_Client_IsRxReady SPI1_IsRxReady
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_IsTxReady API
 */
#define SPI1_Client_IsTxReady SPI1_IsTxReady
/**
 * @ingroup  spi1
 * @brief    This macro defines the Custom Name for \ref SPI1_CallbackRegister API
 */
#define SPI1_Client_RxCompleteCallbackRegister SPI1_RxCompleteCallbackRegister

/**
 * @ingroup spi1
 * @typedef enum SPI1_Client_configuration_name_t
 * @brief Enumeration for the different configurations supported by the driver. 
 * A configuration is specified as parameter to SPI1_Open()
 * and is used by the function to set SPI parameters as specified by the configuration.
 */
typedef enum 
{
    CLIENT_CONFIG,
    SPI1_DEFAULT
} SPI1_Client_configuration_name_t;

/**
 * @ingroup spi1
 * @brief Initializes the SPI1 module.
 * @param None.
 * @return None.
 */
void SPI1_Initialize(void);

/**
 * @ingroup spi1
 * @brief Deinitializes the SPI1 module
 * @param None.
 * @return None.
 */
void SPI1_Deinitialize(void);

/**
 * @ingroup spi1
 * @brief Enables the SPI1 module with the configurations passed as the parameter.
 * See spi1_configuration_name_t for the available configurations.
 * @param spiConfigIndex The Configuration index
 * @retval True SPI1 module is enabled successfully with the chosen configuration
 * @retval False SPI1 module is already open with another configuration
 */
bool SPI1_Open(uint8_t spiConfigIndex);

/**
 * @ingroup spi1
 * @brief Closes the active configuration of the SPI1 module.
 * @param None.
 * @return None.
 */
void SPI1_Close(void);

/**
 * @ingroup spi1
 * @brief Exchanges one byte using the SPI protocol. This function is blocking.
 * @param byteData The byte to be written
 * @return Received data byte
 */
uint8_t SPI1_ByteExchange(uint8_t byteData);

/**
 * @ingroup spi1
 * @brief Exchanges the buffer using the SPI protocol with separate transmit and receive buffer locations. This function is blocking in Polling mode.
 * @param [in] *txBuffer Buffer address of the data to be transmitted during exchange
 * @param [in] *rxBuffer Buffer address of the data to be received during exchange
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI1_Transfer(const void * txBuffer, void * rxBuffer, size_t bufferSize);

/**
 * @ingroup spi1
 * @brief Exchanges the buffer using the SPI protocol. This function is blocking in Polling mode.
 * @param [in,out] *bufferData Buffer address of the data to be exchanged
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI1_BufferExchange(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi1
 * @brief Writes a buffer using the SPI protocol. This function is blocking in Polling mode.
 * @param [in] *bufferData Buffer address of the data to be written
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI1_BufferWrite(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi1
 * @brief Reads a buffer using the SPI protocol. This function is blocking in Polling mode.
 * @param [out] *bufferData Buffer address of the data to be read
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI1_BufferRead(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi1
 * @brief Writes one byte using the SPI protocol. This function is blocking in Polling mode.
 * @param byteData The byte to be written
 * @return None.
 */
void SPI1_ByteWrite(uint8_t byteData);

/**
 * @ingroup spi1
 * @brief Receives one byte using SPI protocol. This function is blocking.
 * @param None.
 * @return Received data byte
 */
uint8_t SPI1_ByteRead(void);

/**
 * @ingroup spi1
 * @brief Checks if the SPI1 module is ready to read data.
 * @param None.
 * @retval True SPI1 module has data ready in buffer
 * @retval False SPI1 module is not ready to read data
 */
bool SPI1_IsRxReady(void);

/**
 * @ingroup spi1
 * @brief Checks if the SPI1 module is ready to write data.
 * @param None.
 * @retval True SPI1 module is ready to write data
 * @retval False SPI1 module is not ready to write data
 */
bool SPI1_IsTxReady(void);

/**
 * @ingroup spi1
 * @brief Sets the callback function to be executed at the completion of data transfer in Interrupt mode.
 * @param Pointer to the function to be executed
 * @return None.
 */
void SPI1_RxCompleteCallbackRegister(void (*callbackHandler)(void));

#endif /* SPI1_H */
