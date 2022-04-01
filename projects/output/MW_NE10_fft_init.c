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

/**
 * @brief Wrapper file for initialization function of complex FFT/IFFT 
 *        floating-point data type (C version).
 * @param[in]   nfft             length of FFT
 * @param[out]  cfg              point to the FFT config memory. This memory is allocated with malloc.
 * The function allocate all necessary storage space for the fft and do init. 
 *
 * Ne10 Lib function being called:
 * ne10_fft_cfg_float32_t ne10_fft_alloc_c2c_float32 (ne10_int32_t nfft)
 */
void  mw_ne10_fft_alloc_c2c_float32(
    ne10_fft_state_float32_t **cfg, 
    ne10_int32_t nfft)
{
    (*cfg) = ne10_fft_alloc_c2c_float32(nfft);    
}


/**
 * @brief User-callable function to allocate all necessary storage space for the fft (c2r) and ifft (c2r).
 * @param[in]   nfft             length of FFT
 * @return      st               point to the FFT config memory. This memory is allocated with malloc.
 * The function allocate all necessary storage space for the fft and ifft. 
 * It also factors out the length of FFT and generates the twiddle coeff.
 *
 * Ne10 Lib function being called:
 * ne10_fft_r2c_cfg_float32_t ne10_fft_alloc_r2c_float32 (ne10_int32_t nfft)
 */

void  mw_ne10_fft_alloc_r2c_float32(
    ne10_fft_r2c_state_float32_t **cfg, 
    ne10_int32_t nfft)
{
    (*cfg) = ne10_fft_alloc_r2c_float32(nfft);    
}
