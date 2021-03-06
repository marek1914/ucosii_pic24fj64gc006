/**
  @Generated MPLAB� Code Configurator Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC24FJ64GC006
        Driver Version    :  1.02
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

// Configuration bits: selected in the GUI

// CONFIG4
#pragma config I2C2SEL = SEC    // Alternate I2C2 Location Select bit->I2C2 is multiplexed to SDA2/RF4 and SCL2/RF5
#pragma config DSWDTEN = OFF    // Deep Sleep Watchdog Timer Enable->DSWDT Disabled
#pragma config DSWDTOSC = LPRC    // DSWDT Reference Clock Select->DSWDT uses LPRC as reference clock
#pragma config PLLDIV = NODIV    // PLL Input Prescaler Select bits->Oscillator used directly (4 MHz input)
#pragma config RTCBAT = ON    // RTC Battery Operation Enable->RTC operation is continued through VBAT
#pragma config IOL1WAY = ON    // PPS IOLOCK Set Only Once Enable bit->Once set, the IOLOCK bit cannot be cleared
#pragma config DSBOREN = ON    // Deep Sleep BOR Enable bit->DSBOR Enabled
#pragma config DSSWEN = ON    // DSEN Bit Enable->Deep Sleep is controlled by the register bit DSEN
#pragma config DSWDTPS = DSWDTPS1F    // Deep Sleep Watchdog Timer Postscale Select bits->1:68719476736 (25.7 Days)

// CONFIG3
#pragma config WPCFG = WPCFGDIS    // Write Protect Configuration Page Select->Disabled
#pragma config BOREN = ON    // Brown-out Reset Enable->Brown-out Reset Enable
#pragma config WPDIS = WPDIS    // Segment Write Protection Disable->Disabled
#pragma config WPFP = WPFP127    // Write Protection Flash Page Segment Boundary->Page 127 (0x1FC00)
#pragma config SOSCSEL = OFF    // SOSC Selection bits->Digital (SCLKI) mode
#pragma config WPEND = WPENDMEM    // Segment Write Protection End Page Select->Write Protect from WPFP to the last page of memory
#pragma config WDTWIN = PS25_0    // Window Mode Watchdog Timer Window Width Select->Watch Dog Timer Window Width is 25 percent

// CONFIG2
#pragma config WDTCLK = LPRC    // WDT Clock Source Select bits->WDT uses LPRC
#pragma config FCKSM = CSDCMD    // Clock Switching and Fail-Safe Clock Monitor Configuration bits->Clock switching and Fail-Safe Clock Monitor are disabled
#pragma config ALTCVREF = CVREF_RB    // External Comparator Reference Location Select bit->CVREF+/CVREF- are mapped to RB0/RB1
#pragma config POSCMD = XT    // Primary Oscillator Select (XT Oscillator Enabled)
//#pragma config POSCMD = NONE
#pragma config ALTADREF = AVREF_RB    // External 12-Bit A/D Reference Location Select bit->AVREF+/AVREF- are mapped to RB0/RB1
#pragma config FNOSC = PRIPLL    // Initial Oscillator Select->Primary Oscillator with PLL module (XTPLL,HSPLL, ECPLL)
//#pragma config FNOSC = FRCPLL
#pragma config IESO = ON    // Internal External Switchover->Disabled
#pragma config OSCIOFCN = ON    // OSCO Pin Configuration->OSCO/CLKO/RC15 functions as port I/O (RC15)
#pragma config WDTCMX = WDTCLK    // WDT Clock Source Select bits->WDT clock source is determined by the WDTCLK Configuration bits

// CONFIG1
#pragma config WDTPS = PS32768    // Watchdog Timer Postscaler Select->1:32,768
#pragma config LPCFG = OFF    // Low power regulator control->Disabled - regardless of RETEN
#pragma config GCP = OFF    // General Segment Code Protect->Code protection is disabled
#pragma config FWDTEN = WDT_DIS    // Watchdog Timer Enable->WDT disabled in hardware; SWDTEN bit disabled
#pragma config ICS = PGx2    // Emulator Pin Placement Select bits->Emulator functions are shared with PGEC2/PGED2
#pragma config WINDIS = OFF    // Windowed WDT Disable->Standard Watchdog Timer
#pragma config JTAGEN = OFF    // JTAG Port Enable->Disabled
#pragma config FWPSA = PR128    // WDT Prescaler Ratio Select->1:128
#pragma config GWRP = OFF    // General Segment Write Protect->Disabled

#include "mcc.h"

void SYSTEM_Initialize(void) {
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    INTERRUPT_Initialize();
}

void OSCILLATOR_Initialize(void) {
    // CPDIV 1:1; PLLEN disabled; RCDIV FRC/2; DOZE 1:8; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3100;
    // STOR disabled; STORPOL Interrupt when STOR is 1; STSIDL disabled; STLPOL Interrupt when STLOCK is 1; STLOCK disabled; STSRC SOSC; STEN disabled; TUN Center frequency; 
    OSCTUN = 0x0000;
    // Set the secondary oscillator
    OSCCONbits.SOSCEN = 0;

    //if (0x03 == OSCCONbits.COSC); XTPLL
    while (0x03 != OSCCONbits.COSC)
    {
}
    while (0 == OSCCONbits.LOCK)
    {
    }
}

/**
 End of File
 */