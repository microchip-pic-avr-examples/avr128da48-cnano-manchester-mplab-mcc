/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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

#include "mcc_generated_files/system/system.h"
#include <stdbool.h>
#include <util/delay.h>

#define START_BYTE                              0x01    /* Start byte used for clock synch */
#define MANCHESTER_BAUD_RATE                    16000   /* Manchester communication baud rate */
#define USART0_SPI_MODE_BAUD_RATE(BAUD_RATE)    (((float) F_CPU * 64 / (2 * (float)BAUD_RATE)) + 0.5)
#define SET_MANCHESTER_BAUD_RATE()              do { USART0.BAUD = (uint16_t)USART0_SPI_MODE_BAUD_RATE(MANCHESTER_BAUD_RATE); } while (0)
#define GAP_DURATION                            (F_CPU / MANCHESTER_BAUD_RATE)

void USART0_Set_SPI_Host_Mode(void);

int main(void)
{
    uint8_t receivedByte;
	bool    break_flag = false;

    SYSTEM_Initialize();
    SET_MANCHESTER_BAUD_RATE();
    SPI0_Open(HOST_CONFIG);

    while (1)
    {
        if(USART1_IsRxReady() == true)
        {   
            receivedByte = USART1_Read();
            
            if(break_flag == true)
            {
                break_flag = false;
                _delay_us(GAP_DURATION);
                while(!SPI0_IsTxReady())
                    ;    
                SPI0_ByteWrite(START_BYTE);
            }
            
            while(!SPI0_IsTxReady())
                ;
            SPI0_ByteWrite(receivedByte);
        }
        else
        {
            break_flag = true;
        }
    }
}