#ifndef RTW_HEADER_BeagleBone_cap_host_h_
#define RTW_HEADER_BeagleBone_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

struct BeagleBone_host_DataMapInfo_T {
  rtwCAPI_ModelMappingInfo mmi;
};

#ifdef __cplusplus

extern "C" {

#endif

  void BeagleBone_host_InitializeDataMapInfo(BeagleBone_host_DataMapInfo_T
    *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 // HOST_CAPI_BUILD
#endif                                 // RTW_HEADER_BeagleBone_cap_host_h_

// EOF: BeagleBone_capi_host.h
