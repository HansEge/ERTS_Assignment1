#include "ModuleDouble.h"
#include <string>
using namespace std;

void ModuleDouble::Thread_A(void)
{
	// Notifies event A every 3ms (simulation time).
	// Thread is "woken up" if Aack-event is notified.
	while (1)
	{
		A.notify();
		wait(3, SC_MS, Aack);
	}
}

void ModuleDouble::Thread_B(void)
{
	// Notifies event B every 2ms (simulation time).
	// Thread is "woken up" if Back-event is notified.
	while (1)
	{
		B.notify();
		wait(2, SC_MS, Back);
	}
}

void ModuleDouble::Method_A(void)
{
	string str;

	// Check whether the event that triggered the method was event_A og event_B.
	// Write the name of the event to the string, notify the 
	// correct acknowledge-event and set up dynamic sensitivity for the other event.
	if (next_trigger_from_A)
	{
		next_trigger_from_A = false;
		str = "A";
		Aack.notify();
		next_trigger(B);

	}
	else
	{
		next_trigger_from_A = true;
		str = "B";
		Back.notify();
		next_trigger(A);
	}

	// Print simulation time and event notified.
	cout << "Simulation time: " << sc_time_stamp() << " - Event notified: " << str << endl;
}