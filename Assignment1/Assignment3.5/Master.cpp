#include "Master.h"

void Master::MasterThread(void)
{
	// send the values in the array
	int i = 0;
	while(i<10)
	{
		cout << "Master writing: " << dataToSend[i] << endl;
		data_out.write(1);
		i++;
	}
}
