#include <stdio.h>
#include <systemc.h>
#include "ModuleDouble.h"


using namespace std;

int sc_main(int argc, char* argv[])
{
	// Create instance of DoubleMoudle
	ModuleDouble myModuleDouble("myModuleDouble");

	// Simulate for 200ms (simulation time)
	sc_start(200, SC_MS);
	return 0;
}

