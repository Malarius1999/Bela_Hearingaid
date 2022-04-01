/*
 * Sfft.cpp
 *
 *  Created on: 18.03.2022
 *      Author: marius.baumann
 */

#include <libraries/Fft/Fft.h>
#include <numeric>
#include <algorithm>
#include "Bela.h"
#include "Sfft.h"

static Fft fft(FFT_SIZE);

std::vector<std::vector<float>> calcSFFT(std::vector<float> input) {
	std::vector<std::vector<float>> sfftOut = std::vector<std::vector<float>>(2, std::vector<float>(FFT_SIZE, 0.0f));
	//Apply window function (TODO Maybe with neon?)
	for(int i = 0; i < FFT_SIZE; i++){
		input[i] = input[i]*window[i];
	}
	//Calculate FFT with neon
	fft.fft(input);
	for(unsigned int i = 0; i < FFT_SIZE; i++){
		sfftOut[0][i] = fft.fdr(i);
		rt_printf("%f\n", fft.fdr(i));
		sfftOut[1][i] = fft.fdi(i);
	}
	return sfftOut;
}


std::vector<float> calcISFFT(std::vector<std::vector<float>> input, std::array<float, FFT_SIZE-AUDIO_BUFFER_SIZE>& overlapAddBuffer) {
	std::vector<float> iSfftOut = std::vector<float>(FFT_SIZE, 0.0f);
	std::vector<float> overlapAddOut = std::vector<float>(AUDIO_BUFFER_SIZE, 0.0f);
	//Calculate IFFT with neon
	fft.ifft(input[0], input[1]);
	for(unsigned int i = 0; i < FFT_SIZE; i++){
		iSfftOut[i] = fft.td(i); 
	}
	//OVERLAP ADD
	for(int i = 0; i < FFT_SIZE; i++) {
		if(i < FFT_SIZE-AUDIO_BUFFER_SIZE){
			if(i < AUDIO_BUFFER_SIZE)
				overlapAddOut[i] = overlapAddBuffer[i]+iSfftOut[i];
			else
				overlapAddBuffer[i] = overlapAddBuffer[i]+iSfftOut[i];
		}
		else{
			if(i < AUDIO_BUFFER_SIZE)
				overlapAddOut[i] = iSfftOut[i];
			else
				overlapAddBuffer[i] = iSfftOut[i];
		}	
	}
	
	//Apply window normalization (TODO Maybe with neon?)
	for(int i = 0; i < AUDIO_BUFFER_SIZE; i++){
		overlapAddOut[i] = AUDIO_BUFFER_SIZE*overlapAddOut[i]/sumWindowValues;
	}
	return iSfftOut;
}


