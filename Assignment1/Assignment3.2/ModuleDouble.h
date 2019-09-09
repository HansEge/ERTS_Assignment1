#pragma once
#include <systemc.h>
SC_MODULE(ModuleDouble) {

	// Events used by used by method.
	sc_event A, B, Aack, Back;

	// Bool used to keep track of method notified.
	bool next_trigger_from_A = true;

	SC_CTOR(ModuleDouble)
	{
		// Threads in module.
		SC_THREAD(Thread_A);
		SC_THREAD(Thread_B);

		// Method
		SC_METHOD(Method_A);
		// Static sensitivity used to start method. Then overwritten by dynamic sensitivity.
		sensitive << A;
		// To make sure that method isn't called when module is initialized.
		dont_initialize();
	}

	// Function prototypes.
	void Thread_A(void);
	void Thread_B(void);
	void Method_A(void);
};

