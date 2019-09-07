#include "Producer.h"
#include "Consumer.h"
int sc_main(int argc, char* argv[]) {
	Producer producer("producer");
	Consumer consumer("consumer");
  sc_start(100, SC_MS);
  return 0;
}
