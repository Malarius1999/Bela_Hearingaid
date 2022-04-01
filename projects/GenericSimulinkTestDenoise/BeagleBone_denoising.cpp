//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: BeagleBone_denoising.cpp
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
#include "BeagleBone_denoising_capi.h"
#include "BeagleBone_denoising.h"
#include "BeagleBone_denoising_private.h"

const creal32_T BeagleBone_denoising_R32GND_Complex = { 0.0F, 0.0F };// real32_T complex ground 

void BeagleBone_denoisingModelClass::BeagleBone_denoisi_RandSrc_GZ_R(real32_T y[],
  const real32_T mean[], int32_T meanLen, const real32_T xstd[], int32_T xstdLen,
  uint32_T state[], int32_T nChans, int32_T nSamps)
{
  int32_T chan;
  int32_T icng_tmp;
  int32_T samp;
  real32_T s;
  real32_T std;
  real32_T y_0;
  uint32_T icng;
  uint32_T jsr;
  static const real32_T vt[65] = { 0.340945F, 0.45731461F, 0.539779305F,
    0.606242716F, 0.663169086F, 0.713697493F, 0.759612501F, 0.80203563F,
    0.841722727F, 0.879210174F, 0.914894819F, 0.949079096F, 0.98200053F,
    1.01384926F, 1.04478097F, 1.07492542F, 1.10439169F, 1.13327384F, 1.16165304F,
    1.18960094F, 1.21718144F, 1.24445164F, 1.27146351F, 1.29826498F, 1.32490075F,
    1.35141253F, 1.37783992F, 1.40422106F, 1.43059289F, 1.45699155F, 1.48345268F,
    1.51001215F, 1.53670609F, 1.56357121F, 1.59064543F, 1.61796796F, 1.64558017F,
    1.67352545F, 1.7018503F, 1.73060453F, 1.75984216F, 1.78962231F, 1.82001F,
    1.85107696F, 1.88290441F, 1.91558313F, 1.9492166F, 1.98392391F, 2.0198431F,
    2.05713558F, 2.09599304F, 2.13664508F, 2.17937136F, 2.22451758F, 2.27251863F,
    2.32393384F, 2.37950087F, 2.44022179F, 2.50751162F, 2.58346581F, 2.67139149F,
    2.77699423F, 2.77699423F, 2.77699423F, 2.77699423F };

  // S-Function (sdsprandsrc2): '<Root>/Random Source'
  // RandSrc_GZ_R
  for (chan = 0; chan < nChans; chan++) {
    std = xstd[xstdLen > 1 ? chan : 0];
    icng_tmp = chan << 1;
    icng = state[icng_tmp];
    jsr = state[icng_tmp + 1];
    for (samp = 0; samp < nSamps; samp++) {
      icng = 69069U * icng + 1234567U;
      jsr ^= jsr << 13;
      jsr ^= jsr >> 17;
      jsr ^= jsr << 5;
      BeagleBone_denoising_B.i_k = static_cast<int32_T>(icng + jsr);
      BeagleBone_denoising_B.j = (BeagleBone_denoising_B.i_k & 63) + 1;
      BeagleBone_denoising_B.r = static_cast<real32_T>
        (BeagleBone_denoising_B.i_k) * 4.65661287E-10F *
        vt[BeagleBone_denoising_B.j];
      BeagleBone_denoising_B.x = static_cast<real32_T>(fabs(static_cast<real_T>
        (BeagleBone_denoising_B.r)));
      y_0 = vt[BeagleBone_denoising_B.j - 1];
      if (!(BeagleBone_denoising_B.x <= y_0)) {
        BeagleBone_denoising_B.x = (BeagleBone_denoising_B.x - y_0) /
          (vt[BeagleBone_denoising_B.j] - y_0);
        icng = 69069U * icng + 1234567U;
        jsr ^= jsr << 13;
        jsr ^= jsr >> 17;
        jsr ^= jsr << 5;
        y_0 = static_cast<real32_T>(static_cast<int32_T>(icng + jsr)) *
          2.32830644E-10F + 0.5F;
        s = BeagleBone_denoising_B.x + y_0;
        if (s > 1.30119801F) {
          BeagleBone_denoising_B.r = BeagleBone_denoising_B.r < 0.0F ?
            0.487899214F * BeagleBone_denoising_B.x - 0.487899214F :
            0.487899214F - 0.487899214F * BeagleBone_denoising_B.x;
        } else if (!(s <= 0.96892792F)) {
          BeagleBone_denoising_B.x = 0.487899214F - 0.487899214F *
            BeagleBone_denoising_B.x;
          if (y_0 > 12.6770601F - static_cast<real32_T>(exp(static_cast<real_T>(
                 -0.5F * BeagleBone_denoising_B.x * BeagleBone_denoising_B.x))) *
              12.3758602F) {
            BeagleBone_denoising_B.r = BeagleBone_denoising_B.r < 0.0F ?
              -BeagleBone_denoising_B.x : BeagleBone_denoising_B.x;
          } else if (!(static_cast<real32_T>(exp(static_cast<real_T>(-0.5F *
              vt[BeagleBone_denoising_B.j] * vt[BeagleBone_denoising_B.j]))) +
                       y_0 * 0.0195830297F / vt[BeagleBone_denoising_B.j] <=
                       static_cast<real32_T>(exp(static_cast<real_T>(-0.5F *
              BeagleBone_denoising_B.r * BeagleBone_denoising_B.r))))) {
            do {
              icng = 69069U * icng + 1234567U;
              jsr ^= jsr << 13;
              jsr ^= jsr >> 17;
              jsr ^= jsr << 5;
              BeagleBone_denoising_B.x = static_cast<real32_T>(log
                (static_cast<real_T>(static_cast<real32_T>(static_cast<int32_T>
                (icng + jsr)) * 2.32830644E-10F + 0.5F))) / 2.77699399F;
              icng = 69069U * icng + 1234567U;
              jsr ^= jsr << 13;
              jsr ^= jsr >> 17;
              jsr ^= jsr << 5;
            } while (static_cast<real32_T>(log(static_cast<real_T>
                       (static_cast<real32_T>(static_cast<int32_T>(icng + jsr)) *
                        2.32830644E-10F + 0.5F))) * -2.0F <=
                     BeagleBone_denoising_B.x * BeagleBone_denoising_B.x);

            BeagleBone_denoising_B.r = BeagleBone_denoising_B.r < 0.0F ?
              BeagleBone_denoising_B.x - 2.77699399F : 2.77699399F -
              BeagleBone_denoising_B.x;
          }
        }
      }

      y[chan * nSamps + samp] = mean[meanLen > 1 ? chan : 0] + std *
        BeagleBone_denoising_B.r;
    }

    state[icng_tmp] = icng;
    state[icng_tmp + 1] = jsr;
  }

  // End of S-Function (sdsprandsrc2): '<Root>/Random Source'
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  // InitializeConditions for S-Function (sdsprandsrc2): '<Root>/Random Source'
  // RandSrcInitState_GZ
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  // End of InitializeConditions for S-Function (sdsprandsrc2): '<Root>/Random Source' 
}

