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
#include <util/atomic.h>
#include <stdbool.h>
#include "fifo.h"

#define MANCHESTER_BAUD_RATE    16000   /* Manchester communication baud rate */
#define SET_TCB0_CMP_VALUE()    do { TCB0.CCMP = 0.625 * F_CPU / MANCHESTER_BAUD_RATE; } while (0)
#define SET_TCB2_CMP_VALUE()    do { TCB2.CCMP = 6 * F_CPU / MANCHESTER_BAUD_RATE; } while (0)
#define RESET_SPI1()            do { SPI1.CTRLA &= ~SPI_ENABLE_bm; SPI1.CTRLA |= SPI_ENABLE_bm; } while (0)

volatile bool waiting_for_SOF = true;

int main(void)
{
    uint8_t data;
    bool fifo_is_empty;
    
    SYSTEM_Initialize();
    
    FIFO_Init();
    SET_TCB0_CMP_VALUE();
    SET_TCB2_CMP_VALUE();
    
    while (1)
    {   
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            fifo_is_empty = FIFO_Get(&data);
        }       
        if(fifo_is_empty == false)
        {  
            if(waiting_for_SOF == true)
            {
                waiting_for_SOF = false;
            }
            else
            {
                USART1_Write(data);
            }
        }
    }
}

ISR(SPI1_INT_vect)
{
    uint8_t received_byte;     
    received_byte = SPI1_GetRxData();    /* Read the received byte */
    /* Store the received byte in the FIFO buffer */
    if(true == FIFO_Put(received_byte))
    {
        /* insert code to signal FIFO buffer full (incoming data loss) */
    } 
	SPI1.INTFLAGS = SPI_RXCIF_bm;   /* Clear the interrupt flag */
}

ISR(TCB2_INT_vect)
{            
    RESET_SPI1();   /* Reset the SPI1 peripheral*/
    waiting_for_SOF = true;
	TCB2.INTFLAGS |= TCB_CAPT_bm;   /* Clear the interrupt flag */
}