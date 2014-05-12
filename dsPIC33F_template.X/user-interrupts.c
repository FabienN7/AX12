/*
 * Template dsPIC33F
 * Compiler : Microchip xC16
 * µC : 33FJ64MC802
 * Juillet 2012
 *    ____________      _           _
 *   |___  /| ___ \    | |         | |
 *      / / | |_/ /___ | |__   ___ | |_
 *     / /  |    // _ \| '_ \ / _ \| __|
 *    / /   | |\ \ (_) | |_) | (_) | |_
 *   /_/    |_| \_\___/|____/ \___/'\__|
 *			      7robot.fr
 */

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <p33Fxxxx.h>      /* Includes device header file                     */
#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "header.h"        /* Function / Parameters                           */
#include "timer.h"         /* Include timer fonctions                         */
#include <uart.h>
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/
#define BAUDRATEAX12 57600
//#define BAUDRATEAX12 9600
#define BRGVALAX12 ((FCY / BAUDRATEAX12 / 16) - 1)

void ConfigureOscillator(void) {
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBDbits.PLLDIV = 150; // M=43
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE = 5; // N2=2
    // Fosc = M/(N1.N2)*Fin
}

void InitApp(void) {
    //pin de la LED en sortie
    //_TRISA0 = 0;
    _TRISA2 = 0;
    //Si on a un interrupteur sur la pin RB5 (par exemple), on la met en entrée
    // _TRISB5 = 1;
    //Et on active la pullup qui va bien (registres CNPU1 et CNPU2)
    // _CN27PUE = 1;
    _ODCB5 = 1; // Open drain sur la pin RB5(pour les AX12)
    // activation de la priorité des interruptions
    _NSTDIS = 0;
    // cf datasheet compilateur
    OpenUART2(UART_EN & UART_IDLE_CON & UART_IrDA_DISABLE & UART_MODE_FLOW
            & UART_UEN_00 & UART_DIS_WAKE & UART_DIS_LOOPBACK
            & UART_DIS_ABAUD & UART_UXRX_IDLE_ONE & UART_BRGH_SIXTEEN
            & UART_NO_PAR_8BIT & UART_1STOPBIT,
            UART_INT_TX_BUF_EMPTY & UART_IrDA_POL_INV_ZERO
            & UART_SYNC_BREAK_DISABLED & UART_TX_ENABLE & UART_TX_BUF_NOT_FUL & UART_INT_RX_CHAR
            & UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR,
            BRGVALAX12);

    ConfigIntUART2(UART_RX_INT_PR4 & UART_RX_INT_EN
            & UART_TX_INT_PR4 & UART_TX_INT_DIS);



    OpenTimer23(T2_ON &
            T2_IDLE_CON &
            T2_GATE_OFF &
            T2_PS_1_1 &
            T2_SOURCE_INT, 0x01);

    ConfigIntTimer2(T2_INT_PRIOR_4 & T2_INT_ON);
}
/******************************************************************************/
/* Interrupt Vector Options                                                   */
/******************************************************************************/
/*                                                                            */
/* Refer to the C30 (MPLAB C Compiler for PIC24F MCUs and dsPIC33F DSCs) User */
/* Guide for an up to date list of the available interrupt options.           */
/* Alternately these names can be pulled from the device linker scripts.      */
/*                                                                            */
/* dsPIC33F Primary Interrupt Vector Names:                                   */
/*                                                                            */
/* _INT0Interrupt      _C1Interrupt                                           */
/* _IC1Interrupt       _DMA3Interrupt                                         */
/* _OC1Interrupt       _IC3Interrupt                                          */
/* _T1Interrupt        _IC4Interrupt                                          */
/* _DMA0Interrupt      _IC5Interrupt                                          */
/* _IC2Interrupt       _IC6Interrupt                                          */
/* _OC2Interrupt       _OC5Interrupt                                          */
/* _T2Interrupt        _OC6Interrupt                                          */
/* _T3Interrupt        _OC7Interrupt                                          */
/* _SPI1ErrInterrupt   _OC8Interrupt                                          */
/* _SPI1Interrupt      _DMA4Interrupt                                         */
/* _U1RXInterrupt      _T6Interrupt                                           */
/* _U1TXInterrupt      _T7Interrupt                                           */
/* _ADC1Interrupt      _SI2C2Interrupt                                        */
/* _DMA1Interrupt      _MI2C2Interrupt                                        */
/* _SI2C1Interrupt     _T8Interrupt                                           */
/* _MI2C1Interrupt     _T9Interrupt                                           */
/* _CNInterrupt        _INT3Interrupt                                         */
/* _INT1Interrupt      _INT4Interrupt                                         */
/* _ADC2Interrupt      _C2RxRdyInterrupt                                      */
/* _DMA2Interrupt      _C2Interrupt                                           */
/* _OC3Interrupt       _DCIErrInterrupt                                       */
/* _OC4Interrupt       _DCIInterrupt                                          */
/* _T4Interrupt        _DMA5Interrupt                                         */
/* _T5Interrupt        _U1ErrInterrupt                                        */
/* _INT2Interrupt      _U2ErrInterrupt                                        */
/* _U2RXInterrupt      _DMA6Interrupt                                         */
/* _U2TXInterrupt      _DMA7Interrupt                                         */
/* _SPI2ErrInterrupt   _C1TxReqInterrupt                                      */
/* _SPI2Interrupt      _C2TxReqInterrupt                                      */
/* _C1RxRdyInterrupt                                                          */
/*                                                                            */
/* For alternate interrupt vector naming, simply add 'Alt' between the prim.  */
/* interrupt vector name '_' and the first character of the primary interrupt */
/* vector name.  There is no Alternate Vector or 'AIVT' for the 33E family.   */
/*                                                                            */
/* For example, the vector name _ADC2Interrupt becomes _AltADC2Interrupt in   */
/* the alternate vector table.                                                */
/*                                                                            */
/* Example Syntax:                                                            */
/*                                                                            */
/* void __attribute__((interrupt,auto_psv)) <Vector Name>(void)               */
/* {                                                                          */
/*     <Clear Interrupt Flag>                                                 */
/* }                                                                          */
/*                                                                            */
/* For more comprehensive interrupt examples refer to the C30 (MPLAB C        */
/* Compiler for PIC24 MCUs and dsPIC DSCs) User Guide in the                  */
/* <compiler installation directory>/doc directory for the latest compiler    */
/* release.                                                                   */
/*                                                                            */
/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* TODO Add interrupt routine code here. */

void __attribute__((interrupt, auto_psv)) _T2Interrupt(void) {
    led1 = !led1; // On bascule l'état de la LED
    _T2IF = 0; // On baisse le FLAG
}

/*
void __attribute__((interrupt,auto_psv)) _T5Interrupt(void)
{
    _T5IF = 0;
    GetAX(num_ax, data);
}
 */

void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void) {

    led1 = led1 ^ 1;
    InterruptAX();

    _U2RXIF = 0; // On baisse le FLAG
}

/*************************************************
 * TX Interrupt *
 *************************************************/


void __attribute__((__interrupt__, no_auto_psv)) _U2TXInterrupt(void) {

    _U2TXIF = 0; // clear TX interrupt flag

}