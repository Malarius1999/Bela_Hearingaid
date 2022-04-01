//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hearingaid_mock.h
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
#ifndef RTW_HEADER_hearingaid_mock_h_
#define RTW_HEADER_hearingaid_mock_h_
#include <cstring>
#include "rtwtypes.h"
#include "hearingaid_mock_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model hearingaid_mock
class hearingaid_mockModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_hearingaid_mock_T {
    real_T IFFT[128];                  // '<S6>/IFFT'
    real_T NL[96];                     // '<S10>/(N-L)'
    real_T MatrixConcatenation[128];   // '<S10>/Matrix Concatenation'
    real_T L[32];                      // '<S10>/L'
    real_T NL_m[96];                   // '<S10>/N-L'
    real_T IFFT_g[128];                // '<S16>/IFFT'
    real_T NL_g[96];                   // '<S20>/(N-L)'
    real_T MatrixConcatenation_m[128]; // '<S20>/Matrix Concatenation'
    real_T L_i[32];                    // '<S20>/L'
    real_T NL_c[96];                   // '<S20>/N-L'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_hearingaid_mock_T {
    real_T Rebuffer_CircBuff[96];      // '<S11>/Rebuffer'
    real_T Rebuffer_CircBuff_f[96];    // '<S12>/Rebuffer'
    real_T Rebuffer_CircBuff_b[96];    // '<S21>/Rebuffer'
    real_T Rebuffer_CircBuff_o[96];    // '<S22>/Rebuffer'
    int32_T Rebuffer_CircBufIdx;       // '<S11>/Rebuffer'
    int32_T Rebuffer_CircBufIdx_c;     // '<S12>/Rebuffer'
    int32_T Rebuffer_CircBufIdx_l;     // '<S21>/Rebuffer'
    int32_T Rebuffer_CircBufIdx_m;     // '<S22>/Rebuffer'
  };

  // Invariant block signals (default storage)
  struct ConstB_hearingaid_mock_T {
    real_T WindowFunction1[128];       // '<S3>/Window Function1'
    real_T Sum;                        // '<S9>/Sum'
    real_T WindowFunction[128];        // '<S4>/Window Function'
    real_T WindowFunction_d[128];      // '<S5>/Window Function'
    real_T WindowFunction1_o[128];     // '<S13>/Window Function1'
    real_T Sum_j;                      // '<S19>/Sum'
    real_T WindowFunction_n[128];      // '<S14>/Window Function'
    real_T WindowFunction_p[128];      // '<S15>/Window Function'
  };

  // Constant parameters (default storage)
  struct ConstP_hearingaid_mock_T {
    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S6>/IFFT'
    //    '<S11>/FFT'
    //    '<S12>/FFT'
    //    '<S16>/IFFT'
    //    '<S21>/FFT'
    //    '<S22>/FFT'

    real_T pooled3[96];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_hearingaid_mock_T {
    real_T Input[32];                  // '<Root>/Input'
    real_T Input1[32];                 // '<Root>/Input1'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_hearingaid_mock_T {
    real_T Output[32];                 // '<Root>/Output'
    real_T Output1[32];                // '<Root>/Output1'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_hearingaid_mock_T {
    const char_T * volatile errorStatus;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  hearingaid_mockModelClass();

  // Destructor
  ~hearingaid_mockModelClass();

  // Root-level structure-based inputs set method

  // Root inports set method
  void setExternalInputs(const ExtU_hearingaid_mock_T* pExtU_hearingaid_mock_T)
  {
    hearingaid_mock_U = *pExtU_hearingaid_mock_T;
  }

  // Root-level structure-based outputs get method

  // Root outports get method
  const hearingaid_mockModelClass::ExtY_hearingaid_mock_T & getExternalOutputs()
    const
  {
    return hearingaid_mock_Y;
  }

  // Real-Time Model get method
  hearingaid_mockModelClass::RT_MODEL_hearingaid_mock_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_hearingaid_mock_T hearingaid_mock_B;

  // Block states
  DW_hearingaid_mock_T hearingaid_mock_DW;

  // External inputs
  ExtU_hearingaid_mock_T hearingaid_mock_U;

  // External outputs
  ExtY_hearingaid_mock_T hearingaid_mock_Y;

  // Real-Time Model
  RT_MODEL_hearingaid_mock_T hearingaid_mock_M;
};

extern const hearingaid_mockModelClass::ConstB_hearingaid_mock_T
  hearingaid_mock_ConstB;              // constant block i/o

// Constant parameters (default storage)
extern const hearingaid_mockModelClass::ConstP_hearingaid_mock_T
  hearingaid_mock_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/Check Signal Attributes' : Unused code path elimination
//  Block '<S8>/Check Signal Attributes' : Unused code path elimination
//  Block '<S17>/Check Signal Attributes' : Unused code path elimination
//  Block '<S18>/Check Signal Attributes' : Unused code path elimination


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
//  '<Root>' : 'hearingaid_mock'
//  '<S1>'   : 'hearingaid_mock/HI Mock'
//  '<S2>'   : 'hearingaid_mock/HI Mock1'
//  '<S3>'   : 'hearingaid_mock/HI Mock/ISTFT'
//  '<S4>'   : 'hearingaid_mock/HI Mock/STFT'
//  '<S5>'   : 'hearingaid_mock/HI Mock/STFT1'
//  '<S6>'   : 'hearingaid_mock/HI Mock/ISTFT/Inverse  Short-Time FFT'
//  '<S7>'   : 'hearingaid_mock/HI Mock/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S8>'   : 'hearingaid_mock/HI Mock/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S9>'   : 'hearingaid_mock/HI Mock/ISTFT/Inverse  Short-Time FFT/Normalization'
//  '<S10>'  : 'hearingaid_mock/HI Mock/ISTFT/Inverse  Short-Time FFT/Overlap-And-Add'
//  '<S11>'  : 'hearingaid_mock/HI Mock/STFT/Short-Time FFT'
//  '<S12>'  : 'hearingaid_mock/HI Mock/STFT1/Short-Time FFT'
//  '<S13>'  : 'hearingaid_mock/HI Mock1/ISTFT'
//  '<S14>'  : 'hearingaid_mock/HI Mock1/STFT'
//  '<S15>'  : 'hearingaid_mock/HI Mock1/STFT1'
//  '<S16>'  : 'hearingaid_mock/HI Mock1/ISTFT/Inverse  Short-Time FFT'
//  '<S17>'  : 'hearingaid_mock/HI Mock1/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S18>'  : 'hearingaid_mock/HI Mock1/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S19>'  : 'hearingaid_mock/HI Mock1/ISTFT/Inverse  Short-Time FFT/Normalization'
//  '<S20>'  : 'hearingaid_mock/HI Mock1/ISTFT/Inverse  Short-Time FFT/Overlap-And-Add'
//  '<S21>'  : 'hearingaid_mock/HI Mock1/STFT/Short-Time FFT'
//  '<S22>'  : 'hearingaid_mock/HI Mock1/STFT1/Short-Time FFT'

#endif                                 // RTW_HEADER_hearingaid_mock_h_

//
// File trailer for generated code.
//
// [EOF]
//
