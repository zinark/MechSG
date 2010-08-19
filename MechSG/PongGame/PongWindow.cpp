#include "PongWindow.h"
#include <sstream>
#include <iostream>
#include <Sprite.h>
#include "resource.h"
#include <Performance.h>
using namespace std;
using namespace UI::Core;

PongWindow::PongWindow( const HINSTANCE& hInst, const int& showStyle ) : AbstractWindow (hInst, showStyle)
{
	SetTitle(L"Z-Pong");
	SetName (L"xZ-Pong");
	SetMouseVisible(false);
	
	_Ball = new DynamicSprite (IDB_COINS, IDB_COINS_MASK);
	_Ball->SetVelocity(Vector2D(-10, -5));
	_Ball->SetLocation (Vector2D (GetWidth() / 2, GetHeight() / 2));
	_Ball->Split (64, 64);
	_CPUPadY = GetHeight() / 2;
	_CpuScore = 0;
	_PlayerScore = 0;
}

void PongWindow::OnWindowCreated()
{
	ToBorderless();
}

PongWindow::~PongWindow(void)
{
	delete _Ball;
}


void PongWindow::OnKeyPressed( unsigned short keyCode )
{
	if (keyCode == VK_ESCAPE)
	{
		if (MessageBox (GetHWnd(), "Do you really want to quit?", "Quit", MB_YESNO) == IDYES)
		{
			DestroyWindow(GetHWnd());
			PostQuitMessage(0);
		}
	}
}

void PongWindow::Loop( int fps, unsigned int memory )
{
	HDC hdc = GetDC (GetHWnd());
	HDC pdc = CreateCompatibleDC(hdc);
	
	HBITMAP surface= CreateCompatibleBitmap(hdc, GetWidth(), GetHeight());
	SelectObject (pdc, surface);

	LOGBRUSH bgBr;
	bgBr.lbStyle = BS_SOLID;
	bgBr.lbColor = RGB (90,80,95);
	HBRUSH bg = CreateBrushIndirect(&bgBr);
	auto oldBrush = SelectObject (pdc, bg);
	Rectangle (pdc, 0,0,GetWidth(), GetHeight());
	Rectangle (pdc, GetWidth()/2 -2 ,0,GetWidth()/2 +2, GetHeight());
	SelectObject (pdc, oldBrush);
	DeleteObject (bg);
	// PAD
	if (_MouseY < 70) _MouseY = 70;
	if (_MouseY > GetHeight() - 55) _MouseY = GetHeight() - 55;

	int spriteIndex = Performance ().GetTime() / 100;

	// BALL 
	_Ball->PickSubSprite (spriteIndex % 8, 0);
	_Ball->Update(1.0f);
	_Ball->Draw(pdc);

	// PLAYER PAD
	Rectangle (pdc, 5, _MouseY - 50, 30, _MouseY + 50);
	// CPU PAD
	Rectangle (pdc, GetWidth() - 30, _CPUPadY - 50, GetWidth()-5, _CPUPadY + 50);


	// Bounce X
	if (_Ball->GetLocation().GetX() <= 0 || _Ball->GetLocation().GetX() >= GetWidth() - _Ball->GetWidth())
	{
		Vector2D reversedVelocity = _Ball->GetVelocity() * Vector2D(-1,1);
		_Ball->SetVelocity(reversedVelocity);
	}
	// Bounce Y
	if (_Ball->GetLocation().GetY() <= 0 || _Ball->GetLocation().GetY() >= GetHeight() - _Ball->GetHeight())
	{
		Vector2D reversedVelocity = _Ball->GetVelocity() * Vector2D(1,-1);
		_Ball->SetVelocity(reversedVelocity);
	}

	bool cpuMakesScore = 
		(_Ball->GetVelocity().GetX() < 0) &&
		(_Ball->GetLocation().GetX() <= 30) &&
		(_Ball->GetLocation().GetY() < _MouseY - 50 - _Ball->GetHeight() || _Ball->GetLocation().GetY() > _MouseY + 50);
	
	if (cpuMakesScore)
	{
		++_CpuScore;
		_Ball->SetLocation(Vector2D (GetWidth()/2, GetHeight()/2));
		
		int sx = (rand() % 5) + 5;
		int sy = (rand() % 5) + 5;
		int signSx = (rand() % 2);
		int signSy = (rand() % 2);
		if (signSx == 1) sx = -sx;
		if (signSy == 1) sy = -sy;

		_Ball->SetVelocity(Vector2D(sx, sy));
	}

	
	// Collision with Pad
	bool collided = 
		(_Ball->GetVelocity().GetX() < 0) &&
		(_Ball->GetLocation().GetX() <= 30) &&
		(_Ball->GetLocation().GetY() > _MouseY - 50 - _Ball->GetHeight()) &&
		(_Ball->GetLocation().GetY() < _MouseY + 50);

	
	if (collided)
	{
		Vector2D reversed  = _Ball->GetVelocity() * Vector2D(-1,1);
		_Ball->SetVelocity(reversed);
		Vector2D newPos = Vector2D (31, _Ball->GetLocation().GetY());
		_Ball->SetLocation(newPos);
		TextOut (pdc,0,GetHeight()-50, "PONG", 4);
		collided = false;
	}

	// AI
	bool canCpuPlay = _Ball->GetLocation ().GetX() >= GetWidth() / 2;
	if (canCpuPlay)
	{
		_CPUPadY = _Ball->GetLocation().GetY();
	}

	ostringstream ostream;
	// ostream << "FPS = " << fps << " FREE = " << memory / 1024  <<  "KB(s)" << endl;
	ostream << "PLAYER = " << _PlayerScore << " CPU = " << _CpuScore <<  endl;
	TextOut (pdc, 1,1, ostream.str().c_str(), ostream.str().length());


	BitBlt (hdc, 0,0, GetWidth(), GetHeight(), pdc, 0,0, SRCCOPY);

	ReleaseDC(GetHWnd(), hdc);
	DeleteDC (hdc);

	ReleaseDC(GetHWnd(), pdc);
	DeleteDC (pdc);

	DeleteObject (surface);
}

void PongWindow::OnMouseMove( int x, int y )
{
	_MouseX = x;
	_MouseY = y;
}
