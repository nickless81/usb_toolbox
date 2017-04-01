// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function builder_gw_c()
  CURRENT_PATH = strsubst(get_absolute_file_path("builder_gateway_c.sce"), "\", "/");

  // if you do not this variable, PutLhsVar is added
  // in gateway generated (default mode in scilab 4.x and 5.x)
  WITHOUT_AUTO_PUTLHSVAR = %t;
  FUNCTIONS_GATEWAY =[
    "hid_init"                , "sci_hid_init";
    "hid_close"               , "sci_hid_close";
    "hid_enumerate"           , "sci_hid_enumerate";
    "hid_error"               , "sci_hid_error";
    "hid_exit"                , "sci_hid_exit";
    "hid_free_enumeration"    , "sci_hid_free_enumeration";
    "hid_get_device_string"   , "sci_hid_get_device_string";
    "hid_get_feature_report"  , "sci_hid_get_feature_report";
    "hid_get_string"          , "sci_hid_get_indexed_string";
    "hid_get_manufacturer"    , "sci_hid_get_manufacturer_string";
    "hid_get_product"         , "sci_hid_get_product_string";
    "hid_get_serial"          , "sci_hid_get_serial_number_string";
    "hid_next_device"         , "sci_hid_next_device";
    "hid_open"                , "sci_hid_open";
    "hid_read"                , "sci_hid_read";
    "hid_read_timeout"        , "sci_hid_read_timeout";
    "hid_send_feature_report" , "sci_hid_send_feature_report";
    "hid_set_nonblocking"     , "sci_hid_set_nonblocking";
    "hid_write"               , "sci_hid_write";
    "bulk_init"               , "sci_bulk_init";
    "bulk_close"              , "sci_bulk_close";
    "bulk_exit"               , "sci_bulk_exit";
    "bulk_get_string"         , "sci_bulk_get_indexed_string";
    "bulk_get_manufacturer"   , "sci_bulk_get_manufacturer_string";
    "bulk_get_product"        , "sci_bulk_get_product_string";
    "bulk_get_serial"         , "sci_bulk_get_serial_number_string";
    "bulk_open"               , "sci_bulk_open";
    "bulk_read"               , "sci_bulk_read";
    "bulk_read_timeout"       , "sci_bulk_read_timeout";
    "bulk_set_endpoint"       , "sci_bulk_set_endpoint";
    "bulk_write"              , "sci_bulk_write";
    "bulk_write_timeout"      , "sci_bulk_write_timeout";
    "bulk_enumerate"          , "sci_bulk_enumerate";
    "bulk_free_enumeration"   , "sci_bulk_free_enumeration";
    "bulk_get_device_string"  , "sci_bulk_get_device_string";
    "bulk_next_device"        , "sci_bulk_next_device";
  ];
  OS=getos()
  [version, opts] = getversion()
  select OS
  case "Windows" then
      disp("Building for Windows")
      include_path=ilib_include_flag(get_absolute_file_path("builder_gateway_c.sce"))+[" -I C:\MinGW\include -I C:\MinGW\include\ddk"];
      include_path=include_path+[" -I ..\..\thirdparty\libusb-1.0.21\include\libusb-1.0\"];
      CFLAGS =ilib_include_flag(get_absolute_file_path("builder_gateway_c.sce"))+ include_path;
      if opts(2)== 'x86' then
          LDFLAGS="-L ..\..\thirdparty\libusb-1.0.21\MinGW32\static\ -lsetupapi -lusb-1.0";
          //LDFLAGS="-L ..\..\thirdparty\libusbx-1.0.10\MinGW32\static\ -lsetupapi -lusb-1.0";
      else
          LDFLAGS="-L ..\..\thirdparty\libusb-1.0.21\MinGW64\static\ -lsetupapi -lusb-1.0";
          //LDFLAGS="-L ..\..\thirdparty\libusbx-1.0.10\MinGW64\static\ -lsetupapi -lusb-1.0";
      end
      FILES_GATEWAY=[
            "bulk-libusb.c",
            "sci_bulk.c",
            "hid.c",
            "sci_hidapi.c"
            ];
      tbx_build_gateway("usb_toolbox_c",FUNCTIONS_GATEWAY,FILES_GATEWAY,CURRENT_PATH,"",LDFLAGS,CFLAGS);
  case "Linux" then
      disp("Building for Linux")
      include_path=ilib_include_flag(get_absolute_file_path("builder_gateway_c.sce")+"../../thirdparty/libusb-1.0.21/include");
      CFLAGS =ilib_include_flag(get_absolute_file_path("builder_gateway_c.sce"))+include_path;
      if opts(2)== 'x86' then
          LIBS=["../../thirdparty/libusb-1.0.21/i386/lib/libusb-1.0"];
      else
          LIBS=["../../thirdparty/libusb-1.0.21/amd64/lib/libusb-1.0"];
      end
      FILES_GATEWAY=[
            "bulk-libusb.c",
            "sci_bulk.c",
            "linux/hid.c",
            "sci_hidapi.c"
            ];
      tbx_build_gateway("usb_toolbox_c",FUNCTIONS_GATEWAY,FILES_GATEWAY,CURRENT_PATH,LIBS,"",CFLAGS);
  end
endfunction
builder_gw_c();
clear builder_gw_c; // remove builder_gw_c on stack
