/**
  System Interrupts Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

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

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
 */
#include <xc.h>
/**
    Section: Device Pin Macros
 */
/**
  @Summary
    Sets the GPIO pin, RB0, high using LATB0.

  @Description
    Sets the GPIO pin, RB0, high using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB0 high (1)
    DVREFPos_SetHigh();
    </code>

 */
#define DVREFPos_SetHigh()          _LATB0 = 1
/**
  @Summary
    Sets the GPIO pin, RB0, low using LATB0.

  @Description
    Sets the GPIO pin, RB0, low using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB0 low (0)
    DVREFPos_SetLow();
    </code>

 */
#define DVREFPos_SetLow()           _LATB0 = 0
/**
  @Summary
    Toggles the GPIO pin, RB0, using LATB0.

  @Description
    Toggles the GPIO pin, RB0, using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB0
    DVREFPos_SetToggle();
    </code>

 */
#define DVREFPos_Toggle()           _LATB0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB0.

  @Description
    Reads the value of the GPIO pin, RB0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB0
    postValue = DVREFPos_GetValue();
    </code>

 */
#define DVREFPos_GetValue()         _RB0
/**
  @Summary
    Configures the GPIO pin, RB0, as an input.

  @Description
    Configures the GPIO pin, RB0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB0 as an input
    DVREFPos_SetDigitalInput();
    </code>

 */
#define DVREFPos_SetDigitalInput()  _TRISB0 = 1
/**
  @Summary
    Configures the GPIO pin, RB0, as an output.

  @Description
    Configures the GPIO pin, RB0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB0 as an output
    DVREFPos_SetDigitalOutput();
    </code>

 */
#define DVREFPos_SetDigitalOutput() _TRISB0 = 0
/**
  @Summary
    Sets the GPIO pin, RB1, high using LATB1.

  @Description
    Sets the GPIO pin, RB1, high using LATB1.

  @Preconditions
    The RB1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB1 high (1)
    IO_ALARM_LED_SetHigh();
    </code>

 */
#define IO_ALARM_LED_SetHigh()          _LATB1 = 1
/**
  @Summary
    Sets the GPIO pin, RB1, low using LATB1.

  @Description
    Sets the GPIO pin, RB1, low using LATB1.

  @Preconditions
    The RB1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB1 low (0)
    IO_ALARM_LED_SetLow();
    </code>

 */
#define IO_ALARM_LED_SetLow()           _LATB1 = 0
/**
  @Summary
    Toggles the GPIO pin, RB1, using LATB1.

  @Description
    Toggles the GPIO pin, RB1, using LATB1.

  @Preconditions
    The RB1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB1
    IO_ALARM_LED_SetToggle();
    </code>

 */
#define IO_ALARM_LED_Toggle()           _LATB1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB1.

  @Description
    Reads the value of the GPIO pin, RB1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB1
    postValue = IO_ALARM_LED_GetValue();
    </code>

 */
#define IO_ALARM_LED_GetValue()         _RB1
/**
  @Summary
    Configures the GPIO pin, RB1, as an input.

  @Description
    Configures the GPIO pin, RB1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB1 as an input
    IO_ALARM_LED_SetDigitalInput();
    </code>

 */
#define IO_ALARM_LED_SetDigitalInput()  _TRISB1 = 1
/**
  @Summary
    Configures the GPIO pin, RB1, as an output.

  @Description
    Configures the GPIO pin, RB1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB1 as an output
    IO_ALARM_LED_SetDigitalOutput();
    </code>

 */
#define IO_ALARM_LED_SetDigitalOutput() _TRISB1 = 0
/**
  @Summary
    Sets the GPIO pin, RB2, high using LATB2.

  @Description
    Sets the GPIO pin, RB2, high using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 high (1)
    IO_FAULT_LED_SetHigh();
    </code>

 */
