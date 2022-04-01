//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hearingaid_mock_private.h
//
// Code generated for Simulink model 'hearingaid_mock'.
//
// Model version                  : 4.0
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Mar 17 10:57:49 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_hearingaid_mock_private_h_
#define RTW_HEADER_hearingaid_mock_private_h_
#include "rtwtypes.h"

extern void MWDSPCG_FFT_Interleave_R2BR_D(const real_T x[], creal_T y[], int32_T
  nChans, int32_T nRows);
extern void MWDSPCG_R2DIT_TBLS_Z(creal_T y[], int32_T nChans, int32_T nRows,
  int32_T fftLen, int32_T offset, const real_T tablePtr[], int32_T twiddleStep,
  boolean_T isInverse);
extern void MWDSPCG_FFT_DblLen_Z(creal_T y[], int32_T nChans, int32_T nRows,
  const real_T twiddleTable[], int32_T twiddleStep);
extern void MWDSPCG_IFFT_DblLen_D_XC(const creal_T x[], real_T y[], int32_T
  nRows, int32_T nChans, int32_T fftLen, const real_T twiddleTable[], int32_T
  twiddleStep);

#endif                                 // RTW_HEADER_hearingaid_mock_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
