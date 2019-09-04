#include "ModuleSingle.h"

void ModuleSingle::ModuleSinglePrintFunction(void)
{
	counter++;
	cout << "Simulation time: " << sc_time_stamp() << " - Counter value:" << counter << endl;
}

void ModuleSingle::ModuleSingleProcess(void)
{
	while (1)
	{
		incrementEvent.notify();
		wait(2,SC_MS);
	}
}