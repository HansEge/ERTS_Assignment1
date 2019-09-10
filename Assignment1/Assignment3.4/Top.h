#include <systemc.h>
#include "Master.h"
#include "Slave.h"


SC_MODULE(TOP)
{
	// References to modules
	Slave *mrSlave;
	Master *mrsDominatrix;

	// Constructor
	SC_CTOR(TOP);

	// Signals used to communicate between modules
	sc_signal<bool> ready;
	sc_signal<bool> valid;
	sc_signal<sc_int<DATA_BITS>> data;
	sc_signal<sc_int<ERROR_BITS>> error;
	sc_signal<sc_int<CHANNEL_BITS>> channel;

	// Clock driving modules
	sc_clock clock;

};