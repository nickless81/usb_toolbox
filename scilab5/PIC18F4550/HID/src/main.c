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
#include <config_pic.h>
void high_isr(void) shadowregs interrupt 1
{
	;
}

void low_isr(void) shadowregs interrupt 2
{
	;
}
void main(void){
    UserInit();
    init_usart();
    printf("INICIANDO DISPOSITIVO\n");
    printf("PROYECTO BASE PARA USB HID\n");
    while(1){
#ifdef  DEBUG_LED
        LED_ENUM=LED_ON;
        delay_ms(100);
        LED_ENUM=LED_OFF;
        delay_ms(100);
#else
        EnableUSBModule();
        if(UCFGbits.UTEYE != 1){
            ProcessUSBTransactions();
        }
        ProcessIO();
#endif
    }
}
