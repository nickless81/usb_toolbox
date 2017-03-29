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
// Post processing for a SET_FEATURE request.  After all the data has
// been delivered from host to device, this will be invoked to perform
// application specific processing.
void SetFeatureReport(unsigned char reportID){
    #ifdef DEBUG_USB
        printf("SetFeatureReport reportID=%u\r\n", reportID);
    #endif
    // Currently only handling report 0, ignore any others.
    if (reportID == 0){
        printf("SetFeatureReport\n");
    }
}
