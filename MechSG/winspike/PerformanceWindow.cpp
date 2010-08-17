#include "PerformanceWindow.h"
#include <iostream>
#include <sstream>
using namespace std;

PerformanceWindow::PerformanceWindow(const HINSTANCE& hInst, const int& showStyle)
	: AbstractWindow (hInst, showStyle)
{
	SetTitle(L"PERFORMANCE WINDOW");
	SetName(L"CPERFORMANCE");
	SetSize(640, 400);
	SetPosition(0, 0);
	_FrameCount = 0;
	_ElapsedTime = 0;
	_FpsString = L"Init...";

}

PerformanceWindow::~PerformanceWindow(void)
{
}

void PerformanceWindow::OnWindowCreated()
{
}

void PerformanceWindow::OnKeyPressed( unsigned short keyCode )
{
	if (keyCode == VK_ESCAPE)
	{
		PostQuitMessage(0);
	}
}

void PerformanceWindow::DrawScene( float deltaTime )
{
	SetTitle(_FpsString.c_str());
	_FrameCount++;
	_ElapsedTime += deltaTime;


	if (_ElapsedTime >= 1.0f)
	{
		wostringstream stream;
		stream << "FRAMECOUNT = " << _FrameCount << " Elapsed = " << _ElapsedTime;
		_FpsString = stream.str();
		_FrameCount = 0;
		_ElapsedTime = 0;
	}
}
