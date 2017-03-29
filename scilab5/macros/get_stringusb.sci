// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout = get_stringusb( varargin )
    [lhs,rhs]=argn()
    if ( rhs < 1 | rhs > 2 ) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "get_stringusb",1,2,rhs))
    end
    if ( lhs < 2 | lhs > 2 ) then
        error(msprintf(..
        "%s: Expected from %d to %d output arguments, "+..
        "but %d are provided",..
        "get_stringusb",2,2,lhs))
    end
    index=varargin(1)
    index=uint16(index)
    if ( rhs > 1 ) then
        comu_type=varargin(2)
    else
        comu_type="hid"
    end
    select comu_type
    case "hid"
        [_string,success]=hid_get_string(index);
    case "bulk"
        [_string,success]=bulk_get_string(index);
    case "iso"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    case "cdc"
        error("This comunication type is not implemented yet.Try USB HID comunication protocol")
    else
        error("Unexpected value")
    end    
    varargout(1) = _string;
    varargout(2) = success;
endfunction
// ====================================================================