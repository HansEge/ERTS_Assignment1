#include "Producer.h"
#include "Consumer.h"
#include "TCPHeader.h"
int sc_main(int argc, char* argv[]) {
	sc_fifo<TCPHeader*> channel(10);

	Producer producer("producer");
	producer.out(channel);
	Consumer consumer("consumer");
	consumer.in(channel);
  sc_start(500, SC_MS);
  return 0;
}
