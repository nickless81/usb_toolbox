// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function demo_read_bulk()
    clc
    n=5;
    txBuff=init_buff(n);
    for i=1:n
        txBuff=setBuffValue(txBuff,i,i);
    end
    txBuff=setBuffValue(txBuff,1,uint8(hex2dec("81")));
    VendorID="04D8";
    ProductID="0204";
    VendorID=uint16(hex2dec(VendorID));
    ProductID=uint16(hex2dec(ProductID));
    enpIn=1;
    enpOut=1;
    enpIn=int32(enpIn);
    enpOut=int32(enpOut);
    init_success=bulk_init();
    if ( init_success < 0 ) then
       disp("unable to initialize the Libusb-1.0 Library");
       return
    else
         disp("Libusb-1.0 Library initialized");
    end
    bulk_enumerate();
    open_success=bulk_open(VendorID,ProductID);
    bulk_free_enumeration();
    if ( open_success < 0 ) then
         disp("unable to open device");
         return
    else
         disp("device open");
    end
    endP_success=bulk_set_endpoint(enpIn,enpOut);
    if ( endP_success < 0 ) then
       disp("unable to set end points");
    else
       disp("end points has been set");
    end
    write_success=bulk_write(txBuff,uint8(n));
    if ( write_success < 0 ) then
       disp("unable to write device");
       bulk_close();
       bulk_exit();
       return
    else
       disp("device have been written");
    end
    [rxBuff,read_success]=bulk_read(uint8(n));
    disp("read_success")
    disp(read_success)
    if ( read_success < 0 ) then
       disp("unable to read device");
    else
       disp("device have been read");
       disp(rxBuff);
    end
    close_success=bulk_close();  
    if ( close_success < 0 ) then
       disp("unable to closed device");
    else
       disp("device closed");
    end
    exit_success=bulk_exit();
    if ( init_success < 0 ) then
       disp("unable to free static data associated with Libusb-1.0 Library");
       return
    else
       disp("Libusb-1.0 Library have been freed all of the static data associated");
    end
endfunction
demo_read_bulk();
clear demo_read_bulk;
