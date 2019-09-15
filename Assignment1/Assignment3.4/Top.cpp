#include "TOP.h"


TOP::TOP(sc_module_name nm) :
	clock("clock", sc_time(20, SC_NS))
{
	// Create instance of Master and Slave
	mrSlave = new Slave("mrSlave");
	mrsDominatrix = new Master("mrsDominatrix");

	// Connect inputs and outputs of Master and Slave to signals.
	mrSlave->ready(ready);
	mrsDominatrix->ready(ready);

	mrSlave->valid(valid);
	mrsDominatrix->valid(valid);

	mrSlave->clk(clock);
	mrsDominatrix->clk(clock);

	mrSlave->data(data);
	mrsDominatrix->data(data);

	mrSlave->error(error);
	mrsDominatrix->error(error);

	mrSlave->channel(channel);
	mrsDominatrix->channel(channel);

	
	//Tracefile configuration
	sc_trace_file *tracefile;
	tracefile = sc_create_vcd_trace_file("Avalon_Streaming_Bus1");
	if (!tracefile) cout << "Could not create trace file." << endl;
	tracefile->set_time_unit(1, SC_NS); // Resolution of trace file = 10ns
	sc_trace(tracefile, clock, "clock");
	sc_trace(tracefile, ready, "ready");
	sc_trace(tracefile, valid, "valid");
	sc_trace(tracefile, data, "data");
	sc_trace(tracefile, error, "error");
	sc_trace(tracefile, channel, "channel");
	
}