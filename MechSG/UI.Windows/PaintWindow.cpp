#include "PaintWindow.h"
#include <string>
using namespace UI::Core;
using namespace UI::Windows;
using namespace std;

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



void UI::Windows::PaintWindow::OnPaint( const HDC& hdc )
{
    string msg = "Press ESC to destroy Application";
    TextOut (hdc, 10, 10, msg.c_str(), msg.length());
}
