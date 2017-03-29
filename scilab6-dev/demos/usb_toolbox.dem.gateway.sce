// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  

function subdemolist = demo_gateway()
  demopath = get_absolute_file_path("usb_toolbox.dem.gateway.sce");

  subdemolist = [
                 "demo demo_enumerate"      , "enumerate.dem.sce";
                 "demo demo_read"           , "read.dem.sce";
                 "demo demo_strings"        , "strings.dem.sce"; 
                 "demo demo_enumerate_bulk" , "enumerate_bulk.dem.sce";
                 "demo demo_read_bulk"      , "read_bulk.dem.sce";
                 "demo demo_strings_bulk"   , "strings_bulk.dem.sce"; 
                 ];

  subdemolist(:,2) = demopath + subdemolist(:,2);
  
endfunction

subdemolist = demo_gateway();
clear demo_gateway; // remove demo_gateway on stack
