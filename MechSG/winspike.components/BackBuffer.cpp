#include "BackBuffer.h"


BackBuffer::BackBuffer( HWND hWnd, int width, int height )
{
	_HWnd = hWnd;
	_Width = width;
	_Height = height;
}


BackBuffer::~BackBuffer(void)
{
}
