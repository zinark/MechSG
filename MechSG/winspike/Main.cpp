#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include "DialogEnterText.h"
#include "DialogTestRadios.h"
#include "DialogComboBox.h"
#include "PerformanceWindow.h"
#include <Application.h>
#include "Performance.h"
#include "BackBuffer.h"
using namespace std;

class DialogFacade
{
public:
	void Start (HINSTANCE hInstance, int show)
	{
		DialogEnterText ().Start (hInstance, show);
		DialogTestRadios ().Start (hInstance, show);
		DialogComboBox ().Start (hInstance, show);
	}
};


class OnApplicationIdleAction : public ApplicationAction
{
private:
	double lastTime;
	PerformanceWindow* _PerformanceWindow;

public:
	OnApplicationIdleAction (PerformanceWindow* performanceWindow)
	{
		lastTime = 0;
		_PerformanceWindow = performanceWindow;
	}

	void operator () ()
	{
		double currentTime = Performance ().GetTimeInSeconds();
		double deltaTime = (currentTime - lastTime);
		_PerformanceWindow->DrawScene (deltaTime);
		lastTime = currentTime;
		Sleep (20);
	}
};

bool ChangeResolution(int width, int height, int bpp) 
{
	DEVMODE devMode;
	ZeroMemory (&devMode, sizeof(DEVMODE));
	EnumDisplaySettings (0, ENUM_CURRENT_SETTINGS, &devMode);

	ostringstream stream;
	stream << "Frequency : " << devMode.dmDisplayFrequency << endl;
	stream << "DeviceName : " << devMode.dmDeviceName << endl;
	stream << "Width : " << devMode.dmPelsWidth << endl;
	stream << "Height : " << devMode.dmPelsHeight << endl;

	devMode.dmPelsWidth = width;
	devMode.dmPelsHeight = height;
	devMode.dmBitsPerPel = bpp;
	devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;
	if (ChangeDisplaySettings (&devMode, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
	{
		// MessageBox (0, stream.str().c_str(), "DEVMODE", MB_OK);		
		MessageBox (0, "Resolution error.", "Error", MB_OK);
		return false;
	}
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
	if (!ChangeResolution(800, 600, 32 )) return -1;

	PerformanceWindow* performanceWindow = new PerformanceWindow (hInstance, showStyle);
	performanceWindow->SetSize(800, 600);
	
	if (performanceWindow->Create())
	{
		performanceWindow->ToFullScreen();
		performanceWindow->Show();
		
	}
	SetCapture (performanceWindow->GetHWnd());
	// MoveWindow(performanceWindow->GetHWnd(), 0,0,800,600, true);
	
	Application ().Start(OnApplicationIdleAction (performanceWindow));
}