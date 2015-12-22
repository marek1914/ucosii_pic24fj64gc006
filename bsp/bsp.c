/*
*********************************************************************************************************
*                                             Microchip dsPIC33FJ
*                                            Board Support Package
*
*                                                   Micrium
*                                    (c) Copyright 2005, Micrium, Weston, FL
*                                              All Rights Reserved
*
*
* File : BSP.C
* By   : Eric Shufro
*********************************************************************************************************
*/

#include <xc.h>
#include <ucos_ii.h>
#include <tmr2.h>
/*
*********************************************************************************************************
*                                              VARIABLES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                              PROTOTYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                         BSP INITIALIZATION
*
* Description : This function should be called by your application code before you make use of any of the
*               functions found in this module.
*
* Arguments   : none
*********************************************************************************************************
*/

void  BSP_Init (void)
{                                                        /* Initialize the I/Os for the LED controls                 */
                                                         /* Initialize the uC/OS-II tick interrupt                   */
    TMR2_Initialize();
}



/*
*********************************************************************************************************
*                                      BSP_CPU_ClkFrq()

* Description : This function determines the CPU clock frequency (Fcy)
* Returns     : The CPU frequency in (HZ)
*********************************************************************************************************
*/
#if 0

CPU_INT32U  BSP_CPU_ClkFrq (void)
{
    CPU_INT08U  Clk_Selected;
    CPU_INT16U  FRC_Div;
    CPU_INT32U  CPU_Clk_Frq;


#if defined (__dsPIC33E__) || defined (__dsPIC33F__)
    CPU_INT08U  PLL_n1;
    CPU_INT08U  PLL_n2;
    CPU_INT16U  PLL_m;
    PLL_m         =  (PLLFBD & PLLDIV_MASK) + 2;                        /* Get the Multiplier value                                 */
    PLL_n1        =  (CLKDIV & PLLPRE_MASK) + 2;                        /* Computer the Pre Divider value                           */
    PLL_n2        = ((CLKDIV & PLLPOST_MASK) >> 6);                     /* Get the Post Divider register value                      */
    PLL_n2        = ((PLL_n2 * 2) + 2);                                 /* Compute the Post Divider value */
#endif

    FRC_Div       = ((CLKDIV & FRCDIV_MASK) >> 8);                      /* Get the FRC Oscillator Divider register value            */
    FRC_Div       = ((1 << FRC_Div) * 2);                               /* Compute the FRC Divider value                            */

    Clk_Selected  =  (OSCCON & COSC_MASK) >> 12;                        /* Determine which clock source is currently selected       */

    switch (Clk_Selected) {
        case 0:                                                         /* Fast Oscillator (FRC) Selected                           */
             CPU_Clk_Frq   =   CPU_FRC_OSC_FRQ;                         /* Return the frequency of the internal fast oscillator     */
             break;

        case 1:   
             #if defined (__dsPIC33E__) || defined(__dsPIC33F__)
             CPU_Clk_Frq   = ((CPU_FRC_OSC_FRQ  * PLL_m) /              /* Compute the PLL output frequency using the FRC as FIN    */
                              (FRC_Div * PLL_n1 * PLL_n2));
             #else
             /* Fast Oscillator (FRC) with PLL Selected                  */
             CPU_Clk_Frq   =  (CPU_FRC_OSC_FRQ  * 4);                   /* Compute the PLL output frequency  = (FRC * 4)            */
             #endif
             break;

        case 2:                                                         /* Primary External Oscillator Selected                     */
             CPU_Clk_Frq   =   CPU_PRIMARY_OSC_FRQ;                     /* Return the frequency of the primary external oscillator  */
             break;

        case 3:       
             #if defined (__dsPIC33E__) || defined(__dsPIC33F__)
             CPU_Clk_Frq   = ((CPU_PRIMARY_OSC_FRQ * PLL_m) /           /* Compute the PLL output frq using the PRI EXT OSC as FIN  */
                              (PLL_n1 * PLL_n2));
             #else
                         /* Primary External Oscillator with PLL Selected            */
             CPU_Clk_Frq   =  (CPU_PRIMARY_OSC_FRQ * 4);                /* Compute the PLL output frq as (CPU_PRIMARY_OSC_FRQ * 4)  */
             #endif
             break;

        case 4:                                                         /* Secondary Oscillator Selected (SOCS)                     */
             CPU_Clk_Frq   =   CPU_SECONDARY_OSC_FRQ;                   /* Return the frq of the external secondary oscillator      */
             break;

        case 5:                                                         /* Low Power Oscillator (LPOSC) Selected                    */
             CPU_Clk_Frq   =   CPU_LOW_POWER_OSC_FRQ;                   /* Return the frq of the Low Power Oscillator               */
             break;

        case 6:
             CPU_Clk_Frq = 0;                                           /* Return 0 for the Reserved clock setting                  */
             break;

        case 7:                                                         /* Fast Oscillator (FRC) with FRCDIV Selected               */
             CPU_Clk_Frq   =   CPU_FRC_OSC_FRQ / FRC_Div;               /* Return the clock frequency of FRC / FRC_Div              */
             break;

        default:
             CPU_Clk_Frq = 0;                                           /* Return 0 if the clock source cannot be determined        */
             break;
    }

    CPU_Clk_Frq   /=  2;                                                /* Divide the final frq by 2, get the actual CPU Frq (Fcy)  */

    return (CPU_Clk_Frq);                                               /* Return the operating frequency                           */
}



static  void  Tmr_TickInit (void)
{
    CPU_INT32U  tmr_frq;
    CPU_INT16U  cnts;


    tmr_frq   =   BSP_CPU_ClkFrq();                                     /* Get the CPU Clock Frequency (Hz) (Fcy)                   */
    cnts      =   (tmr_frq / OS_TICKS_PER_SEC) - 1;                     /* Calaculate the number of timer ticks between interrupts  */


    T2CON     =   0;                                                    /* Use Internal Osc (Fcy), 16 bit mode, prescaler = 1  		*/
    TMR2      =   0;                                                    /* Start counting from 0 and clear the prescaler count      */
    PR2       =   cnts;                                                 /* Set the period register                                  */
    IPC1     &=  ~T2IP_MASK;                                            /* Clear all timer 2 interrupt priority bits                */
    IPC1     |=  (TIMER_INT_PRIO << 12);                                /* Set timer 2 to operate with an interrupt priority of 4   */
    IFS0     &=  ~T2IF;                                                 /* Clear the interrupt for timer 2                          */
    IEC0     |=   T2IE;                                                 /* Enable interrupts for timer 2                            */
    T2CON    |=   TON;                                                  /* Start the timer                                          */

}
#endif
/*
*********************************************************************************************************
*                                     OS TICK INTERRUPT SERVICE ROUTINE
*
* Description : This function handles the timer interrupt that is used to generate TICKs for uC/OS-II.
*********************************************************************************************************
*/

void OS_Tick_ISR_Handler (void)
{
    IFS0bits.T2IF = 0;

    OSTimeTick();
}

