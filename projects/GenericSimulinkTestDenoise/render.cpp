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
#include <libraries/OscSender/OscSender.h>
#include <libraries/OscReceiver/OscReceiver.h>
#include "BeagleBone_denoising.h"         // Model's header file
#include "rtwtypes.h"

OscReceiver oscReceiver;
OscSender oscSender;
int localPort = 7000;
int remotePort = 7001;
const char* remoteIp = "192.168.6.1";

BeagleBone_denoisingModelClass rtObj;

static float output;

void on_receive(oscpkt::Message* msg, void* arg)
{
	BeagleBone_denoisingModelClass::P_BeagleBone_denoising_T param = rtObj.getBlockParameters();
	float floatArg = 0.0f;
	std::string adress = msg->addressPattern();
	if (adress=="/parameter/jx10/VCF_Att"){
		msg->arg().popFloat(floatArg).isOkNoMoreArgs();
		param.RandomSource_VarianceRTP = floatArg;
	} else if (adress=="/parameter/jx10/VCF_Dec"){
		msg->arg().popFloat(floatArg).isOkNoMoreArgs();
		param.NoiseEstimate_Value = floatArg;
	} else if (adress=="/parameter/jx10/VCF_Sus"){
		msg->arg().popFloat(floatArg).isOkNoMoreArgs();
		param.Gain_Gain = floatArg;
	} else if (adress=="/parameter/jx10/VCF_Rel"){
		msg->arg().popFloat(floatArg).isOkNoMoreArgs();
		param.Gain_Gain_l = floatArg;
	} else if(adress=="/parameter/jx10/ENV_Rel"){
		msg->arg().popFloat(floatArg).isOkNoMoreArgs();
		output = floatArg;
	} else {
		printf("%s: Parameter not Implemented\n", msg->addressPattern().c_str());
	}
	rtObj.setBlockParameters(&param);
}

bool setup(BelaContext *context, void *userData)
{
	rt_printf("audioSampleRate: %f \n",context->audioSampleRate);
	
	//Init Algorithm
	rtObj.initialize();
	
	//Setup OSC
	oscReceiver.setup(localPort, on_receive);
	oscSender.setup(remotePort, remoteIp);
	
	return context->audioFrames == 64;
}

void render(BelaContext *context, void *userData)
{
	//Write Input in Algorithm (Blocksize should be 32)
	BeagleBone_denoisingModelClass::ExtU_BeagleBone_denoising_T inputs;
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		inputs.Input[n] = audioRead(context, n, 1);
	}
	rtObj.setExternalInputs(&inputs);
	rtObj.step();
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		audioWrite(context, n, 0, rtObj.getExternalOutputs().Output[n]/1.7219/2*output);
		audioWrite(context, n, 1, rtObj.getExternalOutputs().Output[n]/1.7219/2*output);
	}
}

void cleanup(BelaContext *context, void *userData)
{
	rtObj.terminate();
}