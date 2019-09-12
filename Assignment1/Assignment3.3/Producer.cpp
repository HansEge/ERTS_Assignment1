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
		// Generate new TCP header.
		header = new TCPHeader(SourcePort, DestinationPort, SequenceNumber, Acknowledge, StatusBits, WindowSize, Checksum, UrgentPointer, Data);
		cout << sc_time_stamp() << ": Producing" << endl;
		cout << "Sending: " << endl << *header << endl << endl;
		
		//Write to FIFO
		out.write(header);
		
		// Increment sequence number.
		SequenceNumber++;
	
		// Wait for 2-10 ms.
		int waitTime = rand() % 10 + 2;
		wait(waitTime, SC_MS);
	}
}