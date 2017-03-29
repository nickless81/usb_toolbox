/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <pic18fregs.h>
#include <stdio.h>
#include <usart.h>
#include <usb.h>
#include <hid.h>
#include <app.h>
void UserInit(void){
    rxCnt=0,
    txCnt=0;
    ADCON1 |= 0x0F;
    UCFG = 0x14; // Enable pullup resistors; full speed mode
    deviceState = DETACHED;
    remoteWakeup = 0x00;
    currentConfiguration = 0x00;
    LATA=0;
    TRISA=0;
    LATB=0;
    TRISB=0;
    OSCCONbits.IRCF=7;
    return;
}
