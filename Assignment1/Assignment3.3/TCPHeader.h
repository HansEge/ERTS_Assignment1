#pragma once
#include <systemc.h>
#define PACKET_SIZE 512
#define DATA_SIZE (PACKET_SIZE-20)

class TCPHeader
{
	sc_uint<16> SourcePort;
	sc_uint<16> DestinationPort;
	sc_uint<32> SequenceNumber;
	sc_uint<32> Acknowledge;
	sc_uint<16> StatusBits;
	sc_uint<16> WindowSize;
	sc_uint<16> Checksum;
	sc_uint<16> UrgentPointer;
	char Data[DATA_SIZE];

public:

	// Empty constrtuctor
	TCPHeader()
	{

	}

	// Parametrized constructor
	TCPHeader(sc_uint<16> SourcePort, sc_uint<16> DestinationPort, sc_uint<32> SequenceNumber, sc_uint<32> Acknowledge, sc_uint<16> StatusBits, sc_uint<16> WindowSize, sc_uint<16> Checksum, sc_uint<16> UrgentPointer, char Data[DATA_SIZE])
	{
		this->SourcePort = SourcePort;
		this->DestinationPort = DestinationPort;
		this->SequenceNumber = SequenceNumber;
		this->Acknowledge = Acknowledge;
		this->StatusBits = StatusBits;
		this->WindowSize = WindowSize;
		this->Checksum = Checksum;
		this->UrgentPointer = UrgentPointer;
		strcpy(this->Data, Data);
	}

	sc_uint<32> getSequenceNumber()
	{
		return SequenceNumber;
	}

	void setSequenceNumber(sc_uint<32> sn)
	{
		SequenceNumber = sn;
	}

	// Overload of '='-operator.
	// Creates a new instance with matching attributes.
	TCPHeader& operator=(
		const TCPHeader& rhs
		)
	{
		SourcePort = rhs.SourcePort;
		DestinationPort = rhs.DestinationPort;
		SequenceNumber = rhs.SequenceNumber;
		Acknowledge = rhs.Acknowledge;
		StatusBits = rhs.StatusBits;
		WindowSize = rhs.WindowSize;
		Checksum = rhs.Checksum;
		UrgentPointer = rhs.UrgentPointer;
		strcpy(Data, rhs.Data);
		return *this;
	}
	// Overload of '=='-operator.
	// Checks if all values are the same, in which case true is returned. Otherwise false is returned.
	bool operator==(const TCPHeader& rhs)
		const {
		return SourcePort == rhs.SourcePort
			&& DestinationPort == rhs.DestinationPort
			&& SequenceNumber == rhs.SequenceNumber
			&& Acknowledge == rhs.Acknowledge
			&&StatusBits == rhs.StatusBits
			&&WindowSize == rhs.WindowSize
			&&Checksum == rhs.Checksum
			&&UrgentPointer == rhs.UrgentPointer
			&&strcmp(Data, rhs.Data);
	}


	//Definition of '<<'-operator and sc_trace.
	friend ostream& operator<<(ostream& file, const TCPHeader& trans);
	friend void sc_trace(sc_trace_file*& tf, const TCPHeader& trans, std::string nm);
};