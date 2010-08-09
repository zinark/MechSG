#include "DrawingWindow.h"
using namespace SpikeW32;

DrawingWindow::~DrawingWindow(void)
{

}

void DrawingWindow::OnMousePressed( int x, int y, MouseButton mouseButton )
{
    if (mouseButton != MouseButton::Left) return;

    _CanDrawRectangle = true;

    SetCapture (_HWnd);
    _CurrentRectangle.left = x;
    _CurrentRectangle.top = y;
    
}

void DrawingWindow::OnMouseReleased( int x, int y, MouseButton mouseButton )
{
    if (mouseButton != MouseButton::Left) return;
    
    _CanDrawRectangle = false;

    ReleaseCapture ();
    _CurrentRectangle.right = x;
    _CurrentRectangle.bottom = y;

    _Rectangles.push_back(_CurrentRectangle);
    InvalidateRect(_HWnd, NULL, false);

    
}

void DrawingWindow::OnMouseMove( int x, int y )
{
    _CurrentRectangle.right = x;
    _CurrentRectangle.bottom = y;
    InvalidateRect(_HWnd, NULL, true);
}

void DrawingWindow::OnPaint( const HDC& hdc )
{
    if (_CanDrawRectangle)
    {
        Rectangle (hdc, _CurrentRectangle.left, _CurrentRectangle.top, _CurrentRectangle.right, _CurrentRectangle.bottom);
    }

    for (int i=0; i<_Rectangles.size(); ++i)
    {
        RECT current = _Rectangles[i];
        Ellipse (hdc, current.left, current.top, current.right, current.bottom);
    }
}

void DrawingWindow::OnKeyPressed( unsigned int keyCode )
{
    if (keyCode == VK_ESCAPE)
    {
        PostQuitMessage(0);
    }
}
