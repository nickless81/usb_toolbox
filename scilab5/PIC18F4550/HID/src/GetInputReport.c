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

// Handle a control input report.
void GetInputReport(unsigned char reportID){
    #ifdef DEBUG_USB
        printf("GetInputReport: 0x%uhx\r\n", reportID);
    #endif
    if (reportID == 0){
        unsigned char i;
        // Send back the contents of the HID report
        // TBD: provide useful information...
        outPtr = (unsigned char *)&HIDTxBuffer;
        HIDTxBuffer[0]=0x00;
        HIDTxBuffer[1]=0xF2;	//this is to differentiate between different transfer types
        HIDTxBuffer[2]=HIBYTE(timestamp);
        HIDTxBuffer[3]=LOBYTE(timestamp);
        for(i=4;i<HID_INPUT_REPORT_BYTES;i++){
            HIDTxBuffer[i]=HIDRxBuffer[i];
        }
        // The number of bytes in the report (from usb.h).
        wCount = HID_INPUT_REPORT_BYTES;
        transferType=0;
    }
}
