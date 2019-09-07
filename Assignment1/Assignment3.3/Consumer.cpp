#include "Consumer.h"

void Consumer :: ConsumerThread(void)
{
	while (1)
	{
		cout << "Consuming" << endl;
		wait(10, SC_MS);
	}
}