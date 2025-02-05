
/**
  * TCB1 Generated Driver File
  *
  * @file tcb1.c
  *
  * @ingroup tcb1
  *
  * @brief This file contains the API implementation for the TCB1 module driver.
  *
  * @version TCB1 Driver Version 2.0.0
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

#include "../tcb1.h"


/**
 * Section: Global Variables Definitions
*/
static void (*TCB1_OVF_isr_cb)(void);
static void TCB1_DefaultOverflowCallback(void);
static void (*TCB1_CAPT_isr_cb)(void);
static void TCB1_DefaultCaptureCallback(void);

void TCB1_Initialize(void)
{
    TCB1.CTRLA &= ~TCB_ENABLE_bm; /* Stop Timer */

    TCB1.CTRLB = (1 << TCB_ASYNC_bp)   // ASYNC enabled
        | (1 << TCB_CCMPEN_bp)   // CCMPEN enabled
        | (0 << TCB_CCMPINIT_bp)   // CCMPINIT disabled
        | (TCB_CNTMODE_SINGLE_gc);  // CNTMODE SINGLE

    TCB1.DBGCTRL = (0 << TCB_DBGRUN_bp);  // DBGRUN disabled

    TCB1.EVCTRL = (1 << TCB_CAPTEI_bp)   // CAPTEI enabled
        | (0 << TCB_EDGE_bp)   // EDGE disabled
        | (0 << TCB_FILTER_bp);  // FILTER disabled

    TCB1.CCMP = 0x47U;  // CCMP 0x47

    TCB1.CNT = 0x0;  // CNT 0xNAN

    TCB1.INTFLAGS = (0 << TCB_CAPT_bp)   // CAPT disabled
        | (0 << TCB_OVF_bp);  // OVF disabled
    
	/* cppcheck-suppress misra-c2012-8.7 */
    TCB1_OverflowCallbackRegister(TCB1_DefaultOverflowCallback);
	/* cppcheck-suppress misra-c2012-8.7 */
    TCB1_CaptureCallbackRegister(TCB1_DefaultCaptureCallback);

    TCB1.INTCTRL = (0 << TCB_CAPT_bp)   // CAPT disabled
        | (0 << TCB_OVF_bp);  // OVF disabled

    TCB1.CTRLA = (0 << TCB_CASCADE_bp)   // CASCADE disabled
        | (TCB_CLKSEL_DIV1_gc)   // CLKSEL DIV1
        | (1 << TCB_ENABLE_bp)   // ENABLE enabled
        | (0 << TCB_RUNSTDBY_bp)   // RUNSTDBY disabled
        | (0 << TCB_SYNCUPD_bp);  // SYNCUPD disabled
}

void TCB1_Deinitialize(void)
{
    TCB1.CTRLA &= ~TCB_ENABLE_bm; /* Stop Timer */
    
    TCB1.CCMP = 0x0;

    TCB1.CNT = 0x0;
    
    TCB1.CTRLB = 0x0;

    TCB1.DBGCTRL = 0x0;

    TCB1.EVCTRL = 0x0;

    TCB1.INTCTRL = 0x0;

    TCB1.TEMP = 0x0;

    TCB1.CTRLA = 0x0;
    
    TCB1.INTFLAGS = ~0x0;
}

void TCB1_Start(void)
{
    TCB1.CTRLA |= TCB_ENABLE_bm; /* Start Timer */
}

void TCB1_Stop(void)
{
    TCB1.CTRLA &= ~TCB_ENABLE_bm; /* Stop Timer */
}

void TCB1_CounterSet(uint16_t timerVal)
{
    TCB1.CNT = timerVal;
}

uint16_t TCB1_CounterGet(void)
{
    uint16_t readVal;

    readVal = TCB1.CNT;

    return readVal;
}
void TCB1_PeriodSet(uint16_t periodVal)
{
    TCB1.CCMP = (uint16_t) periodVal;
}

uint16_t TCB1_PeriodGet(void)
{
    return (uint16_t)TCB1.CCMP;
}

uint16_t TCB1_MaxCountGet(void)
{
    return TCB1_MAX_COUNT;
}



bool TCB1_CaptureStatusGet(void)
{
	return TCB1.INTFLAGS & TCB_CAPT_bm;
}

bool TCB1_OverflowStatusGet(void)
{
	return TCB1.INTFLAGS & TCB_OVF_bm;
}

void TCB1_CaptureStatusClear(void)
{
    TCB1.INTFLAGS |= TCB_CAPT_bm;
}

void TCB1_OverflowStatusClear(void)
{
	TCB1.INTFLAGS |= TCB_OVF_bm;
}

bool TCB1_IsCaptInterruptEnabled(void)
{
    return ((TCB1.INTCTRL & TCB_CAPT_bm) > 0);
}

bool TCB1_IsOvfInterruptEnabled(void)
{
    return ((TCB1.INTCTRL & TCB_OVF_bm) > 0);
}


/* cppcheck-suppress misra-c2012-8.7 */
void TCB1_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
	TCB1_OVF_isr_cb = CallbackHandler;
}

static void TCB1_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use TCB1_OverflowCallbackRegister function to use Custom ISR
}

/* cppcheck-suppress misra-c2012-8.7 */
void TCB1_CaptureCallbackRegister(void (* CallbackHandler)(void))
{
	TCB1_CAPT_isr_cb = CallbackHandler;
}

static void TCB1_DefaultCaptureCallback(void)
{
    //Add your Capture interrupt code here or
    //Use TCB1_CaptureCallbackRegister function to use Custom ISR
}


void TCB1_Tasks(void)
{
	if(0U != (TCB1.INTFLAGS & TCB_CAPT_bm))
    {
        if (TCB1_CAPT_isr_cb != NULL)
        {
            (*TCB1_CAPT_isr_cb)();
        }
        TCB1.INTFLAGS = TCB_CAPT_bm;
    }
	if(0U != (TCB1.INTFLAGS & TCB_OVF_bm))
    {
        if (TCB1_OVF_isr_cb != NULL)
        {
            (*TCB1_OVF_isr_cb)();
        }
        TCB1.INTFLAGS = TCB_OVF_bm;
    }
}
