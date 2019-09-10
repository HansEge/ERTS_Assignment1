#pragma once
#include <systemc.h>

#define CHANNEL_BITS 4 // Number of channel wires
#define ERROR_BITS 2 // Number of error wires
#define DATA_BITS 16 // Number of data wires
#define MAX_CHANNEL 2 // Maximum number of channels actual used
#define CLK_PERIODE 20 // ns

SC_MODULE(Master)
{
	sc_int<DATA_BITS> dataToSend;
	bool readyState; // Used to simulate the 1 cycle delay from ready changes until master reacts to this.

	sc_in_clk clk;

	// Inputs
	sc_in<bool> ready;

	// Outputs
	sc_out<bool> valid;
	sc_out <sc_int<DATA_BITS>> data;
	sc_out <sc_int<ERROR_BITS>> error;
	sc_out <sc_int<CHANNEL_BITS>> channel;

	// Constructor
	SC_CTOR(Master)
	{
		// A single thread, , that triggers on the clock going positive.
		SC_THREAD(MasterThread);
		sensitive << clk.pos();
		dont_initialize();
	}

	void MasterThread(void);
};