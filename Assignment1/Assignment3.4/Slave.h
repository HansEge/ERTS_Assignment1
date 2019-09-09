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
	sc_out<bool> ready;

	sc_in<bool> valid;
	sc_in <sc_int<DATA_BITS>> data;
	/*
	sc_in <sc_int<ERROR_BITS>> error;
	sc_in <sc_int<CHANNEL_BITS>> channel;
	*/

	SC_CTOR(Slave)
	{
		//SC_THREAD(SlaveThread);
		SC_METHOD(onClockTriggered);
		sensitive << clk.pos();
	}

	void SlaveThread(void);
	void onClockTriggered(void);
};