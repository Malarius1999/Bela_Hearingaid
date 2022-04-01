/*
 *  Copyright 2014 The MathWorks Inc.
 *  All rights reserved.
 *
 */


#include <NE10_types.h>
#include "rtwtypes.h"

#ifndef MW_NE10_FFT_H
#define MW_NE10_FFT_H

#ifdef __cplusplus
extern "C" {
#endif

    
///////////////////////////
// function prototypes:
///////////////////////////

    /* fft / ifft functions */
    
    /* Wrapper for c2c init function */
    extern void  mw_ne10_fft_alloc_c2c_float32(
        ne10_fft_state_float32_t **cfg, 
        ne10_int32_t nfft);
       
    /* Wrapper for r2c and c2r init function */
    extern void  mw_ne10_fft_alloc_r2c_float32(
        ne10_fft_r2c_state_float32_t **cfg, 
        ne10_int32_t nfft);
       
    /* Wrapper for C version functions */   

    // for c2c API, may still need the wrapper for suppress the compiler warning
    
    extern void mw_ne10_fft_r2c_1d_float32_c	(	
        creal32_T *fout,
        real32_T *fin,
        ne10_fft_r2c_state_float32_t *cfg);

    extern void mw_ne10_fft_c2r_1d_float32_c	(	
        real32_T *fout,
        creal32_T *fin,
        ne10_fft_r2c_state_float32_t *cfg);

    /* Wrapper for NEON version functions */ 
    
    extern void mw_ne10_fft_r2c_1d_float32_neon	(	
        creal32_T *fout,
        real32_T *fin,
        ne10_fft_r2c_state_float32_t *cfg);
    
     extern void mw_ne10_fft_c2r_1d_float32_neon	(	
        real32_T *fout,
        creal32_T *fin,
        ne10_fft_r2c_state_float32_t *cfg);


#ifdef __cplusplus
}
#endif

#endif
