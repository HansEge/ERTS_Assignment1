#include "Slave.h"


void Slave::SlaveThread(void)
{
	while (1)
	{
		int a = 1;
	}
}

void Slave::onClockTriggered(void)
{
	// Slave is ready in 2/3 of all time - This is an assumption.
	if (rand() % 3 == 0)
	{
		ready.write(false);
	}
	else
	{
		ready.write(true);
	}

	if (valid.read())
	{
		cout << "Slave reading data" << endl;
		cout << "Data read: " << data.read() << endl;
	}
}