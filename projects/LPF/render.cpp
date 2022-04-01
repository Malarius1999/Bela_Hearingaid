#include <Bela.h>
#include "rtwtypes.h"
#include "FIR.h"

const static real_T coeffs[] = {
  -0.005859321985082624,
  -0.00229310255526908,
  -0.0027000326031450628,
  -0.003121270189883821,
  -0.003550835147438636,
  -0.003980385712506534,
  -0.004400312103900756,
  -0.004802268672759246,
  -0.005173865146712137,
  -0.005506084816782726,
  -0.005786275431033766,
  -0.006002850403555266,
  -0.006143075845195227,
  -0.006194886402999884,
  -0.006147167226248346,
  -0.005989061645005915,
  -0.005710574742875212,
  -0.005302087998133129,
  -0.004755101673626454,
  -0.004062793539027117,
  -0.0032201488009407217,
  -0.0022238443285939277,
  -0.0010726000783376159,
  0.0002341316257985205,
  0.001693404649445283,
  0.0033014802603010224,
  0.005049956502231077,
  0.006929467307055024,
  0.00892926787562288,
  0.011034311006967615,
  0.013236946940728477,
  0.015502186615408326,
  0.017835493539488673,
  0.020197884989824968,
  0.022571749091759505,
  0.024940075061171095,
  0.02727907002988519,
  0.02956436768041623,
  0.031766694317249065,
  0.03386941983942563,
  0.03584876522157331,
  0.03768521662187988,
  0.039357205677664465,
  0.040845573771907215,
  0.042134025508230116,
  0.04320835376648806,
  0.0440576553927918,
  0.04467208595993831,
  0.04504423644319845,
  0.04516889084914579,
  0.04504423644319845,
  0.04467208595993831,
  0.0440576553927918,
  0.04320835376648806,
  0.042134025508230116,
  0.040845573771907215,
  0.039357205677664465,
  0.03768521662187988,
  0.03584876522157331,
  0.03386941983942563,
  0.031766694317249065,
  0.02956436768041623,
  0.02727907002988519,
  0.024940075061171095,
  0.022571749091759505,
  0.020197884989824968,
  0.017835493539488673,
  0.015502186615408326,
  0.013236946940728477,
  0.011034311006967615,
  0.00892926787562288,
  0.006929467307055024,
  0.005049956502231077,
  0.0033014802603010224,
  0.001693404649445283,
  0.0002341316257985205,
  -0.0010726000783376159,
  -0.0022238443285939277,
  -0.0032201488009407217,
  -0.004062793539027117,
  -0.004755101673626454,
  -0.005302087998133129,
  -0.005710574742875212,
  -0.005989061645005915,
  -0.006147167226248346,
  -0.006194886402999884,
  -0.006143075845195227,
  -0.006002850403555266,
  -0.005786275431033766,
  -0.005506084816782726,
  -0.005173865146712137,
  -0.004802268672759246,
  -0.004400312103900756,
  -0.003980385712506534,
  -0.003550835147438636,
  -0.003121270189883821,
  -0.0027000326031450628,
  -0.00229310255526908,
  -0.005859321985082624
};

static FIR<99> fir(coeffs);

bool setup(BelaContext *context, void *userData)
{
	return true;
}

void render(BelaContext *context, void *userData)
{
	for(unsigned int n = 0; n < context->audioFrames; n++) {
		real_T inp = fir.step(audioRead(context, n, 1));
		audioWrite(context, n, 0, inp);
		audioWrite(context, n, 1, inp);
	}
}

void cleanup(BelaContext *context, void *userData)
{

}