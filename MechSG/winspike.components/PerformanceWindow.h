#pragma once
#include <Windows.h>
#include <iostream>
#include "../UI.Core/AbstractWindow.h"

using namespace std;
using namespace UI::Core;

class PerformanceWindow : public AbstractWindow
{
private:
	wstring _FpsString;
	int _FrameCount;
	double _ElapsedTime;
public:
	PerformanceWindow(const HINSTANCE& hInst, const int& showStyle);
	~PerformanceWindow(void);
	void OnWindowCreated();
	void OnKeyPressed(unsigned short keyCode);
	void DrawScene (double deltaTime);
};

