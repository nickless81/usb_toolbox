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
#include <app.h>
unsigned char dato[]={
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
    'Q','R','S','T','U','V','W','X','Y','Z','@','#','$','&','?','+',
    'q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6'
};
unsigned char sel;
