//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hearingaid_denoising_mock.cpp
//
// Code generated for Simulink model 'hearingaid_denoising_mock'.
//
// Model version                  : 4.1
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Mar 10 10:50:26 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "hearingaid_denoising_mock.h"
#include "hearingaid_denoising_mock_private.h"

void RandSrc_GZ_D(real_T y[], const real_T mean[], int32_T meanLen, const real_T
                  xstd[], int32_T xstdLen, uint32_T state[], int32_T nChans,
                  int32_T nSamps)
{
  real_T r;
  real_T s;
  real_T std;
  real_T x;
  real_T y_0;
  int32_T chan;
  int32_T i;
  int32_T icng_tmp;
  int32_T j;
  int32_T samp;
  uint32_T icng;
  uint32_T jsr;
  static const real_T vt[65] = { 0.340945, 0.4573146, 0.5397793, 0.6062427,
    0.6631691, 0.7136975, 0.7596125, 0.8020356, 0.8417227, 0.8792102, 0.9148948,
    0.9490791, 0.9820005, 1.0138492, 1.044781, 1.0749254, 1.1043917, 1.1332738,
    1.161653, 1.189601, 1.2171815, 1.2444516, 1.2714635, 1.298265, 1.3249008,
    1.3514125, 1.3778399, 1.4042211, 1.4305929, 1.4569915, 1.4834527, 1.5100122,
    1.5367061, 1.5635712, 1.5906454, 1.617968, 1.6455802, 1.6735255, 1.7018503,
    1.7306045, 1.7598422, 1.7896223, 1.8200099, 1.851077, 1.8829044, 1.9155831,
    1.9492166, 1.9839239, 2.0198431, 2.0571356, 2.095993, 2.136645, 2.1793713,
    2.2245175, 2.2725186, 2.3239338, 2.3795008, 2.4402218, 2.5075117, 2.5834658,
    2.6713916, 2.7769942, 2.7769942, 2.7769942, 2.7769942 };

  // S-Function (sdsprandsrc2): '<Root>/Random Source'
  // RandSrc_GZ_D
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
      i = static_cast<int32_T>(icng + jsr);
      j = (i & 63) + 1;
      r = static_cast<real_T>(i) * 4.6566128730773926E-10 * vt[j];
      x = std::abs(r);
      y_0 = vt[j - 1];
      if (!(x <= y_0)) {
        x = (x - y_0) / (vt[j] - y_0);
        icng = 69069U * icng + 1234567U;
        jsr ^= jsr << 13;
        jsr ^= jsr >> 17;
        jsr ^= jsr << 5;
        y_0 = static_cast<real_T>(static_cast<int32_T>(icng + jsr)) *
          2.328306436538696E-10 + 0.5;
        s = x + y_0;
        if (s > 1.301198) {
          r = r < 0.0 ? 0.4878992 * x - 0.4878992 : 0.4878992 - 0.4878992 * x;
        } else if (!(s <= 0.9689279)) {
          x = 0.4878992 - 0.4878992 * x;
          if (y_0 > 12.67706 - std::exp(-0.5 * x * x) * 12.37586) {
            r = r < 0.0 ? -x : x;
          } else if (!(std::exp(-0.5 * vt[j] * vt[j]) + y_0 * 0.01958303 / vt[j]
                       <= std::exp(-0.5 * r * r))) {
            do {
              icng = 69069U * icng + 1234567U;
              jsr ^= jsr << 13;
              jsr ^= jsr >> 17;
              jsr ^= jsr << 5;
              x = std::log(static_cast<real_T>(static_cast<int32_T>(icng + jsr))
                           * 2.328306436538696E-10 + 0.5) / 2.776994;
              icng = 69069U * icng + 1234567U;
              jsr ^= jsr << 13;
              jsr ^= jsr >> 17;
              jsr ^= jsr << 5;
            } while (std::log(static_cast<real_T>(static_cast<int32_T>(icng +
                        jsr)) * 2.328306436538696E-10 + 0.5) * -2.0 <= x * x);

            r = r < 0.0 ? x - 2.776994 : 2.776994 - x;
          }
        }
      }

      y[chan * nSamps + samp] = mean[meanLen > 1 ? chan : 0] + std * r;
    }

    state[icng_tmp] = icng;
    state[icng_tmp + 1] = jsr;
  }

  // End of S-Function (sdsprandsrc2): '<Root>/Random Source'
}

