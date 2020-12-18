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


#include "../include/tcb2.h"

/**
 * \brief Initialize tcb interface
 *
 * \return Initialization status.
 */
void (*TCB2_OVF_isr_cb)(void) = NULL;

void TCB2_SetOvfIsrCallback(TCB2_cb_t cb)
{
	TCB2_OVF_isr_cb = cb;
}

void (*TCB2_CAPT_isr_cb)(void) = NULL;

void TCB2_SetCaptIsrCallback(TCB2_cb_t cb)
{
	TCB2_CAPT_isr_cb = cb;
}

/**
 * \brief Initialize TCB interface
 */
int8_t TCB2_Initialize()
{
    //Compare or Capture
    TCB2.CCMP = 0x1193;

    //Count
    TCB2.CNT = 0x00;

    //ASYNC disabled; CCMPINIT disabled; CCMPEN enabled; CNTMODE TIMEOUT; 
    TCB2.CTRLB = 0x11;

    //DBGRUN disabled; 
    TCB2.DBGCTRL = 0x00;

    //FILTER enabled; EDGE disabled; CAPTEI enabled; 
    TCB2.EVCTRL = 0x41;

    //OVF disabled; CAPT enabled; 
    TCB2.INTCTRL = 0x01;

    //OVF disabled; CAPT disabled; 
    TCB2.INTFLAGS = 0x00;

    //Temporary Value
    TCB2.TEMP = 0x00;

    //RUNSTDBY disabled; CASCADE disabled; SYNCUPD disabled; CLKSEL DIV2; ENABLE enabled; 
    TCB2.CTRLA = 0x03;

    return 0;
}

void TCB2_WriteTimer(uint16_t timerVal)
{
	TCB2.CNT=timerVal;
}

uint16_t TCB2_ReadTimer(void)
{
	uint16_t readVal;

	readVal = TCB2.CNT;

	return readVal;
}

void TCB2_EnableCaptInterrupt(void)
{
	TCB2.INTCTRL |= TCB_CAPT_bm; /* Capture or Timeout: enabled */
}

void TCB2_EnableOvfInterrupt(void)
{
	TCB2.INTCTRL |= TCB_OVF_bm; /* Overflow Interrupt: enabled */
}

void TCB2_DisableCaptInterrupt(void)
{
	TCB2.INTCTRL &= ~TCB_CAPT_bm; /* Capture or Timeout: disabled */

}

void TCB2_DisableOvfInterrupt(void)
{
	TCB2.INTCTRL &= ~TCB_OVF_bm; /* Overflow Interrupt: disabled */

}

inline void TCB2_ClearCaptInterruptFlag(void)
{
	TCB2.INTFLAGS &= ~TCB_CAPT_bm;

}

inline void TCB2_ClearOvfInterruptFlag(void)
{
	TCB2.INTFLAGS &= ~TCB_OVF_bm;

}

inline bool TCB2_IsCaptInterruptEnabled(void)
{
        return ((TCB2.INTCTRL & TCB_CAPT_bm) > 0);
}

inline bool TCB2_IsOvfInterruptEnabled(void)
{
        return ((TCB2.INTCTRL & TCB_OVF_bm) > 0);
}


