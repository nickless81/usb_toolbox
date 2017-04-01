#ifndef __LIBUSB_TOOLBOX_C_GW_HXX__
#define __LIBUSB_TOOLBOX_C_GW_HXX__

#ifdef _MSC_VER
#ifdef LIBUSB_TOOLBOX_C_GW_EXPORTS
#define LIBUSB_TOOLBOX_C_GW_IMPEXP __declspec(dllexport)
#else
#define LIBUSB_TOOLBOX_C_GW_IMPEXP __declspec(dllimport)
#endif
#else
#define LIBUSB_TOOLBOX_C_GW_IMPEXP
#endif

extern "C" LIBUSB_TOOLBOX_C_GW_IMPEXP int libusb_toolbox_c(wchar_t* _pwstFuncName);



#endif /* __LIBUSB_TOOLBOX_C_GW_HXX__ */