#define IO_FAULT_LED_SetHigh()          _LATB2 = 1
/**
  @Summary
    Sets the GPIO pin, RB2, low using LATB2.

  @Description
    Sets the GPIO pin, RB2, low using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 low (0)
    IO_FAULT_LED_SetLow();
    </code>

 */
#define IO_FAULT_LED_SetLow()           _LATB2 = 0
/**
  @Summary
    Toggles the GPIO pin, RB2, using LATB2.

  @Description
    Toggles the GPIO pin, RB2, using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB2
    IO_FAULT_LED_SetToggle();
    </code>

 */
#define IO_FAULT_LED_Toggle()           _LATB2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB2.

  @Description
    Reads the value of the GPIO pin, RB2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB2
    postValue = IO_FAULT_LED_GetValue();
    </code>

 */
#define IO_FAULT_LED_GetValue()         _RB2
/**
  @Summary
    Configures the GPIO pin, RB2, as an input.

  @Description
    Configures the GPIO pin, RB2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an input
    IO_FAULT_LED_SetDigitalInput();
    </code>

 */
#define IO_FAULT_LED_SetDigitalInput()  _TRISB2 = 1
/**
  @Summary
    Configures the GPIO pin, RB2, as an output.

  @Description
    Configures the GPIO pin, RB2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an output
    IO_FAULT_LED_SetDigitalOutput();
    </code>

 */
#define IO_FAULT_LED_SetDigitalOutput() _TRISB2 = 0
/**
  @Summary
    Sets the GPIO pin, RB3, high using LATB3.

  @Description
    Sets the GPIO pin, RB3, high using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 high (1)
    IO_NORMAL_LED_SetHigh();
    </code>

 */
#define IO_NORMAL_LED_SetHigh()          _LATB3 = 1
/**
  @Summary
    Sets the GPIO pin, RB3, low using LATB3.

  @Description
    Sets the GPIO pin, RB3, low using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 low (0)
    IO_NORMAL_LED_SetLow();
    </code>

 */
#define IO_NORMAL_LED_SetLow()           _LATB3 = 0
/**
  @Summary
    Toggles the GPIO pin, RB3, using LATB3.

  @Description
    Toggles the GPIO pin, RB3, using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB3
    IO_NORMAL_LED_SetToggle();
    </code>

 */
#define IO_NORMAL_LED_Toggle()           _LATB3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB3.

  @Description
    Reads the value of the GPIO pin, RB3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB3
    postValue = IO_NORMAL_LED_GetValue();
    </code>

 */
#define IO_NORMAL_LED_GetValue()         _RB3
/**
  @Summary
    Configures the GPIO pin, RB3, as an input.

  @Description
    Configures the GPIO pin, RB3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an input
    IO_NORMAL_LED_SetDigitalInput();
    </code>

 */
#define IO_NORMAL_LED_SetDigitalInput()  _TRISB3 = 1
/**
  @Summary
    Configures the GPIO pin, RB3, as an output.

  @Description
    Configures the GPIO pin, RB3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an output
    IO_NORMAL_LED_SetDigitalOutput();
    </code>

 */
#define IO_NORMAL_LED_SetDigitalOutput() _TRISB3 = 0
/**
  @Summary
    Sets the GPIO pin, RB4, high using LATB4.

  @Description
    Sets the GPIO pin, RB4, high using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 high (1)
    U2RX_SetHigh();
    </code>

 */
#define U2RX_SetHigh()          _LATB4 = 1
/**
  @Summary
    Sets the GPIO pin, RB4, low using LATB4.

  @Description
    Sets the GPIO pin, RB4, low using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 low (0)
    U2RX_SetLow();
    </code>

 */
#define U2RX_SetLow()           _LATB4 = 0
/**
  @Summary
    Toggles the GPIO pin, RB4, using LATB4.

  @Description
    Toggles the GPIO pin, RB4, using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB4
    U2RX_SetToggle();
    </code>

 */
#define U2RX_Toggle()           _LATB4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB4.

  @Description
    Reads the value of the GPIO pin, RB4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB4
    postValue = U2RX_GetValue();
    </code>

 */
