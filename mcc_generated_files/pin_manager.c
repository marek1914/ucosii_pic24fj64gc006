/**
  System Interrupts Generated Driver File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the MPLAB� Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB� Code Configurator interrupts.
    Generation Information : 
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC24FJ64GC006
        Version           :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.24
        MPLAB             :  MPLAB X v2.35 or v3.00
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
    Section: Includes
 */
#include <xc.h>
#include "pin_manager.h"

/**
    void PIN_MANAGER_Initialize(void)
 */
void PIN_MANAGER_Initialize(void) {
    /****************************************************************************
     * Setting the GPIO of PORTB
     ***************************************************************************/
    LATB = 0x00;
    TRISB = 0xF0D1;
    /****************************************************************************
     * Setting the GPIO of PORTC
     ***************************************************************************/
    LATC = 0x00;
    TRISC = 0x9000;
    /****************************************************************************
     * Setting the GPIO of PORTD
     ***************************************************************************/
    LATD = 0x00;
    TRISD = 0x0FFF;
    /****************************************************************************
     * Setting the GPIO of PORTE
     ***************************************************************************/
    LATE = 0x00;
    TRISE = 0xDF;
    /****************************************************************************
     * Setting the GPIO of PORTF
     ***************************************************************************/
    LATF = 0x00;
    TRISF = 0x8B;
    /****************************************************************************
     * Setting the GPIO of PORTG
     ***************************************************************************/
    LATG = 0x00;
    TRISG = 0xC8;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR
     ***************************************************************************/
    ANSB = 0x10C1;
    ANSD = 0x0FFF;
    ANSE = 0xD0;
    ANSF = 0x89;
    ANSG = 0x0240;

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    RPINR19bits.U2RXR = 0x1C; // RB4->UART2:U2RX
    RPOR9bits.RP18R = 0x05; // RB5->UART2:U2TX
    RPINR7bits.IC2R = 0x0E; // RB14->IC2:IC2
    RPINR8bits.IC3R = 0x1D; // RB15->IC3:IC3
    RPINR18bits.U1RXR = 0x1A; // RG7->UART1:U1RX
    RPOR9bits.RP19R = 0x03; // RG8->UART1:U1TX
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
}
