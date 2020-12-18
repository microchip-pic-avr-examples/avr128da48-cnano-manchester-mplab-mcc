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


#include "../include/ccl.h"

int8_t CCL_Initialize()
{
    //INTMODE3 INTDISABLE; INTMODE2 INTDISABLE; INTMODE1 INTDISABLE; INTMODE0 INTDISABLE; 
    CCL.INTCTRL0 = 0x00;
    
    //INTMODE5 INTDISABLE; INTMODE4 INTDISABLE; 
    CCL.INTCTRL1 = 0x00;
    
    //INT5 disabled; INT4 disabled; INT3 disabled; INT2 disabled; INT1 disabled; INT0 disabled; 
    CCL.INTFLAGS = 0x00;
        
    //INSEL1 MASK; INSEL0 MASK; 
    CCL.LUT0CTRLB = 0x00;
    
    //INSEL2 MASK; 
    CCL.LUT0CTRLC = 0x00;
    
    //INSEL1 MASK; INSEL0 MASK; 
    CCL.LUT1CTRLB = 0x00;
    
    //INSEL2 MASK; 
    CCL.LUT1CTRLC = 0x00;
    
    //INSEL1 EVENTA; INSEL0 USART0; 
    CCL.LUT2CTRLB = 0x38;
    
    //INSEL2 MASK; 
    CCL.LUT2CTRLC = 0x00;
    
    //INSEL1 MASK; INSEL0 MASK; 
    CCL.LUT3CTRLB = 0x00;
    
    //INSEL2 MASK; 
    CCL.LUT3CTRLC = 0x00;
    
    //INSEL1 MASK; INSEL0 MASK; 
    CCL.LUT4CTRLB = 0x00;
    
    //INSEL2 MASK; 
    CCL.LUT4CTRLC = 0x00;
    
    //INSEL1 MASK; INSEL0 MASK; 
    CCL.LUT5CTRLB = 0x00;
    
    //INSEL2 MASK; 
    CCL.LUT5CTRLC = 0x00;
    
    //SEQSEL0 DISABLE; 
    CCL.SEQCTRL0 = 0x00;
    
    //SEQSEL1 DISABLE; 
    CCL.SEQCTRL1 = 0x00;
    
    //SEQSEL2 DISABLE; 
    CCL.SEQCTRL2 = 0x00;
    
    //
    CCL.TRUTH0 = 0x00;
    
    //
    CCL.TRUTH1 = 0x00;
    
    //
    CCL.TRUTH2 = 0x06;
    
    //
    CCL.TRUTH3 = 0x00;
    
    //
    CCL.TRUTH4 = 0x00;
    
    //
    CCL.TRUTH5 = 0x00;
    
    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
    CCL.LUT0CTRLA = 0x00;

    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
    CCL.LUT1CTRLA = 0x00;

    //EDGEDET DIS; OUTEN enabled; FILTSEL SYNCH; CLKSRC CLKPER; ENABLE enabled; 
    CCL.LUT2CTRLA = 0x51;

    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
    CCL.LUT3CTRLA = 0x00;

    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
    CCL.LUT4CTRLA = 0x00;

    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
    CCL.LUT5CTRLA = 0x00;

    //RUNSTDBY disabled; ENABLE enabled; 
    CCL.CTRLA = 0x01;

    return 0;
}
ISR(CCL_CCL_vect)
{
    /*
    * Insert your CCL interrupt handling code
    *
    * Interrupt flag can be cleared by writing 1 to its bit location
    * in the INTFLAGS register
    */
}