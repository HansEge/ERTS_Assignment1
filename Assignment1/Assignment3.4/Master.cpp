#include "Master.h"

void Master::MasterThread(void)
{
	while (1)
	{
		int a = 1;
	}
}

void Master::onReadyChanged(void)
{
	ready_state = ready.read();
	if (ready_state)
	{
		cout << sc_time_stamp() << "Master Ready = true." << endl;
	}
	else
	{
		cout << sc_time_stamp() << "Master Ready = false." << endl;
	}
}

void Master::onClockTriggered(void)
{
	if (ready_state)
	{
		// Ensure one clock cycle delay.
		if (delay_one_cycle)
		{
			delay_one_cycle = false;
		}
		else
		{
			if(justSentData)
			{
				valid.write(false);
				justSentData = false;
			}
			else
			{
				// Set valid to high
				valid.write(true);

				//send data
				cout << "Master sending data" << endl;
				sc_int<DATA_BITS> dataToSend = rand() % sc_int<DATA_BITS>(pow(2, DATA_BITS - 1)); // Random number between 0 and max-value
				data.write(dataToSend);

				// To ensure delay of one clock cycle after ready.
				delay_one_cycle = true;
				justSentData = true;
			}
			
		}

		
	}
}

