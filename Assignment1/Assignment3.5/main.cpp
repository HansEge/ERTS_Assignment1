#include "Top.h"

int sc_main(int argc, char* argv[]) {
  TOP top("top");
  sc_start(600, SC_NS);

  cout << "Slave read data: [";
  for (int i = 0; i  < 9; i++)
  {
	  cout << top.slave->data_read_array[i] << ",";
 
  }
  cout << top.slave->data_read_array[9] << "]" << endl;

  return 0;
}
