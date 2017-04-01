#include <wchar.h>
#include "libusb_toolbox_c.hxx"
extern "C"
{
#include "libusb_toolbox_c.h"
#include "addfunction.h"
}

#define MODULE_NAME L"libusb_toolbox_c"

int libusb_toolbox_c(wchar_t* _pwstFuncName)
{
    if(wcscmp(_pwstFuncName, L"hid_init") == 0){ addCStackFunction(L"hid_init", &sci_hid_init, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_close") == 0){ addCStackFunction(L"hid_close", &sci_hid_close, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_enumerate") == 0){ addCStackFunction(L"hid_enumerate", &sci_hid_enumerate, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_error") == 0){ addCStackFunction(L"hid_error", &sci_hid_error, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_exit") == 0){ addCStackFunction(L"hid_exit", &sci_hid_exit, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_free_enumeration") == 0){ addCStackFunction(L"hid_free_enumeration", &sci_hid_free_enumeration, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_get_device_string") == 0){ addCStackFunction(L"hid_get_device_string", &sci_hid_get_device_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_get_feature_report") == 0){ addCStackFunction(L"hid_get_feature_report", &sci_hid_get_feature_report, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_get_string") == 0){ addCStackFunction(L"hid_get_string", &sci_hid_get_indexed_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_get_manufacturer") == 0){ addCStackFunction(L"hid_get_manufacturer", &sci_hid_get_manufacturer_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_get_product") == 0){ addCStackFunction(L"hid_get_product", &sci_hid_get_product_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_get_serial") == 0){ addCStackFunction(L"hid_get_serial", &sci_hid_get_serial_number_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_next_device") == 0){ addCStackFunction(L"hid_next_device", &sci_hid_next_device, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_open") == 0){ addCStackFunction(L"hid_open", &sci_hid_open, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_read") == 0){ addCStackFunction(L"hid_read", &sci_hid_read, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_read_timeout") == 0){ addCStackFunction(L"hid_read_timeout", &sci_hid_read_timeout, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_send_feature_report") == 0){ addCStackFunction(L"hid_send_feature_report", &sci_hid_send_feature_report, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_set_nonblocking") == 0){ addCStackFunction(L"hid_set_nonblocking", &sci_hid_set_nonblocking, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"hid_write") == 0){ addCStackFunction(L"hid_write", &sci_hid_write, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_init") == 0){ addCStackFunction(L"bulk_init", &sci_bulk_init, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_close") == 0){ addCStackFunction(L"bulk_close", &sci_bulk_close, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_exit") == 0){ addCStackFunction(L"bulk_exit", &sci_bulk_exit, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_get_string") == 0){ addCStackFunction(L"bulk_get_string", &sci_bulk_get_indexed_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_get_manufacturer") == 0){ addCStackFunction(L"bulk_get_manufacturer", &sci_bulk_get_manufacturer_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_get_product") == 0){ addCStackFunction(L"bulk_get_product", &sci_bulk_get_product_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_get_serial") == 0){ addCStackFunction(L"bulk_get_serial", &sci_bulk_get_serial_number_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_open") == 0){ addCStackFunction(L"bulk_open", &sci_bulk_open, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_read") == 0){ addCStackFunction(L"bulk_read", &sci_bulk_read, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_read_timeout") == 0){ addCStackFunction(L"bulk_read_timeout", &sci_bulk_read_timeout, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_set_endpoint") == 0){ addCStackFunction(L"bulk_set_endpoint", &sci_bulk_set_endpoint, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_write") == 0){ addCStackFunction(L"bulk_write", &sci_bulk_write, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_write_timeout") == 0){ addCStackFunction(L"bulk_write_timeout", &sci_bulk_write_timeout, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_enumerate") == 0){ addCStackFunction(L"bulk_enumerate", &sci_bulk_enumerate, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_free_enumeration") == 0){ addCStackFunction(L"bulk_free_enumeration", &sci_bulk_free_enumeration, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_get_device_string") == 0){ addCStackFunction(L"bulk_get_device_string", &sci_bulk_get_device_string, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"bulk_next_device") == 0){ addCStackFunction(L"bulk_next_device", &sci_bulk_next_device, MODULE_NAME); }

    return 1;
}
