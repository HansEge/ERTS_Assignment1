#pragma once
#include <systemc.h>

#define CHANNEL_BITS 4 // Number of channel wires
#define ERROR_BITS 2 // Number of error wires
#define DATA_BITS 16 // Number of data wires
#define MAX_CHANNEL 2 // Maximum number of channels actual used
#define CLK_PERIODE 20 // ns

SC_MODULE(Master)
{
	sc_in_clk clk;

	sc_in<bool> ready;

	sc_out<bool> valid;
	sc_out <sc_int<DATA_BITS>> data;
	/*
	sc_out <sc_int<ERROR_BITS>> error;
	sc_out <sc_int<CHANNEL_BITS>> channel;*/

	bool ready_state = false;
	bool valid_state = true;

	bool delay_one_cycle = true;

	bool justSentData = false;

	SC_CTOR(Master)
	{
		//SC_THREAD(MasterThread);

		SC_METHOD(onReadyChanged);
		sensitive << ready;

		SC_METHOD(onClockTriggered);
		sensitive << clk.pos();
	}

	void MasterThread(void);
	void onReadyChanged(void);
	void onClockTriggered(void);
};