#include <Windows.h>
#include "PaintWindow.h"
#include "Application.h"

using namespace UI::Windows;
using namespace UI::Core;

AbstractWindow* MainWindow (const HINSTANCE& hInstance, const int& showStyle)
{
    PaintWindow* pw = new PaintWindow (hInstance, showStyle);
    pw->SetTitle(L"MAIN");
    pw->SetName(L"CMAIN");
    pw->SetSize(400, 400);
    pw->SetPosition(0, 0);
    pw->Create();
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_SOLID;
    logBrush.lbColor = RGB (120, 120, 160);
    pw->SetBackgroundColor(logBrush);
    return pw;
}

AbstractWindow* HelperWindow (const HINSTANCE& hInstance, const int& showStyle)
{
    PaintWindow* pw = new PaintWindow (hInstance, showStyle);
    pw->SetTitle(L"Test");
    pw->SetName(L"CTEST");
    pw->SetSize(400, 400);
    pw->SetPosition(410, 0);
    pw->Create();
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_SOLID;
    logBrush.lbColor = RGB (120, 120, 160);
    pw->SetBackgroundColor(logBrush);
    return pw;
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
    AbstractWindow* win = MainWindow(hInstance, showStyle);
    AbstractWindow* helper = HelperWindow(hInstance, showStyle);

    win->Show();
    helper->Show();
    Application ().Start();
    delete win;
    delete helper;
}
