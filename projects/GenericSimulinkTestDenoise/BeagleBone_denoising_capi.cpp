//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: BeagleBone_denoising_capi.cpp
//
// Code generated for Simulink model 'BeagleBone_denoising'.
//
// Model version                  : 4.5
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Mar 24 11:17:52 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "BeagleBone_denoising_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  // HOST_CAPI_BUILD
#include "builtin_typeid_types.h"
#include "BeagleBone_denoising.h"
#include "BeagleBone_denoising_capi.h"
#include "BeagleBone_denoising_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 // HOST_CAPI_BUILD

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  // addrMapIndex, blockPath,
  //  paramName, dataTypeIndex, dimIndex, fixPtIdx

  { 0, TARGET_STRING("BeagleBone_denoising/Random Source"),
    TARGET_STRING("MeanVal"), 0, 0, 0 },

  { 1, TARGET_STRING("BeagleBone_denoising/Random Source"),
    TARGET_STRING("VarianceRTP"), 0, 0, 0 },

  { 2, TARGET_STRING("BeagleBone_denoising/Manual Switch"),
    TARGET_STRING("CurrentSetting"), 1, 0, 0 },

  { 3, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 4, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 5, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/Gain Estimator/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 6, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/Gain Estimator/Noise Estimate"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 7, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/Gain Estimator/STFT Normalization/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 8, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT/Buffer"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 9, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT1/Short-Time FFT/Rebuffer"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 10, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT2/Short-Time FFT/Rebuffer"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 11, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT3/Short-Time FFT/Rebuffer"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 12, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT4/Short-Time FFT/Rebuffer"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 13, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT/Normalization/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 14, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT/Overlap-And-Add/Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 15, TARGET_STRING("BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Overlap-And-Add/Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

// Tunable variable parameters
static rtwCAPI_ModelParameters rtModelParameters[] = {
  // addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

// Initialize Data Address
static void BeagleBone_denoising_InitializeDataAddr(void* dataAddr[],
  BeagleBone_denoisingModelClass::P_BeagleBone_denoising_T
  *BeagleBone_denoising_P)
{
  dataAddr[0] = (void*) (&BeagleBone_denoising_P->RandomSource_MeanVal);
  dataAddr[1] = (void*) (&BeagleBone_denoising_P->RandomSource_VarianceRTP);
  dataAddr[2] = (void*) (&BeagleBone_denoising_P->ManualSwitch_CurrentSetting);
  dataAddr[3] = (void*) (&BeagleBone_denoising_P->Gain_Gain_l);
  dataAddr[4] = (void*) (&BeagleBone_denoising_P->Gain1_Gain);
  dataAddr[5] = (void*) (&BeagleBone_denoising_P->Constant2_Value);
  dataAddr[6] = (void*) (&BeagleBone_denoising_P->NoiseEstimate_Value);
  dataAddr[7] = (void*) (&BeagleBone_denoising_P->Gain_Gain);
  dataAddr[8] = (void*) (&BeagleBone_denoising_P->Buffer_ic);
  dataAddr[9] = (void*) (&BeagleBone_denoising_P->Rebuffer_ic);
  dataAddr[10] = (void*) (&BeagleBone_denoising_P->Rebuffer_ic_j);
  dataAddr[11] = (void*) (&BeagleBone_denoising_P->Rebuffer_ic_c);
  dataAddr[12] = (void*) (&BeagleBone_denoising_P->Rebuffer_ic_jy);
  dataAddr[13] = (void*) (&BeagleBone_denoising_P->Gain_Gain_l0);
  dataAddr[14] = (void*) (&BeagleBone_denoising_P->Delay1_InitialCondition);
  dataAddr[15] = (void*) (&BeagleBone_denoising_P->Delay1_InitialCondition_m);
}

#endif

// Initialize Data Run-Time Dimension Buffer Address
#ifndef HOST_CAPI_BUILD

static void BeagleBone_denoising_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

// Initialize logging function pointers
static void BeagleBone_denoising_InitializeLoggingFunctions(RTWLoggingFcnPtr
  loggingPtrs[])
{
  loggingPtrs[0] = (NULL);
  loggingPtrs[1] = (NULL);
  loggingPtrs[2] = (NULL);
  loggingPtrs[3] = (NULL);
  loggingPtrs[4] = (NULL);
  loggingPtrs[5] = (NULL);
  loggingPtrs[6] = (NULL);
  loggingPtrs[7] = (NULL);
  loggingPtrs[8] = (NULL);
  loggingPtrs[9] = (NULL);
  loggingPtrs[10] = (NULL);
  loggingPtrs[11] = (NULL);
  loggingPtrs[12] = (NULL);
  loggingPtrs[13] = (NULL);
  loggingPtrs[14] = (NULL);
  loggingPtrs[15] = (NULL);
}

#endif

// Data Type Map - use dataTypeMapIndex to access this structure
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  // cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
  //  isComplex, isPointer, enumStorageType
  { "float", "real32_T", 0, 0, sizeof(real32_T), SS_SINGLE, 0, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

// Structure Element Map - use elemMapIndex to access this structure
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  // elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex
  { (NULL), 0, 0, 0, 0 },
};

// Dimension Map - use dimensionMapIndex to access elements of ths structure
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  // dataOrientation, dimArrayIndex, numDims, vardimsIndex
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

// Dimension Array- use dimArrayIndex to access elements of this array
static uint_T rtDimensionArray[] = {
  1,                                   // 0
  1                                    // 1
};

// Fixed Point Map
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  // fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

// Sample Time Map - use sTimeIndex to access elements of ths structure
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  // samplePeriodPtr, sampleOffsetPtr, tid, samplingMode
  {
    (NULL), (NULL), 0, 0
  }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  // Signals:{signals, numSignals,
  //            rootInputs, numRootInputs,
  //            rootOutputs, numRootOutputs},
  //  Params: {blockParameters, numBlockParameters,
  //           modelParameters, numModelParameters},
  //  States: {states, numStates},
  //  Maps:   {dataTypeMap, dimensionMap, fixPtMap,
  //           elementMap, sampleTimeMap, dimensionArray},
  //  TargetType: targetType

  { (NULL), 0,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 16,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 401044955U,
    3790769495U,
    2667799740U,
    3578178659U },
  (NULL), 0,
  0
};

// Function to get C API Model Mapping Static Info
const rtwCAPI_ModelMappingStaticInfo*
  BeagleBone_denoising_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

// Cache pointers into DataMapInfo substructure of RTModel
#ifndef HOST_CAPI_BUILD

void BeagleBone_denoising_InitializeDataMapInfo(BeagleBone_denoisingModelClass::
  RT_MODEL_BeagleBone_denoising_T *const BeagleBone_denoising_M,
  BeagleBone_denoisingModelClass::P_BeagleBone_denoising_T
  *BeagleBone_denoising_P)
{
  // Set C-API version
  rtwCAPI_SetVersion(BeagleBone_denoising_M->DataMapInfo.mmi, 1);

  // Cache static C-API data into the Real-time Model Data structure
  rtwCAPI_SetStaticMap(BeagleBone_denoising_M->DataMapInfo.mmi, &mmiStatic);

  // Cache static C-API logging data into the Real-time Model Data structure
  rtwCAPI_SetLoggingStaticMap(BeagleBone_denoising_M->DataMapInfo.mmi, (NULL));

  // Cache C-API Data Addresses into the Real-Time Model Data structure
  BeagleBone_denoising_InitializeDataAddr
    (BeagleBone_denoising_M->DataMapInfo.dataAddress, BeagleBone_denoising_P);
  rtwCAPI_SetDataAddressMap(BeagleBone_denoising_M->DataMapInfo.mmi,
    BeagleBone_denoising_M->DataMapInfo.dataAddress);

  // Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure 
  BeagleBone_denoising_InitializeVarDimsAddr
    (BeagleBone_denoising_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(BeagleBone_denoising_M->DataMapInfo.mmi,
    BeagleBone_denoising_M->DataMapInfo.vardimsAddress);

  // Set Instance specific path
  rtwCAPI_SetPath(BeagleBone_denoising_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(BeagleBone_denoising_M->DataMapInfo.mmi, (NULL));

  // Cache C-API logging function pointers into the Real-Time Model Data structure 
  BeagleBone_denoising_InitializeLoggingFunctions
    (BeagleBone_denoising_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(BeagleBone_denoising_M->DataMapInfo.mmi,
    BeagleBone_denoising_M->DataMapInfo.loggingPtrs);

  // Cache the instance C-API logging pointer
  rtwCAPI_SetInstanceLoggingInfo(BeagleBone_denoising_M->DataMapInfo.mmi, (NULL));

  // Set reference to submodels
  rtwCAPI_SetChildMMIArray(BeagleBone_denoising_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(BeagleBone_denoising_M->DataMapInfo.mmi, 0);
}

#else                                  // HOST_CAPI_BUILD
#ifdef __cplusplus

extern "C" {

#endif

  void BeagleBone_denoising_host_InitializeDataMapInfo
    (BeagleBone_denoising_host_DataMapInfo_T *dataMap, const char *path)
  {
    // Set C-API version
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    // Cache static C-API data into the Real-time Model Data structure
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    // host data address map is NULL
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    // host vardims address map is NULL
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    // Set Instance specific path
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    // Set reference to submodels
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 // HOST_CAPI_BUILD

//
// File trailer for generated code.
//
// [EOF]
//
