/* C */
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <errno.h>
*/
/* Libusb implementation*/
#include <bulk.h>
#ifdef __cplusplus
extern "C" {
#endif
    struct bulk_device_{
        /* Handle to the actual device. */
        libusb_device_handle *device_handle;

        /* Endpoint information */
        int input_endpoint;
        int output_endpoint;
        int input_ep_max_packet_size;

        /* The interface number of the HID */
        int interface;

        /* Indexes of Strings */
        int manufacturer_index;
        int product_index;
        int serial_index;
    };
    static libusb_context *usb_context = NULL;
    libusb_device **devs;
    libusb_device *dev;
    ssize_t DevAmount;
    int bulk_init(void){
        if (!usb_context) {
            /* Init Libusb */
            if ( libusb_init( &usb_context ) )
            {
                return -1;
            }
        }
        return 0;
    }
    void bulk_close(libusb_device_handle *handle){
        libusb_close(handle);
        return;
    }
    char bulk_enumerate(void)
    {
        DevAmount=libusb_get_device_list(usb_context, &devs);
        if(DevAmount>0){
            bulk_next_device(0);
        }
        return (char)DevAmount;
    }
    int bulk_exit(void){
        if ( usb_context )
        {
            libusb_exit( usb_context );
            usb_context = NULL;
            return 0;
        }else{
            return -1;
        }

    }
    char bulk_free_enumeration(void)
    {
        if(devs){
            libusb_free_device_list(devs, 1);
            return 0;
        }else{
            return -1;
        }
    }
    char bulk_get_device_string(unsigned short *VendorID,unsigned short *ProductID)
    {
        struct libusb_device_descriptor desc;
        int r = libusb_get_device_descriptor(dev, &desc);
        if (r < 0) {
            fprintf(stderr, "failed to get device descriptor");
            return (char)r;
        }
        *VendorID=desc.idVendor;
        *ProductID=desc.idProduct;
        /*
        printf("%04x:%04x (bus %d, device %d)\n",
            desc.idVendor, desc.idProduct,
            libusb_get_bus_number(dev), libusb_get_device_address(dev));
        */
        return (char)r;
    }
    int bulk_get_indexed_string(libusb_device_handle *dev,uint8_t desc_index,unsigned char *data,int length)
    {
        int Success;
        if(dev){
            Success = libusb_get_string_descriptor_ascii(dev,desc_index,data,length);
        }else{
            Success = -1;
        }
        return Success;
    }
    int bulk_get_manufacturer_string(libusb_device_handle *dev,unsigned char *data,int length)
    {
        int Success;
        if(dev){
            Success = libusb_get_string_descriptor_ascii(dev,1,data,length);
        }else{
            Success = -1;
        }
        return Success;
    }
    int bulk_get_product_string(libusb_device_handle *dev,unsigned char *data,int length)
    {
        int Success;
        if(dev){
            Success = libusb_get_string_descriptor_ascii(dev,2,data,length);
        }else{
            Success = -1;
        }
        return Success;
    }
    int bulk_get_serial_number_string(libusb_device_handle *dev,unsigned char *data,int length)
    {
        int Success;
        if(dev){
            Success = libusb_get_string_descriptor_ascii(dev,3,data,length);
        }else{
            Success = -1;
        }
        return Success;
    }
    char bulk_next_device(int pos)
    {
        if((dev = devs[pos]) != NULL){
            return 0;
        }else{
            return -1;
        }
    }
    libusb_device_handle * bulk_open(unsigned short VendorID,unsigned short ProductID)
    {
        libusb_device_handle *handle;
        handle = libusb_open_device_with_vid_pid(usb_context,VendorID, ProductID);
        return handle;
    }
    int bulk_read(libusb_device_handle *dev_handle,unsigned char endpoint,unsigned char *data,int length,int *transferred)
    {
        int Success;
        Success = libusb_bulk_transfer(
              dev_handle,
              endpoint,
              data,
              length,
              transferred,
              0
              );
        printf("bulk_read\n");
        printf("endpoint=%X\n",endpoint);
        printf("length=%i\n",length);
        printf("transferred=%i\n",*transferred);
        printf("Success=%i\n",Success);
        return Success;
    }
    int bulk_read_timeout(libusb_device_handle *dev_handle,unsigned char endpoint,unsigned char *data,int length,int *transferred,unsigned int timeout)
    {
        int Success;
        Success = libusb_bulk_transfer(
              dev_handle,
              endpoint,
              data,
              length,
              transferred,
              timeout
              );
        return Success;
    }
    int bulk_write(libusb_device_handle *dev_handle,unsigned char endpoint,unsigned char *data,int length,int *transferred){
        int Success;
        Success = libusb_bulk_transfer(
              dev_handle,
              endpoint,
              data,
              length,
              transferred,
              0
              );
        return Success;
    }
    int bulk_write_timeout(libusb_device_handle *dev_handle,unsigned char endpoint,unsigned char *data,int length,int *transferred,unsigned int timeout)
    {
        int Success;
        Success = libusb_bulk_transfer(
              dev_handle,
              endpoint,
              data,
              length,
              transferred,
              timeout
              );
        return Success;
    }






#ifdef __cplusplus
}
#endif
