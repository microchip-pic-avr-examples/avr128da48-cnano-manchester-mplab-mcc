
/**
  * TCB2 Generated Driver File
  *
  * @file tcb2.c
  *
  * @ingroup tcb2
  *
  * @brief This file contains the API implementation for the TCB2 module driver.
  *
  * @version TCB2 Driver Version 2.0.0
  *
  * @version Package Version 6.0.0
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

#include "../tcb2.h"


/**
 * Section: Global Variables Definitions
*/
static void (*TCB2_OVF_isr_cb)(void);
static void TCB2_DefaultOverflowCallback(void);
static void (*TCB2_CAPT_isr_cb)(void);
static void TCB2_DefaultCaptureCallback(void);

void TCB2_Initialize(void)
{
    TCB2.CTRLA &= ~TCB_ENABLE_bm; /* Stop Timer */

    TCB2.CTRLB = (0 << TCB_ASYNC_bp)   // ASYNC disabled
        | (0 << TCB_CCMPEN_bp)   // CCMPEN disabled
        | (0 << TCB_CCMPINIT_bp)   // CCMPINIT disabled
        | (TCB_CNTMODE_TIMEOUT_gc);  // CNTMODE TIMEOUT

    TCB2.DBGCTRL = (0 << TCB_DBGRUN_bp);  // DBGRUN disabled

    TCB2.EVCTRL = (1 << TCB_CAPTEI_bp)   // CAPTEI enabled
        | (0 << TCB_EDGE_bp)   // EDGE disabled
        | (1 << TCB_FILTER_bp);  // FILTER enabled

    TCB2.CCMP = 0x2326U;  // CCMP 0x2326

    TCB2.CNT = 0x0;  // CNT 0xNAN

    TCB2.INTFLAGS = (0 << TCB_CAPT_bp)   // CAPT disabled
        | (0 << TCB_OVF_bp);  // OVF disabled
    
	/* cppcheck-suppress misra-c2012-8.7 */
    TCB2_OverflowCallbackRegister(TCB2_DefaultOverflowCallback);
	/* cppcheck-suppress misra-c2012-8.7 */
    TCB2_CaptureCallbackRegister(TCB2_DefaultCaptureCallback);

    TCB2.INTCTRL = (1 << TCB_CAPT_bp)   // CAPT enabled
        | (0 << TCB_OVF_bp);  // OVF disabled

    TCB2.CTRLA = (0 << TCB_CASCADE_bp)   // CASCADE disabled
        | (TCB_CLKSEL_DIV1_gc)   // CLKSEL DIV1
        | (1 << TCB_ENABLE_bp)   // ENABLE enabled
        | (0 << TCB_RUNSTDBY_bp)   // RUNSTDBY disabled
        | (0 << TCB_SYNCUPD_bp);  // SYNCUPD disabled
}

void TCB2_Deinitialize(void)
{
    TCB2.CTRLA &= ~TCB_ENABLE_bm; /* Stop Timer */
    
    TCB2.CCMP = 0x0;

    TCB2.CNT = 0x0;
    
    TCB2.CTRLB = 0x0;

    TCB2.DBGCTRL = 0x0;

    TCB2.EVCTRL = 0x0;

    TCB2.INTCTRL = 0x0;

    TCB2.TEMP = 0x0;

    TCB2.CTRLA = 0x0;
    
    TCB2.INTFLAGS = ~0x0;
}

void TCB2_Start(void)
{
    TCB2.CTRLA |= TCB_ENABLE_bm; /* Start Timer */
}

void TCB2_Stop(void)
{
    TCB2.CTRLA &= ~TCB_ENABLE_bm; /* Stop Timer */
}

void TCB2_CounterSet(uint16_t timerVal)
{
    TCB2.CNT = timerVal;
}

uint16_t TCB2_CounterGet(void)
{
    uint16_t readVal;

    readVal = TCB2.CNT;

    return readVal;
}
void TCB2_PeriodSet(uint16_t periodVal)
{
    TCB2.CCMP = (uint16_t) periodVal;
}

uint16_t TCB2_PeriodGet(void)
{
    return (uint16_t)TCB2.CCMP;
}

uint16_t TCB2_MaxCountGet(void)
{
    return TCB2_MAX_COUNT;
}

void TCB2_CAPTInterruptEnable(void)
{
    TCB2.INTCTRL |= TCB_CAPT_bm; /* Capture or Timeout: enabled */
}

void TCB2_CAPTInterruptDisable(void)
{
    TCB2.INTCTRL &= ~TCB_CAPT_bm; /* Capture or Timeout: disabled */
}

void TCB2_OVFInterruptEnable(void)
{
	TCB2.INTCTRL |= TCB_OVF_bm; /* Overflow Interrupt: enabled */
}

void TCB2_OVFInterruptDisable(void)
{
	TCB2.INTCTRL &= ~TCB_OVF_bm; /* Overflow Interrupt: disabled */
}


bool TCB2_IsCaptInterruptEnabled(void)
{
    return ((TCB2.INTCTRL & TCB_CAPT_bm) > 0);
}

bool TCB2_IsOvfInterruptEnabled(void)
{
    return ((TCB2.INTCTRL & TCB_OVF_bm) > 0);
}


/* cppcheck-suppress misra-c2012-8.7 */
void TCB2_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
	TCB2_OVF_isr_cb = CallbackHandler;
}

static void TCB2_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use TCB2_OverflowCallbackRegister function to use Custom ISR
}

/* cppcheck-suppress misra-c2012-8.7 */
void TCB2_CaptureCallbackRegister(void (* CallbackHandler)(void))
{
	TCB2_CAPT_isr_cb = CallbackHandler;
}

static void TCB2_DefaultCaptureCallback(void)
{
    //Add your Capture interrupt code here or
    //Use TCB2_CaptureCallbackRegister function to use Custom ISR
}

/* cppcheck-suppress misra-c2012-2.7 */
/* cppcheck-suppress misra-c2012-8.2 */
/* cppcheck-suppress misra-c2012-8.4 */
ISR(TCB2_INT_vect)
{
	if (0U != (TCB2.INTFLAGS & TCB_CAPT_bm))
    {
        if (TCB2_CAPT_isr_cb != NULL)
        {
            (*TCB2_CAPT_isr_cb)();
        }
        TCB2.INTFLAGS = TCB_CAPT_bm;
    }
    if (0U != (TCB2.INTFLAGS & TCB_OVF_bm))
    {
        if (TCB2_OVF_isr_cb != NULL)
        {
            (*TCB2_OVF_isr_cb)();
        }
        TCB2.INTFLAGS = TCB_OVF_bm;
    }
}

