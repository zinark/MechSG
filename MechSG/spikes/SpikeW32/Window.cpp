#include "Window.h"
using namespace SpikeW32;

Window::~Window(void)
{
}

Window::Window( const HINSTANCE& hInst, const int& showStyle ) : AbstractWindow (hInst, showStyle)
{

}

void Window::OnKeyPressed( unsigned int keyCode )
{
    if (keyCode == VK_ESCAPE)
    {
        if (MessageBox (0, L"Are you sure?", L"Exit?", MB_YESNO) == IDYES)
        {
            PostQuitMessage(0);
        }
    }
}
