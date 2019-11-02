#define STOPWATCH_ON
#include "StopWatch.h"

StopWatch::StopWatch():
	m_start(),
	m_stop()
{

}

void StopWatch::START()
{
	using namespace std::chrono;
	m_start = high_resolution_clock::now();
}

void StopWatch::STOP()
{
	using namespace std;
	using namespace chrono;
	m_stop = high_resolution_clock::now();
	cout << "It took me equal: " << duration_cast<nanoseconds>(m_stop - m_start).count() << " nanoseconds" << endl;
}

void StopWatch::STOP(enum StopWatch::TIME_UNIT CHOICE)
{
	using namespace std;
	using namespace chrono;
	m_stop = high_resolution_clock::now();
	cout << "It took me equal: ";
	if (CHOICE == NANOSECOND)
	{
		cout << duration_cast<nanoseconds>(m_stop - m_start).count() << " nanoseconds" << endl;
	}
	else if (CHOICE == MILLISECOND)
	{
		cout << duration_cast<milliseconds>(m_stop - m_start).count() << " miliseconds" << endl;
	}
	else if (CHOICE == SECOND)
	{
		cout << duration_cast<seconds>(m_stop - m_start).count() << " seconds" << endl;
	}
}

StopWatch::~StopWatch()
{
	
}

std::ostream & operator<<(std::ostream & lhs, const StopWatch & rhs)
{
	return lhs;
}

#undef STOPWATCH_ON