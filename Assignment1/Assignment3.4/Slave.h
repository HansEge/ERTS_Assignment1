#pragma once
#include <systemc.h>

#define CHANNEL_BITS 4 // Number of channel wires
#define ERROR_BITS 2 // Number of error wires
#define DATA_BITS 16 // Number of data wires
#define MAX_CHANNEL 2 // Maximum number of channels actual used
#define CLK_PERIODE 20 // ns

SC_MODULE(Slave)
{
	sc_in_clk clk;

	// Outputs
	sc_out<bool> ready;

	// Inputs
	sc_in<bool> valid;
	sc_in <sc_int<DATA_BITS>> data;
	sc_in <sc_int<ERROR_BITS>> error;
	sc_in <sc_int<CHANNEL_BITS>> channel;

	// Used for printing to .txt
	int state_counter = 0;
	int array_index = 0;
	sc_int<16> test_data = 0;
	sc_int<16> test_data_array[10] = { 0 };

	/*
	sc_in <sc_int<DATA_BITS>> data_read_array[10];
	sc_in <sc_int<DATA_BITS>> data_read;
	*/
	
	// Constructor
	SC_CTOR(Slave)
	{
		// Create a single thread, that triggers on the clock going positive.
		SC_THREAD(SlaveThread);
		sensitive << clk.pos();
		dont_initialize();
	}

	void SlaveThread(void);
};