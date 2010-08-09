#include <Windows.h>
#include "PaintWindow.h"
#include "Application.h"

using namespace UI::Windows;
using namespace UI::Core;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE, char* cmdLine, int showStyle)
{
    PaintWindow win (hInstance, showStyle);
    win.SetTitle(L"MAIN");
    win.SetName(L"CMAIN");
    win.SetSize(800, 600);
    win.SetPosition(10, 10);
    // win.SetBackgroundColor(SampleColor());
    if (win.Create())
    {
        win.Show();
        Application ().Start();
    }
}
