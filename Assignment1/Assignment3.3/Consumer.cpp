#include "Consumer.h"
#include "TCPHeader.h"

void Consumer :: ConsumerThread(void)
{
	while (1)
	{
		header = in.read();
		cout << sc_time_stamp() << " - Received TCP Package - Sequence number: " << header.getSequenceNumber() << endl << endl;
	}
}