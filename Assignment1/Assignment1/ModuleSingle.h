#pragma once
#include <systemc.h>
SC_MODULE(ModuleSingle) {
	// Module has an event, which is notified in the thread.
	sc_event incrementEvent;

	sc_uint<4> counter;

	SC_CTOR(ModuleSingle)
	{
		// Define process/thread
		SC_THREAD(ModuleSingleProcess);

		// Define method triggered in thread.
		SC_METHOD(ModuleSinglePrintFunction);

		// Make sure that method doesn't run when module is initialized.
		dont_initialize();

		// Set up static sensitivity.
		sensitive << incrementEvent;
	}

	// Function prototypes
	void ModuleSinglePrintFunction(void);
	void ModuleSingleProcess(void);
};

