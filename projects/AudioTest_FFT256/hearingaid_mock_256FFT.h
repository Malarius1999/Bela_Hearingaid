//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hearingaid_mock_256FFT.h
//
// Code generated for Simulink model 'hearingaid_mock_256FFT'.
//
// Model version                  : 4.0
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Mar 16 17:18:48 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_hearingaid_mock_256FFT_h_
#define RTW_HEADER_hearingaid_mock_256FFT_h_
#include <cstring>
#include "rtwtypes.h"
#include "hearingaid_mock_256FFT_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model hearingaid_mock_256FFT
class hearingaid_mock_256FFTModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_hearingaid_mock_256FFT_T {
    real_T IFFT[256];                  // '<S5>/IFFT'
    real_T NL[192];                    // '<S9>/(N-L)'
    real_T MatrixConcatenation[256];   // '<S9>/Matrix Concatenation'
    real_T L[64];                      // '<S9>/L'
    real_T NL_m[192];                  // '<S9>/N-L'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_hearingaid_mock_256FFT_T {
    real_T Rebuffer_CircBuff[192];     // '<S10>/Rebuffer'
    real_T Rebuffer_CircBuff_e[192];   // '<S11>/Rebuffer'
    int32_T Rebuffer_CircBufIdx;       // '<S10>/Rebuffer'
    int32_T Rebuffer_CircBufIdx_j;     // '<S11>/Rebuffer'
  };

  // Invariant block signals (default storage)
  struct ConstB_hearingaid_mock_256FFT_T {
    real_T WindowFunction1[256];       // '<S2>/Window Function1'
    real_T Sum;                        // '<S8>/Sum'
    real_T WindowFunction[256];        // '<S3>/Window Function'
    real_T WindowFunction_b[256];      // '<S4>/Window Function'
  };

  // Constant parameters (default storage)
  struct ConstP_hearingaid_mock_256FFT_T {
    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S5>/IFFT'
    //    '<S10>/FFT'
    //    '<S11>/FFT'

    real_T pooled3[192];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_hearingaid_mock_256FFT_T {
    real_T Input[64];                  // '<Root>/Input'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_hearingaid_mock_256FFT_T {
    real_T Output[64];                 // '<Root>/Output'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_hearingaid_mock_256F_T {
    const char_T * volatile errorStatus;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  hearingaid_mock_256FFTModelClass();

  // Destructor
  ~hearingaid_mock_256FFTModelClass();

  // Root-level structure-based inputs set method

  // Root inports set method
  void setExternalInputs(const ExtU_hearingaid_mock_256FFT_T
    * pExtU_hearingaid_mock_256FFT_T)
  {
    hearingaid_mock_256FFT_U = *pExtU_hearingaid_mock_256FFT_T;
  }

  // Root-level structure-based outputs get method

  // Root outports get method
  const hearingaid_mock_256FFTModelClass::ExtY_hearingaid_mock_256FFT_T
    & getExternalOutputs() const
  {
    return hearingaid_mock_256FFT_Y;
  }

  // Real-Time Model get method
  hearingaid_mock_256FFTModelClass::RT_MODEL_hearingaid_mock_256F_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_hearingaid_mock_256FFT_T hearingaid_mock_256FFT_B;

  // Block states
  DW_hearingaid_mock_256FFT_T hearingaid_mock_256FFT_DW;

  // External inputs
  ExtU_hearingaid_mock_256FFT_T hearingaid_mock_256FFT_U;

  // External outputs
  ExtY_hearingaid_mock_256FFT_T hearingaid_mock_256FFT_Y;

  // Real-Time Model
  RT_MODEL_hearingaid_mock_256F_T hearingaid_mock_256FFT_M;
};

extern const hearingaid_mock_256FFTModelClass::ConstB_hearingaid_mock_256FFT_T
  hearingaid_mock_256FFT_ConstB;       // constant block i/o

// Constant parameters (default storage)
extern const hearingaid_mock_256FFTModelClass::ConstP_hearingaid_mock_256FFT_T
  hearingaid_mock_256FFT_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/Check Signal Attributes' : Unused code path elimination
//  Block '<S7>/Check Signal Attributes' : Unused code path elimination


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
//  '<Root>' : 'hearingaid_mock_256FFT'
//  '<S1>'   : 'hearingaid_mock_256FFT/HI Mock'
//  '<S2>'   : 'hearingaid_mock_256FFT/HI Mock/ISTFT'
//  '<S3>'   : 'hearingaid_mock_256FFT/HI Mock/STFT'
//  '<S4>'   : 'hearingaid_mock_256FFT/HI Mock/STFT1'
//  '<S5>'   : 'hearingaid_mock_256FFT/HI Mock/ISTFT/Inverse  Short-Time FFT'
//  '<S6>'   : 'hearingaid_mock_256FFT/HI Mock/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S7>'   : 'hearingaid_mock_256FFT/HI Mock/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S8>'   : 'hearingaid_mock_256FFT/HI Mock/ISTFT/Inverse  Short-Time FFT/Normalization'
//  '<S9>'   : 'hearingaid_mock_256FFT/HI Mock/ISTFT/Inverse  Short-Time FFT/Overlap-And-Add'
//  '<S10>'  : 'hearingaid_mock_256FFT/HI Mock/STFT/Short-Time FFT'
//  '<S11>'  : 'hearingaid_mock_256FFT/HI Mock/STFT1/Short-Time FFT'

#endif                                 // RTW_HEADER_hearingaid_mock_256FFT_h_

//
// File trailer for generated code.
//
// [EOF]
//
