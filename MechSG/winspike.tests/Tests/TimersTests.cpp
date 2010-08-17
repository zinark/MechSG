#include <gtest/gtest.h>
#include "../PerformanceTimer.h"

using namespace std;

TEST (PerformanceTimer, CpuSupport)
{
	PerformanceTimer timer;
	EXPECT_EQ (true, timer.HasCpuSupport ());
}

TEST (PerformanceTimer, TimeScale)
{
	PerformanceTimer timer;
	EXPECT_TRUE (timer.GetTimeScale () > 0);
	EXPECT_TRUE (timer.GetTimeScale () <= 1);
}

TEST (Performance, Counter)
{
	PerformanceTimer timer;
	double result = timer.GetTimeInSeconds ();
	cout << result << endl;
}