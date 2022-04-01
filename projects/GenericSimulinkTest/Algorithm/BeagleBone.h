//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: BeagleBone.h
//
// Code generated for Simulink model 'BeagleBone'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Mar 22 17:27:11 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_BeagleBone_h_
#define RTW_HEADER_BeagleBone_h_
#include <arm_neon.h>
#include <string.h>
#include "rtw_modelmap.h"
#include "rtwtypes.h"
#include "BeagleBone_types.h"
#include "MW_NE10_fft.h"
#include "NE10.h"
#include "NE10_fft.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_BeagleBone_T {
  creal32_T IFFT_U0[256];
  creal32_T FFT[256];
  creal32_T Gain[256];                 // '<S1>/Gain'
  creal32_T Gain1[256];                // '<S1>/Gain1'
  creal32_T Add[128];                  // '<Root>/Add'
  real32_T IFFT[256];
  real32_T MatrixConcatenation[256];   // '<S18>/Matrix Concatenation'
  real32_T MatrixScaling[256];         // '<S24>/Matrix Scaling'
  real32_T MatrixScaling_k[256];       // '<S25>/Matrix Scaling'
  real32_T MatrixScaling_p[256];       // '<S26>/Matrix Scaling'
  real32_T MatrixScaling_m[256];       // '<S27>/Matrix Scaling'
  real32_T NL[192];                    // '<S18>/(N-L)'
  real32_T L[64];                      // '<S18>/L'
  real32_T IFFT_g[256];
  real32_T NL_g[192];                  // '<S23>/(N-L)'
  real32_T MatrixConcatenation_m[256]; // '<S23>/Matrix Concatenation'
  real32_T L_i[64];                    // '<S23>/L'
  real32_T NL_k[192];                  // '<S18>/N-L'
  real32_T NL_c[192];                  // '<S23>/N-L'
  real32_T fv[4];
  real32_T fv1[4];
  real32_T fv2[4];
};

// Block states (default storage) for system '<Root>'
struct DW_BeagleBone_T {
  real32_T Rebuffer_CircBuff[192];     // '<S24>/Rebuffer'
  real32_T Rebuffer_CircBuff_b[192];   // '<S25>/Rebuffer'
  real32_T Rebuffer_CircBuff_o[192];   // '<S26>/Rebuffer'
  real32_T Rebuffer_CircBuff_c[192];   // '<S27>/Rebuffer'
  ne10_fft_r2c_state_float32_t* cfg;
  ne10_fft_r2c_state_float32_t* cfg_m;
  ne10_fft_r2c_state_float32_t* cfg_c;
  ne10_fft_r2c_state_float32_t* cfg_k;
  ne10_fft_r2c_state_float32_t* cfg_cx;
  ne10_fft_r2c_state_float32_t* cfg_b;
  int32_T Rebuffer_CircBufIdx;         // '<S24>/Rebuffer'
  int32_T Rebuffer_CircBufIdx_l;       // '<S25>/Rebuffer'
  int32_T Rebuffer_CircBufIdx_m;       // '<S26>/Rebuffer'
  int32_T Rebuffer_CircBufIdx_p;       // '<S27>/Rebuffer'
};

// Invariant block signals (default storage)
struct ConstB_BeagleBone_T {
  real32_T WindowFunction1[256];       // '<S6>/Window Function1'
  real32_T Sum;                        // '<S17>/Sum'
  real32_T WindowFunction[256];        // '<S10>/Window Function'
  real32_T WindowFunction_n[256];      // '<S11>/Window Function'
  real32_T WindowFunction1_o[256];     // '<S7>/Window Function1'
  real32_T Sum_j;                      // '<S22>/Sum'
  real32_T WindowFunction_p[256];      // '<S12>/Window Function'
  real32_T WindowFunction_m[256];      // '<S13>/Window Function'
};

