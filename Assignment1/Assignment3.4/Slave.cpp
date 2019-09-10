#include "Slave.h"


void Slave::SlaveThread(void)
{
	// Initial state of "ready".
	ready.write(false);

	// Simulate ready going low for 3 cycles, then high for 3 cycles, etc..
	while (1)
	{
		// Indicate that slave is not ready to receive data.
		ready.write(false);
		// Wait 3 clock cycles
		for (int i = 0; i < 3; i++)
		{
			wait();
		}

		// Indicate that slave is ready to receive data.
		ready.write(false);
		// Wait 3 clock cycles
		ready.write(true);
		for (int i = 0; i < 3; i++)
		{
			wait();
		}
	}
}