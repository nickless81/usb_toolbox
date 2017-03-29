// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout=clearBuffValue( varargin )
    [lhs,rhs]=argn()
    if ( rhs < 2 | rhs > 2) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "clearBuffValue",2,2,rhs))
    end
    if ( lhs < 1 | lhs > 1) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "clearBuffValue",1,1,rhs))
    end
    buff=varargin(1)
    pos = uint8(varargin(2))
    disp("clearBuffValue hidapi using libusb-1.0");
    buff(1,pos)=0;
    varargout(1) = buff;
endfunction
// ====================================================================