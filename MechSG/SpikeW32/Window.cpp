#include "Window.h"
#include <atlstr.h>
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
    _WindowHandle = CreateWindow (_Name, _Title, style, _X,_Y, _Width, _Height, 0, 0, _ApplicationInstanceHandle, 0);
    return (_WindowHandle != 0);
}

void Window::Show()
{
    ShowWindow (_WindowHandle, _ShowStyle);
    UpdateWindow(_WindowHandle);
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
        //CString str;
        //str.Format(L"HWND = %s");
        //MessageBox (hWnd, str, L"Message", MB_OK);
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
        window = reinterpret_cast<Window*> (((LPCREATESTRUCT) lParam)->lpCreateParams);
        SetWindowLong (hWnd, GWL_USERDATA, reinterpret_cast<long> (window));
    }
    else
    {
        window = reinterpret_cast<Window*> (GetWindowLong (hWnd, GWL_USERDATA));
    }
    
    return window->WindowProcedure(hWnd, message, wParam, lParam);
}
