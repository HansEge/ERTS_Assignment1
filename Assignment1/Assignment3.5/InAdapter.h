#pragma once
#define CHANNEL_BITS 4 // Number of channel wires
#define ERROR_BITS 2 // Number of error wires
#define DATA_BITS 16 // Number of data wires
#define MAX_CHANNEL 2 // Maximum number of channels actual used
#define CLK_PERIODE 20 // ns
template <class T>
class InAdapter : public sc_fifo_out_if <T>, public sc_module
{
public:
	// Clock and reset
	sc_in_clk clk; // Clock
	sc_in<bool> reset; // Reset

	// Handshake ports for ST bus
	sc_in<bool> ready; // Ready signal
	sc_out<bool> valid; // Valid signal

	// Channel, error and data ports ST bus
	sc_out<sc_int<CHANNEL_BITS> > channel;
	sc_out<sc_int<ERROR_BITS> > error;
	sc_out<sc_int<DATA_BITS> > data;
	
	void write(const T & value)
	{
		cout << "InAdapter: write(" << value << ")" << endl;

		// If 'reset' is high, just wait.
		if (reset == false)
		{
			// Output sample data on negative edge of clock

			// Wait until ready is high
			while (ready == false)
				wait(clk.posedge_event());

			// Wait 1 clock cycle to simulate 1 clock cycle delay.
			// wait(clk.posedge_event());

			// Write "high" to valid, indicating that data is being written.
			valid.write(true);

			// Write data
			data.write(value);

			// Write channel and error info
			channel.write(0); // Channel number
			error.write(0); // Error
			
			// Wait one clock cycle, then indicate that data is not being written anymore
			wait(clk.posedge_event());
			valid.write(false);
		}
		else wait(clk.posedge_event());
	}
	InAdapter(sc_module_name name_)
		: sc_module(name_)
	{ }
private:
	bool nb_write(const T & data)
	{
		SC_REPORT_FATAL("/InAdapter", "Called nb_write()");
		return false;
	}
	virtual int num_free() const
	{
		SC_REPORT_FATAL("/InAdapter", "Called num_free()");
		return 0;
	}
	virtual const sc_event& data_read_event() const
	{
		SC_REPORT_FATAL("/InAdapter", "Called data_read_event()");
		return *new sc_event;
	}
};