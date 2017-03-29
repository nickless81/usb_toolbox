/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#ifndef _config_pic_h
#define _config_pic_h
code char at __CONFIG1L CONFIG1L = _PLLDIV_NO_DIVIDE__4MHZ_INPUT__1L & _CPUDIV__OSC1_OSC2_SRC___1__96MHZ_PLL_SRC___2__1L & _USBPLL_CLOCK_SRC_FROM_96MHZ_PLL_2_1L;
code char at __CONFIG1H CONFIG1H = _OSC_HS__HS_PLL__USB_HS_1H & _FCMEN_OFF_1H & _IESO_OFF_1H;
code char at __CONFIG2L CONFIG2L = _PUT_OFF_2L & _BODEN_ON_WHILE_ACTIVE_2L & _BODENV_2_0V_2L & _VREGEN_ON_2L;
code char at __CONFIG2H CONFIG2H = _WDT_DISABLED_CONTROLLED_2H & _WDTPS_1_32768_2H;
code char at __CONFIG3H CONFIG3H = _CCP2MUX_RB3_3H & _PBADEN_PORTB_4_0__CONFIGURED_AS_DIGITAL_I_O_ON_RESET_3H & _LPT1OSC_OFF_3H & _MCLRE_MCLR_ON_RE3_OFF_3H;
code char at __CONFIG4L CONFIG4L = _STVR_ON_4L & _LVP_OFF_4L & _ENICPORT_OFF_4L & _ENHCPU_OFF_4L & _BACKBUG_OFF_4L;
code char at __CONFIG5L CONFIG5L = _CP_0_ON_5L & _CP_1_OFF_5L & _CP_2_OFF_5L & _CP_3_OFF_5L;
code char at __CONFIG5H CONFIG5H = _CPB_OFF_5H;
code char at __CONFIG6L CONFIG6L = _WRT_0_OFF_6L & _WRT_1_OFF_6L & _WRT_2_OFF_6L & _WRT_3_OFF_6L;
code char at __CONFIG6H CONFIG6H = _WRTC_OFF_6H & _WRTB_OFF_6H;
code char at __CONFIG7L CONFIG7L = _EBTR_0_OFF_7L & _EBTR_1_OFF_7L & _EBTR_2_OFF_7L & _EBTR_3_OFF_7L;
code char at __CONFIG7H CONFIG7H = _EBTRB_OFF_7H;
#endif // _config_pic_h
