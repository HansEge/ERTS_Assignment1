#pragma once
#include <systemc.h>
SC_MODULE(ModuleSingle) {
	sc_event incrementEvent;

	sc_uint<4> counter;

	SC_CTOR(ModuleSingle)
	{
		SC_THREAD(ModuleSingleProcess);

		SC_METHOD(ModuleSinglePrintFunction);
		sensitive << incrementEvent;
	}
	void ModuleSinglePrintFunction(void);
	void ModuleSingleProcess(void);
};

