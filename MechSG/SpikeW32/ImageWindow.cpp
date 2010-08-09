#include "ImageWindow.h"
#include "resource.h"
using namespace SpikeW32;

ImageWindow::~ImageWindow(void)
{

}

void ImageWindow::OnMousePressed( int x, int y, MouseButton mouseButton )
{
}

void ImageWindow::OnMouseReleased( int x, int y, MouseButton mouseButton )
{
}

void ImageWindow::OnMouseMove( int x, int y )
{
}

void ImageWindow::OnPaint( const HDC& hdc )
{
    TextOut (hdc, 10,10, L"Ferhat", 6);
}

void ImageWindow::OnKeyPressed( unsigned int keyCode )
{
    if (keyCode == VK_ESCAPE)
    {
        PostQuitMessage(0);
    }
}