// Model step function
void BeagleBone_denoisingModelClass::step()
{
  float32x4_t tmp;
  float32x4_t tmp_0;

  // S-Function (sdsprandsrc2): '<Root>/Random Source'
  BeagleBone_denoisi_RandSrc_GZ_R(&BeagleBone_denoising_B.MatrixScaling_a[0],
    &BeagleBone_denoising_P.RandomSource_MeanVal, 1,
    &BeagleBone_denoising_P.RandomSource_VarianceRTP, 1,
    BeagleBone_denoising_DW.RandomSource_STATE_DWORK, 1, 64);
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i <= 60;
       BeagleBone_denoising_B.i += 4) {
    // Sum: '<Root>/Sum'
    tmp_0 = vld1q_f32
      (&BeagleBone_denoising_B.MatrixScaling_a[BeagleBone_denoising_B.i]);

    // Sum: '<Root>/Sum' incorporates:
    //   Inport: '<Root>/Input'

    vst1q_f32(&BeagleBone_denoising_Y.Output[BeagleBone_denoising_B.i],
              vaddq_f32(vld1q_f32
                        (&BeagleBone_denoising_U.Input[BeagleBone_denoising_B.i]),
                        tmp_0));
  }

  // Buffer: '<S26>/Rebuffer' incorporates:
  //   S-Function (sdspdmult2): '<S26>/Matrix Scaling'

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i < 192 -
         BeagleBone_denoising_DW.Rebuffer_CircBufIdx) {
    BeagleBone_denoising_B.MatrixScaling_a[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff[BeagleBone_denoising_DW.Rebuffer_CircBufIdx
      + BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i < BeagleBone_denoising_DW.Rebuffer_CircBufIdx)
  {
    BeagleBone_denoising_B.MatrixScaling_a[(BeagleBone_denoising_B.i -
      BeagleBone_denoising_DW.Rebuffer_CircBufIdx) + 192] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff[BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  memcpy(&BeagleBone_denoising_B.MatrixScaling_a[192],
         &BeagleBone_denoising_Y.Output[0], sizeof(real32_T) << 6U);
  if (64 > 192 - BeagleBone_denoising_DW.Rebuffer_CircBufIdx) {
    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i < 192 -
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff[BeagleBone_denoising_DW.Rebuffer_CircBufIdx
        + BeagleBone_denoising_B.i] =
        BeagleBone_denoising_Y.Output[BeagleBone_denoising_B.i];
      BeagleBone_denoising_B.i++;
    }

    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i <
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx - 128) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff[BeagleBone_denoising_B.i] =
        BeagleBone_denoising_Y.Output[(BeagleBone_denoising_B.i -
        BeagleBone_denoising_DW.Rebuffer_CircBufIdx) + 192];
      BeagleBone_denoising_B.i++;
    }
  } else {
    for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
         BeagleBone_denoising_B.i++) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff[BeagleBone_denoising_DW.Rebuffer_CircBufIdx
        + BeagleBone_denoising_B.i] =
        BeagleBone_denoising_Y.Output[BeagleBone_denoising_B.i];
    }
  }

  BeagleBone_denoising_DW.Rebuffer_CircBufIdx += 64;
  if (BeagleBone_denoising_DW.Rebuffer_CircBufIdx >= 192) {
    BeagleBone_denoising_DW.Rebuffer_CircBufIdx -= 192;
  }

  // End of Buffer: '<S26>/Rebuffer'

  // S-Function (sdspdmult2): '<S26>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S12>/Window Function'

  BeagleBone_denoising_B.idxS = 0;
  BeagleBone_denoising_B.idxV = 0;
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 256;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.MatrixScaling_a[BeagleBone_denoising_B.idxS] *=
      BeagleBone_denoising_ConstB.WindowFunction[BeagleBone_denoising_B.idxV];
    BeagleBone_denoising_B.idxS++;
    BeagleBone_denoising_B.idxV++;
  }

  // End of S-Function (sdspdmult2): '<S26>/Matrix Scaling'

  // Buffer: '<S27>/Rebuffer' incorporates:
  //   S-Function (sdspdmult2): '<S27>/Matrix Scaling'
  //   SignalConversion generated from: '<S27>/Rebuffer'

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i < 192 -
         BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j) {
    BeagleBone_denoising_B.MatrixScaling[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff_a[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j
      + BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i <
         BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j) {
    BeagleBone_denoising_B.MatrixScaling[(BeagleBone_denoising_B.i -
      BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j) + 192] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff_a[BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  memset(&BeagleBone_denoising_B.MatrixScaling[192], 0, sizeof(real32_T) << 6U);
  if (64 > 192 - BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j) {
    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i < 192 -
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_a[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j
        + BeagleBone_denoising_B.i] = 0.0F;
      BeagleBone_denoising_B.i++;
    }

    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i <
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j - 128) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_a[BeagleBone_denoising_B.i] =
        0.0F;
      BeagleBone_denoising_B.i++;
    }
  } else {
    for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
         BeagleBone_denoising_B.i++) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_a[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j
        + BeagleBone_denoising_B.i] = 0.0F;
    }
  }

  BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j += 64;
  if (BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j >= 192) {
    BeagleBone_denoising_DW.Rebuffer_CircBufIdx_j -= 192;
  }

  // End of Buffer: '<S27>/Rebuffer'

  // S-Function (sdspdmult2): '<S27>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S13>/Window Function'

  BeagleBone_denoising_B.idxS = 0;
  BeagleBone_denoising_B.idxV = 0;
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 256;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.MatrixScaling[BeagleBone_denoising_B.idxS] *=
      BeagleBone_denoising_ConstB.WindowFunction_m[BeagleBone_denoising_B.idxV];
    BeagleBone_denoising_B.idxS++;
    BeagleBone_denoising_B.idxV++;
  }

  // End of S-Function (sdspdmult2): '<S27>/Matrix Scaling'

  // S-Function (sdspfft2): '<S26>/FFT' incorporates:
  //   CrlBlock: '<S29>/FFT'
  //   S-Function (sdspdmult2): '<S26>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_denoising_B.FFT_j[0],
    &BeagleBone_denoising_B.MatrixScaling_a[0], BeagleBone_denoising_DW.cfg);

  // SignalConversion generated from: '<S3>/Mag. Squared' incorporates:
  //   Gain: '<S2>/Gain'
  //
  //  About SignalConversion generated from '<S3>/Mag. Squared':
  //   Operator: magnitude^2

  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.Gain[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_B.FFT_j[BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.Gain[BeagleBone_denoising_B.i + 64] =
      BeagleBone_denoising_B.FFT_j[BeagleBone_denoising_B.i + 192];
  }

  // End of SignalConversion generated from: '<S3>/Mag. Squared'

  // DotProduct: '<S30>/Dot Product' incorporates:
  //   S-Function (sdspwindow2): '<S1>/Window Function'

  BeagleBone_denoising_B.Sum = 0.0F;
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 128;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.Sum +=
      BeagleBone_denoising_ConstB.WindowFunction_o[BeagleBone_denoising_B.i] *
      BeagleBone_denoising_ConstB.WindowFunction_o[BeagleBone_denoising_B.i];
  }

  // Gain: '<S30>/Gain' incorporates:
  //   DotProduct: '<S30>/Dot Product'

  BeagleBone_denoising_B.Sum *= BeagleBone_denoising_P.Gain_Gain;

  // Math: '<S30>/Mag. Squared1'
  //
  //  About '<S30>/Mag. Squared1':
  //   Operator: magnitude^2

  BeagleBone_denoising_B.Sum *= BeagleBone_denoising_B.Sum;
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 128;
       BeagleBone_denoising_B.i++) {
    // Math: '<S3>/Mag. Squared' incorporates:
    //   Gain: '<S2>/Gain'
    //
    //  About '<S3>/Mag. Squared':
    //   Operator: magnitude^2

    BeagleBone_denoising_B.rtb_Gain_m =
      BeagleBone_denoising_B.Gain[BeagleBone_denoising_B.i];

    // Product: '<S3>/Product' incorporates:
    //   Constant: '<S3>/Noise Estimate'
    //   Math: '<S3>/Mag. Squared'
    //
    //  About '<S3>/Mag. Squared':
    //   Operator: magnitude^2

    BeagleBone_denoising_B.rtb_MathFunction1_c =
      (BeagleBone_denoising_B.rtb_Gain_m.re *
       BeagleBone_denoising_B.rtb_Gain_m.re +
       BeagleBone_denoising_B.rtb_Gain_m.im *
       BeagleBone_denoising_B.rtb_Gain_m.im) /
      BeagleBone_denoising_P.NoiseEstimate_Value / BeagleBone_denoising_B.Sum;

    // Math: '<S3>/Math Function2' incorporates:
    //   Constant: '<S3>/Constant2'
    //   RelationalOperator: '<S3>/Relational Operator'
    //   Switch: '<S3>/Switch'
    //
    //  About '<S3>/Math Function2':
    //   Operator: reciprocal

    if (!(BeagleBone_denoising_B.rtb_MathFunction1_c >=
          BeagleBone_denoising_P.Constant2_Value)) {
      BeagleBone_denoising_B.rtb_MathFunction1_c =
        BeagleBone_denoising_P.Constant2_Value;
    }

    // Sqrt: '<S3>/Math Function1' incorporates:
    //   Constant: '<S3>/Constant2'
    //   Math: '<S3>/Math Function2'
    //   Sum: '<S3>/Sum1'
    //
    //  About '<S3>/Math Function1':
    //   Operator: signedSqrt
    //
    //  About '<S3>/Math Function2':
    //   Operator: reciprocal

    BeagleBone_denoising_B.rtb_MathFunction1_c =
      BeagleBone_denoising_P.Constant2_Value - 1.0F /
      BeagleBone_denoising_B.rtb_MathFunction1_c;
    if (BeagleBone_denoising_B.rtb_MathFunction1_c < 0.0F) {
      BeagleBone_denoising_B.u = -static_cast<real32_T>(sqrt(static_cast<real_T>
        (static_cast<real32_T>(fabs(static_cast<real_T>
        (BeagleBone_denoising_B.rtb_MathFunction1_c))))));
    } else {
      BeagleBone_denoising_B.u = static_cast<real32_T>(sqrt(static_cast<real_T>
        (BeagleBone_denoising_B.rtb_MathFunction1_c)));
    }

    // Product: '<S1>/Noise Scaling'
    BeagleBone_denoising_B.rtb_Gain_m.re *= BeagleBone_denoising_B.u;

    // Sqrt: '<S3>/Math Function1'
    //
    //  About '<S3>/Math Function1':
    //   Operator: signedSqrt

    if (BeagleBone_denoising_B.rtb_MathFunction1_c < 0.0F) {
      BeagleBone_denoising_B.u = -static_cast<real32_T>(sqrt(static_cast<real_T>
        (static_cast<real32_T>(fabs(static_cast<real_T>
        (BeagleBone_denoising_B.rtb_MathFunction1_c))))));
    } else {
      BeagleBone_denoising_B.u = static_cast<real32_T>(sqrt(static_cast<real_T>
        (BeagleBone_denoising_B.rtb_MathFunction1_c)));
    }

    // Product: '<S1>/Noise Scaling' incorporates:
    //   Gain: '<S2>/Gain'

    BeagleBone_denoising_B.rtb_Gain_m.im *= BeagleBone_denoising_B.u;
    BeagleBone_denoising_B.Gain[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_B.rtb_Gain_m;
  }

  // S-Function (sdspfft2): '<S27>/FFT' incorporates:
  //   CrlBlock: '<S27>/FFT'
  //   S-Function (sdspdmult2): '<S27>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_denoising_B.FFT[0],
    &BeagleBone_denoising_B.MatrixScaling[0], BeagleBone_denoising_DW.cfg_m);

  // S-Function (sdspfft2): '<S16>/IFFT' incorporates:
  //   CrlBlock: '<S16>/IFFT'
  //   Gain: '<S2>/Gain'
  //   Sum: '<S2>/Add'

  memcpy(&BeagleBone_denoising_B.IFFT_U0[0], &BeagleBone_denoising_B.Gain[0],
         sizeof(creal32_T) << 6U);
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 128;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.IFFT_U0[BeagleBone_denoising_B.i + 64].re =
      (BeagleBone_denoising_B.FFT_j[BeagleBone_denoising_B.i + 64].re +
       BeagleBone_denoising_B.FFT[BeagleBone_denoising_B.i + 64].re) *
      BeagleBone_denoising_P.Gain_Gain_l;
    BeagleBone_denoising_B.IFFT_U0[BeagleBone_denoising_B.i + 64].im =
      (BeagleBone_denoising_B.FFT_j[BeagleBone_denoising_B.i + 64].im +
       BeagleBone_denoising_B.FFT[BeagleBone_denoising_B.i + 64].im) *
      BeagleBone_denoising_P.Gain_Gain_l;
  }

  memcpy(&BeagleBone_denoising_B.IFFT_U0[192], &BeagleBone_denoising_B.Gain[64],
         sizeof(creal32_T) << 6U);
  mw_ne10_fft_c2r_1d_float32_neon(&BeagleBone_denoising_B.IFFT[0],
    &BeagleBone_denoising_B.IFFT_U0[0], BeagleBone_denoising_DW.cfg_c);

  // End of S-Function (sdspfft2): '<S16>/IFFT'
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i <= 188;
       BeagleBone_denoising_B.i += 4) {
    // S-Function (sdspsubmtrx): '<S20>/(N-L)' incorporates:
    //   CrlBlock: '<S16>/IFFT'

    tmp_0 = vld1q_f32(&BeagleBone_denoising_B.IFFT[BeagleBone_denoising_B.i]);
    vst1q_f32(&BeagleBone_denoising_B.NL[BeagleBone_denoising_B.i], tmp_0);

    // Sum: '<S20>/Sum' incorporates:
    //   Delay: '<S20>/Delay1'
    //   S-Function (sdspsubmtrx): '<S20>/(N-L)'

    tmp_0 = vld1q_f32(&BeagleBone_denoising_B.NL[BeagleBone_denoising_B.i]);
    tmp = vld1q_f32(&BeagleBone_denoising_B.NL_c[BeagleBone_denoising_B.i]);
    vst1q_f32
      (&BeagleBone_denoising_B.MatrixConcatenation[BeagleBone_denoising_B.i],
       vaddq_f32(tmp_0, tmp));
  }

  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
       BeagleBone_denoising_B.i++) {
    // S-Function (sdspsubmtrx): '<S20>/(L)' incorporates:
    //   CrlBlock: '<S16>/IFFT'

    BeagleBone_denoising_B.MatrixConcatenation[BeagleBone_denoising_B.i + 192] =
      BeagleBone_denoising_B.IFFT[BeagleBone_denoising_B.i + 192];

    // S-Function (sdspsubmtrx): '<S20>/L' incorporates:
    //   Concatenate: '<S20>/Matrix Concatenation'

    BeagleBone_denoising_B.L[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_B.MatrixConcatenation[BeagleBone_denoising_B.i];
  }

  // S-Function (sdspsubmtrx): '<S20>/N-L' incorporates:
  //   Concatenate: '<S20>/Matrix Concatenation'

  memcpy(&BeagleBone_denoising_B.NL_c[0],
         &BeagleBone_denoising_B.MatrixConcatenation[64], 192U * sizeof(real32_T));

  // Buffer: '<S28>/Rebuffer' incorporates:
  //   S-Function (sdspdmult2): '<S28>/Matrix Scaling'
  //   SignalConversion generated from: '<S28>/Rebuffer'

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i < 192 -
         BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h) {
    BeagleBone_denoising_B.MatrixScaling_d[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff_m[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h
      + BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i <
         BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h) {
    BeagleBone_denoising_B.MatrixScaling_d[(BeagleBone_denoising_B.i -
      BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h) + 192] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff_m[BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  memset(&BeagleBone_denoising_B.MatrixScaling_d[192], 0, sizeof(real32_T) << 6U);
  if (64 > 192 - BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h) {
    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i < 192 -
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_m[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h
        + BeagleBone_denoising_B.i] = 0.0F;
      BeagleBone_denoising_B.i++;
    }

    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i <
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h - 128) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_m[BeagleBone_denoising_B.i] =
        0.0F;
      BeagleBone_denoising_B.i++;
    }
  } else {
    for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
         BeagleBone_denoising_B.i++) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_m[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h
        + BeagleBone_denoising_B.i] = 0.0F;
    }
  }

  BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h += 64;
  if (BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h >= 192) {
    BeagleBone_denoising_DW.Rebuffer_CircBufIdx_h -= 192;
  }

  // End of Buffer: '<S28>/Rebuffer'

  // S-Function (sdspdmult2): '<S28>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S14>/Window Function'

  BeagleBone_denoising_B.idxS = 0;
  BeagleBone_denoising_B.idxV = 0;
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 256;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.MatrixScaling_d[BeagleBone_denoising_B.idxS] *=
      BeagleBone_denoising_ConstB.WindowFunction_e[BeagleBone_denoising_B.idxV];
    BeagleBone_denoising_B.idxS++;
    BeagleBone_denoising_B.idxV++;
  }

  // End of S-Function (sdspdmult2): '<S28>/Matrix Scaling'

  // Buffer: '<S29>/Rebuffer' incorporates:
  //   S-Function (sdspdmult2): '<S29>/Matrix Scaling'
  //   SignalConversion generated from: '<S29>/Rebuffer'

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i < 192 -
         BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a) {
    BeagleBone_denoising_B.MatrixScaling_o[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff_b[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a
      + BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  BeagleBone_denoising_B.i = 0;
  while (BeagleBone_denoising_B.i <
         BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a) {
    BeagleBone_denoising_B.MatrixScaling_o[(BeagleBone_denoising_B.i -
      BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a) + 192] =
      BeagleBone_denoising_DW.Rebuffer_CircBuff_b[BeagleBone_denoising_B.i];
    BeagleBone_denoising_B.i++;
  }

  memset(&BeagleBone_denoising_B.MatrixScaling_o[192], 0, sizeof(real32_T) << 6U);
  if (64 > 192 - BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a) {
    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i < 192 -
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_b[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a
        + BeagleBone_denoising_B.i] = 0.0F;
      BeagleBone_denoising_B.i++;
    }

    BeagleBone_denoising_B.i = 0;
    while (BeagleBone_denoising_B.i <
           BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a - 128) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_b[BeagleBone_denoising_B.i] =
        0.0F;
      BeagleBone_denoising_B.i++;
    }
  } else {
    for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
         BeagleBone_denoising_B.i++) {
      BeagleBone_denoising_DW.Rebuffer_CircBuff_b[BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a
        + BeagleBone_denoising_B.i] = 0.0F;
    }
  }

  BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a += 64;
  if (BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a >= 192) {
    BeagleBone_denoising_DW.Rebuffer_CircBufIdx_a -= 192;
  }

  // End of Buffer: '<S29>/Rebuffer'

  // S-Function (sdspdmult2): '<S29>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S15>/Window Function'

  BeagleBone_denoising_B.idxS = 0;
  BeagleBone_denoising_B.idxV = 0;
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 256;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.MatrixScaling_o[BeagleBone_denoising_B.idxS] *=
      BeagleBone_denoising_ConstB.WindowFunction_mi[BeagleBone_denoising_B.idxV];
    BeagleBone_denoising_B.idxS++;
    BeagleBone_denoising_B.idxV++;
  }

  // End of S-Function (sdspdmult2): '<S29>/Matrix Scaling'

  // S-Function (sdspfft2): '<S29>/FFT' incorporates:
  //   CrlBlock: '<S29>/FFT'
  //   S-Function (sdspdmult2): '<S29>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_denoising_B.FFT_j[0],
    &BeagleBone_denoising_B.MatrixScaling_o[0], BeagleBone_denoising_DW.cfg_k);

  // S-Function (sdspfft2): '<S28>/FFT' incorporates:
  //   Gain: '<S2>/Gain1'
  //   S-Function (sdspdmult2): '<S28>/Matrix Scaling'

  mw_ne10_fft_r2c_1d_float32_neon(&BeagleBone_denoising_B.Gain1[0],
    &BeagleBone_denoising_B.MatrixScaling_d[0], BeagleBone_denoising_DW.cfg_cx);
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 128;
       BeagleBone_denoising_B.i++) {
    // Sum: '<S2>/Add1'
    BeagleBone_denoising_B.Gain1[BeagleBone_denoising_B.i].re =
      BeagleBone_denoising_B.Gain1[BeagleBone_denoising_B.i + 64].re +
      BeagleBone_denoising_B.FFT_j[BeagleBone_denoising_B.i + 64].re;
    BeagleBone_denoising_B.Gain1[BeagleBone_denoising_B.i].im =
      BeagleBone_denoising_B.Gain1[BeagleBone_denoising_B.i + 64].im +
      BeagleBone_denoising_B.FFT_j[BeagleBone_denoising_B.i + 64].im;

    // Gain: '<S2>/Gain1'
    BeagleBone_denoising_B.Gain1[BeagleBone_denoising_B.i].re *=
      BeagleBone_denoising_P.Gain1_Gain;
    BeagleBone_denoising_B.Gain1[BeagleBone_denoising_B.i].im *=
      BeagleBone_denoising_P.Gain1_Gain;
  }

  // S-Function (sdspfft2): '<S21>/IFFT' incorporates:
  //   CrlBlock: '<S21>/IFFT'

  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.IFFT_U0[BeagleBone_denoising_B.i] =
      BeagleBone_denoising_R32GND_Complex;
  }

  memcpy(&BeagleBone_denoising_B.IFFT_U0[64], &BeagleBone_denoising_B.Gain1[0],
         sizeof(creal32_T) << 7U);
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 64;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.IFFT_U0[BeagleBone_denoising_B.i + 192] =
      BeagleBone_denoising_R32GND_Complex;
  }

  mw_ne10_fft_c2r_1d_float32_neon(&BeagleBone_denoising_B.IFFT_c[0],
    &BeagleBone_denoising_B.IFFT_U0[0], BeagleBone_denoising_DW.cfg_b);

  // End of S-Function (sdspfft2): '<S21>/IFFT'

  // S-Function (sdspsubmtrx): '<S25>/(L)' incorporates:
  //   CrlBlock: '<S21>/IFFT'

  memcpy(&BeagleBone_denoising_B.MatrixConcatenation_b[192],
         &BeagleBone_denoising_B.IFFT_c[192], sizeof(real32_T) << 6U);
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i <= 188;
       BeagleBone_denoising_B.i += 4) {
    // S-Function (sdspsubmtrx): '<S25>/(N-L)' incorporates:
    //   CrlBlock: '<S21>/IFFT'

    tmp_0 = vld1q_f32(&BeagleBone_denoising_B.IFFT_c[BeagleBone_denoising_B.i]);
    vst1q_f32(&BeagleBone_denoising_B.NL_cu[BeagleBone_denoising_B.i], tmp_0);

    // Sum: '<S25>/Sum' incorporates:
    //   Delay: '<S25>/Delay1'
    //   S-Function (sdspsubmtrx): '<S25>/(N-L)'

    tmp_0 = vld1q_f32(&BeagleBone_denoising_B.NL_cu[BeagleBone_denoising_B.i]);
    tmp = vld1q_f32(&BeagleBone_denoising_B.NL_m[BeagleBone_denoising_B.i]);
    vst1q_f32
      (&BeagleBone_denoising_B.MatrixConcatenation_b[BeagleBone_denoising_B.i],
       vaddq_f32(tmp_0, tmp));
  }

  // S-Function (sdspsubmtrx): '<S25>/N-L' incorporates:
  //   Concatenate: '<S25>/Matrix Concatenation'

  memcpy(&BeagleBone_denoising_B.NL_m[0],
         &BeagleBone_denoising_B.MatrixConcatenation_b[64], 192U * sizeof
         (real32_T));

  // Sum: '<S19>/Sum' incorporates:
  //   S-Function (sdspwindow2): '<S8>/Window Function1'

  BeagleBone_denoising_B.Sum = -0.0F;
  for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i < 256;
       BeagleBone_denoising_B.i++) {
    BeagleBone_denoising_B.Sum +=
      BeagleBone_denoising_ConstB.WindowFunction1[BeagleBone_denoising_B.i];
  }

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Gain: '<S19>/Gain'
  //   Outport: '<Root>/Output'
  //   Product: '<S19>/Rescale Output1'
  //   S-Function (sdspsubmtrx): '<S20>/L'
  //   Sum: '<Root>/Sum'
  //   Sum: '<S19>/Sum'

  if (BeagleBone_denoising_P.ManualSwitch_CurrentSetting != 1) {
    for (BeagleBone_denoising_B.i = 0; BeagleBone_denoising_B.i <= 60;
         BeagleBone_denoising_B.i += 4) {
      tmp_0 = vld1q_f32(&BeagleBone_denoising_B.L[BeagleBone_denoising_B.i]);
      vst1q_f32(&BeagleBone_denoising_B.fv1[0], vmulq_f32(vdupq_n_f32
                 (BeagleBone_denoising_P.Gain_Gain_l0), tmp_0));
      BeagleBone_denoising_B.fv[0] = BeagleBone_denoising_B.fv1[0] /
        BeagleBone_denoising_B.Sum;
      BeagleBone_denoising_B.fv[1] = BeagleBone_denoising_B.fv1[1] /
        BeagleBone_denoising_B.Sum;
      BeagleBone_denoising_B.fv[2] = BeagleBone_denoising_B.fv1[2] /
        BeagleBone_denoising_B.Sum;
      BeagleBone_denoising_B.fv[3] = BeagleBone_denoising_B.fv1[3] /
        BeagleBone_denoising_B.Sum;
      tmp_0 = vld1q_f32(&BeagleBone_denoising_B.fv[0]);
      vst1q_f32(&BeagleBone_denoising_Y.Output[BeagleBone_denoising_B.i], tmp_0);
    }
  }

  // End of ManualSwitch: '<Root>/Manual Switch'
}

