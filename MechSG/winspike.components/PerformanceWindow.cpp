#include "PerformanceWindow.h"
#include <iostream>
#include <sstream>
#include <AbstractWindow.h>
#include "../winspike/resource.h"
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
	
	_FrameCount++;
	_ElapsedTime += deltaTime;

	//HDC hdc = GetDC (GetHWnd());
	//HDC panelDc = CreateCompatibleDC(hdc);

	//HBITMAP surface = CreateCompatibleBitmap(hdc, GetWidth(), GetHeight());
	//SelectObject (panelDc, surface);

	//LOGBRUSH log;
	//log.lbColor = RGB (220,200,0);
	//log.lbStyle = BS_SOLID;
	//HBRUSH mybrush = CreateBrushIndirect(&log);
	//SelectObject (panelDc, mybrush);
	//Rectangle (panelDc, 0,0,GetWidth(),GetHeight());
	//TextOut (panelDc, 10, 10, "Ferhat",6);
	//

	//
	//BitBlt (hdc, 0,0,GetWidth(), GetHeight(), panelDc, 0,0, SRCCOPY);
	//
	//ReleaseDC (GetHWnd(), panelDc);
	//ReleaseDC (GetHWnd(), hdc);

	DrawingProcedure();

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

void PerformanceWindow::DrawingProcedure()
{
	static int verticalPos;
	HDC hdc = _BackBuffer->GetDeviceContext();
	
	// CLEAN
	LOGBRUSH log;
	log.lbStyle = BS_SOLID;
	log.lbColor = RGB (90,90,90);
	HBRUSH yellowBrush = CreateBrushIndirect(&log);
	auto oldBrush = (HBRUSH) SelectObject (hdc, yellowBrush);
	Rectangle (hdc, 0,0,GetWidth(), GetHeight());
	SelectObject (hdc, oldBrush);

	HDC bgDc = CreateCompatibleDC(hdc);
	HBITMAP hBg = LoadBitmap (GetHInstance(), MAKEINTRESOURCE(IDB_BG));
	SelectObject(bgDc, hBg);
	BitBlt (hdc, 100, 100, 640,480, bgDc, 0,0, SRCCOPY);
	ReleaseDC(GetHWnd(), bgDc);
	DeleteObject (hBg);
	DeleteDC(bgDc);

	// ENTITIES
	int width = 40;
	int height= 40;
	int offset = verticalPos % 40;
	int space = 36;
	for (int i=-1; i<40; i++)
	{
		for (int j=-1; j<20; j++)
		{
			auto oldPen = SelectObject(hdc, GetStockObject(BLACK_PEN));
			//LOGBRUSH yellowLogBrush;
			//yellowLogBrush.lbStyle = BS_SOLID;
			//yellowLogBrush.lbColor= RGB (100, 100, 50);
			//HBRUSH hbr = CreateBrushIndirect (&yellowLogBrush);
			// auto oldBrush = SelectObject(hdc, hbr); 
			auto oldBrush = SelectObject(hdc, GetStockObject(WHITE_BRUSH));

			Ellipse (hdc, 
				i*width + offset + space,
				j*height + offset + space,
				i*width + offset + width, 
				j*height + offset + height);

			SelectObject(hdc, oldPen);
			SelectObject(hdc, oldBrush);
		}
	}

	// PAD
	// Rectangle (hdc, 0, verticalPos, GetWidth (), verticalPos+10);
	if (verticalPos <= GetHeight()) ++verticalPos;
	else
		verticalPos = 0;

	// SPRITE
	TextOut (hdc, 25, 10, "WEREWOLF", 8);
	HBITMAP hWolf = LoadBitmap (GetHInstance(), MAKEINTRESOURCE (IDB_WWOLF01));
	HBITMAP hWolf2 = LoadBitmap (GetHInstance(), MAKEINTRESOURCE (IDB_WWOLF02));
	HBITMAP hWolf3 = LoadBitmap (GetHInstance(), MAKEINTRESOURCE (IDB_WWOLF03));
	HDC pdc = CreateCompatibleDC(hdc);
	
	HGDIOBJ oldWolf;
	int animTime = verticalPos % 60;
	if (animTime >= 0 && animTime <=10) oldWolf = SelectObject (pdc, hWolf);
	if (animTime >= 10 && animTime <=20) oldWolf = SelectObject (pdc, hWolf2);
	if (animTime >= 20 && animTime <=30) oldWolf = SelectObject (pdc, hWolf3);
	if (animTime >= 30 && animTime <=40) oldWolf = SelectObject (pdc, hWolf3);
	if (animTime >= 40 && animTime <=50) oldWolf = SelectObject (pdc, hWolf2);
	if (animTime >= 50 && animTime <=60) oldWolf = SelectObject (pdc, hWolf);
	
	
	for (int i=0; i<6; i++)
	{
		BitBlt (hdc, 25 + i*100,25+i*100, 100, 100, pdc, 0,0, SRCCOPY);
	}
	
	SelectObject(pdc, oldWolf);
	ReleaseDC(GetHWnd(), pdc);
	DeleteObject (hWolf);
	DeleteObject (hWolf2);
	DeleteObject (hWolf3);
	DeleteDC (pdc);

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
}