void MWDSPCG_FFT_Interleave_R2BR_D(const real_T x[], creal_T y[], int32_T nChans,
  int32_T nRows)
{
  int32_T bit_fftLen;
  int32_T br_j;
  int32_T j;
  int32_T nChansBy2;
  int32_T uIdx;
  int32_T yIdx;

  // S-Function (sdspfft2): '<S4>/FFT'
  // Bit-reverses the input data simultaneously with the interleaving operation,
  // obviating the need for explicit data reordering later.  This requires an
  // FFT with bit-reversed inputs.

  br_j = 0;
  yIdx = 0;
  uIdx = 0;
  for (nChansBy2 = nChans >> 1; nChansBy2 != 0; nChansBy2--) {
    for (j = nRows; j - 1 > 0; j--) {
      bit_fftLen = yIdx + br_j;
      y[bit_fftLen].re = x[uIdx];
      y[bit_fftLen].im = x[uIdx + nRows];
      uIdx++;

      // Compute next bit-reversed destination index
      bit_fftLen = nRows;
      do {
        bit_fftLen = static_cast<int32_T>(static_cast<uint32_T>(bit_fftLen) >> 1);
        br_j ^= bit_fftLen;
      } while ((br_j & bit_fftLen) == 0);
    }

    bit_fftLen = yIdx + br_j;
    y[bit_fftLen].re = x[uIdx];
    br_j = uIdx + nRows;
    y[bit_fftLen].im = x[br_j];
    uIdx = br_j + 1;
    yIdx += nRows << 1;
    br_j = 0;
  }

  // For an odd number of channels, prepare the last channel
  // for a double-length real signal algorithm.  No actual
  // interleaving is required, just a copy of the last column
  // of real data, but now placed in bit-reversed order.
  // We need to cast the real u pointer to a cDType_T pointer,
  // in order to fake the interleaving, and cut the number
  // of elements in half (half as many complex interleaved
  // elements as compared to real non-interleaved elements).

  if ((nChans & 1U) != 0U) {
    for (j = nRows >> 1; j - 1 > 0; j--) {
      bit_fftLen = yIdx + br_j;
      y[bit_fftLen].re = x[uIdx];
      y[bit_fftLen].im = x[uIdx + 1];
      uIdx += 2;

      // Compute next bit-reversed destination index
      bit_fftLen = nRows >> 1;
      do {
        bit_fftLen = static_cast<int32_T>(static_cast<uint32_T>(bit_fftLen) >> 1);
        br_j ^= bit_fftLen;
      } while ((br_j & bit_fftLen) == 0);
    }

    bit_fftLen = yIdx + br_j;
    y[bit_fftLen].re = x[uIdx];
    y[bit_fftLen].im = x[uIdx + 1];
  }

  // End of S-Function (sdspfft2): '<S4>/FFT'
}

