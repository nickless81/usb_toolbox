/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "api_scilab.h"
#if API_SCILAB_VERSION < 3
#include "stack-c.h"
#endif
#if SCI_VERSION_MAJOR < 6
#include "MALLOC.h"
#else
#include "sci_malloc.h"
#endif
#include "Scierror.h"
#include "hidapi.h"
#define MAX_STR 255
hid_device *handle_g;
struct hid_device_info *dev_info, *cur_dev_info;
#if SCI_VERSION_MAJOR < 6
int sci_hid_init(char *fname)
#else
int sci_hid_init(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  CheckLhs(1,1) ;
  Success=hid_init();
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_close(char *fname)
#else
int sci_hid_close(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  CheckLhs(1,1) ;   
  if(!handle_g){
      printf("unable to close device\n");
      Success=-1;
  }else{
      hid_close(handle_g);
      printf("device closed\n");
      Success=0;
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1; 
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_enumerate(char *fname)
#else
int sci_hid_enumerate(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    int *piAddressVendorID = NULL;
    int *piAddressProductID = NULL;
    char  Success = 0;
    CheckLhs(1,1) ;
    dev_info = hid_enumerate( 0x0, 0x0 );
    if (!dev_info) {
      printf("unable to enumerate device\n");
      Success = -1;
    }else{
      printf("device enumerated\n");
      cur_dev_info=dev_info;
      Success = 0;
    }
    createScalarInteger8(pvApiCtx, Rhs + 1, Success);
    LhsVar(1) = Rhs + 1;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_error(char *fname)
#else
int sci_hid_error(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    wchar_t *Error;
    CheckLhs(1,1) ;
    Error = hid_error(handle_g);
    createSingleWideString(pvApiCtx, Rhs + 1, Error);
    LhsVar(1) = Rhs + 1;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_exit(char *fname)
#else
int sci_hid_exit(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  CheckLhs(1,1) ;
  Success=hid_exit();
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_free_enumeration(char *fname)
#else
int sci_hid_free_enumeration(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char Success = 0;
  CheckLhs(1,1) ;
  if(!dev_info)
  {
    Success=-1;
  }
  else
  {
    hid_free_enumeration(dev_info);
    Success=0;
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_get_feature_report(char *fname)
#else
int sci_hid_get_feature_report(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    int iRows = 1;
    unsigned char* dBuff = NULL;
    int *piAddressSize = NULL;
    unsigned char dSize = 0;
    unsigned char i;
    unsigned char Success = 0;
    CheckRhs(1,1) ;
    CheckLhs(2,2) ;
    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressSize);
    if(sciErr.iErr)
    {
      printError(&sciErr, 0);
      return 0;
    }
    if ( !isIntegerType(pvApiCtx, piAddressSize) )
    {
      Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
      return 0;
    }

    if ( getScalarUnsignedInteger8(pvApiCtx, piAddressSize, &dSize) )
    {
      Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected.\n", fname, 2);
      return 0;
    }
    dBuff = (unsigned char*)malloc(1 * iRows * dSize);
    memset(dBuff,0x00,dSize);
    if (!handle_g) {
      printf("unable to read device\n");
      Success = -1;
    }else{
      printf("device have been read\n");
      Success = 0;
      while( Success == 0 ){
          Success = hid_get_feature_report(handle_g, dBuff, dSize);
          if (Success == 0){
              printf("waiting...\n");
          }
          if (Success < 0){
              printf("Unable to get feature report\n");
          }
          if(Success > 0){
              printf("Success=%i\n",Success);
          }
      }
    }
    for(i=0;i<dSize;i++){
      printf("dBuff[%i]=%i\n",i,dBuff[i]);
    }
    createMatrixOfUnsignedInteger8(pvApiCtx, Rhs + 1, iRows, (int)dSize, dBuff);
    createScalarInteger8(pvApiCtx, Rhs + 2, Success);
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_get_indexed_string(char *fname)
#else
int sci_hid_get_indexed_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    int *piAddressIndex = NULL;
    unsigned short Index = 0;
    char  Success = 0;
#if defined (__MINGW32__)
    wchar_t IndexedString[MAX_STR];
#else
    char  IndexedString[MAX_STR];
#endif
    CheckRhs(1,1) ;
    CheckLhs(2,2) ;
    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressIndex);
    if(sciErr.iErr)
    {
      printError(&sciErr, 0);
      return 0;
    }
    if ( !isIntegerType(pvApiCtx, piAddressIndex) )
    {
      Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
      return 0;
    }
    if ( getScalarUnsignedInteger16(pvApiCtx, piAddressIndex, &Index) )
    {
      Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected ????.\n", fname, 1);
      return 0;
    }
    
#if defined (__MINGW32__)
    Success = hid_get_indexed_string(handle_g, Index,IndexedString, MAX_STR);
    createSingleWideString(pvApiCtx, Rhs + 1, &IndexedString[0]);
#else
    //TODO: Debug this line on windows
    //Success = hid_get_indexed_string_ascii(handle_g, Index,IndexedString, MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &IndexedString[0]);
#endif
    createScalarInteger8(pvApiCtx, Rhs + 2, Success);
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_get_manufacturer_string(char *fname)
#else
int sci_hid_get_manufacturer_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    char  Success = 0;
#if defined (__MINGW32__)
    wchar_t Manufacturer[MAX_STR];
#else
    char  Manufacturer[MAX_STR];
#endif
    CheckLhs(2,2) ;
#if defined (__MINGW32__)
    Success = hid_get_manufacturer_string(handle_g, Manufacturer, MAX_STR);
    createSingleWideString(pvApiCtx, Rhs + 1, &Manufacturer[0]);
#else
    //TODO: Debug this line on windows
    //Success = hid_get_manufacturer_string_ascii(handle_g, Manufacturer, MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &Manufacturer[0]);
#endif
    createScalarInteger8(pvApiCtx, Rhs + 2, Success );
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_get_product_string(char *fname)
#else
int sci_hid_get_product_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    char  Success = 0;
#if defined (__MINGW32__)
    wchar_t Product[MAX_STR];
#else
    char  Product[MAX_STR];
#endif
    CheckLhs(2,2) ;
#if defined (__MINGW32__)
    Success = hid_get_product_string(handle_g, Product, MAX_STR);
    createSingleWideString(pvApiCtx, Rhs + 1, &Product[0]);
#else
    //TODO: Debug this line on windows
    //Success = hid_get_product_string_ascii(handle_g, Product, MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &Product[0]);
#endif
    createScalarInteger8(pvApiCtx, Rhs + 2, Success);
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_get_serial_number_string(char *fname)
#else
int sci_hid_get_serial_number_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    char  Success = 0;
#if defined (__MINGW32__)
    wchar_t Serial[MAX_STR];
#else
    char  Serial[MAX_STR];
#endif
    CheckLhs(2,2) ;
#if defined (__MINGW32__)
    Success = hid_get_serial_number_string(handle_g, Serial, MAX_STR);
    createSingleWideString(pvApiCtx, Rhs + 1, &Serial[0]);
#else
    //TODO: Debug this line on windows
    //Success = hid_get_serial_number_string_ascii(handle_g, Serial, MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &Serial[0]);
#endif
    createScalarInteger8(pvApiCtx, Rhs + 2, Success);
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_open(char *fname)
#else
int sci_hid_open(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int *piAddressVendorID = NULL;
  int *piAddressProductID = NULL;
  unsigned short VendorID = 0;
  unsigned short ProductID = 0;
  char  Success = 0;
  CheckRhs(2,2) ;
  CheckLhs(1,1) ;
  sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressVendorID);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddressProductID);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  if ( !isIntegerType(pvApiCtx, piAddressVendorID) )
  {
    Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
    return 0;
  }
  if ( !isIntegerType(pvApiCtx, piAddressProductID) )
  {
    Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 2);
    return 0;
  }
  if ( getScalarUnsignedInteger16(pvApiCtx, piAddressVendorID, &VendorID) )
  {
    Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected ????.\n", fname, 1);
    return 0;
  }
  if ( getScalarUnsignedInteger16(pvApiCtx, piAddressProductID, &ProductID) )
  {
    Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected?????.\n", fname, 2);
    return 0;
  }
  handle_g = hid_open( VendorID, ProductID, NULL );
  if (!handle_g) {
    printf("unable to open device\n");
    Success = -1;
  }else{
    printf("device opened\n");
    Success = 0;
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;   
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_read(char *fname)
#else
int sci_hid_read(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int iRows = 1;
  unsigned char* dBuff = NULL;
  int *piAddressSize = NULL;
  unsigned char dSize = 0;
  unsigned char i;
  unsigned char Success = 0;
  CheckRhs(1,1) ;
  CheckLhs(2,2) ;
  sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressSize);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  if ( !isIntegerType(pvApiCtx, piAddressSize) )
  {
    Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
    return 0;
  }

  if ( getScalarUnsignedInteger8(pvApiCtx, piAddressSize, &dSize) )
  {
    Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected.\n", fname, 2);
    return 0;
  }
  dBuff = (unsigned char*)malloc(1 * iRows * dSize);
  memset(dBuff,0x00,dSize);
  if (!handle_g) {
    printf("unable to read device\n");
    Success = -1;
  }else{
    printf("device have been read\n");
    Success = 0;
    while( Success == 0 ){
        Success = hid_read(handle_g, dBuff, dSize);
        if (Success == 0){
            printf("waiting...\n");
        }
        if (Success < 0){
            printf("Unable to read()\n");
        }
        if(Success > 0){
            printf("Success=%i\n",Success);
        }
    }
  }
  createMatrixOfUnsignedInteger8(pvApiCtx, Rhs + 1, iRows, (int)dSize, dBuff);
  createScalarInteger8(pvApiCtx, Rhs + 2, Success);
  LhsVar(1) = Rhs + 1;
  LhsVar(2) = Rhs + 2;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_read_timeout(char *fname)
#else
int sci_hid_read_timeout(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int iRows = 1;
  unsigned char* dBuff = NULL;
  int *piAddressSize = NULL;
  int *piAddressTimeOut = NULL;
  unsigned char dSize = 0;
  int TimeOut = 0 ;
  unsigned char i;
  unsigned char Success = 0;
  CheckRhs(2,2) ;
  CheckLhs(2,2) ;
  sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressSize);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddressTimeOut);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  if ( !isIntegerType(pvApiCtx, piAddressSize) )
  {
    Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
    return 0;
  }
  if ( !isIntegerType(pvApiCtx, piAddressTimeOut) )
  {
    Scierror(999,"%s: Hola Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
    return 0;
  }
  if ( getScalarUnsignedInteger8(pvApiCtx, piAddressSize, &dSize) )
  {
    Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected.\n", fname, 2);
    return 0;
  }
  if ( getScalarInteger32(pvApiCtx, piAddressTimeOut, &TimeOut) )
  {
    Scierror(999,"%s: Adios Wrong size for input argument #%d: A scalar expected.\n", fname, 2);
    return 0;
  }
  dBuff = (unsigned char*)malloc(1 * iRows * dSize);
  memset(dBuff,0x00,dSize);
  if (!handle_g) {
    printf("unable to read device\n");
    Success = -1;
  }else{
    printf("device have been read\n");
    Success = 0;
    while( Success == 0 ){
        Success = hid_read_timeout(handle_g, dBuff, dSize,TimeOut);
        if (Success == 0 && TimeOut == 0 ){
            printf("waiting...\n");
        }
        if (Success < 0){
            printf("Unable to read()\n");
        }
        if(Success > 0){
            printf("Success=%i\n",Success);
        }
    }
  }
  createMatrixOfUnsignedInteger8(pvApiCtx, Rhs + 1, iRows, (int)dSize, dBuff);
  createScalarInteger8(pvApiCtx, Rhs + 2, Success);
  LhsVar(1) = Rhs + 1;
  LhsVar(2) = Rhs + 2;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_send_feature_report(char *fname)
#else
int sci_hid_send_feature_report(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    int iRows       = 0;
    int iCols       = 0;
    int *piAddressBuff = NULL;
    unsigned char* dBuff = NULL;
    int *piAddressSize = NULL;
    unsigned char dSize = 0;
    int res;
    unsigned char Success = 0;
    CheckRhs(2,2) ;
    CheckLhs(1,1) ;
    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressBuff);
    if(sciErr.iErr)
    {
      printError(&sciErr, 0);
      return 0;
    }
    sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddressSize);
    if(sciErr.iErr)
    {
      printError(&sciErr, 0);
      return 0;
    }
    if ( !isIntegerType(pvApiCtx, piAddressBuff) )
    {
      Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
      return 0;
    }

    if ( !isIntegerType(pvApiCtx, piAddressSize) )
    {
      Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 2);
      return 0;
    }
    sciErr = getMatrixOfUnsignedInteger8(pvApiCtx, piAddressBuff, &iRows, &iCols, &dBuff);
    if(sciErr.iErr)
    {
      printError(&sciErr, 0);
      return 0;
    }
    if ( getScalarUnsignedInteger8(pvApiCtx, piAddressSize, &dSize) )
    {
      Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected.\n", fname, 2);
      return 0;
    }
    for(res=0;res<(int)dSize;res++){
      printf("dBuff[%i]=%i\n",res,dBuff[res]);
    }
    if (!handle_g) {
      printf("unable to send feacture report to device\n");
      printf("Error: %ls\n", hid_error(handle_g));
      Success = -1;
    }else{
      res = hid_send_feature_report(handle_g, dBuff, dSize);
      if (res < 0)
      {
        printf("Unable to send a feature report.\n");
        Success = -1;
      }
      else
      {
        printf("feacture report sent to device\n");
        Success = 0;
      }      
    }
    createScalarInteger8(pvApiCtx, Rhs + 1, Success);
    LhsVar(1) = Rhs + 1;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_set_nonblocking(char *fname)
#else
int sci_hid_set_nonblocking(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int *piAddressnonblock = NULL;
  int nonblock = 0;
  unsigned char Success;
  CheckRhs(1,1) ;
  CheckLhs(1,1) ;   
  sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressnonblock);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  if ( !isBooleanType(pvApiCtx, piAddressnonblock) )
  {
    Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
    return 0;
  }
  if(isScalar(pvApiCtx, piAddressnonblock))
  {
      if (getScalarBoolean(pvApiCtx, piAddressnonblock, &nonblock))
      {
          Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected.nonblock=%i\n", fname, 1);
          return 0;
      }
  }
  Success=hid_set_nonblocking(handle_g,nonblock);
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1; 
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_write(char *fname)
#else
int sci_hid_write(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int iRows       = 0;
  int iCols       = 0;
  int *piAddressBuff = NULL;
  unsigned char* dBuff = NULL;  
  int *piAddressSize = NULL;
  unsigned char dSize = 0;
  unsigned char i;
  unsigned char Success = 0;
  CheckRhs(2,2) ;
  CheckLhs(1,1) ;   
  sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressBuff);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddressSize);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  if ( !isIntegerType(pvApiCtx, piAddressBuff) )
  {
    Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
    return 0;
  }
  
  if ( !isIntegerType(pvApiCtx, piAddressSize) )
  {
    Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 2);
    return 0;
  }
  sciErr = getMatrixOfUnsignedInteger8(pvApiCtx, piAddressBuff, &iRows, &iCols, &dBuff);
  if(sciErr.iErr)
  {
    printError(&sciErr, 0);
    return 0;
  }
  if ( getScalarUnsignedInteger8(pvApiCtx, piAddressSize, &dSize) )
  {
    Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected.\n", fname, 2);
    return 0;
  }
  if (!handle_g) {
    printf("unable to write device\n");
    printf("Error: %ls\n", hid_error(handle_g));
    Success = -1;
  }else{
    printf("device written\n");
    hid_write(handle_g, dBuff, dSize);
    Success = 0;
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1; 
  PutLhsVar();
  
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_next_device(char *fname)
#else
int sci_hid_next_device(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  CheckLhs(1,1) ;
  if( cur_dev_info )
  {
    cur_dev_info=cur_dev_info->next;
    Success++;
  }
  else
  {
      Success = -1;
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_hid_get_device_string(char *fname)
#else
int sci_hid_get_device_string(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  unsigned short vendor_id = 0;
  unsigned short product_id = 0;
  CheckLhs(3,3) ;
  if( cur_dev_info )
  {
      vendor_id = cur_dev_info->vendor_id;
      product_id = cur_dev_info->product_id;
      printf("vendor_id = %i\n",vendor_id);
      printf("product_id = %i\n",product_id);
      Success++;
  }
  else
  {
      Success = -1;
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  createScalarUnsignedInteger16(pvApiCtx, Rhs + 2, vendor_id);
  createScalarUnsignedInteger16(pvApiCtx, Rhs + 3, product_id);
  LhsVar(1) = Rhs + 1;
  LhsVar(2) = Rhs + 2;
  LhsVar(3) = Rhs + 3;
  PutLhsVar();
  return 0;
}

