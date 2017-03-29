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
void checkEcho(){
    #ifdef DEBUG_USB_STATE
    switch(deviceState){
        case(DETACHED):
            printf("Detached\r\n");
        break;
        case(ATTACHED):
            printf("Attached\r\n");
        break;
        case(POWERED):
            printf("Powered\r\n");
        break;
        case(DEFAULT):
            printf("Default\r\n");
        break;
        case(ADDRESS):
            printf("Address\r\n");
            LED=LED_ON;
        break;
        case(CONFIGURED):
            printf("Configured\r\n");
        break;
        default:
            printf("Unknown state\r\n");
        break;
    }
    printf("UCON: %x, UCFG: %x\r\n", UCON, UCFG);
    #endif
}
