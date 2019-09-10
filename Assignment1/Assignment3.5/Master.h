#pragma once
#include <systemc.h>
#include "InAdapter.h"

#define CHANNEL_BITS 4 // Number of channel wires
#define ERROR_BITS 2 // Number of error wires
#define DATA_BITS 16 // Number of data wires
#define MAX_CHANNEL 2 // Maximum number of channels actual used
#define CLK_PERIODE 20 // ns

SC_MODULE(Master)
{
	// Instantiate data to send
	sc_int<DATA_BITS> dataToSend[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	// Create output FIFO
	InAdapter<sc_int<DATA_BITS>> data_out;

	// Constructor
	SC_CTOR(Master):data_out("data_out")
	{
		// A single thread, , that triggers on the clock going positive.
		SC_THREAD(MasterThread);
	}

	void MasterThread(void);
};