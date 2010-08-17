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
		lastTime = currentTime;
		_PerformanceWindow->DrawScene (deltaTime);
	}
};

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
	PerformanceWindow* performanceWindow = new PerformanceWindow (hInstance, showStyle);
	if (performanceWindow->Create())
	{
		performanceWindow->Show();
	}

	Application ().Start(OnApplicationIdleAction (performanceWindow));
}