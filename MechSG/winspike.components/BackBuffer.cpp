#include "BackBuffer.h"


BackBuffer::BackBuffer( HWND hWnd, int width, int height )
{
	_HWnd = hWnd;
	_Width = width;
	_Height = height;

	HDC hdc = GetDC (_HWnd);
	_HDC = CreateCompatibleDC(hdc);
	_Surface = CreateCompatibleBitmap(hdc, width, height);
	_OldSurface = (HBITMAP) SelectObject (_HDC, _Surface);
	ReleaseDC (_HWnd, hdc);

	LOGBRUSH log;
	log.lbColor = RGB (90,40,50);
	log.lbStyle = BS_SOLID;
	HBRUSH mybrush = CreateBrushIndirect(&log);
	
	HBRUSH oldBrush = (HBRUSH) SelectObject(_HDC, mybrush);
	Rectangle (_HDC, 0,0, _Width, _Height);
	
	
	SelectObject (_HDC, oldBrush);
}


BackBuffer::~BackBuffer(void)
{
	SelectObject (_HDC, _OldSurface);
	DeleteObject (_Surface);
	DeleteDC (_HDC);
}

void BackBuffer::Draw()
{
	HDC hdc = GetDC (_HWnd);
	BitBlt (hdc, 0,0,_Width, _Height, _HDC, 0,0, SRCCOPY);
	ReleaseDC (_HWnd, hdc);
}

HDC& BackBuffer::GetDeviceContext()
{
	return _HDC;
}
