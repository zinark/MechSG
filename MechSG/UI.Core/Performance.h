#pragma once

namespace UI { namespace Core {
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

}}