// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout = exitusb( varargin )
    [lhs,rhs]=argn()
    if ( rhs > 1 ) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "exitusb",0,1,rhs))
    end
    if ( lhs > 1 ) then
        error(msprintf(..
        "%s: Expected from %d to %d output arguments, "+..
        "but %d are provided",..
        "exitusb",0,1,lhs))
    end
    if ( rhs > 0) then
        comu_type=varargin(1)
    else
        comu_type="hid"
    end
    select comu_type
    case "hid"
        success=hid_exit();
    case "bulk"
        success=bulk_exit();
    case "iso"
        error("This comunication type is not implemented yet.Try USB HID comunication protocol")
    case "cdc"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    else
        error("Unexpected value")
    end
    varargout(1) = success;
endfunction
// ====================================================================