#define U2RX_GetValue()         _RB4
/**
  @Summary
    Configures the GPIO pin, RB4, as an input.

  @Description
    Configures the GPIO pin, RB4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an input
    U2RX_SetDigitalInput();
    </code>

 */
#define U2RX_SetDigitalInput()  _TRISB4 = 1
/**
  @Summary
    Configures the GPIO pin, RB4, as an output.

  @Description
    Configures the GPIO pin, RB4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an output
    U2RX_SetDigitalOutput();
    </code>

 */
#define U2RX_SetDigitalOutput() _TRISB4 = 0
/**
  @Summary
    Sets the GPIO pin, RB5, high using LATB5.

  @Description
    Sets the GPIO pin, RB5, high using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 high (1)
    U2TX_SetHigh();
    </code>

 */
#define U2TX_SetHigh()          _LATB5 = 1
/**
  @Summary
    Sets the GPIO pin, RB5, low using LATB5.

  @Description
    Sets the GPIO pin, RB5, low using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 low (0)
    U2TX_SetLow();
    </code>

 */
#define U2TX_SetLow()           _LATB5 = 0
/**
  @Summary
    Toggles the GPIO pin, RB5, using LATB5.

  @Description
    Toggles the GPIO pin, RB5, using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB5
    U2TX_SetToggle();
    </code>

 */
#define U2TX_Toggle()           _LATB5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB5.

  @Description
    Reads the value of the GPIO pin, RB5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB5
    postValue = U2TX_GetValue();
    </code>

 */
#define U2TX_GetValue()         _RB5
/**
  @Summary
    Configures the GPIO pin, RB5, as an input.

  @Description
    Configures the GPIO pin, RB5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an input
    U2TX_SetDigitalInput();
    </code>

 */
#define U2TX_SetDigitalInput()  _TRISB5 = 1
/**
  @Summary
    Configures the GPIO pin, RB5, as an output.

  @Description
    Configures the GPIO pin, RB5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an output
    U2TX_SetDigitalOutput();
    </code>

 */
#define U2TX_SetDigitalOutput() _TRISB5 = 0
/**
  @Summary
    Sets the GPIO pin, RB13, high using LATB13.

  @Description
    Sets the GPIO pin, RB13, high using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 high (1)
    IO_KEY_SetHigh();
    </code>

 */
#define IO_KEY_SetHigh()          _LATB13 = 1
/**
  @Summary
    Sets the GPIO pin, RB13, low using LATB13.

  @Description
    Sets the GPIO pin, RB13, low using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 low (0)
    IO_KEY_SetLow();
    </code>

 */
#define IO_KEY_SetLow()           _LATB13 = 0
/**
  @Summary
    Toggles the GPIO pin, RB13, using LATB13.

  @Description
    Toggles the GPIO pin, RB13, using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB13
    IO_KEY_SetToggle();
    </code>

 */
#define IO_KEY_Toggle()           _LATB13 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB13.

  @Description
    Reads the value of the GPIO pin, RB13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB13
    postValue = IO_KEY_GetValue();
    </code>

 */
#define IO_KEY_GetValue()         _RB13
/**
  @Summary
    Configures the GPIO pin, RB13, as an input.

  @Description
    Configures the GPIO pin, RB13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an input
    IO_KEY_SetDigitalInput();
    </code>

 */
#define IO_KEY_SetDigitalInput()  _TRISB13 = 1
/**
  @Summary
    Configures the GPIO pin, RB13, as an output.

  @Description
    Configures the GPIO pin, RB13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an output
    IO_KEY_SetDigitalOutput();
    </code>

 */
#define IO_KEY_SetDigitalOutput() _TRISB13 = 0
/**
  @Summary
    Sets the GPIO pin, RE5, high using LATE5.

  @Description
    Sets the GPIO pin, RE5, high using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 high (1)
    IO_LED_LCD_SetHigh();
    </code>

 */
