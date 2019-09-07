#include "Producer.h"
#include "Consumer.h"
#include "TCPHeader.h"
int sc_main(int argc, char* argv[]) {
	sc_fifo<TCPHeader> channel_1(10);
	sc_fifo<TCPHeader> channel_2(10);

	Producer producer("producer");
	Consumer consumer_1("consumer_1");
	Consumer consumer_2("consumer_2");
	producer.out(channel_1);
	producer.out(channel_2);

	consumer_1.in(channel_1);
	consumer_2.in(channel_2);
  sc_start(100, SC_MS);
  return 0;
}
