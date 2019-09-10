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

	// Connect master to fifo.
	//master->data_out(*inAdapter);

	// Connect inputs and outputs of Slave to signals.
	slave->ready(ready);
	slave->valid(valid);
	slave->clk(clock);
	slave->data(data);
	slave->error(error);
	slave->channel(channel);

	// Connect inputs and outputs of InAdapter to signals.
	master->data_out.ready(ready);
	master->data_out.valid(valid);
	master->data_out.clk(clock);
	master->data_out.data(data);
	master->data_out.error(error);
	master->data_out.channel(channel);
	master->data_out.reset(reset);

	
	//Tracefile configuration
	sc_trace_file *tracefile;
	tracefile = sc_create_vcd_trace_file("Avalon_Streaming_Bus");
	if (!tracefile) cout << "Could not create trace file." << endl;
	tracefile->set_time_unit(1, SC_NS); // Resolution of trace file = 10ns
	sc_trace(tracefile, clock, "clock");
	sc_trace(tracefile, ready, "ready");
	sc_trace(tracefile, valid, "valid");
	sc_trace(tracefile, data, "data");
	sc_trace(tracefile, error, "error");
	sc_trace(tracefile, channel, "channel");
	
}