// ====================================================================  
// JOSE PABLO CASTRO VALVERDE                                            
// Copyright (C) EDDAP 2012                                             
// josepablo.castro@gmail.com 
// USB Comunication Toolbox                                          
// This file is released under the 3-clause BSD license. See COPYING-BSD.
// ====================================================================  
clc
n=5
txBuff=init_buff(n)
for i=1:n
    txBuff=setBuffValue(txBuff,i,i)
end
txBuff=setBuffValue(txBuff,1,hex2dec("02"))
hid_init()
success=openusb("04D8","900A","hid")
if ( success < 0 ) then
    disp("Unable to open device")
    return
end
//success2=nonblockingusb(%f)
[man,success3]=get_manufacturerusb()
success3
[pro,success4]=get_productusb()
success4
[ser,success5]=get_serialusb()
success5
[ser2,success6]=get_stringusb(3)
success6
//success7=writeusb(txBuff,n)
//success7=send_feature_reportusb(txBuff,n) 
//[rxBuff,success8]=readusb(n,"hid")
//[rxBuff,success8]=read_timeoutusb(n,100)
//[rxBuff,success8]=hid_read_timeout(uint8(n),int32(100))
//[rxBuff,success9]=get_feature_reportusb(n)
success10=closeusb()
hid_exit()
//disp(rxBuff)
disp(man)
disp(pro)
disp(ser)
disp(ser2)