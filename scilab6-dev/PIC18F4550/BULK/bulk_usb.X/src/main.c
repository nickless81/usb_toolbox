/********************************************************************
 FileName:		main.c
 Dependencies:	See INCLUDES section
 Processor:		PIC18, PIC24, and PIC32 USB Microcontrollers
 Hardware:		This demo is natively intended to be used on Microchip USB demo
 				boards supported by the MCHPFSUSB stack.  See release notes for
 				support matrix.  This demo can be modified for use on other hardware
 				platforms.
 Complier:  	Microchip C18 (for PIC18), C30 (for PIC24), C32 (for PIC32)
 Company:		Microchip Technology, Inc.

 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the �Company�) for its PIC� Microcontroller is intended and
 supplied to you, the Company�s customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************
 File Description:

 Change History:
  Rev   Description
  ----  -----------------------------------------
  2.6a  Added support for the PIC24FJ256GB210

  2.7   No change

  2.7b  Improvements to USBCBSendResume(), to make it easier to use.
********************************************************************/

/** INCLUDES *******************************************************/
#include <stdio.h>
#include <usart.h>
#include <delays.h>
#include "USB/usb.h"
#include "USB/usb_function_generic.h"
#pragma config PLLDIV   = 1         // (20 MHz crystal on PICDEM FS USB board)
#pragma config CPUDIV   = OSC1_PLL2
#pragma config USBDIV   = 2         // Clock source from 96MHz PLL/2
#pragma config FOSC     = HSPLL_HS
#pragma config FCMEN    = OFF
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BOR      = ON
#pragma config BORV     = 3
#pragma config VREGEN   = ON      //USB Voltage Regulator
#pragma config WDT      = OFF
#pragma config WDTPS    = 32768
#pragma config MCLRE    = ON
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF
#pragma config STVREN   = ON
#pragma config LVP      = OFF
#pragma config XINST    = OFF       // Extended Instruction Set
#pragma config CP0      = OFF
#pragma config CP1      = OFF
#pragma config CPB      = OFF
#pragma config WRT0     = OFF
#pragma config WRT1     = OFF
#pragma config WRTB     = OFF       // Boot Block Write Protection
#pragma config WRTC     = OFF
#pragma config EBTR0    = OFF
#pragma config EBTR1    = OFF
#pragma config EBTRB    = OFF

/** VARIABLES ******************************************************/
#pragma udata USB_VARIABLES=0x500


unsigned char OUTPacket[64];	//User application buffer for receiving and holding OUT packets sent from the host
unsigned char INPacket[64];		//User application buffer for sending IN packets to the host
#pragma udata
USB_HANDLE USBGenericOutHandle;
USB_HANDLE USBGenericInHandle;
#pragma udata

/** PRIVATE PROTOTYPES *********************************************/
static void InitializeSystem(void);
void USBDeviceTasks(void);
void YourHighPriorityISRCode(void);
void YourLowPriorityISRCode(void);
void UserInit(void);
void ProcessIO(void);
//void BlinkUSBStatus(void);

#define REMAPPED_RESET_VECTOR_ADDRESS		0x00
#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS	0x08
#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS	0x18
	
#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS
void Remapped_High_ISR (void)
{
     _asm goto YourHighPriorityISRCode _endasm
}
#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS
void Remapped_Low_ISR (void)
{
     _asm goto YourLowPriorityISRCode _endasm
}
#pragma code
#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode()
{
#if defined(USB_INTERRUPT)
    USBDeviceTasks();
#endif
}
#pragma interruptlow YourLowPriorityISRCode
void YourLowPriorityISRCode()
{

}
#pragma code
void main(void)
{   
    InitializeSystem();
#if defined(USB_INTERRUPT)
    USBDeviceAttach();
#endif
    printf("Inicializando Bulk Device\n");

    while(1)
    {
#if defined(USB_POLLING)
        USBDeviceTasks(); 
#endif
        ProcessIO();        
    }
}


/********************************************************************
 * Function:        static void InitializeSystem(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        InitializeSystem is a centralize initialization
 *                  routine. All required USB initialization routines
 *                  are called from here.
 *
 *                  User application initialization routine should
 *                  also be called from here.                  
 *
 * Note:            None
 *******************************************************************/
static void InitializeSystem(void)
{

    ADCON1 |= 0x0F;
    USBGenericOutHandle = 0;
    USBGenericInHandle = 0;
    UserInit();
    USBDeviceInit();//usb_device.c.  Initializes USB module SFRs and firmware
                                    //variables to known states.
}
void UserInit(void)
{
    OpenUSART(
        USART_TX_INT_OFF  &
        USART_RX_INT_OFF &
        USART_ASYNCH_MODE &
        USART_EIGHT_BIT,
        25
    );
}


void ProcessIO(void)
{
    if(( USBDeviceState < CONFIGURED_STATE ) || ( USBSuspendControl == 1 ))
    {
        return;
    }
    if(!USBHandleBusy( USBGenericOutHandle ))
    {   
        switch( OUTPacket[0] )
        {
            case 0x80:
                printf("blinkStatusValid = FALSE;\n");
#if defined(USB_POLLING)
                printf("defined(USB_POLLING)\n");
#endif
#if defined(USB_INTERRUPT)
                printf("defined(USB_INTERRUPT)\n");
#endif
                break;
            case 0x81:
#if defined(USB_POLLING)
                printf("defined(USB_POLLING)\n");
#endif
#if defined(USB_INTERRUPT)
                printf("defined(USB_INTERRUPT)\n");
#endif
                INPacket[0] = 0x81;
                printf("INPacket[0] = 0x81;\n");
                INPacket[1] = 0x0C;
                INPacket[2] = 0x0B;
                INPacket[3] = 0x0A;
                INPacket[4] = 0x0F;
                if(!USBHandleBusy(USBGenericInHandle))
                {
                    USBGenericInHandle = USBGenWrite(USBGEN_EP_NUM,(BYTE*)&INPacket,USBGEN_EP_SIZE);
                }
                break;
        }
        printf("Previo USBGenericOutHandle\n");
        USBGenericOutHandle = USBGenRead(USBGEN_EP_NUM,(BYTE*)&OUTPacket,USBGEN_EP_SIZE);
        printf("Posterior USBGenericOutHandle\n");
    }
}
/** EOF main.c ***************************************************************/
