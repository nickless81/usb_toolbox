#ifndef BULK_H
#define BULK_H
/* C */
#include <stdio.h>
#include <string.h>
#if !defined(_MINGW_)
	#include <stdlib.h>
#endif
#include <ctype.h>
#include <locale.h>
#include <errno.h>
/* GNU / LibUSB */
#include <libusb.h>
/**/
#if defined(_WIN32)
    #define msleep(msecs) Sleep(msecs)
#else
#include <unistd.h>
    #define msleep(msecs) usleep(1000*msecs)
#endif

#if !defined(_MSC_VER) || _MSC_VER<=1200
    #define sscanf_s sscanf
#endif
#if !defined(bool)
    #define bool int
#endif
#if !defined(true)
    #define true (1 == 1)
#endif
#if !defined(false)
    #define false (!true)
#endif
#define usb_interface interface
/**/
#ifdef __cplusplus
extern "C" {
#endif
    struct bulk_device_;
    typedef struct bulk_device_ bulk_device;
    int bulk_init(void);
    void bulk_close(libusb_device_handle *);
    int bulk_exit(void);
    int bulk_get_indexed_string(libusb_device_handle *,uint8_t,unsigned char *,int);
    int bulk_get_manufacturer_string(libusb_device_handle *,unsigned char *,int);
    int bulk_get_product_string(libusb_device_handle *,unsigned char *,int);
    int bulk_get_serial_number_string(libusb_device_handle *,unsigned char *,int);
    libusb_device_handle * bulk_open(unsigned short VendorID,unsigned short ProductID);
    int bulk_read(libusb_device_handle *,unsigned char,unsigned char *,int,int *);
    int bulk_read_timeout(libusb_device_handle *,unsigned char,unsigned char *,int,int *,unsigned int);
    int bulk_write(libusb_device_handle *,unsigned char,unsigned char *,int,int *);
    int bulk_write_timeout(libusb_device_handle *,unsigned char,unsigned char *,int,int *,unsigned int);
    /********************unimplemented************************************/
    char bulk_enumerate( void);//unsigned short,unsigned short);
    char bulk_free_enumeration(void);
    char bulk_get_device_string(unsigned short *,unsigned short *);
    char bulk_next_device(int);
    /********************************************************************/
#ifdef __cplusplus
}
#endif
#endif // BULK_H
