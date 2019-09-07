#pragma once
#include <systemc.h>

SC_MODULE(Producer)
{
	SC_CTOR(Producer)
	{
		SC_THREAD(ProducerThread);
	}

	void ProducerThread(void);
};