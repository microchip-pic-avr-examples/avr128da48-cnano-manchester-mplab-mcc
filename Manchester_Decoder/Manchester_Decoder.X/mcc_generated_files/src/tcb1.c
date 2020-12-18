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


#include "../include/tcb1.h"

/**
 * \brief Initialize tcb interface
 *
 * \return Initialization status.
 */
void (*TCB1_OVF_isr_cb)(void) = NULL;

void TCB1_SetOvfIsrCallback(TCB1_cb_t cb)
{
	TCB1_OVF_isr_cb = cb;
}

void (*TCB1_CAPT_isr_cb)(void) = NULL;

void TCB1_SetCaptIsrCallback(TCB1_cb_t cb)
{
	TCB1_CAPT_isr_cb = cb;
}

ISR(TCB1_INT_vect)
{
	/* Insert your TCB interrupt handling code */

	/**
	 * The interrupt flag is cleared by writing 1 to it, or when the Capture register
	 * is read in Capture mode
	 */
	 if(TCB1.INTFLAGS & TCB_CAPT_bm)
        {
            if (TCB1_CAPT_isr_cb != NULL)
            {
                (*TCB1_CAPT_isr_cb)();
            }

            TCB1.INTFLAGS = TCB_CAPT_bm;
        }

        /**
	 * The Overflow interrupt flag is cleared by writing 1 to it.
	 */
	 if(TCB1.INTFLAGS & TCB_OVF_bm)
        {
            if (TCB1_OVF_isr_cb != NULL)
            {
                (*TCB1_OVF_isr_cb)();
            }

            TCB1.INTFLAGS = TCB_OVF_bm;
        }
	 
}

/**
 * \brief Initialize TCB interface
 */
int8_t TCB1_Initialize()
{
    //Compare or Capture
    TCB1.CCMP = 0x47;

    //Count
    TCB1.CNT = 0x00;

    //ASYNC enabled; CCMPINIT disabled; CCMPEN enabled; CNTMODE SINGLE; 
    TCB1.CTRLB = 0x56;

    //DBGRUN disabled; 
    TCB1.DBGCTRL = 0x00;

    //FILTER disabled; EDGE disabled; CAPTEI enabled; 
    TCB1.EVCTRL = 0x01;

    //OVF disabled; CAPT disabled; 
    TCB1.INTCTRL = 0x00;

    //OVF disabled; CAPT disabled; 
    TCB1.INTFLAGS = 0x00;

    //Temporary Value
    TCB1.TEMP = 0x00;

    //RUNSTDBY disabled; CASCADE disabled; SYNCUPD disabled; CLKSEL DIV1; ENABLE enabled; 
    TCB1.CTRLA = 0x01;

    return 0;
}

void TCB1_WriteTimer(uint16_t timerVal)
{
	TCB1.CNT=timerVal;
}

uint16_t TCB1_ReadTimer(void)
{
	uint16_t readVal;

	readVal = TCB1.CNT;

	return readVal;
}

void TCB1_EnableCaptInterrupt(void)
{
	TCB1.INTCTRL |= TCB_CAPT_bm; /* Capture or Timeout: enabled */
}

void TCB1_EnableOvfInterrupt(void)
{
	TCB1.INTCTRL |= TCB_OVF_bm; /* Overflow Interrupt: enabled */
}

void TCB1_DisableCaptInterrupt(void)
{
	TCB1.INTCTRL &= ~TCB_CAPT_bm; /* Capture or Timeout: disabled */

}

void TCB1_DisableOvfInterrupt(void)
{
	TCB1.INTCTRL &= ~TCB_OVF_bm; /* Overflow Interrupt: disabled */

}

inline void TCB1_ClearCaptInterruptFlag(void)
{
	TCB1.INTFLAGS &= ~TCB_CAPT_bm;

}

inline void TCB1_ClearOvfInterruptFlag(void)
{
	TCB1.INTFLAGS &= ~TCB_OVF_bm;

}

inline bool TCB1_IsCaptInterruptEnabled(void)
{
        return ((TCB1.INTCTRL & TCB_CAPT_bm) > 0);
}

inline bool TCB1_IsOvfInterruptEnabled(void)
{
        return ((TCB1.INTCTRL & TCB_OVF_bm) > 0);
}


