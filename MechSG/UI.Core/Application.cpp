#include "Application.h"

using namespace UI::Core;

Application::Application(void)
{
}


Application::~Application(void)
{
}

void Application::Start(ApplicationAction& action)
{
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
			action ();
		}
	}
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
