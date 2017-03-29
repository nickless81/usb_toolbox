/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <pic18fregs.h>
#include <stdio.h>
#include <usart.h>
#include <string.h>
#include <usb.h>
#include <hid.h>
#include <app.h>
int USBEcho(void){
    rxCnt=0;
    rxCnt = HIDRxReport(rxBuffer, HID_OUTPUT_REPORT_BYTES);
    if (rxCnt == 0){
        memset(rxBuffer,0x00,HID_OUTPUT_REPORT_BYTES);
        return -1;
    }
    return 1;
}
