#include "TCPHeader.h"

ostream & operator<<(ostream & os, const TCPHeader & trans)
{
	os << "{" << endl << " "
		<< "SourcePort: " << trans.SourcePort << endl << " "
		<< "SequenceNumber: " << trans.SequenceNumber << endl << " "
		<< "Data: " << trans.Data
		<< endl << "}";
	return os;
}

void sc_trace(sc_trace_file *& tf, const TCPHeader & trans, std::string nm)
{
	sc_trace(tf, trans.Data, nm + ".Data");
}
