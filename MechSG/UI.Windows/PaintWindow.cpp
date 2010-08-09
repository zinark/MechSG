#include "PaintWindow.h"
using namespace UI::Core;
using namespace UI::Windows;

PaintWindow::~PaintWindow(void)
{
}

void PaintWindow::OnKeyPressed( unsigned int keyCode )
{
    if (MessageBox (_HWnd, "Key pressed", "Title", MB_YESNO) == IDYES)
    {
        PostQuitMessage(0);
    }
}
