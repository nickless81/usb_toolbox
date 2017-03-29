// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function demo_strings()
    clc
    VendorID="04D8";
    //ProductID="900A";
    ProductID="010B";
    VendorID=uint16(hex2dec(VendorID));
    ProductID=uint16(hex2dec(ProductID));
    enum_success=hid_enumerate();
    init_success=hid_init();
    if ( init_success < 0 ) then
       disp("unable to initialize the HIDAPI Library");
       return
    else
         disp("HIDAPI Library initialized");
    end
    open_success=hid_open(VendorID,ProductID);
    if ( open_success < 0 ) then
         disp("unable to open device");
         disp("make sure the USB HID Device is connected to the host");
         disp("or change the VendorID and ProductID");
         return
    else
         disp("Device Open");
    end
    free_success=hid_free_enumeration();
    [manufacturer_string,manufacturer_success]=hid_get_manufacturer()
    if ( manufacturer_success < 0 ) then
         disp("unable to get manufacturer string");
         close_success=hid_close();
         exit_success=hid_exit();
         return
    else
         type(manufacturer_string)
         size(manufacturer_string)
         disp(manufacturer_string);
    end
    [product_string,product_success]=hid_get_product()
    if ( product_success< 0 ) then
         disp("unable to get product string");
         close_success=hid_close();
         exit_success=hid_exit();
         return
    else
         disp(product_string);
    end
    [serial_string,serial_success]=hid_get_serial()
    if ( serial_success < 0 ) then
         disp("unable to get serial string");
         close_success=hid_close();
         exit_success=hid_exit();
         return
    else
         disp(serial_string);
    end
    disp("using hid_get_string");
    for i=1:3
        [indexed_string,string_success]=hid_get_string(uint16(i))
        if ( string_success < 0 ) then
             disp("unable to get indexed string");
             close_success=hid_close();
             exit_success=hid_exit();
             return
        else
             disp(indexed_string);
        end    
    end
    close_success=hid_close();  
    if ( close_success < 0 ) then
       disp("unable to closed device");
    else
       disp("device closed");
    end
    exit_success=hid_exit();
    if ( exit_success < 0 ) then
       disp("unable to free static data associated with HIDAPI Library");
       return
    else
       disp("HIDAPI Library have been freed all of the static data associated");
    end
endfunction
demo_strings();
clear demo_strings;
