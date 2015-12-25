/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC24FJ64GC006
        Driver Version    :  2.00
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

#include <mcc.h>
#include <ucos_ii.h>
#include "app_cfg.h"
#include "debug.h"
#include <bsp.h>

static OS_STK MainTaskSTK[OS_MAIN_TASK_SIZE];

static void hardware_test(void)
{
    IO_ALARM_LED_SetHigh();
    IO_FAULT_LED_SetHigh();
    IO_NORMAL_LED_SetHigh();
    __delay_ms(500);
    IO_ALARM_LED_SetLow();
    IO_FAULT_LED_SetLow();
    IO_NORMAL_LED_SetLow();
    __delay_ms(500);
}

void __attribute__((user_init)) system_init(void)
{
    SYSTEM_Initialize();
    debug_init();
}

static void module_init(void)
{
}

static void main_task(void *p_arg)
{
    BSP_Init();
    module_init();
    
    while (1)
    {
        hardware_test();
        debug_print(1, "main task run\r\n");
        OSTimeDly(100);
    }
}


/*
                         Main application
 */
int main(void) {

    OSInit();
    OSTaskCreateExt(main_task, (void *)0, 
            (OS_STK *)&MainTaskSTK[0],
            OS_MAIN_TASK_PRIO, OS_MAIN_TASK_PRIO, 
            (OS_STK *)&MainTaskSTK[OS_MAIN_TASK_SIZE-1], 
            OS_MAIN_TASK_SIZE, 
            (void *)0, OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
    OSStart();
    return -1;
}
/**
 End of File
 */

