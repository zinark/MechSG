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
	
	_Ball = new DynamicSprite (IDB_BALL, IDB_BALL_MASK);
	_Ball->SetVelocity(Vector2D(-1, 0));
	_Ball->SetLocation (Vector2D (200, 200));
	
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

	Rectangle (pdc, 0,0,GetWidth(), GetHeight());

	_Ball->Split (48, 48);
	int spriteIndex = Performance ().GetTime() / 100;
	_Ball->PickSubSprite (spriteIndex % 3, 0);
	_Ball->Draw(pdc);
	_Ball->Update(0.1f);

	ostringstream ostream;
	ostream << "FPS = " << fps << " FREE = " << memory  <<  "byte(s)" << endl;
	TextOut (pdc, 1,1, ostream.str().c_str(), ostream.str().length());

	if (_MouseY < 70) _MouseY = 70;
	if (_MouseY > GetHeight() - 55) _MouseY = GetHeight() - 55;
	
	Rectangle (pdc, 5, _MouseY - 50, 30, _MouseY + 50);

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
