#include "TOP.h"


TOP::TOP(sc_module_name nm) :
	clock("clock", sc_time(20, SC_NS))
{

	mrSlave = new Slave("mrSlave");
	mrsDominatrix = new Master("mrsDominatrix");

	mrSlave->ready(ready);
	mrsDominatrix->ready(ready);

	mrSlave->valid(valid);
	mrsDominatrix->valid(valid);

	mrSlave->clk(clock);
	mrsDominatrix->clk(clock);

	mrSlave->data(data);
	mrsDominatrix->data(data);

	
	//Tracefile

	sc_trace_file *tracefile;

	tracefile = sc_create_vcd_trace_file("Avalon_filihud");
	if (!tracefile) cout << "Could not create trace file." << endl;
	tracefile->set_time_unit(1, SC_NS); // Set resolution of trace file to be in 10 US
	sc_trace(tracefile, clock, "clock");
	sc_trace(tracefile, ready, "ready");
	sc_trace(tracefile, valid, "valid");
	sc_trace(tracefile, data, "data");
	
}