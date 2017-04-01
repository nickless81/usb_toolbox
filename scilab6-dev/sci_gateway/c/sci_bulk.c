/* ====================================================================  */
/* JOSE PABLO CASTRO VALVERDE                                            */
/* Copyright (C) EDDAP 2012                                              */
/* josepablo.castro@gmail.com                                            */
/* This file is released under the 3-clause BSD license. See COPYING-BSD.*/
/* ====================================================================  */
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
#include <bulk.h>
#if SCI_VERSION_MAJOR < 6
int InEp  = NULL;
int OutEp = NULL;
#else
int InEp  = 0;
int OutEp = 0;
#endif

#define MAX_STR 255
libusb_device_handle *handle_g;
int dev_pos;
#if SCI_VERSION_MAJOR < 6
int sci_bulk_init(char *fname)
#else
int sci_bulk_init(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  CheckLhs(1,1) ;
  Success=(unsigned char)bulk_init();
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_close(char *fname)
#else
int sci_bulk_close(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  CheckLhs(1,1) ;
  if(!handle_g){
      printf("unable to close device\n");
      Success=-1;
  }else{
      bulk_close(handle_g);
      printf("device closed\n");
      Success=0;
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1; 
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_enumerate(char *fname)
#else
int sci_bulk_enumerate(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    int *piAddressVendorID = NULL;
    int *piAddressProductID = NULL;
    char  Success = 0;
    CheckLhs(1,1) ;
    Success = bulk_enumerate();
    dev_pos=0;
    createScalarInteger8(pvApiCtx, Rhs + 1, Success);
    LhsVar(1) = Rhs + 1;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_exit(char *fname)
#else
int sci_bulk_exit(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char  Success = 0;
  CheckLhs(1,1) ;
  Success=bulk_exit(); //needs to be called to end the
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_free_enumeration(char *fname)
#else
int sci_bulk_free_enumeration(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  unsigned char Success = 0;
  CheckLhs(1,1) ;
  Success=bulk_free_enumeration();
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_get_device_string(char *fname)
#else
int sci_bulk_get_device_string(char *fname, void *pvApiCtx)
#endif

{
  SciErr sciErr;
  char  Success = 0;
  unsigned short vendor_id = 0;
  unsigned short product_id = 0;
  CheckLhs(3,3) ;
  Success = bulk_get_device_string(&vendor_id,&product_id);
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  createScalarUnsignedInteger16(pvApiCtx, Rhs + 2, vendor_id);
  createScalarUnsignedInteger16(pvApiCtx, Rhs + 3, product_id);
  LhsVar(1) = Rhs + 1;
  LhsVar(2) = Rhs + 2;
  LhsVar(3) = Rhs + 3;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_get_indexed_string(char *fname)
#else
int sci_bulk_get_indexed_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    int *piAddressIndex = NULL;
    unsigned short Index = 0;
    char  Success = 0;
    char IndexedString[MAX_STR];
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
    Success = (char)bulk_get_indexed_string(handle_g,Index,IndexedString,MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &IndexedString[0]);
    createScalarInteger8(pvApiCtx, Rhs + 2, Success);
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_get_manufacturer_string(char *fname)
#else
int sci_bulk_get_manufacturer_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    char  Success = 0;
    char Manufacturer[MAX_STR];
    CheckLhs(2,2) ;
    Success = (char)bulk_get_manufacturer_string(handle_g,Manufacturer,MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &Manufacturer[0] );
    createScalarInteger8(pvApiCtx, Rhs + 2, Success );
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_get_product_string(char *fname)
#else
int sci_bulk_get_product_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    char  Success = 0;
    char Product[MAX_STR];
    CheckLhs(2,2) ;
    Success = (char)bulk_get_product_string(handle_g,Product,MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &Product[0]);
    createScalarInteger8(pvApiCtx, Rhs + 2, Success);
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_get_serial_number_string(char *fname)
#else
int sci_bulk_get_serial_number_string(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    char  Success = 0;
    char Serial[MAX_STR];
    CheckLhs(2,2) ;
    Success = (char)bulk_get_serial_number_string(handle_g,Serial,MAX_STR);
    createSingleString(pvApiCtx, Rhs + 1, &Serial[0]);
    createScalarInteger8(pvApiCtx, Rhs + 2, Success);
    LhsVar(1) = Rhs + 1;
    LhsVar(2) = Rhs + 2;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_next_device(char *fname)
#else
int sci_bulk_next_device(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  char  Success = 0;
  CheckLhs(1,1) ;
  dev_pos+=1;
  Success = bulk_next_device(dev_pos);
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_open(char *fname)
#else
int sci_bulk_open(char *fname, void *pvApiCtx)
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
  printf("sci_bulk_open\n");
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
  handle_g = bulk_open(VendorID, ProductID);
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
int sci_bulk_read(char *fname)
#else
int sci_bulk_read(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int iRows = 1;
  unsigned char* dBuff = NULL;
  int *piAddressSize = NULL;
  unsigned char dSize = 0;
  int actual;
  char Success = 0;
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
      if(OutEp){
          bulk_read(
                handle_g,
                InEp,
                dBuff,
                dSize,
                &actual
                );
          if (actual == dSize){
              Success = 1;
              printf("Success=%i\n",Success);
          }
      }else{
          Success = -2;
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
int sci_bulk_read_timeout(char *fname)
#else
int sci_bulk_read_timeout(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int iRows = 1;
  unsigned char* dBuff = NULL;
  int *piAddressSize = NULL;
  int *piAddressTimeOut = NULL;
  unsigned char dSize = 0;
  int TimeOut = 0 ;
  int actual;
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
      if(OutEp){
          bulk_read_timeout(
                handle_g,
                InEp ,
                dBuff,
                dSize,
                &actual,
                TimeOut
                );
          if (actual == dSize){
              Success = 1;
              printf("Success=%i\n",Success);
          }
      }else{
          Success = -2;
      }
  }
  createMatrixOfUnsignedInteger8(pvApiCtx, Rhs + 1, iRows, (int)dSize, dBuff);
  createScalarInteger8(pvApiCtx, Rhs + 2, Success);
  LhsVar(1) = Rhs + 1;
  LhsVar(2) = Rhs + 2;
  PutLhsVar();
  return 0;
}
/*
int sci_bulk_set_nonblocking(char *fname)
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
*/
/*
int setblocking(libusb_device_handle *dev_handle,int interface_number, bool set){
    int r;
    cout<<"setblocking()"<<endl;
    if(set){
        r = libusb_claim_interface(dev_handle, interface_number); //claim interface 0 (the first) of device (mine had just 1)
        if(r < 0) {
            cout<<"Cannot Claim Interface"<<endl;
            return 1;
        }
        cout<<"Claimed Interface"<<endl;
    }else{
        r = libusb_release_interface(dev_handle, 0); //release the claimed interface
        if(r!=0) {
            cout<<"Cannot Release Interface"<<endl;
            return 1;
        }
        cout<<"Released Interface"<<endl;
    }
    return r;
}
*/
#if SCI_VERSION_MAJOR < 6
int sci_bulk_set_endpoint(char *fname)
#else
int sci_bulk_set_endpoint(char *fname, void *pvApiCtx)
#endif
{
    SciErr sciErr;
    int *piAddressIn_Ep = NULL;
    int *piAddressOut_Ep = NULL;
    int In_Ep = 0;
    int Out_Ep = 0;
    char  Success = 0;
    CheckRhs(2,2) ;
    CheckLhs(1,1) ;
    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressIn_Ep);
    if(sciErr.iErr)
    {
      printError(&sciErr, 0);
      return 0;
    }
    sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddressOut_Ep);
    if(sciErr.iErr)
    {
      printError(&sciErr, 0);
      return 0;
    }
    if ( !isIntegerType(pvApiCtx, piAddressIn_Ep) )
    {
      Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
      return 0;
    }
    if ( !isIntegerType(pvApiCtx, piAddressOut_Ep) )
    {
      Scierror(999,"%s: Wrong type for input argument #%d: A scalar expected.\n", fname, 2);
      return 0;
    }
    if ( getScalarInteger32(pvApiCtx, piAddressIn_Ep, &In_Ep) )
    {
      Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected ????.\n", fname, 1);
      return 0;
    }
    if ( getScalarInteger32(pvApiCtx, piAddressOut_Ep, &Out_Ep) )
    {
      Scierror(999,"%s: Wrong size for input argument #%d: A scalar expected?????.\n", fname, 2);
      return 0;
    }
    InEp = In_Ep | LIBUSB_ENDPOINT_IN;
    OutEp = Out_Ep | LIBUSB_ENDPOINT_OUT;
    Success=0;

    createScalarInteger8(pvApiCtx, Rhs + 1, Success );
    LhsVar(1) = Rhs + 1;
    PutLhsVar();
    return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_write(char *fname)
#else
int sci_bulk_write(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int iRows       = 0;
  int iCols       = 0;
  int *piAddressBuff = NULL;
  unsigned char* dBuff = NULL;  
  int *piAddressSize = NULL;
  unsigned char dSize = 0;
  int actual;
  unsigned char Success = 0;
  libusb_device_handle *tesptr;
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
    Success = -1;
  }else{
      if(OutEp){
          Success = bulk_write(
                handle_g,
                OutEp,
                dBuff,
                dSize,
                &actual
                );
          printf("sci_bulk_write\n");
      }else{
          Success = -2;
      }
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1; 
  PutLhsVar();
  
  return 0;
}
#if SCI_VERSION_MAJOR < 6
int sci_bulk_write_timeout(char *fname)
#else
int sci_bulk_write_timeout(char *fname, void *pvApiCtx)
#endif
{
  SciErr sciErr;
  int iRows       = 0;
  int iCols       = 0;
  int *piAddressBuff = NULL;
  unsigned char* dBuff = NULL;
  int *piAddressSize = NULL;
  int *piAddressTimeOut = NULL;
  unsigned char dSize = 0;
  int TimeOut = 0 ;
  int actual;
  unsigned char Success = 0;
  CheckRhs(3,3) ;
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
  sciErr = getVarAddressFromPosition(pvApiCtx, 3, &piAddressTimeOut);
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
  if ( !isIntegerType(pvApiCtx, piAddressTimeOut) )
  {
    Scierror(999,"%s: Hola Wrong type for input argument #%d: A scalar expected.\n", fname, 1);
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
  if ( getScalarInteger32(pvApiCtx, piAddressTimeOut, &TimeOut) )
  {
    Scierror(999,"%s: Adios Wrong size for input argument #%d: A scalar expected.\n", fname, 2);
    return 0;
  }
  if (!handle_g) {
      printf("unable to write device\n");
      Success = -1;
  }else{
      if(OutEp){
          Success = bulk_write_timeout(
                handle_g,
                OutEp,
                dBuff,
                dSize,
                &actual,
                TimeOut
                );
      }else{
          Success = -2;
      }
  }
  createScalarInteger8(pvApiCtx, Rhs + 1, Success);
  LhsVar(1) = Rhs + 1;
  PutLhsVar();
  return 0;
}
