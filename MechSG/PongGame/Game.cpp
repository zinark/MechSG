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
	Application application;
	PongWindow window (hInstance, showStyle);
	
	
	if (!window.Create()) 
	{
		MessageBox (0, "Can not create window.", "Error", MB_OK);
		return -1;
	}

	//if (!application.SetResolution(800, 600, 32))
	//{
	//	MessageBox (0, "Can not change resolution to 800x600x32.", "Error", MB_OK);
	//}
	window.Show ();
	application.Start(GameLoop(&window), 5);
}