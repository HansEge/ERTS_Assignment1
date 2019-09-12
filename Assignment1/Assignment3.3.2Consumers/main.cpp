#include "Producer.h"
#include "Consumer.h"
#include "TCPHeader.h"
int sc_main(int argc, char* argv[]) {
	sc_fifo<TCPHeader*> channel_1(10);
	sc_fifo<TCPHeader*> channel_2(10);

	// Create producers and consumers
	Producer producer("producer");
	Consumer consumer_1("consumer_1");
	Consumer consumer_2("consumer_2");

	// Connect output of Producer to FIFO-channels.
	producer.out(channel_1);
	producer.out(channel_2);

	// Connect input of Consumers to FIFO-channels.
	consumer_1.in(channel_1);
	consumer_2.in(channel_2);

	// Simulate for 100 ms (simulation time)
  sc_start(120, SC_MS);
  return 0;
}
