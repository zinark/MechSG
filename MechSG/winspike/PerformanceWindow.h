#pragma once
#include <Windows.h>
#include "AbstractWindow.h"
#include <iostream>
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