#define IO_LED_LCD_SetHigh()          _LATE5 = 1
/**
  @Summary
    Sets the GPIO pin, RE5, low using LATE5.

  @Description
    Sets the GPIO pin, RE5, low using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 low (0)
    IO_LED_LCD_SetLow();
    </code>

 */
#define IO_LED_LCD_SetLow()           _LATE5 = 0
/**
  @Summary
    Toggles the GPIO pin, RE5, using LATE5.

  @Description
    Toggles the GPIO pin, RE5, using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE5
    IO_LED_LCD_SetToggle();
    </code>

 */
#define IO_LED_LCD_Toggle()           _LATE5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE5.

  @Description
    Reads the value of the GPIO pin, RE5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE5
    postValue = IO_LED_LCD_GetValue();
    </code>

 */
#define IO_LED_LCD_GetValue()         _RE5
/**
  @Summary
    Configures the GPIO pin, RE5, as an input.

  @Description
    Configures the GPIO pin, RE5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an input
    IO_LED_LCD_SetDigitalInput();
    </code>

 */
#define IO_LED_LCD_SetDigitalInput()  _TRISE5 = 1
/**
  @Summary
    Configures the GPIO pin, RE5, as an output.

  @Description
    Configures the GPIO pin, RE5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an output
    IO_LED_LCD_SetDigitalOutput();
    </code>

 */
#define IO_LED_LCD_SetDigitalOutput() _TRISE5 = 0
/**
  @Summary
    Sets the GPIO pin, RF4, high using LATF4.

  @Description
    Sets the GPIO pin, RF4, high using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF4 high (1)
    IO_ALARM_BEEP_SetHigh();
    </code>

 */
#define IO_ALARM_BEEP_SetHigh()          _LATF4 = 1
/**
  @Summary
    Sets the GPIO pin, RF4, low using LATF4.

  @Description
    Sets the GPIO pin, RF4, low using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF4 low (0)
    IO_ALARM_BEEP_SetLow();
    </code>

 */
#define IO_ALARM_BEEP_SetLow()           _LATF4 = 0
/**
  @Summary
    Toggles the GPIO pin, RF4, using LATF4.

  @Description
    Toggles the GPIO pin, RF4, using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF4
    IO_ALARM_BEEP_SetToggle();
    </code>

 */
#define IO_ALARM_BEEP_Toggle()           _LATF4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF4.

  @Description
    Reads the value of the GPIO pin, RF4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF4
    postValue = IO_ALARM_BEEP_GetValue();
    </code>

 */
#define IO_ALARM_BEEP_GetValue()         _RF4
/**
  @Summary
    Configures the GPIO pin, RF4, as an input.

  @Description
    Configures the GPIO pin, RF4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF4 as an input
    IO_ALARM_BEEP_SetDigitalInput();
    </code>

 */
#define IO_ALARM_BEEP_SetDigitalInput()  _TRISF4 = 1
/**
  @Summary
    Configures the GPIO pin, RF4, as an output.

  @Description
    Configures the GPIO pin, RF4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF4 as an output
    IO_ALARM_BEEP_SetDigitalOutput();
    </code>

 */
#define IO_ALARM_BEEP_SetDigitalOutput() _TRISF4 = 0
/**
  @Summary
    Sets the GPIO pin, RF5, high using LATF5.

  @Description
    Sets the GPIO pin, RF5, high using LATF5.

  @Preconditions
    The RF5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF5 high (1)
    IO_ALARM_RLY_SetHigh();
    </code>

 */
#define IO_ALARM_RLY_SetHigh()          _LATF5 = 1
/**
  @Summary
    Sets the GPIO pin, RF5, low using LATF5.

  @Description
    Sets the GPIO pin, RF5, low using LATF5.

  @Preconditions
    The RF5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF5 low (0)
    IO_ALARM_RLY_SetLow();
    </code>

 */
