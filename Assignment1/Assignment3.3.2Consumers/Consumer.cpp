#include "Consumer.h"
#include "TCPHeader.h"

void Consumer :: ConsumerThread(void)
{
	const char* processName = sc_core::sc_get_current_process_b()->get_parent()->basename();
	while (1)
	{
		header = in.read();
		cout << sc_time_stamp() << " - " << processName << " received TCP Package - Sequence number: " << header.getSequenceNumber() << endl << endl;
	}
}