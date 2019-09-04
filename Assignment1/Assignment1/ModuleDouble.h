#pragma once
#include <systemc.h>
SC_MODULE(ModuleDouble) {
	sc_event A, B, Aack, Back;
	bool next_trigger_from_A = false;

	SC_CTOR(ModuleDouble)
	{
		SC_THREAD(Thread_A);
		SC_THREAD(Thread_B);

		SC_METHOD(Method_A);
		sensitive << A << B << Aack << Back;
	}
	void Thread_A(void);
	void Thread_B(void);
	void Method_A(void);
};