#define IO_ALARM_RLY_SetLow()           _LATF5 = 0
/**
  @Summary
    Toggles the GPIO pin, RF5, using LATF5.

  @Description
    Toggles the GPIO pin, RF5, using LATF5.

  @Preconditions
    The RF5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF5
    IO_ALARM_RLY_SetToggle();
    </code>

 */
#define IO_ALARM_RLY_Toggle()           _LATF5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF5.

  @Description
    Reads the value of the GPIO pin, RF5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF5
    postValue = IO_ALARM_RLY_GetValue();
    </code>

 */
#define IO_ALARM_RLY_GetValue()         _RF5
/**
  @Summary
    Configures the GPIO pin, RF5, as an input.

  @Description
    Configures the GPIO pin, RF5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF5 as an input
    IO_ALARM_RLY_SetDigitalInput();
    </code>

 */
#define IO_ALARM_RLY_SetDigitalInput()  _TRISF5 = 1
/**
  @Summary
    Configures the GPIO pin, RF5, as an output.

  @Description
    Configures the GPIO pin, RF5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF5 as an output
    IO_ALARM_RLY_SetDigitalOutput();
    </code>

 */
#define IO_ALARM_RLY_SetDigitalOutput() _TRISF5 = 0
/**
  @Summary
    Sets the GPIO pin, RG2, high using LATG2.

  @Description
    Sets the GPIO pin, RG2, high using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG2 high (1)
    IO_SENSOR_SWITCH_SetHigh();
    </code>

 */
#define IO_SENSOR_SWITCH_SetHigh()          _LATG2 = 1
/**
  @Summary
    Sets the GPIO pin, RG2, low using LATG2.

  @Description
    Sets the GPIO pin, RG2, low using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG2 low (0)
    IO_SENSOR_SWITCH_SetLow();
    </code>

 */
#define IO_SENSOR_SWITCH_SetLow()           _LATG2 = 0
/**
  @Summary
    Toggles the GPIO pin, RG2, using LATG2.

  @Description
    Toggles the GPIO pin, RG2, using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG2
    IO_SENSOR_SWITCH_SetToggle();
    </code>

 */
#define IO_SENSOR_SWITCH_Toggle()           _LATG2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG2.

  @Description
    Reads the value of the GPIO pin, RG2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG2
    postValue = IO_SENSOR_SWITCH_GetValue();
    </code>

 */
#define IO_SENSOR_SWITCH_GetValue()         _RG2
/**
  @Summary
    Configures the GPIO pin, RG2, as an input.

  @Description
    Configures the GPIO pin, RG2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG2 as an input
    IO_SENSOR_SWITCH_SetDigitalInput();
    </code>

 */
#define IO_SENSOR_SWITCH_SetDigitalInput()  _TRISG2 = 1
/**
  @Summary
    Configures the GPIO pin, RG2, as an output.

  @Description
    Configures the GPIO pin, RG2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG2 as an output
    IO_SENSOR_SWITCH_SetDigitalOutput();
    </code>

 */
#define IO_SENSOR_SWITCH_SetDigitalOutput() _TRISG2 = 0
/**
  @Summary
    Sets the GPIO pin, RG7, high using LATG7.

  @Description
    Sets the GPIO pin, RG7, high using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 high (1)
    U1RX_SetHigh();
    </code>

 */
#define U1RX_SetHigh()          _LATG7 = 1
/**
  @Summary
    Sets the GPIO pin, RG7, low using LATG7.

  @Description
    Sets the GPIO pin, RG7, low using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 low (0)
    U1RX_SetLow();
    </code>

 */
#define U1RX_SetLow()           _LATG7 = 0
/**
  @Summary
    Toggles the GPIO pin, RG7, using LATG7.

  @Description
    Toggles the GPIO pin, RG7, using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG7
    U1RX_SetToggle();
    </code>

 */
#define U1RX_Toggle()           _LATG7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG7.

  @Description
    Reads the value of the GPIO pin, RG7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG7
    postValue = U1RX_GetValue();
    </code>

 */
