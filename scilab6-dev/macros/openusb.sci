// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout = openusb( varargin )
    [lhs,rhs]=argn()
    if ( rhs < 2 | rhs > 5 ) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "openusb",2,5,rhs))
    end
    if ( lhs > 1 ) then
        error(msprintf(..
        "%s: Expected from %d to %d output arguments, "+..
        "but %d are provided",..
        "openusb",0,1,lhs))
    end
    VendorID = varargin(1)
    ProductID = varargin(2)
    if ( rhs > 2) then
        comu_type=varargin(3)
    else
        comu_type="hid"
    end
    VendorID = uint16( hex2dec( VendorID ) );
    ProductID = uint16( hex2dec( ProductID ) );
    select comu_type
    case "hid"
        success=hid_open(VendorID,ProductID);
        endP_success=0;
    case "bulk"
        success_open=bulk_open(VendorID,ProductID);
        if ( rhs > 3) then
            enpIn=varargin(4)
            enpOut=varargin(5)
        else
            enpIn=1;
            enpOut=1;
        end
        enpIn=int32(enpIn);
        enpOut=int32(enpOut);
        endP_success=bulk_set_endpoint(enpIn,enpOut);
        if( endP_success < 0 | success_open < 0 ) then
            success=-1;
        else
            success=1;
        end
    case "iso"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    case "cdc"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    else
        error("Unexpected value")
    end
    varargout(1) = success;
endfunction
// ====================================================================