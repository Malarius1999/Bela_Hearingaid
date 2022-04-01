/*
 ____  _____ _        _
| __ )| ____| |      / \
|  _ \|  _| | |     / _ \
| |_) | |___| |___ / ___ \
|____/|_____|_____/_/   \_\
http://bela.io
*/
/**
\example Communication/OSC/render.cpp

Open Sound Control
------------------

This example shows an implementation of OSC (Open Sound Control) which was
developed at UC Berkeley Center for New Music and Audio Technology (CNMAT).

It is designed to be run alongside resources/osc/osc.js.
For the example to work, run in a terminal on the board
```
node /root/Bela/resources/osc/osc.js
```

In `setup()` an OSC message to address `/osc-setup`, it then waits
1 second for a reply on `/osc-setup-reply`.

After that, OSC communication takes place in the on_receive() callback,
which is called every time a new message comes in.
*/

#include <Bela.h>
#include <string>
#include <libraries/OscSender/OscSender.h>
#include <libraries/OscReceiver/OscReceiver.h>

using namespace std;

OscReceiver oscReceiver;
OscSender oscSender;
int localPort = 7000;
int remotePort = 7001;
const char* remoteIp = "192.168.6.1"; //"152.96.24.155"; //"192.168.6.1"; //"152.96.24.155";

static int led = 0;

void on_receive(oscpkt::Message* msg, void* arg)
{
	printf("on_receive (%s)\n", msg->addressPattern().c_str());
	if(msg->match("/osc-test")){
		led = !led;
		printf("%i\n", led);
		oscSender.newMessage("/LOG").add(std::string("test")).send();
		oscSender.newMessage("/led").add(led).send();
	}
}

bool setup(BelaContext *context, void *userData)
{
	printf("setup\n"); 
	oscReceiver.setup(localPort, on_receive);
	oscSender.setup(remotePort, remoteIp);
	oscSender.newMessage("/osc-setup").send();
	return true;  
}

void render(BelaContext *context, void *userData)
{
	
}

void cleanup(BelaContext *context, void *userData)
{

}
