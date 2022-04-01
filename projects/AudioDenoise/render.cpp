#include <Bela.h>
#include "hearingaid_denoising_mock.h"         // Model's header file
#include "rtwtypes.h"

static hearingaid_denoising_mockModelClass rtObj;// Instance of model class

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//

bool setup(BelaContext *context, void *userData)
{
	rtObj.initialize();	
	return context->audioFrames == 32;
}

void render(BelaContext *context, void *userData)
{
	hearingaid_denoising_mockModelClass::ExtU_hearingaid_denoising_moc_T inputs;
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		inputs.Input[n] = audioRead(context,n,1);
	}
	rtObj.setExternalInputs(&inputs);
	rtObj.step();
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		audioWrite(context, n, 0, rtObj.getExternalOutputs().Output[n]);
		audioWrite(context, n, 1, rtObj.getExternalOutputs().Output[n]);
	}
	
	/* 64 Block...
	hearingaid_denoising_mockModelClass::ExtU_hearingaid_denoising_moc_T inputs;
	for(unsigned int n = 0; n < context->audioFrames/2; n++) {
		inputs.Input[n] = audioRead(context,2*n,1);
	}
	rtObj.setExternalInputs(&inputs);
	rtObj.step();
	for(unsigned int n = 0; n < context->audioFrames/2; n++) {
		audioWrite(context, 2*n, 0, rtObj.getExternalOutputs().Output[n]);
		audioWrite(context, 2*n+1, 0, rtObj.getExternalOutputs().Output[n]);
		audioWrite(context, 2*n, 1, rtObj.getExternalOutputs().Output[n]);
		audioWrite(context, 2*n+1, 1, rtObj.getExternalOutputs().Output[n]);
	}*/
}

void cleanup(BelaContext *context, void *userData)
{

}