// Model initialize function
void BeagleBone_denoisingModelClass::initialize()
{
  // Registration code

  // Initialize DataMapInfo substructure containing ModelMap for C API
  BeagleBone_denoising_InitializeDataMapInfo((&BeagleBone_denoising_M),
    &BeagleBone_denoising_P);

  {
    int32_T i;
    uint32_T RandomSource_SEED_DWORK;

    // InitializeConditions for S-Function (sdsprandsrc2): '<Root>/Random Source' 
    RandomSource_SEED_DWORK = 81472U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK,
                        &BeagleBone_denoising_DW.RandomSource_STATE_DWORK[0], 1);
    for (i = 0; i < 192; i++) {
      // InitializeConditions for Buffer: '<S26>/Rebuffer'
      BeagleBone_denoising_DW.Rebuffer_CircBuff[i] =
        BeagleBone_denoising_P.Rebuffer_ic;

      // InitializeConditions for Buffer: '<S27>/Rebuffer'
      BeagleBone_denoising_DW.Rebuffer_CircBuff_a[i] =
        BeagleBone_denoising_P.Rebuffer_ic_j;
    }

    // InitializeConditions for S-Function (sdspfft2): '<S26>/FFT'
    mw_ne10_fft_alloc_r2c_float32(&BeagleBone_denoising_DW.cfg, 256);

    // InitializeConditions for S-Function (sdspfft2): '<S27>/FFT'
    mw_ne10_fft_alloc_r2c_float32(&BeagleBone_denoising_DW.cfg_m, 256);

    // InitializeConditions for S-Function (sdspfft2): '<S16>/IFFT'
    mw_ne10_fft_alloc_r2c_float32(&BeagleBone_denoising_DW.cfg_c, 256);
    for (i = 0; i < 192; i++) {
      // InitializeConditions for Delay: '<S20>/Delay1'
      BeagleBone_denoising_B.NL_c[i] =
        BeagleBone_denoising_P.Delay1_InitialCondition;

      // InitializeConditions for Buffer: '<S28>/Rebuffer'
      BeagleBone_denoising_DW.Rebuffer_CircBuff_m[i] =
        BeagleBone_denoising_P.Rebuffer_ic_c;

      // InitializeConditions for Buffer: '<S29>/Rebuffer'
      BeagleBone_denoising_DW.Rebuffer_CircBuff_b[i] =
        BeagleBone_denoising_P.Rebuffer_ic_jy;
    }

    // InitializeConditions for S-Function (sdspfft2): '<S29>/FFT'
    mw_ne10_fft_alloc_r2c_float32(&BeagleBone_denoising_DW.cfg_k, 256);

    // InitializeConditions for S-Function (sdspfft2): '<S28>/FFT'
    mw_ne10_fft_alloc_r2c_float32(&BeagleBone_denoising_DW.cfg_cx, 256);

    // InitializeConditions for S-Function (sdspfft2): '<S21>/IFFT'
    mw_ne10_fft_alloc_r2c_float32(&BeagleBone_denoising_DW.cfg_b, 256);

    // InitializeConditions for Delay: '<S25>/Delay1'
    for (i = 0; i < 192; i++) {
      BeagleBone_denoising_B.NL_m[i] =
        BeagleBone_denoising_P.Delay1_InitialCondition_m;
    }

    // End of InitializeConditions for Delay: '<S25>/Delay1'
  }
}

