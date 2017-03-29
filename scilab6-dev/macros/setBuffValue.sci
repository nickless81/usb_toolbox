// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout=setBuffValue( varargin )
    [lhs,rhs]=argn()
    if ( rhs < 3 | rhs > 3) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "setBuffValue",3,3,rhs))
    end
    if ( lhs < 1 | lhs > 1) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "setBuffValue",1,1,rhs))
    end
    buff=varargin(1)
    pos = uint8(varargin(2))
    value= uint8(varargin(3))
    buff(1,pos)=value;
    varargout(1) = buff;
endfunction
// ====================================================================