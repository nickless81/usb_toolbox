// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function demo_read()
    clc
    n=5;
    txBuff=init_buff(n);
    for i=1:n
        txBuff=setBuffValue(txBuff,i,i);
    end
    VendorID="04D8";
    ProductID="010B";
    VendorID=uint16(hex2dec(VendorID));
    ProductID=uint16(hex2dec(ProductID));
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
         return
    else
         disp("device open");
    end
    write_success=hid_write(txBuff,uint8(n));
    if ( write_success < 0 ) then
       disp("unable to write device");
    else
       disp("device have been  written");
    end
    nonblocking_success=hid_set_nonblocking(%t);
    if ( nonblocking_success < 0 ) then
       disp("unable to set nonblocking");
    else
       disp("device have been set nonblocking");
    end
    [rxBuff,read_success]=hid_read(uint8(n));
    if ( read_success < 0 ) then
       disp("unable to read device");
    else
       disp("device have been read");
       disp(rxBuff);
    end
    close_success=hid_close();  
    if ( close_success < 0 ) then
       disp("unable to closed device");
    else
       disp("device closed");
    end
    exit_success=hid_exit();
    if ( init_success < 0 ) then
       disp("unable to free static data associated with HIDAPI Library");
       return
    else
       disp("HIDAPI Library have been freed all of the static data associated");
    end
endfunction
demo_read();
clear demo_read;
