/*
 ____  _____ _        _    
| __ )| ____| |      / \   
|  _ \|  _| | |     / _ \  
| |_) | |___| |___ / ___ \ 
|____/|_____|_____/_/   \_\

The platform for ultra-low latency audio and sensor processing

http://bela.io

A project of the Augmented Instruments Laboratory within the
Centre for Digital Music at Queen Mary University of London.
http://www.eecs.qmul.ac.uk/~andrewm

(c) 2016 Augmented Instruments Laboratory: Andrew McPherson,
	Astrid Bin, Liam Donovan, Christian Heinrichs, Robert Jack,
	Giulio Moro, Laurel Pardue, Victor Zappi. All rights reserved.

The Bela software is distributed under the GNU Lesser General Public License
(LGPL 3.0), available here: https://www.gnu.org/licenses/lgpl-3.0.txt
*/

#include <Bela.h>
#include "hearingaid_mock.h"         // Model's header file
#include "rtwtypes.h"
#include "FIR.h"

hearingaid_mockModelClass rtObj;// Instance of model class
real_T lastOut = 0;

/*
const real_T coeffs[51] = {
   0.001874231775976,-0.0002073602454701,-0.003045759477659,0.0002952441167629,
   0.004571223484077,-0.0003917209985124,-0.006526369863039,0.0004940826245851,
    0.00901420688205,-0.0005991751438282, -0.01218547009032,0.0007035345697483,
    0.01627851620554,-0.0008035430864377, -0.02170317754061,0.0008955979640387,
    0.02923668456466,-0.000976283959729, -0.04055541301572, 0.001042539738419,
    0.06004222818485,-0.001091809067484,  -0.1038213660603, 0.001122168313259,
     0.3172041190332,   0.4982661421838,   0.3172041190332, 0.001122168313259,
    -0.1038213660603,-0.001091809067484,  0.06004222818485, 0.001042539738419,
   -0.04055541301572,-0.000976283959729,  0.02923668456466,0.0008955979640387,
   -0.02170317754061,-0.0008035430864377,  0.01627851620554,0.0007035345697483,
   -0.01218547009032,-0.0005991751438282,  0.00901420688205,0.0004940826245851,
  -0.006526369863039,-0.0003917209985124, 0.004571223484077,0.0002952441167629,
  -0.003045759477659,-0.0002073602454701, 0.001874231775976
};
const int firSize = sizeof(coeffs)/sizeof(coeffs[0]);
FIR<firSize> fir(coeffs);
FIR<firSize> fir2(coeffs);*/

bool setup(BelaContext *context, void *userData)
{
	rt_printf("audioSampleRate: %f \n",context->audioSampleRate);
	rtObj.initialize();
	return context->audioFrames == 32;
}

void render(BelaContext *context, void *userData)
{
	/*
	//With Fir Filter
	hearingaid_mockModelClass::ExtU_hearingaid_mock_T inputs;
	for(unsigned int n = 0; n < context->audioFrames/2; n++) {
		//FIR filter edgefreq 10kHz, StopBand: -40Db @ 12kHz, Flat in Passband
		//Delay added: 25/44.1kHz = 0.566ms (Maybe use Hardware filter)
		inputs.Input[n] = fir.step(audioRead(context, 2*n, 1));
		fir.step(audioRead(context, 2*n+1, 1)); //Leave one out Downsampling
	}
	rtObj.setExternalInputs(&inputs);
	rtObj.step();
	for(unsigned int n = 0; n < context->audioFrames/2; n++) {
		real_T interpolate = (lastOut+rtObj.getExternalOutputs().Output[n])/2;
		real_T first = fir2.step(interpolate);
		real_T second = fir2.step(rtObj.getExternalOutputs().Output[n]);
		audioWrite(context, 2*n, 0, first);
		audioWrite(context, 2*n+1, 0, second);
		audioWrite(context, 2*n, 1, first);
		audioWrite(context, 2*n+1, 1, second);
		lastOut = rtObj.getExternalOutputs().Output[n];
	}*/
	
	//Write Input in Algorithm (Blocksize should be 32)
	hearingaid_mockModelClass::ExtU_hearingaid_mock_T inputs;
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		inputs.Input[n] = audioRead(context, n, 1);
		inputs.Input1[n] = audioRead(context, n, 1);
	}
	rtObj.setExternalInputs(&inputs);
	rtObj.step();
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		audioWrite(context, n, 0, rtObj.getExternalOutputs().Output[n]/1.7219/2);
		audioWrite(context, n, 1, rtObj.getExternalOutputs().Output1[n]/1.7219/2);
	}
}

void cleanup(BelaContext *context, void *userData)
{
	rtObj.terminate();
}


/**
\example sinetone/render.cpp

Producing your first bleep!
---------------------------

This sketch is the hello world of embedded interactive audio. Better known as bleep, it 
produces a sine tone.

The frequency of the sine tone is determined by a global variable, `gFrequency`. 
The sine tone is produced by incrementing the phase of a sin function 
on every audio frame.

In render() you'll see a nested for loop structure. You'll see this in all Bela projects. 
The first for loop cycles through 'audioFrames', the second through 'audioChannels' (in this case left 0 and right 1). 
It is good to familiarise yourself with this structure as it's fundamental to producing sound with the system.
*/
