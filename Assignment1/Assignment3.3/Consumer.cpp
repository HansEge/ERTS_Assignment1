#include "Consumer.h"
#include "TCPHeader.h"

void Consumer :: ConsumerThread(void)
{
	while (1)
	{
		// Blocking read from FIFO
		header = in.read();
		// Output timestamp and info about TCP package.
		cout << sc_time_stamp() << " - Received TCP Package - Sequence number: " << (*header).getSequenceNumber() << endl << endl;
	}
}