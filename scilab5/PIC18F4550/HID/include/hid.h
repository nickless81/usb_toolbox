/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#ifndef _HID_H_
#define _HID_H_
#ifndef USB_H
#include <usb.h>
#endif
extern unsigned char rxCnt;
extern unsigned char txCnt;
extern char txBuffer[HID_INPUT_REPORT_BYTES];
extern char rxBuffer[HID_OUTPUT_REPORT_BYTES];
extern volatile unsigned char HIDFeatureBuffer[HID_FEATURE_REPORT_BYTES];
extern unsigned int timestamp;
extern unsigned char transferType;
#endif
