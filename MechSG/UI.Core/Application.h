#pragma once
#include <Windows.h>
#include "ApplicationAction.h"
#include "Performance.h"

namespace UI { namespace Core
{
	class ApplicationAction;

	class Application
	{
	private:
		float _ExpectedFps;
		int _Fps;
		double lastTime;
		int _FrameCount;
		double _ElapsedTime;
		Performance _Performance;
		

	public:
		Application(void);
		~Application(void);
		void Start (ApplicationAction& action);
		void Start (ApplicationAction& action, int sleepTime);
		void Start ();
		bool SetResolution (int width, int height, int bpp);
		int GetFPS () { return _Fps;}
		void SetExpectedFps (int fps) { _ExpectedFps = fps; }
	};
}}