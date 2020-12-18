/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#include "../include/spi1.h"
#include "../include/pin_manager.h"

typedef struct spi1_descriptor_s {
    spi1_transfer_status_t status;
} spi1_descriptor_t;

spi1_configuration_t spi1_configurations[] = {
    { 0x15, 0x80 }
};

static spi1_descriptor_t spi1_desc;

uint8_t SPI1_Initialize()
{
    //DORD disabled; MASTER disabled; CLK2X disabled; PRESC DIV4; ENABLE enabled; 
    SPI1.CTRLA = 0x01;

    //BUFEN enabled; BUFWR disabled; SSD disabled; MODE 0; 
    SPI1.CTRLB = 0x80;

    //RXCIE enabled; TXCIE disabled; DREIE disabled; SSIE disabled; IE enabled; 
    SPI1.INTCTRL = 0x81;

    spi1_desc.status = SPI1_FREE;

    //RXCIF disabled; IF disabled; TXCIF disabled; WRCOL disabled; DREIF disabled; SSIF disabled; BUFOVF disabled; 
    SPI1.INTFLAGS = 0x00;

    return 0;
}

void SPI1_Enable()
{
    SPI1.CTRLA |= SPI_ENABLE_bm;
}

void SPI1_Disable()
{
    SPI1.CTRLA &= ~SPI_ENABLE_bm;
}

bool SPI1_OpenConfiguration(uint8_t spiUniqueConfiguration){
    return SPI1_Open(spi1_configurations[spiUniqueConfiguration]);
}

bool SPI1_Open(spi1_configuration_t spiUniqueConfiguration)
{
    if (spi1_desc.status == SPI1_FREE) {
        spi1_desc.status = SPI1_IDLE;
        SPI1.CTRLA                = spiUniqueConfiguration.CTRLAvalue;
        SPI1.CTRLB                = spiUniqueConfiguration.CTRLBvalue;
        return true;
    } else {
        return false;
    }
}

void SPI1_Close(void)
{
    spi1_desc.status = SPI1_FREE;
}

uint8_t SPI1_ExchangeByte(uint8_t data)
{
    SPI1.DATA = data;
    while (!(SPI1.INTFLAGS & SPI_RXCIF_bm));
    return SPI1.DATA;
}

bool SPI1_Selected()
{
/**
 * \brief returns true if SS pin is selected 
 * TODO: Place your code
 */
return true;
}

uint8_t SPI1_GetRxData()
{
    return SPI1.DATA;
}

void SPI1_WriteTxData(uint8_t data)
{
    SPI1.DATA = data;
}

void SPI1_WaitDataready()
{
    while (!(SPI1.INTFLAGS & SPI_RXCIF_bm))
        ;
}

void SPI1_ExchangeBlock(void *block, size_t size)
{
    uint8_t *b = (uint8_t *)block;
    while (size--) {
        SPI1.DATA = *b;
        while (!(SPI1.INTFLAGS & SPI_RXCIF_bm))
            ;
        *b = SPI1.DATA;
        b++;
    }
}

void SPI1_WriteBlock(void *block, size_t size)
{
    uint8_t *b = (uint8_t *)block;
    uint8_t  rdata;
    while (size--) {
        SPI1.DATA = *b;
        while (!(SPI1.INTFLAGS & SPI_RXCIF_bm))
            ;
        rdata = SPI1.DATA;
        (void)(rdata); // Silence compiler warning
        b++;
    }
}

void SPI1_ReadBlock(void *block, size_t size)
{
    uint8_t *b = (uint8_t *)block;
    while (size--) {
        SPI1.DATA = 0;
        while (!(SPI1.INTFLAGS & SPI_RXCIF_bm))
            ;
        *b = SPI1.DATA;
        b++;
    }
}

void SPI1_WriteByte(uint8_t data)
{

    SPI1.DATA = data;
}

uint8_t SPI1_ReadByte()
{
    return SPI1.DATA;
}