//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: BeagleBone.cpp
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
#include "BeagleBone_capi.h"
#include "BeagleBone.h"
#include "BeagleBone_private.h"

// Block signals (default storage)
B_BeagleBone_T BeagleBone_B;

// Block states (default storage)
DW_BeagleBone_T BeagleBone_DW;

// External inputs (root inport signals with default storage)
ExtU_BeagleBone_T BeagleBone_U;

// External outputs (root outports fed by signals with default storage)
ExtY_BeagleBone_T BeagleBone_Y;

// Real-time model
RT_MODEL_BeagleBone_T BeagleBone_M_ = RT_MODEL_BeagleBone_T();
RT_MODEL_BeagleBone_T *const BeagleBone_M = &BeagleBone_M_;

// Model step function
void BeagleBone_step(void)
{
  float32x4_t tmp_0;
  float32x4_t tmp_1;
  int32_T idxS;
  int32_T idxV;
  int32_T k;
  real32_T tmp[4];

  // Buffer: '<S24>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input'
  //   S-Function (sdspdmult2): '<S24>/Matrix Scaling'

  for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx; k++) {
    BeagleBone_B.MatrixScaling[k] =
      BeagleBone_DW.Rebuffer_CircBuff[BeagleBone_DW.Rebuffer_CircBufIdx + k];
  }

  for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx; k++) {
    BeagleBone_B.MatrixScaling[(k - BeagleBone_DW.Rebuffer_CircBufIdx) + 192] =
      BeagleBone_DW.Rebuffer_CircBuff[k];
  }

  memcpy(&BeagleBone_B.MatrixScaling[192], &BeagleBone_U.Input[0], sizeof
         (real32_T) << 6U);
  if (64 > 192 - BeagleBone_DW.Rebuffer_CircBufIdx) {
    for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx; k++) {
      BeagleBone_DW.Rebuffer_CircBuff[BeagleBone_DW.Rebuffer_CircBufIdx + k] =
        BeagleBone_U.Input[k];
    }

    for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx - 128; k++) {
      BeagleBone_DW.Rebuffer_CircBuff[k] = BeagleBone_U.Input[(k -
        BeagleBone_DW.Rebuffer_CircBufIdx) + 192];
    }
  } else {
    for (k = 0; k < 64; k++) {
      BeagleBone_DW.Rebuffer_CircBuff[BeagleBone_DW.Rebuffer_CircBufIdx + k] =
        BeagleBone_U.Input[k];
    }
  }

  BeagleBone_DW.Rebuffer_CircBufIdx += 64;
  if (BeagleBone_DW.Rebuffer_CircBufIdx >= 192) {
    BeagleBone_DW.Rebuffer_CircBufIdx -= 192;
  }

  // End of Buffer: '<S24>/Rebuffer'

  // S-Function (sdspdmult2): '<S24>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S10>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 256; k++) {
    BeagleBone_B.MatrixScaling[idxS] *= BeagleBone_ConstB.WindowFunction[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S24>/Matrix Scaling'

  // S-Function (sdspfft2): '<S24>/FFT' incorporates:
  //   CrlBlock: '<S27>/FFT'
  //   S-Function (sdspdmult2): '<S24>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_B.FFT[0],
    &BeagleBone_B.MatrixScaling[0], BeagleBone_DW.cfg);

  // Buffer: '<S25>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input'
  //   S-Function (sdspdmult2): '<S25>/Matrix Scaling'

  for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx_l; k++) {
    BeagleBone_B.MatrixScaling_k[k] =
      BeagleBone_DW.Rebuffer_CircBuff_b[BeagleBone_DW.Rebuffer_CircBufIdx_l + k];
  }

  for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx_l; k++) {
    BeagleBone_B.MatrixScaling_k[(k - BeagleBone_DW.Rebuffer_CircBufIdx_l) + 192]
      = BeagleBone_DW.Rebuffer_CircBuff_b[k];
  }

  memcpy(&BeagleBone_B.MatrixScaling_k[192], &BeagleBone_U.Input[0], sizeof
         (real32_T) << 6U);
  if (64 > 192 - BeagleBone_DW.Rebuffer_CircBufIdx_l) {
    for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx_l; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_b[BeagleBone_DW.Rebuffer_CircBufIdx_l + k]
        = BeagleBone_U.Input[k];
    }

    for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx_l - 128; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_b[k] = BeagleBone_U.Input[(k -
        BeagleBone_DW.Rebuffer_CircBufIdx_l) + 192];
    }
  } else {
    for (k = 0; k < 64; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_b[BeagleBone_DW.Rebuffer_CircBufIdx_l + k]
        = BeagleBone_U.Input[k];
    }
  }

  BeagleBone_DW.Rebuffer_CircBufIdx_l += 64;
  if (BeagleBone_DW.Rebuffer_CircBufIdx_l >= 192) {
    BeagleBone_DW.Rebuffer_CircBufIdx_l -= 192;
  }

  // End of Buffer: '<S25>/Rebuffer'

  // S-Function (sdspdmult2): '<S25>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S11>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 256; k++) {
    BeagleBone_B.MatrixScaling_k[idxS] *=
      BeagleBone_ConstB.WindowFunction_n[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S25>/Matrix Scaling'

  // S-Function (sdspfft2): '<S25>/FFT' incorporates:
  //   Gain: '<S1>/Gain'
  //   S-Function (sdspdmult2): '<S25>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_B.Gain[0],
    &BeagleBone_B.MatrixScaling_k[0], BeagleBone_DW.cfg_m);

  // Sum: '<Root>/Add'
  for (k = 0; k < 64; k++) {
    BeagleBone_B.Add[k].re = BeagleBone_B.FFT[k].re + BeagleBone_B.Gain[k].re;
    BeagleBone_B.Add[k].im = BeagleBone_B.FFT[k].im + BeagleBone_B.Gain[k].im;
    BeagleBone_B.Add[k + 64].re = BeagleBone_B.FFT[k + 192].re +
      BeagleBone_B.Gain[k + 192].re;
    BeagleBone_B.Add[k + 64].im = BeagleBone_B.FFT[k + 192].im +
      BeagleBone_B.Gain[k + 192].im;
  }

  // End of Sum: '<Root>/Add'
  for (k = 0; k < 128; k++) {
    // Sum: '<S1>/Add'
    BeagleBone_B.Gain[k].re = BeagleBone_B.FFT[k + 64].re + BeagleBone_B.Gain[k
      + 64].re;
    BeagleBone_B.Gain[k].im = BeagleBone_B.FFT[k + 64].im + BeagleBone_B.Gain[k
      + 64].im;

    // Gain: '<S1>/Gain'
    BeagleBone_B.Gain[k].re *= 0.5F;
    BeagleBone_B.Gain[k].im *= 0.5F;
  }

  // S-Function (sdspfft2): '<S14>/IFFT' incorporates:
  //   CrlBlock: '<S14>/IFFT'

  memcpy(&BeagleBone_B.IFFT_U0[0], &BeagleBone_B.Add[0], sizeof(creal32_T) << 6U);
  memcpy(&BeagleBone_B.IFFT_U0[64], &BeagleBone_B.Gain[0], sizeof(creal32_T) <<
         7U);
  memcpy(&BeagleBone_B.IFFT_U0[192], &BeagleBone_B.Add[64], sizeof(creal32_T) <<
         6U);
  mw_ne10_fft_c2r_1d_float32_neon(&BeagleBone_B.IFFT[0], &BeagleBone_B.IFFT_U0[0],
    BeagleBone_DW.cfg_c);

  // S-Function (sdspsubmtrx): '<S18>/(N-L)' incorporates:
  //   CrlBlock: '<S14>/IFFT'

  memcpy(&BeagleBone_B.NL[0], &BeagleBone_B.IFFT[0], 192U * sizeof(real32_T));

  // S-Function (sdspsubmtrx): '<S18>/(L)' incorporates:
  //   CrlBlock: '<S14>/IFFT'

  memcpy(&BeagleBone_B.MatrixConcatenation[192], &BeagleBone_B.IFFT[192], sizeof
         (real32_T) << 6U);
  for (k = 0; k <= 188; k += 4) {
    // Sum: '<S18>/Sum' incorporates:
    //   Delay: '<S18>/Delay1'
    //   S-Function (sdspsubmtrx): '<S18>/(N-L)'

    tmp_0 = vld1q_f32(&BeagleBone_B.NL[k]);
    tmp_1 = vld1q_f32(&BeagleBone_B.NL_k[k]);
    vst1q_f32(&BeagleBone_B.MatrixConcatenation[k], vaddq_f32(tmp_0, tmp_1));
  }

  // S-Function (sdspsubmtrx): '<S18>/L' incorporates:
  //   Concatenate: '<S18>/Matrix Concatenation'

  memcpy(&BeagleBone_B.L[0], &BeagleBone_B.MatrixConcatenation[0], sizeof
         (real32_T) << 6U);

  // Buffer: '<S26>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input1'
  //   S-Function (sdspdmult2): '<S26>/Matrix Scaling'

  for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx_m; k++) {
    BeagleBone_B.MatrixScaling_p[k] =
      BeagleBone_DW.Rebuffer_CircBuff_o[BeagleBone_DW.Rebuffer_CircBufIdx_m + k];
  }

  for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx_m; k++) {
    BeagleBone_B.MatrixScaling_p[(k - BeagleBone_DW.Rebuffer_CircBufIdx_m) + 192]
      = BeagleBone_DW.Rebuffer_CircBuff_o[k];
  }

  memcpy(&BeagleBone_B.MatrixScaling_p[192], &BeagleBone_U.Input1[0], sizeof
         (real32_T) << 6U);
  if (64 > 192 - BeagleBone_DW.Rebuffer_CircBufIdx_m) {
    for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx_m; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_o[BeagleBone_DW.Rebuffer_CircBufIdx_m + k]
        = BeagleBone_U.Input1[k];
    }

    for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx_m - 128; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_o[k] = BeagleBone_U.Input1[(k -
        BeagleBone_DW.Rebuffer_CircBufIdx_m) + 192];
    }
  } else {
    for (k = 0; k < 64; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_o[BeagleBone_DW.Rebuffer_CircBufIdx_m + k]
        = BeagleBone_U.Input1[k];
    }
  }

  BeagleBone_DW.Rebuffer_CircBufIdx_m += 64;
  if (BeagleBone_DW.Rebuffer_CircBufIdx_m >= 192) {
    BeagleBone_DW.Rebuffer_CircBufIdx_m -= 192;
  }

  // End of Buffer: '<S26>/Rebuffer'

  // S-Function (sdspdmult2): '<S26>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S12>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 256; k++) {
    BeagleBone_B.MatrixScaling_p[idxS] *=
      BeagleBone_ConstB.WindowFunction_p[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S26>/Matrix Scaling'

  // Buffer: '<S27>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input1'
  //   S-Function (sdspdmult2): '<S27>/Matrix Scaling'

  for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx_p; k++) {
    BeagleBone_B.MatrixScaling_m[k] =
      BeagleBone_DW.Rebuffer_CircBuff_c[BeagleBone_DW.Rebuffer_CircBufIdx_p + k];
  }

  for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx_p; k++) {
    BeagleBone_B.MatrixScaling_m[(k - BeagleBone_DW.Rebuffer_CircBufIdx_p) + 192]
      = BeagleBone_DW.Rebuffer_CircBuff_c[k];
  }

  memcpy(&BeagleBone_B.MatrixScaling_m[192], &BeagleBone_U.Input1[0], sizeof
         (real32_T) << 6U);
  if (64 > 192 - BeagleBone_DW.Rebuffer_CircBufIdx_p) {
    for (k = 0; k < 192 - BeagleBone_DW.Rebuffer_CircBufIdx_p; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_c[BeagleBone_DW.Rebuffer_CircBufIdx_p + k]
        = BeagleBone_U.Input1[k];
    }

    for (k = 0; k < BeagleBone_DW.Rebuffer_CircBufIdx_p - 128; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_c[k] = BeagleBone_U.Input1[(k -
        BeagleBone_DW.Rebuffer_CircBufIdx_p) + 192];
    }
  } else {
    for (k = 0; k < 64; k++) {
      BeagleBone_DW.Rebuffer_CircBuff_c[BeagleBone_DW.Rebuffer_CircBufIdx_p + k]
        = BeagleBone_U.Input1[k];
    }
  }

  BeagleBone_DW.Rebuffer_CircBufIdx_p += 64;
  if (BeagleBone_DW.Rebuffer_CircBufIdx_p >= 192) {
    BeagleBone_DW.Rebuffer_CircBufIdx_p -= 192;
  }

  // End of Buffer: '<S27>/Rebuffer'

  // S-Function (sdspdmult2): '<S27>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S13>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 256; k++) {
    BeagleBone_B.MatrixScaling_m[idxS] *=
      BeagleBone_ConstB.WindowFunction_m[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S27>/Matrix Scaling'

  // S-Function (sdspfft2): '<S27>/FFT' incorporates:
  //   CrlBlock: '<S27>/FFT'
  //   S-Function (sdspdmult2): '<S27>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_B.FFT[0],
    &BeagleBone_B.MatrixScaling_m[0], BeagleBone_DW.cfg_k);

  // S-Function (sdspfft2): '<S26>/FFT' incorporates:
  //   Gain: '<S1>/Gain1'
  //   S-Function (sdspdmult2): '<S26>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_B.Gain1[0],
    &BeagleBone_B.MatrixScaling_p[0], BeagleBone_DW.cfg_cx);

  // Sum: '<Root>/Add1'
  for (k = 0; k < 64; k++) {
    BeagleBone_B.Add[k].re = BeagleBone_B.Gain1[k].re + BeagleBone_B.FFT[k].re;
    BeagleBone_B.Add[k].im = BeagleBone_B.Gain1[k].im + BeagleBone_B.FFT[k].im;
    BeagleBone_B.Add[k + 64].re = BeagleBone_B.Gain1[k + 192].re +
      BeagleBone_B.FFT[k + 192].re;
    BeagleBone_B.Add[k + 64].im = BeagleBone_B.Gain1[k + 192].im +
      BeagleBone_B.FFT[k + 192].im;
  }

  // End of Sum: '<Root>/Add1'
  for (k = 0; k < 128; k++) {
    // Sum: '<S1>/Add1'
    BeagleBone_B.Gain1[k].re = BeagleBone_B.Gain1[k + 64].re +
      BeagleBone_B.FFT[k + 64].re;
    BeagleBone_B.Gain1[k].im = BeagleBone_B.Gain1[k + 64].im +
      BeagleBone_B.FFT[k + 64].im;

    // Gain: '<S1>/Gain1'
    BeagleBone_B.Gain1[k].re *= 0.5F;
    BeagleBone_B.Gain1[k].im *= 0.5F;
  }

  // S-Function (sdspfft2): '<S19>/IFFT' incorporates:
  //   CrlBlock: '<S19>/IFFT'

  memcpy(&BeagleBone_B.IFFT_U0[0], &BeagleBone_B.Add[0], sizeof(creal32_T) << 6U);
  memcpy(&BeagleBone_B.IFFT_U0[64], &BeagleBone_B.Gain1[0], sizeof(creal32_T) <<
         7U);
  memcpy(&BeagleBone_B.IFFT_U0[192], &BeagleBone_B.Add[64], sizeof(creal32_T) <<
         6U);
  mw_ne10_fft_c2r_1d_float32_neon(&BeagleBone_B.IFFT_g[0],
    &BeagleBone_B.IFFT_U0[0], BeagleBone_DW.cfg_b);

  // S-Function (sdspsubmtrx): '<S23>/(N-L)' incorporates:
  //   CrlBlock: '<S19>/IFFT'

  memcpy(&BeagleBone_B.NL_g[0], &BeagleBone_B.IFFT_g[0], 192U * sizeof(real32_T));

  // S-Function (sdspsubmtrx): '<S23>/(L)' incorporates:
  //   CrlBlock: '<S19>/IFFT'

  memcpy(&BeagleBone_B.MatrixConcatenation_m[192], &BeagleBone_B.IFFT_g[192],
         sizeof(real32_T) << 6U);
  for (k = 0; k <= 188; k += 4) {
    // Sum: '<S23>/Sum' incorporates:
    //   Delay: '<S23>/Delay1'
    //   S-Function (sdspsubmtrx): '<S23>/(N-L)'

    tmp_0 = vld1q_f32(&BeagleBone_B.NL_g[k]);
    tmp_1 = vld1q_f32(&BeagleBone_B.NL_c[k]);
    vst1q_f32(&BeagleBone_B.MatrixConcatenation_m[k], vaddq_f32(tmp_0, tmp_1));
  }

  // S-Function (sdspsubmtrx): '<S23>/L' incorporates:
  //   Concatenate: '<S23>/Matrix Concatenation'

  memcpy(&BeagleBone_B.L_i[0], &BeagleBone_B.MatrixConcatenation_m[0], sizeof
         (real32_T) << 6U);

  // S-Function (sdspsubmtrx): '<S18>/N-L' incorporates:
  //   Concatenate: '<S18>/Matrix Concatenation'

  memcpy(&BeagleBone_B.NL_k[0], &BeagleBone_B.MatrixConcatenation[64], 192U *
         sizeof(real32_T));

  // S-Function (sdspsubmtrx): '<S23>/N-L' incorporates:
  //   Concatenate: '<S23>/Matrix Concatenation'

  memcpy(&BeagleBone_B.NL_c[0], &BeagleBone_B.MatrixConcatenation_m[64], 192U *
         sizeof(real32_T));
  for (k = 0; k <= 60; k += 4) {
    // Gain: '<S22>/Gain' incorporates:
    //   Outport: '<Root>/Output1'
    //   S-Function (sdspsubmtrx): '<S23>/L'

    tmp_0 = vld1q_f32(&BeagleBone_B.L_i[k]);
    tmp_1 = vdupq_n_f32(64.0F);
    vst1q_f32(&BeagleBone_B.fv1[0], vmulq_f32(tmp_1, tmp_0));

    // Product: '<S22>/Rescale Output1'
    BeagleBone_B.fv[0] = BeagleBone_B.fv1[0] / BeagleBone_ConstB.Sum_j;
    BeagleBone_B.fv[1] = BeagleBone_B.fv1[1] / BeagleBone_ConstB.Sum_j;
    BeagleBone_B.fv[2] = BeagleBone_B.fv1[2] / BeagleBone_ConstB.Sum_j;
    BeagleBone_B.fv[3] = BeagleBone_B.fv1[3] / BeagleBone_ConstB.Sum_j;
    tmp_0 = vld1q_f32(&BeagleBone_B.fv[0]);

    // Outport: '<Root>/Output1'
    vst1q_f32(&BeagleBone_Y.Output1[k], tmp_0);

    // Gain: '<S17>/Gain' incorporates:
    //   Outport: '<Root>/Output1'
    //   S-Function (sdspsubmtrx): '<S18>/L'

    tmp_0 = vld1q_f32(&BeagleBone_B.L[k]);
    vst1q_f32(&tmp[0], vmulq_f32(tmp_1, tmp_0));

    // Product: '<S17>/Rescale Output1'
    BeagleBone_B.fv2[0] = tmp[0] / BeagleBone_ConstB.Sum;
    BeagleBone_B.fv2[1] = tmp[1] / BeagleBone_ConstB.Sum;
    BeagleBone_B.fv2[2] = tmp[2] / BeagleBone_ConstB.Sum;
    BeagleBone_B.fv2[3] = tmp[3] / BeagleBone_ConstB.Sum;
    tmp_0 = vld1q_f32(&BeagleBone_B.fv2[0]);

    // Outport: '<Root>/Output' incorporates:
    //   Outport: '<Root>/Output1'

    vst1q_f32(&BeagleBone_Y.Output[k], tmp_0);
  }
}

