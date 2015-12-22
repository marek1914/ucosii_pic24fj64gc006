
/**
  TMR2Generated Driver API Source File 

  @Company
    Microchip Technology Inc.

  @File Name
    tmr4.c

  @Summary
    This is the generated source file for the TMR2 driver using MPLAB� Code Configurator

  @Description
    This source file provides APIs for driver for TMR2. 
    Generation Information : 
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC24FJ64GC006
        Driver Version    :  0.5
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.24
        MPLAB 	          :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
 */

#include <xc.h>
#include "tmr2.h"

/**
  Section: Data Type Definitions
 */

/** TMR Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintainence of the hardware instance.

  @Description
    This defines the object required for the maintainence of the hardware
    instance. This object exists once per hardware instance of the peripheral.

  Remarks:
    None.
 */


/**
  Section: Driver Interface
 */


void TMR2_Initialize(void) {
    //TCKPS 1:64; TON enabled; TSIDL disabled; TCS LPRC; TGATE disabled; 
    T2CON = 0x8222;
    //TMR2 0; 
    TMR2 = 0x0000;
    //Period Value = 100ms; PR4 50   ; 
    PR2 = 0x0032;

    IFS0bits.T2IF = false;
    IEC0bits.T2IE = true;

}

#if 0
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt() {
    /* Check if the Timer Interrupt/Status is set */
    tmr2_obj.count++;
    IFS0bits.T2IF = false;
}
#endif

void TMR2_Period16BitSet(uint16_t value) {
    /* Update the counter values */
    PR2 = value;
}

uint16_t TMR2_Period16BitGet(void) {
    return ( PR2);
}


void TMR2_Counter16BitSet(uint16_t value) {
    /* Update the counter values */
    TMR2 = value;
}

uint16_t TMR2_Counter16BitGet(void) {
    return ( TMR2);
}

void TMR2_Start(void) {
    /*Enable the interrupt*/
    IEC0bits.T2IE = true;

    /* Start the Timer */
    T2CONbits.TON = 1;
}

void TMR2_Stop(void) {
    /* Stop the Timer */
    T2CONbits.TON = false;

    /*Disable the interrupt*/
    IEC0bits.T2IE = false;
}

/**
 End of File
 */
