#include "Slave.h"
#include <fstream>


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
			test_data = data.read();
			test_data_array[array_index] = test_data;
			array_index++;
			cout << "Slave received data: " << test_data << endl;

			// Print the first 10 numbers recieved by the slave to a text file
			if (test_data_array[9] != 0)
			{
				ofstream myfile("Slave_data.txt");
				if (myfile.is_open())
				{
					for (int i = 0; i <= 9; i++)
					{
						myfile << test_data_array[i] << "\n";
					}
					
					myfile.close();
					
				}
				else cout << "Unable to open file";
			}
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
}