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
// Handle control out.  This might be an alternate way of processing
// an output report, so all that's needed is to point the output
// pointer to the output buffer
// Initialization for a SET_REPORT request.  This routine will be
// invoked during the setup stage and is used to set up the buffer
// for receiving data from the host.
void SetupOutputReport(unsigned char reportID){
    #ifdef DEBUG_USB
    printf("SetupOutputReport reportID=%u\n",reportID);
    #endif
    if (reportID == 0){
        // When the report arrives in the data stage, the data will be
	// stored in HIDFeatureBuffer
	inPtr = (unsigned char*)&HIDRxBuffer;
    }
}
