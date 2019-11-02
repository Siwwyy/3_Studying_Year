#include <iostream>
#include <windows.h>
#define STOPWATCH_ON	//or #define STOPWATCH_OFF
#include "StopWatch.h"

using namespace std;

void foo();

int main()
{
	//INFO
	/*StopWatch Watch;
	Watch.START();
	foo();
	Watch.STOP();
	Watch.STOP(StopWatch::SECOND);*/
	START_STOPWATCH                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	foo();
	STOP_STOPWATCH
	//STOP_STOPWATCH_CHOICE(x)
	//Watch.STOP(StopWatch::NANOSECOND);	//mozliwy wybor z trzech jednsotek czasu nano, mili oraz sekunda
	system("pause");
	return 0;
}

void foo()
{
	for (int i = 0; i < 100000; i++)
	{
		cout << '*';
	}
	cout << endl;
}