#pragma once
#include <systemc.h>
#include "TCPHeader.h"

SC_MODULE(Consumer)
{
	sc_fifo_in <TCPHeader> in;
	TCPHeader header;
	SC_CTOR(Consumer)
	{
		SC_THREAD(ConsumerThread);
	}

	void ConsumerThread(void);
};