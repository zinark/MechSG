#include "AbstractWindow.h"
using namespace UI::Core;

AbstractWindow::AbstractWindow( const HINSTANCE& hInst, const int& showStyle ) : AbstractCoreWindow (hInst, showStyle)
{
    // _CallbackRegistry.Register (WM_NCCREATE, OnWindowCreated);
}

AbstractWindow::~AbstractWindow(void)
{
}

LRESULT CALLBACK AbstractWindow::WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    // _CallbackRegistry.Check (hWnd, message, wParam, lParam);
    
	if (message == WM_NCCREATE)
    {
		_HWnd = hWnd;
		OnWindowCreated();
        return DefWindowProc (hWnd, message, wParam, lParam);
    }

    if (message == WM_DESTROY)
    {
        OnWindowDestroyed();
        return 0;
    }

    if (message == WM_KEYDOWN)
    {
        OnKeyPressed(wParam);
        return 0;
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
        HDC hdc = BeginPaint(_HWnd, &_PaintStruct);
        OnPaint(hdc);
        EndPaint(_HWnd, &_PaintStruct);
        return 0;
    }

    if (message == WM_COMMAND)
    {
        OnMenuCommand (LOWORD (wParam));
        return 0;
    }

    if (message == WM_CLOSE)
    {
        OnWindowClose ();
        return 0;
    }

    return DefWindowProc (hWnd, message, wParam, lParam);
}


void AbstractWindow::RePaint( const bool& drawBackground )
{
    InvalidateRect(_HWnd, 0, drawBackground );
}
