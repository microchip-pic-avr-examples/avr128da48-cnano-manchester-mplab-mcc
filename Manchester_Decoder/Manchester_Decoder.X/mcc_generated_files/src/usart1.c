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


#include "../include/usart1.h"


void USART1_Initialize()
{
    //set baud rate register
    USART1.BAUD = (uint16_t)USART1_BAUD_RATE(38400);
	
    //RXCIE disabled; TXCIE disabled; DREIE disabled; RXSIE disabled; LBME disabled; ABEIE disabled; RS485 DISABLE; 
    USART1.CTRLA = 0x00;
	
    //RXEN disabled; TXEN enabled; SFDEN disabled; ODME disabled; RXMODE NORMAL; MPCM disabled; 
    USART1.CTRLB = 0x40;
	
    //CMODE ASYNCHRONOUS; PMODE DISABLED; SBMODE 1BIT; CHSIZE 8BIT; UDORD disabled; UCPHA disabled; 
    USART1.CTRLC = 0x03;
	
    //DBGCTRL_DBGRUN
    USART1.DBGCTRL = 0x00;
	
    //EVCTRL_IREI
    USART1.EVCTRL = 0x00;
	
    //RXPLCTRL_RXPL
    USART1.RXPLCTRL = 0x00;
	
    //TXPLCTRL_TXPL
    USART1.TXPLCTRL = 0x00;
	

}

void USART1_Enable()
{
    USART1.CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
}

void USART1_EnableRx()
{
    USART1.CTRLB |= USART_RXEN_bm;
}

void USART1_EnableTx()
{
    USART1.CTRLB |= USART_TXEN_bm;
}

void USART1_Disable()
{
    USART1.CTRLB &= ~(USART_RXEN_bm | USART_TXEN_bm);
}

uint8_t USART1_GetData()
{
    return USART1.RXDATAL;
}

bool USART1_IsTxReady()
{
    return (USART1.STATUS & USART_DREIF_bm);
}

bool USART1_IsRxReady()
{
    return (USART1.STATUS & USART_RXCIF_bm);
}

bool USART1_IsTxBusy()
{
    return (!(USART1.STATUS & USART_TXCIF_bm));
}

bool USART1_IsTxDone()
{
    return (USART1.STATUS & USART_TXCIF_bm);
}

uint8_t USART1_Read()
{
    while (!(USART1.STATUS & USART_RXCIF_bm))
            ;
    return USART1.RXDATAL;
}

void USART1_Write(const uint8_t data)
{
    while (!(USART1.STATUS & USART_DREIF_bm))
            ;
    USART1.TXDATAL = data;
}