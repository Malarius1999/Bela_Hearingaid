#include <libraries/OscReceiver/OscReceiver.h>

#include "BeagleBone.h"
#include "OSC.h"

OscReceiver oscReceiver;
OscSender oscSender;
int localPort = 7000;
int remotePort = 7001;
const char* remoteIp = "192.168.6.1"; //"152.96.24.155"; //"192.168.6.1"; //"152.96.24.155";

void on_receive(oscpkt::Message* msg, void* arg)
{
	printf("on_receive (%s)\n", msg->addressPattern().c_str());
	if(msg->match("/osc-test")){
		oscSender.newMessage("/LOG").add(std::string("test")).send();
	}
}

void OSC_init(){
	oscReceiver.setup(localPort, on_receive);
	oscSender.setup(remotePort, remoteIp);
}