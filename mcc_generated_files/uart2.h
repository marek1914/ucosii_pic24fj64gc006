/**
  UART2 Generated Driver API Header File 

  @Company
    Microchip Technology Inc.

  @File Name
    uart2.h

  @Summary
    This is the generated header file for the UART2 driver using MPLAB� Code Configurator

  @Description
    This header file provides APIs for driver for UART2. 
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

#ifndef _UART2_H
#define _UART2_H

/**
 Section: Included Files
 */

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

    /**
      Section: Data Types
     */

    /** UART2 Driver Hardware Flags

      @Summary
        Specifies the status of the hardware receive or transmit

      @Description
        This type specifies the status of the hardware receive or transmit.
        More than one of these values may be OR'd together to create a complete
        status value.  To test a value of this type, the bit of interest must be
        AND'ed with value and checked to see if the result is non-zero.
     */
    typedef enum {
        /* Indicates that Receive buffer has data, at least one more character can be read */
        UART2_RX_DATA_AVAILABLE
        /*DOM-IGNORE-BEGIN*/ = (1 << 0) /*DOM-IGNORE-END*/,

        /* Indicates that Receive buffer has overflowed */
        UART2_RX_OVERRUN_ERROR
        /*DOM-IGNORE-BEGIN*/ = (1 << 1) /*DOM-IGNORE-END*/,

        /* Indicates that Framing error has been detected for the current character */
        UART2_FRAMING_ERROR
        /*DOM-IGNORE-BEGIN*/ = (1 << 2) /*DOM-IGNORE-END*/,

        /* Indicates that Parity error has been detected for the current character */
        UART2_PARITY_ERROR
        /*DOM-IGNORE-BEGIN*/ = (1 << 3) /*DOM-IGNORE-END*/,

        /* Indicates that Receiver is Idle */
        UART2_RECEIVER_IDLE
        /*DOM-IGNORE-BEGIN*/ = (1 << 4) /*DOM-IGNORE-END*/,

        /* Indicates that the last transmission has completed */
        UART2_TX_COMPLETE
        /*DOM-IGNORE-BEGIN*/ = (1 << 8) /*DOM-IGNORE-END*/,

        /* Indicates that Transmit buffer is full */
        UART2_TX_FULL
        /*DOM-IGNORE-BEGIN*/ = (1 << 9) /*DOM-IGNORE-END*/

    } UART2_STATUS;


    /**
      Section: UART2 Driver Routines
     */


    /**
      @Summary
        Initializes the UART instance : 2

      @Description
        This routine initializes the UART driver instance for : 2
        index.
        This routine must be called before any other UART routine is called.
    
      @Preconditions
        None.

      @Returns
        None.

      @Param
        None.

      @Comment
    
 
      @Example
        <code>
            const uint8_t writeBuffer[35] = "1234567890ABCDEFGHIJKLMNOP\n" ;
            unsigned int numBytes = 0;
            int  writebufferLen = strlen((char *)writeBuffer);
            UART2_Initialize();
            while(numBytes < writebufferLen)
            {    
                int bytesToWrite = UART2_TransmitBufferSizeGet();
                numBytes = UART2_WriteBuffer ( writeBuffer+numBytes, bytesToWrite)  ;
                UART2_TasksTransmit ( );
                if (!UART2_TransmitBufferisFull())
                {
                    //continue other operation
                }
            }
        </code>

     */

    void UART2_Initialize(void);


    /**
      @Summary
        Read a byte of data from the UART2

      @Description
        This routine reads a byte of data from the UART2.

      @Preconditions
        UART2_Initializer function should have been called 
        before calling this function. The transfer status should be checked to see 
        if the receiver is not empty before calling this function.

      @Param
        None.

      @Returns
        A data byte received by the driver.

      @Example
        <code>
        char            myBuffer[MY_BUFFER_SIZE];
        unsigned int    numBytes;

        numBytes = 0;
        do
        {
            if( UART2_TRANSFER_STATUS_RX_DATA_PRESENT & UART2_TransferStatusGet() )
            {
                myBuffer[numBytes++] = UART2_Read();
            }

            // Do something else...

        } while( numBytes < MY_BUFFER_SIZE);
        </code>
     */

    uint8_t UART2_Read(void);

    /**
      @Summary
        Returns the number of bytes read by the UART2 peripheral

      @Description
        This routine returns the number of bytes read by the Peripheral and fills the
        application read buffer with the read data.

      @Preconditions
        UART2_Initializer function should have been called 
        before calling this function

      @Param
        buffer       - Buffer into which the data read from the UART2

      @Param
        numbytes     - Total number of bytes that need to be read from the UART2
                       (must be equal to or less than the size of the buffer)

      @Returns
        Number of bytes actually copied into the caller's buffer or -1 if there
        is an error.

      @Example
        <code>
        char                     myBuffer[MY_BUFFER_SIZE];
        unsigned int             numBytes;
        UART2_TRANSFER_STATUS status ;

        // Pre-initialize myBuffer with MY_BUFFER_SIZE bytes of valid data.

        numBytes = 0;
        while( numBytes < MY_BUFFER_SIZE);
        {
            status = UART2_TransferStatusGet ( ) ;
            if (status & UART2_TRANSFER_STATUS_RX_FULL)
            {
                numBytes += UART2_ReadBuffer( myBuffer + numBytes, MY_BUFFER_SIZE - numBytes )  ;
                if(numBytes < readbufferLen)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                continue;
            }

            // Do something else...
        }
        </code>
     */

    unsigned int UART2_ReadBuffer(uint8_t *buffer, const unsigned int numbytes);


    /**
      @Summary
        Returns the character in the read sequence at the offset provided, without
        extracting it

      @Description
        This routine returns the character in the read sequence at the offset provided,
        without extracting it
 
      @Param
        None.
    
      @Example 
        <code>
        const uint8_t readBuffer[5];
        unsigned int data, numBytes = 0;
        unsigned int readbufferLen = sizeof(readBuffer);
        UART2_Initializer();
    
        while(numBytes < readbufferLen)        
        {   
            UART2_TasksReceive ( );
            //Check for data at a particular place in the buffer
            data = UART2_Peek(3);
            if(data == 5)
            {
                //discard all other data if byte that is wanted is received.    
                //continue other operation
                numBytes += UART2_ReadBuffer ( readBuffer + numBytes , readbufferLen ) ;
            }
            else
            {
                break;
            }
        }
        </code>
 
     */
    uint8_t UART2_Peek(uint16_t offset);
    

    /**
      @Summary
        Returns the size of the receive buffer

      @Description
        This routine returns the size of the receive buffer.

      @Param
        None.

      @Returns
        Size of receive buffer.
    
      @Example 
        <code>
        const uint8_t readBuffer[5];
        unsigned int size, numBytes = 0;
        unsigned int readbufferLen = sizeof(readBuffer);
        UART2__Initializer();
    
        while(size < readbufferLen)
        {
            UART2_TasksReceive ( );
            size = UART2_ReceiveBufferSizeGet();
        }
        numBytes = UART2_ReadBuffer ( readBuffer , readbufferLen ) ;
        </code>
 
     */
    unsigned int UART2_ReceiveBufferSizeGet(void);
   
  
    /**
      @Summary
        Returns the status of the receive buffer

      @Description
        This routine returns if the receive buffer is empty or not.

      @Param
        None.
 
      @Returns
        True if the receive buffer is empty
        False if the receive buffer is not empty
    
      @Example
        <code>
        char                     myBuffer[MY_BUFFER_SIZE];
        unsigned int             numBytes;
        UART2_TRANSFER_STATUS status ;

        // Pre-initialize myBuffer with MY_BUFFER_SIZE bytes of valid data.

        numBytes = 0;
        while( numBytes < MY_BUFFER_SIZE);
        {
            status = UART2_TransferStatusGet ( ) ;
            if (!UART2_ReceiveBufferIsEmpty())
            {
                numBytes += UART2_ReadBuffer( myBuffer + numBytes, MY_BUFFER_SIZE - numBytes )  ;
                if(numBytes < readbufferLen)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                continue;
            }

            // Do something else...
        }
        </code>
 
     */
    bool UART2_ReceiveBufferIsEmpty(void);
  

    /**
      @Summary
        Returns the transmitter and receiver status

      @Description
        This returns the transmitter and receiver status. The returned status may 
        contain a value with more than one of the bits
        specified in the UART2_STATUS enumeration set.  
        The caller should perform an "AND" with the bit of interest and verify if the
        result is non-zero (as shown in the example) to verify the desired status
        bit.

      @Preconditions
        UART2_Initializer function should have been called 
        before calling this function

      @Param
        None.

      @Returns
        A UART2_STATUS value describing the current status 
        of the transfer.

      @Example
        <code>
            while(!(UART2_StatusGet & UART2_TX_COMPLETE ))
            {
               // Wait for the tranmission to complete
            }
        </code>
     */

    UART2_STATUS UART2_StatusGet(void);
    
    void UART2_Transfer(unsigned char *data, unsigned short size);

#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif

#endif  // _UART2_H

/*
  End of File
 */

