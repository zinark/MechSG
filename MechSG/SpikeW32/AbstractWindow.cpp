#include "AbstractWindow.h"
using namespace SpikeW32;

AbstractWindow::AbstractWindow( const HINSTANCE& hInst, const int& showStyle ) : AbstractCoreWindow (hInst, showStyle)
{
}

AbstractWindow::~AbstractWindow(void)
{
}

LRESULT CALLBACK AbstractWindow::WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    if (message = WM_CREATE)
    {
        OnWindowCreated ();
    }
    
    if (message == WM_DESTROY)
    {
        OnWindowDestroyed();
    }

    if (message == WM_KEYDOWN)
    {
        OnKeyPressed(wParam);
    }

    if (message == WM_LBUTTONDOWN)
    {
        int x = LOWORD (lParam);
        int y = HIWORD (lParam);
        OnMousePressed(x,y, MouseButton::Left);
        return 0;
    }

    if (message == WM_LBUTTONUP)
    {
        int x = LOWORD (lParam);
        int y = HIWORD (lParam);
        OnMouseReleased(x,y, MouseButton::Left);
        return 0;
    }

    if (message == WM_RBUTTONDOWN)
    {
        int x = LOWORD (lParam);
        int y = HIWORD (lParam);
        OnMousePressed(x,y, MouseButton::Right);
        return 0;
    }

    if (message == WM_RBUTTONUP)
    {
        int x = LOWORD (lParam);
        int y = HIWORD (lParam);
        OnMouseReleased(x,y, MouseButton::Right);
        return 0;
    }

    if (message == WM_MOUSEMOVE)
    {
        int x = LOWORD (lParam);
        int y = HIWORD (lParam);
        OnMouseMove (x,y);
        return 0;
    }

    if (message == WM_PAINT)
    {
        PAINTSTRUCT _PaintStruct;
        HDC hdc = BeginPaint(_HWnd, &_PaintStruct);
        OnPaint(hdc);
        EndPaint(_HWnd, &_PaintStruct);
    }
}

