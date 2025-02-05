/**
 * SPI1 Generated Driver File
 *
 * @file spi1.c
 *
 * @ingroup spi1
 *
 * @brief This file contains the driver code for the SPI1 module.
 *
 * @version SPI1 Driver Version 3.1.0
 *  
 * @version SPI1 Package Version 5.1.0
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


#include "../spi1.h"
#include "../spi_interrupt_types.h"

const struct SPI_INTERFACE SPI1_Client = 
{
    .Initialize = SPI1_Initialize,
    .Deinitialize = SPI1_Deinitialize,
    .Open = SPI1_Open,
    .Close = SPI1_Close,
    .Transfer = SPI1_Transfer,
    .BufferExchange = SPI1_BufferExchange,
    .BufferWrite = SPI1_BufferWrite,
    .BufferRead = SPI1_BufferRead,	
    .ByteExchange = SPI1_ByteExchange,
    .ByteWrite = SPI1_ByteWrite,
    .ByteRead = SPI1_ByteRead,
    .IsTxReady = SPI1_IsTxReady,
    .IsRxReady = SPI1_IsRxReady,
    .RxCompleteCallbackRegister = SPI1_RxCompleteCallbackRegister,
    .TxCompleteCallbackRegister = NULL
};

static void (*SPI1_RxCompleteCallback)(void);
void SPI1_ISR(void);

static spi_descriptor_t spi1_descriptor = 
{
    .transmitBuffer = NULL,
    .receiveBuffer = NULL,
    .bufferLength = 0,
    .status = SPI_RESET
};

static const spi_configuration_t spi1_configuration[] = 
{
    { 0x1, 0xc4 },
    { 0x14, 0xC4 }
};

void SPI1_Initialize(void)
{
    SPI1.CTRLA &= ~SPI_ENABLE_bm;
    SPI1.CTRLA = (1 << SPI_CLK2X_bp)                /* CLK2X (enabled) */
				|(0 << SPI_DORD_bp)                 /* DORD (disabled) */
				|(0 << SPI_ENABLE_bp)               /* ENABLE (disabled) */
				|(0 << SPI_MASTER_bp)               /* MASTER (disabled) */
				|(SPI_PRESC_DIV64_gc);              /* PRESC (DIV64) */
    SPI1.CTRLB = (1 << SPI_BUFEN_bp)                /* BUFEN (enabled) */
				|(1 << SPI_BUFWR_bp)                /* BUFWR (enabled) */
				|(SPI_MODE_0_gc)                    /* MODE (0) */
				|(1 << SPI_SSD_bp);                 /* SSD (enabled) */
    // Set Callback handler to NULL
    SPI1_RxCompleteCallbackRegister(NULL);
    spi1_descriptor.status = SPI_RESET;
}

void SPI1_Deinitialize(void)
{

    SPI1.CTRLA = 0x0;
    SPI1.CTRLB = 0x0;
    SPI1.INTCTRL = 0x0;

    spi1_descriptor.status = SPI_RESET;
}

bool SPI1_Open(uint8_t spiConfigIndex)
{
    bool returnValue = false;
    if (SPI_RESET == spi1_descriptor.status)
    {
        SPI1.CTRLB = spi1_configuration[spiConfigIndex].ctrlb;
        SPI1.CTRLA = spi1_configuration[spiConfigIndex].ctrla;
        spi1_descriptor.status = SPI_IDLE;
        SPI1.CTRLA |= SPI_ENABLE_bm;
        returnValue = true;
    } 
    else 
    {
        returnValue = false;
    }
    return returnValue;
}

void SPI1_Close(void)
{
    SPI1.CTRLA &= ~SPI_ENABLE_bm;
    spi1_descriptor.status = SPI_RESET;    
}

void SPI1_RxCompleteCallbackRegister(void (* CallbackHandler)(void))
{
    SPI1_RxCompleteCallback = CallbackHandler;
}

uint8_t SPI1_ByteExchange(uint8_t byteData)
{
    while(SPI_IDLE != spi1_descriptor.status)
    { 
        ; // Wait until ongoing SPI transfer is completed
    }
    spi1_descriptor.transmitBuffer = (const uint8_t*)&byteData;
    spi1_descriptor.receiveBuffer = (uint8_t*)&byteData;
    spi1_descriptor.bufferLength = 0;
    spi1_descriptor.transferType = SPI_READ;
    spi1_descriptor.status = SPI_BUSY;

    SPI1.INTCTRL |= SPI_RXCIE_bm;
    SPI1.DATA = *spi1_descriptor.transmitBuffer;
    
    while (SPI_BUSY == spi1_descriptor.status)
    {
        ; // Wait until ongoing SPI transfer is completed
    }
    return byteData;
}

void SPI1_Transfer(const void *txBuffer, void *rxBuffer, size_t bufferSize)
{
    if(SPI_IDLE == spi1_descriptor.status)
    {
        spi1_descriptor.transmitBuffer = (const uint8_t *)txBuffer;
        spi1_descriptor.receiveBuffer = (uint8_t *)rxBuffer;
        spi1_descriptor.bufferLength = bufferSize - (size_t)1;
        spi1_descriptor.transferType = SPI_EXCHANGE;
        spi1_descriptor.status = SPI_BUSY;

        SPI1.INTCTRL |= SPI_RXCIE_bm;
        SPI1.DATA = *spi1_descriptor.transmitBuffer;
    }
    else
    {
        ; // Exiting due to SPI transfer in progress
    }
}

