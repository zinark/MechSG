#include "Window.h"
#include <atlstr.h>
#include <assert.h>
using namespace SpikeW32;

Window::~Window(void)
{
}

Window::Window( const HINSTANCE& appInstanceHandle, const int& showStyle )
{
    _X = 0;
    _Y = 0;
    _Width = 800;
    _Height = 600;
    _ApplicationInstanceHandle = appInstanceHandle;
    _ShowStyle = showStyle;
}

void Window::SetTitle( const WCHAR* title )
{
    _Title = title;
}

void Window::SetName (const WCHAR* name )
{
    _Name = name;
}

void Window::SetSize( const int& width, const int& height )
{
    _Width = width;
    _Height = height;
}

bool Window::Create()
{
    WNDCLASS win;
    win.style = CS_HREDRAW | CS_VREDRAW;
    win.lpfnWndProc = MessageRouter;
    win.cbClsExtra = 0;
    win.cbWndExtra = 0;
    win.hInstance = _ApplicationInstanceHandle;
    win.hIcon = LoadIcon (_ApplicationInstanceHandle, IDI_APPLICATION); //IDI_APPLICATION MAKEINTRESOURCE (IDI_ICON1)
    win.hCursor = LoadCursor (_ApplicationInstanceHandle, IDC_ARROW);
    win.hbrBackground =  _Background;
    win.lpszClassName = _Name;
    win.lpszMenuName = 0;
    RegisterClass (&win);
    UINT style = WS_CAPTION | WS_POPUP;
    _hWnd = CreateWindow (_Name, _Title, style, _X,_Y, _Width, _Height, 0, 0, _ApplicationInstanceHandle, this);
    return (_hWnd != 0);
}

void Window::Show()
{
    ShowWindow (_hWnd, _ShowStyle);
    UpdateWindow(_hWnd);
}

void Window::SetPosition( const int& x, const int& y )
{
    _X = x;
    _Y = y;
}

LRESULT CALLBACK Window::WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    if (message == WM_DESTROY)
    {
        return 0;
    }

    if (message == WM_KEYDOWN)
    {
        OnKeyPressed(wParam);
        
        if (wParam == VK_ESCAPE)
        {
            if (MessageBox (0, L"Are you sure?", L"Exit?", MB_YESNO) == IDYES)
            {
                PostQuitMessage(0);
            }
        }
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


    return DefWindowProc (hWnd, message, wParam, lParam);
}

void Window::SetBackgroundColor( const HBRUSH& brush )
{
    _Background = brush;
}

LRESULT CALLBACK Window::MessageRouter( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    Window* window = NULL;

    if (message == WM_NCCREATE)
    {
        SetWindowLong (hWnd, GWL_USERDATA, long (((LPCREATESTRUCT) lParam)->lpCreateParams));
        
    }
    window = (Window*) (GetWindowLong (hWnd, GWL_USERDATA));
    
    if (window)
    {
        return window->WindowProcedure(hWnd, message, wParam, lParam);
    }
    else
    {
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
        
    
}