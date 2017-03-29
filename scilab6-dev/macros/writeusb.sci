// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout = writeusb( varargin )
    [lhs,rhs]=argn()
    if ( rhs < 2 | rhs > 3 ) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "writeusb",2,3,rhs))
    end
    if ( lhs > 1 ) then
        error(msprintf(..
        "%s: Expected from %d to %d output arguments, "+..
        "but %d are provided",..
        "writeusb",0,1,lhs))
    end
    _buff = varargin(1)
    _size = varargin(2)
    _size =uint8(_size)
    if ( rhs > 2) then
        comu_type=varargin(3)
    else
        comu_type="hid"
    end
    select comu_type
    case "hid"
        Success=hid_write(_buff,_size);
    case "bulk"
        Success=bulk_write(_buff,_size);
    case "iso"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    case "cdc"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    else
        error("Unexpected value")
    end
    varargout(1) = Success;
endfunction
// ====================================================================