void MWDSPCG_R2DIT_TBLS_Z(creal_T y[], int32_T nChans, int32_T nRows, int32_T
  fftLen, int32_T offset, const real_T tablePtr[], int32_T twiddleStep,
  boolean_T isInverse)
{
  real_T tmp_im;
  real_T tmp_re;
  real_T twidIm;
  real_T twidRe;
  int32_T fwdInvFactor;
  int32_T i1;
  int32_T i2;
  int32_T iCh;
  int32_T idelta;
  int32_T istart;
  int32_T ix;
  int32_T j;
  int32_T k;
  int32_T kratio;
  int32_T nHalf;
  int32_T nQtr;
  int32_T offsetCh;

  // S-Function (sdspfft2): '<S4>/FFT'
  // DSP System Toolbox Decimation in Time FFT
  // Computation performed using table lookup
  // Output type: complex real_T
  nHalf = (fftLen >> 1) * twiddleStep;
  nQtr = nHalf >> 1;
  fwdInvFactor = isInverse ? -1 : 1;

  // For each channel
  offsetCh = offset;
  for (iCh = 0; iCh < nChans; iCh++) {
    // Perform butterflies for the first stage, where no multiply is required.
    for (ix = offsetCh; ix < (fftLen + offsetCh) - 1; ix += 2) {
      tmp_re = y[ix + 1].re;
      tmp_im = y[ix + 1].im;
      y[ix + 1].re = y[ix].re - y[ix + 1].re;
      y[ix + 1].im = y[ix].im - y[ix + 1].im;
      y[ix].re += tmp_re;
      y[ix].im += tmp_im;
    }

    idelta = 2;
    k = fftLen >> 2;
    kratio = k * twiddleStep;
    while (k > 0) {
      i1 = offsetCh;

      // Perform the first butterfly in each remaining stage, where no multiply is required. 
      for (ix = 0; ix < k; ix++) {
        i2 = i1 + idelta;
        tmp_re = y[i2].re;
        tmp_im = y[i2].im;
        y[i2].re = y[i1].re - y[i2].re;
        y[i2].im = y[i1].im - y[i2].im;
        y[i1].re += tmp_re;
        y[i1].im += tmp_im;
        i1 += idelta << 1;
      }

      istart = offsetCh;

      // Perform remaining butterflies
      for (j = kratio; j < nHalf; j += kratio) {
        i1 = istart + 1;
        twidRe = tablePtr[j];
        twidIm = tablePtr[j + nQtr] * static_cast<real_T>(fwdInvFactor);
        for (ix = 0; ix < k; ix++) {
          i2 = i1 + idelta;
          tmp_re = y[i2].re * twidRe - y[i2].im * twidIm;
          tmp_im = y[i2].re * twidIm + y[i2].im * twidRe;
          y[i2].re = y[i1].re - tmp_re;
          y[i2].im = y[i1].im - tmp_im;
          y[i1].re += tmp_re;
          y[i1].im += tmp_im;
          i1 += idelta << 1;
        }

        istart++;
      }

      idelta <<= 1;
      k >>= 1;
      kratio >>= 1;
    }

    // Point to next channel
    offsetCh += nRows;
  }

  // End of S-Function (sdspfft2): '<S4>/FFT'
}

void MWDSPCG_FFT_DblLen_Z(creal_T y[], int32_T nChans, int32_T nRows, const
  real_T twiddleTable[], int32_T twiddleStep)
{
  real_T cTemp_im;
  real_T cTemp_re;
  real_T cTemp_re_tmp;
  real_T tempOut0Im;
  real_T tempOut0Re;
  int32_T N2;
  int32_T N4;
  int32_T W4;
  int32_T ix;
  int32_T temp2Re_tmp;
  int32_T temp2Re_tmp_0;
  int32_T tempOut0Re_tmp;
  int32_T tmp;
  int32_T yIdx;

  // S-Function (sdspfft2): '<S4>/FFT'
  // In-place "double-length" data recovery
  // Table-based mem-optimized twiddle computation

  // Used to recover linear-ordered length-N point complex FFT result
  // from a linear-ordered complex length-N/2 point FFT, performed
  // on N interleaved real values.

  N2 = nRows >> 1;
  N4 = N2 >> 1;
  W4 = N4 * twiddleStep;
  yIdx = (nChans - 1) * nRows;
  if (nRows > 2) {
    tempOut0Re_tmp = N4 + yIdx;
    tempOut0Re = y[tempOut0Re_tmp].re;
    tempOut0Im = y[tempOut0Re_tmp].im;
    tmp = (N2 + N4) + yIdx;
    y[tmp].re = tempOut0Re;
    y[tmp].im = tempOut0Im;
    y[tempOut0Re_tmp].re = tempOut0Re;
    y[tempOut0Re_tmp].im = -tempOut0Im;
  }

  if (nRows > 1) {
    tmp = N2 + yIdx;
    y[tmp].re = y[yIdx].re - y[yIdx].im;
    y[tmp].im = 0.0;
  }

  y[yIdx].re += y[yIdx].im;
  y[yIdx].im = 0.0;
  tempOut0Re_tmp = twiddleStep;
  for (ix = 1; ix < N4; ix++) {
    temp2Re_tmp = ix + yIdx;
    temp2Re_tmp_0 = (N2 - ix) + yIdx;
    tempOut0Re = (y[temp2Re_tmp_0].re + y[temp2Re_tmp].re) / 2.0;
    tempOut0Im = (y[temp2Re_tmp].im - y[temp2Re_tmp_0].im) / 2.0;
    cTemp_re_tmp = y[temp2Re_tmp_0].re;
    cTemp_re = y[temp2Re_tmp].re;
    y[temp2Re_tmp].re = (y[temp2Re_tmp_0].im + y[temp2Re_tmp].im) / 2.0;
    y[temp2Re_tmp].im = (cTemp_re_tmp - cTemp_re) / 2.0;
    cTemp_re_tmp = -twiddleTable[W4 - tempOut0Re_tmp];
    cTemp_re = y[temp2Re_tmp].re * twiddleTable[tempOut0Re_tmp] - cTemp_re_tmp *
      y[temp2Re_tmp].im;
    cTemp_im = y[temp2Re_tmp].im * twiddleTable[tempOut0Re_tmp] + cTemp_re_tmp *
      y[temp2Re_tmp].re;
    y[temp2Re_tmp].re = tempOut0Re + cTemp_re;
    y[temp2Re_tmp].im = tempOut0Im + cTemp_im;
    cTemp_re_tmp = y[temp2Re_tmp].im;
    tmp = (nRows - ix) + yIdx;
    y[tmp].re = y[temp2Re_tmp].re;
    y[tmp].im = -cTemp_re_tmp;
    tmp = (N2 + ix) + yIdx;
    y[tmp].re = tempOut0Re - cTemp_re;
    y[tmp].im = tempOut0Im - cTemp_im;
    cTemp_re_tmp = y[tmp].im;
    y[temp2Re_tmp_0].re = y[tmp].re;
    y[temp2Re_tmp_0].im = -cTemp_re_tmp;
    tempOut0Re_tmp += twiddleStep;
  }

  // End of S-Function (sdspfft2): '<S4>/FFT'
}

