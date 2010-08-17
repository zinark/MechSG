#pragma once

class Performance
{
public:
	Performance(void);
	~Performance(void);
	bool HasCpuSupport ();
	double GetTimeScale ();
	double GetTimeInSeconds ();
	float GetTime();
};

