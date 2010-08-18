#include "Application.h"
#include "Performance.h"

using namespace UI::Core;

Application::Application(void)
{
	_FPS = 0;
}


Application::~Application(void)
{
}

void Application::Start(ApplicationAction& action)
{
	Start (action, 0);
}

void UI::Core::Application::Start()
{
	MSG msg;
	ZeroMemory (&msg, sizeof(msg));
	while (GetMessage (&msg, 0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage (&msg);
	}
}

void UI::Core::Application::Start( ApplicationAction& action, int sleepTime )
{
	action.SetOwnerApplication (this);
	
	MSG msg;
	ZeroMemory (&msg, sizeof(msg));
	while (msg.message != WM_QUIT && msg.message != WM_DESTROY)
	{
		if (PeekMessage (&msg, 0,0,0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage (&msg);
		}
		else
		{
			double currentTime = _Performance.GetTimeInSeconds();
			double deltaTime = (currentTime - lastTime);
			action (); 
			lastTime = currentTime;

			++_FrameCount;
			_ElapsedTime += deltaTime;
			if (_ElapsedTime >= 1.0f)
			{
				_FPS = _FrameCount;
				_FrameCount = 0;
				_ElapsedTime = 0;
			}
			Sleep (sleepTime);
		}
	}
}

bool Application::SetResolution( int width, int height, int bpp )
{
	DEVMODE devMode;
	ZeroMemory (&devMode, sizeof(DEVMODE));
	EnumDisplaySettings (0, ENUM_CURRENT_SETTINGS, &devMode);
	devMode.dmPelsWidth = width;
	devMode.dmPelsHeight = height;
	devMode.dmBitsPerPel = bpp;
	devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

	return ChangeDisplaySettings (&devMode, CDS_FULLSCREEN) == DISP_CHANGE_SUCCESSFUL;
}
