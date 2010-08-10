#include "PaintWindow.h"
using namespace UI::Core;
using namespace UI::Windows;

void PaintWindow::OnWindowCreated()
{

}

PaintWindow::~PaintWindow(void)
{

}

void PaintWindow::OnKeyPressed( unsigned short keyCode )
{
    if (MessageBox (_HWnd, "Do you quit?", "Quit", MB_YESNO) == IDYES)
    {
        PostQuitMessage(0);
    }
}


