#pragma once
#include <Windows.h>
#include <iostream>
#include "../UI.Core/AbstractWindow.h"
#include "BackBuffer.h"

using namespace std;
using namespace UI::Core;

class PerformanceWindow : public AbstractWindow
{
private:
	wstring _FpsString;
	int _FrameCount;
	double _ElapsedTime;
	BackBuffer* _BackBuffer;
	int _MouseX, _MouseY;
	void DrawingProcedure();

public:
	PerformanceWindow(const HINSTANCE& hInst, const int& showStyle);
	~PerformanceWindow(void);
	void OnWindowCreated();
	void OnKeyPressed(unsigned short keyCode);
	void OnMouseMove(int x, int y);
	void DrawScene (double deltaTime);

	

};

