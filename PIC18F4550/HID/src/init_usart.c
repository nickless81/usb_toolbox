/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <pic18fregs.h>
#include <stdio.h>
#include <usart.h>
#include <app.h>
void init_usart(void){
    usart_open(
            USART_TX_INT_OFF
            & USART_RX_INT_OFF
            & USART_BRGH_HIGH
            & USART_ASYNCH_MODE
            & USART_EIGHT_BIT,
            25
            );
    stdout = STREAM_USART;
    stdin = STREAM_USART;
    #ifdef DEBUG_USART
        printf("USB Test Startup\r\n");
    #endif
}