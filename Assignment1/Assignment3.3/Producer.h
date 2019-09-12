#pragma once
#include <systemc.h>
#include "TCPHeader.h"

SC_MODULE(Producer)
{
	sc_fifo_out <TCPHeader*> out;
	SC_CTOR(Producer)
	{
		SC_THREAD(ProducerThread);
	}

	void ProducerThread(void);
};