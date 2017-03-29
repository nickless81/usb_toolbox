// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout = read_timeoutusb( varargin )
    [lhs,rhs]=argn()
    if ( rhs < 2 | rhs > 3 ) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "read_timeoutusb",2,3,rhs))
    end
    if ( lhs > 2 ) then
        error(msprintf(..
        "%s: Expected from %d to %d output arguments, "+..
        "but %d are provided",..
        "read_timeoutusb",0,2,lhs))
    end
    _size = varargin(1)
    _size =uint8(_size)
    if ( rhs > 1) then
       timeout=varargin(2) 
    else
        timeout=-1;
    end
    if ( rhs > 2) then
        comu_type=varargin(3)
    else
        comu_type="hid"
    end
    timeout=int32(timeout);
    select comu_type
    case "hid"
        [rxBuffer,success]=hid_read_timeout(_size,timeout);
    case "bulk"
        [rxBuffer,success]=bulk_read_timeout(_size,timeout);
    case "iso"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    case "cdc"
        error("This comunication type is not implemented yet. Try USB HID comunication protocol")
    else
        error("Unexpected value")
    end
    varargout(1) = rxBuffer;
    if( lhs >= 2 ) then
        varargout(2) = success;
    end
endfunction
// ====================================================================