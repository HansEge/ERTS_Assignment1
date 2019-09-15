#include "TOP.h"


TOP::TOP(sc_module_name nm) :
	clock("clock", sc_time(20, SC_NS))
{
	// Set reset to false
	reset.write(false);

	// Create instance of Master, Slave and InAdapter
	slave = new Slave("slave");
	master = new Master("master");
	inAdapter = new InAdapter<sc_int<DATA_BITS>>("inAdapter");

	// Connect inputs and outputs of Slave to signals.
	slave->ready(ready);
	slave->valid(valid);
	slave->clk(clock);
	slave->data(data);
	slave->error(error);
	slave->channel(channel);

	// Connect master to fifo.
	master->data_out(*inAdapter);

	inAdapter->data(data);
	inAdapter->ready(ready);
	inAdapter->valid(valid);
	inAdapter->clk(clock);
	inAdapter->error(error);
	inAdapter->channel(channel);
	inAdapter->reset(reset);

	//Tracefile configuration
	sc_trace_file *tracefile;
	tracefile = sc_create_vcd_trace_file("Avalon_Streaming_Bus");
	if (!tracefile) cout << "Could not create trace file." << endl;
	tracefile->set_time_unit(1, SC_NS); // Resolution of trace file = 1ns
	sc_trace(tracefile, clock, "clock");
	sc_trace(tracefile, ready, "ready");
	sc_trace(tracefile, valid, "valid");
	sc_trace(tracefile, data, "data");
	sc_trace(tracefile, error, "error");
	sc_trace(tracefile, channel, "channel");
	
}