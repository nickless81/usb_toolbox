// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
OS=getos()
  select OS
  case "Windows" then
      cd D:\usb-toolbox\
  case "Linux" then
      cd /home/jose/usb-toolbox/
  end
clc;
clear;
exec cleaner.sce;
ulink;
exec builder.sce;
clear;
exec loader.sce;
//help