#define U1RX_GetValue()         _RG7
/**
  @Summary
    Configures the GPIO pin, RG7, as an input.

  @Description
    Configures the GPIO pin, RG7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an input
    U1RX_SetDigitalInput();
    </code>

 */
#define U1RX_SetDigitalInput()  _TRISG7 = 1
/**
  @Summary
    Configures the GPIO pin, RG7, as an output.

  @Description
    Configures the GPIO pin, RG7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an output
    U1RX_SetDigitalOutput();
    </code>

 */
#define U1RX_SetDigitalOutput() _TRISG7 = 0
/**
  @Summary
    Sets the GPIO pin, RG8, high using LATG8.

  @Description
    Sets the GPIO pin, RG8, high using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 high (1)
    U1TX_SetHigh();
    </code>

 */
#define U1TX_SetHigh()          _LATG8 = 1
/**
  @Summary
    Sets the GPIO pin, RG8, low using LATG8.

  @Description
    Sets the GPIO pin, RG8, low using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 low (0)
    U1TX_SetLow();
    </code>

 */
#define U1TX_SetLow()           _LATG8 = 0
/**
  @Summary
    Toggles the GPIO pin, RG8, using LATG8.

  @Description
    Toggles the GPIO pin, RG8, using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG8
    U1TX_SetToggle();
    </code>

 */
#define U1TX_Toggle()           _LATG8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG8.

  @Description
    Reads the value of the GPIO pin, RG8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG8
    postValue = U1TX_GetValue();
    </code>

 */
#define U1TX_GetValue()         _RG8
/**
  @Summary
    Configures the GPIO pin, RG8, as an input.

  @Description
    Configures the GPIO pin, RG8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an input
    U1TX_SetDigitalInput();
    </code>

 */
#define U1TX_SetDigitalInput()  _TRISG8 = 1
/**
  @Summary
    Configures the GPIO pin, RG8, as an output.

  @Description
    Configures the GPIO pin, RG8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an output
    U1TX_SetDigitalOutput();
    </code>

 */
#define U1TX_SetDigitalOutput() _TRISG8 = 0
/**
  @Summary
    Sets the GPIO pin, RG9, high using LATG9.

  @Description
    Sets the GPIO pin, RG9, high using LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG9 high (1)
    DAC1_SetHigh();
    </code>

 */
#define DAC1_SetHigh()          _LATG9 = 1
/**
  @Summary
    Sets the GPIO pin, RG9, low using LATG9.

  @Description
    Sets the GPIO pin, RG9, low using LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG9 low (0)
    DAC1_SetLow();
    </code>

 */
#define DAC1_SetLow()           _LATG9 = 0
/**
  @Summary
    Toggles the GPIO pin, RG9, using LATG9.

  @Description
    Toggles the GPIO pin, RG9, using LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG9
    DAC1_SetToggle();
    </code>

 */
#define DAC1_Toggle()           _LATG9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG9.

  @Description
    Reads the value of the GPIO pin, RG9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG9
    postValue = DAC1_GetValue();
    </code>

 */
#define DAC1_GetValue()         _RG9
/**
  @Summary
    Configures the GPIO pin, RG9, as an input.

  @Description
    Configures the GPIO pin, RG9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG9 as an input
    DAC1_SetDigitalInput();
    </code>

 */
#define DAC1_SetDigitalInput()  _TRISG9 = 1
/**
  @Summary
    Configures the GPIO pin, RG9, as an output.

  @Description
    Configures the GPIO pin, RG9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG9 as an output
    DAC1_SetDigitalOutput();
    </code>

 */
#define DAC1_SetDigitalOutput() _TRISG9 = 0

/**
    Section: Function Prototypes
 */
/**
  @Summary
    Configures the pin settings of the PIC24FJ64GC006
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the MPLAB� Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

 */
void PIN_MANAGER_Initialize(void);

#endif
