#include "Producer.h"

void Producer::ProducerThread(void)
{
	while (1)
	{
		cout << "Producing" << endl;
		wait(10, SC_MS);
	}
}