void MWDSPCG_IFFT_DblLen_D_XC(const creal_T x[], real_T y[], int32_T nRows,
  int32_T nChans, int32_T fftLen, const real_T twiddleTable[], int32_T
  twiddleStep)
{
  creal_T *output;
  real_T accIm;
  real_T accIm_0;
  real_T accRe;
  real_T accRe_0;
  real_T prod_re;
  real_T prod_re_tmp;
  int32_T accRe_tmp;
  int32_T accRe_tmp_0;
  int32_T i;
  int32_T jbr_b;
  int32_T jbr_f;
  int32_T k;
  int32_T prod_re_tmp_tmp;
  int32_T prod_re_tmp_tmp_0;
  int32_T tmp;
  int32_T tmp_0;
  int32_T uIdx;
  int32_T yIdx;

  // S-Function (sdspfft2): '<S3>/IFFT'
  // In-place "double-length" data recovery
  // Table-based twiddle computation

  // Used to recover linear-ordered length-N point complex FFT result
  // from a linear-ordered complex length-N/2 point FFT, performed
  // on N interleaved real values.

  output = (creal_T *)y;
  uIdx = (nChans - 1) * nRows;
  yIdx = uIdx >> 1;
  tmp_0 = fftLen >> 1;
  tmp = tmp_0 + uIdx;
  output[yIdx].re = x[tmp].re + x[uIdx].re;
  output[yIdx].im = x[uIdx].re - x[tmp].re;
  if (tmp_0 > 1) {
    accRe = x[tmp - 1].re + x[uIdx + 1].re;
    accIm = x[uIdx + 1].im - x[tmp - 1].im;
    accRe_0 = x[uIdx + 1].re - x[tmp - 1].re;
    accIm_0 = x[tmp - 1].im + x[uIdx + 1].im;
    prod_re_tmp_tmp = fftLen >> 2;
    prod_re_tmp_tmp_0 = prod_re_tmp_tmp * twiddleStep;
    prod_re_tmp = twiddleTable[prod_re_tmp_tmp_0 - twiddleStep];
    prod_re = twiddleTable[twiddleStep] * accRe_0 - prod_re_tmp * accIm_0;
    accRe_0 = prod_re_tmp * accRe_0 + twiddleTable[twiddleStep] * accIm_0;
    accRe_tmp = yIdx + (tmp_0 >> 1);
    output[accRe_tmp].re = (0.0 - accRe_0) + accRe;
    output[accRe_tmp].im = accIm + prod_re;
    if (prod_re_tmp_tmp > 1) {
      accRe_tmp = (yIdx + tmp_0) - 1;
      output[accRe_tmp].re = accRe - (0.0 - accRe_0);
      output[accRe_tmp].im = prod_re - accIm;
      accRe_tmp = prod_re_tmp_tmp + uIdx;
      output[yIdx + 1].re = x[accRe_tmp].re * 2.0;
      output[yIdx + 1].im = (0.0 - x[accRe_tmp].im) * 2.0;
    }

    jbr_f = fftLen >> 3;
    jbr_b = prod_re_tmp_tmp - 1;
    k = twiddleStep << 1;
    for (i = 2; i < prod_re_tmp_tmp; i++) {
      accRe_tmp = uIdx + i;
      accRe_tmp_0 = tmp - i;
      accRe = x[accRe_tmp_0].re + x[accRe_tmp].re;
      accIm = x[accRe_tmp].im - x[accRe_tmp_0].im;
      accRe_0 = x[accRe_tmp].re - x[accRe_tmp_0].re;
      accIm_0 = x[accRe_tmp_0].im + x[accRe_tmp].im;
      prod_re_tmp = twiddleTable[prod_re_tmp_tmp_0 - k];
      prod_re = twiddleTable[k] * accRe_0 - prod_re_tmp * accIm_0;
      accRe_0 = prod_re_tmp * accRe_0 + twiddleTable[k] * accIm_0;
      accRe_tmp = yIdx + jbr_f;
      output[accRe_tmp].re = (0.0 - accRe_0) + accRe;
      output[accRe_tmp].im = accIm + prod_re;
      accRe_tmp = yIdx + jbr_b;
      output[accRe_tmp].re = accRe - (0.0 - accRe_0);
      output[accRe_tmp].im = prod_re - accIm;

      // Compute next bit-reversed destination index
      accRe_tmp = tmp_0;
      do {
        accRe_tmp = static_cast<int32_T>(static_cast<uint32_T>(accRe_tmp) >> 1);
        jbr_f ^= accRe_tmp;
      } while ((jbr_f & accRe_tmp) == 0);

      // Compute next bit-reversed destination index
      accRe_tmp = tmp_0;
      do {
        accRe_tmp = static_cast<int32_T>(static_cast<uint32_T>(accRe_tmp) >> 1);
        jbr_b ^= accRe_tmp;
      } while ((jbr_b & accRe_tmp) != 0);

      k += twiddleStep;
    }
  }

  // End of S-Function (sdspfft2): '<S3>/IFFT'
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
void hearingaid_denoising_mockModelClass::step()
{
  creal_T rtb_FFT[128];
  creal_T rtb_FFT_m;
  real_T rtb_MathFunction1[128];
  real_T rtb_RandomSource[32];
  real_T rtb_MathFunction1_f;
  int32_T idxS;
  int32_T idxV;
  int32_T k;

  // S-Function (sdsprandsrc2): '<Root>/Random Source'
  RandSrc_GZ_D(rtb_RandomSource, &hearingaid_denoising_moc_ConstP.pooled1, 1,
               &hearingaid_denoising_moc_ConstP.RandomSource_VarianceRTP, 1,
               hearingaid_denoising_mock_DW.RandomSource_STATE_DWORK, 1, 32);
  for (idxS = 0; idxS < 32; idxS++) {
    // Sum: '<Root>/Sum' incorporates:
    //   Inport: '<Root>/Input'
    //   S-Function (sdsprandsrc2): '<Root>/Random Source'

    rtb_RandomSource[idxS] += hearingaid_denoising_mock_U.Input[idxS];
  }

  // Buffer: '<S4>/Rebuffer' incorporates:
  //   Sqrt: '<S2>/Math Function1'
  //   Sum: '<Root>/Sum'
  //
  //  About '<S2>/Math Function1':
  //   Operator: signedSqrt

  for (idxS = 0; idxS < 96 - hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx;
       idxS++) {
    rtb_MathFunction1[idxS] =
      hearingaid_denoising_mock_DW.Rebuffer_CircBuff[hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx
      + idxS];
  }

  for (idxS = 0; idxS < hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx; idxS++)
  {
    rtb_MathFunction1[(idxS - hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx)
      + 96] = hearingaid_denoising_mock_DW.Rebuffer_CircBuff[idxS];
  }

  std::memcpy(&rtb_MathFunction1[96], &rtb_RandomSource[0], sizeof(real_T) << 5U);
  if (32 > 96 - hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx) {
    for (idxS = 0; idxS < 96 - hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx;
         idxS++) {
      hearingaid_denoising_mock_DW.Rebuffer_CircBuff[hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx
        + idxS] = rtb_RandomSource[idxS];
    }

    for (idxS = 0; idxS < hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx - 64;
         idxS++) {
      hearingaid_denoising_mock_DW.Rebuffer_CircBuff[idxS] = rtb_RandomSource
        [(idxS - hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx) + 96];
    }
  } else {
    for (idxS = 0; idxS < 32; idxS++) {
      hearingaid_denoising_mock_DW.Rebuffer_CircBuff[hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx
        + idxS] = rtb_RandomSource[idxS];
    }
  }

  hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx += 32;
  if (hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx >= 96) {
    hearingaid_denoising_mock_DW.Rebuffer_CircBufIdx -= 96;
  }

  // End of Buffer: '<S4>/Rebuffer'

  // S-Function (sdspdmult2): '<S4>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S1>/Window Function'
  //   Sqrt: '<S2>/Math Function1'
  //
  //  About '<S2>/Math Function1':
  //   Operator: signedSqrt

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 128; k++) {
    rtb_MathFunction1[idxS] *=
      hearingaid_denoising_moc_ConstB.WindowFunction[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S4>/Matrix Scaling'

  // S-Function (sdspfft2): '<S4>/FFT' incorporates:
  //   Sqrt: '<S2>/Math Function1'
  //
  //  About '<S2>/Math Function1':
  //   Operator: signedSqrt

  MWDSPCG_FFT_Interleave_R2BR_D(&rtb_MathFunction1[0U], &rtb_FFT[0U], 1, 128);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 128, 64, 0,
                       &hearingaid_denoising_moc_ConstP.pooled2[0U], 2, false);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 128,
                       &hearingaid_denoising_moc_ConstP.pooled2[0U], 1);
  for (idxS = 0; idxS < 128; idxS++) {
    // Math: '<S2>/Mag. Squared' incorporates:
    //   S-Function (sdspfft2): '<S4>/FFT'
    //
    //  About '<S2>/Mag. Squared':
    //   Operator: magnitude^2

    rtb_FFT_m = rtb_FFT[idxS];

    // Product: '<S2>/Product' incorporates:
    //   Constant: '<S2>/Noise Estimate'
    //   Math: '<S2>/Mag. Squared'
    //
    //  About '<S2>/Mag. Squared':
    //   Operator: magnitude^2

    rtb_MathFunction1_f = (rtb_FFT_m.re * rtb_FFT_m.re + rtb_FFT_m.im *
      rtb_FFT_m.im) / 0.33749999999999997 /
      hearingaid_denoising_moc_ConstB.MagSquared1;

    // Math: '<S2>/Math Function2' incorporates:
    //   Constant: '<S2>/Constant2'
    //   RelationalOperator: '<S2>/Relational Operator'
    //   Switch: '<S2>/Switch'
    //
    //  About '<S2>/Math Function2':
    //   Operator: reciprocal

    if (!(rtb_MathFunction1_f >= 1.0)) {
      rtb_MathFunction1_f = 1.0;
    }

    // Sqrt: '<S2>/Math Function1' incorporates:
    //   Constant: '<S2>/Constant2'
    //   Math: '<S2>/Math Function2'
    //   Sum: '<S2>/Sum1'
    //
    //  About '<S2>/Math Function1':
    //   Operator: signedSqrt
    //
    //  About '<S2>/Math Function2':
    //   Operator: reciprocal

    rtb_MathFunction1_f = std::sqrt(1.0 - 1.0 / rtb_MathFunction1_f);

    // Product: '<S1>/Noise Scaling' incorporates:
    //   S-Function (sdspfft2): '<S4>/FFT'
    //   Sqrt: '<S2>/Math Function1'
    //
    //  About '<S2>/Math Function1':
    //   Operator: signedSqrt

    rtb_FFT_m.re *= rtb_MathFunction1_f;
    rtb_FFT_m.im *= rtb_MathFunction1_f;
    rtb_FFT[idxS] = rtb_FFT_m;
  }

  // S-Function (sdspfft2): '<S3>/IFFT' incorporates:
  //   Product: '<S1>/Noise Scaling'

  MWDSPCG_IFFT_DblLen_D_XC(&rtb_FFT[0U], &hearingaid_denoising_mock_B.IFFT[0U],
    128, 1, 128, &hearingaid_denoising_moc_ConstP.pooled2[0U], 1);
  MWDSPCG_R2DIT_TBLS_Z(&((creal_T *)&hearingaid_denoising_mock_B.IFFT[0U])[0], 1,
                       64, 64, 0, &hearingaid_denoising_moc_ConstP.pooled2[0U],
                       2, true);

  // Scale inverse transformation
  for (idxS = 0; idxS < 128; idxS++) {
    hearingaid_denoising_mock_B.IFFT[idxS] /= 128.0;
  }

  // End of S-Function (sdspfft2): '<S3>/IFFT'

  // S-Function (sdspsubmtrx): '<S9>/(N-L)' incorporates:
  //   S-Function (sdspfft2): '<S3>/IFFT'

  std::memcpy(&hearingaid_denoising_mock_B.NL[0],
              &hearingaid_denoising_mock_B.IFFT[0], 96U * sizeof(real_T));

  // S-Function (sdspsubmtrx): '<S9>/(L)' incorporates:
  //   S-Function (sdspfft2): '<S3>/IFFT'

  std::memcpy(&hearingaid_denoising_mock_B.MatrixConcatenation[96],
              &hearingaid_denoising_mock_B.IFFT[96], sizeof(real_T) << 5U);

  // Sum: '<S9>/Sum' incorporates:
  //   Delay: '<S9>/Delay1'
  //   S-Function (sdspsubmtrx): '<S9>/(N-L)'

  for (idxS = 0; idxS < 96; idxS++) {
    hearingaid_denoising_mock_B.MatrixConcatenation[idxS] =
      hearingaid_denoising_mock_B.NL[idxS] +
      hearingaid_denoising_mock_B.NL_o[idxS];
  }

  // End of Sum: '<S9>/Sum'

  // S-Function (sdspsubmtrx): '<S9>/L' incorporates:
  //   Concatenate: '<S9>/Matrix Concatenation'

  std::memcpy(&hearingaid_denoising_mock_B.L[0],
              &hearingaid_denoising_mock_B.MatrixConcatenation[0], sizeof(real_T)
              << 5U);

  // S-Function (sdspsubmtrx): '<S9>/N-L' incorporates:
  //   Concatenate: '<S9>/Matrix Concatenation'

  std::memcpy(&hearingaid_denoising_mock_B.NL_o[0],
              &hearingaid_denoising_mock_B.MatrixConcatenation[32], 96U * sizeof
              (real_T));

  // Outport: '<Root>/Output' incorporates:
  //   Gain: '<S8>/Gain'
  //   Product: '<S8>/Rescale Output1'
  //   S-Function (sdspsubmtrx): '<S9>/L'

  for (idxS = 0; idxS < 32; idxS++) {
    hearingaid_denoising_mock_Y.Output[idxS] = 32.0 *
      hearingaid_denoising_mock_B.L[idxS] / hearingaid_denoising_moc_ConstB.Sum;
  }

  // End of Outport: '<Root>/Output'
}

// Model initialize function
void hearingaid_denoising_mockModelClass::initialize()
{
  {
    uint32_T RandomSource_SEED_DWORK;

    // InitializeConditions for S-Function (sdsprandsrc2): '<Root>/Random Source' 
    RandomSource_SEED_DWORK = 81472U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK,
                        &hearingaid_denoising_mock_DW.RandomSource_STATE_DWORK[0],
                        1);
  }
}

// Model terminate function
void hearingaid_denoising_mockModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
hearingaid_denoising_mockModelClass::hearingaid_denoising_mockModelClass() :
  hearingaid_denoising_mock_B(),
  hearingaid_denoising_mock_DW(),
  hearingaid_denoising_mock_U(),
  hearingaid_denoising_mock_Y(),
  hearingaid_denoising_mock_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
hearingaid_denoising_mockModelClass::~hearingaid_denoising_mockModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
hearingaid_denoising_mockModelClass::RT_MODEL_hearingaid_denoising_T
  * hearingaid_denoising_mockModelClass::getRTM()
{
  return (&hearingaid_denoising_mock_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
