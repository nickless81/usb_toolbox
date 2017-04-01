// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                           
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
etc_tlbx  = get_absolute_file_path("main_clear.sce");
etc_tlbx  = getshortpathname(etc_tlbx);
cd (etc_tlbx);
disp(etc_tlbx);
clc;
clear;
exec cleaner.sce;
ulink;
exec builder.sce;
clear;
exec loader.sce;
//help