// External inputs (root inport signals with default storage)
struct ExtU_BeagleBone_T {
  real32_T Input[64];                  // '<Root>/Input'
  real32_T Input1[64];                 // '<Root>/Input1'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_BeagleBone_T {
  real32_T Output[64];                 // '<Root>/Output'
  real32_T Output1[64];                // '<Root>/Output1'
};

// Real-time Model Data Structure
struct tag_RTM_BeagleBone_T {
  const char_T *errorStatus;

  //
  //  DataMapInfo:
  //  The following substructure contains information regarding
  //  structures generated in the model's C API.

  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_BeagleBone_T BeagleBone_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_BeagleBone_T BeagleBone_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_BeagleBone_T BeagleBone_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_BeagleBone_T BeagleBone_Y;

#ifdef __cplusplus

}
#endif

extern const ConstB_BeagleBone_T BeagleBone_ConstB;// constant block i/o

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void BeagleBone_initialize(void);
  extern void BeagleBone_step(void);
  extern void BeagleBone_terminate(void);

#ifdef __cplusplus

}
#endif

// Function to get C API Model Mapping Static Info
extern const rtwCAPI_ModelMappingStaticInfo*
  BeagleBone_GetCAPIStaticMap(void);

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_BeagleBone_T *const BeagleBone_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S15>/Check Signal Attributes' : Unused code path elimination
//  Block '<S16>/Check Signal Attributes' : Unused code path elimination
//  Block '<S20>/Check Signal Attributes' : Unused code path elimination
//  Block '<S21>/Check Signal Attributes' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BeagleBone'
//  '<S1>'   : 'BeagleBone/BeagleBone'
//  '<S2>'   : 'BeagleBone/BeagleBone/Demux'
//  '<S3>'   : 'BeagleBone/BeagleBone/Demux1'
//  '<S4>'   : 'BeagleBone/BeagleBone/Demux2'
//  '<S5>'   : 'BeagleBone/BeagleBone/Demux3'
//  '<S6>'   : 'BeagleBone/BeagleBone/ISTFT'
//  '<S7>'   : 'BeagleBone/BeagleBone/ISTFT1'
//  '<S8>'   : 'BeagleBone/BeagleBone/Mux'
//  '<S9>'   : 'BeagleBone/BeagleBone/Mux1'
//  '<S10>'  : 'BeagleBone/BeagleBone/STFT1'
//  '<S11>'  : 'BeagleBone/BeagleBone/STFT2'
//  '<S12>'  : 'BeagleBone/BeagleBone/STFT3'
//  '<S13>'  : 'BeagleBone/BeagleBone/STFT4'
//  '<S14>'  : 'BeagleBone/BeagleBone/ISTFT/Inverse  Short-Time FFT'
//  '<S15>'  : 'BeagleBone/BeagleBone/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S16>'  : 'BeagleBone/BeagleBone/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S17>'  : 'BeagleBone/BeagleBone/ISTFT/Inverse  Short-Time FFT/Normalization'
//  '<S18>'  : 'BeagleBone/BeagleBone/ISTFT/Inverse  Short-Time FFT/Overlap-And-Add'
//  '<S19>'  : 'BeagleBone/BeagleBone/ISTFT1/Inverse  Short-Time FFT'
//  '<S20>'  : 'BeagleBone/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S21>'  : 'BeagleBone/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S22>'  : 'BeagleBone/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Normalization'
//  '<S23>'  : 'BeagleBone/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Overlap-And-Add'
//  '<S24>'  : 'BeagleBone/BeagleBone/STFT1/Short-Time FFT'
//  '<S25>'  : 'BeagleBone/BeagleBone/STFT2/Short-Time FFT'
//  '<S26>'  : 'BeagleBone/BeagleBone/STFT3/Short-Time FFT'
//  '<S27>'  : 'BeagleBone/BeagleBone/STFT4/Short-Time FFT'

#endif                                 // RTW_HEADER_BeagleBone_h_

//
// File trailer for generated code.
//
// [EOF]
//
