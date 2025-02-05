

/**
 * CLKCTRL Generated Driver File
 * 
 * @file clkctrl.c
 * 
 * @ingroup  clkctrl
 * 
 * @brief This file contains the API implementation for the CLKCTRL driver.
 *
 * @version CLKCTRL Driver Version 1.0.2
 *
 * @version Package Version 5.3.6
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


#include "../clock.h"

void CLOCK_Initialize(void)
{    
    ccp_write_io((void*)&(CLKCTRL.MCLKCTRLA),(0 << CLKCTRL_CLKOUT_bp)   // CLKOUT disabled
            | CLKCTRL_CLKSEL_OSCHF_gc   // CLKSEL Internal high-frequency oscillator
            );
    ccp_write_io((void*)&(CLKCTRL.MCLKCTRLB),CLKCTRL_PDIV_2X_gc   // PDIV 2X
            | (0 << CLKCTRL_PEN_bp)   // PEN disabled
            );
    ccp_write_io((void*)&(CLKCTRL.MCLKLOCK),(0 << CLKCTRL_LOCKEN_bp)   // LOCKEN disabled
            );
    ccp_write_io((void*)&(CLKCTRL.MCLKSTATUS),(0 << CLKCTRL_EXTS_bp)   // EXTS disabled
            | (0 << CLKCTRL_OSCHFS_bp)   // OSCHFS disabled
            | (0 << CLKCTRL_OSC32KS_bp)   // OSC32KS disabled
            | (0 << CLKCTRL_PLLS_bp)   // PLLS disabled
            | (0 << CLKCTRL_SOSC_bp)   // SOSC disabled
            | (0 << CLKCTRL_XOSC32KS_bp)   // XOSC32KS disabled
            );
    ccp_write_io((void*)&(CLKCTRL.OSCHFCTRLA),(0 << CLKCTRL_AUTOTUNE_bp)   // AUTOTUNE disabled
            | CLKCTRL_FRQSEL_24M_gc   // FRQSEL 24 MHz system clock
            | (0 << CLKCTRL_RUNSTDBY_bp)   // RUNSTDBY disabled
            );
    ccp_write_io((void*)&(CLKCTRL.OSCHFTUNE),0x0   // TUNE 0x0
            );
    ccp_write_io((void*)&(CLKCTRL.OSC32KCTRLA),(0 << CLKCTRL_RUNSTDBY_bp)   // RUNSTDBY disabled
            );
    ccp_write_io((void*)&(CLKCTRL.PLLCTRLA),CLKCTRL_MULFAC_DISABLE_gc   // MULFAC PLL is disabled
            | (0 << CLKCTRL_RUNSTDBY_bp)   // RUNSTDBY disabled
            | (0 << CLKCTRL_SOURCE_bp)   // SOURCE disabled
            );
    ccp_write_io((void*)&(CLKCTRL.XOSC32KCTRLA),CLKCTRL_CSUT_1K_gc   // CSUT 1k cycles
            | (0 << CLKCTRL_ENABLE_bp)   // ENABLE disabled
            | (0 << CLKCTRL_LPMODE_bp)   // LPMODE disabled
            | (0 << CLKCTRL_RUNSTDBY_bp)   // RUNSTDBY disabled
            | (0 << CLKCTRL_SEL_bp)   // SEL disabled
            );
}

/**
 End of File
*/