// Model terminate function
void BeagleBone_denoisingModelClass::terminate()
{
  // Terminate for S-Function (sdspfft2): '<S26>/FFT'
  NE10_FREE(BeagleBone_denoising_DW.cfg);

  // Terminate for S-Function (sdspfft2): '<S27>/FFT'
  NE10_FREE(BeagleBone_denoising_DW.cfg_m);

  // Terminate for S-Function (sdspfft2): '<S16>/IFFT'
  NE10_FREE(BeagleBone_denoising_DW.cfg_c);

  // Terminate for S-Function (sdspfft2): '<S29>/FFT'
  NE10_FREE(BeagleBone_denoising_DW.cfg_k);

  // Terminate for S-Function (sdspfft2): '<S28>/FFT'
  NE10_FREE(BeagleBone_denoising_DW.cfg_cx);

  // Terminate for S-Function (sdspfft2): '<S21>/IFFT'
  NE10_FREE(BeagleBone_denoising_DW.cfg_b);
}

// Constructor
BeagleBone_denoisingModelClass::BeagleBone_denoisingModelClass() :
  BeagleBone_denoising_B(),
  BeagleBone_denoising_DW(),
  BeagleBone_denoising_U(),
  BeagleBone_denoising_Y(),
  BeagleBone_denoising_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
BeagleBone_denoisingModelClass::~BeagleBone_denoisingModelClass()
{
  // Currently there is no destructor body generated.
}

// Block parameters get method
const BeagleBone_denoisingModelClass::P_BeagleBone_denoising_T
  & BeagleBone_denoisingModelClass::getBlockParameters() const
{
  return BeagleBone_denoising_P;
}

// Block parameters set method
void BeagleBone_denoisingModelClass::setBlockParameters(const
  P_BeagleBone_denoising_T *pBeagleBone_denoising_P)
{
  BeagleBone_denoising_P = *pBeagleBone_denoising_P;
}

// Real-Time Model get method
BeagleBone_denoisingModelClass::RT_MODEL_BeagleBone_denoising_T
  * BeagleBone_denoisingModelClass::getRTM()
{
  return (&BeagleBone_denoising_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
