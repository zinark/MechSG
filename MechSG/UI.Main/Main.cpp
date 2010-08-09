#include <Windows.h>
#include "PaintWindow.h"
#include "Application.h"
#include <vector>
#include <MenuWindow.h>
#include "resource.h"

using namespace std;
using namespace UI::Windows;
using namespace UI::Core;

AbstractWindow* CreatePaintWindow (const HINSTANCE& hInstance, const int& showStyle)
{
    AbstractWindow* win = new PaintWindow (hInstance, showStyle);
    win->SetTitle(L"MAIN");
    win->SetName(L"CMAIN");
    win->SetSize(400, 400);
    win->SetPosition(0, 0);
    
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_SOLID;
    logBrush.lbColor = RGB (120, 120, 160);
    win->SetBackgroundColor(logBrush);
    
    return win;
}

AbstractWindow* CreateMenuWindow (const HINSTANCE& hInstance, const int& showStyle)
{
    AbstractWindow* win = new MenuWindow (hInstance, showStyle);
    win->SetTitle(L"Menu Window");
    win->SetName(L"XMenuWindow");
    win->SetSize(400, 400);
    win->SetPosition(410, 0);
    return win;
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
    vector<AbstractWindow*> windows;
    windows.push_back(CreatePaintWindow(hInstance, showStyle));
    windows.push_back(CreateMenuWindow(hInstance, showStyle));
    for (int i=0; i < windows.size(); ++i)
    {
        windows[i]->Create();
        windows[i]->Show();
    }
    
    Application ().Start();

    for (int i=0; i < windows.size();++i)
    {
        delete windows[i];
    }
}
