#include <stdio.h>
#include <systemc.h>
#include "ModuleSingle.h"


using namespace std;

int sc_main(int argc, char* argv[])
{
	// Create instande of ModuleSingle.
	ModuleSingle myModuleSingle("myModuleSingle");

	// Simulate for 200ms
	sc_start(200, SC_MS);
	return 0;
}

