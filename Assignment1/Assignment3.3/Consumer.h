#pragma once
#include <systemc.h>

SC_MODULE(Consumer)
{
	SC_CTOR(Consumer)
	{
		SC_THREAD(ConsumerThread);
	}

	void ConsumerThread(void);
};