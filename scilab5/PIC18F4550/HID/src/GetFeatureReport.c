/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <pic18fregs.h>
#include <stdio.h>
#include <string.h>
#include <usart.h>
#include <usb.h>
#include <hid.h>
#include <app.h>
// Handle a feature report request on the control pipe.
void GetFeatureReport(unsigned char reportID){
    #ifdef DEBUG_USB
        printf("GetFeatureReport reportID=%u\n",reportID);
        printf("reportID=%u\tHIDFeatureBuffer[0]=%u\tHIDFeatureBuffer[1]=%u\n",
            reportID,
            HIDFeatureBuffer[0],
            HIDFeatureBuffer[1]
        );
    #endif
    checkEcho();
    if (reportID == 0){
        printf("GetFeatureReport reportID=%u\n",reportID);
        // Handle report #0
        outPtr = (unsigned char *)&HIDFeatureBuffer;
        HIDFeatureBuffer[0] = 0x00;
        HIDFeatureBuffer[1]=0xF1; //this is to differentiate between different transfer types
        HIDFeatureBuffer[2]=HIBYTE(timestamp);
        HIDFeatureBuffer[3]=LOBYTE(timestamp);
        wCount = HID_FEATURE_REPORT_BYTES;
        transferType=0;
    }
}
