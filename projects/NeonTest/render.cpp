#include <Bela.h>
#include <vector>
#include <queue> 
#include <math.h>
#include <array>
#include "Sfft.h"
#include "constants.h"
using namespace std;

/*
const unsigned int channels = 2;
const unsigned int fftsize = 128;

Fft f;
vector<vector<vector<float>>> freq_signals; //channels || real/complex || sample 
vector<vector<float>> fftbuffers;
*/

const unsigned int printCountOnRow = 2;
static array<float, FFT_SIZE-AUDIO_BUFFER_SIZE> overlapAddISFFT1{};

bool setup(BelaContext *context, void *userData)
{
	/*
	if(context->audioFrames != AUDIO_BUFFER_SIZE)
		return false;*/
		
	vector<float> input;
	for(unsigned int i = 0; i < FFT_SIZE; i++){
		input.push_back(i%2);
	}
	
	rt_printf("FFT-In:\n");
	for(int i = 0; i < FFT_SIZE/printCountOnRow; i++){
		for(int j = 0; j < printCountOnRow; j++){
			rt_printf("%f | ", input[i*printCountOnRow+j]);
		}
		rt_printf("\n");
	}
	
	std::vector<std::vector<float>> values = calcSFFT(input);
	
	rt_printf("FFT-Out: \n");
	for(int i = 0; i < FFT_SIZE/printCountOnRow; i++){
		for(int j = 0; j < printCountOnRow; j++){
			rt_printf("%f, %f | ", values[0][i*printCountOnRow+j], values[1][i*printCountOnRow+j]);
		} 
		rt_printf("\n");  
	}
	
	vector<float> output = calcISFFT(values, overlapAddISFFT1);
	
	rt_printf("Buffer2:\n");
	for(int i = 0; i < FFT_SIZE/printCountOnRow; i++){
		for(int j = 0; j < printCountOnRow; j++){
			rt_printf("%f| ", overlapAddISFFT1[i*printCountOnRow+j]);
		} 
		rt_printf("\n");  
	}
	
	output = calcISFFT(values, overlapAddISFFT1);
	
	rt_printf("Output:\n");
	for(int i = 0; i < FFT_SIZE/printCountOnRow; i++){
		for(int j = 0; j < printCountOnRow; j++){
			rt_printf("%f| ", output[i*printCountOnRow+j]);
		} 
		rt_printf("\n");  
	}
	
	/*
	f.setup(fftsize);
	freq_signals.resize(channels);
	fftbuffers.resize(channels);
	for(unsigned int c = 0; c < channels; c++){
		freq_signals[c].resize(2);
		for(unsigned int n = 0; n < 2; n++)
			freq_signals[c][n].resize(fftsize);
		fftbuffers[c].resize(fftsize);
		for(unsigned int i = 0; i < fftsize; i++){
			fftbuffers[c][i]=0.0f;
		}
			
		
	}*/
	return true;
}

void render(BelaContext *context, void *userData)
{
	/*
	for(unsigned int c = 0; c < channels; c++){
		vector<float>::iterator it;
		for(unsigned int n = 0; n < context->audioFrames; n++) {
			it = fftbuffers[c].begin();
			fftbuffers[c].insert(it, audioRead(context, n, c)/1.7219);
			fftbuffers[c].pop_back();
		}
		f.fft(fftbuffers[c]);
		for(unsigned int n = 0; n < fftsize; n++) {
			freq_signals[c][0][n] = f.fdr(n);
			freq_signals[c][1][n] = f.fdi(n);
		}
		f.ifft(freq_signals[c][0], freq_signals[c][1]);
		for(unsigned int n = 0; n < context->audioFrames; n++) {
			audioWrite(context, n, c, f.td(n));
		}
	}
	*/
}

void cleanup(BelaContext *context, void *userData)
{

}