// Model initialize function
void BeagleBone_initialize(void)
{
  // Registration code

  // Initialize DataMapInfo substructure containing ModelMap for C API
  BeagleBone_InitializeDataMapInfo();

  // InitializeConditions for S-Function (sdspfft2): '<S24>/FFT'
  mw_ne10_fft_alloc_r2c_float32(&BeagleBone_DW.cfg, 256);

  // InitializeConditions for S-Function (sdspfft2): '<S25>/FFT'
  mw_ne10_fft_alloc_r2c_float32(&BeagleBone_DW.cfg_m, 256);

  // InitializeConditions for S-Function (sdspfft2): '<S14>/IFFT'
  mw_ne10_fft_alloc_r2c_float32(&BeagleBone_DW.cfg_c, 256);

  // InitializeConditions for S-Function (sdspfft2): '<S27>/FFT'
  mw_ne10_fft_alloc_r2c_float32(&BeagleBone_DW.cfg_k, 256);

  // InitializeConditions for S-Function (sdspfft2): '<S26>/FFT'
  mw_ne10_fft_alloc_r2c_float32(&BeagleBone_DW.cfg_cx, 256);

  // InitializeConditions for S-Function (sdspfft2): '<S19>/IFFT'
  mw_ne10_fft_alloc_r2c_float32(&BeagleBone_DW.cfg_b, 256);
}

// Model terminate function
void BeagleBone_terminate(void)
{
  // Terminate for S-Function (sdspfft2): '<S24>/FFT'
  NE10_FREE(BeagleBone_DW.cfg);

  // Terminate for S-Function (sdspfft2): '<S25>/FFT'
  NE10_FREE(BeagleBone_DW.cfg_m);

  // Terminate for S-Function (sdspfft2): '<S14>/IFFT'
  NE10_FREE(BeagleBone_DW.cfg_c);

  // Terminate for S-Function (sdspfft2): '<S27>/FFT'
  NE10_FREE(BeagleBone_DW.cfg_k);

  // Terminate for S-Function (sdspfft2): '<S26>/FFT'
  NE10_FREE(BeagleBone_DW.cfg_cx);

  // Terminate for S-Function (sdspfft2): '<S19>/IFFT'
  NE10_FREE(BeagleBone_DW.cfg_b);
}

//
// File trailer for generated code.
//
// [EOF]
//
