#include "PerformanceWindow.h"
#include <iostream>
#include <sstream>
#include <AbstractWindow.h>
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
	SetMouseState(false);
}

PerformanceWindow::~PerformanceWindow(void)
{
	delete _BackBuffer;
}

void PerformanceWindow::OnWindowCreated()
{
	_BackBuffer = new BackBuffer (_HWnd, GetWidth(), GetHeight());
}

void PerformanceWindow::OnKeyPressed( unsigned short keyCode )
{
	if (keyCode == VK_ESCAPE)
	{
		PostQuitMessage(0);
	}
}

void PerformanceWindow::DrawScene( double deltaTime )
{
	static int verticalPos;
	_FrameCount++;
	_ElapsedTime += deltaTime;

	HDC hdc = _BackBuffer->GetDeviceContext();
	// CLEAN
	Rectangle (hdc, 0,0,GetWidth(), GetHeight());

	// ENTITIES
	int width = 40;
	int height= 40;
	int offset = verticalPos % 40;

	for (int i=-1; i<40; i++)
	{
		for (int j=-1; j<20; j++)
		{
			auto oldPen = SelectObject(hdc, GetStockObject(WHITE_PEN));
			auto oldBrush = SelectObject(hdc, GetStockObject(BLACK_BRUSH));

			Rectangle (hdc, 
				i*width + offset,
				j*height + offset,
				i*width + offset + width, 
				j*height + offset + height);
			
			SelectObject(hdc, oldPen);
			SelectObject(hdc, oldBrush);
		}
	}

	// PAD
	Rectangle (hdc, 0, verticalPos, GetWidth (), verticalPos+10);
	if (verticalPos <= GetHeight()) ++verticalPos;
	else
		verticalPos = 0;

	// CURSOR
	int range = 10;
	Ellipse (hdc, _MouseX-range, _MouseY-range,_MouseX+range, _MouseY+range );
	int quantity = 5;
	for (int i= -quantity; i <= quantity; i++)
	{
		int sx = i*5 + _FrameCount % quantity, 
			sy = i*5 + _FrameCount % quantity;
		Ellipse (hdc, 
			_MouseX-2+sx, _MouseY-2+sy,
			_MouseX+2+sx, _MouseY+2+sy);
		sx = -sx;

		Ellipse (hdc, 
			_MouseX-2+sx, _MouseY-2+sy,
			_MouseX+2+sx, _MouseY+2+sy);
	}

	Ellipse (hdc, _MouseX-4, _MouseY-4,_MouseX+4, _MouseY+4 );

	_BackBuffer->Draw();

	if (_ElapsedTime >= 1.0f)
	{
		wostringstream stream;
		stream << "FRAMECOUNT = " << _FrameCount << " Elapsed = " << _ElapsedTime;
		_FpsString = stream.str();
		_FrameCount = 0;
		_ElapsedTime = 0;
	}

	SetTitle(_FpsString.c_str());
}

void PerformanceWindow::OnMouseMove( int x, int y )
{
	_MouseX = x;
	_MouseY = y;
}

