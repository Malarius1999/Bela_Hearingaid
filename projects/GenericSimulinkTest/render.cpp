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
#include "BeagleBone.h"         // Model's header file
#include "OSC.h"
#include "rtwtypes.h"

bool setup(BelaContext *context, void *userData)
{
	rt_printf("audioSampleRate: %f \n",context->audioSampleRate);
	BeagleBone_initialize();
	OSC_init();
	return context->audioFrames == 64;
}

void render(BelaContext *context, void *userData)
{
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		BeagleBone_U.Input[n] = audioRead(context, n, 1);
		BeagleBone_U.Input1[n] = audioRead(context, n, 0);
	}
	BeagleBone_step();
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		audioWrite(context, n, 0, BeagleBone_Y.Output[n]/1.7219/2);
		audioWrite(context, n, 1, BeagleBone_Y.Output[n]/1.7219/2);
	}
}

void cleanup(BelaContext *context, void *userData)
{
	BeagleBone_terminate();
}