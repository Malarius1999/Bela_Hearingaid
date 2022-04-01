//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hearingaid_denoising_mock.h
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
#ifndef RTW_HEADER_hearingaid_denoising_mock_h_
#define RTW_HEADER_hearingaid_denoising_mock_h_
#include <cmath>
#include <cstring>
#include "rtwtypes.h"
#include "hearingaid_denoising_mock_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model hearingaid_denoising_mock
class hearingaid_denoising_mockModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_hearingaid_denoising_mock_T {
    real_T IFFT[128];                  // '<S3>/IFFT'
    real_T NL[96];                     // '<S9>/(N-L)'
    real_T MatrixConcatenation[128];   // '<S9>/Matrix Concatenation'
    real_T L[32];                      // '<S9>/L'
    real_T NL_o[96];                   // '<S9>/N-L'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_hearingaid_denoising_mock_T {
    real_T Rebuffer_CircBuff[96];      // '<S4>/Rebuffer'
    int32_T Rebuffer_CircBufIdx;       // '<S4>/Rebuffer'
    uint32_T RandomSource_STATE_DWORK[2];// '<Root>/Random Source'
  };

  // Invariant block signals (default storage)
  struct ConstB_hearingaid_denoising_m_T {
    real_T WindowFunction[128];        // '<S1>/Window Function'
    real_T DotProduct;                 // '<S5>/Dot Product'
    real_T Gain;                       // '<S5>/Gain'
    real_T MagSquared1;                // '<S5>/Mag. Squared1'
    real_T Sum;                        // '<S8>/Sum'
  };

  // Constant parameters (default storage)
  struct ConstP_hearingaid_denoising_m_T {
    // Pooled Parameter (Mixed Expressions)
    //  Referenced by:
    //    '<Root>/Random Source'
    //    '<S3>/Buffer'
    //    '<S4>/Rebuffer'
    //    '<S9>/Delay1'

    real_T pooled1;

    // Computed Parameter: RandomSource_VarianceRTP
    //  Referenced by: '<Root>/Random Source'

    real_T RandomSource_VarianceRTP;

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S3>/IFFT'
    //    '<S4>/FFT'

    real_T pooled2[96];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_hearingaid_denoising_moc_T {
    real_T Input[32];                  // '<Root>/Input'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_hearingaid_denoising_moc_T {
    real_T Output[32];                 // '<Root>/Output'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_hearingaid_denoising_T {
    const char_T * volatile errorStatus;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  hearingaid_denoising_mockModelClass();

  // Destructor
  ~hearingaid_denoising_mockModelClass();

  // Root-level structure-based inputs set method

  // Root inports set method
  void setExternalInputs(const ExtU_hearingaid_denoising_moc_T
    * pExtU_hearingaid_denoising_moc_T)
  {
    hearingaid_denoising_mock_U = *pExtU_hearingaid_denoising_moc_T;
  }

  // Root-level structure-based outputs get method

  // Root outports get method
  const hearingaid_denoising_mockModelClass::ExtY_hearingaid_denoising_moc_T
    & getExternalOutputs() const
  {
    return hearingaid_denoising_mock_Y;
  }

  // Real-Time Model get method
  hearingaid_denoising_mockModelClass::RT_MODEL_hearingaid_denoising_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_hearingaid_denoising_mock_T hearingaid_denoising_mock_B;

  // Block states
  DW_hearingaid_denoising_mock_T hearingaid_denoising_mock_DW;

  // External inputs
  ExtU_hearingaid_denoising_moc_T hearingaid_denoising_mock_U;

  // External outputs
  ExtY_hearingaid_denoising_moc_T hearingaid_denoising_mock_Y;

  // Real-Time Model
  RT_MODEL_hearingaid_denoising_T hearingaid_denoising_mock_M;
};

extern const hearingaid_denoising_mockModelClass::
  ConstB_hearingaid_denoising_m_T hearingaid_denoising_moc_ConstB;// constant block i/o 

// Constant parameters (default storage)
extern const hearingaid_denoising_mockModelClass::
  ConstP_hearingaid_denoising_m_T hearingaid_denoising_moc_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/Check Signal Attributes' : Unused code path elimination
//  Block '<S7>/Check Signal Attributes' : Unused code path elimination
//  Block '<Root>/Manual Switch' : Eliminated due to constant selection input


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
//  '<Root>' : 'hearingaid_denoising_mock'
//  '<S1>'   : 'hearingaid_denoising_mock/Hi denoising mock'
//  '<S2>'   : 'hearingaid_denoising_mock/Hi denoising mock/Gain Estimator'
//  '<S3>'   : 'hearingaid_denoising_mock/Hi denoising mock/Inverse  Short-Time FFT'
//  '<S4>'   : 'hearingaid_denoising_mock/Hi denoising mock/Short-Time FFT'
//  '<S5>'   : 'hearingaid_denoising_mock/Hi denoising mock/Gain Estimator/STFT Normalization'
//  '<S6>'   : 'hearingaid_denoising_mock/Hi denoising mock/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S7>'   : 'hearingaid_denoising_mock/Hi denoising mock/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S8>'   : 'hearingaid_denoising_mock/Hi denoising mock/Inverse  Short-Time FFT/Normalization'
//  '<S9>'   : 'hearingaid_denoising_mock/Hi denoising mock/Inverse  Short-Time FFT/Overlap-And-Add'

#endif                               // RTW_HEADER_hearingaid_denoising_mock_h_

//
// File trailer for generated code.
//
// [EOF]
//
