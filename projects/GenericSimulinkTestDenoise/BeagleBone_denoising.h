//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: BeagleBone_denoising.h
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
#ifndef RTW_HEADER_BeagleBone_denoising_h_
#define RTW_HEADER_BeagleBone_denoising_h_
#include <arm_neon.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#include "rtwtypes.h"
#include "BeagleBone_denoising_types.h"
#include <stddef.h>
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

// External data declarations for dependent source files
extern const creal32_T BeagleBone_denoising_R32GND_Complex;// real32_T complex ground 

// Function to get C API Model Mapping Static Info
extern const rtwCAPI_ModelMappingStaticInfo*
  BeagleBone_denoising_GetCAPIStaticMap(void);

// Class declaration for model BeagleBone_denoising
class BeagleBone_denoisingModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_BeagleBone_denoising_T {
    creal32_T IFFT_U0[256];
    creal32_T FFT_j[256];
    creal32_T FFT[256];
    creal32_T Gain1[256];              // '<S2>/Gain1'
    creal32_T Gain[128];               // '<S2>/Gain'
    real32_T IFFT[256];
    real32_T MatrixConcatenation[256]; // '<S20>/Matrix Concatenation'
    real32_T MatrixScaling_a[256];     // '<S26>/Matrix Scaling'
    real32_T MatrixScaling[256];       // '<S27>/Matrix Scaling'
    real32_T MatrixScaling_d[256];     // '<S28>/Matrix Scaling'
    real32_T MatrixScaling_o[256];     // '<S29>/Matrix Scaling'
    real32_T NL[192];                  // '<S20>/(N-L)'
    real32_T L[64];                    // '<S20>/L'
    real32_T NL_c[192];                // '<S20>/N-L'
    real32_T IFFT_c[256];
    real32_T NL_cu[192];               // '<S25>/(N-L)'
    real32_T MatrixConcatenation_b[256];// '<S25>/Matrix Concatenation'
    real32_T NL_m[192];                // '<S25>/N-L'
    real32_T fv[4];
    real32_T fv1[4];
    creal32_T rtb_Gain_m;
    real32_T Sum;                      // '<S19>/Sum'
    real32_T rtb_MathFunction1_c;
    real32_T u;
    real32_T r;
    real32_T x;
    int32_T idxS;
    int32_T idxV;
    int32_T i;
    int32_T i_k;
    int32_T j;
  };

  // Block states (default storage) for system '<Root>'
  struct DW_BeagleBone_denoising_T {
    real32_T Rebuffer_CircBuff[192];   // '<S26>/Rebuffer'
    real32_T Rebuffer_CircBuff_a[192]; // '<S27>/Rebuffer'
    real32_T Rebuffer_CircBuff_m[192]; // '<S28>/Rebuffer'
    real32_T Rebuffer_CircBuff_b[192]; // '<S29>/Rebuffer'
    ne10_fft_r2c_state_float32_t* cfg;
    ne10_fft_r2c_state_float32_t* cfg_m;
    ne10_fft_r2c_state_float32_t* cfg_c;
    ne10_fft_r2c_state_float32_t* cfg_k;
    ne10_fft_r2c_state_float32_t* cfg_cx;
    ne10_fft_r2c_state_float32_t* cfg_b;
    int32_T Rebuffer_CircBufIdx;       // '<S26>/Rebuffer'
    int32_T Rebuffer_CircBufIdx_j;     // '<S27>/Rebuffer'
    int32_T Rebuffer_CircBufIdx_h;     // '<S28>/Rebuffer'
    int32_T Rebuffer_CircBufIdx_a;     // '<S29>/Rebuffer'
    uint32_T RandomSource_STATE_DWORK[2];// '<Root>/Random Source'
  };

  // Invariant block signals (default storage)
  struct ConstB_BeagleBone_denoising_T {
    real32_T WindowFunction1[256];     // '<S8>/Window Function1'
    real32_T WindowFunction[256];      // '<S12>/Window Function'
    real32_T WindowFunction_m[256];    // '<S13>/Window Function'
    real32_T WindowFunction_e[256];    // '<S14>/Window Function'
    real32_T WindowFunction_mi[256];   // '<S15>/Window Function'
    real32_T WindowFunction_o[128];    // '<S1>/Window Function'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_BeagleBone_denoising_T {
    real32_T Input[64];                // '<Root>/Input'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_BeagleBone_denoising_T {
    real32_T Output[64];               // '<Root>/Output'
  };

  // Parameters (default storage)
  struct P_BeagleBone_denoising_T {
    real32_T RandomSource_MeanVal;     // Mask Parameter: RandomSource_MeanVal
                                          //  Referenced by: '<Root>/Random Source'

    real32_T RandomSource_VarianceRTP;
                                 // Computed Parameter: RandomSource_VarianceRTP
                                    //  Referenced by: '<Root>/Random Source'

    real32_T Rebuffer_ic;              // Computed Parameter: Rebuffer_ic
                                          //  Referenced by: '<S26>/Rebuffer'

    real32_T Rebuffer_ic_j;            // Computed Parameter: Rebuffer_ic_j
                                          //  Referenced by: '<S27>/Rebuffer'

    real32_T Constant2_Value;          // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<S3>/Constant2'

    real32_T NoiseEstimate_Value;     // Computed Parameter: NoiseEstimate_Value
                                         //  Referenced by: '<S3>/Noise Estimate'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S30>/Gain'

    real32_T Gain_Gain_l;              // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S2>/Gain'

    real32_T Delay1_InitialCondition;
                                  // Computed Parameter: Delay1_InitialCondition
                                     //  Referenced by: '<S20>/Delay1'

    real32_T Rebuffer_ic_c;            // Computed Parameter: Rebuffer_ic_c
                                          //  Referenced by: '<S28>/Rebuffer'

    real32_T Rebuffer_ic_jy;           // Computed Parameter: Rebuffer_ic_jy
                                          //  Referenced by: '<S29>/Rebuffer'

    real32_T Gain1_Gain;               // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S2>/Gain1'

    real32_T Delay1_InitialCondition_m;
                                // Computed Parameter: Delay1_InitialCondition_m
                                   //  Referenced by: '<S25>/Delay1'

    real32_T Gain_Gain_l0;             // Computed Parameter: Gain_Gain_l0
                                          //  Referenced by: '<S19>/Gain'

    real32_T Buffer_ic;                // Computed Parameter: Buffer_ic
                                          //  Referenced by: '<S16>/Buffer'

    uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_BeagleBone_denoising_T {
    const char_T *errorStatus;

    //
    //  DataMapInfo:
    //  The following substructure contains information regarding
    //  structures generated in the model's C API.

    struct {
      rtwCAPI_ModelMappingInfo mmi;
      void* dataAddress[16];
      int32_T* vardimsAddress[16];
      RTWLoggingFcnPtr loggingPtrs[16];
    } DataMapInfo;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  BeagleBone_denoisingModelClass();

  // Destructor
  ~BeagleBone_denoisingModelClass();

  // Block parameters get method
  const BeagleBone_denoisingModelClass::P_BeagleBone_denoising_T
    & getBlockParameters() const;

  // Block parameters set method
  void setBlockParameters(const P_BeagleBone_denoising_T
    *pBeagleBone_denoising_P);

  // Root-level structure-based inputs set method

  // Root inports set method
  void setExternalInputs(const ExtU_BeagleBone_denoising_T
    * pExtU_BeagleBone_denoising_T)
  {
    BeagleBone_denoising_U = *pExtU_BeagleBone_denoising_T;
  }

  // Root-level structure-based outputs get method

  // Root outports get method
  const BeagleBone_denoisingModelClass::ExtY_BeagleBone_denoising_T
    & getExternalOutputs() const
  {
    return BeagleBone_denoising_Y;
  }

  // Real-Time Model get method
  BeagleBone_denoisingModelClass::RT_MODEL_BeagleBone_denoising_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  static P_BeagleBone_denoising_T BeagleBone_denoising_P;

  // Block signals
  B_BeagleBone_denoising_T BeagleBone_denoising_B;

  // Block states
  DW_BeagleBone_denoising_T BeagleBone_denoising_DW;

  // External inputs
  ExtU_BeagleBone_denoising_T BeagleBone_denoising_U;

  // External outputs
  ExtY_BeagleBone_denoising_T BeagleBone_denoising_Y;

  // Real-Time Model
  RT_MODEL_BeagleBone_denoising_T BeagleBone_denoising_M;

  // private member function(s) for subsystem '<Root>'
  void BeagleBone_denoisi_RandSrc_GZ_R(real32_T y[], const real32_T mean[],
    int32_T meanLen, const real32_T xstd[], int32_T xstdLen, uint32_T state[],
    int32_T nChans, int32_T nSamps);
};

extern const BeagleBone_denoisingModelClass::ConstB_BeagleBone_denoising_T
  BeagleBone_denoising_ConstB;         // constant block i/o

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S17>/Check Signal Attributes' : Unused code path elimination
//  Block '<S18>/Check Signal Attributes' : Unused code path elimination
//  Block '<S21>/Buffer' : Unused code path elimination
//  Block '<S22>/Check Signal Attributes' : Unused code path elimination
//  Block '<S23>/Check Signal Attributes' : Unused code path elimination
//  Block '<S24>/Gain' : Unused code path elimination
//  Block '<S24>/Rescale Output1' : Unused code path elimination
//  Block '<S24>/Sum' : Unused code path elimination
//  Block '<S25>/L' : Unused code path elimination
//  Block '<S9>/Window Function1' : Unused code path elimination


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
//  '<Root>' : 'BeagleBone_denoising'
//  '<S1>'   : 'BeagleBone_denoising/Hi denoising mock'
//  '<S2>'   : 'BeagleBone_denoising/Hi denoising mock/BeagleBone'
//  '<S3>'   : 'BeagleBone_denoising/Hi denoising mock/Gain Estimator'
//  '<S4>'   : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/Demux'
//  '<S5>'   : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/Demux1'
//  '<S6>'   : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/Demux2'
//  '<S7>'   : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/Demux3'
//  '<S8>'   : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT'
//  '<S9>'   : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT1'
//  '<S10>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/Mux'
//  '<S11>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/Mux1'
//  '<S12>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT1'
//  '<S13>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT2'
//  '<S14>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT3'
//  '<S15>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT4'
//  '<S16>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT'
//  '<S17>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S18>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S19>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT/Normalization'
//  '<S20>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT/Inverse  Short-Time FFT/Overlap-And-Add'
//  '<S21>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT1/Inverse  Short-Time FFT'
//  '<S22>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Check Signal Attributes'
//  '<S23>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Check Signal Attributes1'
//  '<S24>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Normalization'
//  '<S25>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/ISTFT1/Inverse  Short-Time FFT/Overlap-And-Add'
//  '<S26>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT1/Short-Time FFT'
//  '<S27>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT2/Short-Time FFT'
//  '<S28>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT3/Short-Time FFT'
//  '<S29>'  : 'BeagleBone_denoising/Hi denoising mock/BeagleBone/STFT4/Short-Time FFT'
//  '<S30>'  : 'BeagleBone_denoising/Hi denoising mock/Gain Estimator/STFT Normalization'

#endif                                 // RTW_HEADER_BeagleBone_denoising_h_

//
// File trailer for generated code.
//
// [EOF]
//
