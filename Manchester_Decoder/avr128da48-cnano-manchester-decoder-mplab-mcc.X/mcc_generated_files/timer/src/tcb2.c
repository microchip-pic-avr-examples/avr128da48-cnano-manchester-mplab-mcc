/**
  * TCB2 Generated Driver File
  *
  * @file tcb2.c
  *
  * @ingroup tcb2
  *
  * @brief This file contains the API implementation for the TCB2 module driver.
  *
  * @version TCB2 Driver Version 1.1.5
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

#include "../tcb2.h"

const struct TMR_INTERFACE TCB2_Interface = {
    .Initialize = TCB2_Initialize,
    .Start = TCB2_Start,
    .Stop = TCB2_Stop,
    .PeriodCountSet = TCB2_Write,
    .TimeoutCallbackRegister = NULL,
    .Tasks = NULL
};

void (*TCB2_OVF_isr_cb)(void) = NULL;

void TCB2_OverflowCallbackRegister(TCB2_cb_t cb)
{
	TCB2_OVF_isr_cb = cb;
}

void (*TCB2_CAPT_isr_cb)(void) = NULL;

void TCB2_CaptureCallbackRegister(TCB2_cb_t cb)
{
	TCB2_CAPT_isr_cb = cb;
}

ISR(TCB2_INT_vect)
{
	/* Insert your TCB interrupt handling code */
	/**
	 * The interrupt flag is cleared by writing 1 to it, or when the Capture register
	 * is read in Capture mode
	 */
	if(TCB2.INTFLAGS & TCB_CAPT_bm)
    {
        if (TCB2_CAPT_isr_cb != NULL)
        {
            (*TCB2_CAPT_isr_cb)();
        }

        TCB2.INTFLAGS = TCB_CAPT_bm;
    }
}

void TCB2_Initialize(void)
{
    // CCMP 4499; 
    TCB2.CCMP = 0x1193;

    // CNT undefined; 
    TCB2.CNT = 0x0;

    //ASYNC disabled; CCMPEN disabled; CCMPINIT disabled; CNTMODE TIMEOUT; 
    TCB2.CTRLB = 0x1;
    
    //DBGRUN disabled; 
    TCB2.DBGCTRL = 0x0;

    //CAPTEI enabled; EDGE disabled; FILTER enabled; 
    TCB2.EVCTRL = 0x41;

    //CAPT enabled; OVF disabled; 
    TCB2.INTCTRL = 0x1;

    //CAPT disabled; OVF disabled; 
    TCB2.INTFLAGS = 0x0;

    //Temporary Value
    TCB2.TEMP = 0x0;

    //CASCADE disabled; CLKSEL DIV2; ENABLE enabled; RUNSTDBY disabled; SYNCUPD disabled; 
    TCB2.CTRLA = 0x3;

}

void TCB2_Start(void)
{
    TCB2.CTRLA |= TCB_ENABLE_bm; /* Start Timer */
}

void TCB2_Stop(void)
{
    TCB2.CTRLA &= ~TCB_ENABLE_bm; /* Stop Timer */
}

void TCB2_Write(uint16_t timerVal)
{
    TCB2.CNT = timerVal;
}

uint16_t TCB2_Read(void)
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
    TCB2.INTFLAGS |= TCB_CAPT_bm;
}

inline bool TCB2_IsOvfInterruptFlag(void)
{
	return TCB2.INTFLAGS & TCB_OVF_bm;
}

inline bool TCB2_IsCaptInterruptFlag(void)
{
	return TCB2.INTFLAGS & TCB_CAPT_bm;

}

inline void TCB2_ClearOvfInterruptFlag(void)
{
	TCB2.INTFLAGS |= TCB_OVF_bm;
}

inline bool TCB2_IsCaptInterruptEnabled(void)
{
    return ((TCB2.INTCTRL & TCB_CAPT_bm) > 0);
}

inline bool TCB2_IsOvfInterruptEnabled(void)
{
    return ((TCB2.INTCTRL & TCB_OVF_bm) > 0);
}

