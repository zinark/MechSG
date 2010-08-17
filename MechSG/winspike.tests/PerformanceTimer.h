#pragma once

class PerformanceTimer
{
public:
	PerformanceTimer(void);
	~PerformanceTimer(void);
	bool HasCpuSupport ();
	double GetTimeScale ();
	double GetTimeInSeconds ();
};

