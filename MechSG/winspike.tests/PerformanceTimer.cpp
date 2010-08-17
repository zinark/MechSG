#include "PerformanceTimer.h"

#include <Windows.h>
#include <iostream>
#include <MMSystem.h>

PerformanceTimer::PerformanceTimer(void)
{
}

PerformanceTimer::~PerformanceTimer(void)
{
}

bool PerformanceTimer::HasCpuSupport()
{
	INT64 frequence = 0;
	bool result = QueryPerformanceFrequency((LARGE_INTEGER*) &frequence);
	return result;
}

double PerformanceTimer::GetTimeScale()
{
	if (!HasCpuSupport()) return -1;
	
	INT64 frequence = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*) &frequence);
	return 1.0l / (double) frequence;
}

double PerformanceTimer::GetTimeInSeconds()
{
	INT64 time = 0;
	QueryPerformanceCounter((LARGE_INTEGER*) &time);
	return (double) GetTimeScale() * time;
}
