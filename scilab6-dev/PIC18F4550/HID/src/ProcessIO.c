/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <pic18fregs.h>
#include <stdio.h>
#include <usart.h>
#include <delay.h>
#include <hid.h>
#include <usb.h>
#include <app.h>
void ProcessIO(void){
    if ((deviceState < CONFIGURED) || (UCONbits.SUSPND==1)){
        return;
    }
    LED_ENUM=(deviceState==ADDRESS)?LED_ON:LED_OFF;
    if(USBEcho()>0){
        sel=rxBuffer[0];
        usb_remoto();
    }
}
