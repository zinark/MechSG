#pragma once
#include <Windows.h>
class BackBuffer
{
public:
	BackBuffer(HWND hWnd, int width, int height);
	~BackBuffer(void);
	HDC& GetDeviceContext ();
	void Draw ();

private:
	int _Width;
	int _Height;
	HWND _HWnd;
	HDC _HDC;
	
	HBITMAP _Surface;
	HBITMAP _OldSurface;
};

