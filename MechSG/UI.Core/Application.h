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
		int _FPS;
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
		int GetFPS () { return _FPS;}
	};
}}