#include "ModuleDouble.h"
#include <string>
using namespace std;

void ModuleDouble::Thread_A(void)
{
	while (1)
	{
		A.notify();
		wait(3, SC_MS, Aack);
	}
}

void ModuleDouble::Thread_B(void)
{
	while (1)
	{
		B.notify();
		wait(2, SC_MS, Back);
	}
}

void ModuleDouble::Method_A(void)
{
	string str;
	if (next_trigger_from_A)
	{
		next_trigger_from_A = false;
		str = "A";
		next_trigger(B);
		Aack.notify();
	}
	else
	{
		next_trigger_from_A = true;
		str = "B";
		next_trigger(A);
		Back.notify();
	}
	cout << "Simulation time: " << sc_time_stamp() << " - Event notified: " << str << endl;
}