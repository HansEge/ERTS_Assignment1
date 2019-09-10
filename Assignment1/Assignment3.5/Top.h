#include <systemc.h>
#include "Master.h"
#include "Slave.h"
#include "InAdapter.h"


SC_MODULE(TOP)
{
	// References to modules
	Slave *slave;
	Master *master;
	InAdapter<sc_int<DATA_BITS>> *inAdapter;


	// Constructor
	SC_CTOR(TOP);

	// Signals used to communicate between modules
	sc_fifo<sc_int<DATA_BITS>> fifo_channel;

	sc_signal<bool> ready;
	sc_signal<bool> valid;
	sc_signal<sc_int<DATA_BITS>> data;
	sc_signal<sc_int<ERROR_BITS>> error;
	sc_signal<sc_int<CHANNEL_BITS>> channel;

	// Clock driving modules
	sc_clock clock;

	// Reset signal
	sc_signal<bool> reset;

};