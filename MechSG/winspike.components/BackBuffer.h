#pragma once
#include <Windows.h>
class BackBuffer
{
public:
	BackBuffer(HWND hWnd, int width, int height);
	~BackBuffer(void);

private:
	int _Width;
	int _Height;
	HWND _HWnd;
};

