// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function demo_enumerate()
    clc
    bulk_init();
    enum_success=bulk_enumerate();
    if( ~( enum_success < 0 ) ) then
        success_next = 0;
        M_Vendor=list();
        M_Product=list();
        i=0;
        while( ~( success_next < 0 ) ) 
           i=i+1;
           [success_dev,vendor_id,product_id]=bulk_get_device_string ();
           M_Vendor($+1)=vendor_id;
           M_Product($+1)=product_id;
           success_next=bulk_next_device(); 
        end
        free_success=bulk_free_enumeration();
        bulk_exit();
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