void SPI1_BufferExchange(void *bufferData, size_t bufferSize)
{
    if(SPI_IDLE == spi1_descriptor.status)
    {
        spi1_descriptor.transmitBuffer   = (const uint8_t *)bufferData;
        spi1_descriptor.receiveBuffer   = (uint8_t *)bufferData;
        spi1_descriptor.bufferLength   = bufferSize-(size_t)1;
        spi1_descriptor.transferType   = SPI_EXCHANGE;
        spi1_descriptor.status = SPI_BUSY;

        SPI1.INTCTRL |= SPI_RXCIE_bm;
        SPI1.DATA = *spi1_descriptor.transmitBuffer;
    }
    else
    {
        ; // Exiting due to SPI transfer in progress
    }
}

void SPI1_BufferWrite(void *bufferData, size_t bufferSize)
{
    if(SPI_IDLE == spi1_descriptor.status)
    {
        spi1_descriptor.transmitBuffer   = (const uint8_t *)bufferData;
        spi1_descriptor.receiveBuffer   = NULL;
        spi1_descriptor.bufferLength   = bufferSize-(size_t)1;
        spi1_descriptor.transferType   = SPI_WRITE;
        spi1_descriptor.status = SPI_BUSY;

        SPI1.INTCTRL |= SPI_RXCIE_bm;
        SPI1.DATA = *spi1_descriptor.transmitBuffer;
    }
    else
    {
        ; // Exiting due to SPI transfer in progress 
    }
}

void SPI1_BufferRead(void *bufferData, size_t bufferSize)
{
    if(SPI_IDLE == spi1_descriptor.status)
    {
        spi1_descriptor.transmitBuffer   = NULL;
        spi1_descriptor.receiveBuffer   = (uint8_t *)bufferData;
        spi1_descriptor.bufferLength   = bufferSize-(size_t)1;
        spi1_descriptor.transferType   = SPI_READ;
        spi1_descriptor.status = SPI_BUSY;

        SPI1.INTCTRL |= SPI_RXCIE_bm;
        SPI1.DATA = 0;
    }
    else
    {
        ; // Exiting due to SPI transfer in progress
    }
}

void SPI1_ByteWrite(uint8_t byteData)
{
    if(SPI_IDLE == spi1_descriptor.status)
    {
        SPI1.DATA = byteData;
    }
    else
    {
        ;
    }
}

uint8_t SPI1_ByteRead(void)
{   
    uint8_t readData = 0;
    if(SPI_IDLE == spi1_descriptor.status)
    {
        readData = SPI1.DATA;
    }
    else
    {
        ;
    } 
    return readData;  
}

bool SPI1_IsTxReady(void)
{
    bool returnValue = false;
    if(SPI_IDLE == spi1_descriptor.status)
    {
        returnValue = true;
    }
    else
    {
        returnValue = false;
    }
    return returnValue;
}

bool SPI1_IsRxReady(void)
{
    bool returnValue = false;
    if((SPI_IDLE == spi1_descriptor.status) && (0 != (SPI1.INTFLAGS & SPI_RXCIF_bm)))
    {
        returnValue = true;
    }
    else
    {
        returnValue = false;
    }
    return returnValue;
}

void SPI1_ISR(void)
{
    uint8_t readData = SPI1.DATA;
    uint8_t writeData = 0;

    // Clear interrupt flag
    SPI1.INTFLAGS |= SPI_RXCIF_bm;

    if((spi1_descriptor.bufferLength) > 0)
    {
        if (SPI_WRITE != spi1_descriptor.transferType) 
        {
            *spi1_descriptor.receiveBuffer = readData;
        }
        else
        {
            ; 
        }
        spi1_descriptor.transmitBuffer++;
        spi1_descriptor.receiveBuffer++;

        if (SPI_READ != spi1_descriptor.transferType)
        {
            writeData = *spi1_descriptor.transmitBuffer;
        }
        else
        {
            ;
        }
        spi1_descriptor.bufferLength--;
        SPI1.DATA = writeData;
    }
    else
    {
        if ((SPI_WRITE != spi1_descriptor.transferType) && (SPI_BUSY == spi1_descriptor.status))
        {
            *spi1_descriptor.receiveBuffer = readData;
        }
        else
        {
            ;
        }
        spi1_descriptor.status = SPI_IDLE;
        SPI1.INTCTRL &= ~SPI_RXCIE_bm;

        if (SPI1_RxCompleteCallback != NULL)
        {
            SPI1_RxCompleteCallback();
        }
        else
        {
            ; // No transfer complete callback defined
        }
    }
}

/* cppcheck-suppress misra-c2012-8.2 */
/* cppcheck-suppress misra-c2012-8.4 */
ISR(SPI1_INT_vect){
    SPI1_ISR();
}