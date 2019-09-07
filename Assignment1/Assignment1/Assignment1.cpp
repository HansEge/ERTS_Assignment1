#include <stdio.h>
#include <systemc.h>
#include "ModuleSingle.h"


using namespace std;

int sc_main(int argc, char* argv[])
{
	ModuleSingle myModuleSingle("myModuleSingle");
	sc_start(200, SC_MS);
	return 0;
}

