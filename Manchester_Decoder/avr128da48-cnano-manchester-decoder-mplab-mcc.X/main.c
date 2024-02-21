 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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

#include "mcc_generated_files/system/system.h"
#include <stdbool.h>

void TCB2_Callback(void);

#define MANCHESTER_BAUD_RATE    16000   /* Manchester communication baud rate */
#define SET_TCB0_CMP_VALUE()    do { TCB0.CCMP = 0.625 * F_CPU / MANCHESTER_BAUD_RATE; } while (0)
#define SET_TCB2_CMP_VALUE()    do { TCB2.CCMP = 6 * F_CPU / MANCHESTER_BAUD_RATE; } while (0)
#define RESET_SPI1()            do { SPI1.CTRLA &= ~SPI_ENABLE_bm; SPI1.CTRLA |= SPI_ENABLE_bm; } while (0)

volatile bool waiting_for_SOF = true; 

int main(void)
{
    uint8_t bufferRead;
    
    SYSTEM_Initialize();
    
    TCB2_CaptureCallbackRegister(TCB2_Callback);
    SPI1_Open(CLIENT_CONFIG);
    
    SET_TCB0_CMP_VALUE();
    SET_TCB2_CMP_VALUE();

    while (1)
    {
        if (SPI1_IsRxReady() == true)
        {
            SPI1_BufferRead(&bufferRead,1);
            
            while(!(USART1_IsTxReady()))
                ;
            
            if(waiting_for_SOF == true)
                waiting_for_SOF = false;
            else
                USART1_Write(bufferRead);
        }
    }
}

void TCB2_Callback(void)
{            
    RESET_SPI1();   /* Reset the SPI1 peripheral*/
    waiting_for_SOF = true;
}