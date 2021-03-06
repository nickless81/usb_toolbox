// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  

mode(-1);
lines(0);

function main_builder()

  TOOLBOX_NAME  = "usb_toolbox";
  TOOLBOX_TITLE = "USB Comunication Toolbox for Scilab";
  toolbox_dir   = get_absolute_file_path("builder.sce");

// Check Scilab's version
// =============================================================================

  try
    v = getversion("scilab");
  catch
    error(gettext("Scilab 5.3 or more is required."));
  end
  if v(1) < 6 then
    if v(2) < 3 then
        // new API in scilab 5.3
        error(gettext('Scilab 5.3 or more is required.'));
    end
  end

// Check modules_manager module availability
// =============================================================================

if ~isdef('tbx_build_loader') then
  error(msprintf(gettext("%s module not installed."), "modules_manager"));
end

// Action
// =============================================================================

tbx_builder_macros(toolbox_dir);
tbx_builder_gateway(toolbox_dir);
tbx_builder_help(toolbox_dir);

if v(1) < 6 then
    tbx_build_loader(TOOLBOX_NAME, toolbox_dir);
    tbx_build_cleaner(TOOLBOX_NAME, toolbox_dir);
else
    tbx_build_loader(toolbox_dir);
    tbx_build_cleaner(toolbox_dir);
end


endfunction
// =============================================================================
main_builder();
clear main_builder; // remove main_builder on stack
// =============================================================================


