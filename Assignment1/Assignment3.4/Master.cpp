#include "Master.h"

void Master::MasterThread(void)
{
	//Arbitrary data to send.
	dataToSend = 2;

	while (1)
	{
		// Update ready state - Will not be updated until next clock cycle.
		readyState = ready.read();

		// Check if slave is ready to receive data
		if (readyState)
		{
			// Indicate that data is being written
			valid.write(true);

			// Write data
			data.write(dataToSend);

			//Change data
			dataToSend *= 2;

			// Set channel to 1
			channel.write(1);

			// set error to 0
			error.write(0);
		}

		else
		{
			// Indicate that no data is being written
			valid.write(false);

			// Write 0 to data (only to prettify in GTK-viewer).
			data.write(0);

			// Set channel to 0
			channel.write(0);

			// set error to 1
			error.write(1);
		}

		// Wait until next clock cycle.
		wait();
	}
}
