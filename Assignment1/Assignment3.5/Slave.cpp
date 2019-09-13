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
			wait(clk.posedge_event());
		}

		// Indicate that slave is ready to receive data.;
		ready.write(true);

		
		
		// Read data for 3 clock cycles, if any valid data.
		for (int i = 0; i < 3; i++)
		{
			if (valid.read())
			{
				data_read = data.read();
				data_read_array[array_index] = data_read;
				array_index++;
				cout << "Slave received data: " << data_read << endl;
			}
			wait(clk.posedge_event());
		}
	}
};