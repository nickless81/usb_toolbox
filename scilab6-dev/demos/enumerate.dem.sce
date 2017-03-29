// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function demo_enumerate()
    clc
    hid_init();
    enum_success=hid_enumerate();
    if( ~( enum_success < 0 ) ) then
        success_next = 0;
        M_Vendor=list();
        M_Product=list();
        i=0;
        while( ~( success_next < 0 ) ) 
           i=i+1;
           [success_dev,vendor_id,product_id]=hid_get_device_string ();
           M_Vendor($+1)=vendor_id;
           M_Product($+1)=product_id;
           success_next=hid_next_device(); 
        end
        free_success=hid_free_enumeration();
        hid_exit();
        Devices=zeros(i,2)
        for k=1:i
            Devices(k,1)=M_Vendor(k)
            Devices(k,2)=M_Product(k)
        end
        Devices=dec2hex(Devices);
        disp("VendorID  ProductID")
        disp(Devices);
    end
endfunction
demo_enumerate();
clear demo_enumerate;
