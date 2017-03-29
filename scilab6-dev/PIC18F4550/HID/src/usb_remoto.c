/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <pic18fregs.h>
#include <stdio.h>
#include <usart.h>
#include <malloc.h>
#include <string.h>
#include <app.h>
#include <usb.h>
#include <hid.h>
void usb_remoto(void) {
    /* Si el buffer de recepción en su posición cero, rxBuffer[0], es 0x00
     * El MCU no reconoce ese byte.Esto sucede en la aplicación de java y en
     * algún momento paso lo mismo con la aplicación en C++, QT4, sin embargo
     * en QT se solucionó solo. 
     */
    switch(sel){
        case(0x0F):
#ifdef DEBUG_USB_REMOTO
            printf("OPERACION PARA EL CASO %X\n",sel);
            printf("AGREGAR RUTINA QUE HAGA ALGO CON LOS DATOS RECIBIDOS\n\n");
#endif
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            txBuffer[0]=0x01;
            txBuffer[1]=0x0A;
            txBuffer[2]=0x0B;
            txBuffer[3]=0x0C;
            while (ep1Bi.Stat & UOWN){
                ProcessUSBTransactions();
            }
            txCnt=HIDTxReport(txBuffer, 64);
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            memset(rxBuffer,0x00,HID_INPUT_REPORT_BYTES);
        break;
        case(0x01)://START
#ifdef DEBUG_USB_REMOTO
            printf("OPERACION PARA EL CASO %X\n",sel);
            printf("AGREGAR RUTINA QUE HAGA ALGO CON LOS DATOS RECIBIDOS\n\n");
#endif
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            txBuffer[0]=0x02;
            txBuffer[1]=0x0B;
            txBuffer[2]=0x0C;
            txBuffer[3]=0x0D;
            while (ep1Bi.Stat & UOWN){
                ProcessUSBTransactions();
            }
            txCnt=HIDTxReport(txBuffer, 64);
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            memset(rxBuffer,0x00,HID_INPUT_REPORT_BYTES);
        break;
        case(0x02)://CONFIG
#ifdef DEBUG_USB_REMOTO
            printf("OPERACION PARA EL CASO %X\n",sel);
            printf("AGREGAR RUTINA QUE HAGA ALGO CON LOS DATOS RECIBIDOS\n\n");
#endif
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            txBuffer[0]=0x03;
            txBuffer[1]=0x0C;
            txBuffer[2]=0x0D;
            txBuffer[3]=0x0E;
            while (ep1Bi.Stat & UOWN){
                ProcessUSBTransactions();
            }
            txCnt=HIDTxReport(txBuffer, 64);
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            memset(rxBuffer,0x00,HID_INPUT_REPORT_BYTES);
        break;
        case(0x03)://DELAY
#ifdef DEBUG_USB_REMOTO
            printf("OPERACION PARA EL CASO %X\n",sel);
            printf("AGREGAR RUTINA QUE HAGA ALGO CON LOS DATOS RECIBIDOS\n\n");
#endif
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            txBuffer[0]=0x04;
            txBuffer[1]=0x0D;
            txBuffer[2]=0x0E;
            txBuffer[3]=0x0F;
            while (ep1Bi.Stat & UOWN){
                ProcessUSBTransactions();
            }
            txCnt=HIDTxReport(txBuffer, 64);
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            memset(rxBuffer,0x00,HID_INPUT_REPORT_BYTES);
        break;
        default:
#ifdef DEBUG_USB_REMOTO
            printf("default\n");
#endif
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            txBuffer[0]=0x05;
            txBuffer[1]=0x0E;
            txBuffer[2]=0x0F;
            txBuffer[3]=0x01;
            while (ep1Bi.Stat & UOWN){
                ProcessUSBTransactions();
            }
            txCnt=HIDTxReport(txBuffer, 64);
            memset(txBuffer,0x00,HID_INPUT_REPORT_BYTES);
            memset(rxBuffer,0x00,HID_INPUT_REPORT_BYTES);
        break;
        }
    return;
}