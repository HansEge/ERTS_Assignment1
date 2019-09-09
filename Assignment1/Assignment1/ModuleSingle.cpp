#include "ModuleSingle.h"

void ModuleSingle::ModuleSinglePrintFunction(void)
{
	// Increment counter
	counter++;

	// Print simulation time and counter value
	cout << "Simulation time: " << sc_time_stamp() << " - Counter value:" << counter << endl;
}

void ModuleSingle::ModuleSingleProcess(void)
{
	// Set start value for counter.
	counter = 0;

	// While 1 to ensure continuity
	while (1)
	{
		// Notify event
		incrementEvent.notify();

		// Wait for 2 MS (simulation time)
		wait(2,SC_MS);
	}
}