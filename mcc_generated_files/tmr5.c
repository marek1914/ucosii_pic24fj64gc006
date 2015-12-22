
/**
  TMR5 Generated Driver API Source File 

  @Company
    Microchip Technology Inc.

  @File Name
    tmr5.c

  @Summary
    This is the generated source file for the TMR5 driver using MPLAB� Code Configurator

  @Description
    This source file provides APIs for driver for TMR5. 
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
#include "tmr5.h"

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

typedef struct _TMR_OBJ_STRUCT {
    /*Software Counter value*/
    uint16_t count;

} TMR_OBJ;

static TMR_OBJ tmr5_obj;

/**
  Section: Driver Interface
 */


void TMR5_Initialize(void) {
    
    //TCKPS 1:256; T32 disabled; TON enabled; TSIDL disabled; TCS FOSC/2; TECS SOSC; TGATE disabled; 
    T5CON = 0x8030;
    //TMR5 0; 
    TMR5 = 0x0000;
    //Period Value = 10.000 ms; PR5 625; 
    PR5 = 0x0271; 

    IFS1bits.T5IF = false;
    IEC1bits.T5IE = true;
    
    tmr5_obj.count = 0;
}


void __attribute__((interrupt, no_auto_psv)) _T5Interrupt() {
    /* Check if the Timer Interrupt/Status is set */
    tmr5_obj.count++;
    IFS1bits.T5IF = false;
}

void TMR5_Period16BitSet(uint16_t value) {
    /* Update the counter values */
    PR5 = value;
}


uint16_t TMR5_Period16BitGet(void) {
    return ( PR5);
}



void TMR5_Counter16BitSet(uint16_t value) {
    /* Update the counter values */
    TMR5 = value;
}


uint16_t TMR5_Counter16BitGet(void) {
    return ( TMR5);
}


void TMR5_Start(void) {
    /*Enable the interrupt*/
    IEC1bits.T5IE = true;

    /* Start the Timer */
    T5CONbits.TON = 1;
}


void TMR5_Stop(void) {
    /* Stop the Timer */
    T5CONbits.TON = false;

    /*Disable the interrupt*/
    IEC1bits.T5IE = false;
}


uint16_t TMR5_SoftwareCounterGet(void) {
    return tmr5_obj.count;
}


void TMR5_SoftwareCounterClear(void) {
    tmr5_obj.count = 0;
}


/**
 End of File
 */
