/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <pic18fregs.h>
#include <usb.h>
#include <hid.h>
unsigned char rxCnt;
unsigned char txCnt;
volatile unsigned char HIDFeatureBuffer[HID_FEATURE_REPORT_BYTES];
char txBuffer[HID_INPUT_REPORT_BYTES];
char rxBuffer[HID_OUTPUT_REPORT_BYTES];
unsigned int timestamp;
