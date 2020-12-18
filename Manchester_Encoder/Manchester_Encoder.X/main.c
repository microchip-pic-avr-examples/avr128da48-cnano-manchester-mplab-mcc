/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. 
    
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

#include "mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <util/delay.h>
#include <util/atomic.h>
#include "fifo.h"

#define START_BYTE                              0x01    /* Start byte used for clock synch */
#define MANCHESTER_BAUD_RATE                    16000   /* Manchester communication baud rate */
#define USART0_SPI_MODE_BAUD_RATE(BAUD_RATE)    (((float)24000000 * 64 / (2 * (float)BAUD_RATE)) + 0.5)
#define SET_MANCHESTER_BAUD_RATE()              do { USART0.BAUD = (uint16_t)USART0_SPI_MODE_BAUD_RATE(MANCHESTER_BAUD_RATE); } while (0)
#define GAP_DURATION                            (32000000UL / MANCHESTER_BAUD_RATE)


int main(void)
{
    uint8_t data;
    bool    fifo_is_empty;
	bool    break_flag = false;

    SYSTEM_Initialize();
    
    FIFO_Init();
    SET_MANCHESTER_BAUD_RATE();

    while (1)
    {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            fifo_is_empty = FIFO_Get(&data);
        }
        if(fifo_is_empty == false)
        {
            if(break_flag == true)
            {
                break_flag = false;                               
                while(!USART0_IsTxReady())
                 ;
                _delay_us(GAP_DURATION);     
                USART0_Write(START_BYTE);
            }
            USART0_Write(data);
        } 
        else
        {    
            break_flag = true;
        }   
        PORTC.OUTSET = PIN6_bm;    /* turn on-board LED OFF */  
    }
}

ISR(USART1_RXC_vect)
{
    uint8_t receivedByte;  
    receivedByte = USART1_Read();   /* Read the received byte */  
    /* Store the received byte in the FIFO buffer */
    if(true == FIFO_Put(receivedByte))
    {  
        PORTC.OUTCLR = PIN6_bm;    /* turn on-board LED ON if FIFO buffer is full */ 
    }
}