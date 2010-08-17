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

static float lastTime = 0;
PerformanceWindow* performanceWindow = 0;

class OnApplicationIdleAction : public ApplicationAction
{
public:
	void operator () ()
	{
		float currentTime = Performance ().GetTime();
		float deltaTime = (currentTime - lastTime) * 0.001f;
		lastTime = currentTime;
		performanceWindow->DrawScene (deltaTime);
	}
};

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
	performanceWindow = new PerformanceWindow (hInstance, showStyle);
	if (performanceWindow->Create())
	{
		performanceWindow->Show();
	}

	Application ().Start(OnApplicationIdleAction ());
}