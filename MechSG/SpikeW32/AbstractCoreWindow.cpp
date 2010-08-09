#include "Window.h"
#include <atlstr.h>
#include <assert.h>
using namespace SpikeW32;

AbstractCoreWindow::~AbstractCoreWindow(void)
{
}

AbstractCoreWindow::AbstractCoreWindow( const HINSTANCE& appInstanceHandle, const int& showStyle )
{
    _X = 0;
    _Y = 0;
    _Width = 800;
    _Height = 600;
    _HInstance = appInstanceHandle;
    _ShowStyle = showStyle;
}

void AbstractCoreWindow::SetTitle( const WCHAR* title )
{
    _Title = title;
}

void AbstractCoreWindow::SetName (const WCHAR* name )
{
    _Name = name;
}

void AbstractCoreWindow::SetSize( const int& width, const int& height )
{
    _Width = width;
    _Height = height;
}

bool AbstractCoreWindow::Create()
{
    WNDCLASS win;
    win.style = CS_HREDRAW | CS_VREDRAW;
    win.lpfnWndProc = MessageRouter;
    win.cbClsExtra = 0;
    win.cbWndExtra = 0;
    win.hInstance = _HInstance;
    win.hIcon = LoadIcon (_HInstance, IDI_APPLICATION); //IDI_APPLICATION MAKEINTRESOURCE (IDI_ICON1)
    win.hCursor = LoadCursor (_HInstance, IDC_ARROW);
    win.hbrBackground =  _Background;
    win.lpszClassName = _Name;
    win.lpszMenuName = 0;
    RegisterClass (&win);
    UINT style = WS_CAPTION | WS_POPUP;
    _HWnd = CreateWindow (_Name, _Title, style, _X,_Y, _Width, _Height, 0, 0, _HInstance, this);
    return (_HWnd != 0);
}

void AbstractCoreWindow::Show()
{
    ShowWindow (_HWnd, _ShowStyle);
    UpdateWindow(_HWnd);
}

void AbstractCoreWindow::SetPosition( const int& x, const int& y )
{
    _X = x;
    _Y = y;
}

void AbstractCoreWindow::SetBackgroundColor( const HBRUSH& brush )
{
    _Background = brush;
}

LRESULT CALLBACK AbstractCoreWindow::MessageRouter( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    AbstractCoreWindow* window = NULL;

    if (message == WM_NCCREATE)
    {
        SetWindowLong (hWnd, GWL_USERDATA, long (((LPCREATESTRUCT) lParam)->lpCreateParams));
    }
    window = (AbstractCoreWindow*) (GetWindowLong (hWnd, GWL_USERDATA));
    
    if (window)
    {
        window->WindowProcedure(hWnd, message, wParam, lParam);
    }
    return DefWindowProc (hWnd, message, wParam, lParam);
}