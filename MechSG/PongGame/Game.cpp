#include <Windows.h>
#include <Application.h>
#include "PongWindow.h"
#include "MemoryStatus.h"
using namespace UI::Core;

class GameLoop : public ApplicationAction
{
private:
	PongWindow* _PongWindow;
	MemoryStatus memoryStatus;
	
public:
	GameLoop (PongWindow* pongWindow)
	{
		_PongWindow = pongWindow;
	}
	
	void operator () () 
	{
		double fps = GetOwnerApplication()->GetFPS();
		_PongWindow->Loop (fps, memoryStatus.GetFreeMemory ());
	}
};

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS );
	
	Application application;
	PongWindow window (hInstance, showStyle);
	window.SetSize(800,600);
	
	if (!application.SetResolution(800, 600, 32))
	{
		MessageBox (0, "Can not change resolution to 640X480.", "Error", MB_OK);
	}

	if (!window.Create()) 
	{
		MessageBox (0, "Can not create window.", "Error", MB_OK);
		return -1;
	}

	window.Show ();
	SetCapture (window.GetHWnd());
	application.Start(GameLoop(&window));
}