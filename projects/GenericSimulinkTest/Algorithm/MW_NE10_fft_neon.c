/*
 *  Copyright 2014 The MathWorks Inc.
 *  All rights reserved.
 *
 */

/*
 * Wrapper functions for the NE10 DSP Library FFT/IFFT functions
 */

#include "NE10_types.h"
#include "NE10_dsp.h"
#include "rtwtypes.h"




/**
 * @brief Wrapper file for mixed-radix 1D real-to-complex FFT of 
 *        floating-point data type (neon version).
 */
void mw_ne10_fft_r2c_1d_float32_neon (	        
        creal32_T *fout,
        real32_T *fin,
        ne10_fft_r2c_state_float32_t *cfg)
{
    int k;
    int ncfft = cfg->ncfft;
    int nfft = ncfft << 1;
    
    /* NE10 lib only calculates output[0]~output[fftSize/2] */
    ne10_fft_r2c_1d_float32_neon(
            (ne10_fft_cpx_float32_t*)fout,
            fin,
            cfg);
    
    /* fill output[fftSize/2+1] ~ output[fftSize] based on the fact that 
     * output[i] is the conjugate of output[fftSize-i]
     */
    for (k=1; k<ncfft; k++) {
     fout[nfft-k].re = fout[k].re;
     fout[nfft-k].im = -fout[k].im;
    }
}

/**
 * @brief Wrapper file for mixed-radix 1D complex-to-real IFFT of 
 *        floating-point data type (neon version).
 */
void mw_ne10_fft_c2r_1d_float32_neon	(	
        real32_T *fout,
        creal32_T *fin,
        ne10_fft_r2c_state_float32_t *cfg)
{
    ne10_fft_c2r_1d_float32_neon(           
            fout,
            (ne10_fft_cpx_float32_t*)fin,
            cfg);
}
