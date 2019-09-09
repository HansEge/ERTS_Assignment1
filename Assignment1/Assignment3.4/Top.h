#include <systemc.h>
#include "Master.h"
#include "Slave.h"


SC_MODULE(TOP)
{

	Slave *mrSlave;
	Master *mrsDominatrix;

	SC_CTOR(TOP);

	sc_signal<bool> ready;
	sc_signal<bool> valid;
	sc_signal<sc_int<DATA_BITS>> data;

	/*
	sc_signal<sc_int<ERROR_BITS>> error;
	sc_signal<sc_int<CHANNEL_BITS>> channel;
	*/

	sc_clock clock;

};