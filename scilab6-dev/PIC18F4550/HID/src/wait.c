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
unsigned int coms=FREQ/4000;
void delay_ms( unsigned int ms){
#ifdef wait_delay
    ms = ms * coms;
    do{
        wait(250);
    }while(--ms);
#else
    do{
        delay_us(1000);
    }while(--ms);
#endif
    return;
}
void wait( unsigned char a ){
    a;
    _asm
        sublw 1
	bucle:
            addlw 1
            btfss STATUS,0
            goto bucle
    _endasm;
    return;
}
void wait_ms( unsigned int ms){
    ms = ms * coms;
    while (ms > 0 ){
        wait(250);
        ms--;
    }
    return;
}