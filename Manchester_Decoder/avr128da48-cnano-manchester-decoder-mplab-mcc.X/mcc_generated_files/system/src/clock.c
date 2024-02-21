/**
 * CLKCTRL Generated Driver File
 * 
 * @file clkctrl.c
 * 
 * @ingroup  clkctrl
 * 
 * @brief This file contains the API implementation for the CLKCTRL driver.
 *
 * @version CLKCTRL Driver Version 1.0.1
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


#include "../clock.h"

void CLOCK_Initialize(void)
{    
    //CLKOUT disabled; CLKSEL Internal high-frequency oscillator; 
    ccp_write_io((void*)&(CLKCTRL.MCLKCTRLA),0x0);

    //PDIV 2X; PEN disabled; 
    ccp_write_io((void*)&(CLKCTRL.MCLKCTRLB),0x0);

    //LOCKEN disabled; 
    ccp_write_io((void*)&(CLKCTRL.MCLKLOCK),0x0);

    //EXTS disabled; OSCHFS disabled; OSC32KS disabled; PLLS disabled; SOSC disabled; XOSC32KS disabled; 
    ccp_write_io((void*)&(CLKCTRL.MCLKSTATUS),0x0);

    //AUTOTUNE disabled; FRQSEL 24 MHz system clock; RUNSTDBY disabled; 
    ccp_write_io((void*)&(CLKCTRL.OSCHFCTRLA),0x24);

    //TUNE 0x0; 
    ccp_write_io((void*)&(CLKCTRL.OSCHFTUNE),0x0);

    //RUNSTDBY disabled; 
    ccp_write_io((void*)&(CLKCTRL.OSC32KCTRLA),0x0);

    //MULFAC PLL is disabled; RUNSTDBY disabled; SOURCE disabled; 
    ccp_write_io((void*)&(CLKCTRL.PLLCTRLA),0x0);

    //CSUT 1k cycles; ENABLE disabled; LPMODE disabled; RUNSTDBY disabled; SEL disabled; 
    ccp_write_io((void*)&(CLKCTRL.XOSC32KCTRLA),0x0);

}

/**
 End of File
*/