#include "Producer.h"

sc_uint<16> SourcePort =  1;
sc_uint<16> DestinationPort = 2;
sc_uint<32> SequenceNumber = 1;
sc_uint<32> Acknowledge = 4;
sc_uint<16> StatusBits = 5;
sc_uint<16> WindowSize = 6;
sc_uint<16> Checksum = 7;
sc_uint<16> UrgentPointer = 8;
char Data[DATA_SIZE] = "Test Data";

void Producer::ProducerThread(void)
{
	TCPHeader *header;
		while (1)
	{
			header = new TCPHeader(SourcePort, DestinationPort, SequenceNumber, Acknowledge, StatusBits, WindowSize, Checksum, UrgentPointer, Data);

		
		//Write to FIFO
		for (int i = 0; i < out.size(); i++)
		{
			// Generate new TCP header.
			cout << sc_time_stamp() << ": Producing" << endl;
			header->setDestinationPort(i + 1);
			cout << "Sending: " << endl << *header << endl << endl;
			
			out[i]->write(header);
		}
		
		SequenceNumber++;
	
		// Wait for 2-10 ms.
		int waitTime = rand() % 10 + 2;
		wait(waitTime, SC_MS);
	}
}