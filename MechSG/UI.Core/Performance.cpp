#include "Performance.h"

#include <Windows.h>
#include <iostream>
#include <MMSystem.h>

using namespace UI::Core;

Performance::Performance(void)
{
}

Performance::~Performance(void)
{
}

bool Performance::HasCpuSupport()
{
	INT64 frequence = 0;
	bool result = QueryPerformanceFrequency((LARGE_INTEGER*) &frequence);
	return result;
}

double Performance::GetTimeScale()
{
	if (!HasCpuSupport()) return -1;

	INT64 frequence = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*) &frequence);
	return 1.0l / (double) frequence;
}

double Performance::GetTimeInSeconds()
{
	INT64 time = 0;
	QueryPerformanceCounter((LARGE_INTEGER*) &time);
	return (double) GetTimeScale() * time;
}

float Performance::GetTime()
{
	//INT64 time = 0;
	//QueryPerformanceCounter((LARGE_INTEGER*) &time);
	//return (double) GetTimeScale() * time * 1000;
 	return (float) timeGetTime ();
}
