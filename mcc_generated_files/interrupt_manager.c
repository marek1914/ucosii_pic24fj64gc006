/**
  System Interrupts Generated Driver File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

  @Summary:
    This is the generated driver implementation file for setting up the
    interrupts using MPLAB� Code Configurator

  @Description:
    This source file provides implementations for MPLAB� Code Configurator interrupts.
    Generation Information : 
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC24FJ64GC006
        Version           :  1.01
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

/**
    void INTERRUPT_Initialize (void)
 */
void INTERRUPT_Initialize(void) {
    //    URXI: U2RX - UART2 Receiver
    //    Priority: 3
    IPC7bits.U2RXIP = 1;
    //    UERI: U2E - UART2 Error
    //    Priority: 3
    IPC16bits.U2ERIP = 1;
    //    ICI_INT: IC3 - Input Capture 3
    //    Priority: 2
    IPC9bits.IC3IP = 2;
    //    ICI_INT: IC2 - Input Capture 2
    //    Priority: 2
    IPC1bits.IC2IP = 2;
    //    UTXI: U2TX - UART2 Transmitter
    //    Priority: 3
    IPC7bits.U2TXIP = 1;
        //    CNIP: CN31
    //    priority: 2
    IPC4bits.CNIP = 2;
    //    DMA: DMA Channel0
    //    priority: 5
    IPC1bits.DMA0IP = 5;
    //    TI: T4 - Timer4
    //    Priority: 1
    IPC6bits.T4IP = 1;
    //    TI: T5 - Timer5
    //    Priority: 1
    IPC7bits.T5IP = 1;

}
