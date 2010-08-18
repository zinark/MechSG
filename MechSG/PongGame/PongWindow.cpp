#include "PongWindow.h"
#include <sstream>
#include <iostream>
using namespace std;

PongWindow::PongWindow( const HINSTANCE& hInst, const int& showStyle ) : AbstractWindow (hInst, showStyle)
{
	SetTitle(L"Z-Pong");
	SetName (L"xZ-Pong");
	SetMouseVisible(false);
}

void PongWindow::OnWindowCreated()
{
	ToBorderless();
}

PongWindow::~PongWindow(void)
{
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

void PongWindow::Loop( int fps )
{
	HDC hdc = GetDC (GetHWnd());

	HDC pdc = CreateCompatibleDC(hdc);
	HBITMAP surface= CreateCompatibleBitmap(hdc, GetWidth(), GetHeight());
	SelectObject (pdc, surface);

	Rectangle (pdc, 0,0,GetWidth(), GetHeight());

	ostringstream ostream;
	ostream << "FPS = " << fps << endl;
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
