/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#ifndef _APP_H_
#define _APP_H_
#define LOBYTE(x) (*((char *)&x))
#define HIBYTE(x) (*(((char *)&x)+1))
#define FREQ 48000
#define DATO_LENGHT 64
#define LED LATAbits.LATA0
#define LED_ENUM LATBbits.LATB5
#define LED_ON 0
#define LED_OFF 1
#define FALSE 0
#define TRUE 1
#if FREQ == 48000
    #define delay_us(x) { unsigned int _dcnt; \
            _dcnt = (x)/1.25; \
            while(--_dcnt != 0) \
            continue; }
#elif FREQ == 8000
    #define delay_us(x) { unsigned int _dcnt; \
            _dcnt = (x)/7.5; \
            while(--_dcnt != 0) \
            continue; }
#elif FREQ == 4000
    #define delay_us(x) { unsigned int _dcnt; \
            _dcnt = (x)/15; \
            while(--_dcnt != 0) \
            continue; }
#endif
extern unsigned char dato[];
extern unsigned char index_dato;
extern unsigned int coms;
extern unsigned char sel;
/* @brief
 * @param
 * @param
 * @return
 */
extern void checkEcho(void);
/* @brief
 * @param
 * @param
 * @return
 */
extern int USBEcho(void);
/* @brief
 * @param
 * @param
 * @return
 */
extern void UserInit(void);
/* @brief
 * @param
 * @param
 * @return
 */
extern void ProcessIO(void);
/* @brief
 * @param
 * @param
 * @return
 */
extern void init_usart(void);
/* @brief
 * @param ms. Restardo en milisegundos
 * @param
 * @return
 */
extern void wait( unsigned char);
/* @brief
 * @param a. tiempo = (4a + 1)µs a>=2, para 4MHz
 * @param
 * @return
 */
extern void wait_ms( unsigned int);
extern void delay_ms( unsigned int);
/* @brief
 * @param
 * @param
 * @return
 */
extern void usb_remoto(void);
#endif
