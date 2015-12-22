/**
  UART2 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    uart2.c

  @Summary
    This is the generated source file for the UART2 driver using MPLAB� Code Configurator

  @Description
    This source file provides APIs for driver for UART2. 
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

#include "uart2.h"

/**
  Section: Data Type Definitions
 */

/** UART Driver Queue Status

  @Summary
    Defines the object required for the status of the queue.
 */

typedef union {

    struct {
        uint8_t full : 1;
        uint8_t empty : 1;
        uint8_t reserved : 6;
    } s;
    uint8_t status;
}

UART_BYTEQ_STATUS;

/** UART Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

 */
typedef struct {
    /* RX Byte Q */
    uint8_t *rxTail;

    uint8_t *rxHead;

    UART_BYTEQ_STATUS rxStatus;

} UART_OBJECT;

static UART_OBJECT uart2_obj;

/** UART Driver Queue Length

  @Summary
    Defines the length of the Transmit and Receive Buffers

 */

#define UART2_CONFIG_RX_BYTEQ_LENGTH 8


/** UART Driver Queue

  @Summary
    Defines the Transmit and Receive Buffers

 */

static uint8_t uart2_rxByteQ[UART2_CONFIG_RX_BYTEQ_LENGTH];

/** UART Hardware FIFO Buffer Length

  @Summary
    Defines the length of the Transmit and Receive FIFOs
 
 */

#define UART2_RX_FIFO_LENGTH 4 

/**
  Section: Driver Interface
 */


void UART2_Initialize(void) {
    // STSEL 1; IREN disabled; PDSEL 8N; UARTEN enabled; RTSMD enabled; USIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; URXINV disabled; UEN TX_RX; 
    U2MODE = 0x8808;
    // OERR NO_ERROR_cleared; UTXISEL0 TX_ONE_CHAR; URXISEL RX_ONE_CHAR; UTXBRK COMPLETED; UTXEN disabled; ADDEN disabled; UTXINV disabled; 
    U2STA = 0x0000;
    // U2TXREG 0x0000; 
    U2TXREG = 0x0000;
    // U2RXREG 0x0000; 
    U2RXREG = 0x0000;
    // Baud Rate = 115200; BRG 34; 
    U2BRG = 0x0022;

    IEC1bits.U2RXIE = 1;

    U2STAbits.UTXEN = 1;

    
    uart2_obj.rxHead = uart2_rxByteQ;
    uart2_obj.rxTail = uart2_rxByteQ;
    uart2_obj.rxStatus.s.empty = true;
    uart2_obj.rxStatus.s.full = false;
}

/**
    Maintains the driver's transmitter state machine and implements its ISR
 */
#if 0
void __attribute__((interrupt, no_auto_psv)) _U2TXInterrupt(void) {

    IFS1bits.U2TXIF = false;

}
#endif

void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void) {
    int count = 0;

    while ((count < UART2_RX_FIFO_LENGTH) && (U2STAbits.URXDA == 1)) {
        count++;

        *uart2_obj.rxTail = U2RXREG;

        uart2_obj.rxTail++;

        if (uart2_obj.rxTail == (uart2_rxByteQ + UART2_CONFIG_RX_BYTEQ_LENGTH)) {
            uart2_obj.rxTail = uart2_rxByteQ;
        }

        uart2_obj.rxStatus.s.empty = false;

        if (uart2_obj.rxTail == uart2_obj.rxHead) {
            //Sets the flag RX full
            uart2_obj.rxStatus.s.full = true;
            break;
        }

    }

    IFS1bits.U2RXIF = false;

}

void __attribute__((interrupt, no_auto_psv)) _U2ErrInterrupt(void) {
    if ((U2STAbits.OERR == 1)) {
        U2STAbits.OERR = 0;
    }

    IFS4bits.U2ERIF = false;
}

/**
  Section: UART Driver Client Routines
 */

uint8_t UART2_Read(void) {
    uint8_t data = 0;

    data = *uart2_obj.rxHead;

    uart2_obj.rxHead++;

    if (uart2_obj.rxHead == (uart2_rxByteQ + UART2_CONFIG_RX_BYTEQ_LENGTH)) {
        uart2_obj.rxHead = uart2_rxByteQ;
    }

    if (uart2_obj.rxHead == uart2_obj.rxTail) {
        uart2_obj.rxStatus.s.empty = true;
    }

    uart2_obj.rxStatus.s.full = false;

    return data;
}



unsigned int UART2_ReadBuffer(uint8_t *buffer, const unsigned int bufLen) {
    unsigned int numBytesRead = 0;
    while (numBytesRead < (bufLen) && (true != uart2_obj.rxStatus.s.empty)) {
        buffer[numBytesRead++] = UART2_Read();
    }
    return numBytesRead;
}


uint8_t UART2_Peek(uint16_t offset) {
    if ((uart2_obj.rxHead + offset) > (uart2_rxByteQ + UART2_CONFIG_RX_BYTEQ_LENGTH)) {
        return uart2_rxByteQ[offset - (uart2_rxByteQ + UART2_CONFIG_RX_BYTEQ_LENGTH - uart2_obj.rxHead)];
    } else {
        return *(uart2_obj.rxHead + offset);
    }
}

unsigned int UART2_ReceiveBufferSizeGet(void) {
    if (!uart2_obj.rxStatus.s.full) {
        if (uart2_obj.rxHead > uart2_obj.rxTail) {
            return (uart2_obj.rxHead - uart2_obj.rxTail);
        } else {
            return (UART2_CONFIG_RX_BYTEQ_LENGTH - (uart2_obj.rxTail - uart2_obj.rxHead));
        }
    }
    return 0;
}


bool UART2_ReceiveBufferIsEmpty(void) {
    return (uart2_obj.rxStatus.s.empty);
}


UART2_STATUS UART2_StatusGet(void) {
    return U2STA;
}

void UART2_Transfer(unsigned char *data, unsigned short size)
{
    while (size)
    {
        if (U2STAbits.UTXBF != 1)
        {
            U2TXREG = *data;
            data++;
            size--;
        }
    }
}


/**
  End of File
 */
