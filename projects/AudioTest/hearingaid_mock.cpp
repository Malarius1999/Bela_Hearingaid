//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hearingaid_mock.cpp
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
#include "hearingaid_mock.h"
#include "hearingaid_mock_private.h"

void MWDSPCG_FFT_Interleave_R2BR_D(const real_T x[], creal_T y[], int32_T nChans,
  int32_T nRows)
{
  int32_T bit_fftLen;
  int32_T br_j;
  int32_T j;
  int32_T nChansBy2;
  int32_T uIdx;
  int32_T yIdx;

  // S-Function (sdspfft2): '<S11>/FFT'
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

  // End of S-Function (sdspfft2): '<S11>/FFT'
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

  // S-Function (sdspfft2): '<S11>/FFT'
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

  // End of S-Function (sdspfft2): '<S11>/FFT'
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

  // S-Function (sdspfft2): '<S11>/FFT'
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

  // End of S-Function (sdspfft2): '<S11>/FFT'
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

  // S-Function (sdspfft2): '<S6>/IFFT'
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

  // End of S-Function (sdspfft2): '<S6>/IFFT'
}

// Model step function
void hearingaid_mockModelClass::step()
{
  creal_T rtb_Add[128];
  creal_T rtb_FFT[128];
  creal_T rtb_FFT_k;
  real_T rtb_MatrixScaling[128];
  int32_T idxS;
  int32_T idxV;
  int32_T k;

  // Buffer: '<S11>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input'
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'

  for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx; idxS++) {
    rtb_MatrixScaling[idxS] =
      hearingaid_mock_DW.Rebuffer_CircBuff[hearingaid_mock_DW.Rebuffer_CircBufIdx
      + idxS];
  }

  for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx; idxS++) {
    rtb_MatrixScaling[(idxS - hearingaid_mock_DW.Rebuffer_CircBufIdx) + 96] =
      hearingaid_mock_DW.Rebuffer_CircBuff[idxS];
  }

  std::memcpy(&rtb_MatrixScaling[96], &hearingaid_mock_U.Input[0], sizeof(real_T)
              << 5U);
  if (32 > 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx) {
    for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx; idxS++) {
      hearingaid_mock_DW.Rebuffer_CircBuff[hearingaid_mock_DW.Rebuffer_CircBufIdx
        + idxS] = hearingaid_mock_U.Input[idxS];
    }

    for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx - 64; idxS++) {
      hearingaid_mock_DW.Rebuffer_CircBuff[idxS] = hearingaid_mock_U.Input[(idxS
        - hearingaid_mock_DW.Rebuffer_CircBufIdx) + 96];
    }
  } else {
    for (idxS = 0; idxS < 32; idxS++) {
      hearingaid_mock_DW.Rebuffer_CircBuff[hearingaid_mock_DW.Rebuffer_CircBufIdx
        + idxS] = hearingaid_mock_U.Input[idxS];
    }
  }

  hearingaid_mock_DW.Rebuffer_CircBufIdx += 32;
  if (hearingaid_mock_DW.Rebuffer_CircBufIdx >= 96) {
    hearingaid_mock_DW.Rebuffer_CircBufIdx -= 96;
  }

  // End of Buffer: '<S11>/Rebuffer'

  // S-Function (sdspdmult2): '<S11>/Matrix Scaling' incorporates:
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'
  //   S-Function (sdspwindow2): '<S4>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 128; k++) {
    rtb_MatrixScaling[idxS] *= hearingaid_mock_ConstB.WindowFunction[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S11>/Matrix Scaling'

  // S-Function (sdspfft2): '<S11>/FFT' incorporates:
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'
  //   S-Function (sdspfft2): '<S22>/FFT'

  MWDSPCG_FFT_Interleave_R2BR_D(&rtb_MatrixScaling[0U], &rtb_FFT[0U], 1, 128);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 128, 64, 0,
                       &hearingaid_mock_ConstP.pooled3[0U], 2, false);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 128, &hearingaid_mock_ConstP.pooled3[0U],
                       1);

  // Buffer: '<S12>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input'
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'

  for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_c; idxS++) {
    rtb_MatrixScaling[idxS] =
      hearingaid_mock_DW.Rebuffer_CircBuff_f[hearingaid_mock_DW.Rebuffer_CircBufIdx_c
      + idxS];
  }

  for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx_c; idxS++) {
    rtb_MatrixScaling[(idxS - hearingaid_mock_DW.Rebuffer_CircBufIdx_c) + 96] =
      hearingaid_mock_DW.Rebuffer_CircBuff_f[idxS];
  }

  std::memcpy(&rtb_MatrixScaling[96], &hearingaid_mock_U.Input[0], sizeof(real_T)
              << 5U);
  if (32 > 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_c) {
    for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_c; idxS++)
    {
      hearingaid_mock_DW.Rebuffer_CircBuff_f[hearingaid_mock_DW.Rebuffer_CircBufIdx_c
        + idxS] = hearingaid_mock_U.Input[idxS];
    }

    for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx_c - 64; idxS++)
    {
      hearingaid_mock_DW.Rebuffer_CircBuff_f[idxS] = hearingaid_mock_U.Input
        [(idxS - hearingaid_mock_DW.Rebuffer_CircBufIdx_c) + 96];
    }
  } else {
    for (idxS = 0; idxS < 32; idxS++) {
      hearingaid_mock_DW.Rebuffer_CircBuff_f[hearingaid_mock_DW.Rebuffer_CircBufIdx_c
        + idxS] = hearingaid_mock_U.Input[idxS];
    }
  }

  hearingaid_mock_DW.Rebuffer_CircBufIdx_c += 32;
  if (hearingaid_mock_DW.Rebuffer_CircBufIdx_c >= 96) {
    hearingaid_mock_DW.Rebuffer_CircBufIdx_c -= 96;
  }

  // End of Buffer: '<S12>/Rebuffer'

  // S-Function (sdspdmult2): '<S12>/Matrix Scaling' incorporates:
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'
  //   S-Function (sdspwindow2): '<S5>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 128; k++) {
    rtb_MatrixScaling[idxS] *= hearingaid_mock_ConstB.WindowFunction_d[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S12>/Matrix Scaling'

  // S-Function (sdspfft2): '<S12>/FFT' incorporates:
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'
  //   Sum: '<S2>/Add'

  MWDSPCG_FFT_Interleave_R2BR_D(&rtb_MatrixScaling[0U], &rtb_Add[0U], 1, 128);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_Add[0U], 1, 128, 64, 0,
                       &hearingaid_mock_ConstP.pooled3[0U], 2, false);
  MWDSPCG_FFT_DblLen_Z(&rtb_Add[0U], 1, 128, &hearingaid_mock_ConstP.pooled3[0U],
                       1);

  // Sum: '<S1>/Add' incorporates:
  //   S-Function (sdspfft2): '<S22>/FFT'
  //   Sum: '<S2>/Add'

  for (idxS = 0; idxS < 128; idxS++) {
    rtb_FFT_k = rtb_FFT[idxS];
    rtb_FFT_k.re += rtb_Add[idxS].re;
    rtb_FFT_k.im += rtb_Add[idxS].im;
    rtb_FFT[idxS] = rtb_FFT_k;
  }

  // End of Sum: '<S1>/Add'

  // S-Function (sdspfft2): '<S6>/IFFT' incorporates:
  //   S-Function (sdspfft2): '<S22>/FFT'

  MWDSPCG_IFFT_DblLen_D_XC(&rtb_FFT[0U], &hearingaid_mock_B.IFFT[0U], 128, 1,
    128, &hearingaid_mock_ConstP.pooled3[0U], 1);
  MWDSPCG_R2DIT_TBLS_Z(&((creal_T *)&hearingaid_mock_B.IFFT[0U])[0], 1, 64, 64,
                       0, &hearingaid_mock_ConstP.pooled3[0U], 2, true);

  // Scale inverse transformation
  for (idxS = 0; idxS < 128; idxS++) {
    hearingaid_mock_B.IFFT[idxS] /= 128.0;
  }

  // End of S-Function (sdspfft2): '<S6>/IFFT'

  // S-Function (sdspsubmtrx): '<S10>/(N-L)' incorporates:
  //   S-Function (sdspfft2): '<S6>/IFFT'

  std::memcpy(&hearingaid_mock_B.NL[0], &hearingaid_mock_B.IFFT[0], 96U * sizeof
              (real_T));

  // S-Function (sdspsubmtrx): '<S10>/(L)' incorporates:
  //   S-Function (sdspfft2): '<S6>/IFFT'

  std::memcpy(&hearingaid_mock_B.MatrixConcatenation[96],
              &hearingaid_mock_B.IFFT[96], sizeof(real_T) << 5U);

  // Sum: '<S10>/Sum' incorporates:
  //   Delay: '<S10>/Delay1'
  //   S-Function (sdspsubmtrx): '<S10>/(N-L)'

  for (idxS = 0; idxS < 96; idxS++) {
    hearingaid_mock_B.MatrixConcatenation[idxS] = hearingaid_mock_B.NL[idxS] +
      hearingaid_mock_B.NL_m[idxS];
  }

  // End of Sum: '<S10>/Sum'

  // S-Function (sdspsubmtrx): '<S10>/L' incorporates:
  //   Concatenate: '<S10>/Matrix Concatenation'

  std::memcpy(&hearingaid_mock_B.L[0], &hearingaid_mock_B.MatrixConcatenation[0],
              sizeof(real_T) << 5U);

  // S-Function (sdspsubmtrx): '<S10>/N-L' incorporates:
  //   Concatenate: '<S10>/Matrix Concatenation'

  std::memcpy(&hearingaid_mock_B.NL_m[0],
              &hearingaid_mock_B.MatrixConcatenation[32], 96U * sizeof(real_T));

  // Buffer: '<S21>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input1'
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'

  for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_l; idxS++) {
    rtb_MatrixScaling[idxS] =
      hearingaid_mock_DW.Rebuffer_CircBuff_b[hearingaid_mock_DW.Rebuffer_CircBufIdx_l
      + idxS];
  }

  for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx_l; idxS++) {
    rtb_MatrixScaling[(idxS - hearingaid_mock_DW.Rebuffer_CircBufIdx_l) + 96] =
      hearingaid_mock_DW.Rebuffer_CircBuff_b[idxS];
  }

  std::memcpy(&rtb_MatrixScaling[96], &hearingaid_mock_U.Input1[0], sizeof
              (real_T) << 5U);
  if (32 > 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_l) {
    for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_l; idxS++)
    {
      hearingaid_mock_DW.Rebuffer_CircBuff_b[hearingaid_mock_DW.Rebuffer_CircBufIdx_l
        + idxS] = hearingaid_mock_U.Input1[idxS];
    }

    for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx_l - 64; idxS++)
    {
      hearingaid_mock_DW.Rebuffer_CircBuff_b[idxS] = hearingaid_mock_U.Input1
        [(idxS - hearingaid_mock_DW.Rebuffer_CircBufIdx_l) + 96];
    }
  } else {
    for (idxS = 0; idxS < 32; idxS++) {
      hearingaid_mock_DW.Rebuffer_CircBuff_b[hearingaid_mock_DW.Rebuffer_CircBufIdx_l
        + idxS] = hearingaid_mock_U.Input1[idxS];
    }
  }

  hearingaid_mock_DW.Rebuffer_CircBufIdx_l += 32;
  if (hearingaid_mock_DW.Rebuffer_CircBufIdx_l >= 96) {
    hearingaid_mock_DW.Rebuffer_CircBufIdx_l -= 96;
  }

  // End of Buffer: '<S21>/Rebuffer'

  // S-Function (sdspdmult2): '<S21>/Matrix Scaling' incorporates:
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'
  //   S-Function (sdspwindow2): '<S14>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 128; k++) {
    rtb_MatrixScaling[idxS] *= hearingaid_mock_ConstB.WindowFunction_n[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S21>/Matrix Scaling'

  // S-Function (sdspfft2): '<S21>/FFT' incorporates:
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'
  //   Sum: '<S2>/Add'

  MWDSPCG_FFT_Interleave_R2BR_D(&rtb_MatrixScaling[0U], &rtb_Add[0U], 1, 128);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_Add[0U], 1, 128, 64, 0,
                       &hearingaid_mock_ConstP.pooled3[0U], 2, false);
  MWDSPCG_FFT_DblLen_Z(&rtb_Add[0U], 1, 128, &hearingaid_mock_ConstP.pooled3[0U],
                       1);

  // Buffer: '<S22>/Rebuffer' incorporates:
  //   Inport: '<Root>/Input1'
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'

  for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_m; idxS++) {
    rtb_MatrixScaling[idxS] =
      hearingaid_mock_DW.Rebuffer_CircBuff_o[hearingaid_mock_DW.Rebuffer_CircBufIdx_m
      + idxS];
  }

  for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx_m; idxS++) {
    rtb_MatrixScaling[(idxS - hearingaid_mock_DW.Rebuffer_CircBufIdx_m) + 96] =
      hearingaid_mock_DW.Rebuffer_CircBuff_o[idxS];
  }

  std::memcpy(&rtb_MatrixScaling[96], &hearingaid_mock_U.Input1[0], sizeof
              (real_T) << 5U);
  if (32 > 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_m) {
    for (idxS = 0; idxS < 96 - hearingaid_mock_DW.Rebuffer_CircBufIdx_m; idxS++)
    {
      hearingaid_mock_DW.Rebuffer_CircBuff_o[hearingaid_mock_DW.Rebuffer_CircBufIdx_m
        + idxS] = hearingaid_mock_U.Input1[idxS];
    }

    for (idxS = 0; idxS < hearingaid_mock_DW.Rebuffer_CircBufIdx_m - 64; idxS++)
    {
      hearingaid_mock_DW.Rebuffer_CircBuff_o[idxS] = hearingaid_mock_U.Input1
        [(idxS - hearingaid_mock_DW.Rebuffer_CircBufIdx_m) + 96];
    }
  } else {
    for (idxS = 0; idxS < 32; idxS++) {
      hearingaid_mock_DW.Rebuffer_CircBuff_o[hearingaid_mock_DW.Rebuffer_CircBufIdx_m
        + idxS] = hearingaid_mock_U.Input1[idxS];
    }
  }

  hearingaid_mock_DW.Rebuffer_CircBufIdx_m += 32;
  if (hearingaid_mock_DW.Rebuffer_CircBufIdx_m >= 96) {
    hearingaid_mock_DW.Rebuffer_CircBufIdx_m -= 96;
  }

  // End of Buffer: '<S22>/Rebuffer'

  // S-Function (sdspdmult2): '<S22>/Matrix Scaling' incorporates:
  //   S-Function (sdspwindow2): '<S15>/Window Function'

  idxS = 0;
  idxV = 0;
  for (k = 0; k < 128; k++) {
    rtb_MatrixScaling[idxS] *= hearingaid_mock_ConstB.WindowFunction_p[idxV];
    idxS++;
    idxV++;
  }

  // End of S-Function (sdspdmult2): '<S22>/Matrix Scaling'

  // S-Function (sdspfft2): '<S22>/FFT' incorporates:
  //   S-Function (sdspdmult2): '<S22>/Matrix Scaling'

  MWDSPCG_FFT_Interleave_R2BR_D(&rtb_MatrixScaling[0U], &rtb_FFT[0U], 1, 128);
  MWDSPCG_R2DIT_TBLS_Z(&rtb_FFT[0U], 1, 128, 64, 0,
                       &hearingaid_mock_ConstP.pooled3[0U], 2, false);
  MWDSPCG_FFT_DblLen_Z(&rtb_FFT[0U], 1, 128, &hearingaid_mock_ConstP.pooled3[0U],
                       1);

  // Sum: '<S2>/Add' incorporates:
  //   S-Function (sdspfft2): '<S22>/FFT'

  for (idxS = 0; idxS < 128; idxS++) {
    rtb_FFT_k = rtb_Add[idxS];
    rtb_FFT_k.re += rtb_FFT[idxS].re;
    rtb_FFT_k.im += rtb_FFT[idxS].im;
    rtb_Add[idxS] = rtb_FFT_k;
  }

  // End of Sum: '<S2>/Add'

  // S-Function (sdspfft2): '<S16>/IFFT' incorporates:
  //   Sum: '<S2>/Add'

  MWDSPCG_IFFT_DblLen_D_XC(&rtb_Add[0U], &hearingaid_mock_B.IFFT_g[0U], 128, 1,
    128, &hearingaid_mock_ConstP.pooled3[0U], 1);
  MWDSPCG_R2DIT_TBLS_Z(&((creal_T *)&hearingaid_mock_B.IFFT_g[0U])[0], 1, 64, 64,
                       0, &hearingaid_mock_ConstP.pooled3[0U], 2, true);

  // Scale inverse transformation
  for (idxS = 0; idxS < 128; idxS++) {
    hearingaid_mock_B.IFFT_g[idxS] /= 128.0;
  }

  // End of S-Function (sdspfft2): '<S16>/IFFT'

  // S-Function (sdspsubmtrx): '<S20>/(N-L)' incorporates:
  //   S-Function (sdspfft2): '<S16>/IFFT'

  std::memcpy(&hearingaid_mock_B.NL_g[0], &hearingaid_mock_B.IFFT_g[0], 96U *
              sizeof(real_T));

  // S-Function (sdspsubmtrx): '<S20>/(L)' incorporates:
  //   S-Function (sdspfft2): '<S16>/IFFT'

  std::memcpy(&hearingaid_mock_B.MatrixConcatenation_m[96],
              &hearingaid_mock_B.IFFT_g[96], sizeof(real_T) << 5U);

  // Sum: '<S20>/Sum' incorporates:
  //   Delay: '<S20>/Delay1'
  //   S-Function (sdspsubmtrx): '<S20>/(N-L)'

  for (idxS = 0; idxS < 96; idxS++) {
    hearingaid_mock_B.MatrixConcatenation_m[idxS] = hearingaid_mock_B.NL_g[idxS]
      + hearingaid_mock_B.NL_c[idxS];
  }

  // End of Sum: '<S20>/Sum'

  // S-Function (sdspsubmtrx): '<S20>/L' incorporates:
  //   Concatenate: '<S20>/Matrix Concatenation'

  std::memcpy(&hearingaid_mock_B.L_i[0],
              &hearingaid_mock_B.MatrixConcatenation_m[0], sizeof(real_T) << 5U);

  // S-Function (sdspsubmtrx): '<S20>/N-L' incorporates:
  //   Concatenate: '<S20>/Matrix Concatenation'

  std::memcpy(&hearingaid_mock_B.NL_c[0],
              &hearingaid_mock_B.MatrixConcatenation_m[32], 96U * sizeof(real_T));
  for (idxS = 0; idxS < 32; idxS++) {
    // Outport: '<Root>/Output1' incorporates:
    //   Gain: '<S19>/Gain'
    //   Product: '<S19>/Rescale Output1'
    //   S-Function (sdspsubmtrx): '<S20>/L'

    hearingaid_mock_Y.Output1[idxS] = 32.0 * hearingaid_mock_B.L_i[idxS] /
      hearingaid_mock_ConstB.Sum_j;

    // Outport: '<Root>/Output' incorporates:
    //   Gain: '<S9>/Gain'
    //   Product: '<S9>/Rescale Output1'
    //   S-Function (sdspsubmtrx): '<S10>/L'

    hearingaid_mock_Y.Output[idxS] = 32.0 * hearingaid_mock_B.L[idxS] /
      hearingaid_mock_ConstB.Sum;
  }
}

// Model initialize function
void hearingaid_mockModelClass::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void hearingaid_mockModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
hearingaid_mockModelClass::hearingaid_mockModelClass() :
  hearingaid_mock_B(),
  hearingaid_mock_DW(),
  hearingaid_mock_U(),
  hearingaid_mock_Y(),
  hearingaid_mock_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
hearingaid_mockModelClass::~hearingaid_mockModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
hearingaid_mockModelClass::RT_MODEL_hearingaid_mock_T
  * hearingaid_mockModelClass::getRTM()
{
  return (&hearingaid_mock_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
