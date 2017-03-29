// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function demo_strings_bulk()
    clc
    VendorID="04D8";
    //ProductID="0204";
    //ProductID="900A";
    ProductID="010B";
    VendorID=uint16(hex2dec(VendorID));
    ProductID=uint16(hex2dec(ProductID));
    init_success=bulk_init();
    if ( init_success < 0 ) then
       disp("unable to initialize the Libusb-1.0 Library");
       return
    else
         disp("Libusb-1.0 Library initialized");
    end
    open_success=bulk_open(VendorID,ProductID);
    if ( open_success < 0 ) then
         disp("unable to open device");
         disp("make sure the USB BULK Device is connected to the host");
         disp("or change the VendorID and ProductID");
         return
    else
         disp("Device Open");
    end
    [manufacturer_string,manufacturer_success]=bulk_get_manufacturer()
    if ( manufacturer_success < 0 ) then
         disp("unable to get manufacturer string");
         close_success=bulk_close();
         exit_success=bulk_exit();
         return
    else
         disp(manufacturer_string);
    end
    [product_string,product_success]=bulk_get_product()
    if ( product_success< 0 ) then
         disp("unable to get product string");
         close_success=bulk_close();
         exit_success=bulk_exit();
         return
    else
         disp(product_string);
    end
    [serial_string,serial_success]=bulk_get_serial()
    if ( serial_success < 0 ) then
         disp("unable to get serial string");
         close_success=bulk_close();
         exit_success=bulk_exit();
         return
    else
         disp(serial_string);
    end
    for i=1:3
        [indexed_string,string_success]=bulk_get_string(uint16(i))
        if ( string_success < 0 ) then
             disp("unable to get indexed string");
             close_success=bulk_close();
             exit_success=bulk_exit();
             return
        else
             disp(indexed_string);
        end    
    end
    close_success=bulk_close();  
    if ( close_success < 0 ) then
       disp("unable to closed device");
    else
       disp("device closed");
    end
    exit_success=bulk_exit();
    if ( exit_success < 0 ) then
       disp("unable to free static data associated with Libusb-1.0 Library");
       return
    else
       disp("Libusb-1.0 Library have been freed all of the static data associated");
    end
endfunction
demo_strings_bulk();
clear demo_strings_bulk;
