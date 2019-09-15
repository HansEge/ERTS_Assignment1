#include "Slave.h"


void Slave::SlaveThread(void)
{
	// Initial state of "ready".
	ready.write(false);

	// Simulate ready going low for 3 cycles, then high for 3 cycles, etc..
	while (1)
	{
		// read new data if any valid data
		if (valid.read())
		{
			data_read = data.read();
			data_read_array[array_index] = data_read;
			array_index++;
			cout << "Slave received data: " << data_read << endl;
		}

		// Make sure that slave is ready for 3 cycles, then not ready for 3 cycles.
		if (state_counter < 3)
		{
			ready.write(true);
		}
		else
		{
			ready.write(false);
		}
		state_counter++;
		state_counter = state_counter % 6;

		wait(clk.posedge_event());
	}
};