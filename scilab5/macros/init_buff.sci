// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
function varargout = init_buff( varargin )
    [lhs,rhs]=argn()
    if ( rhs > 1 ) then
        error(msprintf(..
        "%s: Expected from %d to %d input arguments, "+..
        "but %d are provided",..
        "init_buff",0,1,rhs))
    end
    if ( lhs > 1 ) then
        error(msprintf(..
        "%s: Expected from %d to %d output arguments, "+..
        "but %d are provided",..
        "init_buff",0,1,lhs))
    end
    if ( rhs == 0) then
        length_buff = uint8(64)
    else 
        length_buff = uint8(varargin(1))
    end
    if (length_buff >64) then
        error(msprintf(..
        "%s: Expected an maxim number %d but %d are provided",..
        "init_buff",64,length_buff))
    end
    buff=uint8(zeros(1,length_buff));
    varargout(1) = buff;
endfunction
// ====================================================================